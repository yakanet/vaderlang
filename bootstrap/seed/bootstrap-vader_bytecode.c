#include "bootstrap.split.h"

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
static bool vader_bytecode_extend_into_loops(void* l0, void* l1, size_t l2, void* l3);
static vader_string_t vader_bytecode_f64_const_operands(double l0);
static void* vader_bytecode_find_loop_ranges(void* l0);
static vader_string_t vader_bytecode_fnv1a_hex(vader_string_t l0);
static bool vader_bytecode_foldable_self_copy(void* l0, size_t l1, size_t l2, void* l3);
static bool vader_bytecode_is_display_to_string(vader_string_t l0);
static bool vader_bytecode_is_int_equals(vader_string_t l0);
static bool vader_bytecode_is_ref_class(uint8_t l0);
static bool vader_bytecode_is_u32_class(uint8_t l0);
static bool vader_bytecode_is_u64_class(uint8_t l0);
static vader_string_t vader_bytecode_key_join(void* l0, void* l1, vader_string_t l2);
static uint64_t vader_bytecode_mix64(uint64_t l0, uint64_t l1);
static vader_box_t vader_bytecode_mod_op(uint8_t l0);
static vader_box_t vader_bytecode_neg_op(uint8_t l0);
static vader_box_t vader_bytecode_parse_val_type(vader_string_t l0);
static vader_box_t vader_bytecode_primitive_arith_op(vader_string_t l0);
static vader_box_t vader_bytecode_primitive_cmp_op(vader_string_t l0);
static void vader_bytecode_printed(void* l0, void* l1, vader_string_t l2, void* l3);
static void vader_bytecode_push_or_assign(void* l0, size_t l1, vader_box_t l2);
static void vader_bytecode_push_scope(void* l0, void* l1, size_t l2, vader_string_t l3, int32_t l4);
static bool vader_bytecode_ranges_overlap(void* l0, void* l1);
static void* vader_bytecode_refer(uint8_t l0, int32_t l1);
static void* vader_bytecode_refer_field(int32_t l0, int32_t l1);
static void* vader_bytecode_remap_debug(void* l0, void* l1, size_t l2);
static vader_box_t vader_bytecode_remap_push_cache_slot(vader_box_t l0, void* l1);
static void* vader_bytecode_remap_signature(void* l0, void* l1);
static vader_box_t vader_bytecode_remap_type_in_op(vader_box_t l0, void* l1);
static void* vader_bytecode_remap_type_indices(void* l0, void* l1);
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
static vader_box_t vader_bytecode_try_fold_arith(vader_box_t l0, void* l1, size_t l2);
static vader_string_t vader_bytecode_tuple_shape_name(void* l0);
static uint64_t vader_bytecode_type_args_hash(uint64_t l0, void* l1);
static int32_t vader_bytecode_type_index_of(vader_box_t l0);
static vader_string_t vader_bytecode_type_key_join(void* l0, vader_string_t l1);
static uint8_t vader_bytecode_val_type_of_primitive_name(vader_string_t l0);
static void vader_bytecode_visit_type(int32_t l0, void* l1, void* l2);
static void vader_bytecode_write_op_refs(void* l0, void* l1, vader_box_t l2);

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
        if (l1 == 1154u) {
            vader_struct_vader_bytecode_F64Add_t* _a0_obj = (vader_struct_vader_bytecode_F64Add_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Add_t));
            vader_obj_header_init(_a0_obj, 554u);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 2184u) {
            vader_struct_vader_bytecode_F64Sub_t* _a1_obj = (vader_struct_vader_bytecode_F64Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Sub_t));
            vader_obj_header_init(_a1_obj, 565u);
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l1 == 1910u)) {
            vader_struct_vader_bytecode_F64Div_t* _a2_obj = (vader_struct_vader_bytecode_F64Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Div_t));
            vader_obj_header_init(_a2_obj, 556u);
            t1 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_F64Mul_t* _a3_obj = (vader_struct_vader_bytecode_F64Mul_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Mul_t));
        vader_obj_header_init(_a3_obj, 562u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        if (l1 == 1154u) {
            vader_struct_vader_bytecode_I64Add_t* _a4_obj = (vader_struct_vader_bytecode_I64Add_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Add_t));
            vader_obj_header_init(_a4_obj, 589u);
            t1 = (void*) _a4_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 2184u) {
            vader_struct_vader_bytecode_I64Sub_t* _a5_obj = (vader_struct_vader_bytecode_I64Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Sub_t));
            vader_obj_header_init(_a5_obj, 608u);
            t1 = (void*) _a5_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l1 == 1910u)) {
            vader_struct_vader_bytecode_I64Div_t* _a6_obj = (vader_struct_vader_bytecode_I64Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Div_t));
            vader_obj_header_init(_a6_obj, 595u);
            t1 = (void*) _a6_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_I64Mul_t* _a7_obj = (vader_struct_vader_bytecode_I64Mul_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Mul_t));
        vader_obj_header_init(_a7_obj, 602u);
        t1 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 1154u) {
        vader_struct_vader_bytecode_I32Add_t* _a8_obj = (vader_struct_vader_bytecode_I32Add_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Add_t));
        vader_obj_header_init(_a8_obj, 569u);
        t1 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 2184u) {
        vader_struct_vader_bytecode_I32Sub_t* _a9_obj = (vader_struct_vader_bytecode_I32Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Sub_t));
        vader_obj_header_init(_a9_obj, 588u);
        t1 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1 == 1910u)) {
        vader_struct_vader_bytecode_I32Div_t* _a10_obj = (vader_struct_vader_bytecode_I32Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Div_t));
        vader_obj_header_init(_a10_obj, 575u);
        t1 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Mul_t* _a11_obj = (vader_struct_vader_bytecode_I32Mul_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Mul_t));
    vader_obj_header_init(_a11_obj, 582u);
    t1 = (void*) _a11_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

uint8_t vader_bytecode_array_kind_from_name(vader_string_t l0) {
    uint8_t l1;
    if (l0 == 2301u) {
        l1 = (uint8_t) 1;
        return l1;
    }
    if (l0 == 2280u) {
        l1 = (uint8_t) 2;
    } else if (l0 == 2281u) {
        l1 = (uint8_t) 3;
    } else if (l0 == 2291u) {
        l1 = (uint8_t) 4;
    } else if (l0 == 2344u) {
        l1 = (uint8_t) 4;
    } else if (l0 == 1706u) {
        l1 = (uint8_t) 5;
    } else if (l0 == 1661u) {
        l1 = (uint8_t) 6;
    } else if (l0 == 1662u) {
        l1 = (uint8_t) 7;
    } else if (l0 == 1684u) {
        l1 = (uint8_t) 8;
    } else if (l0 == 1785u) {
        l1 = (uint8_t) 8;
    } else if (l0 == 1544u) {
        l1 = (uint8_t) 9;
    } else if (l0 == 1546u) {
        l1 = (uint8_t) 10;
    } else if (l0 == 1359u) {
        l1 = (uint8_t) 11;
    } else if (l0 == 1252u) {
        l1 = (uint8_t) 12;
    } else if (l0 == 2021u) {
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
        l1 = 2301u;
        return l1;
    }
    if (l0 == INT32_C(5)) {
        l1 = 1706u;
    } else if (l0 == INT32_C(12)) {
        l1 = 1252u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2280u;
    } else if (l0 == INT32_C(6)) {
        l1 = 1661u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2281u;
    } else if (l0 == INT32_C(7)) {
        l1 = 1662u;
    } else if (l0 == INT32_C(9)) {
        l1 = 1544u;
    } else if (l0 == INT32_C(11)) {
        l1 = 1359u;
    } else if (l0 == INT32_C(4)) {
        l1 = 2291u;
    } else if (l0 == INT32_C(8)) {
        l1 = 1684u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1546u;
    } else if (l0 == INT32_C(13)) {
        l1 = 2021u;
    } else {
        if (!(l0 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1261u;
    }
    return l1;
}

uint8_t vader_bytecode_array_kind_of(vader_box_t l0, void* l1) {
    uint8_t l2;
    void* t0;
    bool t1;
    if (l0.tag == 513u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_array_kind_of_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val);
        return l2;
    }
    if (l0.tag == 517u) {
        l2 = (uint8_t) 13;
    } else if (l0.tag == 504u) {
        l2 = (uint8_t) 13;
    } else if (l0.tag == 507u) {
        l2 = (uint8_t) 13;
    } else if (l0.tag == 518u) {
        t0 = l0.payload.obj;
        t1 = vader_bytecode_is_ref_only_element(vader_ref_box(t0), l1);
        if (t1) {
            l2 = (uint8_t) 13;
        } else {
            l2 = (uint8_t) 0;
        }
    } else {
        if (!(l0.tag == 514u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = (uint8_t) 0;
    }
    return l2;
}

uint8_t vader_bytecode_array_kind_of_val(uint8_t l0) {
    uint8_t l1;
    if (l0 == INT32_C(5)) {
        l1 = (uint8_t) 1;
        return l1;
    }
    if (l0 == INT32_C(6)) {
        l1 = (uint8_t) 2;
    } else if (l0 == INT32_C(7)) {
        l1 = (uint8_t) 3;
    } else if (l0 == INT32_C(8)) {
        l1 = (uint8_t) 4;
    } else if (l0 == INT32_C(9)) {
        l1 = (uint8_t) 4;
    } else if (l0 == INT32_C(0)) {
        l1 = (uint8_t) 5;
    } else if (l0 == INT32_C(1)) {
        l1 = (uint8_t) 6;
    } else if (l0 == INT32_C(2)) {
        l1 = (uint8_t) 7;
    } else if (l0 == INT32_C(3)) {
        l1 = (uint8_t) 8;
    } else if (l0 == INT32_C(4)) {
        l1 = (uint8_t) 8;
    } else if (l0 == INT32_C(10)) {
        l1 = (uint8_t) 9;
    } else if (l0 == INT32_C(11)) {
        l1 = (uint8_t) 10;
    } else if (l0 == INT32_C(13)) {
        l1 = (uint8_t) 11;
    } else if (l0 == INT32_C(12)) {
        l1 = (uint8_t) 12;
    } else if (l0 == INT32_C(14)) {
        l1 = (uint8_t) 0;
    } else if (l0 == INT32_C(15)) {
        l1 = (uint8_t) 0;
    } else if (l0 == INT32_C(16)) {
        l1 = (uint8_t) 0;
    } else if (l0 == INT32_C(17)) {
        l1 = (uint8_t) 4;
    } else if (l0 == INT32_C(18)) {
        l1 = (uint8_t) 13;
    } else {
        if (!(l0 == INT32_C(19))) {
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
        t2 = concat_3(1299u, l0, 917u);
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
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1020u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1013u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
    } else if (l0.tag == 1010u) {
        l1 = 394u;
    } else if ((l0.tag == 1015u || l0.tag == 1016u || l0.tag == 1017u || l0.tag == 1018u || l0.tag == 1021u || l0.tag == 1025u || l0.tag == 1026u || l0.tag == 1028u)) {
        l1 = vader_types_display_type(l0);
    } else {
        if (!((l0.tag == 1011u || l0.tag == 1012u || l0.tag == 1014u || l0.tag == 1022u || l0.tag == 1023u || l0.tag == 1024u || l0.tag == 1027u))) {
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
    vader_obj_header_init(_a0_obj, 511u);
    _a0_obj->f_body = l1;
    _a0_obj->f_jump_table = l2;
    _a0_obj->f_debug = l3;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

size_t vader_bytecode_bc_result_arity(void* l0) {
    bool l1;
    size_t t0;
    vader_box_t t1;
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results)->length;
    if (t0 == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 229u);
        l1 = ((int32_t) t1.payload.i) == INT32_C(16);
    } else {
        l1 = false;
    }
    if (l1) {
        return (size_t) 0;
    }
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results)->length;
    return t0;
}

uint8_t vader_bytecode_bc_single_result(void* l0) {
    void* l1 = NULL;
    size_t l2;
    uint64_t l3;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 16; }
    }
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results)->length;
    if (!((t0 > INT64_C(1)))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 229u);
        { uint8_t __vret = ((uint8_t) t1.payload.i); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = std_core_new_byte_buffer((size_t) 127);
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l1, l2, 1302u);
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results)->length;
    t2 = ((int64_t) (size_t) t0);
    l3 = (uint64_t) (int64_t) t2;
    l2 = std_core_write_unsigned(l1, l2, l3);
    l2 = std_core_write_string_at(l1, l2, 118u);
    t3 = std_core_finish_buffer(l1, l2);
    vader_host_std_abort_panic(t3);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

int32_t vader_bytecode_bc_single_result_type(void* l0) {
    void* l1 = NULL;
    size_t l2;
    uint64_t l3;
    size_t t0;
    int32_t t1;
    int64_t t2;
    vader_string_t t3 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
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
    l1 = std_core_new_byte_buffer((size_t) 132);
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l1, l2, 1301u);
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_result_types)->length;
    t2 = ((int64_t) (size_t) t0);
    l3 = (uint64_t) (int64_t) t2;
    l2 = std_core_write_unsigned(l1, l2, l3);
    l2 = std_core_write_string_at(l1, l2, 118u);
    t3 = std_core_finish_buffer(l1, l2);
    vader_host_std_abort_panic(t3);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

vader_string_t vader_bytecode_bc_type_key(void* l0, int32_t l1) {
    bool l2;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    vader_string_t l7 = 0;
    vader_string_t l10 = 0;
    vader_string_t l12 = 0;
    void* l8 = NULL;
    int64_t l9;
    int32_t l11;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l5, &l6 };
    void** gc_raw_roots[3] = { &l0, &l8, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l10, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l1 < INT32_C(0))) {
        l2 = true;
    } else {
        t0 = ((int64_t) (int32_t) l1);
        l3 = (size_t) (int64_t) t0;
        l4 = ((vader_array_t*) l0)->length;
        l2 = (l3 >= l4);
    }
    if (l2) {
        { vader_gc_top = gc_frame.prev; return 379u; }
    }
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    l6 = l5;
    if (l5.tag == 513u) {
        l8 = std_core_new_byte_buffer((size_t) 22);
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l8, l3, 1977u);
        t1 = l6.payload.obj;
        l9 = ((int64_t) (int32_t) ((int32_t) (uint8_t) ((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val));
        l3 = std_core_write_int(l8, l3, l9);
        l7 = std_core_finish_buffer(l8, l3);
        { vader_string_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 517u) {
        t1 = l6.payload.obj;
        l10 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_name;
        l7 = concat_2(2053u, l10);
    } else if (l5.tag == 514u) {
        t1 = l6.payload.obj;
        l10 = ((vader_struct_vader_bytecode_BcRef_t*) t1)->f_trait_name;
        l7 = concat_2(2007u, l10);
    } else if (l5.tag == 504u) {
        t1 = l6.payload.obj;
        l11 = ((vader_struct_vader_bytecode_BcArray_t*) t1)->f_element;
        l10 = vader_bytecode_bc_type_key(l0, l11);
        l7 = concat_3(1151u, l10, 375u);
    } else if (l5.tag == 518u) {
        t1 = l6.payload.obj;
        l8 = ((vader_struct_vader_bytecode_BcUnion_t*) t1)->f_variants;
        l10 = vader_bytecode_key_join(l0, l8, 2530u);
        l7 = concat_3(2302u, l10, 375u);
    } else {
        if (!(l5.tag == 507u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t1 = l6.payload.obj;
        l8 = ((vader_struct_vader_bytecode_BcFn_t*) t1)->f_params;
        l10 = vader_bytecode_key_join(l0, l8, 2530u);
        t1 = l6.payload.obj;
        l11 = ((vader_struct_vader_bytecode_BcFn_t*) t1)->f_return_type;
        l12 = vader_bytecode_bc_type_key(l0, l11);
        l7 = concat_4(1560u, l10, 246u, l12);
    }
    { vader_string_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_bc_type_of_with_ctx(vader_box_t l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l11 = NULL;
    size_t l5, l6, l8;
    int32_t l7;
    uint64_t l9;
    vader_string_t l10 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    uint8_t t2;
    vader_box_t t3 = vader_box_null();
    int32_t t4;
    int64_t t5;
    vader_box_t* gc_roots[2] = { &l0, &t3 };
    void** gc_raw_roots[5] = { &l1, &l3, &l4, &l11, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l10, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1020u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        t2 = vader_bytecode_val_type_of_primitive_name(t1);
        vader_struct_vader_bytecode_BcPrimitive_t* _a0_obj = (vader_struct_vader_bytecode_BcPrimitive_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPrimitive_t));
        vader_obj_header_init(_a0_obj, 513u);
        _a0_obj->f_val = t2;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1013u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
        t2 = vader_bytecode_val_type_of_primitive_name(t1);
        vader_struct_vader_bytecode_BcPrimitive_t* _a1_obj = (vader_struct_vader_bytecode_BcPrimitive_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPrimitive_t));
        vader_obj_header_init(_a1_obj, 513u);
        _a1_obj->f_val = t2;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1012u) {
        t0 = l0.payload.obj;
        t3 = vader_bytecode_bc_type_of_with_ctx(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing, l1, l2);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1022u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_name;
        vader_struct_vader_bytecode_BcRef_t* _a2_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a2_obj, 514u);
        _a2_obj->f_trait_name = t1;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1023u) {
        t0 = l0.payload.obj;
        t1 = vader_types_trait_key_of(((vader_struct_vader_types_TraitType_t*) t0)->f_symbol);
        vader_struct_vader_bytecode_BcRef_t* _a3_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a3_obj, 514u);
        _a3_obj->f_trait_name = t1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1011u) {
        t0 = l0.payload.obj;
        t4 = vader_bytecode_intern_type(((vader_struct_vader_types_ArrayType_t*) t0)->f_element, l1);
        vader_struct_vader_bytecode_BcArray_t* _a4_obj = (vader_struct_vader_bytecode_BcArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcArray_t));
        vader_obj_header_init(_a4_obj, 504u);
        _a4_obj->f_element = t4;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1027u) {
        vader_array_t* _a5_arr = vader_array_new(9u, 0u, 7u, 226u);
        l3 = (void*) _a5_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        l5 = ((vader_array_t*) l4)->length;
        l6 = (size_t) 0;
        while ((l6 < l5)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
            t3 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
            l7 = vader_bytecode_intern_type(t3, l1);
            vader_array_push_i32((vader_array_t*) l3, l7);
            t5 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t5;
        }
        vader_struct_vader_bytecode_BcUnion_t* _a7_obj = (vader_struct_vader_bytecode_BcUnion_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcUnion_t));
        vader_obj_header_init(_a7_obj, 518u);
        _a7_obj->f_variants = l3;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1014u) {
        vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 226u);
        l3 = (void*) _a8_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
        l5 = ((vader_array_t*) l4)->length;
        l6 = (size_t) 0;
        while ((l6 < l5)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l6)
            t3 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l6);
            l7 = vader_bytecode_intern_type(t3, l1);
            vader_array_push_i32((vader_array_t*) l3, l7);
            t5 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t5;
        }
        t0 = l0.payload.obj;
        l7 = vader_bytecode_intern_type(((vader_struct_vader_types_FnType_t*) t0)->f_return_type, l1);
        vader_struct_vader_bytecode_BcFn_t* _a10_obj = (vader_struct_vader_bytecode_BcFn_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFn_t));
        vader_obj_header_init(_a10_obj, 507u);
        _a10_obj->f_params = l3;
        _a10_obj->f_return_type = l7;
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1024u) {
        vader_array_t* _a11_arr = vader_array_new(37u, 0u, 13u, 506u);
        l3 = (void*) _a11_arr;
        l5 = (size_t) 0;
        t0 = l0.payload.obj;
        l6 = ((vader_array_t*) ((vader_struct_vader_types_TupleType_t*) t0)->f_elements)->length;
        while ((l5 < l6)) {
            l4 = std_core_new_byte_buffer((size_t) 21);
            l8 = (size_t) 0;
            l8 = std_core_write_string_at(l4, l8, 767u);
            t5 = ((int64_t) (size_t) l5);
            l9 = (uint64_t) (int64_t) t5;
            l8 = std_core_write_unsigned(l4, l8, l9);
            l10 = std_core_finish_buffer(l4, l8);
            t0 = l0.payload.obj;
            vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_types_TupleType_t*) t0)->f_elements);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l5)
            t3 = vader_array_ref_load_box(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l5);
            l7 = vader_bytecode_intern_type(t3, l1);
            vader_struct_vader_bytecode_BcField_t* _a13_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
            vader_obj_header_init(_a13_obj, 506u);
            _a13_obj->f_name = l10;
            _a13_obj->f_type_index = l7;
            l11 = (void*) _a13_obj;
            vader_array_push((vader_array_t*) l3, vader_ref_box(l11));
            t5 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t5;
        }
        t0 = l0.payload.obj;
        l10 = vader_bytecode_tuple_shape_name(((vader_struct_vader_types_TupleType_t*) t0)->f_elements);
        l10 = concat_2(783u, l10);
        l7 = -(INT32_C(1));
        vader_struct_vader_bytecode_BcStruct_t* _a14_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
        vader_obj_header_init(_a14_obj, 517u);
        _a14_obj->f_name = l10;
        _a14_obj->f_fields = l3;
        _a14_obj->f_c_name = 0u;
        _a14_obj->f_symbol_id = l7;
        t0 = (void*) _a14_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1026u) {
        t0 = (void*) &vader_data_38;
        vader_array_t* _a15_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        t0 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1025u) {
        t0 = (void*) &vader_data_38;
        vader_array_t* _a16_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        t0 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1021u) {
        t0 = (void*) &vader_data_38;
        vader_array_t* _a17_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        t0 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1028u) {
        t0 = (void*) &vader_data_38;
        vader_array_t* _a18_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        t0 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1017u) {
        t0 = (void*) &vader_data_38;
        vader_array_t* _a19_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        t0 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1015u) {
        t0 = (void*) &vader_data_38;
        vader_array_t* _a20_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        t0 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1016u) {
        t0 = (void*) &vader_data_38;
        vader_array_t* _a21_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        t0 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1018u) {
        t0 = (void*) &vader_data_38;
        vader_array_t* _a22_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
        t0 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 1010u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = (void*) &vader_data_38;
    vader_array_t* _a23_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
    t0 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) INT64_C(0));
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_bytecode_binary_op_for(uint8_t l0, uint8_t l1) {
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        l2 = vader_bytecode_arith_op(l1, 1154u);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        l2 = vader_bytecode_arith_op(l1, 2184u);
    } else if (l0 == INT32_C(2)) {
        l2 = vader_bytecode_arith_op(l1, 1910u);
    } else if (l0 == INT32_C(3)) {
        l2 = vader_bytecode_div_op(l1);
    } else if (l0 == INT32_C(4)) {
        l2 = vader_bytecode_mod_op(l1);
    } else if (l0 == INT32_C(5)) {
        l2 = vader_bytecode_shl_op(l1);
    } else if (l0 == INT32_C(6)) {
        l2 = vader_bytecode_shr_op(l1);
    } else if (l0 == INT32_C(7)) {
        l2 = vader_bytecode_bit_op(l1, 1181u);
    } else if (l0 == INT32_C(8)) {
        l2 = vader_bytecode_bit_op(l1, 1968u);
    } else if (l0 == INT32_C(9)) {
        l2 = vader_bytecode_bit_op(l1, 2518u);
    } else if (l0 == INT32_C(10)) {
        vader_struct_vader_bytecode_BoolAnd_t* _a0_obj = (vader_struct_vader_bytecode_BoolAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolAnd_t));
        vader_obj_header_init(_a0_obj, 526u);
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(11)) {
        vader_struct_vader_bytecode_BoolOr_t* _a1_obj = (vader_struct_vader_bytecode_BoolOr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolOr_t));
        vader_obj_header_init(_a1_obj, 531u);
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
        if (l1 == 1181u) {
            vader_struct_vader_bytecode_I64BitAnd_t* _a0_obj = (vader_struct_vader_bytecode_I64BitAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitAnd_t));
            vader_obj_header_init(_a0_obj, 590u);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l1 == 1968u)) {
            vader_struct_vader_bytecode_I64BitXor_t* _a1_obj = (vader_struct_vader_bytecode_I64BitXor_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitXor_t));
            vader_obj_header_init(_a1_obj, 593u);
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_I64BitOr_t* _a2_obj = (vader_struct_vader_bytecode_I64BitOr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitOr_t));
        vader_obj_header_init(_a2_obj, 592u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 1181u) {
        vader_struct_vader_bytecode_I32BitAnd_t* _a3_obj = (vader_struct_vader_bytecode_I32BitAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitAnd_t));
        vader_obj_header_init(_a3_obj, 570u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1 == 1968u)) {
        vader_struct_vader_bytecode_I32BitXor_t* _a4_obj = (vader_struct_vader_bytecode_I32BitXor_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitXor_t));
        vader_obj_header_init(_a4_obj, 573u);
        t1 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32BitOr_t* _a5_obj = (vader_struct_vader_bytecode_I32BitOr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitOr_t));
    vader_obj_header_init(_a5_obj, 572u);
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
        vader_obj_header_init(_a0_obj, 571u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64BitNot_t* _a1_obj = (vader_struct_vader_bytecode_I64BitNot_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitNot_t));
    vader_obj_header_init(_a1_obj, 591u);
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_build_intrinsic_wrapper_body(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    size_t l3, l4;
    vader_box_t l6 = vader_box_null();
    int64_t t0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(169u, 0u, 13u, 1235u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_params)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_params)->length;
    while ((l3 < l4)) {
        vader_struct_vader_bytecode_LocalGet_t* _a2_obj = (vader_struct_vader_bytecode_LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalGet_t));
        vader_obj_header_init(_a2_obj, 619u);
        _a2_obj->f_slot = ((int32_t) (size_t) l3);
        l5 = (void*) _a2_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
    }
    t1 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
    l6 = vader_bytecode_intrinsic_op_for_mangled(t1);
    if (l6.tag == 0u) {
        vader_struct_vader_bytecode_CallImport_t* _a3_obj = (vader_struct_vader_bytecode_CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallImport_t));
        vader_obj_header_init(_a3_obj, 540u);
        _a3_obj->f_index = l1;
        l5 = (void*) _a3_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
        vader_struct_vader_bytecode_Return_t* _a4_obj = (vader_struct_vader_bytecode_Return_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Return_t));
        vader_obj_header_init(_a4_obj, 631u);
        l5 = (void*) _a4_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_push((vader_array_t*) l2, l6);
    vader_struct_vader_bytecode_Return_t* _a5_obj = (vader_struct_vader_bytecode_Return_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Return_t));
    vader_obj_header_init(_a5_obj, 631u);
    l5 = (void*) _a5_obj;
    vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_c_field_align_at(void* l0, void* l1, int32_t l2) {
    vader_box_t l3;
    void* l4;
    void* l8;
    int64_t l5, l9;
    size_t l6, l7;
    int32_t l10;
    uint8_t t0;
    int32_t t1;
    vader_box_t t2;
    int64_t t3;
    l3 = vader_bytecode_c_field_val_type(l0, l1);
    if (!(l3.tag == 0u)) {
        t0 = ((uint8_t) l3.payload.i);
        t1 = vader_bytecode_size_of_val_type(t0);
        t2 = vader_box_i64(227u, ((int64_t) (int32_t) t1));
        return t2;
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
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        l10 = (l2 + INT32_C(1));
        l3 = vader_bytecode_c_field_align_at(l8, l1, l10);
        if (l3.tag == 0u) {
            return vader_box_obj(0u, NULL);
        }
        l9 = ((int64_t) l3.payload.i);
        if ((l9 > l5)) {
            l5 = l9;
        }
        t3 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t3;
    }
    t2 = vader_box_i64(227u, l5);
    return t2;
}

vader_box_t vader_bytecode_c_field_val_type(void* l0, void* l1) {
    size_t l2, l3;
    vader_box_t l4;
    int32_t t0;
    int64_t t1;
    void* t2;
    vader_box_t t3;
    t0 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_type_index;
    if ((t0 < INT32_C(0))) {
        return vader_box_obj(0u, NULL);
    }
    t0 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_type_index;
    t1 = ((int64_t) (int32_t) t0);
    l2 = (size_t) (int64_t) t1;
    l3 = ((vader_array_t*) l1)->length;
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_type_index;
    t1 = ((int64_t) (int32_t) t0);
    l2 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (!(l4.tag == 513u)) {
        return vader_box_obj(0u, NULL);
    }
    t2 = l4.payload.obj;
    t3 = vader_box_i32(229u, (int32_t)(uint32_t) ((vader_struct_vader_bytecode_BcPrimitive_t*) t2)->f_val);
    return t3;
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
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l3, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_bytecode_c_field_val_type(l0, l1);
    if (!(l3.tag == 0u)) {
        t0 = ((uint8_t) l3.payload.i);
        t1 = vader_bytecode_size_of_val_type(t0);
        t2 = vader_box_i64(227u, ((int64_t) (int32_t) t1));
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
    l5 = (l2 + INT32_C(1));
    l4 = vader_bytecode_c_struct_layout_at(l4, l1, l5);
    if (!(((vader_struct_vader_bytecode_CLayout_t*) l4)->f_unknown_field.tag == 0u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t3 = ((vader_struct_vader_bytecode_CLayout_t*) l4)->f_size;
    t2 = vader_box_i64(227u, t3);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_bytecode_c_safe_key(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t l11 = 0;
    bool l2, l6, l7, l8, l9, l10;
    size_t l3, l4;
    uint8_t l5;
    int64_t t0;
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = 0u;
    l2 = false;
    l3 = vader_host_std_core_byte_len(l0);
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        l5 = vader_host_std_core_byte_at(l0, l4);
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
            l1 = concat_2(l1, 767u);
            l2 = true;
        }
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
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
    int64_t l4, l5, l13, l14, l15, l16;
    vader_box_t l6 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null();
    size_t l8, l9;
    vader_string_t t0 = 0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l6, &l11, &l12 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l7, &l10, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(10u, 0u, 8u, 227u);
    l3 = (void*) _a0_arr;
    l4 = INT64_C(0);
    l5 = INT64_C(1);
    l6 = vader_box_obj(0u, NULL);
    l7 = l0;
    l8 = ((vader_array_t*) l7)->length;
    l9 = (size_t) 0;
    while ((l9 < l8)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
        l10 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
        l11 = vader_bytecode_c_field_width_at(l10, l1, l2);
        l12 = vader_bytecode_c_field_align_at(l10, l1, l2);
        if (l11.tag == 0u) {
            if (l6.tag == 0u) {
                t0 = ((vader_struct_vader_bytecode_BcField_t*) l10)->f_name;
                l6 = vader_box_string(223u, t0);
            }
            vader_array_push_i64((vader_array_t*) l3, l4);
            t1 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t1;
            continue;
        }
        if (l12.tag == 0u) {
            if (l6.tag == 0u) {
                t0 = ((vader_struct_vader_bytecode_BcField_t*) l10)->f_name;
                l6 = vader_box_string(223u, t0);
            }
            vader_array_push_i64((vader_array_t*) l3, l4);
            t1 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t1;
            continue;
        }
        l13 = ((int64_t) l12.payload.i);
        if ((l13 > l5)) {
            l5 = l13;
        }
        l14 = vader_mod_i64(l4, l13);
        if (l14 != INT64_C(0)) {
            l15 = (l13 - l14);
            l4 = (l4 + l15);
        }
        vader_array_push_i64((vader_array_t*) l3, l4);
        l16 = ((int64_t) l11.payload.i);
        l4 = (l4 + l16);
        t1 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t1;
    }
    l13 = vader_mod_i64(l4, l5);
    if (l13 == INT64_C(0)) {
        l14 = l4;
        vader_struct_vader_bytecode_CLayout_t* _a2_obj = (vader_struct_vader_bytecode_CLayout_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CLayout_t));
        vader_obj_header_init(_a2_obj, 538u);
        _a2_obj->f_offsets = l3;
        _a2_obj->f_size = l14;
        _a2_obj->f_unknown_field = l6;
        t2 = (void*) _a2_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l14 = ((l4 + l5) - l13);
    vader_struct_vader_bytecode_CLayout_t* _a3_obj = (vader_struct_vader_bytecode_CLayout_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CLayout_t));
    vader_obj_header_init(_a3_obj, 538u);
    _a3_obj->f_offsets = l3;
    _a3_obj->f_size = l14;
    _a3_obj->f_unknown_field = l6;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_cmp_eq(uint8_t l0) {
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(12)) {
        vader_struct_vader_bytecode_BoolEq_t* _a0_obj = (vader_struct_vader_bytecode_BoolEq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolEq_t));
        vader_obj_header_init(_a0_obj, 528u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(14)) {
        vader_struct_vader_bytecode_StringEq_t* _a1_obj = (vader_struct_vader_bytecode_StringEq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringEq_t));
        vader_obj_header_init(_a1_obj, 644u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_float_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_F64Eq_t* _a2_obj = (vader_struct_vader_bytecode_F64Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Eq_t));
        vader_obj_header_init(_a2_obj, 557u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_64_bit_int_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_I64Eq_t* _a3_obj = (vader_struct_vader_bytecode_I64Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Eq_t));
        vader_obj_header_init(_a3_obj, 596u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_ref_class(l0);
    if (!(t1)) {
        vader_struct_vader_bytecode_I32Eq_t* _a4_obj = (vader_struct_vader_bytecode_I32Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Eq_t));
        vader_obj_header_init(_a4_obj, 576u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_RefEq_t* _a5_obj = (vader_struct_vader_bytecode_RefEq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefEq_t));
    vader_obj_header_init(_a5_obj, 628u);
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
        vader_obj_header_init(_a0_obj, 558u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Ge_t* _a1_obj = (vader_struct_vader_bytecode_U64Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Ge_t));
        vader_obj_header_init(_a1_obj, 659u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Ge_t* _a2_obj = (vader_struct_vader_bytecode_U32Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Ge_t));
        vader_obj_header_init(_a2_obj, 653u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Ge_t* _a3_obj = (vader_struct_vader_bytecode_I32Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Ge_t));
        vader_obj_header_init(_a3_obj, 577u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Ge_t* _a4_obj = (vader_struct_vader_bytecode_I64Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Ge_t));
    vader_obj_header_init(_a4_obj, 597u);
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
        vader_obj_header_init(_a0_obj, 559u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Gt_t* _a1_obj = (vader_struct_vader_bytecode_U64Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Gt_t));
        vader_obj_header_init(_a1_obj, 660u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Gt_t* _a2_obj = (vader_struct_vader_bytecode_U32Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Gt_t));
        vader_obj_header_init(_a2_obj, 654u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Gt_t* _a3_obj = (vader_struct_vader_bytecode_I32Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Gt_t));
        vader_obj_header_init(_a3_obj, 578u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Gt_t* _a4_obj = (vader_struct_vader_bytecode_I64Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Gt_t));
    vader_obj_header_init(_a4_obj, 598u);
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
        vader_obj_header_init(_a0_obj, 560u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Le_t* _a1_obj = (vader_struct_vader_bytecode_U64Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Le_t));
        vader_obj_header_init(_a1_obj, 661u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Le_t* _a2_obj = (vader_struct_vader_bytecode_U32Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Le_t));
        vader_obj_header_init(_a2_obj, 655u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Le_t* _a3_obj = (vader_struct_vader_bytecode_I32Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Le_t));
        vader_obj_header_init(_a3_obj, 579u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Le_t* _a4_obj = (vader_struct_vader_bytecode_I64Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Le_t));
    vader_obj_header_init(_a4_obj, 599u);
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
        vader_obj_header_init(_a0_obj, 561u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Lt_t* _a1_obj = (vader_struct_vader_bytecode_U64Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Lt_t));
        vader_obj_header_init(_a1_obj, 662u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Lt_t* _a2_obj = (vader_struct_vader_bytecode_U32Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Lt_t));
        vader_obj_header_init(_a2_obj, 656u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Lt_t* _a3_obj = (vader_struct_vader_bytecode_I32Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Lt_t));
        vader_obj_header_init(_a3_obj, 580u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Lt_t* _a4_obj = (vader_struct_vader_bytecode_I64Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Lt_t));
    vader_obj_header_init(_a4_obj, 600u);
    t1 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_cmp_ne(uint8_t l0) {
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(12)) {
        vader_struct_vader_bytecode_BoolNe_t* _a0_obj = (vader_struct_vader_bytecode_BoolNe_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolNe_t));
        vader_obj_header_init(_a0_obj, 529u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(14)) {
        vader_struct_vader_bytecode_StringNe_t* _a1_obj = (vader_struct_vader_bytecode_StringNe_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringNe_t));
        vader_obj_header_init(_a1_obj, 645u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_float_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_F64Ne_t* _a2_obj = (vader_struct_vader_bytecode_F64Ne_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Ne_t));
        vader_obj_header_init(_a2_obj, 563u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_64_bit_int_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_I64Ne_t* _a3_obj = (vader_struct_vader_bytecode_I64Ne_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Ne_t));
        vader_obj_header_init(_a3_obj, 603u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_ref_class(l0);
    if (!(t1)) {
        vader_struct_vader_bytecode_I32Ne_t* _a4_obj = (vader_struct_vader_bytecode_I32Ne_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Ne_t));
        vader_obj_header_init(_a4_obj, 583u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_RefNe_t* _a5_obj = (vader_struct_vader_bytecode_RefNe_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefNe_t));
    vader_obj_header_init(_a5_obj, 629u);
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_coalesce_slots(void* l0) {
    size_t l1, l2, l4, l7, l11, l21, l22, l23, l25, l27, l32;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l24 = NULL;
    void* l26 = NULL;
    void* l28 = NULL;
    void* l33 = NULL;
    int32_t l8, l9, l12, l13, l14, l29, l30, l31;
    bool l16;
    uint8_t l20;
    vader_box_t l34 = vader_box_null(), l35 = vader_box_null(), l36 = vader_box_null();
    vader_string_t l37 = 0;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    bool t3;
    size_t t4;
    vader_box_t* gc_roots[4] = { &l34, &l35, &l36, &t2 };
    void** gc_raw_roots[14] = {
        &l0, &l3, &l5, &l6, &l10, &l15, &l17, &l18, &l19, &l24, &l26, &l28, &l33, &t1,
    };
    vader_string_t* gc_atom_roots[1] = { &l37 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    t0 = (l1 + l2);
    l2 = (size_t) (int64_t) t0;
    if ((l2 <= l1)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l4 = ((vader_array_t*) l3)->length;
    vader_array_t* _a0_arr = vader_array_new(44u, 0u, 13u, 634u);
    t1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(6u, 0u, 12u, 221u);
    t1 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l6 = (void*) _a3_arr;
    l7 = (size_t) 0;
    while ((l7 < l2)) {
        l8 = -(INT32_C(1));
        l9 = -(INT32_C(1));
        vader_struct_vader_bytecode_SlotRange_t* _a4_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
        vader_obj_header_init(_a4_obj, 634u);
        _a4_obj->f_first = l8;
        _a4_obj->f_last = l9;
        l10 = (void*) _a4_obj;
        vader_array_push((vader_array_t*) l5, vader_ref_box(l10));
        vader_array_push_bool((vader_array_t*) l6, false);
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    l7 = (size_t) 0;
    while ((l7 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
        t2 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
        l8 = vader_bytecode_slot_touched(t2);
        if ((l8 >= INT32_C(0))) {
            t0 = ((int64_t) (int32_t) l8);
            l11 = (size_t) (int64_t) t0;
            vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l11)
            t2 = vader_box_bool(221u, ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l11]);
            t3 = t2.payload.b;
            if (t3) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l11)
                t1 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l11);
                l13 = ((vader_struct_vader_bytecode_SlotRange_t*) t1)->f_first;
                l14 = ((int32_t) (size_t) l7);
                vader_struct_vader_bytecode_SlotRange_t* _a8_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                vader_obj_header_init(_a8_obj, 634u);
                _a8_obj->f_first = l13;
                _a8_obj->f_last = l14;
                l15 = (void*) _a8_obj;
                vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l11)
                vader_array_ref_store(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l11, l15);
                VADER_WRITE_BARRIER(_a9_slotarr->buf);
            } else {
                l9 = ((int32_t) (size_t) l7);
                l12 = ((int32_t) (size_t) l7);
                vader_struct_vader_bytecode_SlotRange_t* _a10_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                vader_obj_header_init(_a10_obj, 634u);
                _a10_obj->f_first = l9;
                _a10_obj->f_last = l12;
                l10 = (void*) _a10_obj;
                vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l11)
                vader_array_ref_store(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l11, l10);
                VADER_WRITE_BARRIER(_a11_slotarr->buf);
                vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l11)
                ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l11] = (uint8_t) true;
            }
        }
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    l10 = vader_bytecode_find_loop_ranges(l3);
    t4 = ((vader_array_t*) l10)->length;
    if ((t4 > INT64_C(0))) {
        l16 = true;
        while (l16) {
            l16 = vader_bytecode_extend_into_loops(l5, l6, l2, l10);
        }
    }
    l7 = (size_t) 0;
    while ((l7 < l1)) {
        l8 = ((int32_t) (size_t) l4);
        vader_struct_vader_bytecode_SlotRange_t* _a13_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
        vader_obj_header_init(_a13_obj, 634u);
        _a13_obj->f_first = INT32_C(0);
        _a13_obj->f_last = l8;
        l10 = (void*) _a13_obj;
        vader_array_t* _a14_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l7)
        vader_array_ref_store(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l7, l10);
        VADER_WRITE_BARRIER(_a14_slotarr->buf);
        vader_array_t* _a15_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l7)
        ((uint8_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l7] = (uint8_t) true;
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a16_arr = vader_array_new(40u, 0u, 13u, 510u);
    l10 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(9u, 0u, 7u, 226u);
    t1 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l15 = (void*) _a18_arr;
    l7 = (size_t) 0;
    vader_array_t* _pc186_hdr = (vader_array_t*) l15;
    size_t _pc186_len = _pc186_hdr->length;
    size_t _pc186_cap = (_pc186_hdr->offset == 0 && !vader_array_is_borrowed(_pc186_hdr) && _pc186_hdr->length >= _pc186_hdr->buf->length) ? _pc186_hdr->capacity : (size_t) 0;
    void* _pc186_slots = _pc186_hdr->buf->slots;
    for (;;) {
        if ((l7 < l2)) {
            l8 = -(INT32_C(1));
            if (VADER_LIKELY(_pc186_len < _pc186_cap)) {
                ((int32_t*) _pc186_slots)[_pc186_len] = (int32_t) (l8);
                _pc186_len += 1;
            } else {
                _pc186_hdr->length = _pc186_len;
                if (_pc186_hdr->buf->length < _pc186_len) {
                    _pc186_hdr->buf->length = _pc186_len;
                }
                vader_array_push_i32((vader_array_t*) l15, l8);
                _pc186_hdr = (vader_array_t*) l15;
                _pc186_len = _pc186_hdr->length;
                _pc186_cap = (_pc186_hdr->offset == 0 && !vader_array_is_borrowed(_pc186_hdr) && _pc186_hdr->length >= _pc186_hdr->buf->length) ? _pc186_hdr->capacity : (size_t) 0;
                _pc186_slots = _pc186_hdr->buf->slots;
            }
            t0 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t0;
            continue;
        }
        _pc186_hdr->length = _pc186_len;
        if (_pc186_hdr->buf->length < _pc186_len) {
            _pc186_hdr->buf->length = _pc186_len;
        }
        break;
    }
    l7 = (size_t) 0;
    while ((l7 < l1)) {
        l8 = ((int32_t) (size_t) l7);
        vader_array_t* _a19_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l7)
        ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a20_arr = vader_array_new(44u, 0u, 13u, 634u);
    t1 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l1);
    l17 = (void*) _a21_arr;
    l7 = (size_t) 0;
    while ((l7 < l1)) {
        vader_array_t* _a22_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l7)
        l18 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l7);
        vader_array_push((vader_array_t*) l17, vader_ref_box(l18));
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    l7 = l1;
    while ((l7 < l2)) {
        vader_array_t* _a23_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l7)
        t2 = vader_box_bool(221u, ((uint8_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l7]);
        t3 = t2.payload.b;
        if (t3) {
            vader_array_t* _a24_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l7)
            l18 = vader_array_ref_load_obj(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l7);
            l19 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
            t0 = (l7 - l1);
            l11 = (size_t) (int64_t) t0;
            vader_array_t* _a25_slotarr = ((vader_array_t*) l19);
            VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l11)
            t1 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l11);
            l20 = ((vader_struct_vader_bytecode_BcLocal_t*) t1)->f_val;
            l9 = -(INT32_C(1));
            l21 = l1;
            l22 = ((vader_array_t*) l17)->length;
            while ((l21 < l22)) {
                t0 = (l21 - l1);
                l23 = (size_t) (int64_t) t0;
                vader_array_t* _a26_slotarr = ((vader_array_t*) l10);
                VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l23)
                t1 = vader_array_ref_load_obj(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l23);
                if (((vader_struct_vader_bytecode_BcLocal_t*) t1)->f_val == l20) {
                    vader_array_t* _a27_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l21)
                    t1 = vader_array_ref_load_obj(_a27_slotarr->buf, _a27_slotarr->offset + (size_t) l21);
                    t3 = vader_bytecode_ranges_overlap(t1, l18);
                    if (!(t3)) {
                        l9 = ((int32_t) (size_t) l21);
                        break;
                    }
                }
                t0 = (l21 + INT64_C(1));
                l21 = (size_t) (int64_t) t0;
            }
            if ((l9 < INT32_C(0))) {
                t4 = ((vader_array_t*) l17)->length;
                l9 = ((int32_t) (size_t) t4);
                vader_array_push((vader_array_t*) l17, vader_ref_box(l18));
                l24 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
                t0 = (l7 - l1);
                l25 = (size_t) (int64_t) t0;
                vader_array_t* _a28_slotarr = ((vader_array_t*) l24);
                VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l25)
                l26 = vader_array_ref_load_obj(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l25);
                vader_array_push((vader_array_t*) l10, vader_ref_box(l26));
            } else {
                t0 = ((int64_t) (int32_t) l9);
                l27 = (size_t) (int64_t) t0;
                vader_array_t* _a29_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l27)
                l28 = vader_array_ref_load_obj(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l27);
                l13 = ((vader_struct_vader_bytecode_SlotRange_t*) l18)->f_first;
                l14 = ((vader_struct_vader_bytecode_SlotRange_t*) l28)->f_first;
                if ((l13 < l14)) {
                    l12 = ((vader_struct_vader_bytecode_SlotRange_t*) l18)->f_first;
                } else {
                    l12 = ((vader_struct_vader_bytecode_SlotRange_t*) l28)->f_first;
                }
                l30 = ((vader_struct_vader_bytecode_SlotRange_t*) l18)->f_last;
                l31 = ((vader_struct_vader_bytecode_SlotRange_t*) l28)->f_last;
                if ((l30 > l31)) {
                    l29 = ((vader_struct_vader_bytecode_SlotRange_t*) l18)->f_last;
                } else {
                    l29 = ((vader_struct_vader_bytecode_SlotRange_t*) l28)->f_last;
                }
                t0 = ((int64_t) (int32_t) l9);
                l32 = (size_t) (int64_t) t0;
                vader_struct_vader_bytecode_SlotRange_t* _a30_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                vader_obj_header_init(_a30_obj, 634u);
                _a30_obj->f_first = l12;
                _a30_obj->f_last = l29;
                l33 = (void*) _a30_obj;
                vader_array_t* _a31_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l32)
                vader_array_ref_store(_a31_slotarr->buf, _a31_slotarr->offset + (size_t) l32, l33);
                VADER_WRITE_BARRIER(_a31_slotarr->buf);
            }
            vader_array_t* _a32_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l7)
            ((int32_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) l7] = (int32_t) l9;
            t0 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t0;
            continue;
        }
        l8 = -(INT32_C(1));
        vader_array_t* _a33_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l7)
        ((int32_t*) _a33_slotarr->buf->slots)[_a33_slotarr->offset + (size_t) l7] = (int32_t) l8;
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    l16 = true;
    while ((l1 < l2)) {
        vader_array_t* _a34_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l1)
        l8 = ((int32_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l1];
        l9 = ((int32_t) (size_t) l1);
        if (l8 != l9) {
            l16 = false;
            break;
        }
        t0 = (l1 + INT64_C(1));
        l1 = (size_t) (int64_t) t0;
    }
    if (l16) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a35_arr = vader_array_new(169u, 0u, 13u, 1235u);
    l5 = (void*) _a35_arr;
    l1 = (size_t) 0;
    while ((l1 < l4)) {
        vader_array_t* _a36_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l1)
        l34 = vader_array_ref_load_box(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l1);
        l8 = vader_bytecode_slot_touched(l34);
        if ((l8 >= INT32_C(0))) {
            t0 = ((int64_t) (int32_t) l8);
            l2 = (size_t) (int64_t) t0;
            vader_array_t* _a37_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l2)
            l9 = ((int32_t*) _a37_slotarr->buf->slots)[_a37_slotarr->offset + (size_t) l2];
            if ((l9 >= INT32_C(0))) {
                l35 = vader_bytecode_with_remapped_slot(l34, l9);
                vader_array_push((vader_array_t*) l5, l35);
            } else {
                vader_array_push((vader_array_t*) l5, l34);
            }
        } else {
            l36 = vader_bytecode_remap_push_cache_slot(l34, l15);
            vader_array_push((vader_array_t*) l5, l36);
        }
        t0 = (l1 + INT64_C(1));
        l1 = (size_t) (int64_t) t0;
    }
    l3 = l0;
    l37 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_name;
    l16 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_is_main;
    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature;
    l15 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_debug;
    l17 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_jump_table;
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_source_pc;
    vader_struct_vader_bytecode_BcFunction_t* _a38_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a38_obj, 508u);
    _a38_obj->f_name = l37;
    _a38_obj->f_is_main = l16;
    _a38_obj->f_signature = l6;
    _a38_obj->f_locals = l10;
    _a38_obj->f_body = l5;
    _a38_obj->f_debug = l15;
    _a38_obj->f_jump_table = l17;
    _a38_obj->f_source_pc = l3;
    t1 = (void*) _a38_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_bytecode_const_fills_slot(vader_box_t l0, uint8_t l1) {
    bool t0;
    uint8_t t1;
    if (l0.tag == 594u) {
        t0 = vader_bytecode_is_64_bit_int_val(l1);
        return t0;
    }
    if (!(l0.tag == 574u)) {
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
    if (!((l0.tag == 527u || l0.tag == 542u || l0.tag == 555u || l0.tag == 574u || l0.tag == 594u || l0.tag == 625u || l0.tag == 643u))) {
        return vader_box_obj(0u, NULL);
    }
    return l0;
}

static uint8_t vader_bytecode_const_val_type(vader_box_t l0) {
    uint8_t l1;
    if (l0.tag == 574u) {
        l1 = (uint8_t) 2;
        return l1;
    }
    if (l0.tag == 594u) {
        l1 = (uint8_t) 3;
    } else if (l0.tag == 555u) {
        l1 = (uint8_t) 11;
    } else if (l0.tag == 527u) {
        l1 = (uint8_t) 12;
    } else if (l0.tag == 542u) {
        l1 = (uint8_t) 13;
    } else if (l0.tag == 643u) {
        l1 = (uint8_t) 14;
    } else {
        if (!(l0.tag == 625u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = (uint8_t) 15;
    }
    return l1;
}

static vader_string_t vader_bytecode_convert_target_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 1662u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1684u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1546u;
    } else {
        if (!(l0 == INT32_C(3))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1359u;
    }
    return l1;
}

vader_box_t vader_bytecode_convert_target_of(uint8_t l0) {
    vader_box_t l1;
    if (l0 == INT32_C(0)) {
        l1 = vader_box_i32(229u, INT32_C(0));
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = vader_box_i32(229u, INT32_C(0));
    } else if (l0 == INT32_C(2)) {
        l1 = vader_box_i32(229u, INT32_C(0));
    } else if (l0 == INT32_C(5)) {
        l1 = vader_box_i32(229u, INT32_C(0));
    } else if (l0 == INT32_C(6)) {
        l1 = vader_box_i32(229u, INT32_C(0));
    } else if (l0 == INT32_C(7)) {
        l1 = vader_box_i32(229u, INT32_C(0));
    } else if (l0 == INT32_C(3)) {
        l1 = vader_box_i32(229u, INT32_C(1));
    } else if (l0 == INT32_C(8)) {
        l1 = vader_box_i32(229u, INT32_C(1));
    } else if (l0 == INT32_C(4)) {
        l1 = vader_box_i32(229u, INT32_C(1));
    } else if (l0 == INT32_C(9)) {
        l1 = vader_box_i32(229u, INT32_C(1));
    } else if (l0 == INT32_C(10)) {
        l1 = vader_box_i32(229u, INT32_C(2));
    } else if (l0 == INT32_C(11)) {
        l1 = vader_box_i32(229u, INT32_C(2));
    } else if (l0 == INT32_C(13)) {
        l1 = vader_box_i32(229u, INT32_C(3));
    } else if (l0 == INT32_C(12)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(14)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(15)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(16)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(17)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(18)) {
        l1 = vader_box_obj(0u, NULL);
    } else {
        if (!(l0 == INT32_C(19))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_box_obj(0u, NULL);
    }
    return l1;
}

bool vader_bytecode_data_entry_mutable(vader_box_t l0) {
    bool l1;
    void* t0;
    if (l0.tag == 512u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_BcPrimData_t*) t0)->f_mutable;
        return l1;
    }
    if (l0.tag == 516u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_BcStrData_t*) t0)->f_mutable;
    } else {
        if (!(l0.tag == 503u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_BcAggregateData_t*) t0)->f_mutable;
    }
    return l1;
}

void* vader_bytecode_data_pool_type_ids(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    size_t l2, l4, l6, l7, l9, l10, l11;
    vader_box_t l8 = vader_box_null();
    int32_t l12;
    size_t t0;
    void* t1 = NULL;
    int32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 1u, 7u, 226u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(0);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_data_pool)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    t0 = ((vader_array_t*) l1)->length;
    if (t0 == INT64_C(0)) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
    l2 = ((vader_array_t*) l3)->length;
    l4 = (size_t) 0;
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_body;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) 0;
        while ((l7 < l6)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l8 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
            if (l8.tag == 544u) {
                t1 = l8.payload.obj;
                t2 = ((vader_struct_vader_bytecode_DataConst_t*) t1)->f_pool_index;
                if ((t2 >= INT32_C(0))) {
                    t1 = l8.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_DataConst_t*) t1)->f_pool_index;
                    t3 = ((int64_t) (int32_t) t2);
                    l9 = (size_t) (int64_t) t3;
                    l10 = ((vader_array_t*) l1)->length;
                    if ((l9 < l10)) {
                        t1 = l8.payload.obj;
                        t2 = ((vader_struct_vader_bytecode_DataConst_t*) t1)->f_pool_index;
                        t3 = ((int64_t) (int32_t) t2);
                        l11 = (size_t) (int64_t) t3;
                        t1 = l8.payload.obj;
                        l12 = ((vader_struct_vader_bytecode_DataConst_t*) t1)->f_type_id;
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
                        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l11] = (int32_t) l12;
                    }
                }
            }
            t3 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t3;
        }
        t3 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t3;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_default_emit_options(void) {
    void* l0 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 223u);
    l0 = (void*) _a0_arr;
    vader_struct_vader_bytecode_EmitOptions_t* _a1_obj = (vader_struct_vader_bytecode_EmitOptions_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_EmitOptions_t));
    vader_obj_header_init(_a1_obj, 550u);
    _a1_obj->f_optimize = true;
    _a1_obj->f_keep_mangles = l0;
    _a1_obj->f_want_debug = false;
    _a1_obj->f_verify = false;
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
        vader_obj_header_init(_a0_obj, 658u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (!(t0)) {
        t2 = vader_bytecode_arith_op(l0, 1447u);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_U32Div_t* _a1_obj = (vader_struct_vader_bytecode_U32Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Div_t));
    vader_obj_header_init(_a1_obj, 652u);
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_drop_dead_stores(void* l0) {
    size_t l1, l2, l4, l6, l8, l10, l17, l19, l22, l25;
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
    int32_t l9, l11, l18, l21, l24, l26, l27, l28, l30;
    bool l12;
    vader_string_t l32 = 0;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    bool t4;
    size_t t5;
    vader_box_t* gc_roots[3] = { &l7, &l31, &t3 };
    void** gc_raw_roots[11] = { &l0, &l3, &l5, &l13, &l14, &l15, &l16, &l20, &l23, &l29, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l32 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    t0 = (l1 + l2);
    l2 = (size_t) (int64_t) t0;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 226u);
    t1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l3 = (void*) _a1_arr;
    l4 = (size_t) 0;
    vader_array_t* _pc17_hdr = (vader_array_t*) l3;
    size_t _pc17_len = _pc17_hdr->length;
    size_t _pc17_cap = (_pc17_hdr->offset == 0 && !vader_array_is_borrowed(_pc17_hdr) && _pc17_hdr->length >= _pc17_hdr->buf->length) ? _pc17_hdr->capacity : (size_t) 0;
    void* _pc17_slots = _pc17_hdr->buf->slots;
    for (;;) {
        if ((l4 < l2)) {
            if (VADER_LIKELY(_pc17_len < _pc17_cap)) {
                ((int32_t*) _pc17_slots)[_pc17_len] = (int32_t) (INT32_C(0));
                _pc17_len += 1;
            } else {
                _pc17_hdr->length = _pc17_len;
                if (_pc17_hdr->buf->length < _pc17_len) {
                    _pc17_hdr->buf->length = _pc17_len;
                }
                vader_array_push_i32((vader_array_t*) l3, INT32_C(0));
                _pc17_hdr = (vader_array_t*) l3;
                _pc17_len = _pc17_hdr->length;
                _pc17_cap = (_pc17_hdr->offset == 0 && !vader_array_is_borrowed(_pc17_hdr) && _pc17_hdr->length >= _pc17_hdr->buf->length) ? _pc17_hdr->capacity : (size_t) 0;
                _pc17_slots = _pc17_hdr->buf->slots;
            }
            t0 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t0;
            continue;
        }
        _pc17_hdr->length = _pc17_len;
        if (_pc17_hdr->buf->length < _pc17_len) {
            _pc17_hdr->buf->length = _pc17_len;
        }
        break;
    }
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l4 = ((vader_array_t*) l5)->length;
    l6 = (size_t) 0;
    while ((l6 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        if (l7.tag == 619u) {
            t1 = l7.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalGet_t*) t1)->f_slot;
            t0 = ((int64_t) (int32_t) t2);
            l8 = (size_t) (int64_t) t0;
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
            t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l8];
            l9 = (t2 + INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
            ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l8] = (int32_t) l9;
        }
        if (l7.tag == 618u) {
            t1 = l7.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalField_t*) t1)->f_slot;
            t0 = ((int64_t) (int32_t) t2);
            l10 = (size_t) (int64_t) t0;
            vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
            t2 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l10];
            l11 = (t2 + INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
            ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l10] = (int32_t) l11;
        }
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a5_arr = vader_array_new(6u, 0u, 12u, 221u);
    t1 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l5 = (void*) _a6_arr;
    l4 = (size_t) 0;
    vader_array_t* _pc99_hdr = (vader_array_t*) l5;
    size_t _pc99_len = _pc99_hdr->length;
    size_t _pc99_cap = (_pc99_hdr->offset == 0 && !vader_array_is_borrowed(_pc99_hdr) && _pc99_hdr->length >= _pc99_hdr->buf->length) ? _pc99_hdr->capacity : (size_t) 0;
    void* _pc99_slots = _pc99_hdr->buf->slots;
    for (;;) {
        if ((l4 < l2)) {
            if (VADER_LIKELY(_pc99_len < _pc99_cap)) {
                ((uint8_t*) _pc99_slots)[_pc99_len] = (uint8_t) (false);
                _pc99_len += 1;
            } else {
                _pc99_hdr->length = _pc99_len;
                if (_pc99_hdr->buf->length < _pc99_len) {
                    _pc99_hdr->buf->length = _pc99_len;
                }
                vader_array_push_bool((vader_array_t*) l5, false);
                _pc99_hdr = (vader_array_t*) l5;
                _pc99_len = _pc99_hdr->length;
                _pc99_cap = (_pc99_hdr->offset == 0 && !vader_array_is_borrowed(_pc99_hdr) && _pc99_hdr->length >= _pc99_hdr->buf->length) ? _pc99_hdr->capacity : (size_t) 0;
                _pc99_slots = _pc99_hdr->buf->slots;
            }
            t0 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t0;
            continue;
        }
        _pc99_hdr->length = _pc99_len;
        if (_pc99_hdr->buf->length < _pc99_len) {
            _pc99_hdr->buf->length = _pc99_len;
        }
        break;
    }
    l12 = false;
    l4 = l1;
    while ((l4 < l2)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l4)
        t2 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l4];
        if (t2 == INT32_C(0)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l4)
            ((uint8_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l4] = (uint8_t) true;
            l12 = true;
        }
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    if (!(l12)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a9_arr = vader_array_new(9u, 0u, 7u, 226u);
    t1 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l3 = (void*) _a10_arr;
    l4 = (size_t) 0;
    vader_array_t* _pc155_hdr = (vader_array_t*) l3;
    size_t _pc155_len = _pc155_hdr->length;
    size_t _pc155_cap = (_pc155_hdr->offset == 0 && !vader_array_is_borrowed(_pc155_hdr) && _pc155_hdr->length >= _pc155_hdr->buf->length) ? _pc155_hdr->capacity : (size_t) 0;
    void* _pc155_slots = _pc155_hdr->buf->slots;
    for (;;) {
        if ((l4 < l2)) {
            l9 = -(INT32_C(1));
            if (VADER_LIKELY(_pc155_len < _pc155_cap)) {
                ((int32_t*) _pc155_slots)[_pc155_len] = (int32_t) (l9);
                _pc155_len += 1;
            } else {
                _pc155_hdr->length = _pc155_len;
                if (_pc155_hdr->buf->length < _pc155_len) {
                    _pc155_hdr->buf->length = _pc155_len;
                }
                vader_array_push_i32((vader_array_t*) l3, l9);
                _pc155_hdr = (vader_array_t*) l3;
                _pc155_len = _pc155_hdr->length;
                _pc155_cap = (_pc155_hdr->offset == 0 && !vader_array_is_borrowed(_pc155_hdr) && _pc155_hdr->length >= _pc155_hdr->buf->length) ? _pc155_hdr->capacity : (size_t) 0;
                _pc155_slots = _pc155_hdr->buf->slots;
            }
            t0 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t0;
            continue;
        }
        _pc155_hdr->length = _pc155_len;
        if (_pc155_hdr->buf->length < _pc155_len) {
            _pc155_hdr->buf->length = _pc155_len;
        }
        break;
    }
    l9 = INT32_C(0);
    l4 = (size_t) 0;
    while ((l4 < l2)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l4)
        t3 = vader_box_bool(221u, ((uint8_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l4]);
        t4 = t3.payload.b;
        if (!(t4)) {
            vader_array_t* _a12_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l4)
            ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l4] = (int32_t) l9;
            l9 = (l9 + INT32_C(1));
        }
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a13_arr = vader_array_new(169u, 0u, 13u, 1235u);
    l13 = (void*) _a13_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body)->length;
    vader_array_t* _a14_arr = vader_array_new(9u, 0u, 7u, 226u);
    t1 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l4);
    l14 = (void*) _a15_arr;
    l6 = (size_t) 0;
    vader_array_t* _pc215_hdr = (vader_array_t*) l14;
    size_t _pc215_len = _pc215_hdr->length;
    size_t _pc215_cap = (_pc215_hdr->offset == 0 && !vader_array_is_borrowed(_pc215_hdr) && _pc215_hdr->length >= _pc215_hdr->buf->length) ? _pc215_hdr->capacity : (size_t) 0;
    void* _pc215_slots = _pc215_hdr->buf->slots;
    for (;;) {
        if ((l6 < l4)) {
            l9 = -(INT32_C(1));
            if (VADER_LIKELY(_pc215_len < _pc215_cap)) {
                ((int32_t*) _pc215_slots)[_pc215_len] = (int32_t) (l9);
                _pc215_len += 1;
            } else {
                _pc215_hdr->length = _pc215_len;
                if (_pc215_hdr->buf->length < _pc215_len) {
                    _pc215_hdr->buf->length = _pc215_len;
                }
                vader_array_push_i32((vader_array_t*) l14, l9);
                _pc215_hdr = (vader_array_t*) l14;
                _pc215_len = _pc215_hdr->length;
                _pc215_cap = (_pc215_hdr->offset == 0 && !vader_array_is_borrowed(_pc215_hdr) && _pc215_hdr->length >= _pc215_hdr->buf->length) ? _pc215_hdr->capacity : (size_t) 0;
                _pc215_slots = _pc215_hdr->buf->slots;
            }
            t0 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t0;
            continue;
        }
        _pc215_hdr->length = _pc215_len;
        if (_pc215_hdr->buf->length < _pc215_len) {
            _pc215_hdr->buf->length = _pc215_len;
        }
        break;
    }
    l6 = (size_t) 0;
    while ((l6 < l4)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l6)
        l7 = vader_array_ref_load_box(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l6);
        if (l7.tag == 620u) {
            t1 = l7.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalSet_t*) t1)->f_slot;
            t0 = ((int64_t) (int32_t) t2);
            l8 = (size_t) (int64_t) t0;
            vader_array_t* _a17_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l8)
            t3 = vader_box_bool(221u, ((uint8_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l8]);
            t4 = t3.payload.b;
            if (t4) {
                t5 = ((vader_array_t*) l13)->length;
                l9 = ((int32_t) (size_t) t5);
                vader_array_t* _a18_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l6)
                ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l6] = (int32_t) l9;
                vader_struct_vader_bytecode_Drop_t* _a19_obj = (vader_struct_vader_bytecode_Drop_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Drop_t));
                vader_obj_header_init(_a19_obj, 548u);
                l15 = (void*) _a19_obj;
                vader_array_push((vader_array_t*) l13, vader_ref_box(l15));
            } else {
                t5 = ((vader_array_t*) l13)->length;
                l11 = ((int32_t) (size_t) t5);
                vader_array_t* _a20_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l6)
                ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l6] = (int32_t) l11;
                t1 = l7.payload.obj;
                t2 = ((vader_struct_vader_bytecode_LocalSet_t*) t1)->f_slot;
                t0 = ((int64_t) (int32_t) t2);
                l10 = (size_t) (int64_t) t0;
                vader_array_t* _a21_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l10)
                t2 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l10];
                vader_struct_vader_bytecode_LocalSet_t* _a22_obj = (vader_struct_vader_bytecode_LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalSet_t));
                vader_obj_header_init(_a22_obj, 620u);
                _a22_obj->f_slot = t2;
                l16 = (void*) _a22_obj;
                vader_array_push((vader_array_t*) l13, vader_ref_box(l16));
            }
            t0 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t0;
            continue;
        }
        if (l7.tag == 621u) {
            t1 = l7.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalTee_t*) t1)->f_slot;
            t0 = ((int64_t) (int32_t) t2);
            l17 = (size_t) (int64_t) t0;
            vader_array_t* _a23_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l17)
            t3 = vader_box_bool(221u, ((uint8_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l17]);
            t4 = t3.payload.b;
            if (t4) {
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                continue;
            }
            t5 = ((vader_array_t*) l13)->length;
            l18 = ((int32_t) (size_t) t5);
            vader_array_t* _a24_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l6)
            ((int32_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l6] = (int32_t) l18;
            t1 = l7.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalTee_t*) t1)->f_slot;
            t0 = ((int64_t) (int32_t) t2);
            l19 = (size_t) (int64_t) t0;
            vader_array_t* _a25_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l19)
            t2 = ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l19];
            vader_struct_vader_bytecode_LocalTee_t* _a26_obj = (vader_struct_vader_bytecode_LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalTee_t));
            vader_obj_header_init(_a26_obj, 621u);
            _a26_obj->f_slot = t2;
            l20 = (void*) _a26_obj;
            vader_array_push((vader_array_t*) l13, vader_ref_box(l20));
            t0 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t0;
            continue;
        }
        if (l7.tag == 619u) {
            t5 = ((vader_array_t*) l13)->length;
            l21 = ((int32_t) (size_t) t5);
            vader_array_t* _a27_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l6)
            ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l6] = (int32_t) l21;
            t1 = l7.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalGet_t*) t1)->f_slot;
            t0 = ((int64_t) (int32_t) t2);
            l22 = (size_t) (int64_t) t0;
            vader_array_t* _a28_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l22)
            t2 = ((int32_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l22];
            vader_struct_vader_bytecode_LocalGet_t* _a29_obj = (vader_struct_vader_bytecode_LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalGet_t));
            vader_obj_header_init(_a29_obj, 619u);
            _a29_obj->f_slot = t2;
            l23 = (void*) _a29_obj;
            vader_array_push((vader_array_t*) l13, vader_ref_box(l23));
            t0 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t0;
            continue;
        }
        if (l7.tag == 618u) {
            t5 = ((vader_array_t*) l13)->length;
            l24 = ((int32_t) (size_t) t5);
            vader_array_t* _a30_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l6)
            ((int32_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l6] = (int32_t) l24;
            t1 = l7.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalField_t*) t1)->f_slot;
            t0 = ((int64_t) (int32_t) t2);
            l25 = (size_t) (int64_t) t0;
            vader_array_t* _a31_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l25)
            l26 = ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l25];
            t1 = l7.payload.obj;
            l27 = ((vader_struct_vader_bytecode_LocalField_t*) t1)->f_type_id;
            t1 = l7.payload.obj;
            l28 = ((vader_struct_vader_bytecode_LocalField_t*) t1)->f_field_index;
            vader_struct_vader_bytecode_LocalField_t* _a32_obj = (vader_struct_vader_bytecode_LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalField_t));
            vader_obj_header_init(_a32_obj, 618u);
            _a32_obj->f_slot = l26;
            _a32_obj->f_type_id = l27;
            _a32_obj->f_field_index = l28;
            l29 = (void*) _a32_obj;
            vader_array_push((vader_array_t*) l13, vader_ref_box(l29));
            t0 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t0;
            continue;
        }
        t5 = ((vader_array_t*) l13)->length;
        l30 = ((int32_t) (size_t) t5);
        vader_array_t* _a33_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l6)
        ((int32_t*) _a33_slotarr->buf->slots)[_a33_slotarr->offset + (size_t) l6] = (int32_t) l30;
        l31 = vader_bytecode_remap_push_cache_slot(l7, l3);
        vader_array_push((vader_array_t*) l13, l31);
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l4 = ((vader_array_t*) l13)->length;
    l3 = vader_bytecode_remap_jump_table(l3, l14, l4);
    l15 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug;
    l4 = ((vader_array_t*) l13)->length;
    l14 = vader_bytecode_remap_debug(l15, l14, l4);
    vader_array_t* _a34_arr = vader_array_new(40u, 0u, 13u, 510u);
    l15 = (void*) _a34_arr;
    l4 = l1;
    while ((l4 < l2)) {
        vader_array_t* _a35_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l4)
        t3 = vader_box_bool(221u, ((uint8_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l4]);
        t4 = t3.payload.b;
        if (!(t4)) {
            l16 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
            t0 = (l4 - l1);
            l6 = (size_t) (int64_t) t0;
            vader_array_t* _a36_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l6)
            l20 = vader_array_ref_load_obj(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l6);
            vader_array_push((vader_array_t*) l15, vader_ref_box(l20));
        }
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    l5 = l0;
    l32 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_name;
    l12 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_is_main;
    l16 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_signature;
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_source_pc;
    vader_struct_vader_bytecode_BcFunction_t* _a37_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a37_obj, 508u);
    _a37_obj->f_name = l32;
    _a37_obj->f_is_main = l12;
    _a37_obj->f_signature = l16;
    _a37_obj->f_locals = l15;
    _a37_obj->f_body = l13;
    _a37_obj->f_debug = l14;
    _a37_obj->f_jump_table = l3;
    _a37_obj->f_source_pc = l5;
    t1 = (void*) _a37_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_drop_unbranched_blocks(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    size_t l3, l5, l7, l10;
    int32_t l6, l12;
    bool l9;
    vader_box_t l13 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    bool t3;
    size_t t4;
    vader_box_t* gc_roots[2] = { &l13, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l4, &l8, &l11, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l2 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l3 = ((vader_array_t*) l1)->length;
    vader_array_t* _a0_arr = vader_array_new(6u, 1u, 12u, 221u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    l4 = (void*) _a0_arr;
    t0 = (l3 + INT64_C(1));
    l5 = (size_t) (int64_t) t0;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (size_t) l5);
    l4 = (void*) _a1_arr;
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l6 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        if ((t1.tag == 532u || t1.tag == 533u)) {
            if ((l6 >= INT32_C(0))) {
                if ((((int64_t) (int32_t) l6) <= l3)) {
                    t0 = ((int64_t) (int32_t) l6);
                    l7 = (size_t) (int64_t) t0;
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
                    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l7] = (uint8_t) true;
                }
            }
        }
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a5_arr = vader_array_new(6u, 1u, 12u, 221u);
    ((uint8_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (uint8_t) false;
    t2 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) t2, (size_t) l3);
    l8 = (void*) _a6_arr;
    l9 = false;
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
        l6 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l5];
        vader_array_t* _a8_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l5)
        t1 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l5);
        if (t1.tag == 525u) {
            if ((l6 > INT32_C(0))) {
                t0 = ((int64_t) (int32_t) l6);
                l7 = (size_t) (int64_t) t0;
                vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l7)
                t1 = vader_box_bool(221u, ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l7]);
                t3 = t1.payload.b;
                if (!(t3)) {
                    vader_array_t* _a10_slotarr = ((vader_array_t*) l8);
                    VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l5)
                    ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l5] = (uint8_t) true;
                    t0 = (((int64_t) (int32_t) l6) - INT64_C(1));
                    l10 = (size_t) (int64_t) t0;
                    VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l10)
                    ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l10] = (uint8_t) true;
                    l9 = true;
                }
            }
        }
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    if (!(l9)) {
        t2 = vader_bytecode_bc_peephole_unchanged(l0);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a11_arr = vader_array_new(169u, 0u, 13u, 1235u);
    l4 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(9u, 0u, 7u, 226u);
    l11 = (void*) _a12_arr;
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l5)
        t1 = vader_box_bool(221u, ((uint8_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l5]);
        t3 = t1.payload.b;
        if (t3) {
            l6 = -(INT32_C(1));
            vader_array_push_i32((vader_array_t*) l11, l6);
        } else {
            t4 = ((vader_array_t*) l4)->length;
            l12 = ((int32_t) (size_t) t4);
            vader_array_push_i32((vader_array_t*) l11, l12);
            vader_array_t* _a14_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l5)
            l13 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l5);
            vader_array_push((vader_array_t*) l4, l13);
        }
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    l3 = ((vader_array_t*) l4)->length;
    l1 = vader_bytecode_remap_jump_table(l2, l11, l3);
    l2 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug;
    l3 = ((vader_array_t*) l4)->length;
    l2 = vader_bytecode_remap_debug(l2, l11, l3);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a15_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a15_obj, 511u);
    _a15_obj->f_body = l4;
    _a15_obj->f_jump_table = l1;
    _a15_obj->f_debug = l2;
    t2 = (void*) _a15_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_bytecode_extend_into_loops(void* l0, void* l1, size_t l2, void* l3) {
    bool l4;
    size_t l5, l8, l9;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    int32_t l11, l12, l13, l14, l15, l16, l17, l18, l19, l20, l21, l22;
    vader_box_t t0 = vader_box_null();
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l6, &l7, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = false;
    l5 = (size_t) 0;
    while ((l5 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_box_bool(221u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5]);
        t1 = t0.payload.b;
        if (t1) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
            l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            l7 = l3;
            l8 = ((vader_array_t*) l7)->length;
            l9 = (size_t) 0;
            while ((l9 < l8)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
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
                            vader_obj_header_init(_a3_obj, 634u);
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
                            vader_obj_header_init(_a4_obj, 634u);
                            _a4_obj->f_first = l21;
                            _a4_obj->f_last = l22;
                            l6 = (void*) _a4_obj;
                            l4 = true;
                        }
                    }
                }
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
            }
            vader_array_t* _a5_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
            vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5, l6);
            VADER_WRITE_BARRIER(_a5_slotarr->buf);
        }
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_bytecode_f64_const_operands(double l0) {
    uint64_t l1;
    vader_string_t l2 = 0;
    size_t l3;
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
        l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(21) + l3));
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l4, l3, l2);
        l3 = std_core_write_string_at(l4, l3, 8u);
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
    size_t l4, l5, l6;
    vader_box_t l7 = vader_box_null();
    int32_t l8, l9, l10, l11, l12;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l7, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l13 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(44u, 0u, 13u, 634u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 223u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 226u);
    l3 = (void*) _a2_arr;
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) l0)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        if (l7.tag == 525u) {
            l8 = ((int32_t) (size_t) l6);
            vader_bytecode_push_scope(l2, l3, l4, 1251u, l8);
            t0 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t0;
        } else if (l7.tag == 622u) {
            l9 = ((int32_t) (size_t) l6);
            vader_bytecode_push_scope(l2, l3, l4, 1850u, l9);
            t0 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t0;
        } else if (l7.tag == 609u) {
            l10 = ((int32_t) (size_t) l6);
            vader_bytecode_push_scope(l2, l3, l4, 1711u, l10);
            t0 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t0;
        } else if (l7.tag == 552u) {
            if ((l4 > INT64_C(0))) {
                t0 = (l4 - INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                t1 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l4];
                t2 = t1.payload.s;
                if (t2 == 1850u) {
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                    l11 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4];
                    l12 = ((int32_t) (size_t) l6);
                    vader_struct_vader_bytecode_SlotRange_t* _a6_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                    vader_obj_header_init(_a6_obj, 634u);
                    _a6_obj->f_first = l11;
                    _a6_obj->f_last = l12;
                    l13 = (void*) _a6_obj;
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l13));
                }
            }
        }
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_bytecode_fnv1a_hex(vader_string_t l0) {
    uint64_t l1, l4, l7;
    size_t l2, l3;
    vader_string_t l5 = 0;
    vader_string_t l8 = 0;
    int32_t l6;
    uint8_t t0;
    int64_t t1;
    vader_string_t* gc_atom_roots[3] = { &l0, &l5, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = (uint64_t) -3750763034362895579;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        t0 = vader_host_std_core_byte_at(l0, l3);
        t1 = ((int64_t) (uint8_t) t0);
        l4 = (uint64_t) (int64_t) t1;
        t1 = ((l1 ^ l4) * INT64_C(1099511628211));
        l1 = (uint64_t) (int64_t) t1;
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    l5 = 0u;
    l6 = INT32_C(0);
    while ((l6 < INT32_C(16))) {
        t1 = ((int64_t) (int32_t) ((INT32_C(15) - l6) * INT32_C(4)));
        l4 = (uint64_t) (int64_t) t1;
        t1 = ((l1 >> l4) & INT64_C(15));
        l7 = (uint64_t) (int64_t) t1;
        t1 = ((int64_t) (uint64_t) l7);
        l2 = (size_t) (int64_t) t1;
        t1 = (((int64_t) (uint64_t) l7) + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
        l8 = vader_string_slice_codepoints(315u, l2, l3);
        l5 = concat_2(l5, l8);
        l6 = (l6 + INT32_C(1));
    }
    { vader_string_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_bytecode_foldable_self_copy(void* l0, size_t l1, size_t l2, void* l3) {
    size_t l4;
    void* l5;
    vader_box_t l6;
    int32_t l7, l8;
    int64_t t0;
    vader_box_t t1;
    bool t2;
    void* t3;
    if (((l1 + INT64_C(1)) >= l2)) {
        return false;
    }
    t0 = (l1 + INT64_C(1));
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t1 = vader_box_bool(221u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4]);
    t2 = t1.payload.b;
    if (t2) {
        return false;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
    if (t1.tag == 619u) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l1);
        l5 = t1.payload.obj;
        t0 = (l1 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        if (l6.tag == 621u) {
            t3 = l6.payload.obj;
            l7 = ((vader_struct_vader_bytecode_LocalTee_t*) t3)->f_slot;
            l8 = ((vader_struct_vader_bytecode_LocalGet_t*) l5)->f_slot;
            return l7 == l8;
        }
        if (l6.tag == 620u) {
            t3 = l6.payload.obj;
            l7 = ((vader_struct_vader_bytecode_LocalSet_t*) t3)->f_slot;
            l8 = ((vader_struct_vader_bytecode_LocalGet_t*) l5)->f_slot;
            return l7 == l8;
        }
        return false;
    }
    return false;
}

int32_t vader_bytecode_intern_cell_type(vader_box_t l0, void* l1) {
    int32_t l2, l5;
    vader_string_t l3 = 0;
    vader_string_t l8 = 0;
    vader_box_t l4 = vader_box_null();
    void* l6 = NULL;
    void* l7 = NULL;
    size_t t0;
    int32_t t1;
    vader_box_t* gc_roots[2] = { &l0, &l4 };
    void** gc_raw_roots[3] = { &l1, &l6, &l7 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_bytecode_intern_type(l0, l1);
    l3 = vader_bytecode_type_intern_key(l0);
    l3 = concat_3(173u, l3, 375u);
    l4 = std_collections_MutableMap_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l3);
    if (!(l4.tag == 226u)) {
        t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
        l5 = ((int32_t) (size_t) t0);
        vader_struct_vader_bytecode_BcField_t* _a0_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
        vader_obj_header_init(_a0_obj, 506u);
        _a0_obj->f_name = 2469u;
        _a0_obj->f_type_index = l2;
        l6 = (void*) _a0_obj;
        vader_array_t* _a1_arr = vader_array_new(37u, 0u, 13u, 506u);
        l7 = (void*) _a1_arr;
        vader_array_push((vader_array_t*) l7, vader_ref_box(l6));
        l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
        l8 = vader_bytecode_type_intern_key(l0);
        l8 = concat_2(174u, l8);
        l2 = -(INT32_C(1));
        vader_struct_vader_bytecode_BcStruct_t* _a2_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
        vader_obj_header_init(_a2_obj, 517u);
        _a2_obj->f_name = l8;
        _a2_obj->f_fields = l7;
        _a2_obj->f_c_name = 0u;
        _a2_obj->f_symbol_id = l2;
        l7 = (void*) _a2_obj;
        vader_array_push((vader_array_t*) l6, vader_ref_box(l7));
        std_collections_MutableMap_IndexSet_set_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l3, l5);
        { int32_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((int32_t) l4.payload.i);
    { int32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_bytecode_intern_string(vader_string_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int32_t l3;
    size_t t0;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_collections_MutableMap_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_string_key, l0);
    if (!(l2.tag == 226u)) {
        t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_strings)->length;
        l3 = ((int32_t) (size_t) t0);
        vader_array_push((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_strings, vader_box_string(223u, l0));
        std_collections_MutableMap_IndexSet_set_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_string_key, l0, l3);
        { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((int32_t) l2.payload.i);
    { int32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_bytecode_intern_type(vader_box_t l0, void* l1) {
    uint64_t l2;
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null();
    size_t l4, l5;
    void* l6 = NULL;
    vader_string_t l8 = 0;
    int32_t l9;
    int32_t t0;
    int64_t t1;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_string_t t4 = 0;
    size_t t5;
    void* t6 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l3, &l7, &t3 };
    void** gc_raw_roots[3] = { &l1, &l6, &t6 };
    vader_string_t* gc_atom_roots[2] = { &l8, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_bytecode_type_intern_hash(l0);
    l3 = std_collections_MutableMap_Index_at__u64__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_hash, l2);
    if (l3.tag == 226u) {
        t0 = ((int32_t) l3.payload.i);
        t1 = ((int64_t) (int32_t) t0);
        l4 = (size_t) (int64_t) t1;
        l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_by_slot)->length;
        if ((l4 < l5)) {
            l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_by_slot;
            t0 = ((int32_t) l3.payload.i);
            t1 = ((int64_t) (int32_t) t0);
            l4 = (size_t) (int64_t) t1;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            t2 = vader_bytecode_same_intern_class(l0, l7);
            if (t2) {
                t0 = ((int32_t) l3.payload.i);
                { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    l8 = vader_bytecode_type_intern_key(l0);
    l3 = std_collections_MutableMap_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l8);
    if (l3.tag == 226u) {
        t3 = std_collections_MutableMap_Index_at__u64__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_hash, l2);
        if (t3.tag == 0u) {
            l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_hash;
            l9 = ((int32_t) l3.payload.i);
            std_collections_MutableMap_IndexSet_set_at__u64__i32(l6, l2, l9);
            l9 = ((int32_t) l3.payload.i);
            vader_bytecode_record_slot_type(l1, l9, l0);
            t0 = ((int32_t) l3.payload.i);
            { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = ((int32_t) l3.payload.i);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types_frozen;
    if (t2) {
        t4 = concat_3(1300u, l8, 830u);
        vader_host_std_abort_panic(t4);
        vader_unreachable("a no-return call returned");
    } else {
        t5 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
        l9 = ((int32_t) (size_t) t5);
        vader_struct_vader_bytecode_BcRef_t* _a1_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a1_obj, 514u);
        _a1_obj->f_trait_name = 0u;
        t6 = (void*) _a1_obj;
        l3 = vader_ref_box(t6);
        vader_array_push((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types, l3);
        std_collections_MutableMap_IndexSet_set_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l8, l9);
        t3 = std_collections_MutableMap_Index_at__u64__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_hash, l2);
        if (t3.tag == 0u) {
            std_collections_MutableMap_IndexSet_set_at__u64__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_hash, l2, l9);
        }
        vader_bytecode_record_slot_type(l1, l9, l0);
        l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
        t1 = ((int64_t) (int32_t) l9);
        l4 = (size_t) (int64_t) t1;
        l3 = vader_bytecode_bc_type_of_with_ctx(l0, l1, l9);
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        vader_array_ref_store(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4, l3.payload.obj);
        VADER_WRITE_BARRIER(_a2_slotarr->buf);
        { int32_t __vret = l9; vader_gc_top = gc_frame.prev; return __vret; }
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
        { vader_gc_top = gc_frame.prev; return (uint8_t) 8; }
    }
    t0 = vader_bytecode_is_display_to_string(l0);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 9; }
    }
    if (l0 == 2466u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 20; }
    }
    if (l0 == 2467u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 21; }
    }
    if (l0 == 2465u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 22; }
    }
    if (l0 == 2112u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 1; }
    }
    if (l0 == 2111u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 2; }
    }
    if (l0 == 2113u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 3; }
    }
    if (l0 == 2114u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 4; }
    }
    l1 = vader_bytecode_primitive_member_mangle(2148u, 490u, 1233u);
    if (l0 == l1) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 5; }
    }
    l1 = vader_bytecode_primitive_member_mangle(2148u, 470u, 1653u);
    if (l0 == l1) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 6; }
    }
    if (l0 == 2118u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 7; }
    }
    if (l0 == 2125u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 10; }
    }
    if (l0 == 2126u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 11; }
    }
    if (l0 == 2124u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 12; }
    }
    if (l0 == 2123u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 13; }
    }
    if (l0 == 2128u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 14; }
    }
    if (l0 == 2127u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 15; }
    }
    if (l0 == 2129u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 16; }
    }
    if (l0 == 2131u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 18; }
    }
    if (l0 == 2130u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 19; }
    }
    if (!(l0 == 2104u)) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 17; }
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
        l2 = l0 == INT32_C(6);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(5);
    }
    if (l2) {
        l1 = false;
        return l1;
    }
    if (l0 == INT32_C(18)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(19);
    }
    if (l2) {
        l1 = false;
    } else {
        if (l0 == INT32_C(3)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(4);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(9);
        }
        if (l2) {
            l1 = true;
        } else {
            if (l0 == INT32_C(7)) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(8);
            }
            if (l2) {
                l1 = true;
            } else {
                if (l0 == INT32_C(10)) {
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
                    l2 = l0 == INT32_C(13);
                }
                if (l2) {
                    l1 = true;
                } else {
                    if (l0 == INT32_C(14)) {
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
                        l1 = true;
                    } else {
                        if (l0 == INT32_C(20)) {
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
    if (l0 == 2117u) {
        vader_struct_vader_bytecode_StringCompare_t* _a0_obj = (vader_struct_vader_bytecode_StringCompare_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringCompare_t));
        vader_obj_header_init(_a0_obj, 642u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2121u) {
        vader_struct_vader_bytecode_BufferNew_t* _a1_obj = (vader_struct_vader_bytecode_BufferNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BufferNew_t));
        vader_obj_header_init(_a1_obj, 534u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2107u) {
        vader_struct_vader_bytecode_LoadU8_t* _a2_obj = (vader_struct_vader_bytecode_LoadU8_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LoadU8_t));
        vader_obj_header_init(_a2_obj, 617u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2109u) {
        vader_struct_vader_bytecode_StoreU8_t* _a3_obj = (vader_struct_vader_bytecode_StoreU8_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StoreU8_t));
        vader_obj_header_init(_a3_obj, 641u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2108u) {
        vader_struct_vader_bytecode_MemoryCopy_t* _a4_obj = (vader_struct_vader_bytecode_MemoryCopy_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_MemoryCopy_t));
        vader_obj_header_init(_a4_obj, 624u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2106u) {
        vader_struct_vader_bytecode_BufferToString_t* _a5_obj = (vader_struct_vader_bytecode_BufferToString_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BufferToString_t));
        vader_obj_header_init(_a5_obj, 535u);
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2110u) {
        vader_struct_vader_bytecode_BufferWriteString_t* _a6_obj = (vader_struct_vader_bytecode_BufferWriteString_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BufferWriteString_t));
        vader_obj_header_init(_a6_obj, 536u);
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2116u) {
        vader_struct_vader_bytecode_F64ToBits_t* _a7_obj = (vader_struct_vader_bytecode_F64ToBits_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64ToBits_t));
        vader_obj_header_init(_a7_obj, 566u);
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2120u) {
        vader_struct_vader_bytecode_BitsToF64_t* _a8_obj = (vader_struct_vader_bytecode_BitsToF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BitsToF64_t));
        vader_obj_header_init(_a8_obj, 524u);
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2115u) {
        vader_struct_vader_bytecode_F32ToBits_t* _a9_obj = (vader_struct_vader_bytecode_F32ToBits_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F32ToBits_t));
        vader_obj_header_init(_a9_obj, 553u);
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0 == 2119u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_struct_vader_bytecode_BitsToF32_t* _a10_obj = (vader_struct_vader_bytecode_BitsToF32_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BitsToF32_t));
    vader_obj_header_init(_a10_obj, 523u);
    t0 = (void*) _a10_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_bytecode_is_64_bit_int_val(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(3)) {
        l1 = true;
        return l1;
    }
    if (l0 == INT32_C(8)) {
        l1 = true;
    } else if (l0 == INT32_C(4)) {
        l1 = true;
    } else if (l0 == INT32_C(9)) {
        l1 = true;
    } else if (l0 == INT32_C(0)) {
        l1 = false;
    } else if (l0 == INT32_C(1)) {
        l1 = false;
    } else if (l0 == INT32_C(2)) {
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
    } else if (l0 == INT32_C(17)) {
        l1 = false;
    } else if (l0 == INT32_C(18)) {
        l1 = false;
    } else {
        if (!(l0 == INT32_C(19))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

static bool vader_bytecode_is_display_to_string(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    bool l2;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_strip_core_member(l0, 175u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_types_is_primitive_name(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        l2 = t0 != 2484u;
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        { bool __vret = t0 != 1946u; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

bool vader_bytecode_is_float_val(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(10)) {
        l1 = true;
        return l1;
    }
    if (l0 == INT32_C(11)) {
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
    } else if (l0 == INT32_C(8)) {
        l1 = false;
    } else if (l0 == INT32_C(9)) {
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
    } else if (l0 == INT32_C(17)) {
        l1 = false;
    } else if (l0 == INT32_C(18)) {
        l1 = false;
    } else {
        if (!(l0 == INT32_C(19))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

static bool vader_bytecode_is_int_equals(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t t0 = 0;
    bool t1;
    vader_box_t* gc_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_strip_core_member(l0, 177u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        t1 = vader_types_is_int_name(t0);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
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
        l1 = true;
    } else if (l0 == INT32_C(9)) {
        l1 = true;
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
    } else if (l0 == INT32_C(17)) {
        l1 = false;
    } else if (l0 == INT32_C(18)) {
        l1 = false;
    } else {
        if (!(l0 == INT32_C(19))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

bool vader_bytecode_is_narrow_valtype(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(5)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(0);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(6);
    }
    if (l1) {
        return true;
    }
    return l0 == INT32_C(1);
}

static bool vader_bytecode_is_ref_class(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(18)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(19);
    }
    if (l1) {
        return true;
    }
    return l0 == INT32_C(15);
}

bool vader_bytecode_is_ref_only_element(vader_box_t l0, void* l1) {
    bool l2;
    void* l3;
    size_t l4, l5, l6;
    void* t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    bool t4;
    if (l0.tag == 517u) {
        l2 = true;
        return l2;
    }
    if (l0.tag == 504u) {
        l2 = true;
    } else if (l0.tag == 507u) {
        l2 = true;
    } else if (l0.tag == 513u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val == INT32_C(15);
    } else if (l0.tag == 514u) {
        l2 = false;
    } else {
        if (!(l0.tag == 518u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_BcUnion_t*) t0)->f_variants;
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
            t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
            t2 = ((int64_t) (int32_t) t1);
            l6 = (size_t) (int64_t) t2;
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
            t3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
            t4 = vader_bytecode_is_ref_only_element(t3, l1);
            if (!(t4)) {
                return false;
            }
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
        }
        return true;
    }
    return l2;
}

bool vader_bytecode_is_string_val(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(14)) {
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
    } else if (l0 == INT32_C(12)) {
        l1 = false;
    } else if (l0 == INT32_C(13)) {
        l1 = false;
    } else if (l0 == INT32_C(15)) {
        l1 = false;
    } else if (l0 == INT32_C(16)) {
        l1 = false;
    } else if (l0 == INT32_C(17)) {
        l1 = false;
    } else if (l0 == INT32_C(18)) {
        l1 = false;
    } else {
        if (!(l0 == INT32_C(19))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

static bool vader_bytecode_is_u32_class(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(5)) {
        l1 = true;
        return l1;
    }
    if (l0 == INT32_C(6)) {
        l1 = true;
    } else if (l0 == INT32_C(7)) {
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
    } else if (l0 == INT32_C(17)) {
        l1 = false;
    } else if (l0 == INT32_C(18)) {
        l1 = false;
    } else {
        if (!(l0 == INT32_C(19))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

static bool vader_bytecode_is_u64_class(uint8_t l0) {
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
    } else if (l0 == INT32_C(17)) {
        l1 = false;
    } else if (l0 == INT32_C(18)) {
        l1 = false;
    } else {
        if (!(l0 == INT32_C(19))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

bool vader_bytecode_is_unsigned_display(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    bool l2;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_strip_core_member(l0, 175u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        if (t0 == 2281u) {
            l2 = true;
        } else {
            t0 = l1.payload.s;
            l2 = t0 == 2291u;
        }
        if (l2) {
            l2 = true;
        } else {
            t0 = l1.payload.s;
            l2 = t0 == 2344u;
        }
        { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
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
    size_t l4, l6;
    int32_t l7;
    vader_string_t l8 = 0;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l5 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l8, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 223u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) l1)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (size_t) l4);
    l3 = (void*) _a1_arr;
    l5 = l1;
    l4 = ((vader_array_t*) l5)->length;
    l6 = (size_t) 0;
    while ((l6 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l7 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
        l8 = vader_bytecode_bc_type_key(l0, l7);
        vader_array_push((vader_array_t*) l3, vader_box_string(223u, l8));
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    t1 = std_string_join(l3, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_mark_jump_targets(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l6;
    int32_t l5;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(6u, 1u, 12u, 221u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
        l5 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
        if ((l5 >= INT32_C(0))) {
            if ((((int64_t) (int32_t) l5) < l1)) {
                t1 = ((int64_t) (int32_t) l5);
                l6 = (size_t) (int64_t) t1;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
                ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (uint8_t) true;
            }
        }
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
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
        vader_obj_header_init(_a0_obj, 663u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Mod_t* _a1_obj = (vader_struct_vader_bytecode_U32Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Mod_t));
        vader_obj_header_init(_a1_obj, 657u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Mod_t* _a2_obj = (vader_struct_vader_bytecode_I32Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Mod_t));
        vader_obj_header_init(_a2_obj, 581u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Mod_t* _a3_obj = (vader_struct_vader_bytecode_I64Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Mod_t));
    vader_obj_header_init(_a3_obj, 601u);
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
        vader_obj_header_init(_a0_obj, 564u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Neg_t* _a1_obj = (vader_struct_vader_bytecode_I32Neg_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Neg_t));
        vader_obj_header_init(_a1_obj, 584u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Neg_t* _a2_obj = (vader_struct_vader_bytecode_I64Neg_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Neg_t));
    vader_obj_header_init(_a2_obj, 604u);
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_bytecode_nested_mirror(void* l0, void* l1) {
    size_t l2, l3;
    vader_box_t l4;
    int32_t t0;
    int64_t t1;
    void* t2;
    vader_string_t t3;
    t0 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_type_index;
    if ((t0 < INT32_C(0))) {
        return vader_box_obj(0u, NULL);
    }
    t0 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_type_index;
    t1 = ((int64_t) (int32_t) t0);
    l2 = (size_t) (int64_t) t1;
    l3 = ((vader_array_t*) l1)->length;
    if ((l2 >= l3)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_type_index;
    t1 = ((int64_t) (int32_t) t0);
    l2 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    if (l4.tag == 517u) {
        t2 = l4.payload.obj;
        t3 = ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_c_name;
        if (t3 != 0u) {
            t2 = l4.payload.obj;
            return vader_ref_box(t2);
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
    uint64_t l5;
    void* t0 = NULL;
    void** gc_raw_roots[18] = {
        &l0, &l1, &l2, &l3, &l4, &l6, &l7, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &l16, &l17,
        &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 18u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(171u, 0u, 13u, 1258u);
    l0 = (void*) _a0_arr;
    vader_struct_vader_bytecode_BcPrimitive_t* _a1_obj = (vader_struct_vader_bytecode_BcPrimitive_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPrimitive_t));
    vader_obj_header_init(_a1_obj, 513u);
    _a1_obj->f_val = (uint8_t) 15;
    l1 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l0, vader_ref_box(l1));
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 223u);
    l1 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 226u);
    l2 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 226u);
    l3 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a5_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a5_obj, 353u);
    _a5_obj->f_ekeys = l1;
    _a5_obj->f_evals = l2;
    _a5_obj->f_index = l3;
    _a5_obj->f_mask = (size_t) 0;
    _a5_obj->f_size = (size_t) 0;
    _a5_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a5_obj;
    std_collections_MutableMap_IndexSet_set_at__string__i32(l1, 1946u, INT32_C(0));
    vader_array_t* _a6_arr = vader_array_new(14u, 0u, 4u, 232u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 226u);
    l3 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 226u);
    l4 = (void*) _a8_arr;
    vader_struct_std_collections_MutableMap__u64__i32_t* _a9_obj = (vader_struct_std_collections_MutableMap__u64__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__u64__i32_t));
    vader_obj_header_init(_a9_obj, 367u);
    _a9_obj->f_ekeys = l2;
    _a9_obj->f_evals = l3;
    _a9_obj->f_index = l4;
    _a9_obj->f_mask = (size_t) 0;
    _a9_obj->f_size = (size_t) 0;
    _a9_obj->f_tombs = (size_t) 0;
    l2 = (void*) _a9_obj;
    t0 = (void*) &vader_data_15;
    vader_array_t* _a10_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
    t0 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) INT64_C(0));
    l5 = vader_bytecode_type_intern_hash(vader_ref_box(t0));
    std_collections_MutableMap_IndexSet_set_at__u64__i32(l2, l5, INT32_C(0));
    t0 = (void*) &vader_data_15;
    vader_array_t* _a11_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
    t0 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a12_arr = vader_array_new(186u, 1u, 13u, 1447u);
    ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = t0;
    l3 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(8u, 0u, 0u, 223u);
    l4 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(8u, 0u, 0u, 223u);
    l6 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(9u, 0u, 7u, 226u);
    l7 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(9u, 0u, 7u, 226u);
    l8 = (void*) _a16_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a17_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a17_obj, 353u);
    _a17_obj->f_ekeys = l6;
    _a17_obj->f_evals = l7;
    _a17_obj->f_index = l8;
    _a17_obj->f_mask = (size_t) 0;
    _a17_obj->f_size = (size_t) 0;
    _a17_obj->f_tombs = (size_t) 0;
    l6 = (void*) _a17_obj;
    vader_array_t* _a18_arr = vader_array_new(38u, 0u, 13u, 508u);
    l7 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(9u, 0u, 7u, 226u);
    l8 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(9u, 0u, 7u, 226u);
    l9 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(9u, 0u, 7u, 226u);
    l10 = (void*) _a21_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a22_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a22_obj, 302u);
    _a22_obj->f_ekeys = l8;
    _a22_obj->f_evals = l9;
    _a22_obj->f_index = l10;
    _a22_obj->f_mask = (size_t) 0;
    _a22_obj->f_size = (size_t) 0;
    _a22_obj->f_tombs = (size_t) 0;
    l8 = (void*) _a22_obj;
    vader_array_t* _a23_arr = vader_array_new(8u, 0u, 0u, 223u);
    l9 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(9u, 0u, 7u, 226u);
    l10 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(9u, 0u, 7u, 226u);
    l11 = (void*) _a25_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a26_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a26_obj, 353u);
    _a26_obj->f_ekeys = l9;
    _a26_obj->f_evals = l10;
    _a26_obj->f_index = l11;
    _a26_obj->f_mask = (size_t) 0;
    _a26_obj->f_size = (size_t) 0;
    _a26_obj->f_tombs = (size_t) 0;
    l9 = (void*) _a26_obj;
    vader_array_t* _a27_arr = vader_array_new(39u, 0u, 13u, 509u);
    l10 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(9u, 0u, 7u, 226u);
    l11 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_new(9u, 0u, 7u, 226u);
    l12 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(9u, 0u, 7u, 226u);
    l13 = (void*) _a30_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a31_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a31_obj, 302u);
    _a31_obj->f_ekeys = l11;
    _a31_obj->f_evals = l12;
    _a31_obj->f_index = l13;
    _a31_obj->f_mask = (size_t) 0;
    _a31_obj->f_size = (size_t) 0;
    _a31_obj->f_tombs = (size_t) 0;
    l11 = (void*) _a31_obj;
    vader_array_t* _a32_arr = vader_array_new(8u, 0u, 0u, 223u);
    l12 = (void*) _a32_arr;
    vader_array_t* _a33_arr = vader_array_new(9u, 0u, 7u, 226u);
    l13 = (void*) _a33_arr;
    vader_array_t* _a34_arr = vader_array_new(9u, 0u, 7u, 226u);
    l14 = (void*) _a34_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a35_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a35_obj, 353u);
    _a35_obj->f_ekeys = l12;
    _a35_obj->f_evals = l13;
    _a35_obj->f_index = l14;
    _a35_obj->f_mask = (size_t) 0;
    _a35_obj->f_size = (size_t) 0;
    _a35_obj->f_tombs = (size_t) 0;
    l12 = (void*) _a35_obj;
    vader_array_t* _a36_arr = vader_array_new(36u, 0u, 13u, 505u);
    l13 = (void*) _a36_arr;
    vader_array_t* _a37_arr = vader_array_new(9u, 0u, 7u, 226u);
    l14 = (void*) _a37_arr;
    vader_array_t* _a38_arr = vader_array_new(9u, 0u, 7u, 226u);
    l15 = (void*) _a38_arr;
    vader_array_t* _a39_arr = vader_array_new(16u, 0u, 0u, 234u);
    l16 = (void*) _a39_arr;
    vader_array_t* _a40_arr = vader_array_new(9u, 0u, 7u, 226u);
    l17 = (void*) _a40_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a41_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a41_obj, 271u);
    _a41_obj->f_ekeys = l15;
    _a41_obj->f_evals = l16;
    _a41_obj->f_index = l17;
    _a41_obj->f_mask = (size_t) 0;
    _a41_obj->f_size = (size_t) 0;
    _a41_obj->f_tombs = (size_t) 0;
    l15 = (void*) _a41_obj;
    vader_struct_vader_bytecode_EmitterCtx_t* _a42_obj = (vader_struct_vader_bytecode_EmitterCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_EmitterCtx_t));
    vader_obj_header_init(_a42_obj, 551u);
    _a42_obj->f_types = l0;
    _a42_obj->f_type_key = l1;
    _a42_obj->f_type_hash = l2;
    _a42_obj->f_type_by_slot = l3;
    _a42_obj->f_strings = l4;
    _a42_obj->f_string_key = l6;
    _a42_obj->f_functions = l7;
    _a42_obj->f_function_index_by_symbol_id = l8;
    _a42_obj->f_function_index_by_mangle = l9;
    _a42_obj->f_imports = l10;
    _a42_obj->f_import_index_by_symbol_id = l11;
    _a42_obj->f_import_index_by_mangle = l12;
    _a42_obj->f_exports = l13;
    _a42_obj->f_pinned_types = l14;
    _a42_obj->f_types_frozen = false;
    _a42_obj->f_pinned_types_by_fn = l15;
    t0 = (void*) _a42_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_parse_val_type(vader_string_t l0) {
    if (l0 == 1706u) {
        return vader_box_i32(229u, INT32_C(0));
    }
    if (l0 == 1661u) {
        return vader_box_i32(229u, INT32_C(1));
    }
    if (l0 == 1662u) {
        return vader_box_i32(229u, INT32_C(2));
    }
    if (l0 == 1684u) {
        return vader_box_i32(229u, INT32_C(3));
    }
    if (l0 == 1785u) {
        return vader_box_i32(229u, INT32_C(4));
    }
    if (l0 == 2301u) {
        return vader_box_i32(229u, INT32_C(5));
    }
    if (l0 == 2280u) {
        return vader_box_i32(229u, INT32_C(6));
    }
    if (l0 == 2281u) {
        return vader_box_i32(229u, INT32_C(7));
    }
    if (l0 == 2291u) {
        return vader_box_i32(229u, INT32_C(8));
    }
    if (l0 == 2344u) {
        return vader_box_i32(229u, INT32_C(9));
    }
    if (l0 == 1544u) {
        return vader_box_i32(229u, INT32_C(10));
    }
    if (l0 == 1546u) {
        return vader_box_i32(229u, INT32_C(11));
    }
    if (l0 == 1252u) {
        return vader_box_i32(229u, INT32_C(12));
    }
    if (l0 == 1359u) {
        return vader_box_i32(229u, INT32_C(13));
    }
    if (l0 == 2148u) {
        return vader_box_i32(229u, INT32_C(14));
    }
    if (l0 == 1946u) {
        return vader_box_i32(229u, INT32_C(15));
    }
    if (l0 == 2484u) {
        return vader_box_i32(229u, INT32_C(16));
    }
    if (l0 == 1995u) {
        return vader_box_i32(229u, INT32_C(17));
    }
    if (l0 == 2021u) {
        return vader_box_i32(229u, INT32_C(18));
    }
    if (!(l0 == 1184u)) {
        return vader_box_obj(0u, NULL);
    }
    return vader_box_i32(229u, INT32_C(19));
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
    l1 = vader_bytecode_strip_core_member(l0, 171u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        t1 = vader_types_is_numeric_name(t0);
        if (t1) {
            t0 = l1.payload.s;
            t2 = vader_bytecode_val_type_of_primitive_name(t0);
            t3 = vader_bytecode_arith_op(t2, 1154u);
            { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l1 = vader_bytecode_strip_core_member(l0, 181u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        t1 = vader_types_is_numeric_name(t0);
        if (t1) {
            t0 = l1.payload.s;
            t2 = vader_bytecode_val_type_of_primitive_name(t0);
            t3 = vader_bytecode_arith_op(t2, 2184u);
            { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l1 = vader_bytecode_strip_core_member(l0, 180u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        t1 = vader_types_is_numeric_name(t0);
        if (t1) {
            t0 = l1.payload.s;
            t2 = vader_bytecode_val_type_of_primitive_name(t0);
            t3 = vader_bytecode_arith_op(t2, 1910u);
            { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l1 = vader_bytecode_strip_core_member(l0, 176u);
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
    l1 = vader_bytecode_strip_core_member(l0, 177u);
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l1.payload.s;
    t1 = vader_types_is_primitive_name(t0);
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
    t0 = concat_6(2105u, l0, 170u, l1, 170u, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_bytecode_printed(void* l0, void* l1, vader_string_t l2, void* l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    size_t l5, l6, l9;
    int64_t l10;
    vader_string_t l11 = 0;
    int32_t t0;
    int64_t t1;
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l4, &l7, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_string_builder_append(l0, l2);
    l4 = l3;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l8 = std_core_new_byte_buffer((size_t) 21);
        l9 = (size_t) 0;
        l9 = std_core_write_string_at(l8, l9, 8u);
        t0 = ((vader_struct_vader_bytecode_OperandRef_t*) l7)->f_index;
        l10 = ((int64_t) (int32_t) t0);
        l9 = std_core_write_int(l8, l9, l10);
        l11 = std_core_finish_buffer(l8, l9);
        std_string_builder_append(l0, l11);
        vader_array_push((vader_array_t*) l1, vader_ref_box(l7));
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void* vader_bytecode_propagate_const_single_use(void* l0) {
    size_t l1, l2, l8, l12, l14, l15, l17;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l11 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    int32_t l9, l10, l16, l18, l19;
    vader_box_t l13 = vader_box_null(), l25 = vader_box_null(), l27 = vader_box_null(), l28 = vader_box_null(), l29 = vader_box_null();
    bool l24;
    uint8_t l26;
    vader_string_t l30 = 0;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    bool t3;
    vader_box_t t4 = vader_box_null();
    size_t t5;
    vader_box_t* gc_roots[6] = { &l13, &l25, &l27, &l28, &l29, &t4 };
    void** gc_raw_roots[12] = { &l0, &l3, &l4, &l5, &l6, &l7, &l11, &l20, &l21, &l22, &l23, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l30 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    t0 = (l1 + l2);
    l2 = (size_t) (int64_t) t0;
    if ((l2 <= l1)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 226u);
    t1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 226u);
    t1 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 226u);
    t1 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l5 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 226u);
    t1 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l6 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 226u);
    t1 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l7 = (void*) _a9_arr;
    l8 = (size_t) 0;
    while ((l8 < l2)) {
        vader_array_push_i32((vader_array_t*) l3, INT32_C(0));
        vader_array_push_i32((vader_array_t*) l4, INT32_C(0));
        vader_array_push_i32((vader_array_t*) l5, INT32_C(0));
        l9 = -(INT32_C(1));
        vader_array_push_i32((vader_array_t*) l6, l9);
        l10 = -(INT32_C(1));
        vader_array_push_i32((vader_array_t*) l7, l10);
        t0 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t0;
    }
    l11 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l8 = ((vader_array_t*) l11)->length;
    l12 = (size_t) 0;
    while ((l12 < l8)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l12)
        l13 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l12);
        if (l13.tag == 620u) {
            t1 = l13.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalSet_t*) t1)->f_slot;
            t0 = ((int64_t) (int32_t) t2);
            l14 = (size_t) (int64_t) t0;
            vader_array_t* _a11_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l14)
            t2 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l14];
            l9 = (t2 + INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l14)
            ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l14] = (int32_t) l9;
            l10 = ((int32_t) (size_t) l12);
            vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l14)
            ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l14] = (int32_t) l10;
        }
        if (l13.tag == 621u) {
            t1 = l13.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalTee_t*) t1)->f_slot;
            t0 = ((int64_t) (int32_t) t2);
            l15 = (size_t) (int64_t) t0;
            vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l15)
            t2 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l15];
            l16 = (t2 + INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l15)
            ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l15] = (int32_t) l16;
        }
        if (l13.tag == 619u) {
            t1 = l13.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalGet_t*) t1)->f_slot;
            t0 = ((int64_t) (int32_t) t2);
            l17 = (size_t) (int64_t) t0;
            vader_array_t* _a14_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l17)
            t2 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l17];
            l18 = (t2 + INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l17)
            ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l17] = (int32_t) l18;
            l19 = ((int32_t) (size_t) l12);
            vader_array_t* _a15_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l17)
            ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l17] = (int32_t) l19;
        }
        t0 = (l12 + INT64_C(1));
        l12 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a16_arr = vader_array_new(9u, 0u, 7u, 226u);
    l20 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(6u, 0u, 12u, 221u);
    l21 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(9u, 0u, 7u, 226u);
    l22 = (void*) _a18_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a19_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a19_obj, 301u);
    _a19_obj->f_ekeys = l20;
    _a19_obj->f_evals = l21;
    _a19_obj->f_index = l22;
    _a19_obj->f_mask = (size_t) 0;
    _a19_obj->f_size = (size_t) 0;
    _a19_obj->f_tombs = (size_t) 0;
    l20 = (void*) _a19_obj;
    vader_array_t* _a20_arr = vader_array_new(9u, 0u, 7u, 226u);
    l21 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(16u, 0u, 0u, 234u);
    l22 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_new(9u, 0u, 7u, 226u);
    l23 = (void*) _a22_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a23_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a23_obj, 269u);
    _a23_obj->f_ekeys = l21;
    _a23_obj->f_evals = l22;
    _a23_obj->f_index = l23;
    _a23_obj->f_mask = (size_t) 0;
    _a23_obj->f_size = (size_t) 0;
    _a23_obj->f_tombs = (size_t) 0;
    l21 = (void*) _a23_obj;
    l12 = l1;
    while ((l12 < l2)) {
        l24 = true;
        vader_array_t* _a24_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l12)
        t2 = ((int32_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l12];
        if (t2 != INT32_C(0)) {
            l24 = false;
        }
        vader_array_t* _a25_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l12)
        t2 = ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l12];
        if (t2 != INT32_C(1)) {
            l24 = false;
        }
        vader_array_t* _a26_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l12)
        t2 = ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l12];
        if (t2 != INT32_C(1)) {
            l24 = false;
        }
        l9 = -(INT32_C(1));
        l10 = -(INT32_C(1));
        if (l24) {
            vader_array_t* _a27_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l12)
            l9 = ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l12];
            vader_array_t* _a28_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l12)
            l10 = ((int32_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l12];
            if ((l9 <= INT32_C(0))) {
                l24 = false;
            }
            if ((l10 <= l9)) {
                l24 = false;
            }
        }
        if (l24) {
            t0 = ((int64_t) (int32_t) (l9 - INT32_C(1)));
            l14 = (size_t) (int64_t) t0;
            vader_array_t* _a29_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l14)
            l13 = vader_array_ref_load_box(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l14);
            l25 = vader_bytecode_const_op_of(l13);
            if (l25.tag == 0u) {
                l24 = false;
            } else {
                l22 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
                t0 = (l12 - l1);
                l15 = (size_t) (int64_t) t0;
                vader_array_t* _a30_slotarr = ((vader_array_t*) l22);
                VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l15)
                t1 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l15);
                l26 = ((vader_struct_vader_bytecode_BcLocal_t*) t1)->f_val;
                t3 = vader_bytecode_const_fills_slot(l25, l26);
                if (t3) {
                    l16 = (l9 - INT32_C(1));
                    std_collections_MutableMap_IndexSet_set_at__i32__bool(l20, l16, true);
                    std_collections_MutableMap_IndexSet_set_at__i32__bool(l20, l9, true);
                    std_collections_MutableMap_IndexSet_set_at__i32__Any(l21, l10, l13);
                } else {
                    l24 = false;
                }
            }
        }
        t0 = (l12 + INT64_C(1));
        l12 = (size_t) (int64_t) t0;
    }
    t3 = std_collections_is_empty__i32__bool(l20);
    if (t3) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a31_arr = vader_array_new(169u, 0u, 13u, 1235u);
    l3 = (void*) _a31_arr;
    vader_array_t* _a32_arr = vader_array_new(173u, 0u, 13u, 1289u);
    l4 = (void*) _a32_arr;
    vader_array_t* _a33_arr = vader_array_new(9u, 0u, 7u, 226u);
    t1 = (void*) _a33_arr;
    vader_array_t* _a34_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l8);
    l5 = (void*) _a34_arr;
    l1 = (size_t) 0;
    vader_array_t* _pc340_hdr = (vader_array_t*) l5;
    size_t _pc340_len = _pc340_hdr->length;
    size_t _pc340_cap = (_pc340_hdr->offset == 0 && !vader_array_is_borrowed(_pc340_hdr) && _pc340_hdr->length >= _pc340_hdr->buf->length) ? _pc340_hdr->capacity : (size_t) 0;
    void* _pc340_slots = _pc340_hdr->buf->slots;
    for (;;) {
        if ((l1 < l8)) {
            l9 = -(INT32_C(1));
            if (VADER_LIKELY(_pc340_len < _pc340_cap)) {
                ((int32_t*) _pc340_slots)[_pc340_len] = (int32_t) (l9);
                _pc340_len += 1;
            } else {
                _pc340_hdr->length = _pc340_len;
                if (_pc340_hdr->buf->length < _pc340_len) {
                    _pc340_hdr->buf->length = _pc340_len;
                }
                vader_array_push_i32((vader_array_t*) l5, l9);
                _pc340_hdr = (vader_array_t*) l5;
                _pc340_len = _pc340_hdr->length;
                _pc340_cap = (_pc340_hdr->offset == 0 && !vader_array_is_borrowed(_pc340_hdr) && _pc340_hdr->length >= _pc340_hdr->buf->length) ? _pc340_hdr->capacity : (size_t) 0;
                _pc340_slots = _pc340_hdr->buf->slots;
            }
            t0 = (l1 + INT64_C(1));
            l1 = (size_t) (int64_t) t0;
            continue;
        }
        _pc340_hdr->length = _pc340_len;
        if (_pc340_hdr->buf->length < _pc340_len) {
            _pc340_hdr->buf->length = _pc340_len;
        }
        break;
    }
    l1 = (size_t) 0;
    while ((l1 < l8)) {
        l9 = ((int32_t) (size_t) l1);
        t4 = std_collections_MutableMap_Index_at__i32__bool(l20, l9);
        if (t4.tag == 221u) {
            t0 = (l1 + INT64_C(1));
            l1 = (size_t) (int64_t) t0;
            continue;
        }
        l10 = ((int32_t) (size_t) l1);
        l13 = std_collections_MutableMap_Index_at__i32__Any(l21, l10);
        if (l13.tag == 0u) {
            t5 = ((vader_array_t*) l3)->length;
            l16 = ((int32_t) (size_t) t5);
            vader_array_t* _a35_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l1)
            ((int32_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l1] = (int32_t) l16;
            vader_array_t* _a36_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l1)
            l25 = vader_array_ref_load_box(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l1);
            vader_array_push((vader_array_t*) l3, l25);
            vader_array_t* _a37_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l1)
            l27 = vader_array_ref_load_box(_a37_slotarr->buf, _a37_slotarr->offset + (size_t) l1);
            vader_array_push((vader_array_t*) l4, l27);
        } else {
            t5 = ((vader_array_t*) l3)->length;
            l18 = ((int32_t) (size_t) t5);
            vader_array_t* _a38_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l1)
            ((int32_t*) _a38_slotarr->buf->slots)[_a38_slotarr->offset + (size_t) l1] = (int32_t) l18;
            l28 = l13;
            vader_array_push((vader_array_t*) l3, l28);
            vader_array_t* _a39_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug);
            VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l1)
            l29 = vader_array_ref_load_box(_a39_slotarr->buf, _a39_slotarr->offset + (size_t) l1);
            vader_array_push((vader_array_t*) l4, l29);
        }
        t0 = (l1 + INT64_C(1));
        l1 = (size_t) (int64_t) t0;
    }
    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l1 = ((vader_array_t*) l3)->length;
    l5 = vader_bytecode_remap_jump_table(l6, l5, l1);
    l6 = l0;
    l30 = ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_name;
    l24 = ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_is_main;
    l7 = ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_signature;
    l11 = ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_locals;
    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_source_pc;
    vader_struct_vader_bytecode_BcFunction_t* _a40_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a40_obj, 508u);
    _a40_obj->f_name = l30;
    _a40_obj->f_is_main = l24;
    _a40_obj->f_signature = l7;
    _a40_obj->f_locals = l11;
    _a40_obj->f_body = l3;
    _a40_obj->f_debug = l4;
    _a40_obj->f_jump_table = l5;
    _a40_obj->f_source_pc = l6;
    t1 = (void*) _a40_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_bytecode_prune_unused_functions(void* l0, void* l1, void* l2) {
    size_t l3, l7, l11, l14, l15, l16, l17, l31;
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
    void* l32 = NULL;
    int32_t l8, l10, l19, l23, l24;
    vader_string_t l9 = 0;
    vader_string_t l33 = 0;
    vader_box_t l18 = vader_box_null();
    bool l20, l21, l22;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    size_t t4;
    int32_t t5;
    vader_string_t t6 = 0;
    vader_box_t* gc_roots[2] = { &l18, &t3 };
    void** gc_raw_roots[16] = {
        &l0, &l1, &l2, &l4, &l5, &l6, &l12, &l13, &l25, &l26, &l27, &l28, &l29, &l30, &l32, &t2,
    };
    vader_string_t* gc_atom_roots[3] = { &l9, &l33, &t6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 16u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions)->length;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 226u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 221u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 226u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 301u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l5;
    _a3_obj->f_index = l6;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l4 = (void*) _a3_obj;
    l7 = (size_t) 0;
    while ((l7 < l3)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        l5 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l7);
        t0 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_is_main;
        if (t0) {
            l8 = ((int32_t) (size_t) l7);
            std_collections_MutableMap_IndexSet_set_at__i32__bool(l4, l8, true);
        }
        l9 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_name;
        t0 = std_core____Contains_contains__string(l2, l9);
        if (t0) {
            l10 = ((int32_t) (size_t) l7);
            std_collections_MutableMap_IndexSet_set_at__i32__bool(l4, l10, true);
        }
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_exports;
    l7 = ((vader_array_t*) l5)->length;
    l11 = (size_t) 0;
    while ((l11 < l7)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l11)
        t2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l11);
        l8 = ((vader_struct_vader_bytecode_BcExport_t*) t2)->f_fn_index;
        std_collections_MutableMap_IndexSet_set_at__i32__bool(l4, l8, true);
        t1 = (l11 + INT64_C(1));
        l11 = (size_t) (int64_t) t1;
    }
    l5 = l1;
    l7 = ((vader_array_t*) l5)->length;
    l11 = (size_t) 0;
    while ((l11 < l7)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l11)
        l8 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l11];
        if ((l8 >= INT32_C(0))) {
            l10 = ((int32_t) (size_t) l3);
            if ((l8 < l10)) {
                std_collections_MutableMap_IndexSet_set_at__i32__bool(l4, l8, true);
            }
        }
        t1 = (l11 + INT64_C(1));
        l11 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 226u);
    l5 = (void*) _a7_arr;
    l6 = l4;
    l12 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l6)->f_ekeys;
    l13 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l6)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l6)->f_size;
    l11 = (size_t) 0;
    vader_array_t* _pc140_hdr = (vader_array_t*) l5;
    size_t _pc140_len = _pc140_hdr->length;
    size_t _pc140_cap = (_pc140_hdr->offset == 0 && !vader_array_is_borrowed(_pc140_hdr) && _pc140_hdr->length >= _pc140_hdr->buf->length) ? _pc140_hdr->capacity : (size_t) 0;
    void* _pc140_slots = _pc140_hdr->buf->slots;
    for (;;) {
        if (!((l11 >= l7))) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l11)
            l8 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l11];
            vader_array_t* _a9_slotarr = ((vader_array_t*) l13);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l11)
            t3 = vader_box_bool(221u, ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l11]);
            t0 = t3.payload.b;
            l10 = l8;
            t1 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t1;
            if (VADER_LIKELY(_pc140_len < _pc140_cap)) {
                ((int32_t*) _pc140_slots)[_pc140_len] = (int32_t) (l10);
                _pc140_len += 1;
            } else {
                _pc140_hdr->length = _pc140_len;
                if (_pc140_hdr->buf->length < _pc140_len) {
                    _pc140_hdr->buf->length = _pc140_len;
                }
                vader_array_push_i32((vader_array_t*) l5, l10);
                _pc140_hdr = (vader_array_t*) l5;
                _pc140_len = _pc140_hdr->length;
                _pc140_cap = (_pc140_hdr->offset == 0 && !vader_array_is_borrowed(_pc140_hdr) && _pc140_hdr->length >= _pc140_hdr->buf->length) ? _pc140_hdr->capacity : (size_t) 0;
                _pc140_slots = _pc140_hdr->buf->slots;
            }
            continue;
        }
        _pc140_hdr->length = _pc140_len;
        if (_pc140_hdr->buf->length < _pc140_len) {
            _pc140_hdr->buf->length = _pc140_len;
        }
        break;
    }
    for (;;) {
        t4 = ((vader_array_t*) l5)->length;
        if ((t4 > INT64_C(0))) {
            t4 = ((vader_array_t*) l5)->length;
            t1 = (t4 - INT64_C(1));
            l7 = (size_t) (int64_t) t1;
            vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l7)
            l8 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l7];
            vader_array_t* _a11_arr = vader_array_new(9u, 0u, 7u, 226u);
            l6 = (void*) _a11_arr;
            l11 = (size_t) 0;
            t4 = ((vader_array_t*) l5)->length;
            t1 = (t4 - INT64_C(1));
            l14 = (size_t) (int64_t) t1;
            vader_array_t* _pc191_hdr = (vader_array_t*) l6;
            size_t _pc191_len = _pc191_hdr->length;
            size_t _pc191_cap = (_pc191_hdr->offset == 0 && !vader_array_is_borrowed(_pc191_hdr) && _pc191_hdr->length >= _pc191_hdr->buf->length) ? _pc191_hdr->capacity : (size_t) 0;
            void* _pc191_slots = _pc191_hdr->buf->slots;
            for (;;) {
                if ((l11 < l14)) {
                    vader_array_t* _a12_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l11)
                    l10 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l11];
                    if (VADER_LIKELY(_pc191_len < _pc191_cap)) {
                        ((int32_t*) _pc191_slots)[_pc191_len] = (int32_t) (l10);
                        _pc191_len += 1;
                    } else {
                        _pc191_hdr->length = _pc191_len;
                        if (_pc191_hdr->buf->length < _pc191_len) {
                            _pc191_hdr->buf->length = _pc191_len;
                        }
                        vader_array_push_i32((vader_array_t*) l6, l10);
                        _pc191_hdr = (vader_array_t*) l6;
                        _pc191_len = _pc191_hdr->length;
                        _pc191_cap = (_pc191_hdr->offset == 0 && !vader_array_is_borrowed(_pc191_hdr) && _pc191_hdr->length >= _pc191_hdr->buf->length) ? _pc191_hdr->capacity : (size_t) 0;
                        _pc191_slots = _pc191_hdr->buf->slots;
                    }
                    t1 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t1;
                    continue;
                }
                _pc191_hdr->length = _pc191_len;
                if (_pc191_hdr->buf->length < _pc191_len) {
                    _pc191_hdr->buf->length = _pc191_len;
                }
                break;
            }
            l5 = l6;
            if ((((int64_t) (int32_t) l8) >= l3)) {
                continue;
            }
            l12 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
            t1 = ((int64_t) (int32_t) l8);
            l15 = (size_t) (int64_t) t1;
            vader_array_t* _a13_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l15)
            t2 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l15);
            l13 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_body;
            l16 = ((vader_array_t*) l13)->length;
            l17 = (size_t) 0;
            while ((l17 < l16)) {
                vader_array_t* _a14_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l17)
                l18 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l17);
                l19 = -(INT32_C(1));
                if (l18.tag == 539u) {
                    t2 = l18.payload.obj;
                    l19 = ((vader_struct_vader_bytecode_Call_t*) t2)->f_function_index;
                }
                if (l18.tag == 568u) {
                    t2 = l18.payload.obj;
                    l19 = ((vader_struct_vader_bytecode_FnRef_t*) t2)->f_function_index;
                }
                if (l18.tag == 567u) {
                    t2 = l18.payload.obj;
                    l19 = ((vader_struct_vader_bytecode_FnAddr_t*) t2)->f_function_index;
                }
                if (l18.tag == 623u) {
                    t2 = l18.payload.obj;
                    l19 = ((vader_struct_vader_bytecode_MakeClosure_t*) t2)->f_function_index;
                }
                if ((l19 < INT32_C(0))) {
                    t1 = (l17 + INT64_C(1));
                    l17 = (size_t) (int64_t) t1;
                    continue;
                }
                t3 = std_collections_MutableMap_Index_at__i32__bool(l4, l19);
                if (t3.tag == 221u) {
                    t1 = (l17 + INT64_C(1));
                    l17 = (size_t) (int64_t) t1;
                    continue;
                }
                std_collections_MutableMap_IndexSet_set_at__i32__bool(l4, l19, true);
                vader_array_push_i32((vader_array_t*) l5, l19);
                t1 = (l17 + INT64_C(1));
                l17 = (size_t) (int64_t) t1;
            }
            continue;
        }
        break;
    }
    l20 = std_collections_is_empty__i32__bool(l4);
    vader_array_t* _a15_arr = vader_array_new(8u, 0u, 0u, 223u);
    l5 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(9u, 0u, 7u, 226u);
    l6 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(9u, 0u, 7u, 226u);
    l12 = (void*) _a17_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a18_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a18_obj, 353u);
    _a18_obj->f_ekeys = l5;
    _a18_obj->f_evals = l6;
    _a18_obj->f_index = l12;
    _a18_obj->f_mask = (size_t) 0;
    _a18_obj->f_size = (size_t) 0;
    _a18_obj->f_tombs = (size_t) 0;
    l5 = (void*) _a18_obj;
    l21 = false;
    l7 = (size_t) 0;
    while ((l7 < l3)) {
        if (l20) {
            l22 = true;
        } else {
            l8 = ((int32_t) (size_t) l7);
            t3 = std_collections_MutableMap_Index_at__i32__bool(l4, l8);
            l22 = t3.tag == 221u;
        }
        if (l22) {
            vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l7);
            l9 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_name;
            if (l9 != 0u) {
                l18 = std_collections_MutableMap_Index_at__string__i32(l5, l9);
                if (l18.tag == 226u) {
                    l21 = true;
                    vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
                    VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l7)
                    t2 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l7);
                    t4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_body)->length;
                    if ((t4 > INT64_C(0))) {
                        l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
                        t5 = ((int32_t) l18.payload.i);
                        t1 = ((int64_t) (int32_t) t5);
                        l11 = (size_t) (int64_t) t1;
                        vader_array_t* _a21_slotarr = ((vader_array_t*) l6);
                        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l11)
                        t2 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l11);
                        t4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_body)->length;
                        if (t4 == INT64_C(0)) {
                            l10 = ((int32_t) (size_t) l7);
                            std_collections_MutableMap_IndexSet_set_at__string__i32(l5, l9, l10);
                        }
                    }
                } else {
                    l19 = ((int32_t) (size_t) l7);
                    std_collections_MutableMap_IndexSet_set_at__string__i32(l5, l9, l19);
                }
            }
        }
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    if (!(l21)) {
        if (l20) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        t4 = std_collections_len__i32__bool(l4);
        if (t4 == l3) {
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    vader_array_t* _a22_arr = vader_array_new(9u, 0u, 7u, 226u);
    t2 = (void*) _a22_arr;
    vader_array_t* _a23_arr = vader_array_repeat((vader_array_t*) t2, (size_t) l3);
    l6 = (void*) _a23_arr;
    l7 = (size_t) 0;
    while ((l7 < l3)) {
        vader_array_t* _a24_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l7)
        t2 = vader_array_ref_load_obj(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l7);
        l9 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_name;
        l8 = ((int32_t) (size_t) l7);
        if (l9 != 0u) {
            l18 = std_collections_MutableMap_Index_at__string__i32(l5, l9);
            if (l18.tag == 226u) {
                l8 = ((int32_t) l18.payload.i);
            }
        }
        vader_array_push_i32((vader_array_t*) l6, l8);
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a25_arr = vader_array_new(9u, 0u, 7u, 226u);
    l5 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(9u, 0u, 7u, 226u);
    l12 = (void*) _a26_arr;
    vader_array_t* _a27_arr = vader_array_new(9u, 0u, 7u, 226u);
    l13 = (void*) _a27_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a28_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a28_obj, 302u);
    _a28_obj->f_ekeys = l5;
    _a28_obj->f_evals = l12;
    _a28_obj->f_index = l13;
    _a28_obj->f_mask = (size_t) 0;
    _a28_obj->f_size = (size_t) 0;
    _a28_obj->f_tombs = (size_t) 0;
    l5 = (void*) _a28_obj;
    vader_array_t* _a29_arr = vader_array_new(38u, 0u, 13u, 508u);
    l12 = (void*) _a29_arr;
    l7 = (size_t) 0;
    while ((l7 < l3)) {
        {
            if (!(l20)) {
                l8 = ((int32_t) (size_t) l7);
                t3 = std_collections_MutableMap_Index_at__i32__bool(l4, l8);
                if (!(t3.tag == 221u)) {
                    goto end_510;
                }
            }
            vader_array_t* _a30_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l7)
            l10 = ((int32_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l7];
            l19 = ((int32_t) (size_t) l7);
            if (l10 == l19) {
                l23 = ((int32_t) (size_t) l7);
                t4 = ((vader_array_t*) l12)->length;
                l24 = ((int32_t) (size_t) t4);
                std_collections_MutableMap_IndexSet_set_at__i32__i32(l5, l23, l24);
                vader_array_t* _a31_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
                VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l7)
                l13 = vader_array_ref_load_obj(_a31_slotarr->buf, _a31_slotarr->offset + (size_t) l7);
                vader_array_push((vader_array_t*) l12, vader_ref_box(l13));
            }
        } end_510: ;
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a32_arr = vader_array_new(9u, 0u, 7u, 226u);
    t2 = (void*) _a32_arr;
    vader_array_t* _a33_arr = vader_array_repeat((vader_array_t*) t2, (size_t) l3);
    l13 = (void*) _a33_arr;
    l7 = (size_t) 0;
    vader_array_t* _pc570_hdr = (vader_array_t*) l13;
    size_t _pc570_len = _pc570_hdr->length;
    size_t _pc570_cap = (_pc570_hdr->offset == 0 && !vader_array_is_borrowed(_pc570_hdr) && _pc570_hdr->length >= _pc570_hdr->buf->length) ? _pc570_hdr->capacity : (size_t) 0;
    void* _pc570_slots = _pc570_hdr->buf->slots;
    for (;;) {
        if ((l7 < l3)) {
            l8 = -(INT32_C(1));
            if (l20) {
                l21 = true;
            } else {
                l10 = ((int32_t) (size_t) l7);
                t3 = std_collections_MutableMap_Index_at__i32__bool(l4, l10);
                l21 = t3.tag == 221u;
            }
            if (l21) {
                vader_array_t* _a34_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l7)
                l19 = ((int32_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l7];
                l18 = std_collections_MutableMap_Index_at__i32__i32(l5, l19);
                if (l18.tag == 226u) {
                    l8 = ((int32_t) l18.payload.i);
                }
            }
            if (VADER_LIKELY(_pc570_len < _pc570_cap)) {
                ((int32_t*) _pc570_slots)[_pc570_len] = (int32_t) (l8);
                _pc570_len += 1;
            } else {
                _pc570_hdr->length = _pc570_len;
                if (_pc570_hdr->buf->length < _pc570_len) {
                    _pc570_hdr->buf->length = _pc570_len;
                }
                vader_array_push_i32((vader_array_t*) l13, l8);
                _pc570_hdr = (vader_array_t*) l13;
                _pc570_len = _pc570_hdr->length;
                _pc570_cap = (_pc570_hdr->offset == 0 && !vader_array_is_borrowed(_pc570_hdr) && _pc570_hdr->length >= _pc570_hdr->buf->length) ? _pc570_hdr->capacity : (size_t) 0;
                _pc570_slots = _pc570_hdr->buf->slots;
            }
            t1 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t1;
            continue;
        }
        _pc570_hdr->length = _pc570_len;
        if (_pc570_hdr->buf->length < _pc570_len) {
            _pc570_hdr->buf->length = _pc570_len;
        }
        break;
    }
    l4 = l12;
    l3 = ((vader_array_t*) l4)->length;
    l7 = (size_t) 0;
    while ((l7 < l3)) {
        vader_array_t* _a35_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l7)
        l5 = vader_array_ref_load_obj(_a35_slotarr->buf, _a35_slotarr->offset + (size_t) l7);
        l11 = (size_t) 0;
        l14 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body)->length;
        while ((l11 < l14)) {
            vader_array_t* _a36_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l11)
            l18 = vader_array_ref_load_box(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l11);
            if (l18.tag == 539u) {
                l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body;
                t2 = l18.payload.obj;
                t5 = ((vader_struct_vader_bytecode_Call_t*) t2)->f_function_index;
                t1 = ((int64_t) (int32_t) t5);
                l15 = (size_t) (int64_t) t1;
                vader_array_t* _a37_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l15)
                t5 = ((int32_t*) _a37_slotarr->buf->slots)[_a37_slotarr->offset + (size_t) l15];
                vader_struct_vader_bytecode_Call_t* _a38_obj = (vader_struct_vader_bytecode_Call_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Call_t));
                vader_obj_header_init(_a38_obj, 539u);
                _a38_obj->f_function_index = t5;
                l25 = (void*) _a38_obj;
                vader_array_t* _a39_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l11)
                vader_array_ref_store(_a39_slotarr->buf, _a39_slotarr->offset + (size_t) l11, l25);
                VADER_WRITE_BARRIER(_a39_slotarr->buf);
            }
            if (l18.tag == 568u) {
                l26 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body;
                t2 = l18.payload.obj;
                t5 = ((vader_struct_vader_bytecode_FnRef_t*) t2)->f_function_index;
                t1 = ((int64_t) (int32_t) t5);
                l16 = (size_t) (int64_t) t1;
                vader_array_t* _a40_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l16)
                l8 = ((int32_t*) _a40_slotarr->buf->slots)[_a40_slotarr->offset + (size_t) l16];
                t2 = l18.payload.obj;
                l10 = ((vader_struct_vader_bytecode_FnRef_t*) t2)->f_type_id;
                vader_struct_vader_bytecode_FnRef_t* _a41_obj = (vader_struct_vader_bytecode_FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnRef_t));
                vader_obj_header_init(_a41_obj, 568u);
                _a41_obj->f_function_index = l8;
                _a41_obj->f_type_id = l10;
                l27 = (void*) _a41_obj;
                vader_array_t* _a42_slotarr = ((vader_array_t*) l26);
                VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l11)
                vader_array_ref_store(_a42_slotarr->buf, _a42_slotarr->offset + (size_t) l11, l27);
                VADER_WRITE_BARRIER(_a42_slotarr->buf);
            }
            if (l18.tag == 567u) {
                l28 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body;
                t2 = l18.payload.obj;
                t5 = ((vader_struct_vader_bytecode_FnAddr_t*) t2)->f_function_index;
                t1 = ((int64_t) (int32_t) t5);
                l17 = (size_t) (int64_t) t1;
                vader_array_t* _a43_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l17)
                t5 = ((int32_t*) _a43_slotarr->buf->slots)[_a43_slotarr->offset + (size_t) l17];
                vader_struct_vader_bytecode_FnAddr_t* _a44_obj = (vader_struct_vader_bytecode_FnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnAddr_t));
                vader_obj_header_init(_a44_obj, 567u);
                _a44_obj->f_function_index = t5;
                l29 = (void*) _a44_obj;
                vader_array_t* _a45_slotarr = ((vader_array_t*) l28);
                VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l11)
                vader_array_ref_store(_a45_slotarr->buf, _a45_slotarr->offset + (size_t) l11, l29);
                VADER_WRITE_BARRIER(_a45_slotarr->buf);
            }
            if (l18.tag == 623u) {
                l30 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body;
                t2 = l18.payload.obj;
                t5 = ((vader_struct_vader_bytecode_MakeClosure_t*) t2)->f_function_index;
                t1 = ((int64_t) (int32_t) t5);
                l31 = (size_t) (int64_t) t1;
                vader_array_t* _a46_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l31)
                l19 = ((int32_t*) _a46_slotarr->buf->slots)[_a46_slotarr->offset + (size_t) l31];
                t2 = l18.payload.obj;
                l23 = ((vader_struct_vader_bytecode_MakeClosure_t*) t2)->f_env_type_id;
                vader_struct_vader_bytecode_MakeClosure_t* _a47_obj = (vader_struct_vader_bytecode_MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_MakeClosure_t));
                vader_obj_header_init(_a47_obj, 623u);
                _a47_obj->f_function_index = l19;
                _a47_obj->f_env_type_id = l23;
                l32 = (void*) _a47_obj;
                vader_array_t* _a48_slotarr = ((vader_array_t*) l30);
                VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a48_slotarr, l11)
                vader_array_ref_store(_a48_slotarr->buf, _a48_slotarr->offset + (size_t) l11, l32);
                VADER_WRITE_BARRIER(_a48_slotarr->buf);
            }
            t1 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t1;
        }
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a49_arr = vader_array_new(36u, 0u, 13u, 505u);
    l4 = (void*) _a49_arr;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_exports;
    l3 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    while ((l7 < l3)) {
        vader_array_t* _a50_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a50_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a50_slotarr, l7)
        l6 = vader_array_ref_load_obj(_a50_slotarr->buf, _a50_slotarr->offset + (size_t) l7);
        t5 = ((vader_struct_vader_bytecode_BcExport_t*) l6)->f_fn_index;
        t1 = ((int64_t) (int32_t) t5);
        l11 = (size_t) (int64_t) t1;
        vader_array_t* _a51_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a51_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a51_slotarr, l11)
        l8 = ((int32_t*) _a51_slotarr->buf->slots)[_a51_slotarr->offset + (size_t) l11];
        if ((l8 >= INT32_C(0))) {
            t6 = ((vader_struct_vader_bytecode_BcExport_t*) l6)->f_extern_name;
            vader_struct_vader_bytecode_BcExport_t* _a52_obj = (vader_struct_vader_bytecode_BcExport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcExport_t));
            vader_obj_header_init(_a52_obj, 505u);
            _a52_obj->f_extern_name = t6;
            _a52_obj->f_fn_index = l8;
            l25 = (void*) _a52_obj;
            vader_array_push((vader_array_t*) l4, vader_ref_box(l25));
        }
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_exports = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    vader_array_t* _a53_arr = vader_array_new(9u, 0u, 7u, 226u);
    l4 = (void*) _a53_arr;
    vader_array_t* _a54_arr = vader_array_new(9u, 0u, 7u, 226u);
    l5 = (void*) _a54_arr;
    vader_array_t* _a55_arr = vader_array_new(9u, 0u, 7u, 226u);
    l6 = (void*) _a55_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a56_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a56_obj, 302u);
    _a56_obj->f_ekeys = l4;
    _a56_obj->f_evals = l5;
    _a56_obj->f_index = l6;
    _a56_obj->f_mask = (size_t) 0;
    _a56_obj->f_size = (size_t) 0;
    _a56_obj->f_tombs = (size_t) 0;
    l4 = (void*) _a56_obj;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_function_index_by_symbol_id;
    l6 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l5)->f_ekeys;
    l25 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l5)->f_evals;
    l3 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l5)->f_size;
    l7 = (size_t) 0;
    while (!((l7 >= l3))) {
        vader_array_t* _a57_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a57_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a57_slotarr, l7)
        l8 = ((int32_t*) _a57_slotarr->buf->slots)[_a57_slotarr->offset + (size_t) l7];
        vader_array_t* _a58_slotarr = ((vader_array_t*) l25);
        VADER_ARRAY_RESOLVE_BUF(_a58_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a58_slotarr, l7)
        l10 = ((int32_t*) _a58_slotarr->buf->slots)[_a58_slotarr->offset + (size_t) l7];
        l19 = l8;
        l23 = l10;
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
        t1 = ((int64_t) (int32_t) l23);
        l11 = (size_t) (int64_t) t1;
        vader_array_t* _a59_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a59_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a59_slotarr, l11)
        l24 = ((int32_t*) _a59_slotarr->buf->slots)[_a59_slotarr->offset + (size_t) l11];
        if (!((l24 >= INT32_C(0)))) {
            continue;
        }
        std_collections_MutableMap_IndexSet_set_at__i32__i32(l4, l19, l24);
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_function_index_by_symbol_id = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    vader_array_t* _a60_arr = vader_array_new(8u, 0u, 0u, 223u);
    l4 = (void*) _a60_arr;
    vader_array_t* _a61_arr = vader_array_new(9u, 0u, 7u, 226u);
    l5 = (void*) _a61_arr;
    vader_array_t* _a62_arr = vader_array_new(9u, 0u, 7u, 226u);
    l6 = (void*) _a62_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a63_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a63_obj, 353u);
    _a63_obj->f_ekeys = l4;
    _a63_obj->f_evals = l5;
    _a63_obj->f_index = l6;
    _a63_obj->f_mask = (size_t) 0;
    _a63_obj->f_size = (size_t) 0;
    _a63_obj->f_tombs = (size_t) 0;
    l4 = (void*) _a63_obj;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_function_index_by_mangle;
    l6 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l5)->f_ekeys;
    l25 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l5)->f_evals;
    l3 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l5)->f_size;
    l7 = (size_t) 0;
    while (!((l7 >= l3))) {
        vader_array_t* _a64_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a64_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a64_slotarr, l7)
        t3 = vader_array_box_slots(_a64_slotarr->buf)[_a64_slotarr->offset + (size_t) l7];
        l9 = t3.payload.s;
        vader_array_t* _a65_slotarr = ((vader_array_t*) l25);
        VADER_ARRAY_RESOLVE_BUF(_a65_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a65_slotarr, l7)
        l8 = ((int32_t*) _a65_slotarr->buf->slots)[_a65_slotarr->offset + (size_t) l7];
        l33 = l9;
        l10 = l8;
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
        t1 = ((int64_t) (int32_t) l10);
        l11 = (size_t) (int64_t) t1;
        vader_array_t* _a66_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a66_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a66_slotarr, l11)
        l19 = ((int32_t*) _a66_slotarr->buf->slots)[_a66_slotarr->offset + (size_t) l11];
        if (!((l19 >= INT32_C(0)))) {
            continue;
        }
        std_collections_MutableMap_IndexSet_set_at__string__i32(l4, l33, l19);
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_function_index_by_mangle = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    vader_array_t* _a67_arr = vader_array_new(9u, 0u, 7u, 226u);
    l4 = (void*) _a67_arr;
    vader_array_t* _a68_arr = vader_array_new(16u, 0u, 0u, 234u);
    l5 = (void*) _a68_arr;
    vader_array_t* _a69_arr = vader_array_new(9u, 0u, 7u, 226u);
    l6 = (void*) _a69_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a70_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a70_obj, 271u);
    _a70_obj->f_ekeys = l4;
    _a70_obj->f_evals = l5;
    _a70_obj->f_index = l6;
    _a70_obj->f_mask = (size_t) 0;
    _a70_obj->f_size = (size_t) 0;
    _a70_obj->f_tombs = (size_t) 0;
    l4 = (void*) _a70_obj;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_pinned_types_by_fn;
    l6 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l5)->f_ekeys;
    l25 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l5)->f_evals;
    l3 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l5)->f_size;
    l7 = (size_t) 0;
    while (!((l7 >= l3))) {
        vader_array_t* _a71_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a71_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a71_slotarr, l7)
        l8 = ((int32_t*) _a71_slotarr->buf->slots)[_a71_slotarr->offset + (size_t) l7];
        vader_array_t* _a72_slotarr = ((vader_array_t*) l25);
        VADER_ARRAY_RESOLVE_BUF(_a72_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a72_slotarr, l7)
        l5 = vader_array_ref_load_obj(_a72_slotarr->buf, _a72_slotarr->offset + (size_t) l7);
        l10 = l8;
        l26 = l5;
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
        t1 = ((int64_t) (int32_t) l10);
        l11 = (size_t) (int64_t) t1;
        l14 = ((vader_array_t*) l13)->length;
        if ((l11 >= l14)) {
            continue;
        }
        t1 = ((int64_t) (int32_t) l10);
        l15 = (size_t) (int64_t) t1;
        vader_array_t* _a73_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a73_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a73_slotarr, l15)
        l19 = ((int32_t*) _a73_slotarr->buf->slots)[_a73_slotarr->offset + (size_t) l15];
        if ((l19 < INT32_C(0))) {
            continue;
        }
        l18 = std_collections_MutableMap_Index_at__i32__Any(l4, l19);
        if (l18.tag == 9u) {
            l27 = l18.payload.obj;
            l28 = l26;
            l16 = ((vader_array_t*) l28)->length;
            l17 = (size_t) 0;
            while ((l17 < l16)) {
                vader_array_t* _a74_slotarr = ((vader_array_t*) l28);
                VADER_ARRAY_RESOLVE_BUF(_a74_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a74_slotarr, l17)
                l23 = ((int32_t*) _a74_slotarr->buf->slots)[_a74_slotarr->offset + (size_t) l17];
                vader_array_push_i32((vader_array_t*) l27, l23);
                t1 = (l17 + INT64_C(1));
                l17 = (size_t) (int64_t) t1;
            }
            continue;
        }
        std_collections_MutableMap_IndexSet_set_at__i32__Any(l4, l19, vader_ref_box(l26));
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_pinned_types_by_fn = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions = l12;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_bytecode_prune_unused_imports(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    size_t l4, l5, l6, l7, l14;
    vader_box_t l8 = vader_box_null();
    int32_t l9, l10, l12;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    size_t t3;
    int32_t t4;
    vader_box_t* gc_roots[2] = { &l8, &t2 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l11, &l13, &l15, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 226u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 221u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 226u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 301u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
        l3 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_body;
        l6 = ((vader_array_t*) l3)->length;
        l7 = (size_t) 0;
        while ((l7 < l6)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
            l8 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
            if (l8.tag == 540u) {
                t0 = l8.payload.obj;
                l9 = ((vader_struct_vader_bytecode_CallImport_t*) t0)->f_index;
                std_collections_MutableMap_IndexSet_set_at__i32__bool(l1, l9, true);
            }
            t1 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t1;
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l4 = std_collections_len__i32__bool(l1);
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports)->length;
    if (l4 == l5) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 226u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(39u, 0u, 13u, 509u);
    l3 = (void*) _a7_arr;
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports)->length;
    while ((l4 < l5)) {
        l9 = ((int32_t) (size_t) l4);
        t2 = std_collections_MutableMap_Index_at__i32__bool(l1, l9);
        if (t2.tag == 221u) {
            t3 = ((vader_array_t*) l3)->length;
            l10 = ((int32_t) (size_t) t3);
            vader_array_push_i32((vader_array_t*) l2, l10);
            vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l4)
            l11 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l4);
            vader_array_push((vader_array_t*) l3, vader_ref_box(l11));
        } else {
            l12 = -(INT32_C(1));
            vader_array_push_i32((vader_array_t*) l2, l12);
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    l1 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l1)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l5)
        l11 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l5);
        l6 = (size_t) 0;
        l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l11)->f_body)->length;
        while ((l6 < l7)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l11)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l6)
            l8 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l6);
            if (l8.tag == 540u) {
                l13 = ((vader_struct_vader_bytecode_BcFunction_t*) l11)->f_body;
                t0 = l8.payload.obj;
                t4 = ((vader_struct_vader_bytecode_CallImport_t*) t0)->f_index;
                t1 = ((int64_t) (int32_t) t4);
                l14 = (size_t) (int64_t) t1;
                vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l14)
                t4 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l14];
                vader_struct_vader_bytecode_CallImport_t* _a12_obj = (vader_struct_vader_bytecode_CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallImport_t));
                vader_obj_header_init(_a12_obj, 540u);
                _a12_obj->f_index = t4;
                l15 = (void*) _a12_obj;
                vader_array_t* _a13_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
                vader_array_ref_store(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l6, l15);
                VADER_WRITE_BARRIER(_a13_slotarr->buf);
            }
            t1 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t1;
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
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
    size_t l4, l5, l9, l10, l13, l14;
    int32_t l11, l15, l17;
    vader_box_t l16 = vader_box_null(), l18 = vader_box_null();
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    bool l21;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    int32_t t3;
    bool t4;
    size_t t5;
    vader_box_t* gc_roots[3] = { &l16, &l18, &t2 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l6, &l7, &l8, &l12, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l19, &l20, &l22, &l23 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 226u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 221u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 226u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 301u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 381u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    std_collections_add__i32(l1, INT32_C(0));
    vader_array_t* _a5_arr = vader_array_new(9u, 0u, 7u, 226u);
    l2 = (void*) _a5_arr;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_signature)->f_result_types;
        vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l7);
        l8 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_signature)->f_param_types;
        l9 = ((vader_array_t*) l8)->length;
        l10 = (size_t) 0;
        while ((l10 < l9)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l10)
            l11 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l10];
            vader_array_push_i32((vader_array_t*) l2, l11);
            t1 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t1;
        }
        l12 = ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_body;
        l13 = ((vader_array_t*) l12)->length;
        l14 = (size_t) 0;
        while ((l14 < l13)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l14)
            t2 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l14);
            l15 = vader_bytecode_type_index_of(t2);
            if ((l15 >= INT32_C(0))) {
                vader_array_push_i32((vader_array_t*) l2, l15);
            }
            t1 = (l14 + INT64_C(1));
            l14 = (size_t) (int64_t) t1;
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_result_types;
        vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l7);
        l8 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_param_types;
        l9 = ((vader_array_t*) l8)->length;
        l10 = (size_t) 0;
        while ((l10 < l9)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l10)
            l11 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l10];
            vader_array_push_i32((vader_array_t*) l2, l11);
            t1 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t1;
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_pinned_types;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l5)
        l11 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l5];
        vader_array_push_i32((vader_array_t*) l2, l11);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_pinned_types_by_fn;
    l6 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l3)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l3)->f_evals;
    l4 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l3)->f_size;
    l5 = (size_t) 0;
    while (!((l5 >= l4))) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l5)
        t3 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l5];
        vader_array_t* _a13_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l5)
        l3 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l5);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
        l9 = ((vader_array_t*) l3)->length;
        l10 = (size_t) 0;
        while ((l10 < l9)) {
            vader_array_t* _a14_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l10)
            l11 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l10];
            vader_array_push_i32((vader_array_t*) l2, l11);
            t1 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t1;
        }
    }
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a15_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l5)
        t3 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l5];
        vader_bytecode_visit_type(t3, l0, l1);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l4 = std_collections_len__i32(l1);
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types)->length;
    if (l4 == l5) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types)->length;
    vader_array_t* _a16_arr = vader_array_new(9u, 0u, 7u, 226u);
    l2 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(171u, 0u, 13u, 1258u);
    l3 = (void*) _a17_arr;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        l11 = ((int32_t) (size_t) l5);
        t4 = std_collections_MutableSet_Contains_contains__i32(l1, l11);
        if (t4) {
            t5 = ((vader_array_t*) l3)->length;
            l15 = ((int32_t) (size_t) t5);
            vader_array_push_i32((vader_array_t*) l2, l15);
            vader_array_t* _a18_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types);
            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l5)
            l16 = vader_array_ref_load_box(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l5);
            vader_array_push((vader_array_t*) l3, l16);
        } else {
            l17 = -(INT32_C(1));
            vader_array_push_i32((vader_array_t*) l2, l17);
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l1 = l3;
    vader_struct___lambda_env_vader_bytecode_1_t* _a19_obj = (vader_struct___lambda_env_vader_bytecode_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_bytecode_1_t));
    vader_obj_header_init(_a19_obj, 239u);
    _a19_obj->f_cap_0 = l2;
    l3 = (void*) _a19_obj;
    vader_array_t* _a20_arr = vader_array_new(171u, 0u, 13u, 1258u);
    l6 = (void*) _a20_arr;
    l4 = ((vader_array_t*) l1)->length;
    vader_array_t* _a21_arr = vader_array_repeat((vader_array_t*) l6, (size_t) l4);
    l6 = (void*) _a21_arr;
    l4 = ((vader_array_t*) l1)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a22_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l5)
        l16 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l5);
        l18 = __lambda_vader_bytecode_0(l3, l16);
        vader_array_push((vader_array_t*) l6, l18);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    vader_array_t* _a23_arr = vader_array_new(8u, 0u, 0u, 223u);
    l1 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(9u, 0u, 7u, 226u);
    l3 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(9u, 0u, 7u, 226u);
    l6 = (void*) _a25_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a26_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a26_obj, 353u);
    _a26_obj->f_ekeys = l1;
    _a26_obj->f_evals = l3;
    _a26_obj->f_index = l6;
    _a26_obj->f_mask = (size_t) 0;
    _a26_obj->f_size = (size_t) 0;
    _a26_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a26_obj;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_key;
    l6 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l3)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l3)->f_evals;
    l4 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l3)->f_size;
    l5 = (size_t) 0;
    while (!((l5 >= l4))) {
        vader_array_t* _a27_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l5)
        t2 = vader_array_box_slots(_a27_slotarr->buf)[_a27_slotarr->offset + (size_t) l5];
        l19 = t2.payload.s;
        vader_array_t* _a28_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l5)
        l11 = ((int32_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l5];
        l20 = l19;
        l15 = l11;
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
        l17 = vader_bytecode_remap_idx(l2, l15);
        if (!((l17 >= INT32_C(0)))) {
            continue;
        }
        std_collections_MutableMap_IndexSet_set_at__string__i32(l1, l20, l17);
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_key = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    l1 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l1)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a29_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l5)
        l3 = vader_array_ref_load_obj(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l5);
        l6 = vader_bytecode_remap_signature(((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature, l2);
        ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature = l6;
        VADER_WRITE_BARRIER((vader_struct_vader_bytecode_BcFunction_t*) l3);
        l9 = (size_t) 0;
        l10 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_body)->length;
        while ((l9 < l10)) {
            l7 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_body;
            vader_array_t* _a30_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l9)
            t2 = vader_array_ref_load_box(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l9);
            l16 = vader_bytecode_remap_type_in_op(t2, l2);
            vader_array_t* _a31_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l9)
            vader_array_ref_store(_a31_slotarr->buf, _a31_slotarr->offset + (size_t) l9, l16.payload.obj);
            VADER_WRITE_BARRIER(_a31_slotarr->buf);
            t1 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t1;
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a32_arr = vader_array_new(39u, 0u, 13u, 509u);
    l1 = (void*) _a32_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports)->length;
    vader_array_t* _a33_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l4);
    l1 = (void*) _a33_arr;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a34_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a34_slotarr->buf, _a34_slotarr->offset + (size_t) l5);
        l7 = l6;
        l19 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_extern_name;
        l20 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_mangled_name;
        l8 = vader_bytecode_remap_signature(((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature, l2);
        l21 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_is_extern;
        l22 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_c_header;
        l23 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_c_library;
        l11 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_c_variadic_fixed;
        vader_struct_vader_bytecode_BcImport_t* _a35_obj = (vader_struct_vader_bytecode_BcImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcImport_t));
        vader_obj_header_init(_a35_obj, 509u);
        _a35_obj->f_extern_name = l19;
        _a35_obj->f_mangled_name = l20;
        _a35_obj->f_signature = l8;
        _a35_obj->f_is_extern = l21;
        _a35_obj->f_c_header = l22;
        _a35_obj->f_c_library = l23;
        _a35_obj->f_c_variadic_fixed = l11;
        l12 = (void*) _a35_obj;
        vader_array_push((vader_array_t*) l1, vader_ref_box(l12));
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_bytecode_push_or_assign(void* l0, size_t l1, vader_box_t l2) {
    size_t l3;
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

static void vader_bytecode_push_scope(void* l0, void* l1, size_t l2, vader_string_t l3, int32_t l4) {
    size_t l5;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_array_t*) l0)->length;
    if (l2 == l5) {
        vader_array_push((vader_array_t*) l0, vader_box_string(223u, l3));
        vader_array_push_i32((vader_array_t*) l1, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l2] = vader_box_string(223u, l3);
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
    size_t l3, l4;
    void* l5 = NULL;
    void* l6 = NULL;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l5, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_by_slot)->length;
    t0 = ((int64_t) (int32_t) l1);
    l4 = (size_t) (int64_t) t0;
    while ((l3 <= l4)) {
        l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_by_slot;
        t1 = (void*) &vader_data_15;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        vader_array_push((vader_array_t*) l5, vader_ref_box(l6));
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
    }
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_by_slot;
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2.payload.obj);
    VADER_WRITE_BARRIER(_a1_slotarr->buf);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_bytecode_refer(uint8_t l0, int32_t l1) {
    int32_t l2;
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = -(INT32_C(1));
    vader_struct_vader_bytecode_OperandRef_t* _a0_obj = (vader_struct_vader_bytecode_OperandRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_OperandRef_t));
    vader_obj_header_init(_a0_obj, 626u);
    _a0_obj->f_kind = l0;
    _a0_obj->f_index = l1;
    _a0_obj->f_owner = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_bytecode_refer_field(int32_t l0, int32_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_OperandRef_t* _a0_obj = (vader_struct_vader_bytecode_OperandRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_OperandRef_t));
    vader_obj_header_init(_a0_obj, 626u);
    _a0_obj->f_kind = (uint8_t) 2;
    _a0_obj->f_index = l1;
    _a0_obj->f_owner = l0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_bytecode_remap_debug(void* l0, void* l1, size_t l2) {
    void* l3 = NULL;
    size_t l4, l5, l7;
    int32_t l6;
    vader_box_t l8 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l8, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(173u, 1u, 13u, 1289u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = vader_box_obj(0u, NULL).payload.obj;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l2);
    l3 = (void*) _a1_arr;
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) l0)->length;
    while ((l4 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l6 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
        if ((l6 < INT32_C(0))) {
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
            continue;
        }
        t1 = ((int64_t) (int32_t) l6);
        l7 = (size_t) (int64_t) t1;
        if ((l7 < l2)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            t2 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
            if (t2.tag == 0u) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                l8 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
                vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7, l8.payload.obj);
                VADER_WRITE_BARRIER(_a5_slotarr->buf);
            }
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_bytecode_remap_idx(void* l0, int32_t l1) {
    size_t l2, l3;
    int64_t t0;
    int32_t t1;
    if ((l1 < INT32_C(0))) {
        return l1;
    }
    t0 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t0;
    l3 = ((vader_array_t*) l0)->length;
    if (!((l2 >= l3))) {
        t0 = ((int64_t) (int32_t) l1);
        l2 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
        return t1;
    }
    return -(INT32_C(1));
}

void* vader_bytecode_remap_jump_table(void* l0, void* l1, size_t l2) {
    void* l3 = NULL;
    size_t l4, l6, l7, l8, l11, l12, l14;
    int32_t l5, l9, l10, l13;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 226u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l2);
    l3 = (void*) _a1_arr;
    l4 = (size_t) 0;
    vader_array_t* _pc6_hdr = (vader_array_t*) l3;
    size_t _pc6_len = _pc6_hdr->length;
    size_t _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
    void* _pc6_slots = _pc6_hdr->buf->slots;
    for (;;) {
        if ((l4 < l2)) {
            l5 = -(INT32_C(1));
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (l5);
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l3, l5);
                _pc6_hdr = (vader_array_t*) l3;
                _pc6_len = _pc6_hdr->length;
                _pc6_cap = (_pc6_hdr->offset == 0 && !vader_array_is_borrowed(_pc6_hdr) && _pc6_hdr->length >= _pc6_hdr->buf->length) ? _pc6_hdr->capacity : (size_t) 0;
                _pc6_slots = _pc6_hdr->buf->slots;
            }
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
            continue;
        }
        _pc6_hdr->length = _pc6_len;
        if (_pc6_hdr->buf->length < _pc6_len) {
            _pc6_hdr->buf->length = _pc6_len;
        }
        break;
    }
    l4 = ((vader_array_t*) l0)->length;
    l6 = (size_t) 0;
    while ((l6 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l5 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
        if ((l5 < INT32_C(0))) {
            t1 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t1;
            continue;
        }
        t1 = ((int64_t) (int32_t) l5);
        l7 = (size_t) (int64_t) t1;
        l8 = ((vader_array_t*) l1)->length;
        if ((l7 >= l8)) {
            t1 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t1;
            continue;
        }
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        l9 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6];
        if ((l9 < INT32_C(0))) {
            t1 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t1;
            continue;
        }
        l10 = -(INT32_C(1));
        t1 = ((int64_t) (int32_t) l5);
        l11 = (size_t) (int64_t) t1;
        l12 = ((vader_array_t*) l1)->length;
        while ((l11 < l12)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
            l13 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l11];
            if ((l13 >= INT32_C(0))) {
                l10 = l13;
                break;
            }
            t1 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t1;
        }
        if ((l10 < INT32_C(0))) {
            l10 = ((int32_t) (size_t) l2);
        }
        if ((((int64_t) (int32_t) l9) < l2)) {
            t1 = ((int64_t) (int32_t) l9);
            l14 = (size_t) (int64_t) t1;
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l14)
            ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l14] = (int32_t) l10;
        }
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_remap_push_cache_slot(vader_box_t l0, void* l1) {
    bool l2;
    size_t l3, l4;
    int32_t l5, l6;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 497u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_cache_slot;
    if ((t1 < INT32_C(0))) {
        l2 = true;
    } else {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_cache_slot;
        t2 = ((int64_t) (int32_t) t1);
        l3 = (size_t) (int64_t) t2;
        l4 = ((vader_array_t*) l1)->length;
        l2 = (l3 >= l4);
    }
    if (!(l2)) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_type_id;
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_cache_slot;
        t2 = ((int64_t) (int32_t) t1);
        l3 = (size_t) (int64_t) t2;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        vader_struct_vader_bytecode_ArrayPush_t* _a1_obj = (vader_struct_vader_bytecode_ArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayPush_t));
        vader_obj_header_init(_a1_obj, 497u);
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
    l8 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_mutable;
    l2 = ((vader_struct_vader_bytecode_BcSignature_t*) l2)->f_param_by_address;
    vader_struct_vader_bytecode_BcSignature_t* _a0_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
    vader_obj_header_init(_a0_obj, 515u);
    _a0_obj->f_params = l3;
    _a0_obj->f_results = l4;
    _a0_obj->f_param_types = l5;
    _a0_obj->f_result_types = l6;
    _a0_obj->f_param_names = l7;
    _a0_obj->f_param_mutable = l8;
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
    size_t l5, l6;
    vader_string_t l8 = 0;
    vader_string_t l12 = 0;
    int32_t l9, l10;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[6] = { &l1, &l3, &l4, &l7, &l11, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l0.tag == 513u || l0.tag == 514u)) {
        l2 = l0;
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 517u) {
        vader_array_t* _a0_arr = vader_array_new(37u, 0u, 13u, 506u);
        l3 = (void*) _a0_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields;
        l5 = ((vader_array_t*) l4)->length;
        l6 = (size_t) 0;
        while ((l6 < l5)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
            l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
            l8 = ((vader_struct_vader_bytecode_BcField_t*) l7)->f_name;
            l9 = ((vader_struct_vader_bytecode_BcField_t*) l7)->f_type_index;
            l10 = vader_bytecode_remap_idx(l1, l9);
            vader_struct_vader_bytecode_BcField_t* _a2_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
            vader_obj_header_init(_a2_obj, 506u);
            _a2_obj->f_name = l8;
            _a2_obj->f_type_index = l10;
            l11 = (void*) _a2_obj;
            vader_array_push((vader_array_t*) l3, vader_ref_box(l11));
            t1 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t1;
        }
        l4 = l0.payload.obj;
        l8 = ((vader_struct_vader_bytecode_BcStruct_t*) l4)->f_name;
        l12 = ((vader_struct_vader_bytecode_BcStruct_t*) l4)->f_c_name;
        l9 = ((vader_struct_vader_bytecode_BcStruct_t*) l4)->f_symbol_id;
        vader_struct_vader_bytecode_BcStruct_t* _a3_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
        vader_obj_header_init(_a3_obj, 517u);
        _a3_obj->f_name = l8;
        _a3_obj->f_fields = l3;
        _a3_obj->f_c_name = l12;
        _a3_obj->f_symbol_id = l9;
        t0 = (void*) _a3_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 504u) {
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_bytecode_BcArray_t*) t0)->f_element;
        t2 = vader_bytecode_remap_idx(l1, l9);
        vader_struct_vader_bytecode_BcArray_t* _a4_obj = (vader_struct_vader_bytecode_BcArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcArray_t));
        vader_obj_header_init(_a4_obj, 504u);
        _a4_obj->f_element = t2;
        t0 = (void*) _a4_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 518u) {
        vader_array_t* _a5_arr = vader_array_new(9u, 0u, 7u, 226u);
        l3 = (void*) _a5_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_BcUnion_t*) t0)->f_variants;
        l5 = ((vader_array_t*) l4)->length;
        l6 = (size_t) 0;
        vader_array_t* _pc99_hdr = (vader_array_t*) l3;
        size_t _pc99_len = _pc99_hdr->length;
        size_t _pc99_cap = (_pc99_hdr->offset == 0 && !vader_array_is_borrowed(_pc99_hdr) && _pc99_hdr->length >= _pc99_hdr->buf->length) ? _pc99_hdr->capacity : (size_t) 0;
        void* _pc99_slots = _pc99_hdr->buf->slots;
        for (;;) {
            if ((l6 < l5)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
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
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
                continue;
            }
            _pc99_hdr->length = _pc99_len;
            if (_pc99_hdr->buf->length < _pc99_len) {
                _pc99_hdr->buf->length = _pc99_len;
            }
            break;
        }
        vader_struct_vader_bytecode_BcUnion_t* _a7_obj = (vader_struct_vader_bytecode_BcUnion_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcUnion_t));
        vader_obj_header_init(_a7_obj, 518u);
        _a7_obj->f_variants = l3;
        t0 = (void*) _a7_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!(l0.tag == 507u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 226u);
        l3 = (void*) _a8_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_BcFn_t*) t0)->f_params;
        l5 = ((vader_array_t*) l4)->length;
        l6 = (size_t) 0;
        vader_array_t* _pc142_hdr = (vader_array_t*) l3;
        size_t _pc142_len = _pc142_hdr->length;
        size_t _pc142_cap = (_pc142_hdr->offset == 0 && !vader_array_is_borrowed(_pc142_hdr) && _pc142_hdr->length >= _pc142_hdr->buf->length) ? _pc142_hdr->capacity : (size_t) 0;
        void* _pc142_slots = _pc142_hdr->buf->slots;
        for (;;) {
            if ((l6 < l5)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l6)
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
                t1 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t1;
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
        vader_obj_header_init(_a10_obj, 507u);
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
    if (l0.tag == 648u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l5 = ((vader_struct_vader_bytecode_StructNew_t*) l3)->f_stack;
        vader_struct_vader_bytecode_StructNew_t* _a0_obj = (vader_struct_vader_bytecode_StructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructNew_t));
        vader_obj_header_init(_a0_obj, 648u);
        _a0_obj->f_type_id = l4;
        _a0_obj->f_stack = l5;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 647u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l6 = ((vader_struct_vader_bytecode_StructGet_t*) l3)->f_field_index;
        vader_struct_vader_bytecode_StructGet_t* _a1_obj = (vader_struct_vader_bytecode_StructGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructGet_t));
        vader_obj_header_init(_a1_obj, 647u);
        _a1_obj->f_type_id = l4;
        _a1_obj->f_field_index = l6;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 649u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l6 = ((vader_struct_vader_bytecode_StructSet_t*) l3)->f_field_index;
        l5 = ((vader_struct_vader_bytecode_StructSet_t*) l3)->f_stack;
        vader_struct_vader_bytecode_StructSet_t* _a2_obj = (vader_struct_vader_bytecode_StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructSet_t));
        vader_obj_header_init(_a2_obj, 649u);
        _a2_obj->f_type_id = l4;
        _a2_obj->f_field_index = l6;
        _a2_obj->f_stack = l5;
        t0 = (void*) _a2_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 496u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l6 = ((vader_struct_vader_bytecode_ArrayNew_t*) l3)->f_length;
        vader_struct_vader_bytecode_ArrayNew_t* _a3_obj = (vader_struct_vader_bytecode_ArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayNew_t));
        vader_obj_header_init(_a3_obj, 496u);
        _a3_obj->f_type_id = l4;
        _a3_obj->f_length = l6;
        t0 = (void*) _a3_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 494u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_ArrayGet_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l5 = ((vader_struct_vader_bytecode_ArrayGet_t*) l3)->f_bounds_safe;
        vader_struct_vader_bytecode_ArrayGet_t* _a4_obj = (vader_struct_vader_bytecode_ArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayGet_t));
        vader_obj_header_init(_a4_obj, 494u);
        _a4_obj->f_type_id = l4;
        _a4_obj->f_bounds_safe = l5;
        t0 = (void*) _a4_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 501u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_ArraySet_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l5 = ((vader_struct_vader_bytecode_ArraySet_t*) l3)->f_bounds_safe;
        vader_struct_vader_bytecode_ArraySet_t* _a5_obj = (vader_struct_vader_bytecode_ArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArraySet_t));
        vader_obj_header_init(_a5_obj, 501u);
        _a5_obj->f_type_id = l4;
        _a5_obj->f_bounds_safe = l5;
        t0 = (void*) _a5_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 497u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l6 = ((vader_struct_vader_bytecode_ArrayPush_t*) l3)->f_cache_slot;
        vader_struct_vader_bytecode_ArrayPush_t* _a6_obj = (vader_struct_vader_bytecode_ArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayPush_t));
        vader_obj_header_init(_a6_obj, 497u);
        _a6_obj->f_type_id = l4;
        _a6_obj->f_cache_slot = l6;
        t0 = (void*) _a6_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 650u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_TypeCheck_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_TypeCheck_t* _a7_obj = (vader_struct_vader_bytecode_TypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_TypeCheck_t));
        vader_obj_header_init(_a7_obj, 650u);
        _a7_obj->f_type_id = t1;
        t0 = (void*) _a7_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 651u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_TypeConst_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_TypeConst_t* _a8_obj = (vader_struct_vader_bytecode_TypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_TypeConst_t));
        vader_obj_header_init(_a8_obj, 651u);
        _a8_obj->f_type_id = t1;
        t0 = (void*) _a8_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 541u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_CallIndirect_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_CallIndirect_t* _a9_obj = (vader_struct_vader_bytecode_CallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallIndirect_t));
        vader_obj_header_init(_a9_obj, 541u);
        _a9_obj->f_type_id = t1;
        t0 = (void*) _a9_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 623u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_function_index;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_env_type_id;
        l6 = vader_bytecode_remap_idx(l1, l6);
        vader_struct_vader_bytecode_MakeClosure_t* _a10_obj = (vader_struct_vader_bytecode_MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_MakeClosure_t));
        vader_obj_header_init(_a10_obj, 623u);
        _a10_obj->f_function_index = l4;
        _a10_obj->f_env_type_id = l6;
        t0 = (void*) _a10_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 568u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_function_index;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_type_id;
        l6 = vader_bytecode_remap_idx(l1, l6);
        vader_struct_vader_bytecode_FnRef_t* _a11_obj = (vader_struct_vader_bytecode_FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnRef_t));
        vader_obj_header_init(_a11_obj, 568u);
        _a11_obj->f_function_index = l4;
        _a11_obj->f_type_id = l6;
        t0 = (void*) _a11_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 618u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_LocalField_t*) l3)->f_slot;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_type_id;
        l6 = vader_bytecode_remap_idx(l1, l6);
        l7 = ((vader_struct_vader_bytecode_LocalField_t*) l3)->f_field_index;
        vader_struct_vader_bytecode_LocalField_t* _a12_obj = (vader_struct_vader_bytecode_LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalField_t));
        vader_obj_header_init(_a12_obj, 618u);
        _a12_obj->f_slot = l4;
        _a12_obj->f_type_id = l6;
        _a12_obj->f_field_index = l7;
        t0 = (void*) _a12_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 502u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_ArraySlice_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_ArraySlice_t* _a13_obj = (vader_struct_vader_bytecode_ArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArraySlice_t));
        vader_obj_header_init(_a13_obj, 502u);
        _a13_obj->f_type_id = t1;
        t0 = (void*) _a13_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 627u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_RefCast_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_RefCast_t* _a14_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
        vader_obj_header_init(_a14_obj, 627u);
        _a14_obj->f_type_id = t1;
        t0 = (void*) _a14_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 630u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_Retag_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_Retag_t* _a15_obj = (vader_struct_vader_bytecode_Retag_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Retag_t));
        vader_obj_header_init(_a15_obj, 630u);
        _a15_obj->f_type_id = t1;
        t0 = (void*) _a15_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 544u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_pool_index;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_type_id;
        l6 = vader_bytecode_remap_idx(l1, l6);
        vader_struct_vader_bytecode_DataConst_t* _a16_obj = (vader_struct_vader_bytecode_DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DataConst_t));
        vader_obj_header_init(_a16_obj, 544u);
        _a16_obj->f_pool_index = l4;
        _a16_obj->f_type_id = l6;
        t0 = (void*) _a16_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!((l0.tag == 492u || l0.tag == 493u || l0.tag == 495u || l0.tag == 498u || l0.tag == 499u || l0.tag == 500u || l0.tag == 523u || l0.tag == 524u || l0.tag == 525u || l0.tag == 526u || l0.tag == 527u || l0.tag == 528u || l0.tag == 529u || l0.tag == 530u || l0.tag == 531u || l0.tag == 532u || l0.tag == 533u || l0.tag == 534u || l0.tag == 535u || l0.tag == 536u || l0.tag == 539u || l0.tag == 540u || l0.tag == 542u || l0.tag == 543u || l0.tag == 546u || l0.tag == 547u || l0.tag == 548u || l0.tag == 549u || l0.tag == 552u || l0.tag == 553u || l0.tag == 554u || l0.tag == 555u || l0.tag == 556u || l0.tag == 557u || l0.tag == 558u || l0.tag == 559u || l0.tag == 560u || l0.tag == 561u || l0.tag == 562u || l0.tag == 563u || l0.tag == 564u || l0.tag == 565u || l0.tag == 566u || l0.tag == 567u || l0.tag == 569u || l0.tag == 570u || l0.tag == 571u || l0.tag == 572u || l0.tag == 573u || l0.tag == 574u || l0.tag == 575u || l0.tag == 576u || l0.tag == 577u || l0.tag == 578u || l0.tag == 579u || l0.tag == 580u || l0.tag == 581u || l0.tag == 582u || l0.tag == 583u || l0.tag == 584u || l0.tag == 585u || l0.tag == 586u || l0.tag == 587u || l0.tag == 588u || l0.tag == 589u || l0.tag == 590u || l0.tag == 591u || l0.tag == 592u || l0.tag == 593u || l0.tag == 594u || l0.tag == 595u || l0.tag == 596u || l0.tag == 597u || l0.tag == 598u || l0.tag == 599u || l0.tag == 600u || l0.tag == 601u || l0.tag == 602u || l0.tag == 603u || l0.tag == 604u || l0.tag == 605u || l0.tag == 606u || l0.tag == 607u || l0.tag == 608u || l0.tag == 609u || l0.tag == 611u || l0.tag == 612u || l0.tag == 613u || l0.tag == 614u || l0.tag == 615u || l0.tag == 616u || l0.tag == 617u || l0.tag == 619u || l0.tag == 620u || l0.tag == 621u || l0.tag == 622u || l0.tag == 624u || l0.tag == 625u || l0.tag == 628u || l0.tag == 629u || l0.tag == 631u || l0.tag == 632u || l0.tag == 633u || l0.tag == 635u || l0.tag == 636u || l0.tag == 637u || l0.tag == 638u || l0.tag == 639u || l0.tag == 640u || l0.tag == 641u || l0.tag == 642u || l0.tag == 643u || l0.tag == 644u || l0.tag == 645u || l0.tag == 646u || l0.tag == 652u || l0.tag == 653u || l0.tag == 654u || l0.tag == 655u || l0.tag == 656u || l0.tag == 657u || l0.tag == 658u || l0.tag == 659u || l0.tag == 660u || l0.tag == 661u || l0.tag == 662u || l0.tag == 663u || l0.tag == 664u || l0.tag == 665u))) {
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
    size_t l5, l6;
    int32_t l7, l8;
    int64_t t0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l1;
    vader_struct___lambda_env_vader_bytecode_3_t* _a0_obj = (vader_struct___lambda_env_vader_bytecode_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_bytecode_3_t));
    vader_obj_header_init(_a0_obj, 240u);
    _a0_obj->f_cap_0 = l0;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 226u);
    l4 = (void*) _a1_arr;
    l5 = ((vader_array_t*) l2)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l4, (size_t) l5);
    l4 = (void*) _a2_arr;
    l5 = ((vader_array_t*) l2)->length;
    l6 = (size_t) 0;
    vader_array_t* _pc19_hdr = (vader_array_t*) l4;
    size_t _pc19_len = _pc19_hdr->length;
    size_t _pc19_cap = (_pc19_hdr->offset == 0 && !vader_array_is_borrowed(_pc19_hdr) && _pc19_hdr->length >= _pc19_hdr->buf->length) ? _pc19_hdr->capacity : (size_t) 0;
    void* _pc19_slots = _pc19_hdr->buf->slots;
    for (;;) {
        if ((l6 < l5)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
            l7 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6];
            l8 = __lambda_vader_bytecode_2(l3, l7);
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
            t0 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t0;
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
    size_t l2, l4, l6;
    int32_t l7, l11;
    vader_box_t l8 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l8, &l9, &l10 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l2 = ((vader_array_t*) l1)->length;
    vader_array_t* _a0_arr = vader_array_new(169u, 0u, 13u, 1235u);
    l3 = (void*) _a0_arr;
    l4 = (size_t) 0;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 226u);
    t0 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l2);
    l5 = (void*) _a2_arr;
    l6 = (size_t) 0;
    vader_array_t* _pc14_hdr = (vader_array_t*) l5;
    size_t _pc14_len = _pc14_hdr->length;
    size_t _pc14_cap = (_pc14_hdr->offset == 0 && !vader_array_is_borrowed(_pc14_hdr) && _pc14_hdr->length >= _pc14_hdr->buf->length) ? _pc14_hdr->capacity : (size_t) 0;
    void* _pc14_slots = _pc14_hdr->buf->slots;
    for (;;) {
        if ((l6 < l2)) {
            l7 = -(INT32_C(1));
            if (VADER_LIKELY(_pc14_len < _pc14_cap)) {
                ((int32_t*) _pc14_slots)[_pc14_len] = (int32_t) (l7);
                _pc14_len += 1;
            } else {
                _pc14_hdr->length = _pc14_len;
                if (_pc14_hdr->buf->length < _pc14_len) {
                    _pc14_hdr->buf->length = _pc14_len;
                }
                vader_array_push_i32((vader_array_t*) l5, l7);
                _pc14_hdr = (vader_array_t*) l5;
                _pc14_len = _pc14_hdr->length;
                _pc14_cap = (_pc14_hdr->offset == 0 && !vader_array_is_borrowed(_pc14_hdr) && _pc14_hdr->length >= _pc14_hdr->buf->length) ? _pc14_hdr->capacity : (size_t) 0;
                _pc14_slots = _pc14_hdr->buf->slots;
            }
            t1 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t1;
            continue;
        }
        _pc14_hdr->length = _pc14_len;
        if (_pc14_hdr->buf->length < _pc14_len) {
            _pc14_hdr->buf->length = _pc14_len;
        }
        break;
    }
    l6 = (size_t) 0;
    while ((l6 < l2)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        l8 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        l9 = vader_bytecode_try_fold_arith(l8, l3, l4);
        if (l9.tag == 0u) {
            vader_bytecode_push_or_assign(l3, l4, l8);
            l7 = ((int32_t) (size_t) l4);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
            ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l6] = (int32_t) l7;
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        } else {
            t1 = (l4 - INT64_C(2));
            l4 = (size_t) (int64_t) t1;
            l10 = l9;
            vader_bytecode_push_or_assign(l3, l4, l10);
            l11 = ((int32_t) (size_t) l4);
            vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
            ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l6] = (int32_t) l11;
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a6_arr = vader_array_slice((vader_array_t*) l3, (size_t) INT64_C(0), (size_t) l4);
    l1 = (void*) _a6_arr;
    l3 = vader_bytecode_remap_jump_table(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l5, l4);
    l5 = vader_bytecode_remap_debug(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug, l5, l4);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a7_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a7_obj, 511u);
    _a7_obj->f_body = l1;
    _a7_obj->f_jump_table = l3;
    _a7_obj->f_debug = l5;
    t0 = (void*) _a7_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_run_bc_peephole(void* l0) {
    bool l1, l20, l21, l22, l23, l24;
    void* l2 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l26 = NULL;
    void* l33 = NULL;
    void* l38 = NULL;
    size_t l3, l4, l5, l11, l13, l15, l25, l27, l29, l30, l32, l35;
    vader_box_t l10 = vader_box_null(), l19 = vader_box_null(), l31 = vader_box_null(), l36 = vader_box_null();
    int32_t l12, l14, l16, l28, l34, l37, l39, l40;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    int32_t t3;
    vader_box_t t4 = vader_box_null(), t5 = vader_box_null();
    bool t6;
    vader_box_t* gc_roots[6] = { &l10, &l19, &l31, &l36, &t4, &t5 };
    void** gc_raw_roots[12] = { &l0, &l2, &l6, &l7, &l8, &l9, &l17, &l18, &l26, &l33, &l38, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 12u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_bc_result_arity(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature);
    l1 = (t0 > INT64_C(1));
    l2 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l3 = ((vader_array_t*) l2)->length;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    t1 = (l4 + l5);
    l4 = (size_t) (int64_t) t1;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 226u);
    t2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t2, (size_t) l4);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 226u);
    t2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t2, (size_t) l4);
    l7 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 226u);
    t2 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) t2, (size_t) l4);
    l8 = (void*) _a5_arr;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_push_i32((vader_array_t*) l6, INT32_C(0));
        vader_array_push_i32((vader_array_t*) l7, INT32_C(0));
        vader_array_push_i32((vader_array_t*) l8, INT32_C(0));
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l9 = l2;
    l4 = ((vader_array_t*) l9)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l10 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
        if (l10.tag == 620u) {
            t2 = l10.payload.obj;
            t3 = ((vader_struct_vader_bytecode_LocalSet_t*) t2)->f_slot;
            t1 = ((int64_t) (int32_t) t3);
            l11 = (size_t) (int64_t) t1;
            vader_array_t* _a7_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l11)
            t3 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l11];
            l12 = (t3 + INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l11)
            ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l11] = (int32_t) l12;
        }
        if (l10.tag == 619u) {
            t2 = l10.payload.obj;
            t3 = ((vader_struct_vader_bytecode_LocalGet_t*) t2)->f_slot;
            t1 = ((int64_t) (int32_t) t3);
            l13 = (size_t) (int64_t) t1;
            vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l13)
            t3 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l13];
            l14 = (t3 + INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l13)
            ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l13] = (int32_t) l14;
        }
        if (l10.tag == 621u) {
            t2 = l10.payload.obj;
            t3 = ((vader_struct_vader_bytecode_LocalTee_t*) t2)->f_slot;
            t1 = ((int64_t) (int32_t) t3);
            l15 = (size_t) (int64_t) t1;
            vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l15)
            t3 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l15];
            l16 = (t3 + INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l15)
            ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l15] = (int32_t) l16;
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l9 = vader_bytecode_mark_jump_targets(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l3);
    vader_array_t* _a10_arr = vader_array_new(169u, 0u, 13u, 1235u);
    l17 = (void*) _a10_arr;
    l4 = (size_t) 0;
    vader_array_t* _a11_arr = vader_array_new(9u, 0u, 7u, 226u);
    t2 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_repeat((vader_array_t*) t2, (size_t) l3);
    l18 = (void*) _a12_arr;
    l5 = (size_t) 0;
    vader_array_t* _pc150_hdr = (vader_array_t*) l18;
    size_t _pc150_len = _pc150_hdr->length;
    size_t _pc150_cap = (_pc150_hdr->offset == 0 && !vader_array_is_borrowed(_pc150_hdr) && _pc150_hdr->length >= _pc150_hdr->buf->length) ? _pc150_hdr->capacity : (size_t) 0;
    void* _pc150_slots = _pc150_hdr->buf->slots;
    for (;;) {
        if ((l5 < l3)) {
            l12 = -(INT32_C(1));
            if (VADER_LIKELY(_pc150_len < _pc150_cap)) {
                ((int32_t*) _pc150_slots)[_pc150_len] = (int32_t) (l12);
                _pc150_len += 1;
            } else {
                _pc150_hdr->length = _pc150_len;
                if (_pc150_hdr->buf->length < _pc150_len) {
                    _pc150_hdr->buf->length = _pc150_len;
                }
                vader_array_push_i32((vader_array_t*) l18, l12);
                _pc150_hdr = (vader_array_t*) l18;
                _pc150_len = _pc150_hdr->length;
                _pc150_cap = (_pc150_hdr->offset == 0 && !vader_array_is_borrowed(_pc150_hdr) && _pc150_hdr->length >= _pc150_hdr->buf->length) ? _pc150_hdr->capacity : (size_t) 0;
                _pc150_slots = _pc150_hdr->buf->slots;
            }
            t1 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t1;
            continue;
        }
        _pc150_hdr->length = _pc150_len;
        if (_pc150_hdr->buf->length < _pc150_len) {
            _pc150_hdr->buf->length = _pc150_len;
        }
        break;
    }
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l5)
        l10 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l5);
        if (l10.tag == 620u) {
            if (((l5 + INT64_C(1)) < l3)) {
                t1 = (l5 + INT64_C(1));
                l11 = (size_t) (int64_t) t1;
                vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l11)
                l19 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l11);
                if (l19.tag == 619u) {
                    t2 = l19.payload.obj;
                    l12 = ((vader_struct_vader_bytecode_LocalGet_t*) t2)->f_slot;
                    t2 = l10.payload.obj;
                    l14 = ((vader_struct_vader_bytecode_LocalSet_t*) t2)->f_slot;
                    if (l12 == l14) {
                        l20 = false;
                        if ((l4 > INT64_C(0))) {
                            t1 = (l4 - INT64_C(1));
                            l13 = (size_t) (int64_t) t1;
                            vader_array_t* _a15_slotarr = ((vader_array_t*) l17);
                            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l13)
                            t4 = vader_array_ref_load_box(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l13);
                            t5 = vader_bytecode_const_op_of(t4);
                            if (!(t5.tag == 0u)) {
                                l20 = true;
                            }
                        }
                        t2 = l10.payload.obj;
                        t3 = ((vader_struct_vader_bytecode_LocalSet_t*) t2)->f_slot;
                        t1 = ((int64_t) (int32_t) t3);
                        l15 = (size_t) (int64_t) t1;
                        vader_array_t* _a16_slotarr = ((vader_array_t*) l6);
                        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l15)
                        t3 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l15];
                        if (t3 == INT32_C(1)) {
                            vader_array_t* _a17_slotarr = ((vader_array_t*) l7);
                            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l15)
                            t3 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l15];
                            l22 = t3 == INT32_C(1);
                        } else {
                            l22 = false;
                        }
                        if (l22) {
                            vader_array_t* _a18_slotarr = ((vader_array_t*) l8);
                            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l15)
                            t3 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l15];
                            l21 = t3 == INT32_C(0);
                        } else {
                            l21 = false;
                        }
                        if (l20) {
                            l24 = l21;
                        } else {
                            l24 = false;
                        }
                        if (l24) {
                            l23 = true;
                        } else {
                            t1 = (l5 + INT64_C(1));
                            l25 = (size_t) (int64_t) t1;
                            vader_array_t* _a19_slotarr = ((vader_array_t*) l9);
                            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l25)
                            t4 = vader_box_bool(221u, ((uint8_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l25]);
                            l23 = t4.payload.b;
                        }
                        if (!(l23)) {
                            t2 = l10.payload.obj;
                            t3 = ((vader_struct_vader_bytecode_LocalSet_t*) t2)->f_slot;
                            vader_struct_vader_bytecode_LocalTee_t* _a20_obj = (vader_struct_vader_bytecode_LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalTee_t));
                            vader_obj_header_init(_a20_obj, 621u);
                            _a20_obj->f_slot = t3;
                            l26 = (void*) _a20_obj;
                            vader_bytecode_push_or_assign(l17, l4, vader_ref_box(l26));
                            l16 = ((int32_t) (size_t) l4);
                            vader_array_t* _a21_slotarr = ((vader_array_t*) l18);
                            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l5)
                            ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l5] = (int32_t) l16;
                            t1 = (l5 + INT64_C(1));
                            l27 = (size_t) (int64_t) t1;
                            l28 = ((int32_t) (size_t) l4);
                            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l27)
                            ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l27] = (int32_t) l28;
                            t1 = (l4 + INT64_C(1));
                            l4 = (size_t) (int64_t) t1;
                            t1 = (l5 + INT64_C(2));
                            l5 = (size_t) (int64_t) t1;
                            continue;
                        }
                    }
                }
            }
        }
        if (l10.tag == 631u) {
            if (!(l1)) {
                l29 = ((vader_array_t*) l17)->length;
                if ((l29 > INT64_C(0))) {
                    t1 = (l29 - INT64_C(1));
                    l30 = (size_t) (int64_t) t1;
                    vader_array_t* _a22_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l30)
                    t4 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l30);
                    l31 = vader_bytecode_const_op_of(t4);
                    if (!(l31.tag == 0u)) {
                        t1 = (l29 - INT64_C(1));
                        l32 = (size_t) (int64_t) t1;
                        vader_struct_vader_bytecode_ReturnLit_t* _a23_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                        vader_obj_header_init(_a23_obj, 632u);
                        _a23_obj->f_value = l31;
                        l33 = (void*) _a23_obj;
                        vader_array_t* _a24_slotarr = ((vader_array_t*) l17);
                        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l32)
                        vader_array_ref_store(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l32, l33);
                        VADER_WRITE_BARRIER(_a24_slotarr->buf);
                        l34 = ((int32_t) (int64_t) (l4 - INT64_C(1)));
                        vader_array_t* _a25_slotarr = ((vader_array_t*) l18);
                        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l5)
                        ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l5] = (int32_t) l34;
                        t1 = (l5 + INT64_C(1));
                        l5 = (size_t) (int64_t) t1;
                        continue;
                    }
                }
            }
        }
        if (l10.tag == 530u) {
            if ((l4 > INT64_C(0))) {
                t1 = (l4 - INT64_C(1));
                l35 = (size_t) (int64_t) t1;
                vader_array_t* _a26_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l35)
                l36 = vader_array_ref_load_box(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l35);
                if (l36.tag == 530u) {
                    l37 = -(INT32_C(1));
                    vader_array_t* _a27_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l5)
                    ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l5] = (int32_t) l37;
                    t1 = (l4 - INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    t1 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t1;
                    continue;
                }
                if (l36.tag == 527u) {
                    t2 = l36.payload.obj;
                    t6 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                    vader_struct_vader_bytecode_BoolConst_t* _a28_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                    vader_obj_header_init(_a28_obj, 527u);
                    _a28_obj->f_value = !(t6);
                    l38 = (void*) _a28_obj;
                    vader_array_t* _a29_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l35)
                    vader_array_ref_store(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l35, l38);
                    VADER_WRITE_BARRIER(_a29_slotarr->buf);
                    l39 = ((int32_t) (size_t) l35);
                    vader_array_t* _a30_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l5)
                    ((int32_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l5] = (int32_t) l39;
                    t1 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t1;
                    continue;
                }
            }
        }
        vader_bytecode_push_or_assign(l17, l4, l10);
        l40 = ((int32_t) (size_t) l4);
        vader_array_t* _a31_slotarr = ((vader_array_t*) l18);
        VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l5)
        ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l5] = (int32_t) l40;
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a32_arr = vader_array_slice((vader_array_t*) l17, (size_t) INT64_C(0), (size_t) l4);
    l2 = (void*) _a32_arr;
    l6 = vader_bytecode_remap_jump_table(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l18, l4);
    l7 = vader_bytecode_remap_debug(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug, l18, l4);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a33_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a33_obj, 511u);
    _a33_obj->f_body = l2;
    _a33_obj->f_jump_table = l6;
    _a33_obj->f_debug = l7;
    t2 = (void*) _a33_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_run_bc_return_lit_fold(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l13 = NULL;
    size_t l2, l4, l6, l9, l10, l12;
    int32_t l7, l14;
    vader_box_t l8 = vader_box_null(), l11 = vader_box_null();
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l8, &l11, &t3 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l5, &l13, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_bc_result_arity(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature);
    if ((t0 > INT64_C(1))) {
        t1 = vader_bytecode_bc_peephole_unchanged(l0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l2 = ((vader_array_t*) l1)->length;
    vader_array_t* _a0_arr = vader_array_new(169u, 0u, 13u, 1235u);
    l3 = (void*) _a0_arr;
    l4 = (size_t) 0;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 226u);
    t1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l5 = (void*) _a2_arr;
    l6 = (size_t) 0;
    vader_array_t* _pc23_hdr = (vader_array_t*) l5;
    size_t _pc23_len = _pc23_hdr->length;
    size_t _pc23_cap = (_pc23_hdr->offset == 0 && !vader_array_is_borrowed(_pc23_hdr) && _pc23_hdr->length >= _pc23_hdr->buf->length) ? _pc23_hdr->capacity : (size_t) 0;
    void* _pc23_slots = _pc23_hdr->buf->slots;
    for (;;) {
        if ((l6 < l2)) {
            l7 = -(INT32_C(1));
            if (VADER_LIKELY(_pc23_len < _pc23_cap)) {
                ((int32_t*) _pc23_slots)[_pc23_len] = (int32_t) (l7);
                _pc23_len += 1;
            } else {
                _pc23_hdr->length = _pc23_len;
                if (_pc23_hdr->buf->length < _pc23_len) {
                    _pc23_hdr->buf->length = _pc23_len;
                }
                vader_array_push_i32((vader_array_t*) l5, l7);
                _pc23_hdr = (vader_array_t*) l5;
                _pc23_len = _pc23_hdr->length;
                _pc23_cap = (_pc23_hdr->offset == 0 && !vader_array_is_borrowed(_pc23_hdr) && _pc23_hdr->length >= _pc23_hdr->buf->length) ? _pc23_hdr->capacity : (size_t) 0;
                _pc23_slots = _pc23_hdr->buf->slots;
            }
            t2 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t2;
            continue;
        }
        _pc23_hdr->length = _pc23_len;
        if (_pc23_hdr->buf->length < _pc23_len) {
            _pc23_hdr->buf->length = _pc23_len;
        }
        break;
    }
    l6 = (size_t) 0;
    while ((l6 < l2)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        l8 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        if (l8.tag == 631u) {
            l9 = ((vader_array_t*) l3)->length;
            if ((l9 > INT64_C(0))) {
                t2 = (l9 - INT64_C(1));
                l10 = (size_t) (int64_t) t2;
                vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
                t3 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l10);
                l11 = vader_bytecode_const_op_of(t3);
                if (!(l11.tag == 0u)) {
                    t2 = (l9 - INT64_C(1));
                    l12 = (size_t) (int64_t) t2;
                    vader_struct_vader_bytecode_ReturnLit_t* _a5_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                    vader_obj_header_init(_a5_obj, 632u);
                    _a5_obj->f_value = l11;
                    l13 = (void*) _a5_obj;
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l12)
                    vader_array_ref_store(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l12, l13);
                    VADER_WRITE_BARRIER(_a6_slotarr->buf);
                    l7 = ((int32_t) (int64_t) (l9 - INT64_C(1)));
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l6)
                    ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l6] = (int32_t) l7;
                    t2 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t2;
                    continue;
                }
            }
        }
        vader_bytecode_push_or_assign(l3, l4, l8);
        l14 = ((int32_t) (size_t) l4);
        vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l6)
        ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l6] = (int32_t) l14;
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a9_arr = vader_array_slice((vader_array_t*) l3, (size_t) INT64_C(0), (size_t) l4);
    l1 = (void*) _a9_arr;
    l3 = vader_bytecode_remap_jump_table(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l5, l4);
    l5 = vader_bytecode_remap_debug(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug, l5, l4);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a10_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a10_obj, 511u);
    _a10_obj->f_body = l1;
    _a10_obj->f_jump_table = l3;
    _a10_obj->f_debug = l5;
    t1 = (void*) _a10_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_bytecode_same_class_list(void* l0, void* l1) {
    size_t l2, l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    bool t0;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) l0)->length;
    l3 = ((vader_array_t*) l1)->length;
    if (l2 != l3) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        t0 = vader_bytecode_same_intern_class(l4, l5);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return true; }
}

static bool vader_bytecode_same_intern_class(vader_box_t l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    bool l4;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    void* l7 = NULL;
    void* l8 = NULL;
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[4] = { &l0, &l1, &l2, &l3 };
    void** gc_raw_roots[3] = { &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l5, &l6, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1012u) {
        t0 = l0.payload.obj;
        t1 = vader_bytecode_same_intern_class(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1012u) {
        l2 = l0;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_types_DistinctType_t*) t0)->f_backing;
        t1 = vader_bytecode_same_intern_class(l2, l3);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 1013u || l0.tag == 1020u)) {
        l4 = true;
    } else {
        l4 = (l1.tag == 1013u || l1.tag == 1020u);
    }
    if (l4) {
        l5 = vader_bytecode_bare_intern_name(l0);
        l6 = vader_bytecode_bare_intern_name(l1);
        if (l5 == l6) {
            t2 = vader_bytecode_bare_intern_name(l0);
            { bool __vret = t2 != 0u; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 1022u) {
        if (l1.tag == 1022u) {
            t0 = l0.payload.obj;
            l7 = ((vader_struct_vader_types_StructType_t*) t0)->f_symbol;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_types_StructType_t*) t0)->f_symbol;
            l4 = vader_bytecode_same_symbol_class(l7, l8);
        } else {
            l4 = false;
        }
        if (l4) {
            t0 = l0.payload.obj;
            l7 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
            t1 = vader_bytecode_same_class_list(l7, l8);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 1023u) {
        if (l1.tag == 1023u) {
            t0 = l0.payload.obj;
            l7 = ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol;
            l4 = vader_bytecode_same_symbol_class(l7, l8);
        } else {
            l4 = false;
        }
        if (l4) {
            t0 = l0.payload.obj;
            l7 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
            t1 = vader_bytecode_same_class_list(l7, l8);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 1011u) {
        if (l1.tag == 1011u) {
            t0 = l0.payload.obj;
            l2 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_element;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_element;
            t1 = vader_bytecode_same_intern_class(l2, l3);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 1027u) {
        if (l1.tag == 1027u) {
            t0 = l0.payload.obj;
            l7 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
            t1 = vader_bytecode_same_class_list(l7, l8);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 1024u) {
        if (l1.tag == 1024u) {
            t0 = l0.payload.obj;
            l7 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
            t1 = vader_bytecode_same_class_list(l7, l8);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (!(l0.tag == 1014u)) {
        l5 = vader_bytecode_bare_intern_name(l0);
        l6 = vader_bytecode_bare_intern_name(l1);
        { bool __vret = l5 == l6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1014u) {
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
        l4 = vader_bytecode_same_class_list(l7, l8);
    } else {
        l4 = false;
    }
    if (l4) {
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
        vader_obj_header_init(_a0_obj, 585u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Shl_t* _a1_obj = (vader_struct_vader_bytecode_I64Shl_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Shl_t));
    vader_obj_header_init(_a1_obj, 605u);
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
            vader_obj_header_init(_a0_obj, 606u);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_I64ShrU_t* _a1_obj = (vader_struct_vader_bytecode_I64ShrU_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64ShrU_t));
        vader_obj_header_init(_a1_obj, 607u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1)) {
        vader_struct_vader_bytecode_I32Shr_t* _a2_obj = (vader_struct_vader_bytecode_I32Shr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Shr_t));
        vader_obj_header_init(_a2_obj, 586u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32ShrU_t* _a3_obj = (vader_struct_vader_bytecode_I32ShrU_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32ShrU_t));
    vader_obj_header_init(_a3_obj, 587u);
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_bytecode_size_of_bc_type(vader_box_t l0) {
    int32_t l1;
    void* t0;
    if (l0.tag == 513u) {
        t0 = l0.payload.obj;
        l1 = vader_bytecode_size_of_val_type(((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val);
        return l1;
    }
    if (l0.tag == 517u) {
        l1 = INT32_C(8);
    } else if (l0.tag == 504u) {
        l1 = INT32_C(8);
    } else if (l0.tag == 507u) {
        l1 = INT32_C(8);
    } else if (l0.tag == 518u) {
        l1 = INT32_C(16);
    } else {
        if (!(l0.tag == 514u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = INT32_C(16);
    }
    return l1;
}

int32_t vader_bytecode_size_of_val_type(uint8_t l0) {
    int32_t l1;
    if (l0 == INT32_C(0)) {
        l1 = INT32_C(1);
        return l1;
    }
    if (l0 == INT32_C(5)) {
        l1 = INT32_C(1);
    } else if (l0 == INT32_C(12)) {
        l1 = INT32_C(1);
    } else if (l0 == INT32_C(1)) {
        l1 = INT32_C(2);
    } else if (l0 == INT32_C(6)) {
        l1 = INT32_C(2);
    } else if (l0 == INT32_C(2)) {
        l1 = INT32_C(4);
    } else if (l0 == INT32_C(7)) {
        l1 = INT32_C(4);
    } else if (l0 == INT32_C(10)) {
        l1 = INT32_C(4);
    } else if (l0 == INT32_C(13)) {
        l1 = INT32_C(4);
    } else if (l0 == INT32_C(3)) {
        l1 = INT32_C(8);
    } else if (l0 == INT32_C(8)) {
        l1 = INT32_C(8);
    } else if (l0 == INT32_C(11)) {
        l1 = INT32_C(8);
    } else if (l0 == INT32_C(4)) {
        l1 = INT32_C(8);
    } else if (l0 == INT32_C(9)) {
        l1 = INT32_C(8);
    } else if (l0 == INT32_C(14)) {
        l1 = INT32_C(16);
    } else if (l0 == INT32_C(16)) {
        l1 = INT32_C(0);
    } else if (l0 == INT32_C(15)) {
        l1 = INT32_C(0);
    } else if (l0 == INT32_C(17)) {
        l1 = INT32_C(8);
    } else if (l0 == INT32_C(18)) {
        l1 = INT32_C(16);
    } else {
        if (!(l0 == INT32_C(19))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = INT32_C(16);
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
        vader_obj_header_init(_a0_obj, 615u);
        _a0_obj->f_bounds_safe = l1;
        t0 = (void*) _a0_obj;
        l3 = vader_ref_box(t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(2)) {
        vader_struct_vader_bytecode_LoadSlotI64_t* _a1_obj = (vader_struct_vader_bytecode_LoadSlotI64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LoadSlotI64_t));
        vader_obj_header_init(_a1_obj, 616u);
        _a1_obj->f_bounds_safe = l1;
        t0 = (void*) _a1_obj;
        l3 = vader_ref_box(t0);
    } else if (l2 == INT32_C(3)) {
        vader_struct_vader_bytecode_LoadSlotF64_t* _a2_obj = (vader_struct_vader_bytecode_LoadSlotF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LoadSlotF64_t));
        vader_obj_header_init(_a2_obj, 614u);
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
        vader_obj_header_init(_a0_obj, 639u);
        _a0_obj->f_bounds_safe = l1;
        t0 = (void*) _a0_obj;
        l3 = vader_ref_box(t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(2)) {
        vader_struct_vader_bytecode_StoreSlotI64_t* _a1_obj = (vader_struct_vader_bytecode_StoreSlotI64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StoreSlotI64_t));
        vader_obj_header_init(_a1_obj, 640u);
        _a1_obj->f_bounds_safe = l1;
        t0 = (void*) _a1_obj;
        l3 = vader_ref_box(t0);
    } else if (l2 == INT32_C(3)) {
        vader_struct_vader_bytecode_StoreSlotF64_t* _a2_obj = (vader_struct_vader_bytecode_StoreSlotF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StoreSlotF64_t));
        vader_obj_header_init(_a2_obj, 638u);
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
    if (l0.tag == 619u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalGet_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 620u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 621u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
        return t1;
    }
    if (!(l0.tag == 618u)) {
        return -(INT32_C(1));
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_slot;
    return t1;
}

static vader_box_t vader_bytecode_slot_width_for(uint8_t l0) {
    vader_box_t l1;
    if (l0 == INT32_C(0)) {
        l1 = vader_box_i32(229u, INT32_C(0));
        return l1;
    }
    if (l0 == INT32_C(5)) {
        l1 = vader_box_i32(229u, INT32_C(0));
    } else if (l0 == INT32_C(12)) {
        l1 = vader_box_i32(229u, INT32_C(0));
    } else if (l0 == INT32_C(1)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(6)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(2)) {
        l1 = vader_box_i32(229u, INT32_C(1));
    } else if (l0 == INT32_C(7)) {
        l1 = vader_box_i32(229u, INT32_C(1));
    } else if (l0 == INT32_C(13)) {
        l1 = vader_box_i32(229u, INT32_C(1));
    } else if (l0 == INT32_C(10)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(3)) {
        l1 = vader_box_i32(229u, INT32_C(2));
    } else if (l0 == INT32_C(8)) {
        l1 = vader_box_i32(229u, INT32_C(2));
    } else if (l0 == INT32_C(4)) {
        l1 = vader_box_i32(229u, INT32_C(2));
    } else if (l0 == INT32_C(9)) {
        l1 = vader_box_i32(229u, INT32_C(2));
    } else if (l0 == INT32_C(11)) {
        l1 = vader_box_i32(229u, INT32_C(3));
    } else if (l0 == INT32_C(14)) {
        l1 = vader_box_i32(229u, INT32_C(4));
    } else if (l0 == INT32_C(15)) {
        l1 = vader_box_i32(229u, INT32_C(4));
    } else if (l0 == INT32_C(16)) {
        l1 = vader_box_i32(229u, INT32_C(4));
    } else if (l0 == INT32_C(17)) {
        l1 = vader_box_i32(229u, INT32_C(2));
    } else if (l0 == INT32_C(18)) {
        l1 = vader_box_i32(229u, INT32_C(4));
    } else {
        if (!(l0 == INT32_C(19))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_box_i32(229u, INT32_C(4));
    }
    return l1;
}

static vader_box_t vader_bytecode_strip_core_member(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l5;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t4 };
    void** gc_raw_roots[2] = { &l2, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string_starts_with(l0, 2105u);
    if (t0) {
        t0 = std_string_ends_with(l0, l1);
        if (t0) {
            l2 = vader_host_std_core_bytes(l0);
            l3 = vader_host_std_core_byte_len(2105u);
            l4 = ((vader_array_t*) l2)->length;
            l5 = vader_host_std_core_byte_len(l1);
            t1 = (l4 - l5);
            l4 = (size_t) (int64_t) t1;
            vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (size_t) l3, (size_t) l4);
            t2 = (void*) _a0_arr;
            t3 = vader_host_std_core_bytes_to_string(t2);
            t4 = vader_box_string(223u, t3);
            { vader_box_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

void* vader_bytecode_strip_self_copies(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    size_t l2, l5, l9, l12;
    bool l4;
    vader_box_t l8 = vader_box_null();
    int32_t l10, l11, l13, l14;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    size_t t4;
    vader_box_t* gc_roots[2] = { &l8, &t3 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l6, &l7, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l2 = ((vader_array_t*) l1)->length;
    l3 = vader_bytecode_mark_jump_targets(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l2);
    l4 = false;
    l5 = (size_t) 0;
    while ((l5 < l2)) {
        t0 = vader_bytecode_foldable_self_copy(l1, l5, l2, l3);
        if (t0) {
            l4 = true;
            break;
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    if (!(l4)) {
        t2 = vader_bytecode_bc_peephole_unchanged(l0);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(169u, 0u, 13u, 1235u);
    l6 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 1u, 7u, 226u);
    ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) -(INT32_C(1));
    t2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t2, (size_t) l2);
    l7 = (void*) _a2_arr;
    l5 = (size_t) 0;
    while ((l5 < l2)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l8 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        t0 = vader_bytecode_foldable_self_copy(l1, l5, l2, l3);
        if (t0) {
            t1 = (l5 + INT64_C(1));
            l9 = (size_t) (int64_t) t1;
            vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
            t3 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l9);
            if (t3.tag == 621u) {
                t4 = ((vader_array_t*) l6)->length;
                l10 = ((int32_t) (size_t) t4);
                vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
                ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5] = (int32_t) l10;
                vader_array_push((vader_array_t*) l6, l8);
            } else {
                l11 = -(INT32_C(1));
                vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
                ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l5] = (int32_t) l11;
            }
            t1 = (l5 + INT64_C(1));
            l12 = (size_t) (int64_t) t1;
            l13 = -(INT32_C(1));
            vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l12)
            ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l12] = (int32_t) l13;
            t1 = (l5 + INT64_C(2));
            l5 = (size_t) (int64_t) t1;
            continue;
        }
        t4 = ((vader_array_t*) l6)->length;
        l14 = ((int32_t) (size_t) t4);
        vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l5)
        ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l5] = (int32_t) l14;
        vader_array_push((vader_array_t*) l6, l8);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l2 = ((vader_array_t*) l6)->length;
    l1 = vader_bytecode_remap_jump_table(l1, l7, l2);
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug;
    l2 = ((vader_array_t*) l6)->length;
    l3 = vader_bytecode_remap_debug(l3, l7, l2);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a9_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a9_obj, 511u);
    _a9_obj->f_body = l6;
    _a9_obj->f_jump_table = l1;
    _a9_obj->f_debug = l3;
    t2 = (void*) _a9_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_bytecode_struct_type_index(void* l0, vader_string_t l1) {
    size_t l2, l3;
    vader_box_t l4;
    void* t0;
    vader_string_t t1;
    int64_t t2;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 517u) {
            t0 = l4.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_name;
            if (t1 == l1) {
                return ((int32_t) (size_t) l2);
            }
        }
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
    }
    return -(INT32_C(1));
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
    size_t l2;
    int64_t l3;
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
        t0 = concat_3(l4, 280u, l5);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = std_core_new_byte_buffer((size_t) 22);
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l1, l2, 1707u);
    t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    l3 = ((int64_t) (int32_t) t1);
    l2 = std_core_write_int(l1, l2, l3);
    t0 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_try_fold_arith(vader_box_t l0, void* l1, size_t l2) {
    size_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    int32_t l6, l7;
    int64_t l8, l9;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &l4, &l5 };
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l2 < INT64_C(2))) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = (l2 - INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    t0 = (l2 - INT64_C(2));
    l3 = (size_t) (int64_t) t0;
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l5.tag == 574u) {
        if (l4.tag == 574u) {
            if (l0.tag == 569u) {
                t1 = l5.payload.obj;
                l6 = ((vader_struct_vader_bytecode_I32Const_t*) t1)->f_value;
                t1 = l4.payload.obj;
                l7 = ((vader_struct_vader_bytecode_I32Const_t*) t1)->f_value;
                vader_struct_vader_bytecode_I32Const_t* _a1_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
                vader_obj_header_init(_a1_obj, 574u);
                _a1_obj->f_value = (l6 + l7);
                t1 = (void*) _a1_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 588u) {
                t1 = l5.payload.obj;
                l6 = ((vader_struct_vader_bytecode_I32Const_t*) t1)->f_value;
                t1 = l4.payload.obj;
                l7 = ((vader_struct_vader_bytecode_I32Const_t*) t1)->f_value;
                vader_struct_vader_bytecode_I32Const_t* _a2_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
                vader_obj_header_init(_a2_obj, 574u);
                _a2_obj->f_value = (l6 - l7);
                t1 = (void*) _a2_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 582u) {
                t1 = l5.payload.obj;
                l6 = ((vader_struct_vader_bytecode_I32Const_t*) t1)->f_value;
                t1 = l4.payload.obj;
                l7 = ((vader_struct_vader_bytecode_I32Const_t*) t1)->f_value;
                vader_struct_vader_bytecode_I32Const_t* _a3_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
                vader_obj_header_init(_a3_obj, 574u);
                _a3_obj->f_value = (l6 * l7);
                t1 = (void*) _a3_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    if (l5.tag == 594u) {
        if (l4.tag == 594u) {
            if (l0.tag == 589u) {
                t1 = l5.payload.obj;
                l8 = ((vader_struct_vader_bytecode_I64Const_t*) t1)->f_value;
                t1 = l4.payload.obj;
                l9 = ((vader_struct_vader_bytecode_I64Const_t*) t1)->f_value;
                vader_struct_vader_bytecode_I64Const_t* _a4_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                vader_obj_header_init(_a4_obj, 594u);
                _a4_obj->f_value = (l8 + l9);
                t1 = (void*) _a4_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 608u) {
                t1 = l5.payload.obj;
                l8 = ((vader_struct_vader_bytecode_I64Const_t*) t1)->f_value;
                t1 = l4.payload.obj;
                l9 = ((vader_struct_vader_bytecode_I64Const_t*) t1)->f_value;
                vader_struct_vader_bytecode_I64Const_t* _a5_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                vader_obj_header_init(_a5_obj, 594u);
                _a5_obj->f_value = (l8 - l9);
                t1 = (void*) _a5_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 602u) {
                t1 = l5.payload.obj;
                l8 = ((vader_struct_vader_bytecode_I64Const_t*) t1)->f_value;
                t1 = l4.payload.obj;
                l9 = ((vader_struct_vader_bytecode_I64Const_t*) t1)->f_value;
                vader_struct_vader_bytecode_I64Const_t* _a6_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                vader_obj_header_init(_a6_obj, 594u);
                _a6_obj->f_value = (l8 * l9);
                t1 = (void*) _a6_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_string_t vader_bytecode_tuple_shape_name(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t l5 = 0;
    size_t l3, l4;
    void* l6 = NULL;
    uint64_t l7;
    int64_t t0;
    size_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l5, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_type_key_join(l0, 767u);
    l2 = vader_bytecode_fnv1a_hex(l1);
    l1 = vader_bytecode_c_safe_key(l1);
    l3 = vader_host_std_core_byte_len(l1);
    t0 = (INT64_C(32) - INT64_C(1));
    l4 = (size_t) (int64_t) t0;
    if (!((l3 <= l4))) {
        l5 = l2;
        l3 = vader_host_std_core_byte_len(l5);
        l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(21) + l3));
        l3 = (size_t) 0;
        t1 = ((vader_array_t*) l0)->length;
        t0 = ((int64_t) (size_t) t1);
        l7 = (uint64_t) (int64_t) t0;
        l3 = std_core_write_unsigned(l6, l3, l7);
        l3 = std_core_write_string_at(l6, l3, 767u);
        l3 = std_core_write_string_at(l6, l3, l5);
        t2 = std_core_finish_buffer(l6, l3);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_string_slice_codepoints(l2, INT64_C(0), INT64_C(8));
    t2 = concat_3(l1, 767u, l2);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint64_t vader_bytecode_type_args_hash(uint64_t l0, void* l1) {
    uint64_t l2, l6;
    void* l3 = NULL;
    size_t l4, l5;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    size_t t2;
    uint64_t t3;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l6 = vader_bytecode_type_intern_hash(t0);
        l2 = vader_bytecode_mix64(l2, l6);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    t2 = ((vader_array_t*) l1)->length;
    t1 = ((int64_t) (size_t) t2);
    l6 = (uint64_t) (int64_t) t1;
    t3 = vader_bytecode_mix64(l2, l6);
    { uint64_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_bytecode_type_index_of(vader_box_t l0) {
    int32_t l1;
    void* t0;
    if (l0.tag == 648u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_type_id;
        return l1;
    }
    if (l0.tag == 647u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_type_id;
    } else if (l0.tag == 649u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_type_id;
    } else if (l0.tag == 496u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_type_id;
    } else if (l0.tag == 494u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_ArrayGet_t*) t0)->f_type_id;
    } else if (l0.tag == 501u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_ArraySet_t*) t0)->f_type_id;
    } else if (l0.tag == 497u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_type_id;
    } else if (l0.tag == 650u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_TypeCheck_t*) t0)->f_type_id;
    } else if (l0.tag == 651u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_TypeConst_t*) t0)->f_type_id;
    } else if (l0.tag == 541u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_CallIndirect_t*) t0)->f_type_id;
    } else if (l0.tag == 623u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_env_type_id;
    } else if (l0.tag == 568u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_type_id;
    } else if (l0.tag == 618u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_type_id;
    } else if (l0.tag == 502u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_ArraySlice_t*) t0)->f_type_id;
    } else if (l0.tag == 627u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_RefCast_t*) t0)->f_type_id;
    } else if (l0.tag == 630u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_Retag_t*) t0)->f_type_id;
    } else if (l0.tag == 544u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_type_id;
    } else {
        if (!((l0.tag == 492u || l0.tag == 493u || l0.tag == 495u || l0.tag == 498u || l0.tag == 499u || l0.tag == 500u || l0.tag == 523u || l0.tag == 524u || l0.tag == 525u || l0.tag == 526u || l0.tag == 527u || l0.tag == 528u || l0.tag == 529u || l0.tag == 530u || l0.tag == 531u || l0.tag == 532u || l0.tag == 533u || l0.tag == 534u || l0.tag == 535u || l0.tag == 536u || l0.tag == 539u || l0.tag == 540u || l0.tag == 542u || l0.tag == 543u || l0.tag == 546u || l0.tag == 547u || l0.tag == 548u || l0.tag == 549u || l0.tag == 552u || l0.tag == 553u || l0.tag == 554u || l0.tag == 555u || l0.tag == 556u || l0.tag == 557u || l0.tag == 558u || l0.tag == 559u || l0.tag == 560u || l0.tag == 561u || l0.tag == 562u || l0.tag == 563u || l0.tag == 564u || l0.tag == 565u || l0.tag == 566u || l0.tag == 567u || l0.tag == 569u || l0.tag == 570u || l0.tag == 571u || l0.tag == 572u || l0.tag == 573u || l0.tag == 574u || l0.tag == 575u || l0.tag == 576u || l0.tag == 577u || l0.tag == 578u || l0.tag == 579u || l0.tag == 580u || l0.tag == 581u || l0.tag == 582u || l0.tag == 583u || l0.tag == 584u || l0.tag == 585u || l0.tag == 586u || l0.tag == 587u || l0.tag == 588u || l0.tag == 589u || l0.tag == 590u || l0.tag == 591u || l0.tag == 592u || l0.tag == 593u || l0.tag == 594u || l0.tag == 595u || l0.tag == 596u || l0.tag == 597u || l0.tag == 598u || l0.tag == 599u || l0.tag == 600u || l0.tag == 601u || l0.tag == 602u || l0.tag == 603u || l0.tag == 604u || l0.tag == 605u || l0.tag == 606u || l0.tag == 607u || l0.tag == 608u || l0.tag == 609u || l0.tag == 611u || l0.tag == 612u || l0.tag == 613u || l0.tag == 614u || l0.tag == 615u || l0.tag == 616u || l0.tag == 617u || l0.tag == 619u || l0.tag == 620u || l0.tag == 621u || l0.tag == 622u || l0.tag == 624u || l0.tag == 625u || l0.tag == 628u || l0.tag == 629u || l0.tag == 631u || l0.tag == 632u || l0.tag == 633u || l0.tag == 635u || l0.tag == 636u || l0.tag == 637u || l0.tag == 638u || l0.tag == 639u || l0.tag == 640u || l0.tag == 641u || l0.tag == 642u || l0.tag == 643u || l0.tag == 644u || l0.tag == 645u || l0.tag == 646u || l0.tag == 652u || l0.tag == 653u || l0.tag == 654u || l0.tag == 655u || l0.tag == 656u || l0.tag == 657u || l0.tag == 658u || l0.tag == 659u || l0.tag == 660u || l0.tag == 661u || l0.tag == 662u || l0.tag == 663u || l0.tag == 664u || l0.tag == 665u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = -(INT32_C(1));
    }
    return l1;
}

uint64_t vader_bytecode_type_intern_hash(vader_box_t l0) {
    uint64_t l1, l2, l3;
    void* l4 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l4, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1020u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        l1 = vader_bytecode_bare_hash(t1);
        { uint64_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1013u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
        l1 = vader_bytecode_bare_hash(t1);
    } else if (l0.tag == 1010u) {
        l1 = vader_bytecode_bare_hash(394u);
    } else if ((l0.tag == 1015u || l0.tag == 1016u || l0.tag == 1017u || l0.tag == 1018u || l0.tag == 1021u || l0.tag == 1025u || l0.tag == 1026u || l0.tag == 1028u)) {
        t1 = vader_types_display_type(l0);
        l1 = vader_bytecode_bare_hash(t1);
    } else if (l0.tag == 1012u) {
        t0 = l0.payload.obj;
        l1 = vader_bytecode_type_intern_hash(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 1022u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 1);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_symbol_hash(((vader_struct_vader_types_StructType_t*) t0)->f_symbol);
        l2 = vader_bytecode_mix64(l2, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
        l1 = vader_bytecode_type_args_hash(l2, l4);
    } else if (l0.tag == 1023u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 2);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_symbol_hash(((vader_struct_vader_types_TraitType_t*) t0)->f_symbol);
        l2 = vader_bytecode_mix64(l2, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
        l1 = vader_bytecode_type_args_hash(l2, l4);
    } else if (l0.tag == 1011u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 3);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_type_intern_hash(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        l1 = vader_bytecode_mix64(l2, l3);
    } else if (l0.tag == 1027u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 4);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        l1 = vader_bytecode_type_args_hash(l2, l4);
    } else if (l0.tag == 1024u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 5);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
        l1 = vader_bytecode_type_args_hash(l2, l4);
    } else {
        if (!(l0.tag == 1014u)) {
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
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1020u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1022u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_symbol_key(((vader_struct_vader_types_StructType_t*) t0)->f_symbol);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_type_key_join(((vader_struct_vader_types_StructType_t*) t0)->f_args, 2530u);
        l1 = concat_5(622u, l2, 353u, l3, 375u);
    } else if (l0.tag == 1023u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_symbol_key(((vader_struct_vader_types_TraitType_t*) t0)->f_symbol);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_type_key_join(((vader_struct_vader_types_TraitType_t*) t0)->f_args, 2530u);
        l1 = concat_5(713u, l2, 353u, l3, 375u);
    } else if (l0.tag == 1013u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
    } else if (l0.tag == 1012u) {
        t0 = l0.payload.obj;
        l1 = vader_bytecode_type_intern_key(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 1011u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_type_intern_key(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        l1 = concat_3(396u, l2, 375u);
    } else if (l0.tag == 1027u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_type_key_join(((vader_struct_vader_types_UnionType_t*) t0)->f_variants, 2530u);
        l1 = concat_3(720u, l2, 375u);
    } else if (l0.tag == 1024u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_type_key_join(((vader_struct_vader_types_TupleType_t*) t0)->f_elements, 2530u);
        l1 = concat_3(715u, l2, 375u);
    } else if (l0.tag == 1014u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_type_key_join(((vader_struct_vader_types_FnType_t*) t0)->f_params, 255u);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_type_intern_key(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
        l1 = concat_4(463u, l2, 246u, l3);
    } else if (l0.tag == 1026u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1025u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1021u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1028u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1017u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1015u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1016u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1018u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else {
        if (!(l0.tag == 1010u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 394u;
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_bytecode_type_key_join(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    size_t l3, l4;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l5, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = 0u;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        if ((l3 > INT64_C(0))) {
            l5 = l1;
        } else {
            l5 = 0u;
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        l6 = vader_bytecode_type_intern_key(t0);
        l2 = concat_3(l2, l5, l6);
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
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
        l2 = vader_bytecode_neg_op(l1);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        vader_struct_vader_bytecode_BoolNot_t* _a0_obj = (vader_struct_vader_bytecode_BoolNot_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolNot_t));
        vader_obj_header_init(_a0_obj, 530u);
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

vader_string_t vader_bytecode_val_type_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 1706u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1661u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1662u;
    } else if (l0 == INT32_C(3)) {
        l1 = 1684u;
    } else if (l0 == INT32_C(4)) {
        l1 = 1785u;
    } else if (l0 == INT32_C(5)) {
        l1 = 2301u;
    } else if (l0 == INT32_C(6)) {
        l1 = 2280u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2281u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2291u;
    } else if (l0 == INT32_C(9)) {
        l1 = 2344u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1544u;
    } else if (l0 == INT32_C(11)) {
        l1 = 1546u;
    } else if (l0 == INT32_C(12)) {
        l1 = 1252u;
    } else if (l0 == INT32_C(13)) {
        l1 = 1359u;
    } else if (l0 == INT32_C(14)) {
        l1 = 2148u;
    } else if (l0 == INT32_C(15)) {
        l1 = 1946u;
    } else if (l0 == INT32_C(16)) {
        l1 = 2484u;
    } else if (l0 == INT32_C(17)) {
        l1 = 1995u;
    } else if (l0 == INT32_C(18)) {
        l1 = 2021u;
    } else {
        if (!(l0 == INT32_C(19))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1184u;
    }
    return l1;
}

static uint8_t vader_bytecode_val_type_of_primitive_name(vader_string_t l0) {
    vader_box_t l1;
    uint8_t t0;
    if (l0 == 425u) {
        return (uint8_t) 17;
    }
    l1 = vader_bytecode_parse_val_type(l0);
    if (l1.tag == 0u) {
        return (uint8_t) 19;
    }
    t0 = ((uint8_t) l1.payload.i);
    return t0;
}

uint8_t vader_bytecode_val_type_of_type(vader_box_t l0) {
    uint8_t l1;
    void* t0;
    vader_string_t t1;
    if (l0.tag == 1020u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        l1 = vader_bytecode_val_type_of_primitive_name(t1);
        return l1;
    }
    if (l0.tag == 1022u) {
        l1 = (uint8_t) 18;
    } else if (l0.tag == 1013u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
        l1 = vader_bytecode_val_type_of_primitive_name(t1);
    } else if (l0.tag == 1012u) {
        t0 = l0.payload.obj;
        l1 = vader_bytecode_val_type_of_type(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 1011u) {
        l1 = (uint8_t) 18;
    } else if (l0.tag == 1014u) {
        l1 = (uint8_t) 18;
    } else if (l0.tag == 1024u) {
        l1 = (uint8_t) 18;
    } else if (l0.tag == 1023u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 1027u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 1026u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 1025u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 1021u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 1010u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 1028u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 1017u) {
        l1 = (uint8_t) 2;
    } else if (l0.tag == 1015u) {
        l1 = (uint8_t) 13;
    } else if (l0.tag == 1016u) {
        l1 = (uint8_t) 11;
    } else {
        if (!(l0.tag == 1018u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = (uint8_t) 16;
    }
    return l1;
}

static void vader_bytecode_visit_type(int32_t l0, void* l1, void* l2) {
    size_t l3, l4;
    void* l5 = NULL;
    vader_box_t l6 = vader_box_null();
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    int32_t t3;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l1, &l2, &l5, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l0 < INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = std_collections_MutableSet_Contains_contains__i32(l2, l0);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = ((int64_t) (int32_t) l0);
    l3 = (size_t) (int64_t) t1;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
    if ((l3 >= l4)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_collections_add__i32(l2, l0);
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
    t1 = ((int64_t) (int32_t) l0);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l6.tag == 517u) {
        t2 = l6.payload.obj;
        l5 = ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_fields;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            t3 = ((vader_struct_vader_bytecode_BcField_t*) t2)->f_type_index;
            vader_bytecode_visit_type(t3, l1, l2);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    }
    if (l6.tag == 518u) {
        t2 = l6.payload.obj;
        l5 = ((vader_struct_vader_bytecode_BcUnion_t*) t2)->f_variants;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
            vader_bytecode_visit_type(t3, l1, l2);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    }
    if (l6.tag == 504u) {
        t2 = l6.payload.obj;
        t3 = ((vader_struct_vader_bytecode_BcArray_t*) t2)->f_element;
        vader_bytecode_visit_type(t3, l1, l2);
    }
    if (l6.tag == 507u) {
        t2 = l6.payload.obj;
        l5 = ((vader_struct_vader_bytecode_BcFn_t*) t2)->f_params;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
            t3 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
            vader_bytecode_visit_type(t3, l1, l2);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
        t2 = l6.payload.obj;
        t3 = ((vader_struct_vader_bytecode_BcFn_t*) t2)->f_return_type;
        vader_bytecode_visit_type(t3, l1, l2);
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
    if (l0.tag == 619u) {
        vader_struct_vader_bytecode_LocalGet_t* _a0_obj = (vader_struct_vader_bytecode_LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalGet_t));
        vader_obj_header_init(_a0_obj, 619u);
        _a0_obj->f_slot = l1;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 620u) {
        vader_struct_vader_bytecode_LocalSet_t* _a1_obj = (vader_struct_vader_bytecode_LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalSet_t));
        vader_obj_header_init(_a1_obj, 620u);
        _a1_obj->f_slot = l1;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 621u) {
        vader_struct_vader_bytecode_LocalTee_t* _a2_obj = (vader_struct_vader_bytecode_LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalTee_t));
        vader_obj_header_init(_a2_obj, 621u);
        _a2_obj->f_slot = l1;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 618u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_type_id;
    t0 = l0.payload.obj;
    l3 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_field_index;
    vader_struct_vader_bytecode_LocalField_t* _a3_obj = (vader_struct_vader_bytecode_LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalField_t));
    vader_obj_header_init(_a3_obj, 618u);
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
    vader_array_t* _a0_arr = vader_array_new(158u, 0u, 13u, 1104u);
    l2 = (void*) _a0_arr;
    vader_bytecode_write_op_refs(l0, l2, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_bytecode_write_op_refs(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    size_t l4;
    int64_t l5;
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
    bool t5;
    vader_box_t* gc_roots[2] = { &l2, &l13 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l10, &l12, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l14 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2.tag == 574u) {
        l3 = std_core_new_byte_buffer((size_t) 30);
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l3, l4, 1668u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_I32Const_t*) t0)->f_value;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core_write_int(l3, l4, l5);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 594u) {
        l3 = std_core_new_byte_buffer((size_t) 30);
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l3, l4, 1690u);
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_bytecode_I64Const_t*) t0)->f_value;
        l4 = std_core_write_int(l3, l4, l5);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 555u) {
        t0 = l2.payload.obj;
        t2 = ((vader_struct_vader_bytecode_F64Const_t*) t0)->f_value;
        l6 = vader_bytecode_f64_const_operands(t2);
        l6 = concat_2(1548u, l6);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 527u) {
        l3 = std_core_new_byte_buffer((size_t) 16);
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l3, l4, 1254u);
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_bytecode_BoolConst_t*) t0)->f_value;
        l4 = std_core_write_bool(l3, l4, l7);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 542u) {
        l3 = std_core_new_byte_buffer((size_t) 31);
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l3, l4, 1361u);
        t0 = l2.payload.obj;
        t3 = ((vader_struct_vader_bytecode_CharConst_t*) t0)->f_value;
        t4 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3));
        l8 = (uint64_t) (int64_t) t4;
        l4 = std_core_write_unsigned(l3, l4, l8);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 625u) {
        std_string_builder_append(l0, 1947u);
    } else if (l2.tag == 643u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_StringConst_t*) t0)->f_index;
        t0 = vader_bytecode_refer((uint8_t) 3, l9);
        vader_array_t* _a0_arr = vader_array_new(43u, 1u, 13u, 626u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0;
        l3 = (void*) _a0_arr;
        vader_bytecode_printed(l0, l1, 2154u, l3);
    } else if (l2.tag == 619u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_LocalGet_t*) t0)->f_slot;
        t0 = vader_bytecode_refer((uint8_t) 6, l9);
        vader_array_t* _a1_arr = vader_array_new(43u, 1u, 13u, 626u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
        l3 = (void*) _a1_arr;
        vader_bytecode_printed(l0, l1, 1845u, l3);
    } else if (l2.tag == 620u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
        t0 = vader_bytecode_refer((uint8_t) 6, l9);
        vader_array_t* _a2_arr = vader_array_new(43u, 1u, 13u, 626u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0;
        l3 = (void*) _a2_arr;
        vader_bytecode_printed(l0, l1, 1846u, l3);
    } else if (l2.tag == 621u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
        t0 = vader_bytecode_refer((uint8_t) 6, l9);
        vader_array_t* _a3_arr = vader_array_new(43u, 1u, 13u, 626u);
        ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = t0;
        l3 = (void*) _a3_arr;
        vader_bytecode_printed(l0, l1, 1847u, l3);
    } else if (l2.tag == 618u) {
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
        vader_array_t* _a4_arr = vader_array_new(43u, 3u, 13u, 626u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 2u] = l12;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l10;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l3;
        l3 = (void*) _a4_arr;
        vader_bytecode_printed(l0, l1, 1844u, l3);
    } else if (l2.tag == 631u) {
        std_string_builder_append(l0, 2042u);
    } else if (l2.tag == 632u) {
        std_string_builder_append(l0, 2045u);
        vader_array_push((vader_array_t*) l1, vader_box_obj(0u, NULL));
        t0 = l2.payload.obj;
        l13 = ((vader_struct_vader_bytecode_ReturnLit_t*) t0)->f_value;
        vader_bytecode_write_op_refs(l0, l1, l13);
    } else if (l2.tag == 548u) {
        std_string_builder_append(l0, 1453u);
    } else if (l2.tag == 539u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_Call_t*) t0)->f_function_index;
        t0 = vader_bytecode_refer((uint8_t) 0, l9);
        vader_array_t* _a5_arr = vader_array_new(43u, 1u, 13u, 626u);
        ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = t0;
        l3 = (void*) _a5_arr;
        vader_bytecode_printed(l0, l1, 1324u, l3);
    } else if (l2.tag == 540u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_CallImport_t*) t0)->f_index;
        t0 = vader_bytecode_refer((uint8_t) 4, l9);
        vader_array_t* _a6_arr = vader_array_new(43u, 1u, 13u, 626u);
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = t0;
        l3 = (void*) _a6_arr;
        vader_bytecode_printed(l0, l1, 1326u, l3);
    } else if (l2.tag == 541u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_CallIndirect_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a7_arr = vader_array_new(43u, 1u, 13u, 626u);
        ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t0;
        l3 = (void*) _a7_arr;
        vader_bytecode_printed(l0, l1, 1327u, l3);
    } else if (l2.tag == 665u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_VirtualCall_t*) t0)->f_vtable_key;
        l4 = vader_host_std_core_byte_len(l6);
        l3 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(34) + l4));
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l3, l4, 2482u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_VirtualCall_t*) t0)->f_parameter_count;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core_write_int(l3, l4, l5);
        l4 = std_core_write_string_at(l3, l4, 8u);
        l4 = std_core_write_string_at(l3, l4, l6);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 568u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_function_index;
        l3 = vader_bytecode_refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_type_id;
        l10 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a8_arr = vader_array_new(43u, 2u, 13u, 626u);
        ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 1u] = l10;
        ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = l3;
        l3 = (void*) _a8_arr;
        vader_bytecode_printed(l0, l1, 1602u, l3);
    } else if (l2.tag == 567u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_FnAddr_t*) t0)->f_function_index;
        t0 = vader_bytecode_refer((uint8_t) 0, l9);
        vader_array_t* _a9_arr = vader_array_new(43u, 1u, 13u, 626u);
        ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = t0;
        l3 = (void*) _a9_arr;
        vader_bytecode_printed(l0, l1, 1600u, l3);
    } else if (l2.tag == 623u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_function_index;
        l3 = vader_bytecode_refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_env_type_id;
        l10 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a10_arr = vader_array_new(43u, 2u, 13u, 626u);
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 1u] = l10;
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = l3;
        l3 = (void*) _a10_arr;
        vader_bytecode_printed(l0, l1, 1862u, l3);
    } else if (l2.tag == 609u) {
        std_string_builder_append(l0, 1711u);
    } else if (l2.tag == 549u) {
        std_string_builder_append(l0, 1464u);
    } else if (l2.tag == 552u) {
        std_string_builder_append(l0, 1470u);
    } else if (l2.tag == 525u) {
        std_string_builder_append(l0, 1251u);
    } else if (l2.tag == 622u) {
        std_string_builder_append(l0, 1850u);
    } else if (l2.tag == 532u) {
        std_string_builder_append(l0, 1262u);
    } else if (l2.tag == 533u) {
        std_string_builder_append(l0, 1264u);
    } else if (l2.tag == 530u) {
        std_string_builder_append(l0, 1257u);
    } else if (l2.tag == 648u) {
        t0 = l2.payload.obj;
        t5 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_stack;
        if (t5) {
            l6 = 2178u;
        } else {
            l6 = 2175u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a11_arr = vader_array_new(43u, 1u, 13u, 626u);
        ((void**) _a11_arr->buf->slots)[_a11_arr->offset + 0u] = t0;
        l3 = (void*) _a11_arr;
        vader_bytecode_printed(l0, l1, l6, l3);
    } else if (l2.tag == 647u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_type_id;
        l3 = vader_bytecode_refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_field_index;
        l10 = vader_bytecode_refer_field(l9, l11);
        vader_array_t* _a12_arr = vader_array_new(43u, 2u, 13u, 626u);
        ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 1u] = l10;
        ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = l3;
        l3 = (void*) _a12_arr;
        vader_bytecode_printed(l0, l1, 2174u, l3);
    } else if (l2.tag == 649u) {
        t0 = l2.payload.obj;
        t5 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_stack;
        if (t5) {
            l6 = 2183u;
        } else {
            l6 = 2179u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_type_id;
        l3 = vader_bytecode_refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_field_index;
        l10 = vader_bytecode_refer_field(l9, l11);
        vader_array_t* _a13_arr = vader_array_new(43u, 2u, 13u, 626u);
        ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 1u] = l10;
        ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 0u] = l3;
        l3 = (void*) _a13_arr;
        vader_bytecode_printed(l0, l1, l6, l3);
    } else if (l2.tag == 496u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a14_arr = vader_array_new(43u, 1u, 13u, 626u);
        ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = t0;
        l3 = (void*) _a14_arr;
        vader_bytecode_printed(l0, l1, 1208u, l3);
        l3 = std_core_new_byte_buffer((size_t) 21);
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l3, l4, 8u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_length;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core_write_int(l3, l4, l5);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 495u) {
        std_string_builder_append(l0, 1207u);
    } else if (l2.tag == 497u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_cache_slot;
        if ((t1 >= INT32_C(0))) {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_type_id;
            l3 = vader_bytecode_refer((uint8_t) 1, l9);
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_cache_slot;
            l10 = vader_bytecode_refer((uint8_t) 6, l9);
            vader_array_t* _a15_arr = vader_array_new(43u, 2u, 13u, 626u);
            ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 1u] = l10;
            ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 0u] = l3;
            l3 = (void*) _a15_arr;
            vader_bytecode_printed(l0, l1, 1210u, l3);
        } else {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_type_id;
            t0 = vader_bytecode_refer((uint8_t) 1, l9);
            vader_array_t* _a16_arr = vader_array_new(43u, 1u, 13u, 626u);
            ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 0u] = t0;
            l3 = (void*) _a16_arr;
            vader_bytecode_printed(l0, l1, 1210u, l3);
        }
    } else if (l2.tag == 494u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_ArrayGet_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a17_arr = vader_array_new(43u, 1u, 13u, 626u);
        ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = t0;
        l3 = (void*) _a17_arr;
        vader_bytecode_printed(l0, l1, 1206u, l3);
    } else if (l2.tag == 501u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_ArraySet_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a18_arr = vader_array_new(43u, 1u, 13u, 626u);
        ((void**) _a18_arr->buf->slots)[_a18_arr->offset + 0u] = t0;
        l3 = (void*) _a18_arr;
        vader_bytecode_printed(l0, l1, 1219u, l3);
    } else if (l2.tag == 502u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_ArraySlice_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a19_arr = vader_array_new(43u, 1u, 13u, 626u);
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 0u] = t0;
        l3 = (void*) _a19_arr;
        vader_bytecode_printed(l0, l1, 1220u, l3);
    } else if (l2.tag == 500u) {
        std_string_builder_append(l0, 1216u);
    } else if (l2.tag == 498u) {
        std_string_builder_append(l0, 1211u);
    } else if (l2.tag == 493u) {
        std_string_builder_append(l0, 1198u);
    } else if (l2.tag == 499u) {
        std_string_builder_append(l0, 1214u);
    } else if (l2.tag == 492u) {
        std_string_builder_append(l0, 1196u);
    } else if (l2.tag == 544u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_pool_index;
        l3 = vader_bytecode_refer((uint8_t) 5, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_type_id;
        l10 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a20_arr = vader_array_new(43u, 2u, 13u, 626u);
        ((void**) _a20_arr->buf->slots)[_a20_arr->offset + 1u] = l10;
        ((void**) _a20_arr->buf->slots)[_a20_arr->offset + 0u] = l3;
        l3 = (void*) _a20_arr;
        vader_bytecode_printed(l0, l1, 1420u, l3);
    } else if (l2.tag == 651u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_TypeConst_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a21_arr = vader_array_new(43u, 1u, 13u, 626u);
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 0u] = t0;
        l3 = (void*) _a21_arr;
        vader_bytecode_printed(l0, l1, 2261u, l3);
    } else if (l2.tag == 650u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_TypeCheck_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a22_arr = vader_array_new(43u, 1u, 13u, 626u);
        ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = t0;
        l3 = (void*) _a22_arr;
        vader_bytecode_printed(l0, l1, 2264u, l3);
    } else if (l2.tag == 627u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_RefCast_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a23_arr = vader_array_new(43u, 1u, 13u, 626u);
        ((void**) _a23_arr->buf->slots)[_a23_arr->offset + 0u] = t0;
        l3 = (void*) _a23_arr;
        vader_bytecode_printed(l0, l1, 2022u, l3);
    } else if (l2.tag == 630u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_Retag_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a24_arr = vader_array_new(43u, 1u, 13u, 626u);
        ((void**) _a24_arr->buf->slots)[_a24_arr->offset + 0u] = t0;
        l3 = (void*) _a24_arr;
        vader_bytecode_printed(l0, l1, 2041u, l3);
    } else if (l2.tag == 664u) {
        std_string_builder_append(l0, 2325u);
    } else if (l2.tag == 543u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_Convert_t*) t0)->f_from_name;
        t0 = l2.payload.obj;
        l14 = vader_bytecode_convert_target_name(((vader_struct_vader_bytecode_Convert_t*) t0)->f_target);
        l6 = concat_3(l6, 302u, l14);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 633u) {
        std_string_builder_append(l0, 1767u);
    } else if (l2.tag == 569u) {
        std_string_builder_append(l0, 1663u);
    } else if (l2.tag == 588u) {
        std_string_builder_append(l0, 1683u);
    } else if (l2.tag == 582u) {
        std_string_builder_append(l0, 1677u);
    } else if (l2.tag == 575u) {
        std_string_builder_append(l0, 1669u);
    } else if (l2.tag == 581u) {
        std_string_builder_append(l0, 1680u);
    } else if (l2.tag == 584u) {
        std_string_builder_append(l0, 1679u);
    } else if (l2.tag == 571u) {
        std_string_builder_append(l0, 1665u);
    } else if (l2.tag == 570u) {
        std_string_builder_append(l0, 1664u);
    } else if (l2.tag == 572u) {
        std_string_builder_append(l0, 1666u);
    } else if (l2.tag == 573u) {
        std_string_builder_append(l0, 1667u);
    } else if (l2.tag == 585u) {
        std_string_builder_append(l0, 1681u);
    } else if (l2.tag == 586u) {
        std_string_builder_append(l0, 1682u);
    } else if (l2.tag == 587u) {
        std_string_builder_append(l0, 2290u);
    } else if (l2.tag == 576u) {
        std_string_builder_append(l0, 1671u);
    } else if (l2.tag == 583u) {
        std_string_builder_append(l0, 1678u);
    } else if (l2.tag == 580u) {
        std_string_builder_append(l0, 1675u);
    } else if (l2.tag == 579u) {
        std_string_builder_append(l0, 1674u);
    } else if (l2.tag == 578u) {
        std_string_builder_append(l0, 1673u);
    } else if (l2.tag == 577u) {
        std_string_builder_append(l0, 1672u);
    } else if (l2.tag == 589u) {
        std_string_builder_append(l0, 1685u);
    } else if (l2.tag == 608u) {
        std_string_builder_append(l0, 1705u);
    } else if (l2.tag == 602u) {
        std_string_builder_append(l0, 1698u);
    } else if (l2.tag == 595u) {
        std_string_builder_append(l0, 1691u);
    } else if (l2.tag == 601u) {
        std_string_builder_append(l0, 1701u);
    } else if (l2.tag == 604u) {
        std_string_builder_append(l0, 1700u);
    } else if (l2.tag == 590u) {
        std_string_builder_append(l0, 1686u);
    } else if (l2.tag == 592u) {
        std_string_builder_append(l0, 1688u);
    } else if (l2.tag == 593u) {
        std_string_builder_append(l0, 1689u);
    } else if (l2.tag == 591u) {
        std_string_builder_append(l0, 1687u);
    } else if (l2.tag == 605u) {
        std_string_builder_append(l0, 1703u);
    } else if (l2.tag == 606u) {
        std_string_builder_append(l0, 1704u);
    } else if (l2.tag == 607u) {
        std_string_builder_append(l0, 2300u);
    } else if (l2.tag == 596u) {
        std_string_builder_append(l0, 1693u);
    } else if (l2.tag == 603u) {
        std_string_builder_append(l0, 1699u);
    } else if (l2.tag == 600u) {
        std_string_builder_append(l0, 1697u);
    } else if (l2.tag == 599u) {
        std_string_builder_append(l0, 1696u);
    } else if (l2.tag == 598u) {
        std_string_builder_append(l0, 1695u);
    } else if (l2.tag == 597u) {
        std_string_builder_append(l0, 1694u);
    } else if (l2.tag == 652u) {
        std_string_builder_append(l0, 2282u);
    } else if (l2.tag == 657u) {
        std_string_builder_append(l0, 2288u);
    } else if (l2.tag == 656u) {
        std_string_builder_append(l0, 2287u);
    } else if (l2.tag == 655u) {
        std_string_builder_append(l0, 2286u);
    } else if (l2.tag == 654u) {
        std_string_builder_append(l0, 2285u);
    } else if (l2.tag == 653u) {
        std_string_builder_append(l0, 2284u);
    } else if (l2.tag == 658u) {
        std_string_builder_append(l0, 2292u);
    } else if (l2.tag == 663u) {
        std_string_builder_append(l0, 2298u);
    } else if (l2.tag == 662u) {
        std_string_builder_append(l0, 2297u);
    } else if (l2.tag == 661u) {
        std_string_builder_append(l0, 2296u);
    } else if (l2.tag == 660u) {
        std_string_builder_append(l0, 2295u);
    } else if (l2.tag == 659u) {
        std_string_builder_append(l0, 2294u);
    } else if (l2.tag == 554u) {
        std_string_builder_append(l0, 1547u);
    } else if (l2.tag == 565u) {
        std_string_builder_append(l0, 1558u);
    } else if (l2.tag == 562u) {
        std_string_builder_append(l0, 1555u);
    } else if (l2.tag == 556u) {
        std_string_builder_append(l0, 1549u);
    } else if (l2.tag == 564u) {
        std_string_builder_append(l0, 1557u);
    } else if (l2.tag == 557u) {
        std_string_builder_append(l0, 1550u);
    } else if (l2.tag == 563u) {
        std_string_builder_append(l0, 1556u);
    } else if (l2.tag == 561u) {
        std_string_builder_append(l0, 1554u);
    } else if (l2.tag == 560u) {
        std_string_builder_append(l0, 1553u);
    } else if (l2.tag == 559u) {
        std_string_builder_append(l0, 1552u);
    } else if (l2.tag == 558u) {
        std_string_builder_append(l0, 1551u);
    } else if (l2.tag == 528u) {
        std_string_builder_append(l0, 1255u);
    } else if (l2.tag == 529u) {
        std_string_builder_append(l0, 1256u);
    } else if (l2.tag == 526u) {
        std_string_builder_append(l0, 1253u);
    } else if (l2.tag == 531u) {
        std_string_builder_append(l0, 1258u);
    } else if (l2.tag == 644u) {
        std_string_builder_append(l0, 2155u);
    } else if (l2.tag == 645u) {
        std_string_builder_append(l0, 2157u);
    } else if (l2.tag == 642u) {
        std_string_builder_append(l0, 2153u);
    } else if (l2.tag == 646u) {
        std_string_builder_append(l0, 2158u);
    } else if (l2.tag == 628u) {
        std_string_builder_append(l0, 2023u);
    } else if (l2.tag == 629u) {
        std_string_builder_append(l0, 2024u);
    } else if (l2.tag == 547u) {
        std_string_builder_append(l0, 1438u);
    } else if (l2.tag == 546u) {
        l3 = std_core_new_byte_buffer((size_t) 35);
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l3, l4, 1436u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_DeferPopExec_t*) t0)->f_count;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core_write_int(l3, l4, l5);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 534u) {
        std_string_builder_append(l0, 1274u);
    } else if (l2.tag == 617u) {
        std_string_builder_append(l0, 1839u);
    } else if (l2.tag == 612u) {
        std_string_builder_append(l0, 1833u);
    } else if (l2.tag == 613u) {
        std_string_builder_append(l0, 1834u);
    } else if (l2.tag == 611u) {
        std_string_builder_append(l0, 1832u);
    } else if (l2.tag == 641u) {
        std_string_builder_append(l0, 2146u);
    } else if (l2.tag == 636u) {
        std_string_builder_append(l0, 2139u);
    } else if (l2.tag == 637u) {
        std_string_builder_append(l0, 2140u);
    } else if (l2.tag == 635u) {
        std_string_builder_append(l0, 2137u);
    } else if (l2.tag == 615u) {
        std_string_builder_append(l0, 1837u);
    } else if (l2.tag == 616u) {
        std_string_builder_append(l0, 1838u);
    } else if (l2.tag == 614u) {
        std_string_builder_append(l0, 1836u);
    } else if (l2.tag == 639u) {
        std_string_builder_append(l0, 2144u);
    } else if (l2.tag == 640u) {
        std_string_builder_append(l0, 2145u);
    } else if (l2.tag == 638u) {
        std_string_builder_append(l0, 2143u);
    } else if (l2.tag == 624u) {
        std_string_builder_append(l0, 1870u);
    } else if (l2.tag == 535u) {
        std_string_builder_append(l0, 1277u);
    } else if (l2.tag == 536u) {
        std_string_builder_append(l0, 1280u);
    } else if (l2.tag == 566u) {
        std_string_builder_append(l0, 1559u);
    } else if (l2.tag == 524u) {
        std_string_builder_append(l0, 1249u);
    } else if (l2.tag == 553u) {
        std_string_builder_append(l0, 1545u);
    } else {
        if (!(l2.tag == 523u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        std_string_builder_append(l0, 1248u);
    }
    { vader_gc_top = gc_frame.prev; return; }
}
