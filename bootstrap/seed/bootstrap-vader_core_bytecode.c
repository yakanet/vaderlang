#include "bootstrap.split.h"

static vader_box_t vader_core_bytecode$c_field_align_at(void* l0, void* l1, int32_t l2);
static vader_box_t vader_core_bytecode$c_field_width_at(void* l0, void* l1, int32_t l2);
static void* vader_core_bytecode$c_struct_layout_at(void* l0, void* l1, int32_t l2);
static int64_t vader_core_bytecode$cell_value(uint8_t l0, int64_t l1);
static int64_t vader_core_bytecode$integer_bits(uint8_t l0);
static vader_box_t vader_core_bytecode$integer_op(uint8_t l0, int64_t l1, bool l2, int64_t l3, int64_t l4);
static bool vader_core_bytecode$is_display_to_string(vader_string_t l0);
static bool vader_core_bytecode$is_int_equals(vader_string_t l0);
static vader_string_t vader_core_bytecode$key_join(void* l0, void* l1, vader_string_t l2);
static int64_t vader_core_bytecode$value_cell(uint8_t l0, int64_t l1);

uint8_t vader_core_bytecode$array_kind_from_name(vader_string_t l0) {
    uint8_t l1;
    if (l0 == 2794u) {
        l1 = (uint8_t) 1;
        return l1;
    }
    if (l0 == 2773u) {
        l1 = (uint8_t) 2;
    } else if (l0 == 2774u) {
        l1 = (uint8_t) 3;
    } else if (l0 == 2784u) {
        l1 = (uint8_t) 4;
    } else if (l0 == 2119u) {
        l1 = (uint8_t) 5;
    } else if (l0 == 2074u) {
        l1 = (uint8_t) 6;
    } else if (l0 == 2075u) {
        l1 = (uint8_t) 7;
    } else if (l0 == 2097u) {
        l1 = (uint8_t) 8;
    } else if (l0 == 1950u) {
        l1 = (uint8_t) 9;
    } else if (l0 == 1952u) {
        l1 = (uint8_t) 10;
    } else if (l0 == 1745u) {
        l1 = (uint8_t) 11;
    } else if (l0 == 1627u) {
        l1 = (uint8_t) 12;
    } else if (l0 == 2497u) {
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
        l1 = 2794u;
        return l1;
    }
    if (l0 == INT32_C(5)) {
        l1 = 2119u;
    } else if (l0 == INT32_C(12)) {
        l1 = 1627u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2773u;
    } else if (l0 == INT32_C(6)) {
        l1 = 2074u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2774u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2075u;
    } else if (l0 == INT32_C(9)) {
        l1 = 1950u;
    } else if (l0 == INT32_C(11)) {
        l1 = 1745u;
    } else if (l0 == INT32_C(4)) {
        l1 = 2784u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2097u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1952u;
    } else if (l0 == INT32_C(13)) {
        l1 = 2497u;
    } else {
        if (!(l0 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1636u;
    }
    return l1;
}

uint8_t vader_core_bytecode$array_kind_of(vader_box_t l0, void* l1) {
    uint8_t l2;
    void* t0;
    bool t1;
    if (l0.tag == 743u) {
        t0 = l0.payload.obj;
        l2 = vader_core_bytecode$array_kind_of_val(((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val);
        return l2;
    }
    if (l0.tag == 746u) {
        l2 = (uint8_t) 13;
    } else if (l0.tag == 733u) {
        l2 = (uint8_t) 13;
    } else if (l0.tag == 736u) {
        l2 = (uint8_t) 13;
    } else if (l0.tag == 747u) {
        t0 = l0.payload.obj;
        t1 = vader_core_bytecode$is_ref_only_element(vader_ref_box(t0), l1);
        if (t1) {
            l2 = (uint8_t) 13;
        } else {
            l2 = (uint8_t) 0;
        }
    } else {
        if (!(l0.tag == 742u)) {
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
    t0 = ((vader_array_t*) l0)->length;
    if (t0 == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 340u);
        if (((int32_t) t1.payload.i) == INT32_C(14)) {
            return INT64_C(0);
        }
        t0 = ((vader_array_t*) l0)->length;
        return t0;
    }
    t0 = ((vader_array_t*) l0)->length;
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
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_results)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 14; }
    }
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_results)->length;
    if (!((t0 > INT64_C(1)))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_results);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 340u);
        { uint8_t __vret = ((uint8_t) t1.payload.i); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) vader_buffer_new((size_t) INT64_C(125));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 1679u);
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_results)->length;
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 209u);
    t2 = std_core$finish_buffer(l1, l2);
    vader_host_std_abort$panic(t2);
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
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_result_types)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(0); }
    }
    t0 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_result_types)->length;
    if (!((t0 > INT64_C(1)))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_result_types);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
        { int32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) vader_buffer_new((size_t) INT64_C(130));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 1678u);
    l3 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_result_types)->length;
    l2 = std_core$write_int(l1, l2, l3);
    l2 = std_core$write_string_at(l1, l2, 209u);
    t2 = std_core$finish_buffer(l1, l2);
    vader_host_std_abort$panic(t2);
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
        l4 = ((vader_array_t*) l0)->length;
        l2 = (l3 >= l4);
    }
    if (l2) {
        { vader_gc_top = gc_frame.prev; return 529u; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    l6 = l5;
    if (l5.tag == 743u) {
        l8 = (void*) vader_buffer_new((size_t) INT64_C(22));
        l3 = INT64_C(0);
        l3 = std_core$write_string_at(l8, l3, 2443u);
        t0 = l6.payload.obj;
        l4 = ((int64_t) (int32_t) ((int32_t) (uint8_t) ((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val));
        l3 = std_core$write_int(l8, l3, l4);
        l7 = std_core$finish_buffer(l8, l3);
        { vader_string_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 746u) {
        t0 = l6.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcStruct_t*) t0)->f_name;
        l7 = concat_2(2531u, l9);
    } else if (l5.tag == 742u) {
        t0 = l6.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$BcRef_t*) t0)->f_trait_name;
        l7 = concat_2(2481u, l9);
    } else if (l5.tag == 733u) {
        t0 = l6.payload.obj;
        l10 = ((vader_struct_vader_core_bytecode$BcArray_t*) t0)->f_element;
        l9 = vader_core_bytecode$bc_type_key(l0, l10);
        l7 = concat_3(1500u, l9, 525u);
    } else if (l5.tag == 747u) {
        t0 = l6.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t0)->f_variants;
        l9 = vader_core_bytecode$key_join(l0, l8, 3057u);
        l7 = concat_3(2795u, l9, 525u);
    } else {
        if (!(l5.tag == 736u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l6.payload.obj;
        l8 = ((vader_struct_vader_core_bytecode$BcFn_t*) t0)->f_params;
        l9 = vader_core_bytecode$key_join(l0, l8, 3057u);
        t0 = l6.payload.obj;
        l10 = ((vader_struct_vader_core_bytecode$BcFn_t*) t0)->f_return_type;
        l11 = vader_core_bytecode$bc_type_key(l0, l10);
        l7 = concat_4(1966u, l9, 344u, l11);
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
        return vader_box_i64(339u, ((int64_t) (int32_t) t1));
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
    l6 = ((vader_array_t*) l4)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
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
    return vader_box_i64(339u, l5);
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
    l3 = ((vader_array_t*) l1)->length;
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    l4 = ((vader_struct_vader_core_bytecode$BcField_t*) l0)->f_type_index;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    if (!(l5.tag == 743u)) {
        return vader_box_obj(0u, NULL);
    }
    t1 = l5.payload.obj;
    return vader_box_i32(340u, (int32_t)(uint32_t) ((vader_struct_vader_core_bytecode$BcScalar_t*) t1)->f_val);
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
        { vader_box_t __vret = vader_box_i64(339u, ((int64_t) (int32_t) t1)); vader_gc_top = gc_frame.prev; return __vret; }
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
    { vader_box_t __vret = vader_box_i64(339u, t2); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_bytecode$c_result_type(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_result_c_type;
    if (!(t0 == 0u)) {
        t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_result_c_type;
        return vader_box_string(335u, t0);
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
    vader_array_t* _a0_arr = vader_array_new(24u, 0u, 8u, 339u);
    l3 = (void*) _a0_arr;
    l4 = INT64_C(0);
    l5 = INT64_C(1);
    l6 = vader_box_obj(0u, NULL);
    l7 = l0;
    l8 = ((vader_array_t*) l7)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l10 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
        l11 = vader_core_bytecode$c_field_width_at(l10, l1, l2);
        l12 = vader_core_bytecode$c_field_align_at(l10, l1, l2);
        if (l11.tag == 0u) {
            if (l6.tag == 0u) {
                t0 = ((vader_struct_vader_core_bytecode$BcField_t*) l10)->f_name;
                l6 = vader_box_string(335u, t0);
            }
            vader_array_push_i64((vader_array_t*) l3, l4);
            l9 = (l9 + INT64_C(1));
            continue;
        }
        if (l12.tag == 0u) {
            if (l6.tag == 0u) {
                t0 = ((vader_struct_vader_core_bytecode$BcField_t*) l10)->f_name;
                l6 = vader_box_string(335u, t0);
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
        vader_obj_header_init(_a2_obj, 767u);
        _a2_obj->f_offsets = l3;
        _a2_obj->f_size = l9;
        _a2_obj->f_unknown_field = l6;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_chk_add(i64, l4, l5);
    l9 = vader_chk_sub(i64, t2, l8);
    vader_struct_vader_core_bytecode$CLayout_t* _a3_obj = (vader_struct_vader_core_bytecode$CLayout_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$CLayout_t));
    vader_obj_header_init(_a3_obj, 767u);
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
    return vader_box_i64(339u, t0);
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
    return vader_box_i64(339u, t0);
}

vader_string_t vader_core_bytecode$checked_neg_message(uint8_t l0) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[2] = { &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$val_type_name(l0);
    t1 = concat_2(t0, 423u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_bytecode$checked_op_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 1506u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2673u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2356u;
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
    t0 = concat_4(l2, 399u, l3, 195u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_bytecode$const_op_of(vader_box_t l0) {
    if (!((l0.tag == 756u || l0.tag == 771u || l0.tag == 784u || l0.tag == 805u || l0.tag == 825u || l0.tag == 856u || l0.tag == 872u))) {
        return vader_box_obj(0u, NULL);
    }
    return l0;
}

vader_box_t vader_core_bytecode$convert_target_of(uint8_t l0) {
    vader_box_t l1;
    if (l0 == INT32_C(0)) {
        l1 = vader_box_i32(340u, INT32_C(0));
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = vader_box_i32(340u, INT32_C(0));
    } else if (l0 == INT32_C(2)) {
        l1 = vader_box_i32(340u, INT32_C(0));
    } else if (l0 == INT32_C(4)) {
        l1 = vader_box_i32(340u, INT32_C(0));
    } else if (l0 == INT32_C(5)) {
        l1 = vader_box_i32(340u, INT32_C(0));
    } else if (l0 == INT32_C(6)) {
        l1 = vader_box_i32(340u, INT32_C(0));
    } else if (l0 == INT32_C(3)) {
        l1 = vader_box_i32(340u, INT32_C(1));
    } else if (l0 == INT32_C(7)) {
        l1 = vader_box_i32(340u, INT32_C(1));
    } else if (l0 == INT32_C(8)) {
        l1 = vader_box_i32(340u, INT32_C(2));
    } else if (l0 == INT32_C(9)) {
        l1 = vader_box_i32(340u, INT32_C(2));
    } else if (l0 == INT32_C(11)) {
        l1 = vader_box_i32(340u, INT32_C(3));
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
    int64_t l2, l4, l6, l7, l9, l10;
    vader_box_t l8 = vader_box_null();
    int32_t l11, l12;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 1u, 7u, 338u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(0);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_data_pool)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    t0 = ((vader_array_t*) l1)->length;
    if (t0 == INT64_C(0)) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l0)->f_functions;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t1)->f_body;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l8 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
            if (l8.tag == 775u) {
                t1 = l8.payload.obj;
                t2 = ((vader_struct_vader_core_bytecode$DataConst_t*) t1)->f_pool_index;
                if ((t2 >= INT32_C(0))) {
                    t1 = l8.payload.obj;
                    t2 = ((vader_struct_vader_core_bytecode$DataConst_t*) t1)->f_pool_index;
                    l9 = ((int64_t) (int32_t) t2);
                    l10 = ((vader_array_t*) l1)->length;
                    if ((l9 < l10)) {
                        t1 = l8.payload.obj;
                        l11 = ((vader_struct_vader_core_bytecode$DataConst_t*) t1)->f_pool_index;
                        t1 = l8.payload.obj;
                        l12 = ((vader_struct_vader_core_bytecode$DataConst_t*) t1)->f_type_id;
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
                        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l11] = (int32_t) l12;
                    }
                }
            }
            l7 = (l7 + INT64_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
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

uint8_t vader_core_bytecode$intrinsic_id_for(vader_string_t l0) {
    vader_string_t l1 = 0;
    bool t0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$is_int_equals(l0);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 9; }
    }
    t0 = vader_core_bytecode$is_display_to_string(l0);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 10; }
    }
    if (l0 == 2975u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 21; }
    }
    if (l0 == 2977u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 23; }
    }
    if (l0 == 2973u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 24; }
    }
    if (l0 == 2976u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 22; }
    }
    if (l0 == 2974u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 25; }
    }
    if (l0 == 2601u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 1; }
    }
    if (l0 == 2600u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 2; }
    }
    if (l0 == 2602u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 3; }
    }
    if (l0 == 2607u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 4; }
    }
    if (l0 == 2603u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 5; }
    }
    if (l0 == 2604u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 6; }
    }
    l1 = vader_core_bytecode$primitive_member_mangle(2638u, 658u, 2066u);
    if (l0 == l1) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 7; }
    }
    if (l0 == 2610u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 8; }
    }
    if (l0 == 2615u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 11; }
    }
    if (l0 == 2616u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 12; }
    }
    if (l0 == 2614u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 13; }
    }
    if (l0 == 2613u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 14; }
    }
    if (l0 == 2618u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 15; }
    }
    if (l0 == 2617u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 16; }
    }
    if (l0 == 2619u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 17; }
    }
    if (l0 == 2621u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 19; }
    }
    if (l0 == 2620u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 20; }
    }
    if (!(l0 == 2593u)) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 18; }
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
        if (l0 == INT32_C(19)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(20);
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
                l2 = l0 == INT32_C(10);
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
                    l1 = true;
                } else {
                    if (l0 == INT32_C(11)) {
                        l2 = true;
                    } else {
                        l2 = l0 == INT32_C(12);
                    }
                    if (l2) {
                        l2 = true;
                    } else {
                        l2 = l0 == INT32_C(13);
                    }
                    if (l2) {
                        l2 = true;
                    } else {
                        l2 = l0 == INT32_C(14);
                    }
                    if (l2) {
                        l1 = true;
                    } else {
                        if (l0 == INT32_C(15)) {
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
                            l1 = true;
                        } else {
                            if (l0 == INT32_C(21)) {
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
                            if (l2) {
                                l2 = true;
                            } else {
                                l2 = l0 == INT32_C(0);
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
        l2 = true;
    } else {
        l2 = l0 == INT32_C(8);
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
        l2 = true;
    } else {
        l2 = l0 == INT32_C(10);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(9);
    }
    if (l2) {
        l1 = false;
    } else {
        if (l0 == INT32_C(11)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(12);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(13);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(14);
        }
        if (l2) {
            l1 = false;
        } else {
            if (l0 == INT32_C(15)) {
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
                l1 = false;
            } else {
                if (l0 == INT32_C(19)) {
                    l2 = true;
                } else {
                    l2 = l0 == INT32_C(20);
                }
                if (l2) {
                    l2 = true;
                } else {
                    l2 = l0 == INT32_C(18);
                }
                if (l2) {
                    l1 = false;
                } else {
                    if (l0 == INT32_C(21)) {
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
                    if (l2) {
                        l1 = false;
                    } else {
                        if (!(l0 == INT32_C(0))) {
                            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                        }
                        l1 = true;
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

static bool vader_core_bytecode$is_display_to_string(vader_string_t l0) {
    vader_box_t l1;
    bool l2;
    vader_string_t t0;
    l1 = vader_core_bytecode$strip_core_member(l0, 263u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_core_types$is_scalar_type_name(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        l2 = t0 != 3005u;
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        return t0 != 2408u;
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

static bool vader_core_bytecode$is_int_equals(vader_string_t l0) {
    vader_box_t l1;
    vader_string_t t0;
    bool t1;
    l1 = vader_core_bytecode$strip_core_member(l0, 265u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        t1 = vader_core_types$is_int_name(t0);
        return t1;
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
    if (l0.tag == 746u) {
        l2 = true;
        return l2;
    }
    if (l0.tag == 733u) {
        l2 = true;
    } else if (l0.tag == 736u) {
        l2 = true;
    } else if (l0.tag == 743u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val == INT32_C(13);
    } else if (l0.tag == 742u) {
        l2 = false;
    } else {
        if (!(l0.tag == 747u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$BcUnion_t*) t0)->f_variants;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
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

bool vader_core_bytecode$is_unsigned_display(vader_string_t l0) {
    vader_box_t l1;
    vader_string_t t0;
    bool t1;
    l1 = vader_core_bytecode$strip_core_member(l0, 263u);
    if (l1.tag == 0u) {
        return false;
    }
    t0 = l1.payload.s;
    t1 = vader_core_types$is_unsigned_int_name(t0);
    return t1;
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

static vader_string_t vader_core_bytecode$key_join(void* l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    int64_t l4, l6;
    int32_t l7;
    vader_string_t l8 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l5 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l8, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) l1)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    l5 = l1;
    l4 = ((vader_array_t*) l5)->length;
    l6 = INT64_C(0);
    while ((l6 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
        l8 = vader_core_bytecode$bc_type_key(l0, l7);
        vader_array_push_scalar((vader_array_t*) l3, vader_box_string(335u, l8));
        l6 = (l6 + INT64_C(1));
    }
    t0 = std_string$join(l3, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    t0 = ((vader_struct_std_ffi$CLibrary_t*) l1)->f_name;
    return t0;
}

int32_t vader_core_bytecode$main_function_index(void* l0) {
    int64_t l1, l2;
    void* t0;
    bool t1;
    l1 = INT64_C(0);
    l2 = ((vader_array_t*) l0)->length;
    while ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
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
    vader_array_t* _a0_arr = vader_array_new(20u, 1u, 12u, 333u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l5 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
        if ((l5 >= INT32_C(0))) {
            if ((((int64_t) (int32_t) l5) < l1)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5] = (uint8_t) true;
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
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
    return (l0.tag == 721u || l0.tag == 728u);
}

vader_box_t vader_core_bytecode$param_c_type(void* l0, int64_t l1) {
    int64_t l2;
    vader_box_t t0;
    vader_string_t t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_param_c_types)->length;
    if ((l1 >= l2)) {
        return vader_box_obj(0u, NULL);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_param_c_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l1];
    t1 = t0.payload.s;
    if (!(t1 == 0u)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_param_c_types);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        t1 = t0.payload.s;
        return vader_box_string(335u, t1);
    }
    return vader_box_obj(0u, NULL);
}

bool vader_core_bytecode$param_is_by_address(void* l0, int64_t l1) {
    int64_t l2;
    bool t0, t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_param_by_address)->length;
    if ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_param_by_address);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
        t1 = t0;
        return t1;
    }
    return false;
}

bool vader_core_bytecode$param_is_c_out(void* l0, int64_t l1) {
    int64_t l2;
    bool t0, t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_param_c_out)->length;
    if ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcSignature_t*) l0)->f_param_c_out);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
        t1 = t0;
        return t1;
    }
    return false;
}

vader_box_t vader_core_bytecode$parse_val_type(vader_string_t l0) {
    vader_box_t l1;
    if (l0 == 2119u) {
        l1 = vader_box_i32(340u, INT32_C(0));
        return l1;
    }
    if (l0 == 2074u) {
        l1 = vader_box_i32(340u, INT32_C(1));
    } else if (l0 == 2075u) {
        l1 = vader_box_i32(340u, INT32_C(2));
    } else if (l0 == 2097u) {
        l1 = vader_box_i32(340u, INT32_C(3));
    } else if (l0 == 2794u) {
        l1 = vader_box_i32(340u, INT32_C(4));
    } else if (l0 == 2773u) {
        l1 = vader_box_i32(340u, INT32_C(5));
    } else if (l0 == 2774u) {
        l1 = vader_box_i32(340u, INT32_C(6));
    } else if (l0 == 2784u) {
        l1 = vader_box_i32(340u, INT32_C(7));
    } else if (l0 == 1950u) {
        l1 = vader_box_i32(340u, INT32_C(8));
    } else if (l0 == 1952u) {
        l1 = vader_box_i32(340u, INT32_C(9));
    } else if (l0 == 1627u) {
        l1 = vader_box_i32(340u, INT32_C(10));
    } else if (l0 == 1745u) {
        l1 = vader_box_i32(340u, INT32_C(11));
    } else if (l0 == 2638u) {
        l1 = vader_box_i32(340u, INT32_C(12));
    } else if (l0 == 2408u) {
        l1 = vader_box_i32(340u, INT32_C(13));
    } else if (l0 == 3005u) {
        l1 = vader_box_i32(340u, INT32_C(14));
    } else if (l0 == 2468u) {
        l1 = vader_box_i32(340u, INT32_C(15));
    } else if (l0 == 2497u) {
        l1 = vader_box_i32(340u, INT32_C(16));
    } else if (l0 == 1544u) {
        l1 = vader_box_i32(340u, INT32_C(17));
    } else {
        l1 = vader_box_obj(0u, NULL);
    }
    return l1;
}

vader_string_t vader_core_bytecode$primitive_member_mangle(vader_string_t l0, vader_string_t l1, vader_string_t l2) {
    vader_string_t t0;
    t0 = concat_6(2594u, l0, 259u, l1, 259u, l2);
    return t0;
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
        t2 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l6, 340u);
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
    vader_array_t* _a0_arr = vader_array_new(23u, 1u, 7u, 338u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l3 = (void*) _a1_arr;
    l4 = ((vader_array_t*) l0)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
        if ((l6 < INT32_C(0))) {
            l5 = vader_chk_add(i64, l5, INT64_C(1));
            continue;
        }
        l7 = ((int64_t) (int32_t) l6);
        l8 = ((vader_array_t*) l1)->length;
        if ((l7 >= l8)) {
            l5 = vader_chk_add(i64, l5, INT64_C(1));
            continue;
        }
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l9 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
        if ((l9 < INT32_C(0))) {
            l5 = vader_chk_add(i64, l5, INT64_C(1));
            continue;
        }
        l10 = INT32_C(-1);
        l11 = ((int64_t) (int32_t) l6);
        l12 = ((vader_array_t*) l1)->length;
        while ((l11 < l12)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            l13 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l11];
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
            ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l9] = (int32_t) l10;
        }
        l5 = vader_chk_add(i64, l5, INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_core_bytecode$size_of_bc_type(vader_box_t l0) {
    int32_t l1;
    void* t0;
    if (l0.tag == 743u) {
        t0 = l0.payload.obj;
        l1 = vader_core_bytecode$size_of_val_type(((vader_struct_vader_core_bytecode$BcScalar_t*) t0)->f_val);
        return l1;
    }
    if ((l0.tag == 733u || l0.tag == 736u || l0.tag == 746u)) {
        l1 = ((int32_t) 8);
    } else {
        if (!((l0.tag == 742u || l0.tag == 747u))) {
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
    if (l0.tag == 850u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 851u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 852u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
        return t1;
    }
    if (!(l0.tag == 849u)) {
        return INT32_C(-1);
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_slot;
    return t1;
}

vader_box_t vader_core_bytecode$strip_core_member(vader_string_t l0, vader_string_t l1) {
    int64_t l2, l3, l4;
    bool t0;
    vader_string_t t1;
    t0 = std_string$starts_with(l0, 2594u);
    if (t0) {
        t0 = std_string$ends_with(l0, l1);
        if (t0) {
            l2 = vader_host_std_core$byte_len(2594u);
            l3 = vader_host_std_core$byte_len(l0);
            l4 = vader_host_std_core$byte_len(l1);
            l3 = vader_chk_sub(i64, l3, l4);
            t1 = vader_host_std_core$byte_slice(l0, l2, l3);
            return vader_box_string(335u, t1);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

vader_box_t vader_core_bytecode$struct_at(void* l0, int32_t l1) {
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    if ((l1 < INT32_C(0))) {
        return vader_box_obj(0u, NULL);
    }
    l2 = ((int64_t) (int32_t) l1);
    l3 = ((vader_array_t*) l0)->length;
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (!(l4.tag == 746u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l4.payload.obj;
    return vader_ref_box(t0);
}

int32_t vader_core_bytecode$struct_symbol_type_index(void* l0, int32_t l1) {
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    int32_t t1;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 746u) {
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
    l2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (l2.tag == 747u) {
        t0 = l2.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcUnion_t*) t0)->f_variants)->length;
        if (t1 == INT64_C(0)) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l2.payload.obj;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcUnion_t*) t0)->f_variants);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        l3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) INT32_C(0)];
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
        if (!(t2.tag == 746u)) {
            return vader_box_obj(0u, NULL);
        }
        return vader_box_i32(338u, l3);
    }
    return vader_box_obj(0u, NULL);
}

vader_string_t vader_core_bytecode$val_type_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2119u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2074u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2075u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2097u;
    } else if (l0 == INT32_C(4)) {
        l1 = 2794u;
    } else if (l0 == INT32_C(5)) {
        l1 = 2773u;
    } else if (l0 == INT32_C(6)) {
        l1 = 2774u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2784u;
    } else if (l0 == INT32_C(8)) {
        l1 = 1950u;
    } else if (l0 == INT32_C(9)) {
        l1 = 1952u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1627u;
    } else if (l0 == INT32_C(11)) {
        l1 = 1745u;
    } else if (l0 == INT32_C(12)) {
        l1 = 2638u;
    } else if (l0 == INT32_C(13)) {
        l1 = 2408u;
    } else if (l0 == INT32_C(14)) {
        l1 = 3005u;
    } else if (l0 == INT32_C(15)) {
        l1 = 2468u;
    } else if (l0 == INT32_C(16)) {
        l1 = 2497u;
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1544u;
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
    if (l0.tag == 850u) {
        vader_struct_vader_core_bytecode$LocalGet_t* _a0_obj = (vader_struct_vader_core_bytecode$LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalGet_t));
        vader_obj_header_init(_a0_obj, 850u);
        _a0_obj->f_slot = l1;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 851u) {
        vader_struct_vader_core_bytecode$LocalSet_t* _a1_obj = (vader_struct_vader_core_bytecode$LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalSet_t));
        vader_obj_header_init(_a1_obj, 851u);
        _a1_obj->f_slot = l1;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 852u) {
        vader_struct_vader_core_bytecode$LocalTee_t* _a2_obj = (vader_struct_vader_core_bytecode$LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalTee_t));
        vader_obj_header_init(_a2_obj, 852u);
        _a2_obj->f_slot = l1;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 849u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_type_id;
    t0 = l0.payload.obj;
    l3 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_field_index;
    vader_struct_vader_core_bytecode$LocalField_t* _a3_obj = (vader_struct_vader_core_bytecode$LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LocalField_t));
    vader_obj_header_init(_a3_obj, 849u);
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
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6] = (uint8_t) (int32_t) (uint8_t) l7;
        l4 = (l4 >> INT64_C(8));
        l5 = (l5 + INT64_C(1));
    }
    return;
}
