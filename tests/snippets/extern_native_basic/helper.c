/* Helper C unit linked into `extern_native_basic` — provides the
 * `add_i32` symbol that the Vader-side `@extern` declares. `strlen`
 * comes from libc directly (no impl needed here). */
#include <stdint.h>

int32_t add_i32(int32_t a, int32_t b) { return a + b; }
