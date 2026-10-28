#include "bootstrap.split.h"

static int64_t std_path$extension_dot(vader_string_t l0);

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
    return 438u;
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
    t0 = std_string$replace_chars_where(l0, l1, 438u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
