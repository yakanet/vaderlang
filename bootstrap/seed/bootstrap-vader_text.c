#include "bootstrap.split.h"

bool vader_text_is_ident_byte(uint8_t l0) {
    bool l1, l2;
    if ((l0 >= INT32_C(65))) {
        l1 = (l0 <= INT32_C(90));
    } else {
        l1 = false;
    }
    if (l1) {
        l1 = true;
    } else {
        if ((l0 >= INT32_C(97))) {
            l2 = (l0 <= INT32_C(122));
        } else {
            l2 = false;
        }
        l1 = l2;
    }
    if (l1) {
        l1 = true;
    } else {
        if ((l0 >= INT32_C(48))) {
            l2 = (l0 <= INT32_C(57));
        } else {
            l2 = false;
        }
        l1 = l2;
    }
    if (l1) {
        return true;
    }
    return l0 == INT32_C(95);
}
