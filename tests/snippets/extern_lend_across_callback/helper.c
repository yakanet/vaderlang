/* Foreign half of `extern_lend_across_callback`. The callback is what turns a
 * foreign call into a safepoint. `<stdlib.h>` owns `div_t`, as in
 * `c_struct_layout`. */
#include <stdlib.h>
#include <stddef.h>

static void (*g_cb)(int);

void lend_set_cb(void (*cb)(int)) { g_cb = cb; }

void lend_fill_array(int *q, size_t n) {
    g_cb(1);
    for (size_t i = 0; i < n; i++) q[i] = 1000 + (int) i;
}

void lend_fill_div(div_t *d) {
    g_cb(2);
    d->quot = 111;
    d->rem  = 222;
}
