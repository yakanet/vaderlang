#include "bootstrap.split.h"

static vader_box_t vader_support_integer$end_difference(int64_t l0, bool l1, int64_t l2, bool l3);
static vader_box_t vader_support_integer$end_sum(int64_t l0, bool l1, int64_t l2, bool l3);
static void* vader_support_integer$greater_upper(void* l0, void* l1);
static void* vader_support_integer$lesser_upper(void* l0, void* l1);
static vader_box_t vader_support_integer$machine_integer_of(void* l0);
static vader_box_t vader_support_integer$quotients_over(void* l0, int64_t l1, int64_t l2);
static void* vader_support_integer$span_of(int64_t l0, int64_t l1, int64_t l2, int64_t l3);
static void vader_support_integer$value_bounds(void* l0, int64_t* __o0, int64_t* __o1);
static vader_box_t vader_support_integer$within(int64_t l0, bool l1, int64_t l2);

vader_box_t vader_support_integer$checked_add(int64_t l0, bool l1, int64_t l2, int64_t l3) {
    uint64_t l4, l5;
    int64_t l6, l7, l8;
    int64_t t0;
    vader_box_t t1;
    if (l0 == INT64_C(64)) {
        if (l1) {
            t0 = l2;
            l4 = (uint64_t) (int64_t) t0;
            t0 = l3;
            l5 = (uint64_t) (int64_t) t0;
            t0 = (l4 + l5);
            l4 = (uint64_t) (int64_t) t0;
            t0 = l2;
            l5 = (uint64_t) (int64_t) t0;
            if (!((l4 < l5))) {
                return vader_box_i64(339u, ((int64_t) (uint64_t) l4));
            }
            return vader_box_obj(0u, NULL);
        }
    }
    if (!(l0 == INT64_C(64))) {
        l6 = vader_chk_add(i64, l2, l3);
        t1 = vader_support_integer$within(l0, l1, l6);
        return t1;
    }
    l6 = (l2 + l3);
    l7 = (l2 ^ l6);
    l8 = (l3 ^ l6);
    if (!(((l7 & l8) < INT64_C(0)))) {
        return vader_box_i64(339u, l6);
    }
    return vader_box_obj(0u, NULL);
}

vader_box_t vader_support_integer$checked_mul(int64_t l0, bool l1, int64_t l2, int64_t l3) {
    uint64_t l4, l5, l6;
    int64_t l7;
    int64_t t0;
    vader_box_t t1;
    if (l0 == INT64_C(64)) {
        if (l1) {
            t0 = l2;
            l4 = (uint64_t) (int64_t) t0;
            t0 = l3;
            l5 = (uint64_t) (int64_t) t0;
            t0 = (l4 * l5);
            l4 = (uint64_t) (int64_t) t0;
            if (l2 != INT64_C(0)) {
                t0 = l2;
                l5 = (uint64_t) (int64_t) t0;
                l5 = vader_div_u64(l4, l5);
                t0 = l3;
                l6 = (uint64_t) (int64_t) t0;
                if (l5 != l6) {
                    return vader_box_obj(0u, NULL);
                }
                return vader_box_i64(339u, ((int64_t) (uint64_t) l4));
            }
            return vader_box_i64(339u, ((int64_t) (uint64_t) l4));
        }
    }
    if (l0 == INT64_C(64)) {
        if (l2 == INT64_C(-1)) {
            t1 = vader_support_integer$checked_negation(INT64_C(64), false, l3);
            return t1;
        }
        l7 = (l2 * l3);
        if (l2 != INT64_C(0)) {
            t0 = vader_div_i64(l7, l2);
            if (t0 != l3) {
                return vader_box_obj(0u, NULL);
            }
            return vader_box_i64(339u, l7);
        }
        return vader_box_i64(339u, l7);
    }
    if (l1) {
        if (l0 == INT64_C(32)) {
            if (l2 != INT64_C(0)) {
                l7 = vader_div_i64(INT64_C(4294967295), l2);
                if ((l3 > l7)) {
                    return vader_box_obj(0u, NULL);
                }
                l7 = vader_chk_mul(i64, l2, l3);
                t1 = vader_support_integer$within(l0, l1, l7);
                return t1;
            }
            l7 = vader_chk_mul(i64, l2, l3);
            t1 = vader_support_integer$within(l0, l1, l7);
            return t1;
        }
        l7 = vader_chk_mul(i64, l2, l3);
        t1 = vader_support_integer$within(l0, l1, l7);
        return t1;
    }
    l7 = vader_chk_mul(i64, l2, l3);
    t1 = vader_support_integer$within(l0, l1, l7);
    return t1;
}

vader_box_t vader_support_integer$checked_negation(int64_t l0, bool l1, int64_t l2) {
    int64_t l3;
    vader_box_t t0;
    int64_t t1;
    if (l1) {
        if (!(l2 != INT64_C(0))) {
            return vader_box_i64(339u, INT64_C(0));
        }
        return vader_box_obj(0u, NULL);
    }
    if (!(l0 == INT64_C(64))) {
        l3 = vader_chk_neg(i64, l2);
        t0 = vader_support_integer$within(l0, false, l3);
        return t0;
    }
    if (!(l2 == INT64_MIN)) {
        t1 = vader_chk_neg(i64, l2);
        return vader_box_i64(339u, t1);
    }
    return vader_box_obj(0u, NULL);
}

vader_box_t vader_support_integer$checked_sub(int64_t l0, bool l1, int64_t l2, int64_t l3) {
    uint64_t l4, l5;
    int64_t l6, l7, l8;
    int64_t t0;
    vader_box_t t1;
    if (l0 == INT64_C(64)) {
        if (l1) {
            t0 = l2;
            l4 = (uint64_t) (int64_t) t0;
            t0 = l3;
            l5 = (uint64_t) (int64_t) t0;
            if (!((l4 < l5))) {
                return vader_box_i64(339u, (l2 - l3));
            }
            return vader_box_obj(0u, NULL);
        }
    }
    if (!(l0 == INT64_C(64))) {
        l6 = vader_chk_sub(i64, l2, l3);
        t1 = vader_support_integer$within(l0, l1, l6);
        return t1;
    }
    l6 = (l2 - l3);
    l7 = (l2 ^ l3);
    l8 = (l2 ^ l6);
    if (!(((l7 & l8) < INT64_C(0)))) {
        return vader_box_i64(339u, l6);
    }
    return vader_box_obj(0u, NULL);
}

int64_t vader_support_integer$count_bits(void* l0) {
    uint64_t l1, l2;
    int64_t l3;
    bool t0;
    int64_t t1, t2;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo_open;
    if (t0) {
        return INT64_C(64);
    }
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_open;
    if (t0) {
        return INT64_C(64);
    }
    t1 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi;
    t2 = t1;
    l1 = (uint64_t) (int64_t) t2;
    t1 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
    t2 = t1;
    l2 = (uint64_t) (int64_t) t2;
    t1 = (l1 - l2);
    l1 = (uint64_t) (int64_t) t1;
    l3 = INT64_C(0);
    while ((l1 > INT64_C(0))) {
        l1 = (l1 >> INT64_C(1));
        l3 = vader_chk_add(i64, l3, INT64_C(1));
    }
    return l3;
}

static vader_box_t vader_support_integer$end_difference(int64_t l0, bool l1, int64_t l2, bool l3) {
    vader_box_t t0;
    if (l1) {
        return vader_box_obj(0u, NULL);
    }
    if (!(l3)) {
        t0 = vader_support_integer$checked_sub(INT64_C(64), false, l0, l2);
        return t0;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_support_integer$end_sum(int64_t l0, bool l1, int64_t l2, bool l3) {
    vader_box_t t0;
    if (l1) {
        return vader_box_obj(0u, NULL);
    }
    if (!(l3)) {
        t0 = vader_support_integer$checked_add(INT64_C(64), false, l0, l2);
        return t0;
    }
    return vader_box_obj(0u, NULL);
}

int64_t vader_support_integer$greater(int64_t l0, int64_t l1) {
    if (!((l0 >= l1))) {
        return l1;
    }
    return l0;
}

static void* vader_support_integer$greater_upper(void* l0, void* l1) {
    bool t0;
    t0 = vader_support_integer$upper_at_most(l0, l1);
    if (!(t0)) {
        return l0;
    }
    return l1;
}

bool vader_support_integer$holds_value(void* l0, int64_t l1) {
    bool l2;
    int64_t l3;
    bool t0;
    int64_t t1;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo_open;
    if (t0) {
        l2 = true;
    } else {
        t1 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
        l2 = (t1 <= l1);
    }
    if (l2) {
        t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_open;
        if (t0) {
            l2 = true;
        } else {
            l3 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi;
            l2 = (l1 <= l3);
        }
        return l2;
    }
    return false;
}

void* vader_support_integer$interval(int64_t l0, int64_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_support_integer$Interval_t* _a0_obj = (vader_struct_vader_support_integer$Interval_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_integer$Interval_t));
    vader_obj_header_init(_a0_obj, 1403u);
    _a0_obj->f_lo = l0;
    _a0_obj->f_hi = l1;
    _a0_obj->f_lo_open = false;
    _a0_obj->f_hi_open = false;
    _a0_obj->f_hi_past = (uint64_t) 0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_support_integer$interval_add(void* l0, void* l1) {
    int64_t l2, l4;
    bool l3, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l6, &l7 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
    l3 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo_open;
    l4 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo;
    l5 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo_open;
    l6 = vader_support_integer$end_sum(l2, l3, l4, l5);
    l2 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi;
    l3 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_open;
    l4 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi;
    l5 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi_open;
    l7 = vader_support_integer$end_sum(l2, l3, l4, l5);
    t0 = vader_support_integer$interval_from_ends(l6, l7);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_support_integer$interval_div(void* l0, void* l1) {
    int64_t l2, l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    void* l7 = NULL;
    void* l8 = NULL;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l4, &l5, &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l7, &l8, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo_open;
    if (!(t0)) {
        t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_open;
        if (!(t0)) {
            t0 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo_open;
            if (!(t0)) {
                t0 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi_open;
                if (!(t0)) {
                    l2 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo;
                    t1 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi;
                    l3 = vader_support_integer$lesser(t1, INT64_C(-1));
                    l4 = vader_support_integer$quotients_over(l0, l2, l3);
                    t1 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo;
                    l2 = vader_support_integer$greater(t1, INT64_C(1));
                    l3 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi;
                    l5 = vader_support_integer$quotients_over(l0, l2, l3);
                    if (l4.tag == 0u) {
                        l6 = l5;
                        if (l6.tag == 0u) {
                            t2 = (void*) &vader_data_48;
                            vader_array_t* _a0_slotarr = ((vader_array_t*) t2);
                            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                            t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
                            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
                        }
                        t2 = l6.payload.obj;
                        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    if (!(l5.tag == 0u)) {
                        l7 = l4.payload.obj;
                        l8 = l5.payload.obj;
                        t2 = vader_support_integer$interval_join(l7, l8);
                        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    t2 = l4.payload.obj;
                    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
        }
    }
    t2 = (void*) &vader_data_48;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_support_integer$interval_from_ends(vader_box_t l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    int64_t l3, l4;
    bool l5, l6;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &l1, &l2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    if (l2.tag == 0u) {
        l3 = INT64_MIN;
    } else {
        l3 = ((int64_t) l2.payload.i);
    }
    l2 = l1;
    if (l2.tag == 0u) {
        l4 = INT64_C(9223372036854775807);
    } else {
        l4 = ((int64_t) l2.payload.i);
    }
    l5 = l0.tag == 0u;
    l6 = l1.tag == 0u;
    vader_struct_vader_support_integer$Interval_t* _a0_obj = (vader_struct_vader_support_integer$Interval_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_integer$Interval_t));
    vader_obj_header_init(_a0_obj, 1403u);
    _a0_obj->f_lo = l3;
    _a0_obj->f_hi = l4;
    _a0_obj->f_lo_open = l5;
    _a0_obj->f_hi_open = l6;
    _a0_obj->f_hi_past = (uint64_t) 0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_support_integer$interval_join(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    bool l5, l6;
    uint64_t l7;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_support_integer$greater_upper(l0, l1);
    l3 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
    l4 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo;
    l3 = vader_support_integer$lesser(l3, l4);
    l4 = ((vader_struct_vader_support_integer$Interval_t*) l2)->f_hi;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo_open;
    if (t0) {
        l5 = true;
    } else {
        l5 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo_open;
    }
    l6 = ((vader_struct_vader_support_integer$Interval_t*) l2)->f_hi_open;
    l7 = ((vader_struct_vader_support_integer$Interval_t*) l2)->f_hi_past;
    vader_struct_vader_support_integer$Interval_t* _a0_obj = (vader_struct_vader_support_integer$Interval_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_integer$Interval_t));
    vader_obj_header_init(_a0_obj, 1403u);
    _a0_obj->f_lo = l3;
    _a0_obj->f_hi = l4;
    _a0_obj->f_lo_open = l5;
    _a0_obj->f_hi_open = l6;
    _a0_obj->f_hi_past = l7;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_support_integer$interval_meet(void* l0, void* l1) {
    int64_t l2, l3;
    void* l4 = NULL;
    bool l5, l6;
    uint64_t l7;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
    l3 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo;
    l2 = vader_support_integer$greater(l2, l3);
    l4 = vader_support_integer$lesser_upper(l0, l1);
    l3 = ((vader_struct_vader_support_integer$Interval_t*) l4)->f_hi;
    if ((l2 > l3)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = ((vader_struct_vader_support_integer$Interval_t*) l4)->f_hi;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo_open;
    if (t0) {
        l5 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo_open;
    } else {
        l5 = false;
    }
    l6 = ((vader_struct_vader_support_integer$Interval_t*) l4)->f_hi_open;
    l7 = ((vader_struct_vader_support_integer$Interval_t*) l4)->f_hi_past;
    vader_struct_vader_support_integer$Interval_t* _a0_obj = (vader_struct_vader_support_integer$Interval_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_integer$Interval_t));
    vader_obj_header_init(_a0_obj, 1403u);
    _a0_obj->f_lo = l2;
    _a0_obj->f_hi = l3;
    _a0_obj->f_lo_open = l5;
    _a0_obj->f_hi_open = l6;
    _a0_obj->f_hi_past = l7;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_support_integer$interval_mul(void* l0, void* l1) {
    int64_t l2, l3, l5, l6, l7, l8;
    vader_box_t l4 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo_open;
    if (!(t0)) {
        t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_open;
        if (!(t0)) {
            t0 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo_open;
            if (!(t0)) {
                t0 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi_open;
                if (!(t0)) {
                    l2 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
                    l3 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo;
                    l4 = vader_support_integer$checked_mul(INT64_C(64), false, l2, l3);
                    if (l4.tag == 0u) {
                        t1 = (void*) &vader_data_48;
                        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
                        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
                        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l2 = ((int64_t) l4.payload.i);
                    l5 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
                    l6 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi;
                    l4 = vader_support_integer$checked_mul(INT64_C(64), false, l5, l6);
                    if (l4.tag == 0u) {
                        t1 = (void*) &vader_data_48;
                        vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
                        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
                        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l3 = ((int64_t) l4.payload.i);
                    l6 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi;
                    l7 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo;
                    l4 = vader_support_integer$checked_mul(INT64_C(64), false, l6, l7);
                    if (l4.tag == 0u) {
                        t1 = (void*) &vader_data_48;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
                        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l5 = ((int64_t) l4.payload.i);
                    l7 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi;
                    l8 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi;
                    l4 = vader_support_integer$checked_mul(INT64_C(64), false, l7, l8);
                    if (l4.tag == 0u) {
                        t1 = (void*) &vader_data_48;
                        vader_array_t* _a3_slotarr = ((vader_array_t*) t1);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
                        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l6 = ((int64_t) l4.payload.i);
                    t1 = vader_support_integer$span_of(l2, l3, l5, l6);
                    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
        }
    }
    t1 = (void*) &vader_data_48;
    vader_array_t* _a4_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT64_C(0));
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_support_integer$interval_negate(void* l0) {
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_47;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    t1 = vader_support_integer$interval_sub(t0, l0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_support_integer$interval_rem(void* l0, void* l1) {
    int64_t l2, l3, l4;
    bool t0;
    int64_t t1, t2;
    void* t3 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo_open;
    if (!(t0)) {
        t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_open;
        if (!(t0)) {
            t0 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo_open;
            if (!(t0)) {
                t0 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi_open;
                if (!(t0)) {
                    t1 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo;
                    if (!(t1 == INT64_MIN)) {
                        t1 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo;
                        l2 = std_math$abs_2(t1);
                        t1 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi;
                        l3 = std_math$abs_2(t1);
                        t1 = vader_support_integer$greater(l2, l3);
                        l2 = vader_chk_sub(i64, t1, INT64_C(1));
                        if (!((l2 < INT64_C(0)))) {
                            t1 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
                            l3 = vader_support_integer$lesser(t1, INT64_C(0));
                            l4 = vader_chk_neg(i64, l2);
                            l3 = vader_support_integer$greater(l3, l4);
                            t1 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi;
                            t2 = vader_support_integer$greater(t1, INT64_C(0));
                            l2 = vader_support_integer$lesser(t2, l2);
                            t3 = vader_support_integer$interval(l3, l2);
                            { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
                        }
                        t3 = (void*) &vader_data_48;
                        vader_array_t* _a0_slotarr = ((vader_array_t*) t3);
                        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                        t3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
                        { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                }
            }
        }
    }
    t3 = (void*) &vader_data_48;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_support_integer$interval_remove(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l12 = NULL;
    void* l17 = NULL;
    int64_t l4, l5, l8, l9, l10, l11, l13, l14, l15, l16;
    vader_box_t l7 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l6, &l12, &l17, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(218u, 0u, 13u, 1403u);
    l2 = (void*) _a0_arr;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l7 = vader_support_integer$interval_meet(l6, l1);
        if (l7.tag == 0u) {
            vader_array_push_ref((vader_array_t*) l2, l6);
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l8 = ((vader_struct_vader_support_integer$Interval_t*) l6)->f_lo;
        t0 = l7.payload.obj;
        l9 = ((vader_struct_vader_support_integer$Interval_t*) t0)->f_lo;
        if ((l8 < l9)) {
            l10 = ((vader_struct_vader_support_integer$Interval_t*) l6)->f_lo;
            t0 = l7.payload.obj;
            t1 = ((vader_struct_vader_support_integer$Interval_t*) t0)->f_lo;
            l11 = vader_chk_sub(i64, t1, INT64_C(1));
            l12 = vader_support_integer$interval(l10, l11);
            vader_array_push_ref((vader_array_t*) l2, l12);
        }
        t0 = l7.payload.obj;
        l13 = ((vader_struct_vader_support_integer$Interval_t*) t0)->f_hi;
        l14 = ((vader_struct_vader_support_integer$Interval_t*) l6)->f_hi;
        if ((l13 < l14)) {
            t0 = l7.payload.obj;
            t1 = ((vader_struct_vader_support_integer$Interval_t*) t0)->f_hi;
            l15 = vader_chk_add(i64, t1, INT64_C(1));
            l16 = ((vader_struct_vader_support_integer$Interval_t*) l6)->f_hi;
            l17 = vader_support_integer$interval(l15, l16);
            vader_array_push_ref((vader_array_t*) l2, l17);
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_support_integer$interval_sub(void* l0, void* l1) {
    int64_t l2, l4;
    bool l3, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l6, &l7 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
    l3 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo_open;
    l4 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi;
    l5 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi_open;
    l6 = vader_support_integer$end_difference(l2, l3, l4, l5);
    l2 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi;
    l3 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_open;
    l4 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo;
    l5 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo_open;
    l7 = vader_support_integer$end_difference(l2, l3, l4, l5);
    t0 = vader_support_integer$interval_from_ends(l6, l7);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_support_integer$interval_up_to(int64_t l0, uint64_t l1) {
    uint64_t l2;
    int64_t l3;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = INT64_C(9223372036854775807);
    l2 = (uint64_t) (int64_t) t0;
    if (!((l1 <= l2))) {
        t0 = INT64_C(9223372036854775807);
        l2 = (uint64_t) (int64_t) t0;
        t0 = vader_chk_sub(u64, l1, l2);
        l2 = (uint64_t) (int64_t) t0;
        vader_struct_vader_support_integer$Interval_t* _a0_obj = (vader_struct_vader_support_integer$Interval_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_integer$Interval_t));
        vader_obj_header_init(_a0_obj, 1403u);
        _a0_obj->f_lo = l0;
        _a0_obj->f_hi = INT64_C(9223372036854775807);
        _a0_obj->f_lo_open = false;
        _a0_obj->f_hi_open = true;
        _a0_obj->f_hi_past = l2;
        t1 = (void*) _a0_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((int64_t) (uint64_t) l1);
    t1 = vader_support_integer$interval(l0, l3);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_support_integer$interval_within(void* l0, void* l1) {
    int64_t l2, l3;
    bool l4;
    bool t0;
    l2 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
    l3 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo;
    if ((l2 >= l3)) {
        t0 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo_open;
        if (t0) {
            l4 = true;
        } else {
            t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo_open;
            l4 = !(t0);
        }
    } else {
        l4 = false;
    }
    if (l4) {
        t0 = vader_support_integer$upper_at_most(l0, l1);
        return t0;
    }
    return false;
}

int64_t vader_support_integer$lesser(int64_t l0, int64_t l1) {
    if (!((l0 <= l1))) {
        return l1;
    }
    return l0;
}

static void* vader_support_integer$lesser_upper(void* l0, void* l1) {
    bool t0;
    t0 = vader_support_integer$upper_at_most(l0, l1);
    if (!(t0)) {
        return l1;
    }
    return l0;
}

bool vader_support_integer$literal_fits(uint64_t l0, bool l1, void* l2) {
    int64_t l3;
    uint64_t l4;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[2] = { &l2, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1) {
        if ((l0 <= INT64_MIN)) {
            l3 = ((int64_t) (uint64_t) l0);
            l3 = (INT64_C(0) - l3);
            t0 = vader_support_integer$holds_value(l2, l3);
            { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t1 = INT64_C(9223372036854775807);
    l4 = (uint64_t) (int64_t) t1;
    if (!((l0 <= l4))) {
        t2 = vader_support_integer$interval_up_to(INT64_C(9223372036854775807), l0);
        t0 = vader_support_integer$interval_within(t2, l2);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((int64_t) (uint64_t) l0);
    t0 = vader_support_integer$holds_value(l2, l3);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_support_integer$machine_integer_name(void* l0) {
    void* l1;
    vader_box_t l2;
    vader_string_t t0;
    l2 = vader_support_integer$machine_integer_of(l0);
    if (l2.tag == 0u) {
        return 0u;
    }
    l1 = l2.payload.obj;
    t0 = ((vader_struct_vader_support_integer$MachineInteger_t*) l1)->f_name;
    return t0;
}

vader_box_t vader_support_integer$machine_integer_named(vader_string_t l0) {
    void* l1;
    void* l4;
    int64_t l2, l3;
    vader_string_t t0;
    l1 = (void*) &vader_data_46;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_vader_support_integer$MachineInteger_t*) l4)->f_name;
        if (t0 == l0) {
            return vader_ref_box(l4);
        }
        l3 = (l3 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_support_integer$machine_integer_of(void* l0) {
    void* l1;
    void* l4;
    int64_t l2, l3;
    bool t0;
    l1 = (void*) &vader_data_46;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = vader_support_integer$same_interval(((vader_struct_vader_support_integer$MachineInteger_t*) l4)->f_values, l0);
        if (t0) {
            return vader_ref_box(l4);
        }
        l3 = (l3 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

void* vader_support_integer$narrowest_machine_integer(void* l0) {
    bool l1;
    void* l2;
    void* l3;
    void* l6;
    void* l7;
    int64_t l4, l5;
    int64_t t0;
    void* t1;
    bool t2;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
    l1 = (t0 < INT64_C(0));
    t1 = (void*) &vader_data_46;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l3 = (void*) &vader_data_46;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t2 = ((vader_struct_vader_support_integer$MachineInteger_t*) l6)->f_is_signed;
        if (t2 != l1) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l7 = ((vader_struct_vader_support_integer$MachineInteger_t*) l6)->f_values;
        t2 = vader_support_integer$interval_within(l0, l7);
        if (t2) {
            return l6;
        }
        l2 = l6;
        l5 = (l5 + INT64_C(1));
    }
    return l2;
}

void* vader_support_integer$narrowest_width(void* l0) {
    int64_t l1, l2;
    int64_t t0, t1;
    void* t2 = NULL;
    void* t3 = NULL;
    void** gc_raw_roots[3] = { &l0, &t2, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_support_integer$value_bounds(l0, &t0, &t1);
    l2 = t1;
    l1 = t0;
    t2 = vader_support_integer$interval(l1, l2);
    t3 = vader_support_integer$narrowest_machine_integer(t2);
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_support_integer$quotients_over(void* l0, int64_t l1, int64_t l2) {
    int64_t l3, l4, l5, l6;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l1 > l2)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
    if (t0 == INT64_MIN) {
        if (l2 == INT64_C(-1)) {
            t1 = (void*) &vader_data_48;
            vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
    l3 = vader_div_i64(t0, l1);
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
    l4 = vader_div_i64(t0, l2);
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi;
    l5 = vader_div_i64(t0, l1);
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi;
    l6 = vader_div_i64(t0, l2);
    t1 = vader_support_integer$span_of(l3, l4, l5, l6);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_support_integer$same_interval(void* l0, void* l1) {
    int64_t l2, l3;
    bool l4, l5, l6;
    uint64_t l7, l8;
    l2 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
    l3 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo;
    if (l2 == l3) {
        l2 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi;
        l3 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi;
        l4 = l2 == l3;
    } else {
        l4 = false;
    }
    if (l4) {
        l5 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo_open;
        l6 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_lo_open;
        l4 = l5 == l6;
    } else {
        l4 = false;
    }
    if (l4) {
        l5 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_open;
        l6 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi_open;
        l4 = l5 == l6;
    } else {
        l4 = false;
    }
    if (l4) {
        l7 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_past;
        l8 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi_past;
        return l7 == l8;
    }
    return false;
}

static void* vader_support_integer$span_of(int64_t l0, int64_t l1, int64_t l2, int64_t l3) {
    int64_t l4, l5, l6;
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = vader_support_integer$lesser(l0, l1);
    l5 = vader_support_integer$lesser(l2, l3);
    l4 = vader_support_integer$lesser(l4, l5);
    l5 = vader_support_integer$greater(l0, l1);
    l6 = vader_support_integer$greater(l2, l3);
    l5 = vader_support_integer$greater(l5, l6);
    t0 = vader_support_integer$interval(l4, l5);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_support_integer$upper_at_most(void* l0, void* l1) {
    int64_t l2, l3;
    bool l4;
    uint64_t l5, l6;
    bool t0;
    uint64_t t1;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_open;
    if (t0) {
        t0 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi_open;
        if (!(t0)) {
            return false;
        }
        t1 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi_past;
        if (t1 == INT64_C(0)) {
            return true;
        }
        t1 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_past;
        if (t1 != INT64_C(0)) {
            l5 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_past;
            l6 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi_past;
            l4 = (l5 <= l6);
        } else {
            l4 = false;
        }
        return l4;
    }
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi_open;
    if (t0) {
        return true;
    }
    l2 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi;
    l3 = ((vader_struct_vader_support_integer$Interval_t*) l1)->f_hi;
    return (l2 <= l3);
}

uint64_t vader_support_integer$upper_past_i64(void* l0) {
    uint64_t l1, l2;
    uint64_t t0;
    int64_t t1;
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_past;
    if (!(t0 == INT64_C(0))) {
        t1 = INT64_C(9223372036854775807);
        l1 = (uint64_t) (int64_t) t1;
        l2 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_past;
        t1 = vader_chk_add(u64, l1, l2);
        return (uint64_t) (int64_t) t1;
    }
    t1 = vader_chk_add(u64, INT64_C(9223372036854775807), INT64_MIN);
    return (uint64_t) (int64_t) t1;
}

static void vader_support_integer$value_bounds(void* l0, int64_t* __o0, int64_t* __o1) {
    int64_t l1, l2, l4, l5, l6;
    void* l3;
    int64_t t0;
    t0 = ((vader_array_t*) l0)->length;
    if (t0 == INT64_C(0)) {
        *__o1 = INT64_C(0); *__o0 = INT64_C(0); return;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    l1 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    l2 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
        if ((l6 < l1)) {
            l1 = l6;
        }
        if ((l6 > l2)) {
            l2 = l6;
        }
        l5 = (l5 + INT64_C(1));
    }
    *__o1 = l2; *__o0 = l1; return;
}

static vader_box_t vader_support_integer$within(int64_t l0, bool l1, int64_t l2) {
    int64_t l3, l4;
    if (l1) {
        if ((l2 < INT64_C(0))) {
            return vader_box_obj(0u, NULL);
        }
        l3 = (INT64_C(1) << (l0 & 63));
        if (!((l2 >= l3))) {
            return vader_box_i64(339u, l2);
        }
        return vader_box_obj(0u, NULL);
    }
    l3 = vader_chk_sub(i64, l0, INT64_C(1));
    l3 = (INT64_C(1) << (l3 & 63));
    l4 = vader_chk_neg(i64, l3);
    if ((l2 < l4)) {
        return vader_box_obj(0u, NULL);
    }
    if (!((l2 >= l3))) {
        return vader_box_i64(339u, l2);
    }
    return vader_box_obj(0u, NULL);
}
