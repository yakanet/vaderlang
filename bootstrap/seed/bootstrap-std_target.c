#include "bootstrap.split.h"

vader_string_t std_target$Arch$std_core$Display$to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 3094u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1578u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 3065u;
    }
    return l1;
}

vader_string_t std_target$Os$std_core$Display$to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 3073u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2299u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1840u;
    } else if (l0 == INT32_C(3)) {
        l1 = 3064u;
    } else {
        if (!(l0 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1672u;
    }
    return l1;
}
