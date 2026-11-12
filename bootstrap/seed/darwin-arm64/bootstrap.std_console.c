#include "bootstrap.split.h"

static void std_console$write(uint8_t l0, vader_string_t l1);
static int32_t std_console$write_bytes(uint8_t l0, void* l1, int64_t l2);
static bool std_console$write_text(uint8_t l0, vader_string_t l1);

void std_console$eprintln__string(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = concat_2(l0, 1u);
    std_console$write((uint8_t) 1, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void std_console$write(uint8_t l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    int64_t l3, l4, l5, l7, l9;
    int32_t l8;
    bool t0;
    void** gc_raw_roots[2] = { &l2, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_console$write_text(l0, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = vader_host_std_core$bytes(l1);
    l3 = INT64_C(0);
    for (;;) {
        l4 = ((vader_array_t*) l2)->length;
        if (!((l3 >= l4))) {
            l5 = ((vader_array_t*) l2)->length;
            vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (int64_t) l3, (int64_t) l5);
            l6 = (void*) _a0_arr;
            l7 = ((vader_array_t*) l6)->length;
            l8 = std_console$write_bytes(l0, l6, l7);
            if ((l8 <= INT32_C(0))) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            l9 = ((int64_t) (int32_t) l8);
            l3 = vader_chk_add(i64, l3, l9);
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t std_console$write_bytes(uint8_t l0, void* l1, int64_t l2) {
    int32_t l3;
    int64_t l4;
    int32_t t0;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        l3 = INT32_C(1);
    } else {
        l3 = INT32_C(2);
    }
    l4 = vader_host_system_posix$sys_write(l3, l1, l2);
    if ((l4 < INT64_C(0))) {
        t0 = vader_host_system_posix$sys_last_errno();
        if (t0 == INT32_C(32)) {
            vader_host_system_posix$sys_end_on_broken_pipe();
            { int32_t __vret = ((int32_t) (int64_t) l4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { int32_t __vret = ((int32_t) (int64_t) l4); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { int32_t __vret = ((int32_t) (int64_t) l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_console$write_text(uint8_t l0, vader_string_t l1) {
    return false;
}
