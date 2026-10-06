#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2521u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1192u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2498u;
    }
    return l1;
}

vader_string_t std_target_Os_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2507u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1832u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1420u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2497u;
    } else {
        if (!(l0 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1272u;
    }
    return l1;
}
