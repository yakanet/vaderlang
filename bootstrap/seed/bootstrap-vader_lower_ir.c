#include "bootstrap.split.h"

static bool vader_lower_ir$block_mentions(void* l0, int32_t l1, void* l2);
static bool vader_lower_ir$block_runs_code(void* l0);
static bool vader_lower_ir$expr_mentions(vader_box_t l0, int32_t l1, void* l2);
static bool vader_lower_ir$exprs_run_code(void* l0);
static bool vader_lower_ir$fields_mention(void* l0, int32_t l1, void* l2);
static void vader_lower_ir$for_each_lowered_block(void* l0, void* l1);
static void vader_lower_ir$for_each_lowered_expr(vader_box_t l0, void* l1);
static void vader_lower_ir$for_each_lowered_stmt(vader_box_t l0, void* l1);
static void vader_lower_ir$for_each_lowered_stmt_node(vader_box_t l0, void* l1);
static void vader_lower_ir$for_each_stmt_node_in_stmt(vader_box_t l0, void* l1);
static bool vader_lower_ir$len_mentions(vader_box_t l0, int32_t l1, void* l2);
static bool vader_lower_ir$opt_block_mentions(vader_box_t l0, int32_t l1, void* l2);
static bool vader_lower_ir$opt_expr_mentions(vader_box_t l0, int32_t l1, void* l2);
static bool vader_lower_ir$opt_expr_runs_code(vader_box_t l0);
static void vader_lower_ir$ref_block(void* l0, void* l1, void* l2, void* l3);
static void vader_lower_ir$ref_expr(vader_box_t l0, void* l1, void* l2, void* l3);
static void vader_lower_ir$ref_stmt(vader_box_t l0, void* l1, void* l2, void* l3);
static bool vader_lower_ir$stmt_runs_code(vader_box_t l0);
static void vader_lower_ir$verify_no_coroutine_markers(void* l0, vader_string_t l1, void* l2);

vader_box_t vader_lower_ir$adjust_hi_inclusive(vader_box_t l0, bool l1, void* l2) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l1)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_lower_ir$mk_i64_plus_one(l0, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_lower_ir$bare_capture_error(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_string_t l3 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredLet_t*) l0)->f_span;
    l3 = ((vader_struct_vader_lower_ir$LoweredLet_t*) l0)->f_name;
    l3 = concat_5(1035u, l3, 1126u, l1, 1121u);
    t0 = vader_support_diagnostics$internal_error((uint8_t) 9, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_lower_ir$binary_op_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 1506u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2673u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2356u;
    } else if (l0 == INT32_C(3)) {
        l1 = 1837u;
    } else if (l0 == INT32_C(4)) {
        l1 = 2348u;
    } else if (l0 == INT32_C(5)) {
        l1 = 2549u;
    } else if (l0 == INT32_C(6)) {
        l1 = 2553u;
    } else if (l0 == INT32_C(7)) {
        l1 = 1621u;
    } else if (l0 == INT32_C(8)) {
        l1 = 1622u;
    } else if (l0 == INT32_C(9)) {
        l1 = 1625u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1539u;
    } else if (l0 == INT32_C(11)) {
        l1 = 2435u;
    } else if (l0 == INT32_C(12)) {
        l1 = 1896u;
    } else if (l0 == INT32_C(13)) {
        l1 = 2370u;
    } else if (l0 == INT32_C(14)) {
        l1 = 2295u;
    } else if (l0 == INT32_C(15)) {
        l1 = 2296u;
    } else if (l0 == INT32_C(16)) {
        l1 = 2063u;
    } else if (l0 == INT32_C(17)) {
        l1 = 2064u;
    } else if (l0 == INT32_C(18)) {
        l1 = 1508u;
    } else if (l0 == INT32_C(19)) {
        l1 = 2674u;
    } else {
        if (!(l0 == INT32_C(20))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2357u;
    }
    return l1;
}

vader_string_t vader_lower_ir$binary_op_symbol(uint8_t l0) {
    vader_string_t l1;
    bool l2;
    if (l0 == INT32_C(0)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(18);
    }
    if (l2) {
        l1 = 355u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(19);
    }
    if (l2) {
        l1 = 385u;
    } else {
        if (l0 == INT32_C(2)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(20);
        }
        if (l2) {
            l1 = 351u;
        } else if (l0 == INT32_C(3)) {
            l1 = 440u;
        } else if (l0 == INT32_C(4)) {
            l1 = 284u;
        } else if (l0 == INT32_C(5)) {
            l1 = 505u;
        } else if (l0 == INT32_C(6)) {
            l1 = 527u;
        } else if (l0 == INT32_C(7)) {
            l1 = 286u;
        } else if (l0 == INT32_C(8)) {
            l1 = 3057u;
        } else if (l0 == INT32_C(9)) {
            l1 = 975u;
        } else if (l0 == INT32_C(10)) {
            l1 = 287u;
        } else if (l0 == INT32_C(11)) {
            l1 = 3058u;
        } else if (l0 == INT32_C(12)) {
            l1 = 522u;
        } else if (l0 == INT32_C(13)) {
            l1 = 246u;
        } else if (l0 == INT32_C(14)) {
            l1 = 504u;
        } else if (l0 == INT32_C(15)) {
            l1 = 506u;
        } else if (l0 == INT32_C(16)) {
            l1 = 525u;
        } else {
            if (!(l0 == INT32_C(17))) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l1 = 526u;
        }
    }
    return l1;
}

bool vader_lower_ir$binds_bare_capture(void* l0, void* l1) {
    int32_t l2;
    bool t0;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredLet_t*) l1)->f_symbol)->f_id;
    t0 = std_collections$MutableSet$std_core$Contains$contains__i32(l0, l2);
    if (t0) {
        return !(((vader_struct_vader_lower_ir$LoweredLet_t*) l1)->f_value.tag == 1265u);
    }
    return false;
}

static bool vader_lower_ir$block_mentions(void* l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_stmts;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t1 = vader_lower_ir$stmt_mentions_symbol(t0, l1, l2);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    t1 = vader_lower_ir$opt_expr_mentions(((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_trailing, l1, l2);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_lower_ir$block_runs_code(void* l0) {
    void* l1 = NULL;
    bool l2;
    int64_t l3, l4;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_stmts;
    l2 = false;
    l3 = ((vader_array_t*) l1)->length;
    l4 = INT64_C(0);
    {
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            t1 = vader_lower_ir$stmt_runs_code(t0);
            if (t1) {
                l2 = true;
                goto end_9;
            }
            l4 = (l4 + INT64_C(1));
        }
        l2 = false;
    } end_9: ;
    if (l2) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t1 = vader_lower_ir$opt_expr_runs_code(((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_trailing);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_lower_ir$expr_mentions(vader_box_t l0, int32_t l1, void* l2) {
    bool l3, l4;
    void* t0 = NULL;
    int32_t t1;
    bool t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1279u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_id;
        l3 = t1 == l1;
        { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1252u) {
        t0 = l0.payload.obj;
        l3 = vader_lower_ir$len_mentions(((vader_struct_vader_lower_ir$LoweredArrayLen_t*) t0)->f_target, l1, l2);
    } else if ((l0.tag == 1264u || l0.tag == 1274u || l0.tag == 1301u)) {
        l3 = vader_lower_ir$expr_mentions(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredCellGet_t, f_target, l0.payload.obj), l1, l2);
    } else if ((l0.tag == 1263u || l0.tag == 1265u || l0.tag == 1298u)) {
        l3 = vader_lower_ir$expr_mentions(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredCast_t, f_value, l0.payload.obj), l1, l2);
    } else if (l0.tag == 1300u) {
        t0 = l0.payload.obj;
        l3 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredUnary_t*) t0)->f_operand, l1, l2);
    } else if (l0.tag == 1287u) {
        t0 = l0.payload.obj;
        l3 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredMakeClosure_t*) t0)->f_env, l1, l2);
    } else if (l0.tag == 1259u) {
        t0 = l0.payload.obj;
        l3 = vader_lower_ir$block_mentions(t0, l1, l2);
    } else if (l0.tag == 1281u) {
        t0 = l0.payload.obj;
        t2 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_target, l1, l2);
        if (t2) {
            l3 = true;
        } else {
            t0 = l0.payload.obj;
            l3 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_index, l1, l2);
        }
    } else if (l0.tag == 1258u) {
        t0 = l0.payload.obj;
        t2 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_left, l1, l2);
        if (t2) {
            l3 = true;
        } else {
            t0 = l0.payload.obj;
            l3 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_right, l1, l2);
        }
    } else if (l0.tag == 1254u) {
        t2 = ((vader_struct_vader_lower_ir$MentionKinds_t*) l2)->f_push_target;
        if (t2) {
            t0 = l0.payload.obj;
            l4 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t0)->f_target, l1, l2);
        } else {
            l4 = false;
        }
        if (l4) {
            l3 = true;
        } else {
            t0 = l0.payload.obj;
            l3 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t0)->f_value, l1, l2);
        }
    } else if (l0.tag == 1255u) {
        t0 = l0.payload.obj;
        t2 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_target, l1, l2);
        if (t2) {
            l4 = true;
        } else {
            t0 = l0.payload.obj;
            l4 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_lo, l1, l2);
        }
        if (l4) {
            l3 = true;
        } else {
            t0 = l0.payload.obj;
            l3 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_hi, l1, l2);
        }
    } else if (l0.tag == 1262u) {
        t0 = l0.payload.obj;
        t2 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_callee, l1, l2);
        if (t2) {
            l3 = true;
        } else {
            t0 = l0.payload.obj;
            l3 = vader_lower_ir$exprs_mention_symbol(((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_args, l1, l2);
        }
    } else if (l0.tag == 1303u) {
        t0 = l0.payload.obj;
        t2 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) t0)->f_receiver, l1, l2);
        if (t2) {
            l3 = true;
        } else {
            t0 = l0.payload.obj;
            l3 = vader_lower_ir$exprs_mention_symbol(((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) t0)->f_args, l1, l2);
        }
    } else if (l0.tag == 1283u) {
        t0 = l0.payload.obj;
        l3 = vader_lower_ir$exprs_mention_symbol(((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) t0)->f_args, l1, l2);
    } else if (l0.tag == 1253u) {
        t0 = l0.payload.obj;
        l3 = vader_lower_ir$exprs_mention_symbol(((vader_struct_vader_lower_ir$LoweredArrayLit_t*) t0)->f_elements, l1, l2);
    } else if (l0.tag == 1296u) {
        t0 = l0.payload.obj;
        l3 = vader_lower_ir$fields_mention(((vader_struct_vader_lower_ir$LoweredStructLit_t*) t0)->f_fields, l1, l2);
    } else if (l0.tag == 1280u) {
        t0 = l0.payload.obj;
        t2 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_cond, l1, l2);
        if (t2) {
            l4 = true;
        } else {
            t0 = l0.payload.obj;
            l4 = vader_lower_ir$block_mentions(((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_then_block, l1, l2);
        }
        if (l4) {
            l3 = true;
        } else {
            t0 = l0.payload.obj;
            l3 = vader_lower_ir$opt_block_mentions(((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_else_block, l1, l2);
        }
    } else {
        if (!((l0.tag == 1260u || l0.tag == 1267u || l0.tag == 1270u || l0.tag == 1275u || l0.tag == 1277u || l0.tag == 1282u || l0.tag == 1289u || l0.tag == 1293u || l0.tag == 1299u || l0.tag == 1302u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = false;
    }
    { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_lower_ir$expr_runs_code(vader_box_t l0) {
    bool l1, l2;
    void* l3 = NULL;
    int64_t l4, l5;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l0.tag == 1262u || l0.tag == 1303u)) {
        l1 = true;
        { bool __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 1252u || l0.tag == 1264u || l0.tag == 1274u || l0.tag == 1301u)) {
        l1 = vader_lower_ir$expr_runs_code(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_target, l0.payload.obj));
    } else if ((l0.tag == 1263u || l0.tag == 1265u || l0.tag == 1298u)) {
        l1 = vader_lower_ir$expr_runs_code(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredCast_t, f_value, l0.payload.obj));
    } else if (l0.tag == 1300u) {
        t0 = l0.payload.obj;
        l1 = vader_lower_ir$expr_runs_code(((vader_struct_vader_lower_ir$LoweredUnary_t*) t0)->f_operand);
    } else if (l0.tag == 1287u) {
        t0 = l0.payload.obj;
        l1 = vader_lower_ir$expr_runs_code(((vader_struct_vader_lower_ir$LoweredMakeClosure_t*) t0)->f_env);
    } else if (l0.tag == 1259u) {
        t0 = l0.payload.obj;
        l1 = vader_lower_ir$block_runs_code(t0);
    } else if (l0.tag == 1281u) {
        t0 = l0.payload.obj;
        t1 = vader_lower_ir$expr_runs_code(((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_target);
        if (t1) {
            l1 = true;
        } else {
            t0 = l0.payload.obj;
            l1 = vader_lower_ir$expr_runs_code(((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_index);
        }
    } else if (l0.tag == 1258u) {
        t0 = l0.payload.obj;
        t1 = vader_lower_ir$expr_runs_code(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_left);
        if (t1) {
            l1 = true;
        } else {
            t0 = l0.payload.obj;
            l1 = vader_lower_ir$expr_runs_code(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_right);
        }
    } else if (l0.tag == 1254u) {
        t0 = l0.payload.obj;
        t1 = vader_lower_ir$expr_runs_code(((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t0)->f_target);
        if (t1) {
            l1 = true;
        } else {
            t0 = l0.payload.obj;
            l1 = vader_lower_ir$expr_runs_code(((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t0)->f_value);
        }
    } else if (l0.tag == 1255u) {
        t0 = l0.payload.obj;
        t1 = vader_lower_ir$expr_runs_code(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_target);
        if (t1) {
            l2 = true;
        } else {
            t0 = l0.payload.obj;
            l2 = vader_lower_ir$expr_runs_code(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_lo);
        }
        if (l2) {
            l1 = true;
        } else {
            t0 = l0.payload.obj;
            l1 = vader_lower_ir$expr_runs_code(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_hi);
        }
    } else if (l0.tag == 1283u) {
        t0 = l0.payload.obj;
        l1 = vader_lower_ir$exprs_run_code(((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) t0)->f_args);
    } else if (l0.tag == 1253u) {
        t0 = l0.payload.obj;
        l1 = vader_lower_ir$exprs_run_code(((vader_struct_vader_lower_ir$LoweredArrayLit_t*) t0)->f_elements);
    } else if (l0.tag == 1296u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredStructLit_t*) t0)->f_fields;
        l2 = false;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        {
            while ((l5 < l4)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                t1 = __lambda_vader_lower_ir_4(t0);
                if (t1) {
                    l2 = true;
                    goto end_164;
                }
                l5 = (l5 + INT64_C(1));
            }
            l2 = false;
        } end_164: ;
        l1 = l2;
    } else if (l0.tag == 1280u) {
        t0 = l0.payload.obj;
        t1 = vader_lower_ir$expr_runs_code(((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_cond);
        if (t1) {
            l2 = true;
        } else {
            t0 = l0.payload.obj;
            l2 = vader_lower_ir$block_runs_code(((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_then_block);
        }
        if (l2) {
            l1 = true;
        } else {
            t0 = l0.payload.obj;
            if (!(((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_else_block.tag == 0u)) {
                t0 = l0.payload.obj;
                l2 = vader_lower_ir$block_runs_code(((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_else_block.payload.obj);
            } else {
                l2 = false;
            }
            l1 = l2;
        }
    } else {
        if (!((l0.tag == 1260u || l0.tag == 1267u || l0.tag == 1270u || l0.tag == 1275u || l0.tag == 1277u || l0.tag == 1279u || l0.tag == 1282u || l0.tag == 1289u || l0.tag == 1293u || l0.tag == 1299u || l0.tag == 1302u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    { bool __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_lower_ir$exprs_mention_symbol(void* l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t1 = vader_lower_ir$expr_mentions(t0, l1, l2);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_lower_ir$exprs_run_code(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = vader_lower_ir$expr_runs_code(t0);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_lower_ir$fields_mention(void* l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t1 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredStructLitField_t*) t0)->f_value, l1, l2);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

void* vader_lower_ir$fn_symbol_of(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t l2 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_origin)->f_symbol;
    if (l1.tag == 0u) {
        l2 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_mangled;
        t0 = vader_lower_ir$synthetic_symbol(INT32_C(0), (uint8_t) 0, l2);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_lower_ir$for_each_lowered_block(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_core_types$for_each_type(((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_type, l1);
    l2 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_stmts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_lower_ir$for_each_lowered_stmt(t0, l1);
        l4 = (l4 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_trailing;
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_lower_ir$for_each_lowered_expr(l5, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lower_ir$for_each_lowered_expr(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l5, &t1 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_core_types$for_each_type(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_type, l0.payload.obj), l1);
    if (l0.tag == 1279u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 1262u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_callee, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_lower_ir$for_each_lowered_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 1303u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) t0)->f_receiver, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_lower_ir$for_each_lowered_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if ((l0.tag == 1274u || l0.tag == 1301u)) {
        vader_lower_ir$for_each_lowered_expr(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredFieldAccess_t, f_target, l0.payload.obj), l1);
    } else if (l0.tag == 1281u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_index, l1);
    } else if (l0.tag == 1300u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredUnary_t*) t0)->f_operand, l1);
    } else if (l0.tag == 1258u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_right, l1);
    } else if (l0.tag == 1280u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_cond, l1);
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_block(((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_then_block, l1);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_else_block;
        if (!(l5.tag == 0u)) {
            t0 = l5.payload.obj;
            vader_lower_ir$for_each_lowered_block(t0, l1);
        }
    } else if (l0.tag == 1259u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_block(t0, l1);
    } else if (l0.tag == 1296u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredStructLit_t*) t0)->f_fields;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredStructLitField_t*) t0)->f_value, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 1253u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredArrayLit_t*) t0)->f_elements;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
            t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
            vader_lower_ir$for_each_lowered_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 1252u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredArrayLen_t*) t0)->f_target, l1);
    } else if (l0.tag == 1254u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t0)->f_value, l1);
    } else if (l0.tag == 1255u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_lo, l1);
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_hi, l1);
    } else if (l0.tag == 1263u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredCast_t*) t0)->f_value, l1);
    } else if (l0.tag == 1298u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredTypeCheck_t*) t0)->f_value, l1);
        t0 = l0.payload.obj;
        vader_core_types$for_each_type(((vader_struct_vader_lower_ir$LoweredTypeCheck_t*) t0)->f_check_type, l1);
    } else if (l0.tag == 1283u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
            t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
            vader_lower_ir$for_each_lowered_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 1265u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredCellNew_t*) t0)->f_value, l1);
        t0 = l0.payload.obj;
        vader_core_types$for_each_type(((vader_struct_vader_lower_ir$LoweredCellNew_t*) t0)->f_value_type, l1);
    } else if (l0.tag == 1264u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredCellGet_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_core_types$for_each_type(((vader_struct_vader_lower_ir$LoweredCellGet_t*) t0)->f_value_type, l1);
    } else if (l0.tag == 1287u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredMakeClosure_t*) t0)->f_env, l1);
    } else if (l0.tag == 1270u) {
        t0 = l0.payload.obj;
        vader_core_types$for_each_type(((vader_struct_vader_lower_ir$LoweredDataConst_t*) t0)->f_type, l1);
    } else if (l0.tag == 1277u) {
        t0 = l0.payload.obj;
        vader_core_types$for_each_type(((vader_struct_vader_lower_ir$LoweredGlobalGet_t*) t0)->f_type, l1);
    } else if (l0.tag == 1299u) {
        t0 = l0.payload.obj;
        vader_core_types$for_each_type(((vader_struct_vader_lower_ir$LoweredTypeConst_t*) t0)->f_type, l1);
        t0 = l0.payload.obj;
        vader_core_types$for_each_type(((vader_struct_vader_lower_ir$LoweredTypeConst_t*) t0)->f_value, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_lower_ir$for_each_lowered_ref(vader_box_t l0, void* l1, void* l2, void* l3) {
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l4 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1276u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_body;
        if (!(l4.tag == 0u)) {
            t0 = l4.payload.obj;
            vader_lower_ir$ref_block(t0, l1, l2, l3);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 1268u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredConstDecl_t*) t0)->f_value, l1, l2, l3);
    } else if (!(l0.tag == 1294u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_lower_ir$for_each_lowered_ref_in_expr(vader_box_t l0, void* l1, void* l2, void* l3) {
    vader_lower_ir$ref_expr(l0, l1, l2, l3);
    return;
}

static void vader_lower_ir$for_each_lowered_stmt(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    int64_t l4, l5;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l2, &t1 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1285u) {
        t0 = l0.payload.obj;
        vader_core_types$for_each_type(((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_type, l1);
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_value, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 1256u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredAssign_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredAssign_t*) t0)->f_value, l1);
    } else if (l0.tag == 1273u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredExprStmt_t*) t0)->f_expr, l1);
    } else if (l0.tag == 1292u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredReturn_t*) t0)->f_value;
        if (!(l2.tag == 0u)) {
            vader_lower_ir$for_each_lowered_expr(l2, l1);
        }
    } else if (l0.tag == 1305u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredYield_t*) t0)->f_value, l1);
    } else if (l0.tag == 1257u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredAwait_t*) t0)->f_awaited, l1);
    } else if (l0.tag == 1284u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_block(((vader_struct_vader_lower_ir$LoweredLabelledBlock_t*) t0)->f_body, l1);
    } else if (l0.tag == 1286u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_cond;
        if (!(l2.tag == 0u)) {
            vader_lower_ir$for_each_lowered_expr(l2, l1);
        }
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_block(((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_body, l1);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_step;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            vader_lower_ir$for_each_lowered_stmt(t1, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if (!(l0.tag == 1261u)) {
        if (!(l0.tag == 1269u)) {
            if (l0.tag == 1266u) {
                t0 = l0.payload.obj;
                vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredCellSet_t*) t0)->f_target, l1);
                t0 = l0.payload.obj;
                vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredCellSet_t*) t0)->f_value, l1);
                t0 = l0.payload.obj;
                vader_core_types$for_each_type(((vader_struct_vader_lower_ir$LoweredCellSet_t*) t0)->f_value_type, l1);
            } else if (l0.tag == 1278u) {
                t0 = l0.payload.obj;
                vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredGlobalSet_t*) t0)->f_value, l1);
            } else if (l0.tag == 1272u) {
                t0 = l0.payload.obj;
                vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredDeferPush_t*) t0)->f_thunk, l1);
            } else if (!(l0.tag == 1271u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lower_ir$for_each_lowered_stmt_node(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1276u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_body;
        if (!(l2.tag == 0u)) {
            t0 = l2.payload.obj;
            vader_lower_ir$for_each_stmt_node_in_block(t0, l1);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 1268u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredConstDecl_t*) t0)->f_value, l1);
    } else if (!(l0.tag == 1294u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_lower_ir$for_each_lowered_type(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l5 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1276u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_core_types$for_each_type(((vader_struct_vader_lower_ir$LoweredParam_t*) t0)->f_type, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        vader_core_types$for_each_type(((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_return_type, l1);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_body;
        if (!(l5.tag == 0u)) {
            t0 = l5.payload.obj;
            vader_lower_ir$for_each_lowered_block(t0, l1);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 1294u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredStructDecl_t*) t0)->f_fields;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_core_types$for_each_type(((vader_struct_vader_lower_ir$LoweredStructField_t*) t0)->f_type, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else {
        if (!(l0.tag == 1268u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        vader_core_types$for_each_type(((vader_struct_vader_lower_ir$LoweredConstDecl_t*) t0)->f_type, l1);
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_lowered_expr(((vader_struct_vader_lower_ir$LoweredConstDecl_t*) t0)->f_value, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_lower_ir$for_each_stmt_node_in_block(void* l0, void* l1) {
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
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_lower_ir$for_each_stmt_node_in_stmt(t0, l1);
        l4 = (l4 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_trailing;
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_lower_ir$for_each_stmt_node_in_expr(l5, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_lower_ir$for_each_stmt_node_in_expr(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l5, &t1 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1262u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_callee, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_lower_ir$for_each_stmt_node_in_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 1303u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) t0)->f_receiver, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_lower_ir$for_each_stmt_node_in_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 1274u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredFieldAccess_t*) t0)->f_target, l1);
    } else if (l0.tag == 1301u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredUnionField_t*) t0)->f_target, l1);
    } else if (l0.tag == 1281u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_index, l1);
    } else if (l0.tag == 1300u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredUnary_t*) t0)->f_operand, l1);
    } else if (l0.tag == 1258u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_right, l1);
    } else if (l0.tag == 1280u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_cond, l1);
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_block(((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_then_block, l1);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_else_block;
        if (!(l5.tag == 0u)) {
            t0 = l5.payload.obj;
            vader_lower_ir$for_each_stmt_node_in_block(t0, l1);
        }
    } else if (l0.tag == 1259u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_block(t0, l1);
    } else if (l0.tag == 1296u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredStructLit_t*) t0)->f_fields;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredStructLitField_t*) t0)->f_value, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 1253u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredArrayLit_t*) t0)->f_elements;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
            t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
            vader_lower_ir$for_each_stmt_node_in_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 1263u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredCast_t*) t0)->f_value, l1);
    } else if (l0.tag == 1298u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredTypeCheck_t*) t0)->f_value, l1);
    } else if (l0.tag == 1283u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
            t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
            vader_lower_ir$for_each_stmt_node_in_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 1252u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredArrayLen_t*) t0)->f_target, l1);
    } else if (l0.tag == 1254u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t0)->f_value, l1);
    } else if (l0.tag == 1255u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_lo, l1);
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_hi, l1);
    } else if (l0.tag == 1265u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredCellNew_t*) t0)->f_value, l1);
    } else if (l0.tag == 1264u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredCellGet_t*) t0)->f_target, l1);
    } else if (l0.tag == 1287u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredMakeClosure_t*) t0)->f_env, l1);
    } else if (!(l0.tag == 1282u)) {
        if (!(l0.tag == 1275u)) {
            if (!(l0.tag == 1260u)) {
                if (!(l0.tag == 1289u)) {
                    if (!(l0.tag == 1267u)) {
                        if (!(l0.tag == 1293u)) {
                            if (!(l0.tag == 1279u)) {
                                if (!(l0.tag == 1270u)) {
                                    if (!(l0.tag == 1277u)) {
                                        if (!(l0.tag == 1302u)) {
                                            if (!(l0.tag == 1299u)) {
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
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lower_ir$for_each_stmt_node_in_stmt(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    int64_t l4, l5;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l2, &t1 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
    ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, l0);
    if (l0.tag == 1285u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_value, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 1256u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredAssign_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredAssign_t*) t0)->f_value, l1);
    } else if (l0.tag == 1266u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredCellSet_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredCellSet_t*) t0)->f_value, l1);
    } else if (l0.tag == 1278u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredGlobalSet_t*) t0)->f_value, l1);
    } else if (l0.tag == 1273u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredExprStmt_t*) t0)->f_expr, l1);
    } else if (l0.tag == 1292u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredReturn_t*) t0)->f_value;
        if (!(l2.tag == 0u)) {
            vader_lower_ir$for_each_stmt_node_in_expr(l2, l1);
        }
    } else if (l0.tag == 1305u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredYield_t*) t0)->f_value, l1);
    } else if (l0.tag == 1257u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredAwait_t*) t0)->f_awaited, l1);
    } else if (l0.tag == 1284u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_block(((vader_struct_vader_lower_ir$LoweredLabelledBlock_t*) t0)->f_body, l1);
    } else if (l0.tag == 1286u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_cond;
        if (!(l2.tag == 0u)) {
            vader_lower_ir$for_each_stmt_node_in_expr(l2, l1);
        }
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_block(((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_body, l1);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_step;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            vader_lower_ir$for_each_stmt_node_in_stmt(t1, l1);
            l5 = (l5 + INT64_C(1));
        }
    } else if (l0.tag == 1272u) {
        t0 = l0.payload.obj;
        vader_lower_ir$for_each_stmt_node_in_expr(((vader_struct_vader_lower_ir$LoweredDeferPush_t*) t0)->f_thunk, l1);
    } else if (!(l0.tag == 1261u)) {
        if (!(l0.tag == 1269u)) {
            if (!(l0.tag == 1271u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_lower_ir$len_mentions(vader_box_t l0, int32_t l1, void* l2) {
    bool t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_lower_ir$MentionKinds_t*) l2)->f_array_len;
    if (t0) {
        t0 = vader_lower_ir$expr_mentions(l0, l1, l2);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1279u) {
        t1 = l0.payload.obj;
        t2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t1)->f_symbol)->f_id;
        if (t2 == l1) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        t0 = vader_lower_ir$expr_mentions(l0, l1, l2);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_lower_ir$expr_mentions(l0, l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_lower_ir$loop_step_block(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) l0)->f_step;
    l2 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) l0)->f_span;
    t0 = vader_lower_ir$mk_void_block(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_lower_ir$mk_array_repeat(vader_box_t l0, vader_box_t l1, vader_box_t l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &l1, &l2 };
    void** gc_raw_roots[4] = { &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(263u, 2u, 13u, 2045u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l0.payload.obj;
    l4 = (void*) _a0_arr;
    t0 = (void*) &vader_data_23;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a2_arr = vader_array_new(251u, 2u, 13u, 1789u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 1u] = l5;
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l2.payload.obj;
    l5 = (void*) _a2_arr;
    vader_struct_vader_lower_ir$LoweredIntrinsicCall_t* _a3_obj = (vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredIntrinsicCall_t));
    vader_obj_header_init(_a3_obj, 1283u);
    _a3_obj->f_span = l3;
    _a3_obj->f_type = l2;
    _a3_obj->f_name = 1580u;
    _a3_obj->f_args = l4;
    _a3_obj->f_param_types = l5;
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_lower_ir$mk_i64_plus_one(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_23;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    t0 = (void*) &vader_data_23;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    vader_struct_vader_lower_ir$LoweredIntLit_t* _a2_obj = (vader_struct_vader_lower_ir$LoweredIntLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredIntLit_t));
    vader_obj_header_init(_a2_obj, 1282u);
    _a2_obj->f_span = l1;
    _a2_obj->f_type = vader_ref_box(l3);
    _a2_obj->f_value = INT64_C(1);
    l3 = (void*) _a2_obj;
    vader_struct_vader_lower_ir$LoweredBinary_t* _a3_obj = (vader_struct_vader_lower_ir$LoweredBinary_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredBinary_t));
    vader_obj_header_init(_a3_obj, 1258u);
    _a3_obj->f_span = l1;
    _a3_obj->f_type = vader_ref_box(l2);
    _a3_obj->f_op = (uint8_t) 0;
    _a3_obj->f_left = l0;
    _a3_obj->f_right = vader_ref_box(l3);
    t0 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_lower_ir$mk_lowered_call(void* l0, void* l1, vader_box_t l2, void* l3) {
    void* l4 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_lower_ir$LoweredIdent_t* _a0_obj = (vader_struct_vader_lower_ir$LoweredIdent_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredIdent_t));
    vader_obj_header_init(_a0_obj, 1279u);
    _a0_obj->f_span = l3;
    _a0_obj->f_type = l2;
    _a0_obj->f_symbol = l0;
    _a0_obj->f_fresh = false;
    l4 = (void*) _a0_obj;
    vader_struct_vader_lower_ir$LoweredCall_t* _a1_obj = (vader_struct_vader_lower_ir$LoweredCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredCall_t));
    vader_obj_header_init(_a1_obj, 1262u);
    _a1_obj->f_span = l3;
    _a1_obj->f_type = l2;
    _a1_obj->f_callee = vader_ref_box(l4);
    _a1_obj->f_args = l1;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_lower_ir$mk_void_block(void* l0, void* l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_18;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    vader_struct_vader_lower_ir$LoweredBlock_t* _a1_obj = (vader_struct_vader_lower_ir$LoweredBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredBlock_t));
    vader_obj_header_init(_a1_obj, 1259u);
    _a1_obj->f_span = l1;
    _a1_obj->f_type = vader_ref_box(l2);
    _a1_obj->f_stmts = l0;
    _a1_obj->f_trailing = vader_box_obj(0u, NULL);
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_lower_ir$new_lowered_project(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[13] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l11, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 13u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 0u, 346u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 541u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l0 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(198u, 0u, 13u, 1304u);
    l1 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(262u, 0u, 13u, 2042u);
    l2 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(190u, 0u, 13u, 1249u);
    l3 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(24u, 0u, 8u, 339u);
    l4 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(29u, 0u, 0u, 346u);
    l5 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(23u, 0u, 7u, 338u);
    l6 = (void*) _a9_arr;
    vader_struct_std_collections$MutableMap__i64__Any_t* _a10_obj = (vader_struct_std_collections$MutableMap__i64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i64__Any_t));
    vader_obj_header_init(_a10_obj, 514u);
    _a10_obj->f_ekeys = l4;
    _a10_obj->f_evals = l5;
    _a10_obj->f_index = l6;
    _a10_obj->f_mask = INT64_C(0);
    _a10_obj->f_grow_at = INT64_C(0);
    _a10_obj->f_size = INT64_C(0);
    _a10_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a10_obj;
    vader_array_t* _a11_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(29u, 0u, 0u, 346u);
    l6 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(23u, 0u, 7u, 338u);
    l7 = (void*) _a13_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a14_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a14_obj, 467u);
    _a14_obj->f_ekeys = l5;
    _a14_obj->f_evals = l6;
    _a14_obj->f_index = l7;
    _a14_obj->f_mask = INT64_C(0);
    _a14_obj->f_grow_at = INT64_C(0);
    _a14_obj->f_size = INT64_C(0);
    _a14_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a14_obj;
    vader_array_t* _a15_arr = vader_array_new(23u, 0u, 7u, 338u);
    l6 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(29u, 0u, 0u, 346u);
    l7 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(23u, 0u, 7u, 338u);
    l8 = (void*) _a17_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a18_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a18_obj, 467u);
    _a18_obj->f_ekeys = l6;
    _a18_obj->f_evals = l7;
    _a18_obj->f_index = l8;
    _a18_obj->f_mask = INT64_C(0);
    _a18_obj->f_grow_at = INT64_C(0);
    _a18_obj->f_size = INT64_C(0);
    _a18_obj->f_tombs = INT64_C(0);
    l6 = (void*) _a18_obj;
    vader_array_t* _a19_arr = vader_array_new(23u, 0u, 7u, 338u);
    l7 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(29u, 0u, 0u, 346u);
    l8 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(23u, 0u, 7u, 338u);
    l9 = (void*) _a21_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a22_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a22_obj, 467u);
    _a22_obj->f_ekeys = l7;
    _a22_obj->f_evals = l8;
    _a22_obj->f_index = l9;
    _a22_obj->f_mask = INT64_C(0);
    _a22_obj->f_grow_at = INT64_C(0);
    _a22_obj->f_size = INT64_C(0);
    _a22_obj->f_tombs = INT64_C(0);
    l7 = (void*) _a22_obj;
    vader_array_t* _a23_arr = vader_array_new(189u, 0u, 13u, 1248u);
    l8 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(23u, 0u, 7u, 338u);
    l9 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(2u, 0u, 13u, 22u);
    l10 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(23u, 0u, 7u, 338u);
    l11 = (void*) _a26_arr;
    vader_struct_std_collections$MutableMap__i32__string___t* _a27_obj = (vader_struct_std_collections$MutableMap__i32__string___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__string___t));
    vader_obj_header_init(_a27_obj, 483u);
    _a27_obj->f_ekeys = l9;
    _a27_obj->f_evals = l10;
    _a27_obj->f_index = l11;
    _a27_obj->f_mask = INT64_C(0);
    _a27_obj->f_grow_at = INT64_C(0);
    _a27_obj->f_size = INT64_C(0);
    _a27_obj->f_tombs = INT64_C(0);
    l9 = (void*) _a27_obj;
    vader_struct_vader_lower_ir$LoweredProject_t* _a28_obj = (vader_struct_vader_lower_ir$LoweredProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredProject_t));
    vader_obj_header_init(_a28_obj, 1291u);
    _a28_obj->f_modules = l0;
    _a28_obj->f_entry = 0u;
    _a28_obj->f_vtable_entries = l1;
    _a28_obj->f_data_pool = l2;
    _a28_obj->f_globals = l3;
    _a28_obj->f_libraries = l4;
    _a28_obj->f_const_fn_wrap = l5;
    _a28_obj->f_const_inline = l6;
    _a28_obj->f_const_fresh_wrap = l7;
    _a28_obj->f_const_routes = l8;
    _a28_obj->f_trait_membership = l9;
    t0 = (void*) _a28_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_lower_ir$opt_block_mentions(vader_box_t l0, int32_t l1, void* l2) {
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 0u)) {
        t0 = l0.payload.obj;
        t1 = vader_lower_ir$block_mentions(t0, l1, l2);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_lower_ir$opt_expr_mentions(vader_box_t l0, int32_t l1, void* l2) {
    bool t0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 0u)) {
        t0 = vader_lower_ir$expr_mentions(l0, l1, l2);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_lower_ir$opt_expr_runs_code(vader_box_t l0) {
    bool t0;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 0u)) {
        t0 = vader_lower_ir$expr_runs_code(l0);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void vader_lower_ir$ref_block(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    int64_t l5, l6;
    vader_box_t l7 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l7, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_stmts;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        vader_lower_ir$ref_stmt(t0, l1, l2, l3);
        l6 = (l6 + INT64_C(1));
    }
    l7 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_trailing;
    if (l7.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_lower_ir$ref_expr(l7, l1, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lower_ir$ref_expr(vader_box_t l0, void* l1, void* l2, void* l3) {
    vader_box_t l4 = vader_box_null();
    int32_t l5;
    vader_string_t l6 = 0;
    vader_string_t l10 = 0;
    void* l7 = NULL;
    int64_t l8, l9;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l4, &t1 };
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l7, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1262u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
        ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, ((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_type);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_callee;
        if (l4.tag == 1279u) {
            t0 = l4.payload.obj;
            l5 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_id;
            t0 = l4.payload.obj;
            l6 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_name;
            vader_fn_t* _a1_fnobj = (vader_fn_t*) l1;
            ((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_box_i32(338u, l5), vader_box_string(335u, l6));
        }
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_callee, l1, l2, l3);
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_lower_ir$LoweredCall_t*) t0)->f_args;
        l8 = ((vader_array_t*) l7)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
            t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
            vader_lower_ir$ref_expr(t1, l1, l2, l3);
            l9 = (l9 + INT64_C(1));
        }
    } else if (l0.tag == 1303u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a3_fnobj = (vader_fn_t*) l3;
        ((vader_fn_erased_sig_1_t) _a3_fnobj->code)(_a3_fnobj->env, ((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) t0)->f_type);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) t0)->f_trait_name;
        t0 = l0.payload.obj;
        l10 = ((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) t0)->f_method;
        vader_fn_t* _a4_fnobj = (vader_fn_t*) l2;
        ((vader_fn_erased_sig_2_t) _a4_fnobj->code)(_a4_fnobj->env, vader_box_string(335u, l6), vader_box_string(335u, l10));
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) t0)->f_receiver, l1, l2, l3);
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) t0)->f_args;
        l8 = ((vader_array_t*) l7)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
            t1 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9);
            vader_lower_ir$ref_expr(t1, l1, l2, l3);
            l9 = (l9 + INT64_C(1));
        }
    } else if ((l0.tag == 1274u || l0.tag == 1301u)) {
        vader_lower_ir$ref_expr(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredFieldAccess_t, f_target, l0.payload.obj), l1, l2, l3);
    } else if (l0.tag == 1281u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_target, l1, l2, l3);
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_index, l1, l2, l3);
    } else if (l0.tag == 1300u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredUnary_t*) t0)->f_operand, l1, l2, l3);
    } else if (l0.tag == 1258u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_left, l1, l2, l3);
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_right, l1, l2, l3);
    } else if (l0.tag == 1280u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_cond, l1, l2, l3);
        t0 = l0.payload.obj;
        vader_lower_ir$ref_block(((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_then_block, l1, l2, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredIf_t*) t0)->f_else_block;
        if (!(l4.tag == 0u)) {
            t0 = l4.payload.obj;
            vader_lower_ir$ref_block(t0, l1, l2, l3);
        }
    } else if (l0.tag == 1259u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_block(t0, l1, l2, l3);
    } else if (l0.tag == 1296u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a6_fnobj = (vader_fn_t*) l3;
        ((vader_fn_erased_sig_1_t) _a6_fnobj->code)(_a6_fnobj->env, ((vader_struct_vader_lower_ir$LoweredStructLit_t*) t0)->f_type);
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_lower_ir$LoweredStructLit_t*) t0)->f_fields;
        l8 = ((vader_array_t*) l7)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
            t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l9);
            vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredStructLitField_t*) t0)->f_value, l1, l2, l3);
            l9 = (l9 + INT64_C(1));
        }
    } else if (l0.tag == 1253u) {
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_lower_ir$LoweredArrayLit_t*) t0)->f_elements;
        l8 = ((vader_array_t*) l7)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l9)
            t1 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l9);
            vader_lower_ir$ref_expr(t1, l1, l2, l3);
            l9 = (l9 + INT64_C(1));
        }
    } else if (l0.tag == 1252u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredArrayLen_t*) t0)->f_target, l1, l2, l3);
    } else if (l0.tag == 1254u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t0)->f_target, l1, l2, l3);
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredArrayPush_t*) t0)->f_value, l1, l2, l3);
    } else if (l0.tag == 1255u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_target, l1, l2, l3);
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_lo, l1, l2, l3);
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredArraySlice_t*) t0)->f_hi, l1, l2, l3);
    } else if (l0.tag == 1263u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredCast_t*) t0)->f_value, l1, l2, l3);
    } else if (l0.tag == 1298u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredTypeCheck_t*) t0)->f_value, l1, l2, l3);
    } else if (l0.tag == 1283u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a9_fnobj = (vader_fn_t*) l3;
        ((vader_fn_erased_sig_1_t) _a9_fnobj->code)(_a9_fnobj->env, ((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) t0)->f_type);
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) t0)->f_args;
        l8 = ((vader_array_t*) l7)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l9)
            t1 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l9);
            vader_lower_ir$ref_expr(t1, l1, l2, l3);
            l9 = (l9 + INT64_C(1));
        }
    } else if (l0.tag == 1265u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredCellNew_t*) t0)->f_value, l1, l2, l3);
    } else if (l0.tag == 1264u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredCellGet_t*) t0)->f_target, l1, l2, l3);
    } else if (l0.tag == 1287u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredMakeClosure_t*) t0)->f_fn_symbol)->f_id;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredMakeClosure_t*) t0)->f_fn_symbol)->f_name;
        vader_fn_t* _a11_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_2_t) _a11_fnobj->code)(_a11_fnobj->env, vader_box_i32(338u, l5), vader_box_string(335u, l6));
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredMakeClosure_t*) t0)->f_env, l1, l2, l3);
    } else if (l0.tag == 1279u) {
        t0 = l0.payload.obj;
        if (((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_kind == INT32_C(0)) {
            t0 = l0.payload.obj;
            l5 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_id;
            t0 = l0.payload.obj;
            l6 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_name;
            vader_fn_t* _a12_fnobj = (vader_fn_t*) l1;
            ((vader_fn_erased_sig_2_t) _a12_fnobj->code)(_a12_fnobj->env, vader_box_i32(338u, l5), vader_box_string(335u, l6));
        }
    } else if (!(l0.tag == 1270u)) {
        if (!((l0.tag == 1277u || l0.tag == 1299u || l0.tag == 1302u))) {
            if (!((l0.tag == 1260u || l0.tag == 1275u || l0.tag == 1282u || l0.tag == 1289u))) {
                if (!((l0.tag == 1267u || l0.tag == 1293u))) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_lower_ir$ref_stmt(vader_box_t l0, void* l1, void* l2, void* l3) {
    vader_box_t l4 = vader_box_null();
    void* l5 = NULL;
    int64_t l6, l7;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l4, &t1 };
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1285u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_value, l1, l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 1256u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredAssign_t*) t0)->f_target, l1, l2, l3);
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredAssign_t*) t0)->f_value, l1, l2, l3);
    } else if (l0.tag == 1273u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredExprStmt_t*) t0)->f_expr, l1, l2, l3);
    } else if (l0.tag == 1292u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredReturn_t*) t0)->f_value;
        if (!(l4.tag == 0u)) {
            vader_lower_ir$ref_expr(l4, l1, l2, l3);
        }
    } else if (l0.tag == 1305u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredYield_t*) t0)->f_value, l1, l2, l3);
    } else if (l0.tag == 1257u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredAwait_t*) t0)->f_awaited, l1, l2, l3);
    } else if (l0.tag == 1284u) {
        t0 = l0.payload.obj;
        vader_lower_ir$ref_block(((vader_struct_vader_lower_ir$LoweredLabelledBlock_t*) t0)->f_body, l1, l2, l3);
    } else if (l0.tag == 1286u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_cond;
        if (!(l4.tag == 0u)) {
            vader_lower_ir$ref_expr(l4, l1, l2, l3);
        }
        t0 = l0.payload.obj;
        vader_lower_ir$ref_block(((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_body, l1, l2, l3);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_step;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
            vader_lower_ir$ref_stmt(t1, l1, l2, l3);
            l7 = (l7 + INT64_C(1));
        }
    } else if (!(l0.tag == 1261u)) {
        if (!(l0.tag == 1269u)) {
            if (l0.tag == 1266u) {
                t0 = l0.payload.obj;
                vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredCellSet_t*) t0)->f_target, l1, l2, l3);
                t0 = l0.payload.obj;
                vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredCellSet_t*) t0)->f_value, l1, l2, l3);
            } else if (l0.tag == 1278u) {
                t0 = l0.payload.obj;
                vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredGlobalSet_t*) t0)->f_value, l1, l2, l3);
            } else if (l0.tag == 1272u) {
                t0 = l0.payload.obj;
                vader_lower_ir$ref_expr(((vader_struct_vader_lower_ir$LoweredDeferPush_t*) t0)->f_thunk, l1, l2, l3);
            } else if (!(l0.tag == 1271u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

bool vader_lower_ir$stmt_mentions_symbol(vader_box_t l0, int32_t l1, void* l2) {
    bool l3, l4;
    void* t0 = NULL;
    void* t2 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l2, &t0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1285u) {
        t0 = l0.payload.obj;
        l3 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_value, l1, l2);
        { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 1256u || l0.tag == 1266u)) {
        t1 = vader_lower_ir$expr_mentions(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredAssign_t, f_target, l0.payload.obj), l1, l2);
        if (t1) {
            l3 = true;
        } else {
            l3 = vader_lower_ir$expr_mentions(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredAssign_t, f_value, l0.payload.obj), l1, l2);
        }
    } else if (l0.tag == 1278u) {
        t0 = l0.payload.obj;
        l3 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredGlobalSet_t*) t0)->f_value, l1, l2);
    } else if (l0.tag == 1273u) {
        t0 = l0.payload.obj;
        l3 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredExprStmt_t*) t0)->f_expr, l1, l2);
    } else if (l0.tag == 1292u) {
        t0 = l0.payload.obj;
        l3 = vader_lower_ir$opt_expr_mentions(((vader_struct_vader_lower_ir$LoweredReturn_t*) t0)->f_value, l1, l2);
    } else if (l0.tag == 1305u) {
        t0 = l0.payload.obj;
        l3 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredYield_t*) t0)->f_value, l1, l2);
    } else if (l0.tag == 1257u) {
        t0 = l0.payload.obj;
        l3 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredAwait_t*) t0)->f_awaited, l1, l2);
    } else if (l0.tag == 1272u) {
        t0 = l0.payload.obj;
        l3 = vader_lower_ir$expr_mentions(((vader_struct_vader_lower_ir$LoweredDeferPush_t*) t0)->f_thunk, l1, l2);
    } else if (l0.tag == 1284u) {
        t0 = l0.payload.obj;
        l3 = vader_lower_ir$block_mentions(((vader_struct_vader_lower_ir$LoweredLabelledBlock_t*) t0)->f_body, l1, l2);
    } else if (l0.tag == 1286u) {
        t0 = l0.payload.obj;
        t1 = vader_lower_ir$opt_expr_mentions(((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_cond, l1, l2);
        if (t1) {
            l4 = true;
        } else {
            t0 = l0.payload.obj;
            l4 = vader_lower_ir$block_mentions(((vader_struct_vader_lower_ir$LoweredLoop_t*) t0)->f_body, l1, l2);
        }
        if (l4) {
            l3 = true;
        } else {
            t0 = l0.payload.obj;
            t2 = vader_lower_ir$loop_step_block(t0);
            l3 = vader_lower_ir$block_mentions(t2, l1, l2);
        }
    } else {
        if (!((l0.tag == 1261u || l0.tag == 1269u || l0.tag == 1271u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = false;
    }
    { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_lower_ir$stmt_runs_code(vader_box_t l0) {
    bool l1, l2;
    bool t0;
    void* t1 = NULL;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &t1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l0.tag == 1257u || l0.tag == 1271u)) {
        l1 = true;
        { bool __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 1256u || l0.tag == 1266u)) {
        t0 = vader_lower_ir$expr_runs_code(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredAssign_t, f_target, l0.payload.obj));
        if (t0) {
            l1 = true;
        } else {
            l1 = vader_lower_ir$expr_runs_code(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredAssign_t, f_value, l0.payload.obj));
        }
    } else if (l0.tag == 1285u) {
        t1 = l0.payload.obj;
        l1 = vader_lower_ir$expr_runs_code(((vader_struct_vader_lower_ir$LoweredLet_t*) t1)->f_value);
    } else if (l0.tag == 1278u) {
        t1 = l0.payload.obj;
        l1 = vader_lower_ir$expr_runs_code(((vader_struct_vader_lower_ir$LoweredGlobalSet_t*) t1)->f_value);
    } else if (l0.tag == 1305u) {
        t1 = l0.payload.obj;
        l1 = vader_lower_ir$expr_runs_code(((vader_struct_vader_lower_ir$LoweredYield_t*) t1)->f_value);
    } else if (l0.tag == 1273u) {
        t1 = l0.payload.obj;
        l1 = vader_lower_ir$expr_runs_code(((vader_struct_vader_lower_ir$LoweredExprStmt_t*) t1)->f_expr);
    } else if (l0.tag == 1292u) {
        t1 = l0.payload.obj;
        l1 = vader_lower_ir$opt_expr_runs_code(((vader_struct_vader_lower_ir$LoweredReturn_t*) t1)->f_value);
    } else if (l0.tag == 1272u) {
        t1 = l0.payload.obj;
        l1 = vader_lower_ir$expr_runs_code(((vader_struct_vader_lower_ir$LoweredDeferPush_t*) t1)->f_thunk);
    } else if (l0.tag == 1284u) {
        t1 = l0.payload.obj;
        l1 = vader_lower_ir$block_runs_code(((vader_struct_vader_lower_ir$LoweredLabelledBlock_t*) t1)->f_body);
    } else if (l0.tag == 1286u) {
        t1 = l0.payload.obj;
        t0 = vader_lower_ir$opt_expr_runs_code(((vader_struct_vader_lower_ir$LoweredLoop_t*) t1)->f_cond);
        if (t0) {
            l2 = true;
        } else {
            t1 = l0.payload.obj;
            l2 = vader_lower_ir$block_runs_code(((vader_struct_vader_lower_ir$LoweredLoop_t*) t1)->f_body);
        }
        if (l2) {
            l1 = true;
        } else {
            t1 = l0.payload.obj;
            t2 = vader_lower_ir$loop_step_block(t1);
            l1 = vader_lower_ir$block_runs_code(t2);
        }
    } else {
        if (!((l0.tag == 1261u || l0.tag == 1269u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    { bool __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_lower_ir$synthetic_symbol(int32_t l0, uint8_t l1, vader_string_t l2) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_symbol$Symbol_t* _a0_obj = (vader_struct_vader_core_symbol$Symbol_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_symbol$Symbol_t));
    vader_obj_header_init(_a0_obj, 900u);
    _a0_obj->f_id = l0;
    _a0_obj->f_kind = l1;
    _a0_obj->f_name = l2;
    _a0_obj->f_module = 0u;
    _a0_obj->f_module_name = 0u;
    _a0_obj->f_visibility = (uint8_t) 1;
    _a0_obj->f_defined_at = vader_box_obj(0u, NULL);
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_lower_ir$verify_captured_cells(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l12 = NULL;
    int64_t l6, l7, l8, l9;
    vader_box_t l10 = vader_box_null();
    vader_string_t l11 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    void* t3 = NULL;
    vader_box_t* gc_roots[2] = { &l10, &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l12, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l11, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_collections$len__i32(l1);
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l6];
        t2 = t1.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l3 = ((vader_struct_vader_lower_ir$LoweredModule_t*) t3)->f_decls;
        l8 = ((vader_array_t*) l3)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
            l10 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
            l11 = VADER_UNION_FIELD(vader_string_t, vader_struct_vader_lower_ir$LoweredConstDecl_t, f_mangled, l10.payload.obj);
            vader_struct___lambda_env_vader_lower_ir_3_t* _a3_obj = (vader_struct___lambda_env_vader_lower_ir_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_lower_ir_3_t));
            vader_obj_header_init(_a3_obj, 431u);
            _a3_obj->f_cap_0 = l1;
            _a3_obj->f_cap_1 = l2;
            _a3_obj->f_cap_2 = l11;
            t3 = (void*) _a3_obj;
            vader_fn_t* _a4_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
            vader_obj_header_init(_a4_closure, 329u);
            _a4_closure->code = (void*) &vader_fn_lift___lambda_vader_lower_ir_2;
            _a4_closure->env = t3;
            l12 = (void*) _a4_closure;
            vader_lower_ir$for_each_lowered_stmt_node(l10, l12);
            l9 = (l9 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_lower_ir$verify_functions_defined_once(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l25 = NULL;
    void* l28 = NULL;
    int64_t l7, l8, l9, l10;
    vader_box_t l11 = vader_box_null(), l13 = vader_box_null(), l20 = vader_box_null();
    vader_string_t l14 = 0;
    vader_string_t l16 = 0;
    vader_string_t l17 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    vader_string_t l24 = 0;
    vader_string_t l26 = 0;
    vader_string_t l27 = 0;
    int32_t l21;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    bool t3;
    vader_box_t* gc_roots[4] = { &l11, &l13, &l20, &t1 };
    void** gc_raw_roots[14] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l12, &l15, &l18, &l19, &l25, &l28, &t0,
    };
    vader_string_t* gc_atom_roots[9] = { &l14, &l16, &l17, &l22, &l23, &l24, &l26, &l27, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 9u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 333u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 547u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__string_t* _a4_obj = (vader_struct_std_collections$MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__string_t));
    vader_obj_header_init(_a4_obj, 615u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(23u, 0u, 7u, 338u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 0u, 335u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections$MutableMap__i32__string_t* _a8_obj = (vader_struct_std_collections$MutableMap__i32__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__string_t));
    vader_obj_header_init(_a8_obj, 482u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_grow_at = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a8_obj;
    l4 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_modules;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l4)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l4)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l7)
        t1 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l7];
        t2 = t1.payload.s;
        vader_array_t* _a10_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l7)
        t0 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l7);
        l4 = ((vader_struct_vader_lower_ir$LoweredModule_t*) t0)->f_decls;
        l9 = ((vader_array_t*) l4)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            l11 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l10);
            if (l11.tag == 1276u) {
                t0 = l11.payload.obj;
                l13 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_body;
                if (l13.tag == 0u) {
                    l10 = (l10 + INT64_C(1));
                    continue;
                }
                l12 = l13.payload.obj;
                t0 = l11.payload.obj;
                l14 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_mangled;
                t3 = std_collections$add__string(l2, l14);
                if (t3) {
                    t0 = l11.payload.obj;
                    l20 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_origin)->f_symbol;
                    if (l20.tag == 0u) {
                        l10 = (l10 + INT64_C(1));
                        continue;
                    }
                    l19 = l20.payload.obj;
                    l21 = ((vader_struct_vader_core_symbol$Symbol_t*) l19)->f_id;
                    t0 = l11.payload.obj;
                    l22 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_mangled;
                    l23 = std_collections$get_or_put__i32__string(l3, l21, l22);
                    t0 = l11.payload.obj;
                    l24 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_mangled;
                    if (l23 != l24) {
                        l25 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l12)->f_span;
                        t0 = l11.payload.obj;
                        l26 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_mangled;
                        l27 = concat_5(1035u, l26, 1057u, l23, 1075u);
                        l28 = vader_support_diagnostics$internal_error((uint8_t) 10, l25, l27);
                        vader_array_push_ref((vader_array_t*) l1, l28);
                    }
                    l10 = (l10 + INT64_C(1));
                    continue;
                }
                l15 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l12)->f_span;
                t0 = l11.payload.obj;
                l16 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_mangled;
                l17 = concat_3(1035u, l16, 1098u);
                l18 = vader_support_diagnostics$internal_error((uint8_t) 10, l15, l17);
                vader_array_push_ref((vader_array_t*) l1, l18);
                l10 = (l10 + INT64_C(1));
                continue;
            }
            l10 = (l10 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_lower_ir$verify_lowered(void* l0, vader_string_t l1, void* l2) {
    vader_lower_ir$verify_no_coroutine_markers(l0, l1, l2);
    return;
}

static void vader_lower_ir$verify_no_coroutine_markers(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l12 = NULL;
    int64_t l6, l7, l8, l9;
    vader_box_t l10 = vader_box_null();
    vader_string_t l11 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l10, &t0 };
    void** gc_raw_roots[7] = { &l0, &l2, &l3, &l4, &l5, &l12, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l11, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l3)->f_size;
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
        l3 = ((vader_struct_vader_lower_ir$LoweredModule_t*) t2)->f_decls;
        l8 = ((vader_array_t*) l3)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
            l10 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
            l11 = VADER_UNION_FIELD(vader_string_t, vader_struct_vader_lower_ir$LoweredConstDecl_t, f_mangled, l10.payload.obj);
            vader_struct___lambda_env_vader_lower_ir_1_t* _a3_obj = (vader_struct___lambda_env_vader_lower_ir_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_lower_ir_1_t));
            vader_obj_header_init(_a3_obj, 430u);
            _a3_obj->f_cap_0 = l2;
            _a3_obj->f_cap_1 = l1;
            _a3_obj->f_cap_2 = l11;
            t2 = (void*) _a3_obj;
            vader_fn_t* _a4_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
            vader_obj_header_init(_a4_closure, 329u);
            _a4_closure->code = (void*) &vader_fn_lift___lambda_vader_lower_ir_0;
            _a4_closure->env = t2;
            l12 = (void*) _a4_closure;
            vader_lower_ir$for_each_lowered_stmt_node(l10, l12);
            l9 = (l9 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

vader_box_t vader_lower_ir$vtable_entry_of(vader_box_t l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1276u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_params)->length;
        if (t1 == INT64_C(0)) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_origin)->f_vtable_slot;
        if (l2.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l1 = l2.payload.obj;
        l3 = ((vader_struct_vader_core_mono$VtableSlot_t*) l1)->f_trait_key;
        l4 = ((vader_struct_vader_core_mono$VtableSlot_t*) l1)->f_method;
        t0 = l0.payload.obj;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        l2 = ((vader_struct_vader_lower_ir$LoweredParam_t*) t0)->f_type;
        t0 = l0.payload.obj;
        l1 = vader_lower_ir$fn_symbol_of(t0);
        vader_struct_vader_lower_ir$LoweredVtableEntry_t* _a1_obj = (vader_struct_vader_lower_ir$LoweredVtableEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredVtableEntry_t));
        vader_obj_header_init(_a1_obj, 1304u);
        _a1_obj->f_trait_name = l3;
        _a1_obj->f_method_name = l4;
        _a1_obj->f_struct_type = l2;
        _a1_obj->f_fn_symbol = l1;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

void* vader_lower_ir$wrap_as_block(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_type, l0.payload.obj);
    vader_array_t* _a0_arr = vader_array_new(264u, 0u, 13u, 2059u);
    l3 = (void*) _a0_arr;
    vader_struct_vader_lower_ir$LoweredBlock_t* _a1_obj = (vader_struct_vader_lower_ir$LoweredBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredBlock_t));
    vader_obj_header_init(_a1_obj, 1259u);
    _a1_obj->f_span = l1;
    _a1_obj->f_type = l2;
    _a1_obj->f_stmts = l3;
    _a1_obj->f_trailing = l0;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
