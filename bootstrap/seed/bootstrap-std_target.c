#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 2416u;
    }
    if (l0 == INT32_C(1)) {
        return 1158u;
    }
    if (l0 == INT32_C(2)) {
        return 2398u;
    }
    vader_unreachable("unreachable return in std_target$Arch$Display$to_string");
}

vader_string_t std_target_Os_Display_to_string(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 2403u;
    }
    if (l0 == INT32_C(1)) {
        return 1764u;
    }
    if (l0 == INT32_C(2)) {
        return 1386u;
    }
    if (l0 == INT32_C(3)) {
        return 2397u;
    }
    if (l0 == INT32_C(4)) {
        return 1247u;
    }
    vader_unreachable("unreachable return in std_target$Os$Display$to_string");
}

