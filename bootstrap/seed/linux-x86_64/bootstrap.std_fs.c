#include "bootstrap.split.h"

static vader_box_t std_fs$read_file_bytes(vader_string_t l0, int64_t l1);
static vader_box_t std_fs$whole_buffer(int64_t l0, int64_t l1);
static vader_box_t std_fs$write_file_bytes(vader_string_t l0, void* l1);

bool std_fs$exists(vader_string_t l0) {
    int32_t t0;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_host_system_posix$sys_access(l0, INT32_C(0));
    { bool __vret = t0 == INT32_C(0); vader_gc_top = gc_frame.prev; return __vret; }
}

bool std_fs$is_dir(vader_string_t l0) {
    int32_t t0;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_host_system_posix$sys_path_kind(l0);
    { bool __vret = t0 == INT32_C(2); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t std_fs$read_dir(vader_string_t l0) {
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
        t0 = concat_3(2647u, l0, 1098u);
        vader_struct_std_io$IOError_t* _a0_obj = (vader_struct_std_io$IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io$IOError_t));
        vader_obj_header_init(_a0_obj, 858u);
        _a0_obj->f_msg = t0;
        _a0_obj->f_kind = (uint8_t) 0;
        _a0_obj->f_code = INT32_C(0);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((void*) (intptr_t) l2.payload.i);
    vader_struct___defer_env_std_fs_1_t* _a1_obj = (vader_struct___defer_env_std_fs_1_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_fs_1_t));
    vader_obj_header_init(_a1_obj, 517u);
    _a1_obj->f_cap_0 = l1;
    t1 = (void*) _a1_obj;
    vader_fn_t* _a2_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a2_closure, 436u);
    _a2_closure->code = (void*) &vader_fn_lift___defer_std_fs_0;
    _a2_closure->env = t1;
    t1 = (void*) _a2_closure;
    vader_defer_push(vader_ref_box(t1));
    vader_array_t* _a3_arr = vader_array_new(26u, 0u, 0u, 494u);
    l3 = (void*) _a3_arr;
    for (;;) {
        l2 = vader_host_system_posix$sys_readdir(l1);
        if (!(l2.tag == 0u)) {
            t2 = ((void*) (intptr_t) l2.payload.i);
            l4 = vader_host_system_posix$dirent_name(t2);
            if (!(l4 != 433u)) {
                continue;
            }
            if (!(l4 != 434u)) {
                continue;
            }
            vader_array_push_scalar((vader_array_t*) l3, vader_box_string(494u, l4));
            continue;
        }
        break;
    }
    vader_defer_pop_exec(1u);
    { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_fs$read_file_bytes(vader_string_t l0, int64_t l1) {
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
    l3 = vader_host_system_libc$sys_fopen(l0, 2641u);
    if (l3.tag == 0u) {
        t0 = std_io$last_io_error(1843u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((void*) (intptr_t) l3.payload.i);
    vader_struct___defer_env_std_fs_3_t* _a0_obj = (vader_struct___defer_env_std_fs_3_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_fs_3_t));
    vader_obj_header_init(_a0_obj, 518u);
    _a0_obj->f_cap_0 = l2;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 436u);
    _a1_closure->code = (void*) &vader_fn_lift___defer_std_fs_2;
    _a1_closure->env = t0;
    t0 = (void*) _a1_closure;
    vader_defer_push(vader_ref_box(t0));
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 1u, 499u);
    l4 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(29u, 1u, 1u, 499u);
    ((uint8_t*) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) INT64_C(65536));
    l5 = (void*) _a4_arr;
    for (;;) {
        l6 = ((vader_array_t*) l5)->length;
        l7 = vader_host_system_libc$sys_fread(l5, INT64_C(1), l6, l2);
        if ((l7 > INT64_C(0))) {
            vader_array_t* _a5_arr = vader_array_slice((vader_array_t*) l5, (int64_t) INT64_C(0), (int64_t) l7);
            l8 = (void*) _a5_arr;
            vader_array_push_all((vader_array_t*) l4, (vader_array_t*) l8);
        }
        t1 = ((vader_array_t*) l4)->length;
        if ((t1 > l1)) {
            vader_struct_std_io$IOError_t* _a6_obj = (vader_struct_std_io$IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io$IOError_t));
            vader_obj_header_init(_a6_obj, 858u);
            _a6_obj->f_msg = 2125u;
            _a6_obj->f_kind = (uint8_t) 0;
            _a6_obj->f_code = INT32_C(0);
            l9 = (void*) _a6_obj;
            vader_defer_pop_exec(1u);
            { vader_box_t __vret = vader_ref_box(l9); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l10 = ((vader_array_t*) l5)->length;
        if ((l7 < l10)) {
            t2 = vader_host_system_libc$sys_ferror(l2);
            if (!(t2 != INT32_C(0))) {
                vader_defer_pop_exec(1u);
                { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l11 = std_io$last_io_error(2646u);
            vader_defer_pop_exec(1u);
            { vader_box_t __vret = vader_ref_box(l11); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = ((vader_array_t*) l4)->length;
        if (!(t1 == INT64_C(65536))) {
            continue;
        }
        t1 = vader_host_system_posix$sys_stream_size(l2);
        l3 = std_fs$whole_buffer(t1, l1);
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
        l15 = vader_host_system_libc$sys_fread(t0, INT64_C(1), l13, l2);
        if ((l15 < l13)) {
            t2 = vader_host_system_libc$sys_ferror(l2);
            if (!(t2 != INT32_C(0))) {
                l17 = vader_chk_add(i64, INT64_C(65536), l15);
                vader_array_t* _a8_arr = vader_array_slice((vader_array_t*) l12, (int64_t) INT64_C(0), (int64_t) l17);
                l18 = (void*) _a8_arr;
                vader_defer_pop_exec(1u);
                { vader_box_t __vret = vader_ref_box(l18); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l16 = std_io$last_io_error(2646u);
            vader_defer_pop_exec(1u);
            { vader_box_t __vret = vader_ref_box(l16); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = l12;
        continue;
    }
    vader_gc_top = gc_frame.prev;
}

vader_box_t std_fs$read_file_string(vader_string_t l0, int64_t l1) {
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
    l2 = std_fs$read_file_bytes(l0, l1);
    if (!(l2.tag == 858u)) {
        t0 = l2.payload.obj;
        t1 = vader_host_std_core$bytes_to_string(t0);
        { vader_box_t __vret = vader_box_string(494u, t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_fs$whole_buffer(int64_t l0, int64_t l1) {
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
        vader_array_t* _a0_arr = vader_array_new(29u, 1u, 1u, 499u);
        ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) INT32_C(0);
        l2 = (void*) _a0_arr;
        l3 = vader_chk_add(i64, l0, INT64_C(1));
        vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
        t0 = (void*) _a1_arr;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t std_fs$write_file_bytes(vader_string_t l0, void* l1) {
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
            vader_obj_header_init(_a0_obj, 858u);
            _a0_obj->f_msg = 2609u;
            _a0_obj->f_kind = (uint8_t) 0;
            _a0_obj->f_code = INT32_C(0);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = (l2 + INT64_C(1));
    }
    l5 = vader_host_system_libc$sys_fopen(l0, 3244u);
    if (l5.tag == 0u) {
        t1 = std_io$last_io_error(2576u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((void*) (intptr_t) l5.payload.i);
    t2 = ((vader_array_t*) l1)->length;
    if ((t2 > INT64_C(0))) {
        l2 = ((vader_array_t*) l1)->length;
        l2 = vader_host_system_libc$sys_fwrite(l1, INT64_C(1), l2, l4);
        l3 = ((vader_array_t*) l1)->length;
        if (l2 != l3) {
            l6 = std_io$last_io_error(2708u);
            vader_host_system_libc$sys_fclose(l4);
            { vader_box_t __vret = vader_ref_box(l6); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t3 = vader_host_system_libc$sys_fclose(l4);
    if (!(t3 != INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = std_io$last_io_error(1873u);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t std_fs$write_file_string(vader_string_t l0, vader_string_t l1) {
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
    t0 = std_fs$write_file_bytes(l0, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
