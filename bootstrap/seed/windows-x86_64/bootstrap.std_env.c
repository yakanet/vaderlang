#include "bootstrap.split.h"

static bool std_env$is_flag_value_on(vader_string_t l0);
static vader_string_t std_env$without_trailing_sep(vader_string_t l0);

vader_string_t std_env$current_executable_location(void) {
    void* l0 = NULL;
    uint32_t l1;
    bool l2;
    int64_t l3, l4;
    int32_t l5;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    vader_string_t t3 = 0;
    vader_string_t t4 = 0;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &t3, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(30u, 1u, 2u, 500u);
    ((uint16_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint16_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) INT64_C(4096));
    l0 = (void*) _a1_arr;
    t1 = ((vader_array_t*) l0)->length;
    t2 = ((int32_t) (int64_t) t1);
    l1 = (uint32_t) (int32_t) t2;
    l1 = vader_host_system_windows$get_module_file_name(vader_box_obj(0u, NULL), l0, l1);
    if (l1 == INT32_C(0)) {
        l2 = true;
    } else {
        l3 = ((int64_t) (uint32_t) l1);
        l4 = ((vader_array_t*) l0)->length;
        l2 = (l3 >= l4);
    }
    if (!(l2)) {
        l5 = ((int32_t) (uint32_t) l1);
        t3 = system_windows$from_wide(l0, l5);
        t4 = std_path$to_posix(t3);
        { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 433u; }
}

vader_string_t std_env$current_working_directory(void) {
    void* l0 = NULL;
    uint32_t l1;
    bool l2;
    int64_t l3, l4;
    int32_t l5;
    void* t0 = NULL;
    int64_t t1;
    vader_string_t t2 = 0;
    vader_string_t t3 = 0;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &t2, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(30u, 1u, 2u, 500u);
    ((uint16_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint16_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) INT64_C(4096));
    l0 = (void*) _a1_arr;
    t1 = ((vader_array_t*) l0)->length;
    l1 = vader_host_system_windows$get_current_directory((uint32_t) (int32_t) ((int32_t) (int64_t) t1), l0);
    if (l1 == INT32_C(0)) {
        l2 = true;
    } else {
        l3 = ((int64_t) (uint32_t) l1);
        l4 = ((vader_array_t*) l0)->length;
        l2 = (l3 >= l4);
    }
    if (!(l2)) {
        l5 = ((int32_t) (uint32_t) l1);
        t2 = system_windows$from_wide(l0, l5);
        t3 = std_path$to_posix(t2);
        t2 = std_env$without_trailing_sep(t3);
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
    void* t0 = NULL;
    int32_t t1;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = system_windows$to_wide(l0);
    t1 = vader_host_system_windows$set_current_directory(t0);
    if (!(t1 == INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = std_io$last_io_error(1834u);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_env$without_trailing_sep(vader_string_t l0) {
    int64_t l1, l2, l3, l4, l5;
    int64_t t0, t1;
    uint8_t t2;
    vader_string_t t3;
    l1 = INT64_C(0);
    l2 = INT64_C(0);
    l3 = vader_host_std_core$byte_len(l0);
    while ((l2 < l3)) {
        t0 = vader_host_std_core$byte_len(l0);
        t1 = vader_chk_sub(i64, t0, INT64_C(1));
        l4 = vader_chk_sub(i64, t1, l2);
        if (l4 == INT64_C(0)) break;
        t2 = vader_host_std_core$byte_at(l0, l4);
        if (t2 != INT32_C(47)) break;
        l5 = vader_chk_sub(i64, l4, INT64_C(1));
        t2 = vader_host_std_core$byte_at(l0, l5);
        if (t2 == INT32_C(58)) break;
        l1 = vader_chk_add(i64, l1, INT64_C(1));
        l2 = (l2 + INT64_C(1));
    }
    if (!(l1 == INT64_C(0))) {
        t0 = vader_host_std_core$byte_len(l0);
        l1 = vader_chk_sub(i64, t0, l1);
        t3 = vader_host_std_core$byte_slice(l0, INT64_C(0), l1);
        return t3;
    }
    return l0;
}
