#include "bootstrap.split.h"

bool std_env$is_env_flag_on(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_box_t l2 = vader_box_null();
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_env$get_env(l0);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l1 = l2.payload.s;
    if (l1 != 0u) {
        t0 = vader_host_std_core$byte_at(l1, INT64_C(0));
        { bool __vret = t0 != INT32_C(48); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}
