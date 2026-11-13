#include "bootstrap.split.h"

static bool std_env$is_flag_value_on(vader_string_t l0);

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
    vader_array_t* _a0_arr = vader_array_new(30u, 1u, 2u, 505u);
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
    vader_array_t* _a0_arr = vader_array_new(30u, 1u, 2u, 505u);
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
        { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 433u; }
}

vader_box_t std_env$get_env(vader_string_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    uint32_t l3, l7;
    int64_t l5;
    int32_t l8;
    vader_string_t t0 = 0;
    void** gc_raw_roots[4] = { &l1, &l2, &l4, &l6 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = system_windows$to_wide(l0);
    vader_array_t* _a0_arr = vader_array_new(30u, 0u, 2u, 505u);
    l2 = (void*) _a0_arr;
    for (;;) {
        l3 = vader_host_system_windows$get_environment_variable_w(l1, l2, (uint32_t) 0);
        if (!(l3 == INT32_C(0))) {
            vader_array_t* _a1_arr = vader_array_new(30u, 1u, 2u, 505u);
            ((uint16_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (uint16_t) INT32_C(0);
            l4 = (void*) _a1_arr;
            l5 = ((int64_t) (uint32_t) l3);
            vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
            l6 = (void*) _a2_arr;
            l7 = vader_host_system_windows$get_environment_variable_w(l1, l6, l3);
            if (!((l7 < l3))) {
                continue;
            }
            l8 = ((int32_t) (uint32_t) l7);
            t0 = system_windows$from_wide(l6, l8);
            { vader_box_t __vret = vader_box_string(499u, t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
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
    t0 = std_io$last_io_error(1841u);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}
