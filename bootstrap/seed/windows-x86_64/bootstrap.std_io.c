#include "bootstrap.split.h"

static void* std_io$classified_error(vader_string_t l0, uint8_t l1, int32_t l2);
static vader_string_t std_io$describe_io_error_kind(uint8_t l0, vader_string_t l1);
static uint8_t std_io$win32_error_kind(uint32_t l0);

vader_string_t std_io$IOError$std_core$Error$message(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_std_io$IOError_t*) l0)->f_msg;
    return t0;
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
    vader_obj_header_init(_a0_obj, 858u);
    _a0_obj->f_msg = t0;
    _a0_obj->f_kind = l1;
    _a0_obj->f_code = l2;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_io$describe_io_error_kind(uint8_t l0, vader_string_t l1) {
    vader_string_t l2;
    if (l0 == INT32_C(1)) {
        l2 = 2124u;
        return l2;
    }
    if (l0 == INT32_C(2)) {
        l2 = 2614u;
    } else if (l0 == INT32_C(3)) {
        l2 = 2315u;
    } else if (l0 == INT32_C(4)) {
        l2 = 1629u;
    } else if (l0 == INT32_C(5)) {
        l2 = 2550u;
    } else if (l0 == INT32_C(6)) {
        l2 = 2336u;
    } else if (l0 == INT32_C(7)) {
        l2 = 3257u;
    } else if (l0 == INT32_C(8)) {
        l2 = 1754u;
    } else if (l0 == INT32_C(9)) {
        l2 = 2541u;
    } else if (l0 == INT32_C(10)) {
        l2 = 2327u;
    } else if (l0 == INT32_C(11)) {
        l2 = 1955u;
    } else if (l0 == INT32_C(12)) {
        l2 = 1721u;
    } else {
        if (!(l0 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l1;
    }
    return l2;
}

void* std_io$last_io_error(vader_string_t l0) {
    uint32_t l1;
    uint8_t l2;
    int32_t l3;
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_host_system_windows$get_last_error();
    l2 = std_io$win32_error_kind(l1);
    l3 = ((int32_t) (uint32_t) l1);
    t0 = std_io$classified_error(l0, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t std_io$win32_error_kind(uint32_t l0) {
    if (l0 == INT32_C(2)) {
        return (uint8_t) 1;
    }
    if (l0 == INT32_C(3)) {
        return (uint8_t) 1;
    }
    if (l0 == INT32_C(5)) {
        return (uint8_t) 2;
    }
    if (l0 == INT32_C(6)) {
        return (uint8_t) 12;
    }
    if (l0 == INT32_C(80)) {
        return (uint8_t) 4;
    }
    if (l0 == INT32_C(183)) {
        return (uint8_t) 4;
    }
    if (l0 == INT32_C(109)) {
        return (uint8_t) 8;
    }
    if (l0 == INT32_C(112)) {
        return (uint8_t) 9;
    }
    if (!(l0 == INT32_C(145))) {
        return (uint8_t) 0;
    }
    return (uint8_t) 11;
}
