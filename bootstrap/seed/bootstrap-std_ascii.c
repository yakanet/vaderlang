#include "bootstrap.split.h"

vader_box_t std_ascii$hex_value(uint8_t l0) {
    vader_box_t l1;
    bool l2;
    int32_t t0, t1;
    if ((l0 >= INT32_C(48))) {
        l2 = (l0 <= INT32_C(57));
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = vader_chk_sub(u8, l0, INT32_C(48));
        l1 = vader_box_i32(631u, t0);
        return l1;
    }
    if ((l0 >= INT32_C(65))) {
        l2 = (l0 <= INT32_C(70));
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = vader_chk_sub(u8, l0, INT32_C(65));
        t1 = vader_chk_add(u8, t0, INT32_C(10));
        l1 = vader_box_i32(631u, t1);
    } else {
        if ((l0 >= INT32_C(97))) {
            l2 = (l0 <= INT32_C(102));
        } else {
            l2 = false;
        }
        if (l2) {
            t0 = vader_chk_sub(u8, l0, INT32_C(97));
            t1 = vader_chk_add(u8, t0, INT32_C(10));
            l1 = vader_box_i32(631u, t1);
        } else {
            l1 = vader_box_obj(0u, NULL);
        }
    }
    return l1;
}

bool std_ascii$is_digit_byte(uint8_t l0) {
    if ((l0 >= INT32_C(48))) {
        return (l0 <= INT32_C(57));
    }
    return false;
}

bool std_ascii$is_white_byte(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(32)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(9);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(10);
    }
    if (l1) {
        return true;
    }
    return l0 == INT32_C(13);
}

uint8_t std_ascii$to_lower_byte(uint8_t l0) {
    bool l1;
    uint8_t l2;
    int32_t t0;
    if ((l0 >= INT32_C(65))) {
        l1 = (l0 <= INT32_C(90));
    } else {
        l1 = false;
    }
    if (l1) {
        l2 = (uint8_t) 32;
        t0 = vader_chk_add(u8, l0, l2);
        return (uint8_t) (int32_t) t0;
    }
    return l0;
}
