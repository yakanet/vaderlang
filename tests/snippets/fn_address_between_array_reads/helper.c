/* Foreign half of `fn_address_between_array_reads`: calls the callback, so the
 * result proves the address crossed with the right ABI. */
int apply(int (*f)(int), int x) {
    return f(x);
}
