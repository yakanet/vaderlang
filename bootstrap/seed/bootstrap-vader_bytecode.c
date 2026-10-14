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
static bool vader_bytecode_extend_into_loops(void* l0, void* l1, size_t l2, void* l3);
static vader_string_t vader_bytecode_f64_const_operands(double l0);
static void* vader_bytecode_find_loop_ranges(void* l0);
static vader_string_t vader_bytecode_fnv1a_hex(vader_string_t l0);
static bool vader_bytecode_foldable_self_copy(void* l0, size_t l1, size_t l2, void* l3);
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
static int64_t vader_bytecode_value_cell(uint8_t l0, int64_t l1);
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
        if (l1 == 1291u) {
            vader_struct_vader_bytecode_F64Add_t* _a0_obj = (vader_struct_vader_bytecode_F64Add_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Add_t));
            vader_obj_header_init(_a0_obj, 658u);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 2401u) {
            vader_struct_vader_bytecode_F64Sub_t* _a1_obj = (vader_struct_vader_bytecode_F64Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Sub_t));
            vader_obj_header_init(_a1_obj, 669u);
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l1 == 2104u)) {
            vader_struct_vader_bytecode_F64Div_t* _a2_obj = (vader_struct_vader_bytecode_F64Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Div_t));
            vader_obj_header_init(_a2_obj, 660u);
            t1 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_F64Mul_t* _a3_obj = (vader_struct_vader_bytecode_F64Mul_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Mul_t));
        vader_obj_header_init(_a3_obj, 666u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        if (l1 == 1291u) {
            vader_struct_vader_bytecode_I64Add_t* _a4_obj = (vader_struct_vader_bytecode_I64Add_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Add_t));
            vader_obj_header_init(_a4_obj, 693u);
            t1 = (void*) _a4_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 2401u) {
            vader_struct_vader_bytecode_I64Sub_t* _a5_obj = (vader_struct_vader_bytecode_I64Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Sub_t));
            vader_obj_header_init(_a5_obj, 712u);
            t1 = (void*) _a5_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l1 == 2104u)) {
            vader_struct_vader_bytecode_I64Div_t* _a6_obj = (vader_struct_vader_bytecode_I64Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Div_t));
            vader_obj_header_init(_a6_obj, 699u);
            t1 = (void*) _a6_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_I64Mul_t* _a7_obj = (vader_struct_vader_bytecode_I64Mul_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Mul_t));
        vader_obj_header_init(_a7_obj, 706u);
        t1 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 1291u) {
        vader_struct_vader_bytecode_I32Add_t* _a8_obj = (vader_struct_vader_bytecode_I32Add_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Add_t));
        vader_obj_header_init(_a8_obj, 673u);
        t1 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 2401u) {
        vader_struct_vader_bytecode_I32Sub_t* _a9_obj = (vader_struct_vader_bytecode_I32Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Sub_t));
        vader_obj_header_init(_a9_obj, 692u);
        t1 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1 == 2104u)) {
        vader_struct_vader_bytecode_I32Div_t* _a10_obj = (vader_struct_vader_bytecode_I32Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Div_t));
        vader_obj_header_init(_a10_obj, 679u);
        t1 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Mul_t* _a11_obj = (vader_struct_vader_bytecode_I32Mul_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Mul_t));
    vader_obj_header_init(_a11_obj, 686u);
    t1 = (void*) _a11_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

uint8_t vader_bytecode_array_kind_from_name(vader_string_t l0) {
    uint8_t l1;
    if (l0 == 2532u) {
        l1 = (uint8_t) 1;
        return l1;
    }
    if (l0 == 2511u) {
        l1 = (uint8_t) 2;
    } else if (l0 == 2512u) {
        l1 = (uint8_t) 3;
    } else if (l0 == 2522u) {
        l1 = (uint8_t) 4;
    } else if (l0 == 2577u) {
        l1 = (uint8_t) 4;
    } else if (l0 == 1873u) {
        l1 = (uint8_t) 5;
    } else if (l0 == 1828u) {
        l1 = (uint8_t) 6;
    } else if (l0 == 1829u) {
        l1 = (uint8_t) 7;
    } else if (l0 == 1851u) {
        l1 = (uint8_t) 8;
    } else if (l0 == 1959u) {
        l1 = (uint8_t) 8;
    } else if (l0 == 1706u) {
        l1 = (uint8_t) 9;
    } else if (l0 == 1708u) {
        l1 = (uint8_t) 10;
    } else if (l0 == 1514u) {
        l1 = (uint8_t) 11;
    } else if (l0 == 1400u) {
        l1 = (uint8_t) 12;
    } else if (l0 == 2225u) {
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
        l1 = 2532u;
        return l1;
    }
    if (l0 == INT32_C(5)) {
        l1 = 1873u;
    } else if (l0 == INT32_C(12)) {
        l1 = 1400u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2511u;
    } else if (l0 == INT32_C(6)) {
        l1 = 1828u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2512u;
    } else if (l0 == INT32_C(7)) {
        l1 = 1829u;
    } else if (l0 == INT32_C(9)) {
        l1 = 1706u;
    } else if (l0 == INT32_C(11)) {
        l1 = 1514u;
    } else if (l0 == INT32_C(4)) {
        l1 = 2522u;
    } else if (l0 == INT32_C(8)) {
        l1 = 1851u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1708u;
    } else if (l0 == INT32_C(13)) {
        l1 = 2225u;
    } else {
        if (!(l0 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1411u;
    }
    return l1;
}

uint8_t vader_bytecode_array_kind_of(vader_box_t l0, void* l1) {
    uint8_t l2;
    void* t0;
    bool t1;
    if (l0.tag == 615u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_array_kind_of_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val);
        return l2;
    }
    if (l0.tag == 619u) {
        l2 = (uint8_t) 13;
    } else if (l0.tag == 606u) {
        l2 = (uint8_t) 13;
    } else if (l0.tag == 609u) {
        l2 = (uint8_t) 13;
    } else if (l0.tag == 620u) {
        t0 = l0.payload.obj;
        t1 = vader_bytecode_is_ref_only_element(vader_ref_box(t0), l1);
        if (t1) {
            l2 = (uint8_t) 13;
        } else {
            l2 = (uint8_t) 0;
        }
    } else {
        if (!(l0.tag == 616u)) {
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
        t2 = concat_3(1452u, l0, 1010u);
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
    if (l0.tag == 1198u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1191u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
    } else if (l0.tag == 1188u) {
        l1 = 453u;
    } else if ((l0.tag == 1193u || l0.tag == 1194u || l0.tag == 1195u || l0.tag == 1196u || l0.tag == 1199u || l0.tag == 1203u || l0.tag == 1204u || l0.tag == 1206u)) {
        l1 = vader_types_display_type(l0);
    } else {
        if (!((l0.tag == 1189u || l0.tag == 1190u || l0.tag == 1192u || l0.tag == 1200u || l0.tag == 1201u || l0.tag == 1202u || l0.tag == 1205u))) {
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
    vader_obj_header_init(_a0_obj, 613u);
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
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 284u);
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
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 284u);
        { uint8_t __vret = ((uint8_t) t1.payload.i); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = std_core_new_byte_buffer((size_t) 127);
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l1, l2, 1455u);
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results)->length;
    t2 = ((int64_t) (size_t) t0);
    l3 = (uint64_t) (int64_t) t2;
    l2 = std_core_write_unsigned(l1, l2, l3);
    l2 = std_core_write_string_at(l1, l2, 135u);
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
    l2 = std_core_write_string_at(l1, l2, 1454u);
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_result_types)->length;
    t2 = ((int64_t) (size_t) t0);
    l3 = (uint64_t) (int64_t) t2;
    l2 = std_core_write_unsigned(l1, l2, l3);
    l2 = std_core_write_string_at(l1, l2, 135u);
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
        { vader_gc_top = gc_frame.prev; return 437u; }
    }
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    l6 = l5;
    if (l5.tag == 615u) {
        l8 = std_core_new_byte_buffer((size_t) 22);
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l8, l3, 2178u);
        t1 = l6.payload.obj;
        l9 = ((int64_t) (int32_t) ((int32_t) (uint8_t) ((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val));
        l3 = std_core_write_int(l8, l3, l9);
        l7 = std_core_finish_buffer(l8, l3);
        { vader_string_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 619u) {
        t1 = l6.payload.obj;
        l10 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_name;
        l7 = concat_2(2259u, l10);
    } else if (l5.tag == 616u) {
        t1 = l6.payload.obj;
        l10 = ((vader_struct_vader_bytecode_BcRef_t*) t1)->f_trait_name;
        l7 = concat_2(2210u, l10);
    } else if (l5.tag == 606u) {
        t1 = l6.payload.obj;
        l11 = ((vader_struct_vader_bytecode_BcArray_t*) t1)->f_element;
        l10 = vader_bytecode_bc_type_key(l0, l11);
        l7 = concat_3(1287u, l10, 433u);
    } else if (l5.tag == 620u) {
        t1 = l6.payload.obj;
        l8 = ((vader_struct_vader_bytecode_BcUnion_t*) t1)->f_variants;
        l10 = vader_bytecode_key_join(l0, l8, 2769u);
        l7 = concat_3(2533u, l10, 433u);
    } else {
        if (!(l5.tag == 609u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t1 = l6.payload.obj;
        l8 = ((vader_struct_vader_bytecode_BcFn_t*) t1)->f_params;
        l10 = vader_bytecode_key_join(l0, l8, 2769u);
        t1 = l6.payload.obj;
        l11 = ((vader_struct_vader_bytecode_BcFn_t*) t1)->f_return_type;
        l12 = vader_bytecode_bc_type_key(l0, l11);
        l7 = concat_4(1722u, l10, 273u, l12);
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
    if (l0.tag == 1198u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        t2 = vader_bytecode_val_type_of_primitive_name(t1);
        vader_struct_vader_bytecode_BcPrimitive_t* _a0_obj = (vader_struct_vader_bytecode_BcPrimitive_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPrimitive_t));
        vader_obj_header_init(_a0_obj, 615u);
        _a0_obj->f_val = t2;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1191u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
        t2 = vader_bytecode_val_type_of_primitive_name(t1);
        vader_struct_vader_bytecode_BcPrimitive_t* _a1_obj = (vader_struct_vader_bytecode_BcPrimitive_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPrimitive_t));
        vader_obj_header_init(_a1_obj, 615u);
        _a1_obj->f_val = t2;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1190u) {
        t0 = l0.payload.obj;
        t3 = vader_bytecode_bc_type_of_with_ctx(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing, l1, l2);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1200u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_name;
        vader_struct_vader_bytecode_BcRef_t* _a2_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a2_obj, 616u);
        _a2_obj->f_trait_name = t1;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1201u) {
        t0 = l0.payload.obj;
        t1 = vader_types_trait_key_of(((vader_struct_vader_types_TraitType_t*) t0)->f_symbol);
        vader_struct_vader_bytecode_BcRef_t* _a3_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a3_obj, 616u);
        _a3_obj->f_trait_name = t1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1189u) {
        t0 = l0.payload.obj;
        t4 = vader_bytecode_intern_type(((vader_struct_vader_types_ArrayType_t*) t0)->f_element, l1);
        vader_struct_vader_bytecode_BcArray_t* _a4_obj = (vader_struct_vader_bytecode_BcArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcArray_t));
        vader_obj_header_init(_a4_obj, 606u);
        _a4_obj->f_element = t4;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1205u) {
        vader_array_t* _a5_arr = vader_array_new(16u, 0u, 7u, 281u);
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
        vader_obj_header_init(_a7_obj, 620u);
        _a7_obj->f_variants = l3;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1192u) {
        vader_array_t* _a8_arr = vader_array_new(16u, 0u, 7u, 281u);
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
        vader_obj_header_init(_a10_obj, 609u);
        _a10_obj->f_params = l3;
        _a10_obj->f_return_type = l7;
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1202u) {
        vader_array_t* _a11_arr = vader_array_new(47u, 0u, 13u, 608u);
        l3 = (void*) _a11_arr;
        l5 = (size_t) 0;
        t0 = l0.payload.obj;
        l6 = ((vader_array_t*) ((vader_struct_vader_types_TupleType_t*) t0)->f_elements)->length;
        while ((l5 < l6)) {
            l4 = std_core_new_byte_buffer((size_t) 21);
            l8 = (size_t) 0;
            l8 = std_core_write_string_at(l4, l8, 841u);
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
            vader_obj_header_init(_a13_obj, 608u);
            _a13_obj->f_name = l10;
            _a13_obj->f_type_index = l7;
            l11 = (void*) _a13_obj;
            vader_array_push((vader_array_t*) l3, vader_ref_box(l11));
            t5 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t5;
        }
        t0 = l0.payload.obj;
        l10 = vader_bytecode_tuple_shape_name(((vader_struct_vader_types_TupleType_t*) t0)->f_elements);
        t1 = concat_2(857u, l10);
        vader_struct_vader_bytecode_BcStruct_t* _a14_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
        vader_obj_header_init(_a14_obj, 619u);
        _a14_obj->f_name = t1;
        _a14_obj->f_fields = l3;
        _a14_obj->f_c_name = 0u;
        _a14_obj->f_symbol_id = INT32_C(-1);
        t0 = (void*) _a14_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1204u) {
        t0 = (void*) &vader_data_39;
        vader_array_t* _a15_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        t0 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1203u) {
        t0 = (void*) &vader_data_39;
        vader_array_t* _a16_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        t0 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1199u) {
        t0 = (void*) &vader_data_39;
        vader_array_t* _a17_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        t0 = vader_array_ref_load_obj(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1206u) {
        t0 = (void*) &vader_data_39;
        vader_array_t* _a18_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        t0 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1195u) {
        t0 = (void*) &vader_data_39;
        vader_array_t* _a19_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        t0 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1193u) {
        t0 = (void*) &vader_data_39;
        vader_array_t* _a20_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
        t0 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1194u) {
        t0 = (void*) &vader_data_39;
        vader_array_t* _a21_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        t0 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1196u) {
        t0 = (void*) &vader_data_39;
        vader_array_t* _a22_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
        t0 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 1188u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    t0 = (void*) &vader_data_39;
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
        l2 = vader_bytecode_arith_op(l1, 1291u);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        l2 = vader_bytecode_arith_op(l1, 2401u);
    } else if (l0 == INT32_C(2)) {
        l2 = vader_bytecode_arith_op(l1, 2104u);
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
        l2 = vader_bytecode_bit_op(l1, 1326u);
    } else if (l0 == INT32_C(8)) {
        l2 = vader_bytecode_bit_op(l1, 2169u);
    } else if (l0 == INT32_C(9)) {
        l2 = vader_bytecode_bit_op(l1, 2757u);
    } else if (l0 == INT32_C(10)) {
        vader_struct_vader_bytecode_BoolAnd_t* _a0_obj = (vader_struct_vader_bytecode_BoolAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolAnd_t));
        vader_obj_header_init(_a0_obj, 628u);
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(11)) {
        vader_struct_vader_bytecode_BoolOr_t* _a1_obj = (vader_struct_vader_bytecode_BoolOr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolOr_t));
        vader_obj_header_init(_a1_obj, 633u);
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
        if (l1 == 1326u) {
            vader_struct_vader_bytecode_I64BitAnd_t* _a0_obj = (vader_struct_vader_bytecode_I64BitAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitAnd_t));
            vader_obj_header_init(_a0_obj, 694u);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l1 == 2169u)) {
            vader_struct_vader_bytecode_I64BitXor_t* _a1_obj = (vader_struct_vader_bytecode_I64BitXor_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitXor_t));
            vader_obj_header_init(_a1_obj, 697u);
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_I64BitOr_t* _a2_obj = (vader_struct_vader_bytecode_I64BitOr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitOr_t));
        vader_obj_header_init(_a2_obj, 696u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 1326u) {
        vader_struct_vader_bytecode_I32BitAnd_t* _a3_obj = (vader_struct_vader_bytecode_I32BitAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitAnd_t));
        vader_obj_header_init(_a3_obj, 674u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1 == 2169u)) {
        vader_struct_vader_bytecode_I32BitXor_t* _a4_obj = (vader_struct_vader_bytecode_I32BitXor_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitXor_t));
        vader_obj_header_init(_a4_obj, 677u);
        t1 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32BitOr_t* _a5_obj = (vader_struct_vader_bytecode_I32BitOr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitOr_t));
    vader_obj_header_init(_a5_obj, 676u);
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
        vader_obj_header_init(_a0_obj, 675u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64BitNot_t* _a1_obj = (vader_struct_vader_bytecode_I64BitNot_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitNot_t));
    vader_obj_header_init(_a1_obj, 695u);
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
    vader_array_t* _a0_arr = vader_array_new(215u, 0u, 13u, 1441u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_params)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_params)->length;
    while ((l3 < l4)) {
        vader_struct_vader_bytecode_LocalGet_t* _a2_obj = (vader_struct_vader_bytecode_LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalGet_t));
        vader_obj_header_init(_a2_obj, 723u);
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
        vader_obj_header_init(_a3_obj, 642u);
        _a3_obj->f_index = l1;
        l5 = (void*) _a3_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
        vader_struct_vader_bytecode_Return_t* _a4_obj = (vader_struct_vader_bytecode_Return_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Return_t));
        vader_obj_header_init(_a4_obj, 735u);
        l5 = (void*) _a4_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_push((vader_array_t*) l2, l6);
    vader_struct_vader_bytecode_Return_t* _a5_obj = (vader_struct_vader_bytecode_Return_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Return_t));
    vader_obj_header_init(_a5_obj, 735u);
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
        t2 = vader_box_i64(282u, ((int64_t) (int32_t) t1));
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
        t3 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t3;
    }
    t2 = vader_box_i64(282u, l5);
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
    if (!(l4.tag == 615u)) {
        return vader_box_obj(0u, NULL);
    }
    t2 = l4.payload.obj;
    t3 = vader_box_i32(284u, (int32_t)(uint32_t) ((vader_struct_vader_bytecode_BcPrimitive_t*) t2)->f_val);
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
        t2 = vader_box_i64(282u, ((int64_t) (int32_t) t1));
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
    l5 = vader_chk_add(i32, l2, INT32_C(1));
    l4 = vader_bytecode_c_struct_layout_at(l4, l1, l5);
    if (!(((vader_struct_vader_bytecode_CLayout_t*) l4)->f_unknown_field.tag == 0u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t3 = ((vader_struct_vader_bytecode_CLayout_t*) l4)->f_size;
    t2 = vader_box_i64(282u, t3);
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
            l1 = concat_2(l1, 841u);
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
    vader_array_t* _a0_arr = vader_array_new(17u, 0u, 8u, 282u);
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
        l10 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
        l11 = vader_bytecode_c_field_width_at(l10, l1, l2);
        l12 = vader_bytecode_c_field_align_at(l10, l1, l2);
        if (l11.tag == 0u) {
            if (l6.tag == 0u) {
                t0 = ((vader_struct_vader_bytecode_BcField_t*) l10)->f_name;
                l6 = vader_box_string(278u, t0);
            }
            vader_array_push_i64((vader_array_t*) l3, l4);
            t1 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t1;
            continue;
        }
        if (l12.tag == 0u) {
            if (l6.tag == 0u) {
                t0 = ((vader_struct_vader_bytecode_BcField_t*) l10)->f_name;
                l6 = vader_box_string(278u, t0);
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
            l15 = vader_chk_sub(i64, l13, l14);
            l4 = vader_chk_add(i64, l4, l15);
        }
        vader_array_push_i64((vader_array_t*) l3, l4);
        l16 = ((int64_t) l11.payload.i);
        l4 = vader_chk_add(i64, l4, l16);
        t1 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t1;
    }
    l13 = vader_mod_i64(l4, l5);
    if (l13 == INT64_C(0)) {
        l14 = l4;
        vader_struct_vader_bytecode_CLayout_t* _a2_obj = (vader_struct_vader_bytecode_CLayout_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CLayout_t));
        vader_obj_header_init(_a2_obj, 640u);
        _a2_obj->f_offsets = l3;
        _a2_obj->f_size = l14;
        _a2_obj->f_unknown_field = l6;
        t2 = (void*) _a2_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_chk_add(i64, l4, l5);
    l14 = vader_chk_sub(i64, t1, l13);
    vader_struct_vader_bytecode_CLayout_t* _a3_obj = (vader_struct_vader_bytecode_CLayout_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CLayout_t));
    vader_obj_header_init(_a3_obj, 640u);
    _a3_obj->f_offsets = l3;
    _a3_obj->f_size = l14;
    _a3_obj->f_unknown_field = l6;
    t2 = (void*) _a3_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_bytecode_cell_value(uint8_t l0, int64_t l1) {
    bool t0;
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        return l1;
    }
    if (!(l0 == INT32_C(7))) {
        return ((int64_t) (int32_t) ((int32_t) (int64_t) l1));
    }
    return (l1 & INT64_C(4294967295));
}

vader_box_t vader_bytecode_checked_arith(uint8_t l0, uint8_t l1, int64_t l2, int64_t l3) {
    int64_t l4, l6, l7;
    bool l5;
    vader_box_t l8;
    int64_t t0;
    vader_box_t t1;
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
    t1 = vader_box_i64(282u, t0);
    return t1;
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
    vader_obj_header_init(_a0_obj, 645u);
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
    vader_box_t t1;
    l2 = vader_bytecode_integer_bits(l0);
    l3 = vader_bytecode_cell_value(l0, l1);
    l4 = vader_bytecode_is_unsigned_val(l0);
    l5 = vader_integer_checked_negation(l2, l4, l3);
    if (l5.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l2 = ((int64_t) l5.payload.i);
    t0 = vader_bytecode_value_cell(l0, l2);
    t1 = vader_box_i64(282u, t0);
    return t1;
}

vader_string_t vader_bytecode_checked_neg_message(uint8_t l0) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[2] = { &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_val_type_name(l0);
    t1 = concat_2(t0, 341u);
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
    vader_obj_header_init(_a0_obj, 646u);
    _a0_obj->f_kind = l0;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_bytecode_checked_op_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 1291u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2401u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2104u;
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
    t0 = concat_4(l2, 319u, l3, 122u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_cmp_eq(uint8_t l0) {
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(12)) {
        vader_struct_vader_bytecode_BoolEq_t* _a0_obj = (vader_struct_vader_bytecode_BoolEq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolEq_t));
        vader_obj_header_init(_a0_obj, 630u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(14)) {
        vader_struct_vader_bytecode_StringEq_t* _a1_obj = (vader_struct_vader_bytecode_StringEq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringEq_t));
        vader_obj_header_init(_a1_obj, 748u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_float_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_F64Eq_t* _a2_obj = (vader_struct_vader_bytecode_F64Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Eq_t));
        vader_obj_header_init(_a2_obj, 661u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_64_bit_int_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_I64Eq_t* _a3_obj = (vader_struct_vader_bytecode_I64Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Eq_t));
        vader_obj_header_init(_a3_obj, 700u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_ref_class(l0);
    if (!(t1)) {
        vader_struct_vader_bytecode_I32Eq_t* _a4_obj = (vader_struct_vader_bytecode_I32Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Eq_t));
        vader_obj_header_init(_a4_obj, 680u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_RefEq_t* _a5_obj = (vader_struct_vader_bytecode_RefEq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefEq_t));
    vader_obj_header_init(_a5_obj, 732u);
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
        vader_obj_header_init(_a0_obj, 662u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Ge_t* _a1_obj = (vader_struct_vader_bytecode_U64Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Ge_t));
        vader_obj_header_init(_a1_obj, 763u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Ge_t* _a2_obj = (vader_struct_vader_bytecode_U32Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Ge_t));
        vader_obj_header_init(_a2_obj, 757u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Ge_t* _a3_obj = (vader_struct_vader_bytecode_I32Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Ge_t));
        vader_obj_header_init(_a3_obj, 681u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Ge_t* _a4_obj = (vader_struct_vader_bytecode_I64Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Ge_t));
    vader_obj_header_init(_a4_obj, 701u);
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
        vader_obj_header_init(_a0_obj, 663u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Gt_t* _a1_obj = (vader_struct_vader_bytecode_U64Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Gt_t));
        vader_obj_header_init(_a1_obj, 764u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Gt_t* _a2_obj = (vader_struct_vader_bytecode_U32Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Gt_t));
        vader_obj_header_init(_a2_obj, 758u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Gt_t* _a3_obj = (vader_struct_vader_bytecode_I32Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Gt_t));
        vader_obj_header_init(_a3_obj, 682u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Gt_t* _a4_obj = (vader_struct_vader_bytecode_I64Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Gt_t));
    vader_obj_header_init(_a4_obj, 702u);
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
        vader_obj_header_init(_a0_obj, 664u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Le_t* _a1_obj = (vader_struct_vader_bytecode_U64Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Le_t));
        vader_obj_header_init(_a1_obj, 765u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Le_t* _a2_obj = (vader_struct_vader_bytecode_U32Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Le_t));
        vader_obj_header_init(_a2_obj, 759u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Le_t* _a3_obj = (vader_struct_vader_bytecode_I32Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Le_t));
        vader_obj_header_init(_a3_obj, 683u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Le_t* _a4_obj = (vader_struct_vader_bytecode_I64Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Le_t));
    vader_obj_header_init(_a4_obj, 703u);
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
        vader_obj_header_init(_a0_obj, 665u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Lt_t* _a1_obj = (vader_struct_vader_bytecode_U64Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Lt_t));
        vader_obj_header_init(_a1_obj, 766u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Lt_t* _a2_obj = (vader_struct_vader_bytecode_U32Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Lt_t));
        vader_obj_header_init(_a2_obj, 760u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Lt_t* _a3_obj = (vader_struct_vader_bytecode_I32Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Lt_t));
        vader_obj_header_init(_a3_obj, 684u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Lt_t* _a4_obj = (vader_struct_vader_bytecode_I64Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Lt_t));
    vader_obj_header_init(_a4_obj, 704u);
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
        vader_obj_header_init(_a0_obj, 631u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(14)) {
        vader_struct_vader_bytecode_StringNe_t* _a1_obj = (vader_struct_vader_bytecode_StringNe_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringNe_t));
        vader_obj_header_init(_a1_obj, 749u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_float_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_F64Ne_t* _a2_obj = (vader_struct_vader_bytecode_F64Ne_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Ne_t));
        vader_obj_header_init(_a2_obj, 667u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_64_bit_int_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_I64Ne_t* _a3_obj = (vader_struct_vader_bytecode_I64Ne_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Ne_t));
        vader_obj_header_init(_a3_obj, 707u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_ref_class(l0);
    if (!(t1)) {
        vader_struct_vader_bytecode_I32Ne_t* _a4_obj = (vader_struct_vader_bytecode_I32Ne_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Ne_t));
        vader_obj_header_init(_a4_obj, 687u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_RefNe_t* _a5_obj = (vader_struct_vader_bytecode_RefNe_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefNe_t));
    vader_obj_header_init(_a5_obj, 733u);
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_coalesce_slots(void* l0) {
    size_t l1, l2, l4, l7, l10, l21, l22, l23, l25, l27, l31;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l24 = NULL;
    void* l26 = NULL;
    void* l28 = NULL;
    void* l32 = NULL;
    int32_t l9, l11, l12, l13, l14, l29, l30;
    bool l16;
    uint8_t l20;
    vader_box_t l33 = vader_box_null(), l34 = vader_box_null(), l35 = vader_box_null();
    vader_string_t l36 = 0;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    bool t3;
    size_t t4;
    vader_box_t* gc_roots[4] = { &l33, &l34, &l35, &t2 };
    void** gc_raw_roots[14] = {
        &l0, &l3, &l5, &l6, &l8, &l15, &l17, &l18, &l19, &l24, &l26, &l28, &l32, &t1,
    };
    vader_string_t* gc_atom_roots[1] = { &l36 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    t0 = vader_chk_add(usize, l1, l2);
    l2 = (size_t) (int64_t) t0;
    if ((l2 <= l1)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l4 = ((vader_array_t*) l3)->length;
    vader_array_t* _a0_arr = vader_array_new(54u, 0u, 13u, 738u);
    t1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(13u, 0u, 12u, 276u);
    t1 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l6 = (void*) _a3_arr;
    l7 = (size_t) 0;
    while ((l7 < l2)) {
        vader_struct_vader_bytecode_SlotRange_t* _a4_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
        vader_obj_header_init(_a4_obj, 738u);
        _a4_obj->f_first = INT32_C(-1);
        _a4_obj->f_last = INT32_C(-1);
        l8 = (void*) _a4_obj;
        vader_array_push((vader_array_t*) l5, vader_ref_box(l8));
        vader_array_push_bool((vader_array_t*) l6, false);
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    l7 = (size_t) 0;
    while ((l7 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t2 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
        l9 = vader_bytecode_slot_touched(t2);
        if ((l9 >= INT32_C(0))) {
            t0 = ((int64_t) (int32_t) l9);
            l10 = (size_t) (int64_t) t0;
            vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l10)
            t2 = vader_box_bool(276u, ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l10]);
            t3 = t2.payload.b;
            if (t3) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l10)
                t1 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l10);
                l13 = ((vader_struct_vader_bytecode_SlotRange_t*) t1)->f_first;
                l14 = ((int32_t) (size_t) l7);
                vader_struct_vader_bytecode_SlotRange_t* _a8_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                vader_obj_header_init(_a8_obj, 738u);
                _a8_obj->f_first = l13;
                _a8_obj->f_last = l14;
                l15 = (void*) _a8_obj;
                vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l10)
                vader_array_ref_store(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l10, l15);
                VADER_WRITE_BARRIER(_a9_slotarr->buf);
            } else {
                l11 = ((int32_t) (size_t) l7);
                l12 = ((int32_t) (size_t) l7);
                vader_struct_vader_bytecode_SlotRange_t* _a10_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                vader_obj_header_init(_a10_obj, 738u);
                _a10_obj->f_first = l11;
                _a10_obj->f_last = l12;
                l8 = (void*) _a10_obj;
                vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l10)
                vader_array_ref_store(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l10, l8);
                VADER_WRITE_BARRIER(_a11_slotarr->buf);
                vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l10)
                ((uint8_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l10] = (uint8_t) true;
            }
        }
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    l8 = vader_bytecode_find_loop_ranges(l3);
    t4 = ((vader_array_t*) l8)->length;
    if ((t4 > INT64_C(0))) {
        l16 = true;
        while (l16) {
            l16 = vader_bytecode_extend_into_loops(l5, l6, l2, l8);
        }
    }
    l7 = (size_t) 0;
    while ((l7 < l1)) {
        l9 = ((int32_t) (size_t) l4);
        vader_struct_vader_bytecode_SlotRange_t* _a13_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
        vader_obj_header_init(_a13_obj, 738u);
        _a13_obj->f_first = INT32_C(0);
        _a13_obj->f_last = l9;
        l8 = (void*) _a13_obj;
        vader_array_t* _a14_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l7)
        vader_array_ref_store(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l7, l8);
        VADER_WRITE_BARRIER(_a14_slotarr->buf);
        vader_array_t* _a15_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l7)
        ((uint8_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l7] = (uint8_t) true;
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a16_arr = vader_array_new(50u, 0u, 13u, 612u);
    l8 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(16u, 0u, 7u, 281u);
    t1 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l15 = (void*) _a18_arr;
    l7 = (size_t) 0;
    vader_array_t* _pc180_hdr = (vader_array_t*) l15;
    size_t _pc180_len = _pc180_hdr->length;
    size_t _pc180_cap = (_pc180_hdr->offset == 0 && !vader_array_is_borrowed(_pc180_hdr) && _pc180_hdr->length >= _pc180_hdr->buf->length) ? _pc180_hdr->capacity : (size_t) 0;
    void* _pc180_slots = _pc180_hdr->buf->slots;
    for (;;) {
        if ((l7 < l2)) {
            if (VADER_LIKELY(_pc180_len < _pc180_cap)) {
                ((int32_t*) _pc180_slots)[_pc180_len] = (int32_t) (INT32_C(-1));
                _pc180_len += 1;
            } else {
                _pc180_hdr->length = _pc180_len;
                if (_pc180_hdr->buf->length < _pc180_len) {
                    _pc180_hdr->buf->length = _pc180_len;
                }
                vader_array_push_i32((vader_array_t*) l15, INT32_C(-1));
                _pc180_hdr = (vader_array_t*) l15;
                _pc180_len = _pc180_hdr->length;
                _pc180_cap = (_pc180_hdr->offset == 0 && !vader_array_is_borrowed(_pc180_hdr) && _pc180_hdr->length >= _pc180_hdr->buf->length) ? _pc180_hdr->capacity : (size_t) 0;
                _pc180_slots = _pc180_hdr->buf->slots;
            }
            t0 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t0;
            continue;
        }
        _pc180_hdr->length = _pc180_len;
        if (_pc180_hdr->buf->length < _pc180_len) {
            _pc180_hdr->buf->length = _pc180_len;
        }
        break;
    }
    l7 = (size_t) 0;
    while ((l7 < l1)) {
        l9 = ((int32_t) (size_t) l7);
        vader_array_t* _a19_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l7)
        ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l7] = (int32_t) l9;
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a20_arr = vader_array_new(54u, 0u, 13u, 738u);
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
        t2 = vader_box_bool(276u, ((uint8_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l7]);
        t3 = t2.payload.b;
        if (t3) {
            vader_array_t* _a24_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l7)
            l18 = vader_array_ref_load_obj(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l7);
            l19 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
            t0 = vader_chk_sub(usize, l7, l1);
            l10 = (size_t) (int64_t) t0;
            vader_array_t* _a25_slotarr = ((vader_array_t*) l19);
            VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l10)
            t1 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l10);
            l20 = ((vader_struct_vader_bytecode_BcLocal_t*) t1)->f_val;
            l9 = INT32_C(-1);
            l21 = l1;
            l22 = ((vader_array_t*) l17)->length;
            while ((l21 < l22)) {
                t0 = vader_chk_sub(usize, l21, l1);
                l23 = (size_t) (int64_t) t0;
                vader_array_t* _a26_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l23)
                t1 = vader_array_ref_load_obj(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l23);
                if (((vader_struct_vader_bytecode_BcLocal_t*) t1)->f_val == l20) {
                    vader_array_t* _a27_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
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
                t0 = vader_chk_sub(usize, l7, l1);
                l25 = (size_t) (int64_t) t0;
                vader_array_t* _a28_slotarr = ((vader_array_t*) l24);
                VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l25)
                l26 = vader_array_ref_load_obj(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l25);
                vader_array_push((vader_array_t*) l8, vader_ref_box(l26));
            } else {
                t0 = ((int64_t) (int32_t) l9);
                l27 = (size_t) (int64_t) t0;
                vader_array_t* _a29_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l27)
                l28 = vader_array_ref_load_obj(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l27);
                l12 = ((vader_struct_vader_bytecode_SlotRange_t*) l18)->f_first;
                l13 = ((vader_struct_vader_bytecode_SlotRange_t*) l28)->f_first;
                if ((l12 < l13)) {
                    l11 = ((vader_struct_vader_bytecode_SlotRange_t*) l18)->f_first;
                } else {
                    l11 = ((vader_struct_vader_bytecode_SlotRange_t*) l28)->f_first;
                }
                l29 = ((vader_struct_vader_bytecode_SlotRange_t*) l18)->f_last;
                l30 = ((vader_struct_vader_bytecode_SlotRange_t*) l28)->f_last;
                if ((l29 > l30)) {
                    l14 = ((vader_struct_vader_bytecode_SlotRange_t*) l18)->f_last;
                } else {
                    l14 = ((vader_struct_vader_bytecode_SlotRange_t*) l28)->f_last;
                }
                t0 = ((int64_t) (int32_t) l9);
                l31 = (size_t) (int64_t) t0;
                vader_struct_vader_bytecode_SlotRange_t* _a30_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                vader_obj_header_init(_a30_obj, 738u);
                _a30_obj->f_first = l11;
                _a30_obj->f_last = l14;
                l32 = (void*) _a30_obj;
                vader_array_t* _a31_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l31)
                vader_array_ref_store(_a31_slotarr->buf, _a31_slotarr->offset + (size_t) l31, l32);
                VADER_WRITE_BARRIER(_a31_slotarr->buf);
            }
            vader_array_t* _a32_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l7)
            ((int32_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) l7] = (int32_t) l9;
            t0 = vader_chk_add(usize, l7, INT64_C(1));
            l7 = (size_t) (int64_t) t0;
            continue;
        }
        vader_array_t* _a33_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l7)
        ((int32_t*) _a33_slotarr->buf->slots)[_a33_slotarr->offset + (size_t) l7] = (int32_t) INT32_C(-1);
        t0 = vader_chk_add(usize, l7, INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    l16 = true;
    while ((l1 < l2)) {
        vader_array_t* _a34_slotarr = ((vader_array_t*) l15);
        VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l1)
        l9 = ((int32_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l1];
        l11 = ((int32_t) (size_t) l1);
        if (l9 != l11) {
            l16 = false;
            break;
        }
        t0 = (l1 + INT64_C(1));
        l1 = (size_t) (int64_t) t0;
    }
    if (l16) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a35_arr = vader_array_new(215u, 0u, 13u, 1441u);
    l5 = (void*) _a35_arr;
    l1 = (size_t) 0;
    while ((l1 < l4)) {
        vader_array_t* _a36_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
        l33 = vader_array_ref_load_box(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l1);
        l9 = vader_bytecode_slot_touched(l33);
        if ((l9 >= INT32_C(0))) {
            t0 = ((int64_t) (int32_t) l9);
            l2 = (size_t) (int64_t) t0;
            vader_array_t* _a37_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l2)
            l11 = ((int32_t*) _a37_slotarr->buf->slots)[_a37_slotarr->offset + (size_t) l2];
            if ((l11 >= INT32_C(0))) {
                l34 = vader_bytecode_with_remapped_slot(l33, l11);
                vader_array_push((vader_array_t*) l5, l34);
            } else {
                vader_array_push((vader_array_t*) l5, l33);
            }
        } else {
            l35 = vader_bytecode_remap_push_cache_slot(l33, l15);
            vader_array_push((vader_array_t*) l5, l35);
        }
        t0 = (l1 + INT64_C(1));
        l1 = (size_t) (int64_t) t0;
    }
    l3 = l0;
    l36 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_name;
    l16 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_is_main;
    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature;
    l15 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_debug;
    l17 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_jump_table;
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_source_pc;
    vader_struct_vader_bytecode_BcFunction_t* _a38_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a38_obj, 610u);
    _a38_obj->f_name = l36;
    _a38_obj->f_is_main = l16;
    _a38_obj->f_signature = l6;
    _a38_obj->f_locals = l8;
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
    if (l0.tag == 698u) {
        t0 = vader_bytecode_is_64_bit_int_val(l1);
        return t0;
    }
    if (!(l0.tag == 678u)) {
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
    if (!((l0.tag == 629u || l0.tag == 644u || l0.tag == 659u || l0.tag == 678u || l0.tag == 698u || l0.tag == 729u || l0.tag == 747u))) {
        return vader_box_obj(0u, NULL);
    }
    return l0;
}

static uint8_t vader_bytecode_const_val_type(vader_box_t l0) {
    uint8_t l1;
    if (l0.tag == 678u) {
        l1 = (uint8_t) 2;
        return l1;
    }
    if (l0.tag == 698u) {
        l1 = (uint8_t) 3;
    } else if (l0.tag == 659u) {
        l1 = (uint8_t) 11;
    } else if (l0.tag == 629u) {
        l1 = (uint8_t) 12;
    } else if (l0.tag == 644u) {
        l1 = (uint8_t) 13;
    } else if (l0.tag == 747u) {
        l1 = (uint8_t) 14;
    } else {
        if (!(l0.tag == 729u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = (uint8_t) 15;
    }
    return l1;
}

static vader_string_t vader_bytecode_convert_target_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 1829u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1851u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1708u;
    } else {
        if (!(l0 == INT32_C(3))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1514u;
    }
    return l1;
}

vader_box_t vader_bytecode_convert_target_of(uint8_t l0) {
    vader_box_t l1;
    if (l0 == INT32_C(0)) {
        l1 = vader_box_i32(284u, INT32_C(0));
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = vader_box_i32(284u, INT32_C(0));
    } else if (l0 == INT32_C(2)) {
        l1 = vader_box_i32(284u, INT32_C(0));
    } else if (l0 == INT32_C(5)) {
        l1 = vader_box_i32(284u, INT32_C(0));
    } else if (l0 == INT32_C(6)) {
        l1 = vader_box_i32(284u, INT32_C(0));
    } else if (l0 == INT32_C(7)) {
        l1 = vader_box_i32(284u, INT32_C(0));
    } else if (l0 == INT32_C(3)) {
        l1 = vader_box_i32(284u, INT32_C(1));
    } else if (l0 == INT32_C(8)) {
        l1 = vader_box_i32(284u, INT32_C(1));
    } else if (l0 == INT32_C(4)) {
        l1 = vader_box_i32(284u, INT32_C(1));
    } else if (l0 == INT32_C(9)) {
        l1 = vader_box_i32(284u, INT32_C(1));
    } else if (l0 == INT32_C(10)) {
        l1 = vader_box_i32(284u, INT32_C(2));
    } else if (l0 == INT32_C(11)) {
        l1 = vader_box_i32(284u, INT32_C(2));
    } else if (l0 == INT32_C(13)) {
        l1 = vader_box_i32(284u, INT32_C(3));
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
    if (l0.tag == 614u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_BcPrimData_t*) t0)->f_mutable;
        return l1;
    }
    if (l0.tag == 618u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_BcStrData_t*) t0)->f_mutable;
    } else {
        if (!(l0.tag == 605u)) {
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
    vader_array_t* _a0_arr = vader_array_new(16u, 1u, 7u, 281u);
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
            if (l8.tag == 648u) {
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
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 0u, 278u);
    l0 = (void*) _a0_arr;
    vader_struct_vader_bytecode_EmitOptions_t* _a1_obj = (vader_struct_vader_bytecode_EmitOptions_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_EmitOptions_t));
    vader_obj_header_init(_a1_obj, 654u);
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
        vader_obj_header_init(_a0_obj, 762u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (!(t0)) {
        t2 = vader_bytecode_arith_op(l0, 1604u);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_U32Div_t* _a1_obj = (vader_struct_vader_bytecode_U32Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Div_t));
    vader_obj_header_init(_a1_obj, 756u);
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
    t0 = vader_chk_add(usize, l1, l2);
    l2 = (size_t) (int64_t) t0;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 281u);
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
        if (l7.tag == 723u) {
            t1 = l7.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalGet_t*) t1)->f_slot;
            t0 = ((int64_t) (int32_t) t2);
            l8 = (size_t) (int64_t) t0;
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
            t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l8];
            l9 = vader_chk_add(i32, t2, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
            ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l8] = (int32_t) l9;
        }
        if (l7.tag == 722u) {
            t1 = l7.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalField_t*) t1)->f_slot;
            t0 = ((int64_t) (int32_t) t2);
            l10 = (size_t) (int64_t) t0;
            vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
            t2 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l10];
            l11 = vader_chk_add(i32, t2, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l10)
            ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l10] = (int32_t) l11;
        }
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a5_arr = vader_array_new(13u, 0u, 12u, 276u);
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
    vader_array_t* _a9_arr = vader_array_new(16u, 0u, 7u, 281u);
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
            if (VADER_LIKELY(_pc155_len < _pc155_cap)) {
                ((int32_t*) _pc155_slots)[_pc155_len] = (int32_t) (INT32_C(-1));
                _pc155_len += 1;
            } else {
                _pc155_hdr->length = _pc155_len;
                if (_pc155_hdr->buf->length < _pc155_len) {
                    _pc155_hdr->buf->length = _pc155_len;
                }
                vader_array_push_i32((vader_array_t*) l3, INT32_C(-1));
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
        t3 = vader_box_bool(276u, ((uint8_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l4]);
        t4 = t3.payload.b;
        if (!(t4)) {
            vader_array_t* _a12_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l4)
            ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l4] = (int32_t) l9;
            l9 = vader_chk_add(i32, l9, INT32_C(1));
        }
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a13_arr = vader_array_new(215u, 0u, 13u, 1441u);
    l13 = (void*) _a13_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body)->length;
    vader_array_t* _a14_arr = vader_array_new(16u, 0u, 7u, 281u);
    t1 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l4);
    l14 = (void*) _a15_arr;
    l6 = (size_t) 0;
    vader_array_t* _pc212_hdr = (vader_array_t*) l14;
    size_t _pc212_len = _pc212_hdr->length;
    size_t _pc212_cap = (_pc212_hdr->offset == 0 && !vader_array_is_borrowed(_pc212_hdr) && _pc212_hdr->length >= _pc212_hdr->buf->length) ? _pc212_hdr->capacity : (size_t) 0;
    void* _pc212_slots = _pc212_hdr->buf->slots;
    for (;;) {
        if ((l6 < l4)) {
            if (VADER_LIKELY(_pc212_len < _pc212_cap)) {
                ((int32_t*) _pc212_slots)[_pc212_len] = (int32_t) (INT32_C(-1));
                _pc212_len += 1;
            } else {
                _pc212_hdr->length = _pc212_len;
                if (_pc212_hdr->buf->length < _pc212_len) {
                    _pc212_hdr->buf->length = _pc212_len;
                }
                vader_array_push_i32((vader_array_t*) l14, INT32_C(-1));
                _pc212_hdr = (vader_array_t*) l14;
                _pc212_len = _pc212_hdr->length;
                _pc212_cap = (_pc212_hdr->offset == 0 && !vader_array_is_borrowed(_pc212_hdr) && _pc212_hdr->length >= _pc212_hdr->buf->length) ? _pc212_hdr->capacity : (size_t) 0;
                _pc212_slots = _pc212_hdr->buf->slots;
            }
            t0 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t0;
            continue;
        }
        _pc212_hdr->length = _pc212_len;
        if (_pc212_hdr->buf->length < _pc212_len) {
            _pc212_hdr->buf->length = _pc212_len;
        }
        break;
    }
    l6 = (size_t) 0;
    while ((l6 < l4)) {
        vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l6)
        l7 = vader_array_ref_load_box(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l6);
        if (l7.tag == 724u) {
            t1 = l7.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalSet_t*) t1)->f_slot;
            t0 = ((int64_t) (int32_t) t2);
            l8 = (size_t) (int64_t) t0;
            vader_array_t* _a17_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l8)
            t3 = vader_box_bool(276u, ((uint8_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l8]);
            t4 = t3.payload.b;
            if (t4) {
                t5 = ((vader_array_t*) l13)->length;
                l9 = ((int32_t) (size_t) t5);
                vader_array_t* _a18_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l6)
                ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l6] = (int32_t) l9;
                vader_struct_vader_bytecode_Drop_t* _a19_obj = (vader_struct_vader_bytecode_Drop_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Drop_t));
                vader_obj_header_init(_a19_obj, 652u);
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
                vader_obj_header_init(_a22_obj, 724u);
                _a22_obj->f_slot = t2;
                l16 = (void*) _a22_obj;
                vader_array_push((vader_array_t*) l13, vader_ref_box(l16));
            }
            t0 = vader_chk_add(usize, l6, INT64_C(1));
            l6 = (size_t) (int64_t) t0;
            continue;
        }
        if (l7.tag == 725u) {
            t1 = l7.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalTee_t*) t1)->f_slot;
            t0 = ((int64_t) (int32_t) t2);
            l17 = (size_t) (int64_t) t0;
            vader_array_t* _a23_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l17)
            t3 = vader_box_bool(276u, ((uint8_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l17]);
            t4 = t3.payload.b;
            if (t4) {
                t0 = vader_chk_add(usize, l6, INT64_C(1));
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
            vader_obj_header_init(_a26_obj, 725u);
            _a26_obj->f_slot = t2;
            l20 = (void*) _a26_obj;
            vader_array_push((vader_array_t*) l13, vader_ref_box(l20));
            t0 = vader_chk_add(usize, l6, INT64_C(1));
            l6 = (size_t) (int64_t) t0;
            continue;
        }
        if (l7.tag == 723u) {
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
            vader_obj_header_init(_a29_obj, 723u);
            _a29_obj->f_slot = t2;
            l23 = (void*) _a29_obj;
            vader_array_push((vader_array_t*) l13, vader_ref_box(l23));
            t0 = vader_chk_add(usize, l6, INT64_C(1));
            l6 = (size_t) (int64_t) t0;
            continue;
        }
        if (l7.tag == 722u) {
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
            vader_obj_header_init(_a32_obj, 722u);
            _a32_obj->f_slot = l26;
            _a32_obj->f_type_id = l27;
            _a32_obj->f_field_index = l28;
            l29 = (void*) _a32_obj;
            vader_array_push((vader_array_t*) l13, vader_ref_box(l29));
            t0 = vader_chk_add(usize, l6, INT64_C(1));
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
        t0 = vader_chk_add(usize, l6, INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l4 = ((vader_array_t*) l13)->length;
    l3 = vader_bytecode_remap_jump_table(l3, l14, l4);
    l15 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug;
    l4 = ((vader_array_t*) l13)->length;
    l14 = vader_bytecode_remap_debug(l15, l14, l4);
    vader_array_t* _a34_arr = vader_array_new(50u, 0u, 13u, 612u);
    l15 = (void*) _a34_arr;
    l4 = l1;
    while ((l4 < l2)) {
        vader_array_t* _a35_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l4)
        t3 = vader_box_bool(276u, ((uint8_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l4]);
        t4 = t3.payload.b;
        if (!(t4)) {
            l16 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
            t0 = vader_chk_sub(usize, l4, l1);
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
    vader_obj_header_init(_a37_obj, 610u);
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
    int32_t l6;
    bool l9;
    vader_box_t l12 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    bool t3;
    size_t t4;
    vader_box_t* gc_roots[2] = { &l12, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l4, &l8, &l11, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l2 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l3 = ((vader_array_t*) l1)->length;
    vader_array_t* _a0_arr = vader_array_new(13u, 1u, 12u, 276u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    l4 = (void*) _a0_arr;
    t0 = vader_chk_add(usize, l3, INT64_C(1));
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
        t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        if ((t1.tag == 634u || t1.tag == 635u)) {
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
    vader_array_t* _a5_arr = vader_array_new(13u, 1u, 12u, 276u);
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
        t1 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l5);
        if (t1.tag == 627u) {
            if ((l6 > INT32_C(0))) {
                t0 = ((int64_t) (int32_t) l6);
                l7 = (size_t) (int64_t) t0;
                vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l7)
                t1 = vader_box_bool(276u, ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l7]);
                t3 = t1.payload.b;
                if (!(t3)) {
                    vader_array_t* _a10_slotarr = ((vader_array_t*) l8);
                    VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l5)
                    ((uint8_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l5] = (uint8_t) true;
                    t0 = vader_chk_sub(usize, ((int64_t) (int32_t) l6), INT64_C(1));
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
    vader_array_t* _a11_arr = vader_array_new(215u, 0u, 13u, 1441u);
    l4 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(16u, 0u, 7u, 281u);
    l11 = (void*) _a12_arr;
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l5)
        t1 = vader_box_bool(276u, ((uint8_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l5]);
        t3 = t1.payload.b;
        if (t3) {
            vader_array_push_i32((vader_array_t*) l11, INT32_C(-1));
        } else {
            t4 = ((vader_array_t*) l4)->length;
            l6 = ((int32_t) (size_t) t4);
            vader_array_push_i32((vader_array_t*) l11, l6);
            vader_array_t* _a14_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            l12 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l5);
            vader_array_push((vader_array_t*) l4, l12);
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
    vader_obj_header_init(_a15_obj, 613u);
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
        t0 = vader_box_bool(276u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5]);
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
                            vader_obj_header_init(_a3_obj, 738u);
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
                            vader_obj_header_init(_a4_obj, 738u);
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
    vader_array_t* _a0_arr = vader_array_new(54u, 0u, 13u, 738u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 278u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 281u);
    l3 = (void*) _a2_arr;
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) l0)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        if (l7.tag == 627u) {
            l8 = ((int32_t) (size_t) l6);
            vader_bytecode_push_scope(l2, l3, l4, 1399u, l8);
            t0 = vader_chk_add(usize, l4, INT64_C(1));
            l4 = (size_t) (int64_t) t0;
        } else if (l7.tag == 726u) {
            l9 = ((int32_t) (size_t) l6);
            vader_bytecode_push_scope(l2, l3, l4, 2036u, l9);
            t0 = vader_chk_add(usize, l4, INT64_C(1));
            l4 = (size_t) (int64_t) t0;
        } else if (l7.tag == 713u) {
            l10 = ((int32_t) (size_t) l6);
            vader_bytecode_push_scope(l2, l3, l4, 1878u, l10);
            t0 = vader_chk_add(usize, l4, INT64_C(1));
            l4 = (size_t) (int64_t) t0;
        } else if (l7.tag == 656u) {
            if ((l4 > INT64_C(0))) {
                t0 = vader_chk_sub(usize, l4, INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                t1 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l4];
                t2 = t1.payload.s;
                if (t2 == 2036u) {
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                    l11 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4];
                    l12 = ((int32_t) (size_t) l6);
                    vader_struct_vader_bytecode_SlotRange_t* _a6_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                    vader_obj_header_init(_a6_obj, 738u);
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
    int32_t t2, t3;
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
        t2 = vader_chk_sub(i32, INT32_C(15), l6);
        t3 = vader_chk_mul(i32, t2, INT32_C(4));
        t1 = ((int64_t) (int32_t) t3);
        l4 = (uint64_t) (int64_t) t1;
        t1 = ((l1 >> l4) & INT64_C(15));
        l7 = (uint64_t) (int64_t) t1;
        t1 = ((int64_t) (uint64_t) l7);
        l2 = (size_t) (int64_t) t1;
        t1 = vader_chk_add(usize, ((int64_t) (uint64_t) l7), INT64_C(1));
        l3 = (size_t) (int64_t) t1;
        l8 = vader_string_slice_codepoints(369u, l2, l3);
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
    t0 = vader_chk_add(usize, l1, INT64_C(1));
    if ((t0 >= l2)) {
        return false;
    }
    t0 = vader_chk_add(usize, l1, INT64_C(1));
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t1 = vader_box_bool(276u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4]);
    t2 = t1.payload.b;
    if (t2) {
        return false;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
    if (t1.tag == 723u) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l1);
        l5 = t1.payload.obj;
        t0 = vader_chk_add(usize, l1, INT64_C(1));
        l4 = (size_t) (int64_t) t0;
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        if (l6.tag == 725u) {
            t3 = l6.payload.obj;
            l7 = ((vader_struct_vader_bytecode_LocalTee_t*) t3)->f_slot;
            l8 = ((vader_struct_vader_bytecode_LocalGet_t*) l5)->f_slot;
            return l7 == l8;
        }
        if (l6.tag == 724u) {
            t3 = l6.payload.obj;
            l7 = ((vader_struct_vader_bytecode_LocalSet_t*) t3)->f_slot;
            l8 = ((vader_struct_vader_bytecode_LocalGet_t*) l5)->f_slot;
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
    size_t t0;
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
    l3 = concat_3(200u, l3, 433u);
    l4 = std_collections_MutableMap_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l3);
    if (!(l4.tag == 281u)) {
        t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
        l5 = ((int32_t) (size_t) t0);
        vader_struct_vader_bytecode_BcField_t* _a0_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
        vader_obj_header_init(_a0_obj, 608u);
        _a0_obj->f_name = 2706u;
        _a0_obj->f_type_index = l2;
        l6 = (void*) _a0_obj;
        vader_array_t* _a1_arr = vader_array_new(47u, 0u, 13u, 608u);
        l7 = (void*) _a1_arr;
        vader_array_push((vader_array_t*) l7, vader_ref_box(l6));
        l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
        l8 = vader_bytecode_type_intern_key(l0);
        t1 = concat_2(201u, l8);
        vader_struct_vader_bytecode_BcStruct_t* _a2_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
        vader_obj_header_init(_a2_obj, 619u);
        _a2_obj->f_name = t1;
        _a2_obj->f_fields = l7;
        _a2_obj->f_c_name = 0u;
        _a2_obj->f_symbol_id = INT32_C(-1);
        l7 = (void*) _a2_obj;
        vader_array_push((vader_array_t*) l6, vader_ref_box(l7));
        std_collections_MutableMap_IndexSet_set_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l3, l5);
        { int32_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((int32_t) l4.payload.i);
    { int32_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
    if (!(l2.tag == 281u)) {
        t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_strings)->length;
        l3 = ((int32_t) (size_t) t0);
        vader_array_push((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_strings, vader_box_string(278u, l0));
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
    if (l3.tag == 281u) {
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
    if (l3.tag == 281u) {
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
        t4 = concat_3(1453u, l8, 907u);
        vader_host_std_abort_panic(t4);
        vader_unreachable("a no-return call returned");
    } else {
        t5 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
        l9 = ((int32_t) (size_t) t5);
        vader_struct_vader_bytecode_BcRef_t* _a1_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a1_obj, 616u);
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
        { vader_gc_top = gc_frame.prev; return (uint8_t) 9; }
    }
    t0 = vader_bytecode_is_display_to_string(l0);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 10; }
    }
    if (l0 == 2703u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 21; }
    }
    if (l0 == 2704u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 22; }
    }
    if (l0 == 2702u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 23; }
    }
    if (l0 == 2327u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 1; }
    }
    if (l0 == 2326u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 2; }
    }
    if (l0 == 2328u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 3; }
    }
    if (l0 == 2329u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 4; }
    }
    if (l0 == 2330u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 5; }
    }
    l1 = vader_bytecode_primitive_member_mangle(2364u, 554u, 1380u);
    if (l0 == l1) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 6; }
    }
    l1 = vader_bytecode_primitive_member_mangle(2364u, 533u, 1820u);
    if (l0 == l1) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 7; }
    }
    if (l0 == 2334u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 8; }
    }
    if (l0 == 2341u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 11; }
    }
    if (l0 == 2342u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 12; }
    }
    if (l0 == 2340u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 13; }
    }
    if (l0 == 2339u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 14; }
    }
    if (l0 == 2344u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 15; }
    }
    if (l0 == 2343u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 16; }
    }
    if (l0 == 2345u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 17; }
    }
    if (l0 == 2347u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 19; }
    }
    if (l0 == 2346u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 20; }
    }
    if (!(l0 == 2319u)) {
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
        l2 = l0 == INT32_C(6);
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
            if (l0 == INT32_C(4)) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(5);
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
    if (l0 == 2333u) {
        vader_struct_vader_bytecode_StringCompare_t* _a0_obj = (vader_struct_vader_bytecode_StringCompare_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringCompare_t));
        vader_obj_header_init(_a0_obj, 746u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2337u) {
        vader_struct_vader_bytecode_BufferNew_t* _a1_obj = (vader_struct_vader_bytecode_BufferNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BufferNew_t));
        vader_obj_header_init(_a1_obj, 636u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2322u) {
        vader_struct_vader_bytecode_LoadU8_t* _a2_obj = (vader_struct_vader_bytecode_LoadU8_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LoadU8_t));
        vader_obj_header_init(_a2_obj, 721u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2324u) {
        vader_struct_vader_bytecode_StoreU8_t* _a3_obj = (vader_struct_vader_bytecode_StoreU8_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StoreU8_t));
        vader_obj_header_init(_a3_obj, 745u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2323u) {
        vader_struct_vader_bytecode_MemoryCopy_t* _a4_obj = (vader_struct_vader_bytecode_MemoryCopy_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_MemoryCopy_t));
        vader_obj_header_init(_a4_obj, 728u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2321u) {
        vader_struct_vader_bytecode_BufferToString_t* _a5_obj = (vader_struct_vader_bytecode_BufferToString_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BufferToString_t));
        vader_obj_header_init(_a5_obj, 637u);
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2325u) {
        vader_struct_vader_bytecode_BufferWriteString_t* _a6_obj = (vader_struct_vader_bytecode_BufferWriteString_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BufferWriteString_t));
        vader_obj_header_init(_a6_obj, 638u);
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2332u) {
        vader_struct_vader_bytecode_F64ToBits_t* _a7_obj = (vader_struct_vader_bytecode_F64ToBits_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64ToBits_t));
        vader_obj_header_init(_a7_obj, 670u);
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2336u) {
        vader_struct_vader_bytecode_BitsToF64_t* _a8_obj = (vader_struct_vader_bytecode_BitsToF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BitsToF64_t));
        vader_obj_header_init(_a8_obj, 626u);
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2331u) {
        vader_struct_vader_bytecode_F32ToBits_t* _a9_obj = (vader_struct_vader_bytecode_F32ToBits_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F32ToBits_t));
        vader_obj_header_init(_a9_obj, 657u);
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0 == 2335u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_struct_vader_bytecode_BitsToF32_t* _a10_obj = (vader_struct_vader_bytecode_BitsToF32_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BitsToF32_t));
    vader_obj_header_init(_a10_obj, 625u);
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
    l1 = vader_bytecode_strip_core_member(l0, 202u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_types_is_primitive_name(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        l2 = t0 != 2723u;
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        { bool __vret = t0 != 2146u; vader_gc_top = gc_frame.prev; return __vret; }
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
    l1 = vader_bytecode_strip_core_member(l0, 204u);
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
    if (l0.tag == 619u) {
        l2 = true;
        return l2;
    }
    if (l0.tag == 606u) {
        l2 = true;
    } else if (l0.tag == 609u) {
        l2 = true;
    } else if (l0.tag == 615u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val == INT32_C(15);
    } else if (l0.tag == 616u) {
        l2 = false;
    } else {
        if (!(l0.tag == 620u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_BcUnion_t*) t0)->f_variants;
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
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

bool vader_bytecode_is_u64_class(uint8_t l0) {
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
    l1 = vader_bytecode_strip_core_member(l0, 202u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        if (t0 == 2512u) {
            l2 = true;
        } else {
            t0 = l1.payload.s;
            l2 = t0 == 2522u;
        }
        if (l2) {
            l2 = true;
        } else {
            t0 = l1.payload.s;
            l2 = t0 == 2577u;
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
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 0u, 278u);
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
        l7 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
        l8 = vader_bytecode_bc_type_key(l0, l7);
        vader_array_push((vader_array_t*) l3, vader_box_string(278u, l8));
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
    vader_array_t* _a0_arr = vader_array_new(13u, 1u, 12u, 276u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    l3 = (size_t) 0;
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
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
        vader_obj_header_init(_a0_obj, 767u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Mod_t* _a1_obj = (vader_struct_vader_bytecode_U32Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Mod_t));
        vader_obj_header_init(_a1_obj, 761u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Mod_t* _a2_obj = (vader_struct_vader_bytecode_I32Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Mod_t));
        vader_obj_header_init(_a2_obj, 685u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Mod_t* _a3_obj = (vader_struct_vader_bytecode_I64Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Mod_t));
    vader_obj_header_init(_a3_obj, 705u);
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
        vader_obj_header_init(_a0_obj, 668u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_bytecode_I32Neg_t* _a1_obj = (vader_struct_vader_bytecode_I32Neg_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Neg_t));
        vader_obj_header_init(_a1_obj, 688u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Neg_t* _a2_obj = (vader_struct_vader_bytecode_I64Neg_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Neg_t));
    vader_obj_header_init(_a2_obj, 708u);
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
    if (l4.tag == 619u) {
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
    vader_array_t* _a0_arr = vader_array_new(217u, 0u, 13u, 1464u);
    l0 = (void*) _a0_arr;
    vader_struct_vader_bytecode_BcPrimitive_t* _a1_obj = (vader_struct_vader_bytecode_BcPrimitive_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPrimitive_t));
    vader_obj_header_init(_a1_obj, 615u);
    _a1_obj->f_val = (uint8_t) 15;
    l1 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l0, vader_ref_box(l1));
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 0u, 278u);
    l1 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(16u, 0u, 7u, 281u);
    l2 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(16u, 0u, 7u, 281u);
    l3 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a5_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a5_obj, 437u);
    _a5_obj->f_ekeys = l1;
    _a5_obj->f_evals = l2;
    _a5_obj->f_index = l3;
    _a5_obj->f_mask = (size_t) 0;
    _a5_obj->f_size = (size_t) 0;
    _a5_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a5_obj;
    std_collections_MutableMap_IndexSet_set_at__string__i32(l1, 2146u, INT32_C(0));
    vader_array_t* _a6_arr = vader_array_new(21u, 0u, 4u, 287u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(16u, 0u, 7u, 281u);
    l3 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(16u, 0u, 7u, 281u);
    l4 = (void*) _a8_arr;
    vader_struct_std_collections_MutableMap__u64__i32_t* _a9_obj = (vader_struct_std_collections_MutableMap__u64__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__u64__i32_t));
    vader_obj_header_init(_a9_obj, 460u);
    _a9_obj->f_ekeys = l2;
    _a9_obj->f_evals = l3;
    _a9_obj->f_index = l4;
    _a9_obj->f_mask = (size_t) 0;
    _a9_obj->f_size = (size_t) 0;
    _a9_obj->f_tombs = (size_t) 0;
    l2 = (void*) _a9_obj;
    t0 = (void*) &vader_data_16;
    vader_array_t* _a10_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
    t0 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) INT64_C(0));
    l5 = vader_bytecode_type_intern_hash(vader_ref_box(t0));
    std_collections_MutableMap_IndexSet_set_at__u64__i32(l2, l5, INT32_C(0));
    t0 = (void*) &vader_data_16;
    vader_array_t* _a11_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
    t0 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) INT64_C(0));
    vader_array_t* _a12_arr = vader_array_new(235u, 1u, 13u, 1691u);
    ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = t0;
    l3 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(15u, 0u, 0u, 278u);
    l4 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(15u, 0u, 0u, 278u);
    l6 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(16u, 0u, 7u, 281u);
    l7 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(16u, 0u, 7u, 281u);
    l8 = (void*) _a16_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a17_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a17_obj, 437u);
    _a17_obj->f_ekeys = l6;
    _a17_obj->f_evals = l7;
    _a17_obj->f_index = l8;
    _a17_obj->f_mask = (size_t) 0;
    _a17_obj->f_size = (size_t) 0;
    _a17_obj->f_tombs = (size_t) 0;
    l6 = (void*) _a17_obj;
    vader_array_t* _a18_arr = vader_array_new(48u, 0u, 13u, 610u);
    l7 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(16u, 0u, 7u, 281u);
    l8 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(16u, 0u, 7u, 281u);
    l9 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(16u, 0u, 7u, 281u);
    l10 = (void*) _a21_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a22_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a22_obj, 377u);
    _a22_obj->f_ekeys = l8;
    _a22_obj->f_evals = l9;
    _a22_obj->f_index = l10;
    _a22_obj->f_mask = (size_t) 0;
    _a22_obj->f_size = (size_t) 0;
    _a22_obj->f_tombs = (size_t) 0;
    l8 = (void*) _a22_obj;
    vader_array_t* _a23_arr = vader_array_new(15u, 0u, 0u, 278u);
    l9 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(16u, 0u, 7u, 281u);
    l10 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(16u, 0u, 7u, 281u);
    l11 = (void*) _a25_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a26_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a26_obj, 437u);
    _a26_obj->f_ekeys = l9;
    _a26_obj->f_evals = l10;
    _a26_obj->f_index = l11;
    _a26_obj->f_mask = (size_t) 0;
    _a26_obj->f_size = (size_t) 0;
    _a26_obj->f_tombs = (size_t) 0;
    l9 = (void*) _a26_obj;
    vader_array_t* _a27_arr = vader_array_new(49u, 0u, 13u, 611u);
    l10 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(16u, 0u, 7u, 281u);
    l11 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_new(16u, 0u, 7u, 281u);
    l12 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(16u, 0u, 7u, 281u);
    l13 = (void*) _a30_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a31_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a31_obj, 377u);
    _a31_obj->f_ekeys = l11;
    _a31_obj->f_evals = l12;
    _a31_obj->f_index = l13;
    _a31_obj->f_mask = (size_t) 0;
    _a31_obj->f_size = (size_t) 0;
    _a31_obj->f_tombs = (size_t) 0;
    l11 = (void*) _a31_obj;
    vader_array_t* _a32_arr = vader_array_new(15u, 0u, 0u, 278u);
    l12 = (void*) _a32_arr;
    vader_array_t* _a33_arr = vader_array_new(16u, 0u, 7u, 281u);
    l13 = (void*) _a33_arr;
    vader_array_t* _a34_arr = vader_array_new(16u, 0u, 7u, 281u);
    l14 = (void*) _a34_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a35_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a35_obj, 437u);
    _a35_obj->f_ekeys = l12;
    _a35_obj->f_evals = l13;
    _a35_obj->f_index = l14;
    _a35_obj->f_mask = (size_t) 0;
    _a35_obj->f_size = (size_t) 0;
    _a35_obj->f_tombs = (size_t) 0;
    l12 = (void*) _a35_obj;
    vader_array_t* _a36_arr = vader_array_new(46u, 0u, 13u, 607u);
    l13 = (void*) _a36_arr;
    vader_array_t* _a37_arr = vader_array_new(16u, 0u, 7u, 281u);
    l14 = (void*) _a37_arr;
    vader_array_t* _a38_arr = vader_array_new(16u, 0u, 7u, 281u);
    l15 = (void*) _a38_arr;
    vader_array_t* _a39_arr = vader_array_new(23u, 0u, 0u, 289u);
    l16 = (void*) _a39_arr;
    vader_array_t* _a40_arr = vader_array_new(16u, 0u, 7u, 281u);
    l17 = (void*) _a40_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a41_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a41_obj, 344u);
    _a41_obj->f_ekeys = l15;
    _a41_obj->f_evals = l16;
    _a41_obj->f_index = l17;
    _a41_obj->f_mask = (size_t) 0;
    _a41_obj->f_size = (size_t) 0;
    _a41_obj->f_tombs = (size_t) 0;
    l15 = (void*) _a41_obj;
    vader_struct_vader_bytecode_EmitterCtx_t* _a42_obj = (vader_struct_vader_bytecode_EmitterCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_EmitterCtx_t));
    vader_obj_header_init(_a42_obj, 655u);
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
    if (l0 == 1873u) {
        return vader_box_i32(284u, INT32_C(0));
    }
    if (l0 == 1828u) {
        return vader_box_i32(284u, INT32_C(1));
    }
    if (l0 == 1829u) {
        return vader_box_i32(284u, INT32_C(2));
    }
    if (l0 == 1851u) {
        return vader_box_i32(284u, INT32_C(3));
    }
    if (l0 == 1959u) {
        return vader_box_i32(284u, INT32_C(4));
    }
    if (l0 == 2532u) {
        return vader_box_i32(284u, INT32_C(5));
    }
    if (l0 == 2511u) {
        return vader_box_i32(284u, INT32_C(6));
    }
    if (l0 == 2512u) {
        return vader_box_i32(284u, INT32_C(7));
    }
    if (l0 == 2522u) {
        return vader_box_i32(284u, INT32_C(8));
    }
    if (l0 == 2577u) {
        return vader_box_i32(284u, INT32_C(9));
    }
    if (l0 == 1706u) {
        return vader_box_i32(284u, INT32_C(10));
    }
    if (l0 == 1708u) {
        return vader_box_i32(284u, INT32_C(11));
    }
    if (l0 == 1400u) {
        return vader_box_i32(284u, INT32_C(12));
    }
    if (l0 == 1514u) {
        return vader_box_i32(284u, INT32_C(13));
    }
    if (l0 == 2364u) {
        return vader_box_i32(284u, INT32_C(14));
    }
    if (l0 == 2146u) {
        return vader_box_i32(284u, INT32_C(15));
    }
    if (l0 == 2723u) {
        return vader_box_i32(284u, INT32_C(16));
    }
    if (l0 == 2198u) {
        return vader_box_i32(284u, INT32_C(17));
    }
    if (l0 == 2225u) {
        return vader_box_i32(284u, INT32_C(18));
    }
    if (!(l0 == 1329u)) {
        return vader_box_obj(0u, NULL);
    }
    return vader_box_i32(284u, INT32_C(19));
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
    l1 = vader_bytecode_strip_core_member(l0, 198u);
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
    l1 = vader_bytecode_strip_core_member(l0, 207u);
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
    l1 = vader_bytecode_strip_core_member(l0, 206u);
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
    l1 = vader_bytecode_strip_core_member(l0, 203u);
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
    l1 = vader_bytecode_strip_core_member(l0, 204u);
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
    t0 = concat_6(2320u, l0, 197u, l1, 197u, l2);
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
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l8 = std_core_new_byte_buffer((size_t) 21);
        l9 = (size_t) 0;
        l9 = std_core_write_string_at(l8, l9, 10u);
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
    size_t l1, l2, l8, l10, l12, l15, l17;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    vader_box_t l11 = vader_box_null(), l25 = vader_box_null(), l27 = vader_box_null(), l28 = vader_box_null(), l29 = vader_box_null();
    int32_t l13, l14, l16, l18, l19;
    bool l24;
    uint8_t l26;
    vader_string_t l30 = 0;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    bool t3;
    vader_box_t t4 = vader_box_null();
    size_t t5;
    vader_box_t* gc_roots[6] = { &l11, &l25, &l27, &l28, &l29, &t4 };
    void** gc_raw_roots[12] = { &l0, &l3, &l4, &l5, &l6, &l7, &l9, &l20, &l21, &l22, &l23, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l30 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    t0 = vader_chk_add(usize, l1, l2);
    l2 = (size_t) (int64_t) t0;
    if ((l2 <= l1)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 281u);
    t1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 281u);
    t1 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(16u, 0u, 7u, 281u);
    t1 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l5 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(16u, 0u, 7u, 281u);
    t1 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l6 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(16u, 0u, 7u, 281u);
    t1 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l2);
    l7 = (void*) _a9_arr;
    l8 = (size_t) 0;
    while ((l8 < l2)) {
        vader_array_push_i32((vader_array_t*) l3, INT32_C(0));
        vader_array_push_i32((vader_array_t*) l4, INT32_C(0));
        vader_array_push_i32((vader_array_t*) l5, INT32_C(0));
        vader_array_push_i32((vader_array_t*) l6, INT32_C(-1));
        vader_array_push_i32((vader_array_t*) l7, INT32_C(-1));
        t0 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t0;
    }
    l9 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l8 = ((vader_array_t*) l9)->length;
    l10 = (size_t) 0;
    while ((l10 < l8)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l11 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l10);
        if (l11.tag == 724u) {
            t1 = l11.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalSet_t*) t1)->f_slot;
            t0 = ((int64_t) (int32_t) t2);
            l12 = (size_t) (int64_t) t0;
            vader_array_t* _a11_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l12)
            t2 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l12];
            l13 = vader_chk_add(i32, t2, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l12)
            ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l12] = (int32_t) l13;
            l14 = ((int32_t) (size_t) l10);
            vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l12)
            ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l12] = (int32_t) l14;
        }
        if (l11.tag == 725u) {
            t1 = l11.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalTee_t*) t1)->f_slot;
            t0 = ((int64_t) (int32_t) t2);
            l15 = (size_t) (int64_t) t0;
            vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l15)
            t2 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l15];
            l16 = vader_chk_add(i32, t2, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l15)
            ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l15] = (int32_t) l16;
        }
        if (l11.tag == 723u) {
            t1 = l11.payload.obj;
            t2 = ((vader_struct_vader_bytecode_LocalGet_t*) t1)->f_slot;
            t0 = ((int64_t) (int32_t) t2);
            l17 = (size_t) (int64_t) t0;
            vader_array_t* _a14_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l17)
            t2 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l17];
            l18 = vader_chk_add(i32, t2, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l17)
            ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l17] = (int32_t) l18;
            l19 = ((int32_t) (size_t) l10);
            vader_array_t* _a15_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l17)
            ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l17] = (int32_t) l19;
        }
        t0 = (l10 + INT64_C(1));
        l10 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a16_arr = vader_array_new(16u, 0u, 7u, 281u);
    l20 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(13u, 0u, 12u, 276u);
    l21 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(16u, 0u, 7u, 281u);
    l22 = (void*) _a18_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a19_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a19_obj, 376u);
    _a19_obj->f_ekeys = l20;
    _a19_obj->f_evals = l21;
    _a19_obj->f_index = l22;
    _a19_obj->f_mask = (size_t) 0;
    _a19_obj->f_size = (size_t) 0;
    _a19_obj->f_tombs = (size_t) 0;
    l20 = (void*) _a19_obj;
    vader_array_t* _a20_arr = vader_array_new(16u, 0u, 7u, 281u);
    l21 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(23u, 0u, 0u, 289u);
    l22 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_new(16u, 0u, 7u, 281u);
    l23 = (void*) _a22_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a23_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a23_obj, 342u);
    _a23_obj->f_ekeys = l21;
    _a23_obj->f_evals = l22;
    _a23_obj->f_index = l23;
    _a23_obj->f_mask = (size_t) 0;
    _a23_obj->f_size = (size_t) 0;
    _a23_obj->f_tombs = (size_t) 0;
    l21 = (void*) _a23_obj;
    l10 = l1;
    while ((l10 < l2)) {
        l24 = true;
        vader_array_t* _a24_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l10)
        t2 = ((int32_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l10];
        if (t2 != INT32_C(0)) {
            l24 = false;
        }
        vader_array_t* _a25_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l10)
        t2 = ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l10];
        if (t2 != INT32_C(1)) {
            l24 = false;
        }
        vader_array_t* _a26_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l10)
        t2 = ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l10];
        if (t2 != INT32_C(1)) {
            l24 = false;
        }
        l13 = INT32_C(-1);
        l14 = INT32_C(-1);
        if (l24) {
            vader_array_t* _a27_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l10)
            l13 = ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l10];
            vader_array_t* _a28_slotarr = ((vader_array_t*) l7);
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
            t2 = vader_chk_sub(i32, l13, INT32_C(1));
            t0 = ((int64_t) (int32_t) t2);
            l12 = (size_t) (int64_t) t0;
            vader_array_t* _a29_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l12)
            l11 = vader_array_ref_load_box(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l12);
            l25 = vader_bytecode_const_op_of(l11);
            if (l25.tag == 0u) {
                l24 = false;
            } else {
                l22 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
                t0 = vader_chk_sub(usize, l10, l1);
                l15 = (size_t) (int64_t) t0;
                vader_array_t* _a30_slotarr = ((vader_array_t*) l22);
                VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l15)
                t1 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l15);
                l26 = ((vader_struct_vader_bytecode_BcLocal_t*) t1)->f_val;
                t3 = vader_bytecode_const_fills_slot(l25, l26);
                if (t3) {
                    l16 = vader_chk_sub(i32, l13, INT32_C(1));
                    std_collections_MutableMap_IndexSet_set_at__i32__bool(l20, l16, true);
                    std_collections_MutableMap_IndexSet_set_at__i32__bool(l20, l13, true);
                    std_collections_MutableMap_IndexSet_set_at__i32__Any(l21, l14, l11);
                } else {
                    l24 = false;
                }
            }
        }
        t0 = (l10 + INT64_C(1));
        l10 = (size_t) (int64_t) t0;
    }
    t3 = std_collections_is_empty__i32__bool(l20);
    if (t3) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a31_arr = vader_array_new(215u, 0u, 13u, 1441u);
    l3 = (void*) _a31_arr;
    vader_array_t* _a32_arr = vader_array_new(219u, 0u, 13u, 1496u);
    l4 = (void*) _a32_arr;
    vader_array_t* _a33_arr = vader_array_new(16u, 0u, 7u, 281u);
    t1 = (void*) _a33_arr;
    vader_array_t* _a34_arr = vader_array_repeat((vader_array_t*) t1, (size_t) l8);
    l5 = (void*) _a34_arr;
    l1 = (size_t) 0;
    vader_array_t* _pc332_hdr = (vader_array_t*) l5;
    size_t _pc332_len = _pc332_hdr->length;
    size_t _pc332_cap = (_pc332_hdr->offset == 0 && !vader_array_is_borrowed(_pc332_hdr) && _pc332_hdr->length >= _pc332_hdr->buf->length) ? _pc332_hdr->capacity : (size_t) 0;
    void* _pc332_slots = _pc332_hdr->buf->slots;
    for (;;) {
        if ((l1 < l8)) {
            if (VADER_LIKELY(_pc332_len < _pc332_cap)) {
                ((int32_t*) _pc332_slots)[_pc332_len] = (int32_t) (INT32_C(-1));
                _pc332_len += 1;
            } else {
                _pc332_hdr->length = _pc332_len;
                if (_pc332_hdr->buf->length < _pc332_len) {
                    _pc332_hdr->buf->length = _pc332_len;
                }
                vader_array_push_i32((vader_array_t*) l5, INT32_C(-1));
                _pc332_hdr = (vader_array_t*) l5;
                _pc332_len = _pc332_hdr->length;
                _pc332_cap = (_pc332_hdr->offset == 0 && !vader_array_is_borrowed(_pc332_hdr) && _pc332_hdr->length >= _pc332_hdr->buf->length) ? _pc332_hdr->capacity : (size_t) 0;
                _pc332_slots = _pc332_hdr->buf->slots;
            }
            t0 = (l1 + INT64_C(1));
            l1 = (size_t) (int64_t) t0;
            continue;
        }
        _pc332_hdr->length = _pc332_len;
        if (_pc332_hdr->buf->length < _pc332_len) {
            _pc332_hdr->buf->length = _pc332_len;
        }
        break;
    }
    l1 = (size_t) 0;
    while ((l1 < l8)) {
        l13 = ((int32_t) (size_t) l1);
        t4 = std_collections_MutableMap_Index_at__i32__bool(l20, l13);
        if (t4.tag == 276u) {
            t0 = vader_chk_add(usize, l1, INT64_C(1));
            l1 = (size_t) (int64_t) t0;
            continue;
        }
        l14 = ((int32_t) (size_t) l1);
        l11 = std_collections_MutableMap_Index_at__i32__Any(l21, l14);
        if (l11.tag == 0u) {
            t5 = ((vader_array_t*) l3)->length;
            l16 = ((int32_t) (size_t) t5);
            vader_array_t* _a35_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l1)
            ((int32_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l1] = (int32_t) l16;
            vader_array_t* _a36_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
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
            l28 = l11;
            vader_array_push((vader_array_t*) l3, l28);
            vader_array_t* _a39_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug);
            VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l1)
            l29 = vader_array_ref_load_box(_a39_slotarr->buf, _a39_slotarr->offset + (size_t) l1);
            vader_array_push((vader_array_t*) l4, l29);
        }
        t0 = vader_chk_add(usize, l1, INT64_C(1));
        l1 = (size_t) (int64_t) t0;
    }
    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l1 = ((vader_array_t*) l3)->length;
    l5 = vader_bytecode_remap_jump_table(l6, l5, l1);
    l6 = l0;
    l30 = ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_name;
    l24 = ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_is_main;
    l7 = ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_signature;
    l9 = ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_locals;
    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_source_pc;
    vader_struct_vader_bytecode_BcFunction_t* _a40_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a40_obj, 610u);
    _a40_obj->f_name = l30;
    _a40_obj->f_is_main = l24;
    _a40_obj->f_signature = l7;
    _a40_obj->f_locals = l9;
    _a40_obj->f_body = l3;
    _a40_obj->f_debug = l4;
    _a40_obj->f_jump_table = l5;
    _a40_obj->f_source_pc = l6;
    t1 = (void*) _a40_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_prune_unused_data(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    size_t l5, l6, l7, l8, l15;
    vader_box_t l9 = vader_box_null();
    int32_t l10, l11;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    size_t t3;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l12, &l13, &l14, &l16, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 281u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(13u, 0u, 12u, 276u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 281u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 376u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 484u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        l4 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_body;
        l7 = ((vader_array_t*) l4)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            l9 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l8);
            if (l9.tag == 648u) {
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_pool_index;
                std_collections_add__i32(l2, l10);
            }
            t1 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t1;
        }
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    l5 = std_collections_len__i32(l2);
    l6 = ((vader_array_t*) l1)->length;
    if (l5 == l6) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a7_arr = vader_array_new(16u, 0u, 7u, 281u);
    l3 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(216u, 0u, 13u, 1463u);
    l4 = (void*) _a8_arr;
    l5 = (size_t) 0;
    l6 = ((vader_array_t*) l1)->length;
    while ((l5 < l6)) {
        l10 = ((int32_t) (size_t) l5);
        t2 = std_collections_MutableSet_Contains_contains__i32(l2, l10);
        if (t2) {
            t3 = ((vader_array_t*) l4)->length;
            l11 = ((int32_t) (size_t) t3);
            vader_array_push_i32((vader_array_t*) l3, l11);
            vader_array_t* _a9_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            l9 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l5);
            vader_array_push((vader_array_t*) l4, l9);
        } else {
            vader_array_push_i32((vader_array_t*) l3, INT32_C(-1));
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l5 = ((vader_array_t*) l2)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l12 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l6);
        l7 = (size_t) 0;
        l8 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l12)->f_body)->length;
        while ((l7 < l8)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l12)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l7)
            l9 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l7);
            if (l9.tag == 648u) {
                l13 = ((vader_struct_vader_bytecode_BcFunction_t*) l12)->f_body;
                l14 = l9.payload.obj;
                t0 = l9.payload.obj;
                t4 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_pool_index;
                t1 = ((int64_t) (int32_t) t4);
                l15 = (size_t) (int64_t) t1;
                vader_array_t* _a12_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l15)
                l10 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l15];
                l11 = ((vader_struct_vader_bytecode_DataConst_t*) l14)->f_type_id;
                vader_struct_vader_bytecode_DataConst_t* _a13_obj = (vader_struct_vader_bytecode_DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DataConst_t));
                vader_obj_header_init(_a13_obj, 648u);
                _a13_obj->f_pool_index = l10;
                _a13_obj->f_type_id = l11;
                l16 = (void*) _a13_obj;
                vader_array_t* _a14_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l7)
                vader_array_ref_store(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l7, l16);
                VADER_WRITE_BARRIER(_a14_slotarr->buf);
            }
            t1 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t1;
        }
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 281u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(13u, 0u, 12u, 276u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 281u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 376u);
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
    vader_array_t* _a7_arr = vader_array_new(16u, 0u, 7u, 281u);
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
            t3 = vader_box_bool(276u, ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l11]);
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
            t1 = vader_chk_sub(usize, t4, INT64_C(1));
            l7 = (size_t) (int64_t) t1;
            vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            l8 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l7];
            vader_array_t* _a11_arr = vader_array_new(16u, 0u, 7u, 281u);
            l6 = (void*) _a11_arr;
            l11 = (size_t) 0;
            t4 = ((vader_array_t*) l5)->length;
            t1 = vader_chk_sub(usize, t4, INT64_C(1));
            l14 = (size_t) (int64_t) t1;
            vader_array_t* _pc191_hdr = (vader_array_t*) l6;
            size_t _pc191_len = _pc191_hdr->length;
            size_t _pc191_cap = (_pc191_hdr->offset == 0 && !vader_array_is_borrowed(_pc191_hdr) && _pc191_hdr->length >= _pc191_hdr->buf->length) ? _pc191_hdr->capacity : (size_t) 0;
            void* _pc191_slots = _pc191_hdr->buf->slots;
            for (;;) {
                if ((l11 < l14)) {
                    vader_array_t* _a12_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
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
                l18 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l17);
                l19 = INT32_C(-1);
                if (l18.tag == 641u) {
                    t2 = l18.payload.obj;
                    l19 = ((vader_struct_vader_bytecode_Call_t*) t2)->f_function_index;
                }
                if (l18.tag == 672u) {
                    t2 = l18.payload.obj;
                    l19 = ((vader_struct_vader_bytecode_FnRef_t*) t2)->f_function_index;
                }
                if (l18.tag == 671u) {
                    t2 = l18.payload.obj;
                    l19 = ((vader_struct_vader_bytecode_FnAddr_t*) t2)->f_function_index;
                }
                if (l18.tag == 727u) {
                    t2 = l18.payload.obj;
                    l19 = ((vader_struct_vader_bytecode_MakeClosure_t*) t2)->f_function_index;
                }
                if ((l19 < INT32_C(0))) {
                    t1 = (l17 + INT64_C(1));
                    l17 = (size_t) (int64_t) t1;
                    continue;
                }
                t3 = std_collections_MutableMap_Index_at__i32__bool(l4, l19);
                if (t3.tag == 276u) {
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
    vader_array_t* _a15_arr = vader_array_new(15u, 0u, 0u, 278u);
    l5 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(16u, 0u, 7u, 281u);
    l6 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(16u, 0u, 7u, 281u);
    l12 = (void*) _a17_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a18_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a18_obj, 437u);
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
            l22 = t3.tag == 276u;
        }
        if (l22) {
            vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l7)
            t2 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l7);
            l9 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_name;
            if (l9 != 0u) {
                l18 = std_collections_MutableMap_Index_at__string__i32(l5, l9);
                if (l18.tag == 281u) {
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
    vader_array_t* _a22_arr = vader_array_new(16u, 0u, 7u, 281u);
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
            if (l18.tag == 281u) {
                l8 = ((int32_t) l18.payload.i);
            }
        }
        vader_array_push_i32((vader_array_t*) l6, l8);
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a25_arr = vader_array_new(16u, 0u, 7u, 281u);
    l5 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(16u, 0u, 7u, 281u);
    l12 = (void*) _a26_arr;
    vader_array_t* _a27_arr = vader_array_new(16u, 0u, 7u, 281u);
    l13 = (void*) _a27_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a28_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a28_obj, 377u);
    _a28_obj->f_ekeys = l5;
    _a28_obj->f_evals = l12;
    _a28_obj->f_index = l13;
    _a28_obj->f_mask = (size_t) 0;
    _a28_obj->f_size = (size_t) 0;
    _a28_obj->f_tombs = (size_t) 0;
    l5 = (void*) _a28_obj;
    vader_array_t* _a29_arr = vader_array_new(48u, 0u, 13u, 610u);
    l12 = (void*) _a29_arr;
    l7 = (size_t) 0;
    while ((l7 < l3)) {
        {
            if (!(l20)) {
                l8 = ((int32_t) (size_t) l7);
                t3 = std_collections_MutableMap_Index_at__i32__bool(l4, l8);
                if (!(t3.tag == 276u)) {
                    goto end_509;
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
        } end_509: ;
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a32_arr = vader_array_new(16u, 0u, 7u, 281u);
    t2 = (void*) _a32_arr;
    vader_array_t* _a33_arr = vader_array_repeat((vader_array_t*) t2, (size_t) l3);
    l13 = (void*) _a33_arr;
    l7 = (size_t) 0;
    vader_array_t* _pc569_hdr = (vader_array_t*) l13;
    size_t _pc569_len = _pc569_hdr->length;
    size_t _pc569_cap = (_pc569_hdr->offset == 0 && !vader_array_is_borrowed(_pc569_hdr) && _pc569_hdr->length >= _pc569_hdr->buf->length) ? _pc569_hdr->capacity : (size_t) 0;
    void* _pc569_slots = _pc569_hdr->buf->slots;
    for (;;) {
        if ((l7 < l3)) {
            l8 = INT32_C(-1);
            if (l20) {
                l21 = true;
            } else {
                l10 = ((int32_t) (size_t) l7);
                t3 = std_collections_MutableMap_Index_at__i32__bool(l4, l10);
                l21 = t3.tag == 276u;
            }
            if (l21) {
                vader_array_t* _a34_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l7)
                l19 = ((int32_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l7];
                l18 = std_collections_MutableMap_Index_at__i32__i32(l5, l19);
                if (l18.tag == 281u) {
                    l8 = ((int32_t) l18.payload.i);
                }
            }
            if (VADER_LIKELY(_pc569_len < _pc569_cap)) {
                ((int32_t*) _pc569_slots)[_pc569_len] = (int32_t) (l8);
                _pc569_len += 1;
            } else {
                _pc569_hdr->length = _pc569_len;
                if (_pc569_hdr->buf->length < _pc569_len) {
                    _pc569_hdr->buf->length = _pc569_len;
                }
                vader_array_push_i32((vader_array_t*) l13, l8);
                _pc569_hdr = (vader_array_t*) l13;
                _pc569_len = _pc569_hdr->length;
                _pc569_cap = (_pc569_hdr->offset == 0 && !vader_array_is_borrowed(_pc569_hdr) && _pc569_hdr->length >= _pc569_hdr->buf->length) ? _pc569_hdr->capacity : (size_t) 0;
                _pc569_slots = _pc569_hdr->buf->slots;
            }
            t1 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t1;
            continue;
        }
        _pc569_hdr->length = _pc569_len;
        if (_pc569_hdr->buf->length < _pc569_len) {
            _pc569_hdr->buf->length = _pc569_len;
        }
        break;
    }
    l4 = l12;
    l3 = ((vader_array_t*) l4)->length;
    l7 = (size_t) 0;
    while ((l7 < l3)) {
        vader_array_t* _a35_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
        l5 = vader_array_ref_load_obj(_a35_slotarr->buf, _a35_slotarr->offset + (size_t) l7);
        l11 = (size_t) 0;
        l14 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body)->length;
        while ((l11 < l14)) {
            vader_array_t* _a36_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l11)
            l18 = vader_array_ref_load_box(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l11);
            if (l18.tag == 641u) {
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
                vader_obj_header_init(_a38_obj, 641u);
                _a38_obj->f_function_index = t5;
                l25 = (void*) _a38_obj;
                vader_array_t* _a39_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l11)
                vader_array_ref_store(_a39_slotarr->buf, _a39_slotarr->offset + (size_t) l11, l25);
                VADER_WRITE_BARRIER(_a39_slotarr->buf);
            }
            if (l18.tag == 672u) {
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
                vader_obj_header_init(_a41_obj, 672u);
                _a41_obj->f_function_index = l8;
                _a41_obj->f_type_id = l10;
                l27 = (void*) _a41_obj;
                vader_array_t* _a42_slotarr = ((vader_array_t*) l26);
                VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l11)
                vader_array_ref_store(_a42_slotarr->buf, _a42_slotarr->offset + (size_t) l11, l27);
                VADER_WRITE_BARRIER(_a42_slotarr->buf);
            }
            if (l18.tag == 671u) {
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
                vader_obj_header_init(_a44_obj, 671u);
                _a44_obj->f_function_index = t5;
                l29 = (void*) _a44_obj;
                vader_array_t* _a45_slotarr = ((vader_array_t*) l28);
                VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l11)
                vader_array_ref_store(_a45_slotarr->buf, _a45_slotarr->offset + (size_t) l11, l29);
                VADER_WRITE_BARRIER(_a45_slotarr->buf);
            }
            if (l18.tag == 727u) {
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
                vader_obj_header_init(_a47_obj, 727u);
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
    vader_array_t* _a49_arr = vader_array_new(46u, 0u, 13u, 607u);
    l4 = (void*) _a49_arr;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_exports;
    l3 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    while ((l7 < l3)) {
        vader_array_t* _a50_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a50_slotarr)
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
            vader_obj_header_init(_a52_obj, 607u);
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
    vader_array_t* _a53_arr = vader_array_new(16u, 0u, 7u, 281u);
    l4 = (void*) _a53_arr;
    vader_array_t* _a54_arr = vader_array_new(16u, 0u, 7u, 281u);
    l5 = (void*) _a54_arr;
    vader_array_t* _a55_arr = vader_array_new(16u, 0u, 7u, 281u);
    l6 = (void*) _a55_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a56_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a56_obj, 377u);
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
    vader_array_t* _a60_arr = vader_array_new(15u, 0u, 0u, 278u);
    l4 = (void*) _a60_arr;
    vader_array_t* _a61_arr = vader_array_new(16u, 0u, 7u, 281u);
    l5 = (void*) _a61_arr;
    vader_array_t* _a62_arr = vader_array_new(16u, 0u, 7u, 281u);
    l6 = (void*) _a62_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a63_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a63_obj, 437u);
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
    vader_array_t* _a67_arr = vader_array_new(16u, 0u, 7u, 281u);
    l4 = (void*) _a67_arr;
    vader_array_t* _a68_arr = vader_array_new(23u, 0u, 0u, 289u);
    l5 = (void*) _a68_arr;
    vader_array_t* _a69_arr = vader_array_new(16u, 0u, 7u, 281u);
    l6 = (void*) _a69_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a70_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a70_obj, 344u);
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
        if (l18.tag == 16u) {
            l27 = l18.payload.obj;
            l28 = l26;
            l16 = ((vader_array_t*) l28)->length;
            l17 = (size_t) 0;
            while ((l17 < l16)) {
                vader_array_t* _a74_slotarr = ((vader_array_t*) l28);
                VADER_ARRAY_RESOLVE_BUF(_a74_slotarr)
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
    void* l12 = NULL;
    void* l14 = NULL;
    size_t l4, l5, l6, l7, l13;
    vader_box_t l8 = vader_box_null();
    int32_t l9, l10;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    size_t t3;
    int32_t t4;
    vader_box_t* gc_roots[2] = { &l8, &t2 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l11, &l12, &l14, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 281u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(13u, 0u, 12u, 276u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 281u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 376u);
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
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
        l3 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_body;
        l6 = ((vader_array_t*) l3)->length;
        l7 = (size_t) 0;
        while ((l7 < l6)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l8 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
            if (l8.tag == 642u) {
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
    vader_array_t* _a6_arr = vader_array_new(16u, 0u, 7u, 281u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(49u, 0u, 13u, 611u);
    l3 = (void*) _a7_arr;
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports)->length;
    while ((l4 < l5)) {
        l9 = ((int32_t) (size_t) l4);
        t2 = std_collections_MutableMap_Index_at__i32__bool(l1, l9);
        if (t2.tag == 276u) {
            t3 = ((vader_array_t*) l3)->length;
            l10 = ((int32_t) (size_t) t3);
            vader_array_push_i32((vader_array_t*) l2, l10);
            vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l4)
            l11 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l4);
            vader_array_push((vader_array_t*) l3, vader_ref_box(l11));
        } else {
            vader_array_push_i32((vader_array_t*) l2, INT32_C(-1));
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
        l11 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l5);
        l6 = (size_t) 0;
        l7 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l11)->f_body)->length;
        while ((l6 < l7)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l11)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l6)
            l8 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l6);
            if (l8.tag == 642u) {
                l12 = ((vader_struct_vader_bytecode_BcFunction_t*) l11)->f_body;
                t0 = l8.payload.obj;
                t4 = ((vader_struct_vader_bytecode_CallImport_t*) t0)->f_index;
                t1 = ((int64_t) (int32_t) t4);
                l13 = (size_t) (int64_t) t1;
                vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l13)
                t4 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l13];
                vader_struct_vader_bytecode_CallImport_t* _a12_obj = (vader_struct_vader_bytecode_CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallImport_t));
                vader_obj_header_init(_a12_obj, 642u);
                _a12_obj->f_index = t4;
                l14 = (void*) _a12_obj;
                vader_array_t* _a13_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l6)
                vader_array_ref_store(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l6, l14);
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
    int32_t l11, l15, l20;
    vader_box_t l16 = vader_box_null(), l17 = vader_box_null();
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l22 = 0;
    vader_string_t l23 = 0;
    bool l21;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    int32_t t3;
    bool t4;
    size_t t5;
    vader_box_t* gc_roots[3] = { &l16, &l17, &t2 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l6, &l7, &l8, &l12, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l18, &l19, &l22, &l23 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 281u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(13u, 0u, 12u, 276u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 281u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 376u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 484u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    std_collections_add__i32(l1, INT32_C(0));
    vader_array_t* _a5_arr = vader_array_new(16u, 0u, 7u, 281u);
    l2 = (void*) _a5_arr;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_signature)->f_result_types;
        vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l7);
        l8 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_signature)->f_param_types;
        l9 = ((vader_array_t*) l8)->length;
        l10 = (size_t) 0;
        while ((l10 < l9)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
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
        l6 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_result_types;
        vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l7);
        l8 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_param_types;
        l9 = ((vader_array_t*) l8)->length;
        l10 = (size_t) 0;
        while ((l10 < l9)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
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
    vader_array_t* _a16_arr = vader_array_new(16u, 0u, 7u, 281u);
    l2 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(217u, 0u, 13u, 1464u);
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
            vader_array_push_i32((vader_array_t*) l2, INT32_C(-1));
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l1 = l3;
    vader_struct___lambda_env_vader_bytecode_1_t* _a19_obj = (vader_struct___lambda_env_vader_bytecode_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_bytecode_1_t));
    vader_obj_header_init(_a19_obj, 294u);
    _a19_obj->f_cap_0 = l2;
    l3 = (void*) _a19_obj;
    vader_array_t* _a20_arr = vader_array_new(217u, 0u, 13u, 1464u);
    l6 = (void*) _a20_arr;
    l4 = ((vader_array_t*) l1)->length;
    vader_array_t* _a21_arr = vader_array_repeat((vader_array_t*) l6, (size_t) l4);
    l6 = (void*) _a21_arr;
    l4 = ((vader_array_t*) l1)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a22_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
        l16 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l5);
        l17 = __lambda_vader_bytecode_0(l3, l16);
        vader_array_push((vader_array_t*) l6, l17);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    vader_array_t* _a23_arr = vader_array_new(15u, 0u, 0u, 278u);
    l1 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(16u, 0u, 7u, 281u);
    l3 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(16u, 0u, 7u, 281u);
    l6 = (void*) _a25_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a26_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a26_obj, 437u);
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
        l18 = t2.payload.s;
        vader_array_t* _a28_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l5)
        l11 = ((int32_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l5];
        l19 = l18;
        l15 = l11;
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
        l20 = vader_bytecode_remap_idx(l2, l15);
        if (!((l20 >= INT32_C(0)))) {
            continue;
        }
        std_collections_MutableMap_IndexSet_set_at__string__i32(l1, l19, l20);
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_key = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    l1 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l1)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a29_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
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
    vader_array_t* _a32_arr = vader_array_new(49u, 0u, 13u, 611u);
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
        l6 = vader_array_ref_load_obj(_a34_slotarr->buf, _a34_slotarr->offset + (size_t) l5);
        l7 = l6;
        l18 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_extern_name;
        l19 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_mangled_name;
        l8 = vader_bytecode_remap_signature(((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature, l2);
        l21 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_is_extern;
        l22 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_c_header;
        l23 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_c_library;
        l11 = ((vader_struct_vader_bytecode_BcImport_t*) l7)->f_c_variadic_fixed;
        vader_struct_vader_bytecode_BcImport_t* _a35_obj = (vader_struct_vader_bytecode_BcImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcImport_t));
        vader_obj_header_init(_a35_obj, 611u);
        _a35_obj->f_extern_name = l18;
        _a35_obj->f_mangled_name = l19;
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
        vader_array_push((vader_array_t*) l0, vader_box_string(278u, l3));
        vader_array_push_i32((vader_array_t*) l1, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l2] = vader_box_string(278u, l3);
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
    bool l5;
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l6, &l7, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_by_slot)->length;
    t0 = ((int64_t) (int32_t) l1);
    l4 = (size_t) (int64_t) t0;
    l5 = (l3 <= l4);
    while (l5) {
        l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_by_slot;
        t1 = (void*) &vader_data_16;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        vader_array_push((vader_array_t*) l6, vader_ref_box(l7));
        l5 = (l3 < l4);
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
    }
    l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_by_slot;
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
    vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l2.payload.obj);
    VADER_WRITE_BARRIER(_a1_slotarr->buf);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_bytecode_refer(uint8_t l0, int32_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_bytecode_OperandRef_t* _a0_obj = (vader_struct_vader_bytecode_OperandRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_OperandRef_t));
    vader_obj_header_init(_a0_obj, 730u);
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
    vader_obj_header_init(_a0_obj, 730u);
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
    vader_array_t* _a0_arr = vader_array_new(219u, 1u, 13u, 1496u);
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
    return INT32_C(-1);
}

void* vader_bytecode_remap_jump_table(void* l0, void* l1, size_t l2) {
    void* l3 = NULL;
    size_t l4, l5, l7, l8, l11, l12, l14;
    int32_t l6, l9, l10, l13;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 281u);
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
            if (VADER_LIKELY(_pc6_len < _pc6_cap)) {
                ((int32_t*) _pc6_slots)[_pc6_len] = (int32_t) (INT32_C(-1));
                _pc6_len += 1;
            } else {
                _pc6_hdr->length = _pc6_len;
                if (_pc6_hdr->buf->length < _pc6_len) {
                    _pc6_hdr->buf->length = _pc6_len;
                }
                vader_array_push_i32((vader_array_t*) l3, INT32_C(-1));
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
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l5];
        if ((l6 < INT32_C(0))) {
            t1 = vader_chk_add(usize, l5, INT64_C(1));
            l5 = (size_t) (int64_t) t1;
            continue;
        }
        t1 = ((int64_t) (int32_t) l6);
        l7 = (size_t) (int64_t) t1;
        l8 = ((vader_array_t*) l1)->length;
        if ((l7 >= l8)) {
            t1 = vader_chk_add(usize, l5, INT64_C(1));
            l5 = (size_t) (int64_t) t1;
            continue;
        }
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        l9 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
        if ((l9 < INT32_C(0))) {
            t1 = vader_chk_add(usize, l5, INT64_C(1));
            l5 = (size_t) (int64_t) t1;
            continue;
        }
        l10 = INT32_C(-1);
        t1 = ((int64_t) (int32_t) l6);
        l11 = (size_t) (int64_t) t1;
        l12 = ((vader_array_t*) l1)->length;
        while ((l11 < l12)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
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
        t1 = vader_chk_add(usize, l5, INT64_C(1));
        l5 = (size_t) (int64_t) t1;
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
    if (!(l0.tag == 599u)) {
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
        vader_obj_header_init(_a1_obj, 599u);
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
    vader_obj_header_init(_a0_obj, 617u);
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
    if ((l0.tag == 615u || l0.tag == 616u)) {
        l2 = l0;
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 619u) {
        vader_array_t* _a0_arr = vader_array_new(47u, 0u, 13u, 608u);
        l3 = (void*) _a0_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields;
        l5 = ((vader_array_t*) l4)->length;
        l6 = (size_t) 0;
        while ((l6 < l5)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
            l8 = ((vader_struct_vader_bytecode_BcField_t*) l7)->f_name;
            l9 = ((vader_struct_vader_bytecode_BcField_t*) l7)->f_type_index;
            l10 = vader_bytecode_remap_idx(l1, l9);
            vader_struct_vader_bytecode_BcField_t* _a2_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
            vader_obj_header_init(_a2_obj, 608u);
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
        vader_obj_header_init(_a3_obj, 619u);
        _a3_obj->f_name = l8;
        _a3_obj->f_fields = l3;
        _a3_obj->f_c_name = l12;
        _a3_obj->f_symbol_id = l9;
        t0 = (void*) _a3_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 606u) {
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_bytecode_BcArray_t*) t0)->f_element;
        t2 = vader_bytecode_remap_idx(l1, l9);
        vader_struct_vader_bytecode_BcArray_t* _a4_obj = (vader_struct_vader_bytecode_BcArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcArray_t));
        vader_obj_header_init(_a4_obj, 606u);
        _a4_obj->f_element = t2;
        t0 = (void*) _a4_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 620u) {
        vader_array_t* _a5_arr = vader_array_new(16u, 0u, 7u, 281u);
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
        vader_obj_header_init(_a7_obj, 620u);
        _a7_obj->f_variants = l3;
        t0 = (void*) _a7_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!(l0.tag == 609u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_array_t* _a8_arr = vader_array_new(16u, 0u, 7u, 281u);
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
        vader_obj_header_init(_a10_obj, 609u);
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
    if (l0.tag == 752u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l5 = ((vader_struct_vader_bytecode_StructNew_t*) l3)->f_stack;
        vader_struct_vader_bytecode_StructNew_t* _a0_obj = (vader_struct_vader_bytecode_StructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructNew_t));
        vader_obj_header_init(_a0_obj, 752u);
        _a0_obj->f_type_id = l4;
        _a0_obj->f_stack = l5;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 751u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l6 = ((vader_struct_vader_bytecode_StructGet_t*) l3)->f_field_index;
        vader_struct_vader_bytecode_StructGet_t* _a1_obj = (vader_struct_vader_bytecode_StructGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructGet_t));
        vader_obj_header_init(_a1_obj, 751u);
        _a1_obj->f_type_id = l4;
        _a1_obj->f_field_index = l6;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 753u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l6 = ((vader_struct_vader_bytecode_StructSet_t*) l3)->f_field_index;
        l5 = ((vader_struct_vader_bytecode_StructSet_t*) l3)->f_stack;
        vader_struct_vader_bytecode_StructSet_t* _a2_obj = (vader_struct_vader_bytecode_StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructSet_t));
        vader_obj_header_init(_a2_obj, 753u);
        _a2_obj->f_type_id = l4;
        _a2_obj->f_field_index = l6;
        _a2_obj->f_stack = l5;
        t0 = (void*) _a2_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 598u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l6 = ((vader_struct_vader_bytecode_ArrayNew_t*) l3)->f_length;
        vader_struct_vader_bytecode_ArrayNew_t* _a3_obj = (vader_struct_vader_bytecode_ArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayNew_t));
        vader_obj_header_init(_a3_obj, 598u);
        _a3_obj->f_type_id = l4;
        _a3_obj->f_length = l6;
        t0 = (void*) _a3_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 596u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_ArrayGet_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l5 = ((vader_struct_vader_bytecode_ArrayGet_t*) l3)->f_bounds_safe;
        vader_struct_vader_bytecode_ArrayGet_t* _a4_obj = (vader_struct_vader_bytecode_ArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayGet_t));
        vader_obj_header_init(_a4_obj, 596u);
        _a4_obj->f_type_id = l4;
        _a4_obj->f_bounds_safe = l5;
        t0 = (void*) _a4_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 603u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_ArraySet_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l5 = ((vader_struct_vader_bytecode_ArraySet_t*) l3)->f_bounds_safe;
        vader_struct_vader_bytecode_ArraySet_t* _a5_obj = (vader_struct_vader_bytecode_ArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArraySet_t));
        vader_obj_header_init(_a5_obj, 603u);
        _a5_obj->f_type_id = l4;
        _a5_obj->f_bounds_safe = l5;
        t0 = (void*) _a5_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 599u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        l6 = ((vader_struct_vader_bytecode_ArrayPush_t*) l3)->f_cache_slot;
        vader_struct_vader_bytecode_ArrayPush_t* _a6_obj = (vader_struct_vader_bytecode_ArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayPush_t));
        vader_obj_header_init(_a6_obj, 599u);
        _a6_obj->f_type_id = l4;
        _a6_obj->f_cache_slot = l6;
        t0 = (void*) _a6_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 754u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_TypeCheck_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_TypeCheck_t* _a7_obj = (vader_struct_vader_bytecode_TypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_TypeCheck_t));
        vader_obj_header_init(_a7_obj, 754u);
        _a7_obj->f_type_id = t1;
        t0 = (void*) _a7_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 755u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_TypeConst_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_TypeConst_t* _a8_obj = (vader_struct_vader_bytecode_TypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_TypeConst_t));
        vader_obj_header_init(_a8_obj, 755u);
        _a8_obj->f_type_id = t1;
        t0 = (void*) _a8_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 643u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_CallIndirect_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_CallIndirect_t* _a9_obj = (vader_struct_vader_bytecode_CallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallIndirect_t));
        vader_obj_header_init(_a9_obj, 643u);
        _a9_obj->f_type_id = t1;
        t0 = (void*) _a9_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 727u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_function_index;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_env_type_id;
        l6 = vader_bytecode_remap_idx(l1, l6);
        vader_struct_vader_bytecode_MakeClosure_t* _a10_obj = (vader_struct_vader_bytecode_MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_MakeClosure_t));
        vader_obj_header_init(_a10_obj, 727u);
        _a10_obj->f_function_index = l4;
        _a10_obj->f_env_type_id = l6;
        t0 = (void*) _a10_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 672u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_function_index;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_type_id;
        l6 = vader_bytecode_remap_idx(l1, l6);
        vader_struct_vader_bytecode_FnRef_t* _a11_obj = (vader_struct_vader_bytecode_FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnRef_t));
        vader_obj_header_init(_a11_obj, 672u);
        _a11_obj->f_function_index = l4;
        _a11_obj->f_type_id = l6;
        t0 = (void*) _a11_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 722u) {
        l3 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_LocalField_t*) l3)->f_slot;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_type_id;
        l6 = vader_bytecode_remap_idx(l1, l6);
        l7 = ((vader_struct_vader_bytecode_LocalField_t*) l3)->f_field_index;
        vader_struct_vader_bytecode_LocalField_t* _a12_obj = (vader_struct_vader_bytecode_LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalField_t));
        vader_obj_header_init(_a12_obj, 722u);
        _a12_obj->f_slot = l4;
        _a12_obj->f_type_id = l6;
        _a12_obj->f_field_index = l7;
        t0 = (void*) _a12_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 604u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_ArraySlice_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_ArraySlice_t* _a13_obj = (vader_struct_vader_bytecode_ArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArraySlice_t));
        vader_obj_header_init(_a13_obj, 604u);
        _a13_obj->f_type_id = t1;
        t0 = (void*) _a13_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 731u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_RefCast_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_RefCast_t* _a14_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
        vader_obj_header_init(_a14_obj, 731u);
        _a14_obj->f_type_id = t1;
        t0 = (void*) _a14_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 734u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_Retag_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_Retag_t* _a15_obj = (vader_struct_vader_bytecode_Retag_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Retag_t));
        vader_obj_header_init(_a15_obj, 734u);
        _a15_obj->f_type_id = t1;
        t0 = (void*) _a15_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 648u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_pool_index;
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_type_id;
        l6 = vader_bytecode_remap_idx(l1, l6);
        vader_struct_vader_bytecode_DataConst_t* _a16_obj = (vader_struct_vader_bytecode_DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DataConst_t));
        vader_obj_header_init(_a16_obj, 648u);
        _a16_obj->f_pool_index = l4;
        _a16_obj->f_type_id = l6;
        t0 = (void*) _a16_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!((l0.tag == 594u || l0.tag == 595u || l0.tag == 597u || l0.tag == 600u || l0.tag == 601u || l0.tag == 602u || l0.tag == 625u || l0.tag == 626u || l0.tag == 627u || l0.tag == 628u || l0.tag == 629u || l0.tag == 630u || l0.tag == 631u || l0.tag == 632u || l0.tag == 633u || l0.tag == 634u || l0.tag == 635u || l0.tag == 636u || l0.tag == 637u || l0.tag == 638u || l0.tag == 641u || l0.tag == 642u || l0.tag == 644u || l0.tag == 645u || l0.tag == 646u || l0.tag == 647u || l0.tag == 650u || l0.tag == 651u || l0.tag == 652u || l0.tag == 653u || l0.tag == 656u || l0.tag == 657u || l0.tag == 658u || l0.tag == 659u || l0.tag == 660u || l0.tag == 661u || l0.tag == 662u || l0.tag == 663u || l0.tag == 664u || l0.tag == 665u || l0.tag == 666u || l0.tag == 667u || l0.tag == 668u || l0.tag == 669u || l0.tag == 670u || l0.tag == 671u || l0.tag == 673u || l0.tag == 674u || l0.tag == 675u || l0.tag == 676u || l0.tag == 677u || l0.tag == 678u || l0.tag == 679u || l0.tag == 680u || l0.tag == 681u || l0.tag == 682u || l0.tag == 683u || l0.tag == 684u || l0.tag == 685u || l0.tag == 686u || l0.tag == 687u || l0.tag == 688u || l0.tag == 689u || l0.tag == 690u || l0.tag == 691u || l0.tag == 692u || l0.tag == 693u || l0.tag == 694u || l0.tag == 695u || l0.tag == 696u || l0.tag == 697u || l0.tag == 698u || l0.tag == 699u || l0.tag == 700u || l0.tag == 701u || l0.tag == 702u || l0.tag == 703u || l0.tag == 704u || l0.tag == 705u || l0.tag == 706u || l0.tag == 707u || l0.tag == 708u || l0.tag == 709u || l0.tag == 710u || l0.tag == 711u || l0.tag == 712u || l0.tag == 713u || l0.tag == 715u || l0.tag == 716u || l0.tag == 717u || l0.tag == 718u || l0.tag == 719u || l0.tag == 720u || l0.tag == 721u || l0.tag == 723u || l0.tag == 724u || l0.tag == 725u || l0.tag == 726u || l0.tag == 728u || l0.tag == 729u || l0.tag == 732u || l0.tag == 733u || l0.tag == 735u || l0.tag == 736u || l0.tag == 737u || l0.tag == 739u || l0.tag == 740u || l0.tag == 741u || l0.tag == 742u || l0.tag == 743u || l0.tag == 744u || l0.tag == 745u || l0.tag == 746u || l0.tag == 747u || l0.tag == 748u || l0.tag == 749u || l0.tag == 750u || l0.tag == 756u || l0.tag == 757u || l0.tag == 758u || l0.tag == 759u || l0.tag == 760u || l0.tag == 761u || l0.tag == 762u || l0.tag == 763u || l0.tag == 764u || l0.tag == 765u || l0.tag == 766u || l0.tag == 767u || l0.tag == 768u || l0.tag == 769u))) {
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
    vader_obj_header_init(_a0_obj, 295u);
    _a0_obj->f_cap_0 = l0;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 7u, 281u);
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
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null(), l10 = vader_box_null();
    int32_t l9, l11;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l7, &l8, &l10 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l2 = ((vader_array_t*) l1)->length;
    vader_array_t* _a0_arr = vader_array_new(215u, 0u, 13u, 1441u);
    l3 = (void*) _a0_arr;
    l4 = (size_t) 0;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 7u, 281u);
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
            if (VADER_LIKELY(_pc14_len < _pc14_cap)) {
                ((int32_t*) _pc14_slots)[_pc14_len] = (int32_t) (INT32_C(-1));
                _pc14_len += 1;
            } else {
                _pc14_hdr->length = _pc14_len;
                if (_pc14_hdr->buf->length < _pc14_len) {
                    _pc14_hdr->buf->length = _pc14_len;
                }
                vader_array_push_i32((vader_array_t*) l5, INT32_C(-1));
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
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        l8 = vader_bytecode_try_fold_arith(l7, l3, l4);
        if (l8.tag == 0u) {
            vader_bytecode_push_or_assign(l3, l4, l7);
            l9 = ((int32_t) (size_t) l4);
            vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
            ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l6] = (int32_t) l9;
            t1 = vader_chk_add(usize, l4, INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        } else {
            t1 = vader_chk_sub(usize, l4, INT64_C(2));
            l4 = (size_t) (int64_t) t1;
            l10 = l8;
            vader_bytecode_push_or_assign(l3, l4, l10);
            l11 = ((int32_t) (size_t) l4);
            vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
            ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l6] = (int32_t) l11;
            t1 = vader_chk_add(usize, l4, INT64_C(1));
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
    vader_obj_header_init(_a7_obj, 613u);
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
    void* l37 = NULL;
    size_t l3, l4, l5, l11, l13, l15, l25, l27, l29, l30, l32, l35;
    vader_box_t l10 = vader_box_null(), l19 = vader_box_null(), l31 = vader_box_null(), l36 = vader_box_null();
    int32_t l12, l14, l16, l28, l34, l38, l39;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    int32_t t3;
    vader_box_t t4 = vader_box_null(), t5 = vader_box_null();
    bool t6;
    vader_box_t* gc_roots[6] = { &l10, &l19, &l31, &l36, &t4, &t5 };
    void** gc_raw_roots[12] = { &l0, &l2, &l6, &l7, &l8, &l9, &l17, &l18, &l26, &l33, &l37, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 12u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_bc_result_arity(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature);
    l1 = (t0 > INT64_C(1));
    l2 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l3 = ((vader_array_t*) l2)->length;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    t1 = vader_chk_add(usize, l4, l5);
    l4 = (size_t) (int64_t) t1;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 281u);
    t2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t2, (size_t) l4);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 281u);
    t2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t2, (size_t) l4);
    l7 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(16u, 0u, 7u, 281u);
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
        if (l10.tag == 724u) {
            t2 = l10.payload.obj;
            t3 = ((vader_struct_vader_bytecode_LocalSet_t*) t2)->f_slot;
            t1 = ((int64_t) (int32_t) t3);
            l11 = (size_t) (int64_t) t1;
            vader_array_t* _a7_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l11)
            t3 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l11];
            l12 = vader_chk_add(i32, t3, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l11)
            ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l11] = (int32_t) l12;
        }
        if (l10.tag == 723u) {
            t2 = l10.payload.obj;
            t3 = ((vader_struct_vader_bytecode_LocalGet_t*) t2)->f_slot;
            t1 = ((int64_t) (int32_t) t3);
            l13 = (size_t) (int64_t) t1;
            vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l13)
            t3 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l13];
            l14 = vader_chk_add(i32, t3, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l13)
            ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l13] = (int32_t) l14;
        }
        if (l10.tag == 725u) {
            t2 = l10.payload.obj;
            t3 = ((vader_struct_vader_bytecode_LocalTee_t*) t2)->f_slot;
            t1 = ((int64_t) (int32_t) t3);
            l15 = (size_t) (int64_t) t1;
            vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l15)
            t3 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l15];
            l16 = vader_chk_add(i32, t3, INT32_C(1));
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l15)
            ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l15] = (int32_t) l16;
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l9 = vader_bytecode_mark_jump_targets(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l3);
    vader_array_t* _a10_arr = vader_array_new(215u, 0u, 13u, 1441u);
    l17 = (void*) _a10_arr;
    l4 = (size_t) 0;
    vader_array_t* _a11_arr = vader_array_new(16u, 0u, 7u, 281u);
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
            if (VADER_LIKELY(_pc150_len < _pc150_cap)) {
                ((int32_t*) _pc150_slots)[_pc150_len] = (int32_t) (INT32_C(-1));
                _pc150_len += 1;
            } else {
                _pc150_hdr->length = _pc150_len;
                if (_pc150_hdr->buf->length < _pc150_len) {
                    _pc150_hdr->buf->length = _pc150_len;
                }
                vader_array_push_i32((vader_array_t*) l18, INT32_C(-1));
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
        l10 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l5);
        if (l10.tag == 724u) {
            t1 = vader_chk_add(usize, l5, INT64_C(1));
            if ((t1 < l3)) {
                t1 = vader_chk_add(usize, l5, INT64_C(1));
                l11 = (size_t) (int64_t) t1;
                vader_array_t* _a14_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l11)
                l19 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l11);
                if (l19.tag == 723u) {
                    t2 = l19.payload.obj;
                    l12 = ((vader_struct_vader_bytecode_LocalGet_t*) t2)->f_slot;
                    t2 = l10.payload.obj;
                    l14 = ((vader_struct_vader_bytecode_LocalSet_t*) t2)->f_slot;
                    if (l12 == l14) {
                        l20 = false;
                        if ((l4 > INT64_C(0))) {
                            t1 = vader_chk_sub(usize, l4, INT64_C(1));
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
                            t1 = vader_chk_add(usize, l5, INT64_C(1));
                            l25 = (size_t) (int64_t) t1;
                            vader_array_t* _a19_slotarr = ((vader_array_t*) l9);
                            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l25)
                            t4 = vader_box_bool(276u, ((uint8_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l25]);
                            l23 = t4.payload.b;
                        }
                        if (!(l23)) {
                            t2 = l10.payload.obj;
                            t3 = ((vader_struct_vader_bytecode_LocalSet_t*) t2)->f_slot;
                            vader_struct_vader_bytecode_LocalTee_t* _a20_obj = (vader_struct_vader_bytecode_LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalTee_t));
                            vader_obj_header_init(_a20_obj, 725u);
                            _a20_obj->f_slot = t3;
                            l26 = (void*) _a20_obj;
                            vader_bytecode_push_or_assign(l17, l4, vader_ref_box(l26));
                            l16 = ((int32_t) (size_t) l4);
                            vader_array_t* _a21_slotarr = ((vader_array_t*) l18);
                            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l5)
                            ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l5] = (int32_t) l16;
                            t1 = vader_chk_add(usize, l5, INT64_C(1));
                            l27 = (size_t) (int64_t) t1;
                            l28 = ((int32_t) (size_t) l4);
                            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l27)
                            ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l27] = (int32_t) l28;
                            t1 = vader_chk_add(usize, l4, INT64_C(1));
                            l4 = (size_t) (int64_t) t1;
                            t1 = vader_chk_add(usize, l5, INT64_C(2));
                            l5 = (size_t) (int64_t) t1;
                            continue;
                        }
                    }
                }
            }
        }
        if (l10.tag == 735u) {
            if (!(l1)) {
                l29 = ((vader_array_t*) l17)->length;
                if ((l29 > INT64_C(0))) {
                    t1 = vader_chk_sub(usize, l29, INT64_C(1));
                    l30 = (size_t) (int64_t) t1;
                    vader_array_t* _a22_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
                    t4 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l30);
                    l31 = vader_bytecode_const_op_of(t4);
                    if (!(l31.tag == 0u)) {
                        t1 = vader_chk_sub(usize, l29, INT64_C(1));
                        l32 = (size_t) (int64_t) t1;
                        vader_struct_vader_bytecode_ReturnLit_t* _a23_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                        vader_obj_header_init(_a23_obj, 736u);
                        _a23_obj->f_value = l31;
                        l33 = (void*) _a23_obj;
                        vader_array_t* _a24_slotarr = ((vader_array_t*) l17);
                        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
                        vader_array_ref_store(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l32, l33);
                        VADER_WRITE_BARRIER(_a24_slotarr->buf);
                        t1 = vader_chk_sub(usize, l4, INT64_C(1));
                        l34 = ((int32_t) (int64_t) t1);
                        vader_array_t* _a25_slotarr = ((vader_array_t*) l18);
                        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l5)
                        ((int32_t*) _a25_slotarr->buf->slots)[_a25_slotarr->offset + (size_t) l5] = (int32_t) l34;
                        t1 = vader_chk_add(usize, l5, INT64_C(1));
                        l5 = (size_t) (int64_t) t1;
                        continue;
                    }
                }
            }
        }
        if (l10.tag == 632u) {
            if ((l4 > INT64_C(0))) {
                t1 = vader_chk_sub(usize, l4, INT64_C(1));
                l35 = (size_t) (int64_t) t1;
                vader_array_t* _a26_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l35)
                l36 = vader_array_ref_load_box(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l35);
                if (l36.tag == 632u) {
                    vader_array_t* _a27_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l5)
                    ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l5] = (int32_t) INT32_C(-1);
                    t1 = vader_chk_sub(usize, l4, INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    t1 = vader_chk_add(usize, l5, INT64_C(1));
                    l5 = (size_t) (int64_t) t1;
                    continue;
                }
                if (l36.tag == 629u) {
                    t2 = l36.payload.obj;
                    t6 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                    vader_struct_vader_bytecode_BoolConst_t* _a28_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                    vader_obj_header_init(_a28_obj, 629u);
                    _a28_obj->f_value = !(t6);
                    l37 = (void*) _a28_obj;
                    vader_array_t* _a29_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l35)
                    vader_array_ref_store(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l35, l37);
                    VADER_WRITE_BARRIER(_a29_slotarr->buf);
                    l38 = ((int32_t) (size_t) l35);
                    vader_array_t* _a30_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l5)
                    ((int32_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l5] = (int32_t) l38;
                    t1 = vader_chk_add(usize, l5, INT64_C(1));
                    l5 = (size_t) (int64_t) t1;
                    continue;
                }
            }
        }
        vader_bytecode_push_or_assign(l17, l4, l10);
        l39 = ((int32_t) (size_t) l4);
        vader_array_t* _a31_slotarr = ((vader_array_t*) l18);
        VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l5)
        ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l5] = (int32_t) l39;
        t1 = vader_chk_add(usize, l4, INT64_C(1));
        l4 = (size_t) (int64_t) t1;
        t1 = vader_chk_add(usize, l5, INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    vader_array_t* _a32_arr = vader_array_slice((vader_array_t*) l17, (size_t) INT64_C(0), (size_t) l4);
    l2 = (void*) _a32_arr;
    l6 = vader_bytecode_remap_jump_table(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l18, l4);
    l7 = vader_bytecode_remap_debug(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug, l18, l4);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a33_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a33_obj, 613u);
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
    void* l12 = NULL;
    size_t l2, l4, l6, l8, l9, l11;
    vader_box_t l7 = vader_box_null(), l10 = vader_box_null();
    int32_t l13, l14;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l7, &l10, &t3 };
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
    vader_array_t* _a0_arr = vader_array_new(215u, 0u, 13u, 1441u);
    l3 = (void*) _a0_arr;
    l4 = (size_t) 0;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 7u, 281u);
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
            if (VADER_LIKELY(_pc23_len < _pc23_cap)) {
                ((int32_t*) _pc23_slots)[_pc23_len] = (int32_t) (INT32_C(-1));
                _pc23_len += 1;
            } else {
                _pc23_hdr->length = _pc23_len;
                if (_pc23_hdr->buf->length < _pc23_len) {
                    _pc23_hdr->buf->length = _pc23_len;
                }
                vader_array_push_i32((vader_array_t*) l5, INT32_C(-1));
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
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        if (l7.tag == 735u) {
            l8 = ((vader_array_t*) l3)->length;
            if ((l8 > INT64_C(0))) {
                t2 = vader_chk_sub(usize, l8, INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                t3 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l9);
                l10 = vader_bytecode_const_op_of(t3);
                if (!(l10.tag == 0u)) {
                    t2 = vader_chk_sub(usize, l8, INT64_C(1));
                    l11 = (size_t) (int64_t) t2;
                    vader_struct_vader_bytecode_ReturnLit_t* _a5_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                    vader_obj_header_init(_a5_obj, 736u);
                    _a5_obj->f_value = l10;
                    l12 = (void*) _a5_obj;
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                    vader_array_ref_store(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l11, l12);
                    VADER_WRITE_BARRIER(_a6_slotarr->buf);
                    t2 = vader_chk_sub(usize, l8, INT64_C(1));
                    l13 = ((int32_t) (int64_t) t2);
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l6)
                    ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l6] = (int32_t) l13;
                    t2 = vader_chk_add(usize, l6, INT64_C(1));
                    l6 = (size_t) (int64_t) t2;
                    continue;
                }
            }
        }
        vader_bytecode_push_or_assign(l3, l4, l7);
        l14 = ((int32_t) (size_t) l4);
        vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l6)
        ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l6] = (int32_t) l14;
        t2 = vader_chk_add(usize, l4, INT64_C(1));
        l4 = (size_t) (int64_t) t2;
        t2 = vader_chk_add(usize, l6, INT64_C(1));
        l6 = (size_t) (int64_t) t2;
    }
    vader_array_t* _a9_arr = vader_array_slice((vader_array_t*) l3, (size_t) INT64_C(0), (size_t) l4);
    l1 = (void*) _a9_arr;
    l3 = vader_bytecode_remap_jump_table(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l5, l4);
    l5 = vader_bytecode_remap_debug(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug, l5, l4);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a10_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a10_obj, 613u);
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
    if (l0.tag == 1190u) {
        t0 = l0.payload.obj;
        t1 = vader_bytecode_same_intern_class(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1190u) {
        l2 = l0;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_types_DistinctType_t*) t0)->f_backing;
        t1 = vader_bytecode_same_intern_class(l2, l3);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 1191u || l0.tag == 1198u)) {
        l4 = true;
    } else {
        l4 = (l1.tag == 1191u || l1.tag == 1198u);
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
    if (l0.tag == 1200u) {
        if (l1.tag == 1200u) {
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
    if (l0.tag == 1201u) {
        if (l1.tag == 1201u) {
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
    if (l0.tag == 1189u) {
        if (l1.tag == 1189u) {
            t0 = l0.payload.obj;
            l2 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_element;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_element;
            t1 = vader_bytecode_same_intern_class(l2, l3);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 1205u) {
        if (l1.tag == 1205u) {
            t0 = l0.payload.obj;
            l7 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
            t1 = vader_bytecode_same_class_list(l7, l8);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 1202u) {
        if (l1.tag == 1202u) {
            t0 = l0.payload.obj;
            l7 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
            t1 = vader_bytecode_same_class_list(l7, l8);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (!(l0.tag == 1192u)) {
        l5 = vader_bytecode_bare_intern_name(l0);
        l6 = vader_bytecode_bare_intern_name(l1);
        { bool __vret = l5 == l6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1192u) {
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
        vader_obj_header_init(_a0_obj, 689u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I64Shl_t* _a1_obj = (vader_struct_vader_bytecode_I64Shl_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Shl_t));
    vader_obj_header_init(_a1_obj, 709u);
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
            vader_obj_header_init(_a0_obj, 710u);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_I64ShrU_t* _a1_obj = (vader_struct_vader_bytecode_I64ShrU_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64ShrU_t));
        vader_obj_header_init(_a1_obj, 711u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1)) {
        vader_struct_vader_bytecode_I32Shr_t* _a2_obj = (vader_struct_vader_bytecode_I32Shr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Shr_t));
        vader_obj_header_init(_a2_obj, 690u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32ShrU_t* _a3_obj = (vader_struct_vader_bytecode_I32ShrU_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32ShrU_t));
    vader_obj_header_init(_a3_obj, 691u);
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_bytecode_size_of_bc_type(vader_box_t l0) {
    int32_t l1;
    void* t0;
    if (l0.tag == 615u) {
        t0 = l0.payload.obj;
        l1 = vader_bytecode_size_of_val_type(((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val);
        return l1;
    }
    if (l0.tag == 619u) {
        l1 = INT32_C(8);
    } else if (l0.tag == 606u) {
        l1 = INT32_C(8);
    } else if (l0.tag == 609u) {
        l1 = INT32_C(8);
    } else if (l0.tag == 620u) {
        l1 = INT32_C(16);
    } else {
        if (!(l0.tag == 616u)) {
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
        vader_obj_header_init(_a0_obj, 719u);
        _a0_obj->f_bounds_safe = l1;
        t0 = (void*) _a0_obj;
        l3 = vader_ref_box(t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(2)) {
        vader_struct_vader_bytecode_LoadSlotI64_t* _a1_obj = (vader_struct_vader_bytecode_LoadSlotI64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LoadSlotI64_t));
        vader_obj_header_init(_a1_obj, 720u);
        _a1_obj->f_bounds_safe = l1;
        t0 = (void*) _a1_obj;
        l3 = vader_ref_box(t0);
    } else if (l2 == INT32_C(3)) {
        vader_struct_vader_bytecode_LoadSlotF64_t* _a2_obj = (vader_struct_vader_bytecode_LoadSlotF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LoadSlotF64_t));
        vader_obj_header_init(_a2_obj, 718u);
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
        vader_obj_header_init(_a0_obj, 743u);
        _a0_obj->f_bounds_safe = l1;
        t0 = (void*) _a0_obj;
        l3 = vader_ref_box(t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(2)) {
        vader_struct_vader_bytecode_StoreSlotI64_t* _a1_obj = (vader_struct_vader_bytecode_StoreSlotI64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StoreSlotI64_t));
        vader_obj_header_init(_a1_obj, 744u);
        _a1_obj->f_bounds_safe = l1;
        t0 = (void*) _a1_obj;
        l3 = vader_ref_box(t0);
    } else if (l2 == INT32_C(3)) {
        vader_struct_vader_bytecode_StoreSlotF64_t* _a2_obj = (vader_struct_vader_bytecode_StoreSlotF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StoreSlotF64_t));
        vader_obj_header_init(_a2_obj, 742u);
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
    if (l0.tag == 723u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalGet_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 724u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 725u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
        return t1;
    }
    if (!(l0.tag == 722u)) {
        return INT32_C(-1);
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_slot;
    return t1;
}

static vader_box_t vader_bytecode_slot_width_for(uint8_t l0) {
    vader_box_t l1;
    if (l0 == INT32_C(0)) {
        l1 = vader_box_i32(284u, INT32_C(0));
        return l1;
    }
    if (l0 == INT32_C(5)) {
        l1 = vader_box_i32(284u, INT32_C(0));
    } else if (l0 == INT32_C(12)) {
        l1 = vader_box_i32(284u, INT32_C(0));
    } else if (l0 == INT32_C(1)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(6)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(2)) {
        l1 = vader_box_i32(284u, INT32_C(1));
    } else if (l0 == INT32_C(7)) {
        l1 = vader_box_i32(284u, INT32_C(1));
    } else if (l0 == INT32_C(13)) {
        l1 = vader_box_i32(284u, INT32_C(1));
    } else if (l0 == INT32_C(10)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(3)) {
        l1 = vader_box_i32(284u, INT32_C(2));
    } else if (l0 == INT32_C(8)) {
        l1 = vader_box_i32(284u, INT32_C(2));
    } else if (l0 == INT32_C(4)) {
        l1 = vader_box_i32(284u, INT32_C(2));
    } else if (l0 == INT32_C(9)) {
        l1 = vader_box_i32(284u, INT32_C(2));
    } else if (l0 == INT32_C(11)) {
        l1 = vader_box_i32(284u, INT32_C(3));
    } else if (l0 == INT32_C(14)) {
        l1 = vader_box_i32(284u, INT32_C(4));
    } else if (l0 == INT32_C(15)) {
        l1 = vader_box_i32(284u, INT32_C(4));
    } else if (l0 == INT32_C(16)) {
        l1 = vader_box_i32(284u, INT32_C(4));
    } else if (l0 == INT32_C(17)) {
        l1 = vader_box_i32(284u, INT32_C(2));
    } else if (l0 == INT32_C(18)) {
        l1 = vader_box_i32(284u, INT32_C(4));
    } else {
        if (!(l0 == INT32_C(19))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_box_i32(284u, INT32_C(4));
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
    t0 = std_string_starts_with(l0, 2320u);
    if (t0) {
        t0 = std_string_ends_with(l0, l1);
        if (t0) {
            l2 = vader_host_std_core_bytes(l0);
            l3 = vader_host_std_core_byte_len(2320u);
            l4 = ((vader_array_t*) l2)->length;
            l5 = vader_host_std_core_byte_len(l1);
            t1 = vader_chk_sub(usize, l4, l5);
            l4 = (size_t) (int64_t) t1;
            vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l2, (size_t) l3, (size_t) l4);
            t2 = (void*) _a0_arr;
            t3 = vader_host_std_core_bytes_to_string(t2);
            t4 = vader_box_string(278u, t3);
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
    size_t l2, l5, l9, l11;
    bool l4;
    vader_box_t l8 = vader_box_null();
    int32_t l10, l12;
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
        t1 = vader_chk_add(usize, l5, INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    if (!(l4)) {
        t2 = vader_bytecode_bc_peephole_unchanged(l0);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(215u, 0u, 13u, 1441u);
    l6 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 1u, 7u, 281u);
    ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t2, (size_t) l2);
    l7 = (void*) _a2_arr;
    l5 = (size_t) 0;
    while ((l5 < l2)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l8 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        t0 = vader_bytecode_foldable_self_copy(l1, l5, l2, l3);
        if (t0) {
            t1 = vader_chk_add(usize, l5, INT64_C(1));
            l9 = (size_t) (int64_t) t1;
            vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
            t3 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l9);
            if (t3.tag == 725u) {
                t4 = ((vader_array_t*) l6)->length;
                l10 = ((int32_t) (size_t) t4);
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
            t1 = vader_chk_add(usize, l5, INT64_C(1));
            l11 = (size_t) (int64_t) t1;
            vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l11)
            ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l11] = (int32_t) INT32_C(-1);
            t1 = vader_chk_add(usize, l5, INT64_C(2));
            l5 = (size_t) (int64_t) t1;
            continue;
        }
        t4 = ((vader_array_t*) l6)->length;
        l12 = ((int32_t) (size_t) t4);
        vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l5)
        ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l5] = (int32_t) l12;
        vader_array_push((vader_array_t*) l6, l8);
        t1 = vader_chk_add(usize, l5, INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l2 = ((vader_array_t*) l6)->length;
    l1 = vader_bytecode_remap_jump_table(l1, l7, l2);
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug;
    l2 = ((vader_array_t*) l6)->length;
    l3 = vader_bytecode_remap_debug(l3, l7, l2);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a9_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a9_obj, 613u);
    _a9_obj->f_body = l6;
    _a9_obj->f_jump_table = l1;
    _a9_obj->f_debug = l3;
    t2 = (void*) _a9_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_bytecode_struct_symbol_type_index(void* l0, int32_t l1) {
    size_t l2, l3;
    vader_box_t l4;
    void* t0;
    int32_t t1;
    int64_t t2;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 619u) {
            t0 = l4.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_symbol_id;
            if (t1 == l1) {
                return ((int32_t) (size_t) l2);
            }
        }
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
    }
    return INT32_C(-1);
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
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 619u) {
            t0 = l4.payload.obj;
            t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_name;
            if (t1 == l1) {
                return ((int32_t) (size_t) l2);
            }
        }
        t2 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t2;
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
        t0 = concat_3(l4, 319u, l5);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = std_core_new_byte_buffer((size_t) 22);
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l1, l2, 1874u);
    t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    l3 = ((int64_t) (int32_t) t1);
    l2 = std_core_write_int(l1, l2, l3);
    t0 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_try_fold_arith(vader_box_t l0, void* l1, size_t l2) {
    size_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l12 = vader_box_null();
    int32_t l6, l7;
    int64_t l8, l9;
    uint8_t l10, l11;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t* gc_roots[4] = { &l0, &l4, &l5, &l12 };
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l2 < INT64_C(2))) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = vader_chk_sub(usize, l2, INT64_C(1));
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    t0 = vader_chk_sub(usize, l2, INT64_C(2));
    l3 = (size_t) (int64_t) t0;
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l5.tag == 678u) {
        if (l4.tag == 678u) {
            if (l0.tag == 673u) {
                t1 = l5.payload.obj;
                l6 = ((vader_struct_vader_bytecode_I32Const_t*) t1)->f_value;
                t1 = l4.payload.obj;
                l7 = ((vader_struct_vader_bytecode_I32Const_t*) t1)->f_value;
                vader_struct_vader_bytecode_I32Const_t* _a1_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
                vader_obj_header_init(_a1_obj, 678u);
                _a1_obj->f_value = (l6 + l7);
                t1 = (void*) _a1_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 692u) {
                t1 = l5.payload.obj;
                l6 = ((vader_struct_vader_bytecode_I32Const_t*) t1)->f_value;
                t1 = l4.payload.obj;
                l7 = ((vader_struct_vader_bytecode_I32Const_t*) t1)->f_value;
                vader_struct_vader_bytecode_I32Const_t* _a2_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
                vader_obj_header_init(_a2_obj, 678u);
                _a2_obj->f_value = (l6 - l7);
                t1 = (void*) _a2_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 686u) {
                t1 = l5.payload.obj;
                l6 = ((vader_struct_vader_bytecode_I32Const_t*) t1)->f_value;
                t1 = l4.payload.obj;
                l7 = ((vader_struct_vader_bytecode_I32Const_t*) t1)->f_value;
                vader_struct_vader_bytecode_I32Const_t* _a3_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
                vader_obj_header_init(_a3_obj, 678u);
                _a3_obj->f_value = (l6 * l7);
                t1 = (void*) _a3_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 645u) {
                t1 = l5.payload.obj;
                t2 = ((vader_struct_vader_bytecode_I32Const_t*) t1)->f_value;
                l8 = ((int64_t) (int32_t) t2);
                t1 = l4.payload.obj;
                t2 = ((vader_struct_vader_bytecode_I32Const_t*) t1)->f_value;
                l9 = ((int64_t) (int32_t) t2);
                t1 = l0.payload.obj;
                l10 = ((vader_struct_vader_bytecode_CheckedArith_t*) t1)->f_op;
                t1 = l0.payload.obj;
                l11 = ((vader_struct_vader_bytecode_CheckedArith_t*) t1)->f_kind;
                l12 = vader_bytecode_checked_arith(l10, l11, l8, l9);
                if (l12.tag == 0u) {
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                t0 = ((int64_t) l12.payload.i);
                vader_struct_vader_bytecode_I32Const_t* _a4_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
                vader_obj_header_init(_a4_obj, 678u);
                _a4_obj->f_value = ((int32_t) (int64_t) t0);
                t1 = (void*) _a4_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    if (l5.tag == 698u) {
        if (l4.tag == 698u) {
            if (l0.tag == 693u) {
                t1 = l5.payload.obj;
                l8 = ((vader_struct_vader_bytecode_I64Const_t*) t1)->f_value;
                t1 = l4.payload.obj;
                l9 = ((vader_struct_vader_bytecode_I64Const_t*) t1)->f_value;
                vader_struct_vader_bytecode_I64Const_t* _a5_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                vader_obj_header_init(_a5_obj, 698u);
                _a5_obj->f_value = (l8 + l9);
                t1 = (void*) _a5_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 712u) {
                t1 = l5.payload.obj;
                l8 = ((vader_struct_vader_bytecode_I64Const_t*) t1)->f_value;
                t1 = l4.payload.obj;
                l9 = ((vader_struct_vader_bytecode_I64Const_t*) t1)->f_value;
                vader_struct_vader_bytecode_I64Const_t* _a6_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                vader_obj_header_init(_a6_obj, 698u);
                _a6_obj->f_value = (l8 - l9);
                t1 = (void*) _a6_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 706u) {
                t1 = l5.payload.obj;
                l8 = ((vader_struct_vader_bytecode_I64Const_t*) t1)->f_value;
                t1 = l4.payload.obj;
                l9 = ((vader_struct_vader_bytecode_I64Const_t*) t1)->f_value;
                vader_struct_vader_bytecode_I64Const_t* _a7_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                vader_obj_header_init(_a7_obj, 698u);
                _a7_obj->f_value = (l8 * l9);
                t1 = (void*) _a7_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 645u) {
                t1 = l0.payload.obj;
                l10 = ((vader_struct_vader_bytecode_CheckedArith_t*) t1)->f_op;
                t1 = l0.payload.obj;
                l11 = ((vader_struct_vader_bytecode_CheckedArith_t*) t1)->f_kind;
                t1 = l5.payload.obj;
                l8 = ((vader_struct_vader_bytecode_I64Const_t*) t1)->f_value;
                t1 = l4.payload.obj;
                l9 = ((vader_struct_vader_bytecode_I64Const_t*) t1)->f_value;
                l4 = vader_bytecode_checked_arith(l10, l11, l8, l9);
                if (l4.tag == 0u) {
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                t0 = ((int64_t) l4.payload.i);
                vader_struct_vader_bytecode_I64Const_t* _a8_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                vader_obj_header_init(_a8_obj, 698u);
                _a8_obj->f_value = t0;
                t1 = (void*) _a8_obj;
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
    l1 = vader_bytecode_type_key_join(l0, 841u);
    l2 = vader_bytecode_fnv1a_hex(l1);
    l1 = vader_bytecode_c_safe_key(l1);
    l3 = vader_host_std_core_byte_len(l1);
    t0 = vader_chk_sub(usize, INT64_C(32), INT64_C(1));
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
        l3 = std_core_write_string_at(l6, l3, 841u);
        l3 = std_core_write_string_at(l6, l3, l5);
        t2 = std_core_finish_buffer(l6, l3);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_string_slice_codepoints(l2, INT64_C(0), INT64_C(8));
    t2 = concat_3(l1, 841u, l2);
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
    if (l0.tag == 752u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_type_id;
        return l1;
    }
    if (l0.tag == 751u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_type_id;
    } else if (l0.tag == 753u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_type_id;
    } else if (l0.tag == 598u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_type_id;
    } else if (l0.tag == 596u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_ArrayGet_t*) t0)->f_type_id;
    } else if (l0.tag == 603u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_ArraySet_t*) t0)->f_type_id;
    } else if (l0.tag == 599u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_type_id;
    } else if (l0.tag == 754u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_TypeCheck_t*) t0)->f_type_id;
    } else if (l0.tag == 755u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_TypeConst_t*) t0)->f_type_id;
    } else if (l0.tag == 643u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_CallIndirect_t*) t0)->f_type_id;
    } else if (l0.tag == 727u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_env_type_id;
    } else if (l0.tag == 672u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_type_id;
    } else if (l0.tag == 722u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_type_id;
    } else if (l0.tag == 604u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_ArraySlice_t*) t0)->f_type_id;
    } else if (l0.tag == 731u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_RefCast_t*) t0)->f_type_id;
    } else if (l0.tag == 734u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_Retag_t*) t0)->f_type_id;
    } else if (l0.tag == 648u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_type_id;
    } else {
        if (!((l0.tag == 594u || l0.tag == 595u || l0.tag == 597u || l0.tag == 600u || l0.tag == 601u || l0.tag == 602u || l0.tag == 625u || l0.tag == 626u || l0.tag == 627u || l0.tag == 628u || l0.tag == 629u || l0.tag == 630u || l0.tag == 631u || l0.tag == 632u || l0.tag == 633u || l0.tag == 634u || l0.tag == 635u || l0.tag == 636u || l0.tag == 637u || l0.tag == 638u || l0.tag == 641u || l0.tag == 642u || l0.tag == 644u || l0.tag == 645u || l0.tag == 646u || l0.tag == 647u || l0.tag == 650u || l0.tag == 651u || l0.tag == 652u || l0.tag == 653u || l0.tag == 656u || l0.tag == 657u || l0.tag == 658u || l0.tag == 659u || l0.tag == 660u || l0.tag == 661u || l0.tag == 662u || l0.tag == 663u || l0.tag == 664u || l0.tag == 665u || l0.tag == 666u || l0.tag == 667u || l0.tag == 668u || l0.tag == 669u || l0.tag == 670u || l0.tag == 671u || l0.tag == 673u || l0.tag == 674u || l0.tag == 675u || l0.tag == 676u || l0.tag == 677u || l0.tag == 678u || l0.tag == 679u || l0.tag == 680u || l0.tag == 681u || l0.tag == 682u || l0.tag == 683u || l0.tag == 684u || l0.tag == 685u || l0.tag == 686u || l0.tag == 687u || l0.tag == 688u || l0.tag == 689u || l0.tag == 690u || l0.tag == 691u || l0.tag == 692u || l0.tag == 693u || l0.tag == 694u || l0.tag == 695u || l0.tag == 696u || l0.tag == 697u || l0.tag == 698u || l0.tag == 699u || l0.tag == 700u || l0.tag == 701u || l0.tag == 702u || l0.tag == 703u || l0.tag == 704u || l0.tag == 705u || l0.tag == 706u || l0.tag == 707u || l0.tag == 708u || l0.tag == 709u || l0.tag == 710u || l0.tag == 711u || l0.tag == 712u || l0.tag == 713u || l0.tag == 715u || l0.tag == 716u || l0.tag == 717u || l0.tag == 718u || l0.tag == 719u || l0.tag == 720u || l0.tag == 721u || l0.tag == 723u || l0.tag == 724u || l0.tag == 725u || l0.tag == 726u || l0.tag == 728u || l0.tag == 729u || l0.tag == 732u || l0.tag == 733u || l0.tag == 735u || l0.tag == 736u || l0.tag == 737u || l0.tag == 739u || l0.tag == 740u || l0.tag == 741u || l0.tag == 742u || l0.tag == 743u || l0.tag == 744u || l0.tag == 745u || l0.tag == 746u || l0.tag == 747u || l0.tag == 748u || l0.tag == 749u || l0.tag == 750u || l0.tag == 756u || l0.tag == 757u || l0.tag == 758u || l0.tag == 759u || l0.tag == 760u || l0.tag == 761u || l0.tag == 762u || l0.tag == 763u || l0.tag == 764u || l0.tag == 765u || l0.tag == 766u || l0.tag == 767u || l0.tag == 768u || l0.tag == 769u))) {
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
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l4, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1198u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        l1 = vader_bytecode_bare_hash(t1);
        { uint64_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1191u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
        l1 = vader_bytecode_bare_hash(t1);
    } else if (l0.tag == 1188u) {
        l1 = vader_bytecode_bare_hash(453u);
    } else if ((l0.tag == 1193u || l0.tag == 1194u || l0.tag == 1195u || l0.tag == 1196u || l0.tag == 1199u || l0.tag == 1203u || l0.tag == 1204u || l0.tag == 1206u)) {
        t1 = vader_types_display_type(l0);
        l1 = vader_bytecode_bare_hash(t1);
    } else if (l0.tag == 1190u) {
        t0 = l0.payload.obj;
        l1 = vader_bytecode_type_intern_hash(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 1200u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 1);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_symbol_hash(((vader_struct_vader_types_StructType_t*) t0)->f_symbol);
        l2 = vader_bytecode_mix64(l2, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
        l1 = vader_bytecode_type_args_hash(l2, l4);
    } else if (l0.tag == 1201u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 2);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_symbol_hash(((vader_struct_vader_types_TraitType_t*) t0)->f_symbol);
        l2 = vader_bytecode_mix64(l2, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
        l1 = vader_bytecode_type_args_hash(l2, l4);
    } else if (l0.tag == 1189u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 3);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_type_intern_hash(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        l1 = vader_bytecode_mix64(l2, l3);
    } else if (l0.tag == 1205u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 4);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        l1 = vader_bytecode_type_args_hash(l2, l4);
    } else if (l0.tag == 1202u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 5);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
        l1 = vader_bytecode_type_args_hash(l2, l4);
    } else {
        if (!(l0.tag == 1192u)) {
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
    if (l0.tag == 1198u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1200u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_symbol_key(((vader_struct_vader_types_StructType_t*) t0)->f_symbol);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_type_key_join(((vader_struct_vader_types_StructType_t*) t0)->f_args, 2769u);
        l1 = concat_5(685u, l2, 411u, l3, 433u);
    } else if (l0.tag == 1201u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_symbol_key(((vader_struct_vader_types_TraitType_t*) t0)->f_symbol);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_type_key_join(((vader_struct_vader_types_TraitType_t*) t0)->f_args, 2769u);
        l1 = concat_5(783u, l2, 411u, l3, 433u);
    } else if (l0.tag == 1191u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
    } else if (l0.tag == 1190u) {
        t0 = l0.payload.obj;
        l1 = vader_bytecode_type_intern_key(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 1189u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_type_intern_key(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        l1 = concat_3(455u, l2, 433u);
    } else if (l0.tag == 1205u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_type_key_join(((vader_struct_vader_types_UnionType_t*) t0)->f_variants, 2769u);
        l1 = concat_3(790u, l2, 433u);
    } else if (l0.tag == 1202u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_type_key_join(((vader_struct_vader_types_TupleType_t*) t0)->f_elements, 2769u);
        l1 = concat_3(785u, l2, 433u);
    } else if (l0.tag == 1192u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_type_key_join(((vader_struct_vader_types_FnType_t*) t0)->f_params, 286u);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_type_intern_key(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
        l1 = concat_4(526u, l2, 273u, l3);
    } else if (l0.tag == 1204u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1203u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1199u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1206u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1195u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1193u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1194u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 1196u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else {
        if (!(l0.tag == 1188u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 453u;
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
        l2 = vader_bytecode_checked_neg_op(l1);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        vader_struct_vader_bytecode_BoolNot_t* _a0_obj = (vader_struct_vader_bytecode_BoolNot_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolNot_t));
        vader_obj_header_init(_a0_obj, 632u);
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
        l1 = 1873u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 1828u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1829u;
    } else if (l0 == INT32_C(3)) {
        l1 = 1851u;
    } else if (l0 == INT32_C(4)) {
        l1 = 1959u;
    } else if (l0 == INT32_C(5)) {
        l1 = 2532u;
    } else if (l0 == INT32_C(6)) {
        l1 = 2511u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2512u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2522u;
    } else if (l0 == INT32_C(9)) {
        l1 = 2577u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1706u;
    } else if (l0 == INT32_C(11)) {
        l1 = 1708u;
    } else if (l0 == INT32_C(12)) {
        l1 = 1400u;
    } else if (l0 == INT32_C(13)) {
        l1 = 1514u;
    } else if (l0 == INT32_C(14)) {
        l1 = 2364u;
    } else if (l0 == INT32_C(15)) {
        l1 = 2146u;
    } else if (l0 == INT32_C(16)) {
        l1 = 2723u;
    } else if (l0 == INT32_C(17)) {
        l1 = 2198u;
    } else if (l0 == INT32_C(18)) {
        l1 = 2225u;
    } else {
        if (!(l0 == INT32_C(19))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1329u;
    }
    return l1;
}

static uint8_t vader_bytecode_val_type_of_primitive_name(vader_string_t l0) {
    vader_box_t l1;
    uint8_t t0;
    if (l0 == 488u) {
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
    if (l0.tag == 1198u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        l1 = vader_bytecode_val_type_of_primitive_name(t1);
        return l1;
    }
    if (l0.tag == 1200u) {
        l1 = (uint8_t) 18;
    } else if (l0.tag == 1191u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
        l1 = vader_bytecode_val_type_of_primitive_name(t1);
    } else if (l0.tag == 1190u) {
        t0 = l0.payload.obj;
        l1 = vader_bytecode_val_type_of_type(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 1189u) {
        l1 = (uint8_t) 18;
    } else if (l0.tag == 1192u) {
        l1 = (uint8_t) 18;
    } else if (l0.tag == 1202u) {
        l1 = (uint8_t) 18;
    } else if (l0.tag == 1201u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 1205u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 1204u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 1203u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 1199u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 1188u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 1206u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 1195u) {
        l1 = (uint8_t) 2;
    } else if (l0.tag == 1193u) {
        l1 = (uint8_t) 13;
    } else if (l0.tag == 1194u) {
        l1 = (uint8_t) 11;
    } else {
        if (!(l0.tag == 1196u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = (uint8_t) 16;
    }
    return l1;
}

static int64_t vader_bytecode_value_cell(uint8_t l0, int64_t l1) {
    if (!(l0 == INT32_C(7))) {
        return l1;
    }
    return ((int64_t) (int32_t) ((int32_t) (int64_t) l1));
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
    if (l6.tag == 619u) {
        t2 = l6.payload.obj;
        l5 = ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_fields;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            t3 = ((vader_struct_vader_bytecode_BcField_t*) t2)->f_type_index;
            vader_bytecode_visit_type(t3, l1, l2);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    }
    if (l6.tag == 620u) {
        t2 = l6.payload.obj;
        l5 = ((vader_struct_vader_bytecode_BcUnion_t*) t2)->f_variants;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
            vader_bytecode_visit_type(t3, l1, l2);
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
        }
    }
    if (l6.tag == 606u) {
        t2 = l6.payload.obj;
        t3 = ((vader_struct_vader_bytecode_BcArray_t*) t2)->f_element;
        vader_bytecode_visit_type(t3, l1, l2);
    }
    if (l6.tag == 609u) {
        t2 = l6.payload.obj;
        l5 = ((vader_struct_vader_bytecode_BcFn_t*) t2)->f_params;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
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
    if (l0.tag == 723u) {
        vader_struct_vader_bytecode_LocalGet_t* _a0_obj = (vader_struct_vader_bytecode_LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalGet_t));
        vader_obj_header_init(_a0_obj, 723u);
        _a0_obj->f_slot = l1;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 724u) {
        vader_struct_vader_bytecode_LocalSet_t* _a1_obj = (vader_struct_vader_bytecode_LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalSet_t));
        vader_obj_header_init(_a1_obj, 724u);
        _a1_obj->f_slot = l1;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 725u) {
        vader_struct_vader_bytecode_LocalTee_t* _a2_obj = (vader_struct_vader_bytecode_LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalTee_t));
        vader_obj_header_init(_a2_obj, 725u);
        _a2_obj->f_slot = l1;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 722u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_type_id;
    t0 = l0.payload.obj;
    l3 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_field_index;
    vader_struct_vader_bytecode_LocalField_t* _a3_obj = (vader_struct_vader_bytecode_LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalField_t));
    vader_obj_header_init(_a3_obj, 722u);
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
    vader_array_t* _a0_arr = vader_array_new(203u, 0u, 13u, 1294u);
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
    vader_string_t t5 = 0;
    bool t6;
    vader_box_t* gc_roots[2] = { &l2, &l13 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l10, &l12, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l14, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2.tag == 678u) {
        l3 = std_core_new_byte_buffer((size_t) 30);
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l3, l4, 1835u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_I32Const_t*) t0)->f_value;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core_write_int(l3, l4, l5);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 698u) {
        l3 = std_core_new_byte_buffer((size_t) 30);
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l3, l4, 1857u);
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_bytecode_I64Const_t*) t0)->f_value;
        l4 = std_core_write_int(l3, l4, l5);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 659u) {
        t0 = l2.payload.obj;
        t2 = ((vader_struct_vader_bytecode_F64Const_t*) t0)->f_value;
        l6 = vader_bytecode_f64_const_operands(t2);
        l6 = concat_2(1710u, l6);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 629u) {
        l3 = std_core_new_byte_buffer((size_t) 16);
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l3, l4, 1402u);
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_bytecode_BoolConst_t*) t0)->f_value;
        l4 = std_core_write_bool(l3, l4, l7);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 644u) {
        l3 = std_core_new_byte_buffer((size_t) 31);
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l3, l4, 1516u);
        t0 = l2.payload.obj;
        t3 = ((vader_struct_vader_bytecode_CharConst_t*) t0)->f_value;
        t4 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3));
        l8 = (uint64_t) (int64_t) t4;
        l4 = std_core_write_unsigned(l3, l4, l8);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 729u) {
        std_string_builder_append(l0, 2147u);
    } else if (l2.tag == 747u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_StringConst_t*) t0)->f_index;
        t0 = vader_bytecode_refer((uint8_t) 3, l9);
        vader_array_t* _a0_arr = vader_array_new(53u, 1u, 13u, 730u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0;
        l3 = (void*) _a0_arr;
        vader_bytecode_printed(l0, l1, 2370u, l3);
    } else if (l2.tag == 723u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_LocalGet_t*) t0)->f_slot;
        t0 = vader_bytecode_refer((uint8_t) 6, l9);
        vader_array_t* _a1_arr = vader_array_new(53u, 1u, 13u, 730u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
        l3 = (void*) _a1_arr;
        vader_bytecode_printed(l0, l1, 2031u, l3);
    } else if (l2.tag == 724u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
        t0 = vader_bytecode_refer((uint8_t) 6, l9);
        vader_array_t* _a2_arr = vader_array_new(53u, 1u, 13u, 730u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0;
        l3 = (void*) _a2_arr;
        vader_bytecode_printed(l0, l1, 2032u, l3);
    } else if (l2.tag == 725u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
        t0 = vader_bytecode_refer((uint8_t) 6, l9);
        vader_array_t* _a3_arr = vader_array_new(53u, 1u, 13u, 730u);
        ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = t0;
        l3 = (void*) _a3_arr;
        vader_bytecode_printed(l0, l1, 2033u, l3);
    } else if (l2.tag == 722u) {
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
        vader_array_t* _a4_arr = vader_array_new(53u, 3u, 13u, 730u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 2u] = l12;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l10;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l3;
        l3 = (void*) _a4_arr;
        vader_bytecode_printed(l0, l1, 2030u, l3);
    } else if (l2.tag == 735u) {
        std_string_builder_append(l0, 2246u);
    } else if (l2.tag == 736u) {
        std_string_builder_append(l0, 2250u);
        vader_array_push((vader_array_t*) l1, vader_box_obj(0u, NULL));
        t0 = l2.payload.obj;
        l13 = ((vader_struct_vader_bytecode_ReturnLit_t*) t0)->f_value;
        vader_bytecode_write_op_refs(l0, l1, l13);
    } else if (l2.tag == 652u) {
        std_string_builder_append(l0, 1610u);
    } else if (l2.tag == 641u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_Call_t*) t0)->f_function_index;
        t0 = vader_bytecode_refer((uint8_t) 0, l9);
        vader_array_t* _a5_arr = vader_array_new(53u, 1u, 13u, 730u);
        ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = t0;
        l3 = (void*) _a5_arr;
        vader_bytecode_printed(l0, l1, 1479u, l3);
    } else if (l2.tag == 642u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_CallImport_t*) t0)->f_index;
        t0 = vader_bytecode_refer((uint8_t) 4, l9);
        vader_array_t* _a6_arr = vader_array_new(53u, 1u, 13u, 730u);
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = t0;
        l3 = (void*) _a6_arr;
        vader_bytecode_printed(l0, l1, 1481u, l3);
    } else if (l2.tag == 643u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_CallIndirect_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a7_arr = vader_array_new(53u, 1u, 13u, 730u);
        ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t0;
        l3 = (void*) _a7_arr;
        vader_bytecode_printed(l0, l1, 1482u, l3);
    } else if (l2.tag == 769u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_VirtualCall_t*) t0)->f_vtable_key;
        l4 = vader_host_std_core_byte_len(l6);
        l3 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(34) + l4));
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l3, l4, 2721u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_VirtualCall_t*) t0)->f_parameter_count;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core_write_int(l3, l4, l5);
        l4 = std_core_write_string_at(l3, l4, 10u);
        l4 = std_core_write_string_at(l3, l4, l6);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 672u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_function_index;
        l3 = vader_bytecode_refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_type_id;
        l10 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a8_arr = vader_array_new(53u, 2u, 13u, 730u);
        ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 1u] = l10;
        ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = l3;
        l3 = (void*) _a8_arr;
        vader_bytecode_printed(l0, l1, 1767u, l3);
    } else if (l2.tag == 671u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_FnAddr_t*) t0)->f_function_index;
        t0 = vader_bytecode_refer((uint8_t) 0, l9);
        vader_array_t* _a9_arr = vader_array_new(53u, 1u, 13u, 730u);
        ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = t0;
        l3 = (void*) _a9_arr;
        vader_bytecode_printed(l0, l1, 1765u, l3);
    } else if (l2.tag == 645u) {
        t0 = l2.payload.obj;
        l6 = vader_bytecode_val_type_name(((vader_struct_vader_bytecode_CheckedArith_t*) t0)->f_kind);
        t0 = l2.payload.obj;
        l14 = vader_bytecode_checked_op_name(((vader_struct_vader_bytecode_CheckedArith_t*) t0)->f_op);
        l6 = concat_3(l6, 329u, l14);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 646u) {
        t0 = l2.payload.obj;
        t5 = vader_bytecode_val_type_name(((vader_struct_vader_bytecode_CheckedNeg_t*) t0)->f_kind);
        l6 = concat_2(t5, 330u);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 727u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_function_index;
        l3 = vader_bytecode_refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_env_type_id;
        l10 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a10_arr = vader_array_new(53u, 2u, 13u, 730u);
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 1u] = l10;
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = l3;
        l3 = (void*) _a10_arr;
        vader_bytecode_printed(l0, l1, 2047u, l3);
    } else if (l2.tag == 713u) {
        std_string_builder_append(l0, 1878u);
    } else if (l2.tag == 653u) {
        std_string_builder_append(l0, 1623u);
    } else if (l2.tag == 656u) {
        std_string_builder_append(l0, 1629u);
    } else if (l2.tag == 627u) {
        std_string_builder_append(l0, 1399u);
    } else if (l2.tag == 726u) {
        std_string_builder_append(l0, 2036u);
    } else if (l2.tag == 634u) {
        std_string_builder_append(l0, 1412u);
    } else if (l2.tag == 635u) {
        std_string_builder_append(l0, 1414u);
    } else if (l2.tag == 632u) {
        std_string_builder_append(l0, 1405u);
    } else if (l2.tag == 752u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_stack;
        if (t6) {
            l6 = 2394u;
        } else {
            l6 = 2391u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a11_arr = vader_array_new(53u, 1u, 13u, 730u);
        ((void**) _a11_arr->buf->slots)[_a11_arr->offset + 0u] = t0;
        l3 = (void*) _a11_arr;
        vader_bytecode_printed(l0, l1, l6, l3);
    } else if (l2.tag == 751u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_type_id;
        l3 = vader_bytecode_refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_field_index;
        l10 = vader_bytecode_refer_field(l9, l11);
        vader_array_t* _a12_arr = vader_array_new(53u, 2u, 13u, 730u);
        ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 1u] = l10;
        ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = l3;
        l3 = (void*) _a12_arr;
        vader_bytecode_printed(l0, l1, 2390u, l3);
    } else if (l2.tag == 753u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_stack;
        if (t6) {
            l6 = 2399u;
        } else {
            l6 = 2395u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_type_id;
        l3 = vader_bytecode_refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_field_index;
        l10 = vader_bytecode_refer_field(l9, l11);
        vader_array_t* _a13_arr = vader_array_new(53u, 2u, 13u, 730u);
        ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 1u] = l10;
        ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 0u] = l3;
        l3 = (void*) _a13_arr;
        vader_bytecode_printed(l0, l1, l6, l3);
    } else if (l2.tag == 598u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a14_arr = vader_array_new(53u, 1u, 13u, 730u);
        ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = t0;
        l3 = (void*) _a14_arr;
        vader_bytecode_printed(l0, l1, 1355u, l3);
        l3 = std_core_new_byte_buffer((size_t) 21);
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l3, l4, 10u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_length;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core_write_int(l3, l4, l5);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 597u) {
        std_string_builder_append(l0, 1354u);
    } else if (l2.tag == 599u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_cache_slot;
        if ((t1 >= INT32_C(0))) {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_type_id;
            l3 = vader_bytecode_refer((uint8_t) 1, l9);
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_cache_slot;
            l10 = vader_bytecode_refer((uint8_t) 6, l9);
            vader_array_t* _a15_arr = vader_array_new(53u, 2u, 13u, 730u);
            ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 1u] = l10;
            ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 0u] = l3;
            l3 = (void*) _a15_arr;
            vader_bytecode_printed(l0, l1, 1357u, l3);
        } else {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_type_id;
            t0 = vader_bytecode_refer((uint8_t) 1, l9);
            vader_array_t* _a16_arr = vader_array_new(53u, 1u, 13u, 730u);
            ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 0u] = t0;
            l3 = (void*) _a16_arr;
            vader_bytecode_printed(l0, l1, 1357u, l3);
        }
    } else if (l2.tag == 596u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_ArrayGet_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a17_arr = vader_array_new(53u, 1u, 13u, 730u);
        ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = t0;
        l3 = (void*) _a17_arr;
        vader_bytecode_printed(l0, l1, 1353u, l3);
    } else if (l2.tag == 603u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_ArraySet_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a18_arr = vader_array_new(53u, 1u, 13u, 730u);
        ((void**) _a18_arr->buf->slots)[_a18_arr->offset + 0u] = t0;
        l3 = (void*) _a18_arr;
        vader_bytecode_printed(l0, l1, 1366u, l3);
    } else if (l2.tag == 604u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_ArraySlice_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a19_arr = vader_array_new(53u, 1u, 13u, 730u);
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 0u] = t0;
        l3 = (void*) _a19_arr;
        vader_bytecode_printed(l0, l1, 1367u, l3);
    } else if (l2.tag == 602u) {
        std_string_builder_append(l0, 1363u);
    } else if (l2.tag == 600u) {
        std_string_builder_append(l0, 1358u);
    } else if (l2.tag == 595u) {
        std_string_builder_append(l0, 1345u);
    } else if (l2.tag == 601u) {
        std_string_builder_append(l0, 1361u);
    } else if (l2.tag == 594u) {
        std_string_builder_append(l0, 1343u);
    } else if (l2.tag == 648u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_pool_index;
        l3 = vader_bytecode_refer((uint8_t) 5, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_type_id;
        l10 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a20_arr = vader_array_new(53u, 2u, 13u, 730u);
        ((void**) _a20_arr->buf->slots)[_a20_arr->offset + 1u] = l10;
        ((void**) _a20_arr->buf->slots)[_a20_arr->offset + 0u] = l3;
        l3 = (void*) _a20_arr;
        vader_bytecode_printed(l0, l1, 1577u, l3);
    } else if (l2.tag == 755u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_TypeConst_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a21_arr = vader_array_new(53u, 1u, 13u, 730u);
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 0u] = t0;
        l3 = (void*) _a21_arr;
        vader_bytecode_printed(l0, l1, 2491u, l3);
    } else if (l2.tag == 754u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_TypeCheck_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a22_arr = vader_array_new(53u, 1u, 13u, 730u);
        ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = t0;
        l3 = (void*) _a22_arr;
        vader_bytecode_printed(l0, l1, 2494u, l3);
    } else if (l2.tag == 731u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_RefCast_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a23_arr = vader_array_new(53u, 1u, 13u, 730u);
        ((void**) _a23_arr->buf->slots)[_a23_arr->offset + 0u] = t0;
        l3 = (void*) _a23_arr;
        vader_bytecode_printed(l0, l1, 2226u, l3);
    } else if (l2.tag == 734u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_bytecode_Retag_t*) t0)->f_type_id;
        t0 = vader_bytecode_refer((uint8_t) 1, l9);
        vader_array_t* _a24_arr = vader_array_new(53u, 1u, 13u, 730u);
        ((void**) _a24_arr->buf->slots)[_a24_arr->offset + 0u] = t0;
        l3 = (void*) _a24_arr;
        vader_bytecode_printed(l0, l1, 2245u, l3);
    } else if (l2.tag == 768u) {
        std_string_builder_append(l0, 2557u);
    } else if (l2.tag == 647u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_bytecode_Convert_t*) t0)->f_from_name;
        t0 = l2.payload.obj;
        l14 = vader_bytecode_convert_target_name(((vader_struct_vader_bytecode_Convert_t*) t0)->f_target);
        l6 = concat_3(l6, 354u, l14);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 737u) {
        std_string_builder_append(l0, 1940u);
    } else if (l2.tag == 673u) {
        std_string_builder_append(l0, 1830u);
    } else if (l2.tag == 692u) {
        std_string_builder_append(l0, 1850u);
    } else if (l2.tag == 686u) {
        std_string_builder_append(l0, 1844u);
    } else if (l2.tag == 679u) {
        std_string_builder_append(l0, 1836u);
    } else if (l2.tag == 685u) {
        std_string_builder_append(l0, 1847u);
    } else if (l2.tag == 688u) {
        std_string_builder_append(l0, 1846u);
    } else if (l2.tag == 675u) {
        std_string_builder_append(l0, 1832u);
    } else if (l2.tag == 674u) {
        std_string_builder_append(l0, 1831u);
    } else if (l2.tag == 676u) {
        std_string_builder_append(l0, 1833u);
    } else if (l2.tag == 677u) {
        std_string_builder_append(l0, 1834u);
    } else if (l2.tag == 689u) {
        std_string_builder_append(l0, 1848u);
    } else if (l2.tag == 690u) {
        std_string_builder_append(l0, 1849u);
    } else if (l2.tag == 691u) {
        std_string_builder_append(l0, 2521u);
    } else if (l2.tag == 680u) {
        std_string_builder_append(l0, 1838u);
    } else if (l2.tag == 687u) {
        std_string_builder_append(l0, 1845u);
    } else if (l2.tag == 684u) {
        std_string_builder_append(l0, 1842u);
    } else if (l2.tag == 683u) {
        std_string_builder_append(l0, 1841u);
    } else if (l2.tag == 682u) {
        std_string_builder_append(l0, 1840u);
    } else if (l2.tag == 681u) {
        std_string_builder_append(l0, 1839u);
    } else if (l2.tag == 693u) {
        std_string_builder_append(l0, 1852u);
    } else if (l2.tag == 712u) {
        std_string_builder_append(l0, 1872u);
    } else if (l2.tag == 706u) {
        std_string_builder_append(l0, 1865u);
    } else if (l2.tag == 699u) {
        std_string_builder_append(l0, 1858u);
    } else if (l2.tag == 705u) {
        std_string_builder_append(l0, 1868u);
    } else if (l2.tag == 708u) {
        std_string_builder_append(l0, 1867u);
    } else if (l2.tag == 694u) {
        std_string_builder_append(l0, 1853u);
    } else if (l2.tag == 696u) {
        std_string_builder_append(l0, 1855u);
    } else if (l2.tag == 697u) {
        std_string_builder_append(l0, 1856u);
    } else if (l2.tag == 695u) {
        std_string_builder_append(l0, 1854u);
    } else if (l2.tag == 709u) {
        std_string_builder_append(l0, 1870u);
    } else if (l2.tag == 710u) {
        std_string_builder_append(l0, 1871u);
    } else if (l2.tag == 711u) {
        std_string_builder_append(l0, 2531u);
    } else if (l2.tag == 700u) {
        std_string_builder_append(l0, 1860u);
    } else if (l2.tag == 707u) {
        std_string_builder_append(l0, 1866u);
    } else if (l2.tag == 704u) {
        std_string_builder_append(l0, 1864u);
    } else if (l2.tag == 703u) {
        std_string_builder_append(l0, 1863u);
    } else if (l2.tag == 702u) {
        std_string_builder_append(l0, 1862u);
    } else if (l2.tag == 701u) {
        std_string_builder_append(l0, 1861u);
    } else if (l2.tag == 756u) {
        std_string_builder_append(l0, 2513u);
    } else if (l2.tag == 761u) {
        std_string_builder_append(l0, 2519u);
    } else if (l2.tag == 760u) {
        std_string_builder_append(l0, 2518u);
    } else if (l2.tag == 759u) {
        std_string_builder_append(l0, 2517u);
    } else if (l2.tag == 758u) {
        std_string_builder_append(l0, 2516u);
    } else if (l2.tag == 757u) {
        std_string_builder_append(l0, 2515u);
    } else if (l2.tag == 762u) {
        std_string_builder_append(l0, 2523u);
    } else if (l2.tag == 767u) {
        std_string_builder_append(l0, 2529u);
    } else if (l2.tag == 766u) {
        std_string_builder_append(l0, 2528u);
    } else if (l2.tag == 765u) {
        std_string_builder_append(l0, 2527u);
    } else if (l2.tag == 764u) {
        std_string_builder_append(l0, 2526u);
    } else if (l2.tag == 763u) {
        std_string_builder_append(l0, 2525u);
    } else if (l2.tag == 658u) {
        std_string_builder_append(l0, 1709u);
    } else if (l2.tag == 669u) {
        std_string_builder_append(l0, 1720u);
    } else if (l2.tag == 666u) {
        std_string_builder_append(l0, 1717u);
    } else if (l2.tag == 660u) {
        std_string_builder_append(l0, 1711u);
    } else if (l2.tag == 668u) {
        std_string_builder_append(l0, 1719u);
    } else if (l2.tag == 661u) {
        std_string_builder_append(l0, 1712u);
    } else if (l2.tag == 667u) {
        std_string_builder_append(l0, 1718u);
    } else if (l2.tag == 665u) {
        std_string_builder_append(l0, 1716u);
    } else if (l2.tag == 664u) {
        std_string_builder_append(l0, 1715u);
    } else if (l2.tag == 663u) {
        std_string_builder_append(l0, 1714u);
    } else if (l2.tag == 662u) {
        std_string_builder_append(l0, 1713u);
    } else if (l2.tag == 630u) {
        std_string_builder_append(l0, 1403u);
    } else if (l2.tag == 631u) {
        std_string_builder_append(l0, 1404u);
    } else if (l2.tag == 628u) {
        std_string_builder_append(l0, 1401u);
    } else if (l2.tag == 633u) {
        std_string_builder_append(l0, 1406u);
    } else if (l2.tag == 748u) {
        std_string_builder_append(l0, 2371u);
    } else if (l2.tag == 749u) {
        std_string_builder_append(l0, 2373u);
    } else if (l2.tag == 746u) {
        std_string_builder_append(l0, 2369u);
    } else if (l2.tag == 750u) {
        std_string_builder_append(l0, 2374u);
    } else if (l2.tag == 732u) {
        std_string_builder_append(l0, 2227u);
    } else if (l2.tag == 733u) {
        std_string_builder_append(l0, 2228u);
    } else if (l2.tag == 651u) {
        std_string_builder_append(l0, 1594u);
    } else if (l2.tag == 650u) {
        l3 = std_core_new_byte_buffer((size_t) 35);
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l3, l4, 1592u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_bytecode_DeferPopExec_t*) t0)->f_count;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core_write_int(l3, l4, l5);
        l6 = std_core_finish_buffer(l3, l4);
        std_string_builder_append(l0, l6);
    } else if (l2.tag == 636u) {
        std_string_builder_append(l0, 1425u);
    } else if (l2.tag == 721u) {
        std_string_builder_append(l0, 2025u);
    } else if (l2.tag == 716u) {
        std_string_builder_append(l0, 2019u);
    } else if (l2.tag == 717u) {
        std_string_builder_append(l0, 2020u);
    } else if (l2.tag == 715u) {
        std_string_builder_append(l0, 2018u);
    } else if (l2.tag == 745u) {
        std_string_builder_append(l0, 2362u);
    } else if (l2.tag == 740u) {
        std_string_builder_append(l0, 2355u);
    } else if (l2.tag == 741u) {
        std_string_builder_append(l0, 2356u);
    } else if (l2.tag == 739u) {
        std_string_builder_append(l0, 2353u);
    } else if (l2.tag == 719u) {
        std_string_builder_append(l0, 2023u);
    } else if (l2.tag == 720u) {
        std_string_builder_append(l0, 2024u);
    } else if (l2.tag == 718u) {
        std_string_builder_append(l0, 2022u);
    } else if (l2.tag == 743u) {
        std_string_builder_append(l0, 2360u);
    } else if (l2.tag == 744u) {
        std_string_builder_append(l0, 2361u);
    } else if (l2.tag == 742u) {
        std_string_builder_append(l0, 2359u);
    } else if (l2.tag == 728u) {
        std_string_builder_append(l0, 2061u);
    } else if (l2.tag == 637u) {
        std_string_builder_append(l0, 1428u);
    } else if (l2.tag == 638u) {
        std_string_builder_append(l0, 1431u);
    } else if (l2.tag == 670u) {
        std_string_builder_append(l0, 1721u);
    } else if (l2.tag == 626u) {
        std_string_builder_append(l0, 1397u);
    } else if (l2.tag == 657u) {
        std_string_builder_append(l0, 1707u);
    } else {
        if (!(l2.tag == 625u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        std_string_builder_append(l0, 1396u);
    }
    { vader_gc_top = gc_frame.prev; return; }
}
