#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2660u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1287u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2638u;
    }
    return l1;
}

vader_string_t std_target_Os_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2647u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1948u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1519u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2637u;
    } else {
        if (!(l0 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1368u;
    }
    return l1;
}
