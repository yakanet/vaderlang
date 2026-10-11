#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2652u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1282u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2630u;
    }
    return l1;
}

vader_string_t std_target_Os_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2639u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1940u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1513u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2629u;
    } else {
        if (!(l0 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1363u;
    }
    return l1;
}
