/* Foreign half of `extern_callback_slot`. The callback sits between two scalar
 * arguments, which is what forces the Vader side to hold its address in a slot
 * rather than an expression temp. */
int apply_twice(int base, int (*f)(int), int scale) {
    return f(base) * scale + f(base);
}
