#include "bootstrap.split.h"

vader_string_t std_target$Arch$std_core$Display$to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 3616u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1932u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 3570u;
    }
    return l1;
}

vader_string_t std_target$Os$std_core$Display$to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 3586u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2727u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2227u;
    } else if (l0 == INT32_C(3)) {
        l1 = 3569u;
    } else {
        if (!(l0 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2029u;
    }
    return l1;
}
