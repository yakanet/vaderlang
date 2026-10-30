#include "bootstrap.split.h"

static void* std_io$classified_error(vader_string_t l0, uint8_t l1, int32_t l2);
static vader_string_t std_io$describe_io_error_kind(uint8_t l0, vader_string_t l1);
static vader_string_t std_io$from_wide(void* l0, int32_t l1);
static vader_string_t std_io$glob_separator(vader_string_t l0);
static bool std_io$has_console_mode(void* l0);
static bool std_io$is_console(uint8_t l0);
static void* std_io$last_io_error(vader_string_t l0);
static vader_box_t std_io$read_file_bytes(vader_string_t l0, int64_t l1);
static void* std_io$std_handle(uint8_t l0);
static bool std_io$stderr_is_console(void);
static bool std_io$stderr_is_console$singleton(void);
static bool std_io$stdout_is_console(void);
static bool std_io$stdout_is_console$singleton(void);
static vader_string_t std_io$to_slash(vader_string_t l0);
static void* std_io$to_wide(vader_string_t l0);
static vader_box_t std_io$whole_buffer(int64_t l0, int64_t l1);
static void* std_io$wide_to_utf8(void* l0, int32_t l1);
static uint8_t std_io$win32_error_kind(uint32_t l0);
static vader_string_t std_io$without_trailing_sep(vader_string_t l0);
static void std_io$write(uint8_t l0, vader_string_t l1);
static int32_t std_io$write_bytes(uint8_t l0, void* l1, int64_t l2);
static vader_box_t std_io$write_file_bytes(vader_string_t l0, void* l1);
static bool std_io$write_text(uint8_t l0, vader_string_t l1);

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
    vader_obj_header_init(_a0_obj, 624u);
    _a0_obj->f_msg = t0;
    _a0_obj->f_kind = l1;
    _a0_obj->f_code = l2;
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t std_io$current_executable_location(void) {
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
    vader_array_t* _a0_arr = vader_array_new(26u, 1u, 2u, 341u);
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
        t3 = std_io$from_wide(l0, l5);
        t4 = std_io$to_slash(t3);
        { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 399u; }
}

vader_string_t std_io$current_working_directory(void) {
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
    vader_array_t* _a0_arr = vader_array_new(26u, 1u, 2u, 341u);
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
        t2 = std_io$from_wide(l0, l5);
        t3 = std_io$to_slash(t2);
        t2 = std_io$without_trailing_sep(t3);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 399u; }
}

static vader_string_t std_io$describe_io_error_kind(uint8_t l0, vader_string_t l1) {
    vader_string_t l2;
    if (l0 == INT32_C(1)) {
        l2 = 1996u;
        return l2;
    }
    if (l0 == INT32_C(2)) {
        l2 = 2461u;
    } else if (l0 == INT32_C(3)) {
        l2 = 2182u;
    } else if (l0 == INT32_C(4)) {
        l2 = 1514u;
    } else if (l0 == INT32_C(5)) {
        l2 = 2399u;
    } else if (l0 == INT32_C(6)) {
        l2 = 2203u;
    } else if (l0 == INT32_C(7)) {
        l2 = 3025u;
    } else if (l0 == INT32_C(8)) {
        l2 = 1644u;
    } else if (l0 == INT32_C(9)) {
        l2 = 2391u;
    } else if (l0 == INT32_C(10)) {
        l2 = 2194u;
    } else if (l0 == INT32_C(11)) {
        l2 = 1833u;
    } else if (l0 == INT32_C(12)) {
        l2 = 1611u;
    } else {
        if (!(l0 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l1;
    }
    return l2;
}

void std_io$eprintln__string(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = concat_2(l0, 1u);
    std_io$write((uint8_t) 1, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

bool std_io$exists(vader_string_t l0) {
    void* t0 = NULL;
    uint32_t t1;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_io$to_wide(l0);
    t1 = vader_host_system_windows$get_file_attributes(t0);
    { bool __vret = t1 != INT32_C(-1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_io$from_wide(void* l0, int32_t l1) {
    void* t0 = NULL;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_io$wide_to_utf8(l0, l1);
    t1 = vader_host_std_core$bytes_to_string(t0);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_io$glob_separator(vader_string_t l0) {
    int64_t l1;
    uint8_t l2;
    bool l3;
    l1 = vader_host_std_core$byte_len(l0);
    if (l1 == INT64_C(0)) {
        return 0u;
    }
    l1 = vader_chk_sub(i64, l1, INT64_C(1));
    l2 = vader_host_std_core$byte_at(l0, l1);
    if (l2 == INT32_C(92)) {
        l3 = true;
    } else {
        l3 = l2 == INT32_C(47);
    }
    if (l3) {
        l3 = true;
    } else {
        l3 = l2 == INT32_C(58);
    }
    if (!(l3)) {
        return 966u;
    }
    return 0u;
}

static bool std_io$has_console_mode(void* l0) {
    void* l1 = NULL;
    bool t0;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(27u, 1u, 3u, 342u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(0);
    l1 = (void*) _a0_arr;
    t0 = vader_host_system_windows$get_console_mode(l0, l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_io$is_console(uint8_t l0) {
    bool t0;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        t0 = std_io$stdout_is_console();
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0 == INT32_C(1))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = std_io$stderr_is_console();
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool std_io$is_dir(vader_string_t l0) {
    uint32_t l1;
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_io$to_wide(l0);
    l1 = vader_host_system_windows$get_file_attributes(t0);
    if (!(l1 == INT32_C(-1))) {
        { bool __vret = (l1 & INT32_C(16)) != INT32_C(0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void* std_io$last_io_error(vader_string_t l0) {
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

vader_box_t std_io$read_dir(vader_string_t l0) {
    vader_string_t l1 = 0;
    void* l2 = NULL;
    void* l4 = NULL;
    void* l3;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    bool t3;
    void** gc_raw_roots[3] = { &l2, &l4, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_io$glob_separator(l0);
    vader_array_t* _a0_arr = vader_array_new(25u, 1u, 1u, 340u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) INT64_C(1024));
    l2 = (void*) _a1_arr;
    t1 = concat_3(l0, l1, 351u);
    t0 = std_io$to_wide(t1);
    l3 = vader_host_system_windows$find_first_file(t0, l2);
    t2 = (int64_t) (void*) l3;
    if (t2 == INT64_C(-1)) {
        t1 = concat_3(2492u, l0, 1035u);
        vader_struct_std_io$IOError_t* _a2_obj = (vader_struct_std_io$IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io$IOError_t));
        vader_obj_header_init(_a2_obj, 624u);
        _a2_obj->f_msg = t1;
        _a2_obj->f_kind = (uint8_t) 0;
        _a2_obj->f_code = INT32_C(0);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct___defer_env_std_io_1_t* _a3_obj = (vader_struct___defer_env_std_io_1_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_io_1_t));
    vader_obj_header_init(_a3_obj, 357u);
    _a3_obj->f_cap_0 = l3;
    t0 = (void*) _a3_obj;
    vader_fn_t* _a4_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a4_closure, 285u);
    _a4_closure->code = (void*) &vader_fn_lift___defer_std_io_0;
    _a4_closure->env = t0;
    t0 = (void*) _a4_closure;
    vader_defer_push(vader_ref_box(t0));
    vader_array_t* _a5_arr = vader_array_new(22u, 0u, 0u, 335u);
    l4 = (void*) _a5_arr;
    for (;;) {
        l1 = vader_host_system_windows$find_data_name(l2);
        if (l1 != 399u) {
            if (l1 != 400u) {
                vader_array_push_scalar((vader_array_t*) l4, vader_box_string(335u, l1));
            }
        }
        t3 = vader_host_system_windows$find_next_file(l3, l2);
        if (!(t3)) {
            vader_defer_pop_exec(1u);
            { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        continue;
    }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t std_io$read_file_bytes(vader_string_t l0, int64_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    void* l22 = NULL;
    uint32_t l3, l18;
    void* l4;
    int64_t l7, l10, l15, l16, l20, l21;
    bool l12;
    vader_box_t l14 = vader_box_null();
    int32_t t0;
    int64_t t1;
    void* t2 = NULL;
    bool t3;
    uint32_t t4;
    vader_box_t* gc_roots[1] = { &l14 };
    void** gc_raw_roots[11] = { &l2, &l5, &l6, &l8, &l9, &l11, &l13, &l17, &l19, &l22, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_io$to_wide(l0);
    t0 = (INT32_C(1) | INT32_C(2));
    l3 = (uint32_t) (int32_t) t0;
    l4 = vader_host_system_windows$create_file_w(l2, (uint32_t) (int32_t) INT32_MIN, l3, vader_box_obj(0u, NULL), (uint32_t) 3, (uint32_t) 128, vader_box_obj(0u, NULL));
    t1 = (int64_t) (void*) l4;
    if (t1 == INT64_C(-1)) {
        t2 = std_io$last_io_error(1996u);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct___defer_env_std_io_3_t* _a0_obj = (vader_struct___defer_env_std_io_3_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_io_3_t));
    vader_obj_header_init(_a0_obj, 358u);
    _a0_obj->f_cap_0 = l4;
    t2 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 285u);
    _a1_closure->code = (void*) &vader_fn_lift___defer_std_io_2;
    _a1_closure->env = t2;
    t2 = (void*) _a1_closure;
    vader_defer_push(vader_ref_box(t2));
    vader_array_t* _a2_arr = vader_array_new(25u, 0u, 1u, 340u);
    l2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(25u, 1u, 1u, 340u);
    ((uint8_t*) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t2 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) t2, (int64_t) INT64_C(65536));
    l5 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(27u, 1u, 3u, 342u);
    ((int32_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (int32_t) INT32_C(0);
    l6 = (void*) _a5_arr;
    for (;;) {
        t1 = ((vader_array_t*) l5)->length;
        t0 = ((int32_t) (int64_t) t1);
        l3 = (uint32_t) (int32_t) t0;
        t3 = vader_host_system_windows$read_file(l4, l5, l3, l6, vader_box_obj(0u, NULL));
        if (t3) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, INT32_C(0))
            t0 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) INT32_C(0)];
            l7 = ((int64_t) (uint32_t) t0);
            if ((l7 > INT64_C(0))) {
                vader_array_t* _a7_arr = vader_array_slice((vader_array_t*) l5, (int64_t) INT64_C(0), (int64_t) l7);
                l8 = (void*) _a7_arr;
                vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l8);
            }
            t1 = ((vader_array_t*) l2)->length;
            if ((t1 > l1)) {
                vader_struct_std_io$IOError_t* _a8_obj = (vader_struct_std_io$IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io$IOError_t));
                vader_obj_header_init(_a8_obj, 624u);
                _a8_obj->f_msg = 1997u;
                _a8_obj->f_kind = (uint8_t) 0;
                _a8_obj->f_code = INT32_C(0);
                l9 = (void*) _a8_obj;
                vader_defer_pop_exec(1u);
                { vader_box_t __vret = vader_ref_box(l9); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l10 = ((vader_array_t*) l5)->length;
            if ((l7 < l10)) {
                vader_defer_pop_exec(1u);
                { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t1 = ((vader_array_t*) l2)->length;
            if (!(t1 == INT64_C(65536))) {
                continue;
            }
            vader_array_t* _a9_arr = vader_array_new(24u, 1u, 8u, 339u);
            ((int64_t*) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = (int64_t) INT64_C(-1);
            l11 = (void*) _a9_arr;
            t4 = vader_host_system_windows$get_file_type(l4);
            if (t4 != INT32_C(1)) {
                l12 = true;
            } else {
                t3 = vader_host_system_windows$get_file_size_ex(l4, l11);
                l12 = !(t3);
            }
            if (l12) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l11);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a10_slotarr, INT32_C(0))
                ((int64_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) INT32_C(0)] = (int64_t) INT64_C(-1);
            }
            vader_array_t* _a11_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, INT32_C(0))
            t1 = ((int64_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) INT32_C(0)];
            l14 = std_io$whole_buffer(t1, l1);
            if (l14.tag == 0u) {
                continue;
            }
            l13 = l14.payload.obj;
            vader_array_copy((vader_array_t*) l5, (int64_t) INT64_C(0), (vader_array_t*) l13, (int64_t) INT64_C(0), (int64_t) INT64_C(65536));
            t1 = ((vader_array_t*) l13)->length;
            l15 = vader_chk_sub(i64, t1, INT64_C(65536));
            l16 = ((vader_array_t*) l13)->length;
            vader_array_t* _a12_arr = vader_array_slice((vader_array_t*) l13, (int64_t) INT64_C(65536), (int64_t) l16);
            l17 = (void*) _a12_arr;
            t0 = ((int32_t) (int64_t) l15);
            l18 = (uint32_t) (int32_t) t0;
            t3 = vader_host_system_windows$read_file(l4, l17, l18, l6, vader_box_obj(0u, NULL));
            if (!(t3)) {
                l19 = std_io$last_io_error(2491u);
                vader_defer_pop_exec(1u);
                { vader_box_t __vret = vader_ref_box(l19); vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_array_t* _a13_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, INT32_C(0))
            t0 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) INT32_C(0)];
            if ((((int64_t) (uint32_t) t0) < l15)) {
                vader_array_t* _a14_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, INT32_C(0))
                t0 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) INT32_C(0)];
                l20 = ((int64_t) (uint32_t) t0);
                l21 = vader_chk_add(i64, INT64_C(65536), l20);
                vader_array_t* _a15_arr = vader_array_slice((vader_array_t*) l13, (int64_t) INT64_C(0), (int64_t) l21);
                l22 = (void*) _a15_arr;
                vader_defer_pop_exec(1u);
                { vader_box_t __vret = vader_ref_box(l22); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l2 = l13;
            continue;
        }
        break;
    }
    l2 = std_io$last_io_error(2491u);
    vader_defer_pop_exec(1u);
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t std_io$read_file_string(vader_string_t l0, int64_t l1) {
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_io$read_file_bytes(l0, l1);
    if (!(l2.tag == 624u)) {
        t0 = l2.payload.obj;
        t1 = vader_host_std_core$bytes_to_string(t0);
        { vader_box_t __vret = vader_box_string(335u, t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t std_io$set_current_working_directory(vader_string_t l0) {
    void* t0 = NULL;
    int32_t t1;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_io$to_wide(l0);
    t1 = vader_host_system_windows$set_current_directory(t0);
    if (!(t1 == INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = std_io$last_io_error(1719u);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* std_io$std_handle(uint8_t l0) {
    void* t0;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        t0 = vader_host_system_windows$get_std_handle((uint32_t) -11);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0 == INT32_C(1))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = vader_host_system_windows$get_std_handle((uint32_t) -12);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_io$stderr_is_console(void) {
    int32_t t0;
    bool t1;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_0;
    if (t0 == INT32_C(2)) {
        t1 = vader_global_1;
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_global_0;
    if (!(t0 == INT32_C(1))) {
        vader_global_0 = INT32_C(1);
        t1 = std_io$stderr_is_console$singleton();
        vader_global_1 = t1;
        vader_global_0 = INT32_C(2);
        t1 = vader_global_1;
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("singleton `stderr_is_console` called while it initialises");
    vader_gc_top = gc_frame.prev;
}

static bool std_io$stderr_is_console$singleton(void) {
    void* t0;
    bool t1;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_io$std_handle((uint8_t) 1);
    t1 = std_io$has_console_mode(t0);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_io$stdout_is_console(void) {
    int32_t t0;
    bool t1;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_2;
    if (t0 == INT32_C(2)) {
        t1 = vader_global_3;
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_global_2;
    if (!(t0 == INT32_C(1))) {
        vader_global_2 = INT32_C(1);
        t1 = std_io$stdout_is_console$singleton();
        vader_global_3 = t1;
        vader_global_2 = INT32_C(2);
        t1 = vader_global_3;
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("singleton `stdout_is_console` called while it initialises");
    vader_gc_top = gc_frame.prev;
}

static bool std_io$stdout_is_console$singleton(void) {
    void* t0;
    bool t1;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_io$std_handle((uint8_t) 0);
    t1 = std_io$has_console_mode(t0);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_io$to_slash(vader_string_t l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    uint8_t l4;
    uint8_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(25u, 1u, 1u, 340u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l1 = (void*) _a0_arr;
    l2 = vader_host_std_core$byte_len(l0);
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = vader_host_std_core$byte_len(l0);
    while ((l2 < l3)) {
        t0 = vader_host_std_core$byte_at(l0, l2);
        if (t0 == INT32_C(92)) {
            l4 = (uint8_t) 47;
        } else {
            l4 = vader_host_std_core$byte_at(l0, l2);
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l2] = (uint8_t) (int32_t) (uint8_t) l4;
        l2 = (l2 + INT64_C(1));
    }
    t1 = vader_host_std_core$bytes_to_string(l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* std_io$to_wide(vader_string_t l0) {
    void* l1 = NULL;
    int32_t l2;
    int64_t l3;
    void* t0 = NULL;
    int32_t t1;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 2u, 341u);
    l1 = (void*) _a0_arr;
    l2 = vader_host_system_windows$multi_byte_to_wide_char((uint32_t) 65001, (uint32_t) 0, l0, INT32_C(-1), l1, INT32_C(0));
    if ((l2 <= INT32_C(0))) {
        vader_array_t* _a1_arr = vader_array_new(26u, 0u, 2u, 341u);
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(26u, 1u, 2u, 341u);
    ((uint16_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint16_t) INT32_C(0);
    l1 = (void*) _a2_arr;
    l3 = ((int64_t) (int32_t) l2);
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l3);
    l1 = (void*) _a3_arr;
    t1 = vader_host_system_windows$multi_byte_to_wide_char((uint32_t) 65001, (uint32_t) 0, l0, INT32_C(-1), l1, l2);
    if (!((t1 <= INT32_C(0)))) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a4_arr = vader_array_new(26u, 0u, 2u, 341u);
    t0 = (void*) _a4_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_io$whole_buffer(int64_t l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l0 <= INT64_C(65536))) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if ((l0 > l1)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!((l0 >= INT64_C(4294967295)))) {
        vader_array_t* _a0_arr = vader_array_new(25u, 1u, 1u, 340u);
        ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
        l2 = (void*) _a0_arr;
        l3 = vader_chk_add(i64, l0, INT64_C(1));
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
        t0 = (void*) _a1_arr;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void* std_io$wide_to_utf8(void* l0, int32_t l1) {
    void* l2 = NULL;
    int32_t l3;
    int64_t l4;
    void* t0 = NULL;
    int32_t t1;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(25u, 0u, 1u, 340u);
    l2 = (void*) _a0_arr;
    l3 = vader_host_system_windows$wide_char_to_multi_byte((uint32_t) 65001, (uint32_t) 0, l0, l1, l2, INT32_C(0), vader_box_obj(0u, NULL), vader_box_obj(0u, NULL));
    if ((l3 <= INT32_C(0))) {
        vader_array_t* _a1_arr = vader_array_new(25u, 0u, 1u, 340u);
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(25u, 1u, 1u, 340u);
    ((uint8_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (uint8_t) INT32_C(0);
    l2 = (void*) _a2_arr;
    l4 = ((int64_t) (int32_t) l3);
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l4);
    l2 = (void*) _a3_arr;
    t1 = vader_host_system_windows$wide_char_to_multi_byte((uint32_t) 65001, (uint32_t) 0, l0, l1, l2, l3, vader_box_obj(0u, NULL), vader_box_obj(0u, NULL));
    if (!((t1 <= INT32_C(0)))) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a4_arr = vader_array_new(25u, 0u, 1u, 340u);
    t0 = (void*) _a4_arr;
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

static vader_string_t std_io$without_trailing_sep(vader_string_t l0) {
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

static void std_io$write(uint8_t l0, vader_string_t l1) {
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
    t0 = std_io$write_text(l0, l1);
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
            l8 = std_io$write_bytes(l0, l6, l7);
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

static int32_t std_io$write_bytes(uint8_t l0, void* l1, int64_t l2) {
    void* l3 = NULL;
    void* l4;
    uint32_t l5;
    int32_t t0;
    bool t1;
    void** gc_raw_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(27u, 1u, 3u, 342u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(0);
    l3 = (void*) _a0_arr;
    l4 = std_io$std_handle(l0);
    t0 = ((int32_t) (int64_t) l2);
    l5 = (uint32_t) (int32_t) t0;
    t1 = vader_host_system_windows$write_file(l4, l1, l5, l3, vader_box_obj(0u, NULL));
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(-1); }
    }
    { int32_t __vret = ((int32_t) (int64_t) l2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_io$write_file_bytes(vader_string_t l0, void* l1) {
    int64_t l2, l3;
    void* l4;
    void* l5 = NULL;
    uint32_t l6;
    uint8_t t0;
    void* t1 = NULL;
    int64_t t2;
    int32_t t3;
    bool t4;
    void** gc_raw_roots[3] = { &l1, &l5, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = INT64_C(0);
    l3 = vader_host_std_core$byte_len(l0);
    while ((l2 < l3)) {
        t0 = vader_host_std_core$byte_at(l0, l2);
        if (t0 == INT32_C(0)) {
            vader_struct_std_io$IOError_t* _a0_obj = (vader_struct_std_io$IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io$IOError_t));
            vader_obj_header_init(_a0_obj, 624u);
            _a0_obj->f_msg = 2456u;
            _a0_obj->f_kind = (uint8_t) 0;
            _a0_obj->f_code = INT32_C(0);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = (l2 + INT64_C(1));
    }
    t1 = std_io$to_wide(l0);
    l4 = vader_host_system_windows$create_file_w(t1, (uint32_t) 1073741824, (uint32_t) 1, vader_box_obj(0u, NULL), (uint32_t) 2, (uint32_t) 128, vader_box_obj(0u, NULL));
    t2 = (int64_t) (void*) l4;
    if (t2 == INT64_C(-1)) {
        t1 = std_io$last_io_error(2422u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((vader_array_t*) l1)->length;
    if ((t2 > INT64_C(0))) {
        vader_array_t* _a1_arr = vader_array_new(27u, 1u, 3u, 342u);
        ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) INT32_C(0);
        l5 = (void*) _a1_arr;
        t2 = ((vader_array_t*) l1)->length;
        t3 = ((int32_t) (int64_t) t2);
        l6 = (uint32_t) (int32_t) t3;
        t4 = vader_host_system_windows$write_file(l4, l1, l6, l5, vader_box_obj(0u, NULL));
        if (!(t4)) {
            l5 = std_io$last_io_error(2552u);
            vader_host_system_windows$close_handle(l4);
            { vader_box_t __vret = vader_ref_box(l5); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t4 = vader_host_system_windows$close_handle(l4);
    if (!(t4)) {
        t1 = std_io$last_io_error(1755u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

vader_box_t std_io$write_file_string(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core$bytes(l1);
    t0 = std_io$write_file_bytes(l0, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_io$write_text(uint8_t l0, vader_string_t l1) {
    int64_t l2;
    void* l3 = NULL;
    void* l6 = NULL;
    int32_t l4, l5;
    void* l7;
    uint32_t l8;
    bool t0;
    void* t1 = NULL;
    int32_t t2;
    void** gc_raw_roots[3] = { &l3, &l6, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_host_std_core$is_ascii(l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = std_io$is_console(l0);
    if (t0) {
        l2 = vader_host_std_core$byte_len(l1);
        vader_array_t* _a0_arr = vader_array_new(26u, 1u, 2u, 341u);
        ((uint16_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint16_t) INT32_C(0);
        t1 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l2);
        l3 = (void*) _a1_arr;
        l4 = ((int32_t) (int64_t) l2);
        l5 = ((int32_t) (int64_t) l2);
        l4 = vader_host_system_windows$multi_byte_to_wide_char((uint32_t) 65001, (uint32_t) 0, l1, l4, l3, l5);
        if ((l4 > INT32_C(0))) {
            vader_array_t* _a2_arr = vader_array_new(27u, 1u, 3u, 342u);
            ((int32_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (int32_t) INT32_C(0);
            l6 = (void*) _a2_arr;
            l7 = std_io$std_handle(l0);
            t2 = l4;
            l8 = (uint32_t) (int32_t) t2;
            vader_host_system_windows$write_console_w(l7, l3, l8, l6, vader_box_obj(0u, NULL));
            { vader_gc_top = gc_frame.prev; return true; }
        }
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}
