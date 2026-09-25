#include "bootstrap.split.h"

static vader_box_t vader_bytecode_arith_op(uint8_t l0, vader_string_t l1);
static uint8_t vader_bytecode_array_kind_of_val(uint8_t l0);
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
static vader_box_t vader_bytecode_div_op(uint8_t l0);
static bool vader_bytecode_extend_into_loops(void* l0, void* l1, size_t l2, void* l3);
static void* vader_bytecode_find_loop_ranges(void* l0);
static vader_string_t vader_bytecode_fnv1a_hex(vader_string_t l0);
static bool vader_bytecode_foldable_self_copy(void* l0, size_t l1, size_t l2, void* l3);
static vader_string_t vader_bytecode_int_equals_method(vader_string_t l0);
static vader_box_t vader_bytecode_intrinsic_op_for_mangled(vader_string_t l0);
static bool vader_bytecode_is_display_to_string(vader_string_t l0);
static bool vader_bytecode_is_op_eq_prim(vader_string_t l0);
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
static void vader_bytecode_push_or_assign(void* l0, size_t l1, vader_box_t l2);
static void vader_bytecode_push_scope(void* l0, void* l1, size_t l2, vader_string_t l3, int32_t l4);
static bool vader_bytecode_ranges_overlap(void* l0, void* l1);
static void* vader_bytecode_remap_debug(void* l0, void* l1, size_t l2);
static int32_t vader_bytecode_remap_idx(void* l0, int32_t l1);
static vader_box_t vader_bytecode_remap_push_cache_slot(vader_box_t l0, void* l1);
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
static vader_box_t vader_bytecode_with_remapped_slot(vader_box_t l0, int32_t l1);

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
        if (l1 == 1040u) {
            vader_struct_vader_bytecode_F64Add_t* _a0_obj = (vader_struct_vader_bytecode_F64Add_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Add_t));
            vader_obj_header_init(_a0_obj, 531u);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 2041u) {
            vader_struct_vader_bytecode_F64Sub_t* _a1_obj = (vader_struct_vader_bytecode_F64Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Sub_t));
            vader_obj_header_init(_a1_obj, 542u);
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 1782u) {
            vader_struct_vader_bytecode_F64Mul_t* _a2_obj = (vader_struct_vader_bytecode_F64Mul_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Mul_t));
            vader_obj_header_init(_a2_obj, 539u);
            t1 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_F64Div_t* _a3_obj = (vader_struct_vader_bytecode_F64Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Div_t));
        vader_obj_header_init(_a3_obj, 533u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        if (l1 == 1040u) {
            vader_struct_vader_bytecode_I64Add_t* _a4_obj = (vader_struct_vader_bytecode_I64Add_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Add_t));
            vader_obj_header_init(_a4_obj, 566u);
            t1 = (void*) _a4_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 2041u) {
            vader_struct_vader_bytecode_I64Sub_t* _a5_obj = (vader_struct_vader_bytecode_I64Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Sub_t));
            vader_obj_header_init(_a5_obj, 585u);
            t1 = (void*) _a5_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 1782u) {
            vader_struct_vader_bytecode_I64Mul_t* _a6_obj = (vader_struct_vader_bytecode_I64Mul_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Mul_t));
            vader_obj_header_init(_a6_obj, 579u);
            t1 = (void*) _a6_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_I64Div_t* _a7_obj = (vader_struct_vader_bytecode_I64Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Div_t));
        vader_obj_header_init(_a7_obj, 572u);
        t1 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 1040u) {
        vader_struct_vader_bytecode_I32Add_t* _a8_obj = (vader_struct_vader_bytecode_I32Add_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Add_t));
        vader_obj_header_init(_a8_obj, 546u);
        t1 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 2041u) {
        vader_struct_vader_bytecode_I32Sub_t* _a9_obj = (vader_struct_vader_bytecode_I32Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Sub_t));
        vader_obj_header_init(_a9_obj, 565u);
        t1 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 1782u) {
        vader_struct_vader_bytecode_I32Mul_t* _a10_obj = (vader_struct_vader_bytecode_I32Mul_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Mul_t));
        vader_obj_header_init(_a10_obj, 559u);
        t1 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Div_t* _a11_obj = (vader_struct_vader_bytecode_I32Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Div_t));
    vader_obj_header_init(_a11_obj, 552u);
    t1 = (void*) _a11_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

uint8_t vader_bytecode_array_kind_from_name(vader_string_t l0) {
    uint8_t l1;
    if (l0 == 2155u) {
        l1 = (uint8_t) 1;
    } else if (l0 == 2136u) {
        l1 = (uint8_t) 2;
    } else if (l0 == 2137u) {
        l1 = (uint8_t) 3;
    } else if (l0 == 2146u) {
        l1 = (uint8_t) 4;
    } else if (l0 == 2198u) {
        l1 = (uint8_t) 4;
    } else if (l0 == 1579u) {
        l1 = (uint8_t) 5;
    } else if (l0 == 1534u) {
        l1 = (uint8_t) 6;
    } else if (l0 == 1535u) {
        l1 = (uint8_t) 7;
    } else if (l0 == 1557u) {
        l1 = (uint8_t) 8;
    } else if (l0 == 1654u) {
        l1 = (uint8_t) 8;
    } else if (l0 == 1425u) {
        l1 = (uint8_t) 9;
    } else if (l0 == 1428u) {
        l1 = (uint8_t) 10;
    } else if (l0 == 1254u) {
        l1 = (uint8_t) 11;
    } else if (l0 == 1144u) {
        l1 = (uint8_t) 12;
    } else if (l0 == 1878u) {
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
    } else if (l0 == INT32_C(1)) {
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
    } else if (l0 == INT32_C(13)) {
        l1 = INT32_C(13);
    } else {
        vader_unreachable("unreachable return in vader_bytecode$array_kind_index");
    }
    return l1;
}

uint8_t vader_bytecode_array_kind_of(vader_box_t l0, void* l1) {
    uint8_t l2;
    void* t0;
    bool t1;
    if (l0.tag == 489u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_array_kind_of_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val);
    } else if (l0.tag == 493u) {
        l2 = (uint8_t) 13;
    } else if (l0.tag == 480u) {
        l2 = (uint8_t) 13;
    } else if (l0.tag == 483u) {
        l2 = (uint8_t) 13;
    } else if (l0.tag == 494u) {
        t0 = l0.payload.obj;
        t1 = vader_bytecode_is_ref_only_element(vader_ref_box(t0), l1);
        if (t1) {
            l2 = (uint8_t) 13;
        } else {
            l2 = (uint8_t) 0;
        }
    } else if (l0.tag == 490u) {
        l2 = (uint8_t) 0;
    } else {
        vader_unreachable("unreachable return in vader_bytecode$array_kind_of");
    }
    return l2;
}

static uint8_t vader_bytecode_array_kind_of_val(uint8_t l0) {
    uint8_t l1;
    if (l0 == INT32_C(5)) {
        l1 = (uint8_t) 1;
    } else if (l0 == INT32_C(6)) {
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
    } else if (l0 == INT32_C(19)) {
        l1 = (uint8_t) 0;
    } else {
        vader_unreachable("unreachable return in vader_bytecode$array_kind_of_val");
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
    if (t1 != INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t2 = concat_3(1191u, l0, 851u);
    vader_host_std_abort_panic(t2);
    { vader_gc_top = gc_frame.prev; return; }
}

static uint64_t vader_bytecode_bare_hash(vader_string_t l0) {
    uint64_t l1;
    uint64_t t0;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = std_core_string_Hash_hash_vt(l0);
    t0 = vader_bytecode_mix64((uint64_t) -3750763034362895579, l1);
    { uint64_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    if (l0.tag == 964u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
    } else if (l0.tag == 957u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
    } else if (l0.tag == 954u) {
        l1 = 368u;
    } else if ((l0.tag == 959u || l0.tag == 960u || l0.tag == 961u || l0.tag == 962u || l0.tag == 965u || l0.tag == 969u || l0.tag == 970u || l0.tag == 972u)) {
        l1 = vader_types_display_type(l0);
    } else if ((l0.tag == 955u || l0.tag == 956u || l0.tag == 958u || l0.tag == 966u || l0.tag == 967u || l0.tag == 968u || l0.tag == 971u)) {
        l1 = 0u;
    } else {
        vader_unreachable("unreachable return in vader_bytecode$bare_intern_name");
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
    vader_obj_header_init(_a0_obj, 487u);
    _a0_obj->f_body = l1;
    _a0_obj->f_jump_table = l2;
    _a0_obj->f_debug = l3;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

size_t vader_bytecode_bc_result_arity(void* l0) {
    bool l1;
    size_t l2;
    size_t t0;
    vader_box_t t1;
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results)->length;
    if (t0 == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 196u);
        l1 = ((int32_t) t1.payload.i) == INT32_C(16);
    } else {
        l1 = false;
    }
    if (l1) {
        l2 = (size_t) 0;
    } else {
        l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results)->length;
    }
    return l2;
}

uint8_t vader_bytecode_bc_single_result(void* l0) {
    void* l1 = NULL;
    size_t l2;
    uint64_t l3;
    size_t t0;
    int64_t t1;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t3 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 16; }
    }
    t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results)->length;
    if ((t0 > INT64_C(1))) {
        l1 = std_core_new_byte_buffer((size_t) 127);
        l2 = (size_t) 0;
        l2 = std_core_write_string_at(l1, l2, 1194u);
        t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results)->length;
        t1 = ((int64_t) (size_t) t0);
        l3 = (uint64_t) (int64_t) t1;
        l2 = std_core_write_unsigned(l1, l2, l3);
        l2 = std_core_write_string_at(l1, l2, 113u);
        t2 = std_core_finish_buffer(l1, l2);
        vader_host_std_abort_panic(t2);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_results);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t3 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 196u);
    { uint8_t __vret = ((uint8_t) t3.payload.i); vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_bytecode_bc_single_result_type(void* l0) {
    void* l1 = NULL;
    size_t l2;
    uint64_t l3;
    size_t t0;
    int64_t t1;
    vader_string_t t2 = 0;
    int32_t t3;
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
    if ((t0 > INT64_C(1))) {
        l1 = std_core_new_byte_buffer((size_t) 132);
        l2 = (size_t) 0;
        l2 = std_core_write_string_at(l1, l2, 1193u);
        t0 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_result_types)->length;
        t1 = ((int64_t) (size_t) t0);
        l3 = (uint64_t) (int64_t) t1;
        l2 = std_core_write_unsigned(l1, l2, l3);
        l2 = std_core_write_string_at(l1, l2, 113u);
        t2 = std_core_finish_buffer(l1, l2);
        vader_host_std_abort_panic(t2);
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) l0)->f_result_types);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
    { int32_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
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
        { vader_gc_top = gc_frame.prev; return 353u; }
    }
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    l6 = l5;
    if (l5.tag == 489u) {
        l8 = std_core_new_byte_buffer((size_t) 22);
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l8, l3, 1840u);
        t1 = l6.payload.obj;
        l9 = ((int64_t) (int32_t) ((int32_t) (uint8_t) ((vader_struct_vader_bytecode_BcPrimitive_t*) t1)->f_val));
        l3 = std_core_write_int(l8, l3, l9);
        l7 = std_core_finish_buffer(l8, l3);
    } else if (l5.tag == 493u) {
        t1 = l6.payload.obj;
        l10 = ((vader_struct_vader_bytecode_BcStruct_t*) t1)->f_name;
        l7 = concat_2(1907u, l10);
    } else if (l5.tag == 490u) {
        t1 = l6.payload.obj;
        l10 = ((vader_struct_vader_bytecode_BcRef_t*) t1)->f_trait_name;
        l7 = concat_2(1866u, l10);
    } else if (l5.tag == 480u) {
        t1 = l6.payload.obj;
        l11 = ((vader_struct_vader_bytecode_BcArray_t*) t1)->f_element;
        l10 = vader_bytecode_bc_type_key(l0, l11);
        l7 = concat_3(1036u, l10, 349u);
    } else if (l5.tag == 494u) {
        t1 = l6.payload.obj;
        l8 = ((vader_struct_vader_bytecode_BcUnion_t*) t1)->f_variants;
        l10 = vader_bytecode_key_join(l0, l8, 2375u);
        l7 = concat_3(2156u, l10, 349u);
    } else if (l5.tag == 483u) {
        t1 = l6.payload.obj;
        l8 = ((vader_struct_vader_bytecode_BcFn_t*) t1)->f_params;
        l10 = vader_bytecode_key_join(l0, l8, 2375u);
        t1 = l6.payload.obj;
        l11 = ((vader_struct_vader_bytecode_BcFn_t*) t1)->f_return_type;
        l12 = vader_bytecode_bc_type_key(l0, l11);
        l7 = concat_4(1442u, l10, 225u, l12);
    } else {
        vader_unreachable("unreachable return in vader_bytecode$bc_type_key");
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
    if (l0.tag == 964u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        t2 = vader_bytecode_val_type_of_primitive_name(t1);
        vader_struct_vader_bytecode_BcPrimitive_t* _a0_obj = (vader_struct_vader_bytecode_BcPrimitive_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPrimitive_t));
        vader_obj_header_init(_a0_obj, 489u);
        _a0_obj->f_val = t2;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 957u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
        t2 = vader_bytecode_val_type_of_primitive_name(t1);
        vader_struct_vader_bytecode_BcPrimitive_t* _a1_obj = (vader_struct_vader_bytecode_BcPrimitive_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPrimitive_t));
        vader_obj_header_init(_a1_obj, 489u);
        _a1_obj->f_val = t2;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 956u) {
        t0 = l0.payload.obj;
        t3 = vader_bytecode_bc_type_of_with_ctx(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing, l1, l2);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 966u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_name;
        vader_struct_vader_bytecode_BcRef_t* _a2_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a2_obj, 490u);
        _a2_obj->f_trait_name = t1;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 967u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol)->f_name;
        vader_struct_vader_bytecode_BcRef_t* _a3_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a3_obj, 490u);
        _a3_obj->f_trait_name = t1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 955u) {
        t0 = l0.payload.obj;
        t4 = vader_bytecode_intern_type(((vader_struct_vader_types_ArrayType_t*) t0)->f_element, l1);
        vader_struct_vader_bytecode_BcArray_t* _a4_obj = (vader_struct_vader_bytecode_BcArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcArray_t));
        vader_obj_header_init(_a4_obj, 480u);
        _a4_obj->f_element = t4;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 971u) {
        vader_array_t* _a5_arr = vader_array_new(9u, 0u, 7u, 193u);
        l3 = (void*) _a5_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        l5 = ((vader_array_t*) l4)->length;
        l6 = (size_t) 0;
        {
            loop_80: {
                if ((l6 < l5)) {
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
                    t3 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
                    l7 = vader_bytecode_intern_type(t3, l1);
                    vader_array_push_i32((vader_array_t*) l3, l7);
                    t5 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t5;
                    goto loop_80;
                }
            }
        }
        vader_struct_vader_bytecode_BcUnion_t* _a7_obj = (vader_struct_vader_bytecode_BcUnion_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcUnion_t));
        vader_obj_header_init(_a7_obj, 494u);
        _a7_obj->f_variants = l3;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 958u) {
        vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 193u);
        l3 = (void*) _a8_arr;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
        l5 = ((vader_array_t*) l4)->length;
        l6 = (size_t) 0;
        {
            loop_120: {
                if ((l6 < l5)) {
                    vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l6)
                    t3 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l6);
                    l7 = vader_bytecode_intern_type(t3, l1);
                    vader_array_push_i32((vader_array_t*) l3, l7);
                    t5 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t5;
                    goto loop_120;
                }
            }
        }
        t0 = l0.payload.obj;
        l7 = vader_bytecode_intern_type(((vader_struct_vader_types_FnType_t*) t0)->f_return_type, l1);
        vader_struct_vader_bytecode_BcFn_t* _a10_obj = (vader_struct_vader_bytecode_BcFn_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFn_t));
        vader_obj_header_init(_a10_obj, 483u);
        _a10_obj->f_params = l3;
        _a10_obj->f_return_type = l7;
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 968u) {
        vader_array_t* _a11_arr = vader_array_new(37u, 0u, 13u, 482u);
        l3 = (void*) _a11_arr;
        t0 = l0.payload.obj;
        l5 = ((vader_array_t*) ((vader_struct_vader_types_TupleType_t*) t0)->f_elements)->length;
        l6 = (size_t) 0;
        {
            loop_166: {
                if ((l6 < l5)) {
                    l4 = std_core_new_byte_buffer((size_t) 21);
                    l8 = (size_t) 0;
                    l8 = std_core_write_string_at(l4, l8, 717u);
                    t5 = ((int64_t) (size_t) l6);
                    l9 = (uint64_t) (int64_t) t5;
                    l8 = std_core_write_unsigned(l4, l8, l9);
                    l10 = std_core_finish_buffer(l4, l8);
                    t0 = l0.payload.obj;
                    vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_types_TupleType_t*) t0)->f_elements);
                    VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l6)
                    t3 = vader_array_ref_load_box(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l6);
                    l7 = vader_bytecode_intern_type(t3, l1);
                    vader_struct_vader_bytecode_BcField_t* _a13_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
                    vader_obj_header_init(_a13_obj, 482u);
                    _a13_obj->f_name = l10;
                    _a13_obj->f_type_index = l7;
                    l11 = (void*) _a13_obj;
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l11));
                    t5 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t5;
                    goto loop_166;
                }
            }
        }
        t0 = l0.payload.obj;
        l10 = vader_bytecode_tuple_shape_name(((vader_struct_vader_types_TupleType_t*) t0)->f_elements);
        l10 = concat_2(733u, l10);
        l7 = -(INT32_C(1));
        vader_struct_vader_bytecode_BcStruct_t* _a14_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
        vader_obj_header_init(_a14_obj, 493u);
        _a14_obj->f_name = l10;
        _a14_obj->f_fields = l3;
        _a14_obj->f_c_name = 0u;
        _a14_obj->f_symbol_id = l7;
        t0 = (void*) _a14_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 970u) {
        vader_struct_vader_bytecode_BcRef_t* _a15_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a15_obj, 490u);
        _a15_obj->f_trait_name = 0u;
        t0 = (void*) _a15_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 969u) {
        vader_struct_vader_bytecode_BcRef_t* _a16_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a16_obj, 490u);
        _a16_obj->f_trait_name = 0u;
        t0 = (void*) _a16_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 965u) {
        vader_struct_vader_bytecode_BcRef_t* _a17_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a17_obj, 490u);
        _a17_obj->f_trait_name = 0u;
        t0 = (void*) _a17_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 972u) {
        vader_struct_vader_bytecode_BcRef_t* _a18_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a18_obj, 490u);
        _a18_obj->f_trait_name = 0u;
        t0 = (void*) _a18_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 961u) {
        vader_struct_vader_bytecode_BcRef_t* _a19_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a19_obj, 490u);
        _a19_obj->f_trait_name = 0u;
        t0 = (void*) _a19_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 959u) {
        vader_struct_vader_bytecode_BcRef_t* _a20_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a20_obj, 490u);
        _a20_obj->f_trait_name = 0u;
        t0 = (void*) _a20_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 960u) {
        vader_struct_vader_bytecode_BcRef_t* _a21_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a21_obj, 490u);
        _a21_obj->f_trait_name = 0u;
        t0 = (void*) _a21_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 962u) {
        vader_struct_vader_bytecode_BcRef_t* _a22_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a22_obj, 490u);
        _a22_obj->f_trait_name = 0u;
        t0 = (void*) _a22_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 954u) {
        vader_struct_vader_bytecode_BcRef_t* _a23_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a23_obj, 490u);
        _a23_obj->f_trait_name = 0u;
        t0 = (void*) _a23_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_bytecode$bc_type_of_with_ctx");
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
        l2 = vader_bytecode_arith_op(l1, 1040u);
    } else if (l0 == INT32_C(1)) {
        l2 = vader_bytecode_arith_op(l1, 2041u);
    } else if (l0 == INT32_C(2)) {
        l2 = vader_bytecode_arith_op(l1, 1782u);
    } else if (l0 == INT32_C(3)) {
        l2 = vader_bytecode_div_op(l1);
    } else if (l0 == INT32_C(4)) {
        l2 = vader_bytecode_mod_op(l1);
    } else if (l0 == INT32_C(5)) {
        l2 = vader_bytecode_shl_op(l1);
    } else if (l0 == INT32_C(6)) {
        l2 = vader_bytecode_shr_op(l1);
    } else if (l0 == INT32_C(7)) {
        l2 = vader_bytecode_bit_op(l1, 1058u);
    } else if (l0 == INT32_C(8)) {
        l2 = vader_bytecode_bit_op(l1, 1833u);
    } else if (l0 == INT32_C(9)) {
        l2 = vader_bytecode_bit_op(l1, 2363u);
    } else if (l0 == INT32_C(10)) {
        vader_struct_vader_bytecode_BoolAnd_t* _a0_obj = (vader_struct_vader_bytecode_BoolAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolAnd_t));
        vader_obj_header_init(_a0_obj, 502u);
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(11)) {
        vader_struct_vader_bytecode_BoolOr_t* _a1_obj = (vader_struct_vader_bytecode_BoolOr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolOr_t));
        vader_obj_header_init(_a1_obj, 507u);
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
    } else if (l0 == INT32_C(17)) {
        l2 = vader_bytecode_cmp_ge(l1);
    } else {
        vader_unreachable("unreachable return in vader_bytecode$binary_op_for");
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
        if (l1 == 1058u) {
            vader_struct_vader_bytecode_I64BitAnd_t* _a0_obj = (vader_struct_vader_bytecode_I64BitAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitAnd_t));
            vader_obj_header_init(_a0_obj, 567u);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 1833u) {
            vader_struct_vader_bytecode_I64BitOr_t* _a1_obj = (vader_struct_vader_bytecode_I64BitOr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitOr_t));
            vader_obj_header_init(_a1_obj, 569u);
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_I64BitXor_t* _a2_obj = (vader_struct_vader_bytecode_I64BitXor_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitXor_t));
        vader_obj_header_init(_a2_obj, 570u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 1058u) {
        vader_struct_vader_bytecode_I32BitAnd_t* _a3_obj = (vader_struct_vader_bytecode_I32BitAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitAnd_t));
        vader_obj_header_init(_a3_obj, 547u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 1833u) {
        vader_struct_vader_bytecode_I32BitOr_t* _a4_obj = (vader_struct_vader_bytecode_I32BitOr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitOr_t));
        vader_obj_header_init(_a4_obj, 549u);
        t1 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32BitXor_t* _a5_obj = (vader_struct_vader_bytecode_I32BitXor_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitXor_t));
    vader_obj_header_init(_a5_obj, 550u);
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
    if (t0) {
        vader_struct_vader_bytecode_I64BitNot_t* _a0_obj = (vader_struct_vader_bytecode_I64BitNot_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitNot_t));
        vader_obj_header_init(_a0_obj, 568u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32BitNot_t* _a1_obj = (vader_struct_vader_bytecode_I32BitNot_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitNot_t));
    vader_obj_header_init(_a1_obj, 548u);
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
    vader_array_t* _a0_arr = vader_array_new(138u, 0u, 13u, 1148u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_params)->length;
    l4 = (size_t) 0;
    {
        loop_9: {
            if ((l4 < l3)) {
                vader_struct_vader_bytecode_LocalGet_t* _a1_obj = (vader_struct_vader_bytecode_LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalGet_t));
                vader_obj_header_init(_a1_obj, 596u);
                _a1_obj->f_slot = ((int32_t) (size_t) l4);
                l5 = (void*) _a1_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_9;
            }
        }
    }
    t1 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
    l6 = vader_bytecode_intrinsic_op_for_mangled(t1);
    if (!(l6.tag == 0u)) {
        vader_array_push((vader_array_t*) l2, l6);
    } else {
        vader_struct_vader_bytecode_CallImport_t* _a2_obj = (vader_struct_vader_bytecode_CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallImport_t));
        vader_obj_header_init(_a2_obj, 517u);
        _a2_obj->f_index = l1;
        l5 = (void*) _a2_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
    }
    vader_struct_vader_bytecode_Return_t* _a3_obj = (vader_struct_vader_bytecode_Return_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Return_t));
    vader_obj_header_init(_a3_obj, 606u);
    l5 = (void*) _a3_obj;
    vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_c_field_align_at(void* l0, void* l1, int32_t l2) {
    vader_box_t l3;
    int64_t l4;
    void* l5;
    void* l8;
    size_t l6, l7;
    int32_t l9;
    uint8_t t0;
    int32_t t1;
    vader_box_t t2;
    void* t3;
    int64_t t4;
    l3 = vader_bytecode_c_field_val_type(l0, l1);
    if (!(l3.tag == 0u)) {
        t0 = ((uint8_t) l3.payload.i);
        t1 = vader_bytecode_size_of_val_type(t0);
        t2 = vader_box_i64(194u, ((int64_t) (int32_t) t1));
        return t2;
    }
    if ((l2 >= INT32_C(16))) {
        t2 = vader_box_obj(0u, NULL);
        return t2;
    }
    l3 = vader_bytecode_nested_mirror(l0, l1);
    if (l3.tag == 0u) {
        t2 = vader_box_obj(0u, NULL);
        return t2;
    }
    l4 = INT64_C(1);
    t3 = l3.payload.obj;
    l5 = ((vader_struct_vader_bytecode_BcStruct_t*) t3)->f_fields;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    {
        loop_43: {
            if ((l7 < l6)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
                l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
                l9 = (l2 + INT32_C(1));
                l3 = vader_bytecode_c_field_align_at(l8, l1, l9);
                if (l3.tag == 0u) {
                    t2 = vader_box_obj(0u, NULL);
                    return t2;
                }
                t4 = ((int64_t) l3.payload.i);
                if ((t4 > l4)) {
                    l4 = ((int64_t) l3.payload.i);
                }
                t4 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t4;
                goto loop_43;
            }
        }
    }
    t2 = vader_box_i64(194u, l4);
    return t2;
}

vader_box_t vader_bytecode_c_field_val_type(void* l0, void* l1) {
    bool l2;
    size_t l3, l4;
    vader_box_t l5;
    int32_t t0;
    int64_t t1;
    vader_box_t t2;
    void* t3;
    t0 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_type_index;
    if ((t0 < INT32_C(0))) {
        l2 = true;
    } else {
        t0 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_type_index;
        t1 = ((int64_t) (int32_t) t0);
        l3 = (size_t) (int64_t) t1;
        l4 = ((vader_array_t*) l1)->length;
        l2 = (l3 >= l4);
    }
    if (l2) {
        t2 = vader_box_obj(0u, NULL);
        return t2;
    }
    t0 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_type_index;
    t1 = ((int64_t) (int32_t) t0);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l5.tag == 489u) {
        t3 = l5.payload.obj;
        t2 = vader_box_i32(196u, (int32_t)(uint32_t) ((vader_struct_vader_bytecode_BcPrimitive_t*) t3)->f_val);
        return t2;
    }
    t2 = vader_box_obj(0u, NULL);
    return t2;
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
    void* t3 = NULL;
    int64_t t4;
    vader_box_t* gc_roots[2] = { &l3, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_bytecode_c_field_val_type(l0, l1);
    if (!(l3.tag == 0u)) {
        t0 = ((uint8_t) l3.payload.i);
        t1 = vader_bytecode_size_of_val_type(t0);
        t2 = vader_box_i64(194u, ((int64_t) (int32_t) t1));
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l2 >= INT32_C(16))) {
        t2 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_bytecode_nested_mirror(l0, l1);
    if (l3.tag == 0u) {
        t2 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = l3.payload.obj;
    l4 = ((vader_struct_vader_bytecode_BcStruct_t*) t3)->f_fields;
    l5 = (l2 + INT32_C(1));
    l4 = vader_bytecode_c_struct_layout_at(l4, l1, l5);
    if (!(((vader_struct_vader_bytecode_CLayout_t*) l4)->f_unknown_field.tag == 0u)) {
        t2 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = ((vader_struct_vader_bytecode_CLayout_t*) l4)->f_size;
    t2 = vader_box_i64(194u, t4);
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
    {
        loop_10: {
            if ((l4 < l3)) {
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
                    l1 = concat_2(l1, 717u);
                    l2 = true;
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_10;
            }
        }
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
    vader_array_t* _a0_arr = vader_array_new(10u, 0u, 8u, 194u);
    l3 = (void*) _a0_arr;
    l4 = INT64_C(0);
    l5 = INT64_C(1);
    l6 = vader_box_obj(0u, NULL);
    l7 = l0;
    l8 = ((vader_array_t*) l7)->length;
    l9 = (size_t) 0;
    {
        loop_15: {
            if ((l9 < l8)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
                l10 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
                l11 = vader_bytecode_c_field_width_at(l10, l1, l2);
                l12 = vader_bytecode_c_field_align_at(l10, l1, l2);
                if (l11.tag == 0u) {
                    if (l6.tag == 0u) {
                        t0 = ((vader_struct_vader_bytecode_BcField_t*) l10)->f_name;
                        l6 = vader_box_string(190u, t0);
                    }
                    vader_array_push_i64((vader_array_t*) l3, l4);
                    t1 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t1;
                    goto loop_15;
                }
                if (l12.tag == 0u) {
                    if (l6.tag == 0u) {
                        t0 = ((vader_struct_vader_bytecode_BcField_t*) l10)->f_name;
                        l6 = vader_box_string(190u, t0);
                    }
                    vader_array_push_i64((vader_array_t*) l3, l4);
                    t1 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t1;
                    goto loop_15;
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
                goto loop_15;
            }
        }
    }
    l13 = vader_mod_i64(l4, l5);
    if (l13 == INT64_C(0)) {
        l14 = l4;
    } else {
        l14 = ((l4 + l5) - l13);
    }
    vader_struct_vader_bytecode_CLayout_t* _a2_obj = (vader_struct_vader_bytecode_CLayout_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CLayout_t));
    vader_obj_header_init(_a2_obj, 515u);
    _a2_obj->f_offsets = l3;
    _a2_obj->f_size = l14;
    _a2_obj->f_unknown_field = l6;
    t2 = (void*) _a2_obj;
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
        vader_obj_header_init(_a0_obj, 504u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(14)) {
        vader_struct_vader_bytecode_StringEq_t* _a1_obj = (vader_struct_vader_bytecode_StringEq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringEq_t));
        vader_obj_header_init(_a1_obj, 618u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_float_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_F64Eq_t* _a2_obj = (vader_struct_vader_bytecode_F64Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Eq_t));
        vader_obj_header_init(_a2_obj, 534u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_64_bit_int_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_I64Eq_t* _a3_obj = (vader_struct_vader_bytecode_I64Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Eq_t));
        vader_obj_header_init(_a3_obj, 573u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_ref_class(l0);
    if (t1) {
        vader_struct_vader_bytecode_RefEq_t* _a4_obj = (vader_struct_vader_bytecode_RefEq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefEq_t));
        vader_obj_header_init(_a4_obj, 604u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Eq_t* _a5_obj = (vader_struct_vader_bytecode_I32Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Eq_t));
    vader_obj_header_init(_a5_obj, 553u);
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
        vader_obj_header_init(_a0_obj, 535u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Ge_t* _a1_obj = (vader_struct_vader_bytecode_U64Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Ge_t));
        vader_obj_header_init(_a1_obj, 633u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Ge_t* _a2_obj = (vader_struct_vader_bytecode_U32Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Ge_t));
        vader_obj_header_init(_a2_obj, 627u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        vader_struct_vader_bytecode_I64Ge_t* _a3_obj = (vader_struct_vader_bytecode_I64Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Ge_t));
        vader_obj_header_init(_a3_obj, 574u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Ge_t* _a4_obj = (vader_struct_vader_bytecode_I32Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Ge_t));
    vader_obj_header_init(_a4_obj, 554u);
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
        vader_obj_header_init(_a0_obj, 536u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Gt_t* _a1_obj = (vader_struct_vader_bytecode_U64Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Gt_t));
        vader_obj_header_init(_a1_obj, 634u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Gt_t* _a2_obj = (vader_struct_vader_bytecode_U32Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Gt_t));
        vader_obj_header_init(_a2_obj, 628u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        vader_struct_vader_bytecode_I64Gt_t* _a3_obj = (vader_struct_vader_bytecode_I64Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Gt_t));
        vader_obj_header_init(_a3_obj, 575u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Gt_t* _a4_obj = (vader_struct_vader_bytecode_I32Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Gt_t));
    vader_obj_header_init(_a4_obj, 555u);
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
        vader_obj_header_init(_a0_obj, 537u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Le_t* _a1_obj = (vader_struct_vader_bytecode_U64Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Le_t));
        vader_obj_header_init(_a1_obj, 635u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Le_t* _a2_obj = (vader_struct_vader_bytecode_U32Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Le_t));
        vader_obj_header_init(_a2_obj, 629u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        vader_struct_vader_bytecode_I64Le_t* _a3_obj = (vader_struct_vader_bytecode_I64Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Le_t));
        vader_obj_header_init(_a3_obj, 576u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Le_t* _a4_obj = (vader_struct_vader_bytecode_I32Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Le_t));
    vader_obj_header_init(_a4_obj, 556u);
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
        vader_obj_header_init(_a0_obj, 538u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Lt_t* _a1_obj = (vader_struct_vader_bytecode_U64Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Lt_t));
        vader_obj_header_init(_a1_obj, 636u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Lt_t* _a2_obj = (vader_struct_vader_bytecode_U32Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Lt_t));
        vader_obj_header_init(_a2_obj, 630u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        vader_struct_vader_bytecode_I64Lt_t* _a3_obj = (vader_struct_vader_bytecode_I64Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Lt_t));
        vader_obj_header_init(_a3_obj, 577u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Lt_t* _a4_obj = (vader_struct_vader_bytecode_I32Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Lt_t));
    vader_obj_header_init(_a4_obj, 557u);
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
        vader_obj_header_init(_a0_obj, 505u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(14)) {
        vader_struct_vader_bytecode_StringNe_t* _a1_obj = (vader_struct_vader_bytecode_StringNe_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringNe_t));
        vader_obj_header_init(_a1_obj, 619u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_float_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_F64Ne_t* _a2_obj = (vader_struct_vader_bytecode_F64Ne_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Ne_t));
        vader_obj_header_init(_a2_obj, 540u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_64_bit_int_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_I64Ne_t* _a3_obj = (vader_struct_vader_bytecode_I64Ne_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Ne_t));
        vader_obj_header_init(_a3_obj, 580u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_ref_class(l0);
    if (t1) {
        vader_struct_vader_bytecode_RefNe_t* _a4_obj = (vader_struct_vader_bytecode_RefNe_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefNe_t));
        vader_obj_header_init(_a4_obj, 605u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Ne_t* _a5_obj = (vader_struct_vader_bytecode_I32Ne_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Ne_t));
    vader_obj_header_init(_a5_obj, 560u);
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_coalesce_slots(void* l0) {
    size_t l1, l2, l4, l7, l11, l21, l22, l23, l24, l26, l28, l33;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l25 = NULL;
    void* l27 = NULL;
    void* l29 = NULL;
    void* l34 = NULL;
    int32_t l8, l9, l12, l13, l14, l30, l31, l32;
    bool l16;
    uint8_t l20;
    vader_box_t l35 = vader_box_null(), l36 = vader_box_null(), l37 = vader_box_null();
    vader_string_t l38 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    bool t2;
    void* t3 = NULL;
    size_t t4;
    vader_box_t* gc_roots[4] = { &l35, &l36, &l37, &t1 };
    void** gc_raw_roots[14] = {
        &l0, &l3, &l5, &l6, &l10, &l15, &l17, &l18, &l19, &l25, &l27, &l29, &l34, &t3,
    };
    vader_string_t* gc_atom_roots[1] = { &l38 };
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
    vader_array_t* _a0_arr = vader_array_new(42u, 0u, 13u, 609u);
    l5 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 188u);
    l6 = (void*) _a1_arr;
    l7 = (size_t) 0;
    {
        loop_28: {
            if ((l7 < l2)) {
                l8 = -(INT32_C(1));
                l9 = -(INT32_C(1));
                vader_struct_vader_bytecode_SlotRange_t* _a2_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                vader_obj_header_init(_a2_obj, 609u);
                _a2_obj->f_first = l8;
                _a2_obj->f_last = l9;
                l10 = (void*) _a2_obj;
                vader_array_push((vader_array_t*) l5, vader_ref_box(l10));
                vader_array_push_bool((vader_array_t*) l6, false);
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                goto loop_28;
            }
        }
    }
    l7 = (size_t) 0;
    {
        loop_60: {
            if ((l7 < l4)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
                t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
                l8 = vader_bytecode_slot_touched(t1);
                if ((l8 >= INT32_C(0))) {
                    t0 = ((int64_t) (int32_t) l8);
                    l11 = (size_t) (int64_t) t0;
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
                    t1 = vader_box_bool(188u, ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l11]);
                    t2 = t1.payload.b;
                    if (!(t2)) {
                        l9 = ((int32_t) (size_t) l7);
                        l12 = ((int32_t) (size_t) l7);
                        vader_struct_vader_bytecode_SlotRange_t* _a5_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                        vader_obj_header_init(_a5_obj, 609u);
                        _a5_obj->f_first = l9;
                        _a5_obj->f_last = l12;
                        l10 = (void*) _a5_obj;
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
                        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l11)
                        vader_array_ref_store(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l11, l10);
                        VADER_WRITE_BARRIER(_a6_slotarr->buf);
                        vader_array_t* _a7_slotarr = ((vader_array_t*) l6);
                        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l11)
                        ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l11] = (uint8_t) true;
                    } else {
                        vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
                        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l11)
                        t3 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l11);
                        l13 = ((vader_struct_vader_bytecode_SlotRange_t*) t3)->f_first;
                        l14 = ((int32_t) (size_t) l7);
                        vader_struct_vader_bytecode_SlotRange_t* _a9_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                        vader_obj_header_init(_a9_obj, 609u);
                        _a9_obj->f_first = l13;
                        _a9_obj->f_last = l14;
                        l15 = (void*) _a9_obj;
                        vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
                        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l11)
                        vader_array_ref_store(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l11, l15);
                        VADER_WRITE_BARRIER(_a10_slotarr->buf);
                    }
                }
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                goto loop_60;
            }
        }
    }
    l10 = vader_bytecode_find_loop_ranges(l3);
    t4 = ((vader_array_t*) l10)->length;
    if ((t4 > INT64_C(0))) {
        l16 = true;
        {
            loop_138: {
                if (l16) {
                    l16 = vader_bytecode_extend_into_loops(l5, l6, l2, l10);
                    goto loop_138;
                }
            }
        }
    }
    l7 = (size_t) 0;
    {
        loop_155: {
            if ((l7 < l1)) {
                l8 = ((int32_t) (size_t) l4);
                vader_struct_vader_bytecode_SlotRange_t* _a11_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                vader_obj_header_init(_a11_obj, 609u);
                _a11_obj->f_first = INT32_C(0);
                _a11_obj->f_last = l8;
                l10 = (void*) _a11_obj;
                vader_array_t* _a12_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l7)
                vader_array_ref_store(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l7, l10);
                VADER_WRITE_BARRIER(_a12_slotarr->buf);
                vader_array_t* _a13_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l7)
                ((uint8_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l7] = (uint8_t) true;
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                goto loop_155;
            }
        }
    }
    vader_array_t* _a14_arr = vader_array_new(40u, 0u, 13u, 486u);
    l10 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(9u, 0u, 7u, 193u);
    l15 = (void*) _a15_arr;
    l7 = (size_t) 0;
    {
        vader_array_t* _pc190_hdr = (vader_array_t*) l15;
        size_t _pc190_len = _pc190_hdr->length;
        size_t _pc190_cap = (_pc190_hdr->offset == 0 && !vader_array_is_borrowed(_pc190_hdr) && _pc190_hdr->length >= _pc190_hdr->buf->length) ? _pc190_hdr->capacity : (size_t) 0;
        void* _pc190_slots = _pc190_hdr->buf->slots;
        loop_190: {
            if ((l7 < l2)) {
                l8 = -(INT32_C(1));
                if (VADER_LIKELY(_pc190_len < _pc190_cap)) {
                    ((int32_t*) _pc190_slots)[_pc190_len] = (int32_t) (l8);
                    _pc190_len += 1;
                } else {
                    _pc190_hdr->length = _pc190_len;
                    if (_pc190_hdr->buf->length < _pc190_len) {
                        _pc190_hdr->buf->length = _pc190_len;
                    }
                    vader_array_push_i32((vader_array_t*) l15, l8);
                    _pc190_hdr = (vader_array_t*) l15;
                    _pc190_len = _pc190_hdr->length;
                    _pc190_cap = (_pc190_hdr->offset == 0 && !vader_array_is_borrowed(_pc190_hdr) && _pc190_hdr->length >= _pc190_hdr->buf->length) ? _pc190_hdr->capacity : (size_t) 0;
                    _pc190_slots = _pc190_hdr->buf->slots;
                }
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                goto loop_190;
            }
            _pc190_hdr->length = _pc190_len;
            if (_pc190_hdr->buf->length < _pc190_len) {
                _pc190_hdr->buf->length = _pc190_len;
            }
        }
    }
    l7 = (size_t) 0;
    {
        loop_212: {
            if ((l7 < l1)) {
                l8 = ((int32_t) (size_t) l7);
                vader_array_t* _a16_slotarr = ((vader_array_t*) l15);
                VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l7)
                ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l7] = (int32_t) l8;
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                goto loop_212;
            }
        }
    }
    vader_array_t* _a17_arr = vader_array_new(42u, 0u, 13u, 609u);
    l17 = (void*) _a17_arr;
    l7 = (size_t) 0;
    {
        loop_237: {
            if ((l7 < l1)) {
                vader_array_t* _a18_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l7)
                l18 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l7);
                vader_array_push((vader_array_t*) l17, vader_ref_box(l18));
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                goto loop_237;
            }
        }
    }
    l7 = l1;
    {
        loop_260: {
            if ((l7 < l2)) {
                vader_array_t* _a19_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l7)
                t1 = vader_box_bool(188u, ((uint8_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l7]);
                t2 = t1.payload.b;
                if (!(t2)) {
                    l8 = -(INT32_C(1));
                    vader_array_t* _a20_slotarr = ((vader_array_t*) l15);
                    VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l7)
                    ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l7] = (int32_t) l8;
                    t0 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t0;
                    goto loop_260;
                }
                vader_array_t* _a21_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l7)
                l18 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l7);
                l19 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
                t0 = (l7 - l1);
                l11 = (size_t) (int64_t) t0;
                vader_array_t* _a22_slotarr = ((vader_array_t*) l19);
                VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l11)
                t3 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l11);
                l20 = ((vader_struct_vader_bytecode_BcLocal_t*) t3)->f_val;
                l9 = -(INT32_C(1));
                vader_array_t* _a23_slotarr = ((vader_array_t*) l17);
                VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                l21 = ((vader_array_t*) l17)->length;
                l22 = l1;
                {
                    loop_308: {
                        if ((l22 < l21)) {
                            t0 = (l22 - l1);
                            l23 = (size_t) (int64_t) t0;
                            vader_array_t* _a24_slotarr = ((vader_array_t*) l10);
                            VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l23)
                            t3 = vader_array_ref_load_obj(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l23);
                            if (((vader_struct_vader_bytecode_BcLocal_t*) t3)->f_val == l20) {
                                VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l22)
                                t3 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l22);
                                t2 = vader_bytecode_ranges_overlap(t3, l18);
                                if (!(t2)) {
                                    l9 = ((int32_t) (size_t) l22);
                                } else {
                                    l24 = (size_t) 1;
                                    t0 = (l22 + l24);
                                    l22 = (size_t) (int64_t) t0;
                                    goto loop_308;
                                }
                            } else {
                                l24 = (size_t) 1;
                                t0 = (l22 + l24);
                                l22 = (size_t) (int64_t) t0;
                                goto loop_308;
                            }
                        }
                    }
                }
                if ((l9 < INT32_C(0))) {
                    t4 = ((vader_array_t*) l17)->length;
                    l9 = ((int32_t) (size_t) t4);
                    vader_array_push((vader_array_t*) l17, vader_ref_box(l18));
                    l25 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
                    t0 = (l7 - l1);
                    l26 = (size_t) (int64_t) t0;
                    vader_array_t* _a25_slotarr = ((vader_array_t*) l25);
                    VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l26)
                    l27 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l26);
                    vader_array_push((vader_array_t*) l10, vader_ref_box(l27));
                } else {
                    t0 = ((int64_t) (int32_t) l9);
                    l28 = (size_t) (int64_t) t0;
                    vader_array_t* _a26_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l28)
                    l29 = vader_array_ref_load_obj(_a26_slotarr->buf, _a26_slotarr->offset + (size_t) l28);
                    l13 = ((vader_struct_vader_bytecode_SlotRange_t*) l18)->f_first;
                    l14 = ((vader_struct_vader_bytecode_SlotRange_t*) l29)->f_first;
                    if ((l13 < l14)) {
                        l12 = ((vader_struct_vader_bytecode_SlotRange_t*) l18)->f_first;
                    } else {
                        l12 = ((vader_struct_vader_bytecode_SlotRange_t*) l29)->f_first;
                    }
                    l31 = ((vader_struct_vader_bytecode_SlotRange_t*) l18)->f_last;
                    l32 = ((vader_struct_vader_bytecode_SlotRange_t*) l29)->f_last;
                    if ((l31 > l32)) {
                        l30 = ((vader_struct_vader_bytecode_SlotRange_t*) l18)->f_last;
                    } else {
                        l30 = ((vader_struct_vader_bytecode_SlotRange_t*) l29)->f_last;
                    }
                    t0 = ((int64_t) (int32_t) l9);
                    l33 = (size_t) (int64_t) t0;
                    vader_struct_vader_bytecode_SlotRange_t* _a27_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                    vader_obj_header_init(_a27_obj, 609u);
                    _a27_obj->f_first = l12;
                    _a27_obj->f_last = l30;
                    l34 = (void*) _a27_obj;
                    vader_array_t* _a28_slotarr = ((vader_array_t*) l17);
                    VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l33)
                    vader_array_ref_store(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l33, l34);
                    VADER_WRITE_BARRIER(_a28_slotarr->buf);
                }
                vader_array_t* _a29_slotarr = ((vader_array_t*) l15);
                VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l7)
                ((int32_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l7] = (int32_t) l9;
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                goto loop_260;
            }
        }
    }
    l16 = true;
    {
        loop_450: {
            if ((l1 < l2)) {
                vader_array_t* _a30_slotarr = ((vader_array_t*) l15);
                VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l1)
                l8 = ((int32_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l1];
                l9 = ((int32_t) (size_t) l1);
                if (l8 != l9) {
                    l16 = false;
                } else {
                    t0 = (l1 + INT64_C(1));
                    l1 = (size_t) (int64_t) t0;
                    goto loop_450;
                }
            }
        }
    }
    if (l16) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a31_arr = vader_array_new(138u, 0u, 13u, 1148u);
    l5 = (void*) _a31_arr;
    l1 = (size_t) 0;
    {
        loop_488: {
            if ((l1 < l4)) {
                vader_array_t* _a32_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l1)
                l35 = vader_array_ref_load_box(_a32_slotarr->buf, _a32_slotarr->offset + (size_t) l1);
                l8 = vader_bytecode_slot_touched(l35);
                if ((l8 >= INT32_C(0))) {
                    t0 = ((int64_t) (int32_t) l8);
                    l2 = (size_t) (int64_t) t0;
                    vader_array_t* _a33_slotarr = ((vader_array_t*) l15);
                    VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l2)
                    l9 = ((int32_t*) _a33_slotarr->buf->slots)[_a33_slotarr->offset + (size_t) l2];
                    if ((l9 >= INT32_C(0))) {
                        l36 = vader_bytecode_with_remapped_slot(l35, l9);
                        vader_array_push((vader_array_t*) l5, l36);
                    } else {
                        vader_array_push((vader_array_t*) l5, l35);
                    }
                } else {
                    l37 = vader_bytecode_remap_push_cache_slot(l35, l15);
                    vader_array_push((vader_array_t*) l5, l37);
                }
                t0 = (l1 + INT64_C(1));
                l1 = (size_t) (int64_t) t0;
                goto loop_488;
            }
        }
    }
    l38 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_name;
    l16 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_is_main;
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature;
    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug;
    l15 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    vader_struct_vader_bytecode_BcFunction_t* _a34_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a34_obj, 484u);
    _a34_obj->f_name = l38;
    _a34_obj->f_is_main = l16;
    _a34_obj->f_signature = l3;
    _a34_obj->f_locals = l10;
    _a34_obj->f_body = l5;
    _a34_obj->f_debug = l6;
    _a34_obj->f_jump_table = l15;
    t3 = (void*) _a34_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_bytecode_const_fills_slot(vader_box_t l0, uint8_t l1) {
    bool l2;
    bool t0;
    uint8_t t1;
    if (l0.tag == 571u) {
        t0 = vader_bytecode_is_64_bit_int_val(l1);
        return t0;
    }
    if (l0.tag == 551u) {
        t0 = vader_bytecode_is_integer_val(l1);
        if (t0) {
            t0 = vader_bytecode_is_64_bit_int_val(l1);
            l2 = !(t0);
        } else {
            l2 = false;
        }
        return l2;
    }
    t1 = vader_bytecode_const_val_type(l0);
    return t1 == l1;
}

vader_box_t vader_bytecode_const_op_of(vader_box_t l0) {
    vader_box_t t0;
    if ((l0.tag == 503u || l0.tag == 519u || l0.tag == 532u || l0.tag == 551u || l0.tag == 571u || l0.tag == 602u || l0.tag == 617u)) {
        return l0;
    }
    t0 = vader_box_obj(0u, NULL);
    return t0;
}

static uint8_t vader_bytecode_const_val_type(vader_box_t l0) {
    uint8_t l1;
    if (l0.tag == 551u) {
        l1 = (uint8_t) 2;
    } else if (l0.tag == 571u) {
        l1 = (uint8_t) 3;
    } else if (l0.tag == 532u) {
        l1 = (uint8_t) 11;
    } else if (l0.tag == 503u) {
        l1 = (uint8_t) 12;
    } else if (l0.tag == 519u) {
        l1 = (uint8_t) 13;
    } else if (l0.tag == 617u) {
        l1 = (uint8_t) 14;
    } else if (l0.tag == 602u) {
        l1 = (uint8_t) 15;
    } else {
        vader_unreachable("unreachable return in vader_bytecode$const_val_type");
    }
    return l1;
}

vader_box_t vader_bytecode_convert_target_of(uint8_t l0) {
    vader_box_t l1;
    if (l0 == INT32_C(0)) {
        l1 = vader_box_i32(193u, INT32_C(0));
    } else if (l0 == INT32_C(1)) {
        l1 = vader_box_i32(193u, INT32_C(0));
    } else if (l0 == INT32_C(2)) {
        l1 = vader_box_i32(193u, INT32_C(0));
    } else if (l0 == INT32_C(5)) {
        l1 = vader_box_i32(193u, INT32_C(0));
    } else if (l0 == INT32_C(6)) {
        l1 = vader_box_i32(193u, INT32_C(0));
    } else if (l0 == INT32_C(7)) {
        l1 = vader_box_i32(193u, INT32_C(0));
    } else if (l0 == INT32_C(3)) {
        l1 = vader_box_i32(193u, INT32_C(1));
    } else if (l0 == INT32_C(8)) {
        l1 = vader_box_i32(193u, INT32_C(1));
    } else if (l0 == INT32_C(4)) {
        l1 = vader_box_i32(193u, INT32_C(1));
    } else if (l0 == INT32_C(9)) {
        l1 = vader_box_i32(193u, INT32_C(1));
    } else if (l0 == INT32_C(10)) {
        l1 = vader_box_i32(193u, INT32_C(2));
    } else if (l0 == INT32_C(11)) {
        l1 = vader_box_i32(193u, INT32_C(2));
    } else if (l0 == INT32_C(13)) {
        l1 = vader_box_i32(193u, INT32_C(3));
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
    } else if (l0 == INT32_C(19)) {
        l1 = vader_box_obj(0u, NULL);
    } else {
        vader_unreachable("unreachable return in vader_bytecode$convert_target_of");
    }
    return l1;
}

void* vader_bytecode_default_emit_options(void) {
    void* l0 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 190u);
    l0 = (void*) _a0_arr;
    vader_struct_vader_bytecode_EmitOptions_t* _a1_obj = (vader_struct_vader_bytecode_EmitOptions_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_EmitOptions_t));
    vader_obj_header_init(_a1_obj, 527u);
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
        vader_obj_header_init(_a0_obj, 632u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Div_t* _a1_obj = (vader_struct_vader_bytecode_U32Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Div_t));
        vader_obj_header_init(_a1_obj, 626u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_bytecode_arith_op(l0, 1334u);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_drop_dead_stores(void* l0) {
    size_t l1, l2, l4, l6, l8, l9, l11, l12, l22, l25;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l20 = NULL;
    void* l23 = NULL;
    void* l29 = NULL;
    vader_box_t l7 = vader_box_null(), l31 = vader_box_null();
    int32_t l10, l13, l19, l21, l24, l26, l27, l28, l30;
    bool l14;
    vader_string_t l32 = 0;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    bool t4;
    size_t t5;
    vader_box_t* gc_roots[3] = { &l7, &l31, &t3 };
    void** gc_raw_roots[11] = { &l0, &l3, &l5, &l15, &l16, &l17, &l18, &l20, &l23, &l29, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l32 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    t0 = (l1 + l2);
    l2 = (size_t) (int64_t) t0;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    l3 = (void*) _a0_arr;
    l4 = (size_t) 0;
    {
        vader_array_t* _pc16_hdr = (vader_array_t*) l3;
        size_t _pc16_len = _pc16_hdr->length;
        size_t _pc16_cap = (_pc16_hdr->offset == 0 && !vader_array_is_borrowed(_pc16_hdr) && _pc16_hdr->length >= _pc16_hdr->buf->length) ? _pc16_hdr->capacity : (size_t) 0;
        void* _pc16_slots = _pc16_hdr->buf->slots;
        loop_16: {
            if ((l4 < l2)) {
                if (VADER_LIKELY(_pc16_len < _pc16_cap)) {
                    ((int32_t*) _pc16_slots)[_pc16_len] = (int32_t) (INT32_C(0));
                    _pc16_len += 1;
                } else {
                    _pc16_hdr->length = _pc16_len;
                    if (_pc16_hdr->buf->length < _pc16_len) {
                        _pc16_hdr->buf->length = _pc16_len;
                    }
                    vader_array_push_i32((vader_array_t*) l3, INT32_C(0));
                    _pc16_hdr = (vader_array_t*) l3;
                    _pc16_len = _pc16_hdr->length;
                    _pc16_cap = (_pc16_hdr->offset == 0 && !vader_array_is_borrowed(_pc16_hdr) && _pc16_hdr->length >= _pc16_hdr->buf->length) ? _pc16_hdr->capacity : (size_t) 0;
                    _pc16_slots = _pc16_hdr->buf->slots;
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_16;
            }
            _pc16_hdr->length = _pc16_len;
            if (_pc16_hdr->buf->length < _pc16_len) {
                _pc16_hdr->buf->length = _pc16_len;
            }
        }
    }
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l4 = ((vader_array_t*) l5)->length;
    l6 = (size_t) 0;
    {
        loop_39: {
            if ((l6 < l4)) {
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
                l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                if (l7.tag == 596u) {
                    t1 = l7.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_LocalGet_t*) t1)->f_slot;
                    t0 = ((int64_t) (int32_t) t2);
                    l8 = (size_t) (int64_t) t0;
                    t1 = l7.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_LocalGet_t*) t1)->f_slot;
                    t0 = ((int64_t) (int32_t) t2);
                    l9 = (size_t) (int64_t) t0;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
                    t2 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l9];
                    l10 = (t2 + INT32_C(1));
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
                    ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l8] = (int32_t) l10;
                }
                if (l7.tag == 595u) {
                    t1 = l7.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_LocalField_t*) t1)->f_slot;
                    t0 = ((int64_t) (int32_t) t2);
                    l11 = (size_t) (int64_t) t0;
                    t1 = l7.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_LocalField_t*) t1)->f_slot;
                    t0 = ((int64_t) (int32_t) t2);
                    l12 = (size_t) (int64_t) t0;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l12)
                    t2 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l12];
                    l13 = (t2 + INT32_C(1));
                    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l11)
                    ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l11] = (int32_t) l13;
                }
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_39;
            }
        }
    }
    vader_array_t* _a4_arr = vader_array_new(6u, 0u, 12u, 188u);
    l5 = (void*) _a4_arr;
    l4 = (size_t) 0;
    {
        vader_array_t* _pc112_hdr = (vader_array_t*) l5;
        size_t _pc112_len = _pc112_hdr->length;
        size_t _pc112_cap = (_pc112_hdr->offset == 0 && !vader_array_is_borrowed(_pc112_hdr) && _pc112_hdr->length >= _pc112_hdr->buf->length) ? _pc112_hdr->capacity : (size_t) 0;
        void* _pc112_slots = _pc112_hdr->buf->slots;
        loop_112: {
            if ((l4 < l2)) {
                if (VADER_LIKELY(_pc112_len < _pc112_cap)) {
                    ((uint8_t*) _pc112_slots)[_pc112_len] = (uint8_t) (false);
                    _pc112_len += 1;
                } else {
                    _pc112_hdr->length = _pc112_len;
                    if (_pc112_hdr->buf->length < _pc112_len) {
                        _pc112_hdr->buf->length = _pc112_len;
                    }
                    vader_array_push_bool((vader_array_t*) l5, false);
                    _pc112_hdr = (vader_array_t*) l5;
                    _pc112_len = _pc112_hdr->length;
                    _pc112_cap = (_pc112_hdr->offset == 0 && !vader_array_is_borrowed(_pc112_hdr) && _pc112_hdr->length >= _pc112_hdr->buf->length) ? _pc112_hdr->capacity : (size_t) 0;
                    _pc112_slots = _pc112_hdr->buf->slots;
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_112;
            }
            _pc112_hdr->length = _pc112_len;
            if (_pc112_hdr->buf->length < _pc112_len) {
                _pc112_hdr->buf->length = _pc112_len;
            }
        }
    }
    l14 = false;
    l4 = l1;
    {
        loop_133: {
            if ((l4 < l2)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                t2 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4];
                if (t2 == INT32_C(0)) {
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l4)
                    ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l4] = (uint8_t) true;
                    l14 = true;
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_133;
            }
        }
    }
    if (!(l14)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 193u);
    l3 = (void*) _a7_arr;
    l4 = (size_t) 0;
    {
        vader_array_t* _pc170_hdr = (vader_array_t*) l3;
        size_t _pc170_len = _pc170_hdr->length;
        size_t _pc170_cap = (_pc170_hdr->offset == 0 && !vader_array_is_borrowed(_pc170_hdr) && _pc170_hdr->length >= _pc170_hdr->buf->length) ? _pc170_hdr->capacity : (size_t) 0;
        void* _pc170_slots = _pc170_hdr->buf->slots;
        loop_170: {
            if ((l4 < l2)) {
                l10 = -(INT32_C(1));
                if (VADER_LIKELY(_pc170_len < _pc170_cap)) {
                    ((int32_t*) _pc170_slots)[_pc170_len] = (int32_t) (l10);
                    _pc170_len += 1;
                } else {
                    _pc170_hdr->length = _pc170_len;
                    if (_pc170_hdr->buf->length < _pc170_len) {
                        _pc170_hdr->buf->length = _pc170_len;
                    }
                    vader_array_push_i32((vader_array_t*) l3, l10);
                    _pc170_hdr = (vader_array_t*) l3;
                    _pc170_len = _pc170_hdr->length;
                    _pc170_cap = (_pc170_hdr->offset == 0 && !vader_array_is_borrowed(_pc170_hdr) && _pc170_hdr->length >= _pc170_hdr->buf->length) ? _pc170_hdr->capacity : (size_t) 0;
                    _pc170_slots = _pc170_hdr->buf->slots;
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_170;
            }
            _pc170_hdr->length = _pc170_len;
            if (_pc170_hdr->buf->length < _pc170_len) {
                _pc170_hdr->buf->length = _pc170_len;
            }
        }
    }
    l10 = INT32_C(0);
    l4 = (size_t) 0;
    {
        loop_194: {
            if ((l4 < l2)) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l4)
                t3 = vader_box_bool(188u, ((uint8_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l4]);
                t4 = t3.payload.b;
                if (!(t4)) {
                    vader_array_t* _a9_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l4)
                    ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l4] = (int32_t) l10;
                    l10 = (l10 + INT32_C(1));
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_194;
            }
        }
    }
    vader_array_t* _a10_arr = vader_array_new(138u, 0u, 13u, 1148u);
    l15 = (void*) _a10_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body)->length;
    vader_array_t* _a11_arr = vader_array_new(9u, 0u, 7u, 193u);
    l16 = (void*) _a11_arr;
    l6 = (size_t) 0;
    {
        vader_array_t* _pc232_hdr = (vader_array_t*) l16;
        size_t _pc232_len = _pc232_hdr->length;
        size_t _pc232_cap = (_pc232_hdr->offset == 0 && !vader_array_is_borrowed(_pc232_hdr) && _pc232_hdr->length >= _pc232_hdr->buf->length) ? _pc232_hdr->capacity : (size_t) 0;
        void* _pc232_slots = _pc232_hdr->buf->slots;
        loop_232: {
            if ((l6 < l4)) {
                l10 = -(INT32_C(1));
                if (VADER_LIKELY(_pc232_len < _pc232_cap)) {
                    ((int32_t*) _pc232_slots)[_pc232_len] = (int32_t) (l10);
                    _pc232_len += 1;
                } else {
                    _pc232_hdr->length = _pc232_len;
                    if (_pc232_hdr->buf->length < _pc232_len) {
                        _pc232_hdr->buf->length = _pc232_len;
                    }
                    vader_array_push_i32((vader_array_t*) l16, l10);
                    _pc232_hdr = (vader_array_t*) l16;
                    _pc232_len = _pc232_hdr->length;
                    _pc232_cap = (_pc232_hdr->offset == 0 && !vader_array_is_borrowed(_pc232_hdr) && _pc232_hdr->length >= _pc232_hdr->buf->length) ? _pc232_hdr->capacity : (size_t) 0;
                    _pc232_slots = _pc232_hdr->buf->slots;
                }
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_232;
            }
            _pc232_hdr->length = _pc232_len;
            if (_pc232_hdr->buf->length < _pc232_len) {
                _pc232_hdr->buf->length = _pc232_len;
            }
        }
    }
    l6 = (size_t) 0;
    {
        loop_254: {
            if ((l6 < l4)) {
                vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l6)
                l7 = vader_array_ref_load_box(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l6);
                if (l7.tag == 597u) {
                    t1 = l7.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_LocalSet_t*) t1)->f_slot;
                    t0 = ((int64_t) (int32_t) t2);
                    l8 = (size_t) (int64_t) t0;
                    vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l8)
                    t3 = vader_box_bool(188u, ((uint8_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l8]);
                    t4 = t3.payload.b;
                    if (t4) {
                        t5 = ((vader_array_t*) l15)->length;
                        l10 = ((int32_t) (size_t) t5);
                        vader_array_t* _a14_slotarr = ((vader_array_t*) l16);
                        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l6)
                        ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l6] = (int32_t) l10;
                        vader_struct_vader_bytecode_Drop_t* _a15_obj = (vader_struct_vader_bytecode_Drop_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Drop_t));
                        vader_obj_header_init(_a15_obj, 525u);
                        l17 = (void*) _a15_obj;
                        vader_array_push((vader_array_t*) l15, vader_ref_box(l17));
                    } else {
                        t5 = ((vader_array_t*) l15)->length;
                        l13 = ((int32_t) (size_t) t5);
                        vader_array_t* _a16_slotarr = ((vader_array_t*) l16);
                        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l6)
                        ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l6] = (int32_t) l13;
                        t1 = l7.payload.obj;
                        t2 = ((vader_struct_vader_bytecode_LocalSet_t*) t1)->f_slot;
                        t0 = ((int64_t) (int32_t) t2);
                        l9 = (size_t) (int64_t) t0;
                        vader_array_t* _a17_slotarr = ((vader_array_t*) l3);
                        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l9)
                        t2 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l9];
                        vader_struct_vader_bytecode_LocalSet_t* _a18_obj = (vader_struct_vader_bytecode_LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalSet_t));
                        vader_obj_header_init(_a18_obj, 597u);
                        _a18_obj->f_slot = t2;
                        l18 = (void*) _a18_obj;
                        vader_array_push((vader_array_t*) l15, vader_ref_box(l18));
                    }
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_254;
                }
                if (l7.tag == 598u) {
                    t1 = l7.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_LocalTee_t*) t1)->f_slot;
                    t0 = ((int64_t) (int32_t) t2);
                    l11 = (size_t) (int64_t) t0;
                    vader_array_t* _a19_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l11)
                    t3 = vader_box_bool(188u, ((uint8_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l11]);
                    t4 = t3.payload.b;
                    if (t4) {
                        t0 = (l6 + INT64_C(1));
                        l6 = (size_t) (int64_t) t0;
                        goto loop_254;
                    }
                    t5 = ((vader_array_t*) l15)->length;
                    l19 = ((int32_t) (size_t) t5);
                    vader_array_t* _a20_slotarr = ((vader_array_t*) l16);
                    VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l6)
                    ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l6] = (int32_t) l19;
                    t1 = l7.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_LocalTee_t*) t1)->f_slot;
                    t0 = ((int64_t) (int32_t) t2);
                    l12 = (size_t) (int64_t) t0;
                    vader_array_t* _a21_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l12)
                    t2 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l12];
                    vader_struct_vader_bytecode_LocalTee_t* _a22_obj = (vader_struct_vader_bytecode_LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalTee_t));
                    vader_obj_header_init(_a22_obj, 598u);
                    _a22_obj->f_slot = t2;
                    l20 = (void*) _a22_obj;
                    vader_array_push((vader_array_t*) l15, vader_ref_box(l20));
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_254;
                }
                if (l7.tag == 596u) {
                    t5 = ((vader_array_t*) l15)->length;
                    l21 = ((int32_t) (size_t) t5);
                    vader_array_t* _a23_slotarr = ((vader_array_t*) l16);
                    VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l6)
                    ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l6] = (int32_t) l21;
                    t1 = l7.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_LocalGet_t*) t1)->f_slot;
                    t0 = ((int64_t) (int32_t) t2);
                    l22 = (size_t) (int64_t) t0;
                    vader_array_t* _a24_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l22)
                    t2 = ((int32_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l22];
                    vader_struct_vader_bytecode_LocalGet_t* _a25_obj = (vader_struct_vader_bytecode_LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalGet_t));
                    vader_obj_header_init(_a25_obj, 596u);
                    _a25_obj->f_slot = t2;
                    l23 = (void*) _a25_obj;
                    vader_array_push((vader_array_t*) l15, vader_ref_box(l23));
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_254;
                }
                if (l7.tag == 595u) {
                    t5 = ((vader_array_t*) l15)->length;
                    l24 = ((int32_t) (size_t) t5);
                    vader_array_t* _a26_slotarr = ((vader_array_t*) l16);
                    VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l6)
                    ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l6] = (int32_t) l24;
                    t1 = l7.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_LocalField_t*) t1)->f_slot;
                    t0 = ((int64_t) (int32_t) t2);
                    l25 = (size_t) (int64_t) t0;
                    vader_array_t* _a27_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l25)
                    l26 = ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l25];
                    t1 = l7.payload.obj;
                    l27 = ((vader_struct_vader_bytecode_LocalField_t*) t1)->f_type_id;
                    t1 = l7.payload.obj;
                    l28 = ((vader_struct_vader_bytecode_LocalField_t*) t1)->f_field_index;
                    vader_struct_vader_bytecode_LocalField_t* _a28_obj = (vader_struct_vader_bytecode_LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalField_t));
                    vader_obj_header_init(_a28_obj, 595u);
                    _a28_obj->f_slot = l26;
                    _a28_obj->f_type_id = l27;
                    _a28_obj->f_field_index = l28;
                    l29 = (void*) _a28_obj;
                    vader_array_push((vader_array_t*) l15, vader_ref_box(l29));
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_254;
                }
                t5 = ((vader_array_t*) l15)->length;
                l30 = ((int32_t) (size_t) t5);
                vader_array_t* _a29_slotarr = ((vader_array_t*) l16);
                VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l6)
                ((int32_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l6] = (int32_t) l30;
                l31 = vader_bytecode_remap_push_cache_slot(l7, l3);
                vader_array_push((vader_array_t*) l15, l31);
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_254;
            }
        }
    }
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l4 = ((vader_array_t*) l15)->length;
    l3 = vader_bytecode_remap_jump_table(l3, l16, l4);
    l17 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug;
    l4 = ((vader_array_t*) l15)->length;
    l16 = vader_bytecode_remap_debug(l17, l16, l4);
    vader_array_t* _a30_arr = vader_array_new(40u, 0u, 13u, 486u);
    l17 = (void*) _a30_arr;
    l4 = l1;
    {
        loop_491: {
            if ((l4 < l2)) {
                vader_array_t* _a31_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l4)
                t3 = vader_box_bool(188u, ((uint8_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l4]);
                t4 = t3.payload.b;
                if (!(t4)) {
                    l18 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
                    t0 = (l4 - l1);
                    l6 = (size_t) (int64_t) t0;
                    vader_array_t* _a32_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l6)
                    l20 = vader_array_ref_load_obj(_a32_slotarr->buf, _a32_slotarr->offset + (size_t) l6);
                    vader_array_push((vader_array_t*) l17, vader_ref_box(l20));
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_491;
            }
        }
    }
    l32 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_name;
    l14 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_is_main;
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature;
    vader_struct_vader_bytecode_BcFunction_t* _a33_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a33_obj, 484u);
    _a33_obj->f_name = l32;
    _a33_obj->f_is_main = l14;
    _a33_obj->f_signature = l5;
    _a33_obj->f_locals = l17;
    _a33_obj->f_body = l15;
    _a33_obj->f_debug = l16;
    _a33_obj->f_jump_table = l3;
    t1 = (void*) _a33_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_bytecode_extend_into_loops(void* l0, void* l1, size_t l2, void* l3) {
    bool l4, l13;
    size_t l5, l8, l9;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    int32_t l11, l12, l14, l15, l16, l17, l18, l19, l20, l21, l22, l23;
    vader_box_t t0 = vader_box_null();
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l6, &l7, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = false;
    l5 = (size_t) 0;
    {
        loop_5: {
            if ((l5 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
                t0 = vader_box_bool(188u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5]);
                t1 = t0.payload.b;
                if (t1) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                    l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                    l7 = l3;
                    l8 = ((vader_array_t*) l7)->length;
                    l9 = (size_t) 0;
                    {
                        loop_26: {
                            if ((l9 < l8)) {
                                vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
                                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
                                l10 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
                                l11 = ((vader_struct_vader_bytecode_SlotRange_t*) l6)->f_first;
                                l12 = ((vader_struct_vader_bytecode_SlotRange_t*) l10)->f_last;
                                if ((l11 <= l12)) {
                                    l14 = ((vader_struct_vader_bytecode_SlotRange_t*) l6)->f_last;
                                    l15 = ((vader_struct_vader_bytecode_SlotRange_t*) l10)->f_first;
                                    l13 = (l14 >= l15);
                                } else {
                                    l13 = false;
                                }
                                if (l13) {
                                    l16 = ((vader_struct_vader_bytecode_SlotRange_t*) l6)->f_first;
                                    l17 = ((vader_struct_vader_bytecode_SlotRange_t*) l10)->f_first;
                                    if ((l16 > l17)) {
                                        l18 = ((vader_struct_vader_bytecode_SlotRange_t*) l10)->f_first;
                                        l19 = ((vader_struct_vader_bytecode_SlotRange_t*) l6)->f_last;
                                        vader_struct_vader_bytecode_SlotRange_t* _a3_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                                        vader_obj_header_init(_a3_obj, 609u);
                                        _a3_obj->f_first = l18;
                                        _a3_obj->f_last = l19;
                                        l6 = (void*) _a3_obj;
                                        l4 = true;
                                    }
                                    l20 = ((vader_struct_vader_bytecode_SlotRange_t*) l6)->f_last;
                                    l21 = ((vader_struct_vader_bytecode_SlotRange_t*) l10)->f_last;
                                    if ((l20 < l21)) {
                                        l22 = ((vader_struct_vader_bytecode_SlotRange_t*) l6)->f_first;
                                        l23 = ((vader_struct_vader_bytecode_SlotRange_t*) l10)->f_last;
                                        vader_struct_vader_bytecode_SlotRange_t* _a4_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                                        vader_obj_header_init(_a4_obj, 609u);
                                        _a4_obj->f_first = l22;
                                        _a4_obj->f_last = l23;
                                        l6 = (void*) _a4_obj;
                                        l4 = true;
                                    }
                                }
                                t2 = (l9 + INT64_C(1));
                                l9 = (size_t) (int64_t) t2;
                                goto loop_26;
                            }
                        }
                    }
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l0);
                    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
                    vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5, l6);
                    VADER_WRITE_BARRIER(_a5_slotarr->buf);
                }
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_5;
            }
        }
    }
    { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(42u, 0u, 13u, 609u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 190u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 193u);
    l3 = (void*) _a2_arr;
    l4 = (size_t) 0;
    l5 = ((vader_array_t*) l0)->length;
    l6 = (size_t) 0;
    {
        loop_14: {
            if ((l6 < l5)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
                l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
                if (l7.tag == 501u) {
                    l8 = ((int32_t) (size_t) l6);
                    vader_bytecode_push_scope(l2, l3, l4, 1143u, l8);
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                } else if (l7.tag == 599u) {
                    l9 = ((int32_t) (size_t) l6);
                    vader_bytecode_push_scope(l2, l3, l4, 1723u, l9);
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                } else if (l7.tag == 586u) {
                    l10 = ((int32_t) (size_t) l6);
                    vader_bytecode_push_scope(l2, l3, l4, 1584u, l10);
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                } else if (l7.tag == 529u) {
                    if ((l4 > INT64_C(0))) {
                        t0 = (l4 - INT64_C(1));
                        l4 = (size_t) (int64_t) t0;
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                        t1 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l4];
                        t2 = t1.payload.s;
                        if (t2 == 1723u) {
                            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
                            l11 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4];
                            l12 = ((int32_t) (size_t) l6);
                            vader_struct_vader_bytecode_SlotRange_t* _a6_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                            vader_obj_header_init(_a6_obj, 609u);
                            _a6_obj->f_first = l11;
                            _a6_obj->f_last = l12;
                            l13 = (void*) _a6_obj;
                            vader_array_push((vader_array_t*) l1, vader_ref_box(l13));
                        }
                    }
                }
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_14;
            }
        }
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
    {
        loop_8: {
            if ((l3 < l2)) {
                t0 = vader_host_std_core_byte_at(l0, l3);
                t1 = ((int64_t) (uint8_t) t0);
                l4 = (uint64_t) (int64_t) t1;
                t1 = ((l1 ^ l4) * INT64_C(1099511628211));
                l1 = (uint64_t) (int64_t) t1;
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_8;
            }
        }
    }
    l5 = 0u;
    l6 = INT32_C(0);
    {
        loop_37: {
            if ((l6 < INT32_C(16))) {
                t1 = ((int64_t) (int32_t) ((INT32_C(15) - l6) * INT32_C(4)));
                l4 = (uint64_t) (int64_t) t1;
                t1 = ((l1 >> l4) & INT64_C(15));
                l7 = (uint64_t) (int64_t) t1;
                t1 = ((int64_t) (uint64_t) l7);
                l2 = (size_t) (int64_t) t1;
                t1 = (((int64_t) (uint64_t) l7) + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                l8 = vader_string_slice_codepoints(289u, l2, l3);
                l5 = concat_2(l5, l8);
                l6 = (l6 + INT32_C(1));
                goto loop_37;
            }
        }
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
    t1 = vader_box_bool(188u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4]);
    t2 = t1.payload.b;
    if (t2) {
        return false;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
    if (t1.tag == 596u) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l1)
        t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l1);
        l5 = t1.payload.obj;
        t0 = (l1 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        if (l6.tag == 598u) {
            t3 = l6.payload.obj;
            l7 = ((vader_struct_vader_bytecode_LocalTee_t*) t3)->f_slot;
            l8 = ((vader_struct_vader_bytecode_LocalGet_t*) l5)->f_slot;
            return l7 == l8;
        }
        if (l6.tag == 597u) {
            t3 = l6.payload.obj;
            l7 = ((vader_struct_vader_bytecode_LocalSet_t*) t3)->f_slot;
            l8 = ((vader_struct_vader_bytecode_LocalGet_t*) l5)->f_slot;
            return l7 == l8;
        }
    }
    return false;
}

static vader_string_t vader_bytecode_int_equals_method(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    bool l2;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_strip_core_member(l0, 162u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_types_is_int_name(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        { vader_gc_top = gc_frame.prev; return 1371u; }
    }
    l1 = vader_bytecode_strip_core_member(l0, 163u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_types_is_int_name(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        { vader_gc_top = gc_frame.prev; return 1814u; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
}

int32_t vader_bytecode_intern_cell_type(vader_box_t l0, void* l1) {
    int32_t l2, l5;
    vader_string_t l3 = 0;
    vader_string_t l8 = 0;
    vader_box_t l4 = vader_box_null();
    void* l6 = NULL;
    void* l7 = NULL;
    int32_t t0;
    size_t t1;
    vader_box_t* gc_roots[2] = { &l0, &l4 };
    void** gc_raw_roots[3] = { &l1, &l6, &l7 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_bytecode_intern_type(l0, l1);
    l3 = vader_bytecode_type_intern_key(l0);
    l3 = concat_3(158u, l3, 349u);
    l4 = std_collections_MutableMap_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l3);
    if (l4.tag == 193u) {
        t0 = ((int32_t) l4.payload.i);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
    l5 = ((int32_t) (size_t) t1);
    vader_struct_vader_bytecode_BcField_t* _a0_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
    vader_obj_header_init(_a0_obj, 482u);
    _a0_obj->f_name = 2321u;
    _a0_obj->f_type_index = l2;
    l6 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(37u, 0u, 13u, 482u);
    l7 = (void*) _a1_arr;
    vader_array_push((vader_array_t*) l7, vader_ref_box(l6));
    l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
    l8 = vader_bytecode_type_intern_key(l0);
    l8 = concat_2(159u, l8);
    l2 = -(INT32_C(1));
    vader_struct_vader_bytecode_BcStruct_t* _a2_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
    vader_obj_header_init(_a2_obj, 493u);
    _a2_obj->f_name = l8;
    _a2_obj->f_fields = l7;
    _a2_obj->f_c_name = 0u;
    _a2_obj->f_symbol_id = l2;
    l7 = (void*) _a2_obj;
    vader_array_push((vader_array_t*) l6, vader_ref_box(l7));
    std_collections_MutableMap_IndexSet_set_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l3, l5);
    { int32_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_bytecode_intern_string(vader_string_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int32_t l3;
    int32_t t0;
    size_t t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_collections_MutableMap_Index_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_string_key, l0);
    if (l2.tag == 193u) {
        t0 = ((int32_t) l2.payload.i);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_strings)->length;
    l3 = ((int32_t) (size_t) t1);
    vader_array_push((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_strings, vader_box_string(190u, l0));
    std_collections_MutableMap_IndexSet_set_at__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_string_key, l0, l3);
    { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
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
    if (l3.tag == 193u) {
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
    if (l3.tag == 193u) {
        t3 = std_collections_MutableMap_Index_at__u64__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_hash, l2);
        if (t3.tag == 0u) {
            l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_hash;
            l9 = ((int32_t) l3.payload.i);
            std_collections_MutableMap_IndexSet_set_at__u64__i32(l6, l2, l9);
            l9 = ((int32_t) l3.payload.i);
            vader_bytecode_record_slot_type(l1, l9, l0);
        }
        t0 = ((int32_t) l3.payload.i);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types_frozen;
    if (t2) {
        t4 = concat_3(1192u, l8, 781u);
        vader_host_std_abort_panic(t4);
    }
    t5 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
    l9 = ((int32_t) (size_t) t5);
    vader_struct_vader_bytecode_BcRef_t* _a1_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
    vader_obj_header_init(_a1_obj, 490u);
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

uint8_t vader_bytecode_intrinsic_id_for(vader_string_t l0) {
    vader_string_t l1 = 0;
    bool t0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_int_equals_method(l0);
    if (l1 == 1371u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 9; }
    }
    if (l1 == 1814u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 10; }
    }
    t0 = vader_bytecode_is_display_to_string(l0);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 11; }
    }
    if (l0 == 2318u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 22; }
    }
    if (l0 == 2319u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 23; }
    }
    if (l0 == 2317u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 24; }
    }
    if (l0 == 1964u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 1; }
    }
    if (l0 == 1963u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 2; }
    }
    if (l0 == 1965u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 3; }
    }
    if (l0 == 1966u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 4; }
    }
    l1 = vader_bytecode_primitive_member_mangle(2008u, 452u, 1123u);
    if (l0 == l1) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 5; }
    }
    l1 = vader_bytecode_primitive_member_mangle(2008u, 442u, 1526u);
    if (l0 == l1) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 6; }
    }
    if (l0 == 1971u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 7; }
    }
    if (l0 == 1972u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 8; }
    }
    if (l0 == 1979u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 12; }
    }
    if (l0 == 1980u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 13; }
    }
    if (l0 == 1978u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 14; }
    }
    if (l0 == 1977u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 15; }
    }
    if (l0 == 1982u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 16; }
    }
    if (l0 == 1981u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 17; }
    }
    if (l0 == 1983u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 18; }
    }
    if (l0 == 1985u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 20; }
    }
    if (l0 == 1984u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 21; }
    }
    if (l0 == 1956u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 19; }
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
}

static vader_box_t vader_bytecode_intrinsic_op_for_mangled(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_primitive_arith_op(l0);
    if (!(l1.tag == 0u)) {
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1969u) {
        vader_struct_vader_bytecode_I32Eq_t* _a0_obj = (vader_struct_vader_bytecode_I32Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Eq_t));
        vader_obj_header_init(_a0_obj, 553u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1970u) {
        vader_struct_vader_bytecode_I64Eq_t* _a1_obj = (vader_struct_vader_bytecode_I64Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Eq_t));
        vader_obj_header_init(_a1_obj, 573u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_bytecode_primitive_cmp_op(l0);
    if (!(l1.tag == 0u)) {
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1975u) {
        vader_struct_vader_bytecode_BufferNew_t* _a2_obj = (vader_struct_vader_bytecode_BufferNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BufferNew_t));
        vader_obj_header_init(_a2_obj, 511u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1959u) {
        vader_struct_vader_bytecode_LoadU8_t* _a3_obj = (vader_struct_vader_bytecode_LoadU8_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LoadU8_t));
        vader_obj_header_init(_a3_obj, 594u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1961u) {
        vader_struct_vader_bytecode_StoreU8_t* _a4_obj = (vader_struct_vader_bytecode_StoreU8_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StoreU8_t));
        vader_obj_header_init(_a4_obj, 616u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1960u) {
        vader_struct_vader_bytecode_MemoryCopy_t* _a5_obj = (vader_struct_vader_bytecode_MemoryCopy_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_MemoryCopy_t));
        vader_obj_header_init(_a5_obj, 601u);
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1958u) {
        vader_struct_vader_bytecode_BufferToString_t* _a6_obj = (vader_struct_vader_bytecode_BufferToString_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BufferToString_t));
        vader_obj_header_init(_a6_obj, 512u);
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1962u) {
        vader_struct_vader_bytecode_BufferWriteString_t* _a7_obj = (vader_struct_vader_bytecode_BufferWriteString_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BufferWriteString_t));
        vader_obj_header_init(_a7_obj, 513u);
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1968u) {
        vader_struct_vader_bytecode_F64ToBits_t* _a8_obj = (vader_struct_vader_bytecode_F64ToBits_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64ToBits_t));
        vader_obj_header_init(_a8_obj, 543u);
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1974u) {
        vader_struct_vader_bytecode_BitsToF64_t* _a9_obj = (vader_struct_vader_bytecode_BitsToF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BitsToF64_t));
        vader_obj_header_init(_a9_obj, 500u);
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1967u) {
        vader_struct_vader_bytecode_F32ToBits_t* _a10_obj = (vader_struct_vader_bytecode_F32ToBits_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F32ToBits_t));
        vader_obj_header_init(_a10_obj, 530u);
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1973u) {
        vader_struct_vader_bytecode_BitsToF32_t* _a11_obj = (vader_struct_vader_bytecode_BitsToF32_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BitsToF32_t));
        vader_obj_header_init(_a11_obj, 499u);
        t0 = (void*) _a11_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_bytecode_is_64_bit_int_val(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(3)) {
        l1 = true;
    } else if (l0 == INT32_C(8)) {
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
    } else if (l0 == INT32_C(19)) {
        l1 = false;
    } else {
        vader_unreachable("unreachable return in vader_bytecode$is_64_bit_int_val");
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
    l1 = vader_bytecode_strip_core_member(l0, 160u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_types_is_primitive_name(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        l2 = t0 != 2334u;
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        l2 = t0 != 1815u;
    } else {
        l2 = false;
    }
    { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_bytecode_is_float_val(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(10)) {
        l1 = true;
    } else if (l0 == INT32_C(11)) {
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
    } else if (l0 == INT32_C(19)) {
        l1 = false;
    } else {
        vader_unreachable("unreachable return in vader_bytecode$is_float_val");
    }
    return l1;
}

bool vader_bytecode_is_integer_val(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(0)) {
        l1 = true;
    } else if (l0 == INT32_C(1)) {
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
    } else if (l0 == INT32_C(19)) {
        l1 = false;
    } else {
        vader_unreachable("unreachable return in vader_bytecode$is_integer_val");
    }
    return l1;
}

static bool vader_bytecode_is_op_eq_prim(vader_string_t l0) {
    bool l1;
    bool t0;
    t0 = vader_types_is_primitive_name(l0);
    if (t0) {
        t0 = vader_types_is_int_name(l0);
        l1 = !(t0);
    } else {
        l1 = false;
    }
    return l1;
}

static bool vader_bytecode_is_ref_class(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(18)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(19);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(15);
    }
    return l1;
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
    if (l0.tag == 493u) {
        l2 = true;
    } else if (l0.tag == 480u) {
        l2 = true;
    } else if (l0.tag == 483u) {
        l2 = true;
    } else if (l0.tag == 489u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val == INT32_C(15);
    } else if (l0.tag == 490u) {
        l2 = false;
    } else {
        if (l0.tag == 494u) {
            t0 = l0.payload.obj;
            l3 = ((vader_struct_vader_bytecode_BcUnion_t*) t0)->f_variants;
            l4 = ((vader_array_t*) l3)->length;
            l5 = (size_t) 0;
            {
                loop_46: {
                    if ((l5 < l4)) {
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
                        goto loop_46;
                    }
                }
            }
            return true;
        }
        vader_unreachable("unreachable return in vader_bytecode$is_ref_only_element");
    }
    return l2;
}

bool vader_bytecode_is_string_val(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(14)) {
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
    } else if (l0 == INT32_C(19)) {
        l1 = false;
    } else {
        vader_unreachable("unreachable return in vader_bytecode$is_string_val");
    }
    return l1;
}

static bool vader_bytecode_is_u32_class(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(5)) {
        l1 = true;
    } else if (l0 == INT32_C(6)) {
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
    } else if (l0 == INT32_C(19)) {
        l1 = false;
    } else {
        vader_unreachable("unreachable return in vader_bytecode$is_u32_class");
    }
    return l1;
}

static bool vader_bytecode_is_u64_class(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(8)) {
        l1 = true;
    } else if (l0 == INT32_C(9)) {
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
    } else if (l0 == INT32_C(19)) {
        l1 = false;
    } else {
        vader_unreachable("unreachable return in vader_bytecode$is_u64_class");
    }
    return l1;
}

bool vader_bytecode_is_unsigned_display(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    bool l2, l3;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_strip_core_member(l0, 160u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        if (t0 == 2137u) {
            l2 = true;
        } else {
            t0 = l1.payload.s;
            l2 = t0 == 2146u;
        }
        if (l2) {
            l3 = true;
        } else {
            t0 = l1.payload.s;
            l3 = t0 == 2198u;
        }
        l2 = l3;
    } else {
        l2 = false;
    }
    { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_bytecode_is_unsigned_val(uint8_t l0) {
    bool l1;
    bool t0;
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        l1 = true;
    } else {
        l1 = vader_bytecode_is_u64_class(l0);
    }
    return l1;
}

static vader_string_t vader_bytecode_key_join(void* l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    size_t l5, l6;
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 190u);
    l3 = (void*) _a0_arr;
    l4 = l1;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    {
        loop_9: {
            if ((l6 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
                l7 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
                l8 = vader_bytecode_bc_type_key(l0, l7);
                vader_array_push((vader_array_t*) l3, vader_box_string(190u, l8));
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_9;
            }
        }
    }
    t1 = std_string_join(l3, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_mark_jump_targets(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l7;
    int32_t l5;
    bool l6;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(6u, 1u, 12u, 188u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l3 = ((vader_array_t*) l0)->length;
    l4 = (size_t) 0;
    {
        loop_11: {
            if ((l4 < l3)) {
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                l5 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                if ((l5 >= INT32_C(0))) {
                    l6 = (((int64_t) (int32_t) l5) < l1);
                } else {
                    l6 = false;
                }
                if (l6) {
                    t1 = ((int64_t) (int32_t) l5);
                    l7 = (size_t) (int64_t) t1;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
                    ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7] = (uint8_t) true;
                }
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_11;
            }
        }
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
        vader_obj_header_init(_a0_obj, 637u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Mod_t* _a1_obj = (vader_struct_vader_bytecode_U32Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Mod_t));
        vader_obj_header_init(_a1_obj, 631u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        vader_struct_vader_bytecode_I64Mod_t* _a2_obj = (vader_struct_vader_bytecode_I64Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Mod_t));
        vader_obj_header_init(_a2_obj, 578u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Mod_t* _a3_obj = (vader_struct_vader_bytecode_I32Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Mod_t));
    vader_obj_header_init(_a3_obj, 558u);
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
        vader_obj_header_init(_a0_obj, 541u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        vader_struct_vader_bytecode_I64Neg_t* _a1_obj = (vader_struct_vader_bytecode_I64Neg_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Neg_t));
        vader_obj_header_init(_a1_obj, 581u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Neg_t* _a2_obj = (vader_struct_vader_bytecode_I32Neg_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Neg_t));
    vader_obj_header_init(_a2_obj, 561u);
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_bytecode_nested_mirror(void* l0, void* l1) {
    bool l2;
    size_t l3, l4;
    vader_box_t l5;
    int32_t t0;
    int64_t t1;
    vader_box_t t2;
    void* t3;
    vader_string_t t4;
    t0 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_type_index;
    if ((t0 < INT32_C(0))) {
        l2 = true;
    } else {
        t0 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_type_index;
        t1 = ((int64_t) (int32_t) t0);
        l3 = (size_t) (int64_t) t1;
        l4 = ((vader_array_t*) l1)->length;
        l2 = (l3 >= l4);
    }
    if (l2) {
        t2 = vader_box_obj(0u, NULL);
        return t2;
    }
    t0 = ((vader_struct_vader_bytecode_BcField_t*) l0)->f_type_index;
    t1 = ((int64_t) (int32_t) t0);
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l5.tag == 493u) {
        t3 = l5.payload.obj;
        t4 = ((vader_struct_vader_bytecode_BcStruct_t*) t3)->f_c_name;
        if (t4 != 0u) {
            t3 = l5.payload.obj;
            return vader_ref_box(t3);
        }
    }
    t2 = vader_box_obj(0u, NULL);
    return t2;
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
    vader_array_t* _a0_arr = vader_array_new(141u, 0u, 13u, 1158u);
    l0 = (void*) _a0_arr;
    vader_struct_vader_bytecode_BcPrimitive_t* _a1_obj = (vader_struct_vader_bytecode_BcPrimitive_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPrimitive_t));
    vader_obj_header_init(_a1_obj, 489u);
    _a1_obj->f_val = (uint8_t) 15;
    l1 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l0, vader_ref_box(l1));
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 190u);
    l1 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 193u);
    l2 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 193u);
    l3 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a5_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a5_obj, 343u);
    _a5_obj->f_ekeys = l1;
    _a5_obj->f_evals = l2;
    _a5_obj->f_index = l3;
    _a5_obj->f_mask = (size_t) 0;
    _a5_obj->f_size = (size_t) 0;
    _a5_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a5_obj;
    std_collections_MutableMap_IndexSet_set_at__string__i32(l1, 1815u, INT32_C(0));
    vader_array_t* _a6_arr = vader_array_new(14u, 0u, 4u, 199u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 193u);
    l3 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 193u);
    l4 = (void*) _a8_arr;
    vader_struct_std_collections_MutableMap__u64__i32_t* _a9_obj = (vader_struct_std_collections_MutableMap__u64__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__u64__i32_t));
    vader_obj_header_init(_a9_obj, 352u);
    _a9_obj->f_ekeys = l2;
    _a9_obj->f_evals = l3;
    _a9_obj->f_index = l4;
    _a9_obj->f_mask = (size_t) 0;
    _a9_obj->f_size = (size_t) 0;
    _a9_obj->f_tombs = (size_t) 0;
    l2 = (void*) _a9_obj;
    vader_struct_vader_types_PrimitiveType_t* _a10_obj = (vader_struct_vader_types_PrimitiveType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_PrimitiveType_t));
    vader_obj_header_init(_a10_obj, 964u);
    _a10_obj->f_name = 1815u;
    t0 = (void*) _a10_obj;
    l5 = vader_bytecode_type_intern_hash(vader_ref_box(t0));
    std_collections_MutableMap_IndexSet_set_at__u64__i32(l2, l5, INT32_C(0));
    vader_struct_vader_types_PrimitiveType_t* _a11_obj = (vader_struct_vader_types_PrimitiveType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_PrimitiveType_t));
    vader_obj_header_init(_a11_obj, 964u);
    _a11_obj->f_name = 1815u;
    t0 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(156u, 1u, 13u, 1300u);
    ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = t0;
    l3 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(8u, 0u, 0u, 190u);
    l4 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(8u, 0u, 0u, 190u);
    l6 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(9u, 0u, 7u, 193u);
    l7 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(9u, 0u, 7u, 193u);
    l8 = (void*) _a16_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a17_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a17_obj, 343u);
    _a17_obj->f_ekeys = l6;
    _a17_obj->f_evals = l7;
    _a17_obj->f_index = l8;
    _a17_obj->f_mask = (size_t) 0;
    _a17_obj->f_size = (size_t) 0;
    _a17_obj->f_tombs = (size_t) 0;
    l6 = (void*) _a17_obj;
    vader_array_t* _a18_arr = vader_array_new(38u, 0u, 13u, 484u);
    l7 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(9u, 0u, 7u, 193u);
    l8 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(9u, 0u, 7u, 193u);
    l9 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(9u, 0u, 7u, 193u);
    l10 = (void*) _a21_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a22_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a22_obj, 295u);
    _a22_obj->f_ekeys = l8;
    _a22_obj->f_evals = l9;
    _a22_obj->f_index = l10;
    _a22_obj->f_mask = (size_t) 0;
    _a22_obj->f_size = (size_t) 0;
    _a22_obj->f_tombs = (size_t) 0;
    l8 = (void*) _a22_obj;
    vader_array_t* _a23_arr = vader_array_new(8u, 0u, 0u, 190u);
    l9 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(9u, 0u, 7u, 193u);
    l10 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(9u, 0u, 7u, 193u);
    l11 = (void*) _a25_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a26_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a26_obj, 343u);
    _a26_obj->f_ekeys = l9;
    _a26_obj->f_evals = l10;
    _a26_obj->f_index = l11;
    _a26_obj->f_mask = (size_t) 0;
    _a26_obj->f_size = (size_t) 0;
    _a26_obj->f_tombs = (size_t) 0;
    l9 = (void*) _a26_obj;
    vader_array_t* _a27_arr = vader_array_new(39u, 0u, 13u, 485u);
    l10 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(9u, 0u, 7u, 193u);
    l11 = (void*) _a28_arr;
    vader_array_t* _a29_arr = vader_array_new(9u, 0u, 7u, 193u);
    l12 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(9u, 0u, 7u, 193u);
    l13 = (void*) _a30_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a31_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a31_obj, 295u);
    _a31_obj->f_ekeys = l11;
    _a31_obj->f_evals = l12;
    _a31_obj->f_index = l13;
    _a31_obj->f_mask = (size_t) 0;
    _a31_obj->f_size = (size_t) 0;
    _a31_obj->f_tombs = (size_t) 0;
    l11 = (void*) _a31_obj;
    vader_array_t* _a32_arr = vader_array_new(8u, 0u, 0u, 190u);
    l12 = (void*) _a32_arr;
    vader_array_t* _a33_arr = vader_array_new(9u, 0u, 7u, 193u);
    l13 = (void*) _a33_arr;
    vader_array_t* _a34_arr = vader_array_new(9u, 0u, 7u, 193u);
    l14 = (void*) _a34_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a35_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a35_obj, 343u);
    _a35_obj->f_ekeys = l12;
    _a35_obj->f_evals = l13;
    _a35_obj->f_index = l14;
    _a35_obj->f_mask = (size_t) 0;
    _a35_obj->f_size = (size_t) 0;
    _a35_obj->f_tombs = (size_t) 0;
    l12 = (void*) _a35_obj;
    vader_array_t* _a36_arr = vader_array_new(36u, 0u, 13u, 481u);
    l13 = (void*) _a36_arr;
    vader_array_t* _a37_arr = vader_array_new(9u, 0u, 7u, 193u);
    l14 = (void*) _a37_arr;
    vader_array_t* _a38_arr = vader_array_new(9u, 0u, 7u, 193u);
    l15 = (void*) _a38_arr;
    vader_array_t* _a39_arr = vader_array_new(16u, 0u, 0u, 201u);
    l16 = (void*) _a39_arr;
    vader_array_t* _a40_arr = vader_array_new(9u, 0u, 7u, 193u);
    l17 = (void*) _a40_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a41_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a41_obj, 267u);
    _a41_obj->f_ekeys = l15;
    _a41_obj->f_evals = l16;
    _a41_obj->f_index = l17;
    _a41_obj->f_mask = (size_t) 0;
    _a41_obj->f_size = (size_t) 0;
    _a41_obj->f_tombs = (size_t) 0;
    l15 = (void*) _a41_obj;
    vader_struct_vader_bytecode_EmitterCtx_t* _a42_obj = (vader_struct_vader_bytecode_EmitterCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_EmitterCtx_t));
    vader_obj_header_init(_a42_obj, 528u);
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
    vader_box_t t0;
    if (l0 == 1579u) {
        t0 = vader_box_i32(196u, INT32_C(0));
        return t0;
    }
    if (l0 == 1534u) {
        t0 = vader_box_i32(196u, INT32_C(1));
        return t0;
    }
    if (l0 == 1535u) {
        t0 = vader_box_i32(196u, INT32_C(2));
        return t0;
    }
    if (l0 == 1557u) {
        t0 = vader_box_i32(196u, INT32_C(3));
        return t0;
    }
    if (l0 == 1654u) {
        t0 = vader_box_i32(196u, INT32_C(4));
        return t0;
    }
    if (l0 == 2155u) {
        t0 = vader_box_i32(196u, INT32_C(5));
        return t0;
    }
    if (l0 == 2136u) {
        t0 = vader_box_i32(196u, INT32_C(6));
        return t0;
    }
    if (l0 == 2137u) {
        t0 = vader_box_i32(196u, INT32_C(7));
        return t0;
    }
    if (l0 == 2146u) {
        t0 = vader_box_i32(196u, INT32_C(8));
        return t0;
    }
    if (l0 == 2198u) {
        t0 = vader_box_i32(196u, INT32_C(9));
        return t0;
    }
    if (l0 == 1425u) {
        t0 = vader_box_i32(196u, INT32_C(10));
        return t0;
    }
    if (l0 == 1428u) {
        t0 = vader_box_i32(196u, INT32_C(11));
        return t0;
    }
    if (l0 == 1144u) {
        t0 = vader_box_i32(196u, INT32_C(12));
        return t0;
    }
    if (l0 == 1254u) {
        t0 = vader_box_i32(196u, INT32_C(13));
        return t0;
    }
    if (l0 == 2008u) {
        t0 = vader_box_i32(196u, INT32_C(14));
        return t0;
    }
    if (l0 == 1815u) {
        t0 = vader_box_i32(196u, INT32_C(15));
        return t0;
    }
    if (l0 == 2334u) {
        t0 = vader_box_i32(196u, INT32_C(16));
        return t0;
    }
    if (l0 == 1856u) {
        t0 = vader_box_i32(196u, INT32_C(17));
        return t0;
    }
    if (l0 == 1878u) {
        t0 = vader_box_i32(196u, INT32_C(18));
        return t0;
    }
    if (l0 == 1061u) {
        t0 = vader_box_i32(196u, INT32_C(19));
        return t0;
    }
    t0 = vader_box_obj(0u, NULL);
    return t0;
}

static vader_box_t vader_bytecode_primitive_arith_op(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    bool l2;
    vader_string_t t0 = 0;
    uint8_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_strip_core_member(l0, 156u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_types_is_numeric_name(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        t1 = vader_bytecode_val_type_of_primitive_name(t0);
        t2 = vader_bytecode_arith_op(t1, 1040u);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_bytecode_strip_core_member(l0, 167u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_types_is_numeric_name(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        t1 = vader_bytecode_val_type_of_primitive_name(t0);
        t2 = vader_bytecode_arith_op(t1, 2041u);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_bytecode_strip_core_member(l0, 166u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_types_is_numeric_name(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        t1 = vader_bytecode_val_type_of_primitive_name(t0);
        t2 = vader_bytecode_arith_op(t1, 1782u);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_bytecode_strip_core_member(l0, 161u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_types_is_numeric_name(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        t1 = vader_bytecode_val_type_of_primitive_name(t0);
        t2 = vader_bytecode_div_op(t1);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_primitive_cmp_op(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    bool l2;
    vader_string_t t0 = 0;
    uint8_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_strip_core_member(l0, 162u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_bytecode_is_op_eq_prim(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        t1 = vader_bytecode_val_type_of_primitive_name(t0);
        t2 = vader_bytecode_cmp_eq(t1);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_bytecode_strip_core_member(l0, 163u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_bytecode_is_op_eq_prim(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        t1 = vader_bytecode_val_type_of_primitive_name(t0);
        t2 = vader_bytecode_cmp_ne(t1);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_bytecode_primitive_member_mangle(vader_string_t l0, vader_string_t l1, vader_string_t l2) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = concat_6(1957u, l0, 155u, l1, 155u, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_propagate_const_single_use(void* l0) {
    size_t l1, l2, l8, l12, l14, l15, l16, l18;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l11 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    int32_t l9, l10, l17, l19, l20;
    vader_box_t l13 = vader_box_null(), l26 = vader_box_null(), l28 = vader_box_null(), l29 = vader_box_null(), l30 = vader_box_null();
    bool l25;
    uint8_t l27;
    vader_string_t l31 = 0;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    bool t3;
    vader_box_t t4 = vader_box_null();
    size_t t5;
    vader_box_t* gc_roots[6] = { &l13, &l26, &l28, &l29, &l30, &t4 };
    void** gc_raw_roots[12] = { &l0, &l3, &l4, &l5, &l6, &l7, &l11, &l21, &l22, &l23, &l24, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l31 };
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
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 193u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 193u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 193u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 193u);
    l7 = (void*) _a4_arr;
    l8 = (size_t) 0;
    {
        loop_30: {
            if ((l8 < l2)) {
                vader_array_push_i32((vader_array_t*) l3, INT32_C(0));
                vader_array_push_i32((vader_array_t*) l4, INT32_C(0));
                vader_array_push_i32((vader_array_t*) l5, INT32_C(0));
                l9 = -(INT32_C(1));
                vader_array_push_i32((vader_array_t*) l6, l9);
                l10 = -(INT32_C(1));
                vader_array_push_i32((vader_array_t*) l7, l10);
                t0 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t0;
                goto loop_30;
            }
        }
    }
    l11 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    l8 = ((vader_array_t*) l11)->length;
    l12 = (size_t) 0;
    {
        loop_71: {
            if ((l12 < l8)) {
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l12)
                l13 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l12);
                if (l13.tag == 597u) {
                    t1 = l13.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_LocalSet_t*) t1)->f_slot;
                    t0 = ((int64_t) (int32_t) t2);
                    l14 = (size_t) (int64_t) t0;
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l14)
                    t2 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l14];
                    l9 = (t2 + INT32_C(1));
                    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l14)
                    ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l14] = (int32_t) l9;
                    l10 = ((int32_t) (size_t) l12);
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l6);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l14)
                    ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l14] = (int32_t) l10;
                }
                if (l13.tag == 598u) {
                    t1 = l13.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_LocalTee_t*) t1)->f_slot;
                    t0 = ((int64_t) (int32_t) t2);
                    l15 = (size_t) (int64_t) t0;
                    t1 = l13.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_LocalTee_t*) t1)->f_slot;
                    t0 = ((int64_t) (int32_t) t2);
                    l16 = (size_t) (int64_t) t0;
                    vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l16)
                    t2 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l16];
                    l17 = (t2 + INT32_C(1));
                    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l15)
                    ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l15] = (int32_t) l17;
                }
                if (l13.tag == 596u) {
                    t1 = l13.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_LocalGet_t*) t1)->f_slot;
                    t0 = ((int64_t) (int32_t) t2);
                    l18 = (size_t) (int64_t) t0;
                    vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                    VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l18)
                    t2 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l18];
                    l19 = (t2 + INT32_C(1));
                    VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l18)
                    ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l18] = (int32_t) l19;
                    l20 = ((int32_t) (size_t) l12);
                    vader_array_t* _a10_slotarr = ((vader_array_t*) l7);
                    VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l18)
                    ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l18] = (int32_t) l20;
                }
                t0 = (l12 + INT64_C(1));
                l12 = (size_t) (int64_t) t0;
                goto loop_71;
            }
        }
    }
    vader_array_t* _a11_arr = vader_array_new(9u, 0u, 7u, 193u);
    l21 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(6u, 0u, 12u, 188u);
    l22 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(9u, 0u, 7u, 193u);
    l23 = (void*) _a13_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a14_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a14_obj, 294u);
    _a14_obj->f_ekeys = l21;
    _a14_obj->f_evals = l22;
    _a14_obj->f_index = l23;
    _a14_obj->f_mask = (size_t) 0;
    _a14_obj->f_size = (size_t) 0;
    _a14_obj->f_tombs = (size_t) 0;
    l21 = (void*) _a14_obj;
    vader_array_t* _a15_arr = vader_array_new(9u, 0u, 7u, 193u);
    l22 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(16u, 0u, 0u, 201u);
    l23 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(9u, 0u, 7u, 193u);
    l24 = (void*) _a17_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a18_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a18_obj, 265u);
    _a18_obj->f_ekeys = l22;
    _a18_obj->f_evals = l23;
    _a18_obj->f_index = l24;
    _a18_obj->f_mask = (size_t) 0;
    _a18_obj->f_size = (size_t) 0;
    _a18_obj->f_tombs = (size_t) 0;
    l22 = (void*) _a18_obj;
    l12 = l1;
    {
        loop_198: {
            if ((l12 < l2)) {
                l25 = true;
                vader_array_t* _a19_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l12)
                t2 = ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l12];
                if (t2 != INT32_C(0)) {
                    l25 = false;
                }
                vader_array_t* _a20_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l12)
                t2 = ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l12];
                if (t2 != INT32_C(1)) {
                    l25 = false;
                }
                vader_array_t* _a21_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l12)
                t2 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l12];
                if (t2 != INT32_C(1)) {
                    l25 = false;
                }
                l9 = -(INT32_C(1));
                l10 = -(INT32_C(1));
                if (l25) {
                    vader_array_t* _a22_slotarr = ((vader_array_t*) l6);
                    VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l12)
                    l9 = ((int32_t*) _a22_slotarr->buf->slots)[_a22_slotarr->offset + (size_t) l12];
                    vader_array_t* _a23_slotarr = ((vader_array_t*) l7);
                    VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l12)
                    l10 = ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l12];
                    if ((l9 <= INT32_C(0))) {
                        l25 = false;
                    }
                    if ((l10 <= l9)) {
                        l25 = false;
                    }
                }
                if (l25) {
                    t0 = ((int64_t) (int32_t) (l9 - INT32_C(1)));
                    l14 = (size_t) (int64_t) t0;
                    vader_array_t* _a24_slotarr = ((vader_array_t*) l11);
                    VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l14)
                    l13 = vader_array_ref_load_box(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l14);
                    l26 = vader_bytecode_const_op_of(l13);
                    if (l26.tag == 0u) {
                        l25 = false;
                    } else {
                        l23 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
                        t0 = (l12 - l1);
                        l15 = (size_t) (int64_t) t0;
                        vader_array_t* _a25_slotarr = ((vader_array_t*) l23);
                        VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l15)
                        t1 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l15);
                        l27 = ((vader_struct_vader_bytecode_BcLocal_t*) t1)->f_val;
                        t3 = vader_bytecode_const_fills_slot(l26, l27);
                        if (!(t3)) {
                            l25 = false;
                        } else {
                            l17 = (l9 - INT32_C(1));
                            std_collections_MutableMap_IndexSet_set_at__i32__bool(l21, l17, true);
                            std_collections_MutableMap_IndexSet_set_at__i32__bool(l21, l9, true);
                            std_collections_MutableMap_IndexSet_set_at__i32__Any(l22, l10, l13);
                        }
                    }
                }
                t0 = (l12 + INT64_C(1));
                l12 = (size_t) (int64_t) t0;
                goto loop_198;
            }
        }
    }
    t3 = std_collections_is_empty__i32__bool(l21);
    if (t3) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a26_arr = vader_array_new(138u, 0u, 13u, 1148u);
    l3 = (void*) _a26_arr;
    vader_array_t* _a27_arr = vader_array_new(143u, 0u, 13u, 1181u);
    l4 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(9u, 0u, 7u, 193u);
    l5 = (void*) _a28_arr;
    l1 = (size_t) 0;
    {
        vader_array_t* _pc342_hdr = (vader_array_t*) l5;
        size_t _pc342_len = _pc342_hdr->length;
        size_t _pc342_cap = (_pc342_hdr->offset == 0 && !vader_array_is_borrowed(_pc342_hdr) && _pc342_hdr->length >= _pc342_hdr->buf->length) ? _pc342_hdr->capacity : (size_t) 0;
        void* _pc342_slots = _pc342_hdr->buf->slots;
        loop_342: {
            if ((l1 < l8)) {
                l9 = -(INT32_C(1));
                if (VADER_LIKELY(_pc342_len < _pc342_cap)) {
                    ((int32_t*) _pc342_slots)[_pc342_len] = (int32_t) (l9);
                    _pc342_len += 1;
                } else {
                    _pc342_hdr->length = _pc342_len;
                    if (_pc342_hdr->buf->length < _pc342_len) {
                        _pc342_hdr->buf->length = _pc342_len;
                    }
                    vader_array_push_i32((vader_array_t*) l5, l9);
                    _pc342_hdr = (vader_array_t*) l5;
                    _pc342_len = _pc342_hdr->length;
                    _pc342_cap = (_pc342_hdr->offset == 0 && !vader_array_is_borrowed(_pc342_hdr) && _pc342_hdr->length >= _pc342_hdr->buf->length) ? _pc342_hdr->capacity : (size_t) 0;
                    _pc342_slots = _pc342_hdr->buf->slots;
                }
                t0 = (l1 + INT64_C(1));
                l1 = (size_t) (int64_t) t0;
                goto loop_342;
            }
            _pc342_hdr->length = _pc342_len;
            if (_pc342_hdr->buf->length < _pc342_len) {
                _pc342_hdr->buf->length = _pc342_len;
            }
        }
    }
    l1 = (size_t) 0;
    {
        loop_364: {
            if ((l1 < l8)) {
                l9 = ((int32_t) (size_t) l1);
                t4 = std_collections_MutableMap_Index_at__i32__bool(l21, l9);
                if (t4.tag == 188u) {
                    t0 = (l1 + INT64_C(1));
                    l1 = (size_t) (int64_t) t0;
                    goto loop_364;
                }
                l10 = ((int32_t) (size_t) l1);
                l13 = std_collections_MutableMap_Index_at__i32__Any(l22, l10);
                if (l13.tag == 0u) {
                    t5 = ((vader_array_t*) l3)->length;
                    l17 = ((int32_t) (size_t) t5);
                    vader_array_t* _a29_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l1)
                    ((int32_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l1] = (int32_t) l17;
                    vader_array_t* _a30_slotarr = ((vader_array_t*) l11);
                    VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l1)
                    l26 = vader_array_ref_load_box(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l1);
                    vader_array_push((vader_array_t*) l3, l26);
                    vader_array_t* _a31_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug);
                    VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l1)
                    l28 = vader_array_ref_load_box(_a31_slotarr->buf, _a31_slotarr->offset + (size_t) l1);
                    vader_array_push((vader_array_t*) l4, l28);
                } else {
                    t5 = ((vader_array_t*) l3)->length;
                    l19 = ((int32_t) (size_t) t5);
                    vader_array_t* _a32_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l1)
                    ((int32_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) l1] = (int32_t) l19;
                    l29 = l13;
                    vader_array_push((vader_array_t*) l3, l29);
                    vader_array_t* _a33_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug);
                    VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l1)
                    l30 = vader_array_ref_load_box(_a33_slotarr->buf, _a33_slotarr->offset + (size_t) l1);
                    vader_array_push((vader_array_t*) l4, l30);
                }
                t0 = (l1 + INT64_C(1));
                l1 = (size_t) (int64_t) t0;
                goto loop_364;
            }
        }
    }
    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l1 = ((vader_array_t*) l3)->length;
    l5 = vader_bytecode_remap_jump_table(l6, l5, l1);
    l31 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_name;
    l25 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_is_main;
    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature;
    l7 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
    vader_struct_vader_bytecode_BcFunction_t* _a34_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a34_obj, 484u);
    _a34_obj->f_name = l31;
    _a34_obj->f_is_main = l25;
    _a34_obj->f_signature = l6;
    _a34_obj->f_locals = l7;
    _a34_obj->f_body = l3;
    _a34_obj->f_debug = l4;
    _a34_obj->f_jump_table = l5;
    t1 = (void*) _a34_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_bytecode_prune_unused_functions(void* l0, void* l1, void* l2) {
    size_t l3, l7, l11, l15, l16, l17, l18, l32;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l31 = NULL;
    void* l33 = NULL;
    int32_t l8, l10, l20, l24, l25;
    vader_string_t l9 = 0;
    vader_string_t l34 = 0;
    bool l12, l21, l22, l23;
    vader_box_t l19 = vader_box_null();
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    size_t t4;
    int32_t t5;
    vader_string_t t6 = 0;
    vader_box_t* gc_roots[2] = { &l19, &t3 };
    void** gc_raw_roots[16] = {
        &l0, &l1, &l2, &l4, &l5, &l6, &l13, &l14, &l26, &l27, &l28, &l29, &l30, &l31, &l33, &t2,
    };
    vader_string_t* gc_atom_roots[3] = { &l9, &l34, &t6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 16u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions)->length;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 188u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 193u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 294u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l5;
    _a3_obj->f_index = l6;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l4 = (void*) _a3_obj;
    l7 = (size_t) 0;
    {
        loop_20: {
            if ((l7 < l3)) {
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
                goto loop_20;
            }
        }
    }
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_exports;
    l7 = ((vader_array_t*) l5)->length;
    l11 = (size_t) 0;
    {
        loop_70: {
            if ((l11 < l7)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l11)
                t2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l11);
                l8 = ((vader_struct_vader_bytecode_BcExport_t*) t2)->f_fn_index;
                std_collections_MutableMap_IndexSet_set_at__i32__bool(l4, l8, true);
                t1 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t1;
                goto loop_70;
            }
        }
    }
    l5 = l1;
    l7 = ((vader_array_t*) l5)->length;
    l11 = (size_t) 0;
    {
        loop_100: {
            if ((l11 < l7)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l11)
                l8 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l11];
                if ((l8 >= INT32_C(0))) {
                    l10 = ((int32_t) (size_t) l3);
                    l12 = (l8 < l10);
                } else {
                    l12 = false;
                }
                if (l12) {
                    std_collections_MutableMap_IndexSet_set_at__i32__bool(l4, l8, true);
                }
                t1 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t1;
                goto loop_100;
            }
        }
    }
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 193u);
    l5 = (void*) _a7_arr;
    l6 = l4;
    l13 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l6)->f_ekeys;
    l14 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l6)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l6)->f_size;
    l11 = (size_t) 0;
    {
        loop_152: {
            if ((l11 >= l7)) {
            } else {
                vader_array_t* _a8_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l11)
                l8 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l11];
                vader_array_t* _a9_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l11)
                t3 = vader_box_bool(188u, ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l11]);
                t0 = t3.payload.b;
                l10 = l8;
                t1 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t1;
                vader_array_push_i32((vader_array_t*) l5, l10);
                goto loop_152;
            }
        }
    }
    {
        loop_181: {
            t4 = ((vader_array_t*) l5)->length;
            if ((t4 > INT64_C(0))) {
                t4 = ((vader_array_t*) l5)->length;
                t1 = (t4 - INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l7)
                l8 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l7];
                vader_array_t* _a11_arr = vader_array_new(9u, 0u, 7u, 193u);
                l6 = (void*) _a11_arr;
                t4 = ((vader_array_t*) l5)->length;
                t1 = (t4 - INT64_C(1));
                l11 = (size_t) (int64_t) t1;
                l15 = (size_t) 0;
                {
                    vader_array_t* _pc206_hdr = (vader_array_t*) l6;
                    size_t _pc206_len = _pc206_hdr->length;
                    size_t _pc206_cap = (_pc206_hdr->offset == 0 && !vader_array_is_borrowed(_pc206_hdr) && _pc206_hdr->length >= _pc206_hdr->buf->length) ? _pc206_hdr->capacity : (size_t) 0;
                    void* _pc206_slots = _pc206_hdr->buf->slots;
                    loop_206: {
                        if ((l15 < l11)) {
                            vader_array_t* _a12_slotarr = ((vader_array_t*) l5);
                            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l15)
                            l10 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l15];
                            if (VADER_LIKELY(_pc206_len < _pc206_cap)) {
                                ((int32_t*) _pc206_slots)[_pc206_len] = (int32_t) (l10);
                                _pc206_len += 1;
                            } else {
                                _pc206_hdr->length = _pc206_len;
                                if (_pc206_hdr->buf->length < _pc206_len) {
                                    _pc206_hdr->buf->length = _pc206_len;
                                }
                                vader_array_push_i32((vader_array_t*) l6, l10);
                                _pc206_hdr = (vader_array_t*) l6;
                                _pc206_len = _pc206_hdr->length;
                                _pc206_cap = (_pc206_hdr->offset == 0 && !vader_array_is_borrowed(_pc206_hdr) && _pc206_hdr->length >= _pc206_hdr->buf->length) ? _pc206_hdr->capacity : (size_t) 0;
                                _pc206_slots = _pc206_hdr->buf->slots;
                            }
                            t1 = (l15 + INT64_C(1));
                            l15 = (size_t) (int64_t) t1;
                            goto loop_206;
                        }
                        _pc206_hdr->length = _pc206_len;
                        if (_pc206_hdr->buf->length < _pc206_len) {
                            _pc206_hdr->buf->length = _pc206_len;
                        }
                    }
                }
                l5 = l6;
                if ((((int64_t) (int32_t) l8) >= l3)) {
                    goto loop_181;
                }
                l13 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
                t1 = ((int64_t) (int32_t) l8);
                l16 = (size_t) (int64_t) t1;
                vader_array_t* _a13_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l16)
                t2 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l16);
                l14 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_body;
                l17 = ((vader_array_t*) l14)->length;
                l18 = (size_t) 0;
                {
                    loop_250: {
                        if ((l18 < l17)) {
                            vader_array_t* _a14_slotarr = ((vader_array_t*) l14);
                            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l18)
                            l19 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l18);
                            l20 = -(INT32_C(1));
                            if (l19.tag == 516u) {
                                t2 = l19.payload.obj;
                                l20 = ((vader_struct_vader_bytecode_Call_t*) t2)->f_function_index;
                            }
                            if (l19.tag == 545u) {
                                t2 = l19.payload.obj;
                                l20 = ((vader_struct_vader_bytecode_FnRef_t*) t2)->f_function_index;
                            }
                            if (l19.tag == 544u) {
                                t2 = l19.payload.obj;
                                l20 = ((vader_struct_vader_bytecode_FnAddr_t*) t2)->f_function_index;
                            }
                            if (l19.tag == 600u) {
                                t2 = l19.payload.obj;
                                l20 = ((vader_struct_vader_bytecode_MakeClosure_t*) t2)->f_function_index;
                            }
                            if ((l20 < INT32_C(0))) {
                                t1 = (l18 + INT64_C(1));
                                l18 = (size_t) (int64_t) t1;
                                goto loop_250;
                            }
                            t3 = std_collections_MutableMap_Index_at__i32__bool(l4, l20);
                            if (t3.tag == 188u) {
                                t1 = (l18 + INT64_C(1));
                                l18 = (size_t) (int64_t) t1;
                                goto loop_250;
                            }
                            std_collections_MutableMap_IndexSet_set_at__i32__bool(l4, l20, true);
                            vader_array_push_i32((vader_array_t*) l5, l20);
                            t1 = (l18 + INT64_C(1));
                            l18 = (size_t) (int64_t) t1;
                            goto loop_250;
                        }
                    }
                }
                goto loop_181;
            }
        }
    }
    l12 = std_collections_is_empty__i32__bool(l4);
    vader_array_t* _a15_arr = vader_array_new(8u, 0u, 0u, 190u);
    l5 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(9u, 0u, 7u, 193u);
    l6 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(9u, 0u, 7u, 193u);
    l13 = (void*) _a17_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a18_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a18_obj, 343u);
    _a18_obj->f_ekeys = l5;
    _a18_obj->f_evals = l6;
    _a18_obj->f_index = l13;
    _a18_obj->f_mask = (size_t) 0;
    _a18_obj->f_size = (size_t) 0;
    _a18_obj->f_tombs = (size_t) 0;
    l5 = (void*) _a18_obj;
    l21 = false;
    l7 = (size_t) 0;
    {
        loop_360: {
            if ((l7 < l3)) {
                if (l12) {
                    l22 = true;
                } else {
                    l8 = ((int32_t) (size_t) l7);
                    t3 = std_collections_MutableMap_Index_at__i32__bool(l4, l8);
                    l22 = t3.tag == 188u;
                }
                if (l22) {
                    vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
                    VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l7)
                    t2 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l7);
                    l9 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_name;
                    if (l9 != 0u) {
                        l19 = std_collections_MutableMap_Index_at__string__i32(l5, l9);
                        if (l19.tag == 193u) {
                            l21 = true;
                            vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
                            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l7)
                            t2 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l7);
                            t4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_body)->length;
                            if ((t4 > INT64_C(0))) {
                                l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
                                t5 = ((int32_t) l19.payload.i);
                                t1 = ((int64_t) (int32_t) t5);
                                l11 = (size_t) (int64_t) t1;
                                vader_array_t* _a21_slotarr = ((vader_array_t*) l6);
                                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l11)
                                t2 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l11);
                                t4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_body)->length;
                                l23 = t4 == INT64_C(0);
                            } else {
                                l23 = false;
                            }
                            if (l23) {
                                l10 = ((int32_t) (size_t) l7);
                                std_collections_MutableMap_IndexSet_set_at__string__i32(l5, l9, l10);
                            }
                        } else {
                            l20 = ((int32_t) (size_t) l7);
                            std_collections_MutableMap_IndexSet_set_at__string__i32(l5, l9, l20);
                        }
                    }
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_360;
            }
        }
    }
    if (!(l21)) {
        if (l12) {
            l22 = true;
        } else {
            t4 = std_collections_len__i32__bool(l4);
            l22 = t4 == l3;
        }
        l21 = l22;
    } else {
        l21 = false;
    }
    if (l21) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a22_arr = vader_array_new(9u, 0u, 7u, 193u);
    l6 = (void*) _a22_arr;
    l7 = (size_t) 0;
    {
        loop_482: {
            if ((l7 < l3)) {
                vader_array_t* _a23_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
                VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l7)
                t2 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l7);
                l9 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_name;
                l8 = ((int32_t) (size_t) l7);
                if (l9 != 0u) {
                    l19 = std_collections_MutableMap_Index_at__string__i32(l5, l9);
                    if (l19.tag == 193u) {
                        l8 = ((int32_t) l19.payload.i);
                    }
                }
                vader_array_push_i32((vader_array_t*) l6, l8);
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_482;
            }
        }
    }
    vader_array_t* _a24_arr = vader_array_new(9u, 0u, 7u, 193u);
    l5 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(9u, 0u, 7u, 193u);
    l13 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(9u, 0u, 7u, 193u);
    l14 = (void*) _a26_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a27_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a27_obj, 295u);
    _a27_obj->f_ekeys = l5;
    _a27_obj->f_evals = l13;
    _a27_obj->f_index = l14;
    _a27_obj->f_mask = (size_t) 0;
    _a27_obj->f_size = (size_t) 0;
    _a27_obj->f_tombs = (size_t) 0;
    l5 = (void*) _a27_obj;
    vader_array_t* _a28_arr = vader_array_new(38u, 0u, 13u, 484u);
    l13 = (void*) _a28_arr;
    l7 = (size_t) 0;
    {
        loop_541: {
            if ((l7 < l3)) {
                if (l12) {
                    l21 = true;
                } else {
                    l8 = ((int32_t) (size_t) l7);
                    t3 = std_collections_MutableMap_Index_at__i32__bool(l4, l8);
                    l21 = t3.tag == 188u;
                }
                if (l21) {
                    vader_array_t* _a29_slotarr = ((vader_array_t*) l6);
                    VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l7)
                    l10 = ((int32_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l7];
                    l20 = ((int32_t) (size_t) l7);
                    l22 = l10 == l20;
                } else {
                    l22 = false;
                }
                if (l22) {
                    l24 = ((int32_t) (size_t) l7);
                    t4 = ((vader_array_t*) l13)->length;
                    l25 = ((int32_t) (size_t) t4);
                    std_collections_MutableMap_IndexSet_set_at__i32__i32(l5, l24, l25);
                    vader_array_t* _a30_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
                    VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l7)
                    l14 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l7);
                    vader_array_push((vader_array_t*) l13, vader_ref_box(l14));
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_541;
            }
        }
    }
    vader_array_t* _a31_arr = vader_array_new(9u, 0u, 7u, 193u);
    l14 = (void*) _a31_arr;
    l7 = (size_t) 0;
    {
        vader_array_t* _pc611_hdr = (vader_array_t*) l14;
        size_t _pc611_len = _pc611_hdr->length;
        size_t _pc611_cap = (_pc611_hdr->offset == 0 && !vader_array_is_borrowed(_pc611_hdr) && _pc611_hdr->length >= _pc611_hdr->buf->length) ? _pc611_hdr->capacity : (size_t) 0;
        void* _pc611_slots = _pc611_hdr->buf->slots;
        loop_611: {
            if ((l7 < l3)) {
                l8 = -(INT32_C(1));
                if (l12) {
                    l21 = true;
                } else {
                    l10 = ((int32_t) (size_t) l7);
                    t3 = std_collections_MutableMap_Index_at__i32__bool(l4, l10);
                    l21 = t3.tag == 188u;
                }
                if (l21) {
                    vader_array_t* _a32_slotarr = ((vader_array_t*) l6);
                    VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l7)
                    l20 = ((int32_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) l7];
                    l19 = std_collections_MutableMap_Index_at__i32__i32(l5, l20);
                    if (l19.tag == 193u) {
                        l8 = ((int32_t) l19.payload.i);
                    }
                }
                if (VADER_LIKELY(_pc611_len < _pc611_cap)) {
                    ((int32_t*) _pc611_slots)[_pc611_len] = (int32_t) (l8);
                    _pc611_len += 1;
                } else {
                    _pc611_hdr->length = _pc611_len;
                    if (_pc611_hdr->buf->length < _pc611_len) {
                        _pc611_hdr->buf->length = _pc611_len;
                    }
                    vader_array_push_i32((vader_array_t*) l14, l8);
                    _pc611_hdr = (vader_array_t*) l14;
                    _pc611_len = _pc611_hdr->length;
                    _pc611_cap = (_pc611_hdr->offset == 0 && !vader_array_is_borrowed(_pc611_hdr) && _pc611_hdr->length >= _pc611_hdr->buf->length) ? _pc611_hdr->capacity : (size_t) 0;
                    _pc611_slots = _pc611_hdr->buf->slots;
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_611;
            }
            _pc611_hdr->length = _pc611_len;
            if (_pc611_hdr->buf->length < _pc611_len) {
                _pc611_hdr->buf->length = _pc611_len;
            }
        }
    }
    l4 = l13;
    l3 = ((vader_array_t*) l4)->length;
    l7 = (size_t) 0;
    {
        loop_668: {
            if ((l7 < l3)) {
                vader_array_t* _a33_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l7)
                l5 = vader_array_ref_load_obj(_a33_slotarr->buf, _a33_slotarr->offset + (size_t) l7);
                l11 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body)->length;
                l15 = (size_t) 0;
                {
                    loop_683: {
                        if ((l15 < l11)) {
                            vader_array_t* _a34_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body);
                            VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l15)
                            l19 = vader_array_ref_load_box(_a34_slotarr->buf, _a34_slotarr->offset + (size_t) l15);
                            if (l19.tag == 516u) {
                                l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body;
                                t2 = l19.payload.obj;
                                t5 = ((vader_struct_vader_bytecode_Call_t*) t2)->f_function_index;
                                t1 = ((int64_t) (int32_t) t5);
                                l16 = (size_t) (int64_t) t1;
                                vader_array_t* _a35_slotarr = ((vader_array_t*) l14);
                                VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l16)
                                t5 = ((int32_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l16];
                                vader_struct_vader_bytecode_Call_t* _a36_obj = (vader_struct_vader_bytecode_Call_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Call_t));
                                vader_obj_header_init(_a36_obj, 516u);
                                _a36_obj->f_function_index = t5;
                                l26 = (void*) _a36_obj;
                                vader_array_t* _a37_slotarr = ((vader_array_t*) l6);
                                VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l15)
                                vader_array_ref_store(_a37_slotarr->buf, _a37_slotarr->offset + (size_t) l15, l26);
                                VADER_WRITE_BARRIER(_a37_slotarr->buf);
                            }
                            if (l19.tag == 545u) {
                                l27 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body;
                                t2 = l19.payload.obj;
                                t5 = ((vader_struct_vader_bytecode_FnRef_t*) t2)->f_function_index;
                                t1 = ((int64_t) (int32_t) t5);
                                l17 = (size_t) (int64_t) t1;
                                vader_array_t* _a38_slotarr = ((vader_array_t*) l14);
                                VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l17)
                                l8 = ((int32_t*) _a38_slotarr->buf->slots)[_a38_slotarr->offset + (size_t) l17];
                                t2 = l19.payload.obj;
                                l10 = ((vader_struct_vader_bytecode_FnRef_t*) t2)->f_type_id;
                                vader_struct_vader_bytecode_FnRef_t* _a39_obj = (vader_struct_vader_bytecode_FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnRef_t));
                                vader_obj_header_init(_a39_obj, 545u);
                                _a39_obj->f_function_index = l8;
                                _a39_obj->f_type_id = l10;
                                l28 = (void*) _a39_obj;
                                vader_array_t* _a40_slotarr = ((vader_array_t*) l27);
                                VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l15)
                                vader_array_ref_store(_a40_slotarr->buf, _a40_slotarr->offset + (size_t) l15, l28);
                                VADER_WRITE_BARRIER(_a40_slotarr->buf);
                            }
                            if (l19.tag == 544u) {
                                l29 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body;
                                t2 = l19.payload.obj;
                                t5 = ((vader_struct_vader_bytecode_FnAddr_t*) t2)->f_function_index;
                                t1 = ((int64_t) (int32_t) t5);
                                l18 = (size_t) (int64_t) t1;
                                vader_array_t* _a41_slotarr = ((vader_array_t*) l14);
                                VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l18)
                                t5 = ((int32_t*) _a41_slotarr->buf->slots)[_a41_slotarr->offset + (size_t) l18];
                                vader_struct_vader_bytecode_FnAddr_t* _a42_obj = (vader_struct_vader_bytecode_FnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnAddr_t));
                                vader_obj_header_init(_a42_obj, 544u);
                                _a42_obj->f_function_index = t5;
                                l30 = (void*) _a42_obj;
                                vader_array_t* _a43_slotarr = ((vader_array_t*) l29);
                                VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l15)
                                vader_array_ref_store(_a43_slotarr->buf, _a43_slotarr->offset + (size_t) l15, l30);
                                VADER_WRITE_BARRIER(_a43_slotarr->buf);
                            }
                            if (l19.tag == 600u) {
                                l31 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body;
                                t2 = l19.payload.obj;
                                t5 = ((vader_struct_vader_bytecode_MakeClosure_t*) t2)->f_function_index;
                                t1 = ((int64_t) (int32_t) t5);
                                l32 = (size_t) (int64_t) t1;
                                vader_array_t* _a44_slotarr = ((vader_array_t*) l14);
                                VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l32)
                                l20 = ((int32_t*) _a44_slotarr->buf->slots)[_a44_slotarr->offset + (size_t) l32];
                                t2 = l19.payload.obj;
                                l24 = ((vader_struct_vader_bytecode_MakeClosure_t*) t2)->f_env_type_id;
                                vader_struct_vader_bytecode_MakeClosure_t* _a45_obj = (vader_struct_vader_bytecode_MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_MakeClosure_t));
                                vader_obj_header_init(_a45_obj, 600u);
                                _a45_obj->f_function_index = l20;
                                _a45_obj->f_env_type_id = l24;
                                l33 = (void*) _a45_obj;
                                vader_array_t* _a46_slotarr = ((vader_array_t*) l31);
                                VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l15)
                                vader_array_ref_store(_a46_slotarr->buf, _a46_slotarr->offset + (size_t) l15, l33);
                                VADER_WRITE_BARRIER(_a46_slotarr->buf);
                            }
                            t1 = (l15 + INT64_C(1));
                            l15 = (size_t) (int64_t) t1;
                            goto loop_683;
                        }
                    }
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_668;
            }
        }
    }
    vader_array_t* _a47_arr = vader_array_new(36u, 0u, 13u, 481u);
    l4 = (void*) _a47_arr;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_exports;
    l3 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    {
        loop_816: {
            if ((l7 < l3)) {
                vader_array_t* _a48_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a48_slotarr, l7)
                l6 = vader_array_ref_load_obj(_a48_slotarr->buf, _a48_slotarr->offset + (size_t) l7);
                t5 = ((vader_struct_vader_bytecode_BcExport_t*) l6)->f_fn_index;
                t1 = ((int64_t) (int32_t) t5);
                l11 = (size_t) (int64_t) t1;
                vader_array_t* _a49_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a49_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a49_slotarr, l11)
                l8 = ((int32_t*) _a49_slotarr->buf->slots)[_a49_slotarr->offset + (size_t) l11];
                if ((l8 >= INT32_C(0))) {
                    t6 = ((vader_struct_vader_bytecode_BcExport_t*) l6)->f_extern_name;
                    vader_struct_vader_bytecode_BcExport_t* _a50_obj = (vader_struct_vader_bytecode_BcExport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcExport_t));
                    vader_obj_header_init(_a50_obj, 481u);
                    _a50_obj->f_extern_name = t6;
                    _a50_obj->f_fn_index = l8;
                    l26 = (void*) _a50_obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l26));
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_816;
            }
        }
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_exports = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    vader_array_t* _a51_arr = vader_array_new(9u, 0u, 7u, 193u);
    l4 = (void*) _a51_arr;
    vader_array_t* _a52_arr = vader_array_new(9u, 0u, 7u, 193u);
    l5 = (void*) _a52_arr;
    vader_array_t* _a53_arr = vader_array_new(9u, 0u, 7u, 193u);
    l6 = (void*) _a53_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a54_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a54_obj, 295u);
    _a54_obj->f_ekeys = l4;
    _a54_obj->f_evals = l5;
    _a54_obj->f_index = l6;
    _a54_obj->f_mask = (size_t) 0;
    _a54_obj->f_size = (size_t) 0;
    _a54_obj->f_tombs = (size_t) 0;
    l4 = (void*) _a54_obj;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_function_index_by_symbol_id;
    l6 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l5)->f_ekeys;
    l26 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l5)->f_evals;
    l3 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l5)->f_size;
    l7 = (size_t) 0;
    {
        loop_882: {
            if ((l7 >= l3)) {
            } else {
                vader_array_t* _a55_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a55_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a55_slotarr, l7)
                l8 = ((int32_t*) _a55_slotarr->buf->slots)[_a55_slotarr->offset + (size_t) l7];
                vader_array_t* _a56_slotarr = ((vader_array_t*) l26);
                VADER_ARRAY_RESOLVE_BUF(_a56_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a56_slotarr, l7)
                l10 = ((int32_t*) _a56_slotarr->buf->slots)[_a56_slotarr->offset + (size_t) l7];
                l20 = l8;
                l24 = l10;
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                t1 = ((int64_t) (int32_t) l24);
                l11 = (size_t) (int64_t) t1;
                vader_array_t* _a57_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a57_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a57_slotarr, l11)
                l25 = ((int32_t*) _a57_slotarr->buf->slots)[_a57_slotarr->offset + (size_t) l11];
                if ((l25 >= INT32_C(0))) {
                    std_collections_MutableMap_IndexSet_set_at__i32__i32(l4, l20, l25);
                }
                goto loop_882;
            }
        }
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_function_index_by_symbol_id = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    vader_array_t* _a58_arr = vader_array_new(8u, 0u, 0u, 190u);
    l4 = (void*) _a58_arr;
    vader_array_t* _a59_arr = vader_array_new(9u, 0u, 7u, 193u);
    l5 = (void*) _a59_arr;
    vader_array_t* _a60_arr = vader_array_new(9u, 0u, 7u, 193u);
    l6 = (void*) _a60_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a61_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a61_obj, 343u);
    _a61_obj->f_ekeys = l4;
    _a61_obj->f_evals = l5;
    _a61_obj->f_index = l6;
    _a61_obj->f_mask = (size_t) 0;
    _a61_obj->f_size = (size_t) 0;
    _a61_obj->f_tombs = (size_t) 0;
    l4 = (void*) _a61_obj;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_function_index_by_mangle;
    l6 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l5)->f_ekeys;
    l26 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l5)->f_evals;
    l3 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l5)->f_size;
    l7 = (size_t) 0;
    {
        loop_952: {
            if ((l7 >= l3)) {
            } else {
                vader_array_t* _a62_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a62_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a62_slotarr, l7)
                t3 = vader_array_box_slots(_a62_slotarr->buf)[_a62_slotarr->offset + (size_t) l7];
                l9 = t3.payload.s;
                vader_array_t* _a63_slotarr = ((vader_array_t*) l26);
                VADER_ARRAY_RESOLVE_BUF(_a63_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a63_slotarr, l7)
                l8 = ((int32_t*) _a63_slotarr->buf->slots)[_a63_slotarr->offset + (size_t) l7];
                l34 = l9;
                l10 = l8;
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                t1 = ((int64_t) (int32_t) l10);
                l11 = (size_t) (int64_t) t1;
                vader_array_t* _a64_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a64_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a64_slotarr, l11)
                l20 = ((int32_t*) _a64_slotarr->buf->slots)[_a64_slotarr->offset + (size_t) l11];
                if ((l20 >= INT32_C(0))) {
                    std_collections_MutableMap_IndexSet_set_at__string__i32(l4, l34, l20);
                }
                goto loop_952;
            }
        }
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_function_index_by_mangle = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    vader_array_t* _a65_arr = vader_array_new(9u, 0u, 7u, 193u);
    l4 = (void*) _a65_arr;
    vader_array_t* _a66_arr = vader_array_new(16u, 0u, 0u, 201u);
    l5 = (void*) _a66_arr;
    vader_array_t* _a67_arr = vader_array_new(9u, 0u, 7u, 193u);
    l6 = (void*) _a67_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a68_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a68_obj, 267u);
    _a68_obj->f_ekeys = l4;
    _a68_obj->f_evals = l5;
    _a68_obj->f_index = l6;
    _a68_obj->f_mask = (size_t) 0;
    _a68_obj->f_size = (size_t) 0;
    _a68_obj->f_tombs = (size_t) 0;
    l4 = (void*) _a68_obj;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_pinned_types_by_fn;
    l6 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l5)->f_ekeys;
    l26 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l5)->f_evals;
    l3 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l5)->f_size;
    l7 = (size_t) 0;
    {
        loop_1023: {
            if ((l7 >= l3)) {
            } else {
                vader_array_t* _a69_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a69_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a69_slotarr, l7)
                l8 = ((int32_t*) _a69_slotarr->buf->slots)[_a69_slotarr->offset + (size_t) l7];
                vader_array_t* _a70_slotarr = ((vader_array_t*) l26);
                VADER_ARRAY_RESOLVE_BUF(_a70_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a70_slotarr, l7)
                l5 = vader_array_ref_load_obj(_a70_slotarr->buf, _a70_slotarr->offset + (size_t) l7);
                l10 = l8;
                l27 = l5;
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                t1 = ((int64_t) (int32_t) l10);
                l11 = (size_t) (int64_t) t1;
                l15 = ((vader_array_t*) l14)->length;
                if ((l11 >= l15)) {
                    goto loop_1023;
                }
                t1 = ((int64_t) (int32_t) l10);
                l16 = (size_t) (int64_t) t1;
                vader_array_t* _a71_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a71_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a71_slotarr, l16)
                l20 = ((int32_t*) _a71_slotarr->buf->slots)[_a71_slotarr->offset + (size_t) l16];
                if ((l20 < INT32_C(0))) {
                    goto loop_1023;
                }
                l19 = std_collections_MutableMap_Index_at__i32__Any(l4, l20);
                if (l19.tag == 9u) {
                    l28 = l19.payload.obj;
                    l29 = l27;
                    l17 = ((vader_array_t*) l29)->length;
                    l18 = (size_t) 0;
                    {
                        loop_1085: {
                            if ((l18 < l17)) {
                                vader_array_t* _a72_slotarr = ((vader_array_t*) l29);
                                VADER_ARRAY_RESOLVE_BUF(_a72_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a72_slotarr, l18)
                                l24 = ((int32_t*) _a72_slotarr->buf->slots)[_a72_slotarr->offset + (size_t) l18];
                                vader_array_push_i32((vader_array_t*) l28, l24);
                                t1 = (l18 + INT64_C(1));
                                l18 = (size_t) (int64_t) t1;
                                goto loop_1085;
                            }
                        }
                    }
                } else {
                    std_collections_MutableMap_IndexSet_set_at__i32__Any(l4, l20, vader_ref_box(l27));
                }
                goto loop_1023;
            }
        }
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_pinned_types_by_fn = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions = l13;
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
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 188u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 193u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 294u);
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
    {
        loop_21: {
            if ((l5 < l4)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
                t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                l3 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_body;
                l6 = ((vader_array_t*) l3)->length;
                l7 = (size_t) 0;
                {
                    loop_36: {
                        if ((l7 < l6)) {
                            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
                            l8 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
                            if (l8.tag == 517u) {
                                t0 = l8.payload.obj;
                                l9 = ((vader_struct_vader_bytecode_CallImport_t*) t0)->f_index;
                                std_collections_MutableMap_IndexSet_set_at__i32__bool(l1, l9, true);
                            }
                            t1 = (l7 + INT64_C(1));
                            l7 = (size_t) (int64_t) t1;
                            goto loop_36;
                        }
                    }
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_21;
            }
        }
    }
    l4 = std_collections_len__i32__bool(l1);
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports)->length;
    if (l4 == l5) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 193u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(39u, 0u, 13u, 485u);
    l3 = (void*) _a7_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports)->length;
    l5 = (size_t) 0;
    {
        loop_95: {
            if ((l5 < l4)) {
                l9 = ((int32_t) (size_t) l5);
                t2 = std_collections_MutableMap_Index_at__i32__bool(l1, l9);
                if (t2.tag == 188u) {
                    t3 = ((vader_array_t*) l3)->length;
                    l10 = ((int32_t) (size_t) t3);
                    vader_array_push_i32((vader_array_t*) l2, l10);
                    vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports);
                    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l5)
                    l11 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l5);
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l11));
                } else {
                    l12 = -(INT32_C(1));
                    vader_array_push_i32((vader_array_t*) l2, l12);
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_95;
            }
        }
    }
    l1 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l1)->length;
    l5 = (size_t) 0;
    {
        loop_145: {
            if ((l5 < l4)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l5)
                l11 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l5);
                l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l11)->f_body)->length;
                l7 = (size_t) 0;
                {
                    loop_160: {
                        if ((l7 < l6)) {
                            vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l11)->f_body);
                            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l7)
                            l8 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l7);
                            if (l8.tag == 517u) {
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
                                vader_obj_header_init(_a12_obj, 517u);
                                _a12_obj->f_index = t4;
                                l15 = (void*) _a12_obj;
                                vader_array_t* _a13_slotarr = ((vader_array_t*) l13);
                                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l7)
                                vader_array_ref_store(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l7, l15);
                                VADER_WRITE_BARRIER(_a13_slotarr->buf);
                            }
                            t1 = (l7 + INT64_C(1));
                            l7 = (size_t) (int64_t) t1;
                            goto loop_160;
                        }
                    }
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_145;
            }
        }
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
    void* l21 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l26 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    void* l30 = NULL;
    void* l37 = NULL;
    void* l41 = NULL;
    size_t l4, l5, l9, l10, l13, l14, l31, l32;
    int32_t l11, l15, l17, l24, l25, l27, l33, l34, l35, l36;
    vader_box_t l16 = vader_box_null(), l38 = vader_box_null();
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l40 = 0;
    bool l39;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    int32_t t3;
    bool t4;
    size_t t5;
    vader_box_t* gc_roots[3] = { &l16, &l38, &t2 };
    void** gc_raw_roots[18] = {
        &l0, &l1, &l2, &l3, &l6, &l7, &l8, &l12, &l21, &l22, &l23, &l26, &l28, &l29, &l30, &l37,
        &l41, &t0,
    };
    vader_string_t* gc_atom_roots[4] = { &l18, &l19, &l20, &l40 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 18u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 188u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 193u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 294u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 362u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    std_collections_add__i32(l1, INT32_C(0));
    vader_array_t* _a5_arr = vader_array_new(9u, 0u, 7u, 193u);
    l2 = (void*) _a5_arr;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    {
        loop_27: {
            if ((l5 < l4)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
                l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
                l7 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_signature)->f_result_types;
                vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l7);
                l8 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_signature)->f_param_types;
                l9 = ((vader_array_t*) l8)->length;
                l10 = (size_t) 0;
                {
                    loop_50: {
                        if ((l10 < l9)) {
                            vader_array_t* _a7_slotarr = ((vader_array_t*) l8);
                            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l10)
                            l11 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l10];
                            vader_array_push_i32((vader_array_t*) l2, l11);
                            t1 = (l10 + INT64_C(1));
                            l10 = (size_t) (int64_t) t1;
                            goto loop_50;
                        }
                    }
                }
                l12 = ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_body;
                l13 = ((vader_array_t*) l12)->length;
                l14 = (size_t) 0;
                {
                    loop_77: {
                        if ((l14 < l13)) {
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
                            goto loop_77;
                        }
                    }
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_27;
            }
        }
    }
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    {
        loop_117: {
            if ((l5 < l4)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l5)
                l6 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l5);
                l7 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_result_types;
                vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l7);
                l8 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_param_types;
                l9 = ((vader_array_t*) l8)->length;
                l10 = (size_t) 0;
                {
                    loop_140: {
                        if ((l10 < l9)) {
                            vader_array_t* _a10_slotarr = ((vader_array_t*) l8);
                            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l10)
                            l11 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l10];
                            vader_array_push_i32((vader_array_t*) l2, l11);
                            t1 = (l10 + INT64_C(1));
                            l10 = (size_t) (int64_t) t1;
                            goto loop_140;
                        }
                    }
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_117;
            }
        }
    }
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_pinned_types;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    {
        loop_175: {
            if ((l5 < l4)) {
                vader_array_t* _a11_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l5)
                l11 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l5];
                vader_array_push_i32((vader_array_t*) l2, l11);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_175;
            }
        }
    }
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_pinned_types_by_fn;
    l6 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l3)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l3)->f_evals;
    l4 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l3)->f_size;
    l5 = (size_t) 0;
    {
        loop_207: {
            if ((l5 >= l4)) {
            } else {
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
                {
                    loop_231: {
                        if ((l10 < l9)) {
                            vader_array_t* _a14_slotarr = ((vader_array_t*) l3);
                            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l10)
                            l11 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l10];
                            vader_array_push_i32((vader_array_t*) l2, l11);
                            t1 = (l10 + INT64_C(1));
                            l10 = (size_t) (int64_t) t1;
                            goto loop_231;
                        }
                    }
                }
                goto loop_207;
            }
        }
    }
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) 0;
    {
        loop_261: {
            if ((l5 < l4)) {
                vader_array_t* _a15_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l5)
                t3 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l5];
                vader_bytecode_visit_type(t3, l0, l1);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_261;
            }
        }
    }
    l4 = std_collections_len__i32(l1);
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types)->length;
    if (l4 == l5) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types)->length;
    vader_array_t* _a16_arr = vader_array_new(9u, 0u, 7u, 193u);
    l2 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(141u, 0u, 13u, 1158u);
    l3 = (void*) _a17_arr;
    l5 = (size_t) 0;
    {
        loop_302: {
            if ((l5 < l4)) {
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
                goto loop_302;
            }
        }
    }
    vader_array_t* _a19_arr = vader_array_new(141u, 0u, 13u, 1158u);
    l1 = (void*) _a19_arr;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    {
        loop_352: {
            if ((l5 < l4)) {
                vader_array_t* _a20_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l5)
                l16 = vader_array_ref_load_box(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l5);
                if (l16.tag == 493u) {
                    vader_array_t* _a21_arr = vader_array_new(37u, 0u, 13u, 482u);
                    l6 = (void*) _a21_arr;
                    t0 = l16.payload.obj;
                    l7 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_fields;
                    l9 = ((vader_array_t*) l7)->length;
                    l10 = (size_t) 0;
                    {
                        loop_374: {
                            if ((l10 < l9)) {
                                vader_array_t* _a22_slotarr = ((vader_array_t*) l7);
                                VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l10)
                                l8 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l10);
                                l18 = ((vader_struct_vader_bytecode_BcField_t*) l8)->f_name;
                                l11 = ((vader_struct_vader_bytecode_BcField_t*) l8)->f_type_index;
                                l15 = vader_bytecode_remap_idx(l2, l11);
                                vader_struct_vader_bytecode_BcField_t* _a23_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
                                vader_obj_header_init(_a23_obj, 482u);
                                _a23_obj->f_name = l18;
                                _a23_obj->f_type_index = l15;
                                l12 = (void*) _a23_obj;
                                vader_array_push((vader_array_t*) l6, vader_ref_box(l12));
                                t1 = (l10 + INT64_C(1));
                                l10 = (size_t) (int64_t) t1;
                                goto loop_374;
                            }
                        }
                    }
                    t0 = l16.payload.obj;
                    l19 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_name;
                    t0 = l16.payload.obj;
                    l20 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_c_name;
                    t0 = l16.payload.obj;
                    l17 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_symbol_id;
                    vader_struct_vader_bytecode_BcStruct_t* _a24_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
                    vader_obj_header_init(_a24_obj, 493u);
                    _a24_obj->f_name = l19;
                    _a24_obj->f_fields = l6;
                    _a24_obj->f_c_name = l20;
                    _a24_obj->f_symbol_id = l17;
                    l21 = (void*) _a24_obj;
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l21));
                } else if (l16.tag == 494u) {
                    vader_array_t* _a25_arr = vader_array_new(9u, 0u, 7u, 193u);
                    l22 = (void*) _a25_arr;
                    t0 = l16.payload.obj;
                    l23 = ((vader_struct_vader_bytecode_BcUnion_t*) t0)->f_variants;
                    l13 = ((vader_array_t*) l23)->length;
                    l14 = (size_t) 0;
                    {
                        vader_array_t* _pc447_hdr = (vader_array_t*) l22;
                        size_t _pc447_len = _pc447_hdr->length;
                        size_t _pc447_cap = (_pc447_hdr->offset == 0 && !vader_array_is_borrowed(_pc447_hdr) && _pc447_hdr->length >= _pc447_hdr->buf->length) ? _pc447_hdr->capacity : (size_t) 0;
                        void* _pc447_slots = _pc447_hdr->buf->slots;
                        loop_447: {
                            if ((l14 < l13)) {
                                vader_array_t* _a26_slotarr = ((vader_array_t*) l23);
                                VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l14)
                                l24 = ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l14];
                                l25 = vader_bytecode_remap_idx(l2, l24);
                                if (VADER_LIKELY(_pc447_len < _pc447_cap)) {
                                    ((int32_t*) _pc447_slots)[_pc447_len] = (int32_t) (l25);
                                    _pc447_len += 1;
                                } else {
                                    _pc447_hdr->length = _pc447_len;
                                    if (_pc447_hdr->buf->length < _pc447_len) {
                                        _pc447_hdr->buf->length = _pc447_len;
                                    }
                                    vader_array_push_i32((vader_array_t*) l22, l25);
                                    _pc447_hdr = (vader_array_t*) l22;
                                    _pc447_len = _pc447_hdr->length;
                                    _pc447_cap = (_pc447_hdr->offset == 0 && !vader_array_is_borrowed(_pc447_hdr) && _pc447_hdr->length >= _pc447_hdr->buf->length) ? _pc447_hdr->capacity : (size_t) 0;
                                    _pc447_slots = _pc447_hdr->buf->slots;
                                }
                                t1 = (l14 + INT64_C(1));
                                l14 = (size_t) (int64_t) t1;
                                goto loop_447;
                            }
                            _pc447_hdr->length = _pc447_len;
                            if (_pc447_hdr->buf->length < _pc447_len) {
                                _pc447_hdr->buf->length = _pc447_len;
                            }
                        }
                    }
                    vader_struct_vader_bytecode_BcUnion_t* _a27_obj = (vader_struct_vader_bytecode_BcUnion_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcUnion_t));
                    vader_obj_header_init(_a27_obj, 494u);
                    _a27_obj->f_variants = l22;
                    l26 = (void*) _a27_obj;
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l26));
                } else if (l16.tag == 480u) {
                    t0 = l16.payload.obj;
                    l27 = ((vader_struct_vader_bytecode_BcArray_t*) t0)->f_element;
                    t3 = vader_bytecode_remap_idx(l2, l27);
                    vader_struct_vader_bytecode_BcArray_t* _a28_obj = (vader_struct_vader_bytecode_BcArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcArray_t));
                    vader_obj_header_init(_a28_obj, 480u);
                    _a28_obj->f_element = t3;
                    l28 = (void*) _a28_obj;
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l28));
                } else if (l16.tag == 483u) {
                    vader_array_t* _a29_arr = vader_array_new(9u, 0u, 7u, 193u);
                    l29 = (void*) _a29_arr;
                    t0 = l16.payload.obj;
                    l30 = ((vader_struct_vader_bytecode_BcFn_t*) t0)->f_params;
                    l31 = ((vader_array_t*) l30)->length;
                    l32 = (size_t) 0;
                    {
                        vader_array_t* _pc509_hdr = (vader_array_t*) l29;
                        size_t _pc509_len = _pc509_hdr->length;
                        size_t _pc509_cap = (_pc509_hdr->offset == 0 && !vader_array_is_borrowed(_pc509_hdr) && _pc509_hdr->length >= _pc509_hdr->buf->length) ? _pc509_hdr->capacity : (size_t) 0;
                        void* _pc509_slots = _pc509_hdr->buf->slots;
                        loop_509: {
                            if ((l32 < l31)) {
                                vader_array_t* _a30_slotarr = ((vader_array_t*) l30);
                                VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l32)
                                l33 = ((int32_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l32];
                                l34 = vader_bytecode_remap_idx(l2, l33);
                                if (VADER_LIKELY(_pc509_len < _pc509_cap)) {
                                    ((int32_t*) _pc509_slots)[_pc509_len] = (int32_t) (l34);
                                    _pc509_len += 1;
                                } else {
                                    _pc509_hdr->length = _pc509_len;
                                    if (_pc509_hdr->buf->length < _pc509_len) {
                                        _pc509_hdr->buf->length = _pc509_len;
                                    }
                                    vader_array_push_i32((vader_array_t*) l29, l34);
                                    _pc509_hdr = (vader_array_t*) l29;
                                    _pc509_len = _pc509_hdr->length;
                                    _pc509_cap = (_pc509_hdr->offset == 0 && !vader_array_is_borrowed(_pc509_hdr) && _pc509_hdr->length >= _pc509_hdr->buf->length) ? _pc509_hdr->capacity : (size_t) 0;
                                    _pc509_slots = _pc509_hdr->buf->slots;
                                }
                                t1 = (l32 + INT64_C(1));
                                l32 = (size_t) (int64_t) t1;
                                goto loop_509;
                            }
                            _pc509_hdr->length = _pc509_len;
                            if (_pc509_hdr->buf->length < _pc509_len) {
                                _pc509_hdr->buf->length = _pc509_len;
                            }
                        }
                    }
                    t0 = l16.payload.obj;
                    l35 = ((vader_struct_vader_bytecode_BcFn_t*) t0)->f_return_type;
                    l36 = vader_bytecode_remap_idx(l2, l35);
                    vader_struct_vader_bytecode_BcFn_t* _a31_obj = (vader_struct_vader_bytecode_BcFn_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFn_t));
                    vader_obj_header_init(_a31_obj, 483u);
                    _a31_obj->f_params = l29;
                    _a31_obj->f_return_type = l36;
                    l37 = (void*) _a31_obj;
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l37));
                } else {
                    l38 = l16;
                    vader_array_push((vader_array_t*) l1, l38);
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_352;
            }
        }
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    vader_array_t* _a32_arr = vader_array_new(8u, 0u, 0u, 190u);
    l1 = (void*) _a32_arr;
    vader_array_t* _a33_arr = vader_array_new(9u, 0u, 7u, 193u);
    l3 = (void*) _a33_arr;
    vader_array_t* _a34_arr = vader_array_new(9u, 0u, 7u, 193u);
    l6 = (void*) _a34_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a35_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a35_obj, 343u);
    _a35_obj->f_ekeys = l1;
    _a35_obj->f_evals = l3;
    _a35_obj->f_index = l6;
    _a35_obj->f_mask = (size_t) 0;
    _a35_obj->f_size = (size_t) 0;
    _a35_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a35_obj;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_key;
    l6 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l3)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l3)->f_evals;
    l4 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l3)->f_size;
    l5 = (size_t) 0;
    {
        loop_596: {
            if ((l5 >= l4)) {
            } else {
                vader_array_t* _a36_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l5)
                t2 = vader_array_box_slots(_a36_slotarr->buf)[_a36_slotarr->offset + (size_t) l5];
                l18 = t2.payload.s;
                vader_array_t* _a37_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l5)
                l11 = ((int32_t*) _a37_slotarr->buf->slots)[_a37_slotarr->offset + (size_t) l5];
                l19 = l18;
                l15 = l11;
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                l17 = vader_bytecode_remap_idx(l2, l15);
                if ((l17 >= INT32_C(0))) {
                    std_collections_MutableMap_IndexSet_set_at__string__i32(l1, l19, l17);
                }
                goto loop_596;
            }
        }
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_key = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    l1 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l1)->length;
    l5 = (size_t) 0;
    {
        loop_645: {
            if ((l5 < l4)) {
                vader_array_t* _a38_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l5)
                l3 = vader_array_ref_load_obj(_a38_slotarr->buf, _a38_slotarr->offset + (size_t) l5);
                vader_array_t* _a39_arr = vader_array_new(9u, 0u, 7u, 193u);
                l6 = (void*) _a39_arr;
                l7 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature)->f_param_types;
                l9 = ((vader_array_t*) l7)->length;
                l10 = (size_t) 0;
                {
                    vader_array_t* _pc664_hdr = (vader_array_t*) l6;
                    size_t _pc664_len = _pc664_hdr->length;
                    size_t _pc664_cap = (_pc664_hdr->offset == 0 && !vader_array_is_borrowed(_pc664_hdr) && _pc664_hdr->length >= _pc664_hdr->buf->length) ? _pc664_hdr->capacity : (size_t) 0;
                    void* _pc664_slots = _pc664_hdr->buf->slots;
                    loop_664: {
                        if ((l10 < l9)) {
                            vader_array_t* _a40_slotarr = ((vader_array_t*) l7);
                            VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l10)
                            l11 = ((int32_t*) _a40_slotarr->buf->slots)[_a40_slotarr->offset + (size_t) l10];
                            l15 = vader_bytecode_remap_idx(l2, l11);
                            if (VADER_LIKELY(_pc664_len < _pc664_cap)) {
                                ((int32_t*) _pc664_slots)[_pc664_len] = (int32_t) (l15);
                                _pc664_len += 1;
                            } else {
                                _pc664_hdr->length = _pc664_len;
                                if (_pc664_hdr->buf->length < _pc664_len) {
                                    _pc664_hdr->buf->length = _pc664_len;
                                }
                                vader_array_push_i32((vader_array_t*) l6, l15);
                                _pc664_hdr = (vader_array_t*) l6;
                                _pc664_len = _pc664_hdr->length;
                                _pc664_cap = (_pc664_hdr->offset == 0 && !vader_array_is_borrowed(_pc664_hdr) && _pc664_hdr->length >= _pc664_hdr->buf->length) ? _pc664_hdr->capacity : (size_t) 0;
                                _pc664_slots = _pc664_hdr->buf->slots;
                            }
                            t1 = (l10 + INT64_C(1));
                            l10 = (size_t) (int64_t) t1;
                            goto loop_664;
                        }
                        _pc664_hdr->length = _pc664_len;
                        if (_pc664_hdr->buf->length < _pc664_len) {
                            _pc664_hdr->buf->length = _pc664_len;
                        }
                    }
                }
                l8 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature;
                l12 = ((vader_struct_vader_bytecode_BcSignature_t*) l8)->f_params;
                l21 = ((vader_struct_vader_bytecode_BcSignature_t*) l8)->f_results;
                l22 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature)->f_result_types;
                l23 = vader_bytecode_remap_type_indices(l2, l22);
                l26 = ((vader_struct_vader_bytecode_BcSignature_t*) l8)->f_param_names;
                l28 = ((vader_struct_vader_bytecode_BcSignature_t*) l8)->f_param_mutable;
                l29 = ((vader_struct_vader_bytecode_BcSignature_t*) l8)->f_param_by_address;
                vader_struct_vader_bytecode_BcSignature_t* _a41_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
                vader_obj_header_init(_a41_obj, 491u);
                _a41_obj->f_params = l12;
                _a41_obj->f_results = l21;
                _a41_obj->f_param_types = l6;
                _a41_obj->f_result_types = l23;
                _a41_obj->f_param_names = l26;
                _a41_obj->f_param_mutable = l28;
                _a41_obj->f_param_by_address = l29;
                l30 = (void*) _a41_obj;
                ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature = l30;
                VADER_WRITE_BARRIER((vader_struct_vader_bytecode_BcFunction_t*) l3);
                l13 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_body)->length;
                l14 = (size_t) 0;
                {
                    loop_725: {
                        if ((l14 < l13)) {
                            l37 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_body;
                            vader_array_t* _a42_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_body);
                            VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l14)
                            t2 = vader_array_ref_load_box(_a42_slotarr->buf, _a42_slotarr->offset + (size_t) l14);
                            l16 = vader_bytecode_remap_type_in_op(t2, l2);
                            vader_array_t* _a43_slotarr = ((vader_array_t*) l37);
                            VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l14)
                            vader_array_ref_store(_a43_slotarr->buf, _a43_slotarr->offset + (size_t) l14, l16.payload.obj);
                            VADER_WRITE_BARRIER(_a43_slotarr->buf);
                            t1 = (l14 + INT64_C(1));
                            l14 = (size_t) (int64_t) t1;
                            goto loop_725;
                        }
                    }
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_645;
            }
        }
    }
    vader_array_t* _a44_arr = vader_array_new(39u, 0u, 13u, 485u);
    l1 = (void*) _a44_arr;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    {
        loop_767: {
            if ((l5 < l4)) {
                vader_array_t* _a45_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l5)
                l6 = vader_array_ref_load_obj(_a45_slotarr->buf, _a45_slotarr->offset + (size_t) l5);
                vader_array_t* _a46_arr = vader_array_new(9u, 0u, 7u, 193u);
                l7 = (void*) _a46_arr;
                l8 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_param_types;
                l9 = ((vader_array_t*) l8)->length;
                l10 = (size_t) 0;
                {
                    vader_array_t* _pc786_hdr = (vader_array_t*) l7;
                    size_t _pc786_len = _pc786_hdr->length;
                    size_t _pc786_cap = (_pc786_hdr->offset == 0 && !vader_array_is_borrowed(_pc786_hdr) && _pc786_hdr->length >= _pc786_hdr->buf->length) ? _pc786_hdr->capacity : (size_t) 0;
                    void* _pc786_slots = _pc786_hdr->buf->slots;
                    loop_786: {
                        if ((l10 < l9)) {
                            vader_array_t* _a47_slotarr = ((vader_array_t*) l8);
                            VADER_ARRAY_RESOLVE_BUF(_a47_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a47_slotarr, l10)
                            l11 = ((int32_t*) _a47_slotarr->buf->slots)[_a47_slotarr->offset + (size_t) l10];
                            l15 = vader_bytecode_remap_idx(l2, l11);
                            if (VADER_LIKELY(_pc786_len < _pc786_cap)) {
                                ((int32_t*) _pc786_slots)[_pc786_len] = (int32_t) (l15);
                                _pc786_len += 1;
                            } else {
                                _pc786_hdr->length = _pc786_len;
                                if (_pc786_hdr->buf->length < _pc786_len) {
                                    _pc786_hdr->buf->length = _pc786_len;
                                }
                                vader_array_push_i32((vader_array_t*) l7, l15);
                                _pc786_hdr = (vader_array_t*) l7;
                                _pc786_len = _pc786_hdr->length;
                                _pc786_cap = (_pc786_hdr->offset == 0 && !vader_array_is_borrowed(_pc786_hdr) && _pc786_hdr->length >= _pc786_hdr->buf->length) ? _pc786_hdr->capacity : (size_t) 0;
                                _pc786_slots = _pc786_hdr->buf->slots;
                            }
                            t1 = (l10 + INT64_C(1));
                            l10 = (size_t) (int64_t) t1;
                            goto loop_786;
                        }
                        _pc786_hdr->length = _pc786_len;
                        if (_pc786_hdr->buf->length < _pc786_len) {
                            _pc786_hdr->buf->length = _pc786_len;
                        }
                    }
                }
                l18 = ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_extern_name;
                l19 = ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_mangled_name;
                l12 = ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature;
                l21 = ((vader_struct_vader_bytecode_BcSignature_t*) l12)->f_params;
                l22 = ((vader_struct_vader_bytecode_BcSignature_t*) l12)->f_results;
                l23 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_result_types;
                l26 = vader_bytecode_remap_type_indices(l2, l23);
                l28 = ((vader_struct_vader_bytecode_BcSignature_t*) l12)->f_param_names;
                l29 = ((vader_struct_vader_bytecode_BcSignature_t*) l12)->f_param_mutable;
                l30 = ((vader_struct_vader_bytecode_BcSignature_t*) l12)->f_param_by_address;
                vader_struct_vader_bytecode_BcSignature_t* _a48_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
                vader_obj_header_init(_a48_obj, 491u);
                _a48_obj->f_params = l21;
                _a48_obj->f_results = l22;
                _a48_obj->f_param_types = l7;
                _a48_obj->f_result_types = l26;
                _a48_obj->f_param_names = l28;
                _a48_obj->f_param_mutable = l29;
                _a48_obj->f_param_by_address = l30;
                l37 = (void*) _a48_obj;
                l39 = ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_is_extern;
                l20 = ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_c_header;
                l40 = ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_c_library;
                l17 = ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_c_variadic_fixed;
                vader_struct_vader_bytecode_BcImport_t* _a49_obj = (vader_struct_vader_bytecode_BcImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcImport_t));
                vader_obj_header_init(_a49_obj, 485u);
                _a49_obj->f_extern_name = l18;
                _a49_obj->f_mangled_name = l19;
                _a49_obj->f_signature = l37;
                _a49_obj->f_is_extern = l39;
                _a49_obj->f_c_header = l20;
                _a49_obj->f_c_library = l40;
                _a49_obj->f_c_variadic_fixed = l17;
                l41 = (void*) _a49_obj;
                vader_array_push((vader_array_t*) l1, vader_ref_box(l41));
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_767;
            }
        }
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
    } else {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        vader_array_ref_store(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1, l2.payload.obj);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
    }
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
        vader_array_push((vader_array_t*) l0, vader_box_string(190u, l3));
        vader_array_push_i32((vader_array_t*) l1, l4);
    } else {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l2] = vader_box_string(190u, l3);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l2] = (int32_t) l4;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_bytecode_ranges_overlap(void* l0, void* l1) {
    int32_t l2, l3;
    bool l4;
    l2 = ((vader_struct_vader_bytecode_SlotRange_t*) l0)->f_first;
    l3 = ((vader_struct_vader_bytecode_SlotRange_t*) l1)->f_last;
    if ((l2 <= l3)) {
        l2 = ((vader_struct_vader_bytecode_SlotRange_t*) l1)->f_first;
        l3 = ((vader_struct_vader_bytecode_SlotRange_t*) l0)->f_last;
        l4 = (l2 <= l3);
    } else {
        l4 = false;
    }
    return l4;
}

void vader_bytecode_record_slot_type(void* l0, int32_t l1, vader_box_t l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void* l6 = NULL;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l5, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_by_slot)->length;
    {
        loop_7: {
            if ((l4 <= l3)) {
                l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_by_slot;
                vader_struct_vader_types_PrimitiveType_t* _a0_obj = (vader_struct_vader_types_PrimitiveType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_PrimitiveType_t));
                vader_obj_header_init(_a0_obj, 964u);
                _a0_obj->f_name = 1815u;
                l6 = (void*) _a0_obj;
                vader_array_push((vader_array_t*) l5, vader_ref_box(l6));
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_7;
            }
        }
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

static void* vader_bytecode_remap_debug(void* l0, void* l1, size_t l2) {
    void* l3 = NULL;
    size_t l4, l5, l7;
    int32_t l6;
    bool l8;
    vader_box_t l9 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l9, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(143u, 1u, 13u, 1181u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = vader_box_obj(0u, NULL).payload.obj;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l2);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    l4 = ((vader_array_t*) l0)->length;
    l5 = (size_t) 0;
    {
        loop_11: {
            if ((l5 < l4)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                l6 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5];
                if ((l6 < INT32_C(0))) {
                    t1 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t1;
                    goto loop_11;
                }
                t1 = ((int64_t) (int32_t) l6);
                l7 = (size_t) (int64_t) t1;
                if ((l7 < l2)) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
                    t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l7);
                    l8 = t2.tag == 0u;
                } else {
                    l8 = false;
                }
                if (l8) {
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l0);
                    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
                    l9 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
                    vader_array_ref_store(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l7, l9.payload.obj);
                    VADER_WRITE_BARRIER(_a6_slotarr->buf);
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_11;
            }
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_bytecode_remap_idx(void* l0, int32_t l1) {
    size_t l2, l3;
    int64_t t0;
    int32_t t1;
    if ((l1 < INT32_C(0))) {
        return l1;
    }
    t0 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t0;
    l3 = ((vader_array_t*) l0)->length;
    if ((l2 >= l3)) {
        return -(INT32_C(1));
    }
    t0 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    return t1;
}

void* vader_bytecode_remap_jump_table(void* l0, void* l1, size_t l2) {
    void* l3 = NULL;
    size_t l4, l6, l7, l8, l11, l12, l14;
    int32_t l5, l9, l10, l13;
    int64_t t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    l3 = (void*) _a0_arr;
    l4 = (size_t) 0;
    {
        vader_array_t* _pc5_hdr = (vader_array_t*) l3;
        size_t _pc5_len = _pc5_hdr->length;
        size_t _pc5_cap = (_pc5_hdr->offset == 0 && !vader_array_is_borrowed(_pc5_hdr) && _pc5_hdr->length >= _pc5_hdr->buf->length) ? _pc5_hdr->capacity : (size_t) 0;
        void* _pc5_slots = _pc5_hdr->buf->slots;
        loop_5: {
            if ((l4 < l2)) {
                l5 = -(INT32_C(1));
                if (VADER_LIKELY(_pc5_len < _pc5_cap)) {
                    ((int32_t*) _pc5_slots)[_pc5_len] = (int32_t) (l5);
                    _pc5_len += 1;
                } else {
                    _pc5_hdr->length = _pc5_len;
                    if (_pc5_hdr->buf->length < _pc5_len) {
                        _pc5_hdr->buf->length = _pc5_len;
                    }
                    vader_array_push_i32((vader_array_t*) l3, l5);
                    _pc5_hdr = (vader_array_t*) l3;
                    _pc5_len = _pc5_hdr->length;
                    _pc5_cap = (_pc5_hdr->offset == 0 && !vader_array_is_borrowed(_pc5_hdr) && _pc5_hdr->length >= _pc5_hdr->buf->length) ? _pc5_hdr->capacity : (size_t) 0;
                    _pc5_slots = _pc5_hdr->buf->slots;
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_5;
            }
            _pc5_hdr->length = _pc5_len;
            if (_pc5_hdr->buf->length < _pc5_len) {
                _pc5_hdr->buf->length = _pc5_len;
            }
        }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l4 = ((vader_array_t*) l0)->length;
    l6 = (size_t) 0;
    {
        loop_30: {
            if ((l6 < l4)) {
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
                l5 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
                if ((l5 < INT32_C(0))) {
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_30;
                }
                t0 = ((int64_t) (int32_t) l5);
                l7 = (size_t) (int64_t) t0;
                l8 = ((vader_array_t*) l1)->length;
                if ((l7 >= l8)) {
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_30;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
                l9 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                if ((l9 < INT32_C(0))) {
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_30;
                }
                l10 = -(INT32_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                l11 = ((vader_array_t*) l1)->length;
                t0 = ((int64_t) (int32_t) l5);
                l12 = (size_t) (int64_t) t0;
                {
                    loop_87: {
                        if ((l12 < l11)) {
                            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l12)
                            l13 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l12];
                            if ((l13 >= INT32_C(0))) {
                                l10 = l13;
                            } else {
                                t0 = (l12 + INT64_C(1));
                                l12 = (size_t) (int64_t) t0;
                                goto loop_87;
                            }
                        }
                    }
                }
                if ((l10 < INT32_C(0))) {
                    l10 = ((int32_t) (size_t) l2);
                }
                if ((((int64_t) (int32_t) l9) < l2)) {
                    t0 = ((int64_t) (int32_t) l9);
                    l14 = (size_t) (int64_t) t0;
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l14)
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l14] = (int32_t) l10;
                }
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_30;
            }
        }
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
    if (!(l0.tag == 473u)) {
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
    if (l2) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
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
    vader_obj_header_init(_a1_obj, 473u);
    _a1_obj->f_type_id = l5;
    _a1_obj->f_cache_slot = l6;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_remap_type_in_op(vader_box_t l0, void* l1) {
    int32_t l2, l4, l5;
    bool l3;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 622u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_type_id;
        l2 = vader_bytecode_remap_idx(l1, l2);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_stack;
        vader_struct_vader_bytecode_StructNew_t* _a0_obj = (vader_struct_vader_bytecode_StructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructNew_t));
        vader_obj_header_init(_a0_obj, 622u);
        _a0_obj->f_type_id = l2;
        _a0_obj->f_stack = l3;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 621u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_type_id;
        l2 = vader_bytecode_remap_idx(l1, l2);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_field_index;
        vader_struct_vader_bytecode_StructGet_t* _a1_obj = (vader_struct_vader_bytecode_StructGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructGet_t));
        vader_obj_header_init(_a1_obj, 621u);
        _a1_obj->f_type_id = l2;
        _a1_obj->f_field_index = l4;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 623u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_type_id;
        l2 = vader_bytecode_remap_idx(l1, l2);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_field_index;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_stack;
        vader_struct_vader_bytecode_StructSet_t* _a2_obj = (vader_struct_vader_bytecode_StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructSet_t));
        vader_obj_header_init(_a2_obj, 623u);
        _a2_obj->f_type_id = l2;
        _a2_obj->f_field_index = l4;
        _a2_obj->f_stack = l3;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 472u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_type_id;
        l2 = vader_bytecode_remap_idx(l1, l2);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_length;
        vader_struct_vader_bytecode_ArrayNew_t* _a3_obj = (vader_struct_vader_bytecode_ArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayNew_t));
        vader_obj_header_init(_a3_obj, 472u);
        _a3_obj->f_type_id = l2;
        _a3_obj->f_length = l4;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 470u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_ArrayGet_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l2);
        vader_struct_vader_bytecode_ArrayGet_t* _a4_obj = (vader_struct_vader_bytecode_ArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayGet_t));
        vader_obj_header_init(_a4_obj, 470u);
        _a4_obj->f_type_id = t1;
        _a4_obj->f_bounds_safe = false;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 477u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_ArraySet_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l2);
        vader_struct_vader_bytecode_ArraySet_t* _a5_obj = (vader_struct_vader_bytecode_ArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArraySet_t));
        vader_obj_header_init(_a5_obj, 477u);
        _a5_obj->f_type_id = t1;
        _a5_obj->f_bounds_safe = false;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 473u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_type_id;
        l2 = vader_bytecode_remap_idx(l1, l2);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_cache_slot;
        vader_struct_vader_bytecode_ArrayPush_t* _a6_obj = (vader_struct_vader_bytecode_ArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayPush_t));
        vader_obj_header_init(_a6_obj, 473u);
        _a6_obj->f_type_id = l2;
        _a6_obj->f_cache_slot = l4;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 624u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_TypeCheck_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l2);
        vader_struct_vader_bytecode_TypeCheck_t* _a7_obj = (vader_struct_vader_bytecode_TypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_TypeCheck_t));
        vader_obj_header_init(_a7_obj, 624u);
        _a7_obj->f_type_id = t1;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 625u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_TypeConst_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l2);
        vader_struct_vader_bytecode_TypeConst_t* _a8_obj = (vader_struct_vader_bytecode_TypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_TypeConst_t));
        vader_obj_header_init(_a8_obj, 625u);
        _a8_obj->f_type_id = t1;
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 518u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_CallIndirect_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l2);
        vader_struct_vader_bytecode_CallIndirect_t* _a9_obj = (vader_struct_vader_bytecode_CallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallIndirect_t));
        vader_obj_header_init(_a9_obj, 518u);
        _a9_obj->f_type_id = t1;
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 600u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_function_index;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_env_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_MakeClosure_t* _a10_obj = (vader_struct_vader_bytecode_MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_MakeClosure_t));
        vader_obj_header_init(_a10_obj, 600u);
        _a10_obj->f_function_index = l2;
        _a10_obj->f_env_type_id = l4;
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 545u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_function_index;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_FnRef_t* _a11_obj = (vader_struct_vader_bytecode_FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnRef_t));
        vader_obj_header_init(_a11_obj, 545u);
        _a11_obj->f_function_index = l2;
        _a11_obj->f_type_id = l4;
        t0 = (void*) _a11_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 595u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_slot;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_field_index;
        vader_struct_vader_bytecode_LocalField_t* _a12_obj = (vader_struct_vader_bytecode_LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalField_t));
        vader_obj_header_init(_a12_obj, 595u);
        _a12_obj->f_slot = l2;
        _a12_obj->f_type_id = l4;
        _a12_obj->f_field_index = l5;
        t0 = (void*) _a12_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 478u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_ArraySlice_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l2);
        vader_struct_vader_bytecode_ArraySlice_t* _a13_obj = (vader_struct_vader_bytecode_ArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArraySlice_t));
        vader_obj_header_init(_a13_obj, 478u);
        _a13_obj->f_type_id = t1;
        t0 = (void*) _a13_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 603u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_RefCast_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l2);
        vader_struct_vader_bytecode_RefCast_t* _a14_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
        vader_obj_header_init(_a14_obj, 603u);
        _a14_obj->f_type_id = t1;
        t0 = (void*) _a14_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 508u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_Box_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l2);
        vader_struct_vader_bytecode_Box_t* _a15_obj = (vader_struct_vader_bytecode_Box_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Box_t));
        vader_obj_header_init(_a15_obj, 508u);
        _a15_obj->f_type_id = t1;
        t0 = (void*) _a15_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 521u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_pool_index;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_type_id;
        l4 = vader_bytecode_remap_idx(l1, l4);
        vader_struct_vader_bytecode_DataConst_t* _a16_obj = (vader_struct_vader_bytecode_DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DataConst_t));
        vader_obj_header_init(_a16_obj, 521u);
        _a16_obj->f_pool_index = l2;
        _a16_obj->f_type_id = l4;
        t0 = (void*) _a16_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_bytecode_remap_type_indices(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    int32_t l6, l7;
    int64_t t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    l2 = (void*) _a0_arr;
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    {
        vader_array_t* _pc9_hdr = (vader_array_t*) l2;
        size_t _pc9_len = _pc9_hdr->length;
        size_t _pc9_cap = (_pc9_hdr->offset == 0 && !vader_array_is_borrowed(_pc9_hdr) && _pc9_hdr->length >= _pc9_hdr->buf->length) ? _pc9_hdr->capacity : (size_t) 0;
        void* _pc9_slots = _pc9_hdr->buf->slots;
        loop_9: {
            if ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                l6 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
                l7 = vader_bytecode_remap_idx(l0, l6);
                if (VADER_LIKELY(_pc9_len < _pc9_cap)) {
                    ((int32_t*) _pc9_slots)[_pc9_len] = (int32_t) (l7);
                    _pc9_len += 1;
                } else {
                    _pc9_hdr->length = _pc9_len;
                    if (_pc9_hdr->buf->length < _pc9_len) {
                        _pc9_hdr->buf->length = _pc9_len;
                    }
                    vader_array_push_i32((vader_array_t*) l2, l7);
                    _pc9_hdr = (vader_array_t*) l2;
                    _pc9_len = _pc9_hdr->length;
                    _pc9_cap = (_pc9_hdr->offset == 0 && !vader_array_is_borrowed(_pc9_hdr) && _pc9_hdr->length >= _pc9_hdr->buf->length) ? _pc9_hdr->capacity : (size_t) 0;
                    _pc9_slots = _pc9_hdr->buf->slots;
                }
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_9;
            }
            _pc9_hdr->length = _pc9_len;
            if (_pc9_hdr->buf->length < _pc9_len) {
                _pc9_hdr->buf->length = _pc9_len;
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_run_bc_const_fold_arith(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    size_t l2, l4, l6;
    int32_t l7, l11;
    vader_box_t l8 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l8, &l9, &l10 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l2 = ((vader_array_t*) l1)->length;
    vader_array_t* _a0_arr = vader_array_new(138u, 0u, 13u, 1148u);
    l3 = (void*) _a0_arr;
    l4 = (size_t) 0;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 193u);
    l5 = (void*) _a1_arr;
    l6 = (size_t) 0;
    {
        vader_array_t* _pc13_hdr = (vader_array_t*) l5;
        size_t _pc13_len = _pc13_hdr->length;
        size_t _pc13_cap = (_pc13_hdr->offset == 0 && !vader_array_is_borrowed(_pc13_hdr) && _pc13_hdr->length >= _pc13_hdr->buf->length) ? _pc13_hdr->capacity : (size_t) 0;
        void* _pc13_slots = _pc13_hdr->buf->slots;
        loop_13: {
            if ((l6 < l2)) {
                l7 = -(INT32_C(1));
                if (VADER_LIKELY(_pc13_len < _pc13_cap)) {
                    ((int32_t*) _pc13_slots)[_pc13_len] = (int32_t) (l7);
                    _pc13_len += 1;
                } else {
                    _pc13_hdr->length = _pc13_len;
                    if (_pc13_hdr->buf->length < _pc13_len) {
                        _pc13_hdr->buf->length = _pc13_len;
                    }
                    vader_array_push_i32((vader_array_t*) l5, l7);
                    _pc13_hdr = (vader_array_t*) l5;
                    _pc13_len = _pc13_hdr->length;
                    _pc13_cap = (_pc13_hdr->offset == 0 && !vader_array_is_borrowed(_pc13_hdr) && _pc13_hdr->length >= _pc13_hdr->buf->length) ? _pc13_hdr->capacity : (size_t) 0;
                    _pc13_slots = _pc13_hdr->buf->slots;
                }
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_13;
            }
            _pc13_hdr->length = _pc13_len;
            if (_pc13_hdr->buf->length < _pc13_len) {
                _pc13_hdr->buf->length = _pc13_len;
            }
        }
    }
    l6 = (size_t) 0;
    {
        loop_35: {
            if ((l6 < l2)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
                l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
                l9 = vader_bytecode_try_fold_arith(l8, l3, l4);
                if (l9.tag == 0u) {
                    vader_bytecode_push_or_assign(l3, l4, l8);
                    l7 = ((int32_t) (size_t) l4);
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
                    ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l6] = (int32_t) l7;
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                } else {
                    t0 = (l4 - INT64_C(2));
                    l4 = (size_t) (int64_t) t0;
                    l10 = l9;
                    vader_bytecode_push_or_assign(l3, l4, l10);
                    l11 = ((int32_t) (size_t) l4);
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l6] = (int32_t) l11;
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                }
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_35;
            }
        }
    }
    vader_array_t* _a5_arr = vader_array_slice((vader_array_t*) l3, (size_t) INT64_C(0), (size_t) l4);
    l1 = (void*) _a5_arr;
    l3 = vader_bytecode_remap_jump_table(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l5, l4);
    l5 = vader_bytecode_remap_debug(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug, l5, l4);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a6_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a6_obj, 487u);
    _a6_obj->f_body = l1;
    _a6_obj->f_jump_table = l3;
    _a6_obj->f_debug = l5;
    t1 = (void*) _a6_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_run_bc_peephole(void* l0) {
    bool l1, l23, l24, l25, l26, l27, l30;
    void* l2 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l28 = NULL;
    void* l37 = NULL;
    void* l48 = NULL;
    size_t l3, l4, l5, l11, l12, l14, l15, l17, l18, l31, l32, l33, l35, l36, l38, l40, l41, l42, l43, l46, l47, l50, l52, l53;
    vader_box_t l10 = vader_box_null(), l22 = vader_box_null(), l34 = vader_box_null(), l44 = vader_box_null();
    int32_t l13, l16, l19, l29, l39, l45, l49, l51;
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    int32_t t3;
    vader_box_t t4 = vader_box_null(), t5 = vader_box_null();
    bool t6;
    vader_box_t* gc_roots[6] = { &l10, &l22, &l34, &l44, &t4, &t5 };
    void** gc_raw_roots[12] = { &l0, &l2, &l6, &l7, &l8, &l9, &l20, &l21, &l28, &l37, &l48, &t2 };
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
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    l6 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 193u);
    l7 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 193u);
    l8 = (void*) _a2_arr;
    l5 = (size_t) 0;
    {
        loop_29: {
            if ((l5 < l4)) {
                vader_array_push_i32((vader_array_t*) l6, INT32_C(0));
                vader_array_push_i32((vader_array_t*) l7, INT32_C(0));
                vader_array_push_i32((vader_array_t*) l8, INT32_C(0));
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_29;
            }
        }
    }
    l9 = l2;
    vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    l4 = ((vader_array_t*) l9)->length;
    l5 = (size_t) 0;
    {
        loop_58: {
            if ((l5 < l4)) {
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
                l10 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
                if (l10.tag == 597u) {
                    t2 = l10.payload.obj;
                    t3 = ((vader_struct_vader_bytecode_LocalSet_t*) t2)->f_slot;
                    t1 = ((int64_t) (int32_t) t3);
                    l11 = (size_t) (int64_t) t1;
                    t2 = l10.payload.obj;
                    t3 = ((vader_struct_vader_bytecode_LocalSet_t*) t2)->f_slot;
                    t1 = ((int64_t) (int32_t) t3);
                    l12 = (size_t) (int64_t) t1;
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l12)
                    t3 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l12];
                    l13 = (t3 + INT32_C(1));
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l11] = (int32_t) l13;
                }
                if (l10.tag == 596u) {
                    t2 = l10.payload.obj;
                    t3 = ((vader_struct_vader_bytecode_LocalGet_t*) t2)->f_slot;
                    t1 = ((int64_t) (int32_t) t3);
                    l14 = (size_t) (int64_t) t1;
                    t2 = l10.payload.obj;
                    t3 = ((vader_struct_vader_bytecode_LocalGet_t*) t2)->f_slot;
                    t1 = ((int64_t) (int32_t) t3);
                    l15 = (size_t) (int64_t) t1;
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
                    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l15)
                    t3 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l15];
                    l16 = (t3 + INT32_C(1));
                    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l14)
                    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l14] = (int32_t) l16;
                }
                if (l10.tag == 598u) {
                    t2 = l10.payload.obj;
                    t3 = ((vader_struct_vader_bytecode_LocalTee_t*) t2)->f_slot;
                    t1 = ((int64_t) (int32_t) t3);
                    l17 = (size_t) (int64_t) t1;
                    t2 = l10.payload.obj;
                    t3 = ((vader_struct_vader_bytecode_LocalTee_t*) t2)->f_slot;
                    t1 = ((int64_t) (int32_t) t3);
                    l18 = (size_t) (int64_t) t1;
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l8);
                    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l18)
                    t3 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l18];
                    l19 = (t3 + INT32_C(1));
                    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l17)
                    ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l17] = (int32_t) l19;
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_58;
            }
        }
    }
    l9 = vader_bytecode_mark_jump_targets(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l3);
    vader_array_t* _a7_arr = vader_array_new(138u, 0u, 13u, 1148u);
    l20 = (void*) _a7_arr;
    l4 = (size_t) 0;
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 193u);
    l21 = (void*) _a8_arr;
    l5 = (size_t) 0;
    {
        vader_array_t* _pc165_hdr = (vader_array_t*) l21;
        size_t _pc165_len = _pc165_hdr->length;
        size_t _pc165_cap = (_pc165_hdr->offset == 0 && !vader_array_is_borrowed(_pc165_hdr) && _pc165_hdr->length >= _pc165_hdr->buf->length) ? _pc165_hdr->capacity : (size_t) 0;
        void* _pc165_slots = _pc165_hdr->buf->slots;
        loop_165: {
            if ((l5 < l3)) {
                l13 = -(INT32_C(1));
                if (VADER_LIKELY(_pc165_len < _pc165_cap)) {
                    ((int32_t*) _pc165_slots)[_pc165_len] = (int32_t) (l13);
                    _pc165_len += 1;
                } else {
                    _pc165_hdr->length = _pc165_len;
                    if (_pc165_hdr->buf->length < _pc165_len) {
                        _pc165_hdr->buf->length = _pc165_len;
                    }
                    vader_array_push_i32((vader_array_t*) l21, l13);
                    _pc165_hdr = (vader_array_t*) l21;
                    _pc165_len = _pc165_hdr->length;
                    _pc165_cap = (_pc165_hdr->offset == 0 && !vader_array_is_borrowed(_pc165_hdr) && _pc165_hdr->length >= _pc165_hdr->buf->length) ? _pc165_hdr->capacity : (size_t) 0;
                    _pc165_slots = _pc165_hdr->buf->slots;
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_165;
            }
            _pc165_hdr->length = _pc165_len;
            if (_pc165_hdr->buf->length < _pc165_len) {
                _pc165_hdr->buf->length = _pc165_len;
            }
        }
    }
    l5 = (size_t) 0;
    {
        loop_187: {
            if ((l5 < l3)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l5)
                l10 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l5);
                if (l10.tag == 597u) {
                    if (((l5 + INT64_C(1)) < l3)) {
                        t1 = (l5 + INT64_C(1));
                        l11 = (size_t) (int64_t) t1;
                        vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
                        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l11)
                        l22 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l11);
                        if (l22.tag == 596u) {
                            t2 = l22.payload.obj;
                            l13 = ((vader_struct_vader_bytecode_LocalGet_t*) t2)->f_slot;
                            t2 = l10.payload.obj;
                            l16 = ((vader_struct_vader_bytecode_LocalSet_t*) t2)->f_slot;
                            if (l13 == l16) {
                                l23 = false;
                                if ((l4 > INT64_C(0))) {
                                    t1 = (l4 - INT64_C(1));
                                    l12 = (size_t) (int64_t) t1;
                                    vader_array_t* _a11_slotarr = ((vader_array_t*) l20);
                                    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l12)
                                    t4 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l12);
                                    t5 = vader_bytecode_const_op_of(t4);
                                    if (!(t5.tag == 0u)) {
                                        l23 = true;
                                    }
                                }
                                t2 = l10.payload.obj;
                                t3 = ((vader_struct_vader_bytecode_LocalSet_t*) t2)->f_slot;
                                t1 = ((int64_t) (int32_t) t3);
                                l14 = (size_t) (int64_t) t1;
                                vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
                                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l14)
                                t3 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l14];
                                if (t3 == INT32_C(1)) {
                                    vader_array_t* _a13_slotarr = ((vader_array_t*) l7);
                                    VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l14)
                                    t3 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l14];
                                    l25 = t3 == INT32_C(1);
                                } else {
                                    l25 = false;
                                }
                                if (l25) {
                                    vader_array_t* _a14_slotarr = ((vader_array_t*) l8);
                                    VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l14)
                                    t3 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l14];
                                    l24 = t3 == INT32_C(0);
                                } else {
                                    l24 = false;
                                }
                                if (l23) {
                                    l27 = l24;
                                } else {
                                    l27 = false;
                                }
                                if (l27) {
                                    l26 = true;
                                } else {
                                    t1 = (l5 + INT64_C(1));
                                    l15 = (size_t) (int64_t) t1;
                                    vader_array_t* _a15_slotarr = ((vader_array_t*) l9);
                                    VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l15)
                                    t4 = vader_box_bool(188u, ((uint8_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l15]);
                                    l26 = t4.payload.b;
                                }
                                if (!(l26)) {
                                    t2 = l10.payload.obj;
                                    t3 = ((vader_struct_vader_bytecode_LocalSet_t*) t2)->f_slot;
                                    vader_struct_vader_bytecode_LocalTee_t* _a16_obj = (vader_struct_vader_bytecode_LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalTee_t));
                                    vader_obj_header_init(_a16_obj, 598u);
                                    _a16_obj->f_slot = t3;
                                    l28 = (void*) _a16_obj;
                                    vader_bytecode_push_or_assign(l20, l4, vader_ref_box(l28));
                                    l19 = ((int32_t) (size_t) l4);
                                    vader_array_t* _a17_slotarr = ((vader_array_t*) l21);
                                    VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l5)
                                    ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l5] = (int32_t) l19;
                                    t1 = (l5 + INT64_C(1));
                                    l17 = (size_t) (int64_t) t1;
                                    l29 = ((int32_t) (size_t) l4);
                                    VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l17)
                                    ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l17] = (int32_t) l29;
                                    t1 = (l4 + INT64_C(1));
                                    l4 = (size_t) (int64_t) t1;
                                    t1 = (l5 + INT64_C(2));
                                    l5 = (size_t) (int64_t) t1;
                                    goto loop_187;
                                }
                                if (l10.tag == 606u) {
                                    l30 = !(l1);
                                } else {
                                    l30 = false;
                                }
                                if (l30) {
                                    l18 = ((vader_array_t*) l20)->length;
                                    l31 = (size_t) 0;
                                    if ((l18 > l31)) {
                                        l32 = (size_t) 1;
                                        t1 = (l18 - l32);
                                        l33 = (size_t) (int64_t) t1;
                                        vader_array_t* _a18_slotarr = ((vader_array_t*) l20);
                                        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l33)
                                        t4 = vader_array_ref_load_box(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l33);
                                        l34 = vader_bytecode_const_op_of(t4);
                                        if (!(l34.tag == 0u)) {
                                            l35 = (size_t) 1;
                                            t1 = (l18 - l35);
                                            l36 = (size_t) (int64_t) t1;
                                            vader_struct_vader_bytecode_ReturnLit_t* _a19_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                                            vader_obj_header_init(_a19_obj, 607u);
                                            _a19_obj->f_value = l34;
                                            l37 = (void*) _a19_obj;
                                            vader_array_t* _a20_slotarr = ((vader_array_t*) l20);
                                            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l36)
                                            vader_array_ref_store(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l36, l37);
                                            VADER_WRITE_BARRIER(_a20_slotarr->buf);
                                            l38 = (size_t) 1;
                                            l39 = ((int32_t) (int64_t) (l4 - l38));
                                            vader_array_t* _a21_slotarr = ((vader_array_t*) l21);
                                            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l5)
                                            ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l5] = (int32_t) l39;
                                            l40 = (size_t) 1;
                                            t1 = (l5 + l40);
                                            l5 = (size_t) (int64_t) t1;
                                            goto loop_187;
                                        }
                                        if (l10.tag == 506u) {
                                            l41 = (size_t) 0;
                                            if ((l4 > l41)) {
                                                l42 = (size_t) 1;
                                                t1 = (l4 - l42);
                                                l43 = (size_t) (int64_t) t1;
                                                vader_array_t* _a22_slotarr = ((vader_array_t*) l20);
                                                VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l43)
                                                l44 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l43);
                                                if (l44.tag == 506u) {
                                                    l45 = -(INT32_C(1));
                                                    vader_array_t* _a23_slotarr = ((vader_array_t*) l21);
                                                    VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                                                    VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l5)
                                                    ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l5] = (int32_t) l45;
                                                    l46 = (size_t) 1;
                                                    t1 = (l4 - l46);
                                                    l4 = (size_t) (int64_t) t1;
                                                    l47 = (size_t) 1;
                                                    t1 = (l5 + l47);
                                                    l5 = (size_t) (int64_t) t1;
                                                    goto loop_187;
                                                }
                                                if (l44.tag == 503u) {
                                                    t2 = l44.payload.obj;
                                                    t6 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                                    vader_struct_vader_bytecode_BoolConst_t* _a24_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                                    vader_obj_header_init(_a24_obj, 503u);
                                                    _a24_obj->f_value = !(t6);
                                                    l48 = (void*) _a24_obj;
                                                    vader_array_t* _a25_slotarr = ((vader_array_t*) l20);
                                                    VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
                                                    VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l43)
                                                    vader_array_ref_store(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l43, l48);
                                                    VADER_WRITE_BARRIER(_a25_slotarr->buf);
                                                    l49 = ((int32_t) (size_t) l43);
                                                    vader_array_t* _a26_slotarr = ((vader_array_t*) l21);
                                                    VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                                                    VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l5)
                                                    ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l5] = (int32_t) l49;
                                                    l50 = (size_t) 1;
                                                    t1 = (l5 + l50);
                                                    l5 = (size_t) (int64_t) t1;
                                                    goto loop_187;
                                                }
                                                vader_bytecode_push_or_assign(l20, l4, l10);
                                                l51 = ((int32_t) (size_t) l4);
                                                vader_array_t* _a27_slotarr = ((vader_array_t*) l21);
                                                VADER_ARRAY_RESOLVE_BUF(_a27_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a27_slotarr, l5)
                                                ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                                l52 = (size_t) 1;
                                                t1 = (l4 + l52);
                                                l4 = (size_t) (int64_t) t1;
                                                l53 = (size_t) 1;
                                                t1 = (l5 + l53);
                                                l5 = (size_t) (int64_t) t1;
                                                goto loop_187;
                                            }
                                            vader_bytecode_push_or_assign(l20, l4, l10);
                                            l51 = ((int32_t) (size_t) l4);
                                            vader_array_t* _a28_slotarr = ((vader_array_t*) l21);
                                            VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l5)
                                            ((int32_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                            l52 = (size_t) 1;
                                            t1 = (l4 + l52);
                                            l4 = (size_t) (int64_t) t1;
                                            l53 = (size_t) 1;
                                            t1 = (l5 + l53);
                                            l5 = (size_t) (int64_t) t1;
                                            goto loop_187;
                                        }
                                        vader_bytecode_push_or_assign(l20, l4, l10);
                                        l51 = ((int32_t) (size_t) l4);
                                        vader_array_t* _a29_slotarr = ((vader_array_t*) l21);
                                        VADER_ARRAY_RESOLVE_BUF(_a29_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a29_slotarr, l5)
                                        ((int32_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                        l52 = (size_t) 1;
                                        t1 = (l4 + l52);
                                        l4 = (size_t) (int64_t) t1;
                                        l53 = (size_t) 1;
                                        t1 = (l5 + l53);
                                        l5 = (size_t) (int64_t) t1;
                                        goto loop_187;
                                    }
                                    if (l10.tag == 506u) {
                                        l41 = (size_t) 0;
                                        if ((l4 > l41)) {
                                            l42 = (size_t) 1;
                                            t1 = (l4 - l42);
                                            l43 = (size_t) (int64_t) t1;
                                            vader_array_t* _a30_slotarr = ((vader_array_t*) l20);
                                            VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l43)
                                            l44 = vader_array_ref_load_box(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l43);
                                            if (l44.tag == 506u) {
                                                l45 = -(INT32_C(1));
                                                vader_array_t* _a31_slotarr = ((vader_array_t*) l21);
                                                VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l5)
                                                ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l5] = (int32_t) l45;
                                                l46 = (size_t) 1;
                                                t1 = (l4 - l46);
                                                l4 = (size_t) (int64_t) t1;
                                                l47 = (size_t) 1;
                                                t1 = (l5 + l47);
                                                l5 = (size_t) (int64_t) t1;
                                                goto loop_187;
                                            }
                                            if (l44.tag == 503u) {
                                                t2 = l44.payload.obj;
                                                t6 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                                vader_struct_vader_bytecode_BoolConst_t* _a32_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                                vader_obj_header_init(_a32_obj, 503u);
                                                _a32_obj->f_value = !(t6);
                                                l48 = (void*) _a32_obj;
                                                vader_array_t* _a33_slotarr = ((vader_array_t*) l20);
                                                VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l43)
                                                vader_array_ref_store(_a33_slotarr->buf, _a33_slotarr->offset + (size_t) l43, l48);
                                                VADER_WRITE_BARRIER(_a33_slotarr->buf);
                                                l49 = ((int32_t) (size_t) l43);
                                                vader_array_t* _a34_slotarr = ((vader_array_t*) l21);
                                                VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l5)
                                                ((int32_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l5] = (int32_t) l49;
                                                l50 = (size_t) 1;
                                                t1 = (l5 + l50);
                                                l5 = (size_t) (int64_t) t1;
                                                goto loop_187;
                                            }
                                            vader_bytecode_push_or_assign(l20, l4, l10);
                                            l51 = ((int32_t) (size_t) l4);
                                            vader_array_t* _a35_slotarr = ((vader_array_t*) l21);
                                            VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a35_slotarr, l5)
                                            ((int32_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                            l52 = (size_t) 1;
                                            t1 = (l4 + l52);
                                            l4 = (size_t) (int64_t) t1;
                                            l53 = (size_t) 1;
                                            t1 = (l5 + l53);
                                            l5 = (size_t) (int64_t) t1;
                                            goto loop_187;
                                        }
                                        vader_bytecode_push_or_assign(l20, l4, l10);
                                        l51 = ((int32_t) (size_t) l4);
                                        vader_array_t* _a36_slotarr = ((vader_array_t*) l21);
                                        VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l5)
                                        ((int32_t*) _a36_slotarr->buf->slots)[_a36_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                        l52 = (size_t) 1;
                                        t1 = (l4 + l52);
                                        l4 = (size_t) (int64_t) t1;
                                        l53 = (size_t) 1;
                                        t1 = (l5 + l53);
                                        l5 = (size_t) (int64_t) t1;
                                        goto loop_187;
                                    }
                                    vader_bytecode_push_or_assign(l20, l4, l10);
                                    l51 = ((int32_t) (size_t) l4);
                                    vader_array_t* _a37_slotarr = ((vader_array_t*) l21);
                                    VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l5)
                                    ((int32_t*) _a37_slotarr->buf->slots)[_a37_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                    l52 = (size_t) 1;
                                    t1 = (l4 + l52);
                                    l4 = (size_t) (int64_t) t1;
                                    l53 = (size_t) 1;
                                    t1 = (l5 + l53);
                                    l5 = (size_t) (int64_t) t1;
                                    goto loop_187;
                                }
                                if (l10.tag == 506u) {
                                    l41 = (size_t) 0;
                                    if ((l4 > l41)) {
                                        l42 = (size_t) 1;
                                        t1 = (l4 - l42);
                                        l43 = (size_t) (int64_t) t1;
                                        vader_array_t* _a38_slotarr = ((vader_array_t*) l20);
                                        VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l43)
                                        l44 = vader_array_ref_load_box(_a38_slotarr->buf, _a38_slotarr->offset + (size_t) l43);
                                        if (l44.tag == 506u) {
                                            l45 = -(INT32_C(1));
                                            vader_array_t* _a39_slotarr = ((vader_array_t*) l21);
                                            VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l5)
                                            ((int32_t*) _a39_slotarr->buf->slots)[_a39_slotarr->offset + (size_t) l5] = (int32_t) l45;
                                            l46 = (size_t) 1;
                                            t1 = (l4 - l46);
                                            l4 = (size_t) (int64_t) t1;
                                            l47 = (size_t) 1;
                                            t1 = (l5 + l47);
                                            l5 = (size_t) (int64_t) t1;
                                            goto loop_187;
                                        }
                                        if (l44.tag == 503u) {
                                            t2 = l44.payload.obj;
                                            t6 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                            vader_struct_vader_bytecode_BoolConst_t* _a40_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                            vader_obj_header_init(_a40_obj, 503u);
                                            _a40_obj->f_value = !(t6);
                                            l48 = (void*) _a40_obj;
                                            vader_array_t* _a41_slotarr = ((vader_array_t*) l20);
                                            VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l43)
                                            vader_array_ref_store(_a41_slotarr->buf, _a41_slotarr->offset + (size_t) l43, l48);
                                            VADER_WRITE_BARRIER(_a41_slotarr->buf);
                                            l49 = ((int32_t) (size_t) l43);
                                            vader_array_t* _a42_slotarr = ((vader_array_t*) l21);
                                            VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l5)
                                            ((int32_t*) _a42_slotarr->buf->slots)[_a42_slotarr->offset + (size_t) l5] = (int32_t) l49;
                                            l50 = (size_t) 1;
                                            t1 = (l5 + l50);
                                            l5 = (size_t) (int64_t) t1;
                                            goto loop_187;
                                        }
                                        vader_bytecode_push_or_assign(l20, l4, l10);
                                        l51 = ((int32_t) (size_t) l4);
                                        vader_array_t* _a43_slotarr = ((vader_array_t*) l21);
                                        VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l5)
                                        ((int32_t*) _a43_slotarr->buf->slots)[_a43_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                        l52 = (size_t) 1;
                                        t1 = (l4 + l52);
                                        l4 = (size_t) (int64_t) t1;
                                        l53 = (size_t) 1;
                                        t1 = (l5 + l53);
                                        l5 = (size_t) (int64_t) t1;
                                        goto loop_187;
                                    }
                                    vader_bytecode_push_or_assign(l20, l4, l10);
                                    l51 = ((int32_t) (size_t) l4);
                                    vader_array_t* _a44_slotarr = ((vader_array_t*) l21);
                                    VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l5)
                                    ((int32_t*) _a44_slotarr->buf->slots)[_a44_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                    l52 = (size_t) 1;
                                    t1 = (l4 + l52);
                                    l4 = (size_t) (int64_t) t1;
                                    l53 = (size_t) 1;
                                    t1 = (l5 + l53);
                                    l5 = (size_t) (int64_t) t1;
                                    goto loop_187;
                                }
                                vader_bytecode_push_or_assign(l20, l4, l10);
                                l51 = ((int32_t) (size_t) l4);
                                vader_array_t* _a45_slotarr = ((vader_array_t*) l21);
                                VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l5)
                                ((int32_t*) _a45_slotarr->buf->slots)[_a45_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                l52 = (size_t) 1;
                                t1 = (l4 + l52);
                                l4 = (size_t) (int64_t) t1;
                                l53 = (size_t) 1;
                                t1 = (l5 + l53);
                                l5 = (size_t) (int64_t) t1;
                                goto loop_187;
                            }
                            if (l10.tag == 606u) {
                                l30 = !(l1);
                            } else {
                                l30 = false;
                            }
                            if (l30) {
                                l18 = ((vader_array_t*) l20)->length;
                                l31 = (size_t) 0;
                                if ((l18 > l31)) {
                                    l32 = (size_t) 1;
                                    t1 = (l18 - l32);
                                    l33 = (size_t) (int64_t) t1;
                                    vader_array_t* _a46_slotarr = ((vader_array_t*) l20);
                                    VADER_ARRAY_RESOLVE_BUF(_a46_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a46_slotarr, l33)
                                    t4 = vader_array_ref_load_box(_a46_slotarr->buf, _a46_slotarr->offset + (size_t) l33);
                                    l34 = vader_bytecode_const_op_of(t4);
                                    if (!(l34.tag == 0u)) {
                                        l35 = (size_t) 1;
                                        t1 = (l18 - l35);
                                        l36 = (size_t) (int64_t) t1;
                                        vader_struct_vader_bytecode_ReturnLit_t* _a47_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                                        vader_obj_header_init(_a47_obj, 607u);
                                        _a47_obj->f_value = l34;
                                        l37 = (void*) _a47_obj;
                                        vader_array_t* _a48_slotarr = ((vader_array_t*) l20);
                                        VADER_ARRAY_RESOLVE_BUF(_a48_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a48_slotarr, l36)
                                        vader_array_ref_store(_a48_slotarr->buf, _a48_slotarr->offset + (size_t) l36, l37);
                                        VADER_WRITE_BARRIER(_a48_slotarr->buf);
                                        l38 = (size_t) 1;
                                        l39 = ((int32_t) (int64_t) (l4 - l38));
                                        vader_array_t* _a49_slotarr = ((vader_array_t*) l21);
                                        VADER_ARRAY_RESOLVE_BUF(_a49_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a49_slotarr, l5)
                                        ((int32_t*) _a49_slotarr->buf->slots)[_a49_slotarr->offset + (size_t) l5] = (int32_t) l39;
                                        l40 = (size_t) 1;
                                        t1 = (l5 + l40);
                                        l5 = (size_t) (int64_t) t1;
                                        goto loop_187;
                                    }
                                    if (l10.tag == 506u) {
                                        l41 = (size_t) 0;
                                        if ((l4 > l41)) {
                                            l42 = (size_t) 1;
                                            t1 = (l4 - l42);
                                            l43 = (size_t) (int64_t) t1;
                                            vader_array_t* _a50_slotarr = ((vader_array_t*) l20);
                                            VADER_ARRAY_RESOLVE_BUF(_a50_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a50_slotarr, l43)
                                            l44 = vader_array_ref_load_box(_a50_slotarr->buf, _a50_slotarr->offset + (size_t) l43);
                                            if (l44.tag == 506u) {
                                                l45 = -(INT32_C(1));
                                                vader_array_t* _a51_slotarr = ((vader_array_t*) l21);
                                                VADER_ARRAY_RESOLVE_BUF(_a51_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a51_slotarr, l5)
                                                ((int32_t*) _a51_slotarr->buf->slots)[_a51_slotarr->offset + (size_t) l5] = (int32_t) l45;
                                                l46 = (size_t) 1;
                                                t1 = (l4 - l46);
                                                l4 = (size_t) (int64_t) t1;
                                                l47 = (size_t) 1;
                                                t1 = (l5 + l47);
                                                l5 = (size_t) (int64_t) t1;
                                                goto loop_187;
                                            }
                                            if (l44.tag == 503u) {
                                                t2 = l44.payload.obj;
                                                t6 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                                vader_struct_vader_bytecode_BoolConst_t* _a52_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                                vader_obj_header_init(_a52_obj, 503u);
                                                _a52_obj->f_value = !(t6);
                                                l48 = (void*) _a52_obj;
                                                vader_array_t* _a53_slotarr = ((vader_array_t*) l20);
                                                VADER_ARRAY_RESOLVE_BUF(_a53_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a53_slotarr, l43)
                                                vader_array_ref_store(_a53_slotarr->buf, _a53_slotarr->offset + (size_t) l43, l48);
                                                VADER_WRITE_BARRIER(_a53_slotarr->buf);
                                                l49 = ((int32_t) (size_t) l43);
                                                vader_array_t* _a54_slotarr = ((vader_array_t*) l21);
                                                VADER_ARRAY_RESOLVE_BUF(_a54_slotarr)
                                                VADER_ARRAY_CHECK_INDEX(_a54_slotarr, l5)
                                                ((int32_t*) _a54_slotarr->buf->slots)[_a54_slotarr->offset + (size_t) l5] = (int32_t) l49;
                                                l50 = (size_t) 1;
                                                t1 = (l5 + l50);
                                                l5 = (size_t) (int64_t) t1;
                                                goto loop_187;
                                            }
                                            vader_bytecode_push_or_assign(l20, l4, l10);
                                            l51 = ((int32_t) (size_t) l4);
                                            vader_array_t* _a55_slotarr = ((vader_array_t*) l21);
                                            VADER_ARRAY_RESOLVE_BUF(_a55_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a55_slotarr, l5)
                                            ((int32_t*) _a55_slotarr->buf->slots)[_a55_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                            l52 = (size_t) 1;
                                            t1 = (l4 + l52);
                                            l4 = (size_t) (int64_t) t1;
                                            l53 = (size_t) 1;
                                            t1 = (l5 + l53);
                                            l5 = (size_t) (int64_t) t1;
                                            goto loop_187;
                                        }
                                        vader_bytecode_push_or_assign(l20, l4, l10);
                                        l51 = ((int32_t) (size_t) l4);
                                        vader_array_t* _a56_slotarr = ((vader_array_t*) l21);
                                        VADER_ARRAY_RESOLVE_BUF(_a56_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a56_slotarr, l5)
                                        ((int32_t*) _a56_slotarr->buf->slots)[_a56_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                        l52 = (size_t) 1;
                                        t1 = (l4 + l52);
                                        l4 = (size_t) (int64_t) t1;
                                        l53 = (size_t) 1;
                                        t1 = (l5 + l53);
                                        l5 = (size_t) (int64_t) t1;
                                        goto loop_187;
                                    }
                                    vader_bytecode_push_or_assign(l20, l4, l10);
                                    l51 = ((int32_t) (size_t) l4);
                                    vader_array_t* _a57_slotarr = ((vader_array_t*) l21);
                                    VADER_ARRAY_RESOLVE_BUF(_a57_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a57_slotarr, l5)
                                    ((int32_t*) _a57_slotarr->buf->slots)[_a57_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                    l52 = (size_t) 1;
                                    t1 = (l4 + l52);
                                    l4 = (size_t) (int64_t) t1;
                                    l53 = (size_t) 1;
                                    t1 = (l5 + l53);
                                    l5 = (size_t) (int64_t) t1;
                                    goto loop_187;
                                }
                                if (l10.tag == 506u) {
                                    l41 = (size_t) 0;
                                    if ((l4 > l41)) {
                                        l42 = (size_t) 1;
                                        t1 = (l4 - l42);
                                        l43 = (size_t) (int64_t) t1;
                                        vader_array_t* _a58_slotarr = ((vader_array_t*) l20);
                                        VADER_ARRAY_RESOLVE_BUF(_a58_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a58_slotarr, l43)
                                        l44 = vader_array_ref_load_box(_a58_slotarr->buf, _a58_slotarr->offset + (size_t) l43);
                                        if (l44.tag == 506u) {
                                            l45 = -(INT32_C(1));
                                            vader_array_t* _a59_slotarr = ((vader_array_t*) l21);
                                            VADER_ARRAY_RESOLVE_BUF(_a59_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a59_slotarr, l5)
                                            ((int32_t*) _a59_slotarr->buf->slots)[_a59_slotarr->offset + (size_t) l5] = (int32_t) l45;
                                            l46 = (size_t) 1;
                                            t1 = (l4 - l46);
                                            l4 = (size_t) (int64_t) t1;
                                            l47 = (size_t) 1;
                                            t1 = (l5 + l47);
                                            l5 = (size_t) (int64_t) t1;
                                            goto loop_187;
                                        }
                                        if (l44.tag == 503u) {
                                            t2 = l44.payload.obj;
                                            t6 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                            vader_struct_vader_bytecode_BoolConst_t* _a60_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                            vader_obj_header_init(_a60_obj, 503u);
                                            _a60_obj->f_value = !(t6);
                                            l48 = (void*) _a60_obj;
                                            vader_array_t* _a61_slotarr = ((vader_array_t*) l20);
                                            VADER_ARRAY_RESOLVE_BUF(_a61_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a61_slotarr, l43)
                                            vader_array_ref_store(_a61_slotarr->buf, _a61_slotarr->offset + (size_t) l43, l48);
                                            VADER_WRITE_BARRIER(_a61_slotarr->buf);
                                            l49 = ((int32_t) (size_t) l43);
                                            vader_array_t* _a62_slotarr = ((vader_array_t*) l21);
                                            VADER_ARRAY_RESOLVE_BUF(_a62_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a62_slotarr, l5)
                                            ((int32_t*) _a62_slotarr->buf->slots)[_a62_slotarr->offset + (size_t) l5] = (int32_t) l49;
                                            l50 = (size_t) 1;
                                            t1 = (l5 + l50);
                                            l5 = (size_t) (int64_t) t1;
                                            goto loop_187;
                                        }
                                        vader_bytecode_push_or_assign(l20, l4, l10);
                                        l51 = ((int32_t) (size_t) l4);
                                        vader_array_t* _a63_slotarr = ((vader_array_t*) l21);
                                        VADER_ARRAY_RESOLVE_BUF(_a63_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a63_slotarr, l5)
                                        ((int32_t*) _a63_slotarr->buf->slots)[_a63_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                        l52 = (size_t) 1;
                                        t1 = (l4 + l52);
                                        l4 = (size_t) (int64_t) t1;
                                        l53 = (size_t) 1;
                                        t1 = (l5 + l53);
                                        l5 = (size_t) (int64_t) t1;
                                        goto loop_187;
                                    }
                                    vader_bytecode_push_or_assign(l20, l4, l10);
                                    l51 = ((int32_t) (size_t) l4);
                                    vader_array_t* _a64_slotarr = ((vader_array_t*) l21);
                                    VADER_ARRAY_RESOLVE_BUF(_a64_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a64_slotarr, l5)
                                    ((int32_t*) _a64_slotarr->buf->slots)[_a64_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                    l52 = (size_t) 1;
                                    t1 = (l4 + l52);
                                    l4 = (size_t) (int64_t) t1;
                                    l53 = (size_t) 1;
                                    t1 = (l5 + l53);
                                    l5 = (size_t) (int64_t) t1;
                                    goto loop_187;
                                }
                                vader_bytecode_push_or_assign(l20, l4, l10);
                                l51 = ((int32_t) (size_t) l4);
                                vader_array_t* _a65_slotarr = ((vader_array_t*) l21);
                                VADER_ARRAY_RESOLVE_BUF(_a65_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a65_slotarr, l5)
                                ((int32_t*) _a65_slotarr->buf->slots)[_a65_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                l52 = (size_t) 1;
                                t1 = (l4 + l52);
                                l4 = (size_t) (int64_t) t1;
                                l53 = (size_t) 1;
                                t1 = (l5 + l53);
                                l5 = (size_t) (int64_t) t1;
                                goto loop_187;
                            }
                            if (l10.tag == 506u) {
                                l41 = (size_t) 0;
                                if ((l4 > l41)) {
                                    l42 = (size_t) 1;
                                    t1 = (l4 - l42);
                                    l43 = (size_t) (int64_t) t1;
                                    vader_array_t* _a66_slotarr = ((vader_array_t*) l20);
                                    VADER_ARRAY_RESOLVE_BUF(_a66_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a66_slotarr, l43)
                                    l44 = vader_array_ref_load_box(_a66_slotarr->buf, _a66_slotarr->offset + (size_t) l43);
                                    if (l44.tag == 506u) {
                                        l45 = -(INT32_C(1));
                                        vader_array_t* _a67_slotarr = ((vader_array_t*) l21);
                                        VADER_ARRAY_RESOLVE_BUF(_a67_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a67_slotarr, l5)
                                        ((int32_t*) _a67_slotarr->buf->slots)[_a67_slotarr->offset + (size_t) l5] = (int32_t) l45;
                                        l46 = (size_t) 1;
                                        t1 = (l4 - l46);
                                        l4 = (size_t) (int64_t) t1;
                                        l47 = (size_t) 1;
                                        t1 = (l5 + l47);
                                        l5 = (size_t) (int64_t) t1;
                                        goto loop_187;
                                    }
                                    if (l44.tag == 503u) {
                                        t2 = l44.payload.obj;
                                        t6 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                        vader_struct_vader_bytecode_BoolConst_t* _a68_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                        vader_obj_header_init(_a68_obj, 503u);
                                        _a68_obj->f_value = !(t6);
                                        l48 = (void*) _a68_obj;
                                        vader_array_t* _a69_slotarr = ((vader_array_t*) l20);
                                        VADER_ARRAY_RESOLVE_BUF(_a69_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a69_slotarr, l43)
                                        vader_array_ref_store(_a69_slotarr->buf, _a69_slotarr->offset + (size_t) l43, l48);
                                        VADER_WRITE_BARRIER(_a69_slotarr->buf);
                                        l49 = ((int32_t) (size_t) l43);
                                        vader_array_t* _a70_slotarr = ((vader_array_t*) l21);
                                        VADER_ARRAY_RESOLVE_BUF(_a70_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a70_slotarr, l5)
                                        ((int32_t*) _a70_slotarr->buf->slots)[_a70_slotarr->offset + (size_t) l5] = (int32_t) l49;
                                        l50 = (size_t) 1;
                                        t1 = (l5 + l50);
                                        l5 = (size_t) (int64_t) t1;
                                        goto loop_187;
                                    }
                                    vader_bytecode_push_or_assign(l20, l4, l10);
                                    l51 = ((int32_t) (size_t) l4);
                                    vader_array_t* _a71_slotarr = ((vader_array_t*) l21);
                                    VADER_ARRAY_RESOLVE_BUF(_a71_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a71_slotarr, l5)
                                    ((int32_t*) _a71_slotarr->buf->slots)[_a71_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                    l52 = (size_t) 1;
                                    t1 = (l4 + l52);
                                    l4 = (size_t) (int64_t) t1;
                                    l53 = (size_t) 1;
                                    t1 = (l5 + l53);
                                    l5 = (size_t) (int64_t) t1;
                                    goto loop_187;
                                }
                                vader_bytecode_push_or_assign(l20, l4, l10);
                                l51 = ((int32_t) (size_t) l4);
                                vader_array_t* _a72_slotarr = ((vader_array_t*) l21);
                                VADER_ARRAY_RESOLVE_BUF(_a72_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a72_slotarr, l5)
                                ((int32_t*) _a72_slotarr->buf->slots)[_a72_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                l52 = (size_t) 1;
                                t1 = (l4 + l52);
                                l4 = (size_t) (int64_t) t1;
                                l53 = (size_t) 1;
                                t1 = (l5 + l53);
                                l5 = (size_t) (int64_t) t1;
                                goto loop_187;
                            }
                            vader_bytecode_push_or_assign(l20, l4, l10);
                            l51 = ((int32_t) (size_t) l4);
                            vader_array_t* _a73_slotarr = ((vader_array_t*) l21);
                            VADER_ARRAY_RESOLVE_BUF(_a73_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a73_slotarr, l5)
                            ((int32_t*) _a73_slotarr->buf->slots)[_a73_slotarr->offset + (size_t) l5] = (int32_t) l51;
                            l52 = (size_t) 1;
                            t1 = (l4 + l52);
                            l4 = (size_t) (int64_t) t1;
                            l53 = (size_t) 1;
                            t1 = (l5 + l53);
                            l5 = (size_t) (int64_t) t1;
                            goto loop_187;
                        }
                        if (l10.tag == 606u) {
                            l30 = !(l1);
                        } else {
                            l30 = false;
                        }
                        if (l30) {
                            l18 = ((vader_array_t*) l20)->length;
                            l31 = (size_t) 0;
                            if ((l18 > l31)) {
                                l32 = (size_t) 1;
                                t1 = (l18 - l32);
                                l33 = (size_t) (int64_t) t1;
                                vader_array_t* _a74_slotarr = ((vader_array_t*) l20);
                                VADER_ARRAY_RESOLVE_BUF(_a74_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a74_slotarr, l33)
                                t4 = vader_array_ref_load_box(_a74_slotarr->buf, _a74_slotarr->offset + (size_t) l33);
                                l34 = vader_bytecode_const_op_of(t4);
                                if (!(l34.tag == 0u)) {
                                    l35 = (size_t) 1;
                                    t1 = (l18 - l35);
                                    l36 = (size_t) (int64_t) t1;
                                    vader_struct_vader_bytecode_ReturnLit_t* _a75_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                                    vader_obj_header_init(_a75_obj, 607u);
                                    _a75_obj->f_value = l34;
                                    l37 = (void*) _a75_obj;
                                    vader_array_t* _a76_slotarr = ((vader_array_t*) l20);
                                    VADER_ARRAY_RESOLVE_BUF(_a76_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a76_slotarr, l36)
                                    vader_array_ref_store(_a76_slotarr->buf, _a76_slotarr->offset + (size_t) l36, l37);
                                    VADER_WRITE_BARRIER(_a76_slotarr->buf);
                                    l38 = (size_t) 1;
                                    l39 = ((int32_t) (int64_t) (l4 - l38));
                                    vader_array_t* _a77_slotarr = ((vader_array_t*) l21);
                                    VADER_ARRAY_RESOLVE_BUF(_a77_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a77_slotarr, l5)
                                    ((int32_t*) _a77_slotarr->buf->slots)[_a77_slotarr->offset + (size_t) l5] = (int32_t) l39;
                                    l40 = (size_t) 1;
                                    t1 = (l5 + l40);
                                    l5 = (size_t) (int64_t) t1;
                                    goto loop_187;
                                }
                                if (l10.tag == 506u) {
                                    l41 = (size_t) 0;
                                    if ((l4 > l41)) {
                                        l42 = (size_t) 1;
                                        t1 = (l4 - l42);
                                        l43 = (size_t) (int64_t) t1;
                                        vader_array_t* _a78_slotarr = ((vader_array_t*) l20);
                                        VADER_ARRAY_RESOLVE_BUF(_a78_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a78_slotarr, l43)
                                        l44 = vader_array_ref_load_box(_a78_slotarr->buf, _a78_slotarr->offset + (size_t) l43);
                                        if (l44.tag == 506u) {
                                            l45 = -(INT32_C(1));
                                            vader_array_t* _a79_slotarr = ((vader_array_t*) l21);
                                            VADER_ARRAY_RESOLVE_BUF(_a79_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a79_slotarr, l5)
                                            ((int32_t*) _a79_slotarr->buf->slots)[_a79_slotarr->offset + (size_t) l5] = (int32_t) l45;
                                            l46 = (size_t) 1;
                                            t1 = (l4 - l46);
                                            l4 = (size_t) (int64_t) t1;
                                            l47 = (size_t) 1;
                                            t1 = (l5 + l47);
                                            l5 = (size_t) (int64_t) t1;
                                            goto loop_187;
                                        }
                                        if (l44.tag == 503u) {
                                            t2 = l44.payload.obj;
                                            t6 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                            vader_struct_vader_bytecode_BoolConst_t* _a80_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                            vader_obj_header_init(_a80_obj, 503u);
                                            _a80_obj->f_value = !(t6);
                                            l48 = (void*) _a80_obj;
                                            vader_array_t* _a81_slotarr = ((vader_array_t*) l20);
                                            VADER_ARRAY_RESOLVE_BUF(_a81_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a81_slotarr, l43)
                                            vader_array_ref_store(_a81_slotarr->buf, _a81_slotarr->offset + (size_t) l43, l48);
                                            VADER_WRITE_BARRIER(_a81_slotarr->buf);
                                            l49 = ((int32_t) (size_t) l43);
                                            vader_array_t* _a82_slotarr = ((vader_array_t*) l21);
                                            VADER_ARRAY_RESOLVE_BUF(_a82_slotarr)
                                            VADER_ARRAY_CHECK_INDEX(_a82_slotarr, l5)
                                            ((int32_t*) _a82_slotarr->buf->slots)[_a82_slotarr->offset + (size_t) l5] = (int32_t) l49;
                                            l50 = (size_t) 1;
                                            t1 = (l5 + l50);
                                            l5 = (size_t) (int64_t) t1;
                                            goto loop_187;
                                        }
                                        vader_bytecode_push_or_assign(l20, l4, l10);
                                        l51 = ((int32_t) (size_t) l4);
                                        vader_array_t* _a83_slotarr = ((vader_array_t*) l21);
                                        VADER_ARRAY_RESOLVE_BUF(_a83_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a83_slotarr, l5)
                                        ((int32_t*) _a83_slotarr->buf->slots)[_a83_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                        l52 = (size_t) 1;
                                        t1 = (l4 + l52);
                                        l4 = (size_t) (int64_t) t1;
                                        l53 = (size_t) 1;
                                        t1 = (l5 + l53);
                                        l5 = (size_t) (int64_t) t1;
                                        goto loop_187;
                                    }
                                    vader_bytecode_push_or_assign(l20, l4, l10);
                                    l51 = ((int32_t) (size_t) l4);
                                    vader_array_t* _a84_slotarr = ((vader_array_t*) l21);
                                    VADER_ARRAY_RESOLVE_BUF(_a84_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a84_slotarr, l5)
                                    ((int32_t*) _a84_slotarr->buf->slots)[_a84_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                    l52 = (size_t) 1;
                                    t1 = (l4 + l52);
                                    l4 = (size_t) (int64_t) t1;
                                    l53 = (size_t) 1;
                                    t1 = (l5 + l53);
                                    l5 = (size_t) (int64_t) t1;
                                    goto loop_187;
                                }
                                vader_bytecode_push_or_assign(l20, l4, l10);
                                l51 = ((int32_t) (size_t) l4);
                                vader_array_t* _a85_slotarr = ((vader_array_t*) l21);
                                VADER_ARRAY_RESOLVE_BUF(_a85_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a85_slotarr, l5)
                                ((int32_t*) _a85_slotarr->buf->slots)[_a85_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                l52 = (size_t) 1;
                                t1 = (l4 + l52);
                                l4 = (size_t) (int64_t) t1;
                                l53 = (size_t) 1;
                                t1 = (l5 + l53);
                                l5 = (size_t) (int64_t) t1;
                                goto loop_187;
                            }
                            if (l10.tag == 506u) {
                                l41 = (size_t) 0;
                                if ((l4 > l41)) {
                                    l42 = (size_t) 1;
                                    t1 = (l4 - l42);
                                    l43 = (size_t) (int64_t) t1;
                                    vader_array_t* _a86_slotarr = ((vader_array_t*) l20);
                                    VADER_ARRAY_RESOLVE_BUF(_a86_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a86_slotarr, l43)
                                    l44 = vader_array_ref_load_box(_a86_slotarr->buf, _a86_slotarr->offset + (size_t) l43);
                                    if (l44.tag == 506u) {
                                        l45 = -(INT32_C(1));
                                        vader_array_t* _a87_slotarr = ((vader_array_t*) l21);
                                        VADER_ARRAY_RESOLVE_BUF(_a87_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a87_slotarr, l5)
                                        ((int32_t*) _a87_slotarr->buf->slots)[_a87_slotarr->offset + (size_t) l5] = (int32_t) l45;
                                        l46 = (size_t) 1;
                                        t1 = (l4 - l46);
                                        l4 = (size_t) (int64_t) t1;
                                        l47 = (size_t) 1;
                                        t1 = (l5 + l47);
                                        l5 = (size_t) (int64_t) t1;
                                        goto loop_187;
                                    }
                                    if (l44.tag == 503u) {
                                        t2 = l44.payload.obj;
                                        t6 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                        vader_struct_vader_bytecode_BoolConst_t* _a88_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                        vader_obj_header_init(_a88_obj, 503u);
                                        _a88_obj->f_value = !(t6);
                                        l48 = (void*) _a88_obj;
                                        vader_array_t* _a89_slotarr = ((vader_array_t*) l20);
                                        VADER_ARRAY_RESOLVE_BUF(_a89_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a89_slotarr, l43)
                                        vader_array_ref_store(_a89_slotarr->buf, _a89_slotarr->offset + (size_t) l43, l48);
                                        VADER_WRITE_BARRIER(_a89_slotarr->buf);
                                        l49 = ((int32_t) (size_t) l43);
                                        vader_array_t* _a90_slotarr = ((vader_array_t*) l21);
                                        VADER_ARRAY_RESOLVE_BUF(_a90_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a90_slotarr, l5)
                                        ((int32_t*) _a90_slotarr->buf->slots)[_a90_slotarr->offset + (size_t) l5] = (int32_t) l49;
                                        l50 = (size_t) 1;
                                        t1 = (l5 + l50);
                                        l5 = (size_t) (int64_t) t1;
                                        goto loop_187;
                                    }
                                    vader_bytecode_push_or_assign(l20, l4, l10);
                                    l51 = ((int32_t) (size_t) l4);
                                    vader_array_t* _a91_slotarr = ((vader_array_t*) l21);
                                    VADER_ARRAY_RESOLVE_BUF(_a91_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a91_slotarr, l5)
                                    ((int32_t*) _a91_slotarr->buf->slots)[_a91_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                    l52 = (size_t) 1;
                                    t1 = (l4 + l52);
                                    l4 = (size_t) (int64_t) t1;
                                    l53 = (size_t) 1;
                                    t1 = (l5 + l53);
                                    l5 = (size_t) (int64_t) t1;
                                    goto loop_187;
                                }
                                vader_bytecode_push_or_assign(l20, l4, l10);
                                l51 = ((int32_t) (size_t) l4);
                                vader_array_t* _a92_slotarr = ((vader_array_t*) l21);
                                VADER_ARRAY_RESOLVE_BUF(_a92_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a92_slotarr, l5)
                                ((int32_t*) _a92_slotarr->buf->slots)[_a92_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                l52 = (size_t) 1;
                                t1 = (l4 + l52);
                                l4 = (size_t) (int64_t) t1;
                                l53 = (size_t) 1;
                                t1 = (l5 + l53);
                                l5 = (size_t) (int64_t) t1;
                                goto loop_187;
                            }
                            vader_bytecode_push_or_assign(l20, l4, l10);
                            l51 = ((int32_t) (size_t) l4);
                            vader_array_t* _a93_slotarr = ((vader_array_t*) l21);
                            VADER_ARRAY_RESOLVE_BUF(_a93_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a93_slotarr, l5)
                            ((int32_t*) _a93_slotarr->buf->slots)[_a93_slotarr->offset + (size_t) l5] = (int32_t) l51;
                            l52 = (size_t) 1;
                            t1 = (l4 + l52);
                            l4 = (size_t) (int64_t) t1;
                            l53 = (size_t) 1;
                            t1 = (l5 + l53);
                            l5 = (size_t) (int64_t) t1;
                            goto loop_187;
                        }
                        if (l10.tag == 506u) {
                            l41 = (size_t) 0;
                            if ((l4 > l41)) {
                                l42 = (size_t) 1;
                                t1 = (l4 - l42);
                                l43 = (size_t) (int64_t) t1;
                                vader_array_t* _a94_slotarr = ((vader_array_t*) l20);
                                VADER_ARRAY_RESOLVE_BUF(_a94_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a94_slotarr, l43)
                                l44 = vader_array_ref_load_box(_a94_slotarr->buf, _a94_slotarr->offset + (size_t) l43);
                                if (l44.tag == 506u) {
                                    l45 = -(INT32_C(1));
                                    vader_array_t* _a95_slotarr = ((vader_array_t*) l21);
                                    VADER_ARRAY_RESOLVE_BUF(_a95_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a95_slotarr, l5)
                                    ((int32_t*) _a95_slotarr->buf->slots)[_a95_slotarr->offset + (size_t) l5] = (int32_t) l45;
                                    l46 = (size_t) 1;
                                    t1 = (l4 - l46);
                                    l4 = (size_t) (int64_t) t1;
                                    l47 = (size_t) 1;
                                    t1 = (l5 + l47);
                                    l5 = (size_t) (int64_t) t1;
                                    goto loop_187;
                                }
                                if (l44.tag == 503u) {
                                    t2 = l44.payload.obj;
                                    t6 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                    vader_struct_vader_bytecode_BoolConst_t* _a96_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                    vader_obj_header_init(_a96_obj, 503u);
                                    _a96_obj->f_value = !(t6);
                                    l48 = (void*) _a96_obj;
                                    vader_array_t* _a97_slotarr = ((vader_array_t*) l20);
                                    VADER_ARRAY_RESOLVE_BUF(_a97_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a97_slotarr, l43)
                                    vader_array_ref_store(_a97_slotarr->buf, _a97_slotarr->offset + (size_t) l43, l48);
                                    VADER_WRITE_BARRIER(_a97_slotarr->buf);
                                    l49 = ((int32_t) (size_t) l43);
                                    vader_array_t* _a98_slotarr = ((vader_array_t*) l21);
                                    VADER_ARRAY_RESOLVE_BUF(_a98_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a98_slotarr, l5)
                                    ((int32_t*) _a98_slotarr->buf->slots)[_a98_slotarr->offset + (size_t) l5] = (int32_t) l49;
                                    l50 = (size_t) 1;
                                    t1 = (l5 + l50);
                                    l5 = (size_t) (int64_t) t1;
                                    goto loop_187;
                                }
                                vader_bytecode_push_or_assign(l20, l4, l10);
                                l51 = ((int32_t) (size_t) l4);
                                vader_array_t* _a99_slotarr = ((vader_array_t*) l21);
                                VADER_ARRAY_RESOLVE_BUF(_a99_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a99_slotarr, l5)
                                ((int32_t*) _a99_slotarr->buf->slots)[_a99_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                l52 = (size_t) 1;
                                t1 = (l4 + l52);
                                l4 = (size_t) (int64_t) t1;
                                l53 = (size_t) 1;
                                t1 = (l5 + l53);
                                l5 = (size_t) (int64_t) t1;
                                goto loop_187;
                            }
                            vader_bytecode_push_or_assign(l20, l4, l10);
                            l51 = ((int32_t) (size_t) l4);
                            vader_array_t* _a100_slotarr = ((vader_array_t*) l21);
                            VADER_ARRAY_RESOLVE_BUF(_a100_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a100_slotarr, l5)
                            ((int32_t*) _a100_slotarr->buf->slots)[_a100_slotarr->offset + (size_t) l5] = (int32_t) l51;
                            l52 = (size_t) 1;
                            t1 = (l4 + l52);
                            l4 = (size_t) (int64_t) t1;
                            l53 = (size_t) 1;
                            t1 = (l5 + l53);
                            l5 = (size_t) (int64_t) t1;
                            goto loop_187;
                        }
                        vader_bytecode_push_or_assign(l20, l4, l10);
                        l51 = ((int32_t) (size_t) l4);
                        vader_array_t* _a101_slotarr = ((vader_array_t*) l21);
                        VADER_ARRAY_RESOLVE_BUF(_a101_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a101_slotarr, l5)
                        ((int32_t*) _a101_slotarr->buf->slots)[_a101_slotarr->offset + (size_t) l5] = (int32_t) l51;
                        l52 = (size_t) 1;
                        t1 = (l4 + l52);
                        l4 = (size_t) (int64_t) t1;
                        l53 = (size_t) 1;
                        t1 = (l5 + l53);
                        l5 = (size_t) (int64_t) t1;
                        goto loop_187;
                    }
                    if (l10.tag == 606u) {
                        l30 = !(l1);
                    } else {
                        l30 = false;
                    }
                    if (l30) {
                        l18 = ((vader_array_t*) l20)->length;
                        l31 = (size_t) 0;
                        if ((l18 > l31)) {
                            l32 = (size_t) 1;
                            t1 = (l18 - l32);
                            l33 = (size_t) (int64_t) t1;
                            vader_array_t* _a102_slotarr = ((vader_array_t*) l20);
                            VADER_ARRAY_RESOLVE_BUF(_a102_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a102_slotarr, l33)
                            t4 = vader_array_ref_load_box(_a102_slotarr->buf, _a102_slotarr->offset + (size_t) l33);
                            l34 = vader_bytecode_const_op_of(t4);
                            if (!(l34.tag == 0u)) {
                                l35 = (size_t) 1;
                                t1 = (l18 - l35);
                                l36 = (size_t) (int64_t) t1;
                                vader_struct_vader_bytecode_ReturnLit_t* _a103_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                                vader_obj_header_init(_a103_obj, 607u);
                                _a103_obj->f_value = l34;
                                l37 = (void*) _a103_obj;
                                vader_array_t* _a104_slotarr = ((vader_array_t*) l20);
                                VADER_ARRAY_RESOLVE_BUF(_a104_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a104_slotarr, l36)
                                vader_array_ref_store(_a104_slotarr->buf, _a104_slotarr->offset + (size_t) l36, l37);
                                VADER_WRITE_BARRIER(_a104_slotarr->buf);
                                l38 = (size_t) 1;
                                l39 = ((int32_t) (int64_t) (l4 - l38));
                                vader_array_t* _a105_slotarr = ((vader_array_t*) l21);
                                VADER_ARRAY_RESOLVE_BUF(_a105_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a105_slotarr, l5)
                                ((int32_t*) _a105_slotarr->buf->slots)[_a105_slotarr->offset + (size_t) l5] = (int32_t) l39;
                                l40 = (size_t) 1;
                                t1 = (l5 + l40);
                                l5 = (size_t) (int64_t) t1;
                                goto loop_187;
                            }
                            if (l10.tag == 506u) {
                                l41 = (size_t) 0;
                                if ((l4 > l41)) {
                                    l42 = (size_t) 1;
                                    t1 = (l4 - l42);
                                    l43 = (size_t) (int64_t) t1;
                                    vader_array_t* _a106_slotarr = ((vader_array_t*) l20);
                                    VADER_ARRAY_RESOLVE_BUF(_a106_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a106_slotarr, l43)
                                    l44 = vader_array_ref_load_box(_a106_slotarr->buf, _a106_slotarr->offset + (size_t) l43);
                                    if (l44.tag == 506u) {
                                        l45 = -(INT32_C(1));
                                        vader_array_t* _a107_slotarr = ((vader_array_t*) l21);
                                        VADER_ARRAY_RESOLVE_BUF(_a107_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a107_slotarr, l5)
                                        ((int32_t*) _a107_slotarr->buf->slots)[_a107_slotarr->offset + (size_t) l5] = (int32_t) l45;
                                        l46 = (size_t) 1;
                                        t1 = (l4 - l46);
                                        l4 = (size_t) (int64_t) t1;
                                        l47 = (size_t) 1;
                                        t1 = (l5 + l47);
                                        l5 = (size_t) (int64_t) t1;
                                        goto loop_187;
                                    }
                                    if (l44.tag == 503u) {
                                        t2 = l44.payload.obj;
                                        t6 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                        vader_struct_vader_bytecode_BoolConst_t* _a108_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                        vader_obj_header_init(_a108_obj, 503u);
                                        _a108_obj->f_value = !(t6);
                                        l48 = (void*) _a108_obj;
                                        vader_array_t* _a109_slotarr = ((vader_array_t*) l20);
                                        VADER_ARRAY_RESOLVE_BUF(_a109_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a109_slotarr, l43)
                                        vader_array_ref_store(_a109_slotarr->buf, _a109_slotarr->offset + (size_t) l43, l48);
                                        VADER_WRITE_BARRIER(_a109_slotarr->buf);
                                        l49 = ((int32_t) (size_t) l43);
                                        vader_array_t* _a110_slotarr = ((vader_array_t*) l21);
                                        VADER_ARRAY_RESOLVE_BUF(_a110_slotarr)
                                        VADER_ARRAY_CHECK_INDEX(_a110_slotarr, l5)
                                        ((int32_t*) _a110_slotarr->buf->slots)[_a110_slotarr->offset + (size_t) l5] = (int32_t) l49;
                                        l50 = (size_t) 1;
                                        t1 = (l5 + l50);
                                        l5 = (size_t) (int64_t) t1;
                                        goto loop_187;
                                    }
                                    vader_bytecode_push_or_assign(l20, l4, l10);
                                    l51 = ((int32_t) (size_t) l4);
                                    vader_array_t* _a111_slotarr = ((vader_array_t*) l21);
                                    VADER_ARRAY_RESOLVE_BUF(_a111_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a111_slotarr, l5)
                                    ((int32_t*) _a111_slotarr->buf->slots)[_a111_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                    l52 = (size_t) 1;
                                    t1 = (l4 + l52);
                                    l4 = (size_t) (int64_t) t1;
                                    l53 = (size_t) 1;
                                    t1 = (l5 + l53);
                                    l5 = (size_t) (int64_t) t1;
                                    goto loop_187;
                                }
                                vader_bytecode_push_or_assign(l20, l4, l10);
                                l51 = ((int32_t) (size_t) l4);
                                vader_array_t* _a112_slotarr = ((vader_array_t*) l21);
                                VADER_ARRAY_RESOLVE_BUF(_a112_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a112_slotarr, l5)
                                ((int32_t*) _a112_slotarr->buf->slots)[_a112_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                l52 = (size_t) 1;
                                t1 = (l4 + l52);
                                l4 = (size_t) (int64_t) t1;
                                l53 = (size_t) 1;
                                t1 = (l5 + l53);
                                l5 = (size_t) (int64_t) t1;
                                goto loop_187;
                            }
                            vader_bytecode_push_or_assign(l20, l4, l10);
                            l51 = ((int32_t) (size_t) l4);
                            vader_array_t* _a113_slotarr = ((vader_array_t*) l21);
                            VADER_ARRAY_RESOLVE_BUF(_a113_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a113_slotarr, l5)
                            ((int32_t*) _a113_slotarr->buf->slots)[_a113_slotarr->offset + (size_t) l5] = (int32_t) l51;
                            l52 = (size_t) 1;
                            t1 = (l4 + l52);
                            l4 = (size_t) (int64_t) t1;
                            l53 = (size_t) 1;
                            t1 = (l5 + l53);
                            l5 = (size_t) (int64_t) t1;
                            goto loop_187;
                        }
                        if (l10.tag == 506u) {
                            l41 = (size_t) 0;
                            if ((l4 > l41)) {
                                l42 = (size_t) 1;
                                t1 = (l4 - l42);
                                l43 = (size_t) (int64_t) t1;
                                vader_array_t* _a114_slotarr = ((vader_array_t*) l20);
                                VADER_ARRAY_RESOLVE_BUF(_a114_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a114_slotarr, l43)
                                l44 = vader_array_ref_load_box(_a114_slotarr->buf, _a114_slotarr->offset + (size_t) l43);
                                if (l44.tag == 506u) {
                                    l45 = -(INT32_C(1));
                                    vader_array_t* _a115_slotarr = ((vader_array_t*) l21);
                                    VADER_ARRAY_RESOLVE_BUF(_a115_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a115_slotarr, l5)
                                    ((int32_t*) _a115_slotarr->buf->slots)[_a115_slotarr->offset + (size_t) l5] = (int32_t) l45;
                                    l46 = (size_t) 1;
                                    t1 = (l4 - l46);
                                    l4 = (size_t) (int64_t) t1;
                                    l47 = (size_t) 1;
                                    t1 = (l5 + l47);
                                    l5 = (size_t) (int64_t) t1;
                                    goto loop_187;
                                }
                                if (l44.tag == 503u) {
                                    t2 = l44.payload.obj;
                                    t6 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                    vader_struct_vader_bytecode_BoolConst_t* _a116_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                    vader_obj_header_init(_a116_obj, 503u);
                                    _a116_obj->f_value = !(t6);
                                    l48 = (void*) _a116_obj;
                                    vader_array_t* _a117_slotarr = ((vader_array_t*) l20);
                                    VADER_ARRAY_RESOLVE_BUF(_a117_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a117_slotarr, l43)
                                    vader_array_ref_store(_a117_slotarr->buf, _a117_slotarr->offset + (size_t) l43, l48);
                                    VADER_WRITE_BARRIER(_a117_slotarr->buf);
                                    l49 = ((int32_t) (size_t) l43);
                                    vader_array_t* _a118_slotarr = ((vader_array_t*) l21);
                                    VADER_ARRAY_RESOLVE_BUF(_a118_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a118_slotarr, l5)
                                    ((int32_t*) _a118_slotarr->buf->slots)[_a118_slotarr->offset + (size_t) l5] = (int32_t) l49;
                                    l50 = (size_t) 1;
                                    t1 = (l5 + l50);
                                    l5 = (size_t) (int64_t) t1;
                                    goto loop_187;
                                }
                                vader_bytecode_push_or_assign(l20, l4, l10);
                                l51 = ((int32_t) (size_t) l4);
                                vader_array_t* _a119_slotarr = ((vader_array_t*) l21);
                                VADER_ARRAY_RESOLVE_BUF(_a119_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a119_slotarr, l5)
                                ((int32_t*) _a119_slotarr->buf->slots)[_a119_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                l52 = (size_t) 1;
                                t1 = (l4 + l52);
                                l4 = (size_t) (int64_t) t1;
                                l53 = (size_t) 1;
                                t1 = (l5 + l53);
                                l5 = (size_t) (int64_t) t1;
                                goto loop_187;
                            }
                            vader_bytecode_push_or_assign(l20, l4, l10);
                            l51 = ((int32_t) (size_t) l4);
                            vader_array_t* _a120_slotarr = ((vader_array_t*) l21);
                            VADER_ARRAY_RESOLVE_BUF(_a120_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a120_slotarr, l5)
                            ((int32_t*) _a120_slotarr->buf->slots)[_a120_slotarr->offset + (size_t) l5] = (int32_t) l51;
                            l52 = (size_t) 1;
                            t1 = (l4 + l52);
                            l4 = (size_t) (int64_t) t1;
                            l53 = (size_t) 1;
                            t1 = (l5 + l53);
                            l5 = (size_t) (int64_t) t1;
                            goto loop_187;
                        }
                        vader_bytecode_push_or_assign(l20, l4, l10);
                        l51 = ((int32_t) (size_t) l4);
                        vader_array_t* _a121_slotarr = ((vader_array_t*) l21);
                        VADER_ARRAY_RESOLVE_BUF(_a121_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a121_slotarr, l5)
                        ((int32_t*) _a121_slotarr->buf->slots)[_a121_slotarr->offset + (size_t) l5] = (int32_t) l51;
                        l52 = (size_t) 1;
                        t1 = (l4 + l52);
                        l4 = (size_t) (int64_t) t1;
                        l53 = (size_t) 1;
                        t1 = (l5 + l53);
                        l5 = (size_t) (int64_t) t1;
                        goto loop_187;
                    }
                    if (l10.tag == 506u) {
                        l41 = (size_t) 0;
                        if ((l4 > l41)) {
                            l42 = (size_t) 1;
                            t1 = (l4 - l42);
                            l43 = (size_t) (int64_t) t1;
                            vader_array_t* _a122_slotarr = ((vader_array_t*) l20);
                            VADER_ARRAY_RESOLVE_BUF(_a122_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a122_slotarr, l43)
                            l44 = vader_array_ref_load_box(_a122_slotarr->buf, _a122_slotarr->offset + (size_t) l43);
                            if (l44.tag == 506u) {
                                l45 = -(INT32_C(1));
                                vader_array_t* _a123_slotarr = ((vader_array_t*) l21);
                                VADER_ARRAY_RESOLVE_BUF(_a123_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a123_slotarr, l5)
                                ((int32_t*) _a123_slotarr->buf->slots)[_a123_slotarr->offset + (size_t) l5] = (int32_t) l45;
                                l46 = (size_t) 1;
                                t1 = (l4 - l46);
                                l4 = (size_t) (int64_t) t1;
                                l47 = (size_t) 1;
                                t1 = (l5 + l47);
                                l5 = (size_t) (int64_t) t1;
                                goto loop_187;
                            }
                            if (l44.tag == 503u) {
                                t2 = l44.payload.obj;
                                t6 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                vader_struct_vader_bytecode_BoolConst_t* _a124_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                vader_obj_header_init(_a124_obj, 503u);
                                _a124_obj->f_value = !(t6);
                                l48 = (void*) _a124_obj;
                                vader_array_t* _a125_slotarr = ((vader_array_t*) l20);
                                VADER_ARRAY_RESOLVE_BUF(_a125_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a125_slotarr, l43)
                                vader_array_ref_store(_a125_slotarr->buf, _a125_slotarr->offset + (size_t) l43, l48);
                                VADER_WRITE_BARRIER(_a125_slotarr->buf);
                                l49 = ((int32_t) (size_t) l43);
                                vader_array_t* _a126_slotarr = ((vader_array_t*) l21);
                                VADER_ARRAY_RESOLVE_BUF(_a126_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a126_slotarr, l5)
                                ((int32_t*) _a126_slotarr->buf->slots)[_a126_slotarr->offset + (size_t) l5] = (int32_t) l49;
                                l50 = (size_t) 1;
                                t1 = (l5 + l50);
                                l5 = (size_t) (int64_t) t1;
                                goto loop_187;
                            }
                            vader_bytecode_push_or_assign(l20, l4, l10);
                            l51 = ((int32_t) (size_t) l4);
                            vader_array_t* _a127_slotarr = ((vader_array_t*) l21);
                            VADER_ARRAY_RESOLVE_BUF(_a127_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a127_slotarr, l5)
                            ((int32_t*) _a127_slotarr->buf->slots)[_a127_slotarr->offset + (size_t) l5] = (int32_t) l51;
                            l52 = (size_t) 1;
                            t1 = (l4 + l52);
                            l4 = (size_t) (int64_t) t1;
                            l53 = (size_t) 1;
                            t1 = (l5 + l53);
                            l5 = (size_t) (int64_t) t1;
                            goto loop_187;
                        }
                        vader_bytecode_push_or_assign(l20, l4, l10);
                        l51 = ((int32_t) (size_t) l4);
                        vader_array_t* _a128_slotarr = ((vader_array_t*) l21);
                        VADER_ARRAY_RESOLVE_BUF(_a128_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a128_slotarr, l5)
                        ((int32_t*) _a128_slotarr->buf->slots)[_a128_slotarr->offset + (size_t) l5] = (int32_t) l51;
                        l52 = (size_t) 1;
                        t1 = (l4 + l52);
                        l4 = (size_t) (int64_t) t1;
                        l53 = (size_t) 1;
                        t1 = (l5 + l53);
                        l5 = (size_t) (int64_t) t1;
                        goto loop_187;
                    }
                    vader_bytecode_push_or_assign(l20, l4, l10);
                    l51 = ((int32_t) (size_t) l4);
                    vader_array_t* _a129_slotarr = ((vader_array_t*) l21);
                    VADER_ARRAY_RESOLVE_BUF(_a129_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a129_slotarr, l5)
                    ((int32_t*) _a129_slotarr->buf->slots)[_a129_slotarr->offset + (size_t) l5] = (int32_t) l51;
                    l52 = (size_t) 1;
                    t1 = (l4 + l52);
                    l4 = (size_t) (int64_t) t1;
                    l53 = (size_t) 1;
                    t1 = (l5 + l53);
                    l5 = (size_t) (int64_t) t1;
                    goto loop_187;
                }
                if (l10.tag == 606u) {
                    l30 = !(l1);
                } else {
                    l30 = false;
                }
                if (l30) {
                    l18 = ((vader_array_t*) l20)->length;
                    l31 = (size_t) 0;
                    if ((l18 > l31)) {
                        l32 = (size_t) 1;
                        t1 = (l18 - l32);
                        l33 = (size_t) (int64_t) t1;
                        vader_array_t* _a130_slotarr = ((vader_array_t*) l20);
                        VADER_ARRAY_RESOLVE_BUF(_a130_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a130_slotarr, l33)
                        t4 = vader_array_ref_load_box(_a130_slotarr->buf, _a130_slotarr->offset + (size_t) l33);
                        l34 = vader_bytecode_const_op_of(t4);
                        if (!(l34.tag == 0u)) {
                            l35 = (size_t) 1;
                            t1 = (l18 - l35);
                            l36 = (size_t) (int64_t) t1;
                            vader_struct_vader_bytecode_ReturnLit_t* _a131_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                            vader_obj_header_init(_a131_obj, 607u);
                            _a131_obj->f_value = l34;
                            l37 = (void*) _a131_obj;
                            vader_array_t* _a132_slotarr = ((vader_array_t*) l20);
                            VADER_ARRAY_RESOLVE_BUF(_a132_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a132_slotarr, l36)
                            vader_array_ref_store(_a132_slotarr->buf, _a132_slotarr->offset + (size_t) l36, l37);
                            VADER_WRITE_BARRIER(_a132_slotarr->buf);
                            l38 = (size_t) 1;
                            l39 = ((int32_t) (int64_t) (l4 - l38));
                            vader_array_t* _a133_slotarr = ((vader_array_t*) l21);
                            VADER_ARRAY_RESOLVE_BUF(_a133_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a133_slotarr, l5)
                            ((int32_t*) _a133_slotarr->buf->slots)[_a133_slotarr->offset + (size_t) l5] = (int32_t) l39;
                            l40 = (size_t) 1;
                            t1 = (l5 + l40);
                            l5 = (size_t) (int64_t) t1;
                            goto loop_187;
                        }
                        if (l10.tag == 506u) {
                            l41 = (size_t) 0;
                            if ((l4 > l41)) {
                                l42 = (size_t) 1;
                                t1 = (l4 - l42);
                                l43 = (size_t) (int64_t) t1;
                                vader_array_t* _a134_slotarr = ((vader_array_t*) l20);
                                VADER_ARRAY_RESOLVE_BUF(_a134_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a134_slotarr, l43)
                                l44 = vader_array_ref_load_box(_a134_slotarr->buf, _a134_slotarr->offset + (size_t) l43);
                                if (l44.tag == 506u) {
                                    l45 = -(INT32_C(1));
                                    vader_array_t* _a135_slotarr = ((vader_array_t*) l21);
                                    VADER_ARRAY_RESOLVE_BUF(_a135_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a135_slotarr, l5)
                                    ((int32_t*) _a135_slotarr->buf->slots)[_a135_slotarr->offset + (size_t) l5] = (int32_t) l45;
                                    l46 = (size_t) 1;
                                    t1 = (l4 - l46);
                                    l4 = (size_t) (int64_t) t1;
                                    l47 = (size_t) 1;
                                    t1 = (l5 + l47);
                                    l5 = (size_t) (int64_t) t1;
                                    goto loop_187;
                                }
                                if (l44.tag == 503u) {
                                    t2 = l44.payload.obj;
                                    t6 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                    vader_struct_vader_bytecode_BoolConst_t* _a136_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                    vader_obj_header_init(_a136_obj, 503u);
                                    _a136_obj->f_value = !(t6);
                                    l48 = (void*) _a136_obj;
                                    vader_array_t* _a137_slotarr = ((vader_array_t*) l20);
                                    VADER_ARRAY_RESOLVE_BUF(_a137_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a137_slotarr, l43)
                                    vader_array_ref_store(_a137_slotarr->buf, _a137_slotarr->offset + (size_t) l43, l48);
                                    VADER_WRITE_BARRIER(_a137_slotarr->buf);
                                    l49 = ((int32_t) (size_t) l43);
                                    vader_array_t* _a138_slotarr = ((vader_array_t*) l21);
                                    VADER_ARRAY_RESOLVE_BUF(_a138_slotarr)
                                    VADER_ARRAY_CHECK_INDEX(_a138_slotarr, l5)
                                    ((int32_t*) _a138_slotarr->buf->slots)[_a138_slotarr->offset + (size_t) l5] = (int32_t) l49;
                                    l50 = (size_t) 1;
                                    t1 = (l5 + l50);
                                    l5 = (size_t) (int64_t) t1;
                                    goto loop_187;
                                }
                                vader_bytecode_push_or_assign(l20, l4, l10);
                                l51 = ((int32_t) (size_t) l4);
                                vader_array_t* _a139_slotarr = ((vader_array_t*) l21);
                                VADER_ARRAY_RESOLVE_BUF(_a139_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a139_slotarr, l5)
                                ((int32_t*) _a139_slotarr->buf->slots)[_a139_slotarr->offset + (size_t) l5] = (int32_t) l51;
                                l52 = (size_t) 1;
                                t1 = (l4 + l52);
                                l4 = (size_t) (int64_t) t1;
                                l53 = (size_t) 1;
                                t1 = (l5 + l53);
                                l5 = (size_t) (int64_t) t1;
                                goto loop_187;
                            }
                            vader_bytecode_push_or_assign(l20, l4, l10);
                            l51 = ((int32_t) (size_t) l4);
                            vader_array_t* _a140_slotarr = ((vader_array_t*) l21);
                            VADER_ARRAY_RESOLVE_BUF(_a140_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a140_slotarr, l5)
                            ((int32_t*) _a140_slotarr->buf->slots)[_a140_slotarr->offset + (size_t) l5] = (int32_t) l51;
                            l52 = (size_t) 1;
                            t1 = (l4 + l52);
                            l4 = (size_t) (int64_t) t1;
                            l53 = (size_t) 1;
                            t1 = (l5 + l53);
                            l5 = (size_t) (int64_t) t1;
                            goto loop_187;
                        }
                        vader_bytecode_push_or_assign(l20, l4, l10);
                        l51 = ((int32_t) (size_t) l4);
                        vader_array_t* _a141_slotarr = ((vader_array_t*) l21);
                        VADER_ARRAY_RESOLVE_BUF(_a141_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a141_slotarr, l5)
                        ((int32_t*) _a141_slotarr->buf->slots)[_a141_slotarr->offset + (size_t) l5] = (int32_t) l51;
                        l52 = (size_t) 1;
                        t1 = (l4 + l52);
                        l4 = (size_t) (int64_t) t1;
                        l53 = (size_t) 1;
                        t1 = (l5 + l53);
                        l5 = (size_t) (int64_t) t1;
                        goto loop_187;
                    }
                    if (l10.tag == 506u) {
                        l41 = (size_t) 0;
                        if ((l4 > l41)) {
                            l42 = (size_t) 1;
                            t1 = (l4 - l42);
                            l43 = (size_t) (int64_t) t1;
                            vader_array_t* _a142_slotarr = ((vader_array_t*) l20);
                            VADER_ARRAY_RESOLVE_BUF(_a142_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a142_slotarr, l43)
                            l44 = vader_array_ref_load_box(_a142_slotarr->buf, _a142_slotarr->offset + (size_t) l43);
                            if (l44.tag == 506u) {
                                l45 = -(INT32_C(1));
                                vader_array_t* _a143_slotarr = ((vader_array_t*) l21);
                                VADER_ARRAY_RESOLVE_BUF(_a143_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a143_slotarr, l5)
                                ((int32_t*) _a143_slotarr->buf->slots)[_a143_slotarr->offset + (size_t) l5] = (int32_t) l45;
                                l46 = (size_t) 1;
                                t1 = (l4 - l46);
                                l4 = (size_t) (int64_t) t1;
                                l47 = (size_t) 1;
                                t1 = (l5 + l47);
                                l5 = (size_t) (int64_t) t1;
                                goto loop_187;
                            }
                            if (l44.tag == 503u) {
                                t2 = l44.payload.obj;
                                t6 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                vader_struct_vader_bytecode_BoolConst_t* _a144_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                vader_obj_header_init(_a144_obj, 503u);
                                _a144_obj->f_value = !(t6);
                                l48 = (void*) _a144_obj;
                                vader_array_t* _a145_slotarr = ((vader_array_t*) l20);
                                VADER_ARRAY_RESOLVE_BUF(_a145_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a145_slotarr, l43)
                                vader_array_ref_store(_a145_slotarr->buf, _a145_slotarr->offset + (size_t) l43, l48);
                                VADER_WRITE_BARRIER(_a145_slotarr->buf);
                                l49 = ((int32_t) (size_t) l43);
                                vader_array_t* _a146_slotarr = ((vader_array_t*) l21);
                                VADER_ARRAY_RESOLVE_BUF(_a146_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a146_slotarr, l5)
                                ((int32_t*) _a146_slotarr->buf->slots)[_a146_slotarr->offset + (size_t) l5] = (int32_t) l49;
                                l50 = (size_t) 1;
                                t1 = (l5 + l50);
                                l5 = (size_t) (int64_t) t1;
                                goto loop_187;
                            }
                            vader_bytecode_push_or_assign(l20, l4, l10);
                            l51 = ((int32_t) (size_t) l4);
                            vader_array_t* _a147_slotarr = ((vader_array_t*) l21);
                            VADER_ARRAY_RESOLVE_BUF(_a147_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a147_slotarr, l5)
                            ((int32_t*) _a147_slotarr->buf->slots)[_a147_slotarr->offset + (size_t) l5] = (int32_t) l51;
                            l52 = (size_t) 1;
                            t1 = (l4 + l52);
                            l4 = (size_t) (int64_t) t1;
                            l53 = (size_t) 1;
                            t1 = (l5 + l53);
                            l5 = (size_t) (int64_t) t1;
                            goto loop_187;
                        }
                        vader_bytecode_push_or_assign(l20, l4, l10);
                        l51 = ((int32_t) (size_t) l4);
                        vader_array_t* _a148_slotarr = ((vader_array_t*) l21);
                        VADER_ARRAY_RESOLVE_BUF(_a148_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a148_slotarr, l5)
                        ((int32_t*) _a148_slotarr->buf->slots)[_a148_slotarr->offset + (size_t) l5] = (int32_t) l51;
                        l52 = (size_t) 1;
                        t1 = (l4 + l52);
                        l4 = (size_t) (int64_t) t1;
                        l53 = (size_t) 1;
                        t1 = (l5 + l53);
                        l5 = (size_t) (int64_t) t1;
                        goto loop_187;
                    }
                    vader_bytecode_push_or_assign(l20, l4, l10);
                    l51 = ((int32_t) (size_t) l4);
                    vader_array_t* _a149_slotarr = ((vader_array_t*) l21);
                    VADER_ARRAY_RESOLVE_BUF(_a149_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a149_slotarr, l5)
                    ((int32_t*) _a149_slotarr->buf->slots)[_a149_slotarr->offset + (size_t) l5] = (int32_t) l51;
                    l52 = (size_t) 1;
                    t1 = (l4 + l52);
                    l4 = (size_t) (int64_t) t1;
                    l53 = (size_t) 1;
                    t1 = (l5 + l53);
                    l5 = (size_t) (int64_t) t1;
                    goto loop_187;
                }
                if (l10.tag == 506u) {
                    l41 = (size_t) 0;
                    if ((l4 > l41)) {
                        l42 = (size_t) 1;
                        t1 = (l4 - l42);
                        l43 = (size_t) (int64_t) t1;
                        vader_array_t* _a150_slotarr = ((vader_array_t*) l20);
                        VADER_ARRAY_RESOLVE_BUF(_a150_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a150_slotarr, l43)
                        l44 = vader_array_ref_load_box(_a150_slotarr->buf, _a150_slotarr->offset + (size_t) l43);
                        if (l44.tag == 506u) {
                            l45 = -(INT32_C(1));
                            vader_array_t* _a151_slotarr = ((vader_array_t*) l21);
                            VADER_ARRAY_RESOLVE_BUF(_a151_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a151_slotarr, l5)
                            ((int32_t*) _a151_slotarr->buf->slots)[_a151_slotarr->offset + (size_t) l5] = (int32_t) l45;
                            l46 = (size_t) 1;
                            t1 = (l4 - l46);
                            l4 = (size_t) (int64_t) t1;
                            l47 = (size_t) 1;
                            t1 = (l5 + l47);
                            l5 = (size_t) (int64_t) t1;
                            goto loop_187;
                        }
                        if (l44.tag == 503u) {
                            t2 = l44.payload.obj;
                            t6 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                            vader_struct_vader_bytecode_BoolConst_t* _a152_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                            vader_obj_header_init(_a152_obj, 503u);
                            _a152_obj->f_value = !(t6);
                            l48 = (void*) _a152_obj;
                            vader_array_t* _a153_slotarr = ((vader_array_t*) l20);
                            VADER_ARRAY_RESOLVE_BUF(_a153_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a153_slotarr, l43)
                            vader_array_ref_store(_a153_slotarr->buf, _a153_slotarr->offset + (size_t) l43, l48);
                            VADER_WRITE_BARRIER(_a153_slotarr->buf);
                            l49 = ((int32_t) (size_t) l43);
                            vader_array_t* _a154_slotarr = ((vader_array_t*) l21);
                            VADER_ARRAY_RESOLVE_BUF(_a154_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a154_slotarr, l5)
                            ((int32_t*) _a154_slotarr->buf->slots)[_a154_slotarr->offset + (size_t) l5] = (int32_t) l49;
                            l50 = (size_t) 1;
                            t1 = (l5 + l50);
                            l5 = (size_t) (int64_t) t1;
                            goto loop_187;
                        }
                        vader_bytecode_push_or_assign(l20, l4, l10);
                        l51 = ((int32_t) (size_t) l4);
                        vader_array_t* _a155_slotarr = ((vader_array_t*) l21);
                        VADER_ARRAY_RESOLVE_BUF(_a155_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a155_slotarr, l5)
                        ((int32_t*) _a155_slotarr->buf->slots)[_a155_slotarr->offset + (size_t) l5] = (int32_t) l51;
                        l52 = (size_t) 1;
                        t1 = (l4 + l52);
                        l4 = (size_t) (int64_t) t1;
                        l53 = (size_t) 1;
                        t1 = (l5 + l53);
                        l5 = (size_t) (int64_t) t1;
                        goto loop_187;
                    }
                    vader_bytecode_push_or_assign(l20, l4, l10);
                    l51 = ((int32_t) (size_t) l4);
                    vader_array_t* _a156_slotarr = ((vader_array_t*) l21);
                    VADER_ARRAY_RESOLVE_BUF(_a156_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a156_slotarr, l5)
                    ((int32_t*) _a156_slotarr->buf->slots)[_a156_slotarr->offset + (size_t) l5] = (int32_t) l51;
                    l52 = (size_t) 1;
                    t1 = (l4 + l52);
                    l4 = (size_t) (int64_t) t1;
                    l53 = (size_t) 1;
                    t1 = (l5 + l53);
                    l5 = (size_t) (int64_t) t1;
                    goto loop_187;
                }
                vader_bytecode_push_or_assign(l20, l4, l10);
                l51 = ((int32_t) (size_t) l4);
                vader_array_t* _a157_slotarr = ((vader_array_t*) l21);
                VADER_ARRAY_RESOLVE_BUF(_a157_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a157_slotarr, l5)
                ((int32_t*) _a157_slotarr->buf->slots)[_a157_slotarr->offset + (size_t) l5] = (int32_t) l51;
                l52 = (size_t) 1;
                t1 = (l4 + l52);
                l4 = (size_t) (int64_t) t1;
                l53 = (size_t) 1;
                t1 = (l5 + l53);
                l5 = (size_t) (int64_t) t1;
                goto loop_187;
            }
        }
    }
    vader_array_t* _a158_arr = vader_array_slice((vader_array_t*) l20, (size_t) INT64_C(0), (size_t) l4);
    l2 = (void*) _a158_arr;
    l6 = vader_bytecode_remap_jump_table(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l21, l4);
    l7 = vader_bytecode_remap_debug(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug, l21, l4);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a159_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a159_obj, 487u);
    _a159_obj->f_body = l2;
    _a159_obj->f_jump_table = l6;
    _a159_obj->f_debug = l7;
    t2 = (void*) _a159_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_bytecode_run_bc_return_lit_fold(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l13 = NULL;
    size_t l2, l4, l6, l9, l10, l12, l15, l16;
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
    vader_array_t* _a0_arr = vader_array_new(138u, 0u, 13u, 1148u);
    l3 = (void*) _a0_arr;
    l4 = (size_t) 0;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 193u);
    l5 = (void*) _a1_arr;
    l6 = (size_t) 0;
    {
        vader_array_t* _pc22_hdr = (vader_array_t*) l5;
        size_t _pc22_len = _pc22_hdr->length;
        size_t _pc22_cap = (_pc22_hdr->offset == 0 && !vader_array_is_borrowed(_pc22_hdr) && _pc22_hdr->length >= _pc22_hdr->buf->length) ? _pc22_hdr->capacity : (size_t) 0;
        void* _pc22_slots = _pc22_hdr->buf->slots;
        loop_22: {
            if ((l6 < l2)) {
                l7 = -(INT32_C(1));
                if (VADER_LIKELY(_pc22_len < _pc22_cap)) {
                    ((int32_t*) _pc22_slots)[_pc22_len] = (int32_t) (l7);
                    _pc22_len += 1;
                } else {
                    _pc22_hdr->length = _pc22_len;
                    if (_pc22_hdr->buf->length < _pc22_len) {
                        _pc22_hdr->buf->length = _pc22_len;
                    }
                    vader_array_push_i32((vader_array_t*) l5, l7);
                    _pc22_hdr = (vader_array_t*) l5;
                    _pc22_len = _pc22_hdr->length;
                    _pc22_cap = (_pc22_hdr->offset == 0 && !vader_array_is_borrowed(_pc22_hdr) && _pc22_hdr->length >= _pc22_hdr->buf->length) ? _pc22_hdr->capacity : (size_t) 0;
                    _pc22_slots = _pc22_hdr->buf->slots;
                }
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_22;
            }
            _pc22_hdr->length = _pc22_len;
            if (_pc22_hdr->buf->length < _pc22_len) {
                _pc22_hdr->buf->length = _pc22_len;
            }
        }
    }
    l6 = (size_t) 0;
    {
        loop_44: {
            if ((l6 < l2)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
                l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
                if (l8.tag == 606u) {
                    l9 = ((vader_array_t*) l3)->length;
                    if ((l9 > INT64_C(0))) {
                        t2 = (l9 - INT64_C(1));
                        l10 = (size_t) (int64_t) t2;
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
                        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l10)
                        t3 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l10);
                        l11 = vader_bytecode_const_op_of(t3);
                        if (!(l11.tag == 0u)) {
                            t2 = (l9 - INT64_C(1));
                            l12 = (size_t) (int64_t) t2;
                            vader_struct_vader_bytecode_ReturnLit_t* _a4_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                            vader_obj_header_init(_a4_obj, 607u);
                            _a4_obj->f_value = l11;
                            l13 = (void*) _a4_obj;
                            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l12)
                            vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l12, l13);
                            VADER_WRITE_BARRIER(_a5_slotarr->buf);
                            l7 = ((int32_t) (int64_t) (l9 - INT64_C(1)));
                            vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
                            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
                            ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l6] = (int32_t) l7;
                            t2 = (l6 + INT64_C(1));
                            l6 = (size_t) (int64_t) t2;
                            goto loop_44;
                        }
                        vader_bytecode_push_or_assign(l3, l4, l8);
                        l14 = ((int32_t) (size_t) l4);
                        vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
                        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l6)
                        ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l6] = (int32_t) l14;
                        l15 = (size_t) 1;
                        t2 = (l4 + l15);
                        l4 = (size_t) (int64_t) t2;
                        l16 = (size_t) 1;
                        t2 = (l6 + l16);
                        l6 = (size_t) (int64_t) t2;
                        goto loop_44;
                    }
                    vader_bytecode_push_or_assign(l3, l4, l8);
                    l14 = ((int32_t) (size_t) l4);
                    vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l6)
                    ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l6] = (int32_t) l14;
                    l15 = (size_t) 1;
                    t2 = (l4 + l15);
                    l4 = (size_t) (int64_t) t2;
                    l16 = (size_t) 1;
                    t2 = (l6 + l16);
                    l6 = (size_t) (int64_t) t2;
                    goto loop_44;
                }
                vader_bytecode_push_or_assign(l3, l4, l8);
                l14 = ((int32_t) (size_t) l4);
                vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l6)
                ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l6] = (int32_t) l14;
                l15 = (size_t) 1;
                t2 = (l4 + l15);
                l4 = (size_t) (int64_t) t2;
                l16 = (size_t) 1;
                t2 = (l6 + l16);
                l6 = (size_t) (int64_t) t2;
                goto loop_44;
            }
        }
    }
    vader_array_t* _a10_arr = vader_array_slice((vader_array_t*) l3, (size_t) INT64_C(0), (size_t) l4);
    l1 = (void*) _a10_arr;
    l3 = vader_bytecode_remap_jump_table(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l5, l4);
    l5 = vader_bytecode_remap_debug(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug, l5, l4);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a11_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a11_obj, 487u);
    _a11_obj->f_body = l1;
    _a11_obj->f_jump_table = l3;
    _a11_obj->f_debug = l5;
    t1 = (void*) _a11_obj;
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
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 0;
    {
        loop_18: {
            if ((l3 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
                l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                t0 = vader_bytecode_same_intern_class(l4, l5);
                if (!(t0)) {
                    { vader_gc_top = gc_frame.prev; return false; }
                }
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_18;
            }
        }
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
    if (l0.tag == 956u) {
        t0 = l0.payload.obj;
        t1 = vader_bytecode_same_intern_class(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 956u) {
        l2 = l0;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_types_DistinctType_t*) t0)->f_backing;
        t1 = vader_bytecode_same_intern_class(l2, l3);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 957u || l0.tag == 964u)) {
        l4 = true;
    } else {
        l4 = (l1.tag == 957u || l1.tag == 964u);
    }
    if (l4) {
        l5 = vader_bytecode_bare_intern_name(l0);
        l6 = vader_bytecode_bare_intern_name(l1);
        if (l5 == l6) {
            t2 = vader_bytecode_bare_intern_name(l0);
            l4 = t2 != 0u;
        } else {
            l4 = false;
        }
        { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 966u) {
        if (l1.tag == 966u) {
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
            l4 = vader_bytecode_same_class_list(l7, l8);
        } else {
            l4 = false;
        }
        { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 967u) {
        if (l1.tag == 967u) {
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
            l4 = vader_bytecode_same_class_list(l7, l8);
        } else {
            l4 = false;
        }
        { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 955u) {
        if (l1.tag == 955u) {
            t0 = l0.payload.obj;
            l2 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_element;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_element;
            l4 = vader_bytecode_same_intern_class(l2, l3);
        } else {
            l4 = false;
        }
        { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 971u) {
        if (l1.tag == 971u) {
            t0 = l0.payload.obj;
            l7 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
            l4 = vader_bytecode_same_class_list(l7, l8);
        } else {
            l4 = false;
        }
        { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 968u) {
        if (l1.tag == 968u) {
            t0 = l0.payload.obj;
            l7 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
            l4 = vader_bytecode_same_class_list(l7, l8);
        } else {
            l4 = false;
        }
        { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 958u) {
        if (l1.tag == 958u) {
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
            l4 = vader_bytecode_same_intern_class(l2, l3);
        } else {
            l4 = false;
        }
        { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = vader_bytecode_bare_intern_name(l0);
    l6 = vader_bytecode_bare_intern_name(l1);
    { bool __vret = l5 == l6; vader_gc_top = gc_frame.prev; return __vret; }
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
            l2 = l5 == l6;
        } else {
            l2 = false;
        }
        return l2;
    }
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_module_name;
    l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_module_name;
    if (l3 == l4) {
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_name;
        l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_name;
        l2 = l3 == l4;
    } else {
        l2 = false;
    }
    return l2;
}

static vader_box_t vader_bytecode_shl_op(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        vader_struct_vader_bytecode_I64Shl_t* _a0_obj = (vader_struct_vader_bytecode_I64Shl_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Shl_t));
        vader_obj_header_init(_a0_obj, 582u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Shl_t* _a1_obj = (vader_struct_vader_bytecode_I32Shl_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Shl_t));
    vader_obj_header_init(_a1_obj, 562u);
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
        if (l1) {
            vader_struct_vader_bytecode_I64ShrU_t* _a0_obj = (vader_struct_vader_bytecode_I64ShrU_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64ShrU_t));
            vader_obj_header_init(_a0_obj, 584u);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_I64Shr_t* _a1_obj = (vader_struct_vader_bytecode_I64Shr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Shr_t));
        vader_obj_header_init(_a1_obj, 583u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1) {
        vader_struct_vader_bytecode_I32ShrU_t* _a2_obj = (vader_struct_vader_bytecode_I32ShrU_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32ShrU_t));
        vader_obj_header_init(_a2_obj, 564u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Shr_t* _a3_obj = (vader_struct_vader_bytecode_I32Shr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Shr_t));
    vader_obj_header_init(_a3_obj, 563u);
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t vader_bytecode_size_of_bc_type(vader_box_t l0) {
    int32_t l1;
    void* t0;
    if (l0.tag == 489u) {
        t0 = l0.payload.obj;
        l1 = vader_bytecode_size_of_val_type(((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val);
    } else if (l0.tag == 493u) {
        l1 = INT32_C(8);
    } else if (l0.tag == 480u) {
        l1 = INT32_C(8);
    } else if (l0.tag == 483u) {
        l1 = INT32_C(8);
    } else if (l0.tag == 494u) {
        l1 = INT32_C(16);
    } else if (l0.tag == 490u) {
        l1 = INT32_C(16);
    } else {
        vader_unreachable("unreachable return in vader_bytecode$size_of_bc_type");
    }
    return l1;
}

int32_t vader_bytecode_size_of_val_type(uint8_t l0) {
    int32_t l1;
    if (l0 == INT32_C(0)) {
        l1 = INT32_C(1);
    } else if (l0 == INT32_C(5)) {
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
    } else if (l0 == INT32_C(19)) {
        l1 = INT32_C(16);
    } else {
        vader_unreachable("unreachable return in vader_bytecode$size_of_val_type");
    }
    return l1;
}

vader_box_t vader_bytecode_slot_load_op_for(uint8_t l0, bool l1) {
    uint8_t l2;
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_bytecode_slot_width_for(l0);
    if (l3.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((uint8_t) l3.payload.i);
    if (l2 == INT32_C(1)) {
        vader_struct_vader_bytecode_LoadSlotI32_t* _a0_obj = (vader_struct_vader_bytecode_LoadSlotI32_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LoadSlotI32_t));
        vader_obj_header_init(_a0_obj, 592u);
        _a0_obj->f_bounds_safe = l1;
        t1 = (void*) _a0_obj;
        l3 = vader_ref_box(t1);
    } else if (l2 == INT32_C(2)) {
        vader_struct_vader_bytecode_LoadSlotI64_t* _a1_obj = (vader_struct_vader_bytecode_LoadSlotI64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LoadSlotI64_t));
        vader_obj_header_init(_a1_obj, 593u);
        _a1_obj->f_bounds_safe = l1;
        t1 = (void*) _a1_obj;
        l3 = vader_ref_box(t1);
    } else if (l2 == INT32_C(3)) {
        vader_struct_vader_bytecode_LoadSlotF64_t* _a2_obj = (vader_struct_vader_bytecode_LoadSlotF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LoadSlotF64_t));
        vader_obj_header_init(_a2_obj, 591u);
        _a2_obj->f_bounds_safe = l1;
        t1 = (void*) _a2_obj;
        l3 = vader_ref_box(t1);
    } else if (l2 == INT32_C(0)) {
        l3 = vader_box_obj(0u, NULL);
    } else if (l2 == INT32_C(4)) {
        l3 = vader_box_obj(0u, NULL);
    } else {
        vader_unreachable("unreachable return in vader_bytecode$slot_load_op_for");
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_bytecode_slot_store_op_for(uint8_t l0, bool l1) {
    uint8_t l2;
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_bytecode_slot_width_for(l0);
    if (l3.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((uint8_t) l3.payload.i);
    if (l2 == INT32_C(1)) {
        vader_struct_vader_bytecode_StoreSlotI32_t* _a0_obj = (vader_struct_vader_bytecode_StoreSlotI32_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StoreSlotI32_t));
        vader_obj_header_init(_a0_obj, 614u);
        _a0_obj->f_bounds_safe = l1;
        t1 = (void*) _a0_obj;
        l3 = vader_ref_box(t1);
    } else if (l2 == INT32_C(2)) {
        vader_struct_vader_bytecode_StoreSlotI64_t* _a1_obj = (vader_struct_vader_bytecode_StoreSlotI64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StoreSlotI64_t));
        vader_obj_header_init(_a1_obj, 615u);
        _a1_obj->f_bounds_safe = l1;
        t1 = (void*) _a1_obj;
        l3 = vader_ref_box(t1);
    } else if (l2 == INT32_C(3)) {
        vader_struct_vader_bytecode_StoreSlotF64_t* _a2_obj = (vader_struct_vader_bytecode_StoreSlotF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StoreSlotF64_t));
        vader_obj_header_init(_a2_obj, 613u);
        _a2_obj->f_bounds_safe = l1;
        t1 = (void*) _a2_obj;
        l3 = vader_ref_box(t1);
    } else if (l2 == INT32_C(0)) {
        l3 = vader_box_obj(0u, NULL);
    } else if (l2 == INT32_C(4)) {
        l3 = vader_box_obj(0u, NULL);
    } else {
        vader_unreachable("unreachable return in vader_bytecode$slot_store_op_for");
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_bytecode_slot_touched(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (l0.tag == 596u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalGet_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 597u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 598u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 595u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_slot;
        return t1;
    }
    return -(INT32_C(1));
}

static vader_box_t vader_bytecode_slot_width_for(uint8_t l0) {
    vader_box_t l1;
    if (l0 == INT32_C(0)) {
        l1 = vader_box_i32(193u, INT32_C(0));
    } else if (l0 == INT32_C(5)) {
        l1 = vader_box_i32(193u, INT32_C(0));
    } else if (l0 == INT32_C(12)) {
        l1 = vader_box_i32(193u, INT32_C(0));
    } else if (l0 == INT32_C(1)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(6)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(2)) {
        l1 = vader_box_i32(193u, INT32_C(1));
    } else if (l0 == INT32_C(7)) {
        l1 = vader_box_i32(193u, INT32_C(1));
    } else if (l0 == INT32_C(13)) {
        l1 = vader_box_i32(193u, INT32_C(1));
    } else if (l0 == INT32_C(10)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(3)) {
        l1 = vader_box_i32(193u, INT32_C(2));
    } else if (l0 == INT32_C(8)) {
        l1 = vader_box_i32(193u, INT32_C(2));
    } else if (l0 == INT32_C(4)) {
        l1 = vader_box_i32(193u, INT32_C(2));
    } else if (l0 == INT32_C(9)) {
        l1 = vader_box_i32(193u, INT32_C(2));
    } else if (l0 == INT32_C(11)) {
        l1 = vader_box_i32(193u, INT32_C(3));
    } else if (l0 == INT32_C(14)) {
        l1 = vader_box_i32(193u, INT32_C(4));
    } else if (l0 == INT32_C(15)) {
        l1 = vader_box_i32(193u, INT32_C(4));
    } else if (l0 == INT32_C(16)) {
        l1 = vader_box_i32(193u, INT32_C(4));
    } else if (l0 == INT32_C(17)) {
        l1 = vader_box_i32(193u, INT32_C(2));
    } else if (l0 == INT32_C(18)) {
        l1 = vader_box_i32(193u, INT32_C(4));
    } else if (l0 == INT32_C(19)) {
        l1 = vader_box_i32(193u, INT32_C(4));
    } else {
        vader_unreachable("unreachable return in vader_bytecode$slot_width_for");
    }
    return l1;
}

static vader_box_t vader_bytecode_strip_core_member(vader_string_t l0, vader_string_t l1) {
    bool l2;
    void* l3 = NULL;
    size_t l4, l5, l6;
    bool t0;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    void* t3 = NULL;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l3, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string_starts_with(l0, 1957u);
    if (!(t0)) {
        l2 = true;
    } else {
        t0 = std_string_ends_with(l0, l1);
        l2 = !(t0);
    }
    if (l2) {
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_host_std_core_bytes(l0);
    l4 = vader_host_std_core_byte_len(1957u);
    l5 = ((vader_array_t*) l3)->length;
    l6 = vader_host_std_core_byte_len(l1);
    t2 = (l5 - l6);
    l5 = (size_t) (int64_t) t2;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l3, (size_t) l4, (size_t) l5);
    t3 = (void*) _a0_arr;
    t4 = vader_host_std_core_bytes_to_string(t3);
    t1 = vader_box_string(190u, t4);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    {
        loop_13: {
            if ((l5 < l2)) {
                t0 = vader_bytecode_foldable_self_copy(l1, l5, l2, l3);
                if (t0) {
                    l4 = true;
                } else {
                    t1 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t1;
                    goto loop_13;
                }
            }
        }
    }
    if (!(l4)) {
        t2 = vader_bytecode_bc_peephole_unchanged(l0);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(138u, 0u, 13u, 1148u);
    l6 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 1u, 7u, 193u);
    ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) -(INT32_C(1));
    t2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t2, (size_t) l2);
    l7 = (void*) _a2_arr;
    l5 = (size_t) 0;
    {
        loop_54: {
            if ((l5 < l2)) {
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
                    if (t3.tag == 598u) {
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
                    goto loop_54;
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
                goto loop_54;
            }
        }
    }
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l2 = ((vader_array_t*) l6)->length;
    l1 = vader_bytecode_remap_jump_table(l1, l7, l2);
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug;
    l2 = ((vader_array_t*) l6)->length;
    l3 = vader_bytecode_remap_debug(l3, l7, l2);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a9_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a9_obj, 487u);
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
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 0;
    {
        loop_6: {
            if ((l3 < l2)) {
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
                l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                if (l4.tag == 493u) {
                    t0 = l4.payload.obj;
                    t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_name;
                    if (t1 == l1) {
                        return ((int32_t) (size_t) l3);
                    }
                }
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_6;
            }
        }
    }
    return -(INT32_C(1));
}

static uint64_t vader_bytecode_symbol_hash(void* l0) {
    uint64_t l1, l2;
    vader_string_t t0 = 0;
    int32_t t1;
    int64_t t2;
    uint64_t t3;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_module_name;
    if (t0 == 0u) {
        l1 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 101);
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
        t2 = ((int64_t) (uint32_t) t1);
        l2 = (uint64_t) (int64_t) t2;
        t3 = vader_bytecode_mix64(l1, l2);
        { uint64_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_module_name;
    l1 = std_core_string_Hash_hash_vt(t0);
    l1 = vader_bytecode_mix64((uint64_t) -3750763034362895579, l1);
    t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_name;
    l2 = std_core_string_Hash_hash_vt(t0);
    t3 = vader_bytecode_mix64(l1, l2);
    { uint64_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
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
    if (t0 == 0u) {
        l1 = std_core_new_byte_buffer((size_t) 22);
        l2 = (size_t) 0;
        l2 = std_core_write_string_at(l1, l2, 1580u);
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
        l3 = ((int64_t) (int32_t) t1);
        l2 = std_core_write_int(l1, l2, l3);
        t0 = std_core_finish_buffer(l1, l2);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_module_name;
    l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_name;
    t0 = concat_3(l4, 258u, l5);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_bytecode_try_fold_arith(vader_box_t l0, void* l1, size_t l2) {
    size_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    int32_t l6, l7;
    int64_t l8, l9;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l4, &l5, &t0 };
    void** gc_raw_roots[2] = { &l1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l2 < INT64_C(2))) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = (l2 - INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    t1 = (l2 - INT64_C(2));
    l3 = (size_t) (int64_t) t1;
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l5.tag == 551u) {
        if (l4.tag == 551u) {
            if (l0.tag == 546u) {
                t2 = l5.payload.obj;
                l6 = ((vader_struct_vader_bytecode_I32Const_t*) t2)->f_value;
                t2 = l4.payload.obj;
                l7 = ((vader_struct_vader_bytecode_I32Const_t*) t2)->f_value;
                vader_struct_vader_bytecode_I32Const_t* _a1_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
                vader_obj_header_init(_a1_obj, 551u);
                _a1_obj->f_value = (l6 + l7);
                t2 = (void*) _a1_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 565u) {
                t2 = l5.payload.obj;
                l6 = ((vader_struct_vader_bytecode_I32Const_t*) t2)->f_value;
                t2 = l4.payload.obj;
                l7 = ((vader_struct_vader_bytecode_I32Const_t*) t2)->f_value;
                vader_struct_vader_bytecode_I32Const_t* _a2_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
                vader_obj_header_init(_a2_obj, 551u);
                _a2_obj->f_value = (l6 - l7);
                t2 = (void*) _a2_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 559u) {
                t2 = l5.payload.obj;
                l6 = ((vader_struct_vader_bytecode_I32Const_t*) t2)->f_value;
                t2 = l4.payload.obj;
                l7 = ((vader_struct_vader_bytecode_I32Const_t*) t2)->f_value;
                vader_struct_vader_bytecode_I32Const_t* _a3_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
                vader_obj_header_init(_a3_obj, 551u);
                _a3_obj->f_value = (l6 * l7);
                t2 = (void*) _a3_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    if (l5.tag == 571u) {
        if (l4.tag == 571u) {
            if (l0.tag == 566u) {
                t2 = l5.payload.obj;
                l8 = ((vader_struct_vader_bytecode_I64Const_t*) t2)->f_value;
                t2 = l4.payload.obj;
                l9 = ((vader_struct_vader_bytecode_I64Const_t*) t2)->f_value;
                vader_struct_vader_bytecode_I64Const_t* _a4_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                vader_obj_header_init(_a4_obj, 571u);
                _a4_obj->f_value = (l8 + l9);
                t2 = (void*) _a4_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 585u) {
                t2 = l5.payload.obj;
                l8 = ((vader_struct_vader_bytecode_I64Const_t*) t2)->f_value;
                t2 = l4.payload.obj;
                l9 = ((vader_struct_vader_bytecode_I64Const_t*) t2)->f_value;
                vader_struct_vader_bytecode_I64Const_t* _a5_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                vader_obj_header_init(_a5_obj, 571u);
                _a5_obj->f_value = (l8 - l9);
                t2 = (void*) _a5_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 579u) {
                t2 = l5.payload.obj;
                l8 = ((vader_struct_vader_bytecode_I64Const_t*) t2)->f_value;
                t2 = l4.payload.obj;
                l9 = ((vader_struct_vader_bytecode_I64Const_t*) t2)->f_value;
                vader_struct_vader_bytecode_I64Const_t* _a6_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                vader_obj_header_init(_a6_obj, 571u);
                _a6_obj->f_value = (l8 * l9);
                t2 = (void*) _a6_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    t0 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_bytecode_tuple_shape_name(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t l5 = 0;
    size_t l3, l4;
    void* l6 = NULL;
    uint64_t l7;
    int64_t t0;
    vader_string_t t1 = 0;
    size_t t2;
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l5, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_type_key_join(l0, 717u);
    l2 = vader_bytecode_fnv1a_hex(l1);
    l1 = vader_bytecode_c_safe_key(l1);
    l3 = vader_host_std_core_byte_len(l1);
    t0 = (INT64_C(32) - INT64_C(1));
    l4 = (size_t) (int64_t) t0;
    if ((l3 <= l4)) {
        l5 = vader_string_slice_codepoints(l2, INT64_C(0), INT64_C(8));
        t1 = concat_3(l1, 717u, l5);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l2;
    l3 = vader_host_std_core_byte_len(l1);
    l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(21) + l3));
    l3 = (size_t) 0;
    t2 = ((vader_array_t*) l0)->length;
    t0 = ((int64_t) (size_t) t2);
    l7 = (uint64_t) (int64_t) t0;
    l3 = std_core_write_unsigned(l6, l3, l7);
    l3 = std_core_write_string_at(l6, l3, 717u);
    l3 = std_core_write_string_at(l6, l3, l1);
    t1 = std_core_finish_buffer(l6, l3);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    {
        loop_9: {
            if ((l5 < l4)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
                t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                l6 = vader_bytecode_type_intern_hash(t0);
                l2 = vader_bytecode_mix64(l2, l6);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_9;
            }
        }
    }
    t2 = ((vader_array_t*) l1)->length;
    t1 = ((int64_t) (size_t) t2);
    l6 = (uint64_t) (int64_t) t1;
    t3 = vader_bytecode_mix64(l2, l6);
    { uint64_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_bytecode_type_index_of(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (l0.tag == 622u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 621u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 623u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 472u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 470u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArrayGet_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 477u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArraySet_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 473u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 624u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_TypeCheck_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 625u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_TypeConst_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 518u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_CallIndirect_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 600u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_env_type_id;
        return t1;
    }
    if (l0.tag == 545u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 595u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 478u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArraySlice_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 603u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_RefCast_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 508u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_Box_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 521u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_type_id;
        return t1;
    }
    return -(INT32_C(1));
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
    if (l0.tag == 964u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        l1 = vader_bytecode_bare_hash(t1);
    } else if (l0.tag == 957u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
        l1 = vader_bytecode_bare_hash(t1);
    } else if (l0.tag == 954u) {
        l1 = vader_bytecode_bare_hash(368u);
    } else if ((l0.tag == 959u || l0.tag == 960u || l0.tag == 961u || l0.tag == 962u || l0.tag == 965u || l0.tag == 969u || l0.tag == 970u || l0.tag == 972u)) {
        t1 = vader_types_display_type(l0);
        l1 = vader_bytecode_bare_hash(t1);
    } else if (l0.tag == 956u) {
        t0 = l0.payload.obj;
        l1 = vader_bytecode_type_intern_hash(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 966u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 1);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_symbol_hash(((vader_struct_vader_types_StructType_t*) t0)->f_symbol);
        l2 = vader_bytecode_mix64(l2, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
        l1 = vader_bytecode_type_args_hash(l2, l4);
    } else if (l0.tag == 967u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 2);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_symbol_hash(((vader_struct_vader_types_TraitType_t*) t0)->f_symbol);
        l2 = vader_bytecode_mix64(l2, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
        l1 = vader_bytecode_type_args_hash(l2, l4);
    } else if (l0.tag == 955u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 3);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_type_intern_hash(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        l1 = vader_bytecode_mix64(l2, l3);
    } else if (l0.tag == 971u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 4);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        l1 = vader_bytecode_type_args_hash(l2, l4);
    } else if (l0.tag == 968u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 5);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
        l1 = vader_bytecode_type_args_hash(l2, l4);
    } else if (l0.tag == 958u) {
        l2 = vader_bytecode_mix64((uint64_t) -3750763034362895579, (uint64_t) 6);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
        l2 = vader_bytecode_type_args_hash(l2, l4);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_type_intern_hash(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
        l1 = vader_bytecode_mix64(l2, l3);
    } else {
        vader_unreachable("unreachable return in vader_bytecode$type_intern_hash");
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
    if (l0.tag == 964u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
    } else if (l0.tag == 966u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_symbol_key(((vader_struct_vader_types_StructType_t*) t0)->f_symbol);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_type_key_join(((vader_struct_vader_types_StructType_t*) t0)->f_args, 2375u);
        l1 = concat_5(581u, l2, 329u, l3, 349u);
    } else if (l0.tag == 967u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_symbol_key(((vader_struct_vader_types_TraitType_t*) t0)->f_symbol);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_type_key_join(((vader_struct_vader_types_TraitType_t*) t0)->f_args, 2375u);
        l1 = concat_5(663u, l2, 329u, l3, 349u);
    } else if (l0.tag == 957u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
    } else if (l0.tag == 956u) {
        t0 = l0.payload.obj;
        l1 = vader_bytecode_type_intern_key(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 955u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_type_intern_key(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        l1 = concat_3(370u, l2, 349u);
    } else if (l0.tag == 971u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_type_key_join(((vader_struct_vader_types_UnionType_t*) t0)->f_variants, 2375u);
        l1 = concat_3(670u, l2, 349u);
    } else if (l0.tag == 968u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_type_key_join(((vader_struct_vader_types_TupleType_t*) t0)->f_elements, 2375u);
        l1 = concat_3(665u, l2, 349u);
    } else if (l0.tag == 958u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_type_key_join(((vader_struct_vader_types_FnType_t*) t0)->f_params, 234u);
        t0 = l0.payload.obj;
        l3 = vader_bytecode_type_intern_key(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
        l1 = concat_4(435u, l2, 225u, l3);
    } else if (l0.tag == 970u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 969u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 965u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 972u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 961u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 959u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 960u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 962u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(vader_ref_box(t0));
    } else if (l0.tag == 954u) {
        l1 = 368u;
    } else {
        vader_unreachable("unreachable return in vader_bytecode$type_intern_key");
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
    l3 = ((vader_array_t*) l0)->length;
    l4 = (size_t) 0;
    {
        loop_8: {
            if ((l4 < l3)) {
                if ((l4 > INT64_C(0))) {
                    l5 = l1;
                } else {
                    l5 = 0u;
                }
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
                t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                l6 = vader_bytecode_type_intern_key(t0);
                l2 = concat_3(l2, l5, l6);
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_8;
            }
        }
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
    } else if (l0 == INT32_C(1)) {
        vader_struct_vader_bytecode_BoolNot_t* _a0_obj = (vader_struct_vader_bytecode_BoolNot_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolNot_t));
        vader_obj_header_init(_a0_obj, 506u);
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(2)) {
        l2 = vader_bytecode_bitnot_op(l1);
    } else {
        vader_unreachable("unreachable return in vader_bytecode$unary_op_for");
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_bytecode_val_type_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 1579u;
    } else if (l0 == INT32_C(1)) {
        l1 = 1534u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1535u;
    } else if (l0 == INT32_C(3)) {
        l1 = 1557u;
    } else if (l0 == INT32_C(4)) {
        l1 = 1654u;
    } else if (l0 == INT32_C(5)) {
        l1 = 2155u;
    } else if (l0 == INT32_C(6)) {
        l1 = 2136u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2137u;
    } else if (l0 == INT32_C(8)) {
        l1 = 2146u;
    } else if (l0 == INT32_C(9)) {
        l1 = 2198u;
    } else if (l0 == INT32_C(10)) {
        l1 = 1425u;
    } else if (l0 == INT32_C(11)) {
        l1 = 1428u;
    } else if (l0 == INT32_C(12)) {
        l1 = 1144u;
    } else if (l0 == INT32_C(13)) {
        l1 = 1254u;
    } else if (l0 == INT32_C(14)) {
        l1 = 2008u;
    } else if (l0 == INT32_C(15)) {
        l1 = 1815u;
    } else if (l0 == INT32_C(16)) {
        l1 = 2334u;
    } else if (l0 == INT32_C(17)) {
        l1 = 1856u;
    } else if (l0 == INT32_C(18)) {
        l1 = 1878u;
    } else if (l0 == INT32_C(19)) {
        l1 = 1061u;
    } else {
        vader_unreachable("unreachable return in vader_bytecode$val_type_name");
    }
    return l1;
}

static uint8_t vader_bytecode_val_type_of_primitive_name(vader_string_t l0) {
    vader_box_t l1;
    uint8_t t0;
    if (l0 == 397u) {
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
    if (l0.tag == 964u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        l1 = vader_bytecode_val_type_of_primitive_name(t1);
    } else if (l0.tag == 966u) {
        l1 = (uint8_t) 18;
    } else if (l0.tag == 957u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
        l1 = vader_bytecode_val_type_of_primitive_name(t1);
    } else if (l0.tag == 956u) {
        t0 = l0.payload.obj;
        l1 = vader_bytecode_val_type_of_type(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 955u) {
        l1 = (uint8_t) 18;
    } else if (l0.tag == 958u) {
        l1 = (uint8_t) 18;
    } else if (l0.tag == 968u) {
        l1 = (uint8_t) 18;
    } else if (l0.tag == 967u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 971u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 970u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 969u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 965u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 954u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 972u) {
        l1 = (uint8_t) 19;
    } else if (l0.tag == 961u) {
        l1 = (uint8_t) 2;
    } else if (l0.tag == 959u) {
        l1 = (uint8_t) 13;
    } else if (l0.tag == 960u) {
        l1 = (uint8_t) 11;
    } else if (l0.tag == 962u) {
        l1 = (uint8_t) 16;
    } else {
        vader_unreachable("unreachable return in vader_bytecode$val_type_of_type");
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
    if (l6.tag == 493u) {
        t2 = l6.payload.obj;
        l5 = ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_fields;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) 0;
        {
            loop_48: {
                if ((l4 < l3)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                    t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                    t3 = ((vader_struct_vader_bytecode_BcField_t*) t2)->f_type_index;
                    vader_bytecode_visit_type(t3, l1, l2);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_48;
                }
            }
        }
    }
    if (l6.tag == 494u) {
        t2 = l6.payload.obj;
        l5 = ((vader_struct_vader_bytecode_BcUnion_t*) t2)->f_variants;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) 0;
        {
            loop_82: {
                if ((l4 < l3)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                    t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    vader_bytecode_visit_type(t3, l1, l2);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_82;
                }
            }
        }
    }
    if (l6.tag == 480u) {
        t2 = l6.payload.obj;
        t3 = ((vader_struct_vader_bytecode_BcArray_t*) t2)->f_element;
        vader_bytecode_visit_type(t3, l1, l2);
    }
    if (l6.tag == 483u) {
        t2 = l6.payload.obj;
        l5 = ((vader_struct_vader_bytecode_BcFn_t*) t2)->f_params;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) 0;
        {
            loop_125: {
                if ((l4 < l3)) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
                    t3 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                    vader_bytecode_visit_type(t3, l1, l2);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_125;
                }
            }
        }
        t2 = l6.payload.obj;
        t3 = ((vader_struct_vader_bytecode_BcFn_t*) t2)->f_return_type;
        vader_bytecode_visit_type(t3, l1, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_bytecode_with_remapped_slot(vader_box_t l0, int32_t l1) {
    int32_t l2, l3;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 596u) {
        vader_struct_vader_bytecode_LocalGet_t* _a0_obj = (vader_struct_vader_bytecode_LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalGet_t));
        vader_obj_header_init(_a0_obj, 596u);
        _a0_obj->f_slot = l1;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 597u) {
        vader_struct_vader_bytecode_LocalSet_t* _a1_obj = (vader_struct_vader_bytecode_LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalSet_t));
        vader_obj_header_init(_a1_obj, 597u);
        _a1_obj->f_slot = l1;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 598u) {
        vader_struct_vader_bytecode_LocalTee_t* _a2_obj = (vader_struct_vader_bytecode_LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalTee_t));
        vader_obj_header_init(_a2_obj, 598u);
        _a2_obj->f_slot = l1;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 595u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_type_id;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_field_index;
        vader_struct_vader_bytecode_LocalField_t* _a3_obj = (vader_struct_vader_bytecode_LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalField_t));
        vader_obj_header_init(_a3_obj, 595u);
        _a3_obj->f_slot = l1;
        _a3_obj->f_type_id = l2;
        _a3_obj->f_field_index = l3;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}
