#include "bootstrap.split.h"

int64_t std_math$abs_2(int64_t l0) {
    int64_t t0;
    if ((l0 < INT64_C(0))) {
        t0 = vader_chk_neg(i64, l0);
        return t0;
    }
    return l0;
}

bool std_math$is_finite(double l0) {
    return ((uint64_t) (int64_t) ((int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = l0 }).__vu) & INT64_C(9223372036854775807)) < INT64_C(9218868437227405312));
}

int32_t std_math$min_2(int32_t l0, int32_t l1) {
    if ((l0 < l1)) {
        return l0;
    }
    return l1;
}

int64_t std_math$min_3(int64_t l0, int64_t l1) {
    if ((l0 < l1)) {
        return l0;
    }
    return l1;
}
