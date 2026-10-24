#include "bootstrap.split.h"

int64_t std_math_abs_2(int64_t l0) {
    int64_t t0;
    if ((l0 < INT64_C(0))) {
        t0 = vader_chk_neg(i64, l0);
        return t0;
    }
    return l0;
}

int32_t std_math_min_2(int32_t l0, int32_t l1) {
    if ((l0 < l1)) {
        return l0;
    }
    return l1;
}

int64_t std_math_min_3(int64_t l0, int64_t l1) {
    if ((l0 < l1)) {
        return l0;
    }
    return l1;
}
