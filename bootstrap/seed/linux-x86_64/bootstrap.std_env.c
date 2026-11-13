#include "bootstrap.split.h"

static bool std_env$is_flag_value_on(vader_string_t l0);

vader_string_t std_env$current_executable_location(void) {
    void* l0 = NULL;
    int64_t l1;
    void* t0 = NULL;
    int64_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 1u, 1u, 504u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) INT64_C(4096));
    l0 = (void*) _a1_arr;
    t1 = ((vader_array_t*) l0)->length;
    l1 = vader_chk_sub(i64, t1, INT64_C(1));
    t1 = vader_host_system_posix$sys_readlink(496u, l0, l1);
    if (!((t1 <= INT64_C(0)))) {
        t2 = system_posix$up_to_nul(l0);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 433u; }
}

vader_string_t std_env$current_working_directory(void) {
    void* l0 = NULL;
    int64_t l1;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 1u, 1u, 504u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) INT64_C(4096));
    l0 = (void*) _a1_arr;
    l1 = ((vader_array_t*) l0)->length;
    t1 = vader_host_system_posix$sys_getcwd(l0, l1);
    if (!(t1.tag == 0u)) {
        t2 = system_posix$up_to_nul(l0);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 433u; }
}

vader_box_t std_env$get_env(vader_string_t l0) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_host_system_libc$sys_getenv(l0);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

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
    l1 = std_env$get_env(l0);
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

vader_box_t std_env$set_current_working_directory(vader_string_t l0) {
    int32_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_host_system_posix$sys_chdir(l0);
    if (!(t0 != INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = std_io$last_io_error(1841u);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}
