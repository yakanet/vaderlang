#include "bootstrap.split.h"

static bool std_env$is_flag_value_on(vader_string_t l0);

bool std_env$is_env_flag_on(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t t0 = 0;
    bool t1;
    vader_box_t* gc_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_env$get_env(l0);
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = l1.payload.s;
    t1 = std_env$is_flag_value_on(t0);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_env$is_flag_value_on(vader_string_t l0) {
    uint8_t t0;
    if (l0 != 0u) {
        t0 = vader_host_std_core$byte_at(l0, INT64_C(0));
        return t0 != INT32_C(48);
    }
    return false;
}
