#include "bootstrap.split.h"

bool std_char_is_alnum(uint32_t l0) {
    bool l1;
    bool t0;
    t0 = std_char_is_alpha(l0);
    if (t0) {
        l1 = true;
    } else {
        l1 = std_char_is_digit(l0);
    }
    return l1;
}

bool std_char_is_alpha(uint32_t l0) {
    bool l1, l2;
    if ((97u <= l0)) {
        l1 = (l0 <= 122u);
    } else {
        l1 = false;
    }
    if (l1) {
        l1 = true;
    } else {
        if ((65u <= l0)) {
            l2 = (l0 <= 90u);
        } else {
            l2 = false;
        }
        l1 = l2;
    }
    return l1;
}

bool std_char_is_digit(uint32_t l0) {
    bool l1;
    if ((48u <= l0)) {
        l1 = (l0 <= 57u);
    } else {
        l1 = false;
    }
    return l1;
}

bool std_char_is_white_char(uint32_t l0) {
    bool l1;
    if (l0 == 32u) {
        l1 = true;
    } else {
        l1 = l0 == 9u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 10u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 13u;
    }
    return l1;
}

