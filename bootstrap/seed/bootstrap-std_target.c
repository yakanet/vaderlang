#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2540u;
    } else {
        if (l0 == INT32_C(1)) {
            l1 = 1273u;
        } else {
            if (l0 == INT32_C(2)) {
                l1 = 2521u;
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
        l1 = 2527u;
    } else {
        if (l0 == INT32_C(1)) {
            l1 = 1905u;
        } else {
            if (l0 == INT32_C(2)) {
                l1 = 1513u;
            } else {
                if (l0 == INT32_C(3)) {
                    l1 = 2520u;
                } else {
                    if (l0 == INT32_C(4)) {
                        l1 = 1365u;
                    } else {
                        vader_unreachable("unreachable return in std_target$Os$Display$to_string");
                    }
                }
            }
        }
    }
    return l1;
}

