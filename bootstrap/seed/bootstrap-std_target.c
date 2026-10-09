#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2615u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1258u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2593u;
    }
    return l1;
}

vader_string_t std_target_Os_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2602u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1914u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1489u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2592u;
    } else {
        if (!(l0 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1339u;
    }
    return l1;
}
