#include "bootstrap.split.h"

static void std_sort_insertion_sort_range__Any(void* l0, size_t l1, size_t l2, void* l3);
static void std_sort_insertion_sort_range__i32(void* l0, size_t l1, size_t l2, void* l3);
static void std_sort_insertion_sort_range__string(void* l0, size_t l1, size_t l2, void* l3);
static void std_sort_insertion_sort_range__usize(void* l0, size_t l1, size_t l2, void* l3);
static void std_sort_merge_sort_range__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType(void* l0, void* l1, size_t l2, size_t l3, void* l4);
static void std_sort_merge_sort_range__i32(void* l0, void* l1, size_t l2, size_t l3, void* l4);
static void std_sort_merge_sort_range__string(void* l0, void* l1, size_t l2, size_t l3, void* l4);
static void std_sort_merge_sort_range__usize(void* l0, void* l1, size_t l2, size_t l3, void* l4);

static void std_sort_insertion_sort_range__Any(void* l0, size_t l1, size_t l2, void* l3) {
    size_t l4, l6, l8, l10;
    vader_box_t l5 = vader_box_null(), l9 = vader_box_null(), l11 = vader_box_null();
    bool l7;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l5, &l9, &l11, &t1 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (l1 + INT64_C(1));
    l4 = (size_t) (int64_t) t0;
    {
        loop_5: {
            if ((l4 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                l6 = l4;
                {
                    loop_17: {
                        if ((l6 > l1)) {
                            t0 = (l6 - INT64_C(1));
                            l8 = (size_t) (int64_t) t0;
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l8 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            l9 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
                            vader_fn_t* _a2_fnobj = (vader_fn_t*) l3;
                            t1 = ((vader_fn_erased_sig_2_t) _a2_fnobj->code)(_a2_fnobj->env, l5, l9);
                            l7 = t1.payload.b;
                        } else {
                            l7 = false;
                        }
                        if (l7) {
                            t0 = (l6 - INT64_C(1));
                            l10 = (size_t) (int64_t) t0;
                            vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                            if ((size_t) l10 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            l11 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l10);
                            if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            vader_array_ref_store_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6, l11);
                            VADER_WRITE_BARRIER(_a3_slotarr->buf);
                            t0 = (l6 - INT64_C(1));
                            l6 = (size_t) (int64_t) t0;
                            goto loop_17;
                        } else {
                        }
                    }
                }
                vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l6 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                vader_array_ref_store_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l6, l5);
                VADER_WRITE_BARRIER(_a4_slotarr->buf);
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void std_sort_insertion_sort_range__i32(void* l0, size_t l1, size_t l2, void* l3) {
    size_t l4, l6, l8, l10;
    int32_t l5, l9, l11;
    bool l7;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (l1 + INT64_C(1));
    l4 = (size_t) (int64_t) t0;
    {
        loop_5: {
            if ((l4 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
                l6 = l4;
                {
                    loop_17: {
                        if ((l6 > l1)) {
                            t0 = (l6 - INT64_C(1));
                            l8 = (size_t) (int64_t) t0;
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l8 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            l9 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8];
                            vader_fn_t* _a2_fnobj = (vader_fn_t*) l3;
                            t1 = ((vader_fn_erased_sig_2_t) _a2_fnobj->code)(_a2_fnobj->env, vader_box_i32(166u, l5), vader_box_i32(166u, l9));
                            l7 = t1.payload.b;
                        } else {
                            l7 = false;
                        }
                        if (l7) {
                            t0 = (l6 - INT64_C(1));
                            l10 = (size_t) (int64_t) t0;
                            vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                            if ((size_t) l10 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            l11 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l10];
                            if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l11;
                            t0 = (l6 - INT64_C(1));
                            l6 = (size_t) (int64_t) t0;
                            goto loop_17;
                        } else {
                        }
                    }
                }
                vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l6 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l6] = (int32_t) l5;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void std_sort_insertion_sort_range__string(void* l0, size_t l1, size_t l2, void* l3) {
    size_t l4, l6, l8, l10;
    vader_string_t l5, l9, l11;
    bool l7;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (l1 + INT64_C(1));
    l4 = (size_t) (int64_t) t0;
    {
        loop_5: {
            if ((l4 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l4];
                l5 = t1.payload.s;
                l6 = l4;
                {
                    loop_18: {
                        if ((l6 > l1)) {
                            t0 = (l6 - INT64_C(1));
                            l8 = (size_t) (int64_t) t0;
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l8 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l8];
                            l9 = t1.payload.s;
                            vader_fn_t* _a2_fnobj = (vader_fn_t*) l3;
                            t1 = ((vader_fn_erased_sig_2_t) _a2_fnobj->code)(_a2_fnobj->env, vader_box_string(163u, l5), vader_box_string(163u, l9));
                            l7 = t1.payload.b;
                        } else {
                            l7 = false;
                        }
                        if (l7) {
                            t0 = (l6 - INT64_C(1));
                            l10 = (size_t) (int64_t) t0;
                            vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                            if ((size_t) l10 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            t1 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l10];
                            l11 = t1.payload.s;
                            if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l6] = vader_box_string(163u, l11);
                            VADER_WRITE_BARRIER(_a3_slotarr->buf);
                            t0 = (l6 - INT64_C(1));
                            l6 = (size_t) (int64_t) t0;
                            goto loop_18;
                        } else {
                        }
                    }
                }
                vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l6 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l6] = vader_box_string(163u, l5);
                VADER_WRITE_BARRIER(_a4_slotarr->buf);
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void std_sort_insertion_sort_range__usize(void* l0, size_t l1, size_t l2, void* l3) {
    size_t l4, l5, l6, l8, l9, l10, l11;
    bool l7;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (l1 + INT64_C(1));
    l4 = (size_t) (int64_t) t0;
    {
        loop_5: {
            if ((l4 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
                l5 = (size_t) (int64_t) t0;
                l6 = l4;
                {
                    loop_17: {
                        if ((l6 > l1)) {
                            t0 = (l6 - INT64_C(1));
                            l8 = (size_t) (int64_t) t0;
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l8 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8];
                            l9 = (size_t) (int64_t) t0;
                            vader_fn_t* _a2_fnobj = (vader_fn_t*) l3;
                            t1 = ((vader_fn_erased_sig_2_t) _a2_fnobj->code)(_a2_fnobj->env, vader_box_i64(172u, (int64_t)(uint64_t) l5), vader_box_i64(172u, (int64_t)(uint64_t) l9));
                            l7 = t1.payload.b;
                        } else {
                            l7 = false;
                        }
                        if (l7) {
                            t0 = (l6 - INT64_C(1));
                            l10 = (size_t) (int64_t) t0;
                            vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                            if ((size_t) l10 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            t0 = ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l10];
                            l11 = (size_t) (int64_t) t0;
                            if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int64_t) (int64_t) (size_t) l11;
                            t0 = (l6 - INT64_C(1));
                            l6 = (size_t) (int64_t) t0;
                            goto loop_17;
                        } else {
                        }
                    }
                }
                vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l6 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l6] = (int64_t) (int64_t) (size_t) l5;
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void std_sort_merge_sort_range__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType(void* l0, void* l1, size_t l2, size_t l3, void* l4) {
    size_t l5, l6, l8, l9;
    vader_box_t l7 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null(), l14 = vader_box_null();
    int64_t t0;
    uint64_t t1;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[7] = { &l7, &l10, &l11, &l12, &l13, &l14, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 7u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (l3 - l2);
    l5 = (size_t) (int64_t) t0;
    if ((l5 < INT64_C(2))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if ((l5 <= INT64_C(16))) {
        std_sort_insertion_sort_range__Any(l0, l2, l3, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = vader_div_u64(l5, INT64_C(2));
    l5 = (size_t) (uint64_t) t1;
    t0 = (l2 + l5);
    l5 = (size_t) (int64_t) t0;
    std_sort_merge_sort_range__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType(l0, l1, l2, l5, l4);
    std_sort_merge_sort_range__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType(l0, l1, l5, l3, l4);
    l6 = l2;
    {
        loop_43: {
            if ((l6 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
                vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                vader_array_ref_store_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6, l7);
                VADER_WRITE_BARRIER(_a1_slotarr->buf);
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_43;
            } else {
            }
        }
    }
    l6 = l2;
    l8 = l5;
    l9 = l2;
    {
        loop_72: {
            if ((l9 < l3)) {
                if ((l6 >= l5)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l8 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l9 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_ref_store_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9, l7);
                    VADER_WRITE_BARRIER(_a3_slotarr->buf);
                    t0 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t0;
                } else {
                    if ((l8 >= l3)) {
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                        if ((size_t) l6 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                        l10 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l6);
                        vader_array_t* _a5_slotarr = ((vader_array_t*) l0);
                        if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                        if ((size_t) l9 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                        vader_array_ref_store_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9, l10);
                        VADER_WRITE_BARRIER(_a5_slotarr->buf);
                        t0 = (l6 + INT64_C(1));
                        l6 = (size_t) (int64_t) t0;
                    } else {
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l1);
                        if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                        if ((size_t) l8 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                        l11 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l8);
                        if ((size_t) l6 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                        l12 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
                        vader_fn_t* _a7_fnobj = (vader_fn_t*) l4;
                        t2 = ((vader_fn_erased_sig_2_t) _a7_fnobj->code)(_a7_fnobj->env, l11, l12);
                        t3 = t2.payload.b;
                        if (t3) {
                            vader_array_t* _a8_slotarr = ((vader_array_t*) l1);
                            if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                            if ((size_t) l8 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                            l13 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l8);
                            vader_array_t* _a9_slotarr = ((vader_array_t*) l0);
                            if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                            if ((size_t) l9 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                            vader_array_ref_store_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l9, l13);
                            VADER_WRITE_BARRIER(_a9_slotarr->buf);
                            t0 = (l8 + INT64_C(1));
                            l8 = (size_t) (int64_t) t0;
                        } else {
                            vader_array_t* _a10_slotarr = ((vader_array_t*) l1);
                            if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                            if ((size_t) l6 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                            l14 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l6);
                            vader_array_t* _a11_slotarr = ((vader_array_t*) l0);
                            if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                            if ((size_t) l9 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                            vader_array_ref_store_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l9, l14);
                            VADER_WRITE_BARRIER(_a11_slotarr->buf);
                            t0 = (l6 + INT64_C(1));
                            l6 = (size_t) (int64_t) t0;
                        }
                    }
                }
                t0 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t0;
                goto loop_72;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void std_sort_merge_sort_range__i32(void* l0, void* l1, size_t l2, size_t l3, void* l4) {
    size_t l5, l6, l8, l9;
    int32_t l7, l10, l11, l12, l13, l14;
    int64_t t0;
    uint64_t t1;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (l3 - l2);
    l5 = (size_t) (int64_t) t0;
    if ((l5 < INT64_C(2))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if ((l5 <= INT64_C(16))) {
        std_sort_insertion_sort_range__i32(l0, l2, l3, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = vader_div_u64(l5, INT64_C(2));
    l5 = (size_t) (uint64_t) t1;
    t0 = (l2 + l5);
    l5 = (size_t) (int64_t) t0;
    std_sort_merge_sort_range__i32(l0, l1, l2, l5, l4);
    std_sort_merge_sort_range__i32(l0, l1, l5, l3, l4);
    l6 = l2;
    {
        loop_43: {
            if ((l6 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6];
                vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6] = (int32_t) l7;
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_43;
            } else {
            }
        }
    }
    l6 = l2;
    l8 = l5;
    l9 = l2;
    {
        loop_72: {
            if ((l9 < l3)) {
                if ((l6 >= l5)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l8 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    l7 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l8];
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l9 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l9] = (int32_t) l7;
                    t0 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t0;
                } else {
                    if ((l8 >= l3)) {
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                        if ((size_t) l6 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                        l10 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l6];
                        vader_array_t* _a5_slotarr = ((vader_array_t*) l0);
                        if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                        if ((size_t) l9 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l9] = (int32_t) l10;
                        t0 = (l6 + INT64_C(1));
                        l6 = (size_t) (int64_t) t0;
                    } else {
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l1);
                        if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                        if ((size_t) l8 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                        l11 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8];
                        if ((size_t) l6 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                        l12 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l6];
                        vader_fn_t* _a7_fnobj = (vader_fn_t*) l4;
                        t2 = ((vader_fn_erased_sig_2_t) _a7_fnobj->code)(_a7_fnobj->env, vader_box_i32(166u, l11), vader_box_i32(166u, l12));
                        t3 = t2.payload.b;
                        if (t3) {
                            vader_array_t* _a8_slotarr = ((vader_array_t*) l1);
                            if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                            if ((size_t) l8 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                            l13 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l8];
                            vader_array_t* _a9_slotarr = ((vader_array_t*) l0);
                            if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                            if ((size_t) l9 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l9] = (int32_t) l13;
                            t0 = (l8 + INT64_C(1));
                            l8 = (size_t) (int64_t) t0;
                        } else {
                            vader_array_t* _a10_slotarr = ((vader_array_t*) l1);
                            if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                            if ((size_t) l6 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                            l14 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l6];
                            vader_array_t* _a11_slotarr = ((vader_array_t*) l0);
                            if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                            if ((size_t) l9 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l9] = (int32_t) l14;
                            t0 = (l6 + INT64_C(1));
                            l6 = (size_t) (int64_t) t0;
                        }
                    }
                }
                t0 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t0;
                goto loop_72;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void std_sort_merge_sort_range__string(void* l0, void* l1, size_t l2, size_t l3, void* l4) {
    size_t l5, l6, l8, l9;
    vader_string_t l7, l10, l11, l12, l13, l14;
    int64_t t0;
    uint64_t t1;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (l3 - l2);
    l5 = (size_t) (int64_t) t0;
    if ((l5 < INT64_C(2))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if ((l5 <= INT64_C(16))) {
        std_sort_insertion_sort_range__string(l0, l2, l3, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = vader_div_u64(l5, INT64_C(2));
    l5 = (size_t) (uint64_t) t1;
    t0 = (l2 + l5);
    l5 = (size_t) (int64_t) t0;
    std_sort_merge_sort_range__string(l0, l1, l2, l5, l4);
    std_sort_merge_sort_range__string(l0, l1, l5, l3, l4);
    l6 = l2;
    {
        loop_43: {
            if ((l6 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l6];
                l7 = t2.payload.s;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l6] = vader_box_string(163u, l7);
                VADER_WRITE_BARRIER(_a1_slotarr->buf);
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_43;
            } else {
            }
        }
    }
    l6 = l2;
    l8 = l5;
    l9 = l2;
    {
        loop_73: {
            if ((l9 < l3)) {
                if ((l6 >= l5)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l8 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l8];
                    l7 = t2.payload.s;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l9 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l9] = vader_box_string(163u, l7);
                    VADER_WRITE_BARRIER(_a3_slotarr->buf);
                    t0 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t0;
                } else {
                    if ((l8 >= l3)) {
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                        if ((size_t) l6 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                        t2 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l6];
                        l10 = t2.payload.s;
                        vader_array_t* _a5_slotarr = ((vader_array_t*) l0);
                        if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                        if ((size_t) l9 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                        vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l9] = vader_box_string(163u, l10);
                        VADER_WRITE_BARRIER(_a5_slotarr->buf);
                        t0 = (l6 + INT64_C(1));
                        l6 = (size_t) (int64_t) t0;
                    } else {
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l1);
                        if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                        if ((size_t) l8 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                        t2 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l8];
                        l11 = t2.payload.s;
                        if ((size_t) l6 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                        t2 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l6];
                        l12 = t2.payload.s;
                        vader_fn_t* _a7_fnobj = (vader_fn_t*) l4;
                        t2 = ((vader_fn_erased_sig_2_t) _a7_fnobj->code)(_a7_fnobj->env, vader_box_string(163u, l11), vader_box_string(163u, l12));
                        t3 = t2.payload.b;
                        if (t3) {
                            vader_array_t* _a8_slotarr = ((vader_array_t*) l1);
                            if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                            if ((size_t) l8 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = vader_array_box_slots(_a8_slotarr->buf)[_a8_slotarr->offset + (size_t) l8];
                            l13 = t2.payload.s;
                            vader_array_t* _a9_slotarr = ((vader_array_t*) l0);
                            if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                            if ((size_t) l9 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                            vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l9] = vader_box_string(163u, l13);
                            VADER_WRITE_BARRIER(_a9_slotarr->buf);
                            t0 = (l8 + INT64_C(1));
                            l8 = (size_t) (int64_t) t0;
                        } else {
                            vader_array_t* _a10_slotarr = ((vader_array_t*) l1);
                            if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                            if ((size_t) l6 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = vader_array_box_slots(_a10_slotarr->buf)[_a10_slotarr->offset + (size_t) l6];
                            l14 = t2.payload.s;
                            vader_array_t* _a11_slotarr = ((vader_array_t*) l0);
                            if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                            if ((size_t) l9 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                            vader_array_box_slots(_a11_slotarr->buf)[_a11_slotarr->offset + (size_t) l9] = vader_box_string(163u, l14);
                            VADER_WRITE_BARRIER(_a11_slotarr->buf);
                            t0 = (l6 + INT64_C(1));
                            l6 = (size_t) (int64_t) t0;
                        }
                    }
                }
                t0 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t0;
                goto loop_73;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void std_sort_merge_sort_range__usize(void* l0, void* l1, size_t l2, size_t l3, void* l4) {
    size_t l5, l6, l7, l8, l9, l10, l11, l12, l13, l14;
    int64_t t0;
    uint64_t t1;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (l3 - l2);
    l5 = (size_t) (int64_t) t0;
    if ((l5 < INT64_C(2))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if ((l5 <= INT64_C(16))) {
        std_sort_insertion_sort_range__usize(l0, l2, l3, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = vader_div_u64(l5, INT64_C(2));
    l5 = (size_t) (uint64_t) t1;
    t0 = (l2 + l5);
    l5 = (size_t) (int64_t) t0;
    std_sort_merge_sort_range__usize(l0, l1, l2, l5, l4);
    std_sort_merge_sort_range__usize(l0, l1, l5, l3, l4);
    l6 = l2;
    {
        loop_43: {
            if ((l6 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6];
                l7 = (size_t) (int64_t) t0;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6] = (int64_t) (int64_t) (size_t) l7;
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_43;
            } else {
            }
        }
    }
    l6 = l2;
    l7 = l5;
    l8 = l2;
    {
        loop_72: {
            if ((l8 < l3)) {
                if ((l6 >= l5)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l7 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l7];
                    l9 = (size_t) (int64_t) t0;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l8 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int64_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l8] = (int64_t) (int64_t) (size_t) l9;
                    t0 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t0;
                } else {
                    if ((l7 >= l3)) {
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                        if ((size_t) l6 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                        t0 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l6];
                        l10 = (size_t) (int64_t) t0;
                        vader_array_t* _a5_slotarr = ((vader_array_t*) l0);
                        if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                        if ((size_t) l8 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((int64_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l8] = (int64_t) (int64_t) (size_t) l10;
                        t0 = (l6 + INT64_C(1));
                        l6 = (size_t) (int64_t) t0;
                    } else {
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l1);
                        if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                        if ((size_t) l7 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                        t0 = ((int64_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l7];
                        l11 = (size_t) (int64_t) t0;
                        if ((size_t) l6 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                        t0 = ((int64_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l6];
                        l12 = (size_t) (int64_t) t0;
                        vader_fn_t* _a7_fnobj = (vader_fn_t*) l4;
                        t2 = ((vader_fn_erased_sig_2_t) _a7_fnobj->code)(_a7_fnobj->env, vader_box_i64(172u, (int64_t)(uint64_t) l11), vader_box_i64(172u, (int64_t)(uint64_t) l12));
                        t3 = t2.payload.b;
                        if (t3) {
                            vader_array_t* _a8_slotarr = ((vader_array_t*) l1);
                            if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                            if ((size_t) l7 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                            t0 = ((int64_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l7];
                            l13 = (size_t) (int64_t) t0;
                            vader_array_t* _a9_slotarr = ((vader_array_t*) l0);
                            if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                            if ((size_t) l8 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int64_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l8] = (int64_t) (int64_t) (size_t) l13;
                            t0 = (l7 + INT64_C(1));
                            l7 = (size_t) (int64_t) t0;
                        } else {
                            vader_array_t* _a10_slotarr = ((vader_array_t*) l1);
                            if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                            if ((size_t) l6 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                            t0 = ((int64_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l6];
                            l14 = (size_t) (int64_t) t0;
                            vader_array_t* _a11_slotarr = ((vader_array_t*) l0);
                            if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                            if ((size_t) l8 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int64_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l8] = (int64_t) (int64_t) (size_t) l14;
                            t0 = (l6 + INT64_C(1));
                            l6 = (size_t) (int64_t) t0;
                        }
                    }
                }
                t0 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t0;
                goto loop_72;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void* std_sort_sort__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType(void* l0, void* l1) {
    size_t l2;
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) l0)->length;
    l3 = std_iter_clone__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType(l0);
    if ((l2 < INT64_C(2))) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = std_iter_clone__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType(l0);
    std_sort_merge_sort_range__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType(l3, l4, (size_t) (int64_t) INT64_C(0), l2, l1);
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* std_sort_sort__Diagnostic(void* l0, void* l1) {
    size_t l2;
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) l0)->length;
    l3 = std_iter_clone__Diagnostic(l0);
    if ((l2 < INT64_C(2))) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = std_iter_clone__Diagnostic(l0);
    std_sort_merge_sort_range__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType(l3, l4, (size_t) (int64_t) INT64_C(0), l2, l1);
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* std_sort_sort__GenericInstance(void* l0, void* l1) {
    size_t l2;
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) l0)->length;
    l3 = std_iter_clone__GenericInstance(l0);
    if ((l2 < INT64_C(2))) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = std_iter_clone__GenericInstance(l0);
    std_sort_merge_sort_range__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType(l3, l4, (size_t) (int64_t) INT64_C(0), l2, l1);
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* std_sort_sort__PendingFnInstance(void* l0, void* l1) {
    size_t l2;
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) l0)->length;
    l3 = std_iter_clone__PendingFnInstance(l0);
    if ((l2 < INT64_C(2))) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = std_iter_clone__PendingFnInstance(l0);
    std_sort_merge_sort_range__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType(l3, l4, (size_t) (int64_t) INT64_C(0), l2, l1);
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* std_sort_sort__Symbol(void* l0, void* l1) {
    size_t l2;
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) l0)->length;
    l3 = std_iter_clone__Symbol(l0);
    if ((l2 < INT64_C(2))) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = std_iter_clone__Symbol(l0);
    std_sort_merge_sort_range__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType(l3, l4, (size_t) (int64_t) INT64_C(0), l2, l1);
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* std_sort_sort__i32(void* l0, void* l1) {
    size_t l2;
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) l0)->length;
    l3 = std_iter_clone__i32(l0);
    if ((l2 < INT64_C(2))) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = std_iter_clone__i32(l0);
    std_sort_merge_sort_range__i32(l3, l4, (size_t) (int64_t) INT64_C(0), l2, l1);
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* std_sort_sort__string(void* l0, void* l1) {
    size_t l2;
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) l0)->length;
    l3 = std_iter_clone__string(l0);
    if ((l2 < INT64_C(2))) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = std_iter_clone__string(l0);
    std_sort_merge_sort_range__string(l3, l4, (size_t) (int64_t) INT64_C(0), l2, l1);
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* std_sort_sort__usize(void* l0, void* l1) {
    size_t l2;
    void* l3 = NULL;
    void* l4 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) l0)->length;
    l3 = std_iter_clone__usize(l0);
    if ((l2 < INT64_C(2))) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = std_iter_clone__usize(l0);
    std_sort_merge_sort_range__usize(l3, l4, (size_t) (int64_t) INT64_C(0), l2, l1);
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

