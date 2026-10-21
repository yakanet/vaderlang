#include "bootstrap.split.h"

vader_string_t std_target_Arch_std_core_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2830u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1406u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2802u;
    }
    return l1;
}

vader_string_t std_target_Os_std_core_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2811u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2081u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1643u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2801u;
    } else {
        if (!(l0 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1493u;
    }
    return l1;
}
