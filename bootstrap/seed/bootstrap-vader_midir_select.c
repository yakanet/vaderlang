#include "bootstrap.split.h"

static uint64_t vader_midir_select$argument_hash(vader_box_t l0);
static uint64_t vader_midir_select$argument_hashes(uint64_t l0, void* l1);
static vader_string_t vader_midir_select$argument_key(vader_box_t l0);
static vader_string_t vader_midir_select$argument_keys(void* l0);
static vader_box_t vader_midir_select$arith_op(uint8_t l0, vader_string_t l1);
static uint64_t vader_midir_select$bare_hash(vader_string_t l0);
static vader_string_t vader_midir_select$bare_intern_name(vader_box_t l0);
static vader_box_t vader_midir_select$bit_op(uint8_t l0, vader_string_t l1);
static vader_box_t vader_midir_select$bitnot_op(uint8_t l0);
static vader_string_t vader_midir_select$c_safe_key(vader_string_t l0);
static vader_box_t vader_midir_select$checked_arith_op(uint8_t l0, uint8_t l1);
static vader_box_t vader_midir_select$checked_neg_op(uint8_t l0);
static vader_box_t vader_midir_select$cmp_eq(uint8_t l0);
static vader_box_t vader_midir_select$cmp_ge(uint8_t l0);
static vader_box_t vader_midir_select$cmp_gt(uint8_t l0);
static vader_box_t vader_midir_select$cmp_le(uint8_t l0);
static vader_box_t vader_midir_select$cmp_lt(uint8_t l0);
static vader_box_t vader_midir_select$cmp_ne(uint8_t l0);
static vader_box_t vader_midir_select$div_op(uint8_t l0);
static vader_string_t vader_midir_select$fnv1a_hex(vader_string_t l0);
static bool vader_midir_select$is_ref_class(uint8_t l0);
static uint64_t vader_midir_select$mix64(uint64_t l0, uint64_t l1);
static vader_box_t vader_midir_select$mod_op(uint8_t l0);
static vader_box_t vader_midir_select$neg_op(uint8_t l0);
static vader_box_t vader_midir_select$primitive_arith_op(vader_string_t l0);
static vader_box_t vader_midir_select$primitive_cmp_op(vader_string_t l0);
static bool vader_midir_select$same_argument_class(vader_box_t l0, vader_box_t l1);
static bool vader_midir_select$same_argument_list(void* l0, void* l1);
static bool vader_midir_select$same_class_list(void* l0, void* l1);
static bool vader_midir_select$same_symbol_class(void* l0, void* l1);
static vader_box_t vader_midir_select$shl_op(uint8_t l0);
static vader_box_t vader_midir_select$shr_op(uint8_t l0);
static vader_box_t vader_midir_select$slot_width_for(uint8_t l0);
static vader_box_t vader_midir_select$spelled_shape(vader_string_t l0);
static uint64_t vader_midir_select$symbol_hash(void* l0);
static vader_string_t vader_midir_select$symbol_key(void* l0);
static uint64_t vader_midir_select$type_args_hash(uint64_t l0, void* l1);
static vader_string_t vader_midir_select$type_key_join(void* l0, vader_string_t l1);

static uint64_t vader_midir_select$argument_hash(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    uint64_t l2, l3;
    uint64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_core_types$strip_distinct(l0);
    if (!(l1.tag == 906u)) {
        t0 = vader_midir_select$type_intern_hash(l0);
        { uint64_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_midir_select$mix64((uint64_t) -3750763034362895579, (uint64_t) 7);
    t1 = l1.payload.obj;
    l3 = vader_midir_select$symbol_hash(((vader_struct_vader_core_types$EnumType_t*) t1)->f_symbol);
    t0 = vader_midir_select$mix64(l2, l3);
    { uint64_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint64_t vader_midir_select$argument_hashes(uint64_t l0, void* l1) {
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
        l6 = vader_midir_select$argument_hash(t0);
        l2 = vader_midir_select$mix64(l2, l6);
        l5 = (l5 + INT64_C(1));
    }
    t1 = ((vader_array_t*) l1)->length;
    t2 = t1;
    l6 = (uint64_t) (int64_t) t2;
    t3 = vader_midir_select$mix64(l2, l6);
    { uint64_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_midir_select$argument_key(vader_box_t l0) {
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
    l1 = vader_core_types$strip_distinct(l0);
    if (!(l1.tag == 906u)) {
        t0 = vader_midir_select$type_intern_key(l0);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l1.payload.obj;
    l2 = vader_midir_select$symbol_key(((vader_struct_vader_core_types$EnumType_t*) t1)->f_symbol);
    t0 = concat_2(636u, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_midir_select$argument_keys(void* l0) {
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
        l6 = vader_midir_select$argument_key(t0);
        l1 = concat_3(l1, l2, l6);
        l2 = 3057u;
        l5 = (l5 + INT64_C(1));
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_select$arith_op(uint8_t l0, vader_string_t l1) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$is_float_val(l0);
    if (t0) {
        if (l1 == 1506u) {
            vader_struct_vader_core_bytecode$F64Add_t* _a0_obj = (vader_struct_vader_core_bytecode$F64Add_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$F64Add_t));
            vader_obj_header_init(_a0_obj, 783u);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 2673u) {
            vader_struct_vader_core_bytecode$F64Sub_t* _a1_obj = (vader_struct_vader_core_bytecode$F64Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$F64Sub_t));
            vader_obj_header_init(_a1_obj, 794u);
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l1 == 2356u)) {
            vader_struct_vader_core_bytecode$F64Div_t* _a2_obj = (vader_struct_vader_core_bytecode$F64Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$F64Div_t));
            vader_obj_header_init(_a2_obj, 785u);
            t1 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_core_bytecode$F64Mul_t* _a3_obj = (vader_struct_vader_core_bytecode$F64Mul_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$F64Mul_t));
        vader_obj_header_init(_a3_obj, 791u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (t0) {
        if (l1 == 1506u) {
            vader_struct_vader_core_bytecode$I64Add_t* _a4_obj = (vader_struct_vader_core_bytecode$I64Add_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Add_t));
            vader_obj_header_init(_a4_obj, 820u);
            t1 = (void*) _a4_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 2673u) {
            vader_struct_vader_core_bytecode$I64Sub_t* _a5_obj = (vader_struct_vader_core_bytecode$I64Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Sub_t));
            vader_obj_header_init(_a5_obj, 839u);
            t1 = (void*) _a5_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l1 == 2356u)) {
            vader_struct_vader_core_bytecode$I64Div_t* _a6_obj = (vader_struct_vader_core_bytecode$I64Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Div_t));
            vader_obj_header_init(_a6_obj, 826u);
            t1 = (void*) _a6_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_core_bytecode$I64Mul_t* _a7_obj = (vader_struct_vader_core_bytecode$I64Mul_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Mul_t));
        vader_obj_header_init(_a7_obj, 833u);
        t1 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 1506u) {
        vader_struct_vader_core_bytecode$I32Add_t* _a8_obj = (vader_struct_vader_core_bytecode$I32Add_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Add_t));
        vader_obj_header_init(_a8_obj, 800u);
        t1 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 2673u) {
        vader_struct_vader_core_bytecode$I32Sub_t* _a9_obj = (vader_struct_vader_core_bytecode$I32Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Sub_t));
        vader_obj_header_init(_a9_obj, 819u);
        t1 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1 == 2356u)) {
        vader_struct_vader_core_bytecode$I32Div_t* _a10_obj = (vader_struct_vader_core_bytecode$I32Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Div_t));
        vader_obj_header_init(_a10_obj, 806u);
        t1 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_bytecode$I32Mul_t* _a11_obj = (vader_struct_vader_core_bytecode$I32Mul_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Mul_t));
    vader_obj_header_init(_a11_obj, 813u);
    t1 = (void*) _a11_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_midir_select$assert_host_import_wired(vader_string_t l0, bool l1) {
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
    t0 = vader_midir_select$intrinsic_op_for_mangled(l0);
    if (!(t0.tag == 0u)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = vader_core_bytecode$intrinsic_id_for(l0);
    if (!(t1 != INT32_C(0))) {
        t2 = concat_3(1676u, l0, 1177u);
        vader_host_std_abort$panic(t2);
        vader_unreachable("a no-return call returned");
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static uint64_t vader_midir_select$bare_hash(vader_string_t l0) {
    uint64_t l1;
    uint64_t t0;
    l1 = std_core$string$Hash$hash_vt(l0);
    t0 = vader_midir_select$mix64((uint64_t) -3750763034362895579, l1);
    return t0;
}

static vader_string_t vader_midir_select$bare_intern_name(vader_box_t l0) {
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
    if (l0.tag == 915u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 906u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_support_integer$MachineInteger_t*) ((vader_struct_vader_core_types$EnumType_t*) t0)->f_repr)->f_name;
    } else if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$storage_integer(t0);
        l1 = ((vader_struct_vader_support_integer$MachineInteger_t*) t1)->f_name;
    } else if (l0.tag == 903u) {
        l1 = 579u;
    } else if ((l0.tag == 908u || l0.tag == 909u || l0.tag == 910u || l0.tag == 913u || l0.tag == 917u || l0.tag == 922u || l0.tag == 923u || l0.tag == 927u)) {
        l1 = vader_core_types$display_type(l0);
    } else if (l0.tag == 911u) {
        t0 = l0.payload.obj;
        vader_core_types$leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else {
        if (!((l0.tag == 904u || l0.tag == 905u || l0.tag == 907u || l0.tag == 918u || l0.tag == 920u || l0.tag == 921u || l0.tag == 926u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 0u;
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_midir_select$binary_op_for(uint8_t l0, uint8_t l1) {
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        l2 = vader_midir_select$arith_op(l1, 1506u);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        l2 = vader_midir_select$arith_op(l1, 2673u);
    } else if (l0 == INT32_C(2)) {
        l2 = vader_midir_select$arith_op(l1, 2356u);
    } else if (l0 == INT32_C(18)) {
        l2 = vader_midir_select$checked_arith_op(l1, (uint8_t) 0);
    } else if (l0 == INT32_C(19)) {
        l2 = vader_midir_select$checked_arith_op(l1, (uint8_t) 1);
    } else if (l0 == INT32_C(20)) {
        l2 = vader_midir_select$checked_arith_op(l1, (uint8_t) 2);
    } else if (l0 == INT32_C(3)) {
        l2 = vader_midir_select$div_op(l1);
    } else if (l0 == INT32_C(4)) {
        l2 = vader_midir_select$mod_op(l1);
    } else if (l0 == INT32_C(5)) {
        l2 = vader_midir_select$shl_op(l1);
    } else if (l0 == INT32_C(6)) {
        l2 = vader_midir_select$shr_op(l1);
    } else if (l0 == INT32_C(7)) {
        l2 = vader_midir_select$bit_op(l1, 1539u);
    } else if (l0 == INT32_C(8)) {
        l2 = vader_midir_select$bit_op(l1, 2435u);
    } else if (l0 == INT32_C(9)) {
        l2 = vader_midir_select$bit_op(l1, 3044u);
    } else if (l0 == INT32_C(10)) {
        vader_struct_vader_core_bytecode$BoolAnd_t* _a0_obj = (vader_struct_vader_core_bytecode$BoolAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BoolAnd_t));
        vader_obj_header_init(_a0_obj, 755u);
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(11)) {
        vader_struct_vader_core_bytecode$BoolOr_t* _a1_obj = (vader_struct_vader_core_bytecode$BoolOr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BoolOr_t));
        vader_obj_header_init(_a1_obj, 760u);
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(12)) {
        l2 = vader_midir_select$cmp_eq(l1);
    } else if (l0 == INT32_C(13)) {
        l2 = vader_midir_select$cmp_ne(l1);
    } else if (l0 == INT32_C(14)) {
        l2 = vader_midir_select$cmp_lt(l1);
    } else if (l0 == INT32_C(15)) {
        l2 = vader_midir_select$cmp_le(l1);
    } else if (l0 == INT32_C(16)) {
        l2 = vader_midir_select$cmp_gt(l1);
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_midir_select$cmp_ge(l1);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_select$bit_op(uint8_t l0, vader_string_t l1) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (t0) {
        if (l1 == 1539u) {
            vader_struct_vader_core_bytecode$I64BitAnd_t* _a0_obj = (vader_struct_vader_core_bytecode$I64BitAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64BitAnd_t));
            vader_obj_header_init(_a0_obj, 821u);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (!(l1 == 2435u)) {
            vader_struct_vader_core_bytecode$I64BitXor_t* _a1_obj = (vader_struct_vader_core_bytecode$I64BitXor_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64BitXor_t));
            vader_obj_header_init(_a1_obj, 824u);
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_core_bytecode$I64BitOr_t* _a2_obj = (vader_struct_vader_core_bytecode$I64BitOr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64BitOr_t));
        vader_obj_header_init(_a2_obj, 823u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 1539u) {
        vader_struct_vader_core_bytecode$I32BitAnd_t* _a3_obj = (vader_struct_vader_core_bytecode$I32BitAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32BitAnd_t));
        vader_obj_header_init(_a3_obj, 801u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1 == 2435u)) {
        vader_struct_vader_core_bytecode$I32BitXor_t* _a4_obj = (vader_struct_vader_core_bytecode$I32BitXor_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32BitXor_t));
        vader_obj_header_init(_a4_obj, 804u);
        t1 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_bytecode$I32BitOr_t* _a5_obj = (vader_struct_vader_core_bytecode$I32BitOr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32BitOr_t));
    vader_obj_header_init(_a5_obj, 803u);
    t1 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_select$bitnot_op(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_core_bytecode$I32BitNot_t* _a0_obj = (vader_struct_vader_core_bytecode$I32BitNot_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32BitNot_t));
        vader_obj_header_init(_a0_obj, 802u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_bytecode$I64BitNot_t* _a1_obj = (vader_struct_vader_core_bytecode$I64BitNot_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64BitNot_t));
    vader_obj_header_init(_a1_obj, 822u);
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_midir_select$c_safe_key(vader_string_t l0) {
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
    l4 = vader_host_std_core$byte_len(l0);
    while ((l3 < l4)) {
        l5 = vader_host_std_core$byte_at(l0, l3);
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
            l11 = std_core$char$Display$to_string(((uint32_t) (uint8_t) l5));
            l1 = concat_2(l1, l11);
            l2 = false;
        } else if (!(l2)) {
            l1 = concat_2(l1, 976u);
            l2 = true;
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_midir_select$cell_shape_name(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_select$spelled_shape(l0);
    if (l1.tag == 0u) {
        t0 = vader_midir_select$fnv1a_hex(l0);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.s;
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_select$checked_arith_op(uint8_t l0, uint8_t l1) {
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
    t0 = vader_core_bytecode$is_integer_val(l0);
    if (!(t0)) {
        l2 = vader_core_bytecode$checked_op_name(l1);
        t1 = vader_midir_select$arith_op(l0, l2);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_bytecode$CheckedArith_t* _a0_obj = (vader_struct_vader_core_bytecode$CheckedArith_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$CheckedArith_t));
    vader_obj_header_init(_a0_obj, 772u);
    _a0_obj->f_kind = l0;
    _a0_obj->f_op = l1;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_select$checked_neg_op(uint8_t l0) {
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$is_integer_val(l0);
    if (!(t0)) {
        t1 = vader_midir_select$neg_op(l0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_bytecode$CheckedNeg_t* _a0_obj = (vader_struct_vader_core_bytecode$CheckedNeg_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$CheckedNeg_t));
    vader_obj_header_init(_a0_obj, 773u);
    _a0_obj->f_kind = l0;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_select$cmp_eq(uint8_t l0) {
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(10)) {
        vader_struct_vader_core_bytecode$BoolEq_t* _a0_obj = (vader_struct_vader_core_bytecode$BoolEq_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BoolEq_t));
        vader_obj_header_init(_a0_obj, 757u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(12)) {
        vader_struct_vader_core_bytecode$StringEq_t* _a1_obj = (vader_struct_vader_core_bytecode$StringEq_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StringEq_t));
        vader_obj_header_init(_a1_obj, 873u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_core_bytecode$is_float_val(l0);
    if (t1) {
        vader_struct_vader_core_bytecode$F64Eq_t* _a2_obj = (vader_struct_vader_core_bytecode$F64Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$F64Eq_t));
        vader_obj_header_init(_a2_obj, 786u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (t1) {
        vader_struct_vader_core_bytecode$I64Eq_t* _a3_obj = (vader_struct_vader_core_bytecode$I64Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Eq_t));
        vader_obj_header_init(_a3_obj, 827u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_midir_select$is_ref_class(l0);
    if (!(t1)) {
        vader_struct_vader_core_bytecode$I32Eq_t* _a4_obj = (vader_struct_vader_core_bytecode$I32Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Eq_t));
        vader_obj_header_init(_a4_obj, 807u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_bytecode$RefEq_t* _a5_obj = (vader_struct_vader_core_bytecode$RefEq_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$RefEq_t));
    vader_obj_header_init(_a5_obj, 858u);
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_select$cmp_ge(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$is_float_val(l0);
    if (t0) {
        vader_struct_vader_core_bytecode$F64Ge_t* _a0_obj = (vader_struct_vader_core_bytecode$F64Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$F64Ge_t));
        vader_obj_header_init(_a0_obj, 787u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$is_u64_class(l0);
    if (t0) {
        vader_struct_vader_core_bytecode$U64Ge_t* _a1_obj = (vader_struct_vader_core_bytecode$U64Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$U64Ge_t));
        vader_obj_header_init(_a1_obj, 887u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$is_u32_class(l0);
    if (t0) {
        vader_struct_vader_core_bytecode$U32Ge_t* _a2_obj = (vader_struct_vader_core_bytecode$U32Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$U32Ge_t));
        vader_obj_header_init(_a2_obj, 881u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_core_bytecode$I32Ge_t* _a3_obj = (vader_struct_vader_core_bytecode$I32Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Ge_t));
        vader_obj_header_init(_a3_obj, 808u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_bytecode$I64Ge_t* _a4_obj = (vader_struct_vader_core_bytecode$I64Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Ge_t));
    vader_obj_header_init(_a4_obj, 828u);
    t1 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_select$cmp_gt(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$is_float_val(l0);
    if (t0) {
        vader_struct_vader_core_bytecode$F64Gt_t* _a0_obj = (vader_struct_vader_core_bytecode$F64Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$F64Gt_t));
        vader_obj_header_init(_a0_obj, 788u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$is_u64_class(l0);
    if (t0) {
        vader_struct_vader_core_bytecode$U64Gt_t* _a1_obj = (vader_struct_vader_core_bytecode$U64Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$U64Gt_t));
        vader_obj_header_init(_a1_obj, 888u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$is_u32_class(l0);
    if (t0) {
        vader_struct_vader_core_bytecode$U32Gt_t* _a2_obj = (vader_struct_vader_core_bytecode$U32Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$U32Gt_t));
        vader_obj_header_init(_a2_obj, 882u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_core_bytecode$I32Gt_t* _a3_obj = (vader_struct_vader_core_bytecode$I32Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Gt_t));
        vader_obj_header_init(_a3_obj, 809u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_bytecode$I64Gt_t* _a4_obj = (vader_struct_vader_core_bytecode$I64Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Gt_t));
    vader_obj_header_init(_a4_obj, 829u);
    t1 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_select$cmp_le(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$is_float_val(l0);
    if (t0) {
        vader_struct_vader_core_bytecode$F64Le_t* _a0_obj = (vader_struct_vader_core_bytecode$F64Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$F64Le_t));
        vader_obj_header_init(_a0_obj, 789u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$is_u64_class(l0);
    if (t0) {
        vader_struct_vader_core_bytecode$U64Le_t* _a1_obj = (vader_struct_vader_core_bytecode$U64Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$U64Le_t));
        vader_obj_header_init(_a1_obj, 889u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$is_u32_class(l0);
    if (t0) {
        vader_struct_vader_core_bytecode$U32Le_t* _a2_obj = (vader_struct_vader_core_bytecode$U32Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$U32Le_t));
        vader_obj_header_init(_a2_obj, 883u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_core_bytecode$I32Le_t* _a3_obj = (vader_struct_vader_core_bytecode$I32Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Le_t));
        vader_obj_header_init(_a3_obj, 810u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_bytecode$I64Le_t* _a4_obj = (vader_struct_vader_core_bytecode$I64Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Le_t));
    vader_obj_header_init(_a4_obj, 830u);
    t1 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_select$cmp_lt(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$is_float_val(l0);
    if (t0) {
        vader_struct_vader_core_bytecode$F64Lt_t* _a0_obj = (vader_struct_vader_core_bytecode$F64Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$F64Lt_t));
        vader_obj_header_init(_a0_obj, 790u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$is_u64_class(l0);
    if (t0) {
        vader_struct_vader_core_bytecode$U64Lt_t* _a1_obj = (vader_struct_vader_core_bytecode$U64Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$U64Lt_t));
        vader_obj_header_init(_a1_obj, 890u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$is_u32_class(l0);
    if (t0) {
        vader_struct_vader_core_bytecode$U32Lt_t* _a2_obj = (vader_struct_vader_core_bytecode$U32Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$U32Lt_t));
        vader_obj_header_init(_a2_obj, 884u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_core_bytecode$I32Lt_t* _a3_obj = (vader_struct_vader_core_bytecode$I32Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Lt_t));
        vader_obj_header_init(_a3_obj, 811u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_bytecode$I64Lt_t* _a4_obj = (vader_struct_vader_core_bytecode$I64Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Lt_t));
    vader_obj_header_init(_a4_obj, 831u);
    t1 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_select$cmp_ne(uint8_t l0) {
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(10)) {
        vader_struct_vader_core_bytecode$BoolNe_t* _a0_obj = (vader_struct_vader_core_bytecode$BoolNe_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BoolNe_t));
        vader_obj_header_init(_a0_obj, 758u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(12)) {
        vader_struct_vader_core_bytecode$StringNe_t* _a1_obj = (vader_struct_vader_core_bytecode$StringNe_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StringNe_t));
        vader_obj_header_init(_a1_obj, 874u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_core_bytecode$is_float_val(l0);
    if (t1) {
        vader_struct_vader_core_bytecode$F64Ne_t* _a2_obj = (vader_struct_vader_core_bytecode$F64Ne_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$F64Ne_t));
        vader_obj_header_init(_a2_obj, 792u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (t1) {
        vader_struct_vader_core_bytecode$I64Ne_t* _a3_obj = (vader_struct_vader_core_bytecode$I64Ne_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Ne_t));
        vader_obj_header_init(_a3_obj, 834u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_midir_select$is_ref_class(l0);
    if (!(t1)) {
        vader_struct_vader_core_bytecode$I32Ne_t* _a4_obj = (vader_struct_vader_core_bytecode$I32Ne_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Ne_t));
        vader_obj_header_init(_a4_obj, 814u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_bytecode$RefNe_t* _a5_obj = (vader_struct_vader_core_bytecode$RefNe_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$RefNe_t));
    vader_obj_header_init(_a5_obj, 859u);
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_select$div_op(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$is_u64_class(l0);
    if (t0) {
        vader_struct_vader_core_bytecode$U64Div_t* _a0_obj = (vader_struct_vader_core_bytecode$U64Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$U64Div_t));
        vader_obj_header_init(_a0_obj, 886u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$is_u32_class(l0);
    if (!(t0)) {
        t2 = vader_midir_select$arith_op(l0, 1837u);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_bytecode$U32Div_t* _a1_obj = (vader_struct_vader_core_bytecode$U32Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$U32Div_t));
    vader_obj_header_init(_a1_obj, 880u);
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_midir_select$fnv1a_hex(vader_string_t l0) {
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
    l3 = vader_host_std_core$byte_len(l0);
    while ((l2 < l3)) {
        t0 = vader_host_std_core$byte_at(l0, l2);
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
        vader_struct_std_core$Range__i64_t* _a0_obj = (vader_struct_std_core$Range__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_core$Range__i64_t));
        vader_obj_header_init(_a0_obj, 621u);
        _a0_obj->f_start = l2;
        _a0_obj->f_end = l3;
        _a0_obj->f_inclusive = false;
        _a0_obj->f_done = false;
        _a0_obj->f_cursor = l2;
        l8 = (void*) _a0_obj;
        l9 = std_core$string$Index$at$1(456u, l8);
        l5 = concat_2(l5, l9);
        l6 = (l6 + INT32_C(1));
    }
    { vader_string_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_midir_select$intrinsic_op_for_mangled(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_select$primitive_arith_op(l0);
    if (!(l1.tag == 0u)) {
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_midir_select$primitive_cmp_op(l0);
    if (!(l1.tag == 0u)) {
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2609u) {
        vader_struct_vader_core_bytecode$StringCompare_t* _a0_obj = (vader_struct_vader_core_bytecode$StringCompare_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StringCompare_t));
        vader_obj_header_init(_a0_obj, 871u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2608u) {
        vader_struct_vader_core_bytecode$BufferNew_t* _a1_obj = (vader_struct_vader_core_bytecode$BufferNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BufferNew_t));
        vader_obj_header_init(_a1_obj, 763u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2596u) {
        vader_struct_vader_core_bytecode$LoadU8_t* _a2_obj = (vader_struct_vader_core_bytecode$LoadU8_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LoadU8_t));
        vader_obj_header_init(_a2_obj, 848u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2598u) {
        vader_struct_vader_core_bytecode$StoreU8_t* _a3_obj = (vader_struct_vader_core_bytecode$StoreU8_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StoreU8_t));
        vader_obj_header_init(_a3_obj, 870u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2597u) {
        vader_struct_vader_core_bytecode$MemoryCopy_t* _a4_obj = (vader_struct_vader_core_bytecode$MemoryCopy_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$MemoryCopy_t));
        vader_obj_header_init(_a4_obj, 855u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2595u) {
        vader_struct_vader_core_bytecode$BufferToString_t* _a5_obj = (vader_struct_vader_core_bytecode$BufferToString_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BufferToString_t));
        vader_obj_header_init(_a5_obj, 764u);
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2599u) {
        vader_struct_vader_core_bytecode$BufferWriteString_t* _a6_obj = (vader_struct_vader_core_bytecode$BufferWriteString_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BufferWriteString_t));
        vader_obj_header_init(_a6_obj, 765u);
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2606u) {
        vader_struct_vader_core_bytecode$F64ToBits_t* _a7_obj = (vader_struct_vader_core_bytecode$F64ToBits_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$F64ToBits_t));
        vader_obj_header_init(_a7_obj, 795u);
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2612u) {
        vader_struct_vader_core_bytecode$BitsToF64_t* _a8_obj = (vader_struct_vader_core_bytecode$BitsToF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BitsToF64_t));
        vader_obj_header_init(_a8_obj, 753u);
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2605u) {
        vader_struct_vader_core_bytecode$F32ToBits_t* _a9_obj = (vader_struct_vader_core_bytecode$F32ToBits_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$F32ToBits_t));
        vader_obj_header_init(_a9_obj, 782u);
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0 == 2611u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_struct_vader_core_bytecode$BitsToF32_t* _a10_obj = (vader_struct_vader_core_bytecode$BitsToF32_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BitsToF32_t));
    vader_obj_header_init(_a10_obj, 752u);
    t0 = (void*) _a10_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_midir_select$intrinsic_op_for_name(vader_string_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0 == 2558u) {
        vader_struct_vader_core_bytecode$SizeOfType_t* _a0_obj = (vader_struct_vader_core_bytecode$SizeOfType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$SizeOfType_t));
        vader_obj_header_init(_a0_obj, 863u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1580u) {
        vader_struct_vader_core_bytecode$ArrayRepeat_t* _a1_obj = (vader_struct_vader_core_bytecode$ArrayRepeat_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayRepeat_t));
        vader_obj_header_init(_a1_obj, 729u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1575u) {
        vader_struct_vader_core_bytecode$ArrayPushAll_t* _a2_obj = (vader_struct_vader_core_bytecode$ArrayPushAll_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayPushAll_t));
        vader_obj_header_init(_a2_obj, 727u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1562u) {
        vader_struct_vader_core_bytecode$ArrayCopy_t* _a3_obj = (vader_struct_vader_core_bytecode$ArrayCopy_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayCopy_t));
        vader_obj_header_init(_a3_obj, 722u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1578u) {
        vader_struct_vader_core_bytecode$ArrayRemoveLast_t* _a4_obj = (vader_struct_vader_core_bytecode$ArrayRemoveLast_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayRemoveLast_t));
        vader_obj_header_init(_a4_obj, 728u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0 == 1560u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_struct_vader_core_bytecode$ArrayClear_t* _a5_obj = (vader_struct_vader_core_bytecode$ArrayClear_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$ArrayClear_t));
    vader_obj_header_init(_a5_obj, 721u);
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_midir_select$is_boxed_slot(vader_box_t l0) {
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_midir_select$val_type_of_type(l0);
    { bool __vret = t0 == INT32_C(17); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir_select$is_ref_class(uint8_t l0) {
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

bool vader_midir_select$is_scalar_class(uint8_t l0) {
    bool t0;
    t0 = vader_midir_select$is_ref_class(l0);
    if (!(t0)) {
        return l0 != INT32_C(14);
    }
    return false;
}

static uint64_t vader_midir_select$mix64(uint64_t l0, uint64_t l1) {
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

static vader_box_t vader_midir_select$mod_op(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$is_u64_class(l0);
    if (t0) {
        vader_struct_vader_core_bytecode$U64Mod_t* _a0_obj = (vader_struct_vader_core_bytecode$U64Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$U64Mod_t));
        vader_obj_header_init(_a0_obj, 891u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$is_u32_class(l0);
    if (t0) {
        vader_struct_vader_core_bytecode$U32Mod_t* _a1_obj = (vader_struct_vader_core_bytecode$U32Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$U32Mod_t));
        vader_obj_header_init(_a1_obj, 885u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_core_bytecode$I32Mod_t* _a2_obj = (vader_struct_vader_core_bytecode$I32Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Mod_t));
        vader_obj_header_init(_a2_obj, 812u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_bytecode$I64Mod_t* _a3_obj = (vader_struct_vader_core_bytecode$I64Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Mod_t));
    vader_obj_header_init(_a3_obj, 832u);
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_select$neg_op(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$is_float_val(l0);
    if (t0) {
        vader_struct_vader_core_bytecode$F64Neg_t* _a0_obj = (vader_struct_vader_core_bytecode$F64Neg_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$F64Neg_t));
        vader_obj_header_init(_a0_obj, 793u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_core_bytecode$I32Neg_t* _a1_obj = (vader_struct_vader_core_bytecode$I32Neg_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Neg_t));
        vader_obj_header_init(_a1_obj, 815u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_bytecode$I64Neg_t* _a2_obj = (vader_struct_vader_core_bytecode$I64Neg_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Neg_t));
    vader_obj_header_init(_a2_obj, 835u);
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_select$primitive_arith_op(vader_string_t l0) {
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
    l1 = vader_core_bytecode$strip_core_member(l0, 260u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        t1 = vader_core_types$is_numeric_name(t0);
        if (t1) {
            t0 = l1.payload.s;
            t2 = vader_midir_select$val_type_of_primitive_name(t0);
            t3 = vader_midir_select$checked_arith_op(t2, (uint8_t) 0);
            { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l1 = vader_core_bytecode$strip_core_member(l0, 267u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        t1 = vader_core_types$is_numeric_name(t0);
        if (t1) {
            t0 = l1.payload.s;
            t2 = vader_midir_select$val_type_of_primitive_name(t0);
            t3 = vader_midir_select$checked_arith_op(t2, (uint8_t) 1);
            { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l1 = vader_core_bytecode$strip_core_member(l0, 266u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        t1 = vader_core_types$is_numeric_name(t0);
        if (t1) {
            t0 = l1.payload.s;
            t2 = vader_midir_select$val_type_of_primitive_name(t0);
            t3 = vader_midir_select$checked_arith_op(t2, (uint8_t) 2);
            { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l1 = vader_core_bytecode$strip_core_member(l0, 264u);
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l1.payload.s;
    t1 = vader_core_types$is_numeric_name(t0);
    if (t1) {
        t0 = l1.payload.s;
        t2 = vader_midir_select$val_type_of_primitive_name(t0);
        t3 = vader_midir_select$div_op(t2);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_midir_select$primitive_cmp_op(vader_string_t l0) {
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
    l1 = vader_core_bytecode$strip_core_member(l0, 265u);
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l1.payload.s;
    t1 = vader_core_types$is_scalar_type_name(t0);
    if (t1) {
        t0 = l1.payload.s;
        t2 = vader_midir_select$val_type_of_primitive_name(t0);
        t3 = vader_midir_select$cmp_eq(t2);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static bool vader_midir_select$same_argument_class(vader_box_t l0, vader_box_t l1) {
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
    l2 = vader_core_types$strip_distinct(l0);
    l3 = vader_core_types$strip_distinct(l1);
    if (l2.tag == 906u) {
        l4 = true;
    } else {
        l4 = l3.tag == 906u;
    }
    if (!(l4)) {
        t0 = vader_midir_select$same_intern_class(l0, l1);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 906u) {
        l4 = l3.tag == 906u;
    } else {
        l4 = false;
    }
    if (l4) {
        t1 = l2.payload.obj;
        l5 = ((vader_struct_vader_core_types$EnumType_t*) t1)->f_symbol;
        t1 = l3.payload.obj;
        l6 = ((vader_struct_vader_core_types$EnumType_t*) t1)->f_symbol;
        t0 = vader_midir_select$same_symbol_class(l5, l6);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_midir_select$same_argument_list(void* l0, void* l1) {
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
        t0 = vader_midir_select$same_argument_class(l4, l5);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l2 = (l2 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return true; }
}

static bool vader_midir_select$same_class_list(void* l0, void* l1) {
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
        t0 = vader_midir_select$same_intern_class(l4, l5);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l2 = (l2 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return true; }
}

bool vader_midir_select$same_intern_class(vader_box_t l0, vader_box_t l1) {
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
    if (l0.tag == 905u) {
        t0 = l0.payload.obj;
        t1 = vader_midir_select$same_intern_class(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 905u) {
        l2 = l0;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing;
        t1 = vader_midir_select$same_intern_class(l2, l3);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 916u) {
        if (l1.tag == 916u) {
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_core_types$RangeType_t*) t0)->f_bounds;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_core_types$RangeType_t*) t0)->f_bounds;
            t1 = vader_support_integer$same_interval(l4, l5);
            if (t1) {
                { vader_gc_top = gc_frame.prev; return true; }
            }
        }
    }
    if ((l0.tag == 906u || l0.tag == 915u || l0.tag == 916u)) {
        l6 = true;
    } else {
        l6 = (l1.tag == 906u || l1.tag == 915u || l1.tag == 916u);
    }
    if (l6) {
        l7 = vader_midir_select$bare_intern_name(l0);
        if (l7 != 0u) {
            l8 = vader_midir_select$bare_intern_name(l1);
            { bool __vret = l7 == l8; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 918u) {
        if (l1.tag == 918u) {
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol;
            l6 = vader_midir_select$same_symbol_class(l4, l5);
        } else {
            l6 = false;
        }
        if (l6) {
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_args;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_args;
            t1 = vader_midir_select$same_argument_list(l4, l5);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 920u) {
        if (l1.tag == 920u) {
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_core_types$TraitType_t*) t0)->f_symbol;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_core_types$TraitType_t*) t0)->f_symbol;
            l6 = vader_midir_select$same_symbol_class(l4, l5);
        } else {
            l6 = false;
        }
        if (l6) {
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_core_types$TraitType_t*) t0)->f_args;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_core_types$TraitType_t*) t0)->f_args;
            t1 = vader_midir_select$same_argument_list(l4, l5);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 904u) {
        if (l1.tag == 904u) {
            t0 = l0.payload.obj;
            l2 = ((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element;
            t1 = vader_midir_select$same_intern_class(l2, l3);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 926u) {
        if (l1.tag == 926u) {
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
            t1 = vader_midir_select$same_class_list(l4, l5);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 921u) {
        if (l1.tag == 921u) {
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements;
            t1 = vader_midir_select$same_class_list(l4, l5);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (!(l0.tag == 907u)) {
        l7 = vader_midir_select$bare_intern_name(l0);
        l8 = vader_midir_select$bare_intern_name(l1);
        { bool __vret = l7 == l8; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 907u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_params;
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_params;
        l6 = vader_midir_select$same_class_list(l4, l5);
    } else {
        l6 = false;
    }
    if (l6) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type;
        t1 = vader_midir_select$same_intern_class(l2, l3);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_midir_select$same_symbol_class(void* l0, void* l1) {
    bool l2;
    vader_string_t l3, l4;
    int32_t l5, l6;
    vader_string_t t0;
    t0 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_module_name;
    if (t0 == 0u) {
        l2 = true;
    } else {
        t0 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_module_name;
        l2 = t0 == 0u;
    }
    if (l2) {
        l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_module_name;
        l4 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_module_name;
        if (l3 == l4) {
            l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
            l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
            return l5 == l6;
        }
        return false;
    }
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_module_name;
    l4 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_module_name;
    if (l3 == l4) {
        l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
        l4 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_name;
        return l3 == l4;
    }
    return false;
}

static vader_box_t vader_midir_select$shl_op(uint8_t l0) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        vader_struct_vader_core_bytecode$I32Shl_t* _a0_obj = (vader_struct_vader_core_bytecode$I32Shl_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Shl_t));
        vader_obj_header_init(_a0_obj, 816u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_bytecode$I64Shl_t* _a1_obj = (vader_struct_vader_core_bytecode$I64Shl_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Shl_t));
    vader_obj_header_init(_a1_obj, 836u);
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_select$shr_op(uint8_t l0) {
    bool l1;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_core_bytecode$is_unsigned_val(l0);
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (t0) {
        if (!(l1)) {
            vader_struct_vader_core_bytecode$I64Shr_t* _a0_obj = (vader_struct_vader_core_bytecode$I64Shr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64Shr_t));
            vader_obj_header_init(_a0_obj, 837u);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_core_bytecode$I64ShrU_t* _a1_obj = (vader_struct_vader_core_bytecode$I64ShrU_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I64ShrU_t));
        vader_obj_header_init(_a1_obj, 838u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1)) {
        vader_struct_vader_core_bytecode$I32Shr_t* _a2_obj = (vader_struct_vader_core_bytecode$I32Shr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32Shr_t));
        vader_obj_header_init(_a2_obj, 817u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_bytecode$I32ShrU_t* _a3_obj = (vader_struct_vader_core_bytecode$I32ShrU_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$I32ShrU_t));
    vader_obj_header_init(_a3_obj, 818u);
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_midir_select$slot_load_op_for(uint8_t l0, bool l1) {
    uint8_t l2;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_midir_select$slot_width_for(l0);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((uint8_t) l3.payload.i);
    if (l2 == INT32_C(1)) {
        vader_struct_vader_core_bytecode$LoadSlotI32_t* _a0_obj = (vader_struct_vader_core_bytecode$LoadSlotI32_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LoadSlotI32_t));
        vader_obj_header_init(_a0_obj, 846u);
        _a0_obj->f_bounds_safe = l1;
        t0 = (void*) _a0_obj;
        l3 = vader_ref_box(t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(2)) {
        vader_struct_vader_core_bytecode$LoadSlotI64_t* _a1_obj = (vader_struct_vader_core_bytecode$LoadSlotI64_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LoadSlotI64_t));
        vader_obj_header_init(_a1_obj, 847u);
        _a1_obj->f_bounds_safe = l1;
        t0 = (void*) _a1_obj;
        l3 = vader_ref_box(t0);
    } else if (l2 == INT32_C(3)) {
        vader_struct_vader_core_bytecode$LoadSlotF64_t* _a2_obj = (vader_struct_vader_core_bytecode$LoadSlotF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LoadSlotF64_t));
        vader_obj_header_init(_a2_obj, 845u);
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

vader_box_t vader_midir_select$slot_store_op_for(uint8_t l0, bool l1) {
    uint8_t l2;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_midir_select$slot_width_for(l0);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((uint8_t) l3.payload.i);
    if (l2 == INT32_C(1)) {
        vader_struct_vader_core_bytecode$StoreSlotI32_t* _a0_obj = (vader_struct_vader_core_bytecode$StoreSlotI32_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StoreSlotI32_t));
        vader_obj_header_init(_a0_obj, 868u);
        _a0_obj->f_bounds_safe = l1;
        t0 = (void*) _a0_obj;
        l3 = vader_ref_box(t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(2)) {
        vader_struct_vader_core_bytecode$StoreSlotI64_t* _a1_obj = (vader_struct_vader_core_bytecode$StoreSlotI64_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StoreSlotI64_t));
        vader_obj_header_init(_a1_obj, 869u);
        _a1_obj->f_bounds_safe = l1;
        t0 = (void*) _a1_obj;
        l3 = vader_ref_box(t0);
    } else if (l2 == INT32_C(3)) {
        vader_struct_vader_core_bytecode$StoreSlotF64_t* _a2_obj = (vader_struct_vader_core_bytecode$StoreSlotF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StoreSlotF64_t));
        vader_obj_header_init(_a2_obj, 867u);
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

static vader_box_t vader_midir_select$slot_width_for(uint8_t l0) {
    vader_box_t l1;
    if (l0 == INT32_C(0)) {
        l1 = vader_box_i32(340u, INT32_C(0));
        return l1;
    }
    if (l0 == INT32_C(4)) {
        l1 = vader_box_i32(340u, INT32_C(0));
    } else if (l0 == INT32_C(10)) {
        l1 = vader_box_i32(340u, INT32_C(0));
    } else if (l0 == INT32_C(1)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(5)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(2)) {
        l1 = vader_box_i32(340u, INT32_C(1));
    } else if (l0 == INT32_C(6)) {
        l1 = vader_box_i32(340u, INT32_C(1));
    } else if (l0 == INT32_C(11)) {
        l1 = vader_box_i32(340u, INT32_C(1));
    } else if (l0 == INT32_C(8)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(3)) {
        l1 = vader_box_i32(340u, INT32_C(2));
    } else if (l0 == INT32_C(7)) {
        l1 = vader_box_i32(340u, INT32_C(2));
    } else if (l0 == INT32_C(9)) {
        l1 = vader_box_i32(340u, INT32_C(3));
    } else if (l0 == INT32_C(12)) {
        l1 = vader_box_i32(340u, INT32_C(4));
    } else if (l0 == INT32_C(13)) {
        l1 = vader_box_i32(340u, INT32_C(4));
    } else if (l0 == INT32_C(14)) {
        l1 = vader_box_i32(340u, INT32_C(4));
    } else if (l0 == INT32_C(15)) {
        l1 = vader_box_i32(340u, INT32_C(2));
    } else if (l0 == INT32_C(16)) {
        l1 = vader_box_i32(340u, INT32_C(4));
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_box_i32(340u, INT32_C(4));
    }
    return l1;
}

static vader_box_t vader_midir_select$spelled_shape(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t l4 = 0;
    int64_t l2, l3;
    void* l5 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l5 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_select$c_safe_key(l0);
    l2 = vader_host_std_core$byte_len(l1);
    l3 = vader_chk_sub(i64, INT64_C(32), INT64_C(1));
    if (!((l2 > l3))) {
        l4 = vader_midir_select$fnv1a_hex(l0);
        vader_struct_std_core$Range__i64_t* _a0_obj = (vader_struct_std_core$Range__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_core$Range__i64_t));
        vader_obj_header_init(_a0_obj, 621u);
        _a0_obj->f_start = INT64_C(0);
        _a0_obj->f_end = INT64_C(8);
        _a0_obj->f_inclusive = false;
        _a0_obj->f_done = false;
        _a0_obj->f_cursor = INT64_C(0);
        l5 = (void*) _a0_obj;
        l4 = std_core$string$Index$at$1(l4, l5);
        t0 = concat_3(l1, 976u, l4);
        { vader_box_t __vret = vader_box_string(335u, t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static uint64_t vader_midir_select$symbol_hash(void* l0) {
    uint64_t l1, l2, l3;
    vader_string_t t0;
    uint64_t t1;
    int32_t t2;
    int64_t t3;
    t0 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_module_name;
    if (!(t0 == 0u)) {
        t0 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_module_name;
        l1 = std_core$string$Hash$hash_vt(t0);
        l2 = vader_midir_select$mix64((uint64_t) -3750763034362895579, l1);
        t0 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
        l3 = std_core$string$Hash$hash_vt(t0);
        t1 = vader_midir_select$mix64(l2, l3);
        return t1;
    }
    l1 = vader_midir_select$mix64((uint64_t) -3750763034362895579, (uint64_t) 101);
    t2 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
    t3 = ((int64_t) (uint32_t) t2);
    l2 = (uint64_t) (int64_t) t3;
    t1 = vader_midir_select$mix64(l1, l2);
    return t1;
}

static vader_string_t vader_midir_select$symbol_key(void* l0) {
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
    t0 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_module_name;
    if (!(t0 == 0u)) {
        l4 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_module_name;
        l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
        t0 = concat_3(l4, 399u, l5);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) vader_buffer_new((size_t) INT64_C(22));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 2120u);
    t1 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
    l3 = ((int64_t) (int32_t) t1);
    l2 = std_core$write_int(l1, l2, l3);
    t0 = std_core$finish_buffer(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_midir_select$tuple_shape_name(void* l0) {
    vader_string_t l1 = 0;
    vader_box_t l2 = vader_box_null();
    int64_t l3, l4;
    void* l5 = NULL;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_select$type_key_join(l0, 976u);
    l2 = vader_midir_select$spelled_shape(l1);
    if (l2.tag == 0u) {
        l3 = ((vader_array_t*) l0)->length;
        l1 = vader_midir_select$fnv1a_hex(l1);
        l4 = vader_host_std_core$byte_len(l1);
        l5 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l4));
        l4 = INT64_C(0);
        l4 = std_core$write_int(l5, l4, l3);
        l4 = std_core$write_string_at(l5, l4, 976u);
        l4 = std_core$write_string_at(l5, l4, l1);
        t0 = std_core$finish_buffer(l5, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.s;
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint64_t vader_midir_select$type_args_hash(uint64_t l0, void* l1) {
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
        l6 = vader_midir_select$type_intern_hash(t0);
        l2 = vader_midir_select$mix64(l2, l6);
        l5 = (l5 + INT64_C(1));
    }
    t1 = ((vader_array_t*) l1)->length;
    t2 = t1;
    l6 = (uint64_t) (int64_t) t2;
    t3 = vader_midir_select$mix64(l2, l6);
    { uint64_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

uint64_t vader_midir_select$type_intern_hash(vader_box_t l0) {
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
    if (l0.tag == 915u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        l1 = vader_midir_select$bare_hash(t1);
        { uint64_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 906u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_support_integer$MachineInteger_t*) ((vader_struct_vader_core_types$EnumType_t*) t0)->f_repr)->f_name;
        l1 = vader_midir_select$bare_hash(t1);
    } else if (l0.tag == 903u) {
        l1 = vader_midir_select$bare_hash(579u);
    } else if ((l0.tag == 908u || l0.tag == 909u || l0.tag == 910u || l0.tag == 913u || l0.tag == 917u || l0.tag == 922u || l0.tag == 923u || l0.tag == 927u)) {
        t1 = vader_core_types$display_type(l0);
        l1 = vader_midir_select$bare_hash(t1);
    } else if (l0.tag == 911u) {
        t0 = l0.payload.obj;
        vader_core_types$leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else if (l0.tag == 905u) {
        t0 = l0.payload.obj;
        l1 = vader_midir_select$type_intern_hash(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        t2 = vader_core_types$storage_integer(t0);
        t1 = ((vader_struct_vader_support_integer$MachineInteger_t*) t2)->f_name;
        l1 = vader_midir_select$bare_hash(t1);
    } else if (l0.tag == 918u) {
        l2 = vader_midir_select$mix64((uint64_t) -3750763034362895579, (uint64_t) 1);
        t0 = l0.payload.obj;
        l3 = vader_midir_select$symbol_hash(((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol);
        l2 = vader_midir_select$mix64(l2, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_args;
        l1 = vader_midir_select$argument_hashes(l2, l4);
    } else if (l0.tag == 920u) {
        l2 = vader_midir_select$mix64((uint64_t) -3750763034362895579, (uint64_t) 2);
        t0 = l0.payload.obj;
        l3 = vader_midir_select$symbol_hash(((vader_struct_vader_core_types$TraitType_t*) t0)->f_symbol);
        l2 = vader_midir_select$mix64(l2, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_types$TraitType_t*) t0)->f_args;
        l1 = vader_midir_select$argument_hashes(l2, l4);
    } else if (l0.tag == 904u) {
        l2 = vader_midir_select$mix64((uint64_t) -3750763034362895579, (uint64_t) 3);
        t0 = l0.payload.obj;
        l3 = vader_midir_select$type_intern_hash(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element);
        l1 = vader_midir_select$mix64(l2, l3);
    } else if (l0.tag == 926u) {
        l2 = vader_midir_select$mix64((uint64_t) -3750763034362895579, (uint64_t) 4);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
        l1 = vader_midir_select$type_args_hash(l2, l4);
    } else if (l0.tag == 921u) {
        l2 = vader_midir_select$mix64((uint64_t) -3750763034362895579, (uint64_t) 5);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements;
        l1 = vader_midir_select$type_args_hash(l2, l4);
    } else {
        if (!(l0.tag == 907u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_midir_select$mix64((uint64_t) -3750763034362895579, (uint64_t) 6);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_params;
        l2 = vader_midir_select$type_args_hash(l2, l4);
        t0 = l0.payload.obj;
        l3 = vader_midir_select$type_intern_hash(((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type);
        l1 = vader_midir_select$mix64(l2, l3);
    }
    { uint64_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_midir_select$type_intern_key(vader_box_t l0) {
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
    if (l0.tag == 915u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        l2 = vader_midir_select$symbol_key(((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol);
        t0 = l0.payload.obj;
        l3 = vader_midir_select$argument_keys(((vader_struct_vader_core_types$StructType_t*) t0)->f_args);
        l1 = concat_5(802u, l2, 504u, l3, 525u);
    } else if (l0.tag == 920u) {
        t0 = l0.payload.obj;
        l2 = vader_midir_select$symbol_key(((vader_struct_vader_core_types$TraitType_t*) t0)->f_symbol);
        t0 = l0.payload.obj;
        l3 = vader_midir_select$argument_keys(((vader_struct_vader_core_types$TraitType_t*) t0)->f_args);
        l1 = concat_5(916u, l2, 504u, l3, 525u);
    } else if (l0.tag == 906u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_support_integer$MachineInteger_t*) ((vader_struct_vader_core_types$EnumType_t*) t0)->f_repr)->f_name;
    } else if (l0.tag == 905u) {
        t0 = l0.payload.obj;
        l1 = vader_midir_select$type_intern_key(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$storage_integer(t0);
        l1 = ((vader_struct_vader_support_integer$MachineInteger_t*) t1)->f_name;
    } else if (l0.tag == 904u) {
        t0 = l0.payload.obj;
        l2 = vader_midir_select$type_intern_key(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element);
        l1 = concat_3(581u, l2, 525u);
    } else if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        l2 = vader_midir_select$type_key_join(((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants, 3057u);
        l1 = concat_3(923u, l2, 525u);
    } else if (l0.tag == 921u) {
        t0 = l0.payload.obj;
        l2 = vader_midir_select$type_key_join(((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements, 3057u);
        l1 = concat_3(918u, l2, 525u);
    } else if (l0.tag == 907u) {
        t0 = l0.payload.obj;
        l2 = vader_midir_select$type_key_join(((vader_struct_vader_core_types$FnType_t*) t0)->f_params, 360u);
        t0 = l0.payload.obj;
        l3 = vader_midir_select$type_intern_key(((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type);
        l1 = concat_4(648u, l2, 344u, l3);
    } else if (l0.tag == 923u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$display_type(vader_ref_box(t0));
    } else if (l0.tag == 911u) {
        t0 = l0.payload.obj;
        vader_core_types$leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else if (l0.tag == 922u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$display_type(vader_ref_box(t0));
    } else if (l0.tag == 917u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$display_type(vader_ref_box(t0));
    } else if (l0.tag == 927u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$display_type(vader_ref_box(t0));
    } else if (l0.tag == 910u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$display_type(vader_ref_box(t0));
    } else if (l0.tag == 908u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$display_type(vader_ref_box(t0));
    } else if (l0.tag == 909u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$display_type(vader_ref_box(t0));
    } else if (l0.tag == 913u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$display_type(vader_ref_box(t0));
    } else {
        if (!(l0.tag == 903u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 579u;
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_midir_select$type_key_join(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l6, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l0;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) l2)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l6 = vader_midir_select$type_intern_key(t0);
        vader_array_push_scalar((vader_array_t*) l3, vader_box_string(335u, l6));
        l5 = (l5 + INT64_C(1));
    }
    t1 = std_string$join(l3, l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_midir_select$unary_op_for(uint8_t l0, uint8_t l1) {
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        l2 = vader_midir_select$checked_neg_op(l1);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        vader_struct_vader_core_bytecode$BoolNot_t* _a0_obj = (vader_struct_vader_core_bytecode$BoolNot_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BoolNot_t));
        vader_obj_header_init(_a0_obj, 759u);
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_midir_select$bitnot_op(l1);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

uint8_t vader_midir_select$val_type_of_primitive_name(vader_string_t l0) {
    vader_box_t l1;
    uint8_t t0;
    if (l0 == 609u) {
        return (uint8_t) 15;
    }
    l1 = vader_core_bytecode$parse_val_type(l0);
    if (l1.tag == 0u) {
        return (uint8_t) 17;
    }
    t0 = ((uint8_t) l1.payload.i);
    return t0;
}

uint8_t vader_midir_select$val_type_of_type(vader_box_t l0) {
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
    if (l0.tag == 915u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        l1 = vader_midir_select$val_type_of_primitive_name(t1);
        { uint8_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 918u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 906u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_support_integer$MachineInteger_t*) ((vader_struct_vader_core_types$EnumType_t*) t0)->f_repr)->f_name;
        l1 = vader_midir_select$val_type_of_primitive_name(t1);
    } else if (l0.tag == 905u) {
        t0 = l0.payload.obj;
        l1 = vader_midir_select$val_type_of_type(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        t2 = vader_core_types$storage_integer(t0);
        t1 = ((vader_struct_vader_support_integer$MachineInteger_t*) t2)->f_name;
        l1 = vader_midir_select$val_type_of_primitive_name(t1);
    } else if (l0.tag == 904u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 907u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 921u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 920u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 926u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 923u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 911u) {
        t0 = l0.payload.obj;
        vader_core_types$leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else if (l0.tag == 922u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 917u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 903u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 927u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 910u) {
        l1 = (uint8_t) 2;
    } else if (l0.tag == 908u) {
        l1 = (uint8_t) 11;
    } else if (l0.tag == 909u) {
        l1 = (uint8_t) 9;
    } else {
        if (!(l0.tag == 913u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = (uint8_t) 14;
    }
    { uint8_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}
