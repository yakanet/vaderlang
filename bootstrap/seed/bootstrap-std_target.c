#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 2407u;
    }
    if (l0 == INT32_C(1)) {
        return 1177u;
    }
    if (l0 == INT32_C(2)) {
        return 2390u;
    }
    vader_unreachable("unreachable return in std_target$Arch$Display$to_string");
}

vader_string_t std_target_Os_Display_to_string(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 2396u;
    }
    if (l0 == INT32_C(1)) {
        return 1786u;
    }
    if (l0 == INT32_C(2)) {
        return 1408u;
    }
    if (l0 == INT32_C(3)) {
        return 2389u;
    }
    if (l0 == INT32_C(4)) {
        return 1266u;
    }
    vader_unreachable("unreachable return in std_target$Os$Display$to_string");
}

