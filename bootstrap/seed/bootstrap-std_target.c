#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 2380u;
    }
    if (l0 == INT32_C(1)) {
        return 1133u;
    }
    if (l0 == INT32_C(2)) {
        return 2360u;
    }
    vader_unreachable("unreachable return in std_target$Arch$Display$to_string");
}

vader_string_t std_target_Os_Display_to_string(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 2365u;
    }
    if (l0 == INT32_C(1)) {
        return 1731u;
    }
    if (l0 == INT32_C(2)) {
        return 1360u;
    }
    if (l0 == INT32_C(3)) {
        return 2359u;
    }
    if (l0 == INT32_C(4)) {
        return 1222u;
    }
    vader_unreachable("unreachable return in std_target$Os$Display$to_string");
}

