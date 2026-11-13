#include "bootstrap.split.h"

vader_string_t std_target$Arch$std_core$Display$to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 3293u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1677u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 3253u;
    }
    return l1;
}

vader_string_t std_target$Os$std_core$Display$to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 3265u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2421u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1941u;
    } else if (l0 == INT32_C(3)) {
        l1 = 3252u;
    } else {
        if (!(l0 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1763u;
    }
    return l1;
}
