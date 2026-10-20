#include "bootstrap.split.h"

vader_string_t std_target_Arch_std_core_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2809u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1390u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2781u;
    }
    return l1;
}

vader_string_t std_target_Os_std_core_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2790u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2065u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1627u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2780u;
    } else {
        if (!(l0 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1477u;
    }
    return l1;
}
