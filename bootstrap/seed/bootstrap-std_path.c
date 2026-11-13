#include "bootstrap.split.h"

static vader_box_t std_path$extension_dot(vader_string_t l0);
static vader_string_t std_path$filename_on(vader_string_t l0, uint8_t l1);
static bool std_path$is_anchored(vader_string_t l0, uint8_t l1);
static bool std_path$is_ascii_letter(uint8_t l0);
static vader_box_t std_path$last_separator(vader_string_t l0, int64_t l1);
static vader_box_t std_path$next_separator(vader_string_t l0, int64_t l1);
static vader_string_t std_path$normalize_on(vader_string_t l0, uint8_t l1);
static vader_string_t std_path$parent_on(vader_string_t l0, uint8_t l1);
static int64_t std_path$prefix_length(vader_string_t l0, uint8_t l1);
static int64_t std_path$root_length(vader_string_t l0, uint8_t l1);
static vader_string_t std_path$to_posix_on(vader_string_t l0, uint8_t l1);
static vader_string_t std_path$without_trailing_separators(vader_string_t l0, uint8_t l1);

vader_string_t std_path$as_string(vader_string_t l0) {
    return l0;
}

static vader_box_t std_path$extension_dot(vader_string_t l0) {
    vader_box_t t0;
    t0 = std_string$last_index_of(l0, 46u, INT64_C(1));
    return t0;
}

vader_string_t std_path$filename(vader_string_t l0) {
    vader_string_t l1;
    uint8_t l2;
    vader_string_t t0;
    l1 = l0;
    l2 = vader_host_std_target$current_os();
    t0 = std_path$filename_on(l1, l2);
    return t0;
}

static vader_string_t std_path$filename_on(vader_string_t l0, uint8_t l1) {
    vader_string_t l2;
    int64_t l3, l5;
    vader_box_t l4;
    vader_string_t t0;
    int64_t t1;
    l2 = std_path$without_trailing_separators(l0, l1);
    l3 = std_path$root_length(l2, l1);
    l4 = std_path$last_separator(l2, l3);
    if (l4.tag == 0u) {
        l5 = vader_host_std_core$byte_len(l2);
        t0 = vader_host_std_core$byte_slice(l2, l3, l5);
        return t0;
    }
    t1 = ((int64_t) l4.payload.i);
    l3 = vader_chk_add(i64, t1, INT64_C(1));
    l5 = vader_host_std_core$byte_len(l2);
    t0 = vader_host_std_core$byte_slice(l2, l3, l5);
    return t0;
}

static bool std_path$is_anchored(vader_string_t l0, uint8_t l1) {
    int64_t l2;
    bool l3;
    bool t0;
    uint8_t t1;
    l2 = std_path$root_length(l0, l1);
    t0 = std_string$starts_with(l0, 483u);
    if (t0) {
        return true;
    }
    if ((l2 > INT64_C(0))) {
        l2 = vader_chk_sub(i64, l2, INT64_C(1));
        t1 = vader_host_std_core$byte_at(l0, l2);
        l3 = t1 == INT32_C(47);
    } else {
        l3 = false;
    }
    return l3;
}

static bool std_path$is_ascii_letter(uint8_t l0) {
    bool l1;
    if ((l0 >= INT32_C(97))) {
        l1 = (l0 <= INT32_C(122));
    } else {
        l1 = false;
    }
    if (l1) {
        return true;
    }
    if ((l0 >= INT32_C(65))) {
        l1 = (l0 <= INT32_C(90));
    } else {
        l1 = false;
    }
    return l1;
}

static vader_box_t std_path$last_separator(vader_string_t l0, int64_t l1) {
    int64_t l2;
    uint8_t t0;
    l2 = vader_host_std_core$byte_len(l0);
    for (;;) {
        if ((l2 > l1)) {
            l2 = vader_chk_sub(i64, l2, INT64_C(1));
            t0 = vader_host_std_core$byte_at(l0, l2);
            if (!(t0 == INT32_C(47))) {
                continue;
            }
            return vader_box_i64(506u, l2);
        }
        break;
    }
    return vader_box_obj(0u, NULL);
}

vader_string_t std_path$name(vader_string_t l0) {
    vader_string_t l1;
    int64_t l2;
    vader_box_t l3;
    vader_string_t t0;
    l1 = std_path$filename(l0);
    l3 = std_path$extension_dot(l1);
    if (l3.tag == 0u) {
        return l1;
    }
    l2 = ((int64_t) l3.payload.i);
    t0 = vader_host_std_core$byte_slice(l1, INT64_C(0), l2);
    return t0;
}

static vader_box_t std_path$next_separator(vader_string_t l0, int64_t l1) {
    int64_t l2, l3;
    uint8_t t0;
    l2 = l1;
    l3 = vader_host_std_core$byte_len(l0);
    while ((l2 < l3)) {
        t0 = vader_host_std_core$byte_at(l0, l2);
        if (t0 == INT32_C(47)) {
            return vader_box_i64(506u, l2);
        }
        l2 = (l2 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

vader_string_t std_path$normalize(vader_string_t l0) {
    vader_string_t l1 = 0;
    uint8_t l2;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = l0;
    l2 = vader_host_std_target$current_os();
    t0 = std_path$normalize_on(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_path$normalize_on(vader_string_t l0, uint8_t l1) {
    int64_t l2, l3, l6, l7, l12;
    bool l4, l10, l11, l13;
    void* l5 = NULL;
    void* l14 = NULL;
    vader_box_t l8 = vader_box_null();
    vader_string_t l9 = 0;
    bool t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    void* t4 = NULL;
    vader_box_t* gc_roots[2] = { &l8, &t2 };
    void** gc_raw_roots[3] = { &l5, &l14, &t4 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l9, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core$byte_len(l0);
    if (l2 == INT64_C(0)) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = std_path$root_length(l0, l1);
    l4 = std_path$is_anchored(l0, l1);
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 502u);
    l5 = (void*) _a0_arr;
    l6 = l3;
    while ((l6 <= l2)) {
        l8 = std_path$next_separator(l0, l6);
        if (l8.tag == 0u) {
            l7 = l2;
        } else {
            l7 = ((int64_t) l8.payload.i);
        }
        l9 = vader_host_std_core$byte_slice(l0, l6, l7);
        l6 = vader_chk_add(i64, l7, INT64_C(1));
        t0 = std_core$is_empty_1(l9);
        if (t0) {
            continue;
        }
        if (l9 == 432u) {
            continue;
        }
        if (l9 == 433u) {
            t1 = vader_array_length(((vader_array_t*) l5));
            l11 = (t1 > INT64_C(0));
        } else {
            l11 = false;
        }
        if (l11) {
            t1 = vader_array_length(((vader_array_t*) l5));
            l12 = vader_chk_sub(i64, t1, INT64_C(1));
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l12)
            t2 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l12];
            t3 = t2.payload.s;
            l10 = t3 != 433u;
        } else {
            l10 = false;
        }
        if (l10) {
            t2 = vader_array_remove_last((vader_array_t*) l5);
            continue;
        }
        if (l9 != 433u) {
            l13 = true;
        } else {
            l13 = !(l4);
        }
        if (l13) {
            vader_array_push_scalar((vader_array_t*) l5, vader_box_string(502u, l9));
        }
    }
    if (l3 == INT64_C(0)) {
        t0 = std_core$is_empty__string(l5);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return 432u; }
        }
    }
    vader_array_t* _a2_arr = vader_array_new(26u, 0u, 0u, 502u);
    t4 = (void*) _a2_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a3_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a3_obj, 881u);
    _a3_obj->f_parts = t4;
    l14 = (void*) _a3_obj;
    l9 = vader_host_std_core$byte_slice(l0, INT64_C(0), l3);
    std_string__builder$append(l14, l9);
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l5));
    while ((l2 < l3)) {
        if ((l2 > INT64_C(0))) {
            std_string__builder$append(l14, 483u);
        }
        vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t2 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l2];
        l9 = t2.payload.s;
        std_string__builder$append(l14, l9);
        l2 = (l2 + INT64_C(1));
    }
    t3 = std_string__builder$StringBuilder$std_core$Display$to_string(l14);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t std_path$parent(vader_string_t l0) {
    vader_string_t l1;
    uint8_t l2;
    vader_string_t t0;
    l1 = l0;
    l2 = vader_host_std_target$current_os();
    t0 = std_path$parent_on(l1, l2);
    return t0;
}

static vader_string_t std_path$parent_on(vader_string_t l0, uint8_t l1) {
    vader_string_t l2;
    int64_t l3;
    vader_box_t l4;
    vader_string_t t0, t1;
    l2 = std_path$without_trailing_separators(l0, l1);
    l3 = std_path$root_length(l2, l1);
    l4 = std_path$last_separator(l2, l3);
    if (l4.tag == 0u) {
        t0 = vader_host_std_core$byte_slice(l2, INT64_C(0), l3);
        return t0;
    }
    l3 = ((int64_t) l4.payload.i);
    t0 = vader_host_std_core$byte_slice(l2, INT64_C(0), l3);
    t1 = std_path$without_trailing_separators(t0, l1);
    return t1;
}

static int64_t std_path$prefix_length(vader_string_t l0, uint8_t l1) {
    int64_t l2, l4;
    vader_box_t l3;
    uint8_t t0;
    bool t1;
    int64_t t2;
    if (l1 != INT32_C(0)) {
        return INT64_C(0);
    }
    l2 = vader_host_std_core$byte_len(l0);
    if ((l2 >= INT64_C(2))) {
        t0 = vader_host_std_core$byte_at(l0, INT64_C(0));
        t1 = std_path$is_ascii_letter(t0);
        if (t1) {
            t0 = vader_host_std_core$byte_at(l0, INT64_C(1));
            if (t0 == INT32_C(58)) {
                return INT64_C(2);
            }
        }
    }
    if ((l2 < INT64_C(3))) {
        return INT64_C(0);
    }
    t0 = vader_host_std_core$byte_at(l0, INT64_C(0));
    if (t0 != INT32_C(47)) {
        return INT64_C(0);
    }
    t0 = vader_host_std_core$byte_at(l0, INT64_C(1));
    if (t0 != INT32_C(47)) {
        return INT64_C(0);
    }
    t0 = vader_host_std_core$byte_at(l0, INT64_C(2));
    if (t0 == INT32_C(47)) {
        return INT64_C(0);
    }
    l3 = std_path$next_separator(l0, INT64_C(2));
    if (l3.tag == 0u) {
        return l2;
    }
    t2 = ((int64_t) l3.payload.i);
    l4 = vader_chk_add(i64, t2, INT64_C(1));
    l3 = std_path$next_separator(l0, l4);
    if (l3.tag == 0u) {
        return l2;
    }
    t2 = ((int64_t) l3.payload.i);
    return t2;
}

static int64_t std_path$root_length(vader_string_t l0, uint8_t l1) {
    int64_t l2, l3;
    uint8_t t0;
    int64_t t1;
    l2 = std_path$prefix_length(l0, l1);
    l3 = vader_host_std_core$byte_len(l0);
    if ((l2 < l3)) {
        t0 = vader_host_std_core$byte_at(l0, l2);
        if (t0 == INT32_C(47)) {
            t1 = vader_chk_add(i64, l2, INT64_C(1));
            return t1;
        }
        return l2;
    }
    return l2;
}

vader_string_t std_path$to_native(vader_string_t l0) {
    void* l1 = NULL;
    uint8_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_host_std_target$current_os();
    if (!(t0 != INT32_C(0))) {
        l1 = (void*) &vader_fn_static___lambda_std_path_0;
        t1 = std_string$replace_chars_where(l0, l1, 1038u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t std_path$to_native_1(vader_string_t l0) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_path$as_string(l0);
    t1 = std_path$to_native(t0);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t std_path$to_path(vader_string_t l0) {
    uint8_t l1;
    bool t0;
    vader_string_t t1;
    t0 = std_string$ends_with(l0, 483u);
    if (!(t0)) {
        return l0;
    }
    l1 = vader_host_std_target$current_os();
    t1 = std_path$without_trailing_separators(l0, l1);
    return t1;
}

vader_string_t std_path$to_posix(vader_string_t l0) {
    uint8_t l1;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_target$current_os();
    t0 = std_path$to_posix_on(l0, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_path$to_posix_on(vader_string_t l0, uint8_t l1) {
    void* l2 = NULL;
    vader_string_t l3 = 0;
    vader_string_t l5 = 0;
    int64_t l4;
    bool t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l3, &l5, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1 != INT32_C(0)) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = (void*) &vader_fn_static___lambda_std_path_1;
    l3 = std_string$replace_chars_where(l0, l2, 483u);
    t0 = std_string$starts_with(l3, 493u);
    if (t0) {
        l4 = vader_host_std_core$byte_len(l3);
        l5 = vader_host_std_core$byte_slice(l3, INT64_C(8), l4);
        t1 = concat_2(485u, l5);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = std_string$starts_with(l3, 492u);
    if (!(t0)) {
        { vader_string_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_host_std_core$byte_len(l3);
    t1 = vader_host_std_core$byte_slice(l3, INT64_C(4), l4);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t std_path$without_trailing_separators(vader_string_t l0, uint8_t l1) {
    int64_t l2, l3, l4;
    uint8_t t0;
    vader_string_t t1;
    l2 = vader_host_std_core$byte_len(l0);
    if (l2 == INT64_C(0)) {
        return l0;
    }
    l3 = vader_chk_sub(i64, l2, INT64_C(1));
    t0 = vader_host_std_core$byte_at(l0, l3);
    if (t0 != INT32_C(47)) {
        return l0;
    }
    l3 = std_path$root_length(l0, l1);
    while ((l2 > l3)) {
        l4 = vader_chk_sub(i64, l2, INT64_C(1));
        t0 = vader_host_std_core$byte_at(l0, l4);
        if (!(t0 == INT32_C(47))) {
            break;
        }
        l2 = vader_chk_sub(i64, l2, INT64_C(1));
    }
    t1 = vader_host_std_core$byte_slice(l0, INT64_C(0), l2);
    return t1;
}
