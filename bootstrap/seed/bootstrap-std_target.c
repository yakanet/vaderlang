#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2456u;
    } else {
        if (l0 == INT32_C(1)) {
            l1 = 1223u;
        } else {
            if (l0 == INT32_C(2)) {
                l1 = 2439u;
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
        l1 = 2445u;
    } else {
        if (l0 == INT32_C(1)) {
            l1 = 1841u;
        } else {
            if (l0 == INT32_C(2)) {
                l1 = 1457u;
            } else {
                if (l0 == INT32_C(3)) {
                    l1 = 2438u;
                } else {
                    if (l0 == INT32_C(4)) {
                        l1 = 1314u;
                    } else {
                        vader_unreachable("unreachable return in std_target$Os$Display$to_string");
                    }
                }
            }
        }
    }
    return l1;
}

