#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 2438u;
    }
    if (l0 == INT32_C(1)) {
        return 1174u;
    }
    if (l0 == INT32_C(2)) {
        return 2420u;
    }
    vader_unreachable("unreachable return in std_target$Arch$Display$to_string");
}

vader_string_t std_target_Os_Display_to_string(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 2425u;
    }
    if (l0 == INT32_C(1)) {
        return 1784u;
    }
    if (l0 == INT32_C(2)) {
        return 1404u;
    }
    if (l0 == INT32_C(3)) {
        return 2419u;
    }
    if (l0 == INT32_C(4)) {
        return 1263u;
    }
    vader_unreachable("unreachable return in std_target$Os$Display$to_string");
}

