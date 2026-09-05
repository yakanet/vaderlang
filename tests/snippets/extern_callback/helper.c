/* Foreign half of `extern_callback` — calls back into Vader twice and sums the
 * results, which is what proves the address crossed AND that the ABI matched. */
int call_twice(int (*f)(int)) {
    return f(20) + f(1);
}
