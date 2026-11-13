#include "bootstrap.split.h"

static void* std_io$classified_error(vader_string_t l0, uint8_t l1, int32_t l2);
static vader_string_t std_io$describe_io_error_kind(uint8_t l0, vader_string_t l1);
static uint8_t std_io$errno_kind(int32_t l0);

vader_string_t std_io$IOError$std_core$Error$message(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_std_io$IOError_t*) l0)->f_msg;
    return t0;
}

void* std_io$bytes_of(vader_box_t l0) {
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 499u) {
        t0 = l0.payload.s;
        t1 = vader_host_std_core$bytes(t0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l0.payload.obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* std_io$classified_error(vader_string_t l0, uint8_t l1, int32_t l2) {
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_io$describe_io_error_kind(l1, l0);
    vader_struct_std_io$IOError_t* _a0_obj = (vader_struct_std_io$IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io$IOError_t));
    vader_obj_header_init(_a0_obj, 873u);
    _a0_obj->f_msg = t0;
    _a0_obj->f_kind = l1;
    _a0_obj->f_code = l2;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_io$describe_io_error_kind(uint8_t l0, vader_string_t l1) {
    vader_string_t l2;
    if (l0 == INT32_C(1)) {
        l2 = 2137u;
        return l2;
    }
    if (l0 == INT32_C(2)) {
        l2 = 2628u;
    } else if (l0 == INT32_C(3)) {
        l2 = 2328u;
    } else if (l0 == INT32_C(4)) {
        l2 = 1635u;
    } else if (l0 == INT32_C(5)) {
        l2 = 2565u;
    } else if (l0 == INT32_C(6)) {
        l2 = 2350u;
    } else if (l0 == INT32_C(7)) {
        l2 = 3269u;
    } else if (l0 == INT32_C(8)) {
        l2 = 1761u;
    } else if (l0 == INT32_C(9)) {
        l2 = 2556u;
    } else if (l0 == INT32_C(10)) {
        l2 = 2340u;
    } else if (l0 == INT32_C(11)) {
        l2 = 1966u;
    } else if (l0 == INT32_C(12)) {
        l2 = 1728u;
    } else if (l0 == INT32_C(13)) {
        l2 = 2009u;
    } else {
        if (!(l0 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l1;
    }
    return l2;
}

static uint8_t std_io$errno_kind(int32_t l0) {
    int32_t l1;
    if (l0 == INT32_C(2)) {
        return (uint8_t) 1;
    }
    if (l0 == INT32_C(1)) {
        return (uint8_t) 2;
    }
    if (l0 == INT32_C(13)) {
        return (uint8_t) 2;
    }
    if (l0 == INT32_C(4)) {
        return (uint8_t) 3;
    }
    if (l0 == INT32_C(17)) {
        return (uint8_t) 4;
    }
    if (l0 == INT32_C(20)) {
        return (uint8_t) 5;
    }
    if (l0 == INT32_C(21)) {
        return (uint8_t) 6;
    }
    if (INT32_C(2) == INT32_C(2)) {
        l1 = INT32_C(35);
    } else {
        l1 = INT32_C(11);
    }
    if (l0 == l1) {
        return (uint8_t) 7;
    }
    if (l0 == INT32_C(32)) {
        return (uint8_t) 8;
    }
    if (l0 == INT32_C(28)) {
        return (uint8_t) 9;
    }
    if (l0 == INT32_C(22)) {
        return (uint8_t) 10;
    }
    if (INT32_C(2) == INT32_C(2)) {
        l1 = INT32_C(66);
    } else {
        l1 = INT32_C(39);
    }
    if (l0 == l1) {
        return (uint8_t) 11;
    }
    if (!(l0 == INT32_C(9))) {
        return (uint8_t) 0;
    }
    return (uint8_t) 12;
}

void* std_io$last_io_error(vader_string_t l0) {
    int32_t l1;
    uint8_t l2;
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_host_system_posix$sys_last_errno();
    l2 = std_io$errno_kind(l1);
    t0 = std_io$classified_error(l0, l2, l1);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
