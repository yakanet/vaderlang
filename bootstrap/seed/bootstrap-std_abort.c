#include "bootstrap.split.h"

void std_abort_todo(vader_string_t l0) {
    vader_string_t t0;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = concat_2(1863u, l0);
    vader_host_std_abort_panic(t0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_abort_unreachable(vader_string_t l0) {
    vader_string_t t0;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = concat_2(1437u, l0);
    vader_host_std_abort_panic(t0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

