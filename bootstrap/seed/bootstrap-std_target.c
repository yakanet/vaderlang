#include "bootstrap.split.h"

vader_string_t std_target$Arch$std_core$Display$to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 3420u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1780u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 3377u;
    }
    return l1;
}

vader_string_t std_target$Os$std_core$Display$to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 3391u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2507u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2057u;
    } else if (l0 == INT32_C(3)) {
        l1 = 3376u;
    } else {
        if (!(l0 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1869u;
    }
    return l1;
}
