#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2423u;
    } else {
        if (l0 == INT32_C(1)) {
            l1 = 1198u;
        } else {
            if (l0 == INT32_C(2)) {
                l1 = 2405u;
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
        l1 = 2411u;
    } else {
        if (l0 == INT32_C(1)) {
            l1 = 1814u;
        } else {
            if (l0 == INT32_C(2)) {
                l1 = 1433u;
            } else {
                if (l0 == INT32_C(3)) {
                    l1 = 2404u;
                } else {
                    if (l0 == INT32_C(4)) {
                        l1 = 1289u;
                    } else {
                        vader_unreachable("unreachable return in std_target$Os$Display$to_string");
                    }
                }
            }
        }
    }
    return l1;
}

