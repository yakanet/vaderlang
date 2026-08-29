#include "bootstrap.split.h"

size_t std_math_min_2(size_t l0, size_t l1) {
    size_t l2;
    if ((l0 < l1)) {
        l2 = l0;
    } else {
        l2 = l1;
    }
    return l2;
}

