#include "bootstrap.split.h"

static bool toolchain_project$is_portable_name(vader_string_t l0);
static bool toolchain_project$is_windows_device_name(vader_string_t l0);
static bool toolchain_project$leaves_project(vader_string_t l0);

vader_box_t toolchain_project$asset_problem(vader_string_t l0) {
    bool t0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = toolchain_project$leaves_project(l0);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = concat_3(1995u, l0, 1460u);
    { vader_box_t __vret = vader_box_string(603u, t1); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t toolchain_project$entry_name_problem(vader_string_t l0) {
    bool t0;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = toolchain_project$is_portable_name(l0);
    if (!(t0)) {
        { vader_box_t __vret = vader_box_string(603u, 2141u); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = toolchain_project$is_windows_device_name(l0);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_box_t __vret = vader_box_string(603u, 2140u); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t toolchain_project$entry_named(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[3] = { &l0, &l3, &l6 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l2, &t0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_string$to_lower(l1);
    l3 = l0;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
        t0 = ((vader_struct_toolchain_project$ManifestEntry_t*) l6)->f_name;
        t1 = std_string$to_lower(t0);
        if (t1 == l2) {
            { vader_box_t __vret = vader_ref_box(l6); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static bool toolchain_project$is_portable_name(vader_string_t l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    bool t0;
    uint32_t t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0 == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = std_string$starts_with(l0, 459u);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l1 = std_string$chars(l0);
    for (;;) {
        l2 = std_string$StringChars$std_core$Iterator$next(l1);
        if (!(l2.tag == 1048u)) {
            t1 = ((uint32_t) l2.payload.i);
            t0 = __lambda_toolchain_project_0(t1);
            if (t0) {
                continue;
            }
            { vader_gc_top = gc_frame.prev; return false; }
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return true; }
}

static bool toolchain_project$is_windows_device_name(vader_string_t l0) {
    vader_string_t l1 = 0;
    bool l2;
    uint8_t l3;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_string$to_lower(l0);
    vader_array_t* _a0_arr = vader_array_new(28u, 4u, 0u, 603u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 3u] = vader_box_string(603u, 2912u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 2u] = vader_box_string(603u, 2005u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 1u] = vader_box_string(603u, 2982u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(603u, 2207u);
    t0 = (void*) _a0_arr;
    t1 = std_core$$array$Contains$contains__string(t0, l1);
    if (t1) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t2 = vader_host_std_core$Intrinsic$byte_len(l1);
    if (t2 == INT64_C(4)) {
        t1 = std_string$starts_with(l1, 2186u);
        if (t1) {
            l2 = true;
        } else {
            l2 = std_string$starts_with(l1, 2780u);
        }
    } else {
        l2 = false;
    }
    if (l2) {
        l3 = vader_host_std_core$Intrinsic$byte_at(l1, INT64_C(3));
        if ((INT32_C(48) <= l3)) {
            l2 = (l3 <= INT32_C(57));
        } else {
            l2 = false;
        }
        { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_project$leaves_project(vader_string_t l0) {
    void* l1 = NULL;
    vader_string_t l2 = 0;
    bool l3;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = (void*) &vader_fn_static___lambda_toolchain_project_1;
    l2 = std_string$replace_chars_where(l0, l1, 514u);
    t0 = std_string$starts_with(l2, 514u);
    if (t0) {
        l3 = true;
    } else {
        l3 = std_string$string$std_core$Contains$contains(l2, 541u);
    }
    if (l3) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t1 = std_string$split(l2, 514u);
    t0 = std_core$$array$Contains$contains__string(t1, 473u);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
