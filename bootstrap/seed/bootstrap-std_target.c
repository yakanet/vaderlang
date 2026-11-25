#include "bootstrap.split.h"

vader_string_t std_target$Arch$std_core$Display$to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 3777u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2012u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 3719u;
    }
    return l1;
}

vader_string_t std_target$Os$std_core$Display$to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 3745u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2830u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2313u;
    } else if (l0 == INT32_C(3)) {
        l1 = 3717u;
    } else {
        if (!(l0 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2111u;
    }
    return l1;
}
