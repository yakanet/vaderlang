#include "bootstrap.split.h"

static void* std_io$classified_error(vader_string_t l0, uint8_t l1, int32_t l2);
static vader_string_t std_io$describe_io_error_kind(uint8_t l0, vader_string_t l1);
static uint8_t std_io$errno_kind(int32_t l0);
static void* std_io$last_io_error(vader_string_t l0);
static vader_box_t std_io$read_file_bytes(vader_string_t l0, int64_t l1);
static vader_box_t std_io$real_path(vader_string_t l0);
static vader_string_t std_io$to_slash(vader_string_t l0);
static vader_string_t std_io$up_to_nul(void* l0);
static vader_box_t std_io$whole_buffer(int64_t l0, int64_t l1);
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
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    int32_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(25u, 1u, 1u, 340u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) INT64_C(4096));
    l0 = (void*) _a1_arr;
    t1 = vader_host_system_darwin$ns_get_executable_path(l0, (uint32_t) 4096);
    if (t1 != INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return 399u; }
    }
    t2 = std_io$up_to_nul(l0);
    l1 = std_io$real_path(t2);
    if (!(l1.tag == 624u)) {
        t2 = l1.payload.s;
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 399u; }
}

vader_string_t std_io$current_working_directory(void) {
    void* l0 = NULL;
    int64_t l1;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &t2, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(25u, 1u, 1u, 340u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) INT64_C(4096));
    l0 = (void*) _a1_arr;
    l1 = ((vader_array_t*) l0)->length;
    t1 = vader_host_system_posix$sys_getcwd(l0, l1);
    if (!(t1.tag == 0u)) {
        t2 = std_io$up_to_nul(l0);
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

bool std_io$exists(vader_string_t l0) {
    int32_t t0;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_host_system_posix$sys_access(l0, INT32_C(0));
    { bool __vret = t0 == INT32_C(0); vader_gc_top = gc_frame.prev; return __vret; }
}

bool std_io$is_dir(vader_string_t l0) {
    int32_t t0;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_host_system_posix$sys_path_kind(l0);
    { bool __vret = t0 == INT32_C(2); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* std_io$last_io_error(vader_string_t l0) {
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

vader_box_t std_io$read_dir(vader_string_t l0) {
    void* l1;
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    vader_string_t l4 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void* t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l3, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_host_system_posix$sys_opendir(l0);
    if (l2.tag == 0u) {
        t0 = concat_3(2492u, l0, 1035u);
        vader_struct_std_io$IOError_t* _a0_obj = (vader_struct_std_io$IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io$IOError_t));
        vader_obj_header_init(_a0_obj, 624u);
        _a0_obj->f_msg = t0;
        _a0_obj->f_kind = (uint8_t) 0;
        _a0_obj->f_code = INT32_C(0);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((void*) (intptr_t) l2.payload.i);
    vader_struct___defer_env_std_io_1_t* _a1_obj = (vader_struct___defer_env_std_io_1_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_io_1_t));
    vader_obj_header_init(_a1_obj, 357u);
    _a1_obj->f_cap_0 = l1;
    t1 = (void*) _a1_obj;
    vader_fn_t* _a2_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a2_closure, 285u);
    _a2_closure->code = (void*) &vader_fn_lift___defer_std_io_0;
    _a2_closure->env = t1;
    t1 = (void*) _a2_closure;
    vader_defer_push(vader_ref_box(t1));
    vader_array_t* _a3_arr = vader_array_new(22u, 0u, 0u, 335u);
    l3 = (void*) _a3_arr;
    for (;;) {
        l2 = vader_host_system_posix$sys_readdir(l1);
        if (!(l2.tag == 0u)) {
            t2 = ((void*) (intptr_t) l2.payload.i);
            l4 = vader_host_system_posix$dirent_name(t2);
            if (!(l4 != 399u)) {
                continue;
            }
            if (!(l4 != 400u)) {
                continue;
            }
            vader_array_push_scalar((vader_array_t*) l3, vader_box_string(335u, l4));
            continue;
        }
        break;
    }
    vader_defer_pop_exec(1u);
    { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_io$read_file_bytes(vader_string_t l0, int64_t l1) {
    void* l2;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    void* l18 = NULL;
    int64_t l6, l7, l10, l13, l14, l15, l17;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[9] = { &l4, &l5, &l8, &l9, &l11, &l12, &l16, &l18, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_host_system_posix$sys_fopen(l0, 2486u);
    if (l3.tag == 0u) {
        t0 = std_io$last_io_error(1728u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((void*) (intptr_t) l3.payload.i);
    vader_struct___defer_env_std_io_3_t* _a0_obj = (vader_struct___defer_env_std_io_3_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_io_3_t));
    vader_obj_header_init(_a0_obj, 358u);
    _a0_obj->f_cap_0 = l2;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 285u);
    _a1_closure->code = (void*) &vader_fn_lift___defer_std_io_2;
    _a1_closure->env = t0;
    t0 = (void*) _a1_closure;
    vader_defer_push(vader_ref_box(t0));
    vader_array_t* _a2_arr = vader_array_new(25u, 0u, 1u, 340u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(25u, 1u, 1u, 340u);
    ((uint8_t*) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) INT64_C(65536));
    l5 = (void*) _a4_arr;
    for (;;) {
        l6 = ((vader_array_t*) l5)->length;
        l7 = vader_host_system_posix$sys_fread(l5, INT64_C(1), l6, l2);
        if ((l7 > INT64_C(0))) {
            vader_array_t* _a5_arr = vader_array_slice((vader_array_t*) l5, (int64_t) INT64_C(0), (int64_t) l7);
            l8 = (void*) _a5_arr;
            vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l8);
        }
        t1 = ((vader_array_t*) l4)->length;
        if ((t1 > l1)) {
            vader_struct_std_io$IOError_t* _a6_obj = (vader_struct_std_io$IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io$IOError_t));
            vader_obj_header_init(_a6_obj, 624u);
            _a6_obj->f_msg = 1997u;
            _a6_obj->f_kind = (uint8_t) 0;
            _a6_obj->f_code = INT32_C(0);
            l9 = (void*) _a6_obj;
            vader_defer_pop_exec(1u);
            { vader_box_t __vret = vader_ref_box(l9); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l10 = ((vader_array_t*) l5)->length;
        if ((l7 < l10)) {
            t2 = vader_host_system_posix$sys_ferror(l2);
            if (!(t2 != INT32_C(0))) {
                vader_defer_pop_exec(1u);
                { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l11 = std_io$last_io_error(2491u);
            vader_defer_pop_exec(1u);
            { vader_box_t __vret = vader_ref_box(l11); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = ((vader_array_t*) l4)->length;
        if (!(t1 == INT64_C(65536))) {
            continue;
        }
        t1 = vader_host_system_posix$sys_stream_size(l2);
        l3 = std_io$whole_buffer(t1, l1);
        if (l3.tag == 0u) {
            continue;
        }
        l12 = l3.payload.obj;
        vader_array_copy((vader_array_t*) l5, (int64_t) INT64_C(0), (vader_array_t*) l12, (int64_t) INT64_C(0), (int64_t) INT64_C(65536));
        t1 = ((vader_array_t*) l12)->length;
        l13 = vader_chk_sub(i64, t1, INT64_C(65536));
        l14 = ((vader_array_t*) l12)->length;
        vader_array_t* _a7_arr = vader_array_slice((vader_array_t*) l12, (int64_t) INT64_C(65536), (int64_t) l14);
        t0 = (void*) _a7_arr;
        l15 = vader_host_system_posix$sys_fread(t0, INT64_C(1), l13, l2);
        if ((l15 < l13)) {
            t2 = vader_host_system_posix$sys_ferror(l2);
            if (!(t2 != INT32_C(0))) {
                l17 = vader_chk_add(i64, INT64_C(65536), l15);
                vader_array_t* _a8_arr = vader_array_slice((vader_array_t*) l12, (int64_t) INT64_C(0), (int64_t) l17);
                l18 = (void*) _a8_arr;
                vader_defer_pop_exec(1u);
                { vader_box_t __vret = vader_ref_box(l18); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l16 = std_io$last_io_error(2491u);
            vader_defer_pop_exec(1u);
            { vader_box_t __vret = vader_ref_box(l16); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = l12;
        continue;
    }
    vader_gc_top = gc_frame.prev;
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

static vader_box_t std_io$real_path(vader_string_t l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(25u, 1u, 1u, 340u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) INT64_C(4096));
    l1 = (void*) _a1_arr;
    t1 = vader_host_system_posix$sys_realpath(l0, l1);
    if (!(t1.tag == 0u)) {
        t2 = std_io$up_to_nul(l1);
        { vader_box_t __vret = vader_box_string(335u, t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = std_io$last_io_error(1731u);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t std_io$set_current_working_directory(vader_string_t l0) {
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
    t1 = std_io$last_io_error(1719u);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
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

static vader_string_t std_io$up_to_nul(void* l0) {
    int64_t l1, l2, l3;
    vader_box_t t0 = vader_box_null();
    uint8_t t1;
    void* t2 = NULL;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) l0)->length;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l2, 340u);
        t1 = ((uint8_t) t0.payload.i);
        if (t1 == INT32_C(0)) {
            l1 = l2;
            break;
        }
        l2 = (l2 + INT64_C(1));
    }
    vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l0, (int64_t) INT64_C(0), (int64_t) l1);
    t2 = (void*) _a1_arr;
    t3 = vader_host_std_core$bytes_to_string(t2);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
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
    int64_t t0;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        t0 = vader_host_system_posix$sys_write(INT32_C(1), l1, l2);
        { int32_t __vret = ((int32_t) (int64_t) t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_host_system_posix$sys_write(INT32_C(2), l1, l2);
    { int32_t __vret = ((int32_t) (int64_t) t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_io$write_file_bytes(vader_string_t l0, void* l1) {
    int64_t l2, l3;
    void* l4;
    vader_box_t l5 = vader_box_null();
    void* l6 = NULL;
    uint8_t t0;
    void* t1 = NULL;
    int64_t t2;
    int32_t t3;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[3] = { &l1, &l6, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
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
    l5 = vader_host_system_posix$sys_fopen(l0, 3016u);
    if (l5.tag == 0u) {
        t1 = std_io$last_io_error(2422u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((void*) (intptr_t) l5.payload.i);
    t2 = ((vader_array_t*) l1)->length;
    if ((t2 > INT64_C(0))) {
        l2 = ((vader_array_t*) l1)->length;
        l2 = vader_host_system_posix$sys_fwrite(l1, INT64_C(1), l2, l4);
        l3 = ((vader_array_t*) l1)->length;
        if (l2 != l3) {
            l6 = std_io$last_io_error(2552u);
            vader_host_system_posix$sys_fclose(l4);
            { vader_box_t __vret = vader_ref_box(l6); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t3 = vader_host_system_posix$sys_fclose(l4);
    if (!(t3 != INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = std_io$last_io_error(1755u);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
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
    return false;
}
