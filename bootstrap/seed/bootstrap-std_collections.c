#include "bootstrap.split.h"

bool std_collections_add__i32(void* l0, int32_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l0)->f_inner, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    std_collections_put__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l0)->f_inner, l1, true);
    { vader_gc_top = gc_frame.prev; return true; }
    vader_gc_top = gc_frame.prev;
}

bool std_collections_add__i64(void* l0, int64_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_contains_key__i64__bool(((vader_struct_std_collections_MutableSet__i64_t*) l0)->f_inner, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    std_collections_put__i64__bool(((vader_struct_std_collections_MutableSet__i64_t*) l0)->f_inner, l1, true);
    { vader_gc_top = gc_frame.prev; return true; }
    vader_gc_top = gc_frame.prev;
}

bool std_collections_add__string(void* l0, vader_string_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_contains_key__string__bool(((vader_struct_std_collections_MutableSet__string_t*) l0)->f_inner, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    std_collections_put__string__bool(((vader_struct_std_collections_MutableSet__string_t*) l0)->f_inner, l1, true);
    { vader_gc_top = gc_frame.prev; return true; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_clear__i32__bool(void* l0) {
    size_t l1, l2;
    int64_t t0;
    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__bool_t*) l0);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l1 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index)->length;
    l2 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            if ((l2 < l1)) {
                if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2] = (int32_t) INT32_C(0);
                t0 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t0;
                goto loop_12;
            } else {
            }
        }
    }
    return;
}

void std_collections_clear__string__string(void* l0) {
    size_t l1, l2;
    int64_t t0;
    ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__string_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__string_t*) l0);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l1 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index)->length;
    l2 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            if ((l2 < l1)) {
                if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2] = (int32_t) INT32_C(0);
                t0 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t0;
                goto loop_12;
            } else {
            }
        }
    }
    return;
}

bool std_collections_contains_key__i32__bool(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    int64_t t1;
    int32_t t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    t1 = ((int64_t) (int32_t) l1);
    l2 = (uint64_t) (int64_t) t1;
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_18: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                if (t2 != INT32_C(-1)) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                    t1 = (((int64_t) (int32_t) t2) - INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                    if (t2 == l1) {
                        return true;
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l3 + l5);
                    l6 = (size_t) (int64_t) t1;
                    l7 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
                    t1 = (l6 & l7);
                    l3 = (size_t) (int64_t) t1;
                    goto loop_18;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t1 = (l3 + l5);
                l6 = (size_t) (int64_t) t1;
                l7 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
                t1 = (l6 & l7);
                l3 = (size_t) (int64_t) t1;
                goto loop_18;
            } else {
            }
        }
    }
    return false;
}

bool std_collections_contains_key__i64__bool(void* l0, int64_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    int64_t t1;
    int32_t t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    t1 = l1;
    l2 = (uint64_t) (int64_t) t1;
    l3 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_18: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                if (t2 != INT32_C(-1)) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                    t1 = (((int64_t) (int32_t) t2) - INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                    if (t1 == l1) {
                        return true;
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l3 + l5);
                    l6 = (size_t) (int64_t) t1;
                    l7 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
                    t1 = (l6 & l7);
                    l3 = (size_t) (int64_t) t1;
                    goto loop_18;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t1 = (l3 + l5);
                l6 = (size_t) (int64_t) t1;
                l7 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
                t1 = (l6 & l7);
                l3 = (size_t) (int64_t) t1;
                goto loop_18;
            } else {
            }
        }
    }
    return false;
}

bool std_collections_contains_key__string__bool(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_18: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t1 != INT32_C(-1)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                    t2 = (((int64_t) (int32_t) t1) - INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                    t4 = t3.payload.s;
                    if (t4 == l1) {
                        { vader_gc_top = gc_frame.prev; return true; }
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l3 + l5);
                    l6 = (size_t) (int64_t) t2;
                    l7 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
                    t2 = (l6 & l7);
                    l3 = (size_t) (int64_t) t2;
                    goto loop_18;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t2 = (l3 + l5);
                l6 = (size_t) (int64_t) t2;
                l7 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
                t2 = (l6 & l7);
                l3 = (size_t) (int64_t) t2;
                goto loop_18;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return false; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__i32__Any(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__Any_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__Any_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__i32__bool(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__bool_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__bool_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__i32__i32(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__i32_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__i32_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__i32__string(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__string_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__string_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__i32__usize(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__usize_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__usize_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__i64__Any(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__Any_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__Any_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__i64__bool(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__bool_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__bool_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__string__Any(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__Any_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__Any_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__string__bool(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__bool_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__bool_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__string__i32(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i32_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i32_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__string__i64(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i64_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i64_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__string__string(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__string_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__string_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__string__usize(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__usize_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__usize_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__u64__Any(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__Any_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__Any_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__u64__usize(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__usize_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__usize_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__usize__Any(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__Any_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__Any_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__usize__bool(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__bool_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__bool_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__usize__i32(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__i32_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__i32_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_ensure_index__usize__string(void* l0) {
    void* l1 = NULL;
    size_t l2;
    size_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
        l1 = (void*) _a0_arr;
        l2 = (size_t) (int64_t) INT64_C(0);
        {
            loop_10: {
                if ((l2 < INT64_C(16))) {
                    vader_array_push_i32((vader_array_t*) l1, INT32_C(0));
                    t1 = (l2 + INT64_C(1));
                    l2 = (size_t) (int64_t) t1;
                    goto loop_10;
                } else {
                }
            }
        }
        ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_index = l1;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__string_t*) l0);
        l2 = (size_t) (int64_t) INT64_C(15);
        ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_mask = l2;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__string_t*) l0);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t std_collections_get__i32__Any(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    vader_box_t t1;
    int64_t t2;
    int32_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    t2 = ((int64_t) (int32_t) l1);
    l2 = (uint64_t) (int64_t) t2;
    l3 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_20: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t3 != INT32_C(0)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                if (t3 != INT32_C(-1)) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                    t2 = (((int64_t) (int32_t) t3) - INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_ekeys);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                    if (t3 == l1) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_evals);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                        return t1;
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l3 + l5);
                    l6 = (size_t) (int64_t) t2;
                    l7 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask;
                    t2 = (l6 & l7);
                    l3 = (size_t) (int64_t) t2;
                    goto loop_20;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t2 = (l3 + l5);
                l6 = (size_t) (int64_t) t2;
                l7 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask;
                t2 = (l6 & l7);
                l3 = (size_t) (int64_t) t2;
                goto loop_20;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
}

vader_box_t std_collections_get__i32__bool(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    vader_box_t t1;
    int64_t t2;
    int32_t t3;
    bool t4;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    t2 = ((int64_t) (int32_t) l1);
    l2 = (uint64_t) (int64_t) t2;
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_20: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t3 != INT32_C(0)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                if (t3 != INT32_C(-1)) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                    t2 = (((int64_t) (int32_t) t3) - INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                    if (t3 == l1) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_evals);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_box_bool(7u, ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4]);
                        t4 = t1.payload.b;
                        t1 = vader_box_bool(7u, t4);
                        return t1;
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l3 + l5);
                    l6 = (size_t) (int64_t) t2;
                    l7 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
                    t2 = (l6 & l7);
                    l3 = (size_t) (int64_t) t2;
                    goto loop_20;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t2 = (l3 + l5);
                l6 = (size_t) (int64_t) t2;
                l7 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
                t2 = (l6 & l7);
                l3 = (size_t) (int64_t) t2;
                goto loop_20;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
}

vader_box_t std_collections_get__i32__i32(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    vader_box_t t1;
    int64_t t2;
    int32_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    t2 = ((int64_t) (int32_t) l1);
    l2 = (uint64_t) (int64_t) t2;
    l3 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_20: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t3 != INT32_C(0)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                if (t3 != INT32_C(-1)) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                    t2 = (((int64_t) (int32_t) t3) - INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_ekeys);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                    if (t3 == l1) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_evals);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                        t1 = vader_box_i32(3u, t3);
                        return t1;
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l3 + l5);
                    l6 = (size_t) (int64_t) t2;
                    l7 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask;
                    t2 = (l6 & l7);
                    l3 = (size_t) (int64_t) t2;
                    goto loop_20;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t2 = (l3 + l5);
                l6 = (size_t) (int64_t) t2;
                l7 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask;
                t2 = (l6 & l7);
                l3 = (size_t) (int64_t) t2;
                goto loop_20;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
}

vader_box_t std_collections_get__i32__string(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    vader_box_t t1;
    int64_t t2;
    int32_t t3;
    vader_string_t t4;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    t2 = ((int64_t) (int32_t) l1);
    l2 = (uint64_t) (int64_t) t2;
    l3 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_20: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t3 != INT32_C(0)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                if (t3 != INT32_C(-1)) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                    t2 = (((int64_t) (int32_t) t3) - INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_ekeys);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                    if (t3 == l1) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_evals);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
                        t4 = t1.payload.s;
                        t1 = vader_box_string(2u, t4);
                        return t1;
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l3 + l5);
                    l6 = (size_t) (int64_t) t2;
                    l7 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask;
                    t2 = (l6 & l7);
                    l3 = (size_t) (int64_t) t2;
                    goto loop_20;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t2 = (l3 + l5);
                l6 = (size_t) (int64_t) t2;
                l7 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask;
                t2 = (l6 & l7);
                l3 = (size_t) (int64_t) t2;
                goto loop_20;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
}

vader_box_t std_collections_get__i32__usize(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    vader_box_t t1;
    int64_t t2;
    int32_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    t2 = ((int64_t) (int32_t) l1);
    l2 = (uint64_t) (int64_t) t2;
    l3 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_20: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t3 != INT32_C(0)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                if (t3 != INT32_C(-1)) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                    t2 = (((int64_t) (int32_t) t3) - INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_ekeys);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                    if (t3 == l1) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_evals);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t2 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                        t1 = vader_box_i64(20u, t2);
                        return t1;
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l3 + l5);
                    l6 = (size_t) (int64_t) t2;
                    l7 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_mask;
                    t2 = (l6 & l7);
                    l3 = (size_t) (int64_t) t2;
                    goto loop_20;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t2 = (l3 + l5);
                l6 = (size_t) (int64_t) t2;
                l7 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_mask;
                t2 = (l6 & l7);
                l3 = (size_t) (int64_t) t2;
                goto loop_20;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
}

vader_box_t std_collections_get__i64__Any(void* l0, int64_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    vader_box_t t1;
    int64_t t2;
    int32_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    t2 = l1;
    l2 = (uint64_t) (int64_t) t2;
    l3 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_20: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t3 != INT32_C(0)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                if (t3 != INT32_C(-1)) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                    t2 = (((int64_t) (int32_t) t3) - INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_ekeys);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                    if (t2 == l1) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_evals);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                        return t1;
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l3 + l5);
                    l6 = (size_t) (int64_t) t2;
                    l7 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_mask;
                    t2 = (l6 & l7);
                    l3 = (size_t) (int64_t) t2;
                    goto loop_20;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t2 = (l3 + l5);
                l6 = (size_t) (int64_t) t2;
                l7 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_mask;
                t2 = (l6 & l7);
                l3 = (size_t) (int64_t) t2;
                goto loop_20;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
}

vader_box_t std_collections_get__string__Any(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    int64_t t3;
    vader_string_t t4;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_20: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 != INT32_C(-1)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                    t3 = (((int64_t) (int32_t) t2) - INT64_C(1));
                    l4 = (size_t) (int64_t) t3;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_ekeys);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                    t4 = t1.payload.s;
                    if (t4 == l1) {
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_evals);
                        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                        if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
                        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t3 = (l3 + l5);
                    l6 = (size_t) (int64_t) t3;
                    l7 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask;
                    t3 = (l6 & l7);
                    l3 = (size_t) (int64_t) t3;
                    goto loop_20;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t3 = (l3 + l5);
                l6 = (size_t) (int64_t) t3;
                l7 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask;
                t3 = (l6 & l7);
                l3 = (size_t) (int64_t) t3;
                goto loop_20;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t std_collections_get__string__bool(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    int64_t t3;
    vader_string_t t4;
    bool t5;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_20: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 != INT32_C(-1)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                    t3 = (((int64_t) (int32_t) t2) - INT64_C(1));
                    l4 = (size_t) (int64_t) t3;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                    t4 = t1.payload.s;
                    if (t4 == l1) {
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_evals);
                        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                        if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_box_bool(7u, ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4]);
                        t5 = t1.payload.b;
                        t1 = vader_box_bool(7u, t5);
                        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t3 = (l3 + l5);
                    l6 = (size_t) (int64_t) t3;
                    l7 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
                    t3 = (l6 & l7);
                    l3 = (size_t) (int64_t) t3;
                    goto loop_20;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t3 = (l3 + l5);
                l6 = (size_t) (int64_t) t3;
                l7 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
                t3 = (l6 & l7);
                l3 = (size_t) (int64_t) t3;
                goto loop_20;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t std_collections_get__string__i32(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    int64_t t3;
    vader_string_t t4;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_20: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 != INT32_C(-1)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                    t3 = (((int64_t) (int32_t) t2) - INT64_C(1));
                    l4 = (size_t) (int64_t) t3;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_ekeys);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                    t4 = t1.payload.s;
                    if (t4 == l1) {
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_evals);
                        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                        if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                        t2 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4];
                        t1 = vader_box_i32(3u, t2);
                        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t3 = (l3 + l5);
                    l6 = (size_t) (int64_t) t3;
                    l7 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask;
                    t3 = (l6 & l7);
                    l3 = (size_t) (int64_t) t3;
                    goto loop_20;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t3 = (l3 + l5);
                l6 = (size_t) (int64_t) t3;
                l7 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask;
                t3 = (l6 & l7);
                l3 = (size_t) (int64_t) t3;
                goto loop_20;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t std_collections_get__string__i64(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    int64_t t3;
    vader_string_t t4;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_20: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 != INT32_C(-1)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                    t3 = (((int64_t) (int32_t) t2) - INT64_C(1));
                    l4 = (size_t) (int64_t) t3;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_ekeys);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                    t4 = t1.payload.s;
                    if (t4 == l1) {
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_evals);
                        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                        if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                        t3 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4];
                        t1 = vader_box_i64(22u, t3);
                        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t3 = (l3 + l5);
                    l6 = (size_t) (int64_t) t3;
                    l7 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask;
                    t3 = (l6 & l7);
                    l3 = (size_t) (int64_t) t3;
                    goto loop_20;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t3 = (l3 + l5);
                l6 = (size_t) (int64_t) t3;
                l7 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask;
                t3 = (l6 & l7);
                l3 = (size_t) (int64_t) t3;
                goto loop_20;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t std_collections_get__string__string(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    int64_t t3;
    vader_string_t t4;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_20: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 != INT32_C(-1)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                    t3 = (((int64_t) (int32_t) t2) - INT64_C(1));
                    l4 = (size_t) (int64_t) t3;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_ekeys);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                    t4 = t1.payload.s;
                    if (t4 == l1) {
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_evals);
                        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                        if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l4];
                        t4 = t1.payload.s;
                        t1 = vader_box_string(2u, t4);
                        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t3 = (l3 + l5);
                    l6 = (size_t) (int64_t) t3;
                    l7 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask;
                    t3 = (l6 & l7);
                    l3 = (size_t) (int64_t) t3;
                    goto loop_20;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t3 = (l3 + l5);
                l6 = (size_t) (int64_t) t3;
                l7 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask;
                t3 = (l6 & l7);
                l3 = (size_t) (int64_t) t3;
                goto loop_20;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t std_collections_get__string__usize(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    int64_t t3;
    vader_string_t t4;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_20: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 != INT32_C(-1)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                    t3 = (((int64_t) (int32_t) t2) - INT64_C(1));
                    l4 = (size_t) (int64_t) t3;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_ekeys);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                    t4 = t1.payload.s;
                    if (t4 == l1) {
                        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_evals);
                        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                        if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                        t3 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4];
                        t1 = vader_box_i64(20u, t3);
                        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t3 = (l3 + l5);
                    l6 = (size_t) (int64_t) t3;
                    l7 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_mask;
                    t3 = (l6 & l7);
                    l3 = (size_t) (int64_t) t3;
                    goto loop_20;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t3 = (l3 + l5);
                l6 = (size_t) (int64_t) t3;
                l7 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_mask;
                t3 = (l6 & l7);
                l3 = (size_t) (int64_t) t3;
                goto loop_20;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t std_collections_get__u64__Any(void* l0, uint64_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    vader_box_t t1;
    int32_t t2;
    int64_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    l2 = l1;
    l3 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_19: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                if (t2 != INT32_C(-1)) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                    t3 = (((int64_t) (int32_t) t2) - INT64_C(1));
                    l4 = (size_t) (int64_t) t3;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_ekeys);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                    if (t3 == l1) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_evals);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                        return t1;
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t3 = (l3 + l5);
                    l6 = (size_t) (int64_t) t3;
                    l7 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask;
                    t3 = (l6 & l7);
                    l3 = (size_t) (int64_t) t3;
                    goto loop_19;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t3 = (l3 + l5);
                l6 = (size_t) (int64_t) t3;
                l7 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask;
                t3 = (l6 & l7);
                l3 = (size_t) (int64_t) t3;
                goto loop_19;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
}

vader_box_t std_collections_get__u64__usize(void* l0, uint64_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    vader_box_t t1;
    int32_t t2;
    int64_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    l2 = l1;
    l3 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_19: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                if (t2 != INT32_C(-1)) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                    t3 = (((int64_t) (int32_t) t2) - INT64_C(1));
                    l4 = (size_t) (int64_t) t3;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_ekeys);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                    if (t3 == l1) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_evals);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t3 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                        t1 = vader_box_i64(20u, t3);
                        return t1;
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t3 = (l3 + l5);
                    l6 = (size_t) (int64_t) t3;
                    l7 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_mask;
                    t3 = (l6 & l7);
                    l3 = (size_t) (int64_t) t3;
                    goto loop_19;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t3 = (l3 + l5);
                l6 = (size_t) (int64_t) t3;
                l7 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_mask;
                t3 = (l6 & l7);
                l3 = (size_t) (int64_t) t3;
                goto loop_19;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
}

vader_box_t std_collections_get__usize__Any(void* l0, size_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    vader_box_t t1;
    int64_t t2;
    int32_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    t2 = ((int64_t) (size_t) l1);
    l2 = (uint64_t) (int64_t) t2;
    l3 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_20: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t3 != INT32_C(0)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                if (t3 != INT32_C(-1)) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                    t2 = (((int64_t) (int32_t) t3) - INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_ekeys);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                    if (t2 == l1) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_evals);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                        return t1;
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l3 + l5);
                    l6 = (size_t) (int64_t) t2;
                    l7 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_mask;
                    t2 = (l6 & l7);
                    l3 = (size_t) (int64_t) t2;
                    goto loop_20;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t2 = (l3 + l5);
                l6 = (size_t) (int64_t) t2;
                l7 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_mask;
                t2 = (l6 & l7);
                l3 = (size_t) (int64_t) t2;
                goto loop_20;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
}

vader_box_t std_collections_get__usize__bool(void* l0, size_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    vader_box_t t1;
    int64_t t2;
    int32_t t3;
    bool t4;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    t2 = ((int64_t) (size_t) l1);
    l2 = (uint64_t) (int64_t) t2;
    l3 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_20: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t3 != INT32_C(0)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                if (t3 != INT32_C(-1)) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                    t2 = (((int64_t) (int32_t) t3) - INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_ekeys);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                    if (t2 == l1) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_evals);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_box_bool(7u, ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4]);
                        t4 = t1.payload.b;
                        t1 = vader_box_bool(7u, t4);
                        return t1;
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l3 + l5);
                    l6 = (size_t) (int64_t) t2;
                    l7 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_mask;
                    t2 = (l6 & l7);
                    l3 = (size_t) (int64_t) t2;
                    goto loop_20;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t2 = (l3 + l5);
                l6 = (size_t) (int64_t) t2;
                l7 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_mask;
                t2 = (l6 & l7);
                l3 = (size_t) (int64_t) t2;
                goto loop_20;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
}

vader_box_t std_collections_get__usize__i32(void* l0, size_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    vader_box_t t1;
    int64_t t2;
    int32_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    t2 = ((int64_t) (size_t) l1);
    l2 = (uint64_t) (int64_t) t2;
    l3 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_20: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t3 != INT32_C(0)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                if (t3 != INT32_C(-1)) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                    t2 = (((int64_t) (int32_t) t3) - INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_ekeys);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                    if (t2 == l1) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_evals);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                        t1 = vader_box_i32(3u, t3);
                        return t1;
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l3 + l5);
                    l6 = (size_t) (int64_t) t2;
                    l7 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_mask;
                    t2 = (l6 & l7);
                    l3 = (size_t) (int64_t) t2;
                    goto loop_20;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t2 = (l3 + l5);
                l6 = (size_t) (int64_t) t2;
                l7 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_mask;
                t2 = (l6 & l7);
                l3 = (size_t) (int64_t) t2;
                goto loop_20;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
}

vader_box_t std_collections_get__usize__string(void* l0, size_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l6, l7;
    size_t t0;
    vader_box_t t1;
    int64_t t2;
    int32_t t3;
    vader_string_t t4;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    t2 = ((int64_t) (size_t) l1);
    l2 = (uint64_t) (int64_t) t2;
    l3 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_20: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t3 != INT32_C(0)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                if (t3 != INT32_C(-1)) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                    t2 = (((int64_t) (int32_t) t3) - INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_ekeys);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                    if (t2 == l1) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_evals);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l4];
                        t4 = t1.payload.s;
                        t1 = vader_box_string(2u, t4);
                        return t1;
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l3 + l5);
                    l6 = (size_t) (int64_t) t2;
                    l7 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_mask;
                    t2 = (l6 & l7);
                    l3 = (size_t) (int64_t) t2;
                    goto loop_20;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t2 = (l3 + l5);
                l6 = (size_t) (int64_t) t2;
                l7 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_mask;
                t2 = (l6 & l7);
                l3 = (size_t) (int64_t) t2;
                goto loop_20;
            } else {
            }
        }
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
}

void* std_collections_keys__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType(void* l0) {
    void* l1 = NULL;
    size_t l2, l3;
    int32_t l4;
    int64_t t0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            l3 = ((vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l0)->f_size;
            if ((l2 < l3)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l0)->f_ekeys);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l2 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l2];
                vader_array_push_i32((vader_array_t*) l1, l4);
                t0 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t0;
                goto loop_12;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* std_collections_keys__string__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue(void* l0) {
    void* l1 = NULL;
    size_t l2, l3;
    vader_string_t l4;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(1u, 0u, 0u, 2u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__string__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            l3 = ((vader_struct_std_collections_MutableMap__string__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t*) l0)->f_size;
            if ((l2 < l3)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t*) l0)->f_ekeys);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l2 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l2];
                l4 = t0.payload.s;
                vader_array_push((vader_array_t*) l1, vader_box_string(2u, l4));
                t1 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t1;
                goto loop_12;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* std_collections_keys__string__LoweredModule(void* l0) {
    void* l1 = NULL;
    size_t l2, l3;
    vader_string_t l4;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(1u, 0u, 0u, 2u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__string__LoweredModule_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            l3 = ((vader_struct_std_collections_MutableMap__string__LoweredModule_t*) l0)->f_size;
            if ((l2 < l3)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__LoweredModule_t*) l0)->f_ekeys);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l2 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l2];
                l4 = t0.payload.s;
                vader_array_push((vader_array_t*) l1, vader_box_string(2u, l4));
                t1 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t1;
                goto loop_12;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* std_collections_keys__string__TypedProgram(void* l0) {
    void* l1 = NULL;
    size_t l2, l3;
    vader_string_t l4;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(1u, 0u, 0u, 2u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__string__TypedProgram_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            l3 = ((vader_struct_std_collections_MutableMap__string__TypedProgram_t*) l0)->f_size;
            if ((l2 < l3)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__TypedProgram_t*) l0)->f_ekeys);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l2 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l2];
                l4 = t0.payload.s;
                vader_array_push((vader_array_t*) l1, vader_box_string(2u, l4));
                t1 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t1;
                goto loop_12;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__i32__Any(void* l0, int32_t l1, vader_box_t l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__Any(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__i32__Any(l0, l3);
    } else {
    }
    t0 = ((int64_t) (int32_t) l1);
    l6 = (uint64_t) (int64_t) t0;
    l3 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_74: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_74;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_ref_store_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_74;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__Any_t*) l0);
    } else {
    }
    std_collections_write_entry__i32__Any(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__Any_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__i32__bool(void* l0, int32_t l1, bool l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__bool(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__i32__bool(l0, l3);
    } else {
    }
    t0 = ((int64_t) (int32_t) l1);
    l6 = (uint64_t) (int64_t) t0;
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_74: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_74;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (uint8_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_74;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__bool_t*) l0);
    } else {
    }
    std_collections_write_entry__i32__bool(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__bool_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__i32__i32(void* l0, int32_t l1, int32_t l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__i32(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__i32__i32(l0, l3);
    } else {
    }
    t0 = ((int64_t) (int32_t) l1);
    l6 = (uint64_t) (int64_t) t0;
    l3 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_74: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_74;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (int32_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_74;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__i32_t*) l0);
    } else {
    }
    std_collections_write_entry__i32__i32(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__i32_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__i32__string(void* l0, int32_t l1, vader_string_t l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__string(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__i32__string(l0, l3);
    } else {
    }
    t0 = ((int64_t) (int32_t) l1);
    l6 = (uint64_t) (int64_t) t0;
    l3 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_74: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_74;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l4] = vader_box_string(2u, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_74;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__string_t*) l0);
    } else {
    }
    std_collections_write_entry__i32__string(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__string_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__i32__usize(void* l0, int32_t l1, size_t l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i32__usize(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__i32__usize(l0, l3);
    } else {
    }
    t0 = ((int64_t) (int32_t) l1);
    l6 = (uint64_t) (int64_t) t0;
    l3 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_74: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_74;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t2 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (int64_t) (int64_t) (size_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_74;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__usize_t*) l0);
    } else {
    }
    std_collections_write_entry__i32__usize(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__usize_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__i64__Any(void* l0, int64_t l1, vader_box_t l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i64__Any(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__i64__Any(l0, l3);
    } else {
    }
    t0 = l1;
    l6 = (uint64_t) (int64_t) t0;
    l3 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_74: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_74;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_ref_store_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_74;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__Any_t*) l0);
    } else {
    }
    std_collections_write_entry__i64__Any(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__Any_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__i64__bool(void* l0, int64_t l1, bool l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__i64__bool(l0);
    l3 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__i64__bool(l0, l3);
    } else {
    }
    t0 = l1;
    l6 = (uint64_t) (int64_t) t0;
    l3 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_74: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_74;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (uint8_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_74;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__bool_t*) l0);
    } else {
    }
    std_collections_write_entry__i64__bool(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__bool_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__string__Any(void* l0, vader_string_t l1, vader_box_t l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4;
    vader_box_t* gc_roots[2] = { &l2, &t3 };
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__Any(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__string__Any(l0, l3);
    } else {
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_74: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_74;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_ref_store_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_74;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__Any_t*) l0);
    } else {
    }
    std_collections_write_entry__string__Any(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__Any_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__string__bool(void* l0, vader_string_t l1, bool l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__bool(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__string__bool(l0, l3);
    } else {
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_74: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_74;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (uint8_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_74;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__bool_t*) l0);
    } else {
    }
    std_collections_write_entry__string__bool(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__bool_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__string__i32(void* l0, vader_string_t l1, int32_t l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__i32(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__string__i32(l0, l3);
    } else {
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_74: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_74;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (int32_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_74;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i32_t*) l0);
    } else {
    }
    std_collections_write_entry__string__i32(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i32_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__string__i64(void* l0, vader_string_t l1, int64_t l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__i64(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__string__i64(l0, l3);
    } else {
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_74: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_74;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (int64_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_74;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i64_t*) l0);
    } else {
    }
    std_collections_write_entry__string__i64(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i64_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__string__string(void* l0, vader_string_t l1, vader_string_t l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__string(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__string__string(l0, l3);
    } else {
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_74: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_74;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l4] = vader_box_string(2u, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_74;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__string_t*) l0);
    } else {
    }
    std_collections_write_entry__string__string(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__string_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__string__usize(void* l0, vader_string_t l1, size_t l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__string__usize(l0);
    l3 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__string__usize(l0, l3);
    } else {
    }
    l6 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_74: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_74;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                t4 = t3.payload.s;
                if (t4 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (int64_t) (int64_t) (size_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_74;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__usize_t*) l0);
    } else {
    }
    std_collections_write_entry__string__usize(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__usize_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__u64__Any(void* l0, uint64_t l1, vader_box_t l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__u64__Any(l0);
    l3 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__u64__Any(l0, l3);
    } else {
    }
    l6 = l1;
    l3 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_73: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_73;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_ref_store_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_73;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__Any_t*) l0);
    } else {
    }
    std_collections_write_entry__u64__Any(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__Any_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__u64__usize(void* l0, uint64_t l1, size_t l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__u64__usize(l0);
    l3 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__u64__usize(l0, l3);
    } else {
    }
    l6 = l1;
    l3 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_73: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_73;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (int64_t) (int64_t) (size_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_73;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__usize_t*) l0);
    } else {
    }
    std_collections_write_entry__u64__usize(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__usize_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__usize__Any(void* l0, size_t l1, vader_box_t l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__usize__Any(l0);
    l3 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__usize__Any(l0, l3);
    } else {
    }
    t0 = ((int64_t) (size_t) l1);
    l6 = (uint64_t) (int64_t) t0;
    l3 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_74: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_74;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_ref_store_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_74;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__Any_t*) l0);
    } else {
    }
    std_collections_write_entry__usize__Any(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__Any_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__usize__bool(void* l0, size_t l1, bool l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__usize__bool(l0);
    l3 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__usize__bool(l0, l3);
    } else {
    }
    t0 = ((int64_t) (size_t) l1);
    l6 = (uint64_t) (int64_t) t0;
    l3 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_74: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_74;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (uint8_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_74;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__bool_t*) l0);
    } else {
    }
    std_collections_write_entry__usize__bool(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__bool_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__usize__i32(void* l0, size_t l1, int32_t l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__usize__i32(l0);
    l3 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__usize__i32(l0, l3);
    } else {
    }
    t0 = ((int64_t) (size_t) l1);
    l6 = (uint64_t) (int64_t) t0;
    l3 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_74: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_74;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4] = (int32_t) l2;
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_74;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__i32_t*) l0);
    } else {
    }
    std_collections_write_entry__usize__i32(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__i32_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_put__usize__string(void* l0, size_t l1, vader_string_t l2) {
    size_t l3, l4, l5, l8, l9;
    uint64_t l6;
    int64_t l7;
    void* l10 = NULL;
    int32_t l11;
    int64_t t0;
    size_t t1;
    int32_t t2;
    void** gc_raw_roots[2] = { &l0, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_collections_ensure_index__usize__string(l0);
    l3 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_size;
    l4 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_tombs;
    t0 = (((l3 + l4) + INT64_C(1)) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_mask;
    t0 = ((t1 + INT64_C(1)) * INT64_C(3));
    l4 = (size_t) (int64_t) t0;
    if ((l3 > l4)) {
        l3 = (size_t) (int64_t) INT64_C(16);
        {
            loop_30: {
                t1 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_size;
                t0 = ((t1 + INT64_C(1)) * INT64_C(4));
                l4 = (size_t) (int64_t) t0;
                t0 = (l3 * INT64_C(3));
                l5 = (size_t) (int64_t) t0;
                if ((l4 > l5)) {
                    t0 = (l3 * INT64_C(2));
                    l3 = (size_t) (int64_t) t0;
                    goto loop_30;
                } else {
                }
            }
        }
        std_collections_rehash__usize__string(l0, l3);
    } else {
    }
    t0 = ((int64_t) (size_t) l1);
    l6 = (uint64_t) (int64_t) t0;
    l3 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l6, l3);
    l7 = -(INT64_C(1));
    {
        loop_74: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t2 == INT32_C(-1)) {
                    if ((l7 < INT64_C(0))) {
                        l7 = ((int64_t) (size_t) l3);
                    } else {
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l5);
                    l8 = (size_t) (int64_t) t0;
                    l9 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_mask;
                    t0 = (l8 & l9);
                    l3 = (size_t) (int64_t) t0;
                    goto loop_74;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_index);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                t0 = (((int64_t) (int32_t) t2) - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_ekeys);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                if (t0 == l1) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_evals);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l4] = vader_box_string(2u, l2);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l5);
                l8 = (size_t) (int64_t) t0;
                l9 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_mask;
                t0 = (l8 & l9);
                l3 = (size_t) (int64_t) t0;
                goto loop_74;
            } else {
            }
        }
    }
    if ((l7 >= INT64_C(0))) {
        t0 = l7;
        l4 = (size_t) (int64_t) t0;
    } else {
        l4 = l3;
    }
    if ((l7 >= INT64_C(0))) {
        t1 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_tombs;
        t0 = (t1 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_tombs = l3;
        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__string_t*) l0);
    } else {
    }
    std_collections_write_entry__usize__string(l0, l1, l2);
    l10 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_index;
    t1 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_size;
    l11 = ((int32_t) (int64_t) (t1 + INT64_C(1)));
    vader_array_t* _a5_slotarr = ((vader_array_t*) l10);
    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
    if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (int32_t) l11;
    t1 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_size;
    t0 = (t1 + INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_size = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__string_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__i32__Any(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                l6 = std_collections_slot_for((uint64_t) (int64_t) ((int64_t) (int32_t) t1), l3);
                {
                    loop_45: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t1 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_45;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__Any_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__Any_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__Any_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__i32__bool(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                l6 = std_collections_slot_for((uint64_t) (int64_t) ((int64_t) (int32_t) t1), l3);
                {
                    loop_45: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t1 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_45;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__bool_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__i32__i32(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                l6 = std_collections_slot_for((uint64_t) (int64_t) ((int64_t) (int32_t) t1), l3);
                {
                    loop_45: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t1 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_45;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__i32_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__i32_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__i32_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__i32__string(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                l6 = std_collections_slot_for((uint64_t) (int64_t) ((int64_t) (int32_t) t1), l3);
                {
                    loop_45: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t1 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_45;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__string_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__string_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__string_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__i32__usize(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                l6 = std_collections_slot_for((uint64_t) (int64_t) ((int64_t) (int32_t) t1), l3);
                {
                    loop_45: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t1 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_45;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__usize_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__usize_t*) l0);
    ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__usize_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__i64__Any(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                l6 = std_collections_slot_for((uint64_t) (int64_t) t0, l3);
                {
                    loop_45: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t1 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_45;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__Any_t*) l0);
    ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__Any_t*) l0);
    ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__Any_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__i64__bool(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                l6 = std_collections_slot_for((uint64_t) (int64_t) t0, l3);
                {
                    loop_45: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t1 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_45;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i64__bool_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__string__Any(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2;
    uint64_t t3;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t2 = t1.payload.s;
                t3 = std_core_string_Hash_hash_vt(t2);
                l6 = std_collections_slot_for(t3, l3);
                {
                    loop_46: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t4 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t4 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_46;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__Any_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__Any_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__Any_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__string__bool(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2;
    uint64_t t3;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t2 = t1.payload.s;
                t3 = std_core_string_Hash_hash_vt(t2);
                l6 = std_collections_slot_for(t3, l3);
                {
                    loop_46: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t4 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t4 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_46;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__bool_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__string__i32(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2;
    uint64_t t3;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t2 = t1.payload.s;
                t3 = std_core_string_Hash_hash_vt(t2);
                l6 = std_collections_slot_for(t3, l3);
                {
                    loop_46: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t4 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t4 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_46;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i32_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i32_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i32_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__string__i64(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2;
    uint64_t t3;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t2 = t1.payload.s;
                t3 = std_core_string_Hash_hash_vt(t2);
                l6 = std_collections_slot_for(t3, l3);
                {
                    loop_46: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t4 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t4 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_46;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i64_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i64_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__i64_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__string__string(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2;
    uint64_t t3;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t2 = t1.payload.s;
                t3 = std_core_string_Hash_hash_vt(t2);
                l6 = std_collections_slot_for(t3, l3);
                {
                    loop_46: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t4 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t4 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_46;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__string_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__string_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__string_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__string__usize(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2;
    uint64_t t3;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t2 = t1.payload.s;
                t3 = std_core_string_Hash_hash_vt(t2);
                l6 = std_collections_slot_for(t3, l3);
                {
                    loop_46: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t4 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t4 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_46;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__usize_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__usize_t*) l0);
    ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__usize_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__u64__Any(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                l6 = std_collections_slot_for((uint64_t) (int64_t) t0, l3);
                {
                    loop_44: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t1 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_44;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__Any_t*) l0);
    ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__Any_t*) l0);
    ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__Any_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__u64__usize(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                l6 = std_collections_slot_for((uint64_t) (int64_t) t0, l3);
                {
                    loop_44: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t1 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_44;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__usize_t*) l0);
    ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__usize_t*) l0);
    ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__u64__usize_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__usize__Any(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                l6 = std_collections_slot_for((uint64_t) (int64_t) t0, l3);
                {
                    loop_45: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t1 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_45;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__Any_t*) l0);
    ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__Any_t*) l0);
    ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__Any_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__usize__bool(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                l6 = std_collections_slot_for((uint64_t) (int64_t) t0, l3);
                {
                    loop_45: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t1 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_45;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__bool_t*) l0);
    ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__bool_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__usize__i32(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                l6 = std_collections_slot_for((uint64_t) (int64_t) t0, l3);
                {
                    loop_45: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t1 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_45;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__i32_t*) l0);
    ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__i32_t*) l0);
    ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__i32_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_rehash__usize__string(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5, l6;
    int32_t l7;
    int64_t t0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 7u, 3u);
    l2 = (void*) _a0_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l3 < l1)) {
                vader_array_push_i32((vader_array_t*) l2, INT32_C(0));
                t0 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    t0 = (l1 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_29: {
            l5 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_size;
            if ((l4 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_ekeys);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                l6 = std_collections_slot_for((uint64_t) (int64_t) t0, l3);
                {
                    loop_45: {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                        if (t1 != INT32_C(0)) {
                            t0 = ((l6 + INT64_C(1)) & l3);
                            l6 = (size_t) (int64_t) t0;
                            goto loop_45;
                        } else {
                        }
                    }
                }
                l7 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_29;
            } else {
            }
        }
    }
    ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_index = l2;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__string_t*) l0);
    ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_mask = l3;
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__string_t*) l0);
    ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_tombs = (size_t) (int64_t) INT64_C(0);
    VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__usize__string_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

bool std_collections_remove__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l8, l15, l16, l17, l18, l19;
    int32_t l6, l7, l10, l14;
    void* l9;
    void* l11;
    void* l13;
    vader_box_t l12;
    size_t t0;
    int64_t t1;
    int32_t t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    t1 = ((int64_t) (int32_t) l1);
    l2 = (uint64_t) (int64_t) t1;
    l3 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_18: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                if (t2 != INT32_C(-1)) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                    t1 = (((int64_t) (int32_t) t2) - INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_ekeys);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                    if (t2 == l1) {
                        t0 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_size;
                        t1 = (t0 - INT64_C(1));
                        l5 = (size_t) (int64_t) t1;
                        if (l4 != l5) {
                            if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            l6 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
                            l7 = ((int32_t) (int64_t) (l5 + INT64_C(1)));
                            l8 = std_collections_slot_holding__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall(l0, l6, l7);
                            l9 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_ekeys;
                            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_ekeys);
                            if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                            if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                            l10 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
                            vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                            if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4] = (int32_t) l10;
                            l11 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_evals;
                            vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_evals);
                            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                            if ((size_t) l5 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                            l12 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                            vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
                            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                            if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                            vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4, l12.payload.obj);
                            VADER_WRITE_BARRIER(_a5_slotarr->buf);
                            l13 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_index;
                            l14 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                            vader_array_t* _a6_slotarr = ((vader_array_t*) l13);
                            if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                            if ((size_t) l8 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8] = (int32_t) l14;
                        } else {
                        }
                        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_index);
                        if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                        if ((size_t) l3 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l3] = (int32_t) INT32_C(-1);
                        t0 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_tombs;
                        t1 = (t0 + INT64_C(1));
                        l15 = (size_t) (int64_t) t1;
                        ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_tombs = l15;
                        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0);
                        t0 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_size;
                        t1 = (t0 - INT64_C(1));
                        l16 = (size_t) (int64_t) t1;
                        ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_size = l16;
                        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0);
                        return true;
                    }
                    l17 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l3 + l17);
                    l18 = (size_t) (int64_t) t1;
                    l19 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_mask;
                    t1 = (l18 & l19);
                    l3 = (size_t) (int64_t) t1;
                    goto loop_18;
                }
                l17 = (size_t) (int64_t) INT64_C(1);
                t1 = (l3 + l17);
                l18 = (size_t) (int64_t) t1;
                l19 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_mask;
                t1 = (l18 & l19);
                l3 = (size_t) (int64_t) t1;
                goto loop_18;
            } else {
            }
        }
    }
    return false;
}

bool std_collections_remove__i32__NarrowSlot(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l8, l15, l16, l17, l18, l19;
    int32_t l6, l7, l10, l14;
    void* l9;
    void* l11;
    void* l12;
    void* l13;
    size_t t0;
    int64_t t1;
    int32_t t2;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    t1 = ((int64_t) (int32_t) l1);
    l2 = (uint64_t) (int64_t) t1;
    l3 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_18: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                if (t2 != INT32_C(-1)) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                    t1 = (((int64_t) (int32_t) t2) - INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_ekeys);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                    if (t2 == l1) {
                        t0 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_size;
                        t1 = (t0 - INT64_C(1));
                        l5 = (size_t) (int64_t) t1;
                        if (l4 != l5) {
                            if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            l6 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
                            l7 = ((int32_t) (int64_t) (l5 + INT64_C(1)));
                            l8 = std_collections_slot_holding__i32__NarrowSlot(l0, l6, l7);
                            l9 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_ekeys;
                            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_ekeys);
                            if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                            if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                            l10 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
                            vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                            if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4] = (int32_t) l10;
                            l11 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_evals;
                            vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_evals);
                            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                            if ((size_t) l5 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                            l12 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                            vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
                            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                            if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                            vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4, l12);
                            VADER_WRITE_BARRIER(_a5_slotarr->buf);
                            l13 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_index;
                            l14 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                            vader_array_t* _a6_slotarr = ((vader_array_t*) l13);
                            if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                            if ((size_t) l8 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8] = (int32_t) l14;
                        } else {
                        }
                        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_index);
                        if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                        if ((size_t) l3 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l3] = (int32_t) INT32_C(-1);
                        t0 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_tombs;
                        t1 = (t0 + INT64_C(1));
                        l15 = (size_t) (int64_t) t1;
                        ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_tombs = l15;
                        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0);
                        t0 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_size;
                        t1 = (t0 - INT64_C(1));
                        l16 = (size_t) (int64_t) t1;
                        ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_size = l16;
                        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0);
                        return true;
                    }
                    l17 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l3 + l17);
                    l18 = (size_t) (int64_t) t1;
                    l19 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_mask;
                    t1 = (l18 & l19);
                    l3 = (size_t) (int64_t) t1;
                    goto loop_18;
                }
                l17 = (size_t) (int64_t) INT64_C(1);
                t1 = (l3 + l17);
                l18 = (size_t) (int64_t) t1;
                l19 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_mask;
                t1 = (l18 & l19);
                l3 = (size_t) (int64_t) t1;
                goto loop_18;
            } else {
            }
        }
    }
    return false;
}

bool std_collections_remove__i32__bool(void* l0, int32_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l8, l15, l16, l17, l18, l19;
    int32_t l6, l7, l10, l14;
    void* l9;
    void* l11;
    void* l13;
    bool l12;
    size_t t0;
    int64_t t1;
    int32_t t2;
    vader_box_t t3;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    t1 = ((int64_t) (int32_t) l1);
    l2 = (uint64_t) (int64_t) t1;
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_18: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t2 != INT32_C(0)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                if (t2 != INT32_C(-1)) {
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
                    t1 = (((int64_t) (int32_t) t2) - INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                    if (t2 == l1) {
                        t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
                        t1 = (t0 - INT64_C(1));
                        l5 = (size_t) (int64_t) t1;
                        if (l4 != l5) {
                            if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            l6 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
                            l7 = ((int32_t) (int64_t) (l5 + INT64_C(1)));
                            l8 = std_collections_slot_holding__i32__bool(l0, l6, l7);
                            l9 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys;
                            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys);
                            if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                            if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                            l10 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
                            vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                            if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4] = (int32_t) l10;
                            l11 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_evals;
                            vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_evals);
                            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                            if ((size_t) l5 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                            t3 = vader_box_bool(7u, ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l5]);
                            l12 = t3.payload.b;
                            vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
                            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                            if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4] = (uint8_t) l12;
                            l13 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index;
                            l14 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                            vader_array_t* _a6_slotarr = ((vader_array_t*) l13);
                            if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                            if ((size_t) l8 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8] = (int32_t) l14;
                        } else {
                        }
                        vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
                        if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                        if ((size_t) l3 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l3] = (int32_t) INT32_C(-1);
                        t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs;
                        t1 = (t0 + INT64_C(1));
                        l15 = (size_t) (int64_t) t1;
                        ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_tombs = l15;
                        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__bool_t*) l0);
                        t0 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
                        t1 = (t0 - INT64_C(1));
                        l16 = (size_t) (int64_t) t1;
                        ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size = l16;
                        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__i32__bool_t*) l0);
                        return true;
                    }
                    l17 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l3 + l17);
                    l18 = (size_t) (int64_t) t1;
                    l19 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
                    t1 = (l18 & l19);
                    l3 = (size_t) (int64_t) t1;
                    goto loop_18;
                }
                l17 = (size_t) (int64_t) INT64_C(1);
                t1 = (l3 + l17);
                l18 = (size_t) (int64_t) t1;
                l19 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
                t1 = (l18 & l19);
                l3 = (size_t) (int64_t) t1;
                goto loop_18;
            } else {
            }
        }
    }
    return false;
}

bool std_collections_remove__string__NarrowSlot(void* l0, vader_string_t l1) {
    uint64_t l2;
    size_t l3, l4, l5, l8, l15, l16, l17, l18, l19;
    vader_string_t l6, l10;
    int32_t l7, l14;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4;
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[5] = { &l0, &l9, &l11, &l12, &l13 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_index)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = std_core_string_Hash_hash_vt(l1);
    l3 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_mask;
    l3 = std_collections_slot_for(l2, l3);
    {
        loop_18: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
            if (t1 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3];
                if (t1 != INT32_C(-1)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_index);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
                    t2 = (((int64_t) (int32_t) t1) - INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_ekeys);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
                    t4 = t3.payload.s;
                    if (t4 == l1) {
                        t0 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_size;
                        t2 = (t0 - INT64_C(1));
                        l5 = (size_t) (int64_t) t2;
                        if (l4 != l5) {
                            vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_ekeys);
                            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                            if ((size_t) l5 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                            t3 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l5];
                            l6 = t3.payload.s;
                            l7 = ((int32_t) (int64_t) (l5 + INT64_C(1)));
                            l8 = std_collections_slot_holding__string__NarrowSlot(l0, l6, l7);
                            l9 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_ekeys;
                            vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_ekeys);
                            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                            if ((size_t) l5 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                            t3 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l5];
                            l10 = t3.payload.s;
                            vader_array_t* _a6_slotarr = ((vader_array_t*) l9);
                            if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                            if ((size_t) l4 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                            vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l4] = vader_box_string(2u, l10);
                            VADER_WRITE_BARRIER(_a6_slotarr->buf);
                            l11 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_evals;
                            vader_array_t* _a7_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_evals);
                            if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                            if ((size_t) l5 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                            l12 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l5);
                            vader_array_t* _a8_slotarr = ((vader_array_t*) l11);
                            if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                            if ((size_t) l4 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                            vader_array_ref_store(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l4, l12);
                            VADER_WRITE_BARRIER(_a8_slotarr->buf);
                            l13 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_index;
                            l14 = ((int32_t) (int64_t) (l4 + INT64_C(1)));
                            vader_array_t* _a9_slotarr = ((vader_array_t*) l13);
                            if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                            if ((size_t) l8 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l8] = (int32_t) l14;
                        } else {
                        }
                        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_index);
                        if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                        if ((size_t) l3 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l3] = (int32_t) INT32_C(-1);
                        t0 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_tombs;
                        t2 = (t0 + INT64_C(1));
                        l15 = (size_t) (int64_t) t2;
                        ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_tombs = l15;
                        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0);
                        t0 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_size;
                        t2 = (t0 - INT64_C(1));
                        l16 = (size_t) (int64_t) t2;
                        ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_size = l16;
                        VADER_WRITE_BARRIER((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0);
                        { vader_gc_top = gc_frame.prev; return true; }
                    }
                    l17 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l3 + l17);
                    l18 = (size_t) (int64_t) t2;
                    l19 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_mask;
                    t2 = (l18 & l19);
                    l3 = (size_t) (int64_t) t2;
                    goto loop_18;
                }
                l17 = (size_t) (int64_t) INT64_C(1);
                t2 = (l3 + l17);
                l18 = (size_t) (int64_t) t2;
                l19 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_mask;
                t2 = (l18 & l19);
                l3 = (size_t) (int64_t) t2;
                goto loop_18;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return false; }
    vader_gc_top = gc_frame.prev;
}

size_t std_collections_slot_for(uint64_t l0, size_t l1) {
    return (size_t) (int64_t) (((int64_t) (uint64_t) l0) & l1);
}

size_t std_collections_slot_holding__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall(void* l0, int32_t l1, int32_t l2) {
    uint64_t l3;
    size_t l4, l5, l6;
    int64_t t0;
    int32_t t1;
    size_t t2;
    t0 = ((int64_t) (int32_t) l1);
    l3 = (uint64_t) (int64_t) t0;
    l4 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_mask;
    l4 = std_collections_slot_for(l3, l4);
    {
        loop_11: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
            if (t1 != INT32_C(0)) {
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
                if (t1 == l2) {
                    return l4;
                }
                t0 = (l4 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                l6 = ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_mask;
                t0 = (l5 & l6);
                l4 = (size_t) (int64_t) t0;
                goto loop_11;
            } else {
            }
        }
    }
    t2 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__LoweredArrayLen___LoweredArrayLit___LoweredArrayPush___LoweredArraySlice___LoweredBinary___LoweredBlock___LoweredBoolLit___LoweredCall___LoweredCast___LoweredCellGet___LoweredCellNew___LoweredCharLit___LoweredDataConst___LoweredFieldAccess___LoweredFloatLit___LoweredIdent___LoweredIf___LoweredIndex___LoweredIntLit___LoweredIntrinsicCall___LoweredMakeClosure___LoweredNullLit___LoweredStringLit___LoweredStringSlice___LoweredStructLit___LoweredTypeCheck___LoweredTypeConst___LoweredUnary___LoweredUnreachable___LoweredVirtualCall_t*) l0)->f_index)->length;
    return t2;
}

size_t std_collections_slot_holding__i32__NarrowSlot(void* l0, int32_t l1, int32_t l2) {
    uint64_t l3;
    size_t l4, l5, l6;
    int64_t t0;
    int32_t t1;
    size_t t2;
    t0 = ((int64_t) (int32_t) l1);
    l3 = (uint64_t) (int64_t) t0;
    l4 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_mask;
    l4 = std_collections_slot_for(l3, l4);
    {
        loop_11: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
            if (t1 != INT32_C(0)) {
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
                if (t1 == l2) {
                    return l4;
                }
                t0 = (l4 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                l6 = ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_mask;
                t0 = (l5 & l6);
                l4 = (size_t) (int64_t) t0;
                goto loop_11;
            } else {
            }
        }
    }
    t2 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__NarrowSlot_t*) l0)->f_index)->length;
    return t2;
}

size_t std_collections_slot_holding__i32__bool(void* l0, int32_t l1, int32_t l2) {
    uint64_t l3;
    size_t l4, l5, l6;
    int64_t t0;
    int32_t t1;
    size_t t2;
    t0 = ((int64_t) (int32_t) l1);
    l3 = (uint64_t) (int64_t) t0;
    l4 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
    l4 = std_collections_slot_for(l3, l4);
    {
        loop_11: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
            if (t1 != INT32_C(0)) {
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
                if (t1 == l2) {
                    return l4;
                }
                t0 = (l4 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                l6 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_mask;
                t0 = (l5 & l6);
                l4 = (size_t) (int64_t) t0;
                goto loop_11;
            } else {
            }
        }
    }
    t2 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_index)->length;
    return t2;
}

size_t std_collections_slot_holding__string__NarrowSlot(void* l0, vader_string_t l1, int32_t l2) {
    uint64_t l3;
    size_t l4, l5, l6;
    int32_t t0;
    int64_t t1;
    size_t t2;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = std_core_string_Hash_hash_vt(l1);
    l4 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_mask;
    l4 = std_collections_slot_for(l3, l4);
    {
        loop_11: {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_index);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
            if (t0 != INT32_C(0)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_index);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                if (t0 == l2) {
                    { size_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
                }
                t1 = (l4 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                l6 = ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_mask;
                t1 = (l5 & l6);
                l4 = (size_t) (int64_t) t1;
                goto loop_11;
            } else {
            }
        }
    }
    t2 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__NarrowSlot_t*) l0)->f_index)->length;
    { size_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* std_collections_values__string__Symbol(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    size_t l2, l3;
    int64_t t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(90u, 0u, 13u, 91u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            l3 = ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l0)->f_size;
            if ((l2 < l3)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Symbol_t*) l0)->f_evals);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l2 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
                vader_array_push((vader_array_t*) l1, vader_ref_box(l4));
                t0 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t0;
                goto loop_12;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* std_collections_values__u64__Symbol(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    size_t l2, l3;
    int64_t t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(90u, 0u, 13u, 91u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections_MutableMap__u64__Symbol_t*) l0)->f_size;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l2 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            l3 = ((vader_struct_std_collections_MutableMap__u64__Symbol_t*) l0)->f_size;
            if ((l2 < l3)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Symbol_t*) l0)->f_evals);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l2 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
                vader_array_push((vader_array_t*) l1, vader_ref_box(l4));
                t0 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t0;
                goto loop_12;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__i32__Any(void* l0, int32_t l1, vader_box_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int32_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_ref_store_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
    } else {
        vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_ekeys, l1);
        vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__Any_t*) l0)->f_evals, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__i32__bool(void* l0, int32_t l1, bool l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int32_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (uint8_t) l2;
    } else {
        vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_ekeys, l1);
        vader_array_push_bool((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__bool_t*) l0)->f_evals, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__i32__i32(void* l0, int32_t l1, int32_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int32_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int32_t) l2;
    } else {
        vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_ekeys, l1);
        vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__i32_t*) l0)->f_evals, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__i32__string(void* l0, int32_t l1, vader_string_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int32_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3] = vader_box_string(2u, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
    } else {
        vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_ekeys, l1);
        vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__string_t*) l0)->f_evals, vader_box_string(2u, l2));
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__i32__usize(void* l0, int32_t l1, size_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int32_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (size_t) l2;
    } else {
        vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_ekeys, l1);
        vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__i32__usize_t*) l0)->f_evals, (int64_t) (size_t) l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__i64__Any(void* l0, int64_t l1, vader_box_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_ref_store_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
    } else {
        vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_ekeys, l1);
        vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__Any_t*) l0)->f_evals, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__i64__bool(void* l0, int64_t l1, bool l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (uint8_t) l2;
    } else {
        vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_ekeys, l1);
        vader_array_push_bool((vader_array_t*) ((vader_struct_std_collections_MutableMap__i64__bool_t*) l0)->f_evals, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__string__Any(void* l0, vader_string_t l1, vader_box_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(2u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_ref_store_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
    } else {
        vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_ekeys, vader_box_string(2u, l1));
        vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__Any_t*) l0)->f_evals, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__string__bool(void* l0, vader_string_t l1, bool l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(2u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (uint8_t) l2;
    } else {
        vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_ekeys, vader_box_string(2u, l1));
        vader_array_push_bool((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__bool_t*) l0)->f_evals, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__string__i32(void* l0, vader_string_t l1, int32_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(2u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int32_t) l2;
    } else {
        vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_ekeys, vader_box_string(2u, l1));
        vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i32_t*) l0)->f_evals, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__string__i64(void* l0, vader_string_t l1, int64_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(2u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int64_t) l2;
    } else {
        vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_ekeys, vader_box_string(2u, l1));
        vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__i64_t*) l0)->f_evals, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__string__string(void* l0, vader_string_t l1, vader_string_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(2u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3] = vader_box_string(2u, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
    } else {
        vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_ekeys, vader_box_string(2u, l1));
        vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__string_t*) l0)->f_evals, vader_box_string(2u, l2));
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__string__usize(void* l0, vader_string_t l1, size_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3] = vader_box_string(2u, l1);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        l5 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (size_t) l2;
    } else {
        vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_ekeys, vader_box_string(2u, l1));
        vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__string__usize_t*) l0)->f_evals, (int64_t) (size_t) l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__u64__Any(void* l0, uint64_t l1, vader_box_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (uint64_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_ref_store_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
    } else {
        vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_ekeys, (int64_t) (uint64_t) l1);
        vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__Any_t*) l0)->f_evals, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__u64__usize(void* l0, uint64_t l1, size_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (uint64_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (size_t) l2;
    } else {
        vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_ekeys, (int64_t) (uint64_t) l1);
        vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__u64__usize_t*) l0)->f_evals, (int64_t) (size_t) l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__usize__Any(void* l0, size_t l1, vader_box_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (size_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_ref_store_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
    } else {
        vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_ekeys, (int64_t) (size_t) l1);
        vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__Any_t*) l0)->f_evals, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__usize__bool(void* l0, size_t l1, bool l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (size_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (uint8_t) l2;
    } else {
        vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_ekeys, (int64_t) (size_t) l1);
        vader_array_push_bool((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__bool_t*) l0)->f_evals, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__usize__i32(void* l0, size_t l1, int32_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (size_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (int32_t) l2;
    } else {
        vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_ekeys, (int64_t) (size_t) l1);
        vader_array_push_i32((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__i32_t*) l0)->f_evals, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_collections_write_entry__usize__string(void* l0, size_t l1, vader_string_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_size;
    l4 = ((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_ekeys)->length;
    if ((l3 < l4)) {
        l5 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_ekeys;
        l3 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_size;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3] = (int64_t) (int64_t) (size_t) l1;
        l5 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_evals;
        l3 = ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_size;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3] = vader_box_string(2u, l2);
        VADER_WRITE_BARRIER(_a1_slotarr->buf);
    } else {
        vader_array_push_i64((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_ekeys, (int64_t) (size_t) l1);
        vader_array_push((vader_array_t*) ((vader_struct_std_collections_MutableMap__usize__string_t*) l0)->f_evals, vader_box_string(2u, l2));
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

