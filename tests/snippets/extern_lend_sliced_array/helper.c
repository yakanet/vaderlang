/* Foreign half of `extern_lend_sliced_array`. The callback collects in the
 * middle of the lend, which is what a lent buffer must survive. */
#include <stddef.h>

static void (*g_cb)(int);

void slice_set_cb(void (*cb)(int)) { g_cb = cb; }

void slice_fill(int *q, size_t n) {
    g_cb(1);
    for (size_t i = 0; i < n; i++) q[i] = 1000 + (int) i;
}
