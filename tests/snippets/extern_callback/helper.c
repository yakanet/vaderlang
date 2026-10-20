/* Foreign half of `extern_callback`. Both functions call back into Vader and
 * combine the results, which is what proves the address crossed AND that the
 * ABI matched. In `apply_twice` the callback sits between two scalar arguments,
 * which forces the Vader side to hold its address in a slot rather than an
 * expression temp. */
int call_twice(int (*f)(int)) {
    return f(20) + f(1);
}

int apply_twice(int base, int (*f)(int), int scale) {
    return f(base) * scale + f(base);
}
