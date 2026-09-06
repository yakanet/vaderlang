#include "bootstrap.split.h"

vader_string_t std_target_Arch_Display_to_string(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2419u;
    } else {
        if (l0 == INT32_C(1)) {
            l1 = 1195u;
        } else {
            if (l0 == INT32_C(2)) {
                l1 = 2401u;
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
        l1 = 2407u;
    } else {
        if (l0 == INT32_C(1)) {
            l1 = 1811u;
        } else {
            if (l0 == INT32_C(2)) {
                l1 = 1430u;
            } else {
                if (l0 == INT32_C(3)) {
                    l1 = 2400u;
                } else {
                    if (l0 == INT32_C(4)) {
                        l1 = 1286u;
                    } else {
                        vader_unreachable("unreachable return in std_target$Os$Display$to_string");
                    }
                }
            }
        }
    }
    return l1;
}

