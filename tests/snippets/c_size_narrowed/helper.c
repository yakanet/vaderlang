/* Foreign half of `c_struct_layout` — fills a `div_t` through a pointer, the
 * shape `@c_struct` marshalling exists for. `<stdlib.h>` owns the type. */
#include <stdlib.h>

void fill_div(div_t* d, int quot, int rem) {
    d->quot = quot;
    d->rem  = rem;
}
