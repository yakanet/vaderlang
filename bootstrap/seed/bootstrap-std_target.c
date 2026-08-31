#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 2428u;
    }
    if (l0 == INT32_C(1)) {
        return 1162u;
    }
    if (l0 == INT32_C(2)) {
        return 2410u;
    }
    vader_unreachable("unreachable return in std_target$Arch$Display$to_string");
}

vader_string_t std_target_Os_Display_to_string(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 2415u;
    }
    if (l0 == INT32_C(1)) {
        return 1774u;
    }
    if (l0 == INT32_C(2)) {
        return 1391u;
    }
    if (l0 == INT32_C(3)) {
        return 2409u;
    }
    if (l0 == INT32_C(4)) {
        return 1251u;
    }
    vader_unreachable("unreachable return in std_target$Os$Display$to_string");
}

