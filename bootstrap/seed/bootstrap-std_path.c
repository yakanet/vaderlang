#include "bootstrap.split.h"

static int64_t std_path$extension_dot(vader_string_t l0);
static bool std_path$is_absolute(vader_string_t l0);

vader_string_t std_path$as_string(vader_string_t l0) {
    return l0;
}

static int64_t std_path$extension_dot(vader_string_t l0) {
    int64_t t0;
    t0 = std_string$last_index_of(l0, 46u, INT64_C(1));
    return t0;
}

vader_string_t std_path$filename(vader_string_t l0) {
    vader_string_t l1;
    int64_t l2, l3;
    vader_string_t t0;
    l1 = l0;
    l2 = std_string$last_index_of(l1, 47u, INT64_C(0));
    if (!((l2 < INT64_C(0)))) {
        l2 = vader_chk_add(i64, l2, INT64_C(1));
        l3 = vader_host_std_core$byte_len(l1);
        t0 = vader_host_std_core$byte_slice(l1, l2, l3);
        return t0;
    }
    return l1;
}

static bool std_path$is_absolute(vader_string_t l0) {
    vader_string_t t0;
    bool t1;
    t0 = std_path$as_string(l0);
    t1 = std_string$starts_with(t0, 482u);
    return t1;
}

vader_string_t std_path$name(vader_string_t l0) {
    vader_string_t l1;
    int64_t l2;
    vader_string_t t0;
    l1 = std_path$filename(l0);
    l2 = std_path$extension_dot(l1);
    if (!((l2 < INT64_C(0)))) {
        t0 = vader_host_std_core$byte_slice(l1, INT64_C(0), l2);
        return t0;
    }
    return l1;
}

vader_string_t std_path$normalize(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t l11 = 0;
    bool l2, l8, l9, l10, l12, l13;
    void* l3 = NULL;
    void* l17 = NULL;
    int64_t l4, l5, l6, l7, l14, l15, l16;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l3, &l17, &t3 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l11, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = l0;
    t0 = std_string$is_empty(l1);
    if (t0) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = std_path$is_absolute(l0);
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 494u);
    l3 = (void*) _a0_arr;
    l4 = INT64_C(0);
    l5 = vader_host_std_core$byte_len(l1);
    if (l2) {
        l6 = INT64_C(1);
    } else {
        l6 = INT64_C(0);
    }
    l7 = l6;
    while ((l6 <= l5)) {
        l8 = l6 == l5;
        if (!(l8)) {
            l9 = std_string$matches_at(l1, l6, 482u);
        } else {
            l9 = false;
        }
        if (l9) {
            l10 = true;
        } else {
            l10 = l8;
        }
        if (l10) {
            l11 = vader_host_std_core$byte_slice(l1, l7, l6);
            t0 = std_string$is_empty(l11);
            if (t0) {
                l12 = true;
            } else {
                l12 = l11 == 433u;
            }
            if (!(l12)) {
                if (l11 == 434u) {
                    if ((l4 > INT64_C(0))) {
                        l14 = vader_chk_sub(i64, l4, INT64_C(1));
                        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l14)
                        t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l14];
                        t2 = t1.payload.s;
                        l13 = t2 != 434u;
                    } else {
                        l13 = false;
                    }
                    if (l13) {
                        l4 = vader_chk_sub(i64, l4, INT64_C(1));
                    } else if (!(l2)) {
                        l15 = ((vader_array_t*) l3)->length;
                        if ((l4 < l15)) {
                            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                            vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4] = vader_box_string(494u, l11);
                        } else {
                            vader_array_push_scalar((vader_array_t*) l3, vader_box_string(494u, l11));
                        }
                        l4 = vader_chk_add(i64, l4, INT64_C(1));
                    }
                } else {
                    l16 = ((vader_array_t*) l3)->length;
                    if ((l4 < l16)) {
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                        vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4] = vader_box_string(494u, l11);
                    } else {
                        vader_array_push_scalar((vader_array_t*) l3, vader_box_string(494u, l11));
                    }
                    l4 = vader_chk_add(i64, l4, INT64_C(1));
                }
            }
            l7 = vader_chk_add(i64, l6, INT64_C(1));
        }
        l6 = vader_chk_add(i64, l6, INT64_C(1));
    }
    vader_array_t* _a4_arr = vader_array_new(26u, 0u, 0u, 494u);
    t3 = (void*) _a4_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a5_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a5_obj, 861u);
    _a5_obj->f_parts = t3;
    l17 = (void*) _a5_obj;
    if (l2) {
        std_string__builder$append(l17, 482u);
    }
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        if ((l5 > INT64_C(0))) {
            std_string__builder$append(l17, 482u);
        }
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
        t1 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l5];
        l1 = t1.payload.s;
        std_string__builder$append(l17, l1);
        l5 = (l5 + INT64_C(1));
    }
    l1 = std_string__builder$StringBuilder$std_core$Display$to_string(l17);
    t0 = std_string$is_empty(l1);
    if (t0) {
        if (!(l2)) {
            { vader_gc_top = gc_frame.prev; return 433u; }
        }
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t std_path$parent(vader_string_t l0) {
    vader_string_t l1;
    int64_t l2;
    vader_string_t t0;
    l1 = l0;
    l2 = std_string$last_index_of(l1, 47u, INT64_C(0));
    if ((l2 < INT64_C(0))) {
        return 0u;
    }
    if (!(l2 == INT64_C(0))) {
        t0 = vader_host_std_core$byte_slice(l1, INT64_C(0), l2);
        return t0;
    }
    return 482u;
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
        l1 = (void*) &vader_fn_static___lambda_std_path_1;
        t1 = std_string$replace_chars_where(l0, l1, 1034u);
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
    return l0;
}

vader_string_t std_path$to_posix(vader_string_t l0) {
    void* l1 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = (void*) &vader_fn_static___lambda_std_path_0;
    t0 = std_string$replace_chars_where(l0, l1, 482u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
