#include "bootstrap.split.h"

bool std_char_is_alnum(uint32_t l0) {
    bool t0;
    t0 = std_char_is_alpha(l0);
    if (t0) {
        return true;
    }
    t0 = std_char_is_digit(l0);
    return t0;
}

bool std_char_is_alpha(uint32_t l0) {
    bool l1;
    if ((97u <= l0)) {
        l1 = (l0 <= 122u);
    } else {
        l1 = false;
    }
    if (l1) {
        return true;
    }
    if ((65u <= l0)) {
        l1 = (l0 <= 90u);
    } else {
        l1 = false;
    }
    return l1;
}

bool std_char_is_digit(uint32_t l0) {
    if ((48u <= l0)) {
        return (l0 <= 57u);
    }
    return false;
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
        return true;
    }
    return l0 == 13u;
}
