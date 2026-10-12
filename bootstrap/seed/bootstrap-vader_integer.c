#include "bootstrap.split.h"

static vader_box_t vader_integer_within(int64_t l0, bool l1, int64_t l2);

vader_box_t vader_integer_checked_add(int64_t l0, bool l1, int64_t l2, int64_t l3) {
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
                t1 = vader_box_i64(248u, ((int64_t) (uint64_t) l4));
                return t1;
            }
            return vader_box_obj(0u, NULL);
        }
    }
    if (!(l0 == INT64_C(64))) {
        l6 = vader_chk_add(i64, l2, l3);
        t1 = vader_integer_within(l0, l1, l6);
        return t1;
    }
    l6 = (l2 + l3);
    l7 = (l2 ^ l6);
    l8 = (l3 ^ l6);
    if (!(((l7 & l8) < INT64_C(0)))) {
        t1 = vader_box_i64(248u, l6);
        return t1;
    }
    return vader_box_obj(0u, NULL);
}

vader_box_t vader_integer_checked_mul(int64_t l0, bool l1, int64_t l2, int64_t l3) {
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
                t1 = vader_box_i64(248u, ((int64_t) (uint64_t) l4));
                return t1;
            }
            t1 = vader_box_i64(248u, ((int64_t) (uint64_t) l4));
            return t1;
        }
    }
    if (l0 == INT64_C(64)) {
        if (l2 == INT64_C(-1)) {
            t1 = vader_integer_checked_negation(INT64_C(64), false, l3);
            return t1;
        }
        l7 = (l2 * l3);
        if (l2 != INT64_C(0)) {
            t0 = vader_div_i64(l7, l2);
            if (t0 != l3) {
                return vader_box_obj(0u, NULL);
            }
            t1 = vader_box_i64(248u, l7);
            return t1;
        }
        t1 = vader_box_i64(248u, l7);
        return t1;
    }
    if (l1) {
        if (l0 == INT64_C(32)) {
            if (l2 != INT64_C(0)) {
                l7 = vader_div_i64(INT64_C(4294967295), l2);
                if ((l3 > l7)) {
                    return vader_box_obj(0u, NULL);
                }
                l7 = vader_chk_mul(i64, l2, l3);
                t1 = vader_integer_within(l0, l1, l7);
                return t1;
            }
            l7 = vader_chk_mul(i64, l2, l3);
            t1 = vader_integer_within(l0, l1, l7);
            return t1;
        }
        l7 = vader_chk_mul(i64, l2, l3);
        t1 = vader_integer_within(l0, l1, l7);
        return t1;
    }
    l7 = vader_chk_mul(i64, l2, l3);
    t1 = vader_integer_within(l0, l1, l7);
    return t1;
}

vader_box_t vader_integer_checked_negation(int64_t l0, bool l1, int64_t l2) {
    int64_t l3;
    vader_box_t t0;
    int64_t t1;
    if (l1) {
        if (!(l2 != INT64_C(0))) {
            return vader_box_i64(248u, INT64_C(0));
        }
        return vader_box_obj(0u, NULL);
    }
    if (!(l0 == INT64_C(64))) {
        l3 = vader_chk_neg(i64, l2);
        t0 = vader_integer_within(l0, false, l3);
        return t0;
    }
    if (!(l2 == INT64_MIN)) {
        t1 = vader_chk_neg(i64, l2);
        t0 = vader_box_i64(248u, t1);
        return t0;
    }
    return vader_box_obj(0u, NULL);
}

vader_box_t vader_integer_checked_sub(int64_t l0, bool l1, int64_t l2, int64_t l3) {
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
                t1 = vader_box_i64(248u, (l2 - l3));
                return t1;
            }
            return vader_box_obj(0u, NULL);
        }
    }
    if (!(l0 == INT64_C(64))) {
        l6 = vader_chk_sub(i64, l2, l3);
        t1 = vader_integer_within(l0, l1, l6);
        return t1;
    }
    l6 = (l2 - l3);
    l7 = (l2 ^ l3);
    l8 = (l2 ^ l6);
    if (!(((l7 & l8) < INT64_C(0)))) {
        t1 = vader_box_i64(248u, l6);
        return t1;
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_integer_within(int64_t l0, bool l1, int64_t l2) {
    int64_t l3, l4;
    vader_box_t t0;
    if (l1) {
        if ((l2 < INT64_C(0))) {
            return vader_box_obj(0u, NULL);
        }
        l3 = (INT64_C(1) << l0);
        if (!((l2 >= l3))) {
            t0 = vader_box_i64(248u, l2);
            return t0;
        }
        return vader_box_obj(0u, NULL);
    }
    l3 = vader_chk_sub(i64, l0, INT64_C(1));
    l3 = (INT64_C(1) << l3);
    l4 = vader_chk_neg(i64, l3);
    if ((l2 < l4)) {
        return vader_box_obj(0u, NULL);
    }
    if (!((l2 >= l3))) {
        t0 = vader_box_i64(248u, l2);
        return t0;
    }
    return vader_box_obj(0u, NULL);
}
