#include "bootstrap.split.h"

static vader_box_t vader_core_bytecode$c_field_align_at(void* l0, void* l1, int32_t l2);
static vader_box_t vader_core_bytecode$c_field_width_at(void* l0, void* l1, int32_t l2);
static void* vader_core_bytecode$c_struct_layout_at(void* l0, void* l1, int32_t l2);
static int64_t vader_core_bytecode$cell_value(uint8_t l0, int64_t l1);
static void* vader_core_bytecode$effect(int64_t l0, int64_t l1);
static bool vader_core_bytecode$in_range(int32_t l0, int64_t l1);
static vader_box_t vader_core_bytecode$indexed_effect(int32_t l0, int64_t l1, int64_t l2, int64_t l3);
static vader_box_t vader_core_bytecode$indirect_effect(void* l0, int32_t l1);
static int64_t vader_core_bytecode$integer_bits(uint8_t l0);
static vader_box_t vader_core_bytecode$integer_op(uint8_t l0, int64_t l1, bool l2, int64_t l3, int64_t l4);
static vader_string_t vader_core_bytecode$key_join(void* l0, void* l1, vader_string_t l2);
static vader_string_t vader_core_bytecode$member_name(uint8_t l0);
static vader_box_t vader_core_bytecode$struct_new_effect(void* l0, int32_t l1);
static int64_t vader_core_bytecode$value_cell(uint8_t l0, int64_t l1);

uint8_t vader_core_bytecode$array_kind_from_name(vader_string_t l0) {
    uint8_t l1;
    if (l0 == 3333u) {
        l1 = (uint8_t) 1;
        return l1;
    }
    if (l0 == 3312u) {
        l1 = (uint8_t) 2;
    } else if (l0 == 3313u) {
        l1 = (uint8_t) 3;
    } else if (l0 == 3323u) {
        l1 = (uint8_t) 4;
    } else if (l0 == 2597u) {
        l1 = (uint8_t) 5;
    } else if (l0 == 2552u) {
        l1 = (uint8_t) 6;
    } else if (l0 == 2553u) {
        l1 = (uint8_t) 7;
    } else if (l0 == 2575u) {
        l1 = (uint8_t) 8;
    } else if (l0 == 2407u) {
        l1 = (uint8_t) 9;
    } else if (l0 == 2409u) {
        l1 = (uint8_t) 10;
    } else if (l0 == 2165u) {
        l1 = (uint8_t) 11;
    } else if (l0 == 2027u) {
        l1 = (uint8_t) 12;
    } else if (l0 == 3010u) {
        l1 = (uint8_t) 13;
    } else {
        l1 = (uint8_t) 0;
    }
    return l1;
}

int32_t vader_core_bytecode$array_kind_index(uint8_t l0) {
    int32_t l1;
    if (l0 == INT32_C(0)) {
        l1 = INT32_C(0);
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = INT32_C(1);
    } else if (l0 == INT32_C(2)) {
        l1 = INT32_C(2);
    } else if (l0 == INT32_C(3)) {
        l1 = INT32_C(3);
    } else if (l0 == INT32_C(4)) {
        l1 = INT32_C(4);
    } else if (l0 == INT32_C(5)) {
        l1 = INT32_C(5);
    } else if (l0 == INT32_C(6)) {
        l1 = INT32_C(6);
    } else if (l0 == INT32_C(7)) {
        l1 = INT32_C(7);
    } else if (l0 == INT32_C(8)) {
        l1 = INT32_C(8);
    } else if (l0 == INT32_C(9)) {
        l1 = INT32_C(9);
    } else if (l0 == INT32_C(10)) {
        l1 = INT32_C(10);
    } else if (l0 == INT32_C(11)) {
        l1 = INT32_C(11);
    } else if (l0 == INT32_C(12)) {
        l1 = INT32_C(12);
    } else {
        if (!(l0 == INT32_C(13))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = INT32_C(13);
    }
    return l1;
}

vader_string_t vader_core_bytecode$array_kind_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(1)) {
        l1 = 3333u;
        return l1;
    }
    if (l0 == INT32_C(5)) {
        l1 = 2597u;
    } else if (l0 == INT32_C(12)) {
        l1 = 2027u;
    } else if (l0 == INT32_C(2)) {
        l1 = 3312u;
    } else if (l0 == INT32_C(6)) {
        l1 = 2552u;
    } else if (l0 == INT32_C(3)) {
        l1 = 3313u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2553u;
    } else if (l0 == INT32_C(9)) {
        l1 = 2407u;
    } else if (l0 == INT32_C(11)) {
        l1 = 2165u;
    } else if (l0 == INT32_C(4)) {
        l1 = 3323u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2575u;
    } else if (l0 == INT32_C(10)) {
        l1 = 2409u;
    } else if (l0 == INT32_C(13)) {
        l1 = 3010u;
    } else {
        if (!(l0 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2036u;
    }
    return l1;
}

uint8_t vader_core_bytecode$array_kind_of(vader_box_t l0, void* l1) {
    uint8_t l2;
    void* t0;
    bool t1;
    if (l0.tag == 1244u) {
        t0 = l0.payload.obj;
        l2 = vader_core_bytecode$array_kind_of_val(((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val);
        return l2;
    }
    if (l0.tag == 1247u) {
        l2 = (uint8_t) 13;
    } else if (l0.tag == 1234u) {
        l2 = (uint8_t) 13;
    } else if (l0.tag == 1237u) {
        l2 = (uint8_t) 13;
    } else if (l0.tag == 1248u) {
        t0 = l0.payload.obj;
        t1 = vader_core_bytecode$is_ref_only_element(vader_ref_box(t0), l1);
        if (t1) {
            l2 = (uint8_t) 13;
        } else {
            l2 = (uint8_t) 0;
        }
    } else {
        if (!(l0.tag == 1243u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = (uint8_t) 0;
    }
    return l2;
}

uint8_t vader_core_bytecode$array_kind_of_val(uint8_t l0) {
    uint8_t l1;
    if (l0 == INT32_C(4)) {
        l1 = (uint8_t) 1;
        return l1;
    }
    if (l0 == INT32_C(5)) {
        l1 = (uint8_t) 2;
    } else if (l0 == INT32_C(6)) {
        l1 = (uint8_t) 3;
    } else if (l0 == INT32_C(7)) {
        l1 = (uint8_t) 4;
    } else if (l0 == INT32_C(0)) {
        l1 = (uint8_t) 5;
    } else if (l0 == INT32_C(1)) {
        l1 = (uint8_t) 6;
    } else if (l0 == INT32_C(2)) {
        l1 = (uint8_t) 7;
    } else if (l0 == INT32_C(3)) {
        l1 = (uint8_t) 8;
    } else if (l0 == INT32_C(8)) {
        l1 = (uint8_t) 9;
    } else if (l0 == INT32_C(9)) {
        l1 = (uint8_t) 10;
    } else if (l0 == INT32_C(11)) {
        l1 = (uint8_t) 11;
    } else if (l0 == INT32_C(10)) {
        l1 = (uint8_t) 12;
    } else if (l0 == INT32_C(12)) {
        l1 = (uint8_t) 0;
    } else if (l0 == INT32_C(13)) {
        l1 = (uint8_t) 0;
    } else if (l0 == INT32_C(14)) {
        l1 = (uint8_t) 0;
    } else if (l0 == INT32_C(15)) {
        l1 = (uint8_t) 4;
    } else if (l0 == INT32_C(16)) {
        l1 = (uint8_t) 13;
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = (uint8_t) 0;
    }
    return l1;
}

int64_t vader_core_bytecode$bc_result_arity(void* l0) {
    int64_t t0;
    t0 = vader_core_bytecode$bc_results_arity(((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_results);
    return t0;
}

int64_t vader_core_bytecode$bc_results_arity(void* l0) {
    int64_t t0;
    vader_box_t t1;
    t0 = vader_array_length(((vader_array_t*) l0));
    if (t0 == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0), 608u);
        if (((int32_t) t1.payload.i) == INT32_C(14)) {
            return INT64_C(0);
        }
        t0 = vader_array_length(((vader_array_t*) l0));
        return t0;
    }
    t0 = vader_array_length(((vader_array_t*) l0));
    return t0;
}

uint8_t vader_core_bytecode$bc_single_result(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_results));
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 14; }
    }
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_results));
    if (!((t0 > INT64_C(1)))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_results);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0), 608u);
        { uint8_t __vret = ((uint8_t) t1.payload.i); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) vader_buffer_new((size_t) INT64_C(125));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 2087u);
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_results));
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 250u);
    t2 = std_core$finish_buffer(l1, l2);
    vader_host_std_core$Intrinsic$panic(t2);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

int32_t vader_core_bytecode$bc_single_result_type(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    int64_t t0;
    int32_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_result_types));
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(0); }
    }
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_result_types));
    if (!((t0 > INT64_C(1)))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_result_types);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0)];
        { int32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) vader_buffer_new((size_t) INT64_C(130));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 2086u);
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_result_types));
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 250u);
    t2 = std_core$finish_buffer(l1, l2);
    vader_host_std_core$Intrinsic$panic(t2);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

vader_string_t vader_core_bytecode$bc_type_key(void* l0, int32_t l1) {
    bool l2;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    vader_string_t l7 = 0;
    vader_string_t l9 = 0;
    vader_string_t l11 = 0;
    void* l8 = NULL;
    int32_t l10;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l5, &l6 };
    void** gc_raw_roots[3] = { &l0, &l8, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l9, &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l1 < INT32_C(0))) {
        l2 = true;
    } else {
        l3 = ((int64_t) (int32_t) l1);
        l4 = vader_array_length(((vader_array_t*) l0));
        l2 = (l3 >= l4);
    }
    if (l2) {
        { vader_gc_top = gc_frame.prev; return 615u; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    l6 = l5;
    if (l5.tag == 1244u) {
        l8 = (void*) vader_buffer_new((size_t) INT64_C(22));
        l3 = INT64_C(0);
        l3 = std_core$write_string_at(l8, l3, 2953u);
        t0 = l6.payload.obj;
        l4 = ((int64_t) (int32_t) ((int32_t) (uint8_t) ((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val));
        l3 = std_core$write_int(l8, l3, l4);
        l7 = std_core$finish_buffer(l8, l3);
        { vader_string_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 1247u) {
        t0 = l6.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_name;
        l7 = concat_2(3052u, l9);
    } else if (l5.tag == 1243u) {
        t0 = l6.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcRef_t*) t0)->f_trait_name;
        l7 = concat_2(2993u, l9);
    } else if (l5.tag == 1234u) {
        t0 = l6.payload.obj;
        l10 = ((vader_struct_vader_core_bytecode$BcArray_t*) t0)->f_element;
        l9 = vader_core_bytecode$bc_type_key(l0, l10);
        l7 = concat_3(1877u, l9, 607u);
    } else if (l5.tag == 1248u) {
        t0 = l6.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t0)->f_variants;
        l9 = vader_core_bytecode$key_join(l0, l8, 3658u);
        l7 = concat_3(3334u, l9, 607u);
    } else {
        if (!(l5.tag == 1237u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l6.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$BcFn_t*) t0)->f_params;
        l9 = vader_core_bytecode$key_join(l0, l8, 3658u);
        t0 = l6.payload.obj;
        l10 = ((vader_struct_vader_core_bytecode$BcFn_t*) t0)->f_return_type;
        l11 = vader_core_bytecode$bc_type_key(l0, l10);
        l7 = concat_4(2423u, l9, 405u, l11);
    }
    { vader_string_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_bytecode$c_field_align_at(void* l0, void* l1, int32_t l2) {
    vader_box_t l3;
    void* l4;
    void* l8;
    int64_t l5, l6, l7, l9;
    int32_t l10;
    uint8_t t0;
    int32_t t1;
    l3 = vader_core_bytecode$c_field_val_type(l0, l1);
    if (!(l3.tag == 0u)) {
        t0 = ((uint8_t) l3.payload.i);
        t1 = vader_core_bytecode$size_of_val_type(t0);
        return vader_box_i64(607u, ((int64_t) (int32_t) t1));
    }
    if ((l2 >= INT32_C(16))) {
        return vader_box_obj(0u, NULL);
    }
    l3 = vader_core_bytecode$nested_mirror(l0, l1);
    if (l3.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l4 = l3.payload.obj;
    l5 = INT64_C(1);
    l4 = ((vader_struct_vader_core_bytecode$BcStruct_t*) l4)->f_fields;
    l6 = vader_array_length(((vader_array_t*) l4));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l8 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l7);
        l10 = vader_chk_add(i32, l2, INT32_C(1));
        l3 = vader_core_bytecode$c_field_align_at(l8, l1, l10);
        if (l3.tag == 0u) {
            return vader_box_obj(0u, NULL);
        }
        l9 = ((int64_t) l3.payload.i);
        if ((l9 > l5)) {
            l5 = l9;
        }
        l7 = (l7 + INT64_C(1));
    }
    return vader_box_i64(607u, l5);
}

vader_box_t vader_core_bytecode$c_field_val_type(void* l0, void* l1) {
    int64_t l2, l3;
    int32_t l4;
    vader_box_t l5;
    int32_t t0;
    void* t1;
    t0 = ((vader_struct_vader_core_bytecode$BcField_t*) l0)->f_type_index;
    if ((t0 < INT32_C(0))) {
        return vader_box_obj(0u, NULL);
    }
    t0 = ((vader_struct_vader_core_bytecode$BcField_t*) l0)->f_type_index;
    l2 = ((int64_t) (int32_t) t0);
    l3 = vader_array_length(((vader_array_t*) l1));
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    l4 = ((vader_struct_vader_core_bytecode$BcField_t*) l0)->f_type_index;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
    if (!(l5.tag == 1244u)) {
        return vader_box_obj(0u, NULL);
    }
    t1 = l5.payload.obj;
    return vader_box_i32(608u, (int32_t)(uint32_t) ((vader_struct_vader_core_bytecode$BcScalar_t*) t1)->f_val);
}

vader_box_t vader_core_bytecode$c_field_width(void* l0, void* l1) {
    vader_box_t t0;
    t0 = vader_core_bytecode$c_field_width_at(l0, l1, INT32_C(0));
    return t0;
}

static vader_box_t vader_core_bytecode$c_field_width_at(void* l0, void* l1, int32_t l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    int32_t l5;
    uint8_t t0;
    int32_t t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_core_bytecode$c_field_val_type(l0, l1);
    if (!(l3.tag == 0u)) {
        t0 = ((uint8_t) l3.payload.i);
        t1 = vader_core_bytecode$size_of_val_type(t0);
        { vader_box_t __vret = vader_box_i64(607u, ((int64_t) (int32_t) t1)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l2 >= INT32_C(16))) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = vader_core_bytecode$nested_mirror(l0, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = l3.payload.obj;
    l4 = ((vader_struct_vader_core_bytecode$BcStruct_t*) l4)->f_fields;
    l5 = vader_chk_add(i32, l2, INT32_C(1));
    l4 = vader_core_bytecode$c_struct_layout_at(l4, l1, l5);
    if (!(((vader_struct_vader_core_bytecode$CLayout_t*) l4)->f_unknown_field.tag == 0u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t2 = ((vader_struct_vader_core_bytecode$CLayout_t*) l4)->f_size;
    { vader_box_t __vret = vader_box_i64(607u, t2); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_bytecode$c_result_type(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_result_c_type;
    if (!(t0 == 0u)) {
        t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_result_c_type;
        return vader_box_string(603u, t0);
    }
    return vader_box_obj(0u, NULL);
}

void* vader_core_bytecode$c_struct_layout(void* l0, void* l1) {
    void* t0;
    t0 = vader_core_bytecode$c_struct_layout_at(l0, l1, INT32_C(0));
    return t0;
}

static void* vader_core_bytecode$c_struct_layout_at(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    int64_t l4, l5, l8, l9, l13, l14, l15, l16;
    vader_box_t l6 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null();
    vader_string_t t0 = 0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[3] = { &l6, &l11, &l12 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l7, &l10, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(30u, 0u, 8u, 607u);
    l3 = (void*) _a0_arr;
    l4 = INT64_C(0);
    l5 = INT64_C(1);
    l6 = vader_box_obj(0u, NULL);
    l7 = l0;
    l8 = vader_array_length(((vader_array_t*) l7));
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l10 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l9);
        l11 = vader_core_bytecode$c_field_width_at(l10, l1, l2);
        l12 = vader_core_bytecode$c_field_align_at(l10, l1, l2);
        if (l11.tag == 0u) {
            if (l6.tag == 0u) {
                t0 = ((vader_struct_vader_core_bytecode$BcField_t*) l10)->f_name;
                l6 = vader_box_string(603u, t0);
            }
            vader_array_push_i64((vader_array_t*) l3, l4);
            l9 = (l9 + INT64_C(1));
            continue;
        }
        if (l12.tag == 0u) {
            if (l6.tag == 0u) {
                t0 = ((vader_struct_vader_core_bytecode$BcField_t*) l10)->f_name;
                l6 = vader_box_string(603u, t0);
            }
            vader_array_push_i64((vader_array_t*) l3, l4);
            l9 = (l9 + INT64_C(1));
            continue;
        }
        l13 = ((int64_t) l12.payload.i);
        if ((l13 > l5)) {
            l5 = l13;
        }
        l14 = vader_mod_i64(l4, l13);
        if (l14 != INT64_C(0)) {
            l15 = vader_chk_sub(i64, l13, l14);
            l4 = vader_chk_add(i64, l4, l15);
        }
        vader_array_push_i64((vader_array_t*) l3, l4);
        l16 = ((int64_t) l11.payload.i);
        l4 = vader_chk_add(i64, l4, l16);
        l9 = (l9 + INT64_C(1));
    }
    l8 = vader_mod_i64(l4, l5);
    if (l8 == INT64_C(0)) {
        l9 = l4;
        vader_struct_vader_core_bytecode$CLayout_t* _a2_obj = (vader_struct_vader_core_bytecode$CLayout_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$CLayout_t));
        vader_obj_header_init(_a2_obj, 1268u);
        _a2_obj->f_offsets = l3;
        _a2_obj->f_size = l9;
        _a2_obj->f_unknown_field = l6;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_chk_add(i64, l4, l5);
    l9 = vader_chk_sub(i64, t2, l8);
    vader_struct_vader_core_bytecode$CLayout_t* _a3_obj = (vader_struct_vader_core_bytecode$CLayout_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$CLayout_t));
    vader_obj_header_init(_a3_obj, 1268u);
    _a3_obj->f_offsets = l3;
    _a3_obj->f_size = l9;
    _a3_obj->f_unknown_field = l6;
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_core_bytecode$cell_value(uint8_t l0, int64_t l1) {
    bool t0;
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (t0) {
        return l1;
    }
    if (!(l0 == INT32_C(6))) {
        return ((int64_t) (int32_t) ((int32_t) (int64_t) l1));
    }
    return (l1 & INT64_C(4294967295));
}

vader_box_t vader_core_bytecode$checked_arith(uint8_t l0, uint8_t l1, int64_t l2, int64_t l3) {
    int64_t l4, l6, l7;
    bool l5;
    vader_box_t l8;
    int64_t t0;
    l4 = vader_core_bytecode$integer_bits(l1);
    l5 = vader_core_bytecode$is_unsigned_val(l1);
    l6 = vader_core_bytecode$cell_value(l1, l2);
    l7 = vader_core_bytecode$cell_value(l1, l3);
    l8 = vader_core_bytecode$integer_op(l0, l4, l5, l6, l7);
    if (l8.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l4 = ((int64_t) l8.payload.i);
    t0 = vader_core_bytecode$value_cell(l1, l4);
    return vader_box_i64(607u, t0);
}

vader_box_t vader_core_bytecode$checked_neg(uint8_t l0, int64_t l1) {
    int64_t l2, l3;
    bool l4;
    vader_box_t l5;
    int64_t t0;
    l2 = vader_core_bytecode$integer_bits(l0);
    l3 = vader_core_bytecode$cell_value(l0, l1);
    l4 = vader_core_bytecode$is_unsigned_val(l0);
    l5 = vader_support_integer$checked_negation(l2, l4, l3);
    if (l5.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l2 = ((int64_t) l5.payload.i);
    t0 = vader_core_bytecode$value_cell(l0, l2);
    return vader_box_i64(607u, t0);
}

vader_string_t vader_core_bytecode$checked_neg_message(uint8_t l0) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[2] = { &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$val_type_name(l0);
    t1 = concat_2(t0, 499u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_bytecode$checked_op_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 1883u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 3162u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2847u;
    }
    return l1;
}

vader_string_t vader_core_bytecode$checked_overflow_message(uint8_t l0, uint8_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[3] = { &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_core_bytecode$val_type_name(l0);
    l3 = vader_core_bytecode$checked_op_name(l1);
    t0 = concat_4(l2, 472u, l3, 234u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_bytecode$const_op_of(vader_box_t l0) {
    if (!((l0.tag == 1257u || l0.tag == 1272u || l0.tag == 1285u || l0.tag == 1306u || l0.tag == 1326u || l0.tag == 1358u || l0.tag == 1375u))) {
        return vader_box_obj(0u, NULL);
    }
    return l0;
}

vader_box_t vader_core_bytecode$convert_target_of(uint8_t l0) {
    vader_box_t l1;
    if (l0 == INT32_C(0)) {
        l1 = vader_box_i32(608u, INT32_C(0));
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = vader_box_i32(608u, INT32_C(0));
    } else if (l0 == INT32_C(2)) {
        l1 = vader_box_i32(608u, INT32_C(0));
    } else if (l0 == INT32_C(4)) {
        l1 = vader_box_i32(608u, INT32_C(0));
    } else if (l0 == INT32_C(5)) {
        l1 = vader_box_i32(608u, INT32_C(0));
    } else if (l0 == INT32_C(6)) {
        l1 = vader_box_i32(608u, INT32_C(0));
    } else if (l0 == INT32_C(3)) {
        l1 = vader_box_i32(608u, INT32_C(1));
    } else if (l0 == INT32_C(7)) {
        l1 = vader_box_i32(608u, INT32_C(1));
    } else if (l0 == INT32_C(8)) {
        l1 = vader_box_i32(608u, INT32_C(2));
    } else if (l0 == INT32_C(9)) {
        l1 = vader_box_i32(608u, INT32_C(2));
    } else if (l0 == INT32_C(11)) {
        l1 = vader_box_i32(608u, INT32_C(3));
    } else if (l0 == INT32_C(10)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(12)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(13)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(14)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(15)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(16)) {
        l1 = vader_box_obj(0u, NULL);
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_box_obj(0u, NULL);
    }
    return l1;
}

void* vader_core_bytecode$data_pool_type_ids(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    int64_t l2, l4, l6, l7, l10, l11;
    vader_box_t l8 = vader_box_null();
    int32_t l12, l13;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l5, &l9, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 1u, 7u, 606u);
    ((int32_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int32_t) INT32_C(0);
    l1 = (void*) _a0_arr;
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_data_pool));
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    t0 = vader_array_length(((vader_array_t*) l1));
    if (t0 == INT64_C(0)) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions;
    l2 = vader_array_length(((vader_array_t*) l3));
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l4);
        l5 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t1)->f_body;
        l6 = vader_array_length(((vader_array_t*) l5));
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l8 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l7);
            if (l8.tag == 1276u) {
                l9 = l8.payload.obj;
                t2 = ((vader_struct_vader_core_bytecode$DataConst_t*) l9)->f_pool_index;
                if ((t2 >= INT32_C(0))) {
                    t2 = ((vader_struct_vader_core_bytecode$DataConst_t*) l9)->f_pool_index;
                    l10 = ((int64_t) (int32_t) t2);
                    l11 = vader_array_length(((vader_array_t*) l1));
                    if ((l10 < l11)) {
                        l12 = ((vader_struct_vader_core_bytecode$DataConst_t*) l9)->f_pool_index;
                        l13 = ((vader_struct_vader_core_bytecode$DataConst_t*) l9)->f_type_id;
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l12)
                        ((int32_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l12] = (int32_t) l13;
                    }
                }
            }
            l7 = (l7 + INT64_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_bytecode$display_intrinsic(uint8_t l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_core_bytecode$member_name(l0);
    t0 = concat_2(805u, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_core_bytecode$effect(int64_t l0, int64_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_bytecode$StackEffect_t* _a0_obj = (vader_struct_vader_core_bytecode$StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StackEffect_t));
    vader_obj_header_init(_a0_obj, 1366u);
    _a0_obj->f_pops = l0;
    _a0_obj->f_pushes = l1;
    _a0_obj->f_flow = (uint8_t) 0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_bytecode$entry_function_index(void* l0, vader_string_t l1) {
    int64_t l2, l3;
    void* l4;
    vader_string_t t0;
    int64_t t1;
    bool t2;
    if (l1 != 0u) {
        l2 = INT64_C(0);
        l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
        while ((l2 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
            l4 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
            t0 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_name;
            if (t0 == l1) {
                t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_body));
                if ((t1 > INT64_C(0))) {
                    return vader_box_i32(606u, ((int32_t) (int64_t) l2));
                }
            }
            l2 = (l2 + INT64_C(1));
        }
    }
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
    while ((l2 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        l4 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l2);
        t2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_is_main;
        if (t2) {
            t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l4)->f_body));
            if ((t1 > INT64_C(0))) {
                return vader_box_i32(606u, ((int32_t) (int64_t) l2));
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

vader_box_t vader_core_bytecode$fn_at(void* l0, int32_t l1) {
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    if ((l1 < INT32_C(0))) {
        return vader_box_obj(0u, NULL);
    }
    l2 = ((int64_t) (int32_t) l1);
    l3 = vader_array_length(((vader_array_t*) l0));
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (!(l4.tag == 1237u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l4.payload.obj;
    return vader_ref_box(t0);
}

uint8_t vader_core_bytecode$import_intrinsic(bool l0, vader_string_t l1) {
    uint8_t t0;
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (!(l0)) {
        t0 = vader_core_bytecode$intrinsic_id(l1);
        { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
}

static bool vader_core_bytecode$in_range(int32_t l0, int64_t l1) {
    int64_t l2;
    l2 = ((int64_t) (int32_t) l0);
    if ((INT64_C(0) <= l2)) {
        return (l2 < l1);
    }
    return false;
}

static vader_box_t vader_core_bytecode$indexed_effect(int32_t l0, int64_t l1, int64_t l2, int64_t l3) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$in_range(l0, l1);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = vader_core_bytecode$effect(l2, l3);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_bytecode$indirect_effect(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    vader_box_t l3 = vader_box_null();
    int64_t l4;
    int32_t l6;
    bool t0;
    int64_t t1, t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_core_bytecode$fn_at(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l3.payload.obj;
    l5 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types;
    l6 = ((vader_struct_vader_core_bytecode$BcFn_t*) l2)->f_return_type;
    t0 = vader_core_bytecode$is_void_at(l5, l6);
    if (t0) {
        l4 = INT64_C(0);
    } else {
        l4 = INT64_C(1);
    }
    t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFn_t*) l2)->f_params));
    t2 = vader_chk_add(i64, t1, INT64_C(1));
    t3 = vader_core_bytecode$effect(t2, l4);
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_core_bytecode$integer_bits(uint8_t l0) {
    int32_t t0;
    int64_t t1;
    t0 = vader_core_bytecode$size_of_val_type(l0);
    t1 = vader_chk_mul(i64, ((int64_t) (int32_t) t0), INT64_C(8));
    return t1;
}

static vader_box_t vader_core_bytecode$integer_op(uint8_t l0, int64_t l1, bool l2, int64_t l3, int64_t l4) {
    vader_box_t l5;
    if (l0 == INT32_C(0)) {
        l5 = vader_support_integer$checked_add(l1, l2, l3, l4);
        return l5;
    }
    if (l0 == INT32_C(1)) {
        l5 = vader_support_integer$checked_sub(l1, l2, l3, l4);
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l5 = vader_support_integer$checked_mul(l1, l2, l3, l4);
    }
    return l5;
}

uint8_t vader_core_bytecode$intrinsic_id(vader_string_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    uint8_t t1;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 65u, 0u, 603u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 64u] = vader_box_string(603u, 2428u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 63u] = vader_box_string(603u, 2427u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 62u] = vader_box_string(603u, 2433u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 61u] = vader_box_string(603u, 2431u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 60u] = vader_box_string(603u, 2429u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 59u] = vader_box_string(603u, 2239u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 58u] = vader_box_string(603u, 2240u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 57u] = vader_box_string(603u, 2955u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 56u] = vader_box_string(603u, 3114u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 55u] = vader_box_string(603u, 3588u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 54u] = vader_box_string(603u, 3587u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 53u] = vader_box_string(603u, 3592u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 52u] = vader_box_string(603u, 3591u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 51u] = vader_box_string(603u, 3590u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 50u] = vader_box_string(603u, 3589u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 49u] = vader_box_string(603u, 2851u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 48u] = vader_box_string(603u, 2850u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 47u] = vader_box_string(603u, 2849u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 46u] = vader_box_string(603u, 2989u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 45u] = vader_box_string(603u, 2842u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 44u] = vader_box_string(603u, 2843u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 43u] = vader_box_string(603u, 2840u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 42u] = vader_box_string(603u, 3597u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 41u] = vader_box_string(603u, 3598u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 40u] = vader_box_string(603u, 3182u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 39u] = vader_box_string(603u, 2697u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 38u] = vader_box_string(603u, 2696u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 37u] = vader_box_string(603u, 2241u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 36u] = vader_box_string(603u, 2131u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 35u] = vader_box_string(603u, 3082u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 34u] = vader_box_string(603u, 3593u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 33u] = vader_box_string(603u, 2961u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 32u] = vader_box_string(603u, 3091u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 31u] = vader_box_string(603u, 2236u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 30u] = vader_box_string(603u, 1894u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 29u] = vader_box_string(603u, 1893u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 28u] = vader_box_string(603u, 2092u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 27u] = vader_box_string(603u, 2096u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 26u] = vader_box_string(603u, 2185u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 25u] = vader_box_string(603u, 2184u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 24u] = vader_box_string(603u, 2059u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 23u] = vader_box_string(603u, 2052u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 22u] = vader_box_string(603u, 2054u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 21u] = vader_box_string(603u, 2055u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 20u] = vader_box_string(603u, 2053u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 19u] = vader_box_string(603u, 2870u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 18u] = vader_box_string(603u, 1986u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 17u] = vader_box_string(603u, 1992u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 16u] = vader_box_string(603u, 1987u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 15u] = vader_box_string(603u, 1991u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 14u] = vader_box_string(603u, 1990u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 13u] = vader_box_string(603u, 1988u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 12u] = vader_box_string(603u, 2258u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 11u] = vader_box_string(603u, 2020u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 10u] = vader_box_string(603u, 2408u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 9u] = vader_box_string(603u, 2021u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 8u] = vader_box_string(603u, 2422u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 7u] = vader_box_string(603u, 3136u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 6u] = vader_box_string(603u, 3137u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 5u] = vader_box_string(603u, 2093u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 4u] = vader_box_string(603u, 2088u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 3u] = vader_box_string(603u, 2695u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 2u] = vader_box_string(603u, 2080u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 1u] = vader_box_string(603u, 2078u);
    vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(603u, 2079u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(31u, 65u, 1u, 608u);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 64u] = (uint8_t) INT32_C(65);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 63u] = (uint8_t) INT32_C(64);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 62u] = (uint8_t) INT32_C(63);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 61u] = (uint8_t) INT32_C(62);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 60u] = (uint8_t) INT32_C(61);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 59u] = (uint8_t) INT32_C(60);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 58u] = (uint8_t) INT32_C(59);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 57u] = (uint8_t) INT32_C(58);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 56u] = (uint8_t) INT32_C(57);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 55u] = (uint8_t) INT32_C(56);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 54u] = (uint8_t) INT32_C(55);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 53u] = (uint8_t) INT32_C(54);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 52u] = (uint8_t) INT32_C(53);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 51u] = (uint8_t) INT32_C(52);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 50u] = (uint8_t) INT32_C(51);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 49u] = (uint8_t) INT32_C(50);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 48u] = (uint8_t) INT32_C(49);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 47u] = (uint8_t) INT32_C(48);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 46u] = (uint8_t) INT32_C(47);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 45u] = (uint8_t) INT32_C(46);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 44u] = (uint8_t) INT32_C(45);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 43u] = (uint8_t) INT32_C(44);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 42u] = (uint8_t) INT32_C(43);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 41u] = (uint8_t) INT32_C(42);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 40u] = (uint8_t) INT32_C(41);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 39u] = (uint8_t) INT32_C(40);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 38u] = (uint8_t) INT32_C(39);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 37u] = (uint8_t) INT32_C(38);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 36u] = (uint8_t) INT32_C(37);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 35u] = (uint8_t) INT32_C(36);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 34u] = (uint8_t) INT32_C(35);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 33u] = (uint8_t) INT32_C(34);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 32u] = (uint8_t) INT32_C(33);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 31u] = (uint8_t) INT32_C(32);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 30u] = (uint8_t) INT32_C(31);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 29u] = (uint8_t) INT32_C(30);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 28u] = (uint8_t) INT32_C(29);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 27u] = (uint8_t) INT32_C(28);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 26u] = (uint8_t) INT32_C(27);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 25u] = (uint8_t) INT32_C(26);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 24u] = (uint8_t) INT32_C(25);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 23u] = (uint8_t) INT32_C(24);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 22u] = (uint8_t) INT32_C(23);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 21u] = (uint8_t) INT32_C(22);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 20u] = (uint8_t) INT32_C(21);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 19u] = (uint8_t) INT32_C(20);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 18u] = (uint8_t) INT32_C(19);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 17u] = (uint8_t) INT32_C(18);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 16u] = (uint8_t) INT32_C(17);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 15u] = (uint8_t) INT32_C(16);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 14u] = (uint8_t) INT32_C(15);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 13u] = (uint8_t) INT32_C(14);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 12u] = (uint8_t) INT32_C(13);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 11u] = (uint8_t) INT32_C(12);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 10u] = (uint8_t) INT32_C(11);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 9u] = (uint8_t) INT32_C(10);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 8u] = (uint8_t) INT32_C(9);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 7u] = (uint8_t) INT32_C(8);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 6u] = (uint8_t) INT32_C(7);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 5u] = (uint8_t) INT32_C(6);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 4u] = (uint8_t) INT32_C(5);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 3u] = (uint8_t) INT32_C(4);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 2u] = (uint8_t) INT32_C(3);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 1u] = (uint8_t) INT32_C(2);
    ((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = (uint8_t) INT32_C(1);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 128u, 7u, 606u);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 127u] = (int32_t) INT32_C(42);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 126u] = (int32_t) INT32_C(64);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 125u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 124u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 123u] = (int32_t) INT32_C(50);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 122u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 121u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 120u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 119u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 118u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 117u] = (int32_t) INT32_C(25);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 116u] = (int32_t) INT32_C(26);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 115u] = (int32_t) INT32_C(47);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 114u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 113u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 112u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 111u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 110u] = (int32_t) INT32_C(19);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 109u] = (int32_t) INT32_C(35);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 108u] = (int32_t) INT32_C(20);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 107u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 106u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 105u] = (int32_t) INT32_C(21);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 104u] = (int32_t) INT32_C(5);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 103u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 102u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 101u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 100u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 99u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 98u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 97u] = (int32_t) INT32_C(23);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 96u] = (int32_t) INT32_C(51);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 95u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 94u] = (int32_t) INT32_C(63);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 93u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 92u] = (int32_t) INT32_C(11);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 91u] = (int32_t) INT32_C(6);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 90u] = (int32_t) INT32_C(3);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 89u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 88u] = (int32_t) INT32_C(8);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 87u] = (int32_t) INT32_C(59);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 86u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 85u] = (int32_t) INT32_C(10);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 84u] = (int32_t) INT32_C(27);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 83u] = (int32_t) INT32_C(38);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 82u] = (int32_t) INT32_C(45);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 81u] = (int32_t) INT32_C(44);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 80u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 79u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 78u] = (int32_t) INT32_C(1);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 77u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 76u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 75u] = (int32_t) INT32_C(48);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 74u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 73u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 72u] = (int32_t) INT32_C(18);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 71u] = (int32_t) INT32_C(60);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 70u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 69u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 68u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 67u] = (int32_t) INT32_C(55);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 66u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 65u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 64u] = (int32_t) INT32_C(40);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 63u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 62u] = (int32_t) INT32_C(4);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 61u] = (int32_t) INT32_C(16);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 60u] = (int32_t) INT32_C(22);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 59u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 58u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 57u] = (int32_t) INT32_C(15);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 56u] = (int32_t) INT32_C(7);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 55u] = (int32_t) INT32_C(14);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 54u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 53u] = (int32_t) INT32_C(56);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 52u] = (int32_t) INT32_C(41);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 51u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 50u] = (int32_t) INT32_C(24);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 49u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 48u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 47u] = (int32_t) INT32_C(43);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 46u] = (int32_t) INT32_C(49);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 45u] = (int32_t) INT32_C(53);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 44u] = (int32_t) INT32_C(62);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 43u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 42u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 41u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 40u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 39u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 38u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 37u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 36u] = (int32_t) INT32_C(9);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 35u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 34u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 33u] = (int32_t) INT32_C(31);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 32u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 31u] = (int32_t) INT32_C(34);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 30u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 29u] = (int32_t) INT32_C(29);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 28u] = (int32_t) INT32_C(58);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 27u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 26u] = (int32_t) INT32_C(17);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 25u] = (int32_t) INT32_C(61);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 24u] = (int32_t) INT32_C(32);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 23u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 22u] = (int32_t) INT32_C(12);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 21u] = (int32_t) INT32_C(46);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 20u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 19u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 18u] = (int32_t) INT32_C(57);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 17u] = (int32_t) INT32_C(52);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 16u] = (int32_t) INT32_C(65);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 15u] = (int32_t) INT32_C(37);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 14u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 13u] = (int32_t) INT32_C(2);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 12u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 11u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 10u] = (int32_t) INT32_C(30);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 9u] = (int32_t) INT32_C(28);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 8u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 7u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 6u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 5u] = (int32_t) INT32_C(36);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 4u] = (int32_t) INT32_C(54);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 3u] = (int32_t) INT32_C(0);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 2u] = (int32_t) INT32_C(13);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 1u] = (int32_t) INT32_C(33);
    ((int32_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = (int32_t) INT32_C(39);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__vader_core_bytecode_IntrinsicId_t* _a3_obj = (vader_struct_std_collections$Map__string__vader_core_bytecode_IntrinsicId_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__vader_core_bytecode_IntrinsicId_t));
    vader_obj_header_init(_a3_obj, 969u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(127);
    _a3_obj->f_grow_at = INT64_C(96);
    _a3_obj->f_size = INT64_C(65);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    l4 = std_collections$Map$std_core$Index$at__string__vader_core_bytecode_IntrinsicId(t0, l0);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
    }
    t1 = ((uint8_t) l4.payload.i);
    { uint8_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_core_bytecode$intrinsic_may_collect(uint8_t l0) {
    bool l1, l2;
    if (l0 == INT32_C(1)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(2);
    }
    if (l1) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(7);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(4);
    }
    if (l2) {
        l1 = false;
        return l1;
    }
    if (l0 == INT32_C(3)) {
        l1 = false;
    } else {
        if (l0 == INT32_C(33)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(35);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(38);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(39);
        }
        if (l2) {
            l1 = false;
        } else {
            if (l0 == INT32_C(40)) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(42);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(43);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(57);
            }
            if (l2) {
                l1 = false;
            } else if (l0 == INT32_C(41)) {
                l1 = false;
            } else if (l0 == INT32_C(46)) {
                l1 = false;
            } else {
                if (l0 == INT32_C(44)) {
                    l2 = true;
                } else {
                    l2 = l0 == INT32_C(45);
                }
                if (l2) {
                    l1 = true;
                } else {
                    if (l0 == INT32_C(47)) {
                        l2 = true;
                    } else {
                        l2 = l0 == INT32_C(48);
                    }
                    if (l2) {
                        l1 = true;
                    } else if (l0 == INT32_C(49)) {
                        l1 = false;
                    } else {
                        if (l0 == INT32_C(34)) {
                            l2 = true;
                        } else {
                            l2 = l0 == INT32_C(36);
                        }
                        if (l2) {
                            l2 = true;
                        } else {
                            l2 = l0 == INT32_C(37);
                        }
                        if (l2) {
                            l2 = true;
                        } else {
                            l2 = l0 == INT32_C(50);
                        }
                        if (l2) {
                            l1 = true;
                        } else {
                            if (l0 == INT32_C(51)) {
                                l2 = true;
                            } else {
                                l2 = l0 == INT32_C(52);
                            }
                            if (l2) {
                                l2 = true;
                            } else {
                                l2 = l0 == INT32_C(53);
                            }
                            if (l2) {
                                l2 = true;
                            } else {
                                l2 = l0 == INT32_C(54);
                            }
                            if (l2) {
                                l1 = true;
                            } else {
                                if (l0 == INT32_C(55)) {
                                    l2 = true;
                                } else {
                                    l2 = l0 == INT32_C(56);
                                }
                                if (l2) {
                                    l1 = true;
                                } else {
                                    if (l0 == INT32_C(59)) {
                                        l2 = true;
                                    } else {
                                        l2 = l0 == INT32_C(60);
                                    }
                                    if (l2) {
                                        l1 = false;
                                    } else {
                                        if (l0 == INT32_C(5)) {
                                            l2 = true;
                                        } else {
                                            l2 = l0 == INT32_C(6);
                                        }
                                        if (l2) {
                                            l2 = true;
                                        } else {
                                            l2 = l0 == INT32_C(13);
                                        }
                                        if (l2) {
                                            l1 = true;
                                        } else {
                                            if (l0 == INT32_C(26)) {
                                                l2 = true;
                                            } else {
                                                l2 = l0 == INT32_C(27);
                                            }
                                            if (l2) {
                                                l2 = true;
                                            } else {
                                                l2 = l0 == INT32_C(28);
                                            }
                                            if (l2) {
                                                l2 = true;
                                            } else {
                                                l2 = l0 == INT32_C(29);
                                            }
                                            if (l2) {
                                                l1 = true;
                                            } else {
                                                if (l0 == INT32_C(30)) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(31);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(32);
                                                }
                                                if (l2) {
                                                    l1 = true;
                                                } else if (l0 == INT32_C(58)) {
                                                    l1 = true;
                                                } else {
                                                    if (l0 == INT32_C(61)) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(62);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(63);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(64);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(65);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(0);
                                                    }
                                                    if (l2) {
                                                        l1 = true;
                                                    } else {
                                                        if (l0 == INT32_C(8)) {
                                                            l2 = true;
                                                        } else {
                                                            l2 = l0 == INT32_C(9);
                                                        }
                                                        if (l2) {
                                                            l2 = true;
                                                        } else {
                                                            l2 = l0 == INT32_C(10);
                                                        }
                                                        if (l2) {
                                                            l2 = true;
                                                        } else {
                                                            l2 = l0 == INT32_C(11);
                                                        }
                                                        if (l2) {
                                                            l2 = true;
                                                        } else {
                                                            l2 = l0 == INT32_C(12);
                                                        }
                                                        if (l2) {
                                                            l2 = true;
                                                        } else {
                                                            l2 = l0 == INT32_C(14);
                                                        }
                                                        if (l2) {
                                                            l2 = true;
                                                        } else {
                                                            l2 = l0 == INT32_C(15);
                                                        }
                                                        if (l2) {
                                                            l2 = true;
                                                        } else {
                                                            l2 = l0 == INT32_C(16);
                                                        }
                                                        if (l2) {
                                                            l2 = true;
                                                        } else {
                                                            l2 = l0 == INT32_C(17);
                                                        }
                                                        if (l2) {
                                                            l2 = true;
                                                        } else {
                                                            l2 = l0 == INT32_C(18);
                                                        }
                                                        if (l2) {
                                                            l2 = true;
                                                        } else {
                                                            l2 = l0 == INT32_C(19);
                                                        }
                                                        if (l2) {
                                                            l2 = true;
                                                        } else {
                                                            l2 = l0 == INT32_C(20);
                                                        }
                                                        if (l2) {
                                                            l2 = true;
                                                        } else {
                                                            l2 = l0 == INT32_C(21);
                                                        }
                                                        if (l2) {
                                                            l2 = true;
                                                        } else {
                                                            l2 = l0 == INT32_C(22);
                                                        }
                                                        if (l2) {
                                                            l2 = true;
                                                        } else {
                                                            l2 = l0 == INT32_C(23);
                                                        }
                                                        if (l2) {
                                                            l2 = true;
                                                        } else {
                                                            l2 = l0 == INT32_C(24);
                                                        }
                                                        if (l2) {
                                                            l2 = true;
                                                        } else {
                                                            l2 = l0 == INT32_C(25);
                                                        }
                                                        if (!(l2)) {
                                                            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                                                        }
                                                        l1 = true;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return l1;
}

bool vader_core_bytecode$intrinsic_may_shorten_array(uint8_t l0) {
    bool l1, l2;
    if (l0 == INT32_C(1)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(2);
    }
    if (l1) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(3);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(4);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(7);
    }
    if (l2) {
        l1 = false;
        return l1;
    }
    if (l0 == INT32_C(5)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(6);
    }
    if (l2) {
        l1 = false;
    } else if (l0 == INT32_C(13)) {
        l1 = false;
    } else {
        if (l0 == INT32_C(26)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(27);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(28);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(29);
        }
        if (l2) {
            l1 = false;
        } else {
            if (l0 == INT32_C(30)) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(31);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(32);
            }
            if (l2) {
                l1 = false;
            } else {
                if (l0 == INT32_C(33)) {
                    l2 = true;
                } else {
                    l2 = l0 == INT32_C(35);
                }
                if (l2) {
                    l2 = true;
                } else {
                    l2 = l0 == INT32_C(38);
                }
                if (l2) {
                    l2 = true;
                } else {
                    l2 = l0 == INT32_C(39);
                }
                if (l2) {
                    l1 = false;
                } else {
                    if (l0 == INT32_C(40)) {
                        l2 = true;
                    } else {
                        l2 = l0 == INT32_C(42);
                    }
                    if (l2) {
                        l2 = true;
                    } else {
                        l2 = l0 == INT32_C(43);
                    }
                    if (l2) {
                        l2 = true;
                    } else {
                        l2 = l0 == INT32_C(57);
                    }
                    if (l2) {
                        l1 = false;
                    } else if (l0 == INT32_C(41)) {
                        l1 = false;
                    } else {
                        if (l0 == INT32_C(44)) {
                            l2 = true;
                        } else {
                            l2 = l0 == INT32_C(45);
                        }
                        if (l2) {
                            l2 = true;
                        } else {
                            l2 = l0 == INT32_C(46);
                        }
                        if (l2) {
                            l1 = false;
                        } else {
                            if (l0 == INT32_C(47)) {
                                l2 = true;
                            } else {
                                l2 = l0 == INT32_C(48);
                            }
                            if (l2) {
                                l2 = true;
                            } else {
                                l2 = l0 == INT32_C(49);
                            }
                            if (l2) {
                                l1 = false;
                            } else {
                                if (l0 == INT32_C(34)) {
                                    l2 = true;
                                } else {
                                    l2 = l0 == INT32_C(36);
                                }
                                if (l2) {
                                    l2 = true;
                                } else {
                                    l2 = l0 == INT32_C(37);
                                }
                                if (l2) {
                                    l2 = true;
                                } else {
                                    l2 = l0 == INT32_C(50);
                                }
                                if (l2) {
                                    l1 = true;
                                } else {
                                    if (l0 == INT32_C(51)) {
                                        l2 = true;
                                    } else {
                                        l2 = l0 == INT32_C(52);
                                    }
                                    if (l2) {
                                        l2 = true;
                                    } else {
                                        l2 = l0 == INT32_C(53);
                                    }
                                    if (l2) {
                                        l2 = true;
                                    } else {
                                        l2 = l0 == INT32_C(54);
                                    }
                                    if (l2) {
                                        l1 = true;
                                    } else {
                                        if (l0 == INT32_C(55)) {
                                            l2 = true;
                                        } else {
                                            l2 = l0 == INT32_C(56);
                                        }
                                        if (l2) {
                                            l1 = true;
                                        } else {
                                            if (l0 == INT32_C(59)) {
                                                l2 = true;
                                            } else {
                                                l2 = l0 == INT32_C(60);
                                            }
                                            if (l2) {
                                                l2 = true;
                                            } else {
                                                l2 = l0 == INT32_C(58);
                                            }
                                            if (l2) {
                                                l1 = false;
                                            } else {
                                                if (l0 == INT32_C(61)) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(62);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(63);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(64);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(65);
                                                }
                                                if (l2) {
                                                    l1 = false;
                                                } else if (l0 == INT32_C(0)) {
                                                    l1 = true;
                                                } else {
                                                    if (l0 == INT32_C(8)) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(9);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(10);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(11);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(12);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(14);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(15);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(16);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(17);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(18);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(19);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(20);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(21);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(22);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(23);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(24);
                                                    }
                                                    if (l2) {
                                                        l2 = true;
                                                    } else {
                                                        l2 = l0 == INT32_C(25);
                                                    }
                                                    if (!(l2)) {
                                                        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                                                    }
                                                    l1 = true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return l1;
}

bool vader_core_bytecode$intrinsic_parks(uint8_t l0) {
    bool l1, l2;
    if (l0 == INT32_C(34)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(36);
    }
    if (l1) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(50);
    }
    if (l2) {
        l1 = true;
        return l1;
    }
    if (l0 == INT32_C(51)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(52);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(53);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(54);
    }
    if (l2) {
        l1 = true;
    } else {
        if (l0 == INT32_C(55)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(56);
        }
        if (l2) {
            l1 = true;
        } else if (l0 == INT32_C(37)) {
            l1 = false;
        } else {
            if (l0 == INT32_C(33)) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(35);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(38);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(39);
            }
            if (l2) {
                l1 = false;
            } else {
                if (l0 == INT32_C(40)) {
                    l2 = true;
                } else {
                    l2 = l0 == INT32_C(42);
                }
                if (l2) {
                    l2 = true;
                } else {
                    l2 = l0 == INT32_C(43);
                }
                if (l2) {
                    l2 = true;
                } else {
                    l2 = l0 == INT32_C(57);
                }
                if (l2) {
                    l1 = false;
                } else if (l0 == INT32_C(41)) {
                    l1 = false;
                } else {
                    if (l0 == INT32_C(44)) {
                        l2 = true;
                    } else {
                        l2 = l0 == INT32_C(45);
                    }
                    if (l2) {
                        l2 = true;
                    } else {
                        l2 = l0 == INT32_C(46);
                    }
                    if (l2) {
                        l1 = false;
                    } else {
                        if (l0 == INT32_C(47)) {
                            l2 = true;
                        } else {
                            l2 = l0 == INT32_C(48);
                        }
                        if (l2) {
                            l2 = true;
                        } else {
                            l2 = l0 == INT32_C(49);
                        }
                        if (l2) {
                            l1 = false;
                        } else {
                            if (l0 == INT32_C(1)) {
                                l2 = true;
                            } else {
                                l2 = l0 == INT32_C(2);
                            }
                            if (l2) {
                                l2 = true;
                            } else {
                                l2 = l0 == INT32_C(3);
                            }
                            if (l2) {
                                l2 = true;
                            } else {
                                l2 = l0 == INT32_C(4);
                            }
                            if (l2) {
                                l2 = true;
                            } else {
                                l2 = l0 == INT32_C(7);
                            }
                            if (l2) {
                                l2 = true;
                            } else {
                                l2 = l0 == INT32_C(5);
                            }
                            if (l2) {
                                l2 = true;
                            } else {
                                l2 = l0 == INT32_C(6);
                            }
                            if (l2) {
                                l1 = false;
                            } else {
                                if (l0 == INT32_C(13)) {
                                    l2 = true;
                                } else {
                                    l2 = l0 == INT32_C(58);
                                }
                                if (l2) {
                                    l2 = true;
                                } else {
                                    l2 = l0 == INT32_C(59);
                                }
                                if (l2) {
                                    l2 = true;
                                } else {
                                    l2 = l0 == INT32_C(60);
                                }
                                if (l2) {
                                    l1 = false;
                                } else {
                                    if (l0 == INT32_C(26)) {
                                        l2 = true;
                                    } else {
                                        l2 = l0 == INT32_C(27);
                                    }
                                    if (l2) {
                                        l2 = true;
                                    } else {
                                        l2 = l0 == INT32_C(28);
                                    }
                                    if (l2) {
                                        l2 = true;
                                    } else {
                                        l2 = l0 == INT32_C(29);
                                    }
                                    if (l2) {
                                        l1 = false;
                                    } else {
                                        if (l0 == INT32_C(30)) {
                                            l2 = true;
                                        } else {
                                            l2 = l0 == INT32_C(31);
                                        }
                                        if (l2) {
                                            l2 = true;
                                        } else {
                                            l2 = l0 == INT32_C(32);
                                        }
                                        if (l2) {
                                            l1 = false;
                                        } else {
                                            if (l0 == INT32_C(61)) {
                                                l2 = true;
                                            } else {
                                                l2 = l0 == INT32_C(62);
                                            }
                                            if (l2) {
                                                l2 = true;
                                            } else {
                                                l2 = l0 == INT32_C(63);
                                            }
                                            if (l2) {
                                                l2 = true;
                                            } else {
                                                l2 = l0 == INT32_C(64);
                                            }
                                            if (l2) {
                                                l2 = true;
                                            } else {
                                                l2 = l0 == INT32_C(65);
                                            }
                                            if (l2) {
                                                l2 = true;
                                            } else {
                                                l2 = l0 == INT32_C(0);
                                            }
                                            if (l2) {
                                                l1 = false;
                                            } else {
                                                if (l0 == INT32_C(8)) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(9);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(10);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(11);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(12);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(14);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(15);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(16);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(17);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(18);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(19);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(20);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(21);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(22);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(23);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(24);
                                                }
                                                if (l2) {
                                                    l2 = true;
                                                } else {
                                                    l2 = l0 == INT32_C(25);
                                                }
                                                if (!(l2)) {
                                                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                                                }
                                                l1 = false;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return l1;
}

bool vader_core_bytecode$is_64_bit_int_val(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(3)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(7);
    }
    if (l1) {
        return true;
    }
    if (l0 == INT32_C(0)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(1);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(2);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(4);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(5);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(6);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(8);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(9);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(10);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(11);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(12);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(13);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(14);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(15);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(16);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(17);
    }
    if (!(l1)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return false;
}

bool vader_core_bytecode$is_float_val(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(8)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(9);
    }
    if (l1) {
        return true;
    }
    if (l0 == INT32_C(0)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(1);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(2);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(3);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(4);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(5);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(6);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(7);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(10);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(11);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(12);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(13);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(14);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(15);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(16);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(17);
    }
    if (!(l1)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return false;
}

bool vader_core_bytecode$is_integer_val(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(0)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(1);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(2);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(3);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(4);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(5);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(6);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(7);
    }
    if (l1) {
        return true;
    }
    if (l0 == INT32_C(8)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(9);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(10);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(11);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(12);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(13);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(14);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(15);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(16);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(17);
    }
    if (!(l1)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return false;
}

bool vader_core_bytecode$is_narrow_valtype(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(4)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(0);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(5);
    }
    if (l1) {
        return true;
    }
    return l0 == INT32_C(1);
}

bool vader_core_bytecode$is_ref_only_element(vader_box_t l0, void* l1) {
    bool l2;
    void* l3;
    int64_t l4, l5;
    int32_t l6;
    void* t0;
    vader_box_t t1;
    bool t2;
    if (l0.tag == 1247u) {
        l2 = true;
        return l2;
    }
    if (l0.tag == 1234u) {
        l2 = true;
    } else if (l0.tag == 1237u) {
        l2 = true;
    } else if (l0.tag == 1244u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val == INT32_C(13);
    } else if (l0.tag == 1243u) {
        l2 = false;
    } else {
        if (!(l0.tag == 1248u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t0)->f_variants;
        l4 = vader_array_length(((vader_array_t*) l3));
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l6 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l5];
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
            t2 = vader_core_bytecode$is_ref_only_element(t1, l1);
            if (!(t2)) {
                return false;
            }
            l5 = (l5 + INT64_C(1));
        }
        return true;
    }
    return l2;
}

bool vader_core_bytecode$is_string_val(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(12)) {
        return true;
    }
    if (l0 == INT32_C(0)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(1);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(2);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(3);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(4);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(5);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(6);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(7);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(8);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(9);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(10);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(11);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(13);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(14);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(15);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(16);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(17);
    }
    if (!(l1)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return false;
}

bool vader_core_bytecode$is_u32_class(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(4)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(5);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(6);
    }
    if (l1) {
        return true;
    }
    if (l0 == INT32_C(0)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(1);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(2);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(3);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(7);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(8);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(9);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(10);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(11);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(12);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(13);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(14);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(15);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(16);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(17);
    }
    if (!(l1)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return false;
}

bool vader_core_bytecode$is_u64_class(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(7)) {
        return true;
    }
    if (l0 == INT32_C(0)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(1);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(2);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(3);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(4);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(5);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(6);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(8);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(9);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(10);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(11);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(12);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(13);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(14);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(15);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(16);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(17);
    }
    if (!(l1)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return false;
}

bool vader_core_bytecode$is_unsigned_val(uint8_t l0) {
    bool t0;
    t0 = vader_core_bytecode$is_u32_class(l0);
    if (t0) {
        return true;
    }
    t0 = vader_core_bytecode$is_u64_class(l0);
    return t0;
}

bool vader_core_bytecode$is_void_at(void* l0, int32_t l1) {
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    if ((l1 < INT32_C(0))) {
        return false;
    }
    l2 = ((int64_t) (int32_t) l1);
    l3 = vader_array_length(((vader_array_t*) l0));
    if ((l2 >= l3)) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (l4.tag == 1244u) {
        t0 = l4.payload.obj;
        return ((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val == INT32_C(14);
    }
    return false;
}

static vader_string_t vader_core_bytecode$key_join(void* l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    int32_t l7;
    vader_string_t l8 = 0;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l8, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_array_length(((vader_array_t*) l1));
    vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t0, 0u, 603u);
    l3 = (void*) _a0_arr;
    l4 = l1;
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l7 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l6];
        l8 = vader_core_bytecode$bc_type_key(l0, l7);
        vader_array_push_scalar((vader_array_t*) l3, vader_box_string(603u, l8));
        l6 = (l6 + INT64_C(1));
    }
    t1 = std_string$join(l3, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_bytecode$library_name(void* l0) {
    void* l1;
    vader_box_t l2;
    vader_string_t t0;
    l2 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_library;
    if (l2.tag == 0u) {
        return 0u;
    }
    l1 = l2.payload.obj;
    t0 = ((vader_struct_std_core$CLibrary_t*) l1)->f_name;
    return t0;
}

int32_t vader_core_bytecode$main_function_index(void* l0) {
    int64_t l1, l2;
    void* t0;
    bool t1;
    l1 = INT64_C(0);
    l2 = vader_array_length(((vader_array_t*) l0));
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
        t1 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_is_main;
        if (t1) {
            return ((int32_t) (int64_t) l1);
        }
        l1 = (l1 + INT64_C(1));
    }
    return INT32_C(-1);
}

void* vader_core_bytecode$mark_jump_targets(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    int32_t l5;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 1u, 12u, 601u);
    ((uint8_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) l0));
    while ((l3 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l5 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l3];
        if ((l5 >= INT32_C(0))) {
            if ((((int64_t) (int32_t) l5) < l1)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                ((uint8_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l5] = (uint8_t) true;
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_bytecode$member_name(uint8_t l0) {
    void* l1;
    int64_t l2;
    void* t0;
    vader_string_t t1;
    l1 = (void*) &vader_data_26;
    l2 = ((int64_t) (uint8_t) l0);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
    t1 = ((vader_struct_vader_core_bytecode$MemberName_t*) t0)->f_member;
    return t1;
}

vader_box_t vader_core_bytecode$mirror_at(void* l0, int32_t l1) {
    void* l2;
    vader_box_t l3;
    vader_string_t t0;
    l3 = vader_core_bytecode$struct_at(l0, l1);
    if (l3.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l2 = l3.payload.obj;
    t0 = ((vader_struct_vader_core_bytecode$BcStruct_t*) l2)->f_c_name;
    if (!(t0 == 0u)) {
        return vader_ref_box(l2);
    }
    return vader_box_obj(0u, NULL);
}

vader_box_t vader_core_bytecode$nested_mirror(void* l0, void* l1) {
    int32_t l2;
    vader_box_t t0;
    l2 = ((vader_struct_vader_core_bytecode$BcField_t*) l0)->f_type_index;
    t0 = vader_core_bytecode$mirror_at(l1, l2);
    return t0;
}

bool vader_core_bytecode$op_shortens_array(vader_box_t l0) {
    return (l0.tag == 1221u || l0.tag == 1228u);
}

vader_box_t vader_core_bytecode$param_c_type(void* l0, int64_t l1) {
    int64_t l2;
    vader_box_t t0;
    vader_string_t t1;
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_param_c_types));
    if ((l1 >= l2)) {
        return vader_box_obj(0u, NULL);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_param_c_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l1];
    t1 = t0.payload.s;
    if (!(t1 == 0u)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_param_c_types);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l1];
        t1 = t0.payload.s;
        return vader_box_string(603u, t1);
    }
    return vader_box_obj(0u, NULL);
}

bool vader_core_bytecode$param_is_by_address(void* l0, int64_t l1) {
    int64_t l2;
    bool t0, t1;
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_param_by_address));
    if ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_param_by_address);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1];
        t1 = t0;
        return t1;
    }
    return false;
}

bool vader_core_bytecode$param_is_c_out(void* l0, int64_t l1) {
    int64_t l2;
    bool t0, t1;
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_param_c_out));
    if ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_param_c_out);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1];
        t1 = t0;
        return t1;
    }
    return false;
}

vader_box_t vader_core_bytecode$parse_val_type(vader_string_t l0) {
    vader_box_t l1;
    if (l0 == 2597u) {
        l1 = vader_box_i32(608u, INT32_C(0));
        return l1;
    }
    if (l0 == 2552u) {
        l1 = vader_box_i32(608u, INT32_C(1));
    } else if (l0 == 2553u) {
        l1 = vader_box_i32(608u, INT32_C(2));
    } else if (l0 == 2575u) {
        l1 = vader_box_i32(608u, INT32_C(3));
    } else if (l0 == 3333u) {
        l1 = vader_box_i32(608u, INT32_C(4));
    } else if (l0 == 3312u) {
        l1 = vader_box_i32(608u, INT32_C(5));
    } else if (l0 == 3313u) {
        l1 = vader_box_i32(608u, INT32_C(6));
    } else if (l0 == 3323u) {
        l1 = vader_box_i32(608u, INT32_C(7));
    } else if (l0 == 2407u) {
        l1 = vader_box_i32(608u, INT32_C(8));
    } else if (l0 == 2409u) {
        l1 = vader_box_i32(608u, INT32_C(9));
    } else if (l0 == 2027u) {
        l1 = vader_box_i32(608u, INT32_C(10));
    } else if (l0 == 2165u) {
        l1 = vader_box_i32(608u, INT32_C(11));
    } else if (l0 == 3128u) {
        l1 = vader_box_i32(608u, INT32_C(12));
    } else if (l0 == 2913u) {
        l1 = vader_box_i32(608u, INT32_C(13));
    } else if (l0 == 3579u) {
        l1 = vader_box_i32(608u, INT32_C(14));
    } else if (l0 == 2978u) {
        l1 = vader_box_i32(608u, INT32_C(15));
    } else if (l0 == 3010u) {
        l1 = vader_box_i32(608u, INT32_C(16));
    } else if (l0 == 1937u) {
        l1 = vader_box_i32(608u, INT32_C(17));
    } else {
        l1 = vader_box_obj(0u, NULL);
    }
    return l1;
}

uint64_t vader_core_bytecode$read_le(void* l0, int64_t l1, int64_t l2) {
    uint64_t l3, l5, l7;
    int64_t l4, l6;
    int64_t t0, t1;
    vader_box_t t2;
    uint8_t t3;
    l3 = (uint64_t) 0;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        t0 = (l3 << INT64_C(8));
        l5 = (uint64_t) (int64_t) t0;
        t0 = vader_chk_add(i64, l1, l2);
        t1 = vader_chk_sub(i64, t0, INT64_C(1));
        l6 = vader_chk_sub(i64, t1, l4);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        t2 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l6, 608u);
        t3 = ((uint8_t) t2.payload.i);
        t0 = ((int64_t) (uint8_t) t3);
        l7 = (uint64_t) (int64_t) t0;
        t0 = (l5 | l7);
        l3 = (uint64_t) (int64_t) t0;
        l4 = (l4 + INT64_C(1));
    }
    return l3;
}

void* vader_core_bytecode$remap_jump_table(void* l0, void* l1, int64_t l2) {
    void* l3 = NULL;
    int64_t l4, l5, l7, l8, l11, l12, l14;
    int32_t l6, l9, l10, l13;
    bool l15;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 1u, 7u, 606u);
    ((int32_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l3 = (void*) _a1_arr;
    l4 = vader_array_length(((vader_array_t*) l0));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l5];
        if ((l6 < INT32_C(0))) {
            l5 = vader_chk_add(i64, l5, INT64_C(1));
            continue;
        }
        l7 = ((int64_t) (int32_t) l6);
        l8 = vader_array_length(((vader_array_t*) l1));
        if ((l7 >= l8)) {
            l5 = vader_chk_add(i64, l5, INT64_C(1));
            continue;
        }
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l9 = ((int32_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l5];
        if ((l9 < INT32_C(0))) {
            l5 = vader_chk_add(i64, l5, INT64_C(1));
            continue;
        }
        l10 = INT32_C(-1);
        l11 = ((int64_t) (int32_t) l6);
        l12 = vader_array_length(((vader_array_t*) l1));
        while ((l11 < l12)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            l13 = ((int32_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l11];
            if ((l13 >= INT32_C(0))) {
                l10 = l13;
                break;
            }
            l11 = (l11 + INT64_C(1));
        }
        if ((l10 < INT32_C(0))) {
            l10 = ((int32_t) (int64_t) l2);
        }
        l14 = ((int64_t) (int32_t) l9);
        if ((INT64_C(0) <= l14)) {
            l15 = (l14 < l2);
        } else {
            l15 = false;
        }
        if (l15) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l9)
            ((int32_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l9] = (int32_t) l10;
        }
        l5 = vader_chk_add(i64, l5, INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_core_bytecode$size_of_bc_type(vader_box_t l0) {
    int32_t l1;
    void* t0;
    if (l0.tag == 1244u) {
        t0 = l0.payload.obj;
        l1 = vader_core_bytecode$size_of_val_type(((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val);
        return l1;
    }
    if ((l0.tag == 1234u || l0.tag == 1237u || l0.tag == 1247u)) {
        l1 = ((int32_t) 8);
    } else {
        if (!((l0.tag == 1243u || l0.tag == 1248u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = ((int32_t) 16);
    }
    return l1;
}

int32_t vader_core_bytecode$size_of_val_type(uint8_t l0) {
    int32_t l1;
    if (l0 == INT32_C(0)) {
        l1 = INT32_C(1);
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = INT32_C(2);
    } else if (l0 == INT32_C(2)) {
        l1 = INT32_C(4);
    } else if (l0 == INT32_C(3)) {
        l1 = INT32_C(8);
    } else if (l0 == INT32_C(4)) {
        l1 = INT32_C(1);
    } else if (l0 == INT32_C(5)) {
        l1 = INT32_C(2);
    } else if (l0 == INT32_C(6)) {
        l1 = INT32_C(4);
    } else if (l0 == INT32_C(7)) {
        l1 = INT32_C(8);
    } else if (l0 == INT32_C(8)) {
        l1 = INT32_C(4);
    } else if (l0 == INT32_C(9)) {
        l1 = INT32_C(8);
    } else if (l0 == INT32_C(10)) {
        l1 = INT32_C(1);
    } else if (l0 == INT32_C(11)) {
        l1 = INT32_C(4);
    } else if (l0 == INT32_C(12)) {
        l1 = INT32_C(4);
    } else if (l0 == INT32_C(13)) {
        l1 = INT32_C(0);
    } else if (l0 == INT32_C(14)) {
        l1 = INT32_C(0);
    } else if (l0 == INT32_C(15)) {
        l1 = INT32_C(8);
    } else if (l0 == INT32_C(16)) {
        l1 = ((int32_t) 8);
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = ((int32_t) 16);
    }
    return l1;
}

int32_t vader_core_bytecode$slot_touched(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (l0.tag == 1351u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 1352u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 1353u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
        return t1;
    }
    if (!(l0.tag == 1350u)) {
        return INT32_C(-1);
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_slot;
    return t1;
}

uint8_t vader_core_bytecode$slot_val_type(void* l0, int32_t l1) {
    void* l2;
    void* l4;
    int32_t l3;
    int64_t l5, l6;
    int64_t t0;
    void* t1;
    vader_box_t t2;
    l2 = ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_signature)->f_params;
    t0 = vader_array_length(((vader_array_t*) l2));
    l3 = ((int32_t) (int64_t) t0);
    if (!((l1 < l3))) {
        l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l0)->f_locals;
        l5 = ((int64_t) (int32_t) l1);
        l6 = vader_array_length(((vader_array_t*) l2));
        l5 = vader_chk_sub(i64, l5, l6);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
        return ((vader_struct_vader_core_bytecode$BcLocal_t*) t1)->f_val;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    t2 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l1, 608u);
    return ((uint8_t) t2.payload.i);
}

vader_box_t vader_core_bytecode$stack_effect(void* l0, void* l1, vader_box_t l2) {
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    int32_t l6;
    void* l7 = NULL;
    void* t0 = NULL;
    int32_t t1;
    bool t2;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_signature)->f_params));
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_locals));
    l3 = vader_chk_add(i64, l3, l4);
    if (l2.tag == 1351u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
        l5 = vader_core_bytecode$indexed_effect(t1, l3, INT64_C(0), INT64_C(1));
        { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 1352u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
        l5 = vader_core_bytecode$indexed_effect(t1, l3, INT64_C(1), INT64_C(0));
    } else if (l2.tag == 1353u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
        l5 = vader_core_bytecode$indexed_effect(t1, l3, INT64_C(1), INT64_C(1));
    } else if (l2.tag == 1350u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_slot;
        l5 = vader_core_bytecode$indexed_effect(t1, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 1375u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$StringConst_t*) t0)->f_index;
        l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_strings));
        l5 = vader_core_bytecode$indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 1276u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
        l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_data_pool));
        l5 = vader_core_bytecode$indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 1299u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
        l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_globals));
        l5 = vader_core_bytecode$indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 1300u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
        l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_globals));
        l5 = vader_core_bytecode$indexed_effect(l6, l3, INT64_C(1), INT64_C(0));
    } else if (l2.tag == 1269u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
        t2 = vader_core_bytecode$in_range(l6, l3);
        if (t2) {
            l7 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions;
            t0 = l2.payload.obj;
            l6 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
            l7 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_signature;
            l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l7)->f_params));
            l4 = vader_core_bytecode$bc_result_arity(l7);
            t0 = vader_core_bytecode$effect(l3, l4);
            l5 = vader_ref_box(t0);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 1270u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
        l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports));
        t2 = vader_core_bytecode$in_range(l6, l3);
        if (t2) {
            l7 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_imports;
            t0 = l2.payload.obj;
            l6 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
            vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
            l7 = ((vader_struct_vader_core_bytecode$BcImport_t*) t0)->f_signature;
            l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l7)->f_params));
            l4 = vader_core_bytecode$bc_result_arity(l7);
            t0 = vader_core_bytecode$effect(l3, l4);
            l5 = vader_ref_box(t0);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 1271u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
        l5 = vader_core_bytecode$indirect_effect(l0, l6);
    } else if (l2.tag == 1398u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_parameter_count;
        if ((t1 < INT32_C(0))) {
            l5 = vader_box_obj(0u, NULL);
        } else {
            t0 = l2.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_parameter_count;
            l3 = ((int64_t) (int32_t) t1);
            t0 = l2.payload.obj;
            l4 = vader_core_bytecode$bc_results_arity(((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_results);
            t0 = vader_core_bytecode$effect(l3, l4);
            l5 = vader_ref_box(t0);
        }
    } else if (l2.tag == 1298u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
        l5 = vader_core_bytecode$indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 1297u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$FnAddr_t*) t0)->f_function_index;
        l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
        l5 = vader_core_bytecode$indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 1355u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
        l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions));
        l5 = vader_core_bytecode$indexed_effect(l6, l3, INT64_C(1), INT64_C(1));
    } else if (l2.tag == 1379u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        l5 = vader_core_bytecode$struct_new_effect(l0, l6);
    } else if (l2.tag == 1225u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_length;
        if ((t1 >= INT32_C(0))) {
            t0 = l2.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_length;
            t0 = vader_core_bytecode$effect(((int64_t) (int32_t) t1), INT64_C(1));
            l5 = vader_ref_box(t0);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 1382u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
        l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types));
        l5 = vader_core_bytecode$indexed_effect(l6, l3, INT64_C(0), INT64_C(1));
    } else if (l2.tag == 1230u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$ArrayReserve_t*) t0)->f_type_id;
        l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types));
        l5 = vader_core_bytecode$indexed_effect(l6, l3, INT64_C(1), INT64_C(1));
    } else if (l2.tag == 1381u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
        l3 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types));
        l5 = vader_core_bytecode$indexed_effect(l6, l3, INT64_C(1), INT64_C(1));
    } else if (l2.tag == 1273u) {
        t0 = l2.payload.obj;
        t2 = vader_core_bytecode$is_integer_val(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_kind);
        if (t2) {
            t0 = vader_core_bytecode$effect(INT64_C(2), INT64_C(1));
            l5 = vader_ref_box(t0);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if (l2.tag == 1274u) {
        t0 = l2.payload.obj;
        t2 = vader_core_bytecode$is_integer_val(((vader_struct_vader_core_bytecode$CheckedNeg_t*) t0)->f_kind);
        if (t2) {
            t0 = vader_core_bytecode$effect(INT64_C(1), INT64_C(1));
            l5 = vader_ref_box(t0);
        } else {
            l5 = vader_box_obj(0u, NULL);
        }
    } else if ((l2.tag == 1257u || l2.tag == 1272u || l2.tag == 1285u || l2.tag == 1306u || l2.tag == 1326u || l2.tag == 1358u || l2.tag == 1399u)) {
        t0 = vader_core_bytecode$effect(INT64_C(0), INT64_C(1));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 1224u || l2.tag == 1228u || l2.tag == 1253u || l2.tag == 1254u || l2.tag == 1260u || l2.tag == 1264u || l2.tag == 1275u || l2.tag == 1283u || l2.tag == 1294u || l2.tag == 1296u || l2.tag == 1303u || l2.tag == 1316u || l2.tag == 1323u || l2.tag == 1336u || l2.tag == 1359u || l2.tag == 1362u || l2.tag == 1365u || l2.tag == 1378u || l2.tag == 1395u)) {
        t0 = vader_core_bytecode$effect(INT64_C(1), INT64_C(1));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 1223u || l2.tag == 1229u || l2.tag == 1256u || l2.tag == 1258u || l2.tag == 1259u || l2.tag == 1261u || l2.tag == 1265u || l2.tag == 1284u || l2.tag == 1286u || l2.tag == 1287u || l2.tag == 1288u || l2.tag == 1289u || l2.tag == 1290u || l2.tag == 1291u || l2.tag == 1292u || l2.tag == 1293u || l2.tag == 1295u || l2.tag == 1301u || l2.tag == 1302u || l2.tag == 1304u || l2.tag == 1305u || l2.tag == 1307u || l2.tag == 1308u || l2.tag == 1309u || l2.tag == 1310u || l2.tag == 1311u || l2.tag == 1312u || l2.tag == 1313u || l2.tag == 1314u || l2.tag == 1315u || l2.tag == 1317u || l2.tag == 1318u || l2.tag == 1319u || l2.tag == 1320u || l2.tag == 1321u || l2.tag == 1322u || l2.tag == 1324u || l2.tag == 1325u || l2.tag == 1327u || l2.tag == 1328u || l2.tag == 1329u || l2.tag == 1330u || l2.tag == 1331u || l2.tag == 1332u || l2.tag == 1333u || l2.tag == 1334u || l2.tag == 1335u || l2.tag == 1337u || l2.tag == 1338u || l2.tag == 1339u || l2.tag == 1340u || l2.tag == 1343u || l2.tag == 1344u || l2.tag == 1345u || l2.tag == 1346u || l2.tag == 1347u || l2.tag == 1348u || l2.tag == 1349u || l2.tag == 1360u || l2.tag == 1361u || l2.tag == 1374u || l2.tag == 1376u || l2.tag == 1377u || l2.tag == 1383u || l2.tag == 1384u || l2.tag == 1385u || l2.tag == 1386u || l2.tag == 1387u || l2.tag == 1388u || l2.tag == 1389u || l2.tag == 1390u || l2.tag == 1391u || l2.tag == 1392u || l2.tag == 1393u || l2.tag == 1394u)) {
        t0 = vader_core_bytecode$effect(INT64_C(2), INT64_C(1));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 1226u || l2.tag == 1227u || l2.tag == 1380u || l2.tag == 1396u)) {
        t0 = vader_core_bytecode$effect(INT64_C(2), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 1231u || l2.tag == 1266u || l2.tag == 1367u || l2.tag == 1368u || l2.tag == 1369u || l2.tag == 1370u || l2.tag == 1371u || l2.tag == 1372u || l2.tag == 1373u)) {
        t0 = vader_core_bytecode$effect(INT64_C(3), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if (l2.tag == 1232u) {
        t0 = vader_core_bytecode$effect(INT64_C(3), INT64_C(1));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 1222u || l2.tag == 1357u)) {
        t0 = vader_core_bytecode$effect(INT64_C(5), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 1221u || l2.tag == 1279u || l2.tag == 1280u)) {
        t0 = vader_core_bytecode$effect(INT64_C(1), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 1255u || l2.tag == 1278u || l2.tag == 1282u || l2.tag == 1354u)) {
        t0 = vader_core_bytecode$effect(INT64_C(0), INT64_C(0));
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 1263u || l2.tag == 1341u)) {
        vader_struct_vader_core_bytecode$StackEffect_t* _a2_obj = (vader_struct_vader_core_bytecode$StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StackEffect_t));
        vader_obj_header_init(_a2_obj, 1366u);
        _a2_obj->f_pops = INT64_C(1);
        _a2_obj->f_pushes = INT64_C(0);
        _a2_obj->f_flow = (uint8_t) 2;
        t0 = (void*) _a2_obj;
        l5 = vader_ref_box(t0);
    } else if ((l2.tag == 1262u || l2.tag == 1281u)) {
        vader_struct_vader_core_bytecode$StackEffect_t* _a3_obj = (vader_struct_vader_core_bytecode$StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StackEffect_t));
        vader_obj_header_init(_a3_obj, 1366u);
        _a3_obj->f_pops = INT64_C(0);
        _a3_obj->f_pushes = INT64_C(0);
        _a3_obj->f_flow = (uint8_t) 1;
        t0 = (void*) _a3_obj;
        l5 = vader_ref_box(t0);
    } else {
        if (!((l2.tag == 1363u || l2.tag == 1364u || l2.tag == 1397u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_struct_vader_core_bytecode$StackEffect_t* _a4_obj = (vader_struct_vader_core_bytecode$StackEffect_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StackEffect_t));
        vader_obj_header_init(_a4_obj, 1366u);
        _a4_obj->f_pops = INT64_C(0);
        _a4_obj->f_pushes = INT64_C(0);
        _a4_obj->f_flow = (uint8_t) 3;
        t0 = (void*) _a4_obj;
        l5 = vader_ref_box(t0);
    }
    { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_bytecode$struct_at(void* l0, int32_t l1) {
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    if ((l1 < INT32_C(0))) {
        return vader_box_obj(0u, NULL);
    }
    l2 = ((int64_t) (int32_t) l1);
    l3 = vader_array_length(((vader_array_t*) l0));
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (!(l4.tag == 1247u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l4.payload.obj;
    return vader_ref_box(t0);
}

static vader_box_t vader_core_bytecode$struct_new_effect(void* l0, int32_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_core_bytecode$struct_at(((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_types, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l3.payload.obj;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) l2)->f_fields));
    t1 = vader_core_bytecode$effect(t0, INT64_C(1));
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_core_bytecode$struct_symbol_type_index(void* l0, int32_t l1) {
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    int32_t t1;
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
        if (l4.tag == 1247u) {
            t0 = l4.payload.obj;
            t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_symbol_id;
            if (t1 == l1) {
                return ((int32_t) (int64_t) l2);
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    return INT32_C(-1);
}

vader_box_t vader_core_bytecode$union_layout_struct(void* l0, int32_t l1) {
    vader_box_t l2;
    int32_t l3;
    void* t0;
    int64_t t1;
    vader_box_t t2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l2 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    if (l2.tag == 1248u) {
        t0 = l2.payload.obj;
        t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_bytecode$BcUnion_t*) t0)->f_variants));
        if (t1 == INT64_C(0)) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l2.payload.obj;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcUnion_t*) t0)->f_variants);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        l3 = ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0)];
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        t2 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l3);
        if (!(t2.tag == 1247u)) {
            return vader_box_obj(0u, NULL);
        }
        return vader_box_i32(606u, l3);
    }
    return vader_box_obj(0u, NULL);
}

vader_string_t vader_core_bytecode$val_type_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2597u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2552u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2553u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2575u;
    } else if (l0 == INT32_C(4)) {
        l1 = 3333u;
    } else if (l0 == INT32_C(5)) {
        l1 = 3312u;
    } else if (l0 == INT32_C(6)) {
        l1 = 3313u;
    } else if (l0 == INT32_C(7)) {
        l1 = 3323u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2407u;
    } else if (l0 == INT32_C(9)) {
        l1 = 2409u;
    } else if (l0 == INT32_C(10)) {
        l1 = 2027u;
    } else if (l0 == INT32_C(11)) {
        l1 = 2165u;
    } else if (l0 == INT32_C(12)) {
        l1 = 3128u;
    } else if (l0 == INT32_C(13)) {
        l1 = 2913u;
    } else if (l0 == INT32_C(14)) {
        l1 = 3579u;
    } else if (l0 == INT32_C(15)) {
        l1 = 2978u;
    } else if (l0 == INT32_C(16)) {
        l1 = 3010u;
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1937u;
    }
    return l1;
}

static int64_t vader_core_bytecode$value_cell(uint8_t l0, int64_t l1) {
    if (!(l0 == INT32_C(6))) {
        return l1;
    }
    return ((int64_t) (int32_t) ((int32_t) (int64_t) l1));
}

vader_box_t vader_core_bytecode$with_remapped_slot(vader_box_t l0, int32_t l1) {
    int32_t l2, l3;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1351u) {
        vader_struct_vader_core_bytecode$LocalGet_t* _a0_obj = (vader_struct_vader_core_bytecode$LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalGet_t));
        vader_obj_header_init(_a0_obj, 1351u);
        _a0_obj->f_slot = l1;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1352u) {
        vader_struct_vader_core_bytecode$LocalSet_t* _a1_obj = (vader_struct_vader_core_bytecode$LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalSet_t));
        vader_obj_header_init(_a1_obj, 1352u);
        _a1_obj->f_slot = l1;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1353u) {
        vader_struct_vader_core_bytecode$LocalTee_t* _a2_obj = (vader_struct_vader_core_bytecode$LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalTee_t));
        vader_obj_header_init(_a2_obj, 1353u);
        _a2_obj->f_slot = l1;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 1350u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_type_id;
    t0 = l0.payload.obj;
    l3 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_field_index;
    vader_struct_vader_core_bytecode$LocalField_t* _a3_obj = (vader_struct_vader_core_bytecode$LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalField_t));
    vader_obj_header_init(_a3_obj, 1350u);
    _a3_obj->f_slot = l1;
    _a3_obj->f_type_id = l2;
    _a3_obj->f_field_index = l3;
    t0 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_core_bytecode$write_le(void* l0, int64_t l1, int64_t l2, uint64_t l3) {
    uint64_t l4;
    int64_t l5, l6;
    uint8_t l7;
    int32_t t0;
    l4 = l3;
    l5 = INT64_C(0);
    while ((l5 < l2)) {
        l6 = vader_chk_add(i64, l1, l5);
        t0 = (((int32_t) (int64_t) (l4 & INT64_C(255))) & INT32_C(255));
        l7 = (uint8_t) (int32_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l6] = (uint8_t) (int32_t) (uint8_t) l7;
        l4 = (l4 >> INT64_C(8));
        l5 = (l5 + INT64_C(1));
    }
    return;
}
