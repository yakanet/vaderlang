#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2508u;
    } else {
        if (l0 == INT32_C(1)) {
            l1 = 1253u;
        } else {
            if (l0 == INT32_C(2)) {
                l1 = 2491u;
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
        l1 = 2497u;
    } else {
        if (l0 == INT32_C(1)) {
            l1 = 1881u;
        } else {
            if (l0 == INT32_C(2)) {
                l1 = 1493u;
            } else {
                if (l0 == INT32_C(3)) {
                    l1 = 2490u;
                } else {
                    if (l0 == INT32_C(4)) {
                        l1 = 1345u;
                    } else {
                        vader_unreachable("unreachable return in std_target$Os$Display$to_string");
                    }
                }
            }
        }
    }
    return l1;
}

