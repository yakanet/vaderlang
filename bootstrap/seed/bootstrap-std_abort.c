#include "bootstrap.split.h"

void std_abort$todo(vader_string_t l0) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = concat_2(2404u, l0);
    vader_host_std_abort$panic(t0);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

void std_abort$unreachable(vader_string_t l0) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = concat_2(1876u, l0);
    vader_host_std_abort$panic(t0);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}
