#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2505u;
    } else {
        if (l0 == INT32_C(1)) {
            l1 = 1251u;
        } else {
            if (l0 == INT32_C(2)) {
                l1 = 2488u;
            } else {
                vader_unreachable("unreachable return in std_target$Arch$Display$to_string");
            }
        }
    }
    return l1;
}

vader_string_t std_target_Os_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2494u;
    } else {
        if (l0 == INT32_C(1)) {
            l1 = 1878u;
        } else {
            if (l0 == INT32_C(2)) {
                l1 = 1490u;
            } else {
                if (l0 == INT32_C(3)) {
                    l1 = 2487u;
                } else {
                    if (l0 == INT32_C(4)) {
                        l1 = 1343u;
                    } else {
                        vader_unreachable("unreachable return in std_target$Os$Display$to_string");
                    }
                }
            }
        }
    }
    return l1;
}

