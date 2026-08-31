#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 2422u;
    }
    if (l0 == INT32_C(1)) {
        return 1161u;
    }
    if (l0 == INT32_C(2)) {
        return 2404u;
    }
    vader_unreachable("unreachable return in std_target$Arch$Display$to_string");
}

vader_string_t std_target_Os_Display_to_string(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 2409u;
    }
    if (l0 == INT32_C(1)) {
        return 1769u;
    }
    if (l0 == INT32_C(2)) {
        return 1390u;
    }
    if (l0 == INT32_C(3)) {
        return 2403u;
    }
    if (l0 == INT32_C(4)) {
        return 1250u;
    }
    vader_unreachable("unreachable return in std_target$Os$Display$to_string");
}

