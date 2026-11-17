#include "bootstrap.split.h"

vader_string_t std_target$Arch$std_core$Display$to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 3324u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1777u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 3281u;
    }
    return l1;
}

vader_string_t std_target$Os$std_core$Display$to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 3295u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2502u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2052u;
    } else if (l0 == INT32_C(3)) {
        l1 = 3280u;
    } else {
        if (!(l0 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1866u;
    }
    return l1;
}
