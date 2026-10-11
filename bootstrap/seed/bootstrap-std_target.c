#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2636u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1271u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2614u;
    }
    return l1;
}

vader_string_t std_target_Os_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2623u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1929u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1502u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2613u;
    } else {
        if (!(l0 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1352u;
    }
    return l1;
}
