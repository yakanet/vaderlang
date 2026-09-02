#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 2385u;
    }
    if (l0 == INT32_C(1)) {
        return 1158u;
    }
    if (l0 == INT32_C(2)) {
        return 2369u;
    }
    vader_unreachable("unreachable return in std_target$Arch$Display$to_string");
}

vader_string_t std_target_Os_Display_to_string(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 2375u;
    }
    if (l0 == INT32_C(1)) {
        return 1761u;
    }
    if (l0 == INT32_C(2)) {
        return 1387u;
    }
    if (l0 == INT32_C(3)) {
        return 2368u;
    }
    if (l0 == INT32_C(4)) {
        return 1247u;
    }
    vader_unreachable("unreachable return in std_target$Os$Display$to_string");
}

