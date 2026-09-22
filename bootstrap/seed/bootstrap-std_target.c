#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2511u;
    } else {
        if (l0 == INT32_C(1)) {
            l1 = 1256u;
        } else {
            if (l0 == INT32_C(2)) {
                l1 = 2494u;
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
        l1 = 2500u;
    } else {
        if (l0 == INT32_C(1)) {
            l1 = 1884u;
        } else {
            if (l0 == INT32_C(2)) {
                l1 = 1496u;
            } else {
                if (l0 == INT32_C(3)) {
                    l1 = 2493u;
                } else {
                    if (l0 == INT32_C(4)) {
                        l1 = 1348u;
                    } else {
                        vader_unreachable("unreachable return in std_target$Os$Display$to_string");
                    }
                }
            }
        }
    }
    return l1;
}

