#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 2405u;
    }
    if (l0 == INT32_C(1)) {
        return 1149u;
    }
    if (l0 == INT32_C(2)) {
        return 2387u;
    }
    vader_unreachable("unreachable return in std_target$Arch$Display$to_string");
}

vader_string_t std_target_Os_Display_to_string(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 2392u;
    }
    if (l0 == INT32_C(1)) {
        return 1753u;
    }
    if (l0 == INT32_C(2)) {
        return 1376u;
    }
    if (l0 == INT32_C(3)) {
        return 2386u;
    }
    if (l0 == INT32_C(4)) {
        return 1238u;
    }
    vader_unreachable("unreachable return in std_target$Os$Display$to_string");
}

