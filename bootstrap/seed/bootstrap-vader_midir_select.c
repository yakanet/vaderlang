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
    if (!(l1.tag == 1021u)) {
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
    if (!(l1.tag == 1021u)) {
        t0 = vader_midir_select$type_intern_key(l0);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l1.payload.obj;
    l2 = vader_midir_select$symbol_key(((vader_struct_vader_core_types$EnumType_t*) t1)->f_symbol);
    t0 = concat_2(635u, l2);
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
        l2 = 3063u;
        l5 = (l5 + INT64_C(1));
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_select$arith_op(uint8_t l0, vader_string_t l1) {
    bool t0;
    void* t1;
    t0 = vader_core_bytecode$is_float_val(l0);
    if (t0) {
        if (l1 == 1509u) {
            t1 = (void*) &vader_data_108;
            vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
            return vader_ref_box(t1);
        }
        if (l1 == 2678u) {
            t1 = (void*) &vader_data_109;
            vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
            return vader_ref_box(t1);
        }
        if (!(l1 == 2361u)) {
            t1 = (void*) &vader_data_111;
            vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
            return vader_ref_box(t1);
        }
        t1 = (void*) &vader_data_110;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (t0) {
        if (l1 == 1509u) {
            t1 = (void*) &vader_data_112;
            vader_array_t* _a4_slotarr = ((vader_array_t*) t1);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT64_C(0));
            return vader_ref_box(t1);
        }
        if (l1 == 2678u) {
            t1 = (void*) &vader_data_113;
            vader_array_t* _a5_slotarr = ((vader_array_t*) t1);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            t1 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) INT64_C(0));
            return vader_ref_box(t1);
        }
        if (!(l1 == 2361u)) {
            t1 = (void*) &vader_data_115;
            vader_array_t* _a6_slotarr = ((vader_array_t*) t1);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            t1 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) INT64_C(0));
            return vader_ref_box(t1);
        }
        t1 = (void*) &vader_data_114;
        vader_array_t* _a7_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t1 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    if (l1 == 1509u) {
        t1 = (void*) &vader_data_116;
        vader_array_t* _a8_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        t1 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    if (l1 == 2678u) {
        t1 = (void*) &vader_data_72;
        vader_array_t* _a9_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        t1 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    if (!(l1 == 2361u)) {
        t1 = (void*) &vader_data_118;
        vader_array_t* _a10_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        t1 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t1 = (void*) &vader_data_117;
    vader_array_t* _a11_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
    t1 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t1);
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
        t2 = concat_3(1681u, l0, 1175u);
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
    if (l0.tag == 1030u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1021u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_support_integer$MachineInteger_t*) ((vader_struct_vader_core_types$EnumType_t*) t0)->f_repr)->f_name;
    } else if (l0.tag == 1031u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$storage_integer(t0);
        l1 = ((vader_struct_vader_support_integer$MachineInteger_t*) t1)->f_name;
    } else if (l0.tag == 1018u) {
        l1 = 580u;
    } else if ((l0.tag == 1023u || l0.tag == 1024u || l0.tag == 1025u || l0.tag == 1028u || l0.tag == 1032u || l0.tag == 1037u || l0.tag == 1038u || l0.tag == 1042u)) {
        l1 = vader_core_types$display_type(l0);
    } else if (l0.tag == 1026u) {
        t0 = l0.payload.obj;
        vader_core_types$leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else {
        if (!((l0.tag == 1019u || l0.tag == 1020u || l0.tag == 1022u || l0.tag == 1033u || l0.tag == 1035u || l0.tag == 1036u || l0.tag == 1041u))) {
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
        l2 = vader_midir_select$arith_op(l1, 1509u);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        l2 = vader_midir_select$arith_op(l1, 2678u);
    } else if (l0 == INT32_C(2)) {
        l2 = vader_midir_select$arith_op(l1, 2361u);
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
        l2 = vader_midir_select$bit_op(l1, 1544u);
    } else if (l0 == INT32_C(8)) {
        l2 = vader_midir_select$bit_op(l1, 2440u);
    } else if (l0 == INT32_C(9)) {
        l2 = vader_midir_select$bit_op(l1, 3050u);
    } else if (l0 == INT32_C(10)) {
        t0 = (void*) &vader_data_119;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        l2 = vader_ref_box(t0);
    } else if (l0 == INT32_C(11)) {
        t0 = (void*) &vader_data_120;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
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
    void* t1;
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (t0) {
        if (l1 == 1544u) {
            t1 = (void*) &vader_data_148;
            vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
            return vader_ref_box(t1);
        }
        if (!(l1 == 2440u)) {
            t1 = (void*) &vader_data_150;
            vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
            return vader_ref_box(t1);
        }
        t1 = (void*) &vader_data_149;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    if (l1 == 1544u) {
        t1 = (void*) &vader_data_70;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    if (!(l1 == 2440u)) {
        t1 = (void*) &vader_data_71;
        vader_array_t* _a4_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t1 = (void*) &vader_data_151;
    vader_array_t* _a5_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    t1 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t1);
}

static vader_box_t vader_midir_select$bitnot_op(uint8_t l0) {
    bool t0;
    void* t1;
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        t1 = (void*) &vader_data_163;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t1 = (void*) &vader_data_162;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t1);
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
    vader_obj_header_init(_a0_obj, 887u);
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
    vader_obj_header_init(_a0_obj, 888u);
    _a0_obj->f_kind = l0;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir_select$cmp_eq(uint8_t l0) {
    void* t0;
    bool t1;
    if (l0 == INT32_C(10)) {
        t0 = (void*) &vader_data_96;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    if (l0 == INT32_C(12)) {
        t0 = (void*) &vader_data_97;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    t1 = vader_core_bytecode$is_float_val(l0);
    if (t1) {
        t0 = (void*) &vader_data_98;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    t1 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (t1) {
        t0 = (void*) &vader_data_99;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    t1 = vader_midir_select$is_ref_class(l0);
    if (!(t1)) {
        t0 = (void*) &vader_data_101;
        vader_array_t* _a4_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    t0 = (void*) &vader_data_100;
    vader_array_t* _a5_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t0);
}

static vader_box_t vader_midir_select$cmp_ge(uint8_t l0) {
    bool t0;
    void* t1;
    t0 = vader_core_bytecode$is_float_val(l0);
    if (t0) {
        t1 = (void*) &vader_data_122;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t0 = vader_core_bytecode$is_u64_class(l0);
    if (t0) {
        t1 = (void*) &vader_data_123;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t0 = vader_core_bytecode$is_u32_class(l0);
    if (t0) {
        t1 = (void*) &vader_data_124;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        t1 = (void*) &vader_data_126;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t1 = (void*) &vader_data_125;
    vader_array_t* _a4_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t1);
}

static vader_box_t vader_midir_select$cmp_gt(uint8_t l0) {
    bool t0;
    void* t1;
    t0 = vader_core_bytecode$is_float_val(l0);
    if (t0) {
        t1 = (void*) &vader_data_127;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t0 = vader_core_bytecode$is_u64_class(l0);
    if (t0) {
        t1 = (void*) &vader_data_128;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t0 = vader_core_bytecode$is_u32_class(l0);
    if (t0) {
        t1 = (void*) &vader_data_129;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        t1 = (void*) &vader_data_131;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t1 = (void*) &vader_data_130;
    vader_array_t* _a4_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t1);
}

static vader_box_t vader_midir_select$cmp_le(uint8_t l0) {
    bool t0;
    void* t1;
    t0 = vader_core_bytecode$is_float_val(l0);
    if (t0) {
        t1 = (void*) &vader_data_132;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t0 = vader_core_bytecode$is_u64_class(l0);
    if (t0) {
        t1 = (void*) &vader_data_133;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t0 = vader_core_bytecode$is_u32_class(l0);
    if (t0) {
        t1 = (void*) &vader_data_134;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        t1 = (void*) &vader_data_136;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t1 = (void*) &vader_data_135;
    vader_array_t* _a4_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t1);
}

static vader_box_t vader_midir_select$cmp_lt(uint8_t l0) {
    bool t0;
    void* t1;
    t0 = vader_core_bytecode$is_float_val(l0);
    if (t0) {
        t1 = (void*) &vader_data_137;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t0 = vader_core_bytecode$is_u64_class(l0);
    if (t0) {
        t1 = (void*) &vader_data_138;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t0 = vader_core_bytecode$is_u32_class(l0);
    if (t0) {
        t1 = (void*) &vader_data_139;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        t1 = (void*) &vader_data_141;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t1 = (void*) &vader_data_140;
    vader_array_t* _a4_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t1);
}

static vader_box_t vader_midir_select$cmp_ne(uint8_t l0) {
    void* t0;
    bool t1;
    if (l0 == INT32_C(10)) {
        t0 = (void*) &vader_data_142;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    if (l0 == INT32_C(12)) {
        t0 = (void*) &vader_data_143;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    t1 = vader_core_bytecode$is_float_val(l0);
    if (t1) {
        t0 = (void*) &vader_data_144;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    t1 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (t1) {
        t0 = (void*) &vader_data_145;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    t1 = vader_midir_select$is_ref_class(l0);
    if (!(t1)) {
        t0 = (void*) &vader_data_147;
        vader_array_t* _a4_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    t0 = (void*) &vader_data_146;
    vader_array_t* _a5_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t0);
}

static vader_box_t vader_midir_select$div_op(uint8_t l0) {
    bool t0;
    void* t1;
    vader_box_t t2;
    t0 = vader_core_bytecode$is_u64_class(l0);
    if (t0) {
        t1 = (void*) &vader_data_94;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t0 = vader_core_bytecode$is_u32_class(l0);
    if (!(t0)) {
        t2 = vader_midir_select$arith_op(l0, 1842u);
        return t2;
    }
    t1 = (void*) &vader_data_95;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t1);
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
        vader_obj_header_init(_a0_obj, 736u);
        _a0_obj->f_start = l2;
        _a0_obj->f_end = l3;
        _a0_obj->f_inclusive = false;
        _a0_obj->f_done = false;
        _a0_obj->f_cursor = l2;
        l8 = (void*) _a0_obj;
        l9 = std_core$string$Index$at$1(457u, l8);
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
    if (l0 == 2614u) {
        t0 = (void*) &vader_data_83;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2613u) {
        t0 = (void*) &vader_data_84;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2601u) {
        t0 = (void*) &vader_data_85;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2603u) {
        t0 = (void*) &vader_data_86;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2602u) {
        t0 = (void*) &vader_data_87;
        vader_array_t* _a4_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2600u) {
        t0 = (void*) &vader_data_88;
        vader_array_t* _a5_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2604u) {
        t0 = (void*) &vader_data_89;
        vader_array_t* _a6_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2611u) {
        t0 = (void*) &vader_data_90;
        vader_array_t* _a7_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2617u) {
        t0 = (void*) &vader_data_91;
        vader_array_t* _a8_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        t0 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2610u) {
        t0 = (void*) &vader_data_92;
        vader_array_t* _a9_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        t0 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0 == 2616u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = (void*) &vader_data_93;
    vader_array_t* _a10_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
    t0 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) INT64_C(0));
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_midir_select$intrinsic_op_for_name(vader_string_t l0) {
    void* t0;
    if (l0 == 2563u) {
        t0 = (void*) &vader_data_102;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    if (l0 == 1585u) {
        t0 = (void*) &vader_data_103;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    if (l0 == 1580u) {
        t0 = (void*) &vader_data_104;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    if (l0 == 1567u) {
        t0 = (void*) &vader_data_105;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    if (l0 == 1583u) {
        t0 = (void*) &vader_data_106;
        vader_array_t* _a4_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    if (!(l0 == 1565u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = (void*) &vader_data_107;
    vader_array_t* _a5_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t0);
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
    void* t1;
    t0 = vader_core_bytecode$is_u64_class(l0);
    if (t0) {
        t1 = (void*) &vader_data_158;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t0 = vader_core_bytecode$is_u32_class(l0);
    if (t0) {
        t1 = (void*) &vader_data_159;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        t1 = (void*) &vader_data_161;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t1 = (void*) &vader_data_160;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t1);
}

static vader_box_t vader_midir_select$neg_op(uint8_t l0) {
    bool t0;
    void* t1;
    t0 = vader_core_bytecode$is_float_val(l0);
    if (t0) {
        t1 = (void*) &vader_data_164;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        t1 = (void*) &vader_data_166;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t1 = (void*) &vader_data_165;
    vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t1);
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
    l1 = vader_core_bytecode$strip_core_member(l0, 261u);
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
    l1 = vader_core_bytecode$strip_core_member(l0, 268u);
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
    l1 = vader_core_bytecode$strip_core_member(l0, 267u);
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
    l1 = vader_core_bytecode$strip_core_member(l0, 265u);
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
    vader_box_t l1;
    vader_string_t t0;
    bool t1;
    uint8_t t2;
    vader_box_t t3;
    l1 = vader_core_bytecode$strip_core_member(l0, 266u);
    if (l1.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l1.payload.s;
    t1 = vader_core_types$is_scalar_type_name(t0);
    if (t1) {
        t0 = l1.payload.s;
        t2 = vader_midir_select$val_type_of_primitive_name(t0);
        t3 = vader_midir_select$cmp_eq(t2);
        return t3;
    }
    return vader_box_obj(0u, NULL);
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
    if (l2.tag == 1021u) {
        l4 = true;
    } else {
        l4 = l3.tag == 1021u;
    }
    if (!(l4)) {
        t0 = vader_midir_select$same_intern_class(l0, l1);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 1021u) {
        l4 = l3.tag == 1021u;
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
    if (l0.tag == 1020u) {
        t0 = l0.payload.obj;
        t1 = vader_midir_select$same_intern_class(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1020u) {
        l2 = l0;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing;
        t1 = vader_midir_select$same_intern_class(l2, l3);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1031u) {
        if (l1.tag == 1031u) {
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
    if ((l0.tag == 1021u || l0.tag == 1030u || l0.tag == 1031u)) {
        l6 = true;
    } else {
        l6 = (l1.tag == 1021u || l1.tag == 1030u || l1.tag == 1031u);
    }
    if (l6) {
        l7 = vader_midir_select$bare_intern_name(l0);
        if (l7 != 0u) {
            l8 = vader_midir_select$bare_intern_name(l1);
            { bool __vret = l7 == l8; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 1033u) {
        if (l1.tag == 1033u) {
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
    if (l0.tag == 1035u) {
        if (l1.tag == 1035u) {
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
    if (l0.tag == 1019u) {
        if (l1.tag == 1019u) {
            t0 = l0.payload.obj;
            l2 = ((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element;
            t1 = vader_midir_select$same_intern_class(l2, l3);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 1041u) {
        if (l1.tag == 1041u) {
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
            t1 = vader_midir_select$same_class_list(l4, l5);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l0.tag == 1036u) {
        if (l1.tag == 1036u) {
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements;
            t1 = vader_midir_select$same_class_list(l4, l5);
            { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (!(l0.tag == 1022u)) {
        l7 = vader_midir_select$bare_intern_name(l0);
        l8 = vader_midir_select$bare_intern_name(l1);
        { bool __vret = l7 == l8; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1022u) {
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
    void* t1;
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (!(t0)) {
        t1 = (void*) &vader_data_157;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t1 = (void*) &vader_data_156;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t1);
}

static vader_box_t vader_midir_select$shr_op(uint8_t l0) {
    bool l1;
    bool t0;
    void* t1;
    l1 = vader_core_bytecode$is_unsigned_val(l0);
    t0 = vader_core_bytecode$is_64_bit_int_val(l0);
    if (t0) {
        if (!(l1)) {
            t1 = (void*) &vader_data_153;
            vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
            return vader_ref_box(t1);
        }
        t1 = (void*) &vader_data_152;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    if (!(l1)) {
        t1 = (void*) &vader_data_155;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    t1 = (void*) &vader_data_154;
    vader_array_t* _a3_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t1);
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
        vader_obj_header_init(_a0_obj, 961u);
        _a0_obj->f_bounds_safe = l1;
        t0 = (void*) _a0_obj;
        l3 = vader_ref_box(t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(2)) {
        vader_struct_vader_core_bytecode$LoadSlotI64_t* _a1_obj = (vader_struct_vader_core_bytecode$LoadSlotI64_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LoadSlotI64_t));
        vader_obj_header_init(_a1_obj, 962u);
        _a1_obj->f_bounds_safe = l1;
        t0 = (void*) _a1_obj;
        l3 = vader_ref_box(t0);
    } else if (l2 == INT32_C(3)) {
        vader_struct_vader_core_bytecode$LoadSlotF64_t* _a2_obj = (vader_struct_vader_core_bytecode$LoadSlotF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$LoadSlotF64_t));
        vader_obj_header_init(_a2_obj, 960u);
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
        vader_obj_header_init(_a0_obj, 983u);
        _a0_obj->f_bounds_safe = l1;
        t0 = (void*) _a0_obj;
        l3 = vader_ref_box(t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(2)) {
        vader_struct_vader_core_bytecode$StoreSlotI64_t* _a1_obj = (vader_struct_vader_core_bytecode$StoreSlotI64_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StoreSlotI64_t));
        vader_obj_header_init(_a1_obj, 984u);
        _a1_obj->f_bounds_safe = l1;
        t0 = (void*) _a1_obj;
        l3 = vader_ref_box(t0);
    } else if (l2 == INT32_C(3)) {
        vader_struct_vader_core_bytecode$StoreSlotF64_t* _a2_obj = (vader_struct_vader_core_bytecode$StoreSlotF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$StoreSlotF64_t));
        vader_obj_header_init(_a2_obj, 982u);
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
        l1 = vader_box_i32(452u, INT32_C(0));
        return l1;
    }
    if (l0 == INT32_C(4)) {
        l1 = vader_box_i32(452u, INT32_C(0));
    } else if (l0 == INT32_C(10)) {
        l1 = vader_box_i32(452u, INT32_C(0));
    } else if (l0 == INT32_C(1)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(5)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(2)) {
        l1 = vader_box_i32(452u, INT32_C(1));
    } else if (l0 == INT32_C(6)) {
        l1 = vader_box_i32(452u, INT32_C(1));
    } else if (l0 == INT32_C(11)) {
        l1 = vader_box_i32(452u, INT32_C(1));
    } else if (l0 == INT32_C(8)) {
        l1 = vader_box_obj(0u, NULL);
    } else if (l0 == INT32_C(3)) {
        l1 = vader_box_i32(452u, INT32_C(2));
    } else if (l0 == INT32_C(7)) {
        l1 = vader_box_i32(452u, INT32_C(2));
    } else if (l0 == INT32_C(9)) {
        l1 = vader_box_i32(452u, INT32_C(3));
    } else if (l0 == INT32_C(12)) {
        l1 = vader_box_i32(452u, INT32_C(4));
    } else if (l0 == INT32_C(13)) {
        l1 = vader_box_i32(452u, INT32_C(4));
    } else if (l0 == INT32_C(14)) {
        l1 = vader_box_i32(452u, INT32_C(4));
    } else if (l0 == INT32_C(15)) {
        l1 = vader_box_i32(452u, INT32_C(2));
    } else if (l0 == INT32_C(16)) {
        l1 = vader_box_i32(452u, INT32_C(4));
    } else {
        if (!(l0 == INT32_C(17))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_box_i32(452u, INT32_C(4));
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
        vader_obj_header_init(_a0_obj, 736u);
        _a0_obj->f_start = INT64_C(0);
        _a0_obj->f_end = INT64_C(8);
        _a0_obj->f_inclusive = false;
        _a0_obj->f_done = false;
        _a0_obj->f_cursor = INT64_C(0);
        l5 = (void*) _a0_obj;
        l4 = std_core$string$Index$at$1(l4, l5);
        t0 = concat_3(l1, 976u, l4);
        { vader_box_t __vret = vader_box_string(447u, t0); vader_gc_top = gc_frame.prev; return __vret; }
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
        t0 = concat_3(l4, 400u, l5);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) vader_buffer_new((size_t) INT64_C(22));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 2124u);
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
    if (l0.tag == 1030u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        l1 = vader_midir_select$bare_hash(t1);
        { uint64_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1021u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_support_integer$MachineInteger_t*) ((vader_struct_vader_core_types$EnumType_t*) t0)->f_repr)->f_name;
        l1 = vader_midir_select$bare_hash(t1);
    } else if (l0.tag == 1018u) {
        l1 = vader_midir_select$bare_hash(580u);
    } else if ((l0.tag == 1023u || l0.tag == 1024u || l0.tag == 1025u || l0.tag == 1028u || l0.tag == 1032u || l0.tag == 1037u || l0.tag == 1038u || l0.tag == 1042u)) {
        t1 = vader_core_types$display_type(l0);
        l1 = vader_midir_select$bare_hash(t1);
    } else if (l0.tag == 1026u) {
        t0 = l0.payload.obj;
        vader_core_types$leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else if (l0.tag == 1020u) {
        t0 = l0.payload.obj;
        l1 = vader_midir_select$type_intern_hash(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 1031u) {
        t0 = l0.payload.obj;
        t2 = vader_core_types$storage_integer(t0);
        t1 = ((vader_struct_vader_support_integer$MachineInteger_t*) t2)->f_name;
        l1 = vader_midir_select$bare_hash(t1);
    } else if (l0.tag == 1033u) {
        l2 = vader_midir_select$mix64((uint64_t) -3750763034362895579, (uint64_t) 1);
        t0 = l0.payload.obj;
        l3 = vader_midir_select$symbol_hash(((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol);
        l2 = vader_midir_select$mix64(l2, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_args;
        l1 = vader_midir_select$argument_hashes(l2, l4);
    } else if (l0.tag == 1035u) {
        l2 = vader_midir_select$mix64((uint64_t) -3750763034362895579, (uint64_t) 2);
        t0 = l0.payload.obj;
        l3 = vader_midir_select$symbol_hash(((vader_struct_vader_core_types$TraitType_t*) t0)->f_symbol);
        l2 = vader_midir_select$mix64(l2, l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_types$TraitType_t*) t0)->f_args;
        l1 = vader_midir_select$argument_hashes(l2, l4);
    } else if (l0.tag == 1019u) {
        l2 = vader_midir_select$mix64((uint64_t) -3750763034362895579, (uint64_t) 3);
        t0 = l0.payload.obj;
        l3 = vader_midir_select$type_intern_hash(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element);
        l1 = vader_midir_select$mix64(l2, l3);
    } else if (l0.tag == 1041u) {
        l2 = vader_midir_select$mix64((uint64_t) -3750763034362895579, (uint64_t) 4);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
        l1 = vader_midir_select$type_args_hash(l2, l4);
    } else if (l0.tag == 1036u) {
        l2 = vader_midir_select$mix64((uint64_t) -3750763034362895579, (uint64_t) 5);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements;
        l1 = vader_midir_select$type_args_hash(l2, l4);
    } else {
        if (!(l0.tag == 1022u)) {
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
    if (l0.tag == 1030u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1033u) {
        t0 = l0.payload.obj;
        l2 = vader_midir_select$symbol_key(((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol);
        t0 = l0.payload.obj;
        l3 = vader_midir_select$argument_keys(((vader_struct_vader_core_types$StructType_t*) t0)->f_args);
        l1 = concat_5(800u, l2, 505u, l3, 526u);
    } else if (l0.tag == 1035u) {
        t0 = l0.payload.obj;
        l2 = vader_midir_select$symbol_key(((vader_struct_vader_core_types$TraitType_t*) t0)->f_symbol);
        t0 = l0.payload.obj;
        l3 = vader_midir_select$argument_keys(((vader_struct_vader_core_types$TraitType_t*) t0)->f_args);
        l1 = concat_5(915u, l2, 505u, l3, 526u);
    } else if (l0.tag == 1021u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_support_integer$MachineInteger_t*) ((vader_struct_vader_core_types$EnumType_t*) t0)->f_repr)->f_name;
    } else if (l0.tag == 1020u) {
        t0 = l0.payload.obj;
        l1 = vader_midir_select$type_intern_key(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 1031u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$storage_integer(t0);
        l1 = ((vader_struct_vader_support_integer$MachineInteger_t*) t1)->f_name;
    } else if (l0.tag == 1019u) {
        t0 = l0.payload.obj;
        l2 = vader_midir_select$type_intern_key(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element);
        l1 = concat_3(582u, l2, 526u);
    } else if (l0.tag == 1041u) {
        t0 = l0.payload.obj;
        l2 = vader_midir_select$type_key_join(((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants, 3063u);
        l1 = concat_3(922u, l2, 526u);
    } else if (l0.tag == 1036u) {
        t0 = l0.payload.obj;
        l2 = vader_midir_select$type_key_join(((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements, 3063u);
        l1 = concat_3(917u, l2, 526u);
    } else if (l0.tag == 1022u) {
        t0 = l0.payload.obj;
        l2 = vader_midir_select$type_key_join(((vader_struct_vader_core_types$FnType_t*) t0)->f_params, 361u);
        t0 = l0.payload.obj;
        l3 = vader_midir_select$type_intern_key(((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type);
        l1 = concat_4(647u, l2, 345u, l3);
    } else if (l0.tag == 1038u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$display_type(vader_ref_box(t0));
    } else if (l0.tag == 1026u) {
        t0 = l0.payload.obj;
        vader_core_types$leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else if (l0.tag == 1037u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$display_type(vader_ref_box(t0));
    } else if (l0.tag == 1032u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$display_type(vader_ref_box(t0));
    } else if (l0.tag == 1042u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$display_type(vader_ref_box(t0));
    } else if (l0.tag == 1025u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$display_type(vader_ref_box(t0));
    } else if (l0.tag == 1023u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$display_type(vader_ref_box(t0));
    } else if (l0.tag == 1024u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$display_type(vader_ref_box(t0));
    } else if (l0.tag == 1028u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$display_type(vader_ref_box(t0));
    } else {
        if (!(l0.tag == 1018u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 580u;
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
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
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
        vader_array_push_scalar((vader_array_t*) l3, vader_box_string(447u, l6));
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
        t0 = (void*) &vader_data_121;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
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
    if (l0 == 610u) {
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
    if (l0.tag == 1030u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        l1 = vader_midir_select$val_type_of_primitive_name(t1);
        { uint8_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1033u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 1021u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_support_integer$MachineInteger_t*) ((vader_struct_vader_core_types$EnumType_t*) t0)->f_repr)->f_name;
        l1 = vader_midir_select$val_type_of_primitive_name(t1);
    } else if (l0.tag == 1020u) {
        t0 = l0.payload.obj;
        l1 = vader_midir_select$val_type_of_type(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 1031u) {
        t0 = l0.payload.obj;
        t2 = vader_core_types$storage_integer(t0);
        t1 = ((vader_struct_vader_support_integer$MachineInteger_t*) t2)->f_name;
        l1 = vader_midir_select$val_type_of_primitive_name(t1);
    } else if (l0.tag == 1019u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 1022u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 1036u) {
        l1 = (uint8_t) 16;
    } else if (l0.tag == 1035u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 1041u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 1038u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 1026u) {
        t0 = l0.payload.obj;
        vader_core_types$leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else if (l0.tag == 1037u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 1032u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 1018u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 1042u) {
        l1 = (uint8_t) 17;
    } else if (l0.tag == 1025u) {
        l1 = (uint8_t) 2;
    } else if (l0.tag == 1023u) {
        l1 = (uint8_t) 11;
    } else if (l0.tag == 1024u) {
        l1 = (uint8_t) 9;
    } else {
        if (!(l0.tag == 1028u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = (uint8_t) 14;
    }
    { uint8_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}
