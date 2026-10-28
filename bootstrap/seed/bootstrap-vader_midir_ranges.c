#include "bootstrap.split.h"

static void vader_midir_ranges$add_fact(void* l0, uint64_t l1, int64_t l2);
static bool vader_midir_ranges$already_safe(vader_box_t l0);
static void* vader_midir_ranges$analyse_function_ranges(void* l0, void* l1, bool l2);
static vader_box_t vader_midir_ranges$arithmetic_of(uint8_t l0);
static uint8_t vader_midir_ranges$arithmetic_verdict(void* l0, void* l1, void* l2);
static bool vader_midir_ranges$below_top_through(void* l0, void* l1, int32_t l2, int64_t l3, int64_t l4, void* l5);
static vader_string_t vader_midir_ranges$binop_label(void* l0, void* l1);
static void* vader_midir_ranges$bitwise_interval(uint8_t l0, void* l1, void* l2);
static vader_box_t vader_midir_ranges$block_entry_states(void* l0, void* l1, void* l2);
static bool vader_midir_ranges$block_has_sites(void* l0, void* l1, bool l2);
static vader_box_t vader_midir_ranges$branch_comparison(void* l0, void* l1, int32_t l2);
static void* vader_midir_ranges$constant_interval(int64_t l0, vader_box_t l1);
static void* vader_midir_ranges$constants_of(void* l0);
static void* vader_midir_ranges$copy_range_state(void* l0);
static void vader_midir_ranges$count_verdict(void* l0, uint8_t l1);
static vader_string_t vader_midir_ranges$counts_line(void* l0);
static void* vader_midir_ranges$exact_result(uint8_t l0, void* l1, void* l2);
static uint64_t vader_midir_ranges$fact_key(int32_t l0, int32_t l1);
static int32_t vader_midir_ranges$fact_left(uint64_t l0);
static bool vader_midir_ranges$fact_mentions(uint64_t l0, int32_t l1);
static int32_t vader_midir_ranges$fact_right(uint64_t l0);
static bool vader_midir_ranges$flow_out(void* l0, void* l1, void* l2, void* l3);
static void vader_midir_ranges$forget_local(void* l0, int32_t l1);
static void vader_midir_ranges$forget_written(void* l0, vader_box_t l1);
static bool vader_midir_ranges$has_sites(void* l0, void* l1, bool l2);
static bool vader_midir_ranges$held_above_bottom(void* l0, void* l1, int32_t l2, void* l3, void* l4);
static bool vader_midir_ranges$held_below_top(void* l0, void* l1, int32_t l2, void* l3, void* l4, void* l5);
static bool vader_midir_ranges$holds_values_of(void* l0, int32_t l1, void* l2);
static uint8_t vader_midir_ranges$index_verdict(void* l0, void* l1, int32_t l2, int32_t l3);
static vader_box_t vader_midir_ranges$indexed_array(vader_box_t l0);
static vader_box_t vader_midir_ranges$interval_of(void* l0, void* l1, int32_t l2);
static void* vader_midir_ranges$interval_widen(void* l0, void* l1, void* l2);
static bool vader_midir_ranges$is_arithmetic(vader_box_t l0);
static bool vader_midir_ranges$is_checked(uint8_t l0);
static bool vader_midir_ranges$is_checked_access(vader_box_t l0);
static bool vader_midir_ranges$is_single(void* l0);
static void* vader_midir_ranges$join_range_states(void* l0, void* l1);
static bool vader_midir_ranges$judge_sites(void* l0, void* l1, void* l2, bool l3, void* l4);
static void vader_midir_ranges$learn_access(void* l0, void* l1, int32_t l2, int32_t l3);
static bool vader_midir_ranges$learn_comparison(void* l0, void* l1, void* l2, bool l3);
static bool vader_midir_ranges$learn_difference(void* l0, void* l1, int32_t l2, int32_t l3, int64_t l4);
static bool vader_midir_ranges$learn_equal(void* l0, void* l1, int32_t l2, int32_t l3);
static bool vader_midir_ranges$learn_order(void* l0, void* l1, int32_t l2, int32_t l3, int64_t l4, bool l5);
static bool vader_midir_ranges$length_mentions(int32_t l0, int32_t l1, int32_t l2);
static uint64_t vader_midir_ranges$local_bits(int32_t l0);
static vader_string_t vader_midir_ranges$local_name(void* l0, int32_t l1);
static void* vader_midir_ranges$loop_headers(void* l0, void* l1);
static vader_box_t vader_midir_ranges$marked_safe(vader_box_t l0);
static bool vader_midir_ranges$may_prove_an_access(void* l0);
static bool vader_midir_ranges$merge_into(void* l0, void* l1, int32_t l2, void* l3);
static uint8_t vader_midir_ranges$negation_verdict(void* l0, void* l1, void* l2);
static void* vader_midir_ranges$new_range_state(void);
static void* vader_midir_ranges$non_negative_bound(void* l0);
static vader_box_t vader_midir_ranges$on_integers(void* l0, vader_box_t l1);
static uint8_t vader_midir_ranges$overflow_verdict(void* l0, void* l1, bool l2);
static void* vader_midir_ranges$proven_accesses(void* l0, void* l1);
static void* vader_midir_ranges$range_context(void* l0, bool l1, void* l2);
static bool vader_midir_ranges$range_state_covers(void* l0, void* l1);
static bool vader_midir_ranges$range_state_mentions(void* l0, int32_t l1);
static void* vader_midir_ranges$remainder_interval(void* l0, void* l1);
static bool vader_midir_ranges$result_fits(void* l0, void* l1, void* l2, uint8_t l3, void* l4, void* l5, void* l6);
static bool vader_midir_ranges$same_range_state(void* l0, void* l1);
static void vader_midir_ranges$set_interval(void* l0, void* l1, int32_t l2, void* l3);
static void vader_midir_ranges$set_result(void* l0, void* l1, int32_t l2, void* l3);
static void vader_midir_ranges$settle_intervals(void* l0, void* l1);
static void vader_midir_ranges$shift_local(void* l0, void* l1, int32_t l2, int32_t l3, int64_t l4, void* l5);
static int32_t vader_midir_ranges$site_count(void* l0);
static vader_string_t vader_midir_ranges$site_label(void* l0, vader_box_t l1);
static vader_box_t vader_midir_ranges$site_of(void* l0, vader_box_t l1);
static bool vader_midir_ranges$sum_fits(void* l0, void* l1, int32_t l2, void* l3, vader_box_t l4, void* l5, void* l6);
static void vader_midir_ranges$tally_function(void* l0, void* l1);
static vader_string_t vader_midir_ranges$tally_line(void* l0);
static void vader_midir_ranges$transfer(void* l0, void* l1, vader_box_t l2);
static void vader_midir_ranges$transfer_arithmetic(void* l0, void* l1, void* l2, uint8_t l3, void* l4, void* l5, void* l6);
static void vader_midir_ranges$transfer_binop(void* l0, void* l1, void* l2);
static void vader_midir_ranges$transfer_constant(void* l0, void* l1, void* l2);
static void vader_midir_ranges$transfer_copy(void* l0, void* l1, int32_t l2, int32_t l3);
static void vader_midir_ranges$transfer_length(void* l0, void* l1, void* l2);
static void vader_midir_ranges$transfer_unop(void* l0, void* l1, void* l2);
static vader_box_t vader_midir_ranges$type_of(void* l0, int32_t l1);
static uint8_t vader_midir_ranges$verdict_at(void* l0, vader_box_t l1, bool l2, vader_box_t l3);
static vader_box_t vader_midir_ranges$walking_state(vader_box_t l0, int32_t l1);
static vader_box_t vader_midir_ranges$widen_lower(void* l0, void* l1, void* l2);
static void vader_midir_ranges$widen_range_states(void* l0, void* l1, void* l2);
static vader_box_t vader_midir_ranges$widen_upper(void* l0, void* l1, void* l2);
static void* vader_midir_ranges$widening_thresholds(void* l0, int32_t l1);

static void vader_midir_ranges$add_fact(void* l0, uint64_t l1, int64_t l2) {
    int32_t l3, l4;
    int64_t l5;
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_midir_ranges$fact_left(l1);
    l4 = vader_midir_ranges$fact_right(l1);
    t0 = vader_midir$LocalId$std_core$Equals$equals(l3, l4);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = std_collections$get_or_put__u64__i64(((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_differences, l1, l2);
    if ((l2 < l5)) {
        std_collections$MutableMap$std_core$IndexSet$set_at__u64__i64(((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_differences, l1, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_midir_ranges$already_safe(vader_box_t l0) {
    bool l1;
    void* t0;
    if (l0.tag == 1328u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_bounds_safe;
        return l1;
    }
    if (l0.tag == 1332u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_bounds_safe;
    } else {
        if (!((l0.tag == 1334u || l0.tag == 1357u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

static void* vader_midir_ranges$analyse_function_ranges(void* l0, void* l1, bool l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    bool l5, l6, l7, l8;
    vader_string_t l13 = 0;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[9] = { &l0, &l1, &l3, &l4, &l9, &l10, &l11, &l12, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l13 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 9u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_midir_ranges$range_context(((vader_struct_vader_midir$CFGFunction_t*) l0)->f_locals, false, l1);
    vader_array_t* _a0_arr = vader_array_new(213u, 0u, 13u, 1384u);
    l4 = (void*) _a0_arr;
    l5 = vader_midir_ranges$has_sites(l3, l0, false);
    if (l2) {
        l6 = vader_midir_ranges$has_sites(l3, l0, true);
    } else {
        l6 = false;
    }
    l7 = true;
    if (l5) {
        l8 = true;
    } else {
        l8 = l6;
    }
    if (l8) {
        l9 = vader_midir_ranges$constants_of(l0);
        if (l5) {
            t0 = vader_midir_ranges$judge_sites(l3, l0, l9, false, l4);
            if (!(t0)) {
                l7 = false;
            }
        }
        l10 = l3;
        l11 = ((vader_struct_vader_midir_ranges$RangeContext_t*) l10)->f_locals;
        l12 = ((vader_struct_vader_midir_ranges$RangeContext_t*) l10)->f_types;
        l10 = ((vader_struct_vader_midir_ranges$RangeContext_t*) l10)->f_shrinks;
        vader_struct_vader_midir_ranges$RangeContext_t* _a1_obj = (vader_struct_vader_midir_ranges$RangeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ranges$RangeContext_t));
        vader_obj_header_init(_a1_obj, 1382u);
        _a1_obj->f_locals = l11;
        _a1_obj->f_types = l12;
        _a1_obj->f_checked_ops_trap = true;
        _a1_obj->f_shrinks = l10;
        l3 = (void*) _a1_obj;
        if (l6) {
            t0 = vader_midir_ranges$judge_sites(l3, l0, l9, true, l4);
            if (!(t0)) {
                l7 = false;
            }
        }
    }
    l13 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_mangled;
    l3 = (void*) &vader_fn_static___lambda_vader_midir_ranges_3;
    l3 = std_sort$sort__vader_midir_ranges_RangeSite(l4, l3);
    l5 = !(l7);
    vader_struct_vader_midir_ranges$FunctionRanges_t* _a2_obj = (vader_struct_vader_midir_ranges$FunctionRanges_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ranges$FunctionRanges_t));
    vader_obj_header_init(_a2_obj, 1381u);
    _a2_obj->f_mangled = l13;
    _a2_obj->f_sites = l3;
    _a2_obj->f_gave_up = l5;
    t1 = (void*) _a2_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_ranges$arithmetic_of(uint8_t l0) {
    vader_box_t l1;
    bool l2;
    if (l0 == INT32_C(0)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(18);
    }
    if (l2) {
        l1 = vader_box_i32(340u, INT32_C(0));
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(19);
    }
    if (l2) {
        l1 = vader_box_i32(340u, INT32_C(1));
    } else {
        if (l0 == INT32_C(2)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(20);
        }
        if (l2) {
            l1 = vader_box_i32(340u, INT32_C(2));
        } else {
            if (l0 == INT32_C(3)) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(4);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(5);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(6);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(7);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(8);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(9);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(10);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(11);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(12);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(13);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(14);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(15);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(16);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(17);
            }
            if (!(l2)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l1 = vader_box_obj(0u, NULL);
        }
    }
    return l1;
}

static uint8_t vader_midir_ranges$arithmetic_verdict(void* l0, void* l1, void* l2) {
    int32_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    uint8_t l8;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    bool l12;
    uint8_t t0;
    vader_box_t* gc_roots[4] = { &l4, &l5, &l6, &l7 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l9, &l10, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_dst;
    l4 = vader_midir_ranges$type_of(l0, l3);
    l3 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_lhs;
    l5 = vader_midir_ranges$interval_of(l0, l1, l3);
    l3 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_rhs;
    l6 = vader_midir_ranges$interval_of(l0, l1, l3);
    l7 = vader_midir_ranges$arithmetic_of(((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_op);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 2; }
    }
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 2; }
    }
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 2; }
    }
    if (!(l7.tag == 0u)) {
        l8 = ((uint8_t) l7.payload.i);
        l9 = l5.payload.obj;
        l10 = l6.payload.obj;
        l11 = l4.payload.obj;
        l12 = vader_midir_ranges$result_fits(l0, l1, l2, l8, l9, l10, l11);
        l8 = ((uint8_t) l7.payload.i);
        l9 = l5.payload.obj;
        l10 = l6.payload.obj;
        l9 = vader_midir_ranges$exact_result(l8, l9, l10);
        l10 = l4.payload.obj;
        t0 = vader_midir_ranges$overflow_verdict(l9, l10, l12);
        { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 2; }
}

static bool vader_midir_ranges$below_top_through(void* l0, void* l1, int32_t l2, int64_t l3, int64_t l4, void* l5) {
    void* l6;
    vader_box_t l7;
    int64_t l8, l9;
    bool t0;
    int64_t t1;
    l7 = vader_midir_ranges$interval_of(l0, l1, l2);
    if (l7.tag == 0u) {
        return false;
    }
    l6 = l7.payload.obj;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l6)->f_hi_open;
    if (t0) {
        l7 = vader_support_integer$checked_add(INT64_C(64), false, l3, l4);
        if (l7.tag == 0u) {
            return false;
        }
        t1 = ((int64_t) l7.payload.i);
        if ((t1 <= INT64_C(0))) {
            t0 = vader_midir_ranges$holds_values_of(l0, l2, l5);
            return t0;
        }
        return false;
    }
    l8 = ((vader_struct_vader_support_integer$Interval_t*) l6)->f_hi;
    l7 = vader_support_integer$checked_add(INT64_C(64), false, l8, l3);
    if (l7.tag == 0u) {
        return false;
    }
    l8 = ((int64_t) l7.payload.i);
    l7 = vader_support_integer$checked_add(INT64_C(64), false, l8, l4);
    if (l7.tag == 0u) {
        return false;
    }
    l8 = ((int64_t) l7.payload.i);
    l9 = ((vader_struct_vader_support_integer$Interval_t*) l5)->f_hi;
    return (l8 <= l9);
}

static vader_string_t vader_midir_ranges$binop_label(void* l0, void* l1) {
    int32_t l2;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[4] = { &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir$InstrBinOp_t*) l1)->f_lhs;
    l3 = vader_midir_ranges$local_name(l0, l2);
    l4 = vader_lower_ir$binary_op_symbol(((vader_struct_vader_midir$InstrBinOp_t*) l1)->f_op);
    l2 = ((vader_struct_vader_midir$InstrBinOp_t*) l1)->f_rhs;
    l5 = vader_midir_ranges$local_name(l0, l2);
    t0 = concat_5(l3, 14u, l4, 14u, l5);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_ranges$bitwise_interval(uint8_t l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t l6 = vader_box_null();
    bool l7;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[6] = { &l1, &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(4)) {
        l3 = vader_midir_ranges$remainder_interval(l1, l2);
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(7)) {
        l4 = vader_midir_ranges$non_negative_bound(l1);
        l5 = vader_midir_ranges$non_negative_bound(l2);
        l6 = vader_support_integer$interval_meet(l4, l5);
        if (l6.tag == 0u) {
            t0 = (void*) &vader_data_48;
            vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        } else {
            l3 = l6.payload.obj;
        }
    } else if (l0 == INT32_C(6)) {
        l3 = vader_midir_ranges$non_negative_bound(l1);
    } else {
        if (l0 == INT32_C(0)) {
            l7 = true;
        } else {
            l7 = l0 == INT32_C(1);
        }
        if (l7) {
            l7 = true;
        } else {
            l7 = l0 == INT32_C(2);
        }
        if (l7) {
            l7 = true;
        } else {
            l7 = l0 == INT32_C(3);
        }
        if (l7) {
            l7 = true;
        } else {
            l7 = l0 == INT32_C(5);
        }
        if (l7) {
            l7 = true;
        } else {
            l7 = l0 == INT32_C(8);
        }
        if (l7) {
            l7 = true;
        } else {
            l7 = l0 == INT32_C(9);
        }
        if (l7) {
            l7 = true;
        } else {
            l7 = l0 == INT32_C(10);
        }
        if (l7) {
            l7 = true;
        } else {
            l7 = l0 == INT32_C(11);
        }
        if (l7) {
            l7 = true;
        } else {
            l7 = l0 == INT32_C(12);
        }
        if (l7) {
            l7 = true;
        } else {
            l7 = l0 == INT32_C(13);
        }
        if (l7) {
            l7 = true;
        } else {
            l7 = l0 == INT32_C(14);
        }
        if (l7) {
            l7 = true;
        } else {
            l7 = l0 == INT32_C(15);
        }
        if (l7) {
            l7 = true;
        } else {
            l7 = l0 == INT32_C(16);
        }
        if (l7) {
            l7 = true;
        } else {
            l7 = l0 == INT32_C(17);
        }
        if (l7) {
            l7 = true;
        } else {
            l7 = l0 == INT32_C(18);
        }
        if (l7) {
            l7 = true;
        } else {
            l7 = l0 == INT32_C(19);
        }
        if (l7) {
            l7 = true;
        } else {
            l7 = l0 == INT32_C(20);
        }
        if (!(l7)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = (void*) &vader_data_48;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_ranges$block_entry_states(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l14 = NULL;
    int64_t l4, l11, l15, l16;
    int32_t l9, l12;
    bool l10;
    vader_box_t l13 = vader_box_null(), l17 = vader_box_null();
    void* t0 = NULL;
    bool t1, t2;
    vader_box_t* gc_roots[2] = { &l13, &l17 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l5, &l6, &l7, &l8, &l14, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_midir$reverse_postorder(l1);
    l4 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_blocks)->length;
    vader_array_t* _a0_arr = vader_array_new(234u, 1u, 13u, 1533u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = vader_box_obj(0u, NULL).payload.obj;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l4);
    l5 = (void*) _a1_arr;
    l6 = vader_midir_ranges$loop_headers(l1, l3);
    vader_array_t* _a2_arr = vader_array_new(22u, 1u, 7u, 338u);
    ((int32_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (int32_t) INT32_C(0);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l4);
    l7 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(19u, 1u, 12u, 333u);
    ((uint8_t*) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l4);
    l8 = (void*) _a5_arr;
    vader_struct_vader_midir_ranges$RangeFlow_t* _a6_obj = (vader_struct_vader_midir_ranges$RangeFlow_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ranges$RangeFlow_t));
    vader_obj_header_init(_a6_obj, 1383u);
    _a6_obj->f_states = l5;
    _a6_obj->f_headers = l6;
    _a6_obj->f_widenings = l7;
    _a6_obj->f_dirty = l8;
    _a6_obj->f_thresholds = l2;
    l5 = (void*) _a6_obj;
    l6 = ((vader_struct_vader_midir_ranges$RangeFlow_t*) l5)->f_states;
    l9 = ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_entry;
    l7 = vader_midir_ranges$new_range_state();
    vader_array_t* _a7_slotarr = ((vader_array_t*) l6);
    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
    vader_array_ref_store(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l9, l7);
    VADER_WRITE_BARRIER(_a7_slotarr->buf);
    l6 = ((vader_struct_vader_midir_ranges$RangeFlow_t*) l5)->f_dirty;
    l9 = ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_entry;
    vader_array_t* _a8_slotarr = ((vader_array_t*) l6);
    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l9)
    ((uint8_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l9] = (uint8_t) true;
    l9 = INT32_C(0);
    while ((l9 < INT32_C(100))) {
        l10 = false;
        l6 = l3;
        l4 = ((vader_array_t*) l6)->length;
        l11 = INT64_C(0);
        while ((l11 < l4)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l11)
            l12 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l11];
            vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_ranges$RangeFlow_t*) l5)->f_dirty);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l12)
            t1 = ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l12];
            t2 = t1;
            if (t2) {
                vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_ranges$RangeFlow_t*) l5)->f_dirty);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l12)
                ((uint8_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l12] = (uint8_t) false;
                vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_ranges$RangeFlow_t*) l5)->f_states);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l12)
                l13 = vader_array_ref_load_box(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l12);
                if (l13.tag == 0u) {
                    l11 = (l11 + INT64_C(1));
                    continue;
                }
                t0 = l13.payload.obj;
                l7 = vader_midir_ranges$copy_range_state(t0);
                vader_array_t* _a13_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_blocks);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l12)
                l8 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l12);
                l14 = ((vader_struct_vader_midir$BasicBlock_t*) l8)->f_instructions;
                l15 = ((vader_array_t*) l14)->length;
                l16 = INT64_C(0);
                while ((l16 < l15)) {
                    vader_array_t* _a14_slotarr = ((vader_array_t*) l14);
                    VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l16)
                    l17 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l16);
                    vader_midir_ranges$transfer(l0, l7, l17);
                    l16 = (l16 + INT64_C(1));
                }
                t1 = vader_midir_ranges$flow_out(l0, l5, l8, l7);
                if (t1) {
                    l10 = true;
                }
                l11 = (l11 + INT64_C(1));
                continue;
            }
            l11 = (l11 + INT64_C(1));
        }
        if (!(l10)) {
            { vader_box_t __vret = vader_ref_box(((vader_struct_vader_midir_ranges$RangeFlow_t*) l5)->f_states); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = (l9 + INT32_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static bool vader_midir_ranges$block_has_sites(void* l0, void* l1, bool l2) {
    void* l3;
    int64_t l4, l5;
    vader_box_t l6, l7;
    bool t0;
    l3 = ((vader_struct_vader_midir$BasicBlock_t*) l1)->f_instructions;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l7 = vader_midir_ranges$site_of(l0, l6);
        if (!(l7.tag == 0u)) {
            t0 = vader_midir_ranges$is_arithmetic(l7);
            if (t0 == l2) {
                return true;
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    return false;
}

static vader_box_t vader_midir_ranges$branch_comparison(void* l0, void* l1, int32_t l2) {
    vader_box_t l3, l7;
    void* l4;
    int64_t l5, l6;
    bool l8, l10;
    int32_t l9, l11;
    void* t0;
    bool t1;
    l3 = vader_box_obj(0u, NULL);
    l4 = ((vader_struct_vader_midir$BasicBlock_t*) l1)->f_instructions;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        if (!(l3.tag == 0u)) {
            t0 = l3.payload.obj;
            l9 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_lhs;
            t1 = vader_midir$writes_local(l7, l9);
            if (t1) {
                l10 = true;
            } else {
                t0 = l3.payload.obj;
                l11 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_rhs;
                l10 = vader_midir$writes_local(l7, l11);
            }
            l8 = l10;
        } else {
            l8 = false;
        }
        if (l8) {
            l3 = vader_box_obj(0u, NULL);
        }
        t1 = vader_midir$writes_local(l7, l2);
        if (t1) {
            l3 = vader_midir_ranges$on_integers(l0, l7);
        }
        l6 = (l6 + INT64_C(1));
    }
    return l3;
}

static void* vader_midir_ranges$constant_interval(int64_t l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_core_types$held_values(l1);
    if (l3.tag == 0u) {
        t0 = vader_support_integer$interval(l0, l0);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    if ((l0 < INT64_C(0))) {
        t1 = ((vader_struct_vader_support_integer$Interval_t*) l2)->f_hi_open;
        if (t1) {
            vader_struct_vader_support_integer$Interval_t* _a0_obj = (vader_struct_vader_support_integer$Interval_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_integer$Interval_t));
            vader_obj_header_init(_a0_obj, 1403u);
            _a0_obj->f_lo = INT64_C(9223372036854775807);
            _a0_obj->f_hi = INT64_C(9223372036854775807);
            _a0_obj->f_lo_open = false;
            _a0_obj->f_hi_open = true;
            _a0_obj->f_hi_past = (uint64_t) 0;
            t0 = (void*) _a0_obj;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_support_integer$interval(l0, l0);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_support_integer$interval(l0, l0);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_ranges$constants_of(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5, l7, l8, l11, l12;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l9, &l10 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 8u, 339u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i64__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i64__bool_t));
    vader_obj_header_init(_a3_obj, 508u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i64_t* _a4_obj = (vader_struct_std_collections$MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i64_t));
    vader_obj_header_init(_a4_obj, 606u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(23u, 0u, 8u, 339u);
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
            if (l9.tag == 1341u) {
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_midir$InstrConst_t*) t0)->f_value;
                if (l10.tag == 1321u) {
                    t0 = l10.payload.obj;
                    l11 = ((vader_struct_vader_midir$ConstInt_t*) t0)->f_value;
                    t1 = std_collections$add__i64(l1, l11);
                    if (t1) {
                        t0 = l10.payload.obj;
                        l12 = ((vader_struct_vader_midir$ConstInt_t*) t0)->f_value;
                        vader_array_push_i64((vader_array_t*) l2, l12);
                    }
                }
            }
            l8 = (l8 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l1 = (void*) &vader_fn_static___lambda_vader_midir_ranges_6;
    t0 = std_sort$sort__i64(l2, l1);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_ranges$copy_range_state(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    int64_t l5, l6, l11, l13;
    int32_t l7, l8, l14, l15;
    uint64_t l10, l12;
    int64_t t0;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_ranges$new_range_state();
    l2 = ((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_intervals;
    l3 = ((vader_struct_std_collections$MutableMap__i32__vader_support_integer_Interval_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$MutableMap__i32__vader_support_integer_Interval_t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__i32__vader_support_integer_Interval_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l7 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l8 = l7;
        l9 = l2;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_intervals, l8, vader_ref_box(l9));
        l5 = (l5 + INT64_C(1));
    }
    l2 = ((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_differences;
    l3 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
        l10 = (uint64_t) (int64_t) t0;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l11 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
        l12 = l10;
        l13 = l11;
        std_collections$MutableMap$std_core$IndexSet$set_at__u64__i64(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_differences, l12, l13);
        l5 = (l5 + INT64_C(1));
    }
    l2 = ((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_lengths;
    l3 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
        l7 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5];
        vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
        l8 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5];
        l14 = l7;
        l15 = l8;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__i32(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_lengths, l14, l15);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_ranges$count_verdict(void* l0, uint8_t l1) {
    int32_t l2;
    int32_t t0;
    if (l1 == INT32_C(0)) {
        t0 = ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_already_safe;
        l2 = vader_chk_add(i32, t0, INT32_C(1));
        ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_already_safe = l2;
        return;
    }
    if (l1 == INT32_C(1)) {
        t0 = ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_proven;
        l2 = vader_chk_add(i32, t0, INT32_C(1));
        ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_proven = l2;
    } else if (l1 == INT32_C(2)) {
        t0 = ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_unproven;
        l2 = vader_chk_add(i32, t0, INT32_C(1));
        ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_unproven = l2;
    } else if (l1 == INT32_C(3)) {
        t0 = ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_certain_fault;
        l2 = vader_chk_add(i32, t0, INT32_C(1));
        ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_certain_fault = l2;
    } else {
        if (!(l1 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_unreachable;
        l2 = vader_chk_add(i32, t0, INT32_C(1));
        ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_unreachable = l2;
    }
    return;
}

static vader_string_t vader_midir_ranges$counts_line(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    int32_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[3] = { &l4, &l5, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = (void*) vader_buffer_new((size_t) INT64_C(92));
    l2 = INT64_C(0);
    t0 = vader_midir_ranges$site_count(l0);
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 211u);
    t0 = ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_proven;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 363u);
    t0 = ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_already_safe;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 360u);
    l4 = std_core$finish_buffer(l1, l2);
    l1 = (void*) vader_buffer_new((size_t) INT64_C(100));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 2833u);
    t0 = ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_unproven;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 370u);
    t0 = ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_certain_fault;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 379u);
    t0 = ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_unreachable;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l5 = std_core$finish_buffer(l1, l2);
    t1 = concat_2(l4, l5);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_ranges$exact_result(uint8_t l0, void* l1, void* l2) {
    void* l3 = NULL;
    void** gc_raw_roots[3] = { &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        l3 = vader_support_integer$interval_add(l1, l2);
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        l3 = vader_support_integer$interval_sub(l1, l2);
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = vader_support_integer$interval_mul(l1, l2);
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint64_t vader_midir_ranges$fact_key(int32_t l0, int32_t l1) {
    uint64_t l2, l3;
    uint64_t t0;
    int64_t t1;
    t0 = vader_midir_ranges$local_bits(l0);
    t1 = (t0 << INT64_C(32));
    l2 = (uint64_t) (int64_t) t1;
    l3 = vader_midir_ranges$local_bits(l1);
    return (uint64_t) (int64_t) (l2 | l3);
}

static int32_t vader_midir_ranges$fact_left(uint64_t l0) {
    return ((int32_t) (uint64_t) (l0 >> INT64_C(32)));
}

static bool vader_midir_ranges$fact_mentions(uint64_t l0, int32_t l1) {
    int32_t t0;
    bool t1;
    t0 = vader_midir_ranges$fact_left(l0);
    t1 = vader_midir$LocalId$std_core$Equals$equals(t0, l1);
    if (t1) {
        return true;
    }
    t0 = vader_midir_ranges$fact_right(l0);
    t1 = vader_midir$LocalId$std_core$Equals$equals(t0, l1);
    return t1;
}

static int32_t vader_midir_ranges$fact_right(uint64_t l0) {
    return ((int32_t) (int64_t) (l0 & INT64_C(4294967295)));
}

static bool vader_midir_ranges$flow_out(void* l0, void* l1, void* l2, void* l3) {
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null();
    int32_t l5;
    bool l7;
    void* l8 = NULL;
    void* l9 = NULL;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l4, &l6 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l8, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_midir$BasicBlock_t*) l2)->f_terminator;
    if (l4.tag == 1370u) {
        t0 = l4.payload.obj;
        l5 = ((vader_struct_vader_midir$TermBranch_t*) t0)->f_target;
        t1 = vader_midir_ranges$merge_into(l0, l1, l5, l3);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l4.tag == 1371u)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = l4.payload.obj;
    l5 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_cond;
    l6 = vader_midir_ranges$branch_comparison(l0, l2, l5);
    if (l6.tag == 0u) {
        t0 = l4.payload.obj;
        l5 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_then_block;
        l7 = vader_midir_ranges$merge_into(l0, l1, l5, l3);
        t0 = l4.payload.obj;
        l5 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_else_block;
        t1 = vader_midir_ranges$merge_into(l0, l1, l5, l3);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        { bool __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = vader_midir_ranges$copy_range_state(l3);
    l7 = false;
    l9 = l6.payload.obj;
    t1 = vader_midir_ranges$learn_comparison(l0, l8, l9, true);
    if (t1) {
        t0 = l4.payload.obj;
        l5 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_then_block;
        l7 = vader_midir_ranges$merge_into(l0, l1, l5, l8);
    }
    l8 = l6.payload.obj;
    t1 = vader_midir_ranges$learn_comparison(l0, l3, l8, false);
    if (!(t1)) {
        { bool __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l4.payload.obj;
    l5 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_else_block;
    t1 = vader_midir_ranges$merge_into(l0, l1, l5, l3);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { bool __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_ranges$forget_local(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    int64_t l6, l7;
    uint64_t l8, l9;
    int32_t l10, l11, l12, l13;
    bool t0;
    int64_t t1;
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections$remove__vader_midir$LocalId__vader_support_integer_Interval(((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_intervals, l1);
    t0 = vader_midir_ranges$range_state_mentions(l0, l1);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 4u, 343u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_differences;
    l4 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l3)->f_size;
    vader_array_t* _pc24_hdr = (vader_array_t*) l2;
    size_t _pc24_len = _pc24_hdr->length;
    size_t _pc24_cap = (_pc24_hdr->offset == 0 && !vader_array_is_borrowed(_pc24_hdr) && _pc24_hdr->length >= _pc24_hdr->buf->length) ? _pc24_hdr->capacity : (size_t) 0;
    void* _pc24_slots = _pc24_hdr->buf->slots;
    for (;;) {
        if ((l6 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
            t1 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
            l8 = (uint64_t) (int64_t) t1;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
            t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
            l9 = l8;
            t0 = vader_midir_ranges$fact_mentions(l9, l1);
            if (t0) {
                if (VADER_LIKELY(_pc24_len < _pc24_cap)) {
                    ((int64_t*) _pc24_slots)[_pc24_len] = (int64_t) ((int64_t) (uint64_t) l9);
                    _pc24_len += 1;
                } else {
                    _pc24_hdr->length = _pc24_len;
                    if (_pc24_hdr->buf->length < _pc24_len) {
                        _pc24_hdr->buf->length = _pc24_len;
                    }
                    vader_array_push_i64((vader_array_t*) l2, (int64_t) (uint64_t) l9);
                    _pc24_hdr = (vader_array_t*) l2;
                    _pc24_len = _pc24_hdr->length;
                    _pc24_cap = (_pc24_hdr->offset == 0 && !vader_array_is_borrowed(_pc24_hdr) && _pc24_hdr->length >= _pc24_hdr->buf->length) ? _pc24_hdr->capacity : (size_t) 0;
                    _pc24_slots = _pc24_hdr->buf->slots;
                }
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        _pc24_hdr->length = _pc24_len;
        if (_pc24_hdr->buf->length < _pc24_len) {
            _pc24_hdr->buf->length = _pc24_len;
        }
        break;
    }
    l6 = ((vader_array_t*) l2)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t1 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
        l8 = (uint64_t) (int64_t) t1;
        std_collections$remove__u64__i64(((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_differences, l8);
        l7 = (l7 + INT64_C(1));
    }
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a4_arr;
    l3 = ((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_lengths;
    l4 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l3)->f_size;
    vader_array_t* _pc91_hdr = (vader_array_t*) l2;
    size_t _pc91_len = _pc91_hdr->length;
    size_t _pc91_cap = (_pc91_hdr->offset == 0 && !vader_array_is_borrowed(_pc91_hdr) && _pc91_hdr->length >= _pc91_hdr->buf->length) ? _pc91_hdr->capacity : (size_t) 0;
    void* _pc91_slots = _pc91_hdr->buf->slots;
    for (;;) {
        if ((l6 < l7)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
            l10 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l6];
            vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
            l11 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l6];
            l12 = l10;
            l13 = l11;
            t0 = vader_midir_ranges$length_mentions(l12, l13, l1);
            if (t0) {
                if (VADER_LIKELY(_pc91_len < _pc91_cap)) {
                    ((int32_t*) _pc91_slots)[_pc91_len] = (int32_t) (l12);
                    _pc91_len += 1;
                } else {
                    _pc91_hdr->length = _pc91_len;
                    if (_pc91_hdr->buf->length < _pc91_len) {
                        _pc91_hdr->buf->length = _pc91_len;
                    }
                    vader_array_push_i32((vader_array_t*) l2, l12);
                    _pc91_hdr = (vader_array_t*) l2;
                    _pc91_len = _pc91_hdr->length;
                    _pc91_cap = (_pc91_hdr->offset == 0 && !vader_array_is_borrowed(_pc91_hdr) && _pc91_hdr->length >= _pc91_hdr->buf->length) ? _pc91_hdr->capacity : (size_t) 0;
                    _pc91_slots = _pc91_hdr->buf->slots;
                }
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        _pc91_hdr->length = _pc91_len;
        if (_pc91_hdr->buf->length < _pc91_len) {
            _pc91_hdr->buf->length = _pc91_len;
        }
        break;
    }
    l6 = ((vader_array_t*) l2)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        l10 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l7];
        std_collections$remove__vader_midir$LocalId__vader_midir$LocalId(((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_lengths, l10);
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_ranges$forget_written(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l7 = vader_box_null();
    void* l3 = NULL;
    int64_t l4, l5;
    int32_t l6;
    vader_box_t* gc_roots[3] = { &l1, &l2, &l7 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_midir$multi_dsts(l1);
    if (l2.tag == 0u) {
        l7 = vader_midir$dst_of(l1);
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l6 = ((int32_t) l7.payload.i);
        vader_midir_ranges$forget_local(l0, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = l2.payload.obj;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
        vader_midir_ranges$forget_local(l0, l6);
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_midir_ranges$has_sites(void* l0, void* l1, bool l2) {
    void* l3;
    void* l6;
    int64_t l4, l5;
    bool t0;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_blocks;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t0 = vader_midir_ranges$block_has_sites(l0, l6, l2);
        if (t0) {
            return true;
        }
        l5 = (l5 + INT64_C(1));
    }
    return false;
}

static bool vader_midir_ranges$held_above_bottom(void* l0, void* l1, int32_t l2, void* l3, void* l4) {
    void* l5;
    void* l6;
    void* l7;
    int64_t l8, l9, l11, l13, l16, l17, l19, l20, l22;
    uint64_t l10, l12;
    int32_t l14;
    vader_box_t l15, l18, l21;
    bool t0;
    int64_t t1;
    int32_t t2;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l3)->f_lo_open;
    if (t0) {
        return false;
    }
    l5 = ((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_differences;
    l6 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l5)->f_ekeys;
    l7 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l5)->f_evals;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l5)->f_size;
    while ((l8 < l9)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
        t1 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l8];
        l10 = (uint64_t) (int64_t) t1;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        l11 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8];
        l12 = l10;
        l13 = l11;
        t2 = vader_midir_ranges$fact_right(l12);
        t0 = vader_midir$LocalId$std_core$Equals$equals(t2, l2);
        if (t0) {
            l14 = vader_midir_ranges$fact_left(l12);
            l15 = vader_midir_ranges$interval_of(l0, l1, l14);
            if (!(l15.tag == 0u)) {
                l5 = l15.payload.obj;
                t0 = ((vader_struct_vader_support_integer$Interval_t*) l5)->f_lo_open;
                if (!(t0)) {
                    l17 = ((vader_struct_vader_support_integer$Interval_t*) l5)->f_lo;
                    l18 = vader_support_integer$checked_sub(INT64_C(64), false, l17, l13);
                    if (!(l18.tag == 0u)) {
                        l16 = ((int64_t) l18.payload.i);
                        l20 = ((vader_struct_vader_support_integer$Interval_t*) l3)->f_lo;
                        l21 = vader_support_integer$checked_add(INT64_C(64), false, l16, l20);
                        if (!(l21.tag == 0u)) {
                            l19 = ((int64_t) l21.payload.i);
                            l22 = ((vader_struct_vader_support_integer$Interval_t*) l4)->f_lo;
                            if ((l19 >= l22)) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        l8 = (l8 + INT64_C(1));
    }
    return false;
}

static bool vader_midir_ranges$held_below_top(void* l0, void* l1, int32_t l2, void* l3, void* l4, void* l5) {
    void* l6;
    void* l7;
    void* l8;
    int64_t l9, l10, l12, l14, l16;
    uint64_t l11, l13;
    int32_t l15;
    bool t0;
    int64_t t1;
    int32_t t2;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l4)->f_hi_open;
    if (t0) {
        return false;
    }
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l3)->f_hi_open;
    if (t0) {
        t0 = ((vader_struct_vader_support_integer$Interval_t*) l5)->f_hi_open;
        if (t0) {
            t1 = ((vader_struct_vader_support_integer$Interval_t*) l4)->f_hi;
            if ((t1 <= INT64_C(0))) {
                return true;
            }
        }
    }
    l6 = ((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_differences;
    l7 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l6)->f_evals;
    l9 = INT64_C(0);
    l10 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l6)->f_size;
    while ((l9 < l10)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        t1 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l9];
        l11 = (uint64_t) (int64_t) t1;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        l12 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l9];
        l13 = l11;
        l14 = l12;
        t2 = vader_midir_ranges$fact_left(l13);
        t0 = vader_midir$LocalId$std_core$Equals$equals(t2, l2);
        if (t0) {
            l15 = vader_midir_ranges$fact_right(l13);
            l16 = ((vader_struct_vader_support_integer$Interval_t*) l4)->f_hi;
            t0 = vader_midir_ranges$below_top_through(l0, l1, l15, l14, l16, l5);
            if (t0) {
                return true;
            }
        }
        l9 = (l9 + INT64_C(1));
    }
    return false;
}

static bool vader_midir_ranges$holds_values_of(void* l0, int32_t l1, void* l2) {
    vader_box_t l3;
    void* t0;
    bool t1;
    l3 = vader_midir_ranges$type_of(l0, l1);
    if (l3.tag == 0u) {
        return false;
    }
    t0 = l3.payload.obj;
    t1 = vader_support_integer$same_interval(t0, l2);
    return t1;
}

static uint8_t vader_midir_ranges$index_verdict(void* l0, void* l1, int32_t l2, int32_t l3) {
    void* l4;
    void* l6;
    void* l7;
    void* l8;
    void* l15;
    vader_box_t l5, l16;
    int64_t l9, l10, l17, l18;
    int32_t l11, l12, l13;
    uint64_t l14;
    bool t0;
    int64_t t1;
    l5 = vader_midir_ranges$interval_of(l0, l1, l3);
    if (l5.tag == 0u) {
        return (uint8_t) 2;
    }
    l4 = l5.payload.obj;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l4)->f_hi_open;
    if (!(t0)) {
        t1 = ((vader_struct_vader_support_integer$Interval_t*) l4)->f_hi;
        if ((t1 < INT64_C(0))) {
            return (uint8_t) 3;
        }
    }
    t1 = ((vader_struct_vader_support_integer$Interval_t*) l4)->f_lo;
    if ((t1 < INT64_C(0))) {
        return (uint8_t) 2;
    }
    l6 = ((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_lengths;
    l7 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l6)->f_evals;
    l9 = INT64_C(0);
    l10 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l6)->f_size;
    while ((l9 < l10)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        l11 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l9];
        vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        l12 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l9];
        l13 = l11;
        t0 = vader_midir$LocalId$std_core$Equals$equals(l12, l2);
        if (t0) {
            l6 = ((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_differences;
            l14 = vader_midir_ranges$fact_key(l3, l13);
            l5 = std_collections$MutableMap$std_core$Index$at__u64__i64(l6, l14);
            if (!(l5.tag == 0u)) {
                t1 = ((int64_t) l5.payload.i);
                if ((t1 <= INT64_C(-1))) {
                    return (uint8_t) 1;
                }
            }
            l16 = vader_midir_ranges$interval_of(l0, l1, l13);
            if (!(l16.tag == 0u)) {
                l15 = l16.payload.obj;
                t0 = ((vader_struct_vader_support_integer$Interval_t*) l4)->f_hi_open;
                if (!(t0)) {
                    l17 = ((vader_struct_vader_support_integer$Interval_t*) l4)->f_hi;
                    l18 = ((vader_struct_vader_support_integer$Interval_t*) l15)->f_lo;
                    if ((l17 < l18)) {
                        return (uint8_t) 1;
                    }
                }
            }
        }
        l9 = (l9 + INT64_C(1));
    }
    return (uint8_t) 2;
}

static vader_box_t vader_midir_ranges$indexed_array(vader_box_t l0) {
    void* t0;
    if (l0.tag == 1328u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_target);
    }
    if (!(l0.tag == 1332u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    return vader_box_i32(338u, ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_target);
}

static vader_box_t vader_midir_ranges$interval_of(void* l0, void* l1, int32_t l2) {
    void* l3;
    vader_box_t l4;
    void* t0;
    l4 = vader_midir_ranges$type_of(l0, l2);
    if (l4.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l3 = l4.payload.obj;
    l4 = std_collections$MutableMap$std_core$Index$at__i32__Any(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_intervals, l2);
    if (l4.tag == 0u) {
        return vader_ref_box(l3);
    }
    t0 = l4.payload.obj;
    return vader_ref_box(t0);
}

static void* vader_midir_ranges$interval_widen(void* l0, void* l1, void* l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_midir_ranges$widen_lower(l0, l1, l2);
    l4 = vader_midir_ranges$widen_upper(l0, l1, l2);
    t0 = vader_support_integer$interval_from_ends(l3, l4);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_ranges$is_arithmetic(vader_box_t l0) {
    return (l0.tag == 1334u || l0.tag == 1357u);
}

static bool vader_midir_ranges$is_checked(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(18)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(19);
    }
    if (l1) {
        return true;
    }
    return l0 == INT32_C(20);
}

static bool vader_midir_ranges$is_checked_access(vader_box_t l0) {
    bool t0;
    if ((l0.tag == 1328u || l0.tag == 1332u)) {
        t0 = vader_midir_ranges$already_safe(l0);
        return !(t0);
    }
    return false;
}

static bool vader_midir_ranges$is_single(void* l0) {
    bool l1;
    int64_t l2, l3;
    bool t0;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo_open;
    if (!(t0)) {
        t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_open;
        l1 = !(t0);
    } else {
        l1 = false;
    }
    if (l1) {
        l2 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
        l3 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi;
        return l2 == l3;
    }
    return false;
}

static void* vader_midir_ranges$join_range_states(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    int64_t l6, l7, l16, l18, l19, l20;
    int32_t l8, l9, l21, l22;
    vader_box_t l12 = vader_box_null();
    uint64_t l15, l17;
    int64_t t0;
    int32_t t1;
    bool t2;
    vader_box_t* gc_roots[1] = { &l12 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l10, &l11, &l13, &l14 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_midir_ranges$new_range_state();
    l3 = ((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_intervals;
    l4 = ((vader_struct_std_collections$MutableMap__i32__vader_support_integer_Interval_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__i32__vader_support_integer_Interval_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__i32__vader_support_integer_Interval_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        l8 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6];
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l9 = l8;
        l10 = l3;
        l12 = std_collections$MutableMap$std_core$Index$at__i32__Any(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_intervals, l9);
        if (!(l12.tag == 0u)) {
            l11 = l12.payload.obj;
            l13 = ((vader_struct_vader_midir_ranges$RangeState_t*) l2)->f_intervals;
            l14 = vader_support_integer$interval_join(l10, l11);
            std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l13, l9, vader_ref_box(l14));
        }
        l6 = (l6 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_differences;
    l4 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
        l15 = (uint64_t) (int64_t) t0;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        l16 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6];
        l17 = l15;
        l18 = l16;
        l12 = std_collections$MutableMap$std_core$Index$at__u64__i64(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_differences, l17);
        if (!(l12.tag == 0u)) {
            l19 = ((int64_t) l12.payload.i);
            l3 = ((vader_struct_vader_midir_ranges$RangeState_t*) l2)->f_differences;
            l20 = vader_support_integer$greater(l18, l19);
            std_collections$MutableMap$std_core$IndexSet$set_at__u64__i64(l3, l17, l20);
        }
        l6 = (l6 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_lengths;
    l4 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
        l8 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l6];
        vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        l9 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l6];
        l21 = l8;
        l22 = l9;
        l12 = std_collections$MutableMap$std_core$Index$at__i32__i32(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_lengths, l21);
        if (!(l12.tag == 0u)) {
            t1 = ((int32_t) l12.payload.i);
            t2 = vader_midir$LocalId$std_core$Equals$equals(t1, l22);
            if (t2) {
                std_collections$MutableMap$std_core$IndexSet$set_at__i32__i32(((vader_struct_vader_midir_ranges$RangeState_t*) l2)->f_lengths, l21, l22);
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_ranges$judge_sites(void* l0, void* l1, void* l2, bool l3, void* l4) {
    vader_box_t l5 = vader_box_null(), l11 = vader_box_null(), l14 = vader_box_null(), l15 = vader_box_null(), l18 = vader_box_null(), l21 = vader_box_null();
    void* l6 = NULL;
    void* l9 = NULL;
    void* l16 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    int64_t l7, l8, l12, l13;
    int32_t l10, l17;
    vader_string_t l19 = 0;
    bool l20;
    uint8_t l22;
    bool t0;
    vader_box_t* gc_roots[6] = { &l5, &l11, &l14, &l15, &l18, &l21 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l4, &l6, &l9, &l16, &l23, &l24 };
    vader_string_t* gc_atom_roots[1] = { &l19 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_midir_ranges$block_entry_states(l0, l1, l2);
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l1)->f_blocks;
    l7 = ((vader_array_t*) l6)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
        l9 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
        t0 = vader_midir_ranges$block_has_sites(l0, l9, l3);
        if (t0) {
            l10 = ((vader_struct_vader_midir$BasicBlock_t*) l9)->f_id;
            l11 = vader_midir_ranges$walking_state(l5, l10);
            l12 = INT64_C(0);
            l13 = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l9)->f_instructions)->length;
            while ((l12 < l13)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l9)->f_instructions);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l12)
                l14 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l12);
                l15 = vader_midir_ranges$site_of(l0, l14);
                if (!(l15.tag == 0u)) {
                    t0 = vader_midir_ranges$is_arithmetic(l15);
                    if (t0 == l3) {
                        l16 = VADER_UNION_FIELD(void*, vader_struct_vader_midir$InstrArrayGet_t, f_span, l15.payload.obj);
                        l17 = ((vader_struct_vader_midir$BasicBlock_t*) l9)->f_id;
                        l18 = l15;
                        l19 = vader_midir_ranges$site_label(l0, l18);
                        l20 = l5.tag == 0u;
                        l21 = l15;
                        l22 = vader_midir_ranges$verdict_at(l0, l11, l20, l21);
                        vader_struct_vader_midir_ranges$RangeSite_t* _a2_obj = (vader_struct_vader_midir_ranges$RangeSite_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ranges$RangeSite_t));
                        vader_obj_header_init(_a2_obj, 1384u);
                        _a2_obj->f_span = l16;
                        _a2_obj->f_block = l17;
                        _a2_obj->f_position = l12;
                        _a2_obj->f_what = l19;
                        _a2_obj->f_arithmetic = l3;
                        _a2_obj->f_verdict = l22;
                        l23 = (void*) _a2_obj;
                        vader_array_push_ref((vader_array_t*) l4, l23);
                    }
                }
                if (!(l11.tag == 0u)) {
                    l24 = l11.payload.obj;
                    vader_midir_ranges$transfer(l0, l24, l14);
                }
                l12 = (l12 + INT64_C(1));
            }
            l8 = (l8 + INT64_C(1));
            continue;
        }
        l8 = (l8 + INT64_C(1));
    }
    { bool __vret = !(l5.tag == 0u); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_ranges$learn_access(void* l0, void* l1, int32_t l2, int32_t l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    vader_box_t l5 = vader_box_null();
    bool l6;
    bool t0;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = vader_midir_ranges$interval_of(l0, l1, l3);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = l5.payload.obj;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l4)->f_lo_open;
    if (t0) {
        l6 = true;
    } else {
        t1 = ((vader_struct_vader_support_integer$Interval_t*) l4)->f_lo;
        l6 = (t1 < INT64_C(0));
    }
    if (l6) {
        l7 = vader_support_integer$interval_from_ends(vader_box_i64(339u, INT64_C(0)), vader_box_obj(0u, NULL));
        l5 = vader_support_integer$interval_meet(l4, l7);
        if (l5.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l4 = l5.payload.obj;
        vader_midir_ranges$set_interval(l0, l1, l3, l4);
        std_collections$get_or_put__vader_midir$LocalId__vader_midir$LocalId(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_lengths, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_collections$get_or_put__vader_midir$LocalId__vader_midir$LocalId(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_lengths, l3, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_midir_ranges$learn_comparison(void* l0, void* l1, void* l2, bool l3) {
    uint8_t l4;
    bool l5, l8;
    int32_t l6, l7;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_op;
    if (l4 == INT32_C(14)) {
        l6 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_lhs;
        l7 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_rhs;
        l5 = vader_midir_ranges$learn_order(l0, l1, l6, l7, INT64_C(-1), l3);
        { bool __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(15)) {
        l6 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_lhs;
        l7 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_rhs;
        l5 = vader_midir_ranges$learn_order(l0, l1, l6, l7, INT64_C(0), l3);
    } else if (l4 == INT32_C(16)) {
        l6 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_rhs;
        l7 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_lhs;
        l5 = vader_midir_ranges$learn_order(l0, l1, l6, l7, INT64_C(-1), l3);
    } else if (l4 == INT32_C(17)) {
        l6 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_rhs;
        l7 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_lhs;
        l5 = vader_midir_ranges$learn_order(l0, l1, l6, l7, INT64_C(0), l3);
    } else if (l4 == INT32_C(12)) {
        if (!(l3)) {
            l5 = true;
        } else {
            l6 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_lhs;
            l7 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_rhs;
            l5 = vader_midir_ranges$learn_equal(l0, l1, l6, l7);
        }
    } else if (l4 == INT32_C(13)) {
        if (l3) {
            l5 = true;
        } else {
            l6 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_lhs;
            l7 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_rhs;
            l5 = vader_midir_ranges$learn_equal(l0, l1, l6, l7);
        }
    } else {
        if (l4 == INT32_C(0)) {
            l8 = true;
        } else {
            l8 = l4 == INT32_C(1);
        }
        if (l8) {
            l8 = true;
        } else {
            l8 = l4 == INT32_C(2);
        }
        if (l8) {
            l8 = true;
        } else {
            l8 = l4 == INT32_C(3);
        }
        if (l8) {
            l8 = true;
        } else {
            l8 = l4 == INT32_C(4);
        }
        if (l8) {
            l8 = true;
        } else {
            l8 = l4 == INT32_C(5);
        }
        if (l8) {
            l8 = true;
        } else {
            l8 = l4 == INT32_C(6);
        }
        if (l8) {
            l8 = true;
        } else {
            l8 = l4 == INT32_C(7);
        }
        if (l8) {
            l8 = true;
        } else {
            l8 = l4 == INT32_C(8);
        }
        if (l8) {
            l8 = true;
        } else {
            l8 = l4 == INT32_C(9);
        }
        if (l8) {
            l8 = true;
        } else {
            l8 = l4 == INT32_C(10);
        }
        if (l8) {
            l8 = true;
        } else {
            l8 = l4 == INT32_C(11);
        }
        if (l8) {
            l8 = true;
        } else {
            l8 = l4 == INT32_C(18);
        }
        if (l8) {
            l8 = true;
        } else {
            l8 = l4 == INT32_C(19);
        }
        if (l8) {
            l8 = true;
        } else {
            l8 = l4 == INT32_C(20);
        }
        if (!(l8)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l5 = true;
    }
    { bool __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_ranges$learn_difference(void* l0, void* l1, int32_t l2, int32_t l3, int64_t l4) {
    void* l5 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    vader_box_t l6 = vader_box_null();
    int64_t l8;
    uint64_t l10;
    bool t0;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l7, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l6 = vader_midir_ranges$interval_of(l0, l1, l2);
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l5 = l6.payload.obj;
    l6 = vader_midir_ranges$interval_of(l0, l1, l3);
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l7 = l6.payload.obj;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l7)->f_hi_open;
    if (!(t0)) {
        l8 = ((vader_struct_vader_support_integer$Interval_t*) l7)->f_hi;
        l6 = vader_support_integer$checked_add(INT64_C(64), false, l8, l4);
        if (!(l6.tag == 0u)) {
            l8 = ((int64_t) l6.payload.i);
            l9 = vader_support_integer$interval_from_ends(vader_box_obj(0u, NULL), vader_box_i64(339u, l8));
            l6 = vader_support_integer$interval_meet(l5, l9);
            if (l6.tag == 0u) {
                { vader_gc_top = gc_frame.prev; return false; }
            }
            l9 = l6.payload.obj;
            vader_midir_ranges$set_interval(l0, l1, l2, l9);
        }
    }
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l5)->f_lo_open;
    if (!(t0)) {
        l8 = ((vader_struct_vader_support_integer$Interval_t*) l5)->f_lo;
        l6 = vader_support_integer$checked_sub(INT64_C(64), false, l8, l4);
        if (!(l6.tag == 0u)) {
            t1 = ((int64_t) l6.payload.i);
            l9 = vader_support_integer$interval_from_ends(vader_box_i64(339u, t1), vader_box_obj(0u, NULL));
            l6 = vader_support_integer$interval_meet(l7, l9);
            if (l6.tag == 0u) {
                { vader_gc_top = gc_frame.prev; return false; }
            }
            l5 = l6.payload.obj;
            vader_midir_ranges$set_interval(l0, l1, l3, l5);
        }
    }
    l10 = vader_midir_ranges$fact_key(l2, l3);
    vader_midir_ranges$add_fact(l1, l10, l4);
    { vader_gc_top = gc_frame.prev; return true; }
}

static bool vader_midir_ranges$learn_equal(void* l0, void* l1, int32_t l2, int32_t l3) {
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_midir_ranges$learn_difference(l0, l1, l2, l3, INT64_C(0));
    if (t0) {
        t0 = vader_midir_ranges$learn_difference(l0, l1, l3, l2, INT64_C(0));
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_midir_ranges$learn_order(void* l0, void* l1, int32_t l2, int32_t l3, int64_t l4, bool l5) {
    int64_t l6;
    int64_t t0;
    bool t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l5)) {
        t0 = vader_chk_neg(i64, l4);
        l6 = vader_chk_sub(i64, t0, INT64_C(1));
        t1 = vader_midir_ranges$learn_difference(l0, l1, l3, l2, l6);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_midir_ranges$learn_difference(l0, l1, l2, l3, l4);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_ranges$length_mentions(int32_t l0, int32_t l1, int32_t l2) {
    bool t0;
    t0 = vader_midir$LocalId$std_core$Equals$equals(l0, l2);
    if (t0) {
        return true;
    }
    t0 = vader_midir$LocalId$std_core$Equals$equals(l1, l2);
    return t0;
}

static uint64_t vader_midir_ranges$local_bits(int32_t l0) {
    return (uint64_t) (int64_t) ((int64_t) (uint32_t) l0);
}

static vader_string_t vader_midir_ranges$local_name(void* l0, int32_t l1) {
    void* l2;
    int32_t l3;
    void* t0;
    vader_string_t t1;
    l2 = ((vader_struct_vader_midir_ranges$RangeContext_t*) l0)->f_locals;
    l3 = l1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    t1 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_name;
    return t1;
}

static void* vader_midir_ranges$loop_headers(void* l0, void* l1) {
    int64_t l2, l6, l11, l12;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    int32_t l8, l9, l13, l14, l15;
    int32_t t0;
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l4, &l5, &l7, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks)->length;
    l3 = vader_midir$rpo_positions(l1, l2);
    vader_array_t* _a0_arr = vader_array_new(19u, 1u, 12u, 333u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    l4 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l2);
    l4 = (void*) _a1_arr;
    l5 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l2 = ((vader_array_t*) l5)->length;
    l6 = INT64_C(0);
    while ((l6 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l8 = ((vader_struct_vader_midir$BasicBlock_t*) l7)->f_id;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
        l9 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l8];
        if ((l9 < INT32_C(0))) {
            l6 = (l6 + INT64_C(1));
            continue;
        }
        l10 = vader_midir$successors_of(l7);
        l11 = ((vader_array_t*) l10)->length;
        l12 = INT64_C(0);
        while ((l12 < l11)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            l13 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l12];
            l14 = l13;
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l14)
            t0 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l14];
            if ((t0 <= l9)) {
                l15 = l13;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l15)
                ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l15] = (uint8_t) true;
            }
            l12 = (l12 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_midir_ranges$mark_block(void* l0, void* l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    int64_t l3, l4, l6;
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null();
    int32_t l9;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l5, &l7 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(268u, 0u, 13u, 2082u);
    l2 = (void*) _a0_arr;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_instructions)->length;
    while ((l3 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_instructions);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        l6 = vader_midir$pos_key(((vader_struct_vader_midir$BasicBlock_t*) l0)->f_id, l3);
        t0 = std_collections$MutableSet$std_core$Contains$contains__i64(l1, l6);
        if (t0) {
            l7 = vader_midir_ranges$marked_safe(l5);
            vader_array_push_ref((vader_array_t*) l2, l7.payload.obj);
        } else {
            vader_array_push_ref((vader_array_t*) l2, l5.payload.obj);
        }
        l3 = (l3 + INT64_C(1));
    }
    l8 = l0;
    l9 = ((vader_struct_vader_midir$BasicBlock_t*) l8)->f_id;
    l5 = ((vader_struct_vader_midir$BasicBlock_t*) l8)->f_terminator;
    l8 = ((vader_struct_vader_midir$BasicBlock_t*) l8)->f_span;
    vader_struct_vader_midir$BasicBlock_t* _a2_obj = (vader_struct_vader_midir$BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$BasicBlock_t));
    vader_obj_header_init(_a2_obj, 1304u);
    _a2_obj->f_id = l9;
    _a2_obj->f_instructions = l2;
    _a2_obj->f_terminator = l5;
    _a2_obj->f_span = l8;
    t1 = (void*) _a2_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_midir_ranges$mark_in_function(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    vader_string_t l4 = 0;
    vader_box_t l6 = vader_box_null();
    int32_t l9;
    int64_t l11, l12;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l5, &l7, &l8, &l10, &l13, &l14, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_midir_ranges$proven_accesses(l0, l1);
    t0 = std_collections$len__i64(l2);
    if (t0 == INT64_C(0)) {
        l3 = l0;
        l4 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_mangled;
        l5 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_params;
        l6 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_return_type;
        l7 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_locals;
        l8 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_blocks;
        l9 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_entry;
        l10 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_origin;
        l3 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_scalarised_results;
        vader_struct_vader_midir$CFGFunction_t* _a0_obj = (vader_struct_vader_midir$CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGFunction_t));
        vader_obj_header_init(_a0_obj, 1306u);
        _a0_obj->f_mangled = l4;
        _a0_obj->f_params = l5;
        _a0_obj->f_return_type = l6;
        _a0_obj->f_locals = l7;
        _a0_obj->f_blocks = l8;
        _a0_obj->f_entry = l9;
        _a0_obj->f_origin = l10;
        _a0_obj->f_scalarised_results = l3;
        t1 = (void*) _a0_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l0;
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_mangled;
    l5 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_params;
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_return_type;
    l7 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_locals;
    l8 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    vader_struct___lambda_env_vader_midir_ranges_5_t* _a1_obj = (vader_struct___lambda_env_vader_midir_ranges_5_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_ranges_5_t));
    vader_obj_header_init(_a1_obj, 441u);
    _a1_obj->f_cap_0 = l2;
    l2 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(201u, 0u, 13u, 1304u);
    l10 = (void*) _a2_arr;
    l11 = ((vader_array_t*) l8)->length;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l10, (int64_t) l11);
    l10 = (void*) _a3_arr;
    l11 = ((vader_array_t*) l8)->length;
    l12 = INT64_C(0);
    while ((l12 < l11)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        l13 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l12);
        l14 = __lambda_vader_midir_ranges_4(l2, l13);
        vader_array_push_ref((vader_array_t*) l10, l14);
        l12 = (l12 + INT64_C(1));
    }
    l9 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_entry;
    l2 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_origin;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l3)->f_scalarised_results;
    vader_struct_vader_midir$CFGFunction_t* _a5_obj = (vader_struct_vader_midir$CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGFunction_t));
    vader_obj_header_init(_a5_obj, 1306u);
    _a5_obj->f_mangled = l4;
    _a5_obj->f_params = l5;
    _a5_obj->f_return_type = l6;
    _a5_obj->f_locals = l7;
    _a5_obj->f_blocks = l10;
    _a5_obj->f_entry = l9;
    _a5_obj->f_origin = l2;
    _a5_obj->f_scalarised_results = l3;
    t1 = (void*) _a5_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_midir_ranges$mark_proven_accesses(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    int64_t l6, l7, l15, l17, l18;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[19] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l10, &l11, &l12, &l13, &l14, &l16, &l19, &l20, &l21, &l24,
        &l25, &l26, &t0,
    };
    vader_string_t* gc_atom_roots[4] = { &l8, &l9, &l22, &l23 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 19u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_midir$summarise_array_shrinking(l0);
    l1 = vader_midir$shrink_predicate(t0);
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 533u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    l3 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
        t1 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l6];
        l8 = t1.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        l3 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        l9 = l8;
        l10 = l3;
        l12 = ((vader_struct_vader_midir$CFGModule_t*) l10)->f_functions;
        vader_struct___lambda_env_vader_midir_ranges_2_t* _a6_obj = (vader_struct___lambda_env_vader_midir_ranges_2_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_ranges_2_t));
        vader_obj_header_init(_a6_obj, 440u);
        _a6_obj->f_cap_0 = l1;
        l13 = (void*) _a6_obj;
        vader_array_t* _a7_arr = vader_array_new(203u, 0u, 13u, 1306u);
        l14 = (void*) _a7_arr;
        l15 = ((vader_array_t*) l12)->length;
        vader_array_t* _a8_arr = vader_array_repeat((vader_array_t*) l14, (int64_t) l15);
        l16 = (void*) _a8_arr;
        l17 = ((vader_array_t*) l12)->length;
        l18 = INT64_C(0);
        while ((l18 < l17)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l18)
            l19 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l18);
            l20 = __lambda_vader_midir_ranges_1(l13, l19);
            vader_array_push_ref((vader_array_t*) l16, l20);
            l18 = (l18 + INT64_C(1));
        }
        l11 = l16;
        l21 = l10;
        l22 = ((vader_struct_vader_midir$CFGModule_t*) l21)->f_module_id;
        l23 = ((vader_struct_vader_midir$CFGModule_t*) l21)->f_display_path;
        l24 = ((vader_struct_vader_midir$CFGModule_t*) l21)->f_externs;
        l25 = ((vader_struct_vader_midir$CFGModule_t*) l21)->f_struct_decls;
        vader_struct_vader_midir$CFGModule_t* _a10_obj = (vader_struct_vader_midir$CFGModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGModule_t));
        vader_obj_header_init(_a10_obj, 1308u);
        _a10_obj->f_module_id = l22;
        _a10_obj->f_display_path = l23;
        _a10_obj->f_functions = l11;
        _a10_obj->f_externs = l24;
        _a10_obj->f_struct_decls = l25;
        l26 = (void*) _a10_obj;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l2, l9, vader_ref_box(l26));
        l6 = (l6 + INT64_C(1));
    }
    l1 = l0;
    l3 = ((vader_struct_vader_midir$CFGProject_t*) l1)->f_vtable_entries;
    l4 = ((vader_struct_vader_midir$CFGProject_t*) l1)->f_strings;
    l5 = ((vader_struct_vader_midir$CFGProject_t*) l1)->f_data_pool;
    l10 = ((vader_struct_vader_midir$CFGProject_t*) l1)->f_globals;
    l1 = ((vader_struct_vader_midir$CFGProject_t*) l1)->f_trait_membership;
    vader_struct_vader_midir$CFGProject_t* _a11_obj = (vader_struct_vader_midir$CFGProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGProject_t));
    vader_obj_header_init(_a11_obj, 1310u);
    _a11_obj->f_modules = l2;
    _a11_obj->f_vtable_entries = l3;
    _a11_obj->f_strings = l4;
    _a11_obj->f_data_pool = l5;
    _a11_obj->f_globals = l10;
    _a11_obj->f_trait_membership = l1;
    t0 = (void*) _a11_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_ranges$marked_safe(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    int32_t l3, l4, l6;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l5 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1328u) {
        l1 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir$InstrArrayGet_t*) l1)->f_span;
        l3 = ((vader_struct_vader_midir$InstrArrayGet_t*) l1)->f_dst;
        l4 = ((vader_struct_vader_midir$InstrArrayGet_t*) l1)->f_target;
        l5 = ((vader_struct_vader_midir$InstrArrayGet_t*) l1)->f_type;
        l6 = ((vader_struct_vader_midir$InstrArrayGet_t*) l1)->f_index;
        vader_struct_vader_midir$InstrArrayGet_t* _a0_obj = (vader_struct_vader_midir$InstrArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArrayGet_t));
        vader_obj_header_init(_a0_obj, 1328u);
        _a0_obj->f_span = l2;
        _a0_obj->f_dst = l3;
        _a0_obj->f_target = l4;
        _a0_obj->f_type = l5;
        _a0_obj->f_index = l6;
        _a0_obj->f_bounds_safe = true;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 1332u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l0.payload.obj;
    l2 = ((vader_struct_vader_midir$InstrArraySet_t*) l1)->f_span;
    l3 = ((vader_struct_vader_midir$InstrArraySet_t*) l1)->f_target;
    l4 = ((vader_struct_vader_midir$InstrArraySet_t*) l1)->f_index;
    l6 = ((vader_struct_vader_midir$InstrArraySet_t*) l1)->f_value;
    vader_struct_vader_midir$InstrArraySet_t* _a1_obj = (vader_struct_vader_midir$InstrArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArraySet_t));
    vader_obj_header_init(_a1_obj, 1332u);
    _a1_obj->f_span = l2;
    _a1_obj->f_target = l3;
    _a1_obj->f_index = l4;
    _a1_obj->f_value = l6;
    _a1_obj->f_bounds_safe = true;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_ranges$may_prove_an_access(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    int64_t l6, l7, l8, l9, l15, l16;
    vader_box_t l10 = vader_box_null(), l13 = vader_box_null(), l14 = vader_box_null();
    int32_t l11, l12;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[3] = { &l10, &l13, &l14 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
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
    vader_array_t* _a6_arr = vader_array_new(23u, 0u, 8u, 339u);
    l3 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a7_arr;
    vader_struct_std_collections$MutableMap__i32__i64_t* _a8_obj = (vader_struct_std_collections$MutableMap__i32__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__i64_t));
    vader_obj_header_init(_a8_obj, 465u);
    _a8_obj->f_ekeys = l2;
    _a8_obj->f_evals = l3;
    _a8_obj->f_index = l4;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_grow_at = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a8_obj;
    vader_array_t* _a9_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(19u, 0u, 12u, 333u);
    l4 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a11_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a12_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a12_obj, 462u);
    _a12_obj->f_ekeys = l3;
    _a12_obj->f_evals = l4;
    _a12_obj->f_index = l5;
    _a12_obj->f_mask = INT64_C(0);
    _a12_obj->f_grow_at = INT64_C(0);
    _a12_obj->f_size = INT64_C(0);
    _a12_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a12_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a13_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a13_obj, 605u);
    _a13_obj->f_inner = t0;
    l3 = (void*) _a13_obj;
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l6 = ((vader_array_t*) l4)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a14_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        t0 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l7);
        l5 = ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_instructions;
        l8 = ((vader_array_t*) l5)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            l10 = vader_array_ref_load_box(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l9);
            if (l10.tag == 1329u) {
                t0 = l10.payload.obj;
                l11 = ((vader_struct_vader_midir$InstrArrayLen_t*) t0)->f_target;
                std_collections$add__vader_midir$LocalId(l1, l11);
            }
            l13 = vader_midir_ranges$indexed_array(l10);
            if (l13.tag == 0u) {
                l9 = (l9 + INT64_C(1));
                continue;
            }
            l12 = ((int32_t) l13.payload.i);
            l14 = std_collections$MutableMap$std_core$Index$at__i32__i64(l2, l12);
            if (l14.tag == 0u) {
                l15 = INT64_C(0);
            } else {
                l15 = ((int64_t) l14.payload.i);
            }
            l16 = vader_chk_add(i64, l15, INT64_C(1));
            std_collections$MutableMap$std_core$IndexSet$set_at__i32__i64(l2, l12, l16);
            t1 = vader_midir_ranges$is_checked_access(l10);
            if (t1) {
                std_collections$add__vader_midir$LocalId(l3, l12);
            }
            l9 = (l9 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    l4 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l3)->f_inner)->f_ekeys;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l3)->f_inner)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l6)
        l11 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l6];
        t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l1, l11);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l10 = std_collections$MutableMap$std_core$Index$at__i32__i64(l2, l11);
        if (l10.tag == 0u) {
            l8 = INT64_C(0);
        } else {
            l8 = ((int64_t) l10.payload.i);
        }
        if ((l8 > INT64_C(1))) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_midir_ranges$merge_into(void* l0, void* l1, int32_t l2, void* l3) {
    int32_t l4, l9;
    vader_box_t l5 = vader_box_null();
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* t0 = NULL;
    bool t1, t2;
    int32_t t3;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l6, &l7, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = l2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_ranges$RangeFlow_t*) l1)->f_states);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    if (l5.tag == 0u) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_ranges$RangeFlow_t*) l1)->f_states);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4, l3);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_ranges$RangeFlow_t*) l1)->f_dirty);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4] = (uint8_t) true;
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = l5.payload.obj;
    t1 = vader_midir_ranges$range_state_covers(t0, l3);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = l5.payload.obj;
    l6 = vader_midir_ranges$join_range_states(t0, l3);
    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_ranges$RangeFlow_t*) l1)->f_headers);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
    t1 = ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
    t2 = t1;
    if (t2) {
        l7 = l5.payload.obj;
        l8 = vader_midir_ranges$widening_thresholds(l1, l4);
        vader_midir_ranges$widen_range_states(l7, l6, l8);
    }
    vader_midir_ranges$settle_intervals(l0, l6);
    t0 = l5.payload.obj;
    t1 = vader_midir_ranges$same_range_state(t0, l6);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_ranges$RangeFlow_t*) l1)->f_headers);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
    t1 = ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4];
    t2 = t1;
    if (t2) {
        l7 = ((vader_struct_vader_midir_ranges$RangeFlow_t*) l1)->f_widenings;
        vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_ranges$RangeFlow_t*) l1)->f_widenings);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
        t3 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4];
        l9 = vader_chk_add(i32, t3, INT32_C(1));
        vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l4)
        ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l4] = (int32_t) l9;
    }
    vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_ranges$RangeFlow_t*) l1)->f_states);
    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l4)
    vader_array_ref_store(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l4, l6);
    VADER_WRITE_BARRIER(_a7_slotarr->buf);
    vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_ranges$RangeFlow_t*) l1)->f_dirty);
    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l4)
    ((uint8_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l4] = (uint8_t) true;
    { vader_gc_top = gc_frame.prev; return true; }
}

static uint8_t vader_midir_ranges$negation_verdict(void* l0, void* l1, void* l2) {
    int32_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    bool l9;
    void* t0 = NULL;
    uint8_t t1;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l6, &l7, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir$InstrUnOp_t*) l2)->f_dst;
    l4 = vader_midir_ranges$type_of(l0, l3);
    l3 = ((vader_struct_vader_midir$InstrUnOp_t*) l2)->f_operand;
    l5 = vader_midir_ranges$interval_of(l0, l1, l3);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 2; }
    }
    if (!(l5.tag == 0u)) {
        t0 = l5.payload.obj;
        l6 = vader_support_integer$interval_negate(t0);
        l7 = l4.payload.obj;
        l8 = l4.payload.obj;
        l9 = vader_support_integer$interval_within(l6, l8);
        t1 = vader_midir_ranges$overflow_verdict(l6, l7, l9);
        { uint8_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 2; }
}

static void* vader_midir_ranges$new_range_state(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 459u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l0 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(27u, 0u, 4u, 343u);
    l1 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(23u, 0u, 8u, 339u);
    l2 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a6_arr;
    vader_struct_std_collections$MutableMap__u64__i64_t* _a7_obj = (vader_struct_std_collections$MutableMap__u64__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__u64__i64_t));
    vader_obj_header_init(_a7_obj, 592u);
    _a7_obj->f_ekeys = l1;
    _a7_obj->f_evals = l2;
    _a7_obj->f_index = l3;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a10_arr;
    vader_struct_std_collections$MutableMap__i32__i32_t* _a11_obj = (vader_struct_std_collections$MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__i32_t));
    vader_obj_header_init(_a11_obj, 463u);
    _a11_obj->f_ekeys = l2;
    _a11_obj->f_evals = l3;
    _a11_obj->f_index = l4;
    _a11_obj->f_mask = INT64_C(0);
    _a11_obj->f_grow_at = INT64_C(0);
    _a11_obj->f_size = INT64_C(0);
    _a11_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a11_obj;
    vader_struct_vader_midir_ranges$RangeState_t* _a12_obj = (vader_struct_vader_midir_ranges$RangeState_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ranges$RangeState_t));
    vader_obj_header_init(_a12_obj, 1385u);
    _a12_obj->f_intervals = l0;
    _a12_obj->f_differences = l1;
    _a12_obj->f_lengths = l2;
    t0 = (void*) _a12_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_ranges$non_negative_bound(void* l0) {
    int64_t l1;
    bool l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
    if (!((t0 < INT64_C(0)))) {
        l1 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi;
        l2 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_open;
        vader_struct_vader_support_integer$Interval_t* _a0_obj = (vader_struct_vader_support_integer$Interval_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_integer$Interval_t));
        vader_obj_header_init(_a0_obj, 1403u);
        _a0_obj->f_lo = INT64_C(0);
        _a0_obj->f_hi = l1;
        _a0_obj->f_lo_open = false;
        _a0_obj->f_hi_open = l2;
        _a0_obj->f_hi_past = (uint64_t) 0;
        t1 = (void*) _a0_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = (void*) &vader_data_48;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_ranges$on_integers(void* l0, vader_box_t l1) {
    int32_t l2;
    void* t0;
    vader_box_t t1;
    if (l1.tag == 1334u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_lhs;
        t1 = vader_midir_ranges$type_of(l0, l2);
        if (t1.tag == 0u) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_rhs;
        t1 = vader_midir_ranges$type_of(l0, l2);
        if (!(t1.tag == 0u)) {
            t0 = l1.payload.obj;
            return vader_ref_box(t0);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

static uint8_t vader_midir_ranges$overflow_verdict(void* l0, void* l1, bool l2) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_support_integer$interval_meet(l0, l1);
    if (t0.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 3; }
    }
    if (!(l2)) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 2; }
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 1; }
}

static void* vader_midir_ranges$proven_accesses(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6, l8, l9;
    int32_t l7;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 8u, 339u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(19u, 0u, 12u, 333u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i64__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i64__bool_t));
    vader_obj_header_init(_a3_obj, 508u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i64_t* _a4_obj = (vader_struct_std_collections$MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i64_t));
    vader_obj_header_init(_a4_obj, 606u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    t1 = vader_midir_ranges$may_prove_an_access(l0);
    if (!(t1)) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_midir_ranges$analyse_function_ranges(l0, l1, false);
    l3 = ((vader_struct_vader_midir_ranges$FunctionRanges_t*) t0)->f_sites;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l4 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        if (((vader_struct_vader_midir_ranges$RangeSite_t*) l4)->f_verdict == INT32_C(1)) {
            l7 = ((vader_struct_vader_midir_ranges$RangeSite_t*) l4)->f_block;
            l8 = ((vader_struct_vader_midir_ranges$RangeSite_t*) l4)->f_position;
            l9 = vader_midir$pos_key(l7, l8);
            std_collections$add__i64(l2, l9);
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir_ranges$range_context(void* l0, bool l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    int64_t l4, l6;
    vader_box_t l7 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(269u, 0u, 13u, 2111u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    l5 = l0;
    l4 = ((vader_array_t*) l5)->length;
    l6 = INT64_C(0);
    while ((l6 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l7 = vader_core_types$held_values(((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type);
        vader_array_push_ref((vader_array_t*) l3, l7.payload.obj);
        l6 = (l6 + INT64_C(1));
    }
    vader_struct_vader_midir_ranges$RangeContext_t* _a3_obj = (vader_struct_vader_midir_ranges$RangeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ranges$RangeContext_t));
    vader_obj_header_init(_a3_obj, 1382u);
    _a3_obj->f_locals = l0;
    _a3_obj->f_types = l3;
    _a3_obj->f_checked_ops_trap = l1;
    _a3_obj->f_shrinks = l2;
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_ranges$range_state_covers(void* l0, void* l1) {
    void* l2;
    void* l3;
    void* l4;
    void* l9;
    int64_t l5, l6, l12, l14;
    int32_t l7, l8, l15, l16;
    vader_box_t l10;
    uint64_t l11, l13;
    void* t0;
    bool t1;
    int64_t t2;
    int32_t t3;
    l2 = ((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_intervals;
    l3 = ((vader_struct_std_collections$MutableMap__i32__vader_support_integer_Interval_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$MutableMap__i32__vader_support_integer_Interval_t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__i32__vader_support_integer_Interval_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l7 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l8 = l7;
        l9 = l2;
        l10 = std_collections$MutableMap$std_core$Index$at__i32__Any(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_intervals, l8);
        if (l10.tag == 0u) {
            return false;
        }
        t0 = l10.payload.obj;
        t1 = vader_support_integer$interval_within(t0, l9);
        if (!(t1)) {
            return false;
        }
        l5 = (l5 + INT64_C(1));
    }
    l2 = ((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_differences;
    l3 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t2 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
        l11 = (uint64_t) (int64_t) t2;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l12 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
        l13 = l11;
        l14 = l12;
        l10 = std_collections$MutableMap$std_core$Index$at__u64__i64(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_differences, l13);
        if (l10.tag == 0u) {
            return false;
        }
        t2 = ((int64_t) l10.payload.i);
        if ((t2 > l14)) {
            return false;
        }
        l5 = (l5 + INT64_C(1));
    }
    l2 = ((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_lengths;
    l3 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
        l7 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5];
        vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
        l8 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5];
        l15 = l7;
        l16 = l8;
        l10 = std_collections$MutableMap$std_core$Index$at__i32__i32(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_lengths, l15);
        if (l10.tag == 0u) {
            return false;
        }
        t3 = ((int32_t) l10.payload.i);
        t1 = vader_midir$LocalId$std_core$Equals$equals(t3, l16);
        if (!(t1)) {
            return false;
        }
        l5 = (l5 + INT64_C(1));
    }
    return true;
}

static bool vader_midir_ranges$range_state_mentions(void* l0, int32_t l1) {
    void* l2;
    void* l3;
    void* l4;
    int64_t l5, l6;
    uint64_t l7;
    int32_t l8, l9, l10, l11;
    int64_t t0;
    bool t1;
    l2 = ((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_differences;
    l3 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
        l7 = (uint64_t) (int64_t) t0;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
        t1 = vader_midir_ranges$fact_mentions(l7, l1);
        if (t1) {
            return true;
        }
        l5 = (l5 + INT64_C(1));
    }
    l2 = ((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_lengths;
    l3 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l8 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
        vader_array_t* _a3_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l9 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
        l10 = l8;
        l11 = l9;
        t1 = vader_midir_ranges$length_mentions(l10, l11, l1);
        if (t1) {
            return true;
        }
        l5 = (l5 + INT64_C(1));
    }
    return false;
}

static void* vader_midir_ranges$remainder_interval(void* l0, void* l1) {
    int64_t l2, l3;
    int64_t t0;
    bool t1;
    void* t2 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
    if (!((t0 < INT64_C(0)))) {
        t0 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo;
        if (!((t0 < INT64_C(1)))) {
            t1 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi_open;
            if (!(t1)) {
                l2 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi;
                t0 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi;
                l3 = vader_chk_sub(i64, t0, INT64_C(1));
                l2 = vader_support_integer$lesser(l2, l3);
                t2 = vader_support_integer$interval(INT64_C(0), l2);
                { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = vader_midir_ranges$non_negative_bound(l0);
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t2 = (void*) &vader_data_48;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_midir_ranges$report_ranges(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l25 = NULL;
    void* l32 = NULL;
    int64_t l10, l11, l16, l17, l23, l24;
    vader_string_t l26 = 0;
    vader_string_t l27 = 0;
    vader_string_t l28 = 0;
    vader_string_t l29 = 0;
    int32_t l30, l31;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int32_t t2;
    void* t3 = NULL;
    int64_t t4;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[22] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l12, &l13, &l14, &l15, &l18, &l19, &l20,
        &l21, &l22, &l25, &l32, &t3,
    };
    vader_string_t* gc_atom_roots[5] = { &l26, &l27, &l28, &l29, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 22u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_midir$summarise_array_shrinking(l0);
    l2 = vader_midir$shrink_predicate(l1);
    vader_struct_vader_midir_ranges$VerdictCounts_t* _a0_obj = (vader_struct_vader_midir_ranges$VerdictCounts_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ranges$VerdictCounts_t));
    vader_obj_header_init(_a0_obj, 1387u);
    _a0_obj->f_already_safe = INT32_C(0);
    _a0_obj->f_proven = INT32_C(0);
    _a0_obj->f_unproven = INT32_C(0);
    _a0_obj->f_certain_fault = INT32_C(0);
    _a0_obj->f_unreachable = INT32_C(0);
    l3 = (void*) _a0_obj;
    vader_struct_vader_midir_ranges$VerdictCounts_t* _a1_obj = (vader_struct_vader_midir_ranges$VerdictCounts_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ranges$VerdictCounts_t));
    vader_obj_header_init(_a1_obj, 1387u);
    _a1_obj->f_already_safe = INT32_C(0);
    _a1_obj->f_proven = INT32_C(0);
    _a1_obj->f_unproven = INT32_C(0);
    _a1_obj->f_certain_fault = INT32_C(0);
    _a1_obj->f_unreachable = INT32_C(0);
    l4 = (void*) _a1_obj;
    vader_struct_vader_midir_ranges$RangeTally_t* _a2_obj = (vader_struct_vader_midir_ranges$RangeTally_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ranges$RangeTally_t));
    vader_obj_header_init(_a2_obj, 1386u);
    _a2_obj->f_accesses = l3;
    _a2_obj->f_checked = l4;
    _a2_obj->f_gave_up = INT32_C(0);
    l3 = (void*) _a2_obj;
    vader_struct_vader_midir_ranges$VerdictCounts_t* _a3_obj = (vader_struct_vader_midir_ranges$VerdictCounts_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ranges$VerdictCounts_t));
    vader_obj_header_init(_a3_obj, 1387u);
    _a3_obj->f_already_safe = INT32_C(0);
    _a3_obj->f_proven = INT32_C(0);
    _a3_obj->f_unproven = INT32_C(0);
    _a3_obj->f_certain_fault = INT32_C(0);
    _a3_obj->f_unreachable = INT32_C(0);
    l4 = (void*) _a3_obj;
    vader_struct_vader_midir_ranges$VerdictCounts_t* _a4_obj = (vader_struct_vader_midir_ranges$VerdictCounts_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ranges$VerdictCounts_t));
    vader_obj_header_init(_a4_obj, 1387u);
    _a4_obj->f_already_safe = INT32_C(0);
    _a4_obj->f_proven = INT32_C(0);
    _a4_obj->f_unproven = INT32_C(0);
    _a4_obj->f_certain_fault = INT32_C(0);
    _a4_obj->f_unreachable = INT32_C(0);
    l5 = (void*) _a4_obj;
    vader_struct_vader_midir_ranges$RangeTally_t* _a5_obj = (vader_struct_vader_midir_ranges$RangeTally_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ranges$RangeTally_t));
    vader_obj_header_init(_a5_obj, 1386u);
    _a5_obj->f_accesses = l4;
    _a5_obj->f_checked = l5;
    _a5_obj->f_gave_up = INT32_C(0);
    l4 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(29u, 0u, 13u, 349u);
    l5 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(21u, 0u, 0u, 335u);
    l6 = (void*) _a7_arr;
    l7 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_modules;
    l8 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l7)->f_ekeys;
    l9 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l7)->f_evals;
    l10 = INT64_C(0);
    l11 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l7)->f_size;
    while ((l10 < l11)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l10)
        t0 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l10];
        t1 = t0.payload.s;
        vader_array_t* _a9_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l10)
        l7 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l10);
        vader_struct_vader_midir_ranges$VerdictCounts_t* _a10_obj = (vader_struct_vader_midir_ranges$VerdictCounts_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ranges$VerdictCounts_t));
        vader_obj_header_init(_a10_obj, 1387u);
        _a10_obj->f_already_safe = INT32_C(0);
        _a10_obj->f_proven = INT32_C(0);
        _a10_obj->f_unproven = INT32_C(0);
        _a10_obj->f_certain_fault = INT32_C(0);
        _a10_obj->f_unreachable = INT32_C(0);
        l12 = (void*) _a10_obj;
        vader_struct_vader_midir_ranges$VerdictCounts_t* _a11_obj = (vader_struct_vader_midir_ranges$VerdictCounts_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ranges$VerdictCounts_t));
        vader_obj_header_init(_a11_obj, 1387u);
        _a11_obj->f_already_safe = INT32_C(0);
        _a11_obj->f_proven = INT32_C(0);
        _a11_obj->f_unproven = INT32_C(0);
        _a11_obj->f_certain_fault = INT32_C(0);
        _a11_obj->f_unreachable = INT32_C(0);
        l13 = (void*) _a11_obj;
        vader_struct_vader_midir_ranges$RangeTally_t* _a12_obj = (vader_struct_vader_midir_ranges$RangeTally_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_ranges$RangeTally_t));
        vader_obj_header_init(_a12_obj, 1386u);
        _a12_obj->f_accesses = l12;
        _a12_obj->f_checked = l13;
        _a12_obj->f_gave_up = INT32_C(0);
        l14 = (void*) _a12_obj;
        l15 = ((vader_struct_vader_midir$CFGModule_t*) l7)->f_functions;
        l16 = ((vader_array_t*) l15)->length;
        l17 = INT64_C(0);
        while ((l17 < l16)) {
            vader_array_t* _a13_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l17)
            l18 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l17);
            l19 = vader_midir_ranges$analyse_function_ranges(l18, l2, true);
            vader_midir_ranges$tally_function(l14, l19);
            vader_midir_ranges$tally_function(l3, l19);
            l20 = (void*) &vader_fn_static_vader_midir$instruction_runs_code;
            l21 = vader_midir_ranges$analyse_function_ranges(l18, l20, true);
            vader_midir_ranges$tally_function(l4, l21);
            l22 = ((vader_struct_vader_midir_ranges$FunctionRanges_t*) l19)->f_sites;
            l23 = ((vader_array_t*) l22)->length;
            l24 = INT64_C(0);
            while ((l24 < l23)) {
                vader_array_t* _a14_slotarr = ((vader_array_t*) l22);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                l25 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l24);
                if (((vader_struct_vader_midir_ranges$RangeSite_t*) l25)->f_verdict == INT32_C(3)) {
                    l26 = toolchain_span$source_position(((vader_struct_vader_midir_ranges$RangeSite_t*) l25)->f_span);
                    l27 = ((vader_struct_vader_midir_ranges$RangeSite_t*) l25)->f_what;
                    l28 = ((vader_struct_vader_midir_ranges$FunctionRanges_t*) l19)->f_mangled;
                    l29 = concat_7(26u, l26, 971u, l27, 141u, l28, 1u);
                    vader_array_push_scalar((vader_array_t*) l6, vader_box_string(335u, l29));
                }
                l24 = (l24 + INT64_C(1));
            }
            l17 = (l17 + INT64_C(1));
        }
        l30 = vader_midir_ranges$site_count(((vader_struct_vader_midir_ranges$RangeTally_t*) l14)->f_accesses);
        l31 = vader_midir_ranges$site_count(((vader_struct_vader_midir_ranges$RangeTally_t*) l14)->f_checked);
        t2 = vader_chk_add(i32, l30, l31);
        if ((t2 > INT32_C(0))) {
            t1 = ((vader_struct_vader_midir$CFGModule_t*) l7)->f_display_path;
            vader_struct___Tuple_2_471c43984d8ea035_t* _a15_obj = (vader_struct___Tuple_2_471c43984d8ea035_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_471c43984d8ea035_t));
            vader_obj_header_init(_a15_obj, 349u);
            _a15_obj->f__0 = t1;
            _a15_obj->f__1 = l14;
            l32 = (void*) _a15_obj;
            vader_array_push_ref((vader_array_t*) l5, l32);
        }
        l10 = (l10 + INT64_C(1));
    }
    vader_array_t* _a16_arr = vader_array_new(21u, 0u, 0u, 335u);
    t3 = (void*) _a16_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a17_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a17_obj, 618u);
    _a17_obj->f_parts = t3;
    l2 = (void*) _a17_obj;
    std_string__builder$append(l2, 11u);
    l26 = vader_midir_ranges$counts_line(((vader_struct_vader_midir_ranges$RangeTally_t*) l3)->f_accesses);
    l26 = concat_3(35u, l26, 1u);
    std_string__builder$append(l2, l26);
    l26 = vader_midir_ranges$counts_line(((vader_struct_vader_midir_ranges$RangeTally_t*) l3)->f_checked);
    l26 = concat_3(37u, l26, 1u);
    std_string__builder$append(l2, l26);
    l7 = (void*) vader_buffer_new((size_t) INT64_C(54));
    l10 = INT64_C(0);
    l10 = std_core$write_string_at(l7, l10, 38u);
    t2 = ((vader_struct_vader_midir_ranges$RangeTally_t*) l3)->f_gave_up;
    l11 = ((int64_t) (int32_t) t2);
    l10 = std_core$write_int(l7, l10, l11);
    l10 = std_core$write_string_at(l7, l10, 1u);
    l26 = std_core$finish_buffer(l7, l10);
    std_string__builder$append(l2, l26);
    std_string__builder$append(l2, 42u);
    l26 = vader_midir_ranges$counts_line(((vader_struct_vader_midir_ranges$RangeTally_t*) l4)->f_accesses);
    l26 = concat_3(27u, l26, 1u);
    std_string__builder$append(l2, l26);
    l26 = vader_midir_ranges$counts_line(((vader_struct_vader_midir_ranges$RangeTally_t*) l4)->f_checked);
    l26 = concat_3(28u, l26, 1u);
    std_string__builder$append(l2, l26);
    l26 = vader_midir$shrink_summary_line(l1);
    l26 = concat_3(36u, l26, 1u);
    std_string__builder$append(l2, l26);
    std_string__builder$append(l2, 4u);
    l1 = (void*) &vader_fn_static___lambda_vader_midir_ranges_0;
    l1 = std_sort$sort___string__vader_midir_ranges_RangeTally_(l5, l1);
    l10 = ((vader_array_t*) l1)->length;
    l11 = INT64_C(0);
    while ((l11 < l10)) {
        vader_array_t* _a18_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        l3 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l11);
        l26 = ((vader_struct___Tuple_2_471c43984d8ea035_t*) l3)->f__0;
        l27 = vader_midir_ranges$tally_line(((vader_struct___Tuple_2_471c43984d8ea035_t*) l3)->f__1);
        l28 = concat_5(16u, l26, 460u, l27, 1u);
        std_string__builder$append(l2, l28);
        l11 = (l11 + INT64_C(1));
    }
    t4 = ((vader_array_t*) l6)->length;
    if ((t4 > INT64_C(0))) {
        std_string__builder$append(l2, 3u);
        l1 = l6;
        l10 = ((vader_array_t*) l1)->length;
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a19_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            t0 = vader_array_box_slots(_a19_slotarr->buf)[_a19_slotarr->offset + (size_t) l11];
            l26 = t0.payload.s;
            std_string__builder$append(l2, l26);
            l11 = (l11 + INT64_C(1));
        }
    }
    t1 = std_string__builder$StringBuilder$std_core$Display$to_string(l2);
    std_io$eprintln__string(t1);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_midir_ranges$result_fits(void* l0, void* l1, void* l2, uint8_t l3, void* l4, void* l5, void* l6) {
    bool l7;
    int32_t l8, l9;
    void* l10 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l4, &l5, &l6, &l10, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l3 == INT32_C(0)) {
        l8 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_lhs;
        l9 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_rhs;
        l7 = vader_midir_ranges$sum_fits(l0, l1, l8, l4, vader_box_i32(338u, l9), l5, l6);
        { bool __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(1)) {
        l8 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_lhs;
        l10 = vader_support_integer$interval_negate(l5);
        l7 = vader_midir_ranges$sum_fits(l0, l1, l8, l4, vader_box_obj(0u, NULL), l10, l6);
    } else {
        if (!(l3 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = vader_support_integer$interval_mul(l4, l5);
        l7 = vader_support_integer$interval_within(t0, l6);
    }
    { bool __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_ranges$same_range_state(void* l0, void* l1) {
    int64_t l2, l3, l13, l15;
    void* l4;
    void* l5;
    void* l6;
    void* l9;
    void* l10;
    int32_t l7, l8, l16, l17;
    vader_box_t l11;
    uint64_t l12, l14;
    bool t0;
    int64_t t1;
    int32_t t2;
    l2 = std_collections$len__i32__Any(((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_intervals);
    l3 = std_collections$len__i32__Any(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_intervals);
    if (l2 != l3) {
        return false;
    }
    l2 = std_collections$len__u64__i64(((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_differences);
    l3 = std_collections$len__u64__i64(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_differences);
    if (l2 != l3) {
        return false;
    }
    l2 = std_collections$len__i32__i32(((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_lengths);
    l3 = std_collections$len__i32__i32(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_lengths);
    if (l2 != l3) {
        return false;
    }
    l4 = ((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_intervals;
    l5 = ((vader_struct_std_collections$MutableMap__i32__vader_support_integer_Interval_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections$MutableMap__i32__vader_support_integer_Interval_t*) l4)->f_evals;
    l2 = INT64_C(0);
    l3 = ((vader_struct_std_collections$MutableMap__i32__vader_support_integer_Interval_t*) l4)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l7 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        l8 = l7;
        l9 = l4;
        l11 = std_collections$MutableMap$std_core$Index$at__i32__Any(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_intervals, l8);
        if (l11.tag == 0u) {
            return false;
        }
        l10 = l11.payload.obj;
        t0 = vader_support_integer$same_interval(l9, l10);
        if (!(t0)) {
            return false;
        }
        l2 = (l2 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_differences;
    l5 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l4)->f_evals;
    l2 = INT64_C(0);
    l3 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l4)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        t1 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l2];
        l12 = (uint64_t) (int64_t) t1;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l2)
        l13 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l2];
        l14 = l12;
        l15 = l13;
        l11 = std_collections$MutableMap$std_core$Index$at__u64__i64(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_differences, l14);
        if (l11.tag == 0u) {
            return false;
        }
        t1 = ((int64_t) l11.payload.i);
        if (t1 != l15) {
            return false;
        }
        l2 = (l2 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_lengths;
    l5 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l4)->f_evals;
    l2 = INT64_C(0);
    l3 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l4)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l2)
        l7 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l2];
        vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l2)
        l8 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l2];
        l16 = l7;
        l17 = l8;
        l11 = std_collections$MutableMap$std_core$Index$at__i32__i32(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_lengths, l16);
        if (l11.tag == 0u) {
            return false;
        }
        t2 = ((int32_t) l11.payload.i);
        t0 = vader_midir$LocalId$std_core$Equals$equals(t2, l17);
        if (!(t0)) {
            return false;
        }
        l2 = (l2 + INT64_C(1));
    }
    return true;
}

static void vader_midir_ranges$set_interval(void* l0, void* l1, int32_t l2, void* l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    vader_box_t l5 = vader_box_null();
    bool l6;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l4, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = vader_midir_ranges$type_of(l0, l2);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = l5.payload.obj;
    l5 = vader_support_integer$interval_meet(l3, l4);
    if (l5.tag == 0u) {
        l6 = true;
    } else {
        t0 = l5.payload.obj;
        l6 = vader_support_integer$same_interval(t0, l4);
    }
    if (!(l6)) {
        l4 = ((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_intervals;
        l7 = l5.payload.obj;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l4, l2, vader_ref_box(l7));
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_collections$remove__vader_midir$LocalId__vader_support_integer_Interval(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_intervals, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_ranges$set_result(void* l0, void* l1, int32_t l2, void* l3) {
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_midir_ranges$forget_local(l1, l2);
    vader_midir_ranges$set_interval(l0, l1, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_ranges$settle_intervals(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    int64_t l6, l7;
    int32_t l8, l9;
    vader_box_t l12 = vader_box_null();
    bool l13;
    bool t0;
    vader_box_t* gc_roots[1] = { &l12 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l10, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_intervals;
    l4 = ((vader_struct_std_collections$MutableMap__i32__vader_support_integer_Interval_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__i32__vader_support_integer_Interval_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__i32__vader_support_integer_Interval_t*) l3)->f_size;
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
        l12 = vader_midir_ranges$type_of(l0, l9);
        if (!(l12.tag == 0u)) {
            l11 = l12.payload.obj;
            t0 = vader_support_integer$interval_within(l10, l11);
            if (!(t0)) {
                l13 = true;
            } else {
                l13 = vader_support_integer$same_interval(l10, l11);
            }
            if (l13) {
                vader_array_push_i32((vader_array_t*) l2, l9);
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    l6 = ((vader_array_t*) l2)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l8 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
        l12 = std_collections$MutableMap$std_core$Index$at__i32__Any(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_intervals, l8);
        if (l12.tag == 0u) {
            l7 = (l7 + INT64_C(1));
            continue;
        }
        l3 = l12.payload.obj;
        vader_midir_ranges$set_interval(l0, l1, l8, l3);
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_ranges$shift_local(void* l0, void* l1, int32_t l2, int32_t l3, int64_t l4, void* l5) {
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    int64_t l11, l12, l14, l16, l17, l21;
    uint64_t l13, l15, l20, l23;
    vader_box_t l18 = vader_box_null(), l22 = vader_box_null();
    int32_t l19;
    int64_t t0;
    int32_t t1;
    bool t2;
    vader_box_t* gc_roots[2] = { &l18, &l22 };
    void** gc_raw_roots[8] = { &l0, &l1, &l5, &l6, &l7, &l8, &l9, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 4u, 343u);
    l6 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(23u, 0u, 8u, 339u);
    l7 = (void*) _a1_arr;
    l8 = ((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_differences;
    l9 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l8)->f_ekeys;
    l10 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l8)->f_evals;
    l11 = INT64_C(0);
    l12 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l8)->f_size;
    while ((l11 < l12)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l11)
        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l11];
        l13 = (uint64_t) (int64_t) t0;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l11)
        l14 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l11];
        l15 = l13;
        l16 = l14;
        {
            t1 = vader_midir_ranges$fact_left(l15);
            t2 = vader_midir$LocalId$std_core$Equals$equals(t1, l3);
            if (t2) {
                l18 = vader_support_integer$checked_add(INT64_C(64), false, l16, l4);
                if (l18.tag == 0u) goto end_32;
                l17 = ((int64_t) l18.payload.i);
                l19 = vader_midir_ranges$fact_right(l15);
                l20 = vader_midir_ranges$fact_key(l2, l19);
                vader_array_push_i64((vader_array_t*) l6, (int64_t) (uint64_t) l20);
                vader_array_push_i64((vader_array_t*) l7, l17);
            } else {
                t1 = vader_midir_ranges$fact_right(l15);
                t2 = vader_midir$LocalId$std_core$Equals$equals(t1, l3);
                if (t2) {
                    l22 = vader_support_integer$checked_sub(INT64_C(64), false, l16, l4);
                    if (l22.tag == 0u) goto end_32;
                    l21 = ((int64_t) l22.payload.i);
                    t1 = vader_midir_ranges$fact_left(l15);
                    l23 = vader_midir_ranges$fact_key(t1, l2);
                    vader_array_push_i64((vader_array_t*) l6, (int64_t) (uint64_t) l23);
                    vader_array_push_i64((vader_array_t*) l7, l21);
                }
            }
        } end_32: ;
        l11 = (l11 + INT64_C(1));
    }
    l18 = std_collections$MutableMap$std_core$Index$at__i32__i32(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_lengths, l3);
    vader_midir_ranges$set_result(l0, l1, l2, l5);
    l11 = INT64_C(0);
    l12 = ((vader_array_t*) l6)->length;
    while ((l11 < l12)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l11];
        l13 = (uint64_t) (int64_t) t0;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l11)
        l14 = ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l11];
        vader_midir_ranges$add_fact(l1, l13, l14);
        l11 = (l11 + INT64_C(1));
    }
    l13 = vader_midir_ranges$fact_key(l2, l3);
    vader_midir_ranges$add_fact(l1, l13, l4);
    l22 = vader_support_integer$checked_negation(INT64_C(64), false, l4);
    if (!(l22.tag == 0u)) {
        l13 = vader_midir_ranges$fact_key(l3, l2);
        l11 = ((int64_t) l22.payload.i);
        vader_midir_ranges$add_fact(l1, l13, l11);
    }
    if (l18.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if ((l4 <= INT64_C(0))) {
        l6 = ((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_lengths;
        l19 = ((int32_t) l18.payload.i);
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__i32(l6, l2, l19);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_midir_ranges$site_count(void* l0) {
    int32_t l1, l2;
    int32_t t0;
    l1 = ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_already_safe;
    l2 = ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_proven;
    l1 = vader_chk_add(i32, l1, l2);
    l2 = ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_unproven;
    l1 = vader_chk_add(i32, l1, l2);
    l2 = ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_certain_fault;
    l1 = vader_chk_add(i32, l1, l2);
    l2 = ((vader_struct_vader_midir_ranges$VerdictCounts_t*) l0)->f_unreachable;
    t0 = vader_chk_add(i32, l1, l2);
    return t0;
}

static vader_string_t vader_midir_ranges$site_label(void* l0, vader_box_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    int32_t l3;
    void* l6 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l6, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l4, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1328u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_target;
        l2 = vader_midir_ranges$local_name(l0, l3);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_index;
        l4 = vader_midir_ranges$local_name(l0, l3);
        l2 = concat_4(l2, 966u, l4, 969u);
        { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1332u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_target;
        l4 = vader_midir_ranges$local_name(l0, l3);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_index;
        l5 = vader_midir_ranges$local_name(l0, l3);
        l2 = concat_4(l4, 966u, l5, 972u);
    } else if (l1.tag == 1334u) {
        l6 = l1.payload.obj;
        l2 = vader_midir_ranges$binop_label(l0, l6);
    } else {
        if (!(l1.tag == 1357u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_operand;
        l4 = vader_midir_ranges$local_name(l0, l3);
        l2 = concat_2(383u, l4);
    }
    { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_ranges$site_of(void* l0, vader_box_t l1) {
    int32_t l2;
    void* t0;
    bool t1;
    vader_box_t t2;
    if ((l1.tag == 1328u || l1.tag == 1332u)) {
        return l1;
    }
    if (l1.tag == 1334u) {
        t0 = l1.payload.obj;
        t1 = vader_midir_ranges$is_checked(((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_op);
        if (t1) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_dst;
            t2 = vader_midir_ranges$type_of(l0, l2);
            if (!(t2.tag == 0u)) {
                t0 = l1.payload.obj;
                return vader_ref_box(t0);
            }
        }
    }
    if (l1.tag == 1357u) {
        t0 = l1.payload.obj;
        if (((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_op == INT32_C(0)) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_dst;
            t2 = vader_midir_ranges$type_of(l0, l2);
            if (!(t2.tag == 0u)) {
                t0 = l1.payload.obj;
                return vader_ref_box(t0);
            }
            return vader_box_obj(0u, NULL);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

static bool vader_midir_ranges$sum_fits(void* l0, void* l1, int32_t l2, void* l3, vader_box_t l4, void* l5, void* l6) {
    void* l7 = NULL;
    bool l8, l11, l12;
    int64_t l9, l10;
    int32_t l13;
    bool t0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l5, &l6, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l7 = vader_support_integer$interval_add(l3, l5);
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l7)->f_hi_open;
    if (!(t0)) {
        l9 = ((vader_struct_vader_support_integer$Interval_t*) l7)->f_hi;
        l10 = ((vader_struct_vader_support_integer$Interval_t*) l6)->f_hi;
        l8 = (l9 <= l10);
    } else {
        l8 = false;
    }
    if (l8) {
        l8 = true;
    } else {
        l8 = vader_midir_ranges$held_below_top(l0, l1, l2, l3, l5, l6);
    }
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l7)->f_lo_open;
    if (!(t0)) {
        l9 = ((vader_struct_vader_support_integer$Interval_t*) l7)->f_lo;
        l10 = ((vader_struct_vader_support_integer$Interval_t*) l6)->f_lo;
        l11 = (l9 >= l10);
    } else {
        l11 = false;
    }
    if (l11) {
        l11 = true;
    } else {
        l11 = vader_midir_ranges$held_above_bottom(l0, l1, l2, l5, l6);
    }
    if (!(l4.tag == 0u)) {
        if (l8) {
            l12 = true;
        } else {
            l13 = ((int32_t) l4.payload.i);
            l12 = vader_midir_ranges$held_below_top(l0, l1, l13, l5, l3, l6);
        }
        l8 = l12;
        if (l11) {
            l12 = true;
        } else {
            l13 = ((int32_t) l4.payload.i);
            l12 = vader_midir_ranges$held_above_bottom(l0, l1, l13, l3, l6);
        }
        l11 = l12;
    }
    if (l8) {
        { bool __vret = l11; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void vader_midir_ranges$tally_function(void* l0, void* l1) {
    int32_t l2;
    void* l3;
    void* l6;
    void* l7;
    void* l9;
    int64_t l4, l5;
    uint8_t l8, l10;
    bool t0;
    int32_t t1;
    t0 = ((vader_struct_vader_midir_ranges$FunctionRanges_t*) l1)->f_gave_up;
    if (t0) {
        t1 = ((vader_struct_vader_midir_ranges$RangeTally_t*) l0)->f_gave_up;
        l2 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_midir_ranges$RangeTally_t*) l0)->f_gave_up = l2;
    }
    l3 = ((vader_struct_vader_midir_ranges$FunctionRanges_t*) l1)->f_sites;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t0 = ((vader_struct_vader_midir_ranges$RangeSite_t*) l6)->f_arithmetic;
        if (t0) {
            l7 = ((vader_struct_vader_midir_ranges$RangeTally_t*) l0)->f_checked;
            l8 = ((vader_struct_vader_midir_ranges$RangeSite_t*) l6)->f_verdict;
            vader_midir_ranges$count_verdict(l7, l8);
        } else {
            l9 = ((vader_struct_vader_midir_ranges$RangeTally_t*) l0)->f_accesses;
            l10 = ((vader_struct_vader_midir_ranges$RangeSite_t*) l6)->f_verdict;
            vader_midir_ranges$count_verdict(l9, l10);
        }
        l5 = (l5 + INT64_C(1));
    }
    return;
}

static vader_string_t vader_midir_ranges$tally_line(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    int32_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[3] = { &l4, &l5, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = (void*) vader_buffer_new((size_t) INT64_C(77));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 1513u);
    t0 = ((vader_struct_vader_midir_ranges$VerdictCounts_t*) ((vader_struct_vader_midir_ranges$RangeTally_t*) l0)->f_accesses)->f_proven;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 60u);
    t0 = ((vader_struct_vader_midir_ranges$VerdictCounts_t*) ((vader_struct_vader_midir_ranges$RangeTally_t*) l0)->f_accesses)->f_already_safe;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 64u);
    t0 = vader_midir_ranges$site_count(((vader_struct_vader_midir_ranges$RangeTally_t*) l0)->f_accesses);
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 360u);
    l4 = std_core$finish_buffer(l1, l2);
    l1 = (void*) vader_buffer_new((size_t) INT64_C(51));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 1761u);
    t0 = ((vader_struct_vader_midir_ranges$VerdictCounts_t*) ((vader_struct_vader_midir_ranges$RangeTally_t*) l0)->f_checked)->f_proven;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 64u);
    t0 = vader_midir_ranges$site_count(((vader_struct_vader_midir_ranges$RangeTally_t*) l0)->f_checked);
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    l5 = std_core$finish_buffer(l1, l2);
    t1 = concat_2(l4, l5);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir_ranges$transfer(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    int32_t l4, l5;
    vader_box_t l6 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l2, &l6, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir_ranges$RangeContext_t*) l0)->f_shrinks;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
    t0 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, l2);
    t1 = t0.payload.b;
    if (t1) {
        std_collections$clear__i32__i32(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_lengths);
    }
    if (l2.tag == 1341u) {
        l3 = l2.payload.obj;
        vader_midir_ranges$transfer_constant(l0, l1, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 1353u) {
        t2 = l2.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrMove_t*) t2)->f_dst;
        t2 = l2.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrMove_t*) t2)->f_src;
        vader_midir_ranges$transfer_copy(l0, l1, l4, l5);
    } else if (l2.tag == 1337u) {
        t2 = l2.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrCast_t*) t2)->f_dst;
        t2 = l2.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrCast_t*) t2)->f_value;
        vader_midir_ranges$transfer_copy(l0, l1, l4, l5);
    } else if (l2.tag == 1334u) {
        l3 = l2.payload.obj;
        vader_midir_ranges$transfer_binop(l0, l1, l3);
    } else if (l2.tag == 1357u) {
        l3 = l2.payload.obj;
        vader_midir_ranges$transfer_unop(l0, l1, l3);
    } else if (l2.tag == 1329u) {
        l3 = l2.payload.obj;
        vader_midir_ranges$transfer_length(l0, l1, l3);
    } else if (l2.tag == 1328u) {
        t2 = l2.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrArrayGet_t*) t2)->f_target;
        t2 = l2.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrArrayGet_t*) t2)->f_index;
        vader_midir_ranges$learn_access(l0, l1, l4, l5);
        l3 = l2.payload.obj;
        vader_midir_ranges$forget_written(l1, vader_ref_box(l3));
    } else if (l2.tag == 1332u) {
        t2 = l2.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrArraySet_t*) t2)->f_target;
        t2 = l2.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrArraySet_t*) t2)->f_index;
        vader_midir_ranges$learn_access(l0, l1, l4, l5);
        l3 = l2.payload.obj;
        vader_midir_ranges$forget_written(l1, vader_ref_box(l3));
    } else {
        if (!((l2.tag == 1330u || l2.tag == 1331u || l2.tag == 1333u || l2.tag == 1335u || l2.tag == 1336u || l2.tag == 1338u || l2.tag == 1339u || l2.tag == 1340u || l2.tag == 1342u || l2.tag == 1343u || l2.tag == 1344u || l2.tag == 1345u || l2.tag == 1346u || l2.tag == 1347u || l2.tag == 1348u || l2.tag == 1349u || l2.tag == 1350u || l2.tag == 1351u || l2.tag == 1352u || l2.tag == 1354u || l2.tag == 1355u || l2.tag == 1356u || l2.tag == 1358u || l2.tag == 1359u || l2.tag == 1360u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l6 = l2;
        vader_midir_ranges$forget_written(l1, l6);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_ranges$transfer_arithmetic(void* l0, void* l1, void* l2, uint8_t l3, void* l4, void* l5, void* l6) {
    bool l7;
    int32_t l8, l10;
    void* l9 = NULL;
    int64_t l11;
    vader_box_t l12 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[1] = { &l12 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l4, &l5, &l6, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_midir_ranges$RangeContext_t*) l0)->f_checked_ops_trap;
    if (t0) {
        l7 = vader_midir_ranges$is_checked(((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_op);
    } else {
        l7 = false;
    }
    if (!(l7)) {
        t0 = vader_midir_ranges$result_fits(l0, l1, l2, l3, l4, l5, l6);
        if (!(t0)) {
            l8 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_dst;
            vader_midir_ranges$forget_local(l1, l8);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    l9 = vader_midir_ranges$exact_result(l3, l4, l5);
    if (l3 == INT32_C(0)) {
        t0 = vader_midir_ranges$is_single(l5);
        if (t0) {
            l8 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_dst;
            l10 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_lhs;
            l11 = ((vader_struct_vader_support_integer$Interval_t*) l5)->f_lo;
            vader_midir_ranges$shift_local(l0, l1, l8, l10, l11, l9);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    if (l3 == INT32_C(0)) {
        t0 = vader_midir_ranges$is_single(l4);
        if (t0) {
            l8 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_dst;
            l10 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_rhs;
            l11 = ((vader_struct_vader_support_integer$Interval_t*) l4)->f_lo;
            vader_midir_ranges$shift_local(l0, l1, l8, l10, l11, l9);
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    if (l3 == INT32_C(1)) {
        t0 = vader_midir_ranges$is_single(l5);
        if (t0) {
            l11 = ((vader_struct_vader_support_integer$Interval_t*) l5)->f_lo;
            l12 = vader_support_integer$checked_negation(INT64_C(64), false, l11);
            if (!(l12.tag == 0u)) {
                l8 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_dst;
                l10 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_lhs;
                l11 = ((int64_t) l12.payload.i);
                vader_midir_ranges$shift_local(l0, l1, l8, l10, l11, l9);
                { vader_gc_top = gc_frame.prev; return; }
            }
            l8 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_dst;
            vader_midir_ranges$set_result(l0, l1, l8, l9);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l8 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_dst;
        vader_midir_ranges$set_result(l0, l1, l8, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l8 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_dst;
    vader_midir_ranges$set_result(l0, l1, l8, l9);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_ranges$transfer_binop(void* l0, void* l1, void* l2) {
    int32_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null(), l8 = vader_box_null();
    bool l7;
    uint8_t l9;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    vader_box_t* gc_roots[4] = { &l4, &l5, &l6, &l8 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l10, &l11, &l12 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_dst;
    l4 = vader_midir_ranges$type_of(l0, l3);
    l3 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_lhs;
    l5 = vader_midir_ranges$interval_of(l0, l1, l3);
    l3 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_rhs;
    l6 = vader_midir_ranges$interval_of(l0, l1, l3);
    if (l4.tag == 0u) {
        l7 = true;
    } else {
        l7 = l5.tag == 0u;
    }
    if (l7) {
        l7 = true;
    } else {
        l7 = l6.tag == 0u;
    }
    if (l7) {
        l3 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_dst;
        vader_midir_ranges$forget_local(l1, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l8 = vader_midir_ranges$arithmetic_of(((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_op);
    if (!(l8.tag == 0u)) {
        l9 = ((uint8_t) l8.payload.i);
        l10 = l5.payload.obj;
        l11 = l6.payload.obj;
        l12 = l4.payload.obj;
        vader_midir_ranges$transfer_arithmetic(l0, l1, l2, l9, l10, l11, l12);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_dst;
    l9 = ((vader_struct_vader_midir$InstrBinOp_t*) l2)->f_op;
    l10 = l5.payload.obj;
    l11 = l6.payload.obj;
    l10 = vader_midir_ranges$bitwise_interval(l9, l10, l11);
    vader_midir_ranges$set_result(l0, l1, l3, l10);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_ranges$transfer_constant(void* l0, void* l1, void* l2) {
    int32_t l3;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null();
    void* l5 = NULL;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l4, &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir$InstrConst_t*) l2)->f_dst;
    vader_midir_ranges$forget_local(l1, l3);
    l4 = ((vader_struct_vader_midir$InstrConst_t*) l2)->f_value;
    if (l4.tag == 1321u) {
        l5 = ((vader_struct_vader_midir_ranges$RangeContext_t*) l0)->f_locals;
        l3 = ((vader_struct_vader_midir$InstrConst_t*) l2)->f_dst;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        l6 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
        l3 = ((vader_struct_vader_midir$InstrConst_t*) l2)->f_dst;
        t0 = l4.payload.obj;
        t1 = ((vader_struct_vader_midir$ConstInt_t*) t0)->f_value;
        l5 = vader_midir_ranges$constant_interval(t1, l6);
        vader_midir_ranges$set_interval(l0, l1, l3, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_ranges$transfer_copy(void* l0, void* l1, int32_t l2, int32_t l3) {
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    bool l6;
    void* l7 = NULL;
    void* l8 = NULL;
    bool t0;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l7, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = vader_midir_ranges$interval_of(l0, l1, l3);
    l5 = vader_midir_ranges$type_of(l0, l2);
    if (l4.tag == 0u) {
        l6 = true;
    } else {
        l6 = l5.tag == 0u;
    }
    if (l6) {
        l6 = true;
    } else {
        l7 = l4.payload.obj;
        l8 = l5.payload.obj;
        t0 = vader_support_integer$interval_within(l7, l8);
        l6 = !(t0);
    }
    if (!(l6)) {
        l7 = l4.payload.obj;
        vader_midir_ranges$shift_local(l0, l1, l2, l3, INT64_C(0), l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_midir_ranges$forget_local(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_ranges$transfer_length(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l18 = NULL;
    int64_t l7, l8;
    int32_t l9, l10, l11, l12, l13, l14;
    uint64_t l15;
    vader_box_t l16 = vader_box_null(), l17 = vader_box_null(), l19 = vader_box_null();
    bool t0;
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l16, &l17, &l19 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l18 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 338u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_lengths;
    l5 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l4)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$MutableMap__i32__i32_t*) l4)->f_size;
    vader_array_t* _pc13_hdr = (vader_array_t*) l3;
    size_t _pc13_len = _pc13_hdr->length;
    size_t _pc13_cap = (_pc13_hdr->offset == 0 && !vader_array_is_borrowed(_pc13_hdr) && _pc13_hdr->length >= _pc13_hdr->buf->length) ? _pc13_hdr->capacity : (size_t) 0;
    void* _pc13_slots = _pc13_hdr->buf->slots;
    for (;;) {
        if ((l7 < l8)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
            l9 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l7];
            vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
            l10 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l7];
            l11 = l9;
            l12 = l10;
            l13 = ((vader_struct_vader_midir$InstrArrayLen_t*) l2)->f_target;
            t0 = vader_midir$LocalId$std_core$Equals$equals(l12, l13);
            if (t0) {
                l14 = ((vader_struct_vader_midir$InstrArrayLen_t*) l2)->f_dst;
                t0 = vader_midir$LocalId$std_core$Equals$equals(l11, l14);
                if (!(t0)) {
                    if (VADER_LIKELY(_pc13_len < _pc13_cap)) {
                        ((int32_t*) _pc13_slots)[_pc13_len] = (int32_t) (l11);
                        _pc13_len += 1;
                    } else {
                        _pc13_hdr->length = _pc13_len;
                        if (_pc13_hdr->buf->length < _pc13_len) {
                            _pc13_hdr->buf->length = _pc13_len;
                        }
                        vader_array_push_i32((vader_array_t*) l3, l11);
                        _pc13_hdr = (vader_array_t*) l3;
                        _pc13_len = _pc13_hdr->length;
                        _pc13_cap = (_pc13_hdr->offset == 0 && !vader_array_is_borrowed(_pc13_hdr) && _pc13_hdr->length >= _pc13_hdr->buf->length) ? _pc13_hdr->capacity : (size_t) 0;
                        _pc13_slots = _pc13_hdr->buf->slots;
                    }
                }
            }
            l7 = (l7 + INT64_C(1));
            continue;
        }
        _pc13_hdr->length = _pc13_len;
        if (_pc13_hdr->buf->length < _pc13_len) {
            _pc13_hdr->buf->length = _pc13_len;
        }
        break;
    }
    l9 = ((vader_struct_vader_midir$InstrArrayLen_t*) l2)->f_dst;
    vader_midir_ranges$forget_local(l1, l9);
    l7 = ((vader_array_t*) l3)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l9 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l8];
        l10 = ((vader_struct_vader_midir$InstrArrayLen_t*) l2)->f_dst;
        l15 = vader_midir_ranges$fact_key(l9, l10);
        vader_midir_ranges$add_fact(l1, l15, INT64_C(0));
        l16 = vader_midir_ranges$interval_of(l0, l1, l9);
        if (l16.tag == 0u) {
            l8 = (l8 + INT64_C(1));
            continue;
        }
        l4 = l16.payload.obj;
        l11 = ((vader_struct_vader_midir$InstrArrayLen_t*) l2)->f_dst;
        l17 = vader_midir_ranges$interval_of(l0, l1, l11);
        if (l17.tag == 0u) {
            l8 = (l8 + INT64_C(1));
            continue;
        }
        l5 = l17.payload.obj;
        t1 = ((vader_struct_vader_support_integer$Interval_t*) l4)->f_lo;
        l18 = vader_support_integer$interval_from_ends(vader_box_i64(339u, t1), vader_box_obj(0u, NULL));
        l19 = vader_support_integer$interval_meet(l5, l18);
        if (l19.tag == 0u) {
            l8 = (l8 + INT64_C(1));
            continue;
        }
        l6 = l19.payload.obj;
        l12 = ((vader_struct_vader_midir$InstrArrayLen_t*) l2)->f_dst;
        vader_midir_ranges$set_interval(l0, l1, l12, l6);
        l8 = (l8 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_lengths;
    l9 = ((vader_struct_vader_midir$InstrArrayLen_t*) l2)->f_dst;
    l10 = ((vader_struct_vader_midir$InstrArrayLen_t*) l2)->f_target;
    std_collections$MutableMap$std_core$IndexSet$set_at__i32__i32(l3, l9, l10);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir_ranges$transfer_unop(void* l0, void* l1, void* l2) {
    int32_t l3, l9;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* l6 = NULL;
    void* l8 = NULL;
    bool l7;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l6, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir$InstrUnOp_t*) l2)->f_dst;
    l4 = vader_midir_ranges$type_of(l0, l3);
    l3 = ((vader_struct_vader_midir$InstrUnOp_t*) l2)->f_operand;
    l5 = vader_midir_ranges$interval_of(l0, l1, l3);
    if (((vader_struct_vader_midir$InstrUnOp_t*) l2)->f_op == INT32_C(0)) {
        if (l4.tag == 0u) {
            l9 = ((vader_struct_vader_midir$InstrUnOp_t*) l2)->f_dst;
            vader_midir_ranges$forget_local(l1, l9);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l5.tag == 0u) {
            l9 = ((vader_struct_vader_midir$InstrUnOp_t*) l2)->f_dst;
            vader_midir_ranges$forget_local(l1, l9);
            { vader_gc_top = gc_frame.prev; return; }
        }
        t0 = l5.payload.obj;
        l6 = vader_support_integer$interval_negate(t0);
        t1 = ((vader_struct_vader_midir_ranges$RangeContext_t*) l0)->f_checked_ops_trap;
        if (t1) {
            l7 = true;
        } else {
            l8 = l4.payload.obj;
            l7 = vader_support_integer$interval_within(l6, l8);
        }
        if (l7) {
            l3 = ((vader_struct_vader_midir$InstrUnOp_t*) l2)->f_dst;
            vader_midir_ranges$set_result(l0, l1, l3, l6);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l9 = ((vader_struct_vader_midir$InstrUnOp_t*) l2)->f_dst;
        vader_midir_ranges$forget_local(l1, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l9 = ((vader_struct_vader_midir$InstrUnOp_t*) l2)->f_dst;
    vader_midir_ranges$forget_local(l1, l9);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_ranges$type_of(void* l0, int32_t l1) {
    void* l2;
    int32_t l3;
    vader_box_t t0;
    l2 = ((vader_struct_vader_midir_ranges$RangeContext_t*) l0)->f_types;
    l3 = l1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    return t0;
}

static uint8_t vader_midir_ranges$verdict_at(void* l0, vader_box_t l1, bool l2, vader_box_t l3) {
    uint8_t l4;
    void* l5 = NULL;
    void* l8 = NULL;
    int32_t l6, l7;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[4] = { &l0, &l5, &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_midir_ranges$already_safe(l3);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
    }
    if (l2) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 2; }
    }
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 4; }
    }
    if (l3.tag == 1328u) {
        l5 = l1.payload.obj;
        t1 = l3.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrArrayGet_t*) t1)->f_target;
        t1 = l3.payload.obj;
        l7 = ((vader_struct_vader_midir$InstrArrayGet_t*) t1)->f_index;
        l4 = vader_midir_ranges$index_verdict(l0, l5, l6, l7);
        { uint8_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3.tag == 1332u) {
        l5 = l1.payload.obj;
        t1 = l3.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrArraySet_t*) t1)->f_target;
        t1 = l3.payload.obj;
        l7 = ((vader_struct_vader_midir$InstrArraySet_t*) t1)->f_index;
        l4 = vader_midir_ranges$index_verdict(l0, l5, l6, l7);
    } else if (l3.tag == 1334u) {
        l5 = l1.payload.obj;
        l8 = l3.payload.obj;
        l4 = vader_midir_ranges$arithmetic_verdict(l0, l5, l8);
    } else {
        if (!(l3.tag == 1357u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l5 = l1.payload.obj;
        l8 = l3.payload.obj;
        l4 = vader_midir_ranges$negation_verdict(l0, l5, l8);
    }
    { uint8_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_ranges$walking_state(vader_box_t l0, int32_t l1) {
    void* l2 = NULL;
    int32_t l3;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l4 };
    void** gc_raw_roots[3] = { &l2, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l0.payload.obj;
    l3 = l1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l4.payload.obj;
    t1 = vader_midir_ranges$copy_range_state(t0);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_ranges$widen_lower(void* l0, void* l1, void* l2) {
    int64_t l3, l4, l7, l8;
    vader_box_t l5;
    void* l6;
    bool t0;
    int64_t t1;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo_open;
    if (t0) {
        return vader_box_obj(0u, NULL);
    }
    l3 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo;
    l4 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
    if ((l3 >= l4)) {
        t1 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo;
        return vader_box_i64(339u, t1);
    }
    l5 = vader_box_obj(0u, NULL);
    l6 = l2;
    l3 = ((vader_array_t*) l6)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        l8 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo;
        if ((l7 <= l8)) {
            l5 = vader_box_i64(339u, l7);
        }
        l4 = (l4 + INT64_C(1));
    }
    return l5;
}

static void vader_midir_ranges$widen_range_states(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    int64_t l4, l5, l14, l16, l17;
    int32_t l6;
    vader_box_t l8 = vader_box_null(), l10 = vader_box_null();
    uint64_t l13, l15;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l8, &l10 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l7, &l9, &l11, &l12 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = std_collections$keys__vader_midir$LocalId__vader_support_integer_Interval(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_intervals);
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
        l8 = std_collections$MutableMap$std_core$Index$at__i32__Any(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_intervals, l6);
        if (l8.tag == 0u) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l7 = l8.payload.obj;
        l10 = std_collections$MutableMap$std_core$Index$at__i32__Any(((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_intervals, l6);
        if (l10.tag == 0u) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l9 = l10.payload.obj;
        l11 = ((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_intervals;
        l12 = vader_midir_ranges$interval_widen(l9, l7, l2);
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l11, l6, vader_ref_box(l12));
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a1_arr = vader_array_new(27u, 0u, 4u, 343u);
    l3 = (void*) _a1_arr;
    l7 = ((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_differences;
    l9 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l7)->f_ekeys;
    l11 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l7)->f_evals;
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections$MutableMap__u64__i64_t*) l7)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        l13 = (uint64_t) (int64_t) t0;
        vader_array_t* _a3_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
        l14 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
        l15 = l13;
        l16 = l14;
        l8 = std_collections$MutableMap$std_core$Index$at__u64__i64(((vader_struct_vader_midir_ranges$RangeState_t*) l0)->f_differences, l15);
        if (!(l8.tag == 0u)) {
            l17 = ((int64_t) l8.payload.i);
            if ((l16 > l17)) {
                vader_array_push_i64((vader_array_t*) l3, (int64_t) (uint64_t) l15);
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5];
        l13 = (uint64_t) (int64_t) t0;
        std_collections$remove__u64__i64(((vader_struct_vader_midir_ranges$RangeState_t*) l1)->f_differences, l13);
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir_ranges$widen_upper(void* l0, void* l1, void* l2) {
    int64_t l3, l4, l6, l7;
    void* l5;
    bool t0;
    int64_t t1;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi_open;
    if (t0) {
        return vader_box_obj(0u, NULL);
    }
    l3 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi;
    l4 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi;
    if ((l3 <= l4)) {
        t1 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi;
        return vader_box_i64(339u, t1);
    }
    l5 = l2;
    l3 = ((vader_array_t*) l5)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        l7 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi;
        if ((l6 >= l7)) {
            return vader_box_i64(339u, l6);
        }
        l4 = (l4 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

static void* vader_midir_ranges$widening_thresholds(void* l0, int32_t l1) {
    int32_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir_ranges$RangeFlow_t*) l0)->f_widenings);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    if (!((t0 < INT32_C(3)))) {
        vader_array_t* _a1_arr = vader_array_new(23u, 0u, 8u, 339u);
        t1 = (void*) _a1_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = ((vader_struct_vader_midir_ranges$RangeFlow_t*) l0)->f_thresholds; vader_gc_top = gc_frame.prev; return __vret; }
}
