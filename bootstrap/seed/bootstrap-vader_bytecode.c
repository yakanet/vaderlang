#include "bootstrap.split.h"

static uint64_t vader_bytecode_argument_hash(vader_box_t l0);
static uint64_t vader_bytecode_argument_hashes(uint64_t l0, void* l1);
static vader_string_t vader_bytecode_argument_key(vader_box_t l0);
static vader_string_t vader_bytecode_argument_keys(void* l0);
static vader_box_t vader_bytecode_arith_op(uint8_t l0, vader_string_t l1);
static uint64_t vader_bytecode_bare_hash(vader_string_t l0);
static vader_string_t vader_bytecode_bare_intern_name(vader_box_t l0);
static void* vader_bytecode_bc_peephole_unchanged(void* l0);
static vader_box_t vader_bytecode_bc_type_of_with_ctx(vader_box_t l0, void* l1, int32_t l2);
static vader_box_t vader_bytecode_bit_op(uint8_t l0, vader_string_t l1);
static vader_box_t vader_bytecode_bitnot_op(uint8_t l0);
static vader_box_t vader_bytecode_c_field_align_at(void* l0, void* l1, int32_t l2);
static vader_box_t vader_bytecode_c_field_width_at(void* l0, void* l1, int32_t l2);
static vader_string_t vader_bytecode_c_safe_key(vader_string_t l0);
static void* vader_bytecode_c_struct_layout_at(void* l0, void* l1, int32_t l2);
static int64_t vader_bytecode_cell_value(uint8_t l0, int64_t l1);
static vader_box_t vader_bytecode_checked_arith_op(uint8_t l0, uint8_t l1);
static vader_box_t vader_bytecode_checked_neg_op(uint8_t l0);
static vader_box_t vader_bytecode_cmp_eq(uint8_t l0);
static vader_box_t vader_bytecode_cmp_ge(uint8_t l0);
static vader_box_t vader_bytecode_cmp_gt(uint8_t l0);
static vader_box_t vader_bytecode_cmp_le(uint8_t l0);
static vader_box_t vader_bytecode_cmp_lt(uint8_t l0);
static vader_box_t vader_bytecode_cmp_ne(uint8_t l0);
static bool vader_bytecode_const_fills_slot(vader_box_t l0, uint8_t l1);
static uint8_t vader_bytecode_const_val_type(vader_box_t l0);
static vader_string_t vader_bytecode_convert_target_name(uint8_t l0);
static vader_box_t vader_bytecode_div_op(uint8_t l0);
static bool vader_bytecode_extend_into_loops(void* l0, void* l1, int64_t l2, void* l3);
static vader_string_t vader_bytecode_f64_const_operands(double l0);
static void* vader_bytecode_find_loop_ranges(void* l0);
static vader_string_t vader_bytecode_fnv1a_hex(vader_string_t l0);
static bool vader_bytecode_foldable_self_copy(void* l0, int64_t l1, int64_t l2, void* l3);
static int64_t vader_bytecode_integer_bits(uint8_t l0);
static vader_box_t vader_bytecode_integer_op(uint8_t l0, int64_t l1, bool l2, int64_t l3, int64_t l4);
static bool vader_bytecode_is_display_to_string(vader_string_t l0);
static bool vader_bytecode_is_int_equals(vader_string_t l0);
static bool vader_bytecode_is_ref_class(uint8_t l0);
static bool vader_bytecode_is_u32_class(uint8_t l0);
static vader_string_t vader_bytecode_key_join(void* l0, void* l1, vader_string_t l2);
static uint64_t vader_bytecode_mix64(uint64_t l0, uint64_t l1);
static vader_box_t vader_bytecode_mod_op(uint8_t l0);
static vader_box_t vader_bytecode_neg_op(uint8_t l0);
static vader_box_t vader_bytecode_parse_val_type(vader_string_t l0);
static vader_box_t vader_bytecode_primitive_arith_op(vader_string_t l0);
static vader_box_t vader_bytecode_primitive_cmp_op(vader_string_t l0);
static void vader_bytecode_printed(void* l0, void* l1, vader_string_t l2, void* l3);
static void vader_bytecode_push_or_assign(void* l0, int64_t l1, vader_box_t l2);
static void vader_bytecode_push_scope(void* l0, void* l1, int64_t l2, vader_string_t l3, int32_t l4);
static bool vader_bytecode_ranges_overlap(void* l0, void* l1);
static void* vader_bytecode_refer(uint8_t l0, int32_t l1);
static void* vader_bytecode_refer_field(int32_t l0, int32_t l1);
static void* vader_bytecode_remap_debug(void* l0, void* l1, int64_t l2);
static void* vader_bytecode_remap_globals(void* l0, void* l1);
static vader_box_t vader_bytecode_remap_push_cache_slot(vader_box_t l0, void* l1);
static void* vader_bytecode_remap_signature(void* l0, void* l1);
static vader_box_t vader_bytecode_remap_type_in_op(vader_box_t l0, void* l1);
static void* vader_bytecode_remap_type_indices(void* l0, void* l1);
static bool vader_bytecode_same_argument_class(vader_box_t l0, vader_box_t l1);
static bool vader_bytecode_same_argument_list(void* l0, void* l1);
static bool vader_bytecode_same_class_list(void* l0, void* l1);
static bool vader_bytecode_same_intern_class(vader_box_t l0, vader_box_t l1);
static bool vader_bytecode_same_symbol_class(void* l0, void* l1);
static vader_box_t vader_bytecode_shl_op(uint8_t l0);
static vader_box_t vader_bytecode_shr_op(uint8_t l0);
static int32_t vader_bytecode_slot_touched(vader_box_t l0);
static vader_box_t vader_bytecode_slot_width_for(uint8_t l0);
static vader_box_t vader_bytecode_strip_core_member(vader_string_t l0, vader_string_t l1);
static uint64_t vader_bytecode_symbol_hash(void* l0);
static vader_string_t vader_bytecode_symbol_key(void* l0);
static vader_box_t vader_bytecode_try_fold_arith(vader_box_t l0, void* l1, int64_t l2);
static vader_string_t vader_bytecode_tuple_shape_name(void* l0);
static uint64_t vader_bytecode_type_args_hash(uint64_t l0, void* l1);
static int32_t vader_bytecode_type_index_of(vader_box_t l0);
static vader_string_t vader_bytecode_type_key_join(void* l0, vader_string_t l1);
static uint8_t vader_bytecode_val_type_of_primitive_name(vader_string_t l0);
static int64_t vader_bytecode_value_cell(uint8_t l0, int64_t l1);
static void vader_bytecode_visit_type(int32_t l0, void* l1, void* l2);
static void vader_bytecode_write_op_refs(void* l0, void* l1, vader_box_t l2);

static uint64_t vader_bytecode_argument_hash(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    uint64_t l2, l3;
    uint64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_types_strip_distinct(l0);
    if (!(l1.tag == 1262u)) {
        t0 = vader_bytecode_type_intern_hash(l0);
        { uint64_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 7);
    t1 = l1.payload.obj;
    l3 = vader_bytecode_symbol_hash(((vader_struct_vader_types_EnumType_t*) t1)->f_symbol);
    t0 = vader_bytecode_mix64(l2, l3);
    { uint64_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint64_t vader_bytecode_argument_hashes(uint64_t l0, void* l1) {
    uint64_t l2, l6;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t t0 = vader_box_null();
    int64_t t1, t2;
    uint64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l6 = vader_bytecode_argument_hash(t0);
        l2 = vader_bytecode_mix64(l2, l6);
        l5 = (l5 + INT64_C(1));
    }
    t1 = ((vader_array_t*) l1)->length;
    t2 = t1;
    l6 = (uint64_t) (int64_t) t2;
    t3 = vader_bytecode_mix64(l2, l6);
    { uint64_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_bytecode_argument_key(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t l2 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_types_strip_distinct(l0);
    if (!(l1.tag == 1262u)) {
        t0 = vader_bytecode_type_intern_key(l0);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l1.payload.obj;
    l2 = vader_bytecode_symbol_key(((vader_struct_vader_types_EnumType_t*) t1)->f_symbol);
    t0 = concat_2(533u, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_bytecode_argument_keys(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t l6 = 0;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = 0u;
    l2 = 0u;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l6 = vader_bytecode_argument_key(t0);
        l1 = concat_3(l1, l2, l6);
        l2 = 2844u;
        l5 = (l5 + INT64_C(1));
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_arith_op(uint8_t l0, vader_string_t l1) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_is_float_val(l0);
    if (t0) {
        if (l1 == 1363u) {
            vader_struct_vader_bytecode_F64Add_t* _a0_obj = (vader_struct_vader_bytecode_F64Add_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Add_t));
            vader_obj_header_init(_a0_obj, 692u);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 2476u) {
            vader_struct_vader_bytecode_F64Sub_t* _a1_obj = (vader_struct_vader_bytecode_F64Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Sub_t));
            vader_obj_header_init(_a1_obj, 703u);
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l1 == 2177u)) {
            vader_struct_vader_bytecode_F64Div_t* _a2_obj = (vader_struct_vader_bytecode_F64Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Div_t));
            vader_obj_header_init(_a2_obj, 694u);
            t1 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_F64Mul_t* _a3_obj = (vader_struct_vader_bytecode_F64Mul_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Mul_t));
        vader_obj_header_init(_a3_obj, 700u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        if (l1 == 1363u) {
            vader_struct_vader_bytecode_I64Add_t* _a4_obj = (vader_struct_vader_bytecode_I64Add_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Add_t));
            vader_obj_header_init(_a4_obj, 729u);
            t1 = (void*) _a4_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 2476u) {
            vader_struct_vader_bytecode_I64Sub_t* _a5_obj = (vader_struct_vader_bytecode_I64Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Sub_t));
            vader_obj_header_init(_a5_obj, 748u);
            t1 = (void*) _a5_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l1 == 2177u)) {
            vader_struct_vader_bytecode_I64Div_t* _a6_obj = (vader_struct_vader_bytecode_I64Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Div_t));
            vader_obj_header_init(_a6_obj, 735u);
            t1 = (void*) _a6_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_I64Mul_t* _a7_obj = (vader_struct_vader_bytecode_I64Mul_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Mul_t));
        vader_obj_header_init(_a7_obj, 742u);
        t1 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 1363u) {
        vader_struct_vader_bytecode_I32Add_t* _a8_obj = (vader_struct_vader_bytecode_I32Add_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Add_t));
        vader_obj_header_init(_a8_obj, 709u);
        t1 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 2476u) {
        vader_struct_vader_bytecode_I32Sub_t* _a9_obj = (vader_struct_vader_bytecode_I32Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Sub_t));
        vader_obj_header_init(_a9_obj, 728u);
        t1 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1 == 2177u)) {
        vader_struct_vader_bytecode_I32Div_t* _a10_obj = (vader_struct_vader_bytecode_I32Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Div_t));
        vader_obj_header_init(_a10_obj, 715u);
        t1 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Mul_t* _a11_obj = (vader_struct_vader_bytecode_I32Mul_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Mul_t));
    vader_obj_header_init(_a11_obj, 722u);
    t1 = (void*) _a11_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

uint8_t vader_bytecode_array_kind_from_name(vader_string_t l0) {
    uint8_t l1;
    if (l0 == 2596u) {
        l1 = (uint8_t) 1;
        return l1;
    }
    if (l0 == 2575u) {
        l1 = (uint8_t) 2;
    } else if (l0 == 2576u) {
        l1 = (uint8_t) 3;
    } else if (l0 == 2586u) {
        l1 = (uint8_t) 4;
    } else if (l0 == 1946u) {
        l1 = (uint8_t) 5;
    } else if (l0 == 1901u) {
        l1 = (uint8_t) 6;
    } else if (l0 == 1902u) {
        l1 = (uint8_t) 7;
    } else if (l0 == 1924u) {
        l1 = (uint8_t) 8;
    } else if (l0 == 1775u) {
        l1 = (uint8_t) 9;
    } else if (l0 == 1777u) {
        l1 = (uint8_t) 10;
    } else if (l0 == 1581u) {
        l1 = (uint8_t) 11;
    } else if (l0 == 1473u) {
        l1 = (uint8_t) 12;
    } else if (l0 == 2309u) {
        l1 = (uint8_t) 13;
    } else {
        l1 = (uint8_t) 0;
    }
    return l1;
}

int32_t vader_bytecode_array_kind_index(uint8_t l0) {
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

vader_string_t vader_bytecode_array_kind_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(1)) {
        l1 = 2596u;
        return l1;
    }
    if (l0 == INT32_C(5)) {
        l1 = 1946u;
    } else if (l0 == INT32_C(12)) {
        l1 = 1473u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2575u;
    } else if (l0 == INT32_C(6)) {
        l1 = 1901u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2576u;
    } else if (l0 == INT32_C(7)) {
        l1 = 1902u;
    } else if (l0 == INT32_C(9)) {
        l1 = 1775u;
    } else if (l0 == INT32_C(11)) {
        l1 = 1581u;
    } else if (l0 == INT32_C(4)) {
        l1 = 2586u;
    } else if (l0 == INT32_C(8)) {
        l1 = 1924u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1777u;
    } else if (l0 == INT32_C(13)) {
        l1 = 2309u;
    } else {
        if (!(l0 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1484u;
    }
    return l1;
}

uint8_t vader_bytecode_array_kind_of(vader_box_t l0, void* l1) {
    uint8_t l2;
    void* t0;
    bool t1;
    if (l0.tag == 650u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_array_kind_of_val(((vader_struct_vader_bytecode_BcScalar_t*) t0)->f_val);
        return l2;
    }
    if (l0.tag == 653u) {
        l2 = (uint8_t) 13;
    } else if (l0.tag == 639u) {
        l2 = (uint8_t) 13;
    } else if (l0.tag == 642u) {
        l2 = (uint8_t) 13;
    } else if (l0.tag == 654u) {
        t0 = l0.payload.obj;
        t1 = vader_bytecode_is_ref_only_element(vader_ref_box(t0), l1);
        if (t1) {
            l2 = (uint8_t) 13;
        } else {
            l2 = (uint8_t) 0;
        }
    } else {
        if (!(l0.tag == 649u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = (uint8_t) 0;
    }
    return l2;
}

uint8_t vader_bytecode_array_kind_of_val(uint8_t l0) {
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

void vader_bytecode_assert_host_import_wired(vader_string_t l0, bool l1) {
    vader_box_t t0 = vader_box_null();
    uint8_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = vader_bytecode_intrinsic_op_for_mangled(l0);
    if (!(t0.tag == 0u)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = vader_bytecode_intrinsic_id_for(l0);
    if (!(t1 != INT32_C(0))) {
        t2 = concat_3(1522u, l0, 1046u);
        vader_host_std_abort_panic(t2);
        vader_unreachable("a no-return call returned");
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static uint64_t vader_bytecode_bare_hash(vader_string_t l0) {
    uint64_t l1;
    uint64_t t0;
    l1 = std_core_string_Hash_hash_vt(l0);
    t0 = vader_bytecode_mix64((uint64_t) -3750763034362895579, l1);
    return t0;
}

static vader_string_t vader_bytecode_bare_intern_name(vader_box_t l0) {
    vader_string_t l1 = 0;
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1270u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1262u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_integer_MachineInteger_t*) ((vader_struct_vader_types_EnumType_t*) t0)->f_repr)->f_name;
    } else if (l0.tag == 1271u) {
        t0 = l0.payload.obj;
        t1 = vader_types_storage_integer(t0);
        l1 = ((vader_struct_vader_integer_MachineInteger_t*) t1)->f_name;
    } else if (l0.tag == 1259u) {
        l1 = 474u;
    } else if ((l0.tag == 1264u || l0.tag == 1265u || l0.tag == 1266u || l0.tag == 1268u || l0.tag == 1272u || l0.tag == 1276u || l0.tag == 1277u || l0.tag == 1279u)) {
        l1 = vader_types_display_type(l0);
    } else if (l0.tag == 1267u) {
        t0 = l0.payload.obj;
        vader_types_leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else {
        if (!((l0.tag == 1260u || l0.tag == 1261u || l0.tag == 1263u || l0.tag == 1273u || l0.tag == 1274u || l0.tag == 1275u || l0.tag == 1278u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 0u;
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_bytecode_bc_peephole_unchanged(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l2 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug;
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a0_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a0_obj, 647u);
    _a0_obj->f_body = l1;
    _a0_obj->f_jump_table = l2;
    _a0_obj->f_debug = l3;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t vader_bytecode_bc_result_arity(void* l0) {
    bool l1;
    int64_t t0;
    vader_box_t t1;
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results)->length;
    if (t0 == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 292u);
        l1 = ((int32_t) t1.payload.i) == INT32_C(14);
    } else {
        l1 = false;
    }
    if (l1) {
        return INT64_C(0);
    }
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results)->length;
    return t0;
}

uint8_t vader_bytecode_bc_single_result(void* l0) {
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
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 14; }
    }
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results)->length;
    if (!((t0 > INT64_C(1)))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 292u);
        { uint8_t __vret = ((uint8_t) t1.payload.i); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) vader_buffer_new((size_t) INT64_C(127));
    l2 = INT64_C(0);
    l2 = std_core_write_string_at(l1, l2, 1525u);
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results)->length;
    l2 = std_core_write_int(l1, l2, l3);
    l2 = std_core_write_string_at(l1, l2, 155u);
    t2 = std_core_finish_buffer(l1, l2);
    vader_host_std_abort_panic(t2);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

int32_t vader_bytecode_bc_single_result_type(void* l0) {
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
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_result_types)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(0); }
    }
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_result_types)->length;
    if (!((t0 > INT64_C(1)))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_result_types);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
        { int32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) vader_buffer_new((size_t) INT64_C(132));
    l2 = INT64_C(0);
    l2 = std_core_write_string_at(l1, l2, 1524u);
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_result_types)->length;
    l2 = std_core_write_int(l1, l2, l3);
    l2 = std_core_write_string_at(l1, l2, 155u);
    t2 = std_core_finish_buffer(l1, l2);
    vader_host_std_abort_panic(t2);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

vader_string_t vader_bytecode_bc_type_key(void* l0, int32_t l1) {
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
        { vader_gc_top = gc_frame.prev; return 461u; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    l6 = l5;
    if (l5.tag == 650u) {
        l8 = (void*) vader_buffer_new((size_t) INT64_C(22));
        l3 = INT64_C(0);
        l3 = std_core_write_string_at(l8, l3, 2261u);
        t0 = l6.payload.obj;
        l4 = ((int64_t) (int32_t) ((int32_t) (uint8_t) ((vader_struct_vader_bytecode_BcScalar_t*) t0)->f_val));
        l3 = std_core_write_int(l8, l3, l4);
        l7 = std_core_finish_buffer(l8, l3);
        { vader_string_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 653u) {
        t0 = l6.payload.obj;
        l9 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_name;
        l7 = concat_2(2342u, l9);
    } else if (l5.tag == 649u) {
        t0 = l6.payload.obj;
        l9 = ((vader_struct_vader_bytecode_BcRef_t*) t0)->f_trait_name;
        l7 = concat_2(2293u, l9);
    } else if (l5.tag == 639u) {
        t0 = l6.payload.obj;
        l10 = ((vader_struct_vader_bytecode_BcArray_t*) t0)->f_element;
        l9 = vader_bytecode_bc_type_key(l0, l10);
        l7 = concat_3(1360u, l9, 457u);
    } else if (l5.tag == 654u) {
        t0 = l6.payload.obj;
        l8 = ((vader_struct_vader_bytecode_BcUnion_t*) t0)->f_variants;
        l9 = vader_bytecode_key_join(l0, l8, 2844u);
        l7 = concat_3(2597u, l9, 457u);
    } else {
        if (!(l5.tag == 642u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l6.payload.obj;
        l8 = ((vader_struct_vader_bytecode_BcFn_t*) t0)->f_params;
        l9 = vader_bytecode_key_join(l0, l8, 2844u);
        t0 = l6.payload.obj;
        l10 = ((vader_struct_vader_bytecode_BcFn_t*) t0)->f_return_type;
        l11 = vader_bytecode_bc_type_key(l0, l10);
        l7 = concat_4(1791u, l9, 289u, l11);
    }
    { vader_string_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_bc_type_of_with_ctx(vader_box_t l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l10 = NULL;
    int64_t l5, l6, l8;
    int32_t l7;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    uint8_t t2;
    vader_box_t t3 = vader_box_null();
    int32_t t4;
    vader_box_t* gc_roots[2] = { &l0, &t3 };
    void** gc_raw_roots[5] = { &l1, &l3, &l4, &l10, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l9, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1270u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        t2 = vader_bytecode_val_type_of_primitive_name(t1);
        vader_struct_vader_bytecode_BcScalar_t* _a0_obj = (vader_struct_vader_bytecode_BcScalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcScalar_t));
        vader_obj_header_init(_a0_obj, 650u);
        _a0_obj->f_val = t2;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 1262u || l0.tag == 1271u)) {
        t2 = vader_bytecode_val_type_of_type(l0);
        vader_struct_vader_bytecode_BcScalar_t* _a1_obj = (vader_struct_vader_bytecode_BcScalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcScalar_t));
        vader_obj_header_init(_a1_obj, 650u);
        _a1_obj->f_val = t2;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1261u) {
        t0 = l0.payload.obj;
        t3 = vader_bytecode_bc_type_of_with_ctx(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing, l1, l2);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1273u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_name;
        vader_struct_vader_bytecode_BcRef_t* _a2_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a2_obj, 649u);
        _a2_obj->f_trait_name = t1;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1274u) {
        t0 = l0.payload.obj;
        t1 = vader_types_trait_key_of(((vader_struct_vader_types_TraitType_t*) t0)->f_symbol);
        vader_struct_vader_bytecode_BcRef_t* _a3_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a3_obj, 649u);
        _a3_obj->f_trait_name = t1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1260u) {
        t0 = l0.payload.obj;
        t4 = vader_bytecode_intern_type(((vader_struct_vader_types_ArrayType_t*) t0)->f_element, l1);
        vader_struct_vader_bytecode_BcArray_t* _a4_obj = (vader_struct_vader_bytecode_BcArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcArray_t));
        vader_obj_header_init(_a4_obj, 639u);
        _a4_obj->f_element = t4;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1278u) {
        vader_array_t* _a5_arr = vader_array_new(15u, 0u, 7u, 290u);
        l3 = (void*) _a5_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        l5 = ((vader_array_t*) l4)->length;
        l6 = INT64_C(0);
        while ((l6 < l5)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            t3 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
            l7 = vader_bytecode_intern_type(t3, l1);
            vader_array_push_i32((vader_array_t*) l3, l7);
            l6 = (l6 + INT64_C(1));
        }
        vader_struct_vader_bytecode_BcUnion_t* _a7_obj = (vader_struct_vader_bytecode_BcUnion_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcUnion_t));
        vader_obj_header_init(_a7_obj, 654u);
        _a7_obj->f_variants = l3;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1263u) {
        vader_array_t* _a8_arr = vader_array_new(15u, 0u, 7u, 290u);
        l3 = (void*) _a8_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
        l5 = ((vader_array_t*) l4)->length;
        l6 = INT64_C(0);
        while ((l6 < l5)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            t3 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l6);
            l7 = vader_bytecode_intern_type(t3, l1);
            vader_array_push_i32((vader_array_t*) l3, l7);
            l6 = (l6 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l7 = vader_bytecode_intern_type(((vader_struct_vader_types_FnType_t*) t0)->f_return_type, l1);
        vader_struct_vader_bytecode_BcFn_t* _a10_obj = (vader_struct_vader_bytecode_BcFn_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFn_t));
        vader_obj_header_init(_a10_obj, 642u);
        _a10_obj->f_params = l3;
        _a10_obj->f_return_type = l7;
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1275u) {
        vader_array_t* _a11_arr = vader_array_new(50u, 0u, 13u, 641u);
        l3 = (void*) _a11_arr;
        l5 = INT64_C(0);
        t0 = l0.payload.obj;
        l6 = ((vader_array_t*) ((vader_struct_vader_types_TupleType_t*) t0)->f_elements)->length;
        while ((l5 < l6)) {
            l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
            l8 = INT64_C(0);
            l8 = std_core_write_string_at(l4, l8, 857u);
            l8 = std_core_write_int(l4, l8, l5);
            l9 = std_core_finish_buffer(l4, l8);
            t0 = l0.payload.obj;
            vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_types_TupleType_t*) t0)->f_elements);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l5)
            t3 = vader_array_ref_load_box(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l5);
            l7 = vader_bytecode_intern_type(t3, l1);
            vader_struct_vader_bytecode_BcField_t* _a13_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
            vader_obj_header_init(_a13_obj, 641u);
            _a13_obj->f_name = l9;
            _a13_obj->f_type_index = l7;
            l10 = (void*) _a13_obj;
            vader_array_push((vader_array_t*) l3, vader_ref_box(l10));
            l5 = (l5 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l9 = vader_bytecode_tuple_shape_name(((vader_struct_vader_types_TupleType_t*) t0)->f_elements);
        t1 = concat_2(873u, l9);
        vader_struct_vader_bytecode_BcStruct_t* _a14_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
        vader_obj_header_init(_a14_obj, 653u);
        _a14_obj->f_name = t1;
        _a14_obj->f_fields = l3;
        _a14_obj->f_c_name = 0u;
        _a14_obj->f_symbol_id = INT32_C(-1);
        t0 = (void*) _a14_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1277u) {
        t0 = (void*) &vader_data_44;
        vader_array_t* _a15_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        t0 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1267u) {
        t0 = l0.payload.obj;
        vader_types_leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else {
        if (l0.tag == 1276u) {
            t0 = (void*) &vader_data_44;
            vader_array_t* _a16_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            t0 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 1272u) {
            t0 = (void*) &vader_data_44;
            vader_array_t* _a17_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            t0 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 1279u) {
            t0 = (void*) &vader_data_44;
            vader_array_t* _a18_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
            t0 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 1266u) {
            t0 = (void*) &vader_data_44;
            vader_array_t* _a19_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            t0 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 1264u) {
            t0 = (void*) &vader_data_44;
            vader_array_t* _a20_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
            t0 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 1265u) {
            t0 = (void*) &vader_data_44;
            vader_array_t* _a21_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
            t0 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l0.tag == 1268u) {
            t0 = (void*) &vader_data_44;
            vader_array_t* _a22_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
            t0 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l0.tag == 1259u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = (void*) &vader_data_44;
        vader_array_t* _a23_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        t0 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_bytecode_binary_op_for(uint8_t l0, uint8_t l1) {
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        l2 = vader_bytecode_arith_op(l1, 1363u);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        l2 = vader_bytecode_arith_op(l1, 2476u);
    } else if (l0 == INT32_C(2)) {
        l2 = vader_bytecode_arith_op(l1, 2177u);
    } else if (l0 == INT32_C(18)) {
        l2 = vader_bytecode_checked_arith_op(l1, (uint8_t) 0);
    } else if (l0 == INT32_C(19)) {
        l2 = vader_bytecode_checked_arith_op(l1, (uint8_t) 1);
    } else if (l0 == INT32_C(20)) {
        l2 = vader_bytecode_checked_arith_op(l1, (uint8_t) 2);
    } else if (l0 == INT32_C(3)) {
        l2 = vader_bytecode_div_op(l1);
    } else if (l0 == INT32_C(4)) {
        l2 = vader_bytecode_mod_op(l1);
    } else if (l0 == INT32_C(5)) {
        l2 = vader_bytecode_shl_op(l1);
    } else if (l0 == INT32_C(6)) {
        l2 = vader_bytecode_shr_op(l1);
    } else if (l0 == INT32_C(7)) {
        l2 = vader_bytecode_bit_op(l1, 1394u);
    } else if (l0 == INT32_C(8)) {
        l2 = vader_bytecode_bit_op(l1, 2252u);
    } else if (l0 == INT32_C(9)) {
        l2 = vader_bytecode_bit_op(l1, 2831u);
    } else if (l0 == INT32_C(10)) {
        vader_struct_vader_bytecode_BoolAnd_t* _a0_obj = (vader_struct_vader_bytecode_BoolAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolAnd_t));
        vader_obj_header_init(_a0_obj, 662u);
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(11)) {
        vader_struct_vader_bytecode_BoolOr_t* _a1_obj = (vader_struct_vader_bytecode_BoolOr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolOr_t));
        vader_obj_header_init(_a1_obj, 667u);
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(12)) {
        l2 = vader_bytecode_cmp_eq(l1);
    } else if (l0 == INT32_C(13)) {
        l2 = vader_bytecode_cmp_ne(l1);
    } else if (l0 == INT32_C(14)) {
        l2 = vader_bytecode_cmp_lt(l1);
    } else if (l0 == INT32_C(15)) {
        l2 = vader_bytecode_cmp_le(l1);
    } else if (l0 == INT32_C(16)) {
        l2 = vader_bytecode_cmp_gt(l1);
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_bytecode_cmp_ge(l1);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_bit_op(uint8_t l0, vader_string_t l1) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        if (l1 == 1394u) {
            vader_struct_vader_bytecode_I64BitAnd_t* _a0_obj = (vader_struct_vader_bytecode_I64BitAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitAnd_t));
            vader_obj_header_init(_a0_obj, 730u);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l1 == 2252u)) {
            vader_struct_vader_bytecode_I64BitXor_t* _a1_obj = (vader_struct_vader_bytecode_I64BitXor_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitXor_t));
            vader_obj_header_init(_a1_obj, 733u);
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_I64BitOr_t* _a2_obj = (vader_struct_vader_bytecode_I64BitOr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitOr_t));
        vader_obj_header_init(_a2_obj, 732u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 1394u) {
        vader_struct_vader_bytecode_I32BitAnd_t* _a3_obj = (vader_struct_vader_bytecode_I32BitAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitAnd_t));
        vader_obj_header_init(_a3_obj, 710u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1 == 2252u)) {
        vader_struct_vader_bytecode_I32BitXor_t* _a4_obj = (vader_struct_vader_bytecode_I32BitXor_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitXor_t));
        vader_obj_header_init(_a4_obj, 713u);
        t1 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32BitOr_t* _a5_obj = (vader_struct_vader_bytecode_I32BitOr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitOr_t));
    vader_obj_header_init(_a5_obj, 712u);
    t1 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_bitnot_op(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32BitNot_t* _a0_obj = (vader_struct_vader_bytecode_I32BitNot_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitNot_t));
        vader_obj_header_init(_a0_obj, 711u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64BitNot_t* _a1_obj = (vader_struct_vader_bytecode_I64BitNot_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitNot_t));
    vader_obj_header_init(_a1_obj, 731u);
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_build_intrinsic_wrapper_body(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4;
    vader_box_t l6 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(226u, 0u, 13u, 1538u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_params)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_params)->length;
    while ((l3 < l4)) {
        vader_struct_vader_bytecode_LocalGet_t* _a2_obj = (vader_struct_vader_bytecode_LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalGet_t));
        vader_obj_header_init(_a2_obj, 759u);
        _a2_obj->f_slot = ((int32_t) (int64_t) l3);
        l5 = (void*) _a2_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
        l3 = (l3 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
    l6 = vader_bytecode_intrinsic_op_for_mangled(t0);
    if (l6.tag == 0u) {
        vader_struct_vader_bytecode_CallImport_t* _a3_obj = (vader_struct_vader_bytecode_CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallImport_t));
        vader_obj_header_init(_a3_obj, 676u);
        _a3_obj->f_index = l1;
        l5 = (void*) _a3_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
        vader_struct_vader_bytecode_Return_t* _a4_obj = (vader_struct_vader_bytecode_Return_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Return_t));
        vader_obj_header_init(_a4_obj, 771u);
        l5 = (void*) _a4_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_push((vader_array_t*) l2, l6);
    vader_struct_vader_bytecode_Return_t* _a5_obj = (vader_struct_vader_bytecode_Return_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Return_t));
    vader_obj_header_init(_a5_obj, 771u);
    l5 = (void*) _a5_obj;
    vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_c_field_align_at(void* l0, void* l1, int32_t l2) {
    vader_box_t l3;
    void* l4;
    void* l8;
    int64_t l5, l6, l7, l9;
    int32_t l10;
    uint8_t t0;
    int32_t t1;
    l3 = vader_bytecode_c_field_val_type(l0, l1);
    if (!(l3.tag == 0u)) {
        t0 = ((uint8_t) l3.payload.i);
        t1 = vader_bytecode_size_of_val_type(t0);
        return vader_box_i64(291u, ((int64_t) (int32_t) t1));
    }
    if ((l2 >= INT32_C(16))) {
        return vader_box_obj(0u, NULL);
    }
    l3 = vader_bytecode_nested_mirror(l0, l1);
    if (l3.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l4 = l3.payload.obj;
    l5 = INT64_C(1);
    l4 = ((vader_struct_vader_bytecode_BcStruct_t*) l4)->f_fields;
    l6 = ((vader_array_t*) l4)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        l10 = vader_chk_add(i32, l2, INT32_C(1));
        l3 = vader_bytecode_c_field_align_at(l8, l1, l10);
        if (l3.tag == 0u) {
            return vader_box_obj(0u, NULL);
        }
        l9 = ((int64_t) l3.payload.i);
        if ((l9 > l5)) {
            l5 = l9;
        }
        l7 = (l7 + INT64_C(1));
    }
    return vader_box_i64(291u, l5);
}

vader_box_t vader_bytecode_c_field_val_type(void* l0, void* l1) {
    int64_t l2, l3;
    int32_t l4;
    vader_box_t l5;
    int32_t t0;
    void* t1;
    t0 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_type_index;
    if ((t0 < INT32_C(0))) {
        return vader_box_obj(0u, NULL);
    }
    t0 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_type_index;
    l2 = ((int64_t) (int32_t) t0);
    l3 = ((vader_array_t*) l1)->length;
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    l4 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_type_index;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    if (!(l5.tag == 650u)) {
        return vader_box_obj(0u, NULL);
    }
    t1 = l5.payload.obj;
    return vader_box_i32(292u, (int32_t)(uint32_t) ((vader_struct_vader_bytecode_BcScalar_t*) t1)->f_val);
}

vader_box_t vader_bytecode_c_field_width(void* l0, void* l1) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_c_field_width_at(l0, l1, INT32_C(0));
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_c_field_width_at(void* l0, void* l1, int32_t l2) {
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
    l3 = vader_bytecode_c_field_val_type(l0, l1);
    if (!(l3.tag == 0u)) {
        t0 = ((uint8_t) l3.payload.i);
        t1 = vader_bytecode_size_of_val_type(t0);
        { vader_box_t __vret = vader_box_i64(291u, ((int64_t) (int32_t) t1)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l2 >= INT32_C(16))) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = vader_bytecode_nested_mirror(l0, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = l3.payload.obj;
    l4 = ((vader_struct_vader_bytecode_BcStruct_t*) l4)->f_fields;
    l5 = vader_chk_add(i32, l2, INT32_C(1));
    l4 = vader_bytecode_c_struct_layout_at(l4, l1, l5);
    if (!(((vader_struct_vader_bytecode_CLayout_t*) l4)->f_unknown_field.tag == 0u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t2 = ((vader_struct_vader_bytecode_CLayout_t*) l4)->f_size;
    { vader_box_t __vret = vader_box_i64(291u, t2); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_bytecode_c_result_type(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_result_c_type;
    if (!(t0 == 0u)) {
        t0 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_result_c_type;
        return vader_box_string(287u, t0);
    }
    return vader_box_obj(0u, NULL);
}

static vader_string_t vader_bytecode_c_safe_key(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t l11 = 0;
    bool l2, l6, l7, l8, l9, l10;
    int64_t l3, l4;
    uint8_t l5;
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = 0u;
    l2 = false;
    l3 = INT64_C(0);
    l4 = vader_host_std_core_byte_len(l0);
    while ((l3 < l4)) {
        l5 = vader_host_std_core_byte_at(l0, l3);
        if ((l5 >= INT32_C(97))) {
            l6 = (l5 <= INT32_C(122));
        } else {
            l6 = false;
        }
        if (l6) {
            l7 = true;
        } else {
            if ((l5 >= INT32_C(65))) {
                l8 = (l5 <= INT32_C(90));
            } else {
                l8 = false;
            }
            l7 = l8;
        }
        if (l7) {
            l9 = true;
        } else {
            if ((l5 >= INT32_C(48))) {
                l10 = (l5 <= INT32_C(57));
            } else {
                l10 = false;
            }
            l9 = l10;
        }
        if (l9) {
            l11 = std_core_char_Display_to_string(((uint32_t) (uint8_t) l5));
            l1 = concat_2(l1, l11);
            l2 = false;
        } else if (!(l2)) {
            l1 = concat_2(l1, 857u);
            l2 = true;
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_c_struct_layout(void* l0, void* l1) {
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_c_struct_layout_at(l0, l1, INT32_C(0));
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_bytecode_c_struct_layout_at(void* l0, void* l1, int32_t l2) {
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
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 8u, 291u);
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
        l11 = vader_bytecode_c_field_width_at(l10, l1, l2);
        l12 = vader_bytecode_c_field_align_at(l10, l1, l2);
        if (l11.tag == 0u) {
            if (l6.tag == 0u) {
                t0 = ((vader_struct_vader_bytecode_BcField_t*) l10)->f_name;
                l6 = vader_box_string(287u, t0);
            }
            vader_array_push_i64((vader_array_t*) l3, l4);
            l9 = (l9 + INT64_C(1));
            continue;
        }
        if (l12.tag == 0u) {
            if (l6.tag == 0u) {
                t0 = ((vader_struct_vader_bytecode_BcField_t*) l10)->f_name;
                l6 = vader_box_string(287u, t0);
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
        vader_struct_vader_bytecode_CLayout_t* _a2_obj = (vader_struct_vader_bytecode_CLayout_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CLayout_t));
        vader_obj_header_init(_a2_obj, 674u);
        _a2_obj->f_offsets = l3;
        _a2_obj->f_size = l9;
        _a2_obj->f_unknown_field = l6;
        t1 = (void*) _a2_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_chk_add(i64, l4, l5);
    l9 = vader_chk_sub(i64, t2, l8);
    vader_struct_vader_bytecode_CLayout_t* _a3_obj = (vader_struct_vader_bytecode_CLayout_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CLayout_t));
    vader_obj_header_init(_a3_obj, 674u);
    _a3_obj->f_offsets = l3;
    _a3_obj->f_size = l9;
    _a3_obj->f_unknown_field = l6;
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_bytecode_cell_value(uint8_t l0, int64_t l1) {
    bool t0;
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        return l1;
    }
    if (!(l0 == INT32_C(6))) {
        return ((int64_t) (int32_t) ((int32_t) (int64_t) l1));
    }
    return (l1 & INT64_C(4294967295));
}

vader_box_t vader_bytecode_checked_arith(uint8_t l0, uint8_t l1, int64_t l2, int64_t l3) {
    int64_t l4, l6, l7;
    bool l5;
    vader_box_t l8;
    int64_t t0;
    l4 = vader_bytecode_integer_bits(l1);
    l5 = vader_bytecode_is_unsigned_val(l1);
    l6 = vader_bytecode_cell_value(l1, l2);
    l7 = vader_bytecode_cell_value(l1, l3);
    l8 = vader_bytecode_integer_op(l0, l4, l5, l6, l7);
    if (l8.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l4 = ((int64_t) l8.payload.i);
    t0 = vader_bytecode_value_cell(l1, l4);
    return vader_box_i64(291u, t0);
}

static vader_box_t vader_bytecode_checked_arith_op(uint8_t l0, uint8_t l1) {
    vader_string_t l2 = 0;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &t2 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_is_integer_val(l0);
    if (!(t0)) {
        l2 = vader_bytecode_checked_op_name(l1);
        t1 = vader_bytecode_arith_op(l0, l2);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_CheckedArith_t* _a0_obj = (vader_struct_vader_bytecode_CheckedArith_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CheckedArith_t));
    vader_obj_header_init(_a0_obj, 679u);
    _a0_obj->f_kind = l0;
    _a0_obj->f_op = l1;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_bytecode_checked_neg(uint8_t l0, int64_t l1) {
    int64_t l2, l3;
    bool l4;
    vader_box_t l5;
    int64_t t0;
    l2 = vader_bytecode_integer_bits(l0);
    l3 = vader_bytecode_cell_value(l0, l1);
    l4 = vader_bytecode_is_unsigned_val(l0);
    l5 = vader_integer_checked_negation(l2, l4, l3);
    if (l5.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l2 = ((int64_t) l5.payload.i);
    t0 = vader_bytecode_value_cell(l0, l2);
    return vader_box_i64(291u, t0);
}

vader_string_t vader_bytecode_checked_neg_message(uint8_t l0) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[2] = { &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_val_type_name(l0);
    t1 = concat_2(t0, 359u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_checked_neg_op(uint8_t l0) {
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_is_integer_val(l0);
    if (!(t0)) {
        t1 = vader_bytecode_neg_op(l0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_CheckedNeg_t* _a0_obj = (vader_struct_vader_bytecode_CheckedNeg_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CheckedNeg_t));
    vader_obj_header_init(_a0_obj, 680u);
    _a0_obj->f_kind = l0;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_bytecode_checked_op_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 1363u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2476u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2177u;
    }
    return l1;
}

vader_string_t vader_bytecode_checked_overflow_message(uint8_t l0, uint8_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[3] = { &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_bytecode_val_type_name(l0);
    l3 = vader_bytecode_checked_op_name(l1);
    t0 = concat_4(l2, 335u, l3, 142u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_cmp_eq(uint8_t l0) {
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(10)) {
        vader_struct_vader_bytecode_BoolEq_t* _a0_obj = (vader_struct_vader_bytecode_BoolEq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolEq_t));
        vader_obj_header_init(_a0_obj, 664u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(12)) {
        vader_struct_vader_bytecode_StringEq_t* _a1_obj = (vader_struct_vader_bytecode_StringEq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringEq_t));
        vader_obj_header_init(_a1_obj, 784u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_float_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_F64Eq_t* _a2_obj = (vader_struct_vader_bytecode_F64Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Eq_t));
        vader_obj_header_init(_a2_obj, 695u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_64_bit_int_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_I64Eq_t* _a3_obj = (vader_struct_vader_bytecode_I64Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Eq_t));
        vader_obj_header_init(_a3_obj, 736u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_ref_class(l0);
    if (!(t1)) {
        vader_struct_vader_bytecode_I32Eq_t* _a4_obj = (vader_struct_vader_bytecode_I32Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Eq_t));
        vader_obj_header_init(_a4_obj, 716u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_RefEq_t* _a5_obj = (vader_struct_vader_bytecode_RefEq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefEq_t));
    vader_obj_header_init(_a5_obj, 768u);
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_cmp_ge(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_is_float_val(l0);
    if (t0) {
        vader_struct_vader_bytecode_F64Ge_t* _a0_obj = (vader_struct_vader_bytecode_F64Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Ge_t));
        vader_obj_header_init(_a0_obj, 696u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Ge_t* _a1_obj = (vader_struct_vader_bytecode_U64Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Ge_t));
        vader_obj_header_init(_a1_obj, 798u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Ge_t* _a2_obj = (vader_struct_vader_bytecode_U32Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Ge_t));
        vader_obj_header_init(_a2_obj, 792u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Ge_t* _a3_obj = (vader_struct_vader_bytecode_I32Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Ge_t));
        vader_obj_header_init(_a3_obj, 717u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Ge_t* _a4_obj = (vader_struct_vader_bytecode_I64Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Ge_t));
    vader_obj_header_init(_a4_obj, 737u);
    t1 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_cmp_gt(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_is_float_val(l0);
    if (t0) {
        vader_struct_vader_bytecode_F64Gt_t* _a0_obj = (vader_struct_vader_bytecode_F64Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Gt_t));
        vader_obj_header_init(_a0_obj, 697u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Gt_t* _a1_obj = (vader_struct_vader_bytecode_U64Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Gt_t));
        vader_obj_header_init(_a1_obj, 799u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Gt_t* _a2_obj = (vader_struct_vader_bytecode_U32Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Gt_t));
        vader_obj_header_init(_a2_obj, 793u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Gt_t* _a3_obj = (vader_struct_vader_bytecode_I32Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Gt_t));
        vader_obj_header_init(_a3_obj, 718u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Gt_t* _a4_obj = (vader_struct_vader_bytecode_I64Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Gt_t));
    vader_obj_header_init(_a4_obj, 738u);
    t1 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_cmp_le(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_is_float_val(l0);
    if (t0) {
        vader_struct_vader_bytecode_F64Le_t* _a0_obj = (vader_struct_vader_bytecode_F64Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Le_t));
        vader_obj_header_init(_a0_obj, 698u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Le_t* _a1_obj = (vader_struct_vader_bytecode_U64Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Le_t));
        vader_obj_header_init(_a1_obj, 800u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Le_t* _a2_obj = (vader_struct_vader_bytecode_U32Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Le_t));
        vader_obj_header_init(_a2_obj, 794u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Le_t* _a3_obj = (vader_struct_vader_bytecode_I32Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Le_t));
        vader_obj_header_init(_a3_obj, 719u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Le_t* _a4_obj = (vader_struct_vader_bytecode_I64Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Le_t));
    vader_obj_header_init(_a4_obj, 739u);
    t1 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_cmp_lt(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_is_float_val(l0);
    if (t0) {
        vader_struct_vader_bytecode_F64Lt_t* _a0_obj = (vader_struct_vader_bytecode_F64Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Lt_t));
        vader_obj_header_init(_a0_obj, 699u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Lt_t* _a1_obj = (vader_struct_vader_bytecode_U64Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Lt_t));
        vader_obj_header_init(_a1_obj, 801u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Lt_t* _a2_obj = (vader_struct_vader_bytecode_U32Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Lt_t));
        vader_obj_header_init(_a2_obj, 795u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Lt_t* _a3_obj = (vader_struct_vader_bytecode_I32Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Lt_t));
        vader_obj_header_init(_a3_obj, 720u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Lt_t* _a4_obj = (vader_struct_vader_bytecode_I64Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Lt_t));
    vader_obj_header_init(_a4_obj, 740u);
    t1 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_cmp_ne(uint8_t l0) {
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(10)) {
        vader_struct_vader_bytecode_BoolNe_t* _a0_obj = (vader_struct_vader_bytecode_BoolNe_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolNe_t));
        vader_obj_header_init(_a0_obj, 665u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(12)) {
        vader_struct_vader_bytecode_StringNe_t* _a1_obj = (vader_struct_vader_bytecode_StringNe_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringNe_t));
        vader_obj_header_init(_a1_obj, 785u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_float_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_F64Ne_t* _a2_obj = (vader_struct_vader_bytecode_F64Ne_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Ne_t));
        vader_obj_header_init(_a2_obj, 701u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_64_bit_int_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_I64Ne_t* _a3_obj = (vader_struct_vader_bytecode_I64Ne_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Ne_t));
        vader_obj_header_init(_a3_obj, 743u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_ref_class(l0);
    if (!(t1)) {
        vader_struct_vader_bytecode_I32Ne_t* _a4_obj = (vader_struct_vader_bytecode_I32Ne_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Ne_t));
        vader_obj_header_init(_a4_obj, 723u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_RefNe_t* _a5_obj = (vader_struct_vader_bytecode_RefNe_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefNe_t));
    vader_obj_header_init(_a5_obj, 769u);
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_coalesce_slots(void* l0) {
    int64_t l1, l2, l4, l6, l10, l21, l22, l23, l25;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l24 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l30 = NULL;
    int32_t l9, l11, l12, l13, l14, l28, l29;
    bool l16;
    uint8_t l20;
    vader_box_t l31 = vader_box_null(), l32 = vader_box_null(), l33 = vader_box_null();
    vader_string_t l34 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    int64_t t3;
    vader_box_t* gc_roots[4] = { &l31, &l32, &l33, &t0 };
    void** gc_raw_roots[14] = {
        &l0, &l3, &l5, &l7, &l8, &l15, &l17, &l18, &l19, &l24, &l26, &l27, &l30, &t2,
    };
    vader_string_t* gc_atom_roots[1] = { &l34 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    l2 = vader_chk_add(i64, l1, l2);
    if ((l2 <= l1)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l4 = ((vader_array_t*) l3)->length;
    vader_array_t* _a0_arr = vader_array_new(58u, 0u, 13u, 774u);
    l5 = (void*) _a0_arr;
    if ((INT64_C(0) < l2)) {
        l6 = l2;
    } else {
        l6 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(12u, 0u, 12u, 285u);
    l7 = (void*) _a2_arr;
    if ((INT64_C(0) < l2)) {
        l6 = l2;
    } else {
        l6 = INT64_C(0);
    }
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l7, (int64_t) l6);
    l7 = (void*) _a3_arr;
    l6 = INT64_C(0);
    while ((l6 < l2)) {
        vader_struct_vader_bytecode_SlotRange_t* _a4_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
        vader_obj_header_init(_a4_obj, 774u);
        _a4_obj->f_first = INT32_C(-1);
        _a4_obj->f_last = INT32_C(-1);
        l8 = (void*) _a4_obj;
        vader_array_push((vader_array_t*) l5, vader_ref_box(l8));
        vader_array_push_bool((vader_array_t*) l7, false);
        l6 = (l6 + INT64_C(1));
    }
    l6 = INT64_C(0);
    while ((l6 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t0 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        l9 = vader_bytecode_slot_touched(t0);
        if ((l9 >= INT32_C(0))) {
            l10 = ((int64_t) (int32_t) l9);
            vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l10)
            t0 = vader_box_bool(285u, ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l10]);
            t1 = t0.payload.b;
            if (t1) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l10)
                t2 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l10);
                l13 = ((vader_struct_vader_bytecode_SlotRange_t*) t2)->f_first;
                l14 = ((int32_t) (int64_t) l6);
                vader_struct_vader_bytecode_SlotRange_t* _a8_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                vader_obj_header_init(_a8_obj, 774u);
                _a8_obj->f_first = l13;
                _a8_obj->f_last = l14;
                l15 = (void*) _a8_obj;
                vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l10)
                vader_array_ref_store(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l10, l15);
                VADER_WRITE_BARRIER(_a9_slotarr->buf);
            } else {
                l11 = ((int32_t) (int64_t) l6);
                l12 = ((int32_t) (int64_t) l6);
                vader_struct_vader_bytecode_SlotRange_t* _a10_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                vader_obj_header_init(_a10_obj, 774u);
                _a10_obj->f_first = l11;
                _a10_obj->f_last = l12;
                l8 = (void*) _a10_obj;
                vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l10)
                vader_array_ref_store(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l10, l8);
                VADER_WRITE_BARRIER(_a11_slotarr->buf);
                vader_array_t* _a12_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l10)
                ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l10] = (uint8_t) true;
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    l8 = vader_bytecode_find_loop_ranges(l3);
    t3 = ((vader_array_t*) l8)->length;
    if ((t3 > INT64_C(0))) {
        l16 = true;
        while (l16) {
            l16 = vader_bytecode_extend_into_loops(l5, l7, l2, l8);
        }
    }
    l6 = INT64_C(0);
    while ((l6 < l1)) {
        l9 = ((int32_t) (int64_t) l4);
        vader_struct_vader_bytecode_SlotRange_t* _a13_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
        vader_obj_header_init(_a13_obj, 774u);
        _a13_obj->f_first = INT32_C(0);
        _a13_obj->f_last = l9;
        l8 = (void*) _a13_obj;
        vader_array_t* _a14_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l6)
        vader_array_ref_store(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l6, l8);
        VADER_WRITE_BARRIER(_a14_slotarr->buf);
        vader_array_t* _a15_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l6)
        ((uint8_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l6] = (uint8_t) true;
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a16_arr = vader_array_new(54u, 0u, 13u, 646u);
    l8 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(15u, 0u, 7u, 290u);
    l15 = (void*) _a17_arr;
    if ((INT64_C(0) < l2)) {
        l6 = l2;
    } else {
        l6 = INT64_C(0);
    }
    vader_array_t* _a18_arr = vader_array_repeat((vader_array_t*) l15, (int64_t) l6);
    l15 = (void*) _a18_arr;
    l6 = INT64_C(0);
    vader_array_t* _pc216_hdr = (vader_array_t*) l15;
    size_t _pc216_len = _pc216_hdr->length;
    size_t _pc216_cap = (_pc216_hdr->offset == 0 && !vader_array_is_borrowed(_pc216_hdr) && _pc216_hdr->length >= _pc216_hdr->buf->length) ? _pc216_hdr->capacity : (size_t) 0;
    void* _pc216_slots = _pc216_hdr->buf->slots;
    for (;;) {
        if ((l6 < l2)) {
            if (VADER_LIKELY(_pc216_len < _pc216_cap)) {
                ((int32_t*) _pc216_slots)[_pc216_len] = (int32_t) (INT32_C(-1));
                _pc216_len += 1;
            } else {
                _pc216_hdr->length = _pc216_len;
                if (_pc216_hdr->buf->length < _pc216_len) {
                    _pc216_hdr->buf->length = _pc216_len;
                }
                vader_array_push_i32((vader_array_t*) l15, INT32_C(-1));
                _pc216_hdr = (vader_array_t*) l15;
                _pc216_len = _pc216_hdr->length;
                _pc216_cap = (_pc216_hdr->offset == 0 && !vader_array_is_borrowed(_pc216_hdr) && _pc216_hdr->length >= _pc216_hdr->buf->length) ? _pc216_hdr->capacity : (size_t) 0;
                _pc216_slots = _pc216_hdr->buf->slots;
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        _pc216_hdr->length = _pc216_len;
        if (_pc216_hdr->buf->length < _pc216_len) {
            _pc216_hdr->buf->length = _pc216_len;
        }
        break;
    }
    l6 = INT64_C(0);
    while ((l6 < l1)) {
        l9 = ((int32_t) (int64_t) l6);
        vader_array_t* _a19_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l6)
        ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l6] = (int32_t) l9;
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a20_arr = vader_array_new(58u, 0u, 13u, 774u);
    l17 = (void*) _a20_arr;
    if ((INT64_C(0) < l1)) {
        l6 = l1;
    } else {
        l6 = INT64_C(0);
    }
    vader_array_t* _a21_arr = vader_array_repeat((vader_array_t*) l17, (int64_t) l6);
    l17 = (void*) _a21_arr;
    l6 = INT64_C(0);
    while ((l6 < l1)) {
        vader_array_t* _a22_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l6)
        l18 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l6);
        vader_array_push((vader_array_t*) l17, vader_ref_box(l18));
        l6 = (l6 + INT64_C(1));
    }
    l6 = l1;
    while ((l6 < l2)) {
        vader_array_t* _a23_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l6)
        t0 = vader_box_bool(285u, ((uint8_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l6]);
        t1 = t0.payload.b;
        if (t1) {
            vader_array_t* _a24_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l6)
            l18 = vader_array_ref_load_obj(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l6);
            l19 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
            l10 = vader_chk_sub(i64, l6, l1);
            vader_array_t* _a25_slotarr = ((vader_array_t*) l19);
            VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l10)
            t2 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l10);
            l20 = ((vader_struct_vader_bytecode_BcLocal_t*) t2)->f_val;
            l9 = INT32_C(-1);
            l21 = l1;
            l22 = ((vader_array_t*) l17)->length;
            while ((l21 < l22)) {
                l23 = vader_chk_sub(i64, l21, l1);
                vader_array_t* _a26_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l23)
                t2 = vader_array_ref_load_obj(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l23);
                if (((vader_struct_vader_bytecode_BcLocal_t*) t2)->f_val == l20) {
                    vader_array_t* _a27_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l21)
                    t2 = vader_array_ref_load_obj(_a27_slotarr->buf, _a27_slotarr->offset + (size_t) l21);
                    t1 = vader_bytecode_ranges_overlap(t2, l18);
                    if (!(t1)) {
                        l9 = ((int32_t) (int64_t) l21);
                        break;
                    }
                }
                l21 = (l21 + INT64_C(1));
            }
            if ((l9 < INT32_C(0))) {
                t3 = ((vader_array_t*) l17)->length;
                l9 = ((int32_t) (int64_t) t3);
                vader_array_push((vader_array_t*) l17, vader_ref_box(l18));
                l24 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
                l25 = vader_chk_sub(i64, l6, l1);
                vader_array_t* _a28_slotarr = ((vader_array_t*) l24);
                VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l25)
                l26 = vader_array_ref_load_obj(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l25);
                vader_array_push((vader_array_t*) l8, vader_ref_box(l26));
            } else {
                vader_array_t* _a29_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l9)
                l27 = vader_array_ref_load_obj(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l9);
                l12 = ((vader_struct_vader_bytecode_SlotRange_t*) l18)->f_first;
                l13 = ((vader_struct_vader_bytecode_SlotRange_t*) l27)->f_first;
                if ((l12 < l13)) {
                    l11 = ((vader_struct_vader_bytecode_SlotRange_t*) l18)->f_first;
                } else {
                    l11 = ((vader_struct_vader_bytecode_SlotRange_t*) l27)->f_first;
                }
                l28 = ((vader_struct_vader_bytecode_SlotRange_t*) l18)->f_last;
                l29 = ((vader_struct_vader_bytecode_SlotRange_t*) l27)->f_last;
                if ((l28 > l29)) {
                    l14 = ((vader_struct_vader_bytecode_SlotRange_t*) l18)->f_last;
                } else {
                    l14 = ((vader_struct_vader_bytecode_SlotRange_t*) l27)->f_last;
                }
                vader_struct_vader_bytecode_SlotRange_t* _a30_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                vader_obj_header_init(_a30_obj, 774u);
                _a30_obj->f_first = l11;
                _a30_obj->f_last = l14;
                l30 = (void*) _a30_obj;
                vader_array_t* _a31_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l9)
                vader_array_ref_store(_a31_slotarr->buf, _a31_slotarr->offset + (size_t) l9, l30);
                VADER_WRITE_BARRIER(_a31_slotarr->buf);
            }
            vader_array_t* _a32_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l6)
            ((int32_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) l6] = (int32_t) l9;
            l6 = vader_chk_add(i64, l6, INT64_C(1));
            continue;
        }
        vader_array_t* _a33_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l6)
        ((int32_t*) _a33_slotarr->buf->slots)[_a33_slotarr->offset + (size_t) l6] = (int32_t) INT32_C(-1);
        l6 = vader_chk_add(i64, l6, INT64_C(1));
    }
    l16 = true;
    while ((l1 < l2)) {
        vader_array_t* _a34_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l1)
        l9 = ((int32_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l1];
        l11 = ((int32_t) (int64_t) l1);
        if (l9 != l11) {
            l16 = false;
            break;
        }
        l1 = (l1 + INT64_C(1));
    }
    if (l16) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a35_arr = vader_array_new(226u, 0u, 13u, 1538u);
    l5 = (void*) _a35_arr;
    l1 = INT64_C(0);
    while ((l1 < l4)) {
        vader_array_t* _a36_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
        l31 = vader_array_ref_load_box(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l1);
        l9 = vader_bytecode_slot_touched(l31);
        if ((l9 >= INT32_C(0))) {
            vader_array_t* _a37_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l9)
            l11 = ((int32_t*) _a37_slotarr->buf->slots)[_a37_slotarr->offset + (size_t) l9];
            if ((l11 >= INT32_C(0))) {
                l32 = vader_bytecode_with_remapped_slot(l31, l11);
                vader_array_push((vader_array_t*) l5, l32);
            } else {
                vader_array_push((vader_array_t*) l5, l31);
            }
        } else {
            l33 = vader_bytecode_remap_push_cache_slot(l31, l15);
            vader_array_push((vader_array_t*) l5, l33);
        }
        l1 = (l1 + INT64_C(1));
    }
    l3 = l0;
    l34 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_name;
    l16 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_is_main;
    l7 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature;
    l15 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_debug;
    l17 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_jump_table;
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_source_pc;
    vader_struct_vader_bytecode_BcFunction_t* _a38_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a38_obj, 643u);
    _a38_obj->f_name = l34;
    _a38_obj->f_is_main = l16;
    _a38_obj->f_signature = l7;
    _a38_obj->f_locals = l8;
    _a38_obj->f_body = l5;
    _a38_obj->f_debug = l15;
    _a38_obj->f_jump_table = l17;
    _a38_obj->f_source_pc = l3;
    t2 = (void*) _a38_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_bytecode_const_fills_slot(vader_box_t l0, uint8_t l1) {
    bool t0;
    uint8_t t1;
    if (l0.tag == 734u) {
        t0 = vader_bytecode_is_64_bit_int_val(l1);
        return t0;
    }
    if (!(l0.tag == 714u)) {
        t1 = vader_bytecode_const_val_type(l0);
        return t1 == l1;
    }
    t0 = vader_bytecode_is_integer_val(l1);
    if (t0) {
        t0 = vader_bytecode_is_64_bit_int_val(l1);
        return !(t0);
    }
    return false;
}

vader_box_t vader_bytecode_const_op_of(vader_box_t l0) {
    if (!((l0.tag == 663u || l0.tag == 678u || l0.tag == 693u || l0.tag == 714u || l0.tag == 734u || l0.tag == 765u || l0.tag == 783u))) {
        return vader_box_obj(0u, NULL);
    }
    return l0;
}

static uint8_t vader_bytecode_const_val_type(vader_box_t l0) {
    uint8_t l1;
    if (l0.tag == 714u) {
        l1 = (uint8_t) 2;
        return l1;
    }
    if (l0.tag == 734u) {
        l1 = (uint8_t) 3;
    } else if (l0.tag == 693u) {
        l1 = (uint8_t) 9;
    } else if (l0.tag == 663u) {
        l1 = (uint8_t) 10;
    } else if (l0.tag == 678u) {
        l1 = (uint8_t) 11;
    } else if (l0.tag == 783u) {
        l1 = (uint8_t) 12;
    } else {
        if (!(l0.tag == 765u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = (uint8_t) 13;
    }
    return l1;
}

static vader_string_t vader_bytecode_convert_target_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 1902u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1924u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1777u;
    } else {
        if (!(l0 == INT32_C(3))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1581u;
    }
    return l1;
}

vader_box_t vader_bytecode_convert_target_of(uint8_t l0) {
    vader_box_t l1;
    if (l0 == INT32_C(0)) {
        l1 = vader_box_i32(292u, INT32_C(0));
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = vader_box_i32(292u, INT32_C(0));
    } else if (l0 == INT32_C(2)) {
        l1 = vader_box_i32(292u, INT32_C(0));
    } else if (l0 == INT32_C(4)) {
        l1 = vader_box_i32(292u, INT32_C(0));
    } else if (l0 == INT32_C(5)) {
        l1 = vader_box_i32(292u, INT32_C(0));
    } else if (l0 == INT32_C(6)) {
        l1 = vader_box_i32(292u, INT32_C(0));
    } else if (l0 == INT32_C(3)) {
        l1 = vader_box_i32(292u, INT32_C(1));
    } else if (l0 == INT32_C(7)) {
        l1 = vader_box_i32(292u, INT32_C(1));
    } else if (l0 == INT32_C(8)) {
        l1 = vader_box_i32(292u, INT32_C(2));
    } else if (l0 == INT32_C(9)) {
        l1 = vader_box_i32(292u, INT32_C(2));
    } else if (l0 == INT32_C(11)) {
        l1 = vader_box_i32(292u, INT32_C(3));
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

void* vader_bytecode_data_pool_type_ids(void* l0) {
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
    vader_array_t* _a0_arr = vader_array_new(15u, 1u, 7u, 290u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(0);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_data_pool)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    t0 = ((vader_array_t*) l1)->length;
    if (t0 == INT64_C(0)) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_body;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l8 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
            if (l8.tag == 682u) {
                t1 = l8.payload.obj;
                t2 = ((vader_struct_vader_bytecode_DataConst_t*) t1)->f_pool_index;
                if ((t2 >= INT32_C(0))) {
                    t1 = l8.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_DataConst_t*) t1)->f_pool_index;
                    l9 = ((int64_t) (int32_t) t2);
                    l10 = ((vader_array_t*) l1)->length;
                    if ((l9 < l10)) {
                        t1 = l8.payload.obj;
                        l11 = ((vader_struct_vader_bytecode_DataConst_t*) t1)->f_pool_index;
                        t1 = l8.payload.obj;
                        l12 = ((vader_struct_vader_bytecode_DataConst_t*) t1)->f_type_id;
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

void* vader_bytecode_default_emit_options(void) {
    void* l0 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 287u);
    l0 = (void*) _a0_arr;
    vader_struct_vader_bytecode_EmitOptions_t* _a1_obj = (vader_struct_vader_bytecode_EmitOptions_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_EmitOptions_t));
    vader_obj_header_init(_a1_obj, 688u);
    _a1_obj->f_optimize = true;
    _a1_obj->f_keep_mangles = l0;
    _a1_obj->f_want_debug = false;
    _a1_obj->f_verify = false;
    _a1_obj->f_prove_bounds = false;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_div_op(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Div_t* _a0_obj = (vader_struct_vader_bytecode_U64Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Div_t));
        vader_obj_header_init(_a0_obj, 797u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (!(t0)) {
        t2 = vader_bytecode_arith_op(l0, 1672u);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_U32Div_t* _a1_obj = (vader_struct_vader_bytecode_U32Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Div_t));
    vader_obj_header_init(_a1_obj, 791u);
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_drop_dead_stores(void* l0) {
    int64_t l1, l2, l4, l6;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l20 = NULL;
    void* l23 = NULL;
    void* l29 = NULL;
    vader_box_t l7 = vader_box_null(), l31 = vader_box_null();
    int32_t l8, l9, l10, l11, l17, l18, l19, l21, l22, l24, l25, l26, l27, l28, l30;
    bool l12;
    vader_string_t l32 = 0;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t t2 = vader_box_null();
    bool t3;
    int64_t t4;
    vader_box_t* gc_roots[3] = { &l7, &l31, &t2 };
    void** gc_raw_roots[11] = { &l0, &l3, &l5, &l13, &l14, &l15, &l16, &l20, &l23, &l29, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l32 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    l2 = vader_chk_add(i64, l1, l2);
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l3 = (void*) _a0_arr;
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    l4 = INT64_C(0);
    vader_array_t* _pc29_hdr = (vader_array_t*) l3;
    size_t _pc29_len = _pc29_hdr->length;
    size_t _pc29_cap = (_pc29_hdr->offset == 0 && !vader_array_is_borrowed(_pc29_hdr) && _pc29_hdr->length >= _pc29_hdr->buf->length) ? _pc29_hdr->capacity : (size_t) 0;
    void* _pc29_slots = _pc29_hdr->buf->slots;
    for (;;) {
        if ((l4 < l2)) {
            if (VADER_LIKELY(_pc29_len < _pc29_cap)) {
                ((int32_t*) _pc29_slots)[_pc29_len] = (int32_t) (INT32_C(0));
                _pc29_len += 1;
            } else {
                _pc29_hdr->length = _pc29_len;
                if (_pc29_hdr->buf->length < _pc29_len) {
                    _pc29_hdr->buf->length = _pc29_len;
                }
                vader_array_push_i32((vader_array_t*) l3, INT32_C(0));
                _pc29_hdr = (vader_array_t*) l3;
                _pc29_len = _pc29_hdr->length;
                _pc29_cap = (_pc29_hdr->offset == 0 && !vader_array_is_borrowed(_pc29_hdr) && _pc29_hdr->length >= _pc29_hdr->buf->length) ? _pc29_hdr->capacity : (size_t) 0;
                _pc29_slots = _pc29_hdr->buf->slots;
            }
            l4 = (l4 + INT64_C(1));
            continue;
        }
        _pc29_hdr->length = _pc29_len;
        if (_pc29_hdr->buf->length < _pc29_len) {
            _pc29_hdr->buf->length = _pc29_len;
        }
        break;
    }
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l4 = ((vader_array_t*) l5)->length;
    l6 = INT64_C(0);
    while ((l6 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        if (l7.tag == 759u) {
            t0 = l7.payload.obj;
            l8 = ((vader_struct_vader_bytecode_LocalGet_t*) t0)->f_slot;
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
            t1 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l8];
            l9 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
            ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l8] = (int32_t) l9;
        }
        if (l7.tag == 758u) {
            t0 = l7.payload.obj;
            l10 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_slot;
            vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
            t1 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l10];
            l11 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
            ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l10] = (int32_t) l11;
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a5_arr = vader_array_new(12u, 0u, 12u, 285u);
    l5 = (void*) _a5_arr;
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l4);
    l5 = (void*) _a6_arr;
    l4 = INT64_C(0);
    vader_array_t* _pc121_hdr = (vader_array_t*) l5;
    size_t _pc121_len = _pc121_hdr->length;
    size_t _pc121_cap = (_pc121_hdr->offset == 0 && !vader_array_is_borrowed(_pc121_hdr) && _pc121_hdr->length >= _pc121_hdr->buf->length) ? _pc121_hdr->capacity : (size_t) 0;
    void* _pc121_slots = _pc121_hdr->buf->slots;
    for (;;) {
        if ((l4 < l2)) {
            if (VADER_LIKELY(_pc121_len < _pc121_cap)) {
                ((uint8_t*) _pc121_slots)[_pc121_len] = (uint8_t) (false);
                _pc121_len += 1;
            } else {
                _pc121_hdr->length = _pc121_len;
                if (_pc121_hdr->buf->length < _pc121_len) {
                    _pc121_hdr->buf->length = _pc121_len;
                }
                vader_array_push_bool((vader_array_t*) l5, false);
                _pc121_hdr = (vader_array_t*) l5;
                _pc121_len = _pc121_hdr->length;
                _pc121_cap = (_pc121_hdr->offset == 0 && !vader_array_is_borrowed(_pc121_hdr) && _pc121_hdr->length >= _pc121_hdr->buf->length) ? _pc121_hdr->capacity : (size_t) 0;
                _pc121_slots = _pc121_hdr->buf->slots;
            }
            l4 = (l4 + INT64_C(1));
            continue;
        }
        _pc121_hdr->length = _pc121_len;
        if (_pc121_hdr->buf->length < _pc121_len) {
            _pc121_hdr->buf->length = _pc121_len;
        }
        break;
    }
    l12 = false;
    l4 = l1;
    while ((l4 < l2)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l4)
        t1 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l4];
        if (t1 == INT32_C(0)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l4)
            ((uint8_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l4] = (uint8_t) true;
            l12 = true;
        }
        l4 = (l4 + INT64_C(1));
    }
    if (!(l12)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a9_arr = vader_array_new(15u, 0u, 7u, 290u);
    l3 = (void*) _a9_arr;
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a10_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a10_arr;
    l4 = INT64_C(0);
    vader_array_t* _pc189_hdr = (vader_array_t*) l3;
    size_t _pc189_len = _pc189_hdr->length;
    size_t _pc189_cap = (_pc189_hdr->offset == 0 && !vader_array_is_borrowed(_pc189_hdr) && _pc189_hdr->length >= _pc189_hdr->buf->length) ? _pc189_hdr->capacity : (size_t) 0;
    void* _pc189_slots = _pc189_hdr->buf->slots;
    for (;;) {
        if ((l4 < l2)) {
            if (VADER_LIKELY(_pc189_len < _pc189_cap)) {
                ((int32_t*) _pc189_slots)[_pc189_len] = (int32_t) (INT32_C(-1));
                _pc189_len += 1;
            } else {
                _pc189_hdr->length = _pc189_len;
                if (_pc189_hdr->buf->length < _pc189_len) {
                    _pc189_hdr->buf->length = _pc189_len;
                }
                vader_array_push_i32((vader_array_t*) l3, INT32_C(-1));
                _pc189_hdr = (vader_array_t*) l3;
                _pc189_len = _pc189_hdr->length;
                _pc189_cap = (_pc189_hdr->offset == 0 && !vader_array_is_borrowed(_pc189_hdr) && _pc189_hdr->length >= _pc189_hdr->buf->length) ? _pc189_hdr->capacity : (size_t) 0;
                _pc189_slots = _pc189_hdr->buf->slots;
            }
            l4 = (l4 + INT64_C(1));
            continue;
        }
        _pc189_hdr->length = _pc189_len;
        if (_pc189_hdr->buf->length < _pc189_len) {
            _pc189_hdr->buf->length = _pc189_len;
        }
        break;
    }
    l8 = INT32_C(0);
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l4)
        t2 = vader_box_bool(285u, ((uint8_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l4]);
        t3 = t2.payload.b;
        if (!(t3)) {
            vader_array_t* _a12_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l4)
            ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l4] = (int32_t) l8;
            l8 = vader_chk_add(i32, l8, INT32_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    vader_array_t* _a13_arr = vader_array_new(226u, 0u, 13u, 1538u);
    l13 = (void*) _a13_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body)->length;
    vader_array_t* _a14_arr = vader_array_new(15u, 0u, 7u, 290u);
    l14 = (void*) _a14_arr;
    if ((INT64_C(0) < l4)) {
        l6 = l4;
    } else {
        l6 = INT64_C(0);
    }
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) l14, (int64_t) l6);
    l14 = (void*) _a15_arr;
    l6 = INT64_C(0);
    vader_array_t* _pc258_hdr = (vader_array_t*) l14;
    size_t _pc258_len = _pc258_hdr->length;
    size_t _pc258_cap = (_pc258_hdr->offset == 0 && !vader_array_is_borrowed(_pc258_hdr) && _pc258_hdr->length >= _pc258_hdr->buf->length) ? _pc258_hdr->capacity : (size_t) 0;
    void* _pc258_slots = _pc258_hdr->buf->slots;
    for (;;) {
        if ((l6 < l4)) {
            if (VADER_LIKELY(_pc258_len < _pc258_cap)) {
                ((int32_t*) _pc258_slots)[_pc258_len] = (int32_t) (INT32_C(-1));
                _pc258_len += 1;
            } else {
                _pc258_hdr->length = _pc258_len;
                if (_pc258_hdr->buf->length < _pc258_len) {
                    _pc258_hdr->buf->length = _pc258_len;
                }
                vader_array_push_i32((vader_array_t*) l14, INT32_C(-1));
                _pc258_hdr = (vader_array_t*) l14;
                _pc258_len = _pc258_hdr->length;
                _pc258_cap = (_pc258_hdr->offset == 0 && !vader_array_is_borrowed(_pc258_hdr) && _pc258_hdr->length >= _pc258_hdr->buf->length) ? _pc258_hdr->capacity : (size_t) 0;
                _pc258_slots = _pc258_hdr->buf->slots;
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        _pc258_hdr->length = _pc258_len;
        if (_pc258_hdr->buf->length < _pc258_len) {
            _pc258_hdr->buf->length = _pc258_len;
        }
        break;
    }
    l6 = INT64_C(0);
    while ((l6 < l4)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l6)
        l7 = vader_array_ref_load_box(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l6);
        if (l7.tag == 760u) {
            t0 = l7.payload.obj;
            l8 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
            vader_array_t* _a17_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l8)
            t2 = vader_box_bool(285u, ((uint8_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l8]);
            t3 = t2.payload.b;
            if (t3) {
                t4 = ((vader_array_t*) l13)->length;
                l9 = ((int32_t) (int64_t) t4);
                vader_array_t* _a18_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l6)
                ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l6] = (int32_t) l9;
                vader_struct_vader_bytecode_Drop_t* _a19_obj = (vader_struct_vader_bytecode_Drop_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Drop_t));
                vader_obj_header_init(_a19_obj, 686u);
                l15 = (void*) _a19_obj;
                vader_array_push((vader_array_t*) l13, vader_ref_box(l15));
            } else {
                t4 = ((vader_array_t*) l13)->length;
                l10 = ((int32_t) (int64_t) t4);
                vader_array_t* _a20_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l6)
                ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l6] = (int32_t) l10;
                t0 = l7.payload.obj;
                l11 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
                vader_array_t* _a21_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l11)
                t1 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l11];
                vader_struct_vader_bytecode_LocalSet_t* _a22_obj = (vader_struct_vader_bytecode_LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalSet_t));
                vader_obj_header_init(_a22_obj, 760u);
                _a22_obj->f_slot = t1;
                l16 = (void*) _a22_obj;
                vader_array_push((vader_array_t*) l13, vader_ref_box(l16));
            }
            l6 = vader_chk_add(i64, l6, INT64_C(1));
            continue;
        }
        if (l7.tag == 761u) {
            t0 = l7.payload.obj;
            l17 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
            vader_array_t* _a23_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l17)
            t2 = vader_box_bool(285u, ((uint8_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l17]);
            t3 = t2.payload.b;
            if (t3) {
                l6 = vader_chk_add(i64, l6, INT64_C(1));
                continue;
            }
            t4 = ((vader_array_t*) l13)->length;
            l18 = ((int32_t) (int64_t) t4);
            vader_array_t* _a24_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l6)
            ((int32_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l6] = (int32_t) l18;
            t0 = l7.payload.obj;
            l19 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
            vader_array_t* _a25_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l19)
            t1 = ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l19];
            vader_struct_vader_bytecode_LocalTee_t* _a26_obj = (vader_struct_vader_bytecode_LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalTee_t));
            vader_obj_header_init(_a26_obj, 761u);
            _a26_obj->f_slot = t1;
            l20 = (void*) _a26_obj;
            vader_array_push((vader_array_t*) l13, vader_ref_box(l20));
            l6 = vader_chk_add(i64, l6, INT64_C(1));
            continue;
        }
        if (l7.tag == 759u) {
            t4 = ((vader_array_t*) l13)->length;
            l21 = ((int32_t) (int64_t) t4);
            vader_array_t* _a27_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l6)
            ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l6] = (int32_t) l21;
            t0 = l7.payload.obj;
            l22 = ((vader_struct_vader_bytecode_LocalGet_t*) t0)->f_slot;
            vader_array_t* _a28_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l22)
            t1 = ((int32_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l22];
            vader_struct_vader_bytecode_LocalGet_t* _a29_obj = (vader_struct_vader_bytecode_LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalGet_t));
            vader_obj_header_init(_a29_obj, 759u);
            _a29_obj->f_slot = t1;
            l23 = (void*) _a29_obj;
            vader_array_push((vader_array_t*) l13, vader_ref_box(l23));
            l6 = vader_chk_add(i64, l6, INT64_C(1));
            continue;
        }
        if (l7.tag == 758u) {
            t4 = ((vader_array_t*) l13)->length;
            l24 = ((int32_t) (int64_t) t4);
            vader_array_t* _a30_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l6)
            ((int32_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l6] = (int32_t) l24;
            t0 = l7.payload.obj;
            l25 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_slot;
            vader_array_t* _a31_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l25)
            l26 = ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l25];
            t0 = l7.payload.obj;
            l27 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_type_id;
            t0 = l7.payload.obj;
            l28 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_field_index;
            vader_struct_vader_bytecode_LocalField_t* _a32_obj = (vader_struct_vader_bytecode_LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalField_t));
            vader_obj_header_init(_a32_obj, 758u);
            _a32_obj->f_slot = l26;
            _a32_obj->f_type_id = l27;
            _a32_obj->f_field_index = l28;
            l29 = (void*) _a32_obj;
            vader_array_push((vader_array_t*) l13, vader_ref_box(l29));
            l6 = vader_chk_add(i64, l6, INT64_C(1));
            continue;
        }
        t4 = ((vader_array_t*) l13)->length;
        l30 = ((int32_t) (int64_t) t4);
        vader_array_t* _a33_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l6)
        ((int32_t*) _a33_slotarr->buf->slots)[_a33_slotarr->offset + (size_t) l6] = (int32_t) l30;
        l31 = vader_bytecode_remap_push_cache_slot(l7, l3);
        vader_array_push((vader_array_t*) l13, l31);
        l6 = vader_chk_add(i64, l6, INT64_C(1));
    }
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l4 = ((vader_array_t*) l13)->length;
    l3 = vader_bytecode_remap_jump_table(l3, l14, l4);
    l15 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug;
    l4 = ((vader_array_t*) l13)->length;
    l14 = vader_bytecode_remap_debug(l15, l14, l4);
    vader_array_t* _a34_arr = vader_array_new(54u, 0u, 13u, 646u);
    l15 = (void*) _a34_arr;
    l4 = l1;
    while ((l4 < l2)) {
        vader_array_t* _a35_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l4)
        t2 = vader_box_bool(285u, ((uint8_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l4]);
        t3 = t2.payload.b;
        if (!(t3)) {
            l16 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
            l6 = vader_chk_sub(i64, l4, l1);
            vader_array_t* _a36_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l6)
            l20 = vader_array_ref_load_obj(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l6);
            vader_array_push((vader_array_t*) l15, vader_ref_box(l20));
        }
        l4 = (l4 + INT64_C(1));
    }
    l5 = l0;
    l32 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_name;
    l12 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_is_main;
    l16 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_signature;
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_source_pc;
    vader_struct_vader_bytecode_BcFunction_t* _a37_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a37_obj, 643u);
    _a37_obj->f_name = l32;
    _a37_obj->f_is_main = l12;
    _a37_obj->f_signature = l16;
    _a37_obj->f_locals = l15;
    _a37_obj->f_body = l13;
    _a37_obj->f_debug = l14;
    _a37_obj->f_jump_table = l3;
    _a37_obj->f_source_pc = l5;
    t0 = (void*) _a37_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_drop_unbranched_blocks(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    int64_t l3, l5, l9;
    int32_t l6;
    bool l8;
    vader_box_t l11 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l11, &t0 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l4, &l7, &l10, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l2 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l3 = ((vader_array_t*) l1)->length;
    vader_array_t* _a0_arr = vader_array_new(12u, 1u, 12u, 285u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    l4 = (void*) _a0_arr;
    l5 = vader_chk_add(i64, l3, INT64_C(1));
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a1_arr;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l6 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t0 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        if ((t0.tag == 668u || t0.tag == 669u)) {
            if ((l6 >= INT32_C(0))) {
                if ((((int64_t) (int32_t) l6) <= l3)) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l6] = (uint8_t) true;
                }
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a5_arr = vader_array_new(12u, 1u, 12u, 285u);
    ((uint8_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (uint8_t) false;
    t1 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l3);
    l7 = (void*) _a6_arr;
    l8 = false;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
        l6 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l5];
        vader_array_t* _a8_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        t0 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l5);
        if (t0.tag == 661u) {
            if ((l6 > INT32_C(0))) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l6)
                t0 = vader_box_bool(285u, ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l6]);
                t2 = t0.payload.b;
                if (!(t2)) {
                    vader_array_t* _a10_slotarr = ((vader_array_t*) l7);
                    VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l5)
                    ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l5] = (uint8_t) true;
                    l9 = vader_chk_sub(i64, ((int64_t) (int32_t) l6), INT64_C(1));
                    VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l9)
                    ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l9] = (uint8_t) true;
                    l8 = true;
                }
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    if (!(l8)) {
        t1 = vader_bytecode_bc_peephole_unchanged(l0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a11_arr = vader_array_new(226u, 0u, 13u, 1538u);
    l4 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(15u, 0u, 7u, 290u);
    l10 = (void*) _a12_arr;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l5)
        t0 = vader_box_bool(285u, ((uint8_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l5]);
        t2 = t0.payload.b;
        if (t2) {
            vader_array_push_i32((vader_array_t*) l10, INT32_C(-1));
        } else {
            t3 = ((vader_array_t*) l4)->length;
            l6 = ((int32_t) (int64_t) t3);
            vader_array_push_i32((vader_array_t*) l10, l6);
            vader_array_t* _a14_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            l11 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l5);
            vader_array_push((vader_array_t*) l4, l11);
        }
        l5 = (l5 + INT64_C(1));
    }
    l3 = ((vader_array_t*) l4)->length;
    l1 = vader_bytecode_remap_jump_table(l2, l10, l3);
    l2 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug;
    l3 = ((vader_array_t*) l4)->length;
    l2 = vader_bytecode_remap_debug(l2, l10, l3);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a15_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a15_obj, 647u);
    _a15_obj->f_body = l4;
    _a15_obj->f_jump_table = l1;
    _a15_obj->f_debug = l2;
    t1 = (void*) _a15_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_bytecode_extend_into_loops(void* l0, void* l1, int64_t l2, void* l3) {
    bool l4;
    int64_t l5, l8, l9;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    int32_t l11, l12, l13, l14, l15, l16, l17, l18, l19, l20, l21, l22;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l6, &l7, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = false;
    l5 = INT64_C(0);
    while ((l5 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_box_bool(285u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5]);
        t1 = t0.payload.b;
        if (t1) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
            l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            l7 = l3;
            l8 = ((vader_array_t*) l7)->length;
            l9 = INT64_C(0);
            while ((l9 < l8)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                l10 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
                l11 = ((vader_struct_vader_bytecode_SlotRange_t*) l6)->f_first;
                l12 = ((vader_struct_vader_bytecode_SlotRange_t*) l10)->f_last;
                if ((l11 <= l12)) {
                    l13 = ((vader_struct_vader_bytecode_SlotRange_t*) l6)->f_last;
                    l14 = ((vader_struct_vader_bytecode_SlotRange_t*) l10)->f_first;
                    if ((l13 >= l14)) {
                        l15 = ((vader_struct_vader_bytecode_SlotRange_t*) l6)->f_first;
                        l16 = ((vader_struct_vader_bytecode_SlotRange_t*) l10)->f_first;
                        if ((l15 > l16)) {
                            l17 = ((vader_struct_vader_bytecode_SlotRange_t*) l10)->f_first;
                            l18 = ((vader_struct_vader_bytecode_SlotRange_t*) l6)->f_last;
                            vader_struct_vader_bytecode_SlotRange_t* _a3_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                            vader_obj_header_init(_a3_obj, 774u);
                            _a3_obj->f_first = l17;
                            _a3_obj->f_last = l18;
                            l6 = (void*) _a3_obj;
                            l4 = true;
                        }
                        l19 = ((vader_struct_vader_bytecode_SlotRange_t*) l6)->f_last;
                        l20 = ((vader_struct_vader_bytecode_SlotRange_t*) l10)->f_last;
                        if ((l19 < l20)) {
                            l21 = ((vader_struct_vader_bytecode_SlotRange_t*) l6)->f_first;
                            l22 = ((vader_struct_vader_bytecode_SlotRange_t*) l10)->f_last;
                            vader_struct_vader_bytecode_SlotRange_t* _a4_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                            vader_obj_header_init(_a4_obj, 774u);
                            _a4_obj->f_first = l21;
                            _a4_obj->f_last = l22;
                            l6 = (void*) _a4_obj;
                            l4 = true;
                        }
                    }
                }
                l9 = (l9 + INT64_C(1));
            }
            vader_array_t* _a5_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
            vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5, l6);
            VADER_WRITE_BARRIER(_a5_slotarr->buf);
        }
        l5 = (l5 + INT64_C(1));
    }
    { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_bytecode_f64_const_operands(double l0) {
    uint64_t l1;
    vader_string_t l2 = 0;
    int64_t l3;
    void* l4 = NULL;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l4 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = l0 }).__vu);
    l1 = (uint64_t) (int64_t) t0;
    if (!(((l1 >> INT64_C(52)) & INT64_C(2047)) == INT64_C(2047))) {
        l2 = std_core_f64_Display_to_string(l0);
        l3 = vader_host_std_core_byte_len(l2);
        l4 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l3));
        l3 = INT64_C(0);
        l3 = std_core_write_string_at(l4, l3, l2);
        l3 = std_core_write_string_at(l4, l3, 10u);
        l3 = std_core_write_unsigned(l4, l3, l1);
        t1 = std_core_finish_buffer(l4, l3);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = std_core_f64_Display_to_string(l0);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_bytecode_find_loop_ranges(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l13 = NULL;
    int64_t l4, l5, l6;
    vader_box_t l7 = vader_box_null();
    int32_t l8, l9, l10, l11, l12;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l7, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l13 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(58u, 0u, 13u, 774u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(14u, 0u, 0u, 287u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 290u);
    l3 = (void*) _a2_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) l0)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        if (l7.tag == 661u) {
            l8 = ((int32_t) (int64_t) l6);
            vader_bytecode_push_scope(l2, l3, l4, 1472u, l8);
            l4 = vader_chk_add(i64, l4, INT64_C(1));
        } else if (l7.tag == 762u) {
            l9 = ((int32_t) (int64_t) l6);
            vader_bytecode_push_scope(l2, l3, l4, 2101u, l9);
            l4 = vader_chk_add(i64, l4, INT64_C(1));
        } else if (l7.tag == 749u) {
            l10 = ((int32_t) (int64_t) l6);
            vader_bytecode_push_scope(l2, l3, l4, 1951u, l10);
            l4 = vader_chk_add(i64, l4, INT64_C(1));
        } else if (l7.tag == 690u) {
            if ((l4 > INT64_C(0))) {
                l4 = vader_chk_sub(i64, l4, INT64_C(1));
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l4];
                t1 = t0.payload.s;
                if (t1 == 2101u) {
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                    l11 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4];
                    l12 = ((int32_t) (int64_t) l6);
                    vader_struct_vader_bytecode_SlotRange_t* _a6_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                    vader_obj_header_init(_a6_obj, 774u);
                    _a6_obj->f_first = l11;
                    _a6_obj->f_last = l12;
                    l13 = (void*) _a6_obj;
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l13));
                }
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_bytecode_fnv1a_hex(vader_string_t l0) {
    uint64_t l1, l4, l7;
    int64_t l2, l3;
    vader_string_t l5 = 0;
    vader_string_t l9 = 0;
    int32_t l6;
    void* l8 = NULL;
    uint8_t t0;
    int64_t t1;
    int32_t t2, t3;
    void** gc_raw_roots[1] = { &l8 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l5, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = (uint64_t) -3750763034362895579;
    l2 = INT64_C(0);
    l3 = vader_host_std_core_byte_len(l0);
    while ((l2 < l3)) {
        t0 = vader_host_std_core_byte_at(l0, l2);
        t1 = ((int64_t) (uint8_t) t0);
        l4 = (uint64_t) (int64_t) t1;
        t1 = ((l1 ^ l4) * INT64_C(1099511628211));
        l1 = (uint64_t) (int64_t) t1;
        l2 = (l2 + INT64_C(1));
    }
    l5 = 0u;
    l6 = INT32_C(0);
    while ((l6 < INT32_C(16))) {
        t2 = vader_chk_sub(i32, INT32_C(15), l6);
        t3 = vader_chk_mul(i32, t2, INT32_C(4));
        t1 = ((int64_t) (int32_t) t3);
        l4 = (uint64_t) (int64_t) t1;
        t1 = ((l1 >> (l4 & 63)) & INT64_C(15));
        l7 = (uint64_t) (int64_t) t1;
        l2 = ((int64_t) (uint64_t) l7);
        l3 = vader_chk_add(i64, ((int64_t) (uint64_t) l7), INT64_C(1));
        vader_struct_std_core_Range__i64_t* _a0_obj = (vader_struct_std_core_Range__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_core_Range__i64_t));
        vader_obj_header_init(_a0_obj, 527u);
        _a0_obj->f_start = l2;
        _a0_obj->f_end = l3;
        _a0_obj->f_inclusive = false;
        _a0_obj->f_done = false;
        _a0_obj->f_cursor = l2;
        l8 = (void*) _a0_obj;
        l9 = std_core_string_Index_at_1(390u, l8);
        l5 = concat_2(l5, l9);
        l6 = (l6 + INT32_C(1));
    }
    { vader_string_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_bytecode_foldable_self_copy(void* l0, int64_t l1, int64_t l2, void* l3) {
    int64_t l4;
    vader_box_t l5, l6;
    int32_t l7, l8;
    int64_t t0;
    vader_box_t t1;
    bool t2;
    void* t3;
    t0 = vader_chk_add(i64, l1, INT64_C(1));
    if ((t0 >= l2)) {
        return false;
    }
    l4 = vader_chk_add(i64, l1, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t1 = vader_box_bool(285u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4]);
    t2 = t1.payload.b;
    if (t2) {
        return false;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
    if (l5.tag == 759u) {
        l4 = vader_chk_add(i64, l1, INT64_C(1));
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        if (l6.tag == 761u) {
            t3 = l6.payload.obj;
            l7 = ((vader_struct_vader_bytecode_LocalTee_t*) t3)->f_slot;
            t3 = l5.payload.obj;
            l8 = ((vader_struct_vader_bytecode_LocalGet_t*) t3)->f_slot;
            return l7 == l8;
        }
        if (l6.tag == 760u) {
            t3 = l6.payload.obj;
            l7 = ((vader_struct_vader_bytecode_LocalSet_t*) t3)->f_slot;
            t3 = l5.payload.obj;
            l8 = ((vader_struct_vader_bytecode_LocalGet_t*) t3)->f_slot;
            return l7 == l8;
        }
        return false;
    }
    return false;
}

static int64_t vader_bytecode_integer_bits(uint8_t l0) {
    int32_t t0;
    int64_t t1;
    t0 = vader_bytecode_size_of_val_type(l0);
    t1 = vader_chk_mul(i64, ((int64_t) (int32_t) t0), INT64_C(8));
    return t1;
}

static vader_box_t vader_bytecode_integer_op(uint8_t l0, int64_t l1, bool l2, int64_t l3, int64_t l4) {
    vader_box_t l5;
    if (l0 == INT32_C(0)) {
        l5 = vader_integer_checked_add(l1, l2, l3, l4);
        return l5;
    }
    if (l0 == INT32_C(1)) {
        l5 = vader_integer_checked_sub(l1, l2, l3, l4);
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l5 = vader_integer_checked_mul(l1, l2, l3, l4);
    }
    return l5;
}

int32_t vader_bytecode_intern_cell_type(vader_box_t l0, void* l1) {
    int32_t l2, l5;
    vader_string_t l3 = 0;
    vader_string_t l8 = 0;
    vader_box_t l4 = vader_box_null();
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t t0;
    vader_string_t t1 = 0;
    int32_t t2;
    vader_box_t* gc_roots[2] = { &l0, &l4 };
    void** gc_raw_roots[3] = { &l1, &l6, &l7 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l8, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_bytecode_intern_type(l0, l1);
    l3 = vader_bytecode_type_intern_key(l0);
    l3 = concat_3(213u, l3, 457u);
    l4 = std_collections_MutableMap_std_core_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l3);
    if (!(l4.tag == 290u)) {
        t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
        l5 = ((int32_t) (int64_t) t0);
        vader_struct_vader_bytecode_BcField_t* _a0_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
        vader_obj_header_init(_a0_obj, 641u);
        _a0_obj->f_name = 2769u;
        _a0_obj->f_type_index = l2;
        l6 = (void*) _a0_obj;
        vader_array_t* _a1_arr = vader_array_new(50u, 0u, 13u, 641u);
        l7 = (void*) _a1_arr;
        vader_array_push((vader_array_t*) l7, vader_ref_box(l6));
        l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
        l8 = vader_bytecode_type_intern_key(l0);
        t1 = concat_2(214u, l8);
        vader_struct_vader_bytecode_BcStruct_t* _a2_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
        vader_obj_header_init(_a2_obj, 653u);
        _a2_obj->f_name = t1;
        _a2_obj->f_fields = l7;
        _a2_obj->f_c_name = 0u;
        _a2_obj->f_symbol_id = INT32_C(-1);
        l7 = (void*) _a2_obj;
        vader_array_push((vader_array_t*) l6, vader_ref_box(l7));
        std_collections_MutableMap_std_core_IndexSet_set_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l3, l5);
        { int32_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int32_t) l4.payload.i);
    { int32_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_bytecode_intern_string(vader_string_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int32_t l3;
    int64_t t0;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_collections_MutableMap_std_core_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_string_key, l0);
    if (!(l2.tag == 290u)) {
        t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_strings)->length;
        l3 = ((int32_t) (int64_t) t0);
        vader_array_push((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_strings, vader_box_string(287u, l0));
        std_collections_MutableMap_std_core_IndexSet_set_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_string_key, l0, l3);
        { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((int32_t) l2.payload.i);
    { int32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_bytecode_intern_type(vader_box_t l0, void* l1) {
    uint64_t l2;
    vader_box_t l3 = vader_box_null(), l9 = vader_box_null();
    int64_t l4, l6;
    bool l5;
    void* l7 = NULL;
    int32_t l8;
    vader_string_t l10 = 0;
    int32_t t0;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    int64_t t4;
    void* t5 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l3, &l9, &t2 };
    void** gc_raw_roots[3] = { &l1, &l7, &t5 };
    vader_string_t* gc_atom_roots[2] = { &l10, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_bytecode_type_intern_hash(l0);
    l3 = std_collections_MutableMap_std_core_Index_at__u64__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_hash, l2);
    if (l3.tag == 290u) {
        t0 = ((int32_t) l3.payload.i);
        l4 = ((int64_t) (int32_t) t0);
        if ((INT64_C(0) <= l4)) {
            l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_by_slot)->length;
            l5 = (l4 < l6);
        } else {
            l5 = false;
        }
        if (l5) {
            l7 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_by_slot;
            l8 = ((int32_t) l3.payload.i);
            vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
            l9 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
            t1 = vader_bytecode_same_intern_class(l0, l9);
            if (t1) {
                t0 = ((int32_t) l3.payload.i);
                { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    l10 = vader_bytecode_type_intern_key(l0);
    l3 = std_collections_MutableMap_std_core_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l10);
    if (l3.tag == 290u) {
        t2 = std_collections_MutableMap_std_core_Index_at__u64__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_hash, l2);
        if (t2.tag == 0u) {
            l7 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_hash;
            l8 = ((int32_t) l3.payload.i);
            std_collections_MutableMap_std_core_IndexSet_set_at__u64__i32(l7, l2, l8);
            l8 = ((int32_t) l3.payload.i);
            vader_bytecode_record_slot_type(l1, l8, l0);
            t0 = ((int32_t) l3.payload.i);
            { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = ((int32_t) l3.payload.i);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types_frozen;
    if (t1) {
        t3 = concat_3(1523u, l10, 924u);
        vader_host_std_abort_panic(t3);
        vader_unreachable("a no-return call returned");
    } else {
        t4 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
        l8 = ((int32_t) (int64_t) t4);
        vader_struct_vader_bytecode_BcRef_t* _a1_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a1_obj, 649u);
        _a1_obj->f_trait_name = 0u;
        t5 = (void*) _a1_obj;
        l3 = vader_ref_box(t5);
        vader_array_push((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types, l3);
        std_collections_MutableMap_std_core_IndexSet_set_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l10, l8);
        t2 = std_collections_MutableMap_std_core_Index_at__u64__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_hash, l2);
        if (t2.tag == 0u) {
            std_collections_MutableMap_std_core_IndexSet_set_at__u64__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_hash, l2, l8);
        }
        vader_bytecode_record_slot_type(l1, l8, l0);
        l7 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
        l3 = vader_bytecode_bc_type_of_with_ctx(l0, l1, l8);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
        vader_array_ref_store(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8, l3.payload.obj);
        VADER_WRITE_BARRIER(_a2_slotarr->buf);
        { int32_t __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_gc_top = gc_frame.prev;
}

uint8_t vader_bytecode_intrinsic_id_for(vader_string_t l0) {
    vader_string_t l1 = 0;
    bool t0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_is_int_equals(l0);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 9; }
    }
    t0 = vader_bytecode_is_display_to_string(l0);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 10; }
    }
    if (l0 == 2766u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 21; }
    }
    if (l0 == 2767u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 22; }
    }
    if (l0 == 2765u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 23; }
    }
    if (l0 == 2409u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 1; }
    }
    if (l0 == 2408u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 2; }
    }
    if (l0 == 2410u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 3; }
    }
    if (l0 == 2415u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 4; }
    }
    if (l0 == 2411u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 5; }
    }
    if (l0 == 2412u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 6; }
    }
    l1 = vader_bytecode_primitive_member_mangle(2447u, 551u, 1893u);
    if (l0 == l1) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 7; }
    }
    if (l0 == 2418u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 8; }
    }
    if (l0 == 2424u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 11; }
    }
    if (l0 == 2425u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 12; }
    }
    if (l0 == 2423u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 13; }
    }
    if (l0 == 2422u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 14; }
    }
    if (l0 == 2427u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 15; }
    }
    if (l0 == 2426u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 16; }
    }
    if (l0 == 2428u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 17; }
    }
    if (l0 == 2430u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 19; }
    }
    if (l0 == 2429u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 20; }
    }
    if (!(l0 == 2401u)) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 18; }
}

bool vader_bytecode_intrinsic_may_collect(uint8_t l0) {
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

vader_box_t vader_bytecode_intrinsic_op_for_mangled(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_primitive_arith_op(l0);
    if (!(l1.tag == 0u)) {
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_bytecode_primitive_cmp_op(l0);
    if (!(l1.tag == 0u)) {
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2417u) {
        vader_struct_vader_bytecode_StringCompare_t* _a0_obj = (vader_struct_vader_bytecode_StringCompare_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringCompare_t));
        vader_obj_header_init(_a0_obj, 782u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2416u) {
        vader_struct_vader_bytecode_BufferNew_t* _a1_obj = (vader_struct_vader_bytecode_BufferNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BufferNew_t));
        vader_obj_header_init(_a1_obj, 670u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2404u) {
        vader_struct_vader_bytecode_LoadU8_t* _a2_obj = (vader_struct_vader_bytecode_LoadU8_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LoadU8_t));
        vader_obj_header_init(_a2_obj, 757u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2406u) {
        vader_struct_vader_bytecode_StoreU8_t* _a3_obj = (vader_struct_vader_bytecode_StoreU8_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StoreU8_t));
        vader_obj_header_init(_a3_obj, 781u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2405u) {
        vader_struct_vader_bytecode_MemoryCopy_t* _a4_obj = (vader_struct_vader_bytecode_MemoryCopy_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_MemoryCopy_t));
        vader_obj_header_init(_a4_obj, 764u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2403u) {
        vader_struct_vader_bytecode_BufferToString_t* _a5_obj = (vader_struct_vader_bytecode_BufferToString_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BufferToString_t));
        vader_obj_header_init(_a5_obj, 671u);
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2407u) {
        vader_struct_vader_bytecode_BufferWriteString_t* _a6_obj = (vader_struct_vader_bytecode_BufferWriteString_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BufferWriteString_t));
        vader_obj_header_init(_a6_obj, 672u);
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2414u) {
        vader_struct_vader_bytecode_F64ToBits_t* _a7_obj = (vader_struct_vader_bytecode_F64ToBits_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64ToBits_t));
        vader_obj_header_init(_a7_obj, 704u);
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2420u) {
        vader_struct_vader_bytecode_BitsToF64_t* _a8_obj = (vader_struct_vader_bytecode_BitsToF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BitsToF64_t));
        vader_obj_header_init(_a8_obj, 660u);
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2413u) {
        vader_struct_vader_bytecode_F32ToBits_t* _a9_obj = (vader_struct_vader_bytecode_F32ToBits_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F32ToBits_t));
        vader_obj_header_init(_a9_obj, 691u);
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0 == 2419u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_struct_vader_bytecode_BitsToF32_t* _a10_obj = (vader_struct_vader_bytecode_BitsToF32_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BitsToF32_t));
    vader_obj_header_init(_a10_obj, 659u);
    t0 = (void*) _a10_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_bytecode_is_64_bit_int_val(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(3)) {
        l1 = true;
        return l1;
    }
    if (l0 == INT32_C(7)) {
        l1 = true;
    } else if (l0 == INT32_C(0)) {
        l1 = false;
    } else if (l0 == INT32_C(1)) {
        l1 = false;
    } else if (l0 == INT32_C(2)) {
        l1 = false;
    } else if (l0 == INT32_C(4)) {
        l1 = false;
    } else if (l0 == INT32_C(5)) {
        l1 = false;
    } else if (l0 == INT32_C(6)) {
        l1 = false;
    } else if (l0 == INT32_C(8)) {
        l1 = false;
    } else if (l0 == INT32_C(9)) {
        l1 = false;
    } else if (l0 == INT32_C(10)) {
        l1 = false;
    } else if (l0 == INT32_C(11)) {
        l1 = false;
    } else if (l0 == INT32_C(12)) {
        l1 = false;
    } else if (l0 == INT32_C(13)) {
        l1 = false;
    } else if (l0 == INT32_C(14)) {
        l1 = false;
    } else if (l0 == INT32_C(15)) {
        l1 = false;
    } else if (l0 == INT32_C(16)) {
        l1 = false;
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

static bool vader_bytecode_is_display_to_string(vader_string_t l0) {
    vader_box_t l1;
    bool l2;
    vader_string_t t0;
    l1 = vader_bytecode_strip_core_member(l0, 215u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_types_is_scalar_type_name(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        l2 = t0 != 2792u;
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        return t0 != 2227u;
    }
    return false;
}

bool vader_bytecode_is_float_val(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(8)) {
        l1 = true;
        return l1;
    }
    if (l0 == INT32_C(9)) {
        l1 = true;
    } else if (l0 == INT32_C(0)) {
        l1 = false;
    } else if (l0 == INT32_C(1)) {
        l1 = false;
    } else if (l0 == INT32_C(2)) {
        l1 = false;
    } else if (l0 == INT32_C(3)) {
        l1 = false;
    } else if (l0 == INT32_C(4)) {
        l1 = false;
    } else if (l0 == INT32_C(5)) {
        l1 = false;
    } else if (l0 == INT32_C(6)) {
        l1 = false;
    } else if (l0 == INT32_C(7)) {
        l1 = false;
    } else if (l0 == INT32_C(10)) {
        l1 = false;
    } else if (l0 == INT32_C(11)) {
        l1 = false;
    } else if (l0 == INT32_C(12)) {
        l1 = false;
    } else if (l0 == INT32_C(13)) {
        l1 = false;
    } else if (l0 == INT32_C(14)) {
        l1 = false;
    } else if (l0 == INT32_C(15)) {
        l1 = false;
    } else if (l0 == INT32_C(16)) {
        l1 = false;
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

static bool vader_bytecode_is_int_equals(vader_string_t l0) {
    vader_box_t l1;
    vader_string_t t0;
    bool t1;
    l1 = vader_bytecode_strip_core_member(l0, 217u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        t1 = vader_types_is_int_name(t0);
        return t1;
    }
    return false;
}

bool vader_bytecode_is_integer_val(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(0)) {
        l1 = true;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = true;
    } else if (l0 == INT32_C(2)) {
        l1 = true;
    } else if (l0 == INT32_C(3)) {
        l1 = true;
    } else if (l0 == INT32_C(4)) {
        l1 = true;
    } else if (l0 == INT32_C(5)) {
        l1 = true;
    } else if (l0 == INT32_C(6)) {
        l1 = true;
    } else if (l0 == INT32_C(7)) {
        l1 = true;
    } else if (l0 == INT32_C(8)) {
        l1 = false;
    } else if (l0 == INT32_C(9)) {
        l1 = false;
    } else if (l0 == INT32_C(10)) {
        l1 = false;
    } else if (l0 == INT32_C(11)) {
        l1 = false;
    } else if (l0 == INT32_C(12)) {
        l1 = false;
    } else if (l0 == INT32_C(13)) {
        l1 = false;
    } else if (l0 == INT32_C(14)) {
        l1 = false;
    } else if (l0 == INT32_C(15)) {
        l1 = false;
    } else if (l0 == INT32_C(16)) {
        l1 = false;
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

bool vader_bytecode_is_narrow_valtype(uint8_t l0) {
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

static bool vader_bytecode_is_ref_class(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(16)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(17);
    }
    if (l1) {
        return true;
    }
    return l0 == INT32_C(13);
}

bool vader_bytecode_is_ref_only_element(vader_box_t l0, void* l1) {
    bool l2;
    void* l3;
    int64_t l4, l5;
    int32_t l6;
    void* t0;
    vader_box_t t1;
    bool t2;
    if (l0.tag == 653u) {
        l2 = true;
        return l2;
    }
    if (l0.tag == 639u) {
        l2 = true;
    } else if (l0.tag == 642u) {
        l2 = true;
    } else if (l0.tag == 650u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_BcScalar_t*) t0)->f_val == INT32_C(13);
    } else if (l0.tag == 649u) {
        l2 = false;
    } else {
        if (!(l0.tag == 654u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_BcUnion_t*) t0)->f_variants;
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
            t2 = vader_bytecode_is_ref_only_element(t1, l1);
            if (!(t2)) {
                return false;
            }
            l5 = (l5 + INT64_C(1));
        }
        return true;
    }
    return l2;
}

bool vader_bytecode_is_string_val(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(12)) {
        l1 = true;
        return l1;
    }
    if (l0 == INT32_C(0)) {
        l1 = false;
    } else if (l0 == INT32_C(1)) {
        l1 = false;
    } else if (l0 == INT32_C(2)) {
        l1 = false;
    } else if (l0 == INT32_C(3)) {
        l1 = false;
    } else if (l0 == INT32_C(4)) {
        l1 = false;
    } else if (l0 == INT32_C(5)) {
        l1 = false;
    } else if (l0 == INT32_C(6)) {
        l1 = false;
    } else if (l0 == INT32_C(7)) {
        l1 = false;
    } else if (l0 == INT32_C(8)) {
        l1 = false;
    } else if (l0 == INT32_C(9)) {
        l1 = false;
    } else if (l0 == INT32_C(10)) {
        l1 = false;
    } else if (l0 == INT32_C(11)) {
        l1 = false;
    } else if (l0 == INT32_C(13)) {
        l1 = false;
    } else if (l0 == INT32_C(14)) {
        l1 = false;
    } else if (l0 == INT32_C(15)) {
        l1 = false;
    } else if (l0 == INT32_C(16)) {
        l1 = false;
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

static bool vader_bytecode_is_u32_class(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(4)) {
        l1 = true;
        return l1;
    }
    if (l0 == INT32_C(5)) {
        l1 = true;
    } else if (l0 == INT32_C(6)) {
        l1 = true;
    } else if (l0 == INT32_C(0)) {
        l1 = false;
    } else if (l0 == INT32_C(1)) {
        l1 = false;
    } else if (l0 == INT32_C(2)) {
        l1 = false;
    } else if (l0 == INT32_C(3)) {
        l1 = false;
    } else if (l0 == INT32_C(7)) {
        l1 = false;
    } else if (l0 == INT32_C(8)) {
        l1 = false;
    } else if (l0 == INT32_C(9)) {
        l1 = false;
    } else if (l0 == INT32_C(10)) {
        l1 = false;
    } else if (l0 == INT32_C(11)) {
        l1 = false;
    } else if (l0 == INT32_C(12)) {
        l1 = false;
    } else if (l0 == INT32_C(13)) {
        l1 = false;
    } else if (l0 == INT32_C(14)) {
        l1 = false;
    } else if (l0 == INT32_C(15)) {
        l1 = false;
    } else if (l0 == INT32_C(16)) {
        l1 = false;
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

bool vader_bytecode_is_u64_class(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(7)) {
        l1 = true;
        return l1;
    }
    if (l0 == INT32_C(0)) {
        l1 = false;
    } else if (l0 == INT32_C(1)) {
        l1 = false;
    } else if (l0 == INT32_C(2)) {
        l1 = false;
    } else if (l0 == INT32_C(3)) {
        l1 = false;
    } else if (l0 == INT32_C(4)) {
        l1 = false;
    } else if (l0 == INT32_C(5)) {
        l1 = false;
    } else if (l0 == INT32_C(6)) {
        l1 = false;
    } else if (l0 == INT32_C(8)) {
        l1 = false;
    } else if (l0 == INT32_C(9)) {
        l1 = false;
    } else if (l0 == INT32_C(10)) {
        l1 = false;
    } else if (l0 == INT32_C(11)) {
        l1 = false;
    } else if (l0 == INT32_C(12)) {
        l1 = false;
    } else if (l0 == INT32_C(13)) {
        l1 = false;
    } else if (l0 == INT32_C(14)) {
        l1 = false;
    } else if (l0 == INT32_C(15)) {
        l1 = false;
    } else if (l0 == INT32_C(16)) {
        l1 = false;
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

bool vader_bytecode_is_unsigned_display(vader_string_t l0) {
    vader_box_t l1;
    vader_string_t t0;
    bool t1;
    l1 = vader_bytecode_strip_core_member(l0, 215u);
    if (l1.tag == 0u) {
        return false;
    }
    t0 = l1.payload.s;
    t1 = vader_types_is_unsigned_int_name(t0);
    return t1;
}

bool vader_bytecode_is_unsigned_val(uint8_t l0) {
    bool t0;
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        return true;
    }
    t0 = vader_bytecode_is_u64_class(l0);
    return t0;
}

static vader_string_t vader_bytecode_key_join(void* l0, void* l1, vader_string_t l2) {
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
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 287u);
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
        l8 = vader_bytecode_bc_type_key(l0, l7);
        vader_array_push((vader_array_t*) l3, vader_box_string(287u, l8));
        l6 = (l6 + INT64_C(1));
    }
    t0 = std_string_join(l3, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_mark_jump_targets(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    int32_t l5;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(12u, 1u, 12u, 285u);
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

static uint64_t vader_bytecode_mix64(uint64_t l0, uint64_t l1) {
    uint64_t l2, l3;
    int64_t t0;
    t0 = ((l0 ^ l1) * INT64_C(1099511628211));
    l2 = (uint64_t) (int64_t) t0;
    l3 = (l2 >> INT64_C(33));
    t0 = ((l2 ^ l3) * INT64_C(-49064778989728563));
    l2 = (uint64_t) (int64_t) t0;
    l3 = (l2 >> INT64_C(29));
    t0 = ((l2 ^ l3) * INT64_C(-4265267296055464877));
    l2 = (uint64_t) (int64_t) t0;
    l3 = (l2 >> INT64_C(32));
    return (uint64_t) (int64_t) (l2 ^ l3);
}

static vader_box_t vader_bytecode_mod_op(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Mod_t* _a0_obj = (vader_struct_vader_bytecode_U64Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Mod_t));
        vader_obj_header_init(_a0_obj, 802u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Mod_t* _a1_obj = (vader_struct_vader_bytecode_U32Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Mod_t));
        vader_obj_header_init(_a1_obj, 796u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Mod_t* _a2_obj = (vader_struct_vader_bytecode_I32Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Mod_t));
        vader_obj_header_init(_a2_obj, 721u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Mod_t* _a3_obj = (vader_struct_vader_bytecode_I64Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Mod_t));
    vader_obj_header_init(_a3_obj, 741u);
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_neg_op(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_is_float_val(l0);
    if (t0) {
        vader_struct_vader_bytecode_F64Neg_t* _a0_obj = (vader_struct_vader_bytecode_F64Neg_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Neg_t));
        vader_obj_header_init(_a0_obj, 702u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Neg_t* _a1_obj = (vader_struct_vader_bytecode_I32Neg_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Neg_t));
        vader_obj_header_init(_a1_obj, 724u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Neg_t* _a2_obj = (vader_struct_vader_bytecode_I64Neg_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Neg_t));
    vader_obj_header_init(_a2_obj, 744u);
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_bytecode_nested_mirror(void* l0, void* l1) {
    int64_t l2, l3;
    int32_t l4;
    vader_box_t l5;
    int32_t t0;
    void* t1;
    vader_string_t t2;
    t0 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_type_index;
    if ((t0 < INT32_C(0))) {
        return vader_box_obj(0u, NULL);
    }
    t0 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_type_index;
    l2 = ((int64_t) (int32_t) t0);
    l3 = ((vader_array_t*) l1)->length;
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    l4 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_type_index;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    if (l5.tag == 653u) {
        t1 = l5.payload.obj;
        t2 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_c_name;
        if (t2 != 0u) {
            t1 = l5.payload.obj;
            return vader_ref_box(t1);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

void* vader_bytecode_new_emitter_ctx(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    uint64_t l5;
    void* t0 = NULL;
    void** gc_raw_roots[19] = {
        &l0, &l1, &l2, &l3, &l4, &l6, &l7, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &l16, &l17,
        &l18, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 19u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(228u, 0u, 13u, 1560u);
    l0 = (void*) _a0_arr;
    vader_struct_vader_bytecode_BcScalar_t* _a1_obj = (vader_struct_vader_bytecode_BcScalar_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcScalar_t));
    vader_obj_header_init(_a1_obj, 650u);
    _a1_obj->f_val = (uint8_t) 13;
    l1 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l0, vader_ref_box(l1));
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 0u, 287u);
    l1 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(15u, 0u, 7u, 290u);
    l3 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a5_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a5_obj, 457u);
    _a5_obj->f_ekeys = l1;
    _a5_obj->f_evals = l2;
    _a5_obj->f_index = l3;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a5_obj;
    std_collections_MutableMap_std_core_IndexSet_set_at__string__i32(l1, 2227u, INT32_C(0));
    vader_array_t* _a6_arr = vader_array_new(20u, 0u, 4u, 295u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(15u, 0u, 7u, 290u);
    l3 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(15u, 0u, 7u, 290u);
    l4 = (void*) _a8_arr;
    vader_struct_std_collections_MutableMap__u64__i32_t* _a9_obj = (vader_struct_std_collections_MutableMap__u64__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__u64__i32_t));
    vader_obj_header_init(_a9_obj, 507u);
    _a9_obj->f_ekeys = l2;
    _a9_obj->f_evals = l3;
    _a9_obj->f_index = l4;
    _a9_obj->f_mask = INT64_C(0);
    _a9_obj->f_size = INT64_C(0);
    _a9_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a9_obj;
    t0 = (void*) &vader_data_17;
    vader_array_t* _a10_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
    t0 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) INT64_C(0));
    l5 = vader_bytecode_type_intern_hash(vader_ref_box(t0));
    std_collections_MutableMap_std_core_IndexSet_set_at__u64__i32(l2, l5, INT32_C(0));
    t0 = (void*) &vader_data_17;
    vader_array_t* _a11_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
    t0 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a12_arr = vader_array_new(246u, 1u, 13u, 1818u);
    ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = t0;
    l3 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(52u, 0u, 13u, 644u);
    l4 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(14u, 0u, 0u, 287u);
    l6 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(14u, 0u, 0u, 287u);
    l7 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(15u, 0u, 7u, 290u);
    l8 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(15u, 0u, 7u, 290u);
    l9 = (void*) _a17_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a18_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a18_obj, 457u);
    _a18_obj->f_ekeys = l7;
    _a18_obj->f_evals = l8;
    _a18_obj->f_index = l9;
    _a18_obj->f_mask = INT64_C(0);
    _a18_obj->f_size = INT64_C(0);
    _a18_obj->f_tombs = INT64_C(0);
    l7 = (void*) _a18_obj;
    vader_array_t* _a19_arr = vader_array_new(51u, 0u, 13u, 643u);
    l8 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(15u, 0u, 7u, 290u);
    l9 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(15u, 0u, 7u, 290u);
    l10 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_new(15u, 0u, 7u, 290u);
    l11 = (void*) _a22_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a23_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a23_obj, 384u);
    _a23_obj->f_ekeys = l9;
    _a23_obj->f_evals = l10;
    _a23_obj->f_index = l11;
    _a23_obj->f_mask = INT64_C(0);
    _a23_obj->f_size = INT64_C(0);
    _a23_obj->f_tombs = INT64_C(0);
    l9 = (void*) _a23_obj;
    vader_array_t* _a24_arr = vader_array_new(14u, 0u, 0u, 287u);
    l10 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(15u, 0u, 7u, 290u);
    l11 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(15u, 0u, 7u, 290u);
    l12 = (void*) _a26_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a27_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a27_obj, 457u);
    _a27_obj->f_ekeys = l10;
    _a27_obj->f_evals = l11;
    _a27_obj->f_index = l12;
    _a27_obj->f_mask = INT64_C(0);
    _a27_obj->f_size = INT64_C(0);
    _a27_obj->f_tombs = INT64_C(0);
    l10 = (void*) _a27_obj;
    vader_array_t* _a28_arr = vader_array_new(53u, 0u, 13u, 645u);
    l11 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_new(15u, 0u, 7u, 290u);
    l12 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(15u, 0u, 7u, 290u);
    l13 = (void*) _a30_arr;
    vader_array_t* _a31_arr = vader_array_new(15u, 0u, 7u, 290u);
    l14 = (void*) _a31_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a32_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a32_obj, 384u);
    _a32_obj->f_ekeys = l12;
    _a32_obj->f_evals = l13;
    _a32_obj->f_index = l14;
    _a32_obj->f_mask = INT64_C(0);
    _a32_obj->f_size = INT64_C(0);
    _a32_obj->f_tombs = INT64_C(0);
    l12 = (void*) _a32_obj;
    vader_array_t* _a33_arr = vader_array_new(14u, 0u, 0u, 287u);
    l13 = (void*) _a33_arr;
    vader_array_t* _a34_arr = vader_array_new(15u, 0u, 7u, 290u);
    l14 = (void*) _a34_arr;
    vader_array_t* _a35_arr = vader_array_new(15u, 0u, 7u, 290u);
    l15 = (void*) _a35_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a36_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a36_obj, 457u);
    _a36_obj->f_ekeys = l13;
    _a36_obj->f_evals = l14;
    _a36_obj->f_index = l15;
    _a36_obj->f_mask = INT64_C(0);
    _a36_obj->f_size = INT64_C(0);
    _a36_obj->f_tombs = INT64_C(0);
    l13 = (void*) _a36_obj;
    vader_array_t* _a37_arr = vader_array_new(49u, 0u, 13u, 640u);
    l14 = (void*) _a37_arr;
    vader_array_t* _a38_arr = vader_array_new(15u, 0u, 7u, 290u);
    l15 = (void*) _a38_arr;
    vader_array_t* _a39_arr = vader_array_new(15u, 0u, 7u, 290u);
    l16 = (void*) _a39_arr;
    vader_array_t* _a40_arr = vader_array_new(21u, 0u, 0u, 298u);
    l17 = (void*) _a40_arr;
    vader_array_t* _a41_arr = vader_array_new(15u, 0u, 7u, 290u);
    l18 = (void*) _a41_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a42_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a42_obj, 382u);
    _a42_obj->f_ekeys = l16;
    _a42_obj->f_evals = l17;
    _a42_obj->f_index = l18;
    _a42_obj->f_mask = INT64_C(0);
    _a42_obj->f_size = INT64_C(0);
    _a42_obj->f_tombs = INT64_C(0);
    l16 = (void*) _a42_obj;
    vader_struct_vader_bytecode_EmitterCtx_t* _a43_obj = (vader_struct_vader_bytecode_EmitterCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_EmitterCtx_t));
    vader_obj_header_init(_a43_obj, 689u);
    _a43_obj->f_globals = l4;
    _a43_obj->f_types = l0;
    _a43_obj->f_type_key = l1;
    _a43_obj->f_type_hash = l2;
    _a43_obj->f_type_by_slot = l3;
    _a43_obj->f_strings = l6;
    _a43_obj->f_string_key = l7;
    _a43_obj->f_functions = l8;
    _a43_obj->f_function_index_by_symbol_id = l9;
    _a43_obj->f_function_index_by_mangle = l10;
    _a43_obj->f_imports = l11;
    _a43_obj->f_import_index_by_symbol_id = l12;
    _a43_obj->f_import_index_by_mangle = l13;
    _a43_obj->f_exports = l14;
    _a43_obj->f_pinned_types = l15;
    _a43_obj->f_types_frozen = false;
    _a43_obj->f_pinned_types_by_fn = l16;
    t0 = (void*) _a43_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_bytecode_param_c_type(void* l0, int64_t l1) {
    int64_t l2;
    vader_box_t t0;
    vader_string_t t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_param_c_types)->length;
    if ((l1 >= l2)) {
        return vader_box_obj(0u, NULL);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_param_c_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l1];
    t1 = t0.payload.s;
    if (!(t1 == 0u)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_param_c_types);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
        t1 = t0.payload.s;
        return vader_box_string(287u, t1);
    }
    return vader_box_obj(0u, NULL);
}

bool vader_bytecode_param_is_by_address(void* l0, int64_t l1) {
    int64_t l2;
    vader_box_t t0;
    bool t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_by_address)->length;
    if ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_by_address);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_box_bool(285u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1]);
        t1 = t0.payload.b;
        return t1;
    }
    return false;
}

bool vader_bytecode_param_is_c_out(void* l0, int64_t l1) {
    int64_t l2;
    vader_box_t t0;
    bool t1;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_c_out)->length;
    if ((l1 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_c_out);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_box_bool(285u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1]);
        t1 = t0.payload.b;
        return t1;
    }
    return false;
}

static vader_box_t vader_bytecode_parse_val_type(vader_string_t l0) {
    if (l0 == 1946u) {
        return vader_box_i32(292u, INT32_C(0));
    }
    if (l0 == 1901u) {
        return vader_box_i32(292u, INT32_C(1));
    }
    if (l0 == 1902u) {
        return vader_box_i32(292u, INT32_C(2));
    }
    if (l0 == 1924u) {
        return vader_box_i32(292u, INT32_C(3));
    }
    if (l0 == 2596u) {
        return vader_box_i32(292u, INT32_C(4));
    }
    if (l0 == 2575u) {
        return vader_box_i32(292u, INT32_C(5));
    }
    if (l0 == 2576u) {
        return vader_box_i32(292u, INT32_C(6));
    }
    if (l0 == 2586u) {
        return vader_box_i32(292u, INT32_C(7));
    }
    if (l0 == 1775u) {
        return vader_box_i32(292u, INT32_C(8));
    }
    if (l0 == 1777u) {
        return vader_box_i32(292u, INT32_C(9));
    }
    if (l0 == 1473u) {
        return vader_box_i32(292u, INT32_C(10));
    }
    if (l0 == 1581u) {
        return vader_box_i32(292u, INT32_C(11));
    }
    if (l0 == 2447u) {
        return vader_box_i32(292u, INT32_C(12));
    }
    if (l0 == 2227u) {
        return vader_box_i32(292u, INT32_C(13));
    }
    if (l0 == 2792u) {
        return vader_box_i32(292u, INT32_C(14));
    }
    if (l0 == 2282u) {
        return vader_box_i32(292u, INT32_C(15));
    }
    if (l0 == 2309u) {
        return vader_box_i32(292u, INT32_C(16));
    }
    if (!(l0 == 1398u)) {
        return vader_box_obj(0u, NULL);
    }
    return vader_box_i32(292u, INT32_C(17));
}

static vader_box_t vader_bytecode_primitive_arith_op(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t t0 = 0;
    bool t1;
    uint8_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_strip_core_member(l0, 212u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        t1 = vader_types_is_numeric_name(t0);
        if (t1) {
            t0 = l1.payload.s;
            t2 = vader_bytecode_val_type_of_primitive_name(t0);
            t3 = vader_bytecode_checked_arith_op(t2, (uint8_t) 0);
            { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l1 = vader_bytecode_strip_core_member(l0, 219u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        t1 = vader_types_is_numeric_name(t0);
        if (t1) {
            t0 = l1.payload.s;
            t2 = vader_bytecode_val_type_of_primitive_name(t0);
            t3 = vader_bytecode_checked_arith_op(t2, (uint8_t) 1);
            { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l1 = vader_bytecode_strip_core_member(l0, 218u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        t1 = vader_types_is_numeric_name(t0);
        if (t1) {
            t0 = l1.payload.s;
            t2 = vader_bytecode_val_type_of_primitive_name(t0);
            t3 = vader_bytecode_checked_arith_op(t2, (uint8_t) 2);
            { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l1 = vader_bytecode_strip_core_member(l0, 216u);
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l1.payload.s;
    t1 = vader_types_is_numeric_name(t0);
    if (t1) {
        t0 = l1.payload.s;
        t2 = vader_bytecode_val_type_of_primitive_name(t0);
        t3 = vader_bytecode_div_op(t2);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_bytecode_primitive_cmp_op(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t t0 = 0;
    bool t1;
    uint8_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_strip_core_member(l0, 217u);
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l1.payload.s;
    t1 = vader_types_is_scalar_type_name(t0);
    if (t1) {
        t0 = l1.payload.s;
        t2 = vader_bytecode_val_type_of_primitive_name(t0);
        t3 = vader_bytecode_cmp_eq(t2);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

vader_string_t vader_bytecode_primitive_member_mangle(vader_string_t l0, vader_string_t l1, vader_string_t l2) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = concat_6(2402u, l0, 211u, l1, 211u, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_bytecode_printed(void* l0, void* l1, vader_string_t l2, void* l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l5, l6, l9, l10;
    vader_string_t l11 = 0;
    int32_t t0;
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l4, &l7, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_string_builder_append(l0, l2);
    l4 = l3;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l8 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l9 = INT64_C(0);
        l9 = std_core_write_string_at(l8, l9, 10u);
        t0 = ((vader_struct_vader_bytecode_OperandRef_t*) l7)->f_index;
        l10 = ((int64_t) (int32_t) t0);
        l9 = std_core_write_int(l8, l9, l10);
        l11 = std_core_finish_buffer(l8, l9);
        std_string_builder_append(l0, l11);
        vader_array_push((vader_array_t*) l1, vader_ref_box(l7));
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void* vader_bytecode_propagate_const_single_use(void* l0) {
    int64_t l1, l2, l4, l10, l12, l17;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    vader_box_t l11 = vader_box_null(), l25 = vader_box_null(), l27 = vader_box_null(), l28 = vader_box_null(), l29 = vader_box_null();
    int32_t l13, l14, l15, l16, l18, l19;
    bool l24;
    uint8_t l26;
    vader_string_t l30 = 0;
    void* t0 = NULL;
    int32_t t1;
    bool t2;
    vader_box_t t3 = vader_box_null();
    int64_t t4;
    vader_box_t* gc_roots[6] = { &l11, &l25, &l27, &l28, &l29, &t3 };
    void** gc_raw_roots[12] = { &l0, &l3, &l5, &l6, &l7, &l8, &l9, &l20, &l21, &l22, &l23, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l30 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    l2 = vader_chk_add(i64, l1, l2);
    if ((l2 <= l1)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l3 = (void*) _a0_arr;
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 290u);
    l5 = (void*) _a2_arr;
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l4);
    l5 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(15u, 0u, 7u, 290u);
    l6 = (void*) _a4_arr;
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l4);
    l6 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(15u, 0u, 7u, 290u);
    l7 = (void*) _a6_arr;
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) l7, (int64_t) l4);
    l7 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(15u, 0u, 7u, 290u);
    l8 = (void*) _a8_arr;
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) l8, (int64_t) l4);
    l8 = (void*) _a9_arr;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_push_i32((vader_array_t*) l3, INT32_C(0));
        vader_array_push_i32((vader_array_t*) l5, INT32_C(0));
        vader_array_push_i32((vader_array_t*) l6, INT32_C(0));
        vader_array_push_i32((vader_array_t*) l7, INT32_C(-1));
        vader_array_push_i32((vader_array_t*) l8, INT32_C(-1));
        l4 = (l4 + INT64_C(1));
    }
    l9 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l4 = ((vader_array_t*) l9)->length;
    l10 = INT64_C(0);
    while ((l10 < l4)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l11 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l10);
        if (l11.tag == 760u) {
            t0 = l11.payload.obj;
            t1 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
            l12 = ((int64_t) (int32_t) t1);
            vader_array_t* _a11_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l12)
            t1 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l12];
            l13 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l12)
            ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l12] = (int32_t) l13;
            l14 = ((int32_t) (int64_t) l10);
            vader_array_t* _a12_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l12)
            ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l12] = (int32_t) l14;
        }
        if (l11.tag == 761u) {
            t0 = l11.payload.obj;
            l15 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
            vader_array_t* _a13_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l15)
            t1 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l15];
            l16 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l15)
            ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l15] = (int32_t) l16;
        }
        if (l11.tag == 759u) {
            t0 = l11.payload.obj;
            t1 = ((vader_struct_vader_bytecode_LocalGet_t*) t0)->f_slot;
            l17 = ((int64_t) (int32_t) t1);
            vader_array_t* _a14_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l17)
            t1 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l17];
            l18 = vader_chk_add(i32, t1, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l17)
            ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l17] = (int32_t) l18;
            l19 = ((int32_t) (int64_t) l10);
            vader_array_t* _a15_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l17)
            ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l17] = (int32_t) l19;
        }
        l10 = (l10 + INT64_C(1));
    }
    vader_array_t* _a16_arr = vader_array_new(15u, 0u, 7u, 290u);
    l20 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(12u, 0u, 12u, 285u);
    l21 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(15u, 0u, 7u, 290u);
    l22 = (void*) _a18_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a19_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a19_obj, 383u);
    _a19_obj->f_ekeys = l20;
    _a19_obj->f_evals = l21;
    _a19_obj->f_index = l22;
    _a19_obj->f_mask = INT64_C(0);
    _a19_obj->f_size = INT64_C(0);
    _a19_obj->f_tombs = INT64_C(0);
    l20 = (void*) _a19_obj;
    vader_array_t* _a20_arr = vader_array_new(15u, 0u, 7u, 290u);
    l21 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(21u, 0u, 0u, 298u);
    l22 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_new(15u, 0u, 7u, 290u);
    l23 = (void*) _a22_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a23_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a23_obj, 381u);
    _a23_obj->f_ekeys = l21;
    _a23_obj->f_evals = l22;
    _a23_obj->f_index = l23;
    _a23_obj->f_mask = INT64_C(0);
    _a23_obj->f_size = INT64_C(0);
    _a23_obj->f_tombs = INT64_C(0);
    l21 = (void*) _a23_obj;
    l10 = l1;
    while ((l10 < l2)) {
        l24 = true;
        vader_array_t* _a24_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l10)
        t1 = ((int32_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l10];
        if (t1 != INT32_C(0)) {
            l24 = false;
        }
        vader_array_t* _a25_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l10)
        t1 = ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l10];
        if (t1 != INT32_C(1)) {
            l24 = false;
        }
        vader_array_t* _a26_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l10)
        t1 = ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l10];
        if (t1 != INT32_C(1)) {
            l24 = false;
        }
        l13 = INT32_C(-1);
        l14 = INT32_C(-1);
        if (l24) {
            vader_array_t* _a27_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l10)
            l13 = ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l10];
            vader_array_t* _a28_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l10)
            l14 = ((int32_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l10];
            if ((l13 <= INT32_C(0))) {
                l24 = false;
            }
            if ((l14 <= l13)) {
                l24 = false;
            }
        }
        if (l24) {
            l15 = vader_chk_sub(i32, l13, INT32_C(1));
            vader_array_t* _a29_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l15)
            l11 = vader_array_ref_load_box(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l15);
            l25 = vader_bytecode_const_op_of(l11);
            if (l25.tag == 0u) {
                l24 = false;
            } else {
                l22 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
                l12 = vader_chk_sub(i64, l10, l1);
                vader_array_t* _a30_slotarr = ((vader_array_t*) l22);
                VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l12)
                t0 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l12);
                l26 = ((vader_struct_vader_bytecode_BcLocal_t*) t0)->f_val;
                t2 = vader_bytecode_const_fills_slot(l25, l26);
                if (t2) {
                    l16 = vader_chk_sub(i32, l13, INT32_C(1));
                    std_collections_MutableMap_std_core_IndexSet_set_at__i32__bool(l20, l16, true);
                    std_collections_MutableMap_std_core_IndexSet_set_at__i32__bool(l20, l13, true);
                    std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l21, l14, l11);
                } else {
                    l24 = false;
                }
            }
        }
        l10 = (l10 + INT64_C(1));
    }
    t2 = std_collections_is_empty__i32__bool(l20);
    if (t2) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a31_arr = vader_array_new(226u, 0u, 13u, 1538u);
    l3 = (void*) _a31_arr;
    vader_array_t* _a32_arr = vader_array_new(230u, 0u, 13u, 1594u);
    l5 = (void*) _a32_arr;
    vader_array_t* _a33_arr = vader_array_new(15u, 0u, 7u, 290u);
    l6 = (void*) _a33_arr;
    if ((INT64_C(0) < l4)) {
        l1 = l4;
    } else {
        l1 = INT64_C(0);
    }
    vader_array_t* _a34_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l1);
    l6 = (void*) _a34_arr;
    l1 = INT64_C(0);
    vader_array_t* _pc402_hdr = (vader_array_t*) l6;
    size_t _pc402_len = _pc402_hdr->length;
    size_t _pc402_cap = (_pc402_hdr->offset == 0 && !vader_array_is_borrowed(_pc402_hdr) && _pc402_hdr->length >= _pc402_hdr->buf->length) ? _pc402_hdr->capacity : (size_t) 0;
    void* _pc402_slots = _pc402_hdr->buf->slots;
    for (;;) {
        if ((l1 < l4)) {
            if (VADER_LIKELY(_pc402_len < _pc402_cap)) {
                ((int32_t*) _pc402_slots)[_pc402_len] = (int32_t) (INT32_C(-1));
                _pc402_len += 1;
            } else {
                _pc402_hdr->length = _pc402_len;
                if (_pc402_hdr->buf->length < _pc402_len) {
                    _pc402_hdr->buf->length = _pc402_len;
                }
                vader_array_push_i32((vader_array_t*) l6, INT32_C(-1));
                _pc402_hdr = (vader_array_t*) l6;
                _pc402_len = _pc402_hdr->length;
                _pc402_cap = (_pc402_hdr->offset == 0 && !vader_array_is_borrowed(_pc402_hdr) && _pc402_hdr->length >= _pc402_hdr->buf->length) ? _pc402_hdr->capacity : (size_t) 0;
                _pc402_slots = _pc402_hdr->buf->slots;
            }
            l1 = (l1 + INT64_C(1));
            continue;
        }
        _pc402_hdr->length = _pc402_len;
        if (_pc402_hdr->buf->length < _pc402_len) {
            _pc402_hdr->buf->length = _pc402_len;
        }
        break;
    }
    l1 = INT64_C(0);
    while ((l1 < l4)) {
        l13 = ((int32_t) (int64_t) l1);
        t3 = std_collections_MutableMap_std_core_Index_at__i32__bool(l20, l13);
        if (t3.tag == 285u) {
            l1 = vader_chk_add(i64, l1, INT64_C(1));
            continue;
        }
        l14 = ((int32_t) (int64_t) l1);
        l11 = std_collections_MutableMap_std_core_Index_at__i32__Any(l21, l14);
        if (l11.tag == 0u) {
            t4 = ((vader_array_t*) l3)->length;
            l15 = ((int32_t) (int64_t) t4);
            vader_array_t* _a35_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l1)
            ((int32_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l1] = (int32_t) l15;
            vader_array_t* _a36_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
            l25 = vader_array_ref_load_box(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l1);
            vader_array_push((vader_array_t*) l3, l25);
            vader_array_t* _a37_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l1)
            l27 = vader_array_ref_load_box(_a37_slotarr->buf, _a37_slotarr->offset + (size_t) l1);
            vader_array_push((vader_array_t*) l5, l27);
        } else {
            t4 = ((vader_array_t*) l3)->length;
            l16 = ((int32_t) (int64_t) t4);
            vader_array_t* _a38_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l1)
            ((int32_t*) _a38_slotarr->buf->slots)[_a38_slotarr->offset + (size_t) l1] = (int32_t) l16;
            l28 = l11;
            vader_array_push((vader_array_t*) l3, l28);
            vader_array_t* _a39_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug);
            VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l1)
            l29 = vader_array_ref_load_box(_a39_slotarr->buf, _a39_slotarr->offset + (size_t) l1);
            vader_array_push((vader_array_t*) l5, l29);
        }
        l1 = vader_chk_add(i64, l1, INT64_C(1));
    }
    l7 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l1 = ((vader_array_t*) l3)->length;
    l6 = vader_bytecode_remap_jump_table(l7, l6, l1);
    l7 = l0;
    l30 = ((vader_struct_vader_bytecode_BcFunction_t*) l7)->f_name;
    l24 = ((vader_struct_vader_bytecode_BcFunction_t*) l7)->f_is_main;
    l8 = ((vader_struct_vader_bytecode_BcFunction_t*) l7)->f_signature;
    l9 = ((vader_struct_vader_bytecode_BcFunction_t*) l7)->f_locals;
    l7 = ((vader_struct_vader_bytecode_BcFunction_t*) l7)->f_source_pc;
    vader_struct_vader_bytecode_BcFunction_t* _a40_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a40_obj, 643u);
    _a40_obj->f_name = l30;
    _a40_obj->f_is_main = l24;
    _a40_obj->f_signature = l8;
    _a40_obj->f_locals = l9;
    _a40_obj->f_body = l3;
    _a40_obj->f_debug = l5;
    _a40_obj->f_jump_table = l6;
    _a40_obj->f_source_pc = l7;
    t0 = (void*) _a40_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_prune_unused_data(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    int64_t l5, l6, l7, l8;
    vader_box_t l9 = vader_box_null();
    int32_t l10, l11, l15;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l12, &l13, &l14, &l16, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 285u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 290u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 383u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 519u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        l4 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_body;
        l7 = ((vader_array_t*) l4)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            l9 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l8);
            if (l9.tag == 682u) {
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_pool_index;
                std_collections_add__i32(l2, l10);
            }
            l8 = (l8 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    l5 = std_collections_len__i32(l2);
    l6 = ((vader_array_t*) l1)->length;
    if (l5 == l6) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a7_arr = vader_array_new(15u, 0u, 7u, 290u);
    l3 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(227u, 0u, 13u, 1559u);
    l4 = (void*) _a8_arr;
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) l1)->length;
    while ((l5 < l6)) {
        l10 = ((int32_t) (int64_t) l5);
        t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l2, l10);
        if (t1) {
            t2 = ((vader_array_t*) l4)->length;
            l11 = ((int32_t) (int64_t) t2);
            vader_array_push_i32((vader_array_t*) l3, l11);
            vader_array_t* _a9_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            l9 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l5);
            vader_array_push((vader_array_t*) l4, l9);
        } else {
            vader_array_push_i32((vader_array_t*) l3, INT32_C(-1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l5 = ((vader_array_t*) l2)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l12 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l6);
        l7 = INT64_C(0);
        l8 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l12)->f_body)->length;
        while ((l7 < l8)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l12)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l7)
            l9 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l7);
            if (l9.tag == 682u) {
                l13 = ((vader_struct_vader_bytecode_BcFunction_t*) l12)->f_body;
                l14 = l9.payload.obj;
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_pool_index;
                vader_array_t* _a12_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l10)
                l11 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l10];
                l15 = ((vader_struct_vader_bytecode_DataConst_t*) l14)->f_type_id;
                vader_struct_vader_bytecode_DataConst_t* _a13_obj = (vader_struct_vader_bytecode_DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DataConst_t));
                vader_obj_header_init(_a13_obj, 682u);
                _a13_obj->f_pool_index = l11;
                _a13_obj->f_type_id = l15;
                l16 = (void*) _a13_obj;
                vader_array_t* _a14_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l7)
                vader_array_ref_store(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l7, l16);
                VADER_WRITE_BARRIER(_a14_slotarr->buf);
            }
            l7 = (l7 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_bytecode_prune_unused_functions(void* l0, void* l1, void* l2) {
    int64_t l3, l7, l11, l14, l15, l17, l18;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l34 = NULL;
    int32_t l8, l10, l20, l23, l24, l31, l32, l33;
    vader_string_t l9 = 0;
    vader_string_t l35 = 0;
    bool l16, l21, l22;
    vader_box_t l19 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    int32_t t4;
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[2] = { &l19, &t2 };
    void** gc_raw_roots[16] = {
        &l0, &l1, &l2, &l4, &l5, &l6, &l12, &l13, &l25, &l26, &l27, &l28, &l29, &l30, &l34, &t1,
    };
    vader_string_t* gc_atom_roots[3] = { &l9, &l35, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 16u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions)->length;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 285u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 290u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 383u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l5;
    _a3_obj->f_index = l6;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a3_obj;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        l5 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l7);
        t0 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_is_main;
        if (t0) {
            l8 = ((int32_t) (int64_t) l7);
            std_collections_MutableMap_std_core_IndexSet_set_at__i32__bool(l4, l8, true);
        }
        l9 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_name;
        t0 = std_core____Contains_contains__string(l2, l9);
        if (t0) {
            l10 = ((int32_t) (int64_t) l7);
            std_collections_MutableMap_std_core_IndexSet_set_at__i32__bool(l4, l10, true);
        }
        l7 = (l7 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_exports;
    l7 = ((vader_array_t*) l5)->length;
    l11 = INT64_C(0);
    while ((l11 < l7)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t1 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l11);
        l8 = ((vader_struct_vader_bytecode_BcExport_t*) t1)->f_fn_index;
        std_collections_MutableMap_std_core_IndexSet_set_at__i32__bool(l4, l8, true);
        l11 = (l11 + INT64_C(1));
    }
    l5 = l1;
    l7 = ((vader_array_t*) l5)->length;
    l11 = INT64_C(0);
    while ((l11 < l7)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l8 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l11];
        if ((l8 >= INT32_C(0))) {
            l10 = ((int32_t) (int64_t) l3);
            if ((l8 < l10)) {
                std_collections_MutableMap_std_core_IndexSet_set_at__i32__bool(l4, l8, true);
            }
        }
        l11 = (l11 + INT64_C(1));
    }
    vader_array_t* _a7_arr = vader_array_new(15u, 0u, 7u, 290u);
    l5 = (void*) _a7_arr;
    l11 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l4)->f_size;
    if ((INT64_C(0) < l11)) {
        l7 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l4)->f_size;
    } else {
        l7 = INT64_C(0);
    }
    vader_array_t* _a8_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l7);
    l5 = (void*) _a8_arr;
    l6 = l4;
    l12 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l6)->f_ekeys;
    l13 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l6)->f_evals;
    l7 = INT64_C(0);
    l11 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l6)->f_size;
    vader_array_t* _pc158_hdr = (vader_array_t*) l5;
    size_t _pc158_len = _pc158_hdr->length;
    size_t _pc158_cap = (_pc158_hdr->offset == 0 && !vader_array_is_borrowed(_pc158_hdr) && _pc158_hdr->length >= _pc158_hdr->buf->length) ? _pc158_hdr->capacity : (size_t) 0;
    void* _pc158_slots = _pc158_hdr->buf->slots;
    for (;;) {
        if ((l7 < l11)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l7)
            l8 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l7];
            vader_array_t* _a10_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l7)
            t2 = vader_box_bool(285u, ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l7]);
            t0 = t2.payload.b;
            l10 = l8;
            if (VADER_LIKELY(_pc158_len < _pc158_cap)) {
                ((int32_t*) _pc158_slots)[_pc158_len] = (int32_t) (l10);
                _pc158_len += 1;
            } else {
                _pc158_hdr->length = _pc158_len;
                if (_pc158_hdr->buf->length < _pc158_len) {
                    _pc158_hdr->buf->length = _pc158_len;
                }
                vader_array_push_i32((vader_array_t*) l5, l10);
                _pc158_hdr = (vader_array_t*) l5;
                _pc158_len = _pc158_hdr->length;
                _pc158_cap = (_pc158_hdr->offset == 0 && !vader_array_is_borrowed(_pc158_hdr) && _pc158_hdr->length >= _pc158_hdr->buf->length) ? _pc158_hdr->capacity : (size_t) 0;
                _pc158_slots = _pc158_hdr->buf->slots;
            }
            l7 = (l7 + INT64_C(1));
            continue;
        }
        _pc158_hdr->length = _pc158_len;
        if (_pc158_hdr->buf->length < _pc158_len) {
            _pc158_hdr->buf->length = _pc158_len;
        }
        break;
    }
    for (;;) {
        t3 = ((vader_array_t*) l5)->length;
        if ((t3 > INT64_C(0))) {
            t3 = ((vader_array_t*) l5)->length;
            l7 = vader_chk_sub(i64, t3, INT64_C(1));
            vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            l8 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l7];
            vader_array_t* _a12_arr = vader_array_new(15u, 0u, 7u, 290u);
            l6 = (void*) _a12_arr;
            l11 = INT64_C(0);
            t3 = ((vader_array_t*) l5)->length;
            l14 = vader_chk_sub(i64, t3, INT64_C(1));
            vader_array_t* _pc208_hdr = (vader_array_t*) l6;
            size_t _pc208_len = _pc208_hdr->length;
            size_t _pc208_cap = (_pc208_hdr->offset == 0 && !vader_array_is_borrowed(_pc208_hdr) && _pc208_hdr->length >= _pc208_hdr->buf->length) ? _pc208_hdr->capacity : (size_t) 0;
            void* _pc208_slots = _pc208_hdr->buf->slots;
            for (;;) {
                if ((l11 < l14)) {
                    vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                    l10 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l11];
                    if (VADER_LIKELY(_pc208_len < _pc208_cap)) {
                        ((int32_t*) _pc208_slots)[_pc208_len] = (int32_t) (l10);
                        _pc208_len += 1;
                    } else {
                        _pc208_hdr->length = _pc208_len;
                        if (_pc208_hdr->buf->length < _pc208_len) {
                            _pc208_hdr->buf->length = _pc208_len;
                        }
                        vader_array_push_i32((vader_array_t*) l6, l10);
                        _pc208_hdr = (vader_array_t*) l6;
                        _pc208_len = _pc208_hdr->length;
                        _pc208_cap = (_pc208_hdr->offset == 0 && !vader_array_is_borrowed(_pc208_hdr) && _pc208_hdr->length >= _pc208_hdr->buf->length) ? _pc208_hdr->capacity : (size_t) 0;
                        _pc208_slots = _pc208_hdr->buf->slots;
                    }
                    l11 = (l11 + INT64_C(1));
                    continue;
                }
                _pc208_hdr->length = _pc208_len;
                if (_pc208_hdr->buf->length < _pc208_len) {
                    _pc208_hdr->buf->length = _pc208_len;
                }
                break;
            }
            l5 = l6;
            l15 = ((int64_t) (int32_t) l8);
            if ((INT64_C(0) <= l15)) {
                l16 = (l15 < l3);
            } else {
                l16 = false;
            }
            if (!(l16)) {
                continue;
            }
            vader_array_t* _a14_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l8)
            t1 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l8);
            l12 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_body;
            l17 = ((vader_array_t*) l12)->length;
            l18 = INT64_C(0);
            while ((l18 < l17)) {
                vader_array_t* _a15_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                l19 = vader_array_ref_load_box(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l18);
                l20 = INT32_C(-1);
                if (l19.tag == 675u) {
                    t1 = l19.payload.obj;
                    l20 = ((vader_struct_vader_bytecode_Call_t*) t1)->f_function_index;
                }
                if (l19.tag == 706u) {
                    t1 = l19.payload.obj;
                    l20 = ((vader_struct_vader_bytecode_FnRef_t*) t1)->f_function_index;
                }
                if (l19.tag == 705u) {
                    t1 = l19.payload.obj;
                    l20 = ((vader_struct_vader_bytecode_FnAddr_t*) t1)->f_function_index;
                }
                if (l19.tag == 763u) {
                    t1 = l19.payload.obj;
                    l20 = ((vader_struct_vader_bytecode_MakeClosure_t*) t1)->f_function_index;
                }
                if ((l20 < INT32_C(0))) {
                    l18 = (l18 + INT64_C(1));
                    continue;
                }
                t2 = std_collections_MutableMap_std_core_Index_at__i32__bool(l4, l20);
                if (t2.tag == 285u) {
                    l18 = (l18 + INT64_C(1));
                    continue;
                }
                std_collections_MutableMap_std_core_IndexSet_set_at__i32__bool(l4, l20, true);
                vader_array_push_i32((vader_array_t*) l5, l20);
                l18 = (l18 + INT64_C(1));
            }
            continue;
        }
        break;
    }
    l16 = std_collections_is_empty__i32__bool(l4);
    vader_array_t* _a16_arr = vader_array_new(14u, 0u, 0u, 287u);
    l5 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(15u, 0u, 7u, 290u);
    l6 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(15u, 0u, 7u, 290u);
    l12 = (void*) _a18_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a19_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a19_obj, 457u);
    _a19_obj->f_ekeys = l5;
    _a19_obj->f_evals = l6;
    _a19_obj->f_index = l12;
    _a19_obj->f_mask = INT64_C(0);
    _a19_obj->f_size = INT64_C(0);
    _a19_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a19_obj;
    l21 = false;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        if (l16) {
            l22 = true;
        } else {
            l8 = ((int32_t) (int64_t) l7);
            t2 = std_collections_MutableMap_std_core_Index_at__i32__bool(l4, l8);
            l22 = t2.tag == 285u;
        }
        if (l22) {
            vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l7)
            t1 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l7);
            l9 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_name;
            if (l9 != 0u) {
                l19 = std_collections_MutableMap_std_core_Index_at__string__i32(l5, l9);
                if (l19.tag == 290u) {
                    l21 = true;
                    vader_array_t* _a21_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
                    VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l7)
                    t1 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l7);
                    t3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_body)->length;
                    if ((t3 > INT64_C(0))) {
                        l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
                        l10 = ((int32_t) l19.payload.i);
                        vader_array_t* _a22_slotarr = ((vader_array_t*) l6);
                        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l10)
                        t1 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l10);
                        t3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_body)->length;
                        if (t3 == INT64_C(0)) {
                            l20 = ((int32_t) (int64_t) l7);
                            std_collections_MutableMap_std_core_IndexSet_set_at__string__i32(l5, l9, l20);
                        }
                    }
                } else {
                    l23 = ((int32_t) (int64_t) l7);
                    std_collections_MutableMap_std_core_IndexSet_set_at__string__i32(l5, l9, l23);
                }
            }
        }
        l7 = (l7 + INT64_C(1));
    }
    if (!(l21)) {
        if (l16) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        t3 = std_collections_len__i32__bool(l4);
        if (t3 == l3) {
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    vader_array_t* _a23_arr = vader_array_new(15u, 0u, 7u, 290u);
    l6 = (void*) _a23_arr;
    if ((INT64_C(0) < l3)) {
        l7 = l3;
    } else {
        l7 = INT64_C(0);
    }
    vader_array_t* _a24_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l7);
    l6 = (void*) _a24_arr;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        vader_array_t* _a25_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l7)
        t1 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l7);
        l9 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_name;
        l8 = ((int32_t) (int64_t) l7);
        if (l9 != 0u) {
            l19 = std_collections_MutableMap_std_core_Index_at__string__i32(l5, l9);
            if (l19.tag == 290u) {
                l8 = ((int32_t) l19.payload.i);
            }
        }
        vader_array_push_i32((vader_array_t*) l6, l8);
        l7 = (l7 + INT64_C(1));
    }
    vader_array_t* _a26_arr = vader_array_new(15u, 0u, 7u, 290u);
    l5 = (void*) _a26_arr;
    vader_array_t* _a27_arr = vader_array_new(15u, 0u, 7u, 290u);
    l12 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(15u, 0u, 7u, 290u);
    l13 = (void*) _a28_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a29_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a29_obj, 384u);
    _a29_obj->f_ekeys = l5;
    _a29_obj->f_evals = l12;
    _a29_obj->f_index = l13;
    _a29_obj->f_mask = INT64_C(0);
    _a29_obj->f_size = INT64_C(0);
    _a29_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a29_obj;
    vader_array_t* _a30_arr = vader_array_new(51u, 0u, 13u, 643u);
    l12 = (void*) _a30_arr;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        {
            if (!(l16)) {
                l8 = ((int32_t) (int64_t) l7);
                t2 = std_collections_MutableMap_std_core_Index_at__i32__bool(l4, l8);
                if (!(t2.tag == 285u)) {
                    goto end_545;
                }
            }
            vader_array_t* _a31_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l7)
            l10 = ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l7];
            l20 = ((int32_t) (int64_t) l7);
            if (l10 == l20) {
                l23 = ((int32_t) (int64_t) l7);
                t3 = ((vader_array_t*) l12)->length;
                l24 = ((int32_t) (int64_t) t3);
                std_collections_MutableMap_std_core_IndexSet_set_at__i32__i32(l5, l23, l24);
                vader_array_t* _a32_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
                VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l7)
                l13 = vader_array_ref_load_obj(_a32_slotarr->buf, _a32_slotarr->offset + (size_t) l7);
                vader_array_push((vader_array_t*) l12, vader_ref_box(l13));
            }
        } end_545: ;
        l7 = (l7 + INT64_C(1));
    }
    vader_array_t* _a33_arr = vader_array_new(15u, 0u, 7u, 290u);
    l13 = (void*) _a33_arr;
    if ((INT64_C(0) < l3)) {
        l7 = l3;
    } else {
        l7 = INT64_C(0);
    }
    vader_array_t* _a34_arr = vader_array_repeat((vader_array_t*) l13, (int64_t) l7);
    l13 = (void*) _a34_arr;
    l7 = INT64_C(0);
    vader_array_t* _pc617_hdr = (vader_array_t*) l13;
    size_t _pc617_len = _pc617_hdr->length;
    size_t _pc617_cap = (_pc617_hdr->offset == 0 && !vader_array_is_borrowed(_pc617_hdr) && _pc617_hdr->length >= _pc617_hdr->buf->length) ? _pc617_hdr->capacity : (size_t) 0;
    void* _pc617_slots = _pc617_hdr->buf->slots;
    for (;;) {
        if ((l7 < l3)) {
            l8 = INT32_C(-1);
            if (l16) {
                l21 = true;
            } else {
                l10 = ((int32_t) (int64_t) l7);
                t2 = std_collections_MutableMap_std_core_Index_at__i32__bool(l4, l10);
                l21 = t2.tag == 285u;
            }
            if (l21) {
                vader_array_t* _a35_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l7)
                l20 = ((int32_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l7];
                l19 = std_collections_MutableMap_std_core_Index_at__i32__i32(l5, l20);
                if (l19.tag == 290u) {
                    l8 = ((int32_t) l19.payload.i);
                }
            }
            if (VADER_LIKELY(_pc617_len < _pc617_cap)) {
                ((int32_t*) _pc617_slots)[_pc617_len] = (int32_t) (l8);
                _pc617_len += 1;
            } else {
                _pc617_hdr->length = _pc617_len;
                if (_pc617_hdr->buf->length < _pc617_len) {
                    _pc617_hdr->buf->length = _pc617_len;
                }
                vader_array_push_i32((vader_array_t*) l13, l8);
                _pc617_hdr = (vader_array_t*) l13;
                _pc617_len = _pc617_hdr->length;
                _pc617_cap = (_pc617_hdr->offset == 0 && !vader_array_is_borrowed(_pc617_hdr) && _pc617_hdr->length >= _pc617_hdr->buf->length) ? _pc617_hdr->capacity : (size_t) 0;
                _pc617_slots = _pc617_hdr->buf->slots;
            }
            l7 = (l7 + INT64_C(1));
            continue;
        }
        _pc617_hdr->length = _pc617_len;
        if (_pc617_hdr->buf->length < _pc617_len) {
            _pc617_hdr->buf->length = _pc617_len;
        }
        break;
    }
    l4 = l12;
    l3 = ((vader_array_t*) l4)->length;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        vader_array_t* _a36_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
        l5 = vader_array_ref_load_obj(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l7);
        l11 = INT64_C(0);
        l14 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body)->length;
        while ((l11 < l14)) {
            vader_array_t* _a37_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l11)
            l19 = vader_array_ref_load_box(_a37_slotarr->buf, _a37_slotarr->offset + (size_t) l11);
            if (l19.tag == 675u) {
                l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body;
                t1 = l19.payload.obj;
                l8 = ((vader_struct_vader_bytecode_Call_t*) t1)->f_function_index;
                vader_array_t* _a38_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l8)
                t4 = ((int32_t*) _a38_slotarr->buf->slots)[_a38_slotarr->offset + (size_t) l8];
                vader_struct_vader_bytecode_Call_t* _a39_obj = (vader_struct_vader_bytecode_Call_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Call_t));
                vader_obj_header_init(_a39_obj, 675u);
                _a39_obj->f_function_index = t4;
                l25 = (void*) _a39_obj;
                vader_array_t* _a40_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l11)
                vader_array_ref_store(_a40_slotarr->buf, _a40_slotarr->offset + (size_t) l11, l25);
                VADER_WRITE_BARRIER(_a40_slotarr->buf);
            }
            if (l19.tag == 706u) {
                l26 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body;
                t1 = l19.payload.obj;
                l10 = ((vader_struct_vader_bytecode_FnRef_t*) t1)->f_function_index;
                vader_array_t* _a41_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l10)
                l20 = ((int32_t*) _a41_slotarr->buf->slots)[_a41_slotarr->offset + (size_t) l10];
                t1 = l19.payload.obj;
                l23 = ((vader_struct_vader_bytecode_FnRef_t*) t1)->f_type_id;
                vader_struct_vader_bytecode_FnRef_t* _a42_obj = (vader_struct_vader_bytecode_FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnRef_t));
                vader_obj_header_init(_a42_obj, 706u);
                _a42_obj->f_function_index = l20;
                _a42_obj->f_type_id = l23;
                l27 = (void*) _a42_obj;
                vader_array_t* _a43_slotarr = ((vader_array_t*) l26);
                VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l11)
                vader_array_ref_store(_a43_slotarr->buf, _a43_slotarr->offset + (size_t) l11, l27);
                VADER_WRITE_BARRIER(_a43_slotarr->buf);
            }
            if (l19.tag == 705u) {
                l28 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body;
                t1 = l19.payload.obj;
                l24 = ((vader_struct_vader_bytecode_FnAddr_t*) t1)->f_function_index;
                vader_array_t* _a44_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l24)
                t4 = ((int32_t*) _a44_slotarr->buf->slots)[_a44_slotarr->offset + (size_t) l24];
                vader_struct_vader_bytecode_FnAddr_t* _a45_obj = (vader_struct_vader_bytecode_FnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnAddr_t));
                vader_obj_header_init(_a45_obj, 705u);
                _a45_obj->f_function_index = t4;
                l29 = (void*) _a45_obj;
                vader_array_t* _a46_slotarr = ((vader_array_t*) l28);
                VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l11)
                vader_array_ref_store(_a46_slotarr->buf, _a46_slotarr->offset + (size_t) l11, l29);
                VADER_WRITE_BARRIER(_a46_slotarr->buf);
            }
            if (l19.tag == 763u) {
                l30 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body;
                t1 = l19.payload.obj;
                l31 = ((vader_struct_vader_bytecode_MakeClosure_t*) t1)->f_function_index;
                vader_array_t* _a47_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a47_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a47_slotarr, l31)
                l32 = ((int32_t*) _a47_slotarr->buf->slots)[_a47_slotarr->offset + (size_t) l31];
                t1 = l19.payload.obj;
                l33 = ((vader_struct_vader_bytecode_MakeClosure_t*) t1)->f_env_type_id;
                vader_struct_vader_bytecode_MakeClosure_t* _a48_obj = (vader_struct_vader_bytecode_MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_MakeClosure_t));
                vader_obj_header_init(_a48_obj, 763u);
                _a48_obj->f_function_index = l32;
                _a48_obj->f_env_type_id = l33;
                l34 = (void*) _a48_obj;
                vader_array_t* _a49_slotarr = ((vader_array_t*) l30);
                VADER_ARRAY_RESOLVE_BUF(_a49_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a49_slotarr, l11)
                vader_array_ref_store(_a49_slotarr->buf, _a49_slotarr->offset + (size_t) l11, l34);
                VADER_WRITE_BARRIER(_a49_slotarr->buf);
            }
            l11 = (l11 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    vader_array_t* _a50_arr = vader_array_new(49u, 0u, 13u, 640u);
    l4 = (void*) _a50_arr;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_exports;
    l3 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l3)) {
        vader_array_t* _a51_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a51_slotarr)
        l6 = vader_array_ref_load_obj(_a51_slotarr->buf, _a51_slotarr->offset + (size_t) l7);
        l8 = ((vader_struct_vader_bytecode_BcExport_t*) l6)->f_fn_index;
        vader_array_t* _a52_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a52_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a52_slotarr, l8)
        l10 = ((int32_t*) _a52_slotarr->buf->slots)[_a52_slotarr->offset + (size_t) l8];
        if ((l10 >= INT32_C(0))) {
            t5 = ((vader_struct_vader_bytecode_BcExport_t*) l6)->f_extern_name;
            vader_struct_vader_bytecode_BcExport_t* _a53_obj = (vader_struct_vader_bytecode_BcExport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcExport_t));
            vader_obj_header_init(_a53_obj, 640u);
            _a53_obj->f_extern_name = t5;
            _a53_obj->f_fn_index = l10;
            l25 = (void*) _a53_obj;
            vader_array_push((vader_array_t*) l4, vader_ref_box(l25));
        }
        l7 = (l7 + INT64_C(1));
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_exports = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    vader_array_t* _a54_arr = vader_array_new(15u, 0u, 7u, 290u);
    l4 = (void*) _a54_arr;
    vader_array_t* _a55_arr = vader_array_new(15u, 0u, 7u, 290u);
    l5 = (void*) _a55_arr;
    vader_array_t* _a56_arr = vader_array_new(15u, 0u, 7u, 290u);
    l6 = (void*) _a56_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a57_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a57_obj, 384u);
    _a57_obj->f_ekeys = l4;
    _a57_obj->f_evals = l5;
    _a57_obj->f_index = l6;
    _a57_obj->f_mask = INT64_C(0);
    _a57_obj->f_size = INT64_C(0);
    _a57_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a57_obj;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_function_index_by_symbol_id;
    l6 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l5)->f_ekeys;
    l25 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l5)->f_evals;
    l3 = INT64_C(0);
    l7 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l5)->f_size;
    while ((l3 < l7)) {
        vader_array_t* _a58_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a58_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a58_slotarr, l3)
        l8 = ((int32_t*) _a58_slotarr->buf->slots)[_a58_slotarr->offset + (size_t) l3];
        vader_array_t* _a59_slotarr = ((vader_array_t*) l25);
        VADER_ARRAY_RESOLVE_BUF(_a59_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a59_slotarr, l3)
        l10 = ((int32_t*) _a59_slotarr->buf->slots)[_a59_slotarr->offset + (size_t) l3];
        l20 = l8;
        l23 = l10;
        vader_array_t* _a60_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a60_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a60_slotarr, l23)
        l24 = ((int32_t*) _a60_slotarr->buf->slots)[_a60_slotarr->offset + (size_t) l23];
        if ((l24 >= INT32_C(0))) {
            std_collections_MutableMap_std_core_IndexSet_set_at__i32__i32(l4, l20, l24);
        }
        l3 = (l3 + INT64_C(1));
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_function_index_by_symbol_id = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    vader_array_t* _a61_arr = vader_array_new(14u, 0u, 0u, 287u);
    l4 = (void*) _a61_arr;
    vader_array_t* _a62_arr = vader_array_new(15u, 0u, 7u, 290u);
    l5 = (void*) _a62_arr;
    vader_array_t* _a63_arr = vader_array_new(15u, 0u, 7u, 290u);
    l6 = (void*) _a63_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a64_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a64_obj, 457u);
    _a64_obj->f_ekeys = l4;
    _a64_obj->f_evals = l5;
    _a64_obj->f_index = l6;
    _a64_obj->f_mask = INT64_C(0);
    _a64_obj->f_size = INT64_C(0);
    _a64_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a64_obj;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_function_index_by_mangle;
    l6 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l5)->f_ekeys;
    l25 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l5)->f_evals;
    l3 = INT64_C(0);
    l7 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l5)->f_size;
    while ((l3 < l7)) {
        vader_array_t* _a65_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a65_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a65_slotarr, l3)
        t2 = vader_array_box_slots(_a65_slotarr->buf)[_a65_slotarr->offset + (size_t) l3];
        l9 = t2.payload.s;
        vader_array_t* _a66_slotarr = ((vader_array_t*) l25);
        VADER_ARRAY_RESOLVE_BUF(_a66_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a66_slotarr, l3)
        l8 = ((int32_t*) _a66_slotarr->buf->slots)[_a66_slotarr->offset + (size_t) l3];
        l35 = l9;
        l10 = l8;
        vader_array_t* _a67_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a67_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a67_slotarr, l10)
        l20 = ((int32_t*) _a67_slotarr->buf->slots)[_a67_slotarr->offset + (size_t) l10];
        if ((l20 >= INT32_C(0))) {
            std_collections_MutableMap_std_core_IndexSet_set_at__string__i32(l4, l35, l20);
        }
        l3 = (l3 + INT64_C(1));
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_function_index_by_mangle = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    vader_array_t* _a68_arr = vader_array_new(15u, 0u, 7u, 290u);
    l4 = (void*) _a68_arr;
    vader_array_t* _a69_arr = vader_array_new(21u, 0u, 0u, 298u);
    l5 = (void*) _a69_arr;
    vader_array_t* _a70_arr = vader_array_new(15u, 0u, 7u, 290u);
    l6 = (void*) _a70_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a71_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a71_obj, 382u);
    _a71_obj->f_ekeys = l4;
    _a71_obj->f_evals = l5;
    _a71_obj->f_index = l6;
    _a71_obj->f_mask = INT64_C(0);
    _a71_obj->f_size = INT64_C(0);
    _a71_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a71_obj;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_pinned_types_by_fn;
    l6 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l5)->f_ekeys;
    l25 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l5)->f_evals;
    l3 = INT64_C(0);
    l7 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l5)->f_size;
    while ((l3 < l7)) {
        vader_array_t* _a72_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a72_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a72_slotarr, l3)
        l8 = ((int32_t*) _a72_slotarr->buf->slots)[_a72_slotarr->offset + (size_t) l3];
        vader_array_t* _a73_slotarr = ((vader_array_t*) l25);
        VADER_ARRAY_RESOLVE_BUF(_a73_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a73_slotarr, l3)
        l5 = vader_array_ref_load_obj(_a73_slotarr->buf, _a73_slotarr->offset + (size_t) l3);
        l10 = l8;
        l26 = l5;
        l11 = ((int64_t) (int32_t) l10);
        if ((INT64_C(0) <= l11)) {
            l14 = ((vader_array_t*) l13)->length;
            l16 = (l11 < l14);
        } else {
            l16 = false;
        }
        if (!(!(l16))) {
            vader_array_t* _a74_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a74_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a74_slotarr, l10)
            l20 = ((int32_t*) _a74_slotarr->buf->slots)[_a74_slotarr->offset + (size_t) l10];
            if (!((l20 < INT32_C(0)))) {
                l19 = std_collections_MutableMap_std_core_Index_at__i32__Any(l4, l20);
                if (l19.tag == 15u) {
                    l27 = l26;
                    l15 = ((vader_array_t*) l27)->length;
                    l17 = INT64_C(0);
                    while ((l17 < l15)) {
                        vader_array_t* _a75_slotarr = ((vader_array_t*) l27);
                        VADER_ARRAY_RESOLVE_BUF(_a75_slotarr)
                        l23 = ((int32_t*) _a75_slotarr->buf->slots)[_a75_slotarr->offset + (size_t) l17];
                        t1 = l19.payload.obj;
                        vader_array_push_i32((vader_array_t*) t1, l23);
                        l17 = (l17 + INT64_C(1));
                    }
                } else {
                    std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l4, l20, vader_ref_box(l26));
                }
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_pinned_types_by_fn = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions = l12;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_bytecode_prune_unused_globals(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    int64_t l4, l5, l6, l7;
    vader_box_t l8 = vader_box_null();
    int32_t l9, l10;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    int32_t t3;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l11, &l12, &l13, &l14, &l15, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 285u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 290u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 383u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 519u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
        l3 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_body;
        l6 = ((vader_array_t*) l3)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            l8 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l7);
            if (l8.tag == 707u) {
                t0 = l8.payload.obj;
                l9 = ((vader_struct_vader_bytecode_GlobalGet_t*) t0)->f_index;
                std_collections_add__i32(l1, l9);
            } else if (l8.tag == 708u) {
                t0 = l8.payload.obj;
                l10 = ((vader_struct_vader_bytecode_GlobalSet_t*) t0)->f_index;
                std_collections_add__i32(l1, l10);
            }
            l7 = (l7 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l4 = std_collections_len__i32(l1);
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_globals)->length;
    if (l4 == l5) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a7_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(52u, 0u, 13u, 644u);
    l3 = (void*) _a8_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_globals)->length;
    while ((l4 < l5)) {
        l9 = ((int32_t) (int64_t) l4);
        t1 = std_collections_MutableSet_std_core_Contains_contains__i32(l1, l9);
        if (t1) {
            t2 = ((vader_array_t*) l3)->length;
            l10 = ((int32_t) (int64_t) t2);
            vader_array_push_i32((vader_array_t*) l2, l10);
            vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_globals);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l4)
            l11 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l4);
            vader_array_push((vader_array_t*) l3, vader_ref_box(l11));
        } else {
            vader_array_push_i32((vader_array_t*) l2, INT32_C(-1));
        }
        l4 = (l4 + INT64_C(1));
    }
    l1 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l1)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l11 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l5);
        l6 = INT64_C(0);
        l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l11)->f_body)->length;
        while ((l6 < l7)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l11)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l6)
            l8 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l6);
            if (l8.tag == 707u) {
                l12 = ((vader_struct_vader_bytecode_BcFunction_t*) l11)->f_body;
                t0 = l8.payload.obj;
                l9 = ((vader_struct_vader_bytecode_GlobalGet_t*) t0)->f_index;
                vader_array_t* _a12_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l9)
                t3 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l9];
                vader_struct_vader_bytecode_GlobalGet_t* _a13_obj = (vader_struct_vader_bytecode_GlobalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_GlobalGet_t));
                vader_obj_header_init(_a13_obj, 707u);
                _a13_obj->f_index = t3;
                l13 = (void*) _a13_obj;
                vader_array_t* _a14_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l6)
                vader_array_ref_store(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l6, l13);
                VADER_WRITE_BARRIER(_a14_slotarr->buf);
            } else if (l8.tag == 708u) {
                l14 = ((vader_struct_vader_bytecode_BcFunction_t*) l11)->f_body;
                t0 = l8.payload.obj;
                l10 = ((vader_struct_vader_bytecode_GlobalSet_t*) t0)->f_index;
                vader_array_t* _a15_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l10)
                t3 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l10];
                vader_struct_vader_bytecode_GlobalSet_t* _a16_obj = (vader_struct_vader_bytecode_GlobalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_GlobalSet_t));
                vader_obj_header_init(_a16_obj, 708u);
                _a16_obj->f_index = t3;
                l15 = (void*) _a16_obj;
                vader_array_t* _a17_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l6)
                vader_array_ref_store(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l6, l15);
                VADER_WRITE_BARRIER(_a17_slotarr->buf);
            }
            l6 = (l6 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_globals = l3;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_bytecode_prune_unused_imports(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    int64_t l4, l5, l6, l7;
    vader_box_t l8 = vader_box_null();
    int32_t l9, l10;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    int32_t t3;
    vader_box_t* gc_roots[2] = { &l8, &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l11, &l12, &l13, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 285u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 290u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 383u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
        l3 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_body;
        l6 = ((vader_array_t*) l3)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l8 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
            if (l8.tag == 676u) {
                t0 = l8.payload.obj;
                l9 = ((vader_struct_vader_bytecode_CallImport_t*) t0)->f_index;
                std_collections_MutableMap_std_core_IndexSet_set_at__i32__bool(l1, l9, true);
            }
            l7 = (l7 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l4 = std_collections_len__i32__bool(l1);
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports)->length;
    if (l4 == l5) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a6_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(53u, 0u, 13u, 645u);
    l3 = (void*) _a7_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports)->length;
    while ((l4 < l5)) {
        l9 = ((int32_t) (int64_t) l4);
        t1 = std_collections_MutableMap_std_core_Index_at__i32__bool(l1, l9);
        if (t1.tag == 285u) {
            t2 = ((vader_array_t*) l3)->length;
            l10 = ((int32_t) (int64_t) t2);
            vader_array_push_i32((vader_array_t*) l2, l10);
            vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l4)
            l11 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l4);
            vader_array_push((vader_array_t*) l3, vader_ref_box(l11));
        } else {
            vader_array_push_i32((vader_array_t*) l2, INT32_C(-1));
        }
        l4 = (l4 + INT64_C(1));
    }
    l1 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l1)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        l11 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l5);
        l6 = INT64_C(0);
        l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l11)->f_body)->length;
        while ((l6 < l7)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l11)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l6)
            l8 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l6);
            if (l8.tag == 676u) {
                l12 = ((vader_struct_vader_bytecode_BcFunction_t*) l11)->f_body;
                t0 = l8.payload.obj;
                l9 = ((vader_struct_vader_bytecode_CallImport_t*) t0)->f_index;
                vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
                t3 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l9];
                vader_struct_vader_bytecode_CallImport_t* _a12_obj = (vader_struct_vader_bytecode_CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallImport_t));
                vader_obj_header_init(_a12_obj, 676u);
                _a12_obj->f_index = t3;
                l13 = (void*) _a12_obj;
                vader_array_t* _a13_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
                vader_array_ref_store(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l6, l13);
                VADER_WRITE_BARRIER(_a13_slotarr->buf);
            }
            l6 = (l6 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports = l3;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_bytecode_prune_unused_types(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l25 = NULL;
    int64_t l4, l5, l9, l10, l13, l14;
    int32_t l11, l15, l20;
    vader_box_t l16 = vader_box_null(), l17 = vader_box_null();
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    vader_string_t l24 = 0;
    bool l21;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    bool t3;
    int64_t t4;
    vader_box_t* gc_roots[3] = { &l16, &l17, &t1 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l6, &l7, &l8, &l12, &l25, &t0 };
    vader_string_t* gc_atom_roots[5] = { &l18, &l19, &l22, &l23, &l24 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 285u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 290u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 383u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 519u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    std_collections_add__i32(l1, INT32_C(0));
    vader_array_t* _a5_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a5_arr;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_signature)->f_result_types;
        vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l7);
        l8 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_signature)->f_param_types;
        l9 = ((vader_array_t*) l8)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            l11 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l10];
            vader_array_push_i32((vader_array_t*) l2, l11);
            l10 = (l10 + INT64_C(1));
        }
        l12 = ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_body;
        l13 = ((vader_array_t*) l12)->length;
        l14 = INT64_C(0);
        while ((l14 < l13)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            t1 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l14);
            l15 = vader_bytecode_type_index_of(t1);
            if ((l15 >= INT32_C(0))) {
                vader_array_push_i32((vader_array_t*) l2, l15);
            }
            l14 = (l14 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        l6 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_result_types;
        vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l7);
        l8 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_param_types;
        l9 = ((vader_array_t*) l8)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            l11 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l10];
            vader_array_push_i32((vader_array_t*) l2, l11);
            l10 = (l10 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_globals;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        t0 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l5);
        l11 = ((vader_struct_vader_bytecode_BcGlobal_t*) t0)->f_type_id;
        vader_array_push_i32((vader_array_t*) l2, l11);
        l5 = (l5 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_pinned_types;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        l11 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l5];
        vader_array_push_i32((vader_array_t*) l2, l11);
        l5 = (l5 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_pinned_types_by_fn;
    l6 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l3)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l3)->f_evals;
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l3)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l4)
        t2 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l4];
        vader_array_t* _a14_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l4)
        l3 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l4);
        l9 = ((vader_array_t*) l3)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            l11 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l10];
            vader_array_push_i32((vader_array_t*) l2, l11);
            l10 = (l10 + INT64_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        t2 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l5];
        vader_bytecode_visit_type(t2, l0, l1);
        l5 = (l5 + INT64_C(1));
    }
    l4 = std_collections_len__i32(l1);
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types)->length;
    if (l4 == l5) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types)->length;
    vader_array_t* _a17_arr = vader_array_new(15u, 0u, 7u, 290u);
    l2 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(228u, 0u, 13u, 1560u);
    l3 = (void*) _a18_arr;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        l11 = ((int32_t) (int64_t) l5);
        t3 = std_collections_MutableSet_std_core_Contains_contains__i32(l1, l11);
        if (t3) {
            t4 = ((vader_array_t*) l3)->length;
            l15 = ((int32_t) (int64_t) t4);
            vader_array_push_i32((vader_array_t*) l2, l15);
            vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l5)
            l16 = vader_array_ref_load_box(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l5);
            vader_array_push((vader_array_t*) l3, l16);
        } else {
            vader_array_push_i32((vader_array_t*) l2, INT32_C(-1));
        }
        l5 = (l5 + INT64_C(1));
    }
    l1 = l3;
    vader_struct___lambda_env_vader_bytecode_1_t* _a20_obj = (vader_struct___lambda_env_vader_bytecode_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_bytecode_1_t));
    vader_obj_header_init(_a20_obj, 308u);
    _a20_obj->f_cap_0 = l2;
    l3 = (void*) _a20_obj;
    vader_array_t* _a21_arr = vader_array_new(228u, 0u, 13u, 1560u);
    l6 = (void*) _a21_arr;
    l4 = ((vader_array_t*) l1)->length;
    vader_array_t* _a22_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l4);
    l6 = (void*) _a22_arr;
    l4 = ((vader_array_t*) l1)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a23_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        l16 = vader_array_ref_load_box(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l5);
        l17 = __lambda_vader_bytecode_0(l3, l16);
        vader_array_push((vader_array_t*) l6, l17);
        l5 = (l5 + INT64_C(1));
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    vader_array_t* _a24_arr = vader_array_new(14u, 0u, 0u, 287u);
    l1 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(15u, 0u, 7u, 290u);
    l3 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(15u, 0u, 7u, 290u);
    l6 = (void*) _a26_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a27_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a27_obj, 457u);
    _a27_obj->f_ekeys = l1;
    _a27_obj->f_evals = l3;
    _a27_obj->f_index = l6;
    _a27_obj->f_mask = INT64_C(0);
    _a27_obj->f_size = INT64_C(0);
    _a27_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a27_obj;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_key;
    l6 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l3)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l3)->f_evals;
    l4 = INT64_C(0);
    l5 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l3)->f_size;
    while ((l4 < l5)) {
        vader_array_t* _a28_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l4)
        t1 = vader_array_box_slots(_a28_slotarr->buf)[_a28_slotarr->offset + (size_t) l4];
        l18 = t1.payload.s;
        vader_array_t* _a29_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l4)
        l11 = ((int32_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l4];
        l19 = l18;
        l15 = l11;
        l20 = vader_bytecode_remap_idx(l2, l15);
        if ((l20 >= INT32_C(0))) {
            std_collections_MutableMap_std_core_IndexSet_set_at__string__i32(l1, l19, l20);
        }
        l4 = (l4 + INT64_C(1));
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_key = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    l1 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l1)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a30_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
        l3 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l5);
        l6 = vader_bytecode_remap_signature(((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature, l2);
        ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature = l6;
        VADER_WRITE_BARRIER((vader_struct_vader_bytecode_BcFunction_t*) l3);
        l9 = INT64_C(0);
        l10 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_body)->length;
        while ((l9 < l10)) {
            l7 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_body;
            vader_array_t* _a31_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l9)
            t1 = vader_array_ref_load_box(_a31_slotarr->buf, _a31_slotarr->offset + (size_t) l9);
            l16 = vader_bytecode_remap_type_in_op(t1, l2);
            vader_array_t* _a32_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l9)
            vader_array_ref_store(_a32_slotarr->buf, _a32_slotarr->offset + (size_t) l9, l16.payload.obj);
            VADER_WRITE_BARRIER(_a32_slotarr->buf);
            l9 = (l9 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a33_arr = vader_array_new(53u, 0u, 13u, 645u);
    l1 = (void*) _a33_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports)->length;
    vader_array_t* _a34_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l4);
    l1 = (void*) _a34_arr;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a35_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        l6 = vader_array_ref_load_obj(_a35_slotarr->buf, _a35_slotarr->offset + (size_t) l5);
        l7 = l6;
        l18 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_extern_name;
        l19 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_mangled_name;
        l8 = vader_bytecode_remap_signature(((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature, l2);
        l21 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_is_extern;
        l22 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_c_header;
        l23 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_c_library;
        l11 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_c_variadic_fixed;
        l12 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_param_c_types;
        l24 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_result_c_type;
        vader_struct_vader_bytecode_BcImport_t* _a36_obj = (vader_struct_vader_bytecode_BcImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcImport_t));
        vader_obj_header_init(_a36_obj, 645u);
        _a36_obj->f_extern_name = l18;
        _a36_obj->f_mangled_name = l19;
        _a36_obj->f_signature = l8;
        _a36_obj->f_is_extern = l21;
        _a36_obj->f_c_header = l22;
        _a36_obj->f_c_library = l23;
        _a36_obj->f_c_variadic_fixed = l11;
        _a36_obj->f_param_c_types = l12;
        _a36_obj->f_result_c_type = l24;
        l25 = (void*) _a36_obj;
        vader_array_push((vader_array_t*) l1, vader_ref_box(l25));
        l5 = (l5 + INT64_C(1));
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    l1 = vader_bytecode_remap_globals(((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_globals, l2);
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_globals = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_bytecode_push_or_assign(void* l0, int64_t l1, vader_box_t l2) {
    int64_t l3;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) l0)->length;
    if (l1 == l3) {
        vader_array_push((vader_array_t*) l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    vader_array_ref_store(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1, l2.payload.obj);
    VADER_WRITE_BARRIER(_a0_slotarr->buf);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_bytecode_push_scope(void* l0, void* l1, int64_t l2, vader_string_t l3, int32_t l4) {
    int64_t l5;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_array_t*) l0)->length;
    if (l2 == l5) {
        vader_array_push((vader_array_t*) l0, vader_box_string(287u, l3));
        vader_array_push_i32((vader_array_t*) l1, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l2] = vader_box_string(287u, l3);
    VADER_WRITE_BARRIER(_a0_slotarr->buf);
    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l2] = (int32_t) l4;
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_bytecode_ranges_overlap(void* l0, void* l1) {
    int32_t l2, l3;
    l2 = ((vader_struct_vader_bytecode_SlotRange_t*) l0)->f_first;
    l3 = ((vader_struct_vader_bytecode_SlotRange_t*) l1)->f_last;
    if ((l2 <= l3)) {
        l2 = ((vader_struct_vader_bytecode_SlotRange_t*) l1)->f_first;
        l3 = ((vader_struct_vader_bytecode_SlotRange_t*) l0)->f_last;
        return (l2 <= l3);
    }
    return false;
}

void vader_bytecode_record_slot_type(void* l0, int32_t l1, vader_box_t l2) {
    int64_t l3, l4;
    bool l5;
    void* l6 = NULL;
    void* l7 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l6, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_by_slot)->length;
    l4 = ((int64_t) (int32_t) l1);
    l5 = (l3 <= l4);
    while (l5) {
        l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_by_slot;
        t0 = (void*) &vader_data_17;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        vader_array_push((vader_array_t*) l6, vader_ref_box(l7));
        l5 = (l3 < l4);
        l3 = (l3 + INT64_C(1));
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_by_slot);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1, l2.payload.obj);
    VADER_WRITE_BARRIER(_a1_slotarr->buf);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_bytecode_refer(uint8_t l0, int32_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_OperandRef_t* _a0_obj = (vader_struct_vader_bytecode_OperandRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_OperandRef_t));
    vader_obj_header_init(_a0_obj, 766u);
    _a0_obj->f_kind = l0;
    _a0_obj->f_index = l1;
    _a0_obj->f_owner = INT32_C(-1);
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_bytecode_refer_field(int32_t l0, int32_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_OperandRef_t* _a0_obj = (vader_struct_vader_bytecode_OperandRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_OperandRef_t));
    vader_obj_header_init(_a0_obj, 766u);
    _a0_obj->f_kind = (uint8_t) 2;
    _a0_obj->f_index = l1;
    _a0_obj->f_owner = l0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_bytecode_remap_debug(void* l0, void* l1, int64_t l2) {
    void* l3 = NULL;
    int64_t l4, l5, l7;
    int32_t l6;
    vader_box_t l8 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l8, &t1 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(230u, 1u, 13u, 1594u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = vader_box_obj(0u, NULL).payload.obj;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l3 = (void*) _a1_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) l0)->length;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l6 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        if ((l6 < INT32_C(0))) {
            l4 = (l4 + INT64_C(1));
            continue;
        }
        l7 = ((int64_t) (int32_t) l6);
        if ((l7 < l2)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
            if (t1.tag == 0u) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                l8 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
                vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7, l8.payload.obj);
                VADER_WRITE_BARRIER(_a5_slotarr->buf);
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_bytecode_remap_globals(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l5, l6;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    vader_struct___lambda_env_vader_bytecode_3_t* _a0_obj = (vader_struct___lambda_env_vader_bytecode_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_bytecode_3_t));
    vader_obj_header_init(_a0_obj, 309u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(52u, 0u, 13u, 644u);
    l4 = (void*) _a1_arr;
    l5 = ((vader_array_t*) l2)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a2_arr;
    l5 = ((vader_array_t*) l2)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        l8 = __lambda_vader_bytecode_2(l3, l7);
        vader_array_push((vader_array_t*) l4, vader_ref_box(l8));
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_bytecode_remap_idx(void* l0, int32_t l1) {
    int64_t l2, l3;
    int32_t t0;
    if ((l1 < INT32_C(0))) {
        return l1;
    }
    l2 = ((int64_t) (int32_t) l1);
    l3 = ((vader_array_t*) l0)->length;
    if (!((l2 >= l3))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
        return t0;
    }
    return INT32_C(-1);
}

void* vader_bytecode_remap_jump_table(void* l0, void* l1, int64_t l2) {
    void* l3 = NULL;
    int64_t l4, l5, l7, l8, l11, l12, l14;
    int32_t l6, l9, l10, l13;
    bool l15;
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l3 = (void*) _a0_arr;
    if ((INT64_C(0) < l2)) {
        l4 = l2;
    } else {
        l4 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    l4 = INT64_C(0);
    vader_array_t* _pc18_hdr = (vader_array_t*) l3;
    size_t _pc18_len = _pc18_hdr->length;
    size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
    void* _pc18_slots = _pc18_hdr->buf->slots;
    for (;;) {
        if ((l4 < l2)) {
            if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                ((int32_t*) _pc18_slots)[_pc18_len] = (int32_t) (INT32_C(-1));
                _pc18_len += 1;
            } else {
                _pc18_hdr->length = _pc18_len;
                if (_pc18_hdr->buf->length < _pc18_len) {
                    _pc18_hdr->buf->length = _pc18_len;
                }
                vader_array_push_i32((vader_array_t*) l3, INT32_C(-1));
                _pc18_hdr = (vader_array_t*) l3;
                _pc18_len = _pc18_hdr->length;
                _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                _pc18_slots = _pc18_hdr->buf->slots;
            }
            l4 = (l4 + INT64_C(1));
            continue;
        }
        _pc18_hdr->length = _pc18_len;
        if (_pc18_hdr->buf->length < _pc18_len) {
            _pc18_hdr->buf->length = _pc18_len;
        }
        break;
    }
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

static vader_box_t vader_bytecode_remap_push_cache_slot(vader_box_t l0, void* l1) {
    bool l2;
    int64_t l3, l4;
    int32_t l5, l6;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 632u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_cache_slot;
    if ((t1 < INT32_C(0))) {
        l2 = true;
    } else {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_cache_slot;
        l3 = ((int64_t) (int32_t) t1);
        l4 = ((vader_array_t*) l1)->length;
        l2 = (l3 >= l4);
    }
    if (!(l2)) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_type_id;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_cache_slot;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6];
        vader_struct_vader_bytecode_ArrayPush_t* _a1_obj = (vader_struct_vader_bytecode_ArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayPush_t));
        vader_obj_header_init(_a1_obj, 632u);
        _a1_obj->f_type_id = l5;
        _a1_obj->f_cache_slot = l6;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_bytecode_remap_signature(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_params;
    l4 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_results;
    l5 = ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_param_types;
    l5 = vader_bytecode_remap_type_indices(l1, l5);
    l6 = ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_result_types;
    l6 = vader_bytecode_remap_type_indices(l1, l6);
    l7 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_names;
    l8 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_c_out;
    l2 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_by_address;
    vader_struct_vader_bytecode_BcSignature_t* _a0_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
    vader_obj_header_init(_a0_obj, 651u);
    _a0_obj->f_params = l3;
    _a0_obj->f_results = l4;
    _a0_obj->f_param_types = l5;
    _a0_obj->f_result_types = l6;
    _a0_obj->f_param_names = l7;
    _a0_obj->f_param_c_out = l8;
    _a0_obj->f_param_by_address = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_bytecode_remap_type(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l11 = NULL;
    int64_t l5, l6;
    vader_string_t l8 = 0;
    vader_string_t l12 = 0;
    int32_t l9, l10;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[6] = { &l1, &l3, &l4, &l7, &l11, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l0.tag == 649u || l0.tag == 650u)) {
        l2 = l0;
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 653u) {
        vader_array_t* _a0_arr = vader_array_new(50u, 0u, 13u, 641u);
        l3 = (void*) _a0_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields;
        l5 = ((vader_array_t*) l4)->length;
        l6 = INT64_C(0);
        while ((l6 < l5)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
            l8 = ((vader_struct_vader_bytecode_BcField_t*) l7)->f_name;
            l9 = ((vader_struct_vader_bytecode_BcField_t*) l7)->f_type_index;
            l10 = vader_bytecode_remap_idx(l1, l9);
            vader_struct_vader_bytecode_BcField_t* _a2_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
            vader_obj_header_init(_a2_obj, 641u);
            _a2_obj->f_name = l8;
            _a2_obj->f_type_index = l10;
            l11 = (void*) _a2_obj;
            vader_array_push((vader_array_t*) l3, vader_ref_box(l11));
            l6 = (l6 + INT64_C(1));
        }
        l4 = l0.payload.obj;
        l8 = ((vader_struct_vader_bytecode_BcStruct_t*) l4)->f_name;
        l12 = ((vader_struct_vader_bytecode_BcStruct_t*) l4)->f_c_name;
        l9 = ((vader_struct_vader_bytecode_BcStruct_t*) l4)->f_symbol_id;
        vader_struct_vader_bytecode_BcStruct_t* _a3_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
        vader_obj_header_init(_a3_obj, 653u);
        _a3_obj->f_name = l8;
        _a3_obj->f_fields = l3;
        _a3_obj->f_c_name = l12;
        _a3_obj->f_symbol_id = l9;
        t0 = (void*) _a3_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 639u) {
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_bytecode_BcArray_t*) t0)->f_element;
        t1 = vader_bytecode_remap_idx(l1, l9);
        vader_struct_vader_bytecode_BcArray_t* _a4_obj = (vader_struct_vader_bytecode_BcArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcArray_t));
        vader_obj_header_init(_a4_obj, 639u);
        _a4_obj->f_element = t1;
        t0 = (void*) _a4_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 654u) {
        vader_array_t* _a5_arr = vader_array_new(15u, 0u, 7u, 290u);
        l3 = (void*) _a5_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_BcUnion_t*) t0)->f_variants;
        l5 = ((vader_array_t*) l4)->length;
        l6 = INT64_C(0);
        vader_array_t* _pc99_hdr = (vader_array_t*) l3;
        size_t _pc99_len = _pc99_hdr->length;
        size_t _pc99_cap = (_pc99_hdr->offset == 0 && !vader_array_is_borrowed(_pc99_hdr) && _pc99_hdr->length >= _pc99_hdr->buf->length) ? _pc99_hdr->capacity : (size_t) 0;
        void* _pc99_slots = _pc99_hdr->buf->slots;
        for (;;) {
            if ((l6 < l5)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                l9 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l6];
                l10 = vader_bytecode_remap_idx(l1, l9);
                if (VADER_LIKELY(_pc99_len < _pc99_cap)) {
                    ((int32_t*) _pc99_slots)[_pc99_len] = (int32_t) (l10);
                    _pc99_len += 1;
                } else {
                    _pc99_hdr->length = _pc99_len;
                    if (_pc99_hdr->buf->length < _pc99_len) {
                        _pc99_hdr->buf->length = _pc99_len;
                    }
                    vader_array_push_i32((vader_array_t*) l3, l10);
                    _pc99_hdr = (vader_array_t*) l3;
                    _pc99_len = _pc99_hdr->length;
                    _pc99_cap = (_pc99_hdr->offset == 0 && !vader_array_is_borrowed(_pc99_hdr) && _pc99_hdr->length >= _pc99_hdr->buf->length) ? _pc99_hdr->capacity : (size_t) 0;
                    _pc99_slots = _pc99_hdr->buf->slots;
                }
                l6 = (l6 + INT64_C(1));
                continue;
            }
            _pc99_hdr->length = _pc99_len;
            if (_pc99_hdr->buf->length < _pc99_len) {
                _pc99_hdr->buf->length = _pc99_len;
            }
            break;
        }
        vader_struct_vader_bytecode_BcUnion_t* _a7_obj = (vader_struct_vader_bytecode_BcUnion_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcUnion_t));
        vader_obj_header_init(_a7_obj, 654u);
        _a7_obj->f_variants = l3;
        t0 = (void*) _a7_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!(l0.tag == 642u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_array_t* _a8_arr = vader_array_new(15u, 0u, 7u, 290u);
        l3 = (void*) _a8_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_BcFn_t*) t0)->f_params;
        l5 = ((vader_array_t*) l4)->length;
        l6 = INT64_C(0);
        vader_array_t* _pc142_hdr = (vader_array_t*) l3;
        size_t _pc142_len = _pc142_hdr->length;
        size_t _pc142_cap = (_pc142_hdr->offset == 0 && !vader_array_is_borrowed(_pc142_hdr) && _pc142_hdr->length >= _pc142_hdr->buf->length) ? _pc142_hdr->capacity : (size_t) 0;
        void* _pc142_slots = _pc142_hdr->buf->slots;
        for (;;) {
            if ((l6 < l5)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                l9 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l6];
                l10 = vader_bytecode_remap_idx(l1, l9);
                if (VADER_LIKELY(_pc142_len < _pc142_cap)) {
                    ((int32_t*) _pc142_slots)[_pc142_len] = (int32_t) (l10);
                    _pc142_len += 1;
                } else {
                    _pc142_hdr->length = _pc142_len;
                    if (_pc142_hdr->buf->length < _pc142_len) {
                        _pc142_hdr->buf->length = _pc142_len;
                    }
                    vader_array_push_i32((vader_array_t*) l3, l10);
                    _pc142_hdr = (vader_array_t*) l3;
                    _pc142_len = _pc142_hdr->length;
                    _pc142_cap = (_pc142_hdr->offset == 0 && !vader_array_is_borrowed(_pc142_hdr) && _pc142_hdr->length >= _pc142_hdr->buf->length) ? _pc142_hdr->capacity : (size_t) 0;
                    _pc142_slots = _pc142_hdr->buf->slots;
                }
                l6 = (l6 + INT64_C(1));
                continue;
            }
            _pc142_hdr->length = _pc142_len;
            if (_pc142_hdr->buf->length < _pc142_len) {
                _pc142_hdr->buf->length = _pc142_len;
            }
            break;
        }
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_bytecode_BcFn_t*) t0)->f_return_type;
        l9 = vader_bytecode_remap_idx(l1, l9);
        vader_struct_vader_bytecode_BcFn_t* _a10_obj = (vader_struct_vader_bytecode_BcFn_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFn_t));
        vader_obj_header_init(_a10_obj, 642u);
        _a10_obj->f_params = l3;
        _a10_obj->f_return_type = l9;
        t0 = (void*) _a10_obj;
        l2 = vader_ref_box(t0);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_remap_type_in_op(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    int32_t l4, l6, l7;
    bool l5;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 787u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l5 = ((vader_struct_vader_bytecode_StructNew_t*) l3)->f_stack;
        vader_struct_vader_bytecode_StructNew_t* _a0_obj = (vader_struct_vader_bytecode_StructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructNew_t));
        vader_obj_header_init(_a0_obj, 787u);
        _a0_obj->f_type_id = l4;
        _a0_obj->f_stack = l5;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 786u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l6 = ((vader_struct_vader_bytecode_StructGet_t*) l3)->f_field_index;
        vader_struct_vader_bytecode_StructGet_t* _a1_obj = (vader_struct_vader_bytecode_StructGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructGet_t));
        vader_obj_header_init(_a1_obj, 786u);
        _a1_obj->f_type_id = l4;
        _a1_obj->f_field_index = l6;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 788u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l6 = ((vader_struct_vader_bytecode_StructSet_t*) l3)->f_field_index;
        l5 = ((vader_struct_vader_bytecode_StructSet_t*) l3)->f_stack;
        vader_struct_vader_bytecode_StructSet_t* _a2_obj = (vader_struct_vader_bytecode_StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructSet_t));
        vader_obj_header_init(_a2_obj, 788u);
        _a2_obj->f_type_id = l4;
        _a2_obj->f_field_index = l6;
        _a2_obj->f_stack = l5;
        t0 = (void*) _a2_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 803u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_UnionFieldGet_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l6 = ((vader_struct_vader_bytecode_UnionFieldGet_t*) l3)->f_field_index;
        vader_struct_vader_bytecode_UnionFieldGet_t* _a3_obj = (vader_struct_vader_bytecode_UnionFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_UnionFieldGet_t));
        vader_obj_header_init(_a3_obj, 803u);
        _a3_obj->f_type_id = l4;
        _a3_obj->f_field_index = l6;
        t0 = (void*) _a3_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 804u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_UnionFieldSet_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l6 = ((vader_struct_vader_bytecode_UnionFieldSet_t*) l3)->f_field_index;
        vader_struct_vader_bytecode_UnionFieldSet_t* _a4_obj = (vader_struct_vader_bytecode_UnionFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_UnionFieldSet_t));
        vader_obj_header_init(_a4_obj, 804u);
        _a4_obj->f_type_id = l4;
        _a4_obj->f_field_index = l6;
        t0 = (void*) _a4_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 631u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l6 = ((vader_struct_vader_bytecode_ArrayNew_t*) l3)->f_length;
        vader_struct_vader_bytecode_ArrayNew_t* _a5_obj = (vader_struct_vader_bytecode_ArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayNew_t));
        vader_obj_header_init(_a5_obj, 631u);
        _a5_obj->f_type_id = l4;
        _a5_obj->f_length = l6;
        t0 = (void*) _a5_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 629u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_ArrayGet_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l5 = ((vader_struct_vader_bytecode_ArrayGet_t*) l3)->f_bounds_safe;
        vader_struct_vader_bytecode_ArrayGet_t* _a6_obj = (vader_struct_vader_bytecode_ArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayGet_t));
        vader_obj_header_init(_a6_obj, 629u);
        _a6_obj->f_type_id = l4;
        _a6_obj->f_bounds_safe = l5;
        t0 = (void*) _a6_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 636u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_ArraySet_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l5 = ((vader_struct_vader_bytecode_ArraySet_t*) l3)->f_bounds_safe;
        vader_struct_vader_bytecode_ArraySet_t* _a7_obj = (vader_struct_vader_bytecode_ArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArraySet_t));
        vader_obj_header_init(_a7_obj, 636u);
        _a7_obj->f_type_id = l4;
        _a7_obj->f_bounds_safe = l5;
        t0 = (void*) _a7_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 632u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l6 = ((vader_struct_vader_bytecode_ArrayPush_t*) l3)->f_cache_slot;
        vader_struct_vader_bytecode_ArrayPush_t* _a8_obj = (vader_struct_vader_bytecode_ArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayPush_t));
        vader_obj_header_init(_a8_obj, 632u);
        _a8_obj->f_type_id = l4;
        _a8_obj->f_cache_slot = l6;
        t0 = (void*) _a8_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 789u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_TypeCheck_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_TypeCheck_t* _a9_obj = (vader_struct_vader_bytecode_TypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_TypeCheck_t));
        vader_obj_header_init(_a9_obj, 789u);
        _a9_obj->f_type_id = t1;
        t0 = (void*) _a9_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 790u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_TypeConst_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_TypeConst_t* _a10_obj = (vader_struct_vader_bytecode_TypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_TypeConst_t));
        vader_obj_header_init(_a10_obj, 790u);
        _a10_obj->f_type_id = t1;
        t0 = (void*) _a10_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 677u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_CallIndirect_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_CallIndirect_t* _a11_obj = (vader_struct_vader_bytecode_CallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallIndirect_t));
        vader_obj_header_init(_a11_obj, 677u);
        _a11_obj->f_type_id = t1;
        t0 = (void*) _a11_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 763u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_function_index;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_env_type_id;
        l6 = vader_bytecode_remap_idx(l1, l6);
        vader_struct_vader_bytecode_MakeClosure_t* _a12_obj = (vader_struct_vader_bytecode_MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_MakeClosure_t));
        vader_obj_header_init(_a12_obj, 763u);
        _a12_obj->f_function_index = l4;
        _a12_obj->f_env_type_id = l6;
        t0 = (void*) _a12_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 706u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_function_index;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_type_id;
        l6 = vader_bytecode_remap_idx(l1, l6);
        vader_struct_vader_bytecode_FnRef_t* _a13_obj = (vader_struct_vader_bytecode_FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnRef_t));
        vader_obj_header_init(_a13_obj, 706u);
        _a13_obj->f_function_index = l4;
        _a13_obj->f_type_id = l6;
        t0 = (void*) _a13_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 758u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_LocalField_t*) l3)->f_slot;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_type_id;
        l6 = vader_bytecode_remap_idx(l1, l6);
        l7 = ((vader_struct_vader_bytecode_LocalField_t*) l3)->f_field_index;
        vader_struct_vader_bytecode_LocalField_t* _a14_obj = (vader_struct_vader_bytecode_LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalField_t));
        vader_obj_header_init(_a14_obj, 758u);
        _a14_obj->f_slot = l4;
        _a14_obj->f_type_id = l6;
        _a14_obj->f_field_index = l7;
        t0 = (void*) _a14_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 637u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_ArraySlice_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_ArraySlice_t* _a15_obj = (vader_struct_vader_bytecode_ArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArraySlice_t));
        vader_obj_header_init(_a15_obj, 637u);
        _a15_obj->f_type_id = t1;
        t0 = (void*) _a15_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 767u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_RefCast_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_RefCast_t* _a16_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
        vader_obj_header_init(_a16_obj, 767u);
        _a16_obj->f_type_id = t1;
        t0 = (void*) _a16_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 770u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_Retag_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_Retag_t* _a17_obj = (vader_struct_vader_bytecode_Retag_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Retag_t));
        vader_obj_header_init(_a17_obj, 770u);
        _a17_obj->f_type_id = t1;
        t0 = (void*) _a17_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 682u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_pool_index;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_type_id;
        l6 = vader_bytecode_remap_idx(l1, l6);
        vader_struct_vader_bytecode_DataConst_t* _a18_obj = (vader_struct_vader_bytecode_DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DataConst_t));
        vader_obj_header_init(_a18_obj, 682u);
        _a18_obj->f_pool_index = l4;
        _a18_obj->f_type_id = l6;
        t0 = (void*) _a18_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!((l0.tag == 627u || l0.tag == 628u || l0.tag == 630u || l0.tag == 633u || l0.tag == 634u || l0.tag == 635u || l0.tag == 659u || l0.tag == 660u || l0.tag == 661u || l0.tag == 662u || l0.tag == 663u || l0.tag == 664u || l0.tag == 665u || l0.tag == 666u || l0.tag == 667u || l0.tag == 668u || l0.tag == 669u || l0.tag == 670u || l0.tag == 671u || l0.tag == 672u || l0.tag == 675u || l0.tag == 676u || l0.tag == 678u || l0.tag == 679u || l0.tag == 680u || l0.tag == 681u || l0.tag == 684u || l0.tag == 685u || l0.tag == 686u || l0.tag == 687u || l0.tag == 690u || l0.tag == 691u || l0.tag == 692u || l0.tag == 693u || l0.tag == 694u || l0.tag == 695u || l0.tag == 696u || l0.tag == 697u || l0.tag == 698u || l0.tag == 699u || l0.tag == 700u || l0.tag == 701u || l0.tag == 702u || l0.tag == 703u || l0.tag == 704u || l0.tag == 705u || l0.tag == 707u || l0.tag == 708u || l0.tag == 709u || l0.tag == 710u || l0.tag == 711u || l0.tag == 712u || l0.tag == 713u || l0.tag == 714u || l0.tag == 715u || l0.tag == 716u || l0.tag == 717u || l0.tag == 718u || l0.tag == 719u || l0.tag == 720u || l0.tag == 721u || l0.tag == 722u || l0.tag == 723u || l0.tag == 724u || l0.tag == 725u || l0.tag == 726u || l0.tag == 727u || l0.tag == 728u || l0.tag == 729u || l0.tag == 730u || l0.tag == 731u || l0.tag == 732u || l0.tag == 733u || l0.tag == 734u || l0.tag == 735u || l0.tag == 736u || l0.tag == 737u || l0.tag == 738u || l0.tag == 739u || l0.tag == 740u || l0.tag == 741u || l0.tag == 742u || l0.tag == 743u || l0.tag == 744u || l0.tag == 745u || l0.tag == 746u || l0.tag == 747u || l0.tag == 748u || l0.tag == 749u || l0.tag == 751u || l0.tag == 752u || l0.tag == 753u || l0.tag == 754u || l0.tag == 755u || l0.tag == 756u || l0.tag == 757u || l0.tag == 759u || l0.tag == 760u || l0.tag == 761u || l0.tag == 762u || l0.tag == 764u || l0.tag == 765u || l0.tag == 768u || l0.tag == 769u || l0.tag == 771u || l0.tag == 772u || l0.tag == 773u || l0.tag == 775u || l0.tag == 776u || l0.tag == 777u || l0.tag == 778u || l0.tag == 779u || l0.tag == 780u || l0.tag == 781u || l0.tag == 782u || l0.tag == 783u || l0.tag == 784u || l0.tag == 785u || l0.tag == 791u || l0.tag == 792u || l0.tag == 793u || l0.tag == 794u || l0.tag == 795u || l0.tag == 796u || l0.tag == 797u || l0.tag == 798u || l0.tag == 799u || l0.tag == 800u || l0.tag == 801u || l0.tag == 802u || l0.tag == 805u || l0.tag == 806u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0;
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_bytecode_remap_type_indices(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    int32_t l7, l8;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l1;
    vader_struct___lambda_env_vader_bytecode_5_t* _a0_obj = (vader_struct___lambda_env_vader_bytecode_5_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_bytecode_5_t));
    vader_obj_header_init(_a0_obj, 310u);
    _a0_obj->f_cap_0 = l0;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 7u, 290u);
    l4 = (void*) _a1_arr;
    l5 = ((vader_array_t*) l2)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a2_arr;
    l5 = ((vader_array_t*) l2)->length;
    l6 = INT64_C(0);
    vader_array_t* _pc19_hdr = (vader_array_t*) l4;
    size_t _pc19_len = _pc19_hdr->length;
    size_t _pc19_cap = (_pc19_hdr->offset == 0 && !vader_array_is_borrowed(_pc19_hdr) && _pc19_hdr->length >= _pc19_hdr->buf->length) ? _pc19_hdr->capacity : (size_t) 0;
    void* _pc19_slots = _pc19_hdr->buf->slots;
    for (;;) {
        if ((l6 < l5)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l7 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6];
            l8 = __lambda_vader_bytecode_4(l3, l7);
            if (VADER_LIKELY(_pc19_len < _pc19_cap)) {
                ((int32_t*) _pc19_slots)[_pc19_len] = (int32_t) (l8);
                _pc19_len += 1;
            } else {
                _pc19_hdr->length = _pc19_len;
                if (_pc19_hdr->buf->length < _pc19_len) {
                    _pc19_hdr->buf->length = _pc19_len;
                }
                vader_array_push_i32((vader_array_t*) l4, l8);
                _pc19_hdr = (vader_array_t*) l4;
                _pc19_len = _pc19_hdr->length;
                _pc19_cap = (_pc19_hdr->offset == 0 && !vader_array_is_borrowed(_pc19_hdr) && _pc19_hdr->length >= _pc19_hdr->buf->length) ? _pc19_hdr->capacity : (size_t) 0;
                _pc19_slots = _pc19_hdr->buf->slots;
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        _pc19_hdr->length = _pc19_len;
        if (_pc19_hdr->buf->length < _pc19_len) {
            _pc19_hdr->buf->length = _pc19_len;
        }
        break;
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_run_bc_const_fold_arith(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    int64_t l2, l4, l6;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null(), l10 = vader_box_null();
    int32_t l9, l11;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l7, &l8, &l10 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l2 = ((vader_array_t*) l1)->length;
    vader_array_t* _a0_arr = vader_array_new(226u, 0u, 13u, 1538u);
    l3 = (void*) _a0_arr;
    l4 = INT64_C(0);
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 7u, 290u);
    l5 = (void*) _a1_arr;
    if ((INT64_C(0) < l2)) {
        l6 = l2;
    } else {
        l6 = INT64_C(0);
    }
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
    l5 = (void*) _a2_arr;
    l6 = INT64_C(0);
    vader_array_t* _pc26_hdr = (vader_array_t*) l5;
    size_t _pc26_len = _pc26_hdr->length;
    size_t _pc26_cap = (_pc26_hdr->offset == 0 && !vader_array_is_borrowed(_pc26_hdr) && _pc26_hdr->length >= _pc26_hdr->buf->length) ? _pc26_hdr->capacity : (size_t) 0;
    void* _pc26_slots = _pc26_hdr->buf->slots;
    for (;;) {
        if ((l6 < l2)) {
            if (VADER_LIKELY(_pc26_len < _pc26_cap)) {
                ((int32_t*) _pc26_slots)[_pc26_len] = (int32_t) (INT32_C(-1));
                _pc26_len += 1;
            } else {
                _pc26_hdr->length = _pc26_len;
                if (_pc26_hdr->buf->length < _pc26_len) {
                    _pc26_hdr->buf->length = _pc26_len;
                }
                vader_array_push_i32((vader_array_t*) l5, INT32_C(-1));
                _pc26_hdr = (vader_array_t*) l5;
                _pc26_len = _pc26_hdr->length;
                _pc26_cap = (_pc26_hdr->offset == 0 && !vader_array_is_borrowed(_pc26_hdr) && _pc26_hdr->length >= _pc26_hdr->buf->length) ? _pc26_hdr->capacity : (size_t) 0;
                _pc26_slots = _pc26_hdr->buf->slots;
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        _pc26_hdr->length = _pc26_len;
        if (_pc26_hdr->buf->length < _pc26_len) {
            _pc26_hdr->buf->length = _pc26_len;
        }
        break;
    }
    l6 = INT64_C(0);
    while ((l6 < l2)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        l8 = vader_bytecode_try_fold_arith(l7, l3, l4);
        if (l8.tag == 0u) {
            vader_bytecode_push_or_assign(l3, l4, l7);
            l9 = ((int32_t) (int64_t) l4);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
            ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l6] = (int32_t) l9;
            l4 = vader_chk_add(i64, l4, INT64_C(1));
        } else {
            l4 = vader_chk_sub(i64, l4, INT64_C(2));
            l10 = l8;
            vader_bytecode_push_or_assign(l3, l4, l10);
            l11 = ((int32_t) (int64_t) l4);
            vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
            ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l6] = (int32_t) l11;
            l4 = vader_chk_add(i64, l4, INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a6_arr = vader_array_slice((vader_array_t*) l3, (int64_t) INT64_C(0), (int64_t) l4);
    l1 = (void*) _a6_arr;
    l3 = vader_bytecode_remap_jump_table(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l5, l4);
    l5 = vader_bytecode_remap_debug(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug, l5, l4);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a7_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a7_obj, 647u);
    _a7_obj->f_body = l1;
    _a7_obj->f_jump_table = l3;
    _a7_obj->f_debug = l5;
    t0 = (void*) _a7_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_run_bc_peephole(void* l0) {
    bool l1, l21, l24, l25, l26, l27;
    void* l2 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l29 = NULL;
    void* l35 = NULL;
    void* l38 = NULL;
    int64_t l3, l4, l5, l19, l22, l23, l28, l30, l31, l32, l34, l36;
    vader_box_t l10 = vader_box_null(), l20 = vader_box_null(), l33 = vader_box_null(), l37 = vader_box_null();
    int32_t l11, l12, l13, l14, l15, l16, l39;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t t3 = vader_box_null(), t4 = vader_box_null();
    bool t5;
    vader_box_t* gc_roots[6] = { &l10, &l20, &l33, &l37, &t3, &t4 };
    void** gc_raw_roots[12] = { &l0, &l2, &l6, &l7, &l8, &l9, &l17, &l18, &l29, &l35, &l38, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 12u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_bc_result_arity(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature);
    l1 = (t0 > INT64_C(1));
    l2 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l3 = ((vader_array_t*) l2)->length;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    l4 = vader_chk_add(i64, l4, l5);
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 290u);
    l6 = (void*) _a0_arr;
    if ((INT64_C(0) < l4)) {
        l5 = l4;
    } else {
        l5 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l6, (int64_t) l5);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 290u);
    l7 = (void*) _a2_arr;
    if ((INT64_C(0) < l4)) {
        l5 = l4;
    } else {
        l5 = INT64_C(0);
    }
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l7, (int64_t) l5);
    l7 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(15u, 0u, 7u, 290u);
    l8 = (void*) _a4_arr;
    if ((INT64_C(0) < l4)) {
        l5 = l4;
    } else {
        l5 = INT64_C(0);
    }
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) l8, (int64_t) l5);
    l8 = (void*) _a5_arr;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_push_i32((vader_array_t*) l6, INT32_C(0));
        vader_array_push_i32((vader_array_t*) l7, INT32_C(0));
        vader_array_push_i32((vader_array_t*) l8, INT32_C(0));
        l5 = (l5 + INT64_C(1));
    }
    l9 = l2;
    l4 = ((vader_array_t*) l9)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l10 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
        if (l10.tag == 760u) {
            t1 = l10.payload.obj;
            l11 = ((vader_struct_vader_bytecode_LocalSet_t*) t1)->f_slot;
            vader_array_t* _a7_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l11)
            t2 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l11];
            l12 = vader_chk_add(i32, t2, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l11)
            ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l11] = (int32_t) l12;
        }
        if (l10.tag == 759u) {
            t1 = l10.payload.obj;
            l13 = ((vader_struct_vader_bytecode_LocalGet_t*) t1)->f_slot;
            vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l13)
            t2 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l13];
            l14 = vader_chk_add(i32, t2, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l13)
            ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l13] = (int32_t) l14;
        }
        if (l10.tag == 761u) {
            t1 = l10.payload.obj;
            l15 = ((vader_struct_vader_bytecode_LocalTee_t*) t1)->f_slot;
            vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l15)
            t2 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l15];
            l16 = vader_chk_add(i32, t2, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l15)
            ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l15] = (int32_t) l16;
        }
        l5 = (l5 + INT64_C(1));
    }
    l9 = vader_bytecode_mark_jump_targets(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l3);
    vader_array_t* _a10_arr = vader_array_new(226u, 0u, 13u, 1538u);
    l17 = (void*) _a10_arr;
    l4 = INT64_C(0);
    vader_array_t* _a11_arr = vader_array_new(15u, 0u, 7u, 290u);
    l18 = (void*) _a11_arr;
    if ((INT64_C(0) < l3)) {
        l5 = l3;
    } else {
        l5 = INT64_C(0);
    }
    vader_array_t* _a12_arr = vader_array_repeat((vader_array_t*) l18, (int64_t) l5);
    l18 = (void*) _a12_arr;
    l5 = INT64_C(0);
    vader_array_t* _pc195_hdr = (vader_array_t*) l18;
    size_t _pc195_len = _pc195_hdr->length;
    size_t _pc195_cap = (_pc195_hdr->offset == 0 && !vader_array_is_borrowed(_pc195_hdr) && _pc195_hdr->length >= _pc195_hdr->buf->length) ? _pc195_hdr->capacity : (size_t) 0;
    void* _pc195_slots = _pc195_hdr->buf->slots;
    for (;;) {
        if ((l5 < l3)) {
            if (VADER_LIKELY(_pc195_len < _pc195_cap)) {
                ((int32_t*) _pc195_slots)[_pc195_len] = (int32_t) (INT32_C(-1));
                _pc195_len += 1;
            } else {
                _pc195_hdr->length = _pc195_len;
                if (_pc195_hdr->buf->length < _pc195_len) {
                    _pc195_hdr->buf->length = _pc195_len;
                }
                vader_array_push_i32((vader_array_t*) l18, INT32_C(-1));
                _pc195_hdr = (vader_array_t*) l18;
                _pc195_len = _pc195_hdr->length;
                _pc195_cap = (_pc195_hdr->offset == 0 && !vader_array_is_borrowed(_pc195_hdr) && _pc195_hdr->length >= _pc195_hdr->buf->length) ? _pc195_hdr->capacity : (size_t) 0;
                _pc195_slots = _pc195_hdr->buf->slots;
            }
            l5 = (l5 + INT64_C(1));
            continue;
        }
        _pc195_hdr->length = _pc195_len;
        if (_pc195_hdr->buf->length < _pc195_len) {
            _pc195_hdr->buf->length = _pc195_len;
        }
        break;
    }
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        l10 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l5);
        if (l10.tag == 760u) {
            t0 = vader_chk_add(i64, l5, INT64_C(1));
            if ((t0 < l3)) {
                l19 = vader_chk_add(i64, l5, INT64_C(1));
                vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l19)
                l20 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l19);
                if (l20.tag == 759u) {
                    t1 = l20.payload.obj;
                    l11 = ((vader_struct_vader_bytecode_LocalGet_t*) t1)->f_slot;
                    t1 = l10.payload.obj;
                    l12 = ((vader_struct_vader_bytecode_LocalSet_t*) t1)->f_slot;
                    if (l11 == l12) {
                        l21 = false;
                        if ((l4 > INT64_C(0))) {
                            l22 = vader_chk_sub(i64, l4, INT64_C(1));
                            vader_array_t* _a15_slotarr = ((vader_array_t*) l17);
                            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l22)
                            t3 = vader_array_ref_load_box(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l22);
                            t4 = vader_bytecode_const_op_of(t3);
                            if (!(t4.tag == 0u)) {
                                l21 = true;
                            }
                        }
                        t1 = l10.payload.obj;
                        t2 = ((vader_struct_vader_bytecode_LocalSet_t*) t1)->f_slot;
                        l23 = ((int64_t) (int32_t) t2);
                        vader_array_t* _a16_slotarr = ((vader_array_t*) l6);
                        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l23)
                        t2 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l23];
                        if (t2 == INT32_C(1)) {
                            vader_array_t* _a17_slotarr = ((vader_array_t*) l7);
                            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l23)
                            t2 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l23];
                            l25 = t2 == INT32_C(1);
                        } else {
                            l25 = false;
                        }
                        if (l25) {
                            vader_array_t* _a18_slotarr = ((vader_array_t*) l8);
                            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l23)
                            t2 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l23];
                            l24 = t2 == INT32_C(0);
                        } else {
                            l24 = false;
                        }
                        if (l21) {
                            l27 = l24;
                        } else {
                            l27 = false;
                        }
                        if (l27) {
                            l26 = true;
                        } else {
                            l28 = vader_chk_add(i64, l5, INT64_C(1));
                            vader_array_t* _a19_slotarr = ((vader_array_t*) l9);
                            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l28)
                            t3 = vader_box_bool(285u, ((uint8_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l28]);
                            l26 = t3.payload.b;
                        }
                        if (!(l26)) {
                            t1 = l10.payload.obj;
                            t2 = ((vader_struct_vader_bytecode_LocalSet_t*) t1)->f_slot;
                            vader_struct_vader_bytecode_LocalTee_t* _a20_obj = (vader_struct_vader_bytecode_LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalTee_t));
                            vader_obj_header_init(_a20_obj, 761u);
                            _a20_obj->f_slot = t2;
                            l29 = (void*) _a20_obj;
                            vader_bytecode_push_or_assign(l17, l4, vader_ref_box(l29));
                            l13 = ((int32_t) (int64_t) l4);
                            vader_array_t* _a21_slotarr = ((vader_array_t*) l18);
                            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l5)
                            ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l5] = (int32_t) l13;
                            l30 = vader_chk_add(i64, l5, INT64_C(1));
                            l14 = ((int32_t) (int64_t) l4);
                            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l30)
                            ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l30] = (int32_t) l14;
                            l4 = vader_chk_add(i64, l4, INT64_C(1));
                            l5 = vader_chk_add(i64, l5, INT64_C(2));
                            continue;
                        }
                    }
                }
            }
        }
        if (l10.tag == 771u) {
            if (!(l1)) {
                l31 = ((vader_array_t*) l17)->length;
                if ((l31 > INT64_C(0))) {
                    l32 = vader_chk_sub(i64, l31, INT64_C(1));
                    vader_array_t* _a22_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
                    t3 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l32);
                    l33 = vader_bytecode_const_op_of(t3);
                    if (!(l33.tag == 0u)) {
                        l34 = vader_chk_sub(i64, l31, INT64_C(1));
                        vader_struct_vader_bytecode_ReturnLit_t* _a23_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                        vader_obj_header_init(_a23_obj, 772u);
                        _a23_obj->f_value = l33;
                        l35 = (void*) _a23_obj;
                        vader_array_t* _a24_slotarr = ((vader_array_t*) l17);
                        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
                        vader_array_ref_store(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l34, l35);
                        VADER_WRITE_BARRIER(_a24_slotarr->buf);
                        t0 = vader_chk_sub(i64, l4, INT64_C(1));
                        l15 = ((int32_t) (int64_t) t0);
                        vader_array_t* _a25_slotarr = ((vader_array_t*) l18);
                        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l5)
                        ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l5] = (int32_t) l15;
                        l5 = vader_chk_add(i64, l5, INT64_C(1));
                        continue;
                    }
                }
            }
        }
        if (l10.tag == 666u) {
            if ((l4 > INT64_C(0))) {
                l36 = vader_chk_sub(i64, l4, INT64_C(1));
                vader_array_t* _a26_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l36)
                l37 = vader_array_ref_load_box(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l36);
                if (l37.tag == 666u) {
                    vader_array_t* _a27_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l5)
                    ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l5] = (int32_t) INT32_C(-1);
                    l4 = vader_chk_sub(i64, l4, INT64_C(1));
                    l5 = vader_chk_add(i64, l5, INT64_C(1));
                    continue;
                }
                if (l37.tag == 663u) {
                    t1 = l37.payload.obj;
                    t5 = ((vader_struct_vader_bytecode_BoolConst_t*) t1)->f_value;
                    vader_struct_vader_bytecode_BoolConst_t* _a28_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                    vader_obj_header_init(_a28_obj, 663u);
                    _a28_obj->f_value = !(t5);
                    l38 = (void*) _a28_obj;
                    vader_array_t* _a29_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l36)
                    vader_array_ref_store(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l36, l38);
                    VADER_WRITE_BARRIER(_a29_slotarr->buf);
                    l16 = ((int32_t) (int64_t) l36);
                    vader_array_t* _a30_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l5)
                    ((int32_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l5] = (int32_t) l16;
                    l5 = vader_chk_add(i64, l5, INT64_C(1));
                    continue;
                }
            }
        }
        vader_bytecode_push_or_assign(l17, l4, l10);
        l39 = ((int32_t) (int64_t) l4);
        vader_array_t* _a31_slotarr = ((vader_array_t*) l18);
        VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l5)
        ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l5] = (int32_t) l39;
        l4 = vader_chk_add(i64, l4, INT64_C(1));
        l5 = vader_chk_add(i64, l5, INT64_C(1));
    }
    vader_array_t* _a32_arr = vader_array_slice((vader_array_t*) l17, (int64_t) INT64_C(0), (int64_t) l4);
    l2 = (void*) _a32_arr;
    l6 = vader_bytecode_remap_jump_table(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l18, l4);
    l7 = vader_bytecode_remap_debug(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug, l18, l4);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a33_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a33_obj, 647u);
    _a33_obj->f_body = l2;
    _a33_obj->f_jump_table = l6;
    _a33_obj->f_debug = l7;
    t1 = (void*) _a33_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_run_bc_return_lit_fold(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l12 = NULL;
    int64_t l2, l4, l6, l8, l9, l11;
    vader_box_t l7 = vader_box_null(), l10 = vader_box_null();
    int32_t l13, l14;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l7, &l10, &t2 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l5, &l12, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_bc_result_arity(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature);
    if ((t0 > INT64_C(1))) {
        t1 = vader_bytecode_bc_peephole_unchanged(l0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l2 = ((vader_array_t*) l1)->length;
    vader_array_t* _a0_arr = vader_array_new(226u, 0u, 13u, 1538u);
    l3 = (void*) _a0_arr;
    l4 = INT64_C(0);
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 7u, 290u);
    l5 = (void*) _a1_arr;
    if ((INT64_C(0) < l2)) {
        l6 = l2;
    } else {
        l6 = INT64_C(0);
    }
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
    l5 = (void*) _a2_arr;
    l6 = INT64_C(0);
    vader_array_t* _pc35_hdr = (vader_array_t*) l5;
    size_t _pc35_len = _pc35_hdr->length;
    size_t _pc35_cap = (_pc35_hdr->offset == 0 && !vader_array_is_borrowed(_pc35_hdr) && _pc35_hdr->length >= _pc35_hdr->buf->length) ? _pc35_hdr->capacity : (size_t) 0;
    void* _pc35_slots = _pc35_hdr->buf->slots;
    for (;;) {
        if ((l6 < l2)) {
            if (VADER_LIKELY(_pc35_len < _pc35_cap)) {
                ((int32_t*) _pc35_slots)[_pc35_len] = (int32_t) (INT32_C(-1));
                _pc35_len += 1;
            } else {
                _pc35_hdr->length = _pc35_len;
                if (_pc35_hdr->buf->length < _pc35_len) {
                    _pc35_hdr->buf->length = _pc35_len;
                }
                vader_array_push_i32((vader_array_t*) l5, INT32_C(-1));
                _pc35_hdr = (vader_array_t*) l5;
                _pc35_len = _pc35_hdr->length;
                _pc35_cap = (_pc35_hdr->offset == 0 && !vader_array_is_borrowed(_pc35_hdr) && _pc35_hdr->length >= _pc35_hdr->buf->length) ? _pc35_hdr->capacity : (size_t) 0;
                _pc35_slots = _pc35_hdr->buf->slots;
            }
            l6 = (l6 + INT64_C(1));
            continue;
        }
        _pc35_hdr->length = _pc35_len;
        if (_pc35_hdr->buf->length < _pc35_len) {
            _pc35_hdr->buf->length = _pc35_len;
        }
        break;
    }
    l6 = INT64_C(0);
    while ((l6 < l2)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        if (l7.tag == 771u) {
            l8 = ((vader_array_t*) l3)->length;
            if ((l8 > INT64_C(0))) {
                l9 = vader_chk_sub(i64, l8, INT64_C(1));
                vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l9);
                l10 = vader_bytecode_const_op_of(t2);
                if (!(l10.tag == 0u)) {
                    l11 = vader_chk_sub(i64, l8, INT64_C(1));
                    vader_struct_vader_bytecode_ReturnLit_t* _a5_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                    vader_obj_header_init(_a5_obj, 772u);
                    _a5_obj->f_value = l10;
                    l12 = (void*) _a5_obj;
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                    vader_array_ref_store(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l11, l12);
                    VADER_WRITE_BARRIER(_a6_slotarr->buf);
                    t0 = vader_chk_sub(i64, l8, INT64_C(1));
                    l13 = ((int32_t) (int64_t) t0);
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l6)
                    ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l6] = (int32_t) l13;
                    l6 = vader_chk_add(i64, l6, INT64_C(1));
                    continue;
                }
            }
        }
        vader_bytecode_push_or_assign(l3, l4, l7);
        l14 = ((int32_t) (int64_t) l4);
        vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l6)
        ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l6] = (int32_t) l14;
        l4 = vader_chk_add(i64, l4, INT64_C(1));
        l6 = vader_chk_add(i64, l6, INT64_C(1));
    }
    vader_array_t* _a9_arr = vader_array_slice((vader_array_t*) l3, (int64_t) INT64_C(0), (int64_t) l4);
    l1 = (void*) _a9_arr;
    l3 = vader_bytecode_remap_jump_table(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l5, l4);
    l5 = vader_bytecode_remap_debug(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug, l5, l4);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a10_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a10_obj, 647u);
    _a10_obj->f_body = l1;
    _a10_obj->f_jump_table = l3;
    _a10_obj->f_debug = l5;
    t1 = (void*) _a10_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_bytecode_same_argument_class(vader_box_t l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    bool l4;
    void* l5 = NULL;
    void* l6 = NULL;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l1, &l2, &l3 };
    void** gc_raw_roots[3] = { &l5, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_types_strip_distinct(l0);
    l3 = vader_types_strip_distinct(l1);
    if (l2.tag == 1262u) {
        l4 = true;
    } else {
        l4 = l3.tag == 1262u;
    }
    if (!(l4)) {
        t0 = vader_bytecode_same_intern_class(l0, l1);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 1262u) {
        l4 = l3.tag == 1262u;
    } else {
        l4 = false;
    }
    if (l4) {
        t1 = l2.payload.obj;
        l5 = ((vader_struct_vader_types_EnumType_t*) t1)->f_symbol;
        t1 = l3.payload.obj;
        l6 = ((vader_struct_vader_types_EnumType_t*) t1)->f_symbol;
        t0 = vader_bytecode_same_symbol_class(l5, l6);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_bytecode_same_argument_list(void* l0, void* l1) {
    int64_t l2, l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) l0)->length;
    l3 = ((vader_array_t*) l1)->length;
    if (l2 != l3) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        t0 = vader_bytecode_same_argument_class(l4, l5);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l2 = (l2 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return true; }
}

static bool vader_bytecode_same_class_list(void* l0, void* l1) {
    int64_t l2, l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) l0)->length;
    l3 = ((vader_array_t*) l1)->length;
    if (l2 != l3) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        t0 = vader_bytecode_same_intern_class(l4, l5);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l2 = (l2 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return true; }
}

static bool vader_bytecode_same_intern_class(vader_box_t l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    void* l5 = NULL;
    bool l6;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[4] = { &l0, &l1, &l2, &l3 };
    void** gc_raw_roots[3] = { &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l7, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1261u) {
        t0 = l0.payload.obj;
        t1 = vader_bytecode_same_intern_class(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1261u) {
        l2 = l0;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_types_DistinctType_t*) t0)->f_backing;
        t1 = vader_bytecode_same_intern_class(l2, l3);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1271u) {
        if (l1.tag == 1271u) {
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_types_RangeType_t*) t0)->f_bounds;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_types_RangeType_t*) t0)->f_bounds;
            t1 = vader_integer_same_interval(l4, l5);
            if (t1) {
                { vader_gc_top = gc_frame.prev; return true; }
            }
        }
    }
    if ((l0.tag == 1262u || l0.tag == 1270u || l0.tag == 1271u)) {
        l6 = true;
    } else {
        l6 = (l1.tag == 1262u || l1.tag == 1270u || l1.tag == 1271u);
    }
    if (l6) {
        l7 = vader_bytecode_bare_intern_name(l0);
        if (l7 != 0u) {
            l8 = vader_bytecode_bare_intern_name(l1);
            { bool __vret = l7 == l8; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 1273u) {
        if (l1.tag == 1273u) {
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_types_StructType_t*) t0)->f_symbol;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_types_StructType_t*) t0)->f_symbol;
            l6 = vader_bytecode_same_symbol_class(l4, l5);
        } else {
            l6 = false;
        }
        if (l6) {
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
            t1 = vader_bytecode_same_argument_list(l4, l5);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 1274u) {
        if (l1.tag == 1274u) {
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol;
            l6 = vader_bytecode_same_symbol_class(l4, l5);
        } else {
            l6 = false;
        }
        if (l6) {
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
            t1 = vader_bytecode_same_argument_list(l4, l5);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 1260u) {
        if (l1.tag == 1260u) {
            t0 = l0.payload.obj;
            l2 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_element;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_element;
            t1 = vader_bytecode_same_intern_class(l2, l3);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 1278u) {
        if (l1.tag == 1278u) {
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
            t1 = vader_bytecode_same_class_list(l4, l5);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 1275u) {
        if (l1.tag == 1275u) {
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
            t1 = vader_bytecode_same_class_list(l4, l5);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (!(l0.tag == 1263u)) {
        l7 = vader_bytecode_bare_intern_name(l0);
        l8 = vader_bytecode_bare_intern_name(l1);
        { bool __vret = l7 == l8; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1263u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
        l6 = vader_bytecode_same_class_list(l4, l5);
    } else {
        l6 = false;
    }
    if (l6) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_types_FnType_t*) t0)->f_return_type;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_types_FnType_t*) t0)->f_return_type;
        t1 = vader_bytecode_same_intern_class(l2, l3);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_bytecode_same_symbol_class(void* l0, void* l1) {
    bool l2;
    vader_string_t l3, l4;
    int32_t l5, l6;
    vader_string_t t0;
    t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_module_name;
    if (t0 == 0u) {
        l2 = true;
    } else {
        t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_module_name;
        l2 = t0 == 0u;
    }
    if (l2) {
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_module_name;
        l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_module_name;
        if (l3 == l4) {
            l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
            l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_id;
            return l5 == l6;
        }
        return false;
    }
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_module_name;
    l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_module_name;
    if (l3 == l4) {
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_name;
        l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_name;
        return l3 == l4;
    }
    return false;
}

static vader_box_t vader_bytecode_shl_op(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Shl_t* _a0_obj = (vader_struct_vader_bytecode_I32Shl_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Shl_t));
        vader_obj_header_init(_a0_obj, 725u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Shl_t* _a1_obj = (vader_struct_vader_bytecode_I64Shl_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Shl_t));
    vader_obj_header_init(_a1_obj, 745u);
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_shr_op(uint8_t l0) {
    bool l1;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_is_unsigned_val(l0);
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        if (!(l1)) {
            vader_struct_vader_bytecode_I64Shr_t* _a0_obj = (vader_struct_vader_bytecode_I64Shr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Shr_t));
            vader_obj_header_init(_a0_obj, 746u);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_I64ShrU_t* _a1_obj = (vader_struct_vader_bytecode_I64ShrU_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64ShrU_t));
        vader_obj_header_init(_a1_obj, 747u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1)) {
        vader_struct_vader_bytecode_I32Shr_t* _a2_obj = (vader_struct_vader_bytecode_I32Shr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Shr_t));
        vader_obj_header_init(_a2_obj, 726u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32ShrU_t* _a3_obj = (vader_struct_vader_bytecode_I32ShrU_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32ShrU_t));
    vader_obj_header_init(_a3_obj, 727u);
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_bytecode_size_of_bc_type(vader_box_t l0) {
    int32_t l1;
    void* t0;
    if (l0.tag == 650u) {
        t0 = l0.payload.obj;
        l1 = vader_bytecode_size_of_val_type(((vader_struct_vader_bytecode_BcScalar_t*) t0)->f_val);
        return l1;
    }
    if ((l0.tag == 639u || l0.tag == 642u || l0.tag == 653u)) {
        l1 = ((int32_t) 8);
    } else {
        if (!((l0.tag == 649u || l0.tag == 654u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = ((int32_t) 16);
    }
    return l1;
}

int32_t vader_bytecode_size_of_val_type(uint8_t l0) {
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

vader_box_t vader_bytecode_slot_load_op_for(uint8_t l0, bool l1) {
    uint8_t l2;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_bytecode_slot_width_for(l0);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((uint8_t) l3.payload.i);
    if (l2 == INT32_C(1)) {
        vader_struct_vader_bytecode_LoadSlotI32_t* _a0_obj = (vader_struct_vader_bytecode_LoadSlotI32_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LoadSlotI32_t));
        vader_obj_header_init(_a0_obj, 755u);
        _a0_obj->f_bounds_safe = l1;
        t0 = (void*) _a0_obj;
        l3 = vader_ref_box(t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(2)) {
        vader_struct_vader_bytecode_LoadSlotI64_t* _a1_obj = (vader_struct_vader_bytecode_LoadSlotI64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LoadSlotI64_t));
        vader_obj_header_init(_a1_obj, 756u);
        _a1_obj->f_bounds_safe = l1;
        t0 = (void*) _a1_obj;
        l3 = vader_ref_box(t0);
    } else if (l2 == INT32_C(3)) {
        vader_struct_vader_bytecode_LoadSlotF64_t* _a2_obj = (vader_struct_vader_bytecode_LoadSlotF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LoadSlotF64_t));
        vader_obj_header_init(_a2_obj, 754u);
        _a2_obj->f_bounds_safe = l1;
        t0 = (void*) _a2_obj;
        l3 = vader_ref_box(t0);
    } else if (l2 == INT32_C(0)) {
        l3 = vader_box_obj(0u, NULL);
    } else {
        if (!(l2 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_bytecode_slot_store_op_for(uint8_t l0, bool l1) {
    uint8_t l2;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_bytecode_slot_width_for(l0);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((uint8_t) l3.payload.i);
    if (l2 == INT32_C(1)) {
        vader_struct_vader_bytecode_StoreSlotI32_t* _a0_obj = (vader_struct_vader_bytecode_StoreSlotI32_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StoreSlotI32_t));
        vader_obj_header_init(_a0_obj, 779u);
        _a0_obj->f_bounds_safe = l1;
        t0 = (void*) _a0_obj;
        l3 = vader_ref_box(t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(2)) {
        vader_struct_vader_bytecode_StoreSlotI64_t* _a1_obj = (vader_struct_vader_bytecode_StoreSlotI64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StoreSlotI64_t));
        vader_obj_header_init(_a1_obj, 780u);
        _a1_obj->f_bounds_safe = l1;
        t0 = (void*) _a1_obj;
        l3 = vader_ref_box(t0);
    } else if (l2 == INT32_C(3)) {
        vader_struct_vader_bytecode_StoreSlotF64_t* _a2_obj = (vader_struct_vader_bytecode_StoreSlotF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StoreSlotF64_t));
        vader_obj_header_init(_a2_obj, 778u);
        _a2_obj->f_bounds_safe = l1;
        t0 = (void*) _a2_obj;
        l3 = vader_ref_box(t0);
    } else if (l2 == INT32_C(0)) {
        l3 = vader_box_obj(0u, NULL);
    } else {
        if (!(l2 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_bytecode_slot_touched(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (l0.tag == 759u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalGet_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 760u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 761u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
        return t1;
    }
    if (!(l0.tag == 758u)) {
        return INT32_C(-1);
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_slot;
    return t1;
}

static vader_box_t vader_bytecode_slot_width_for(uint8_t l0) {
    vader_box_t l1;
    if (l0 == INT32_C(0)) {
        l1 = vader_box_i32(292u, INT32_C(0));
        return l1;
    }
    if (l0 == INT32_C(4)) {
        l1 = vader_box_i32(292u, INT32_C(0));
    } else if (l0 == INT32_C(10)) {
        l1 = vader_box_i32(292u, INT32_C(0));
    } else if (l0 == INT32_C(1)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(5)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(2)) {
        l1 = vader_box_i32(292u, INT32_C(1));
    } else if (l0 == INT32_C(6)) {
        l1 = vader_box_i32(292u, INT32_C(1));
    } else if (l0 == INT32_C(11)) {
        l1 = vader_box_i32(292u, INT32_C(1));
    } else if (l0 == INT32_C(8)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(3)) {
        l1 = vader_box_i32(292u, INT32_C(2));
    } else if (l0 == INT32_C(7)) {
        l1 = vader_box_i32(292u, INT32_C(2));
    } else if (l0 == INT32_C(9)) {
        l1 = vader_box_i32(292u, INT32_C(3));
    } else if (l0 == INT32_C(12)) {
        l1 = vader_box_i32(292u, INT32_C(4));
    } else if (l0 == INT32_C(13)) {
        l1 = vader_box_i32(292u, INT32_C(4));
    } else if (l0 == INT32_C(14)) {
        l1 = vader_box_i32(292u, INT32_C(4));
    } else if (l0 == INT32_C(15)) {
        l1 = vader_box_i32(292u, INT32_C(2));
    } else if (l0 == INT32_C(16)) {
        l1 = vader_box_i32(292u, INT32_C(4));
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_box_i32(292u, INT32_C(4));
    }
    return l1;
}

static vader_box_t vader_bytecode_strip_core_member(vader_string_t l0, vader_string_t l1) {
    int64_t l2, l3, l4;
    bool t0;
    vader_string_t t1;
    t0 = std_string_starts_with(l0, 2402u);
    if (t0) {
        t0 = std_string_ends_with(l0, l1);
        if (t0) {
            l2 = vader_host_std_core_byte_len(2402u);
            l3 = vader_host_std_core_byte_len(l0);
            l4 = vader_host_std_core_byte_len(l1);
            l3 = vader_chk_sub(i64, l3, l4);
            t1 = vader_host_std_core_byte_slice(l0, l2, l3);
            return vader_box_string(287u, t1);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

void* vader_bytecode_strip_self_copies(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t l2, l5, l9, l11;
    bool l4;
    vader_box_t l8 = vader_box_null();
    int32_t l10, l12;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l8, &t2 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l6, &l7, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l2 = ((vader_array_t*) l1)->length;
    l3 = vader_bytecode_mark_jump_targets(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l2);
    l4 = false;
    l5 = INT64_C(0);
    while ((l5 < l2)) {
        t0 = vader_bytecode_foldable_self_copy(l1, l5, l2, l3);
        if (t0) {
            l4 = true;
            break;
        }
        l5 = vader_chk_add(i64, l5, INT64_C(1));
    }
    if (!(l4)) {
        t1 = vader_bytecode_bc_peephole_unchanged(l0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(226u, 0u, 13u, 1538u);
    l6 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 1u, 7u, 290u);
    ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t1, (int64_t) l2);
    l7 = (void*) _a2_arr;
    l5 = INT64_C(0);
    while ((l5 < l2)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l8 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        t0 = vader_bytecode_foldable_self_copy(l1, l5, l2, l3);
        if (t0) {
            l9 = vader_chk_add(i64, l5, INT64_C(1));
            vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
            t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l9);
            if (t2.tag == 761u) {
                t3 = ((vader_array_t*) l6)->length;
                l10 = ((int32_t) (int64_t) t3);
                vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
                ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l10;
                vader_array_push((vader_array_t*) l6, l8);
            } else {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
                ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l5] = (int32_t) INT32_C(-1);
            }
            l11 = vader_chk_add(i64, l5, INT64_C(1));
            vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l11)
            ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l11] = (int32_t) INT32_C(-1);
            l5 = vader_chk_add(i64, l5, INT64_C(2));
            continue;
        }
        t3 = ((vader_array_t*) l6)->length;
        l12 = ((int32_t) (int64_t) t3);
        vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l5)
        ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l5] = (int32_t) l12;
        vader_array_push((vader_array_t*) l6, l8);
        l5 = vader_chk_add(i64, l5, INT64_C(1));
    }
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l2 = ((vader_array_t*) l6)->length;
    l1 = vader_bytecode_remap_jump_table(l1, l7, l2);
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug;
    l2 = ((vader_array_t*) l6)->length;
    l3 = vader_bytecode_remap_debug(l3, l7, l2);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a9_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a9_obj, 647u);
    _a9_obj->f_body = l6;
    _a9_obj->f_jump_table = l1;
    _a9_obj->f_debug = l3;
    t1 = (void*) _a9_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_bytecode_struct_symbol_type_index(void* l0, int32_t l1) {
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
        if (l4.tag == 653u) {
            t0 = l4.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_symbol_id;
            if (t1 == l1) {
                return ((int32_t) (int64_t) l2);
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    return INT32_C(-1);
}

int32_t vader_bytecode_struct_type_index(void* l0, vader_string_t l1) {
    int64_t l2, l3;
    vader_box_t l4;
    void* t0;
    vader_string_t t1;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 653u) {
            t0 = l4.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_name;
            if (t1 == l1) {
                return ((int32_t) (int64_t) l2);
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    return INT32_C(-1);
}

static uint64_t vader_bytecode_symbol_hash(void* l0) {
    uint64_t l1, l2, l3;
    vader_string_t t0;
    uint64_t t1;
    int32_t t2;
    int64_t t3;
    t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_module_name;
    if (!(t0 == 0u)) {
        t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_module_name;
        l1 = std_core_string_Hash_hash_vt(t0);
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, l1);
        t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_name;
        l3 = std_core_string_Hash_hash_vt(t0);
        t1 = vader_bytecode_mix64(l2, l3);
        return t1;
    }
    l1 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 101);
    t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    t3 = ((int64_t) (uint32_t) t2);
    l2 = (uint64_t) (int64_t) t3;
    t1 = vader_bytecode_mix64(l1, l2);
    return t1;
}

static vader_string_t vader_bytecode_symbol_key(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_string_t t0 = 0;
    int32_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[3] = { &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_module_name;
    if (!(t0 == 0u)) {
        l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_module_name;
        l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_name;
        t0 = concat_3(l4, 335u, l5);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) vader_buffer_new((size_t) INT64_C(22));
    l2 = INT64_C(0);
    l2 = std_core_write_string_at(l1, l2, 1947u);
    t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    l3 = ((int64_t) (int32_t) t1);
    l2 = std_core_write_int(l1, l2, l3);
    t0 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_try_fold_arith(vader_box_t l0, void* l1, int64_t l2) {
    int64_t l3, l8;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l11 = vader_box_null();
    int32_t l6, l7;
    uint8_t l9, l10;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    vader_box_t* gc_roots[4] = { &l0, &l4, &l5, &l11 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l2 < INT64_C(2))) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = vader_chk_sub(i64, l2, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    l3 = vader_chk_sub(i64, l2, INT64_C(2));
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l5.tag == 714u) {
        if (l4.tag == 714u) {
            if (l0.tag == 709u) {
                t0 = l5.payload.obj;
                l6 = ((vader_struct_vader_bytecode_I32Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l7 = ((vader_struct_vader_bytecode_I32Const_t*) t0)->f_value;
                vader_struct_vader_bytecode_I32Const_t* _a1_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
                vader_obj_header_init(_a1_obj, 714u);
                _a1_obj->f_value = (l6 + l7);
                t0 = (void*) _a1_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 728u) {
                t0 = l5.payload.obj;
                l6 = ((vader_struct_vader_bytecode_I32Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l7 = ((vader_struct_vader_bytecode_I32Const_t*) t0)->f_value;
                vader_struct_vader_bytecode_I32Const_t* _a2_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
                vader_obj_header_init(_a2_obj, 714u);
                _a2_obj->f_value = (l6 - l7);
                t0 = (void*) _a2_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 722u) {
                t0 = l5.payload.obj;
                l6 = ((vader_struct_vader_bytecode_I32Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l7 = ((vader_struct_vader_bytecode_I32Const_t*) t0)->f_value;
                vader_struct_vader_bytecode_I32Const_t* _a3_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
                vader_obj_header_init(_a3_obj, 714u);
                _a3_obj->f_value = (l6 * l7);
                t0 = (void*) _a3_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 679u) {
                t0 = l5.payload.obj;
                t1 = ((vader_struct_vader_bytecode_I32Const_t*) t0)->f_value;
                l3 = ((int64_t) (int32_t) t1);
                t0 = l4.payload.obj;
                t1 = ((vader_struct_vader_bytecode_I32Const_t*) t0)->f_value;
                l8 = ((int64_t) (int32_t) t1);
                t0 = l0.payload.obj;
                l9 = ((vader_struct_vader_bytecode_CheckedArith_t*) t0)->f_op;
                t0 = l0.payload.obj;
                l10 = ((vader_struct_vader_bytecode_CheckedArith_t*) t0)->f_kind;
                l11 = vader_bytecode_checked_arith(l9, l10, l3, l8);
                if (l11.tag == 0u) {
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                t2 = ((int64_t) l11.payload.i);
                vader_struct_vader_bytecode_I32Const_t* _a4_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
                vader_obj_header_init(_a4_obj, 714u);
                _a4_obj->f_value = ((int32_t) (int64_t) t2);
                t0 = (void*) _a4_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    if (l5.tag == 734u) {
        if (l4.tag == 734u) {
            if (l0.tag == 729u) {
                t0 = l5.payload.obj;
                l3 = ((vader_struct_vader_bytecode_I64Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l8 = ((vader_struct_vader_bytecode_I64Const_t*) t0)->f_value;
                vader_struct_vader_bytecode_I64Const_t* _a5_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                vader_obj_header_init(_a5_obj, 734u);
                _a5_obj->f_value = (l3 + l8);
                t0 = (void*) _a5_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 748u) {
                t0 = l5.payload.obj;
                l3 = ((vader_struct_vader_bytecode_I64Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l8 = ((vader_struct_vader_bytecode_I64Const_t*) t0)->f_value;
                vader_struct_vader_bytecode_I64Const_t* _a6_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                vader_obj_header_init(_a6_obj, 734u);
                _a6_obj->f_value = (l3 - l8);
                t0 = (void*) _a6_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 742u) {
                t0 = l5.payload.obj;
                l3 = ((vader_struct_vader_bytecode_I64Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l8 = ((vader_struct_vader_bytecode_I64Const_t*) t0)->f_value;
                vader_struct_vader_bytecode_I64Const_t* _a7_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                vader_obj_header_init(_a7_obj, 734u);
                _a7_obj->f_value = (l3 * l8);
                t0 = (void*) _a7_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 679u) {
                t0 = l0.payload.obj;
                l9 = ((vader_struct_vader_bytecode_CheckedArith_t*) t0)->f_op;
                t0 = l0.payload.obj;
                l10 = ((vader_struct_vader_bytecode_CheckedArith_t*) t0)->f_kind;
                t0 = l5.payload.obj;
                l3 = ((vader_struct_vader_bytecode_I64Const_t*) t0)->f_value;
                t0 = l4.payload.obj;
                l8 = ((vader_struct_vader_bytecode_I64Const_t*) t0)->f_value;
                l4 = vader_bytecode_checked_arith(l9, l10, l3, l8);
                if (l4.tag == 0u) {
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                t2 = ((int64_t) l4.payload.i);
                vader_struct_vader_bytecode_I64Const_t* _a8_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                vader_obj_header_init(_a8_obj, 734u);
                _a8_obj->f_value = t2;
                t0 = (void*) _a8_obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_string_t vader_bytecode_tuple_shape_name(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t l6 = 0;
    int64_t l3, l4;
    void* l5 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l6, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_type_key_join(l0, 857u);
    l2 = vader_bytecode_fnv1a_hex(l1);
    l1 = vader_bytecode_c_safe_key(l1);
    l3 = vader_host_std_core_byte_len(l1);
    l4 = vader_chk_sub(i64, INT64_C(32), INT64_C(1));
    if (!((l3 <= l4))) {
        l6 = l2;
        l3 = vader_host_std_core_byte_len(l6);
        l5 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l3));
        l3 = INT64_C(0);
        l4 = ((vader_array_t*) l0)->length;
        l3 = std_core_write_int(l5, l3, l4);
        l3 = std_core_write_string_at(l5, l3, 857u);
        l3 = std_core_write_string_at(l5, l3, l6);
        t0 = std_core_finish_buffer(l5, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_std_core_Range__i64_t* _a0_obj = (vader_struct_std_core_Range__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_core_Range__i64_t));
    vader_obj_header_init(_a0_obj, 527u);
    _a0_obj->f_start = INT64_C(0);
    _a0_obj->f_end = INT64_C(8);
    _a0_obj->f_inclusive = false;
    _a0_obj->f_done = false;
    _a0_obj->f_cursor = INT64_C(0);
    l5 = (void*) _a0_obj;
    l2 = std_core_string_Index_at_1(l2, l5);
    t0 = concat_3(l1, 857u, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint64_t vader_bytecode_type_args_hash(uint64_t l0, void* l1) {
    uint64_t l2, l6;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t t0 = vader_box_null();
    int64_t t1, t2;
    uint64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l6 = vader_bytecode_type_intern_hash(t0);
        l2 = vader_bytecode_mix64(l2, l6);
        l5 = (l5 + INT64_C(1));
    }
    t1 = ((vader_array_t*) l1)->length;
    t2 = t1;
    l6 = (uint64_t) (int64_t) t2;
    t3 = vader_bytecode_mix64(l2, l6);
    { uint64_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_bytecode_type_index_of(vader_box_t l0) {
    int32_t l1;
    void* t0;
    if (l0.tag == 787u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_type_id;
        return l1;
    }
    if (l0.tag == 786u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_type_id;
    } else if (l0.tag == 788u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_type_id;
    } else if (l0.tag == 803u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_UnionFieldGet_t*) t0)->f_type_id;
    } else if (l0.tag == 804u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_UnionFieldSet_t*) t0)->f_type_id;
    } else if (l0.tag == 631u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_type_id;
    } else if (l0.tag == 629u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_ArrayGet_t*) t0)->f_type_id;
    } else if (l0.tag == 636u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_ArraySet_t*) t0)->f_type_id;
    } else if (l0.tag == 632u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_type_id;
    } else if (l0.tag == 789u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_TypeCheck_t*) t0)->f_type_id;
    } else if (l0.tag == 790u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_TypeConst_t*) t0)->f_type_id;
    } else if (l0.tag == 677u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_CallIndirect_t*) t0)->f_type_id;
    } else if (l0.tag == 763u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_env_type_id;
    } else if (l0.tag == 706u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_type_id;
    } else if (l0.tag == 758u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_type_id;
    } else if (l0.tag == 637u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_ArraySlice_t*) t0)->f_type_id;
    } else if (l0.tag == 767u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_RefCast_t*) t0)->f_type_id;
    } else if (l0.tag == 770u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_Retag_t*) t0)->f_type_id;
    } else if (l0.tag == 682u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_type_id;
    } else {
        if (!((l0.tag == 627u || l0.tag == 628u || l0.tag == 630u || l0.tag == 633u || l0.tag == 634u || l0.tag == 635u || l0.tag == 659u || l0.tag == 660u || l0.tag == 661u || l0.tag == 662u || l0.tag == 663u || l0.tag == 664u || l0.tag == 665u || l0.tag == 666u || l0.tag == 667u || l0.tag == 668u || l0.tag == 669u || l0.tag == 670u || l0.tag == 671u || l0.tag == 672u || l0.tag == 675u || l0.tag == 676u || l0.tag == 678u || l0.tag == 679u || l0.tag == 680u || l0.tag == 681u || l0.tag == 684u || l0.tag == 685u || l0.tag == 686u || l0.tag == 687u || l0.tag == 690u || l0.tag == 691u || l0.tag == 692u || l0.tag == 693u || l0.tag == 694u || l0.tag == 695u || l0.tag == 696u || l0.tag == 697u || l0.tag == 698u || l0.tag == 699u || l0.tag == 700u || l0.tag == 701u || l0.tag == 702u || l0.tag == 703u || l0.tag == 704u || l0.tag == 705u || l0.tag == 707u || l0.tag == 708u || l0.tag == 709u || l0.tag == 710u || l0.tag == 711u || l0.tag == 712u || l0.tag == 713u || l0.tag == 714u || l0.tag == 715u || l0.tag == 716u || l0.tag == 717u || l0.tag == 718u || l0.tag == 719u || l0.tag == 720u || l0.tag == 721u || l0.tag == 722u || l0.tag == 723u || l0.tag == 724u || l0.tag == 725u || l0.tag == 726u || l0.tag == 727u || l0.tag == 728u || l0.tag == 729u || l0.tag == 730u || l0.tag == 731u || l0.tag == 732u || l0.tag == 733u || l0.tag == 734u || l0.tag == 735u || l0.tag == 736u || l0.tag == 737u || l0.tag == 738u || l0.tag == 739u || l0.tag == 740u || l0.tag == 741u || l0.tag == 742u || l0.tag == 743u || l0.tag == 744u || l0.tag == 745u || l0.tag == 746u || l0.tag == 747u || l0.tag == 748u || l0.tag == 749u || l0.tag == 751u || l0.tag == 752u || l0.tag == 753u || l0.tag == 754u || l0.tag == 755u || l0.tag == 756u || l0.tag == 757u || l0.tag == 759u || l0.tag == 760u || l0.tag == 761u || l0.tag == 762u || l0.tag == 764u || l0.tag == 765u || l0.tag == 768u || l0.tag == 769u || l0.tag == 771u || l0.tag == 772u || l0.tag == 773u || l0.tag == 775u || l0.tag == 776u || l0.tag == 777u || l0.tag == 778u || l0.tag == 779u || l0.tag == 780u || l0.tag == 781u || l0.tag == 782u || l0.tag == 783u || l0.tag == 784u || l0.tag == 785u || l0.tag == 791u || l0.tag == 792u || l0.tag == 793u || l0.tag == 794u || l0.tag == 795u || l0.tag == 796u || l0.tag == 797u || l0.tag == 798u || l0.tag == 799u || l0.tag == 800u || l0.tag == 801u || l0.tag == 802u || l0.tag == 805u || l0.tag == 806u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = INT32_C(-1);
    }
    return l1;
}

uint64_t vader_bytecode_type_intern_hash(vader_box_t l0) {
    uint64_t l1, l2, l3;
    void* l4 = NULL;
    void* t0 = NULL;
    void* t2 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l4, &t0, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1270u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        l1 = vader_bytecode_bare_hash(t1);
        { uint64_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1262u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_integer_MachineInteger_t*) ((vader_struct_vader_types_EnumType_t*) t0)->f_repr)->f_name;
        l1 = vader_bytecode_bare_hash(t1);
    } else if (l0.tag == 1259u) {
        l1 = vader_bytecode_bare_hash(474u);
    } else if ((l0.tag == 1264u || l0.tag == 1265u || l0.tag == 1266u || l0.tag == 1268u || l0.tag == 1272u || l0.tag == 1276u || l0.tag == 1277u || l0.tag == 1279u)) {
        t1 = vader_types_display_type(l0);
        l1 = vader_bytecode_bare_hash(t1);
    } else if (l0.tag == 1267u) {
        t0 = l0.payload.obj;
        vader_types_leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else if (l0.tag == 1261u) {
        t0 = l0.payload.obj;
        l1 = vader_bytecode_type_intern_hash(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 1271u) {
        t0 = l0.payload.obj;
        t2 = vader_types_storage_integer(t0);
        t1 = ((vader_struct_vader_integer_MachineInteger_t*) t2)->f_name;
        l1 = vader_bytecode_bare_hash(t1);
    } else if (l0.tag == 1273u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 1);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_symbol_hash(((vader_struct_vader_types_StructType_t*) t0)->f_symbol);
        l2 = vader_bytecode_mix64(l2, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
        l1 = vader_bytecode_argument_hashes(l2, l4);
    } else if (l0.tag == 1274u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 2);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_symbol_hash(((vader_struct_vader_types_TraitType_t*) t0)->f_symbol);
        l2 = vader_bytecode_mix64(l2, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
        l1 = vader_bytecode_argument_hashes(l2, l4);
    } else if (l0.tag == 1260u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 3);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_type_intern_hash(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        l1 = vader_bytecode_mix64(l2, l3);
    } else if (l0.tag == 1278u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 4);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        l1 = vader_bytecode_type_args_hash(l2, l4);
    } else if (l0.tag == 1275u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 5);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
        l1 = vader_bytecode_type_args_hash(l2, l4);
    } else {
        if (!(l0.tag == 1263u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 6);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
        l2 = vader_bytecode_type_args_hash(l2, l4);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_type_intern_hash(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
        l1 = vader_bytecode_mix64(l2, l3);
    }
    { uint64_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_bytecode_type_intern_key(vader_box_t l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &t0, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1270u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1273u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_symbol_key(((vader_struct_vader_types_StructType_t*) t0)->f_symbol);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_argument_keys(((vader_struct_vader_types_StructType_t*) t0)->f_args);
        l1 = concat_5(698u, l2, 433u, l3, 457u);
    } else if (l0.tag == 1274u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_symbol_key(((vader_struct_vader_types_TraitType_t*) t0)->f_symbol);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_argument_keys(((vader_struct_vader_types_TraitType_t*) t0)->f_args);
        l1 = concat_5(803u, l2, 433u, l3, 457u);
    } else if (l0.tag == 1262u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_integer_MachineInteger_t*) ((vader_struct_vader_types_EnumType_t*) t0)->f_repr)->f_name;
    } else if (l0.tag == 1261u) {
        t0 = l0.payload.obj;
        l1 = vader_bytecode_type_intern_key(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 1271u) {
        t0 = l0.payload.obj;
        t1 = vader_types_storage_integer(t0);
        l1 = ((vader_struct_vader_integer_MachineInteger_t*) t1)->f_name;
    } else if (l0.tag == 1260u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_type_intern_key(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        l1 = concat_3(476u, l2, 457u);
    } else if (l0.tag == 1278u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_type_key_join(((vader_struct_vader_types_UnionType_t*) t0)->f_variants, 2844u);
        l1 = concat_3(809u, l2, 457u);
    } else if (l0.tag == 1275u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_type_key_join(((vader_struct_vader_types_TupleType_t*) t0)->f_elements, 2844u);
        l1 = concat_3(805u, l2, 457u);
    } else if (l0.tag == 1263u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_type_key_join(((vader_struct_vader_types_FnType_t*) t0)->f_params, 303u);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_type_intern_key(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
        l1 = concat_4(544u, l2, 289u, l3);
    } else if (l0.tag == 1277u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1267u) {
        t0 = l0.payload.obj;
        vader_types_leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else if (l0.tag == 1276u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1272u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1279u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1266u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1264u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1265u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1268u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else {
        if (!(l0.tag == 1259u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 474u;
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_bytecode_type_key_join(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    int64_t l3, l4;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l5, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = 0u;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        if ((l3 > INT64_C(0))) {
            l5 = l1;
        } else {
            l5 = 0u;
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        l6 = vader_bytecode_type_intern_key(t0);
        l2 = concat_3(l2, l5, l6);
        l3 = (l3 + INT64_C(1));
    }
    { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_bytecode_unary_op_for(uint8_t l0, uint8_t l1) {
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        l2 = vader_bytecode_checked_neg_op(l1);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        vader_struct_vader_bytecode_BoolNot_t* _a0_obj = (vader_struct_vader_bytecode_BoolNot_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolNot_t));
        vader_obj_header_init(_a0_obj, 666u);
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_bytecode_bitnot_op(l1);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_bytecode_union_layout_struct(void* l0, int32_t l1) {
    vader_box_t l2;
    int32_t l3;
    void* t0;
    int64_t t1;
    vader_box_t t2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    if (l2.tag == 654u) {
        t0 = l2.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcUnion_t*) t0)->f_variants)->length;
        if (t1 == INT64_C(0)) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l2.payload.obj;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcUnion_t*) t0)->f_variants);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        l3 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) INT32_C(0)];
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
        if (!(t2.tag == 653u)) {
            return vader_box_obj(0u, NULL);
        }
        return vader_box_i32(290u, l3);
    }
    return vader_box_obj(0u, NULL);
}

vader_string_t vader_bytecode_val_type_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 1946u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1901u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1902u;
    } else if (l0 == INT32_C(3)) {
        l1 = 1924u;
    } else if (l0 == INT32_C(4)) {
        l1 = 2596u;
    } else if (l0 == INT32_C(5)) {
        l1 = 2575u;
    } else if (l0 == INT32_C(6)) {
        l1 = 2576u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2586u;
    } else if (l0 == INT32_C(8)) {
        l1 = 1775u;
    } else if (l0 == INT32_C(9)) {
        l1 = 1777u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1473u;
    } else if (l0 == INT32_C(11)) {
        l1 = 1581u;
    } else if (l0 == INT32_C(12)) {
        l1 = 2447u;
    } else if (l0 == INT32_C(13)) {
        l1 = 2227u;
    } else if (l0 == INT32_C(14)) {
        l1 = 2792u;
    } else if (l0 == INT32_C(15)) {
        l1 = 2282u;
    } else if (l0 == INT32_C(16)) {
        l1 = 2309u;
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1398u;
    }
    return l1;
}

static uint8_t vader_bytecode_val_type_of_primitive_name(vader_string_t l0) {
    vader_box_t l1;
    uint8_t t0;
    if (l0 == 510u) {
        return (uint8_t) 15;
    }
    l1 = vader_bytecode_parse_val_type(l0);
    if (l1.tag == 0u) {
        return (uint8_t) 17;
    }
    t0 = ((uint8_t) l1.payload.i);
    return t0;
}

uint8_t vader_bytecode_val_type_of_type(vader_box_t l0) {
    uint8_t l1;
    void* t0 = NULL;
    void* t2 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &t0, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1270u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        l1 = vader_bytecode_val_type_of_primitive_name(t1);
        { uint8_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1273u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 1262u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_integer_MachineInteger_t*) ((vader_struct_vader_types_EnumType_t*) t0)->f_repr)->f_name;
        l1 = vader_bytecode_val_type_of_primitive_name(t1);
    } else if (l0.tag == 1261u) {
        t0 = l0.payload.obj;
        l1 = vader_bytecode_val_type_of_type(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 1271u) {
        t0 = l0.payload.obj;
        t2 = vader_types_storage_integer(t0);
        t1 = ((vader_struct_vader_integer_MachineInteger_t*) t2)->f_name;
        l1 = vader_bytecode_val_type_of_primitive_name(t1);
    } else if (l0.tag == 1260u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 1263u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 1275u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 1274u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 1278u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 1277u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 1267u) {
        t0 = l0.payload.obj;
        vader_types_leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else if (l0.tag == 1276u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 1272u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 1259u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 1279u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 1266u) {
        l1 = (uint8_t) 2;
    } else if (l0.tag == 1264u) {
        l1 = (uint8_t) 11;
    } else if (l0.tag == 1265u) {
        l1 = (uint8_t) 9;
    } else {
        if (!(l0.tag == 1268u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = (uint8_t) 14;
    }
    { uint8_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_bytecode_value_cell(uint8_t l0, int64_t l1) {
    if (!(l0 == INT32_C(6))) {
        return l1;
    }
    return ((int64_t) (int32_t) ((int32_t) (int64_t) l1));
}

static void vader_bytecode_visit_type(int32_t l0, void* l1, void* l2) {
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    void* l6 = NULL;
    bool t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l1, &l2, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l0 < INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = std_collections_MutableSet_std_core_Contains_contains__i32(l2, l0);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((int64_t) (int32_t) l0);
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
    if ((l3 >= l4)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_collections_add__i32(l2, l0);
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l0)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l0);
    if (l5.tag == 653u) {
        t1 = l5.payload.obj;
        l6 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_fields;
        l3 = ((vader_array_t*) l6)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            t2 = ((vader_struct_vader_bytecode_BcField_t*) t1)->f_type_index;
            vader_bytecode_visit_type(t2, l1, l2);
            l4 = (l4 + INT64_C(1));
        }
    }
    if (l5.tag == 654u) {
        t1 = l5.payload.obj;
        l6 = ((vader_struct_vader_bytecode_BcUnion_t*) t1)->f_variants;
        l3 = ((vader_array_t*) l6)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
            vader_bytecode_visit_type(t2, l1, l2);
            l4 = (l4 + INT64_C(1));
        }
    }
    if (l5.tag == 639u) {
        t1 = l5.payload.obj;
        t2 = ((vader_struct_vader_bytecode_BcArray_t*) t1)->f_element;
        vader_bytecode_visit_type(t2, l1, l2);
    }
    if (l5.tag == 642u) {
        t1 = l5.payload.obj;
        l6 = ((vader_struct_vader_bytecode_BcFn_t*) t1)->f_params;
        l3 = ((vader_array_t*) l6)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
            vader_bytecode_visit_type(t2, l1, l2);
            l4 = (l4 + INT64_C(1));
        }
        t1 = l5.payload.obj;
        t2 = ((vader_struct_vader_bytecode_BcFn_t*) t1)->f_return_type;
        vader_bytecode_visit_type(t2, l1, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

vader_box_t vader_bytecode_with_remapped_slot(vader_box_t l0, int32_t l1) {
    int32_t l2, l3;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 759u) {
        vader_struct_vader_bytecode_LocalGet_t* _a0_obj = (vader_struct_vader_bytecode_LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalGet_t));
        vader_obj_header_init(_a0_obj, 759u);
        _a0_obj->f_slot = l1;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 760u) {
        vader_struct_vader_bytecode_LocalSet_t* _a1_obj = (vader_struct_vader_bytecode_LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalSet_t));
        vader_obj_header_init(_a1_obj, 760u);
        _a1_obj->f_slot = l1;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 761u) {
        vader_struct_vader_bytecode_LocalTee_t* _a2_obj = (vader_struct_vader_bytecode_LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalTee_t));
        vader_obj_header_init(_a2_obj, 761u);
        _a2_obj->f_slot = l1;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 758u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_type_id;
    t0 = l0.payload.obj;
    l3 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_field_index;
    vader_struct_vader_bytecode_LocalField_t* _a3_obj = (vader_struct_vader_bytecode_LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalField_t));
    vader_obj_header_init(_a3_obj, 758u);
    _a3_obj->f_slot = l1;
    _a3_obj->f_type_id = l2;
    _a3_obj->f_field_index = l3;
    t0 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_bytecode_write_op(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(213u, 0u, 13u, 1365u);
    l2 = (void*) _a0_arr;
    vader_bytecode_write_op_refs(l0, l2, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_bytecode_write_op_refs(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    vader_string_t l14 = 0;
    bool l7;
    uint64_t l8;
    int32_t l9, l11;
    vader_box_t l13 = vader_box_null();
    void* t0 = NULL;
    int32_t t1;
    double t2;
    uint32_t t3;
    int64_t t4;
    vader_string_t t5 = 0;
    bool t6;
    vader_box_t* gc_roots[2] = { &l2, &l13 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l10, &l12, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l14, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2.tag == 714u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(30));
        l4 = INT64_C(0);
        l4 = std_core_write_string_at(l3, l4, 1908u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_I32Const_t*) t0)->f_value;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core_write_int(l3, l4, l5);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 734u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(30));
        l4 = INT64_C(0);
        l4 = std_core_write_string_at(l3, l4, 1930u);
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_bytecode_I64Const_t*) t0)->f_value;
        l4 = std_core_write_int(l3, l4, l5);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 693u) {
        t0 = l2.payload.obj;
        t2 = ((vader_struct_vader_bytecode_F64Const_t*) t0)->f_value;
        l6 = vader_bytecode_f64_const_operands(t2);
        l6 = concat_2(1779u, l6);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 663u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(16));
        l4 = INT64_C(0);
        l4 = std_core_write_string_at(l3, l4, 1475u);
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_bytecode_BoolConst_t*) t0)->f_value;
        l4 = std_core_write_bool(l3, l4, l7);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 678u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(31));
        l4 = INT64_C(0);
        l4 = std_core_write_string_at(l3, l4, 1583u);
        t0 = l2.payload.obj;
        t3 = ((vader_struct_vader_bytecode_CharConst_t*) t0)->f_value;
        t4 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3));
        l8 = (uint64_t) (int64_t) t4;
        l4 = std_core_write_unsigned(l3, l4, l8);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 765u) {
        std_string_builder_append(l0, 2228u);
    } else if (l2.tag == 783u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_StringConst_t*) t0)->f_index;
        t0 = vader_bytecode_refer((uint8_t) 3, l9);
        vader_array_t* _a0_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0;
        l3 = (void*) _a0_arr;
        vader_bytecode_printed(l0, l1, 2451u, l3);
    } else if (l2.tag == 759u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_LocalGet_t*) t0)->f_slot;
        t0 = vader_bytecode_refer((uint8_t) 6, l9);
        vader_array_t* _a1_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
        l3 = (void*) _a1_arr;
        vader_bytecode_printed(l0, l1, 2096u, l3);
    } else if (l2.tag == 760u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
        t0 = vader_bytecode_refer((uint8_t) 6, l9);
        vader_array_t* _a2_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0;
        l3 = (void*) _a2_arr;
        vader_bytecode_printed(l0, l1, 2097u, l3);
    } else if (l2.tag == 761u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
        t0 = vader_bytecode_refer((uint8_t) 6, l9);
        vader_array_t* _a3_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = t0;
        l3 = (void*) _a3_arr;
        vader_bytecode_printed(l0, l1, 2098u, l3);
    } else if (l2.tag == 758u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_slot;
        l3 = vader_bytecode_refer((uint8_t) 6, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_type_id;
        l10 = vader_bytecode_refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_field_index;
        l12 = vader_bytecode_refer_field(l9, l11);
        vader_array_t* _a4_arr = vader_array_new(57u, 3u, 13u, 766u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 2u] = l12;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l10;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l3;
        l3 = (void*) _a4_arr;
        vader_bytecode_printed(l0, l1, 2095u, l3);
    } else if (l2.tag == 771u) {
        std_string_builder_append(l0, 2330u);
    } else if (l2.tag == 772u) {
        std_string_builder_append(l0, 2334u);
        vader_array_push((vader_array_t*) l1, vader_box_obj(0u, NULL));
        t0 = l2.payload.obj;
        l13 = ((vader_struct_vader_bytecode_ReturnLit_t*) t0)->f_value;
        vader_bytecode_write_op_refs(l0, l1, l13);
    } else if (l2.tag == 686u) {
        std_string_builder_append(l0, 1678u);
    } else if (l2.tag == 675u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_Call_t*) t0)->f_function_index;
        t0 = vader_bytecode_refer((uint8_t) 0, l9);
        vader_array_t* _a5_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = t0;
        l3 = (void*) _a5_arr;
        vader_bytecode_printed(l0, l1, 1549u, l3);
    } else if (l2.tag == 676u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_CallImport_t*) t0)->f_index;
        t0 = vader_bytecode_refer((uint8_t) 4, l9);
        vader_array_t* _a6_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = t0;
        l3 = (void*) _a6_arr;
        vader_bytecode_printed(l0, l1, 1551u, l3);
    } else if (l2.tag == 677u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_CallIndirect_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a7_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t0;
        l3 = (void*) _a7_arr;
        vader_bytecode_printed(l0, l1, 1552u, l3);
    } else if (l2.tag == 806u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_VirtualCall_t*) t0)->f_vtable_key;
        l4 = vader_host_std_core_byte_len(l6);
        l3 = (void*) vader_buffer_new((size_t) (INT64_C(34) + l4));
        l4 = INT64_C(0);
        l4 = std_core_write_string_at(l3, l4, 2790u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_VirtualCall_t*) t0)->f_parameter_count;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core_write_int(l3, l4, l5);
        l4 = std_core_write_string_at(l3, l4, 10u);
        l4 = std_core_write_string_at(l3, l4, l6);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 706u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_function_index;
        l3 = vader_bytecode_refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_type_id;
        l10 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a8_arr = vader_array_new(57u, 2u, 13u, 766u);
        ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 1u] = l10;
        ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = l3;
        l3 = (void*) _a8_arr;
        vader_bytecode_printed(l0, l1, 1837u, l3);
    } else if (l2.tag == 705u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_FnAddr_t*) t0)->f_function_index;
        t0 = vader_bytecode_refer((uint8_t) 0, l9);
        vader_array_t* _a9_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = t0;
        l3 = (void*) _a9_arr;
        vader_bytecode_printed(l0, l1, 1835u, l3);
    } else if (l2.tag == 679u) {
        t0 = l2.payload.obj;
        l6 = vader_bytecode_val_type_name(((vader_struct_vader_bytecode_CheckedArith_t*) t0)->f_kind);
        t0 = l2.payload.obj;
        l14 = vader_bytecode_checked_op_name(((vader_struct_vader_bytecode_CheckedArith_t*) t0)->f_op);
        l6 = concat_3(l6, 345u, l14);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 680u) {
        t0 = l2.payload.obj;
        t5 = vader_bytecode_val_type_name(((vader_struct_vader_bytecode_CheckedNeg_t*) t0)->f_kind);
        l6 = concat_2(t5, 346u);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 763u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_function_index;
        l3 = vader_bytecode_refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_env_type_id;
        l10 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a10_arr = vader_array_new(57u, 2u, 13u, 766u);
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 1u] = l10;
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = l3;
        l3 = (void*) _a10_arr;
        vader_bytecode_printed(l0, l1, 2115u, l3);
    } else if (l2.tag == 749u) {
        std_string_builder_append(l0, 1951u);
    } else if (l2.tag == 687u) {
        std_string_builder_append(l0, 1691u);
    } else if (l2.tag == 690u) {
        std_string_builder_append(l0, 1697u);
    } else if (l2.tag == 661u) {
        std_string_builder_append(l0, 1472u);
    } else if (l2.tag == 762u) {
        std_string_builder_append(l0, 2101u);
    } else if (l2.tag == 668u) {
        std_string_builder_append(l0, 1485u);
    } else if (l2.tag == 669u) {
        std_string_builder_append(l0, 1487u);
    } else if (l2.tag == 666u) {
        std_string_builder_append(l0, 1478u);
    } else if (l2.tag == 787u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_stack;
        if (t6) {
            l6 = 2469u;
        } else {
            l6 = 2466u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a11_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a11_arr->buf->slots)[_a11_arr->offset + 0u] = t0;
        l3 = (void*) _a11_arr;
        vader_bytecode_printed(l0, l1, l6, l3);
    } else if (l2.tag == 786u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_type_id;
        l3 = vader_bytecode_refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_field_index;
        l10 = vader_bytecode_refer_field(l9, l11);
        vader_array_t* _a12_arr = vader_array_new(57u, 2u, 13u, 766u);
        ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 1u] = l10;
        ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = l3;
        l3 = (void*) _a12_arr;
        vader_bytecode_printed(l0, l1, 2465u, l3);
    } else if (l2.tag == 788u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_stack;
        if (t6) {
            l6 = 2474u;
        } else {
            l6 = 2470u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_type_id;
        l3 = vader_bytecode_refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_field_index;
        l10 = vader_bytecode_refer_field(l9, l11);
        vader_array_t* _a13_arr = vader_array_new(57u, 2u, 13u, 766u);
        ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 1u] = l10;
        ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 0u] = l3;
        l3 = (void*) _a13_arr;
        vader_bytecode_printed(l0, l1, l6, l3);
    } else if (l2.tag == 803u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_UnionFieldGet_t*) t0)->f_type_id;
        l3 = vader_bytecode_refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_UnionFieldGet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_bytecode_UnionFieldGet_t*) t0)->f_field_index;
        l10 = vader_bytecode_refer_field(l9, l11);
        vader_array_t* _a14_arr = vader_array_new(57u, 2u, 13u, 766u);
        ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 1u] = l10;
        ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = l3;
        l3 = (void*) _a14_arr;
        vader_bytecode_printed(l0, l1, 2611u, l3);
    } else if (l2.tag == 804u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_UnionFieldSet_t*) t0)->f_type_id;
        l3 = vader_bytecode_refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_UnionFieldSet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_bytecode_UnionFieldSet_t*) t0)->f_field_index;
        l10 = vader_bytecode_refer_field(l9, l11);
        vader_array_t* _a15_arr = vader_array_new(57u, 2u, 13u, 766u);
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 1u] = l10;
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 0u] = l3;
        l3 = (void*) _a15_arr;
        vader_bytecode_printed(l0, l1, 2612u, l3);
    } else if (l2.tag == 631u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a16_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 0u] = t0;
        l3 = (void*) _a16_arr;
        vader_bytecode_printed(l0, l1, 1424u, l3);
        l3 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l4 = INT64_C(0);
        l4 = std_core_write_string_at(l3, l4, 10u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_length;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core_write_int(l3, l4, l5);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 630u) {
        std_string_builder_append(l0, 1423u);
    } else if (l2.tag == 632u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_cache_slot;
        if ((t1 >= INT32_C(0))) {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_type_id;
            l3 = vader_bytecode_refer((uint8_t) 1, l9);
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_cache_slot;
            l10 = vader_bytecode_refer((uint8_t) 6, l9);
            vader_array_t* _a17_arr = vader_array_new(57u, 2u, 13u, 766u);
            ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 1u] = l10;
            ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = l3;
            l3 = (void*) _a17_arr;
            vader_bytecode_printed(l0, l1, 1426u, l3);
        } else {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_type_id;
            t0 = vader_bytecode_refer((uint8_t) 1, l9);
            vader_array_t* _a18_arr = vader_array_new(57u, 1u, 13u, 766u);
            ((void**) _a18_arr->buf->slots)[_a18_arr->offset + 0u] = t0;
            l3 = (void*) _a18_arr;
            vader_bytecode_printed(l0, l1, 1426u, l3);
        }
    } else if (l2.tag == 629u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_ArrayGet_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a19_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 0u] = t0;
        l3 = (void*) _a19_arr;
        vader_bytecode_printed(l0, l1, 1422u, l3);
    } else if (l2.tag == 636u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_ArraySet_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a20_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a20_arr->buf->slots)[_a20_arr->offset + 0u] = t0;
        l3 = (void*) _a20_arr;
        vader_bytecode_printed(l0, l1, 1435u, l3);
    } else if (l2.tag == 637u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_ArraySlice_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a21_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 0u] = t0;
        l3 = (void*) _a21_arr;
        vader_bytecode_printed(l0, l1, 1436u, l3);
    } else if (l2.tag == 635u) {
        std_string_builder_append(l0, 1432u);
    } else if (l2.tag == 633u) {
        std_string_builder_append(l0, 1427u);
    } else if (l2.tag == 628u) {
        std_string_builder_append(l0, 1414u);
    } else if (l2.tag == 634u) {
        std_string_builder_append(l0, 1430u);
    } else if (l2.tag == 627u) {
        std_string_builder_append(l0, 1412u);
    } else if (l2.tag == 682u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_pool_index;
        l3 = vader_bytecode_refer((uint8_t) 5, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_type_id;
        l10 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a22_arr = vader_array_new(57u, 2u, 13u, 766u);
        ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 1u] = l10;
        ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = l3;
        l3 = (void*) _a22_arr;
        vader_bytecode_printed(l0, l1, 1645u, l3);
    } else if (l2.tag == 707u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_GlobalGet_t*) t0)->f_index;
        t0 = vader_bytecode_refer((uint8_t) 7, l9);
        vader_array_t* _a23_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a23_arr->buf->slots)[_a23_arr->offset + 0u] = t0;
        l3 = (void*) _a23_arr;
        vader_bytecode_printed(l0, l1, 1885u, l3);
    } else if (l2.tag == 708u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_GlobalSet_t*) t0)->f_index;
        t0 = vader_bytecode_refer((uint8_t) 7, l9);
        vader_array_t* _a24_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a24_arr->buf->slots)[_a24_arr->offset + 0u] = t0;
        l3 = (void*) _a24_arr;
        vader_bytecode_printed(l0, l1, 1886u, l3);
    } else if (l2.tag == 790u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_TypeConst_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a25_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a25_arr->buf->slots)[_a25_arr->offset + 0u] = t0;
        l3 = (void*) _a25_arr;
        vader_bytecode_printed(l0, l1, 2555u, l3);
    } else if (l2.tag == 789u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_TypeCheck_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a26_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a26_arr->buf->slots)[_a26_arr->offset + 0u] = t0;
        l3 = (void*) _a26_arr;
        vader_bytecode_printed(l0, l1, 2558u, l3);
    } else if (l2.tag == 767u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_RefCast_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a27_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a27_arr->buf->slots)[_a27_arr->offset + 0u] = t0;
        l3 = (void*) _a27_arr;
        vader_bytecode_printed(l0, l1, 2310u, l3);
    } else if (l2.tag == 770u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_Retag_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a28_arr = vader_array_new(57u, 1u, 13u, 766u);
        ((void**) _a28_arr->buf->slots)[_a28_arr->offset + 0u] = t0;
        l3 = (void*) _a28_arr;
        vader_bytecode_printed(l0, l1, 2329u, l3);
    } else if (l2.tag == 805u) {
        std_string_builder_append(l0, 2622u);
    } else if (l2.tag == 681u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_Convert_t*) t0)->f_from_name;
        t0 = l2.payload.obj;
        l14 = vader_bytecode_convert_target_name(((vader_struct_vader_bytecode_Convert_t*) t0)->f_target);
        l6 = concat_3(l6, 373u, l14);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 773u) {
        std_string_builder_append(l0, 2015u);
    } else if (l2.tag == 709u) {
        std_string_builder_append(l0, 1903u);
    } else if (l2.tag == 728u) {
        std_string_builder_append(l0, 1923u);
    } else if (l2.tag == 722u) {
        std_string_builder_append(l0, 1917u);
    } else if (l2.tag == 715u) {
        std_string_builder_append(l0, 1909u);
    } else if (l2.tag == 721u) {
        std_string_builder_append(l0, 1920u);
    } else if (l2.tag == 724u) {
        std_string_builder_append(l0, 1919u);
    } else if (l2.tag == 711u) {
        std_string_builder_append(l0, 1905u);
    } else if (l2.tag == 710u) {
        std_string_builder_append(l0, 1904u);
    } else if (l2.tag == 712u) {
        std_string_builder_append(l0, 1906u);
    } else if (l2.tag == 713u) {
        std_string_builder_append(l0, 1907u);
    } else if (l2.tag == 725u) {
        std_string_builder_append(l0, 1921u);
    } else if (l2.tag == 726u) {
        std_string_builder_append(l0, 1922u);
    } else if (l2.tag == 727u) {
        std_string_builder_append(l0, 2585u);
    } else if (l2.tag == 716u) {
        std_string_builder_append(l0, 1911u);
    } else if (l2.tag == 723u) {
        std_string_builder_append(l0, 1918u);
    } else if (l2.tag == 720u) {
        std_string_builder_append(l0, 1915u);
    } else if (l2.tag == 719u) {
        std_string_builder_append(l0, 1914u);
    } else if (l2.tag == 718u) {
        std_string_builder_append(l0, 1913u);
    } else if (l2.tag == 717u) {
        std_string_builder_append(l0, 1912u);
    } else if (l2.tag == 729u) {
        std_string_builder_append(l0, 1925u);
    } else if (l2.tag == 748u) {
        std_string_builder_append(l0, 1945u);
    } else if (l2.tag == 742u) {
        std_string_builder_append(l0, 1938u);
    } else if (l2.tag == 735u) {
        std_string_builder_append(l0, 1931u);
    } else if (l2.tag == 741u) {
        std_string_builder_append(l0, 1941u);
    } else if (l2.tag == 744u) {
        std_string_builder_append(l0, 1940u);
    } else if (l2.tag == 730u) {
        std_string_builder_append(l0, 1926u);
    } else if (l2.tag == 732u) {
        std_string_builder_append(l0, 1928u);
    } else if (l2.tag == 733u) {
        std_string_builder_append(l0, 1929u);
    } else if (l2.tag == 731u) {
        std_string_builder_append(l0, 1927u);
    } else if (l2.tag == 745u) {
        std_string_builder_append(l0, 1943u);
    } else if (l2.tag == 746u) {
        std_string_builder_append(l0, 1944u);
    } else if (l2.tag == 747u) {
        std_string_builder_append(l0, 2595u);
    } else if (l2.tag == 736u) {
        std_string_builder_append(l0, 1933u);
    } else if (l2.tag == 743u) {
        std_string_builder_append(l0, 1939u);
    } else if (l2.tag == 740u) {
        std_string_builder_append(l0, 1937u);
    } else if (l2.tag == 739u) {
        std_string_builder_append(l0, 1936u);
    } else if (l2.tag == 738u) {
        std_string_builder_append(l0, 1935u);
    } else if (l2.tag == 737u) {
        std_string_builder_append(l0, 1934u);
    } else if (l2.tag == 791u) {
        std_string_builder_append(l0, 2577u);
    } else if (l2.tag == 796u) {
        std_string_builder_append(l0, 2583u);
    } else if (l2.tag == 795u) {
        std_string_builder_append(l0, 2582u);
    } else if (l2.tag == 794u) {
        std_string_builder_append(l0, 2581u);
    } else if (l2.tag == 793u) {
        std_string_builder_append(l0, 2580u);
    } else if (l2.tag == 792u) {
        std_string_builder_append(l0, 2579u);
    } else if (l2.tag == 797u) {
        std_string_builder_append(l0, 2587u);
    } else if (l2.tag == 802u) {
        std_string_builder_append(l0, 2593u);
    } else if (l2.tag == 801u) {
        std_string_builder_append(l0, 2592u);
    } else if (l2.tag == 800u) {
        std_string_builder_append(l0, 2591u);
    } else if (l2.tag == 799u) {
        std_string_builder_append(l0, 2590u);
    } else if (l2.tag == 798u) {
        std_string_builder_append(l0, 2589u);
    } else if (l2.tag == 692u) {
        std_string_builder_append(l0, 1778u);
    } else if (l2.tag == 703u) {
        std_string_builder_append(l0, 1789u);
    } else if (l2.tag == 700u) {
        std_string_builder_append(l0, 1786u);
    } else if (l2.tag == 694u) {
        std_string_builder_append(l0, 1780u);
    } else if (l2.tag == 702u) {
        std_string_builder_append(l0, 1788u);
    } else if (l2.tag == 695u) {
        std_string_builder_append(l0, 1781u);
    } else if (l2.tag == 701u) {
        std_string_builder_append(l0, 1787u);
    } else if (l2.tag == 699u) {
        std_string_builder_append(l0, 1785u);
    } else if (l2.tag == 698u) {
        std_string_builder_append(l0, 1784u);
    } else if (l2.tag == 697u) {
        std_string_builder_append(l0, 1783u);
    } else if (l2.tag == 696u) {
        std_string_builder_append(l0, 1782u);
    } else if (l2.tag == 664u) {
        std_string_builder_append(l0, 1476u);
    } else if (l2.tag == 665u) {
        std_string_builder_append(l0, 1477u);
    } else if (l2.tag == 662u) {
        std_string_builder_append(l0, 1474u);
    } else if (l2.tag == 667u) {
        std_string_builder_append(l0, 1479u);
    } else if (l2.tag == 784u) {
        std_string_builder_append(l0, 2452u);
    } else if (l2.tag == 785u) {
        std_string_builder_append(l0, 2454u);
    } else if (l2.tag == 782u) {
        std_string_builder_append(l0, 2450u);
    } else if (l2.tag == 768u) {
        std_string_builder_append(l0, 2311u);
    } else if (l2.tag == 769u) {
        std_string_builder_append(l0, 2312u);
    } else if (l2.tag == 685u) {
        std_string_builder_append(l0, 1662u);
    } else if (l2.tag == 684u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(35));
        l4 = INT64_C(0);
        l4 = std_core_write_string_at(l3, l4, 1660u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_DeferPopExec_t*) t0)->f_count;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core_write_int(l3, l4, l5);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 670u) {
        std_string_builder_append(l0, 1497u);
    } else if (l2.tag == 757u) {
        std_string_builder_append(l0, 2090u);
    } else if (l2.tag == 752u) {
        std_string_builder_append(l0, 2084u);
    } else if (l2.tag == 753u) {
        std_string_builder_append(l0, 2085u);
    } else if (l2.tag == 751u) {
        std_string_builder_append(l0, 2083u);
    } else if (l2.tag == 781u) {
        std_string_builder_append(l0, 2445u);
    } else if (l2.tag == 776u) {
        std_string_builder_append(l0, 2438u);
    } else if (l2.tag == 777u) {
        std_string_builder_append(l0, 2439u);
    } else if (l2.tag == 775u) {
        std_string_builder_append(l0, 2436u);
    } else if (l2.tag == 755u) {
        std_string_builder_append(l0, 2088u);
    } else if (l2.tag == 756u) {
        std_string_builder_append(l0, 2089u);
    } else if (l2.tag == 754u) {
        std_string_builder_append(l0, 2087u);
    } else if (l2.tag == 779u) {
        std_string_builder_append(l0, 2443u);
    } else if (l2.tag == 780u) {
        std_string_builder_append(l0, 2444u);
    } else if (l2.tag == 778u) {
        std_string_builder_append(l0, 2442u);
    } else if (l2.tag == 764u) {
        std_string_builder_append(l0, 2131u);
    } else if (l2.tag == 671u) {
        std_string_builder_append(l0, 1500u);
    } else if (l2.tag == 672u) {
        std_string_builder_append(l0, 1503u);
    } else if (l2.tag == 704u) {
        std_string_builder_append(l0, 1790u);
    } else if (l2.tag == 660u) {
        std_string_builder_append(l0, 1470u);
    } else if (l2.tag == 691u) {
        std_string_builder_append(l0, 1776u);
    } else {
        if (!(l2.tag == 659u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        std_string_builder_append(l0, 1469u);
    }
    { vader_gc_top = gc_frame.prev; return; }
}
