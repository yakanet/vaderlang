#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2587u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1243u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2565u;
    }
    return l1;
}

vader_string_t std_target_Os_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2574u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1889u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1472u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2564u;
    } else {
        if (!(l0 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1324u;
    }
    return l1;
}
