#include "bootstrap.split.h"

static vader_box_t std_fs$File$std_io$Writer$write(void* l0, vader_box_t l1);
static int32_t std_fs$access_mode(void* l0);
static vader_box_t std_fs$create(vader_string_t l0);
static int32_t std_fs$fd_of(vader_box_t l0);
static bool std_fs$has_nul(vader_string_t l0);
static void* std_fs$invalid_options(vader_string_t l0);
static void* std_fs$is_a_directory(int32_t l0);
static uint8_t std_fs$kind_of(int64_t l0);
static uint8_t std_fs$kind_of_dirent(vader_string_t l0, vader_string_t l1, int32_t l2);
static int32_t std_fs$link_flag(bool l0);
static vader_box_t std_fs$list_dir(vader_string_t l0);
static vader_box_t std_fs$open(vader_string_t l0, void* l1);
static int32_t std_fs$open_flags(void* l0);
static vader_box_t std_fs$read_file_bytes(vader_string_t l0, int64_t l1);
static vader_box_t std_fs$read_into(vader_box_t l0, void* l1);
static bool std_fs$reads_whole(int64_t l0, int64_t l1);
static vader_box_t std_fs$refusal_of(vader_string_t l0, void* l1);
static vader_box_t std_fs$stat_cells(vader_string_t l0, bool l1);
static vader_box_t std_fs$system_close(vader_box_t l0);
static vader_box_t std_fs$system_open(vader_string_t l0, void* l1);
static vader_box_t std_fs$system_read(vader_box_t l0, void* l1, int64_t l2);
static int64_t std_fs$system_size(vader_box_t l0);
static vader_box_t std_fs$system_write(vader_box_t l0, void* l1);

static vader_box_t std_fs$File$std_io$Writer$write(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l7 = NULL;
    int64_t l3, l4, l6, l9;
    vader_box_t l5 = vader_box_null(), l8 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[3] = { &l1, &l5, &l8 };
    void** gc_raw_roots[4] = { &l0, &l2, &l7, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_std_fs$File_t*) l0)->f_closed;
    if (t0) {
        t1 = (void*) &vader_data_43;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = std_io$bytes_of(l1);
    l3 = INT64_C(0);
    for (;;) {
        l4 = ((vader_array_t*) l2)->length;
        if ((l3 < l4)) {
            l5 = ((vader_struct_std_fs$File_t*) l0)->f_handle;
            l6 = ((vader_array_t*) l2)->length;
            vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l2, (int64_t) l3, (int64_t) l6);
            l7 = (void*) _a1_arr;
            l8 = std_fs$system_write(l5, l7);
            if (l8.tag == 873u) {
                t1 = l8.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = ((int64_t) l8.payload.i);
            if (t2 == INT64_C(0)) {
                vader_struct_std_io$IOError_t* _a2_obj = (vader_struct_std_io$IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io$IOError_t));
                vader_obj_header_init(_a2_obj, 873u);
                _a2_obj->f_msg = 3281u;
                _a2_obj->f_kind = (uint8_t) 0;
                _a2_obj->f_code = INT32_C(0);
                t1 = (void*) _a2_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l9 = ((int64_t) l8.payload.i);
            l3 = vader_chk_add(i64, l3, l9);
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static int32_t std_fs$access_mode(void* l0) {
    bool l1;
    bool t0;
    t0 = ((vader_struct_std_fs$OpenOptions_t*) l0)->f_write;
    if (t0) {
        l1 = true;
    } else {
        l1 = ((vader_struct_std_fs$OpenOptions_t*) l0)->f_append;
    }
    t0 = ((vader_struct_std_fs$OpenOptions_t*) l0)->f_read;
    if (t0) {
        if (l1) {
            return INT32_C(2);
        }
    }
    if (!(l1)) {
        return INT32_C(0);
    }
    return INT32_C(1);
}

vader_box_t std_fs$close(void* l0) {
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_std_fs$File_t*) l0)->f_closed;
    if (!(t0)) {
        ((vader_struct_std_fs$File_t*) l0)->f_closed = true;
        t1 = std_fs$system_close(((vader_struct_std_fs$File_t*) l0)->f_handle);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t std_fs$create(vader_string_t l0) {
    void* l1 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_std_fs$OpenOptions_t* _a0_obj = (vader_struct_std_fs$OpenOptions_t*) vader_gc_alloc(sizeof(vader_struct_std_fs$OpenOptions_t));
    vader_obj_header_init(_a0_obj, 872u);
    _a0_obj->f_read = false;
    _a0_obj->f_write = true;
    _a0_obj->f_append = false;
    _a0_obj->f_create = true;
    _a0_obj->f_truncate = true;
    _a0_obj->f_create_new = false;
    l1 = (void*) _a0_obj;
    t0 = std_fs$open(l0, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool std_fs$exists(vader_string_t l0) {
    int32_t t0;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_host_system_posix$sys_access(l0, INT32_C(0));
    { bool __vret = t0 == INT32_C(0); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t std_fs$fd_of(vader_box_t l0) {
    int32_t t0;
    if (!(l0.tag == 502u)) {
        vader_unreachable("@unreachable match: a variant the arms assert cannot occur was reached");
    }
    t0 = ((int32_t) l0.payload.i);
    return t0;
}

static bool std_fs$has_nul(vader_string_t l0) {
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_host_std_core$bytes(l0);
    t1 = std_core$index_of__u8(t0, (uint8_t) 0);
    { bool __vret = !(t1.tag == 0u); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* std_fs$invalid_options(vader_string_t l0) {
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = concat_2(2350u, l0);
    vader_struct_std_io$IOError_t* _a0_obj = (vader_struct_std_io$IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io$IOError_t));
    vader_obj_header_init(_a0_obj, 873u);
    _a0_obj->f_msg = t0;
    _a0_obj->f_kind = (uint8_t) 10;
    _a0_obj->f_code = INT32_C(0);
    t1 = (void*) _a0_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* std_fs$is_a_directory(int32_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_std_io$IOError_t* _a0_obj = (vader_struct_std_io$IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io$IOError_t));
    vader_obj_header_init(_a0_obj, 873u);
    _a0_obj->f_msg = 2352u;
    _a0_obj->f_kind = (uint8_t) 6;
    _a0_obj->f_code = l0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool std_fs$is_dir(vader_string_t l0) {
    int32_t t0;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_host_system_posix$sys_path_kind(l0);
    { bool __vret = t0 == INT32_C(2); vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t std_fs$kind_of(int64_t l0) {
    int32_t l1;
    l1 = ((int32_t) (int64_t) l0);
    if (l1 == INT32_C(1)) {
        return (uint8_t) 0;
    }
    if (l1 == INT32_C(2)) {
        return (uint8_t) 1;
    }
    if (!(l1 == INT32_C(4))) {
        return (uint8_t) 3;
    }
    return (uint8_t) 2;
}

static uint8_t std_fs$kind_of_dirent(vader_string_t l0, vader_string_t l1, int32_t l2) {
    vader_box_t l3 = vader_box_null();
    uint8_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[1] = { &t2 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2 != INT32_C(0)) {
        t0 = std_fs$kind_of(((int64_t) (int32_t) l2));
        { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = concat_3(l0, 484u, l1);
    l3 = std_fs$stat_cells(t1, false);
    if (!(l3.tag == 873u)) {
        t2 = l3.payload.obj;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t3 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
        t0 = std_fs$kind_of(t3);
        { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 3; }
}

static int32_t std_fs$link_flag(bool l0) {
    if (!(l0)) {
        return INT32_C(0);
    }
    return INT32_C(1);
}

static vader_box_t std_fs$list_dir(vader_string_t l0) {
    void* l1;
    void* l4;
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l8 = NULL;
    vader_string_t l5 = 0;
    int32_t l6;
    uint8_t l7;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l3, &l8, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_host_system_posix$sys_opendir(l0);
    if (l2.tag == 0u) {
        t0 = std_io$last_io_error(1853u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((void*) (intptr_t) l2.payload.i);
    vader_struct___defer_env_std_fs_1_t* _a0_obj = (vader_struct___defer_env_std_fs_1_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_fs_1_t));
    vader_obj_header_init(_a0_obj, 522u);
    _a0_obj->f_cap_0 = l1;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 440u);
    _a1_closure->code = (void*) &vader_fn_lift___defer_std_fs_0;
    _a1_closure->env = t0;
    t0 = (void*) _a1_closure;
    vader_defer_push(vader_ref_box(t0));
    vader_array_t* _a2_arr = vader_array_new(46u, 0u, 13u, 871u);
    l3 = (void*) _a2_arr;
    for (;;) {
        l2 = vader_host_system_posix$sys_readdir(l1);
        if (!(l2.tag == 0u)) {
            l4 = ((void*) (intptr_t) l2.payload.i);
            l5 = vader_host_system_posix$dirent_name(l4);
            if (!(l5 != 433u)) {
                continue;
            }
            if (!(l5 != 434u)) {
                continue;
            }
            l6 = vader_host_system_posix$dirent_kind(l4);
            l7 = std_fs$kind_of_dirent(l0, l5, l6);
            vader_struct_std_fs$ListedEntry_t* _a3_obj = (vader_struct_std_fs$ListedEntry_t*) vader_gc_alloc(sizeof(vader_struct_std_fs$ListedEntry_t));
            vader_obj_header_init(_a3_obj, 871u);
            _a3_obj->f_name = l5;
            _a3_obj->f_kind = l7;
            l8 = (void*) _a3_obj;
            vader_array_push_ref((vader_array_t*) l3, l8);
            continue;
        }
        break;
    }
    vader_defer_pop_exec(1u);
    { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_fs$open(vader_string_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_fs$refusal_of(l0, l1);
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = std_fs$system_open(l0, l1);
    if (!(l2.tag == 873u)) {
        vader_struct_std_fs$File_t* _a0_obj = (vader_struct_std_fs$File_t*) vader_gc_alloc(sizeof(vader_struct_std_fs$File_t));
        vader_obj_header_init(_a0_obj, 870u);
        _a0_obj->f_handle = l2;
        _a0_obj->f_closed = false;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t std_fs$open_flags(void* l0) {
    int32_t l1, l2, l3;
    bool t0;
    if (INT32_C(1) == INT32_C(2)) {
        l1 = INT32_C(16777216);
    } else {
        l1 = INT32_C(524288);
    }
    l2 = std_fs$access_mode(l0);
    l1 = (l1 | l2);
    t0 = ((vader_struct_std_fs$OpenOptions_t*) l0)->f_append;
    if (t0) {
        if (INT32_C(1) == INT32_C(2)) {
            l2 = INT32_C(8);
        } else {
            l2 = INT32_C(1024);
        }
        l1 = (l1 | l2);
    }
    t0 = ((vader_struct_std_fs$OpenOptions_t*) l0)->f_create;
    if (t0) {
        if (INT32_C(1) == INT32_C(2)) {
            l2 = INT32_C(512);
        } else {
            l2 = INT32_C(64);
        }
        l1 = (l1 | l2);
    }
    t0 = ((vader_struct_std_fs$OpenOptions_t*) l0)->f_truncate;
    if (t0) {
        if (INT32_C(1) == INT32_C(2)) {
            l2 = INT32_C(1024);
        } else {
            l2 = INT32_C(512);
        }
        l1 = (l1 | l2);
    }
    t0 = ((vader_struct_std_fs$OpenOptions_t*) l0)->f_create_new;
    if (t0) {
        if (INT32_C(1) == INT32_C(2)) {
            l2 = INT32_C(512);
        } else {
            l2 = INT32_C(64);
        }
        l2 = (l1 | l2);
        if (INT32_C(1) == INT32_C(2)) {
            l3 = INT32_C(2048);
        } else {
            l3 = INT32_C(128);
        }
        l1 = (l2 | l3);
        return l1;
    }
    return l1;
}

vader_box_t std_fs$read_dir(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l2, &l3, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_fs$has_nul(l0);
    if (t0) {
        t1 = (void*) &vader_data_42;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = std_fs$list_dir(l0);
    if (l1.tag == 873u) {
        t1 = l1.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(26u, 0u, 0u, 499u);
    l2 = (void*) _a1_arr;
    l3 = l1.payload.obj;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_std_fs$ListedEntry_t*) t1)->f_name;
        vader_array_push_scalar((vader_array_t*) l2, vader_box_string(499u, l6));
        l5 = (l5 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_fs$read_file_bytes(vader_string_t l0, int64_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null();
    int64_t l4, l6;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l3, &l7 };
    void** gc_raw_roots[5] = { &l2, &l5, &l8, &l9, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_std_fs$OpenOptions_t* _a0_obj = (vader_struct_std_fs$OpenOptions_t*) vader_gc_alloc(sizeof(vader_struct_std_fs$OpenOptions_t));
    vader_obj_header_init(_a0_obj, 872u);
    _a0_obj->f_read = true;
    _a0_obj->f_write = false;
    _a0_obj->f_append = false;
    _a0_obj->f_create = false;
    _a0_obj->f_truncate = false;
    _a0_obj->f_create_new = false;
    l2 = (void*) _a0_obj;
    l3 = std_fs$open(l0, l2);
    if (l3.tag == 873u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct___defer_env_std_fs_3_t* _a1_obj = (vader_struct___defer_env_std_fs_3_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_fs_3_t));
    vader_obj_header_init(_a1_obj, 523u);
    _a1_obj->f_cap_0 = l3;
    t0 = (void*) _a1_obj;
    vader_fn_t* _a2_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a2_closure, 440u);
    _a2_closure->code = (void*) &vader_fn_lift___defer_std_fs_2;
    _a2_closure->env = t0;
    t0 = (void*) _a2_closure;
    vader_defer_push(vader_ref_box(t0));
    vader_array_t* _a3_arr = vader_array_new(29u, 0u, 1u, 504u);
    l2 = (void*) _a3_arr;
    t0 = l3.payload.obj;
    l4 = std_fs$system_size(((vader_struct_std_fs$File_t*) t0)->f_handle);
    t1 = std_fs$reads_whole(l4, l1);
    if (t1) {
        vader_array_t* _a4_arr = vader_array_new(29u, 1u, 1u, 504u);
        ((uint8_t*) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = (uint8_t) INT32_C(0);
        l5 = (void*) _a4_arr;
        l6 = vader_chk_add(i64, l4, INT64_C(1));
        vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
        l5 = (void*) _a5_arr;
        t0 = l3.payload.obj;
        l7 = std_fs$read_into(((vader_struct_std_fs$File_t*) t0)->f_handle, l5);
        if (l7.tag == 873u) {
            l8 = l7.payload.obj;
            vader_defer_pop_exec(1u);
            { vader_box_t __vret = vader_ref_box(l8); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((int64_t) l7.payload.i);
        if ((t2 <= l4)) {
            l4 = ((int64_t) l7.payload.i);
            vader_array_t* _a6_arr = vader_array_slice((vader_array_t*) l5, (int64_t) INT64_C(0), (int64_t) l4);
            l8 = (void*) _a6_arr;
            vader_defer_pop_exec(1u);
            { vader_box_t __vret = vader_ref_box(l8); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = l5;
    }
    vader_array_t* _a7_arr = vader_array_new(29u, 1u, 1u, 504u);
    ((uint8_t*) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = (uint8_t) INT32_C(0);
    t0 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) INT64_C(65536));
    l5 = (void*) _a8_arr;
    for (;;) {
        t2 = ((vader_array_t*) l2)->length;
        if (!((t2 > l1))) {
            t0 = l3.payload.obj;
            l7 = std_fs$system_read(((vader_struct_std_fs$File_t*) t0)->f_handle, l5, INT64_C(65536));
            if (l7.tag == 873u) {
                l8 = l7.payload.obj;
                vader_defer_pop_exec(1u);
                { vader_box_t __vret = vader_ref_box(l8); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = ((int64_t) l7.payload.i);
            if (t2 == INT64_C(0)) {
                vader_defer_pop_exec(1u);
                { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l4 = ((int64_t) l7.payload.i);
            vader_array_t* _a9_arr = vader_array_slice((vader_array_t*) l5, (int64_t) INT64_C(0), (int64_t) l4);
            l9 = (void*) _a9_arr;
            vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l9);
            continue;
        }
        break;
    }
    vader_struct_std_io$IOError_t* _a10_obj = (vader_struct_std_io$IOError_t*) vader_gc_alloc(sizeof(vader_struct_std_io$IOError_t));
    vader_obj_header_init(_a10_obj, 873u);
    _a10_obj->f_msg = 2140u;
    _a10_obj->f_kind = (uint8_t) 0;
    _a10_obj->f_code = INT32_C(0);
    l2 = (void*) _a10_obj;
    vader_defer_pop_exec(1u);
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
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
    if (!(l2.tag == 873u)) {
        t0 = l2.payload.obj;
        t1 = vader_host_std_core$bytes_to_string(t0);
        { vader_box_t __vret = vader_box_string(499u, t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_fs$read_into(vader_box_t l0, void* l1) {
    int64_t l2, l3, l4, l6, l8;
    void* l5 = NULL;
    vader_box_t l7 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l7 };
    void** gc_raw_roots[3] = { &l1, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = INT64_C(0);
    for (;;) {
        l3 = ((vader_array_t*) l1)->length;
        if ((l2 < l3)) {
            l4 = ((vader_array_t*) l1)->length;
            vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l1, (int64_t) l2, (int64_t) l4);
            l5 = (void*) _a0_arr;
            t0 = ((vader_array_t*) l1)->length;
            l6 = vader_chk_sub(i64, t0, l2);
            l7 = std_fs$system_read(l0, l5, l6);
            if (l7.tag == 873u) {
                t1 = l7.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t0 = ((int64_t) l7.payload.i);
            if (t0 == INT64_C(0)) {
                { vader_box_t __vret = vader_box_i64(503u, l2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l8 = ((int64_t) l7.payload.i);
            l2 = vader_chk_add(i64, l2, l8);
            continue;
        }
        break;
    }
    { vader_box_t __vret = vader_box_i64(503u, l2); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool std_fs$reads_whole(int64_t l0, int64_t l1) {
    bool l2;
    if ((l0 >= INT64_C(0))) {
        l2 = (l0 <= l1);
    } else {
        l2 = false;
    }
    if (l2) {
        return (l0 < INT64_C(4294967295));
    }
    return false;
}

static vader_box_t std_fs$refusal_of(vader_string_t l0, void* l1) {
    bool l2;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_fs$has_nul(l0);
    if (t0) {
        t1 = (void*) &vader_data_42;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_std_fs$OpenOptions_t*) l1)->f_write;
    if (t0) {
        l2 = true;
    } else {
        l2 = ((vader_struct_std_fs$OpenOptions_t*) l1)->f_append;
    }
    t0 = ((vader_struct_std_fs$OpenOptions_t*) l1)->f_read;
    if (!(t0)) {
        if (!(l2)) {
            t1 = std_fs$invalid_options(2537u);
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    {
        t0 = ((vader_struct_std_fs$OpenOptions_t*) l1)->f_create;
        if (!(t0)) {
            t0 = ((vader_struct_std_fs$OpenOptions_t*) l1)->f_create_new;
            if (!(t0)) {
                goto end_30;
            }
        }
        if (!(l2)) {
            t1 = std_fs$invalid_options(1938u);
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    } end_30: ;
    t0 = ((vader_struct_std_fs$OpenOptions_t*) l1)->f_truncate;
    if (t0) {
        t0 = ((vader_struct_std_fs$OpenOptions_t*) l1)->f_write;
        if (!(t0)) {
            t1 = std_fs$invalid_options(2955u);
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t0 = ((vader_struct_std_fs$OpenOptions_t*) l1)->f_truncate;
    if (t0) {
        t0 = ((vader_struct_std_fs$OpenOptions_t*) l1)->f_append;
        if (t0) {
            t1 = std_fs$invalid_options(2954u);
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t std_fs$stat_cells(vader_string_t l0, bool l1) {
    void* l2 = NULL;
    int32_t l3;
    int32_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l2, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 4u, 8u, 503u);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 3u] = (int64_t) INT64_C(0);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = (int64_t) INT64_C(0);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = (int64_t) INT64_C(0);
    ((int64_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int64_t) INT64_C(0);
    l2 = (void*) _a0_arr;
    l3 = std_fs$link_flag(l1);
    t0 = vader_host_system_posix$sys_path_stat(l0, l3, l2);
    if (!(t0 != INT32_C(0))) {
        { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = std_io$last_io_error(1852u);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_fs$system_close(vader_box_t l0) {
    int32_t t0, t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_fs$fd_of(l0);
    t1 = vader_host_system_posix$sys_close(t0);
    if (!(t1 != INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t2 = std_io$last_io_error(1882u);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_fs$system_open(vader_string_t l0, void* l1) {
    int32_t l2;
    void* t0 = NULL;
    int32_t t1;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_fs$open_flags(l1);
    l2 = vader_host_system_posix$sys_open(l0, l2, INT32_C(438));
    if ((l2 < INT32_C(0))) {
        t0 = std_io$last_io_error(1850u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = std_fs$access_mode(l1);
    if (t1 == INT32_C(0)) {
        t1 = vader_host_system_posix$sys_fd_kind(l2);
        if (t1 == INT32_C(2)) {
            vader_host_system_posix$sys_close(l2);
            t0 = std_fs$is_a_directory(INT32_C(21));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = vader_box_i32(502u, l2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = vader_box_i32(502u, l2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_fs$system_read(vader_box_t l0, void* l1, int64_t l2) {
    int64_t l3;
    int32_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    for (;;) {
        t0 = std_fs$fd_of(l0);
        l3 = vader_host_system_posix$sys_read(t0, l1, l2);
        if (!((l3 >= INT64_C(0)))) {
            t0 = vader_host_system_posix$sys_last_errno();
            if (!(t0 != INT32_C(4))) {
                continue;
            }
            t1 = std_io$last_io_error(2663u);
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        break;
    }
    { vader_box_t __vret = vader_box_i64(503u, l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t std_fs$system_size(vader_box_t l0) {
    int32_t t0;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_fs$fd_of(l0);
    t1 = vader_host_system_posix$sys_fd_size(t0);
    { int64_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_fs$system_write(vader_box_t l0, void* l1) {
    int32_t l2;
    int64_t l3, l4;
    int32_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    for (;;) {
        l2 = std_fs$fd_of(l0);
        l3 = ((vader_array_t*) l1)->length;
        l4 = vader_host_system_posix$sys_write(l2, l1, l3);
        if (!((l4 >= INT64_C(0)))) {
            t0 = vader_host_system_posix$sys_last_errno();
            if (!(t0 != INT32_C(4))) {
                continue;
            }
            t1 = std_io$last_io_error(3280u);
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        break;
    }
    { vader_box_t __vret = vader_box_i64(503u, l4); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t std_fs$write_file(vader_string_t l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l2, &l3 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_fs$create(l0);
    if (l2.tag == 873u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    l3 = std_fs$File$std_io$Writer$write(t0, l1);
    t0 = l2.payload.obj;
    l2 = std_fs$close(t0);
    if (!(l3.tag == 873u)) {
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l3.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}
