#include "bootstrap.split.h"

static vader_box_t vader_bytecode_arith_op(uint8_t l0, vader_string_t l1);
static uint8_t vader_bytecode_array_kind_of_val(uint8_t l0);
static vader_box_t vader_bytecode_bc_type_of_with_ctx(vader_box_t l0, void* l1, int32_t l2);
static vader_box_t vader_bytecode_bit_op(uint8_t l0, vader_string_t l1);
static vader_box_t vader_bytecode_bitnot_op(uint8_t l0);
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
static bool vader_bytecode_foldable_self_copy(void* l0, size_t l1, size_t l2, void* l3);
static vader_string_t vader_bytecode_int_equals_method(vader_string_t l0);
static vader_box_t vader_bytecode_intrinsic_op_for_mangled(vader_string_t l0);
static bool vader_bytecode_is_display_to_string(vader_string_t l0);
static bool vader_bytecode_is_op_eq_prim(vader_string_t l0);
static bool vader_bytecode_is_ref_class(uint8_t l0);
static bool vader_bytecode_is_u32_class(uint8_t l0);
static bool vader_bytecode_is_u64_class(uint8_t l0);
static vader_string_t vader_bytecode_key_join(void* l0, void* l1, vader_string_t l2);
static void* vader_bytecode_mark_jump_targets(void* l0, size_t l1);
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
static void* vader_bytecode_remap_jump_table(void* l0, void* l1, size_t l2);
static vader_box_t vader_bytecode_remap_type_in_op(vader_box_t l0, void* l1);
static vader_box_t vader_bytecode_shl_op(uint8_t l0);
static vader_box_t vader_bytecode_shr_op(uint8_t l0);
static int32_t vader_bytecode_slot_touched(vader_box_t l0);
static vader_box_t vader_bytecode_slot_width_for(uint8_t l0);
static vader_box_t vader_bytecode_strip_core_member(vader_string_t l0, vader_string_t l1);
static vader_string_t vader_bytecode_symbol_key(void* l0);
static vader_box_t vader_bytecode_try_fold_arith(vader_box_t l0, void* l1, size_t l2);
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_is_float_val(l0);
    if (t0) {
        if (l1 == 1154u) {
            vader_struct_vader_bytecode_F64Add_t* _a0_obj = (vader_struct_vader_bytecode_F64Add_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Add_t));
            vader_obj_header_init(_a0_obj, 544u);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 2133u) {
            vader_struct_vader_bytecode_F64Sub_t* _a1_obj = (vader_struct_vader_bytecode_F64Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Sub_t));
            vader_obj_header_init(_a1_obj, 555u);
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 1859u) {
            vader_struct_vader_bytecode_F64Mul_t* _a2_obj = (vader_struct_vader_bytecode_F64Mul_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Mul_t));
            vader_obj_header_init(_a2_obj, 552u);
            t1 = (void*) _a2_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_F64Div_t* _a3_obj = (vader_struct_vader_bytecode_F64Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Div_t));
        vader_obj_header_init(_a3_obj, 546u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        if (l1 == 1154u) {
            vader_struct_vader_bytecode_I64Add_t* _a4_obj = (vader_struct_vader_bytecode_I64Add_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Add_t));
            vader_obj_header_init(_a4_obj, 578u);
            t1 = (void*) _a4_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 2133u) {
            vader_struct_vader_bytecode_I64Sub_t* _a5_obj = (vader_struct_vader_bytecode_I64Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Sub_t));
            vader_obj_header_init(_a5_obj, 597u);
            t1 = (void*) _a5_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 1859u) {
            vader_struct_vader_bytecode_I64Mul_t* _a6_obj = (vader_struct_vader_bytecode_I64Mul_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Mul_t));
            vader_obj_header_init(_a6_obj, 591u);
            t1 = (void*) _a6_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_I64Div_t* _a7_obj = (vader_struct_vader_bytecode_I64Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Div_t));
        vader_obj_header_init(_a7_obj, 584u);
        t1 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 1154u) {
        vader_struct_vader_bytecode_I32Add_t* _a8_obj = (vader_struct_vader_bytecode_I32Add_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Add_t));
        vader_obj_header_init(_a8_obj, 558u);
        t1 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 2133u) {
        vader_struct_vader_bytecode_I32Sub_t* _a9_obj = (vader_struct_vader_bytecode_I32Sub_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Sub_t));
        vader_obj_header_init(_a9_obj, 577u);
        t1 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 1859u) {
        vader_struct_vader_bytecode_I32Mul_t* _a10_obj = (vader_struct_vader_bytecode_I32Mul_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Mul_t));
        vader_obj_header_init(_a10_obj, 571u);
        t1 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Div_t* _a11_obj = (vader_struct_vader_bytecode_I32Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Div_t));
    vader_obj_header_init(_a11_obj, 564u);
    t1 = (void*) _a11_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

uint8_t vader_bytecode_array_kind_from_name(vader_string_t l0) {
    uint8_t l1;
    if (l0 == 2261u) {
        l1 = (uint8_t) (int32_t) INT32_C(1);
    } else {
        if (l0 == 2242u) {
            l1 = (uint8_t) (int32_t) INT32_C(2);
        } else {
            if (l0 == 2243u) {
                l1 = (uint8_t) (int32_t) INT32_C(3);
            } else {
                if (l0 == 2252u) {
                    l1 = (uint8_t) (int32_t) INT32_C(4);
                } else {
                    if (l0 == 2305u) {
                        l1 = (uint8_t) (int32_t) INT32_C(4);
                    } else {
                        if (l0 == 1667u) {
                            l1 = (uint8_t) (int32_t) INT32_C(5);
                        } else {
                            if (l0 == 1622u) {
                                l1 = (uint8_t) (int32_t) INT32_C(6);
                            } else {
                                if (l0 == 1623u) {
                                    l1 = (uint8_t) (int32_t) INT32_C(7);
                                } else {
                                    if (l0 == 1645u) {
                                        l1 = (uint8_t) (int32_t) INT32_C(8);
                                    } else {
                                        if (l0 == 1741u) {
                                            l1 = (uint8_t) (int32_t) INT32_C(8);
                                        } else {
                                            if (l0 == 1516u) {
                                                l1 = (uint8_t) (int32_t) INT32_C(9);
                                            } else {
                                                if (l0 == 1519u) {
                                                    l1 = (uint8_t) (int32_t) INT32_C(10);
                                                } else {
                                                    if (l0 == 1339u) {
                                                        l1 = (uint8_t) (int32_t) INT32_C(11);
                                                    } else {
                                                        if (l0 == 1248u) {
                                                            l1 = (uint8_t) (int32_t) INT32_C(12);
                                                        } else {
                                                            if (l0 == 1936u) {
                                                                l1 = (uint8_t) (int32_t) INT32_C(13);
                                                            } else {
                                                                l1 = (uint8_t) (int32_t) INT32_C(0);
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
        }
    }
    return l1;
}

int32_t vader_bytecode_array_kind_index(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return INT32_C(0);
    }
    if (l0 == INT32_C(1)) {
        return INT32_C(1);
    }
    if (l0 == INT32_C(2)) {
        return INT32_C(2);
    }
    if (l0 == INT32_C(3)) {
        return INT32_C(3);
    }
    if (l0 == INT32_C(4)) {
        return INT32_C(4);
    }
    if (l0 == INT32_C(5)) {
        return INT32_C(5);
    }
    if (l0 == INT32_C(6)) {
        return INT32_C(6);
    }
    if (l0 == INT32_C(7)) {
        return INT32_C(7);
    }
    if (l0 == INT32_C(8)) {
        return INT32_C(8);
    }
    if (l0 == INT32_C(9)) {
        return INT32_C(9);
    }
    if (l0 == INT32_C(10)) {
        return INT32_C(10);
    }
    if (l0 == INT32_C(11)) {
        return INT32_C(11);
    }
    if (l0 == INT32_C(12)) {
        return INT32_C(12);
    }
    if (l0 == INT32_C(13)) {
        return INT32_C(13);
    }
    vader_unreachable("unreachable return in vader_bytecode$array_kind_index");
}

uint8_t vader_bytecode_array_kind_of(vader_box_t l0, void* l1) {
    uint8_t l2;
    void* t0;
    bool t1;
    if (l0.tag == 503u) {
        t0 = l0.payload.obj;
        l2 = vader_bytecode_array_kind_of_val(((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val);
        return l2;
    }
    if (l0.tag == 507u) {
        l2 = (uint8_t) (int32_t) INT32_C(13);
        return l2;
    }
    if (l0.tag == 494u) {
        l2 = (uint8_t) (int32_t) INT32_C(13);
        return l2;
    }
    if (l0.tag == 497u) {
        l2 = (uint8_t) (int32_t) INT32_C(13);
        return l2;
    }
    if (l0.tag == 508u) {
        t0 = l0.payload.obj;
        t1 = vader_bytecode_is_ref_only_element(vader_ref_box(t0), l1);
        if (t1) {
            l2 = (uint8_t) (int32_t) INT32_C(13);
        } else {
            l2 = (uint8_t) (int32_t) INT32_C(0);
        }
        return l2;
    }
    if (l0.tag == 504u) {
        l2 = (uint8_t) (int32_t) INT32_C(0);
        return l2;
    }
    vader_unreachable("unreachable return in vader_bytecode$array_kind_of");
}

static uint8_t vader_bytecode_array_kind_of_val(uint8_t l0) {
    if (l0 == INT32_C(5)) {
        return (uint8_t) (int32_t) INT32_C(1);
    }
    if (l0 == INT32_C(6)) {
        return (uint8_t) (int32_t) INT32_C(2);
    }
    if (l0 == INT32_C(7)) {
        return (uint8_t) (int32_t) INT32_C(3);
    }
    if (l0 == INT32_C(8)) {
        return (uint8_t) (int32_t) INT32_C(4);
    }
    if (l0 == INT32_C(9)) {
        return (uint8_t) (int32_t) INT32_C(4);
    }
    if (l0 == INT32_C(0)) {
        return (uint8_t) (int32_t) INT32_C(5);
    }
    if (l0 == INT32_C(1)) {
        return (uint8_t) (int32_t) INT32_C(6);
    }
    if (l0 == INT32_C(2)) {
        return (uint8_t) (int32_t) INT32_C(7);
    }
    if (l0 == INT32_C(3)) {
        return (uint8_t) (int32_t) INT32_C(8);
    }
    if (l0 == INT32_C(4)) {
        return (uint8_t) (int32_t) INT32_C(8);
    }
    if (l0 == INT32_C(10)) {
        return (uint8_t) (int32_t) INT32_C(9);
    }
    if (l0 == INT32_C(11)) {
        return (uint8_t) (int32_t) INT32_C(10);
    }
    if (l0 == INT32_C(13)) {
        return (uint8_t) (int32_t) INT32_C(11);
    }
    if (l0 == INT32_C(12)) {
        return (uint8_t) (int32_t) INT32_C(12);
    }
    if (l0 == INT32_C(14)) {
        return (uint8_t) (int32_t) INT32_C(0);
    }
    if (l0 == INT32_C(15)) {
        return (uint8_t) (int32_t) INT32_C(0);
    }
    if (l0 == INT32_C(16)) {
        return (uint8_t) (int32_t) INT32_C(0);
    }
    if (l0 == INT32_C(17)) {
        return (uint8_t) (int32_t) INT32_C(4);
    }
    if (l0 == INT32_C(18)) {
        return (uint8_t) (int32_t) INT32_C(13);
    }
    if (l0 == INT32_C(19)) {
        return (uint8_t) (int32_t) INT32_C(0);
    }
    vader_unreachable("unreachable return in vader_bytecode$array_kind_of_val");
}

void vader_bytecode_assert_host_import_wired(vader_string_t l0, bool l1) {
    vader_box_t t0 = vader_box_null();
    uint8_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots };
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
    t2 = concat_3(1293u, l0, 989u);
    vader_host_std_abort_panic(t2);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t vader_bytecode_bc_type_key(void* l0, int32_t l1) {
    bool l2;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null();
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t l8;
    vader_string_t l9 = 0;
    vader_string_t l11 = 0;
    int32_t l10;
    int64_t t0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[3] = { &l0, &l6, &l7 };
    vader_string_t* gc_atom_roots[3] = { &l9, &l11, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
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
        { vader_gc_top = gc_frame.prev; return 534u; }
    }
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l5.tag == 503u) {
        l6 = l5.payload.obj;
        l7 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(22));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l7, l3, 1902u);
        l8 = ((int64_t) (int32_t) ((int32_t) (uint8_t) ((vader_struct_vader_bytecode_BcPrimitive_t*) l6)->f_val));
        l3 = std_core_write_int(l7, l3, l8);
        t1 = std_core_finish_buffer(l7, l3);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 507u) {
        l6 = l5.payload.obj;
        l9 = ((vader_struct_vader_bytecode_BcStruct_t*) l6)->f_name;
        t1 = concat_2(1967u, l9);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 504u) {
        l6 = l5.payload.obj;
        l9 = ((vader_struct_vader_bytecode_BcRef_t*) l6)->f_trait_name;
        t1 = concat_2(1923u, l9);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 494u) {
        l6 = l5.payload.obj;
        l10 = ((vader_struct_vader_bytecode_BcArray_t*) l6)->f_element;
        l9 = vader_bytecode_bc_type_key(l0, l10);
        t1 = concat_3(1150u, l9, 530u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 508u) {
        l6 = l5.payload.obj;
        l6 = ((vader_struct_vader_bytecode_BcUnion_t*) l6)->f_variants;
        l9 = vader_bytecode_key_join(l0, l6, 2441u);
        t1 = concat_3(2264u, l9, 530u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 497u) {
        l6 = l5.payload.obj;
        l7 = ((vader_struct_vader_bytecode_BcFn_t*) l6)->f_params;
        l9 = vader_bytecode_key_join(l0, l7, 2441u);
        l10 = ((vader_struct_vader_bytecode_BcFn_t*) l6)->f_return_type;
        l11 = vader_bytecode_bc_type_key(l0, l10);
        t1 = concat_4(1533u, l9, 363u, l11);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_bytecode$bc_type_key");
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_bytecode_bc_type_of_with_ctx(vader_box_t l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    size_t l5, l6, l9;
    int32_t l7;
    uint64_t l10;
    vader_string_t l11 = 0;
    int64_t l13;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    uint8_t t2;
    vader_box_t t3 = vader_box_null();
    int32_t t4;
    int64_t t5;
    vader_box_t* gc_roots[2] = { &l0, &t3 };
    void** gc_raw_roots[6] = { &l1, &l3, &l4, &l8, &l12, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l11, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 917u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        t2 = vader_bytecode_val_type_of_primitive_name(t1);
        vader_struct_vader_bytecode_BcPrimitive_t* _a0_obj = (vader_struct_vader_bytecode_BcPrimitive_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPrimitive_t));
        vader_obj_header_init(_a0_obj, 503u);
        _a0_obj->f_val = t2;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 910u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
        t2 = vader_bytecode_val_type_of_primitive_name(t1);
        vader_struct_vader_bytecode_BcPrimitive_t* _a1_obj = (vader_struct_vader_bytecode_BcPrimitive_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPrimitive_t));
        vader_obj_header_init(_a1_obj, 503u);
        _a1_obj->f_val = t2;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 909u) {
        t0 = l0.payload.obj;
        t3 = vader_bytecode_bc_type_of_with_ctx(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing, l1, l2);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 919u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_name;
        vader_struct_vader_bytecode_BcRef_t* _a2_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a2_obj, 504u);
        _a2_obj->f_trait_name = t1;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 920u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol)->f_name;
        vader_struct_vader_bytecode_BcRef_t* _a3_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a3_obj, 504u);
        _a3_obj->f_trait_name = t1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 908u) {
        t0 = l0.payload.obj;
        t4 = vader_bytecode_intern_type(((vader_struct_vader_types_ArrayType_t*) t0)->f_element, l1);
        vader_struct_vader_bytecode_BcArray_t* _a4_obj = (vader_struct_vader_bytecode_BcArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcArray_t));
        vader_obj_header_init(_a4_obj, 494u);
        _a4_obj->f_element = t4;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 924u) {
        l3 = l0.payload.obj;
        vader_array_t* _a5_arr = vader_array_new(9u, 0u, 7u, 166u);
        l4 = (void*) _a5_arr;
        l3 = ((vader_struct_vader_types_UnionType_t*) l3)->f_variants;
        l5 = ((vader_array_t*) l3)->length;
        l6 = (size_t) (int64_t) INT64_C(0);
        {
            loop_81: {
                if ((l6 < l5)) {
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                    if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                    if ((size_t) l6 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
                    l7 = vader_bytecode_intern_type(t3, l1);
                    vader_array_push_i32((vader_array_t*) l4, l7);
                    t5 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t5;
                    goto loop_81;
                } else {
                }
            }
        }
        vader_struct_vader_bytecode_BcUnion_t* _a7_obj = (vader_struct_vader_bytecode_BcUnion_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcUnion_t));
        vader_obj_header_init(_a7_obj, 508u);
        _a7_obj->f_variants = l4;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 911u) {
        l3 = l0.payload.obj;
        vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 166u);
        l4 = (void*) _a8_arr;
        l8 = ((vader_struct_vader_types_FnType_t*) l3)->f_params;
        l5 = ((vader_array_t*) l8)->length;
        l6 = (size_t) (int64_t) INT64_C(0);
        {
            loop_123: {
                if ((l6 < l5)) {
                    vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
                    if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                    if ((size_t) l6 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l6);
                    l7 = vader_bytecode_intern_type(t3, l1);
                    vader_array_push_i32((vader_array_t*) l4, l7);
                    t5 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t5;
                    goto loop_123;
                } else {
                }
            }
        }
        l7 = vader_bytecode_intern_type(((vader_struct_vader_types_FnType_t*) l3)->f_return_type, l1);
        vader_struct_vader_bytecode_BcFn_t* _a10_obj = (vader_struct_vader_bytecode_BcFn_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFn_t));
        vader_obj_header_init(_a10_obj, 497u);
        _a10_obj->f_params = l4;
        _a10_obj->f_return_type = l7;
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 921u) {
        l3 = l0.payload.obj;
        vader_array_t* _a11_arr = vader_array_new(36u, 0u, 13u, 496u);
        l4 = (void*) _a11_arr;
        l5 = ((vader_array_t*) ((vader_struct_vader_types_TupleType_t*) l3)->f_elements)->length;
        l6 = (size_t) (int64_t) INT64_C(0);
        {
            loop_169: {
                if ((l6 < l5)) {
                    l8 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
                    l9 = (size_t) (int64_t) INT64_C(0);
                    l9 = std_core_write_string_at(l8, l9, 869u);
                    t5 = ((int64_t) (size_t) l6);
                    l10 = (uint64_t) (int64_t) t5;
                    l9 = std_core_write_unsigned(l8, l9, l10);
                    l11 = std_core_finish_buffer(l8, l9);
                    vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_types_TupleType_t*) l3)->f_elements);
                    if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                    if ((size_t) l6 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = vader_array_ref_load_box(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l6);
                    l7 = vader_bytecode_intern_type(t3, l1);
                    vader_struct_vader_bytecode_BcField_t* _a13_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
                    vader_obj_header_init(_a13_obj, 496u);
                    _a13_obj->f_name = l11;
                    _a13_obj->f_type_index = l7;
                    l12 = (void*) _a13_obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l12));
                    t5 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t5;
                    goto loop_169;
                } else {
                }
            }
        }
        l3 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(28));
        l5 = (size_t) (int64_t) INT64_C(0);
        l5 = std_core_write_string_at(l3, l5, 888u);
        l13 = ((int64_t) (int32_t) l2);
        l5 = std_core_write_int(l3, l5, l13);
        l11 = std_core_finish_buffer(l3, l5);
        l7 = -(INT32_C(1));
        vader_struct_vader_bytecode_BcStruct_t* _a14_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
        vader_obj_header_init(_a14_obj, 507u);
        _a14_obj->f_name = l11;
        _a14_obj->f_fields = l4;
        _a14_obj->f_c_name = 0u;
        _a14_obj->f_symbol_id = l7;
        t0 = (void*) _a14_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 923u) {
        vader_struct_vader_bytecode_BcRef_t* _a15_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a15_obj, 504u);
        _a15_obj->f_trait_name = 0u;
        t0 = (void*) _a15_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 922u) {
        vader_struct_vader_bytecode_BcRef_t* _a16_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a16_obj, 504u);
        _a16_obj->f_trait_name = 0u;
        t0 = (void*) _a16_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 918u) {
        vader_struct_vader_bytecode_BcRef_t* _a17_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a17_obj, 504u);
        _a17_obj->f_trait_name = 0u;
        t0 = (void*) _a17_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 925u) {
        vader_struct_vader_bytecode_BcRef_t* _a18_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a18_obj, 504u);
        _a18_obj->f_trait_name = 0u;
        t0 = (void*) _a18_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 914u) {
        vader_struct_vader_bytecode_BcRef_t* _a19_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a19_obj, 504u);
        _a19_obj->f_trait_name = 0u;
        t0 = (void*) _a19_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 912u) {
        vader_struct_vader_bytecode_BcRef_t* _a20_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a20_obj, 504u);
        _a20_obj->f_trait_name = 0u;
        t0 = (void*) _a20_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 913u) {
        vader_struct_vader_bytecode_BcRef_t* _a21_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a21_obj, 504u);
        _a21_obj->f_trait_name = 0u;
        t0 = (void*) _a21_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 915u) {
        vader_struct_vader_bytecode_BcRef_t* _a22_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a22_obj, 504u);
        _a22_obj->f_trait_name = 0u;
        t0 = (void*) _a22_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 907u) {
        vader_struct_vader_bytecode_BcRef_t* _a23_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
        vader_obj_header_init(_a23_obj, 504u);
        _a23_obj->f_trait_name = 0u;
        t0 = (void*) _a23_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_bytecode$bc_type_of_with_ctx");
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_bytecode_binary_op_for(uint8_t l0, uint8_t l1) {
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        t0 = vader_bytecode_arith_op(l1, 1154u);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        t0 = vader_bytecode_arith_op(l1, 2133u);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(2)) {
        t0 = vader_bytecode_arith_op(l1, 1859u);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(3)) {
        t0 = vader_bytecode_div_op(l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(4)) {
        t0 = vader_bytecode_mod_op(l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(5)) {
        t0 = vader_bytecode_shl_op(l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(6)) {
        t0 = vader_bytecode_shr_op(l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(7)) {
        t0 = vader_bytecode_bit_op(l1, 1169u);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(8)) {
        t0 = vader_bytecode_bit_op(l1, 1896u);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(9)) {
        t0 = vader_bytecode_bit_op(l1, 2430u);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(10)) {
        vader_struct_vader_bytecode_BoolAnd_t* _a0_obj = (vader_struct_vader_bytecode_BoolAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolAnd_t));
        vader_obj_header_init(_a0_obj, 516u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(11)) {
        vader_struct_vader_bytecode_BoolOr_t* _a1_obj = (vader_struct_vader_bytecode_BoolOr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolOr_t));
        vader_obj_header_init(_a1_obj, 521u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(12)) {
        t0 = vader_bytecode_cmp_eq(l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(13)) {
        t0 = vader_bytecode_cmp_ne(l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(14)) {
        t0 = vader_bytecode_cmp_lt(l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(15)) {
        t0 = vader_bytecode_cmp_le(l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(16)) {
        t0 = vader_bytecode_cmp_gt(l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(17)) {
        t0 = vader_bytecode_cmp_ge(l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_bytecode$binary_op_for");
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_bytecode_bit_op(uint8_t l0, vader_string_t l1) {
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        if (l1 == 1169u) {
            vader_struct_vader_bytecode_I64BitAnd_t* _a0_obj = (vader_struct_vader_bytecode_I64BitAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitAnd_t));
            vader_obj_header_init(_a0_obj, 579u);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1 == 1896u) {
            vader_struct_vader_bytecode_I64BitOr_t* _a1_obj = (vader_struct_vader_bytecode_I64BitOr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitOr_t));
            vader_obj_header_init(_a1_obj, 581u);
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_I64BitXor_t* _a2_obj = (vader_struct_vader_bytecode_I64BitXor_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64BitXor_t));
        vader_obj_header_init(_a2_obj, 582u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 1169u) {
        vader_struct_vader_bytecode_I32BitAnd_t* _a3_obj = (vader_struct_vader_bytecode_I32BitAnd_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitAnd_t));
        vader_obj_header_init(_a3_obj, 559u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 1896u) {
        vader_struct_vader_bytecode_I32BitOr_t* _a4_obj = (vader_struct_vader_bytecode_I32BitOr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitOr_t));
        vader_obj_header_init(_a4_obj, 561u);
        t1 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32BitXor_t* _a5_obj = (vader_struct_vader_bytecode_I32BitXor_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitXor_t));
    vader_obj_header_init(_a5_obj, 562u);
    t1 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        vader_obj_header_init(_a0_obj, 580u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32BitNot_t* _a1_obj = (vader_struct_vader_bytecode_I32BitNot_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32BitNot_t));
    vader_obj_header_init(_a1_obj, 560u);
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(117u, 0u, 13u, 1070u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_signature)->f_params)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l4 < l3)) {
                vader_struct_vader_bytecode_LocalGet_t* _a1_obj = (vader_struct_vader_bytecode_LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalGet_t));
                vader_obj_header_init(_a1_obj, 608u);
                _a1_obj->f_slot = ((int32_t) (size_t) l4);
                l5 = (void*) _a1_obj;
                vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_9;
            } else {
            }
        }
    }
    t1 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
    l6 = vader_bytecode_intrinsic_op_for_mangled(t1);
    if (!(l6.tag == 0u)) {
        vader_array_push((vader_array_t*) l2, l6);
    } else {
        vader_struct_vader_bytecode_CallImport_t* _a2_obj = (vader_struct_vader_bytecode_CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallImport_t));
        vader_obj_header_init(_a2_obj, 530u);
        _a2_obj->f_index = l1;
        l5 = (void*) _a2_obj;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
    }
    vader_struct_vader_bytecode_Return_t* _a3_obj = (vader_struct_vader_bytecode_Return_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Return_t));
    vader_obj_header_init(_a3_obj, 618u);
    l5 = (void*) _a3_obj;
    vader_array_push((vader_array_t*) l2, vader_ref_box(l5));
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_bytecode_cmp_eq(uint8_t l0) {
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(12)) {
        vader_struct_vader_bytecode_BoolEq_t* _a0_obj = (vader_struct_vader_bytecode_BoolEq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolEq_t));
        vader_obj_header_init(_a0_obj, 518u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(14)) {
        vader_struct_vader_bytecode_StringEq_t* _a1_obj = (vader_struct_vader_bytecode_StringEq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringEq_t));
        vader_obj_header_init(_a1_obj, 630u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_float_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_F64Eq_t* _a2_obj = (vader_struct_vader_bytecode_F64Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Eq_t));
        vader_obj_header_init(_a2_obj, 547u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_64_bit_int_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_I64Eq_t* _a3_obj = (vader_struct_vader_bytecode_I64Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Eq_t));
        vader_obj_header_init(_a3_obj, 585u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_ref_class(l0);
    if (t1) {
        vader_struct_vader_bytecode_RefEq_t* _a4_obj = (vader_struct_vader_bytecode_RefEq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefEq_t));
        vader_obj_header_init(_a4_obj, 616u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Eq_t* _a5_obj = (vader_struct_vader_bytecode_I32Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Eq_t));
    vader_obj_header_init(_a5_obj, 565u);
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        vader_obj_header_init(_a0_obj, 548u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Ge_t* _a1_obj = (vader_struct_vader_bytecode_U64Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Ge_t));
        vader_obj_header_init(_a1_obj, 645u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Ge_t* _a2_obj = (vader_struct_vader_bytecode_U32Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Ge_t));
        vader_obj_header_init(_a2_obj, 639u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        vader_struct_vader_bytecode_I64Ge_t* _a3_obj = (vader_struct_vader_bytecode_I64Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Ge_t));
        vader_obj_header_init(_a3_obj, 586u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Ge_t* _a4_obj = (vader_struct_vader_bytecode_I32Ge_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Ge_t));
    vader_obj_header_init(_a4_obj, 566u);
    t1 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        vader_obj_header_init(_a0_obj, 549u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Gt_t* _a1_obj = (vader_struct_vader_bytecode_U64Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Gt_t));
        vader_obj_header_init(_a1_obj, 646u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Gt_t* _a2_obj = (vader_struct_vader_bytecode_U32Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Gt_t));
        vader_obj_header_init(_a2_obj, 640u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        vader_struct_vader_bytecode_I64Gt_t* _a3_obj = (vader_struct_vader_bytecode_I64Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Gt_t));
        vader_obj_header_init(_a3_obj, 587u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Gt_t* _a4_obj = (vader_struct_vader_bytecode_I32Gt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Gt_t));
    vader_obj_header_init(_a4_obj, 567u);
    t1 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        vader_obj_header_init(_a0_obj, 550u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Le_t* _a1_obj = (vader_struct_vader_bytecode_U64Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Le_t));
        vader_obj_header_init(_a1_obj, 647u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Le_t* _a2_obj = (vader_struct_vader_bytecode_U32Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Le_t));
        vader_obj_header_init(_a2_obj, 641u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        vader_struct_vader_bytecode_I64Le_t* _a3_obj = (vader_struct_vader_bytecode_I64Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Le_t));
        vader_obj_header_init(_a3_obj, 588u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Le_t* _a4_obj = (vader_struct_vader_bytecode_I32Le_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Le_t));
    vader_obj_header_init(_a4_obj, 568u);
    t1 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        vader_obj_header_init(_a0_obj, 551u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u64_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U64Lt_t* _a1_obj = (vader_struct_vader_bytecode_U64Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U64Lt_t));
        vader_obj_header_init(_a1_obj, 648u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Lt_t* _a2_obj = (vader_struct_vader_bytecode_U32Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Lt_t));
        vader_obj_header_init(_a2_obj, 642u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        vader_struct_vader_bytecode_I64Lt_t* _a3_obj = (vader_struct_vader_bytecode_I64Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Lt_t));
        vader_obj_header_init(_a3_obj, 589u);
        t1 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Lt_t* _a4_obj = (vader_struct_vader_bytecode_I32Lt_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Lt_t));
    vader_obj_header_init(_a4_obj, 569u);
    t1 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_bytecode_cmp_ne(uint8_t l0) {
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(12)) {
        vader_struct_vader_bytecode_BoolNe_t* _a0_obj = (vader_struct_vader_bytecode_BoolNe_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolNe_t));
        vader_obj_header_init(_a0_obj, 519u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(14)) {
        vader_struct_vader_bytecode_StringNe_t* _a1_obj = (vader_struct_vader_bytecode_StringNe_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StringNe_t));
        vader_obj_header_init(_a1_obj, 631u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_float_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_F64Ne_t* _a2_obj = (vader_struct_vader_bytecode_F64Ne_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64Ne_t));
        vader_obj_header_init(_a2_obj, 553u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_64_bit_int_val(l0);
    if (t1) {
        vader_struct_vader_bytecode_I64Ne_t* _a3_obj = (vader_struct_vader_bytecode_I64Ne_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Ne_t));
        vader_obj_header_init(_a3_obj, 592u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_bytecode_is_ref_class(l0);
    if (t1) {
        vader_struct_vader_bytecode_RefNe_t* _a4_obj = (vader_struct_vader_bytecode_RefNe_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefNe_t));
        vader_obj_header_init(_a4_obj, 617u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Ne_t* _a5_obj = (vader_struct_vader_bytecode_I32Ne_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Ne_t));
    vader_obj_header_init(_a5_obj, 572u);
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_box_t l35 = vader_box_null(), l36 = vader_box_null();
    vader_string_t l37 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    bool t2;
    void* t3 = NULL;
    size_t t4;
    vader_box_t* gc_roots[3] = { &l35, &l36, &t1 };
    void** gc_raw_roots[14] = { &l0, &l3, &l5, &l6, &l10, &l15, &l17, &l18, &l19, &l25, &l27, &l29, &l34, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l37 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
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
    vader_array_t* _a0_arr = vader_array_new(41u, 0u, 13u, 621u);
    l5 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 161u);
    l6 = (void*) _a1_arr;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_28: {
            if ((l7 < l2)) {
                l8 = -(INT32_C(1));
                l9 = -(INT32_C(1));
                vader_struct_vader_bytecode_SlotRange_t* _a2_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                vader_obj_header_init(_a2_obj, 621u);
                _a2_obj->f_first = l8;
                _a2_obj->f_last = l9;
                l10 = (void*) _a2_obj;
                vader_array_push((vader_array_t*) l5, vader_ref_box(l10));
                vader_array_push_bool((vader_array_t*) l6, false);
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                goto loop_28;
            } else {
            }
        }
    }
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_61: {
            if ((l7 < l4)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l7 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
                l8 = vader_bytecode_slot_touched(t1);
                if ((l8 >= INT32_C(0))) {
                    t0 = ((int64_t) (int32_t) l8);
                    l11 = (size_t) (int64_t) t0;
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l11 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_box_bool(161u, ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l11]);
                    t2 = t1.payload.b;
                    if (!(t2)) {
                        l9 = ((int32_t) (size_t) l7);
                        l12 = ((int32_t) (size_t) l7);
                        vader_struct_vader_bytecode_SlotRange_t* _a5_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                        vader_obj_header_init(_a5_obj, 621u);
                        _a5_obj->f_first = l9;
                        _a5_obj->f_last = l12;
                        l10 = (void*) _a5_obj;
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
                        if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                        if ((size_t) l11 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                        vader_array_ref_store(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l11, l10);
                        VADER_WRITE_BARRIER(_a6_slotarr->buf);
                        vader_array_t* _a7_slotarr = ((vader_array_t*) l6);
                        if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                        if ((size_t) l11 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l11] = (uint8_t) true;
                    } else {
                        vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
                        if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                        if ((size_t) l11 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                        t3 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l11);
                        l13 = ((vader_struct_vader_bytecode_SlotRange_t*) t3)->f_first;
                        l14 = ((int32_t) (size_t) l7);
                        vader_struct_vader_bytecode_SlotRange_t* _a9_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                        vader_obj_header_init(_a9_obj, 621u);
                        _a9_obj->f_first = l13;
                        _a9_obj->f_last = l14;
                        l15 = (void*) _a9_obj;
                        vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
                        if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                        if ((size_t) l11 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                        vader_array_ref_store(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l11, l15);
                        VADER_WRITE_BARRIER(_a10_slotarr->buf);
                    }
                } else {
                }
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                goto loop_61;
            } else {
            }
        }
    }
    l10 = vader_bytecode_find_loop_ranges(l3);
    t4 = ((vader_array_t*) l10)->length;
    if ((t4 > INT64_C(0))) {
        l16 = true;
        {
            loop_141: {
                if (l16) {
                    l16 = vader_bytecode_extend_into_loops(l5, l6, l2, l10);
                    goto loop_141;
                } else {
                }
            }
        }
    } else {
    }
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_160: {
            if ((l7 < l1)) {
                l8 = ((int32_t) (size_t) l4);
                vader_struct_vader_bytecode_SlotRange_t* _a11_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                vader_obj_header_init(_a11_obj, 621u);
                _a11_obj->f_first = INT32_C(0);
                _a11_obj->f_last = l8;
                l10 = (void*) _a11_obj;
                vader_array_t* _a12_slotarr = ((vader_array_t*) l5);
                if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                if ((size_t) l7 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                vader_array_ref_store(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l7, l10);
                VADER_WRITE_BARRIER(_a12_slotarr->buf);
                vader_array_t* _a13_slotarr = ((vader_array_t*) l6);
                if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                if ((size_t) l7 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                ((uint8_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l7] = (uint8_t) true;
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                goto loop_160;
            } else {
            }
        }
    }
    vader_array_t* _a14_arr = vader_array_new(39u, 0u, 13u, 500u);
    l10 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(9u, 0u, 7u, 166u);
    l15 = (void*) _a15_arr;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_196: {
            if ((l7 < l2)) {
                l8 = -(INT32_C(1));
                vader_array_push_i32((vader_array_t*) l15, l8);
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                goto loop_196;
            } else {
            }
        }
    }
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_219: {
            if ((l7 < l1)) {
                l8 = ((int32_t) (size_t) l7);
                vader_array_t* _a16_slotarr = ((vader_array_t*) l15);
                if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                if ((size_t) l7 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l7] = (int32_t) l8;
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                goto loop_219;
            } else {
            }
        }
    }
    vader_array_t* _a17_arr = vader_array_new(41u, 0u, 13u, 621u);
    l17 = (void*) _a17_arr;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_245: {
            if ((l7 < l1)) {
                vader_array_t* _a18_slotarr = ((vader_array_t*) l5);
                if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                if ((size_t) l7 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                l18 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l7);
                vader_array_push((vader_array_t*) l17, vader_ref_box(l18));
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                goto loop_245;
            } else {
            }
        }
    }
    l7 = l1;
    {
        loop_269: {
            if ((l7 < l2)) {
                vader_array_t* _a19_slotarr = ((vader_array_t*) l6);
                if (_a19_slotarr->buf != NULL && _a19_slotarr->buf->header.forward != NULL) { _a19_slotarr->buf = vader_array_buf_forward(_a19_slotarr->buf); }
                if ((size_t) l7 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_box_bool(161u, ((uint8_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l7]);
                t2 = t1.payload.b;
                if (!(t2)) {
                    l8 = -(INT32_C(1));
                    vader_array_t* _a20_slotarr = ((vader_array_t*) l15);
                    if (_a20_slotarr->buf != NULL && _a20_slotarr->buf->header.forward != NULL) { _a20_slotarr->buf = vader_array_buf_forward(_a20_slotarr->buf); }
                    if ((size_t) l7 >= _a20_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l7] = (int32_t) l8;
                    t0 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t0;
                    goto loop_269;
                }
                vader_array_t* _a21_slotarr = ((vader_array_t*) l5);
                if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
                if ((size_t) l7 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
                l18 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l7);
                l19 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
                t0 = (l7 - l1);
                l11 = (size_t) (int64_t) t0;
                vader_array_t* _a22_slotarr = ((vader_array_t*) l19);
                if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                if ((size_t) l11 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l11);
                l20 = ((vader_struct_vader_bytecode_BcLocal_t*) t3)->f_val;
                l9 = -(INT32_C(1));
                vader_array_t* _a23_slotarr = ((vader_array_t*) l17);
                if (_a23_slotarr->buf != NULL && _a23_slotarr->buf->header.forward != NULL) { _a23_slotarr->buf = vader_array_buf_forward(_a23_slotarr->buf); }
                l21 = ((vader_array_t*) l17)->length;
                l22 = l1;
                {
                    loop_317: {
                        if ((l22 < l21)) {
                            t0 = (l22 - l1);
                            l23 = (size_t) (int64_t) t0;
                            vader_array_t* _a24_slotarr = ((vader_array_t*) l10);
                            if (_a24_slotarr->buf != NULL && _a24_slotarr->buf->header.forward != NULL) { _a24_slotarr->buf = vader_array_buf_forward(_a24_slotarr->buf); }
                            if ((size_t) l23 >= _a24_slotarr->length) { vader_trap("array index out of bounds"); }
                            t3 = vader_array_ref_load_obj(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l23);
                            if (((vader_struct_vader_bytecode_BcLocal_t*) t3)->f_val == l20) {
                                if ((size_t) l22 >= _a23_slotarr->length) { vader_trap("array index out of bounds"); }
                                t3 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l22);
                                t2 = vader_bytecode_ranges_overlap(t3, l18);
                                if (!(t2)) {
                                    l9 = ((int32_t) (size_t) l22);
                                } else {
                                    l24 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l22 + l24);
                                    l22 = (size_t) (int64_t) t0;
                                    goto loop_317;
                                }
                            } else {
                                l24 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l22 + l24);
                                l22 = (size_t) (int64_t) t0;
                                goto loop_317;
                            }
                        } else {
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
                    if (_a25_slotarr->buf != NULL && _a25_slotarr->buf->header.forward != NULL) { _a25_slotarr->buf = vader_array_buf_forward(_a25_slotarr->buf); }
                    if ((size_t) l26 >= _a25_slotarr->length) { vader_trap("array index out of bounds"); }
                    l27 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l26);
                    vader_array_push((vader_array_t*) l10, vader_ref_box(l27));
                } else {
                    t0 = ((int64_t) (int32_t) l9);
                    l28 = (size_t) (int64_t) t0;
                    vader_array_t* _a26_slotarr = ((vader_array_t*) l17);
                    if (_a26_slotarr->buf != NULL && _a26_slotarr->buf->header.forward != NULL) { _a26_slotarr->buf = vader_array_buf_forward(_a26_slotarr->buf); }
                    if ((size_t) l28 >= _a26_slotarr->length) { vader_trap("array index out of bounds"); }
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
                    vader_obj_header_init(_a27_obj, 621u);
                    _a27_obj->f_first = l12;
                    _a27_obj->f_last = l30;
                    l34 = (void*) _a27_obj;
                    vader_array_t* _a28_slotarr = ((vader_array_t*) l17);
                    if (_a28_slotarr->buf != NULL && _a28_slotarr->buf->header.forward != NULL) { _a28_slotarr->buf = vader_array_buf_forward(_a28_slotarr->buf); }
                    if ((size_t) l33 >= _a28_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_ref_store(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l33, l34);
                    VADER_WRITE_BARRIER(_a28_slotarr->buf);
                }
                vader_array_t* _a29_slotarr = ((vader_array_t*) l15);
                if (_a29_slotarr->buf != NULL && _a29_slotarr->buf->header.forward != NULL) { _a29_slotarr->buf = vader_array_buf_forward(_a29_slotarr->buf); }
                if ((size_t) l7 >= _a29_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l7] = (int32_t) l9;
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                goto loop_269;
            } else {
            }
        }
    }
    l16 = true;
    {
        loop_461: {
            if ((l1 < l2)) {
                vader_array_t* _a30_slotarr = ((vader_array_t*) l15);
                if (_a30_slotarr->buf != NULL && _a30_slotarr->buf->header.forward != NULL) { _a30_slotarr->buf = vader_array_buf_forward(_a30_slotarr->buf); }
                if ((size_t) l1 >= _a30_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = ((int32_t*) _a30_slotarr->buf->slots)[_a30_slotarr->offset + (size_t) l1];
                l9 = ((int32_t) (size_t) l1);
                if (l8 != l9) {
                    l16 = false;
                } else {
                    t0 = (l1 + INT64_C(1));
                    l1 = (size_t) (int64_t) t0;
                    goto loop_461;
                }
            } else {
            }
        }
    }
    if (l16) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a31_arr = vader_array_new(117u, 0u, 13u, 1070u);
    l5 = (void*) _a31_arr;
    l1 = (size_t) (int64_t) INT64_C(0);
    {
        loop_500: {
            if ((l1 < l4)) {
                vader_array_t* _a32_slotarr = ((vader_array_t*) l3);
                if (_a32_slotarr->buf != NULL && _a32_slotarr->buf->header.forward != NULL) { _a32_slotarr->buf = vader_array_buf_forward(_a32_slotarr->buf); }
                if ((size_t) l1 >= _a32_slotarr->length) { vader_trap("array index out of bounds"); }
                l35 = vader_array_ref_load_box(_a32_slotarr->buf, _a32_slotarr->offset + (size_t) l1);
                l8 = vader_bytecode_slot_touched(l35);
                if ((l8 >= INT32_C(0))) {
                    t0 = ((int64_t) (int32_t) l8);
                    l2 = (size_t) (int64_t) t0;
                    vader_array_t* _a33_slotarr = ((vader_array_t*) l15);
                    if (_a33_slotarr->buf != NULL && _a33_slotarr->buf->header.forward != NULL) { _a33_slotarr->buf = vader_array_buf_forward(_a33_slotarr->buf); }
                    if ((size_t) l2 >= _a33_slotarr->length) { vader_trap("array index out of bounds"); }
                    l9 = ((int32_t*) _a33_slotarr->buf->slots)[_a33_slotarr->offset + (size_t) l2];
                    if ((l9 >= INT32_C(0))) {
                        l36 = vader_bytecode_with_remapped_slot(l35, l9);
                        vader_array_push((vader_array_t*) l5, l36);
                    } else {
                        vader_array_push((vader_array_t*) l5, l35);
                    }
                } else {
                    vader_array_push((vader_array_t*) l5, l35);
                }
                t0 = (l1 + INT64_C(1));
                l1 = (size_t) (int64_t) t0;
                goto loop_500;
            } else {
            }
        }
    }
    l37 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_name;
    l16 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_is_main;
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature;
    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug;
    l15 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    vader_struct_vader_bytecode_BcFunction_t* _a34_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a34_obj, 498u);
    _a34_obj->f_name = l37;
    _a34_obj->f_is_main = l16;
    _a34_obj->f_signature = l3;
    _a34_obj->f_locals = l10;
    _a34_obj->f_body = l5;
    _a34_obj->f_debug = l6;
    _a34_obj->f_jump_table = l15;
    t3 = (void*) _a34_obj;
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_bytecode_const_fills_slot(vader_box_t l0, uint8_t l1) {
    bool l2;
    bool t0;
    uint8_t t1;
    if (l0.tag == 583u) {
        t0 = vader_bytecode_is_64_bit_int_val(l1);
        return t0;
    }
    if (l0.tag == 563u) {
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
    if ((l0.tag == 517u || l0.tag == 532u || l0.tag == 545u || l0.tag == 563u || l0.tag == 583u || l0.tag == 614u || l0.tag == 629u)) {
        return l0;
    }
    t0 = vader_box_obj(0u, NULL);
    return t0;
}

static uint8_t vader_bytecode_const_val_type(vader_box_t l0) {
    if (l0.tag == 563u) {
        return (uint8_t) (int32_t) INT32_C(2);
    }
    if (l0.tag == 583u) {
        return (uint8_t) (int32_t) INT32_C(3);
    }
    if (l0.tag == 545u) {
        return (uint8_t) (int32_t) INT32_C(11);
    }
    if (l0.tag == 517u) {
        return (uint8_t) (int32_t) INT32_C(12);
    }
    if (l0.tag == 532u) {
        return (uint8_t) (int32_t) INT32_C(13);
    }
    if (l0.tag == 629u) {
        return (uint8_t) (int32_t) INT32_C(14);
    }
    if (l0.tag == 614u) {
        return (uint8_t) (int32_t) INT32_C(15);
    }
    vader_unreachable("unreachable return in vader_bytecode$const_val_type");
}

vader_box_t vader_bytecode_convert_target_of(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return vader_box_i32(166u, INT32_C(0));
    }
    if (l0 == INT32_C(1)) {
        return vader_box_i32(166u, INT32_C(0));
    }
    if (l0 == INT32_C(2)) {
        return vader_box_i32(166u, INT32_C(0));
    }
    if (l0 == INT32_C(5)) {
        return vader_box_i32(166u, INT32_C(0));
    }
    if (l0 == INT32_C(6)) {
        return vader_box_i32(166u, INT32_C(0));
    }
    if (l0 == INT32_C(7)) {
        return vader_box_i32(166u, INT32_C(0));
    }
    if (l0 == INT32_C(3)) {
        return vader_box_i32(166u, INT32_C(1));
    }
    if (l0 == INT32_C(8)) {
        return vader_box_i32(166u, INT32_C(1));
    }
    if (l0 == INT32_C(4)) {
        return vader_box_i32(166u, INT32_C(1));
    }
    if (l0 == INT32_C(9)) {
        return vader_box_i32(166u, INT32_C(1));
    }
    if (l0 == INT32_C(10)) {
        return vader_box_i32(166u, INT32_C(2));
    }
    if (l0 == INT32_C(11)) {
        return vader_box_i32(166u, INT32_C(2));
    }
    if (l0 == INT32_C(13)) {
        return vader_box_i32(166u, INT32_C(3));
    }
    if (l0 == INT32_C(12)) {
        return vader_box_obj(0u, NULL);
    }
    if (l0 == INT32_C(14)) {
        return vader_box_obj(0u, NULL);
    }
    if (l0 == INT32_C(15)) {
        return vader_box_obj(0u, NULL);
    }
    if (l0 == INT32_C(16)) {
        return vader_box_obj(0u, NULL);
    }
    if (l0 == INT32_C(17)) {
        return vader_box_obj(0u, NULL);
    }
    if (l0 == INT32_C(18)) {
        return vader_box_obj(0u, NULL);
    }
    if (l0 == INT32_C(19)) {
        return vader_box_obj(0u, NULL);
    }
    vader_unreachable("unreachable return in vader_bytecode$convert_target_of");
}

void* vader_bytecode_default_emit_options(void) {
    void* l0 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 163u);
    l0 = (void*) _a0_arr;
    vader_struct_vader_bytecode_EmitOptions_t* _a1_obj = (vader_struct_vader_bytecode_EmitOptions_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_EmitOptions_t));
    vader_obj_header_init(_a1_obj, 540u);
    _a1_obj->f_optimize = true;
    _a1_obj->f_keep_mangles = l0;
    _a1_obj->f_want_debug = false;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        vader_obj_header_init(_a0_obj, 644u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Div_t* _a1_obj = (vader_struct_vader_bytecode_U32Div_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Div_t));
        vader_obj_header_init(_a1_obj, 638u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_bytecode_arith_op(l0, 1424u);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_bytecode_drop_dead_stores(void* l0) {
    size_t l1, l2, l4, l6, l9, l10, l13, l14, l25, l29;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l33 = NULL;
    vader_box_t l7 = vader_box_null(), l35 = vader_box_null();
    int32_t l11, l15, l21, l24, l28, l30, l31, l32, l34;
    bool l16;
    vader_string_t l36 = 0;
    int64_t t0;
    int32_t t1;
    vader_box_t t2 = vader_box_null();
    bool t3;
    size_t t4;
    void* t5 = NULL;
    vader_box_t* gc_roots[3] = { &l7, &l35, &t2 };
    void** gc_raw_roots[15] = { &l0, &l3, &l5, &l8, &l12, &l17, &l18, &l19, &l20, &l22, &l23, &l26, &l27, &l33, &t5 };
    vader_string_t* gc_atom_roots[1] = { &l36 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    t0 = (l1 + l2);
    l2 = (size_t) (int64_t) t0;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 166u);
    l3 = (void*) _a0_arr;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_16: {
            if ((l4 < l2)) {
                vader_array_push_i32((vader_array_t*) l3, INT32_C(0));
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_16;
            } else {
            }
        }
    }
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    l4 = ((vader_array_t*) l5)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_40: {
            if ((l6 < l4)) {
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                if (l7.tag == 608u) {
                    l8 = l7.payload.obj;
                    t1 = ((vader_struct_vader_bytecode_LocalGet_t*) l8)->f_slot;
                    t0 = ((int64_t) (int32_t) t1);
                    l9 = (size_t) (int64_t) t0;
                    t1 = ((vader_struct_vader_bytecode_LocalGet_t*) l8)->f_slot;
                    t0 = ((int64_t) (int32_t) t1);
                    l10 = (size_t) (int64_t) t0;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l10 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l10];
                    l11 = (t1 + INT32_C(1));
                    if ((size_t) l9 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l9] = (int32_t) l11;
                } else {
                }
                if (l7.tag == 607u) {
                    l12 = l7.payload.obj;
                    t1 = ((vader_struct_vader_bytecode_LocalField_t*) l12)->f_slot;
                    t0 = ((int64_t) (int32_t) t1);
                    l13 = (size_t) (int64_t) t0;
                    t1 = ((vader_struct_vader_bytecode_LocalField_t*) l12)->f_slot;
                    t0 = ((int64_t) (int32_t) t1);
                    l14 = (size_t) (int64_t) t0;
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l14 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l14];
                    l15 = (t1 + INT32_C(1));
                    if ((size_t) l13 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l13] = (int32_t) l15;
                } else {
                }
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_40;
            } else {
            }
        }
    }
    vader_array_t* _a4_arr = vader_array_new(6u, 0u, 12u, 161u);
    l5 = (void*) _a4_arr;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_114: {
            if ((l4 < l2)) {
                vader_array_push_bool((vader_array_t*) l5, false);
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_114;
            } else {
            }
        }
    }
    l16 = false;
    l4 = l1;
    {
        loop_136: {
            if ((l4 < l2)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4];
                if (t1 == INT32_C(0)) {
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
                    if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                    if ((size_t) l4 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l4] = (uint8_t) true;
                    l16 = true;
                } else {
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_136;
            } else {
            }
        }
    }
    if (!(l16)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 166u);
    l3 = (void*) _a7_arr;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_175: {
            if ((l4 < l2)) {
                l11 = -(INT32_C(1));
                vader_array_push_i32((vader_array_t*) l3, l11);
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_175;
            } else {
            }
        }
    }
    l11 = INT32_C(0);
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_200: {
            if ((l4 < l2)) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
                if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                if ((size_t) l4 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_box_bool(161u, ((uint8_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l4]);
                t3 = t2.payload.b;
                if (!(t3)) {
                    vader_array_t* _a9_slotarr = ((vader_array_t*) l3);
                    if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                    if ((size_t) l4 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l4] = (int32_t) l11;
                    l11 = (l11 + INT32_C(1));
                } else {
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_200;
            } else {
            }
        }
    }
    vader_array_t* _a10_arr = vader_array_new(117u, 0u, 13u, 1070u);
    l8 = (void*) _a10_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body)->length;
    vader_array_t* _a11_arr = vader_array_new(9u, 0u, 7u, 166u);
    l12 = (void*) _a11_arr;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_240: {
            if ((l6 < l4)) {
                l11 = -(INT32_C(1));
                vader_array_push_i32((vader_array_t*) l12, l11);
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_240;
            } else {
            }
        }
    }
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_263: {
            if ((l6 < l4)) {
                vader_array_t* _a12_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body);
                if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                if ((size_t) l6 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_box(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l6);
                if (l7.tag == 609u) {
                    l17 = l7.payload.obj;
                    t1 = ((vader_struct_vader_bytecode_LocalSet_t*) l17)->f_slot;
                    t0 = ((int64_t) (int32_t) t1);
                    l9 = (size_t) (int64_t) t0;
                    vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
                    if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                    if ((size_t) l9 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_box_bool(161u, ((uint8_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l9]);
                    t3 = t2.payload.b;
                    if (t3) {
                        t4 = ((vader_array_t*) l8)->length;
                        l11 = ((int32_t) (size_t) t4);
                        vader_array_t* _a14_slotarr = ((vader_array_t*) l12);
                        if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                        if ((size_t) l6 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l6] = (int32_t) l11;
                        vader_struct_vader_bytecode_Drop_t* _a15_obj = (vader_struct_vader_bytecode_Drop_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Drop_t));
                        vader_obj_header_init(_a15_obj, 538u);
                        l18 = (void*) _a15_obj;
                        vader_array_push((vader_array_t*) l8, vader_ref_box(l18));
                    } else {
                        t4 = ((vader_array_t*) l8)->length;
                        l15 = ((int32_t) (size_t) t4);
                        vader_array_t* _a16_slotarr = ((vader_array_t*) l12);
                        if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                        if ((size_t) l6 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l6] = (int32_t) l15;
                        t1 = ((vader_struct_vader_bytecode_LocalSet_t*) l17)->f_slot;
                        t0 = ((int64_t) (int32_t) t1);
                        l10 = (size_t) (int64_t) t0;
                        vader_array_t* _a17_slotarr = ((vader_array_t*) l3);
                        if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                        if ((size_t) l10 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l10];
                        vader_struct_vader_bytecode_LocalSet_t* _a18_obj = (vader_struct_vader_bytecode_LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalSet_t));
                        vader_obj_header_init(_a18_obj, 609u);
                        _a18_obj->f_slot = t1;
                        l19 = (void*) _a18_obj;
                        vader_array_push((vader_array_t*) l8, vader_ref_box(l19));
                    }
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_263;
                }
                if (l7.tag == 610u) {
                    l20 = l7.payload.obj;
                    t1 = ((vader_struct_vader_bytecode_LocalTee_t*) l20)->f_slot;
                    t0 = ((int64_t) (int32_t) t1);
                    l13 = (size_t) (int64_t) t0;
                    vader_array_t* _a19_slotarr = ((vader_array_t*) l5);
                    if (_a19_slotarr->buf != NULL && _a19_slotarr->buf->header.forward != NULL) { _a19_slotarr->buf = vader_array_buf_forward(_a19_slotarr->buf); }
                    if ((size_t) l13 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_box_bool(161u, ((uint8_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l13]);
                    t3 = t2.payload.b;
                    if (t3) {
                        t0 = (l6 + INT64_C(1));
                        l6 = (size_t) (int64_t) t0;
                        goto loop_263;
                    }
                    t4 = ((vader_array_t*) l8)->length;
                    l21 = ((int32_t) (size_t) t4);
                    vader_array_t* _a20_slotarr = ((vader_array_t*) l12);
                    if (_a20_slotarr->buf != NULL && _a20_slotarr->buf->header.forward != NULL) { _a20_slotarr->buf = vader_array_buf_forward(_a20_slotarr->buf); }
                    if ((size_t) l6 >= _a20_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l6] = (int32_t) l21;
                    t1 = ((vader_struct_vader_bytecode_LocalTee_t*) l20)->f_slot;
                    t0 = ((int64_t) (int32_t) t1);
                    l14 = (size_t) (int64_t) t0;
                    vader_array_t* _a21_slotarr = ((vader_array_t*) l3);
                    if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
                    if ((size_t) l14 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l14];
                    vader_struct_vader_bytecode_LocalTee_t* _a22_obj = (vader_struct_vader_bytecode_LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalTee_t));
                    vader_obj_header_init(_a22_obj, 610u);
                    _a22_obj->f_slot = t1;
                    l22 = (void*) _a22_obj;
                    vader_array_push((vader_array_t*) l8, vader_ref_box(l22));
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_263;
                }
                if (l7.tag == 608u) {
                    l23 = l7.payload.obj;
                    t4 = ((vader_array_t*) l8)->length;
                    l24 = ((int32_t) (size_t) t4);
                    vader_array_t* _a23_slotarr = ((vader_array_t*) l12);
                    if (_a23_slotarr->buf != NULL && _a23_slotarr->buf->header.forward != NULL) { _a23_slotarr->buf = vader_array_buf_forward(_a23_slotarr->buf); }
                    if ((size_t) l6 >= _a23_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l6] = (int32_t) l24;
                    t1 = ((vader_struct_vader_bytecode_LocalGet_t*) l23)->f_slot;
                    t0 = ((int64_t) (int32_t) t1);
                    l25 = (size_t) (int64_t) t0;
                    vader_array_t* _a24_slotarr = ((vader_array_t*) l3);
                    if (_a24_slotarr->buf != NULL && _a24_slotarr->buf->header.forward != NULL) { _a24_slotarr->buf = vader_array_buf_forward(_a24_slotarr->buf); }
                    if ((size_t) l25 >= _a24_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = ((int32_t*) _a24_slotarr->buf->slots)[_a24_slotarr->offset + (size_t) l25];
                    vader_struct_vader_bytecode_LocalGet_t* _a25_obj = (vader_struct_vader_bytecode_LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalGet_t));
                    vader_obj_header_init(_a25_obj, 608u);
                    _a25_obj->f_slot = t1;
                    l26 = (void*) _a25_obj;
                    vader_array_push((vader_array_t*) l8, vader_ref_box(l26));
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_263;
                }
                if (l7.tag == 607u) {
                    l27 = l7.payload.obj;
                    t4 = ((vader_array_t*) l8)->length;
                    l28 = ((int32_t) (size_t) t4);
                    vader_array_t* _a26_slotarr = ((vader_array_t*) l12);
                    if (_a26_slotarr->buf != NULL && _a26_slotarr->buf->header.forward != NULL) { _a26_slotarr->buf = vader_array_buf_forward(_a26_slotarr->buf); }
                    if ((size_t) l6 >= _a26_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l6] = (int32_t) l28;
                    t1 = ((vader_struct_vader_bytecode_LocalField_t*) l27)->f_slot;
                    t0 = ((int64_t) (int32_t) t1);
                    l29 = (size_t) (int64_t) t0;
                    vader_array_t* _a27_slotarr = ((vader_array_t*) l3);
                    if (_a27_slotarr->buf != NULL && _a27_slotarr->buf->header.forward != NULL) { _a27_slotarr->buf = vader_array_buf_forward(_a27_slotarr->buf); }
                    if ((size_t) l29 >= _a27_slotarr->length) { vader_trap("array index out of bounds"); }
                    l30 = ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l29];
                    l31 = ((vader_struct_vader_bytecode_LocalField_t*) l27)->f_type_id;
                    l32 = ((vader_struct_vader_bytecode_LocalField_t*) l27)->f_field_index;
                    vader_struct_vader_bytecode_LocalField_t* _a28_obj = (vader_struct_vader_bytecode_LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalField_t));
                    vader_obj_header_init(_a28_obj, 607u);
                    _a28_obj->f_slot = l30;
                    _a28_obj->f_type_id = l31;
                    _a28_obj->f_field_index = l32;
                    l33 = (void*) _a28_obj;
                    vader_array_push((vader_array_t*) l8, vader_ref_box(l33));
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_263;
                }
                t4 = ((vader_array_t*) l8)->length;
                l34 = ((int32_t) (size_t) t4);
                vader_array_t* _a29_slotarr = ((vader_array_t*) l12);
                if (_a29_slotarr->buf != NULL && _a29_slotarr->buf->header.forward != NULL) { _a29_slotarr->buf = vader_array_buf_forward(_a29_slotarr->buf); }
                if ((size_t) l6 >= _a29_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l6] = (int32_t) l34;
                l35 = l7;
                vader_array_push((vader_array_t*) l8, l35);
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_263;
            } else {
            }
        }
    }
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l4 = ((vader_array_t*) l8)->length;
    l3 = vader_bytecode_remap_jump_table(l3, l12, l4);
    l17 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug;
    l4 = ((vader_array_t*) l8)->length;
    l12 = vader_bytecode_remap_debug(l17, l12, l4);
    vader_array_t* _a30_arr = vader_array_new(39u, 0u, 13u, 500u);
    l17 = (void*) _a30_arr;
    l4 = l1;
    {
        loop_495: {
            if ((l4 < l2)) {
                vader_array_t* _a31_slotarr = ((vader_array_t*) l5);
                if (_a31_slotarr->buf != NULL && _a31_slotarr->buf->header.forward != NULL) { _a31_slotarr->buf = vader_array_buf_forward(_a31_slotarr->buf); }
                if ((size_t) l4 >= _a31_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_box_bool(161u, ((uint8_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l4]);
                t3 = t2.payload.b;
                if (!(t3)) {
                    l18 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
                    t0 = (l4 - l1);
                    l6 = (size_t) (int64_t) t0;
                    vader_array_t* _a32_slotarr = ((vader_array_t*) l18);
                    if (_a32_slotarr->buf != NULL && _a32_slotarr->buf->header.forward != NULL) { _a32_slotarr->buf = vader_array_buf_forward(_a32_slotarr->buf); }
                    if ((size_t) l6 >= _a32_slotarr->length) { vader_trap("array index out of bounds"); }
                    l19 = vader_array_ref_load_obj(_a32_slotarr->buf, _a32_slotarr->offset + (size_t) l6);
                    vader_array_push((vader_array_t*) l17, vader_ref_box(l19));
                } else {
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_495;
            } else {
            }
        }
    }
    l36 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_name;
    l16 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_is_main;
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature;
    vader_struct_vader_bytecode_BcFunction_t* _a33_obj = (vader_struct_vader_bytecode_BcFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFunction_t));
    vader_obj_header_init(_a33_obj, 498u);
    _a33_obj->f_name = l36;
    _a33_obj->f_is_main = l16;
    _a33_obj->f_signature = l5;
    _a33_obj->f_locals = l17;
    _a33_obj->f_body = l8;
    _a33_obj->f_debug = l12;
    _a33_obj->f_jump_table = l3;
    t5 = (void*) _a33_obj;
    { void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l5 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_box_bool(161u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5]);
                t1 = t0.payload.b;
                if (t1) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                    l7 = l3;
                    l8 = ((vader_array_t*) l7)->length;
                    l9 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_26: {
                            if ((l9 < l8)) {
                                vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
                                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                                if ((size_t) l9 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
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
                                        vader_obj_header_init(_a3_obj, 621u);
                                        _a3_obj->f_first = l18;
                                        _a3_obj->f_last = l19;
                                        l6 = (void*) _a3_obj;
                                        l4 = true;
                                    } else {
                                    }
                                    l20 = ((vader_struct_vader_bytecode_SlotRange_t*) l6)->f_last;
                                    l21 = ((vader_struct_vader_bytecode_SlotRange_t*) l10)->f_last;
                                    if ((l20 < l21)) {
                                        l22 = ((vader_struct_vader_bytecode_SlotRange_t*) l6)->f_first;
                                        l23 = ((vader_struct_vader_bytecode_SlotRange_t*) l10)->f_last;
                                        vader_struct_vader_bytecode_SlotRange_t* _a4_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                                        vader_obj_header_init(_a4_obj, 621u);
                                        _a4_obj->f_first = l22;
                                        _a4_obj->f_last = l23;
                                        l6 = (void*) _a4_obj;
                                        l4 = true;
                                    } else {
                                    }
                                } else {
                                }
                                t2 = (l9 + INT64_C(1));
                                l9 = (size_t) (int64_t) t2;
                                goto loop_26;
                            } else {
                            }
                        }
                    }
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l0);
                    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                    if ((size_t) l5 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5, l6);
                    VADER_WRITE_BARRIER(_a5_slotarr->buf);
                } else {
                }
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_5;
            } else {
            }
        }
    }
    { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(41u, 0u, 13u, 621u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 163u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 166u);
    l3 = (void*) _a2_arr;
    l4 = (size_t) (int64_t) INT64_C(0);
    l5 = ((vader_array_t*) l0)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_14: {
            if ((l6 < l5)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l0);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
                if (l7.tag == 515u) {
                    l8 = ((int32_t) (size_t) l6);
                    vader_bytecode_push_scope(l2, l3, l4, 1247u, l8);
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                } else {
                    if (l7.tag == 611u) {
                        l9 = ((int32_t) (size_t) l6);
                        vader_bytecode_push_scope(l2, l3, l4, 1805u, l9);
                        t0 = (l4 + INT64_C(1));
                        l4 = (size_t) (int64_t) t0;
                    } else {
                        if (l7.tag == 598u) {
                            l10 = ((int32_t) (size_t) l6);
                            vader_bytecode_push_scope(l2, l3, l4, 1671u, l10);
                            t0 = (l4 + INT64_C(1));
                            l4 = (size_t) (int64_t) t0;
                        } else {
                            if (l7.tag == 542u) {
                                if ((l4 > INT64_C(0))) {
                                    t0 = (l4 - INT64_C(1));
                                    l4 = (size_t) (int64_t) t0;
                                    vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t1 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l4];
                                    t2 = t1.payload.s;
                                    if (t2 == 1805u) {
                                        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                                        if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                                        if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l11 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l4];
                                        l12 = ((int32_t) (size_t) l6);
                                        vader_struct_vader_bytecode_SlotRange_t* _a6_obj = (vader_struct_vader_bytecode_SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_SlotRange_t));
                                        vader_obj_header_init(_a6_obj, 621u);
                                        _a6_obj->f_first = l11;
                                        _a6_obj->f_last = l12;
                                        l13 = (void*) _a6_obj;
                                        vader_array_push((vader_array_t*) l1, vader_ref_box(l13));
                                    } else {
                                    }
                                } else {
                                }
                            } else {
                            }
                        }
                    }
                }
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_14;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t1 = vader_box_bool(161u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4]);
    t2 = t1.payload.b;
    if (t2) {
        return false;
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    if ((size_t) l1 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
    t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
    if (t1.tag == 608u) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
        if ((size_t) l1 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
        t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l1);
        l5 = t1.payload.obj;
        t0 = (l1 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
        if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        if (l6.tag == 610u) {
            t3 = l6.payload.obj;
            l7 = ((vader_struct_vader_bytecode_LocalTee_t*) t3)->f_slot;
            l8 = ((vader_struct_vader_bytecode_LocalGet_t*) l5)->f_slot;
            return l7 == l8;
        }
        if (l6.tag == 609u) {
            t3 = l6.payload.obj;
            l7 = ((vader_struct_vader_bytecode_LocalSet_t*) t3)->f_slot;
            l8 = ((vader_struct_vader_bytecode_LocalGet_t*) l5)->f_slot;
            return l7 == l8;
        }
        return false;
    }
    return false;
}

static vader_string_t vader_bytecode_int_equals_method(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    bool l2;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_strip_core_member(l0, 270u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_types_is_int_name(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        { vader_gc_top = gc_frame.prev; return 1461u; }
    }
    l1 = vader_bytecode_strip_core_member(l0, 271u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_types_is_int_name(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        { vader_gc_top = gc_frame.prev; return 1882u; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_bytecode_intern_type(l0, l1);
    l3 = vader_bytecode_type_intern_key(l0);
    l3 = concat_3(266u, l3, 530u);
    l4 = std_collections_get__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l3);
    if (l4.tag == 166u) {
        t0 = ((int32_t) l4.payload.i);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
    l5 = ((int32_t) (size_t) t1);
    vader_struct_vader_bytecode_BcField_t* _a0_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
    vader_obj_header_init(_a0_obj, 496u);
    _a0_obj->f_name = 2391u;
    _a0_obj->f_type_index = l2;
    l6 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(36u, 0u, 13u, 496u);
    l7 = (void*) _a1_arr;
    vader_array_push((vader_array_t*) l7, vader_ref_box(l6));
    l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
    l8 = vader_bytecode_type_intern_key(l0);
    l8 = concat_2(267u, l8);
    l2 = -(INT32_C(1));
    vader_struct_vader_bytecode_BcStruct_t* _a2_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
    vader_obj_header_init(_a2_obj, 507u);
    _a2_obj->f_name = l8;
    _a2_obj->f_fields = l7;
    _a2_obj->f_c_name = 0u;
    _a2_obj->f_symbol_id = l2;
    l7 = (void*) _a2_obj;
    vader_array_push((vader_array_t*) l6, vader_ref_box(l7));
    std_collections_put__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l3, l5);
    { int32_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

int32_t vader_bytecode_intern_string(vader_string_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int32_t l3;
    int32_t t0;
    size_t t1;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = std_collections_get__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_string_key, l0);
    if (l2.tag == 166u) {
        t0 = ((int32_t) l2.payload.i);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_strings)->length;
    l3 = ((int32_t) (size_t) t1);
    vader_array_push((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_strings, vader_box_string(163u, l0));
    std_collections_put__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_string_key, l0, l3);
    { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

int32_t vader_bytecode_intern_type(vader_box_t l0, void* l1) {
    vader_string_t l2 = 0;
    vader_box_t l3 = vader_box_null();
    int32_t l4;
    void* l5 = NULL;
    size_t l6;
    int32_t t0;
    bool t1;
    vader_string_t t2 = 0;
    size_t t3;
    void* t4 = NULL;
    int64_t t5;
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    void** gc_raw_roots[3] = { &l1, &l5, &t4 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_bytecode_type_intern_key(l0);
    l3 = std_collections_get__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l2);
    if (l3.tag == 166u) {
        t0 = ((int32_t) l3.payload.i);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types_frozen;
    if (t1) {
        t2 = concat_3(1294u, l2, 933u);
        vader_host_std_abort_panic(t2);
    } else {
    }
    t3 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types)->length;
    l4 = ((int32_t) (size_t) t3);
    vader_struct_vader_bytecode_BcRef_t* _a0_obj = (vader_struct_vader_bytecode_BcRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcRef_t));
    vader_obj_header_init(_a0_obj, 504u);
    _a0_obj->f_trait_name = 0u;
    t4 = (void*) _a0_obj;
    l3 = vader_ref_box(t4);
    vader_array_push((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types, l3);
    std_collections_put__string__i32(((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_type_key, l2, l4);
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l1)->f_types;
    t5 = ((int64_t) (int32_t) l4);
    l6 = (size_t) (int64_t) t5;
    l3 = vader_bytecode_bc_type_of_with_ctx(l0, l1, l4);
    vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
    vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6, l3.payload.obj);
    VADER_WRITE_BARRIER(_a1_slotarr->buf);
    { int32_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

uint8_t vader_bytecode_intrinsic_id_for(vader_string_t l0) {
    vader_string_t l1 = 0;
    bool t0;
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_int_equals_method(l0);
    if (l1 == 1461u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(23); }
    }
    if (l1 == 1882u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(24); }
    }
    t0 = vader_bytecode_is_display_to_string(l0);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(25); }
    }
    if (l0 == 2387u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(47); }
    }
    if (l0 == 2388u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(48); }
    }
    if (l0 == 2384u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(49); }
    }
    if (l0 == 2385u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(52); }
    }
    if (l0 == 2386u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(50); }
    }
    if (l0 == 2383u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(51); }
    }
    if (l0 == 2052u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(1); }
    }
    if (l0 == 2053u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(2); }
    }
    if (l0 == 2061u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(3); }
    }
    if (l0 == 2055u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(4); }
    }
    if (l0 == 2056u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(5); }
    }
    if (l0 == 2062u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(6); }
    }
    if (l0 == 2057u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(7); }
    }
    if (l0 == 2058u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(8); }
    }
    if (l0 == 2054u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(9); }
    }
    if (l0 == 2060u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(10); }
    }
    if (l0 == 2050u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(11); }
    }
    if (l0 == 2051u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(12); }
    }
    if (l0 == 2049u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(13); }
    }
    if (l0 == 2059u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(14); }
    }
    if (l0 == 2035u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(15); }
    }
    if (l0 == 2034u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(16); }
    }
    if (l0 == 2036u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(17); }
    }
    if (l0 == 2037u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(18); }
    }
    l1 = vader_bytecode_primitive_member_mangle(2101u, 626u, 1230u);
    if (l0 == l1) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(19); }
    }
    l1 = vader_bytecode_primitive_member_mangle(2101u, 617u, 1616u);
    if (l0 == l1) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(20); }
    }
    if (l0 == 2042u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(21); }
    }
    if (l0 == 2043u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(22); }
    }
    if (l0 == 2070u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(26); }
    }
    if (l0 == 2071u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(27); }
    }
    if (l0 == 2069u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(28); }
    }
    if (l0 == 2068u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(29); }
    }
    if (l0 == 2073u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(30); }
    }
    if (l0 == 2072u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(31); }
    }
    if (l0 == 2074u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(32); }
    }
    if (l0 == 2065u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(33); }
    }
    if (l0 == 2063u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(35); }
    }
    if (l0 == 2064u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(34); }
    }
    if (l0 == 2067u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(36); }
    }
    if (l0 == 2066u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(37); }
    }
    if (l0 == 2078u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(38); }
    }
    if (l0 == 2079u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(43); }
    }
    if (l0 == 2080u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(44); }
    }
    if (l0 == 2077u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(45); }
    }
    if (l0 == 2081u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(46); }
    }
    if (l0 == 2047u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(39); }
    }
    if (l0 == 2076u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(41); }
    }
    if (l0 == 2075u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(42); }
    }
    if (l0 == 2026u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(40); }
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) (int32_t) INT32_C(0); }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_bytecode_intrinsic_op_for_mangled(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_primitive_arith_op(l0);
    if (!(l1.tag == 0u)) {
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2040u) {
        vader_struct_vader_bytecode_I32Eq_t* _a0_obj = (vader_struct_vader_bytecode_I32Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Eq_t));
        vader_obj_header_init(_a0_obj, 565u);
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2041u) {
        vader_struct_vader_bytecode_I64Eq_t* _a1_obj = (vader_struct_vader_bytecode_I64Eq_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Eq_t));
        vader_obj_header_init(_a1_obj, 585u);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_bytecode_primitive_cmp_op(l0);
    if (!(l1.tag == 0u)) {
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2046u) {
        vader_struct_vader_bytecode_BufferNew_t* _a2_obj = (vader_struct_vader_bytecode_BufferNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BufferNew_t));
        vader_obj_header_init(_a2_obj, 525u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2030u) {
        vader_struct_vader_bytecode_LoadU8_t* _a3_obj = (vader_struct_vader_bytecode_LoadU8_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LoadU8_t));
        vader_obj_header_init(_a3_obj, 606u);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2032u) {
        vader_struct_vader_bytecode_StoreU8_t* _a4_obj = (vader_struct_vader_bytecode_StoreU8_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StoreU8_t));
        vader_obj_header_init(_a4_obj, 628u);
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2031u) {
        vader_struct_vader_bytecode_MemoryCopy_t* _a5_obj = (vader_struct_vader_bytecode_MemoryCopy_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_MemoryCopy_t));
        vader_obj_header_init(_a5_obj, 613u);
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2029u) {
        vader_struct_vader_bytecode_BufferToString_t* _a6_obj = (vader_struct_vader_bytecode_BufferToString_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BufferToString_t));
        vader_obj_header_init(_a6_obj, 526u);
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2033u) {
        vader_struct_vader_bytecode_BufferWriteString_t* _a7_obj = (vader_struct_vader_bytecode_BufferWriteString_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BufferWriteString_t));
        vader_obj_header_init(_a7_obj, 527u);
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2039u) {
        vader_struct_vader_bytecode_F64ToBits_t* _a8_obj = (vader_struct_vader_bytecode_F64ToBits_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F64ToBits_t));
        vader_obj_header_init(_a8_obj, 556u);
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2045u) {
        vader_struct_vader_bytecode_BitsToF64_t* _a9_obj = (vader_struct_vader_bytecode_BitsToF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BitsToF64_t));
        vader_obj_header_init(_a9_obj, 514u);
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2038u) {
        vader_struct_vader_bytecode_F32ToBits_t* _a10_obj = (vader_struct_vader_bytecode_F32ToBits_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_F32ToBits_t));
        vader_obj_header_init(_a10_obj, 543u);
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 2044u) {
        vader_struct_vader_bytecode_BitsToF32_t* _a11_obj = (vader_struct_vader_bytecode_BitsToF32_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BitsToF32_t));
        vader_obj_header_init(_a11_obj, 513u);
        t0 = (void*) _a11_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool vader_bytecode_is_64_bit_int_val(uint8_t l0) {
    if (l0 == INT32_C(3)) {
        return true;
    }
    if (l0 == INT32_C(8)) {
        return true;
    }
    if (l0 == INT32_C(4)) {
        return true;
    }
    if (l0 == INT32_C(9)) {
        return true;
    }
    if (l0 == INT32_C(0)) {
        return false;
    }
    if (l0 == INT32_C(1)) {
        return false;
    }
    if (l0 == INT32_C(2)) {
        return false;
    }
    if (l0 == INT32_C(5)) {
        return false;
    }
    if (l0 == INT32_C(6)) {
        return false;
    }
    if (l0 == INT32_C(7)) {
        return false;
    }
    if (l0 == INT32_C(10)) {
        return false;
    }
    if (l0 == INT32_C(11)) {
        return false;
    }
    if (l0 == INT32_C(12)) {
        return false;
    }
    if (l0 == INT32_C(13)) {
        return false;
    }
    if (l0 == INT32_C(14)) {
        return false;
    }
    if (l0 == INT32_C(15)) {
        return false;
    }
    if (l0 == INT32_C(16)) {
        return false;
    }
    if (l0 == INT32_C(17)) {
        return false;
    }
    if (l0 == INT32_C(18)) {
        return false;
    }
    if (l0 == INT32_C(19)) {
        return false;
    }
    vader_unreachable("unreachable return in vader_bytecode$is_64_bit_int_val");
}

static bool vader_bytecode_is_display_to_string(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    bool l2;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_strip_core_member(l0, 268u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_types_is_primitive_name(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        l2 = t0 != 2402u;
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        l2 = t0 != 1883u;
    } else {
        l2 = false;
    }
    { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool vader_bytecode_is_float_val(uint8_t l0) {
    if (l0 == INT32_C(10)) {
        return true;
    }
    if (l0 == INT32_C(11)) {
        return true;
    }
    if (l0 == INT32_C(0)) {
        return false;
    }
    if (l0 == INT32_C(1)) {
        return false;
    }
    if (l0 == INT32_C(2)) {
        return false;
    }
    if (l0 == INT32_C(3)) {
        return false;
    }
    if (l0 == INT32_C(4)) {
        return false;
    }
    if (l0 == INT32_C(5)) {
        return false;
    }
    if (l0 == INT32_C(6)) {
        return false;
    }
    if (l0 == INT32_C(7)) {
        return false;
    }
    if (l0 == INT32_C(8)) {
        return false;
    }
    if (l0 == INT32_C(9)) {
        return false;
    }
    if (l0 == INT32_C(12)) {
        return false;
    }
    if (l0 == INT32_C(13)) {
        return false;
    }
    if (l0 == INT32_C(14)) {
        return false;
    }
    if (l0 == INT32_C(15)) {
        return false;
    }
    if (l0 == INT32_C(16)) {
        return false;
    }
    if (l0 == INT32_C(17)) {
        return false;
    }
    if (l0 == INT32_C(18)) {
        return false;
    }
    if (l0 == INT32_C(19)) {
        return false;
    }
    vader_unreachable("unreachable return in vader_bytecode$is_float_val");
}

bool vader_bytecode_is_integer_val(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return true;
    }
    if (l0 == INT32_C(1)) {
        return true;
    }
    if (l0 == INT32_C(2)) {
        return true;
    }
    if (l0 == INT32_C(3)) {
        return true;
    }
    if (l0 == INT32_C(4)) {
        return true;
    }
    if (l0 == INT32_C(5)) {
        return true;
    }
    if (l0 == INT32_C(6)) {
        return true;
    }
    if (l0 == INT32_C(7)) {
        return true;
    }
    if (l0 == INT32_C(8)) {
        return true;
    }
    if (l0 == INT32_C(9)) {
        return true;
    }
    if (l0 == INT32_C(10)) {
        return false;
    }
    if (l0 == INT32_C(11)) {
        return false;
    }
    if (l0 == INT32_C(12)) {
        return false;
    }
    if (l0 == INT32_C(13)) {
        return false;
    }
    if (l0 == INT32_C(14)) {
        return false;
    }
    if (l0 == INT32_C(15)) {
        return false;
    }
    if (l0 == INT32_C(16)) {
        return false;
    }
    if (l0 == INT32_C(17)) {
        return false;
    }
    if (l0 == INT32_C(18)) {
        return false;
    }
    if (l0 == INT32_C(19)) {
        return false;
    }
    vader_unreachable("unreachable return in vader_bytecode$is_integer_val");
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
    void* l2;
    size_t l3, l4, l5;
    void* t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    bool t4;
    if (l0.tag == 507u) {
        return true;
    }
    if (l0.tag == 494u) {
        return true;
    }
    if (l0.tag == 497u) {
        return true;
    }
    if (l0.tag == 503u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val == INT32_C(15);
    }
    if (l0.tag == 504u) {
        return false;
    }
    if (l0.tag == 508u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_bytecode_BcUnion_t*) t0)->f_variants;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_42: {
                if ((l4 < l3)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
                    t2 = ((int64_t) (int32_t) t1);
                    l5 = (size_t) (int64_t) t2;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                    t4 = vader_bytecode_is_ref_only_element(t3, l1);
                    if (!(t4)) {
                        return false;
                    }
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    goto loop_42;
                } else {
                }
            }
        }
        return true;
    }
    vader_unreachable("unreachable return in vader_bytecode$is_ref_only_element");
}

bool vader_bytecode_is_string_val(uint8_t l0) {
    if (l0 == INT32_C(14)) {
        return true;
    }
    if (l0 == INT32_C(0)) {
        return false;
    }
    if (l0 == INT32_C(1)) {
        return false;
    }
    if (l0 == INT32_C(2)) {
        return false;
    }
    if (l0 == INT32_C(3)) {
        return false;
    }
    if (l0 == INT32_C(4)) {
        return false;
    }
    if (l0 == INT32_C(5)) {
        return false;
    }
    if (l0 == INT32_C(6)) {
        return false;
    }
    if (l0 == INT32_C(7)) {
        return false;
    }
    if (l0 == INT32_C(8)) {
        return false;
    }
    if (l0 == INT32_C(9)) {
        return false;
    }
    if (l0 == INT32_C(10)) {
        return false;
    }
    if (l0 == INT32_C(11)) {
        return false;
    }
    if (l0 == INT32_C(12)) {
        return false;
    }
    if (l0 == INT32_C(13)) {
        return false;
    }
    if (l0 == INT32_C(15)) {
        return false;
    }
    if (l0 == INT32_C(16)) {
        return false;
    }
    if (l0 == INT32_C(17)) {
        return false;
    }
    if (l0 == INT32_C(18)) {
        return false;
    }
    if (l0 == INT32_C(19)) {
        return false;
    }
    vader_unreachable("unreachable return in vader_bytecode$is_string_val");
}

static bool vader_bytecode_is_u32_class(uint8_t l0) {
    if (l0 == INT32_C(5)) {
        return true;
    }
    if (l0 == INT32_C(6)) {
        return true;
    }
    if (l0 == INT32_C(7)) {
        return true;
    }
    if (l0 == INT32_C(0)) {
        return false;
    }
    if (l0 == INT32_C(1)) {
        return false;
    }
    if (l0 == INT32_C(2)) {
        return false;
    }
    if (l0 == INT32_C(3)) {
        return false;
    }
    if (l0 == INT32_C(4)) {
        return false;
    }
    if (l0 == INT32_C(8)) {
        return false;
    }
    if (l0 == INT32_C(9)) {
        return false;
    }
    if (l0 == INT32_C(10)) {
        return false;
    }
    if (l0 == INT32_C(11)) {
        return false;
    }
    if (l0 == INT32_C(12)) {
        return false;
    }
    if (l0 == INT32_C(13)) {
        return false;
    }
    if (l0 == INT32_C(14)) {
        return false;
    }
    if (l0 == INT32_C(15)) {
        return false;
    }
    if (l0 == INT32_C(16)) {
        return false;
    }
    if (l0 == INT32_C(17)) {
        return false;
    }
    if (l0 == INT32_C(18)) {
        return false;
    }
    if (l0 == INT32_C(19)) {
        return false;
    }
    vader_unreachable("unreachable return in vader_bytecode$is_u32_class");
}

static bool vader_bytecode_is_u64_class(uint8_t l0) {
    if (l0 == INT32_C(8)) {
        return true;
    }
    if (l0 == INT32_C(9)) {
        return true;
    }
    if (l0 == INT32_C(0)) {
        return false;
    }
    if (l0 == INT32_C(1)) {
        return false;
    }
    if (l0 == INT32_C(2)) {
        return false;
    }
    if (l0 == INT32_C(3)) {
        return false;
    }
    if (l0 == INT32_C(4)) {
        return false;
    }
    if (l0 == INT32_C(5)) {
        return false;
    }
    if (l0 == INT32_C(6)) {
        return false;
    }
    if (l0 == INT32_C(7)) {
        return false;
    }
    if (l0 == INT32_C(10)) {
        return false;
    }
    if (l0 == INT32_C(11)) {
        return false;
    }
    if (l0 == INT32_C(12)) {
        return false;
    }
    if (l0 == INT32_C(13)) {
        return false;
    }
    if (l0 == INT32_C(14)) {
        return false;
    }
    if (l0 == INT32_C(15)) {
        return false;
    }
    if (l0 == INT32_C(16)) {
        return false;
    }
    if (l0 == INT32_C(17)) {
        return false;
    }
    if (l0 == INT32_C(18)) {
        return false;
    }
    if (l0 == INT32_C(19)) {
        return false;
    }
    vader_unreachable("unreachable return in vader_bytecode$is_u64_class");
}

bool vader_bytecode_is_unsigned_display(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    bool l2, l3;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_strip_core_member(l0, 268u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        if (t0 == 2243u) {
            l2 = true;
        } else {
            t0 = l1.payload.s;
            l2 = t0 == 2252u;
        }
        if (l2) {
            l3 = true;
        } else {
            t0 = l1.payload.s;
            l3 = t0 == 2305u;
        }
        l2 = l3;
    } else {
        l2 = false;
    }
    { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 163u);
    l3 = (void*) _a0_arr;
    l4 = l1;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l6 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
                l8 = vader_bytecode_bc_type_key(l0, l7);
                vader_array_push((vader_array_t*) l3, vader_box_string(163u, l8));
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_9;
            } else {
            }
        }
    }
    t1 = std_string_join(l3, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_bytecode_mark_jump_targets(void* l0, size_t l1) {
    void* l2 = NULL;
    size_t l3, l4, l7;
    int32_t l5;
    bool l6;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(6u, 1u, 12u, 161u);
    ((uint8_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (uint8_t) false;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l1);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
    l3 = ((vader_array_t*) l0)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_11: {
            if ((l4 < l3)) {
                if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
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
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l7 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((uint8_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7] = (uint8_t) true;
                } else {
                }
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_11;
            } else {
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        vader_obj_header_init(_a0_obj, 649u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_u32_class(l0);
    if (t0) {
        vader_struct_vader_bytecode_U32Mod_t* _a1_obj = (vader_struct_vader_bytecode_U32Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_U32Mod_t));
        vader_obj_header_init(_a1_obj, 643u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        vader_struct_vader_bytecode_I64Mod_t* _a2_obj = (vader_struct_vader_bytecode_I64Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Mod_t));
        vader_obj_header_init(_a2_obj, 590u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Mod_t* _a3_obj = (vader_struct_vader_bytecode_I32Mod_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Mod_t));
    vader_obj_header_init(_a3_obj, 570u);
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        vader_obj_header_init(_a0_obj, 554u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_bytecode_is_64_bit_int_val(l0);
    if (t0) {
        vader_struct_vader_bytecode_I64Neg_t* _a1_obj = (vader_struct_vader_bytecode_I64Neg_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Neg_t));
        vader_obj_header_init(_a1_obj, 593u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Neg_t* _a2_obj = (vader_struct_vader_bytecode_I32Neg_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Neg_t));
    vader_obj_header_init(_a2_obj, 573u);
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_bytecode_new_emitter_ctx(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[16] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 16u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(119u, 0u, 13u, 1077u);
    l0 = (void*) _a0_arr;
    vader_struct_vader_bytecode_BcPrimitive_t* _a1_obj = (vader_struct_vader_bytecode_BcPrimitive_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPrimitive_t));
    vader_obj_header_init(_a1_obj, 503u);
    _a1_obj->f_val = (uint8_t) (int32_t) INT32_C(15);
    l1 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l0, vader_ref_box(l1));
    vader_array_t* _a2_arr = vader_array_new(8u, 0u, 0u, 163u);
    l1 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 166u);
    l2 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 166u);
    l3 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a5_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a5_obj, 359u);
    _a5_obj->f_ekeys = l1;
    _a5_obj->f_evals = l2;
    _a5_obj->f_index = l3;
    _a5_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a5_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a5_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a5_obj;
    std_collections_put__string__i32(l1, 1883u, INT32_C(0));
    vader_array_t* _a6_arr = vader_array_new(8u, 0u, 0u, 163u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(8u, 0u, 0u, 163u);
    l3 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 166u);
    l4 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(9u, 0u, 7u, 166u);
    l5 = (void*) _a9_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a10_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a10_obj, 359u);
    _a10_obj->f_ekeys = l3;
    _a10_obj->f_evals = l4;
    _a10_obj->f_index = l5;
    _a10_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a10_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a10_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a10_obj;
    vader_array_t* _a11_arr = vader_array_new(37u, 0u, 13u, 498u);
    l4 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(9u, 0u, 7u, 166u);
    l5 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(9u, 0u, 7u, 166u);
    l6 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(9u, 0u, 7u, 166u);
    l7 = (void*) _a14_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a15_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a15_obj, 310u);
    _a15_obj->f_ekeys = l5;
    _a15_obj->f_evals = l6;
    _a15_obj->f_index = l7;
    _a15_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a15_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a15_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l5 = (void*) _a15_obj;
    vader_array_t* _a16_arr = vader_array_new(8u, 0u, 0u, 163u);
    l6 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(9u, 0u, 7u, 166u);
    l7 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(9u, 0u, 7u, 166u);
    l8 = (void*) _a18_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a19_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a19_obj, 359u);
    _a19_obj->f_ekeys = l6;
    _a19_obj->f_evals = l7;
    _a19_obj->f_index = l8;
    _a19_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a19_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a19_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l6 = (void*) _a19_obj;
    vader_array_t* _a20_arr = vader_array_new(38u, 0u, 13u, 499u);
    l7 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(9u, 0u, 7u, 166u);
    l8 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_new(9u, 0u, 7u, 166u);
    l9 = (void*) _a22_arr;
    vader_array_t* _a23_arr = vader_array_new(9u, 0u, 7u, 166u);
    l10 = (void*) _a23_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a24_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a24_obj, 310u);
    _a24_obj->f_ekeys = l8;
    _a24_obj->f_evals = l9;
    _a24_obj->f_index = l10;
    _a24_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a24_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a24_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l8 = (void*) _a24_obj;
    vader_array_t* _a25_arr = vader_array_new(8u, 0u, 0u, 163u);
    l9 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(9u, 0u, 7u, 166u);
    l10 = (void*) _a26_arr;
    vader_array_t* _a27_arr = vader_array_new(9u, 0u, 7u, 166u);
    l11 = (void*) _a27_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a28_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a28_obj, 359u);
    _a28_obj->f_ekeys = l9;
    _a28_obj->f_evals = l10;
    _a28_obj->f_index = l11;
    _a28_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a28_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a28_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l9 = (void*) _a28_obj;
    vader_array_t* _a29_arr = vader_array_new(35u, 0u, 13u, 495u);
    l10 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(9u, 0u, 7u, 166u);
    l11 = (void*) _a30_arr;
    vader_array_t* _a31_arr = vader_array_new(9u, 0u, 7u, 166u);
    l12 = (void*) _a31_arr;
    vader_array_t* _a32_arr = vader_array_new(15u, 0u, 0u, 173u);
    l13 = (void*) _a32_arr;
    vader_array_t* _a33_arr = vader_array_new(9u, 0u, 7u, 166u);
    l14 = (void*) _a33_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a34_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a34_obj, 284u);
    _a34_obj->f_ekeys = l12;
    _a34_obj->f_evals = l13;
    _a34_obj->f_index = l14;
    _a34_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a34_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a34_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l12 = (void*) _a34_obj;
    vader_struct_vader_bytecode_EmitterCtx_t* _a35_obj = (vader_struct_vader_bytecode_EmitterCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_EmitterCtx_t));
    vader_obj_header_init(_a35_obj, 541u);
    _a35_obj->f_types = l0;
    _a35_obj->f_type_key = l1;
    _a35_obj->f_strings = l2;
    _a35_obj->f_string_key = l3;
    _a35_obj->f_functions = l4;
    _a35_obj->f_function_index_by_symbol_id = l5;
    _a35_obj->f_function_index_by_mangle = l6;
    _a35_obj->f_imports = l7;
    _a35_obj->f_import_index_by_symbol_id = l8;
    _a35_obj->f_import_index_by_mangle = l9;
    _a35_obj->f_exports = l10;
    _a35_obj->f_pinned_types = l11;
    _a35_obj->f_types_frozen = false;
    _a35_obj->f_pinned_types_by_fn = l12;
    t0 = (void*) _a35_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_bytecode_parse_val_type(vader_string_t l0) {
    vader_box_t t0;
    if (l0 == 1667u) {
        t0 = vader_box_i32(169u, INT32_C(0));
        return t0;
    }
    if (l0 == 1622u) {
        t0 = vader_box_i32(169u, INT32_C(1));
        return t0;
    }
    if (l0 == 1623u) {
        t0 = vader_box_i32(169u, INT32_C(2));
        return t0;
    }
    if (l0 == 1645u) {
        t0 = vader_box_i32(169u, INT32_C(3));
        return t0;
    }
    if (l0 == 1741u) {
        t0 = vader_box_i32(169u, INT32_C(4));
        return t0;
    }
    if (l0 == 2261u) {
        t0 = vader_box_i32(169u, INT32_C(5));
        return t0;
    }
    if (l0 == 2242u) {
        t0 = vader_box_i32(169u, INT32_C(6));
        return t0;
    }
    if (l0 == 2243u) {
        t0 = vader_box_i32(169u, INT32_C(7));
        return t0;
    }
    if (l0 == 2252u) {
        t0 = vader_box_i32(169u, INT32_C(8));
        return t0;
    }
    if (l0 == 2305u) {
        t0 = vader_box_i32(169u, INT32_C(9));
        return t0;
    }
    if (l0 == 1516u) {
        t0 = vader_box_i32(169u, INT32_C(10));
        return t0;
    }
    if (l0 == 1519u) {
        t0 = vader_box_i32(169u, INT32_C(11));
        return t0;
    }
    if (l0 == 1248u) {
        t0 = vader_box_i32(169u, INT32_C(12));
        return t0;
    }
    if (l0 == 1339u) {
        t0 = vader_box_i32(169u, INT32_C(13));
        return t0;
    }
    if (l0 == 2101u) {
        t0 = vader_box_i32(169u, INT32_C(14));
        return t0;
    }
    if (l0 == 1883u) {
        t0 = vader_box_i32(169u, INT32_C(15));
        return t0;
    }
    if (l0 == 2402u) {
        t0 = vader_box_i32(169u, INT32_C(16));
        return t0;
    }
    if (l0 == 1914u) {
        t0 = vader_box_i32(169u, INT32_C(17));
        return t0;
    }
    if (l0 == 1936u) {
        t0 = vader_box_i32(169u, INT32_C(18));
        return t0;
    }
    if (l0 == 1172u) {
        t0 = vader_box_i32(169u, INT32_C(19));
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_strip_core_member(l0, 265u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_types_is_numeric_name(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        t1 = vader_bytecode_val_type_of_primitive_name(t0);
        t2 = vader_bytecode_arith_op(t1, 1154u);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_bytecode_strip_core_member(l0, 273u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_types_is_numeric_name(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        t1 = vader_bytecode_val_type_of_primitive_name(t0);
        t2 = vader_bytecode_arith_op(t1, 2133u);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_bytecode_strip_core_member(l0, 272u);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.s;
        l2 = vader_types_is_numeric_name(t0);
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.s;
        t1 = vader_bytecode_val_type_of_primitive_name(t0);
        t2 = vader_bytecode_arith_op(t1, 1859u);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_bytecode_strip_core_member(l0, 269u);
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
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_bytecode_primitive_cmp_op(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    bool l2;
    vader_string_t t0 = 0;
    uint8_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_bytecode_strip_core_member(l0, 270u);
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
    l1 = vader_bytecode_strip_core_member(l0, 271u);
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
    vader_gc_top = gc_frame.prev;
}

vader_string_t vader_bytecode_primitive_member_mangle(vader_string_t l0, vader_string_t l1, vader_string_t l2) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = concat_7(2027u, 264u, l0, 264u, l1, 264u, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_bytecode_propagate_const_single_use(void* l0) {
    size_t l1, l2, l8, l12, l14, l16, l17, l19;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l11 = NULL;
    void* l15 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    int32_t l9, l10, l18, l20, l21;
    vader_box_t l13 = vader_box_null(), l26 = vader_box_null(), l28 = vader_box_null(), l29 = vader_box_null(), l30 = vader_box_null();
    bool l25;
    uint8_t l27;
    vader_string_t l31 = 0;
    int64_t t0;
    void* t1 = NULL;
    int32_t t2;
    bool t3;
    size_t t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l13, &l26, &l28, &l29, &l30, &t5 };
    void** gc_raw_roots[12] = { &l0, &l3, &l4, &l5, &l6, &l7, &l11, &l15, &l22, &l23, &l24, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l31 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    l2 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    t0 = (l1 + l2);
    l2 = (size_t) (int64_t) t0;
    if ((l2 <= l1)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 166u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 166u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 166u);
    l5 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 166u);
    l6 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 166u);
    l7 = (void*) _a4_arr;
    l8 = (size_t) (int64_t) INT64_C(0);
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
            } else {
            }
        }
    }
    l11 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l8 = ((vader_array_t*) l11)->length;
    l12 = (size_t) (int64_t) INT64_C(0);
    {
        loop_72: {
            if ((l12 < l8)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l12 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                l13 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l12);
                if (l13.tag == 609u) {
                    t1 = l13.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_LocalSet_t*) t1)->f_slot;
                    t0 = ((int64_t) (int32_t) t2);
                    l14 = (size_t) (int64_t) t0;
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                    if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                    if ((size_t) l14 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l14];
                    l9 = (t2 + INT32_C(1));
                    if ((size_t) l14 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l14] = (int32_t) l9;
                    l10 = ((int32_t) (size_t) l12);
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l6);
                    if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                    if ((size_t) l14 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l14] = (int32_t) l10;
                } else {
                }
                if (l13.tag == 610u) {
                    l15 = l13.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_LocalTee_t*) l15)->f_slot;
                    t0 = ((int64_t) (int32_t) t2);
                    l16 = (size_t) (int64_t) t0;
                    t2 = ((vader_struct_vader_bytecode_LocalTee_t*) l15)->f_slot;
                    t0 = ((int64_t) (int32_t) t2);
                    l17 = (size_t) (int64_t) t0;
                    vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
                    if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                    if ((size_t) l17 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l17];
                    l18 = (t2 + INT32_C(1));
                    if ((size_t) l16 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l16] = (int32_t) l18;
                } else {
                }
                if (l13.tag == 608u) {
                    t1 = l13.payload.obj;
                    t2 = ((vader_struct_vader_bytecode_LocalGet_t*) t1)->f_slot;
                    t0 = ((int64_t) (int32_t) t2);
                    l19 = (size_t) (int64_t) t0;
                    vader_array_t* _a9_slotarr = ((vader_array_t*) l4);
                    if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                    if ((size_t) l19 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l19];
                    l20 = (t2 + INT32_C(1));
                    if ((size_t) l19 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l19] = (int32_t) l20;
                    l21 = ((int32_t) (size_t) l12);
                    vader_array_t* _a10_slotarr = ((vader_array_t*) l7);
                    if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                    if ((size_t) l19 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l19] = (int32_t) l21;
                } else {
                }
                t0 = (l12 + INT64_C(1));
                l12 = (size_t) (int64_t) t0;
                goto loop_72;
            } else {
            }
        }
    }
    vader_array_t* _a11_arr = vader_array_new(9u, 0u, 7u, 166u);
    l15 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(6u, 0u, 12u, 161u);
    l22 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(9u, 0u, 7u, 166u);
    l23 = (void*) _a13_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a14_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a14_obj, 309u);
    _a14_obj->f_ekeys = l15;
    _a14_obj->f_evals = l22;
    _a14_obj->f_index = l23;
    _a14_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a14_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a14_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l15 = (void*) _a14_obj;
    vader_array_t* _a15_arr = vader_array_new(9u, 0u, 7u, 166u);
    l22 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(15u, 0u, 0u, 173u);
    l23 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(9u, 0u, 7u, 166u);
    l24 = (void*) _a17_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a18_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a18_obj, 282u);
    _a18_obj->f_ekeys = l22;
    _a18_obj->f_evals = l23;
    _a18_obj->f_index = l24;
    _a18_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a18_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a18_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l22 = (void*) _a18_obj;
    l12 = l1;
    {
        loop_202: {
            if ((l12 < l2)) {
                l25 = true;
                vader_array_t* _a19_slotarr = ((vader_array_t*) l5);
                if (_a19_slotarr->buf != NULL && _a19_slotarr->buf->header.forward != NULL) { _a19_slotarr->buf = vader_array_buf_forward(_a19_slotarr->buf); }
                if ((size_t) l12 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a19_slotarr->buf->slots)[_a19_slotarr->offset + (size_t) l12];
                if (t2 != INT32_C(0)) {
                    l25 = false;
                } else {
                }
                vader_array_t* _a20_slotarr = ((vader_array_t*) l3);
                if (_a20_slotarr->buf != NULL && _a20_slotarr->buf->header.forward != NULL) { _a20_slotarr->buf = vader_array_buf_forward(_a20_slotarr->buf); }
                if ((size_t) l12 >= _a20_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l12];
                if (t2 != INT32_C(1)) {
                    l25 = false;
                } else {
                }
                vader_array_t* _a21_slotarr = ((vader_array_t*) l4);
                if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
                if ((size_t) l12 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l12];
                if (t2 != INT32_C(1)) {
                    l25 = false;
                } else {
                }
                l9 = -(INT32_C(1));
                l10 = -(INT32_C(1));
                if (l25) {
                    vader_array_t* _a22_slotarr = ((vader_array_t*) l6);
                    if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                    if ((size_t) l12 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                    l9 = ((int32_t*) _a22_slotarr->buf->slots)[_a22_slotarr->offset + (size_t) l12];
                    vader_array_t* _a23_slotarr = ((vader_array_t*) l7);
                    if (_a23_slotarr->buf != NULL && _a23_slotarr->buf->header.forward != NULL) { _a23_slotarr->buf = vader_array_buf_forward(_a23_slotarr->buf); }
                    if ((size_t) l12 >= _a23_slotarr->length) { vader_trap("array index out of bounds"); }
                    l10 = ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l12];
                    if ((l9 <= INT32_C(0))) {
                        l25 = false;
                    } else {
                    }
                    if ((l10 <= l9)) {
                        l25 = false;
                    } else {
                    }
                } else {
                }
                if (l25) {
                    t0 = ((int64_t) (int32_t) (l9 - INT32_C(1)));
                    l14 = (size_t) (int64_t) t0;
                    vader_array_t* _a24_slotarr = ((vader_array_t*) l11);
                    if (_a24_slotarr->buf != NULL && _a24_slotarr->buf->header.forward != NULL) { _a24_slotarr->buf = vader_array_buf_forward(_a24_slotarr->buf); }
                    if ((size_t) l14 >= _a24_slotarr->length) { vader_trap("array index out of bounds"); }
                    l13 = vader_array_ref_load_box(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l14);
                    l26 = vader_bytecode_const_op_of(l13);
                    if (l26.tag == 0u) {
                    } else {
                        l23 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals;
                        t0 = (l12 - l1);
                        l16 = (size_t) (int64_t) t0;
                        vader_array_t* _a25_slotarr = ((vader_array_t*) l23);
                        if (_a25_slotarr->buf != NULL && _a25_slotarr->buf->header.forward != NULL) { _a25_slotarr->buf = vader_array_buf_forward(_a25_slotarr->buf); }
                        if ((size_t) l16 >= _a25_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l16);
                        l27 = ((vader_struct_vader_bytecode_BcLocal_t*) t1)->f_val;
                        t3 = vader_bytecode_const_fills_slot(l26, l27);
                        if (!(t3)) {
                        } else {
                            l18 = (l9 - INT32_C(1));
                            std_collections_put__i32__bool(l15, l18, true);
                            std_collections_put__i32__bool(l15, l9, true);
                            std_collections_put__i32__Any(l22, l10, l13);
                        }
                    }
                } else {
                }
                t0 = (l12 + INT64_C(1));
                l12 = (size_t) (int64_t) t0;
                goto loop_202;
            } else {
            }
        }
    }
    t4 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l15)->f_size;
    if (t4 == INT64_C(0)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a26_arr = vader_array_new(117u, 0u, 13u, 1070u);
    l3 = (void*) _a26_arr;
    vader_array_t* _a27_arr = vader_array_new(121u, 0u, 13u, 1094u);
    l4 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(9u, 0u, 7u, 166u);
    l5 = (void*) _a28_arr;
    l1 = (size_t) (int64_t) INT64_C(0);
    {
        loop_352: {
            if ((l1 < l8)) {
                l9 = -(INT32_C(1));
                vader_array_push_i32((vader_array_t*) l5, l9);
                t0 = (l1 + INT64_C(1));
                l1 = (size_t) (int64_t) t0;
                goto loop_352;
            } else {
            }
        }
    }
    l1 = (size_t) (int64_t) INT64_C(0);
    {
        loop_375: {
            if ((l1 < l8)) {
                l9 = ((int32_t) (size_t) l1);
                t5 = std_collections_get__i32__bool(l15, l9);
                if (t5.tag == 161u) {
                    t0 = (l1 + INT64_C(1));
                    l1 = (size_t) (int64_t) t0;
                    goto loop_375;
                }
                l10 = ((int32_t) (size_t) l1);
                l13 = std_collections_get__i32__Any(l22, l10);
                if (l13.tag == 0u) {
                    t4 = ((vader_array_t*) l3)->length;
                    l18 = ((int32_t) (size_t) t4);
                    vader_array_t* _a29_slotarr = ((vader_array_t*) l5);
                    if (_a29_slotarr->buf != NULL && _a29_slotarr->buf->header.forward != NULL) { _a29_slotarr->buf = vader_array_buf_forward(_a29_slotarr->buf); }
                    if ((size_t) l1 >= _a29_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l1] = (int32_t) l18;
                    vader_array_t* _a30_slotarr = ((vader_array_t*) l11);
                    if (_a30_slotarr->buf != NULL && _a30_slotarr->buf->header.forward != NULL) { _a30_slotarr->buf = vader_array_buf_forward(_a30_slotarr->buf); }
                    if ((size_t) l1 >= _a30_slotarr->length) { vader_trap("array index out of bounds"); }
                    l26 = vader_array_ref_load_box(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l1);
                    vader_array_push((vader_array_t*) l3, l26);
                    vader_array_t* _a31_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug);
                    if (_a31_slotarr->buf != NULL && _a31_slotarr->buf->header.forward != NULL) { _a31_slotarr->buf = vader_array_buf_forward(_a31_slotarr->buf); }
                    if ((size_t) l1 >= _a31_slotarr->length) { vader_trap("array index out of bounds"); }
                    l28 = vader_array_ref_load_box(_a31_slotarr->buf, _a31_slotarr->offset + (size_t) l1);
                    vader_array_push((vader_array_t*) l4, l28);
                } else {
                    t4 = ((vader_array_t*) l3)->length;
                    l20 = ((int32_t) (size_t) t4);
                    vader_array_t* _a32_slotarr = ((vader_array_t*) l5);
                    if (_a32_slotarr->buf != NULL && _a32_slotarr->buf->header.forward != NULL) { _a32_slotarr->buf = vader_array_buf_forward(_a32_slotarr->buf); }
                    if ((size_t) l1 >= _a32_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) l1] = (int32_t) l20;
                    l29 = l13;
                    vader_array_push((vader_array_t*) l3, l29);
                    vader_array_t* _a33_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug);
                    if (_a33_slotarr->buf != NULL && _a33_slotarr->buf->header.forward != NULL) { _a33_slotarr->buf = vader_array_buf_forward(_a33_slotarr->buf); }
                    if ((size_t) l1 >= _a33_slotarr->length) { vader_trap("array index out of bounds"); }
                    l30 = vader_array_ref_load_box(_a33_slotarr->buf, _a33_slotarr->offset + (size_t) l1);
                    vader_array_push((vader_array_t*) l4, l30);
                }
                t0 = (l1 + INT64_C(1));
                l1 = (size_t) (int64_t) t0;
                goto loop_375;
            } else {
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
    vader_obj_header_init(_a34_obj, 498u);
    _a34_obj->f_name = l31;
    _a34_obj->f_is_main = l25;
    _a34_obj->f_signature = l6;
    _a34_obj->f_locals = l7;
    _a34_obj->f_body = l3;
    _a34_obj->f_debug = l4;
    _a34_obj->f_jump_table = l5;
    t1 = (void*) _a34_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void vader_bytecode_prune_unused_functions(void* l0, void* l1, void* l2) {
    size_t l3, l7, l11, l15, l16, l17, l18;
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
    void* l32 = NULL;
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
    void** gc_raw_roots[17] = { &l0, &l1, &l2, &l4, &l5, &l6, &l13, &l14, &l26, &l27, &l28, &l29, &l30, &l31, &l32, &l33, &t2 };
    vader_struct___Tuple_1276_t _a10_storage = {0};
    vader_struct___Tuple_1277_t _a56_storage = {0};
    vader_struct___Tuple_1278_t _a65_storage = {0};
    void* gc_stack_objs[3] = { (void*) &_a10_storage, (void*) &_a56_storage, (void*) &_a65_storage };
    vader_string_t* gc_atom_roots[3] = { &l9, &l34, &t6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 17u, gc_roots, gc_raw_roots, 3u, gc_stack_objs, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions)->length;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 166u);
    l4 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 161u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 166u);
    l6 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 309u);
    _a3_obj->f_ekeys = l4;
    _a3_obj->f_evals = l5;
    _a3_obj->f_index = l6;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l4 = (void*) _a3_obj;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_20: {
            if ((l7 < l3)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l7 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l7);
                t0 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_is_main;
                if (t0) {
                    l8 = ((int32_t) (size_t) l7);
                    std_collections_put__i32__bool(l4, l8, true);
                } else {
                }
                l9 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_name;
                t0 = std_core____Contains_contains__string(l2, l9);
                if (t0) {
                    l10 = ((int32_t) (size_t) l7);
                    std_collections_put__i32__bool(l4, l10, true);
                } else {
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_20;
            } else {
            }
        }
    }
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_exports;
    l7 = ((vader_array_t*) l5)->length;
    l11 = (size_t) (int64_t) INT64_C(0);
    {
        loop_73: {
            if ((l11 < l7)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                if ((size_t) l11 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l11);
                l8 = ((vader_struct_vader_bytecode_BcExport_t*) t2)->f_fn_index;
                std_collections_put__i32__bool(l4, l8, true);
                t1 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t1;
                goto loop_73;
            } else {
            }
        }
    }
    l5 = l1;
    l7 = ((vader_array_t*) l5)->length;
    l11 = (size_t) (int64_t) INT64_C(0);
    {
        loop_104: {
            if ((l11 < l7)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l11 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l11];
                if ((l8 >= INT32_C(0))) {
                    l10 = ((int32_t) (size_t) l3);
                    l12 = (l8 < l10);
                } else {
                    l12 = false;
                }
                if (l12) {
                    std_collections_put__i32__bool(l4, l8, true);
                } else {
                }
                t1 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t1;
                goto loop_104;
            } else {
            }
        }
    }
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 166u);
    l5 = (void*) _a7_arr;
    l6 = l4;
    l13 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l6)->f_ekeys;
    l14 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l6)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l6)->f_size;
    l11 = (size_t) (int64_t) INT64_C(0);
    {
        loop_158: {
            if ((l11 >= l7)) {
            } else {
                vader_array_t* _a8_slotarr = ((vader_array_t*) l13);
                if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                if ((size_t) l11 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l11];
                vader_array_t* _a9_slotarr = ((vader_array_t*) l14);
                if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                if ((size_t) l11 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_box_bool(161u, ((uint8_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l11]);
                l12 = t3.payload.b;
                vader_struct___Tuple_1276_t* _a11_obj = &_a10_storage;
                vader_obj_header_init(_a11_obj, 224u);
                _a11_obj->f__0 = l8;
                _a11_obj->f__1 = l12;
                t2 = (void*) _a11_obj;
                l10 = ((vader_struct___Tuple_1276_t*) t2)->f__0;
                t1 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t1;
                vader_array_push_i32((vader_array_t*) l5, l10);
                goto loop_158;
            }
        }
    }
    {
        loop_191: {
            t4 = ((vader_array_t*) l5)->length;
            if ((t4 > INT64_C(0))) {
                t4 = ((vader_array_t*) l5)->length;
                t1 = (t4 - INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                vader_array_t* _a12_slotarr = ((vader_array_t*) l5);
                if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                if ((size_t) l7 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l7];
                vader_array_t* _a13_arr = vader_array_new(9u, 0u, 7u, 166u);
                l6 = (void*) _a13_arr;
                t4 = ((vader_array_t*) l5)->length;
                t1 = (t4 - INT64_C(1));
                l11 = (size_t) (int64_t) t1;
                l15 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_216: {
                        if ((l15 < l11)) {
                            vader_array_t* _a14_slotarr = ((vader_array_t*) l5);
                            if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                            if ((size_t) l15 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                            l10 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l15];
                            vader_array_push_i32((vader_array_t*) l6, l10);
                            t1 = (l15 + INT64_C(1));
                            l15 = (size_t) (int64_t) t1;
                            goto loop_216;
                        } else {
                        }
                    }
                }
                l5 = l6;
                if ((((int64_t) (int32_t) l8) >= l3)) {
                    goto loop_191;
                }
                l13 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
                t1 = ((int64_t) (int32_t) l8);
                l16 = (size_t) (int64_t) t1;
                vader_array_t* _a15_slotarr = ((vader_array_t*) l13);
                if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                if ((size_t) l16 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_ref_load_obj(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l16);
                l14 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_body;
                l17 = ((vader_array_t*) l14)->length;
                l18 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_261: {
                        if ((l18 < l17)) {
                            vader_array_t* _a16_slotarr = ((vader_array_t*) l14);
                            if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                            if ((size_t) l18 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                            l19 = vader_array_ref_load_box(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l18);
                            l20 = -(INT32_C(1));
                            if (l19.tag == 529u) {
                                t2 = l19.payload.obj;
                                l20 = ((vader_struct_vader_bytecode_Call_t*) t2)->f_function_index;
                            } else {
                            }
                            if (l19.tag == 557u) {
                                t2 = l19.payload.obj;
                                l20 = ((vader_struct_vader_bytecode_FnRef_t*) t2)->f_function_index;
                            } else {
                            }
                            if (l19.tag == 612u) {
                                t2 = l19.payload.obj;
                                l20 = ((vader_struct_vader_bytecode_MakeClosure_t*) t2)->f_function_index;
                            } else {
                            }
                            if ((l20 < INT32_C(0))) {
                                t1 = (l18 + INT64_C(1));
                                l18 = (size_t) (int64_t) t1;
                                goto loop_261;
                            }
                            t3 = std_collections_get__i32__bool(l4, l20);
                            if (t3.tag == 161u) {
                                t1 = (l18 + INT64_C(1));
                                l18 = (size_t) (int64_t) t1;
                                goto loop_261;
                            }
                            std_collections_put__i32__bool(l4, l20, true);
                            vader_array_push_i32((vader_array_t*) l5, l20);
                            t1 = (l18 + INT64_C(1));
                            l18 = (size_t) (int64_t) t1;
                            goto loop_261;
                        } else {
                        }
                    }
                }
                goto loop_191;
            } else {
            }
        }
    }
    t4 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l4)->f_size;
    l12 = t4 == INT64_C(0);
    vader_array_t* _a17_arr = vader_array_new(8u, 0u, 0u, 163u);
    l5 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(9u, 0u, 7u, 166u);
    l6 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(9u, 0u, 7u, 166u);
    l13 = (void*) _a19_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a20_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a20_obj, 359u);
    _a20_obj->f_ekeys = l5;
    _a20_obj->f_evals = l6;
    _a20_obj->f_index = l13;
    _a20_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a20_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a20_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l5 = (void*) _a20_obj;
    l21 = false;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_369: {
            if ((l7 < l3)) {
                if (l12) {
                    l22 = true;
                } else {
                    l8 = ((int32_t) (size_t) l7);
                    t3 = std_collections_get__i32__bool(l4, l8);
                    l22 = t3.tag == 161u;
                }
                if (l22) {
                    vader_array_t* _a21_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
                    if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
                    if ((size_t) l7 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l7);
                    l9 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_name;
                    if (l9 != 0u) {
                        l19 = std_collections_get__string__i32(l5, l9);
                        if (l19.tag == 166u) {
                            l10 = ((int32_t) l19.payload.i);
                            l21 = true;
                            vader_array_t* _a22_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
                            if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                            if ((size_t) l7 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = vader_array_ref_load_obj(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l7);
                            t4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_body)->length;
                            if ((t4 > INT64_C(0))) {
                                l6 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
                                t1 = ((int64_t) (int32_t) l10);
                                l11 = (size_t) (int64_t) t1;
                                vader_array_t* _a23_slotarr = ((vader_array_t*) l6);
                                if (_a23_slotarr->buf != NULL && _a23_slotarr->buf->header.forward != NULL) { _a23_slotarr->buf = vader_array_buf_forward(_a23_slotarr->buf); }
                                if ((size_t) l11 >= _a23_slotarr->length) { vader_trap("array index out of bounds"); }
                                t2 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l11);
                                t4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_body)->length;
                                l23 = t4 == INT64_C(0);
                            } else {
                                l23 = false;
                            }
                            if (l23) {
                                l20 = ((int32_t) (size_t) l7);
                                std_collections_put__string__i32(l5, l9, l20);
                            } else {
                            }
                        } else {
                            l24 = ((int32_t) (size_t) l7);
                            std_collections_put__string__i32(l5, l9, l24);
                        }
                    } else {
                    }
                } else {
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_369;
            } else {
            }
        }
    }
    if (!(l21)) {
        if (l12) {
            l22 = true;
        } else {
            t4 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l4)->f_size;
            l22 = t4 == l3;
        }
        l21 = l22;
    } else {
        l21 = false;
    }
    if (l21) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a24_arr = vader_array_new(9u, 0u, 7u, 166u);
    l6 = (void*) _a24_arr;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_497: {
            if ((l7 < l3)) {
                vader_array_t* _a25_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
                if (_a25_slotarr->buf != NULL && _a25_slotarr->buf->header.forward != NULL) { _a25_slotarr->buf = vader_array_buf_forward(_a25_slotarr->buf); }
                if ((size_t) l7 >= _a25_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l7);
                l9 = ((vader_struct_vader_bytecode_BcFunction_t*) t2)->f_name;
                l8 = ((int32_t) (size_t) l7);
                if (l9 != 0u) {
                    l19 = std_collections_get__string__i32(l5, l9);
                    if (l19.tag == 166u) {
                        l8 = ((int32_t) l19.payload.i);
                    } else {
                    }
                } else {
                }
                vader_array_push_i32((vader_array_t*) l6, l8);
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_497;
            } else {
            }
        }
    }
    vader_array_t* _a26_arr = vader_array_new(9u, 0u, 7u, 166u);
    l5 = (void*) _a26_arr;
    vader_array_t* _a27_arr = vader_array_new(9u, 0u, 7u, 166u);
    l13 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(9u, 0u, 7u, 166u);
    l14 = (void*) _a28_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a29_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a29_obj, 310u);
    _a29_obj->f_ekeys = l5;
    _a29_obj->f_evals = l13;
    _a29_obj->f_index = l14;
    _a29_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a29_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a29_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l5 = (void*) _a29_obj;
    vader_array_t* _a30_arr = vader_array_new(37u, 0u, 13u, 498u);
    l13 = (void*) _a30_arr;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_559: {
            if ((l7 < l3)) {
                if (l12) {
                    l21 = true;
                } else {
                    l8 = ((int32_t) (size_t) l7);
                    t3 = std_collections_get__i32__bool(l4, l8);
                    l21 = t3.tag == 161u;
                }
                if (l21) {
                    vader_array_t* _a31_slotarr = ((vader_array_t*) l6);
                    if (_a31_slotarr->buf != NULL && _a31_slotarr->buf->header.forward != NULL) { _a31_slotarr->buf = vader_array_buf_forward(_a31_slotarr->buf); }
                    if ((size_t) l7 >= _a31_slotarr->length) { vader_trap("array index out of bounds"); }
                    l10 = ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l7];
                    l20 = ((int32_t) (size_t) l7);
                    l22 = l10 == l20;
                } else {
                    l22 = false;
                }
                if (l22) {
                    l24 = ((int32_t) (size_t) l7);
                    t4 = ((vader_array_t*) l13)->length;
                    l25 = ((int32_t) (size_t) t4);
                    std_collections_put__i32__i32(l5, l24, l25);
                    vader_array_t* _a32_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions);
                    if (_a32_slotarr->buf != NULL && _a32_slotarr->buf->header.forward != NULL) { _a32_slotarr->buf = vader_array_buf_forward(_a32_slotarr->buf); }
                    if ((size_t) l7 >= _a32_slotarr->length) { vader_trap("array index out of bounds"); }
                    l14 = vader_array_ref_load_obj(_a32_slotarr->buf, _a32_slotarr->offset + (size_t) l7);
                    vader_array_push((vader_array_t*) l13, vader_ref_box(l14));
                } else {
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_559;
            } else {
            }
        }
    }
    vader_array_t* _a33_arr = vader_array_new(9u, 0u, 7u, 166u);
    l14 = (void*) _a33_arr;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_631: {
            if ((l7 < l3)) {
                l8 = -(INT32_C(1));
                if (l12) {
                    l21 = true;
                } else {
                    l10 = ((int32_t) (size_t) l7);
                    t3 = std_collections_get__i32__bool(l4, l10);
                    l21 = t3.tag == 161u;
                }
                if (l21) {
                    vader_array_t* _a34_slotarr = ((vader_array_t*) l6);
                    if (_a34_slotarr->buf != NULL && _a34_slotarr->buf->header.forward != NULL) { _a34_slotarr->buf = vader_array_buf_forward(_a34_slotarr->buf); }
                    if ((size_t) l7 >= _a34_slotarr->length) { vader_trap("array index out of bounds"); }
                    l20 = ((int32_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l7];
                    l19 = std_collections_get__i32__i32(l5, l20);
                    if (l19.tag == 166u) {
                        l8 = ((int32_t) l19.payload.i);
                    } else {
                    }
                } else {
                }
                vader_array_push_i32((vader_array_t*) l14, l8);
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_631;
            } else {
            }
        }
    }
    l4 = l13;
    l3 = ((vader_array_t*) l4)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_691: {
            if ((l7 < l3)) {
                vader_array_t* _a35_slotarr = ((vader_array_t*) l4);
                if (_a35_slotarr->buf != NULL && _a35_slotarr->buf->header.forward != NULL) { _a35_slotarr->buf = vader_array_buf_forward(_a35_slotarr->buf); }
                if ((size_t) l7 >= _a35_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a35_slotarr->buf, _a35_slotarr->offset + (size_t) l7);
                l11 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body)->length;
                l15 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_706: {
                        if ((l15 < l11)) {
                            vader_array_t* _a36_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body);
                            if (_a36_slotarr->buf != NULL && _a36_slotarr->buf->header.forward != NULL) { _a36_slotarr->buf = vader_array_buf_forward(_a36_slotarr->buf); }
                            if ((size_t) l15 >= _a36_slotarr->length) { vader_trap("array index out of bounds"); }
                            l19 = vader_array_ref_load_box(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l15);
                            if (l19.tag == 529u) {
                                l6 = l19.payload.obj;
                                l26 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body;
                                t5 = ((vader_struct_vader_bytecode_Call_t*) l6)->f_function_index;
                                t1 = ((int64_t) (int32_t) t5);
                                l16 = (size_t) (int64_t) t1;
                                vader_array_t* _a37_slotarr = ((vader_array_t*) l14);
                                if (_a37_slotarr->buf != NULL && _a37_slotarr->buf->header.forward != NULL) { _a37_slotarr->buf = vader_array_buf_forward(_a37_slotarr->buf); }
                                if ((size_t) l16 >= _a37_slotarr->length) { vader_trap("array index out of bounds"); }
                                t5 = ((int32_t*) _a37_slotarr->buf->slots)[_a37_slotarr->offset + (size_t) l16];
                                vader_struct_vader_bytecode_Call_t* _a38_obj = (vader_struct_vader_bytecode_Call_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Call_t));
                                vader_obj_header_init(_a38_obj, 529u);
                                _a38_obj->f_function_index = t5;
                                l27 = (void*) _a38_obj;
                                vader_array_t* _a39_slotarr = ((vader_array_t*) l26);
                                if (_a39_slotarr->buf != NULL && _a39_slotarr->buf->header.forward != NULL) { _a39_slotarr->buf = vader_array_buf_forward(_a39_slotarr->buf); }
                                if ((size_t) l15 >= _a39_slotarr->length) { vader_trap("array index out of bounds"); }
                                vader_array_ref_store(_a39_slotarr->buf, _a39_slotarr->offset + (size_t) l15, l27);
                                VADER_WRITE_BARRIER(_a39_slotarr->buf);
                            } else {
                            }
                            if (l19.tag == 557u) {
                                l28 = l19.payload.obj;
                                l29 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body;
                                t5 = ((vader_struct_vader_bytecode_FnRef_t*) l28)->f_function_index;
                                t1 = ((int64_t) (int32_t) t5);
                                l17 = (size_t) (int64_t) t1;
                                vader_array_t* _a40_slotarr = ((vader_array_t*) l14);
                                if (_a40_slotarr->buf != NULL && _a40_slotarr->buf->header.forward != NULL) { _a40_slotarr->buf = vader_array_buf_forward(_a40_slotarr->buf); }
                                if ((size_t) l17 >= _a40_slotarr->length) { vader_trap("array index out of bounds"); }
                                l8 = ((int32_t*) _a40_slotarr->buf->slots)[_a40_slotarr->offset + (size_t) l17];
                                l10 = ((vader_struct_vader_bytecode_FnRef_t*) l28)->f_type_id;
                                vader_struct_vader_bytecode_FnRef_t* _a41_obj = (vader_struct_vader_bytecode_FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnRef_t));
                                vader_obj_header_init(_a41_obj, 557u);
                                _a41_obj->f_function_index = l8;
                                _a41_obj->f_type_id = l10;
                                l30 = (void*) _a41_obj;
                                vader_array_t* _a42_slotarr = ((vader_array_t*) l29);
                                if (_a42_slotarr->buf != NULL && _a42_slotarr->buf->header.forward != NULL) { _a42_slotarr->buf = vader_array_buf_forward(_a42_slotarr->buf); }
                                if ((size_t) l15 >= _a42_slotarr->length) { vader_trap("array index out of bounds"); }
                                vader_array_ref_store(_a42_slotarr->buf, _a42_slotarr->offset + (size_t) l15, l30);
                                VADER_WRITE_BARRIER(_a42_slotarr->buf);
                            } else {
                            }
                            if (l19.tag == 612u) {
                                l31 = l19.payload.obj;
                                l32 = ((vader_struct_vader_bytecode_BcFunction_t*) l5)->f_body;
                                t5 = ((vader_struct_vader_bytecode_MakeClosure_t*) l31)->f_function_index;
                                t1 = ((int64_t) (int32_t) t5);
                                l18 = (size_t) (int64_t) t1;
                                vader_array_t* _a43_slotarr = ((vader_array_t*) l14);
                                if (_a43_slotarr->buf != NULL && _a43_slotarr->buf->header.forward != NULL) { _a43_slotarr->buf = vader_array_buf_forward(_a43_slotarr->buf); }
                                if ((size_t) l18 >= _a43_slotarr->length) { vader_trap("array index out of bounds"); }
                                l20 = ((int32_t*) _a43_slotarr->buf->slots)[_a43_slotarr->offset + (size_t) l18];
                                l24 = ((vader_struct_vader_bytecode_MakeClosure_t*) l31)->f_env_type_id;
                                vader_struct_vader_bytecode_MakeClosure_t* _a44_obj = (vader_struct_vader_bytecode_MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_MakeClosure_t));
                                vader_obj_header_init(_a44_obj, 612u);
                                _a44_obj->f_function_index = l20;
                                _a44_obj->f_env_type_id = l24;
                                l33 = (void*) _a44_obj;
                                vader_array_t* _a45_slotarr = ((vader_array_t*) l32);
                                if (_a45_slotarr->buf != NULL && _a45_slotarr->buf->header.forward != NULL) { _a45_slotarr->buf = vader_array_buf_forward(_a45_slotarr->buf); }
                                if ((size_t) l15 >= _a45_slotarr->length) { vader_trap("array index out of bounds"); }
                                vader_array_ref_store(_a45_slotarr->buf, _a45_slotarr->offset + (size_t) l15, l33);
                                VADER_WRITE_BARRIER(_a45_slotarr->buf);
                            } else {
                            }
                            t1 = (l15 + INT64_C(1));
                            l15 = (size_t) (int64_t) t1;
                            goto loop_706;
                        } else {
                        }
                    }
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_691;
            } else {
            }
        }
    }
    vader_array_t* _a46_arr = vader_array_new(35u, 0u, 13u, 495u);
    l4 = (void*) _a46_arr;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_exports;
    l3 = ((vader_array_t*) l5)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_822: {
            if ((l7 < l3)) {
                vader_array_t* _a47_slotarr = ((vader_array_t*) l5);
                if (_a47_slotarr->buf != NULL && _a47_slotarr->buf->header.forward != NULL) { _a47_slotarr->buf = vader_array_buf_forward(_a47_slotarr->buf); }
                if ((size_t) l7 >= _a47_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a47_slotarr->buf, _a47_slotarr->offset + (size_t) l7);
                t5 = ((vader_struct_vader_bytecode_BcExport_t*) l6)->f_fn_index;
                t1 = ((int64_t) (int32_t) t5);
                l11 = (size_t) (int64_t) t1;
                vader_array_t* _a48_slotarr = ((vader_array_t*) l14);
                if (_a48_slotarr->buf != NULL && _a48_slotarr->buf->header.forward != NULL) { _a48_slotarr->buf = vader_array_buf_forward(_a48_slotarr->buf); }
                if ((size_t) l11 >= _a48_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = ((int32_t*) _a48_slotarr->buf->slots)[_a48_slotarr->offset + (size_t) l11];
                if ((l8 >= INT32_C(0))) {
                    t6 = ((vader_struct_vader_bytecode_BcExport_t*) l6)->f_extern_name;
                    vader_struct_vader_bytecode_BcExport_t* _a49_obj = (vader_struct_vader_bytecode_BcExport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcExport_t));
                    vader_obj_header_init(_a49_obj, 495u);
                    _a49_obj->f_extern_name = t6;
                    _a49_obj->f_fn_index = l8;
                    l26 = (void*) _a49_obj;
                    vader_array_push((vader_array_t*) l4, vader_ref_box(l26));
                } else {
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_822;
            } else {
            }
        }
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_exports = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    vader_array_t* _a50_arr = vader_array_new(9u, 0u, 7u, 166u);
    l4 = (void*) _a50_arr;
    vader_array_t* _a51_arr = vader_array_new(9u, 0u, 7u, 166u);
    l5 = (void*) _a51_arr;
    vader_array_t* _a52_arr = vader_array_new(9u, 0u, 7u, 166u);
    l6 = (void*) _a52_arr;
    vader_struct_std_collections_MutableMap__i32__i32_t* _a53_obj = (vader_struct_std_collections_MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i32_t));
    vader_obj_header_init(_a53_obj, 310u);
    _a53_obj->f_ekeys = l4;
    _a53_obj->f_evals = l5;
    _a53_obj->f_index = l6;
    _a53_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a53_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a53_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l4 = (void*) _a53_obj;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_function_index_by_symbol_id;
    l6 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l5)->f_ekeys;
    l26 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l5)->f_evals;
    l3 = ((vader_struct_std_collections_MutableMap__i32__i32_t*) l5)->f_size;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_890: {
            if ((l7 >= l3)) {
            } else {
                vader_array_t* _a54_slotarr = ((vader_array_t*) l6);
                if (_a54_slotarr->buf != NULL && _a54_slotarr->buf->header.forward != NULL) { _a54_slotarr->buf = vader_array_buf_forward(_a54_slotarr->buf); }
                if ((size_t) l7 >= _a54_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = ((int32_t*) _a54_slotarr->buf->slots)[_a54_slotarr->offset + (size_t) l7];
                vader_array_t* _a55_slotarr = ((vader_array_t*) l26);
                if (_a55_slotarr->buf != NULL && _a55_slotarr->buf->header.forward != NULL) { _a55_slotarr->buf = vader_array_buf_forward(_a55_slotarr->buf); }
                if ((size_t) l7 >= _a55_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = ((int32_t*) _a55_slotarr->buf->slots)[_a55_slotarr->offset + (size_t) l7];
                vader_struct___Tuple_1277_t* _a57_obj = &_a56_storage;
                vader_obj_header_init(_a57_obj, 225u);
                _a57_obj->f__0 = l8;
                _a57_obj->f__1 = l10;
                l5 = (void*) _a57_obj;
                l20 = ((vader_struct___Tuple_1277_t*) l5)->f__0;
                l24 = ((vader_struct___Tuple_1277_t*) l5)->f__1;
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                t1 = ((int64_t) (int32_t) l24);
                l11 = (size_t) (int64_t) t1;
                vader_array_t* _a58_slotarr = ((vader_array_t*) l14);
                if (_a58_slotarr->buf != NULL && _a58_slotarr->buf->header.forward != NULL) { _a58_slotarr->buf = vader_array_buf_forward(_a58_slotarr->buf); }
                if ((size_t) l11 >= _a58_slotarr->length) { vader_trap("array index out of bounds"); }
                l25 = ((int32_t*) _a58_slotarr->buf->slots)[_a58_slotarr->offset + (size_t) l11];
                if ((l25 >= INT32_C(0))) {
                    std_collections_put__i32__i32(l4, l20, l25);
                } else {
                }
                goto loop_890;
            }
        }
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_function_index_by_symbol_id = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    vader_array_t* _a59_arr = vader_array_new(8u, 0u, 0u, 163u);
    l4 = (void*) _a59_arr;
    vader_array_t* _a60_arr = vader_array_new(9u, 0u, 7u, 166u);
    l5 = (void*) _a60_arr;
    vader_array_t* _a61_arr = vader_array_new(9u, 0u, 7u, 166u);
    l6 = (void*) _a61_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a62_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a62_obj, 359u);
    _a62_obj->f_ekeys = l4;
    _a62_obj->f_evals = l5;
    _a62_obj->f_index = l6;
    _a62_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a62_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a62_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l4 = (void*) _a62_obj;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_function_index_by_mangle;
    l6 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l5)->f_ekeys;
    l26 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l5)->f_evals;
    l3 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l5)->f_size;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_967: {
            if ((l7 >= l3)) {
            } else {
                vader_array_t* _a63_slotarr = ((vader_array_t*) l6);
                if (_a63_slotarr->buf != NULL && _a63_slotarr->buf->header.forward != NULL) { _a63_slotarr->buf = vader_array_buf_forward(_a63_slotarr->buf); }
                if ((size_t) l7 >= _a63_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = vader_array_box_slots(_a63_slotarr->buf)[_a63_slotarr->offset + (size_t) l7];
                l9 = t3.payload.s;
                vader_array_t* _a64_slotarr = ((vader_array_t*) l26);
                if (_a64_slotarr->buf != NULL && _a64_slotarr->buf->header.forward != NULL) { _a64_slotarr->buf = vader_array_buf_forward(_a64_slotarr->buf); }
                if ((size_t) l7 >= _a64_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = ((int32_t*) _a64_slotarr->buf->slots)[_a64_slotarr->offset + (size_t) l7];
                vader_struct___Tuple_1278_t* _a66_obj = &_a65_storage;
                vader_obj_header_init(_a66_obj, 226u);
                _a66_obj->f__0 = l9;
                _a66_obj->f__1 = l8;
                l5 = (void*) _a66_obj;
                l34 = ((vader_struct___Tuple_1278_t*) l5)->f__0;
                l10 = ((vader_struct___Tuple_1278_t*) l5)->f__1;
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                t1 = ((int64_t) (int32_t) l10);
                l11 = (size_t) (int64_t) t1;
                vader_array_t* _a67_slotarr = ((vader_array_t*) l14);
                if (_a67_slotarr->buf != NULL && _a67_slotarr->buf->header.forward != NULL) { _a67_slotarr->buf = vader_array_buf_forward(_a67_slotarr->buf); }
                if ((size_t) l11 >= _a67_slotarr->length) { vader_trap("array index out of bounds"); }
                l20 = ((int32_t*) _a67_slotarr->buf->slots)[_a67_slotarr->offset + (size_t) l11];
                if ((l20 >= INT32_C(0))) {
                    std_collections_put__string__i32(l4, l34, l20);
                } else {
                }
                goto loop_967;
            }
        }
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_function_index_by_mangle = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    vader_array_t* _a68_arr = vader_array_new(9u, 0u, 7u, 166u);
    l4 = (void*) _a68_arr;
    vader_array_t* _a69_arr = vader_array_new(15u, 0u, 0u, 173u);
    l5 = (void*) _a69_arr;
    vader_array_t* _a70_arr = vader_array_new(9u, 0u, 7u, 166u);
    l6 = (void*) _a70_arr;
    vader_struct_std_collections_MutableMap__i32__Any___t* _a71_obj = (vader_struct_std_collections_MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any___t));
    vader_obj_header_init(_a71_obj, 284u);
    _a71_obj->f_ekeys = l4;
    _a71_obj->f_evals = l5;
    _a71_obj->f_index = l6;
    _a71_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a71_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a71_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l4 = (void*) _a71_obj;
    l5 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_pinned_types_by_fn;
    l6 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l5)->f_ekeys;
    l26 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l5)->f_evals;
    l3 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l5)->f_size;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_1045: {
            if ((l7 >= l3)) {
            } else {
                vader_array_t* _a72_slotarr = ((vader_array_t*) l6);
                if (_a72_slotarr->buf != NULL && _a72_slotarr->buf->header.forward != NULL) { _a72_slotarr->buf = vader_array_buf_forward(_a72_slotarr->buf); }
                if ((size_t) l7 >= _a72_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = ((int32_t*) _a72_slotarr->buf->slots)[_a72_slotarr->offset + (size_t) l7];
                vader_array_t* _a73_slotarr = ((vader_array_t*) l26);
                if (_a73_slotarr->buf != NULL && _a73_slotarr->buf->header.forward != NULL) { _a73_slotarr->buf = vader_array_buf_forward(_a73_slotarr->buf); }
                if ((size_t) l7 >= _a73_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a73_slotarr->buf, _a73_slotarr->offset + (size_t) l7);
                vader_struct___Tuple_1279_t* _a74_obj = (vader_struct___Tuple_1279_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1279_t));
                vader_obj_header_init(_a74_obj, 227u);
                _a74_obj->f__0 = l8;
                _a74_obj->f__1 = l5;
                l27 = (void*) _a74_obj;
                l10 = ((vader_struct___Tuple_1279_t*) l27)->f__0;
                l28 = ((vader_struct___Tuple_1279_t*) l27)->f__1;
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                t1 = ((int64_t) (int32_t) l10);
                l11 = (size_t) (int64_t) t1;
                l15 = ((vader_array_t*) l14)->length;
                if ((l11 >= l15)) {
                    goto loop_1045;
                }
                t1 = ((int64_t) (int32_t) l10);
                l16 = (size_t) (int64_t) t1;
                vader_array_t* _a75_slotarr = ((vader_array_t*) l14);
                if (_a75_slotarr->buf != NULL && _a75_slotarr->buf->header.forward != NULL) { _a75_slotarr->buf = vader_array_buf_forward(_a75_slotarr->buf); }
                if ((size_t) l16 >= _a75_slotarr->length) { vader_trap("array index out of bounds"); }
                l20 = ((int32_t*) _a75_slotarr->buf->slots)[_a75_slotarr->offset + (size_t) l16];
                if ((l20 < INT32_C(0))) {
                    goto loop_1045;
                }
                l19 = std_collections_get__i32__Any(l4, l20);
                if (l19.tag == 9u) {
                    l29 = l19.payload.obj;
                    l30 = l28;
                    l17 = ((vader_array_t*) l30)->length;
                    l18 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_1112: {
                            if ((l18 < l17)) {
                                vader_array_t* _a76_slotarr = ((vader_array_t*) l30);
                                if (_a76_slotarr->buf != NULL && _a76_slotarr->buf->header.forward != NULL) { _a76_slotarr->buf = vader_array_buf_forward(_a76_slotarr->buf); }
                                if ((size_t) l18 >= _a76_slotarr->length) { vader_trap("array index out of bounds"); }
                                l24 = ((int32_t*) _a76_slotarr->buf->slots)[_a76_slotarr->offset + (size_t) l18];
                                vader_array_push_i32((vader_array_t*) l29, l24);
                                t1 = (l18 + INT64_C(1));
                                l18 = (size_t) (int64_t) t1;
                                goto loop_1112;
                            } else {
                            }
                        }
                    }
                } else {
                    std_collections_put__i32__Any(l4, l20, vader_ref_box(l28));
                }
                goto loop_1045;
            }
        }
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_pinned_types_by_fn = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions = l13;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void vader_bytecode_prune_unused_imports(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    size_t l4, l5, l6, l7, l15;
    vader_box_t l8 = vader_box_null();
    int32_t l9, l10, l12;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    size_t t3;
    int32_t t4;
    vader_box_t* gc_roots[2] = { &l8, &t2 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l11, &l13, &l14, &l16, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 166u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 161u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 166u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 309u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_21: {
            if ((l5 < l4)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l5 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                l3 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_body;
                l6 = ((vader_array_t*) l3)->length;
                l7 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_36: {
                        if ((l7 < l6)) {
                            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                            if ((size_t) l7 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                            l8 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
                            if (l8.tag == 530u) {
                                t0 = l8.payload.obj;
                                l9 = ((vader_struct_vader_bytecode_CallImport_t*) t0)->f_index;
                                std_collections_put__i32__bool(l1, l9, true);
                            } else {
                            }
                            t1 = (l7 + INT64_C(1));
                            l7 = (size_t) (int64_t) t1;
                            goto loop_36;
                        } else {
                        }
                    }
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_21;
            } else {
            }
        }
    }
    l4 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) l1)->f_size;
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports)->length;
    if (l4 == l5) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 166u);
    l2 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(38u, 0u, 13u, 499u);
    l3 = (void*) _a7_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_98: {
            if ((l5 < l4)) {
                l9 = ((int32_t) (size_t) l5);
                t2 = std_collections_get__i32__bool(l1, l9);
                if (t2.tag == 161u) {
                    t3 = ((vader_array_t*) l3)->length;
                    l10 = ((int32_t) (size_t) t3);
                    vader_array_push_i32((vader_array_t*) l2, l10);
                    vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports);
                    if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                    if ((size_t) l5 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                    l11 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l5);
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l11));
                } else {
                    l12 = -(INT32_C(1));
                    vader_array_push_i32((vader_array_t*) l2, l12);
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_98;
            } else {
            }
        }
    }
    l1 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l1)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_149: {
            if ((l5 < l4)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l1);
                if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                if ((size_t) l5 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                l11 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l5);
                l6 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l11)->f_body)->length;
                l7 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_164: {
                        if ((l7 < l6)) {
                            vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l11)->f_body);
                            if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                            if ((size_t) l7 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                            l8 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l7);
                            if (l8.tag == 530u) {
                                l13 = l8.payload.obj;
                                l14 = ((vader_struct_vader_bytecode_BcFunction_t*) l11)->f_body;
                                t4 = ((vader_struct_vader_bytecode_CallImport_t*) l13)->f_index;
                                t1 = ((int64_t) (int32_t) t4);
                                l15 = (size_t) (int64_t) t1;
                                vader_array_t* _a11_slotarr = ((vader_array_t*) l2);
                                if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                                if ((size_t) l15 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                                t4 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l15];
                                vader_struct_vader_bytecode_CallImport_t* _a12_obj = (vader_struct_vader_bytecode_CallImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallImport_t));
                                vader_obj_header_init(_a12_obj, 530u);
                                _a12_obj->f_index = t4;
                                l16 = (void*) _a12_obj;
                                vader_array_t* _a13_slotarr = ((vader_array_t*) l14);
                                if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                                if ((size_t) l7 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                                vader_array_ref_store(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l7, l16);
                                VADER_WRITE_BARRIER(_a13_slotarr->buf);
                            } else {
                            }
                            t1 = (l7 + INT64_C(1));
                            l7 = (size_t) (int64_t) t1;
                            goto loop_164;
                        } else {
                        }
                    }
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_149;
            } else {
            }
        }
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports = l3;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void vader_bytecode_prune_unused_types(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    void* l28 = NULL;
    void* l30 = NULL;
    void* l31 = NULL;
    void* l32 = NULL;
    void* l33 = NULL;
    void* l40 = NULL;
    size_t l4, l5, l9, l10, l13, l14, l34, l35;
    int32_t l7, l11, l15, l26, l27, l29, l36, l37, l38, l39;
    vader_box_t l16 = vader_box_null(), l41 = vader_box_null();
    vader_string_t l18 = 0;
    vader_string_t l20 = 0;
    vader_string_t l21 = 0;
    vader_string_t l44 = 0;
    uint8_t l42;
    bool l43;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    int32_t t3;
    bool t4;
    size_t t5;
    vader_box_t* gc_roots[3] = { &l16, &l41, &t2 };
    void** gc_raw_roots[20] = { &l0, &l1, &l2, &l3, &l6, &l8, &l12, &l17, &l19, &l22, &l23, &l24, &l25, &l28, &l30, &l31, &l32, &l33, &l40, &t0 };
    vader_struct___Tuple_1279_t _a14_storage = {0};
    vader_struct___Tuple_1278_t _a40_storage = {0};
    void* gc_stack_objs[2] = { (void*) &_a14_storage, (void*) &_a40_storage };
    vader_string_t* gc_atom_roots[4] = { &l18, &l20, &l21, &l44 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 20u, gc_roots, gc_raw_roots, 2u, gc_stack_objs, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 166u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 161u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 166u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 309u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 376u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    std_collections_add__i32(l1, INT32_C(0));
    vader_array_t* _a5_arr = vader_array_new(9u, 0u, 7u, 166u);
    l2 = (void*) _a5_arr;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_27: {
            if ((l5 < l4)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l5 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
                l7 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_signature)->f_result_type;
                vader_array_push_i32((vader_array_t*) l2, l7);
                l8 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_signature)->f_param_types;
                l9 = ((vader_array_t*) l8)->length;
                l10 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_51: {
                        if ((l10 < l9)) {
                            vader_array_t* _a7_slotarr = ((vader_array_t*) l8);
                            if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                            if ((size_t) l10 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                            l11 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l10];
                            vader_array_push_i32((vader_array_t*) l2, l11);
                            t1 = (l10 + INT64_C(1));
                            l10 = (size_t) (int64_t) t1;
                            goto loop_51;
                        } else {
                        }
                    }
                }
                l12 = ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_body;
                l13 = ((vader_array_t*) l12)->length;
                l14 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_79: {
                        if ((l14 < l13)) {
                            vader_array_t* _a8_slotarr = ((vader_array_t*) l12);
                            if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                            if ((size_t) l14 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l14);
                            l15 = vader_bytecode_type_index_of(t2);
                            if ((l15 >= INT32_C(0))) {
                                vader_array_push_i32((vader_array_t*) l2, l15);
                            } else {
                            }
                            t1 = (l14 + INT64_C(1));
                            l14 = (size_t) (int64_t) t1;
                            goto loop_79;
                        } else {
                        }
                    }
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_27;
            } else {
            }
        }
    }
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_122: {
            if ((l5 < l4)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l3);
                if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                if ((size_t) l5 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l5);
                l7 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_result_type;
                vader_array_push_i32((vader_array_t*) l2, l7);
                l8 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_param_types;
                l9 = ((vader_array_t*) l8)->length;
                l10 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_146: {
                        if ((l10 < l9)) {
                            vader_array_t* _a10_slotarr = ((vader_array_t*) l8);
                            if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                            if ((size_t) l10 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                            l11 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l10];
                            vader_array_push_i32((vader_array_t*) l2, l11);
                            t1 = (l10 + INT64_C(1));
                            l10 = (size_t) (int64_t) t1;
                            goto loop_146;
                        } else {
                        }
                    }
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_122;
            } else {
            }
        }
    }
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_pinned_types;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_183: {
            if ((l5 < l4)) {
                vader_array_t* _a11_slotarr = ((vader_array_t*) l3);
                if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                if ((size_t) l5 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l5];
                vader_array_push_i32((vader_array_t*) l2, l7);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_183;
            } else {
            }
        }
    }
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_pinned_types_by_fn;
    l6 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l3)->f_ekeys;
    l8 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l3)->f_evals;
    l4 = ((vader_struct_std_collections_MutableMap__i32__i32___t*) l3)->f_size;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_216: {
            if ((l5 >= l4)) {
            } else {
                vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
                if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                if ((size_t) l5 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l5];
                vader_array_t* _a13_slotarr = ((vader_array_t*) l8);
                if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                if ((size_t) l5 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                l3 = vader_array_ref_load_obj(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l5);
                vader_struct___Tuple_1279_t* _a15_obj = &_a14_storage;
                vader_obj_header_init(_a15_obj, 227u);
                _a15_obj->f__0 = l7;
                _a15_obj->f__1 = l3;
                t0 = (void*) _a15_obj;
                l12 = ((vader_struct___Tuple_1279_t*) t0)->f__1;
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                l9 = ((vader_array_t*) l12)->length;
                l10 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_245: {
                        if ((l10 < l9)) {
                            vader_array_t* _a16_slotarr = ((vader_array_t*) l12);
                            if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                            if ((size_t) l10 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                            l11 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l10];
                            vader_array_push_i32((vader_array_t*) l2, l11);
                            t1 = (l10 + INT64_C(1));
                            l10 = (size_t) (int64_t) t1;
                            goto loop_245;
                        } else {
                        }
                    }
                }
                goto loop_216;
            }
        }
    }
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_276: {
            if ((l5 < l4)) {
                vader_array_t* _a17_slotarr = ((vader_array_t*) l2);
                if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                if ((size_t) l5 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                t3 = ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l5];
                vader_bytecode_visit_type(t3, l0, l1);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_276;
            } else {
            }
        }
    }
    l4 = ((vader_struct_std_collections_MutableMap__i32__bool_t*) ((vader_struct_std_collections_MutableSet__i32_t*) l1)->f_inner)->f_size;
    l5 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types)->length;
    if (l4 == l5) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types)->length;
    vader_array_t* _a18_arr = vader_array_new(9u, 0u, 7u, 166u);
    l2 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(119u, 0u, 13u, 1077u);
    l3 = (void*) _a19_arr;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_319: {
            if ((l5 < l4)) {
                l6 = ((vader_struct_std_collections_MutableSet__i32_t*) l1)->f_inner;
                l7 = ((int32_t) (size_t) l5);
                t4 = std_collections_contains_key__i32__bool(l6, l7);
                if (t4) {
                    t5 = ((vader_array_t*) l3)->length;
                    l11 = ((int32_t) (size_t) t5);
                    vader_array_push_i32((vader_array_t*) l2, l11);
                    vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types);
                    if (_a20_slotarr->buf != NULL && _a20_slotarr->buf->header.forward != NULL) { _a20_slotarr->buf = vader_array_buf_forward(_a20_slotarr->buf); }
                    if ((size_t) l5 >= _a20_slotarr->length) { vader_trap("array index out of bounds"); }
                    l16 = vader_array_ref_load_box(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l5);
                    vader_array_push((vader_array_t*) l3, l16);
                } else {
                    l15 = -(INT32_C(1));
                    vader_array_push_i32((vader_array_t*) l2, l15);
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_319;
            } else {
            }
        }
    }
    vader_array_t* _a21_arr = vader_array_new(119u, 0u, 13u, 1077u);
    l1 = (void*) _a21_arr;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_372: {
            if ((l5 < l4)) {
                vader_array_t* _a22_slotarr = ((vader_array_t*) l3);
                if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                if ((size_t) l5 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                l16 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l5);
                if (l16.tag == 507u) {
                    l6 = l16.payload.obj;
                    vader_array_t* _a23_arr = vader_array_new(36u, 0u, 13u, 496u);
                    l8 = (void*) _a23_arr;
                    l12 = ((vader_struct_vader_bytecode_BcStruct_t*) l6)->f_fields;
                    l9 = ((vader_array_t*) l12)->length;
                    l10 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_395: {
                            if ((l10 < l9)) {
                                vader_array_t* _a24_slotarr = ((vader_array_t*) l12);
                                if (_a24_slotarr->buf != NULL && _a24_slotarr->buf->header.forward != NULL) { _a24_slotarr->buf = vader_array_buf_forward(_a24_slotarr->buf); }
                                if ((size_t) l10 >= _a24_slotarr->length) { vader_trap("array index out of bounds"); }
                                l17 = vader_array_ref_load_obj(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l10);
                                l18 = ((vader_struct_vader_bytecode_BcField_t*) l17)->f_name;
                                l7 = ((vader_struct_vader_bytecode_BcField_t*) l17)->f_type_index;
                                l11 = vader_bytecode_remap_idx(l2, l7);
                                vader_struct_vader_bytecode_BcField_t* _a25_obj = (vader_struct_vader_bytecode_BcField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcField_t));
                                vader_obj_header_init(_a25_obj, 496u);
                                _a25_obj->f_name = l18;
                                _a25_obj->f_type_index = l11;
                                l19 = (void*) _a25_obj;
                                vader_array_push((vader_array_t*) l8, vader_ref_box(l19));
                                t1 = (l10 + INT64_C(1));
                                l10 = (size_t) (int64_t) t1;
                                goto loop_395;
                            } else {
                            }
                        }
                    }
                    l20 = ((vader_struct_vader_bytecode_BcStruct_t*) l6)->f_name;
                    l21 = ((vader_struct_vader_bytecode_BcStruct_t*) l6)->f_c_name;
                    l15 = ((vader_struct_vader_bytecode_BcStruct_t*) l6)->f_symbol_id;
                    vader_struct_vader_bytecode_BcStruct_t* _a26_obj = (vader_struct_vader_bytecode_BcStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcStruct_t));
                    vader_obj_header_init(_a26_obj, 507u);
                    _a26_obj->f_name = l20;
                    _a26_obj->f_fields = l8;
                    _a26_obj->f_c_name = l21;
                    _a26_obj->f_symbol_id = l15;
                    l22 = (void*) _a26_obj;
                    vader_array_push((vader_array_t*) l1, vader_ref_box(l22));
                } else {
                    if (l16.tag == 508u) {
                        l23 = l16.payload.obj;
                        vader_array_t* _a27_arr = vader_array_new(9u, 0u, 7u, 166u);
                        l24 = (void*) _a27_arr;
                        l25 = ((vader_struct_vader_bytecode_BcUnion_t*) l23)->f_variants;
                        l13 = ((vader_array_t*) l25)->length;
                        l14 = (size_t) (int64_t) INT64_C(0);
                        {
                            loop_464: {
                                if ((l14 < l13)) {
                                    vader_array_t* _a28_slotarr = ((vader_array_t*) l25);
                                    if (_a28_slotarr->buf != NULL && _a28_slotarr->buf->header.forward != NULL) { _a28_slotarr->buf = vader_array_buf_forward(_a28_slotarr->buf); }
                                    if ((size_t) l14 >= _a28_slotarr->length) { vader_trap("array index out of bounds"); }
                                    l26 = ((int32_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l14];
                                    l27 = vader_bytecode_remap_idx(l2, l26);
                                    vader_array_push_i32((vader_array_t*) l24, l27);
                                    t1 = (l14 + INT64_C(1));
                                    l14 = (size_t) (int64_t) t1;
                                    goto loop_464;
                                } else {
                                }
                            }
                        }
                        vader_struct_vader_bytecode_BcUnion_t* _a29_obj = (vader_struct_vader_bytecode_BcUnion_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcUnion_t));
                        vader_obj_header_init(_a29_obj, 508u);
                        _a29_obj->f_variants = l24;
                        l28 = (void*) _a29_obj;
                        vader_array_push((vader_array_t*) l1, vader_ref_box(l28));
                    } else {
                        if (l16.tag == 494u) {
                            t0 = l16.payload.obj;
                            l29 = ((vader_struct_vader_bytecode_BcArray_t*) t0)->f_element;
                            t3 = vader_bytecode_remap_idx(l2, l29);
                            vader_struct_vader_bytecode_BcArray_t* _a30_obj = (vader_struct_vader_bytecode_BcArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcArray_t));
                            vader_obj_header_init(_a30_obj, 494u);
                            _a30_obj->f_element = t3;
                            l30 = (void*) _a30_obj;
                            vader_array_push((vader_array_t*) l1, vader_ref_box(l30));
                        } else {
                            if (l16.tag == 497u) {
                                l31 = l16.payload.obj;
                                vader_array_t* _a31_arr = vader_array_new(9u, 0u, 7u, 166u);
                                l32 = (void*) _a31_arr;
                                l33 = ((vader_struct_vader_bytecode_BcFn_t*) l31)->f_params;
                                l34 = ((vader_array_t*) l33)->length;
                                l35 = (size_t) (int64_t) INT64_C(0);
                                {
                                    loop_528: {
                                        if ((l35 < l34)) {
                                            vader_array_t* _a32_slotarr = ((vader_array_t*) l33);
                                            if (_a32_slotarr->buf != NULL && _a32_slotarr->buf->header.forward != NULL) { _a32_slotarr->buf = vader_array_buf_forward(_a32_slotarr->buf); }
                                            if ((size_t) l35 >= _a32_slotarr->length) { vader_trap("array index out of bounds"); }
                                            l36 = ((int32_t*) _a32_slotarr->buf->slots)[_a32_slotarr->offset + (size_t) l35];
                                            l37 = vader_bytecode_remap_idx(l2, l36);
                                            vader_array_push_i32((vader_array_t*) l32, l37);
                                            t1 = (l35 + INT64_C(1));
                                            l35 = (size_t) (int64_t) t1;
                                            goto loop_528;
                                        } else {
                                        }
                                    }
                                }
                                l38 = ((vader_struct_vader_bytecode_BcFn_t*) l31)->f_return_type;
                                l39 = vader_bytecode_remap_idx(l2, l38);
                                vader_struct_vader_bytecode_BcFn_t* _a33_obj = (vader_struct_vader_bytecode_BcFn_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcFn_t));
                                vader_obj_header_init(_a33_obj, 497u);
                                _a33_obj->f_params = l32;
                                _a33_obj->f_return_type = l39;
                                l40 = (void*) _a33_obj;
                                vader_array_push((vader_array_t*) l1, vader_ref_box(l40));
                            } else {
                                l41 = l16;
                                vader_array_push((vader_array_t*) l1, l41);
                            }
                        }
                    }
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_372;
            } else {
            }
        }
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_types = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    vader_array_t* _a34_arr = vader_array_new(8u, 0u, 0u, 163u);
    l1 = (void*) _a34_arr;
    vader_array_t* _a35_arr = vader_array_new(9u, 0u, 7u, 166u);
    l3 = (void*) _a35_arr;
    vader_array_t* _a36_arr = vader_array_new(9u, 0u, 7u, 166u);
    l6 = (void*) _a36_arr;
    vader_struct_std_collections_MutableMap__string__i32_t* _a37_obj = (vader_struct_std_collections_MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__i32_t));
    vader_obj_header_init(_a37_obj, 359u);
    _a37_obj->f_ekeys = l1;
    _a37_obj->f_evals = l3;
    _a37_obj->f_index = l6;
    _a37_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a37_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a37_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a37_obj;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_key;
    l6 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l3)->f_ekeys;
    l8 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l3)->f_evals;
    l4 = ((vader_struct_std_collections_MutableMap__string__i32_t*) l3)->f_size;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_615: {
            if ((l5 >= l4)) {
            } else {
                vader_array_t* _a38_slotarr = ((vader_array_t*) l6);
                if (_a38_slotarr->buf != NULL && _a38_slotarr->buf->header.forward != NULL) { _a38_slotarr->buf = vader_array_buf_forward(_a38_slotarr->buf); }
                if ((size_t) l5 >= _a38_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_box_slots(_a38_slotarr->buf)[_a38_slotarr->offset + (size_t) l5];
                l18 = t2.payload.s;
                vader_array_t* _a39_slotarr = ((vader_array_t*) l8);
                if (_a39_slotarr->buf != NULL && _a39_slotarr->buf->header.forward != NULL) { _a39_slotarr->buf = vader_array_buf_forward(_a39_slotarr->buf); }
                if ((size_t) l5 >= _a39_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = ((int32_t*) _a39_slotarr->buf->slots)[_a39_slotarr->offset + (size_t) l5];
                vader_struct___Tuple_1278_t* _a41_obj = &_a40_storage;
                vader_obj_header_init(_a41_obj, 226u);
                _a41_obj->f__0 = l18;
                _a41_obj->f__1 = l7;
                l3 = (void*) _a41_obj;
                l20 = ((vader_struct___Tuple_1278_t*) l3)->f__0;
                l11 = ((vader_struct___Tuple_1278_t*) l3)->f__1;
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                l15 = vader_bytecode_remap_idx(l2, l11);
                if ((l15 >= INT32_C(0))) {
                    std_collections_put__string__i32(l1, l20, l15);
                } else {
                }
                goto loop_615;
            }
        }
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_type_key = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    l1 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l1)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_671: {
            if ((l5 < l4)) {
                vader_array_t* _a42_slotarr = ((vader_array_t*) l1);
                if (_a42_slotarr->buf != NULL && _a42_slotarr->buf->header.forward != NULL) { _a42_slotarr->buf = vader_array_buf_forward(_a42_slotarr->buf); }
                if ((size_t) l5 >= _a42_slotarr->length) { vader_trap("array index out of bounds"); }
                l3 = vader_array_ref_load_obj(_a42_slotarr->buf, _a42_slotarr->offset + (size_t) l5);
                vader_array_t* _a43_arr = vader_array_new(9u, 0u, 7u, 166u);
                l6 = (void*) _a43_arr;
                l8 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature)->f_param_types;
                l9 = ((vader_array_t*) l8)->length;
                l10 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_690: {
                        if ((l10 < l9)) {
                            vader_array_t* _a44_slotarr = ((vader_array_t*) l8);
                            if (_a44_slotarr->buf != NULL && _a44_slotarr->buf->header.forward != NULL) { _a44_slotarr->buf = vader_array_buf_forward(_a44_slotarr->buf); }
                            if ((size_t) l10 >= _a44_slotarr->length) { vader_trap("array index out of bounds"); }
                            l7 = ((int32_t*) _a44_slotarr->buf->slots)[_a44_slotarr->offset + (size_t) l10];
                            l11 = vader_bytecode_remap_idx(l2, l7);
                            vader_array_push_i32((vader_array_t*) l6, l11);
                            t1 = (l10 + INT64_C(1));
                            l10 = (size_t) (int64_t) t1;
                            goto loop_690;
                        } else {
                        }
                    }
                }
                l12 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature)->f_params;
                l42 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature)->f_result;
                l15 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature)->f_result_type;
                l26 = vader_bytecode_remap_idx(l2, l15);
                l17 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature)->f_param_names;
                l19 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature)->f_param_mutable;
                l22 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature)->f_param_by_address;
                vader_struct_vader_bytecode_BcSignature_t* _a45_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
                vader_obj_header_init(_a45_obj, 505u);
                _a45_obj->f_params = l12;
                _a45_obj->f_result = l42;
                _a45_obj->f_param_types = l6;
                _a45_obj->f_result_type = l26;
                _a45_obj->f_param_names = l17;
                _a45_obj->f_param_mutable = l19;
                _a45_obj->f_param_by_address = l22;
                l23 = (void*) _a45_obj;
                ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_signature = l23;
                VADER_WRITE_BARRIER((vader_struct_vader_bytecode_BcFunction_t*) l3);
                l13 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_body)->length;
                l14 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_756: {
                        if ((l14 < l13)) {
                            l24 = ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_body;
                            vader_array_t* _a46_slotarr = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l3)->f_body);
                            if (_a46_slotarr->buf != NULL && _a46_slotarr->buf->header.forward != NULL) { _a46_slotarr->buf = vader_array_buf_forward(_a46_slotarr->buf); }
                            if ((size_t) l14 >= _a46_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = vader_array_ref_load_box(_a46_slotarr->buf, _a46_slotarr->offset + (size_t) l14);
                            l16 = vader_bytecode_remap_type_in_op(t2, l2);
                            vader_array_t* _a47_slotarr = ((vader_array_t*) l24);
                            if (_a47_slotarr->buf != NULL && _a47_slotarr->buf->header.forward != NULL) { _a47_slotarr->buf = vader_array_buf_forward(_a47_slotarr->buf); }
                            if ((size_t) l14 >= _a47_slotarr->length) { vader_trap("array index out of bounds"); }
                            vader_array_ref_store(_a47_slotarr->buf, _a47_slotarr->offset + (size_t) l14, l16.payload.obj);
                            VADER_WRITE_BARRIER(_a47_slotarr->buf);
                            t1 = (l14 + INT64_C(1));
                            l14 = (size_t) (int64_t) t1;
                            goto loop_756;
                        } else {
                        }
                    }
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_671;
            } else {
            }
        }
    }
    vader_array_t* _a48_arr = vader_array_new(38u, 0u, 13u, 499u);
    l1 = (void*) _a48_arr;
    l3 = ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_800: {
            if ((l5 < l4)) {
                vader_array_t* _a49_slotarr = ((vader_array_t*) l3);
                if (_a49_slotarr->buf != NULL && _a49_slotarr->buf->header.forward != NULL) { _a49_slotarr->buf = vader_array_buf_forward(_a49_slotarr->buf); }
                if ((size_t) l5 >= _a49_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a49_slotarr->buf, _a49_slotarr->offset + (size_t) l5);
                vader_array_t* _a50_arr = vader_array_new(9u, 0u, 7u, 166u);
                l8 = (void*) _a50_arr;
                l12 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_param_types;
                l9 = ((vader_array_t*) l12)->length;
                l10 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_819: {
                        if ((l10 < l9)) {
                            vader_array_t* _a51_slotarr = ((vader_array_t*) l12);
                            if (_a51_slotarr->buf != NULL && _a51_slotarr->buf->header.forward != NULL) { _a51_slotarr->buf = vader_array_buf_forward(_a51_slotarr->buf); }
                            if ((size_t) l10 >= _a51_slotarr->length) { vader_trap("array index out of bounds"); }
                            l7 = ((int32_t*) _a51_slotarr->buf->slots)[_a51_slotarr->offset + (size_t) l10];
                            l11 = vader_bytecode_remap_idx(l2, l7);
                            vader_array_push_i32((vader_array_t*) l8, l11);
                            t1 = (l10 + INT64_C(1));
                            l10 = (size_t) (int64_t) t1;
                            goto loop_819;
                        } else {
                        }
                    }
                }
                l18 = ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_extern_name;
                l20 = ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_mangled_name;
                l17 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_params;
                l42 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_result;
                l15 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_result_type;
                l26 = vader_bytecode_remap_idx(l2, l15);
                l19 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_param_names;
                l22 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_param_mutable;
                l23 = ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_signature)->f_param_by_address;
                vader_struct_vader_bytecode_BcSignature_t* _a52_obj = (vader_struct_vader_bytecode_BcSignature_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcSignature_t));
                vader_obj_header_init(_a52_obj, 505u);
                _a52_obj->f_params = l17;
                _a52_obj->f_result = l42;
                _a52_obj->f_param_types = l8;
                _a52_obj->f_result_type = l26;
                _a52_obj->f_param_names = l19;
                _a52_obj->f_param_mutable = l22;
                _a52_obj->f_param_by_address = l23;
                l24 = (void*) _a52_obj;
                l43 = ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_is_extern;
                l21 = ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_c_header;
                l44 = ((vader_struct_vader_bytecode_BcImport_t*) l6)->f_c_library;
                vader_struct_vader_bytecode_BcImport_t* _a53_obj = (vader_struct_vader_bytecode_BcImport_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcImport_t));
                vader_obj_header_init(_a53_obj, 499u);
                _a53_obj->f_extern_name = l18;
                _a53_obj->f_mangled_name = l20;
                _a53_obj->f_signature = l24;
                _a53_obj->f_is_extern = l43;
                _a53_obj->f_c_header = l21;
                _a53_obj->f_c_library = l44;
                l25 = (void*) _a53_obj;
                vader_array_push((vader_array_t*) l1, vader_ref_box(l25));
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_800;
            } else {
            }
        }
    }
    ((vader_struct_vader_bytecode_EmitterCtx_t*) l0)->f_imports = l1;
    VADER_WRITE_BARRIER((vader_struct_vader_bytecode_EmitterCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l1 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_ref_store(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1, l2.payload.obj);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_bytecode_push_scope(void* l0, void* l1, size_t l2, vader_string_t l3, int32_t l4) {
    size_t l5;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l5 = ((vader_array_t*) l0)->length;
    if (l2 == l5) {
        vader_array_push((vader_array_t*) l0, vader_box_string(163u, l3));
        vader_array_push_i32((vader_array_t*) l1, l4);
    } else {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l2] = vader_box_string(163u, l3);
        VADER_WRITE_BARRIER(_a0_slotarr->buf);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) l2 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l2] = (int32_t) l4;
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
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
    vader_array_t* _a0_arr = vader_array_new(121u, 1u, 13u, 1094u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = vader_box_obj(0u, NULL).payload.obj;
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l2);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
    l4 = ((vader_array_t*) l0)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_11: {
            if ((l5 < l4)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l5 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
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
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l7 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l7);
                    l8 = t2.tag == 0u;
                } else {
                    l8 = false;
                }
                if (l8) {
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l0);
                    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                    if ((size_t) l5 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                    l9 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                    if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                    if ((size_t) l7 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                    vader_array_ref_store(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l7, l9.payload.obj);
                    VADER_WRITE_BARRIER(_a6_slotarr->buf);
                } else {
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_11;
            } else {
            }
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    return t1;
}

static void* vader_bytecode_remap_jump_table(void* l0, void* l1, size_t l2) {
    void* l3 = NULL;
    size_t l4, l6, l7, l8, l11, l12, l14;
    int32_t l5, l9, l10, l13;
    int64_t t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 166u);
    l3 = (void*) _a0_arr;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l4 < l2)) {
                l5 = -(INT32_C(1));
                vader_array_push_i32((vader_array_t*) l3, l5);
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    l4 = ((vader_array_t*) l0)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_31: {
            if ((l6 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
                if ((l5 < INT32_C(0))) {
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_31;
                }
                t0 = ((int64_t) (int32_t) l5);
                l7 = (size_t) (int64_t) t0;
                l8 = ((vader_array_t*) l1)->length;
                if ((l7 >= l8)) {
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_31;
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l6];
                if ((l9 < INT32_C(0))) {
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_31;
                }
                l10 = -(INT32_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                l11 = ((vader_array_t*) l1)->length;
                t0 = ((int64_t) (int32_t) l5);
                l12 = (size_t) (int64_t) t0;
                {
                    loop_88: {
                        if ((l12 < l11)) {
                            if ((size_t) l12 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                            l13 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l12];
                            if ((l13 >= INT32_C(0))) {
                                l10 = l13;
                            } else {
                                t0 = (l12 + INT64_C(1));
                                l12 = (size_t) (int64_t) t0;
                                goto loop_88;
                            }
                        } else {
                        }
                    }
                }
                if ((l10 < INT32_C(0))) {
                    l10 = ((int32_t) (size_t) l2);
                } else {
                }
                if ((((int64_t) (int32_t) l9) < l2)) {
                    t0 = ((int64_t) (int32_t) l9);
                    l14 = (size_t) (int64_t) t0;
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l14 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l14] = (int32_t) l10;
                } else {
                }
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_31;
            } else {
            }
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_bytecode_remap_type_in_op(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int32_t l3, l5, l6;
    bool l4;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 634u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_StructNew_t*) l2)->f_type_id;
        l3 = vader_bytecode_remap_idx(l1, l3);
        l4 = ((vader_struct_vader_bytecode_StructNew_t*) l2)->f_stack;
        vader_struct_vader_bytecode_StructNew_t* _a0_obj = (vader_struct_vader_bytecode_StructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructNew_t));
        vader_obj_header_init(_a0_obj, 634u);
        _a0_obj->f_type_id = l3;
        _a0_obj->f_stack = l4;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 633u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_StructGet_t*) l2)->f_type_id;
        l3 = vader_bytecode_remap_idx(l1, l3);
        l5 = ((vader_struct_vader_bytecode_StructGet_t*) l2)->f_field_index;
        vader_struct_vader_bytecode_StructGet_t* _a1_obj = (vader_struct_vader_bytecode_StructGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructGet_t));
        vader_obj_header_init(_a1_obj, 633u);
        _a1_obj->f_type_id = l3;
        _a1_obj->f_field_index = l5;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 635u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_StructSet_t*) l2)->f_type_id;
        l3 = vader_bytecode_remap_idx(l1, l3);
        l5 = ((vader_struct_vader_bytecode_StructSet_t*) l2)->f_field_index;
        l4 = ((vader_struct_vader_bytecode_StructSet_t*) l2)->f_stack;
        vader_struct_vader_bytecode_StructSet_t* _a2_obj = (vader_struct_vader_bytecode_StructSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StructSet_t));
        vader_obj_header_init(_a2_obj, 635u);
        _a2_obj->f_type_id = l3;
        _a2_obj->f_field_index = l5;
        _a2_obj->f_stack = l4;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 486u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_ArrayNew_t*) l2)->f_type_id;
        l3 = vader_bytecode_remap_idx(l1, l3);
        l5 = ((vader_struct_vader_bytecode_ArrayNew_t*) l2)->f_length;
        vader_struct_vader_bytecode_ArrayNew_t* _a3_obj = (vader_struct_vader_bytecode_ArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayNew_t));
        vader_obj_header_init(_a3_obj, 486u);
        _a3_obj->f_type_id = l3;
        _a3_obj->f_length = l5;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 484u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_ArrayGet_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l3);
        vader_struct_vader_bytecode_ArrayGet_t* _a4_obj = (vader_struct_vader_bytecode_ArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayGet_t));
        vader_obj_header_init(_a4_obj, 484u);
        _a4_obj->f_type_id = t1;
        _a4_obj->f_bounds_safe = false;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 491u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_ArraySet_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l3);
        vader_struct_vader_bytecode_ArraySet_t* _a5_obj = (vader_struct_vader_bytecode_ArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArraySet_t));
        vader_obj_header_init(_a5_obj, 491u);
        _a5_obj->f_type_id = t1;
        _a5_obj->f_bounds_safe = false;
        t0 = (void*) _a5_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 487u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l3);
        vader_struct_vader_bytecode_ArrayPush_t* _a6_obj = (vader_struct_vader_bytecode_ArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArrayPush_t));
        vader_obj_header_init(_a6_obj, 487u);
        _a6_obj->f_type_id = t1;
        t0 = (void*) _a6_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 636u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_TypeCheck_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l3);
        vader_struct_vader_bytecode_TypeCheck_t* _a7_obj = (vader_struct_vader_bytecode_TypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_TypeCheck_t));
        vader_obj_header_init(_a7_obj, 636u);
        _a7_obj->f_type_id = t1;
        t0 = (void*) _a7_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 637u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_TypeConst_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l3);
        vader_struct_vader_bytecode_TypeConst_t* _a8_obj = (vader_struct_vader_bytecode_TypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_TypeConst_t));
        vader_obj_header_init(_a8_obj, 637u);
        _a8_obj->f_type_id = t1;
        t0 = (void*) _a8_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 531u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_CallIndirect_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l3);
        vader_struct_vader_bytecode_CallIndirect_t* _a9_obj = (vader_struct_vader_bytecode_CallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_CallIndirect_t));
        vader_obj_header_init(_a9_obj, 531u);
        _a9_obj->f_type_id = t1;
        t0 = (void*) _a9_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 612u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_MakeClosure_t*) l2)->f_function_index;
        l5 = ((vader_struct_vader_bytecode_MakeClosure_t*) l2)->f_env_type_id;
        l5 = vader_bytecode_remap_idx(l1, l5);
        vader_struct_vader_bytecode_MakeClosure_t* _a10_obj = (vader_struct_vader_bytecode_MakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_MakeClosure_t));
        vader_obj_header_init(_a10_obj, 612u);
        _a10_obj->f_function_index = l3;
        _a10_obj->f_env_type_id = l5;
        t0 = (void*) _a10_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 557u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_FnRef_t*) l2)->f_function_index;
        l5 = ((vader_struct_vader_bytecode_FnRef_t*) l2)->f_type_id;
        l5 = vader_bytecode_remap_idx(l1, l5);
        vader_struct_vader_bytecode_FnRef_t* _a11_obj = (vader_struct_vader_bytecode_FnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_FnRef_t));
        vader_obj_header_init(_a11_obj, 557u);
        _a11_obj->f_function_index = l3;
        _a11_obj->f_type_id = l5;
        t0 = (void*) _a11_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 607u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_LocalField_t*) l2)->f_slot;
        l5 = ((vader_struct_vader_bytecode_LocalField_t*) l2)->f_type_id;
        l5 = vader_bytecode_remap_idx(l1, l5);
        l6 = ((vader_struct_vader_bytecode_LocalField_t*) l2)->f_field_index;
        vader_struct_vader_bytecode_LocalField_t* _a12_obj = (vader_struct_vader_bytecode_LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalField_t));
        vader_obj_header_init(_a12_obj, 607u);
        _a12_obj->f_slot = l3;
        _a12_obj->f_type_id = l5;
        _a12_obj->f_field_index = l6;
        t0 = (void*) _a12_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 492u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_ArraySlice_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l3);
        vader_struct_vader_bytecode_ArraySlice_t* _a13_obj = (vader_struct_vader_bytecode_ArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ArraySlice_t));
        vader_obj_header_init(_a13_obj, 492u);
        _a13_obj->f_type_id = t1;
        t0 = (void*) _a13_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 615u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_RefCast_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l3);
        vader_struct_vader_bytecode_RefCast_t* _a14_obj = (vader_struct_vader_bytecode_RefCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_RefCast_t));
        vader_obj_header_init(_a14_obj, 615u);
        _a14_obj->f_type_id = t1;
        t0 = (void*) _a14_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 522u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_Box_t*) t0)->f_type_id;
        t1 = vader_bytecode_remap_idx(l1, l3);
        vader_struct_vader_bytecode_Box_t* _a15_obj = (vader_struct_vader_bytecode_Box_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_Box_t));
        vader_obj_header_init(_a15_obj, 522u);
        _a15_obj->f_type_id = t1;
        t0 = (void*) _a15_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 534u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_DataConst_t*) l2)->f_pool_index;
        l5 = ((vader_struct_vader_bytecode_DataConst_t*) l2)->f_type_id;
        l5 = vader_bytecode_remap_idx(l1, l5);
        vader_struct_vader_bytecode_DataConst_t* _a16_obj = (vader_struct_vader_bytecode_DataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_DataConst_t));
        vader_obj_header_init(_a16_obj, 534u);
        _a16_obj->f_pool_index = l3;
        _a16_obj->f_type_id = l5;
        t0 = (void*) _a16_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    vader_array_t* _a0_arr = vader_array_new(117u, 0u, 13u, 1070u);
    l3 = (void*) _a0_arr;
    l4 = (size_t) (int64_t) INT64_C(0);
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 166u);
    l5 = (void*) _a1_arr;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_13: {
            if ((l6 < l2)) {
                l7 = -(INT32_C(1));
                vader_array_push_i32((vader_array_t*) l5, l7);
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_13;
            } else {
            }
        }
    }
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_36: {
            if ((l6 < l2)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
                l9 = vader_bytecode_try_fold_arith(l8, l3, l4);
                if (l9.tag == 0u) {
                    vader_bytecode_push_or_assign(l3, l4, l8);
                    l7 = ((int32_t) (size_t) l4);
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
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
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l6 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l6] = (int32_t) l11;
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                }
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_36;
            } else {
            }
        }
    }
    vader_array_t* _a5_arr = vader_array_slice((vader_array_t*) l3, (size_t) INT64_C(0), (size_t) l4);
    l1 = (void*) _a5_arr;
    l3 = vader_bytecode_remap_jump_table(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l5, l4);
    l5 = vader_bytecode_remap_debug(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug, l5, l4);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a6_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a6_obj, 501u);
    _a6_obj->f_body = l1;
    _a6_obj->f_jump_table = l3;
    _a6_obj->f_debug = l5;
    t1 = (void*) _a6_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_bytecode_run_bc_peephole(void* l0) {
    void* l1 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    void* l28 = NULL;
    void* l36 = NULL;
    void* l47 = NULL;
    size_t l2, l3, l4, l11, l12, l15, l16, l19, l20, l30, l31, l32, l34, l35, l37, l39, l40, l41, l42, l45, l46, l49, l51, l52;
    vader_box_t l9 = vader_box_null(), l22 = vader_box_null(), l33 = vader_box_null(), l43 = vader_box_null();
    int32_t l13, l17, l21, l29, l38, l44, l48, l50;
    bool l23, l24, l25, l26, l27;
    int64_t t0;
    int32_t t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null(), t4 = vader_box_null();
    bool t5;
    vader_box_t* gc_roots[6] = { &l9, &l22, &l33, &l43, &t3, &t4 };
    void** gc_raw_roots[13] = { &l0, &l1, &l5, &l6, &l7, &l8, &l10, &l14, &l18, &l28, &l36, &l47, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 13u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l2 = ((vader_array_t*) l1)->length;
    l3 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcSignature_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_signature)->f_params)->length;
    l4 = ((vader_array_t*) ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_locals)->length;
    t0 = (l3 + l4);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 166u);
    l5 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 166u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 166u);
    l7 = (void*) _a2_arr;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_24: {
            if ((l4 < l3)) {
                vader_array_push_i32((vader_array_t*) l5, INT32_C(0));
                vader_array_push_i32((vader_array_t*) l6, INT32_C(0));
                vader_array_push_i32((vader_array_t*) l7, INT32_C(0));
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_24;
            } else {
            }
        }
    }
    l8 = l1;
    vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
    l3 = ((vader_array_t*) l8)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_54: {
            if ((l4 < l3)) {
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
                if (l9.tag == 609u) {
                    l10 = l9.payload.obj;
                    t1 = ((vader_struct_vader_bytecode_LocalSet_t*) l10)->f_slot;
                    t0 = ((int64_t) (int32_t) t1);
                    l11 = (size_t) (int64_t) t0;
                    t1 = ((vader_struct_vader_bytecode_LocalSet_t*) l10)->f_slot;
                    t0 = ((int64_t) (int32_t) t1);
                    l12 = (size_t) (int64_t) t0;
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l12 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l12];
                    l13 = (t1 + INT32_C(1));
                    if ((size_t) l11 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l11] = (int32_t) l13;
                } else {
                }
                if (l9.tag == 608u) {
                    l14 = l9.payload.obj;
                    t1 = ((vader_struct_vader_bytecode_LocalGet_t*) l14)->f_slot;
                    t0 = ((int64_t) (int32_t) t1);
                    l15 = (size_t) (int64_t) t0;
                    t1 = ((vader_struct_vader_bytecode_LocalGet_t*) l14)->f_slot;
                    t0 = ((int64_t) (int32_t) t1);
                    l16 = (size_t) (int64_t) t0;
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
                    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                    if ((size_t) l16 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l16];
                    l17 = (t1 + INT32_C(1));
                    if ((size_t) l15 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l15] = (int32_t) l17;
                } else {
                }
                if (l9.tag == 610u) {
                    l18 = l9.payload.obj;
                    t1 = ((vader_struct_vader_bytecode_LocalTee_t*) l18)->f_slot;
                    t0 = ((int64_t) (int32_t) t1);
                    l19 = (size_t) (int64_t) t0;
                    t1 = ((vader_struct_vader_bytecode_LocalTee_t*) l18)->f_slot;
                    t0 = ((int64_t) (int32_t) t1);
                    l20 = (size_t) (int64_t) t0;
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
                    if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                    if ((size_t) l20 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l20];
                    l21 = (t1 + INT32_C(1));
                    if ((size_t) l19 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l19] = (int32_t) l21;
                } else {
                }
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_54;
            } else {
            }
        }
    }
    l8 = vader_bytecode_mark_jump_targets(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l2);
    vader_array_t* _a7_arr = vader_array_new(117u, 0u, 13u, 1070u);
    l10 = (void*) _a7_arr;
    l3 = (size_t) (int64_t) INT64_C(0);
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 166u);
    l14 = (void*) _a8_arr;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_162: {
            if ((l4 < l2)) {
                l13 = -(INT32_C(1));
                vader_array_push_i32((vader_array_t*) l14, l13);
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_162;
            } else {
            }
        }
    }
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_185: {
            if ((l4 < l2)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l1);
                if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                if ((size_t) l4 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l4);
                if (l9.tag == 609u) {
                    l18 = l9.payload.obj;
                    if (((l4 + INT64_C(1)) < l2)) {
                        t0 = (l4 + INT64_C(1));
                        l11 = (size_t) (int64_t) t0;
                        vader_array_t* _a10_slotarr = ((vader_array_t*) l1);
                        if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                        if ((size_t) l11 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                        l22 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l11);
                        if (l22.tag == 608u) {
                            t2 = l22.payload.obj;
                            l13 = ((vader_struct_vader_bytecode_LocalGet_t*) t2)->f_slot;
                            l17 = ((vader_struct_vader_bytecode_LocalSet_t*) l18)->f_slot;
                            if (l13 == l17) {
                                l23 = false;
                                if ((l3 > INT64_C(0))) {
                                    t0 = (l3 - INT64_C(1));
                                    l12 = (size_t) (int64_t) t0;
                                    vader_array_t* _a11_slotarr = ((vader_array_t*) l10);
                                    if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                                    if ((size_t) l12 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t3 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l12);
                                    t4 = vader_bytecode_const_op_of(t3);
                                    if (!(t4.tag == 0u)) {
                                        l23 = true;
                                    } else {
                                    }
                                } else {
                                }
                                t1 = ((vader_struct_vader_bytecode_LocalSet_t*) l18)->f_slot;
                                t0 = ((int64_t) (int32_t) t1);
                                l15 = (size_t) (int64_t) t0;
                                vader_array_t* _a12_slotarr = ((vader_array_t*) l5);
                                if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                                if ((size_t) l15 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                                t1 = ((int32_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l15];
                                if (t1 == INT32_C(1)) {
                                    vader_array_t* _a13_slotarr = ((vader_array_t*) l6);
                                    if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                                    if ((size_t) l15 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t1 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l15];
                                    l25 = t1 == INT32_C(1);
                                } else {
                                    l25 = false;
                                }
                                if (l25) {
                                    vader_array_t* _a14_slotarr = ((vader_array_t*) l7);
                                    if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                                    if ((size_t) l15 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t1 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l15];
                                    l24 = t1 == INT32_C(0);
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
                                    t0 = (l4 + INT64_C(1));
                                    l16 = (size_t) (int64_t) t0;
                                    vader_array_t* _a15_slotarr = ((vader_array_t*) l8);
                                    if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                                    if ((size_t) l16 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t3 = vader_box_bool(161u, ((uint8_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l16]);
                                    l26 = t3.payload.b;
                                }
                                if (!(l26)) {
                                    t1 = ((vader_struct_vader_bytecode_LocalSet_t*) l18)->f_slot;
                                    vader_struct_vader_bytecode_LocalTee_t* _a16_obj = (vader_struct_vader_bytecode_LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalTee_t));
                                    vader_obj_header_init(_a16_obj, 610u);
                                    _a16_obj->f_slot = t1;
                                    l28 = (void*) _a16_obj;
                                    vader_bytecode_push_or_assign(l10, l3, vader_ref_box(l28));
                                    l21 = ((int32_t) (size_t) l3);
                                    vader_array_t* _a17_slotarr = ((vader_array_t*) l14);
                                    if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                                    if ((size_t) l4 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l4] = (int32_t) l21;
                                    t0 = (l4 + INT64_C(1));
                                    l19 = (size_t) (int64_t) t0;
                                    l29 = ((int32_t) (size_t) l3);
                                    if ((size_t) l19 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l19] = (int32_t) l29;
                                    t0 = (l3 + INT64_C(1));
                                    l3 = (size_t) (int64_t) t0;
                                    t0 = (l4 + INT64_C(2));
                                    l4 = (size_t) (int64_t) t0;
                                    goto loop_185;
                                }
                                if (l9.tag == 618u) {
                                    l20 = ((vader_array_t*) l10)->length;
                                    l30 = (size_t) (int64_t) INT64_C(0);
                                    if ((l20 > l30)) {
                                        l31 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l20 - l31);
                                        l32 = (size_t) (int64_t) t0;
                                        vader_array_t* _a18_slotarr = ((vader_array_t*) l10);
                                        if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                                        if ((size_t) l32 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t3 = vader_array_ref_load_box(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l32);
                                        l33 = vader_bytecode_const_op_of(t3);
                                        if (!(l33.tag == 0u)) {
                                            l34 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l20 - l34);
                                            l35 = (size_t) (int64_t) t0;
                                            vader_struct_vader_bytecode_ReturnLit_t* _a19_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                                            vader_obj_header_init(_a19_obj, 619u);
                                            _a19_obj->f_value = l33;
                                            l36 = (void*) _a19_obj;
                                            vader_array_t* _a20_slotarr = ((vader_array_t*) l10);
                                            if (_a20_slotarr->buf != NULL && _a20_slotarr->buf->header.forward != NULL) { _a20_slotarr->buf = vader_array_buf_forward(_a20_slotarr->buf); }
                                            if ((size_t) l35 >= _a20_slotarr->length) { vader_trap("array index out of bounds"); }
                                            vader_array_ref_store(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l35, l36);
                                            VADER_WRITE_BARRIER(_a20_slotarr->buf);
                                            l37 = (size_t) (int64_t) INT64_C(1);
                                            l38 = ((int32_t) (int64_t) (l3 - l37));
                                            vader_array_t* _a21_slotarr = ((vader_array_t*) l14);
                                            if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
                                            if ((size_t) l4 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
                                            ((int32_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l4] = (int32_t) l38;
                                            l39 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l4 + l39);
                                            l4 = (size_t) (int64_t) t0;
                                            goto loop_185;
                                        }
                                        if (l9.tag == 520u) {
                                            l40 = (size_t) (int64_t) INT64_C(0);
                                            if ((l3 > l40)) {
                                                l41 = (size_t) (int64_t) INT64_C(1);
                                                t0 = (l3 - l41);
                                                l42 = (size_t) (int64_t) t0;
                                                vader_array_t* _a22_slotarr = ((vader_array_t*) l10);
                                                if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                                                if ((size_t) l42 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                                                l43 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l42);
                                                if (l43.tag == 520u) {
                                                    l44 = -(INT32_C(1));
                                                    vader_array_t* _a23_slotarr = ((vader_array_t*) l14);
                                                    if (_a23_slotarr->buf != NULL && _a23_slotarr->buf->header.forward != NULL) { _a23_slotarr->buf = vader_array_buf_forward(_a23_slotarr->buf); }
                                                    if ((size_t) l4 >= _a23_slotarr->length) { vader_trap("array index out of bounds"); }
                                                    ((int32_t*) _a23_slotarr->buf->slots)[_a23_slotarr->offset + (size_t) l4] = (int32_t) l44;
                                                    l45 = (size_t) (int64_t) INT64_C(1);
                                                    t0 = (l3 - l45);
                                                    l3 = (size_t) (int64_t) t0;
                                                    l46 = (size_t) (int64_t) INT64_C(1);
                                                    t0 = (l4 + l46);
                                                    l4 = (size_t) (int64_t) t0;
                                                    goto loop_185;
                                                }
                                                if (l43.tag == 517u) {
                                                    t2 = l43.payload.obj;
                                                    t5 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                                    vader_struct_vader_bytecode_BoolConst_t* _a24_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                                    vader_obj_header_init(_a24_obj, 517u);
                                                    _a24_obj->f_value = !(t5);
                                                    l47 = (void*) _a24_obj;
                                                    vader_array_t* _a25_slotarr = ((vader_array_t*) l10);
                                                    if (_a25_slotarr->buf != NULL && _a25_slotarr->buf->header.forward != NULL) { _a25_slotarr->buf = vader_array_buf_forward(_a25_slotarr->buf); }
                                                    if ((size_t) l42 >= _a25_slotarr->length) { vader_trap("array index out of bounds"); }
                                                    vader_array_ref_store(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l42, l47);
                                                    VADER_WRITE_BARRIER(_a25_slotarr->buf);
                                                    l48 = ((int32_t) (size_t) l42);
                                                    vader_array_t* _a26_slotarr = ((vader_array_t*) l14);
                                                    if (_a26_slotarr->buf != NULL && _a26_slotarr->buf->header.forward != NULL) { _a26_slotarr->buf = vader_array_buf_forward(_a26_slotarr->buf); }
                                                    if ((size_t) l4 >= _a26_slotarr->length) { vader_trap("array index out of bounds"); }
                                                    ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l4] = (int32_t) l48;
                                                    l49 = (size_t) (int64_t) INT64_C(1);
                                                    t0 = (l4 + l49);
                                                    l4 = (size_t) (int64_t) t0;
                                                    goto loop_185;
                                                }
                                                vader_bytecode_push_or_assign(l10, l3, l9);
                                                l50 = ((int32_t) (size_t) l3);
                                                vader_array_t* _a27_slotarr = ((vader_array_t*) l14);
                                                if (_a27_slotarr->buf != NULL && _a27_slotarr->buf->header.forward != NULL) { _a27_slotarr->buf = vader_array_buf_forward(_a27_slotarr->buf); }
                                                if ((size_t) l4 >= _a27_slotarr->length) { vader_trap("array index out of bounds"); }
                                                ((int32_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                                l51 = (size_t) (int64_t) INT64_C(1);
                                                t0 = (l3 + l51);
                                                l3 = (size_t) (int64_t) t0;
                                                l52 = (size_t) (int64_t) INT64_C(1);
                                                t0 = (l4 + l52);
                                                l4 = (size_t) (int64_t) t0;
                                                goto loop_185;
                                            }
                                            vader_bytecode_push_or_assign(l10, l3, l9);
                                            l50 = ((int32_t) (size_t) l3);
                                            vader_array_t* _a28_slotarr = ((vader_array_t*) l14);
                                            if (_a28_slotarr->buf != NULL && _a28_slotarr->buf->header.forward != NULL) { _a28_slotarr->buf = vader_array_buf_forward(_a28_slotarr->buf); }
                                            if ((size_t) l4 >= _a28_slotarr->length) { vader_trap("array index out of bounds"); }
                                            ((int32_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                            l51 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l3 + l51);
                                            l3 = (size_t) (int64_t) t0;
                                            l52 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l4 + l52);
                                            l4 = (size_t) (int64_t) t0;
                                            goto loop_185;
                                        }
                                        vader_bytecode_push_or_assign(l10, l3, l9);
                                        l50 = ((int32_t) (size_t) l3);
                                        vader_array_t* _a29_slotarr = ((vader_array_t*) l14);
                                        if (_a29_slotarr->buf != NULL && _a29_slotarr->buf->header.forward != NULL) { _a29_slotarr->buf = vader_array_buf_forward(_a29_slotarr->buf); }
                                        if ((size_t) l4 >= _a29_slotarr->length) { vader_trap("array index out of bounds"); }
                                        ((int32_t*) _a29_slotarr->buf->slots)[_a29_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                        l51 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l3 + l51);
                                        l3 = (size_t) (int64_t) t0;
                                        l52 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l4 + l52);
                                        l4 = (size_t) (int64_t) t0;
                                        goto loop_185;
                                    }
                                    if (l9.tag == 520u) {
                                        l40 = (size_t) (int64_t) INT64_C(0);
                                        if ((l3 > l40)) {
                                            l41 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l3 - l41);
                                            l42 = (size_t) (int64_t) t0;
                                            vader_array_t* _a30_slotarr = ((vader_array_t*) l10);
                                            if (_a30_slotarr->buf != NULL && _a30_slotarr->buf->header.forward != NULL) { _a30_slotarr->buf = vader_array_buf_forward(_a30_slotarr->buf); }
                                            if ((size_t) l42 >= _a30_slotarr->length) { vader_trap("array index out of bounds"); }
                                            l43 = vader_array_ref_load_box(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l42);
                                            if (l43.tag == 520u) {
                                                l44 = -(INT32_C(1));
                                                vader_array_t* _a31_slotarr = ((vader_array_t*) l14);
                                                if (_a31_slotarr->buf != NULL && _a31_slotarr->buf->header.forward != NULL) { _a31_slotarr->buf = vader_array_buf_forward(_a31_slotarr->buf); }
                                                if ((size_t) l4 >= _a31_slotarr->length) { vader_trap("array index out of bounds"); }
                                                ((int32_t*) _a31_slotarr->buf->slots)[_a31_slotarr->offset + (size_t) l4] = (int32_t) l44;
                                                l45 = (size_t) (int64_t) INT64_C(1);
                                                t0 = (l3 - l45);
                                                l3 = (size_t) (int64_t) t0;
                                                l46 = (size_t) (int64_t) INT64_C(1);
                                                t0 = (l4 + l46);
                                                l4 = (size_t) (int64_t) t0;
                                                goto loop_185;
                                            }
                                            if (l43.tag == 517u) {
                                                t2 = l43.payload.obj;
                                                t5 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                                vader_struct_vader_bytecode_BoolConst_t* _a32_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                                vader_obj_header_init(_a32_obj, 517u);
                                                _a32_obj->f_value = !(t5);
                                                l47 = (void*) _a32_obj;
                                                vader_array_t* _a33_slotarr = ((vader_array_t*) l10);
                                                if (_a33_slotarr->buf != NULL && _a33_slotarr->buf->header.forward != NULL) { _a33_slotarr->buf = vader_array_buf_forward(_a33_slotarr->buf); }
                                                if ((size_t) l42 >= _a33_slotarr->length) { vader_trap("array index out of bounds"); }
                                                vader_array_ref_store(_a33_slotarr->buf, _a33_slotarr->offset + (size_t) l42, l47);
                                                VADER_WRITE_BARRIER(_a33_slotarr->buf);
                                                l48 = ((int32_t) (size_t) l42);
                                                vader_array_t* _a34_slotarr = ((vader_array_t*) l14);
                                                if (_a34_slotarr->buf != NULL && _a34_slotarr->buf->header.forward != NULL) { _a34_slotarr->buf = vader_array_buf_forward(_a34_slotarr->buf); }
                                                if ((size_t) l4 >= _a34_slotarr->length) { vader_trap("array index out of bounds"); }
                                                ((int32_t*) _a34_slotarr->buf->slots)[_a34_slotarr->offset + (size_t) l4] = (int32_t) l48;
                                                l49 = (size_t) (int64_t) INT64_C(1);
                                                t0 = (l4 + l49);
                                                l4 = (size_t) (int64_t) t0;
                                                goto loop_185;
                                            }
                                            vader_bytecode_push_or_assign(l10, l3, l9);
                                            l50 = ((int32_t) (size_t) l3);
                                            vader_array_t* _a35_slotarr = ((vader_array_t*) l14);
                                            if (_a35_slotarr->buf != NULL && _a35_slotarr->buf->header.forward != NULL) { _a35_slotarr->buf = vader_array_buf_forward(_a35_slotarr->buf); }
                                            if ((size_t) l4 >= _a35_slotarr->length) { vader_trap("array index out of bounds"); }
                                            ((int32_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                            l51 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l3 + l51);
                                            l3 = (size_t) (int64_t) t0;
                                            l52 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l4 + l52);
                                            l4 = (size_t) (int64_t) t0;
                                            goto loop_185;
                                        }
                                        vader_bytecode_push_or_assign(l10, l3, l9);
                                        l50 = ((int32_t) (size_t) l3);
                                        vader_array_t* _a36_slotarr = ((vader_array_t*) l14);
                                        if (_a36_slotarr->buf != NULL && _a36_slotarr->buf->header.forward != NULL) { _a36_slotarr->buf = vader_array_buf_forward(_a36_slotarr->buf); }
                                        if ((size_t) l4 >= _a36_slotarr->length) { vader_trap("array index out of bounds"); }
                                        ((int32_t*) _a36_slotarr->buf->slots)[_a36_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                        l51 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l3 + l51);
                                        l3 = (size_t) (int64_t) t0;
                                        l52 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l4 + l52);
                                        l4 = (size_t) (int64_t) t0;
                                        goto loop_185;
                                    }
                                    vader_bytecode_push_or_assign(l10, l3, l9);
                                    l50 = ((int32_t) (size_t) l3);
                                    vader_array_t* _a37_slotarr = ((vader_array_t*) l14);
                                    if (_a37_slotarr->buf != NULL && _a37_slotarr->buf->header.forward != NULL) { _a37_slotarr->buf = vader_array_buf_forward(_a37_slotarr->buf); }
                                    if ((size_t) l4 >= _a37_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((int32_t*) _a37_slotarr->buf->slots)[_a37_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                    l51 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l3 + l51);
                                    l3 = (size_t) (int64_t) t0;
                                    l52 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l4 + l52);
                                    l4 = (size_t) (int64_t) t0;
                                    goto loop_185;
                                }
                                if (l9.tag == 520u) {
                                    l40 = (size_t) (int64_t) INT64_C(0);
                                    if ((l3 > l40)) {
                                        l41 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l3 - l41);
                                        l42 = (size_t) (int64_t) t0;
                                        vader_array_t* _a38_slotarr = ((vader_array_t*) l10);
                                        if (_a38_slotarr->buf != NULL && _a38_slotarr->buf->header.forward != NULL) { _a38_slotarr->buf = vader_array_buf_forward(_a38_slotarr->buf); }
                                        if ((size_t) l42 >= _a38_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l43 = vader_array_ref_load_box(_a38_slotarr->buf, _a38_slotarr->offset + (size_t) l42);
                                        if (l43.tag == 520u) {
                                            l44 = -(INT32_C(1));
                                            vader_array_t* _a39_slotarr = ((vader_array_t*) l14);
                                            if (_a39_slotarr->buf != NULL && _a39_slotarr->buf->header.forward != NULL) { _a39_slotarr->buf = vader_array_buf_forward(_a39_slotarr->buf); }
                                            if ((size_t) l4 >= _a39_slotarr->length) { vader_trap("array index out of bounds"); }
                                            ((int32_t*) _a39_slotarr->buf->slots)[_a39_slotarr->offset + (size_t) l4] = (int32_t) l44;
                                            l45 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l3 - l45);
                                            l3 = (size_t) (int64_t) t0;
                                            l46 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l4 + l46);
                                            l4 = (size_t) (int64_t) t0;
                                            goto loop_185;
                                        }
                                        if (l43.tag == 517u) {
                                            t2 = l43.payload.obj;
                                            t5 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                            vader_struct_vader_bytecode_BoolConst_t* _a40_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                            vader_obj_header_init(_a40_obj, 517u);
                                            _a40_obj->f_value = !(t5);
                                            l47 = (void*) _a40_obj;
                                            vader_array_t* _a41_slotarr = ((vader_array_t*) l10);
                                            if (_a41_slotarr->buf != NULL && _a41_slotarr->buf->header.forward != NULL) { _a41_slotarr->buf = vader_array_buf_forward(_a41_slotarr->buf); }
                                            if ((size_t) l42 >= _a41_slotarr->length) { vader_trap("array index out of bounds"); }
                                            vader_array_ref_store(_a41_slotarr->buf, _a41_slotarr->offset + (size_t) l42, l47);
                                            VADER_WRITE_BARRIER(_a41_slotarr->buf);
                                            l48 = ((int32_t) (size_t) l42);
                                            vader_array_t* _a42_slotarr = ((vader_array_t*) l14);
                                            if (_a42_slotarr->buf != NULL && _a42_slotarr->buf->header.forward != NULL) { _a42_slotarr->buf = vader_array_buf_forward(_a42_slotarr->buf); }
                                            if ((size_t) l4 >= _a42_slotarr->length) { vader_trap("array index out of bounds"); }
                                            ((int32_t*) _a42_slotarr->buf->slots)[_a42_slotarr->offset + (size_t) l4] = (int32_t) l48;
                                            l49 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l4 + l49);
                                            l4 = (size_t) (int64_t) t0;
                                            goto loop_185;
                                        }
                                        vader_bytecode_push_or_assign(l10, l3, l9);
                                        l50 = ((int32_t) (size_t) l3);
                                        vader_array_t* _a43_slotarr = ((vader_array_t*) l14);
                                        if (_a43_slotarr->buf != NULL && _a43_slotarr->buf->header.forward != NULL) { _a43_slotarr->buf = vader_array_buf_forward(_a43_slotarr->buf); }
                                        if ((size_t) l4 >= _a43_slotarr->length) { vader_trap("array index out of bounds"); }
                                        ((int32_t*) _a43_slotarr->buf->slots)[_a43_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                        l51 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l3 + l51);
                                        l3 = (size_t) (int64_t) t0;
                                        l52 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l4 + l52);
                                        l4 = (size_t) (int64_t) t0;
                                        goto loop_185;
                                    }
                                    vader_bytecode_push_or_assign(l10, l3, l9);
                                    l50 = ((int32_t) (size_t) l3);
                                    vader_array_t* _a44_slotarr = ((vader_array_t*) l14);
                                    if (_a44_slotarr->buf != NULL && _a44_slotarr->buf->header.forward != NULL) { _a44_slotarr->buf = vader_array_buf_forward(_a44_slotarr->buf); }
                                    if ((size_t) l4 >= _a44_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((int32_t*) _a44_slotarr->buf->slots)[_a44_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                    l51 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l3 + l51);
                                    l3 = (size_t) (int64_t) t0;
                                    l52 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l4 + l52);
                                    l4 = (size_t) (int64_t) t0;
                                    goto loop_185;
                                }
                                vader_bytecode_push_or_assign(l10, l3, l9);
                                l50 = ((int32_t) (size_t) l3);
                                vader_array_t* _a45_slotarr = ((vader_array_t*) l14);
                                if (_a45_slotarr->buf != NULL && _a45_slotarr->buf->header.forward != NULL) { _a45_slotarr->buf = vader_array_buf_forward(_a45_slotarr->buf); }
                                if ((size_t) l4 >= _a45_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((int32_t*) _a45_slotarr->buf->slots)[_a45_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                l51 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l3 + l51);
                                l3 = (size_t) (int64_t) t0;
                                l52 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l4 + l52);
                                l4 = (size_t) (int64_t) t0;
                                goto loop_185;
                            }
                            if (l9.tag == 618u) {
                                l20 = ((vader_array_t*) l10)->length;
                                l30 = (size_t) (int64_t) INT64_C(0);
                                if ((l20 > l30)) {
                                    l31 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l20 - l31);
                                    l32 = (size_t) (int64_t) t0;
                                    vader_array_t* _a46_slotarr = ((vader_array_t*) l10);
                                    if (_a46_slotarr->buf != NULL && _a46_slotarr->buf->header.forward != NULL) { _a46_slotarr->buf = vader_array_buf_forward(_a46_slotarr->buf); }
                                    if ((size_t) l32 >= _a46_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t3 = vader_array_ref_load_box(_a46_slotarr->buf, _a46_slotarr->offset + (size_t) l32);
                                    l33 = vader_bytecode_const_op_of(t3);
                                    if (!(l33.tag == 0u)) {
                                        l34 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l20 - l34);
                                        l35 = (size_t) (int64_t) t0;
                                        vader_struct_vader_bytecode_ReturnLit_t* _a47_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                                        vader_obj_header_init(_a47_obj, 619u);
                                        _a47_obj->f_value = l33;
                                        l36 = (void*) _a47_obj;
                                        vader_array_t* _a48_slotarr = ((vader_array_t*) l10);
                                        if (_a48_slotarr->buf != NULL && _a48_slotarr->buf->header.forward != NULL) { _a48_slotarr->buf = vader_array_buf_forward(_a48_slotarr->buf); }
                                        if ((size_t) l35 >= _a48_slotarr->length) { vader_trap("array index out of bounds"); }
                                        vader_array_ref_store(_a48_slotarr->buf, _a48_slotarr->offset + (size_t) l35, l36);
                                        VADER_WRITE_BARRIER(_a48_slotarr->buf);
                                        l37 = (size_t) (int64_t) INT64_C(1);
                                        l38 = ((int32_t) (int64_t) (l3 - l37));
                                        vader_array_t* _a49_slotarr = ((vader_array_t*) l14);
                                        if (_a49_slotarr->buf != NULL && _a49_slotarr->buf->header.forward != NULL) { _a49_slotarr->buf = vader_array_buf_forward(_a49_slotarr->buf); }
                                        if ((size_t) l4 >= _a49_slotarr->length) { vader_trap("array index out of bounds"); }
                                        ((int32_t*) _a49_slotarr->buf->slots)[_a49_slotarr->offset + (size_t) l4] = (int32_t) l38;
                                        l39 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l4 + l39);
                                        l4 = (size_t) (int64_t) t0;
                                        goto loop_185;
                                    }
                                    if (l9.tag == 520u) {
                                        l40 = (size_t) (int64_t) INT64_C(0);
                                        if ((l3 > l40)) {
                                            l41 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l3 - l41);
                                            l42 = (size_t) (int64_t) t0;
                                            vader_array_t* _a50_slotarr = ((vader_array_t*) l10);
                                            if (_a50_slotarr->buf != NULL && _a50_slotarr->buf->header.forward != NULL) { _a50_slotarr->buf = vader_array_buf_forward(_a50_slotarr->buf); }
                                            if ((size_t) l42 >= _a50_slotarr->length) { vader_trap("array index out of bounds"); }
                                            l43 = vader_array_ref_load_box(_a50_slotarr->buf, _a50_slotarr->offset + (size_t) l42);
                                            if (l43.tag == 520u) {
                                                l44 = -(INT32_C(1));
                                                vader_array_t* _a51_slotarr = ((vader_array_t*) l14);
                                                if (_a51_slotarr->buf != NULL && _a51_slotarr->buf->header.forward != NULL) { _a51_slotarr->buf = vader_array_buf_forward(_a51_slotarr->buf); }
                                                if ((size_t) l4 >= _a51_slotarr->length) { vader_trap("array index out of bounds"); }
                                                ((int32_t*) _a51_slotarr->buf->slots)[_a51_slotarr->offset + (size_t) l4] = (int32_t) l44;
                                                l45 = (size_t) (int64_t) INT64_C(1);
                                                t0 = (l3 - l45);
                                                l3 = (size_t) (int64_t) t0;
                                                l46 = (size_t) (int64_t) INT64_C(1);
                                                t0 = (l4 + l46);
                                                l4 = (size_t) (int64_t) t0;
                                                goto loop_185;
                                            }
                                            if (l43.tag == 517u) {
                                                t2 = l43.payload.obj;
                                                t5 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                                vader_struct_vader_bytecode_BoolConst_t* _a52_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                                vader_obj_header_init(_a52_obj, 517u);
                                                _a52_obj->f_value = !(t5);
                                                l47 = (void*) _a52_obj;
                                                vader_array_t* _a53_slotarr = ((vader_array_t*) l10);
                                                if (_a53_slotarr->buf != NULL && _a53_slotarr->buf->header.forward != NULL) { _a53_slotarr->buf = vader_array_buf_forward(_a53_slotarr->buf); }
                                                if ((size_t) l42 >= _a53_slotarr->length) { vader_trap("array index out of bounds"); }
                                                vader_array_ref_store(_a53_slotarr->buf, _a53_slotarr->offset + (size_t) l42, l47);
                                                VADER_WRITE_BARRIER(_a53_slotarr->buf);
                                                l48 = ((int32_t) (size_t) l42);
                                                vader_array_t* _a54_slotarr = ((vader_array_t*) l14);
                                                if (_a54_slotarr->buf != NULL && _a54_slotarr->buf->header.forward != NULL) { _a54_slotarr->buf = vader_array_buf_forward(_a54_slotarr->buf); }
                                                if ((size_t) l4 >= _a54_slotarr->length) { vader_trap("array index out of bounds"); }
                                                ((int32_t*) _a54_slotarr->buf->slots)[_a54_slotarr->offset + (size_t) l4] = (int32_t) l48;
                                                l49 = (size_t) (int64_t) INT64_C(1);
                                                t0 = (l4 + l49);
                                                l4 = (size_t) (int64_t) t0;
                                                goto loop_185;
                                            }
                                            vader_bytecode_push_or_assign(l10, l3, l9);
                                            l50 = ((int32_t) (size_t) l3);
                                            vader_array_t* _a55_slotarr = ((vader_array_t*) l14);
                                            if (_a55_slotarr->buf != NULL && _a55_slotarr->buf->header.forward != NULL) { _a55_slotarr->buf = vader_array_buf_forward(_a55_slotarr->buf); }
                                            if ((size_t) l4 >= _a55_slotarr->length) { vader_trap("array index out of bounds"); }
                                            ((int32_t*) _a55_slotarr->buf->slots)[_a55_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                            l51 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l3 + l51);
                                            l3 = (size_t) (int64_t) t0;
                                            l52 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l4 + l52);
                                            l4 = (size_t) (int64_t) t0;
                                            goto loop_185;
                                        }
                                        vader_bytecode_push_or_assign(l10, l3, l9);
                                        l50 = ((int32_t) (size_t) l3);
                                        vader_array_t* _a56_slotarr = ((vader_array_t*) l14);
                                        if (_a56_slotarr->buf != NULL && _a56_slotarr->buf->header.forward != NULL) { _a56_slotarr->buf = vader_array_buf_forward(_a56_slotarr->buf); }
                                        if ((size_t) l4 >= _a56_slotarr->length) { vader_trap("array index out of bounds"); }
                                        ((int32_t*) _a56_slotarr->buf->slots)[_a56_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                        l51 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l3 + l51);
                                        l3 = (size_t) (int64_t) t0;
                                        l52 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l4 + l52);
                                        l4 = (size_t) (int64_t) t0;
                                        goto loop_185;
                                    }
                                    vader_bytecode_push_or_assign(l10, l3, l9);
                                    l50 = ((int32_t) (size_t) l3);
                                    vader_array_t* _a57_slotarr = ((vader_array_t*) l14);
                                    if (_a57_slotarr->buf != NULL && _a57_slotarr->buf->header.forward != NULL) { _a57_slotarr->buf = vader_array_buf_forward(_a57_slotarr->buf); }
                                    if ((size_t) l4 >= _a57_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((int32_t*) _a57_slotarr->buf->slots)[_a57_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                    l51 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l3 + l51);
                                    l3 = (size_t) (int64_t) t0;
                                    l52 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l4 + l52);
                                    l4 = (size_t) (int64_t) t0;
                                    goto loop_185;
                                }
                                if (l9.tag == 520u) {
                                    l40 = (size_t) (int64_t) INT64_C(0);
                                    if ((l3 > l40)) {
                                        l41 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l3 - l41);
                                        l42 = (size_t) (int64_t) t0;
                                        vader_array_t* _a58_slotarr = ((vader_array_t*) l10);
                                        if (_a58_slotarr->buf != NULL && _a58_slotarr->buf->header.forward != NULL) { _a58_slotarr->buf = vader_array_buf_forward(_a58_slotarr->buf); }
                                        if ((size_t) l42 >= _a58_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l43 = vader_array_ref_load_box(_a58_slotarr->buf, _a58_slotarr->offset + (size_t) l42);
                                        if (l43.tag == 520u) {
                                            l44 = -(INT32_C(1));
                                            vader_array_t* _a59_slotarr = ((vader_array_t*) l14);
                                            if (_a59_slotarr->buf != NULL && _a59_slotarr->buf->header.forward != NULL) { _a59_slotarr->buf = vader_array_buf_forward(_a59_slotarr->buf); }
                                            if ((size_t) l4 >= _a59_slotarr->length) { vader_trap("array index out of bounds"); }
                                            ((int32_t*) _a59_slotarr->buf->slots)[_a59_slotarr->offset + (size_t) l4] = (int32_t) l44;
                                            l45 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l3 - l45);
                                            l3 = (size_t) (int64_t) t0;
                                            l46 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l4 + l46);
                                            l4 = (size_t) (int64_t) t0;
                                            goto loop_185;
                                        }
                                        if (l43.tag == 517u) {
                                            t2 = l43.payload.obj;
                                            t5 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                            vader_struct_vader_bytecode_BoolConst_t* _a60_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                            vader_obj_header_init(_a60_obj, 517u);
                                            _a60_obj->f_value = !(t5);
                                            l47 = (void*) _a60_obj;
                                            vader_array_t* _a61_slotarr = ((vader_array_t*) l10);
                                            if (_a61_slotarr->buf != NULL && _a61_slotarr->buf->header.forward != NULL) { _a61_slotarr->buf = vader_array_buf_forward(_a61_slotarr->buf); }
                                            if ((size_t) l42 >= _a61_slotarr->length) { vader_trap("array index out of bounds"); }
                                            vader_array_ref_store(_a61_slotarr->buf, _a61_slotarr->offset + (size_t) l42, l47);
                                            VADER_WRITE_BARRIER(_a61_slotarr->buf);
                                            l48 = ((int32_t) (size_t) l42);
                                            vader_array_t* _a62_slotarr = ((vader_array_t*) l14);
                                            if (_a62_slotarr->buf != NULL && _a62_slotarr->buf->header.forward != NULL) { _a62_slotarr->buf = vader_array_buf_forward(_a62_slotarr->buf); }
                                            if ((size_t) l4 >= _a62_slotarr->length) { vader_trap("array index out of bounds"); }
                                            ((int32_t*) _a62_slotarr->buf->slots)[_a62_slotarr->offset + (size_t) l4] = (int32_t) l48;
                                            l49 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l4 + l49);
                                            l4 = (size_t) (int64_t) t0;
                                            goto loop_185;
                                        }
                                        vader_bytecode_push_or_assign(l10, l3, l9);
                                        l50 = ((int32_t) (size_t) l3);
                                        vader_array_t* _a63_slotarr = ((vader_array_t*) l14);
                                        if (_a63_slotarr->buf != NULL && _a63_slotarr->buf->header.forward != NULL) { _a63_slotarr->buf = vader_array_buf_forward(_a63_slotarr->buf); }
                                        if ((size_t) l4 >= _a63_slotarr->length) { vader_trap("array index out of bounds"); }
                                        ((int32_t*) _a63_slotarr->buf->slots)[_a63_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                        l51 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l3 + l51);
                                        l3 = (size_t) (int64_t) t0;
                                        l52 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l4 + l52);
                                        l4 = (size_t) (int64_t) t0;
                                        goto loop_185;
                                    }
                                    vader_bytecode_push_or_assign(l10, l3, l9);
                                    l50 = ((int32_t) (size_t) l3);
                                    vader_array_t* _a64_slotarr = ((vader_array_t*) l14);
                                    if (_a64_slotarr->buf != NULL && _a64_slotarr->buf->header.forward != NULL) { _a64_slotarr->buf = vader_array_buf_forward(_a64_slotarr->buf); }
                                    if ((size_t) l4 >= _a64_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((int32_t*) _a64_slotarr->buf->slots)[_a64_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                    l51 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l3 + l51);
                                    l3 = (size_t) (int64_t) t0;
                                    l52 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l4 + l52);
                                    l4 = (size_t) (int64_t) t0;
                                    goto loop_185;
                                }
                                vader_bytecode_push_or_assign(l10, l3, l9);
                                l50 = ((int32_t) (size_t) l3);
                                vader_array_t* _a65_slotarr = ((vader_array_t*) l14);
                                if (_a65_slotarr->buf != NULL && _a65_slotarr->buf->header.forward != NULL) { _a65_slotarr->buf = vader_array_buf_forward(_a65_slotarr->buf); }
                                if ((size_t) l4 >= _a65_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((int32_t*) _a65_slotarr->buf->slots)[_a65_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                l51 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l3 + l51);
                                l3 = (size_t) (int64_t) t0;
                                l52 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l4 + l52);
                                l4 = (size_t) (int64_t) t0;
                                goto loop_185;
                            }
                            if (l9.tag == 520u) {
                                l40 = (size_t) (int64_t) INT64_C(0);
                                if ((l3 > l40)) {
                                    l41 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l3 - l41);
                                    l42 = (size_t) (int64_t) t0;
                                    vader_array_t* _a66_slotarr = ((vader_array_t*) l10);
                                    if (_a66_slotarr->buf != NULL && _a66_slotarr->buf->header.forward != NULL) { _a66_slotarr->buf = vader_array_buf_forward(_a66_slotarr->buf); }
                                    if ((size_t) l42 >= _a66_slotarr->length) { vader_trap("array index out of bounds"); }
                                    l43 = vader_array_ref_load_box(_a66_slotarr->buf, _a66_slotarr->offset + (size_t) l42);
                                    if (l43.tag == 520u) {
                                        l44 = -(INT32_C(1));
                                        vader_array_t* _a67_slotarr = ((vader_array_t*) l14);
                                        if (_a67_slotarr->buf != NULL && _a67_slotarr->buf->header.forward != NULL) { _a67_slotarr->buf = vader_array_buf_forward(_a67_slotarr->buf); }
                                        if ((size_t) l4 >= _a67_slotarr->length) { vader_trap("array index out of bounds"); }
                                        ((int32_t*) _a67_slotarr->buf->slots)[_a67_slotarr->offset + (size_t) l4] = (int32_t) l44;
                                        l45 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l3 - l45);
                                        l3 = (size_t) (int64_t) t0;
                                        l46 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l4 + l46);
                                        l4 = (size_t) (int64_t) t0;
                                        goto loop_185;
                                    }
                                    if (l43.tag == 517u) {
                                        t2 = l43.payload.obj;
                                        t5 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                        vader_struct_vader_bytecode_BoolConst_t* _a68_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                        vader_obj_header_init(_a68_obj, 517u);
                                        _a68_obj->f_value = !(t5);
                                        l47 = (void*) _a68_obj;
                                        vader_array_t* _a69_slotarr = ((vader_array_t*) l10);
                                        if (_a69_slotarr->buf != NULL && _a69_slotarr->buf->header.forward != NULL) { _a69_slotarr->buf = vader_array_buf_forward(_a69_slotarr->buf); }
                                        if ((size_t) l42 >= _a69_slotarr->length) { vader_trap("array index out of bounds"); }
                                        vader_array_ref_store(_a69_slotarr->buf, _a69_slotarr->offset + (size_t) l42, l47);
                                        VADER_WRITE_BARRIER(_a69_slotarr->buf);
                                        l48 = ((int32_t) (size_t) l42);
                                        vader_array_t* _a70_slotarr = ((vader_array_t*) l14);
                                        if (_a70_slotarr->buf != NULL && _a70_slotarr->buf->header.forward != NULL) { _a70_slotarr->buf = vader_array_buf_forward(_a70_slotarr->buf); }
                                        if ((size_t) l4 >= _a70_slotarr->length) { vader_trap("array index out of bounds"); }
                                        ((int32_t*) _a70_slotarr->buf->slots)[_a70_slotarr->offset + (size_t) l4] = (int32_t) l48;
                                        l49 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l4 + l49);
                                        l4 = (size_t) (int64_t) t0;
                                        goto loop_185;
                                    }
                                    vader_bytecode_push_or_assign(l10, l3, l9);
                                    l50 = ((int32_t) (size_t) l3);
                                    vader_array_t* _a71_slotarr = ((vader_array_t*) l14);
                                    if (_a71_slotarr->buf != NULL && _a71_slotarr->buf->header.forward != NULL) { _a71_slotarr->buf = vader_array_buf_forward(_a71_slotarr->buf); }
                                    if ((size_t) l4 >= _a71_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((int32_t*) _a71_slotarr->buf->slots)[_a71_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                    l51 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l3 + l51);
                                    l3 = (size_t) (int64_t) t0;
                                    l52 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l4 + l52);
                                    l4 = (size_t) (int64_t) t0;
                                    goto loop_185;
                                }
                                vader_bytecode_push_or_assign(l10, l3, l9);
                                l50 = ((int32_t) (size_t) l3);
                                vader_array_t* _a72_slotarr = ((vader_array_t*) l14);
                                if (_a72_slotarr->buf != NULL && _a72_slotarr->buf->header.forward != NULL) { _a72_slotarr->buf = vader_array_buf_forward(_a72_slotarr->buf); }
                                if ((size_t) l4 >= _a72_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((int32_t*) _a72_slotarr->buf->slots)[_a72_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                l51 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l3 + l51);
                                l3 = (size_t) (int64_t) t0;
                                l52 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l4 + l52);
                                l4 = (size_t) (int64_t) t0;
                                goto loop_185;
                            }
                            vader_bytecode_push_or_assign(l10, l3, l9);
                            l50 = ((int32_t) (size_t) l3);
                            vader_array_t* _a73_slotarr = ((vader_array_t*) l14);
                            if (_a73_slotarr->buf != NULL && _a73_slotarr->buf->header.forward != NULL) { _a73_slotarr->buf = vader_array_buf_forward(_a73_slotarr->buf); }
                            if ((size_t) l4 >= _a73_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a73_slotarr->buf->slots)[_a73_slotarr->offset + (size_t) l4] = (int32_t) l50;
                            l51 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l3 + l51);
                            l3 = (size_t) (int64_t) t0;
                            l52 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l4 + l52);
                            l4 = (size_t) (int64_t) t0;
                            goto loop_185;
                        }
                        if (l9.tag == 618u) {
                            l20 = ((vader_array_t*) l10)->length;
                            l30 = (size_t) (int64_t) INT64_C(0);
                            if ((l20 > l30)) {
                                l31 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l20 - l31);
                                l32 = (size_t) (int64_t) t0;
                                vader_array_t* _a74_slotarr = ((vader_array_t*) l10);
                                if (_a74_slotarr->buf != NULL && _a74_slotarr->buf->header.forward != NULL) { _a74_slotarr->buf = vader_array_buf_forward(_a74_slotarr->buf); }
                                if ((size_t) l32 >= _a74_slotarr->length) { vader_trap("array index out of bounds"); }
                                t3 = vader_array_ref_load_box(_a74_slotarr->buf, _a74_slotarr->offset + (size_t) l32);
                                l33 = vader_bytecode_const_op_of(t3);
                                if (!(l33.tag == 0u)) {
                                    l34 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l20 - l34);
                                    l35 = (size_t) (int64_t) t0;
                                    vader_struct_vader_bytecode_ReturnLit_t* _a75_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                                    vader_obj_header_init(_a75_obj, 619u);
                                    _a75_obj->f_value = l33;
                                    l36 = (void*) _a75_obj;
                                    vader_array_t* _a76_slotarr = ((vader_array_t*) l10);
                                    if (_a76_slotarr->buf != NULL && _a76_slotarr->buf->header.forward != NULL) { _a76_slotarr->buf = vader_array_buf_forward(_a76_slotarr->buf); }
                                    if ((size_t) l35 >= _a76_slotarr->length) { vader_trap("array index out of bounds"); }
                                    vader_array_ref_store(_a76_slotarr->buf, _a76_slotarr->offset + (size_t) l35, l36);
                                    VADER_WRITE_BARRIER(_a76_slotarr->buf);
                                    l37 = (size_t) (int64_t) INT64_C(1);
                                    l38 = ((int32_t) (int64_t) (l3 - l37));
                                    vader_array_t* _a77_slotarr = ((vader_array_t*) l14);
                                    if (_a77_slotarr->buf != NULL && _a77_slotarr->buf->header.forward != NULL) { _a77_slotarr->buf = vader_array_buf_forward(_a77_slotarr->buf); }
                                    if ((size_t) l4 >= _a77_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((int32_t*) _a77_slotarr->buf->slots)[_a77_slotarr->offset + (size_t) l4] = (int32_t) l38;
                                    l39 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l4 + l39);
                                    l4 = (size_t) (int64_t) t0;
                                    goto loop_185;
                                }
                                if (l9.tag == 520u) {
                                    l40 = (size_t) (int64_t) INT64_C(0);
                                    if ((l3 > l40)) {
                                        l41 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l3 - l41);
                                        l42 = (size_t) (int64_t) t0;
                                        vader_array_t* _a78_slotarr = ((vader_array_t*) l10);
                                        if (_a78_slotarr->buf != NULL && _a78_slotarr->buf->header.forward != NULL) { _a78_slotarr->buf = vader_array_buf_forward(_a78_slotarr->buf); }
                                        if ((size_t) l42 >= _a78_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l43 = vader_array_ref_load_box(_a78_slotarr->buf, _a78_slotarr->offset + (size_t) l42);
                                        if (l43.tag == 520u) {
                                            l44 = -(INT32_C(1));
                                            vader_array_t* _a79_slotarr = ((vader_array_t*) l14);
                                            if (_a79_slotarr->buf != NULL && _a79_slotarr->buf->header.forward != NULL) { _a79_slotarr->buf = vader_array_buf_forward(_a79_slotarr->buf); }
                                            if ((size_t) l4 >= _a79_slotarr->length) { vader_trap("array index out of bounds"); }
                                            ((int32_t*) _a79_slotarr->buf->slots)[_a79_slotarr->offset + (size_t) l4] = (int32_t) l44;
                                            l45 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l3 - l45);
                                            l3 = (size_t) (int64_t) t0;
                                            l46 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l4 + l46);
                                            l4 = (size_t) (int64_t) t0;
                                            goto loop_185;
                                        }
                                        if (l43.tag == 517u) {
                                            t2 = l43.payload.obj;
                                            t5 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                            vader_struct_vader_bytecode_BoolConst_t* _a80_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                            vader_obj_header_init(_a80_obj, 517u);
                                            _a80_obj->f_value = !(t5);
                                            l47 = (void*) _a80_obj;
                                            vader_array_t* _a81_slotarr = ((vader_array_t*) l10);
                                            if (_a81_slotarr->buf != NULL && _a81_slotarr->buf->header.forward != NULL) { _a81_slotarr->buf = vader_array_buf_forward(_a81_slotarr->buf); }
                                            if ((size_t) l42 >= _a81_slotarr->length) { vader_trap("array index out of bounds"); }
                                            vader_array_ref_store(_a81_slotarr->buf, _a81_slotarr->offset + (size_t) l42, l47);
                                            VADER_WRITE_BARRIER(_a81_slotarr->buf);
                                            l48 = ((int32_t) (size_t) l42);
                                            vader_array_t* _a82_slotarr = ((vader_array_t*) l14);
                                            if (_a82_slotarr->buf != NULL && _a82_slotarr->buf->header.forward != NULL) { _a82_slotarr->buf = vader_array_buf_forward(_a82_slotarr->buf); }
                                            if ((size_t) l4 >= _a82_slotarr->length) { vader_trap("array index out of bounds"); }
                                            ((int32_t*) _a82_slotarr->buf->slots)[_a82_slotarr->offset + (size_t) l4] = (int32_t) l48;
                                            l49 = (size_t) (int64_t) INT64_C(1);
                                            t0 = (l4 + l49);
                                            l4 = (size_t) (int64_t) t0;
                                            goto loop_185;
                                        }
                                        vader_bytecode_push_or_assign(l10, l3, l9);
                                        l50 = ((int32_t) (size_t) l3);
                                        vader_array_t* _a83_slotarr = ((vader_array_t*) l14);
                                        if (_a83_slotarr->buf != NULL && _a83_slotarr->buf->header.forward != NULL) { _a83_slotarr->buf = vader_array_buf_forward(_a83_slotarr->buf); }
                                        if ((size_t) l4 >= _a83_slotarr->length) { vader_trap("array index out of bounds"); }
                                        ((int32_t*) _a83_slotarr->buf->slots)[_a83_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                        l51 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l3 + l51);
                                        l3 = (size_t) (int64_t) t0;
                                        l52 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l4 + l52);
                                        l4 = (size_t) (int64_t) t0;
                                        goto loop_185;
                                    }
                                    vader_bytecode_push_or_assign(l10, l3, l9);
                                    l50 = ((int32_t) (size_t) l3);
                                    vader_array_t* _a84_slotarr = ((vader_array_t*) l14);
                                    if (_a84_slotarr->buf != NULL && _a84_slotarr->buf->header.forward != NULL) { _a84_slotarr->buf = vader_array_buf_forward(_a84_slotarr->buf); }
                                    if ((size_t) l4 >= _a84_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((int32_t*) _a84_slotarr->buf->slots)[_a84_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                    l51 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l3 + l51);
                                    l3 = (size_t) (int64_t) t0;
                                    l52 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l4 + l52);
                                    l4 = (size_t) (int64_t) t0;
                                    goto loop_185;
                                }
                                vader_bytecode_push_or_assign(l10, l3, l9);
                                l50 = ((int32_t) (size_t) l3);
                                vader_array_t* _a85_slotarr = ((vader_array_t*) l14);
                                if (_a85_slotarr->buf != NULL && _a85_slotarr->buf->header.forward != NULL) { _a85_slotarr->buf = vader_array_buf_forward(_a85_slotarr->buf); }
                                if ((size_t) l4 >= _a85_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((int32_t*) _a85_slotarr->buf->slots)[_a85_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                l51 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l3 + l51);
                                l3 = (size_t) (int64_t) t0;
                                l52 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l4 + l52);
                                l4 = (size_t) (int64_t) t0;
                                goto loop_185;
                            }
                            if (l9.tag == 520u) {
                                l40 = (size_t) (int64_t) INT64_C(0);
                                if ((l3 > l40)) {
                                    l41 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l3 - l41);
                                    l42 = (size_t) (int64_t) t0;
                                    vader_array_t* _a86_slotarr = ((vader_array_t*) l10);
                                    if (_a86_slotarr->buf != NULL && _a86_slotarr->buf->header.forward != NULL) { _a86_slotarr->buf = vader_array_buf_forward(_a86_slotarr->buf); }
                                    if ((size_t) l42 >= _a86_slotarr->length) { vader_trap("array index out of bounds"); }
                                    l43 = vader_array_ref_load_box(_a86_slotarr->buf, _a86_slotarr->offset + (size_t) l42);
                                    if (l43.tag == 520u) {
                                        l44 = -(INT32_C(1));
                                        vader_array_t* _a87_slotarr = ((vader_array_t*) l14);
                                        if (_a87_slotarr->buf != NULL && _a87_slotarr->buf->header.forward != NULL) { _a87_slotarr->buf = vader_array_buf_forward(_a87_slotarr->buf); }
                                        if ((size_t) l4 >= _a87_slotarr->length) { vader_trap("array index out of bounds"); }
                                        ((int32_t*) _a87_slotarr->buf->slots)[_a87_slotarr->offset + (size_t) l4] = (int32_t) l44;
                                        l45 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l3 - l45);
                                        l3 = (size_t) (int64_t) t0;
                                        l46 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l4 + l46);
                                        l4 = (size_t) (int64_t) t0;
                                        goto loop_185;
                                    }
                                    if (l43.tag == 517u) {
                                        t2 = l43.payload.obj;
                                        t5 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                        vader_struct_vader_bytecode_BoolConst_t* _a88_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                        vader_obj_header_init(_a88_obj, 517u);
                                        _a88_obj->f_value = !(t5);
                                        l47 = (void*) _a88_obj;
                                        vader_array_t* _a89_slotarr = ((vader_array_t*) l10);
                                        if (_a89_slotarr->buf != NULL && _a89_slotarr->buf->header.forward != NULL) { _a89_slotarr->buf = vader_array_buf_forward(_a89_slotarr->buf); }
                                        if ((size_t) l42 >= _a89_slotarr->length) { vader_trap("array index out of bounds"); }
                                        vader_array_ref_store(_a89_slotarr->buf, _a89_slotarr->offset + (size_t) l42, l47);
                                        VADER_WRITE_BARRIER(_a89_slotarr->buf);
                                        l48 = ((int32_t) (size_t) l42);
                                        vader_array_t* _a90_slotarr = ((vader_array_t*) l14);
                                        if (_a90_slotarr->buf != NULL && _a90_slotarr->buf->header.forward != NULL) { _a90_slotarr->buf = vader_array_buf_forward(_a90_slotarr->buf); }
                                        if ((size_t) l4 >= _a90_slotarr->length) { vader_trap("array index out of bounds"); }
                                        ((int32_t*) _a90_slotarr->buf->slots)[_a90_slotarr->offset + (size_t) l4] = (int32_t) l48;
                                        l49 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l4 + l49);
                                        l4 = (size_t) (int64_t) t0;
                                        goto loop_185;
                                    }
                                    vader_bytecode_push_or_assign(l10, l3, l9);
                                    l50 = ((int32_t) (size_t) l3);
                                    vader_array_t* _a91_slotarr = ((vader_array_t*) l14);
                                    if (_a91_slotarr->buf != NULL && _a91_slotarr->buf->header.forward != NULL) { _a91_slotarr->buf = vader_array_buf_forward(_a91_slotarr->buf); }
                                    if ((size_t) l4 >= _a91_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((int32_t*) _a91_slotarr->buf->slots)[_a91_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                    l51 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l3 + l51);
                                    l3 = (size_t) (int64_t) t0;
                                    l52 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l4 + l52);
                                    l4 = (size_t) (int64_t) t0;
                                    goto loop_185;
                                }
                                vader_bytecode_push_or_assign(l10, l3, l9);
                                l50 = ((int32_t) (size_t) l3);
                                vader_array_t* _a92_slotarr = ((vader_array_t*) l14);
                                if (_a92_slotarr->buf != NULL && _a92_slotarr->buf->header.forward != NULL) { _a92_slotarr->buf = vader_array_buf_forward(_a92_slotarr->buf); }
                                if ((size_t) l4 >= _a92_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((int32_t*) _a92_slotarr->buf->slots)[_a92_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                l51 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l3 + l51);
                                l3 = (size_t) (int64_t) t0;
                                l52 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l4 + l52);
                                l4 = (size_t) (int64_t) t0;
                                goto loop_185;
                            }
                            vader_bytecode_push_or_assign(l10, l3, l9);
                            l50 = ((int32_t) (size_t) l3);
                            vader_array_t* _a93_slotarr = ((vader_array_t*) l14);
                            if (_a93_slotarr->buf != NULL && _a93_slotarr->buf->header.forward != NULL) { _a93_slotarr->buf = vader_array_buf_forward(_a93_slotarr->buf); }
                            if ((size_t) l4 >= _a93_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a93_slotarr->buf->slots)[_a93_slotarr->offset + (size_t) l4] = (int32_t) l50;
                            l51 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l3 + l51);
                            l3 = (size_t) (int64_t) t0;
                            l52 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l4 + l52);
                            l4 = (size_t) (int64_t) t0;
                            goto loop_185;
                        }
                        if (l9.tag == 520u) {
                            l40 = (size_t) (int64_t) INT64_C(0);
                            if ((l3 > l40)) {
                                l41 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l3 - l41);
                                l42 = (size_t) (int64_t) t0;
                                vader_array_t* _a94_slotarr = ((vader_array_t*) l10);
                                if (_a94_slotarr->buf != NULL && _a94_slotarr->buf->header.forward != NULL) { _a94_slotarr->buf = vader_array_buf_forward(_a94_slotarr->buf); }
                                if ((size_t) l42 >= _a94_slotarr->length) { vader_trap("array index out of bounds"); }
                                l43 = vader_array_ref_load_box(_a94_slotarr->buf, _a94_slotarr->offset + (size_t) l42);
                                if (l43.tag == 520u) {
                                    l44 = -(INT32_C(1));
                                    vader_array_t* _a95_slotarr = ((vader_array_t*) l14);
                                    if (_a95_slotarr->buf != NULL && _a95_slotarr->buf->header.forward != NULL) { _a95_slotarr->buf = vader_array_buf_forward(_a95_slotarr->buf); }
                                    if ((size_t) l4 >= _a95_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((int32_t*) _a95_slotarr->buf->slots)[_a95_slotarr->offset + (size_t) l4] = (int32_t) l44;
                                    l45 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l3 - l45);
                                    l3 = (size_t) (int64_t) t0;
                                    l46 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l4 + l46);
                                    l4 = (size_t) (int64_t) t0;
                                    goto loop_185;
                                }
                                if (l43.tag == 517u) {
                                    t2 = l43.payload.obj;
                                    t5 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                    vader_struct_vader_bytecode_BoolConst_t* _a96_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                    vader_obj_header_init(_a96_obj, 517u);
                                    _a96_obj->f_value = !(t5);
                                    l47 = (void*) _a96_obj;
                                    vader_array_t* _a97_slotarr = ((vader_array_t*) l10);
                                    if (_a97_slotarr->buf != NULL && _a97_slotarr->buf->header.forward != NULL) { _a97_slotarr->buf = vader_array_buf_forward(_a97_slotarr->buf); }
                                    if ((size_t) l42 >= _a97_slotarr->length) { vader_trap("array index out of bounds"); }
                                    vader_array_ref_store(_a97_slotarr->buf, _a97_slotarr->offset + (size_t) l42, l47);
                                    VADER_WRITE_BARRIER(_a97_slotarr->buf);
                                    l48 = ((int32_t) (size_t) l42);
                                    vader_array_t* _a98_slotarr = ((vader_array_t*) l14);
                                    if (_a98_slotarr->buf != NULL && _a98_slotarr->buf->header.forward != NULL) { _a98_slotarr->buf = vader_array_buf_forward(_a98_slotarr->buf); }
                                    if ((size_t) l4 >= _a98_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((int32_t*) _a98_slotarr->buf->slots)[_a98_slotarr->offset + (size_t) l4] = (int32_t) l48;
                                    l49 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l4 + l49);
                                    l4 = (size_t) (int64_t) t0;
                                    goto loop_185;
                                }
                                vader_bytecode_push_or_assign(l10, l3, l9);
                                l50 = ((int32_t) (size_t) l3);
                                vader_array_t* _a99_slotarr = ((vader_array_t*) l14);
                                if (_a99_slotarr->buf != NULL && _a99_slotarr->buf->header.forward != NULL) { _a99_slotarr->buf = vader_array_buf_forward(_a99_slotarr->buf); }
                                if ((size_t) l4 >= _a99_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((int32_t*) _a99_slotarr->buf->slots)[_a99_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                l51 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l3 + l51);
                                l3 = (size_t) (int64_t) t0;
                                l52 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l4 + l52);
                                l4 = (size_t) (int64_t) t0;
                                goto loop_185;
                            }
                            vader_bytecode_push_or_assign(l10, l3, l9);
                            l50 = ((int32_t) (size_t) l3);
                            vader_array_t* _a100_slotarr = ((vader_array_t*) l14);
                            if (_a100_slotarr->buf != NULL && _a100_slotarr->buf->header.forward != NULL) { _a100_slotarr->buf = vader_array_buf_forward(_a100_slotarr->buf); }
                            if ((size_t) l4 >= _a100_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a100_slotarr->buf->slots)[_a100_slotarr->offset + (size_t) l4] = (int32_t) l50;
                            l51 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l3 + l51);
                            l3 = (size_t) (int64_t) t0;
                            l52 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l4 + l52);
                            l4 = (size_t) (int64_t) t0;
                            goto loop_185;
                        }
                        vader_bytecode_push_or_assign(l10, l3, l9);
                        l50 = ((int32_t) (size_t) l3);
                        vader_array_t* _a101_slotarr = ((vader_array_t*) l14);
                        if (_a101_slotarr->buf != NULL && _a101_slotarr->buf->header.forward != NULL) { _a101_slotarr->buf = vader_array_buf_forward(_a101_slotarr->buf); }
                        if ((size_t) l4 >= _a101_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((int32_t*) _a101_slotarr->buf->slots)[_a101_slotarr->offset + (size_t) l4] = (int32_t) l50;
                        l51 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l3 + l51);
                        l3 = (size_t) (int64_t) t0;
                        l52 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l4 + l52);
                        l4 = (size_t) (int64_t) t0;
                        goto loop_185;
                    }
                    if (l9.tag == 618u) {
                        l20 = ((vader_array_t*) l10)->length;
                        l30 = (size_t) (int64_t) INT64_C(0);
                        if ((l20 > l30)) {
                            l31 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l20 - l31);
                            l32 = (size_t) (int64_t) t0;
                            vader_array_t* _a102_slotarr = ((vader_array_t*) l10);
                            if (_a102_slotarr->buf != NULL && _a102_slotarr->buf->header.forward != NULL) { _a102_slotarr->buf = vader_array_buf_forward(_a102_slotarr->buf); }
                            if ((size_t) l32 >= _a102_slotarr->length) { vader_trap("array index out of bounds"); }
                            t3 = vader_array_ref_load_box(_a102_slotarr->buf, _a102_slotarr->offset + (size_t) l32);
                            l33 = vader_bytecode_const_op_of(t3);
                            if (!(l33.tag == 0u)) {
                                l34 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l20 - l34);
                                l35 = (size_t) (int64_t) t0;
                                vader_struct_vader_bytecode_ReturnLit_t* _a103_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                                vader_obj_header_init(_a103_obj, 619u);
                                _a103_obj->f_value = l33;
                                l36 = (void*) _a103_obj;
                                vader_array_t* _a104_slotarr = ((vader_array_t*) l10);
                                if (_a104_slotarr->buf != NULL && _a104_slotarr->buf->header.forward != NULL) { _a104_slotarr->buf = vader_array_buf_forward(_a104_slotarr->buf); }
                                if ((size_t) l35 >= _a104_slotarr->length) { vader_trap("array index out of bounds"); }
                                vader_array_ref_store(_a104_slotarr->buf, _a104_slotarr->offset + (size_t) l35, l36);
                                VADER_WRITE_BARRIER(_a104_slotarr->buf);
                                l37 = (size_t) (int64_t) INT64_C(1);
                                l38 = ((int32_t) (int64_t) (l3 - l37));
                                vader_array_t* _a105_slotarr = ((vader_array_t*) l14);
                                if (_a105_slotarr->buf != NULL && _a105_slotarr->buf->header.forward != NULL) { _a105_slotarr->buf = vader_array_buf_forward(_a105_slotarr->buf); }
                                if ((size_t) l4 >= _a105_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((int32_t*) _a105_slotarr->buf->slots)[_a105_slotarr->offset + (size_t) l4] = (int32_t) l38;
                                l39 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l4 + l39);
                                l4 = (size_t) (int64_t) t0;
                                goto loop_185;
                            }
                            if (l9.tag == 520u) {
                                l40 = (size_t) (int64_t) INT64_C(0);
                                if ((l3 > l40)) {
                                    l41 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l3 - l41);
                                    l42 = (size_t) (int64_t) t0;
                                    vader_array_t* _a106_slotarr = ((vader_array_t*) l10);
                                    if (_a106_slotarr->buf != NULL && _a106_slotarr->buf->header.forward != NULL) { _a106_slotarr->buf = vader_array_buf_forward(_a106_slotarr->buf); }
                                    if ((size_t) l42 >= _a106_slotarr->length) { vader_trap("array index out of bounds"); }
                                    l43 = vader_array_ref_load_box(_a106_slotarr->buf, _a106_slotarr->offset + (size_t) l42);
                                    if (l43.tag == 520u) {
                                        l44 = -(INT32_C(1));
                                        vader_array_t* _a107_slotarr = ((vader_array_t*) l14);
                                        if (_a107_slotarr->buf != NULL && _a107_slotarr->buf->header.forward != NULL) { _a107_slotarr->buf = vader_array_buf_forward(_a107_slotarr->buf); }
                                        if ((size_t) l4 >= _a107_slotarr->length) { vader_trap("array index out of bounds"); }
                                        ((int32_t*) _a107_slotarr->buf->slots)[_a107_slotarr->offset + (size_t) l4] = (int32_t) l44;
                                        l45 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l3 - l45);
                                        l3 = (size_t) (int64_t) t0;
                                        l46 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l4 + l46);
                                        l4 = (size_t) (int64_t) t0;
                                        goto loop_185;
                                    }
                                    if (l43.tag == 517u) {
                                        t2 = l43.payload.obj;
                                        t5 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                        vader_struct_vader_bytecode_BoolConst_t* _a108_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                        vader_obj_header_init(_a108_obj, 517u);
                                        _a108_obj->f_value = !(t5);
                                        l47 = (void*) _a108_obj;
                                        vader_array_t* _a109_slotarr = ((vader_array_t*) l10);
                                        if (_a109_slotarr->buf != NULL && _a109_slotarr->buf->header.forward != NULL) { _a109_slotarr->buf = vader_array_buf_forward(_a109_slotarr->buf); }
                                        if ((size_t) l42 >= _a109_slotarr->length) { vader_trap("array index out of bounds"); }
                                        vader_array_ref_store(_a109_slotarr->buf, _a109_slotarr->offset + (size_t) l42, l47);
                                        VADER_WRITE_BARRIER(_a109_slotarr->buf);
                                        l48 = ((int32_t) (size_t) l42);
                                        vader_array_t* _a110_slotarr = ((vader_array_t*) l14);
                                        if (_a110_slotarr->buf != NULL && _a110_slotarr->buf->header.forward != NULL) { _a110_slotarr->buf = vader_array_buf_forward(_a110_slotarr->buf); }
                                        if ((size_t) l4 >= _a110_slotarr->length) { vader_trap("array index out of bounds"); }
                                        ((int32_t*) _a110_slotarr->buf->slots)[_a110_slotarr->offset + (size_t) l4] = (int32_t) l48;
                                        l49 = (size_t) (int64_t) INT64_C(1);
                                        t0 = (l4 + l49);
                                        l4 = (size_t) (int64_t) t0;
                                        goto loop_185;
                                    }
                                    vader_bytecode_push_or_assign(l10, l3, l9);
                                    l50 = ((int32_t) (size_t) l3);
                                    vader_array_t* _a111_slotarr = ((vader_array_t*) l14);
                                    if (_a111_slotarr->buf != NULL && _a111_slotarr->buf->header.forward != NULL) { _a111_slotarr->buf = vader_array_buf_forward(_a111_slotarr->buf); }
                                    if ((size_t) l4 >= _a111_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((int32_t*) _a111_slotarr->buf->slots)[_a111_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                    l51 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l3 + l51);
                                    l3 = (size_t) (int64_t) t0;
                                    l52 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l4 + l52);
                                    l4 = (size_t) (int64_t) t0;
                                    goto loop_185;
                                }
                                vader_bytecode_push_or_assign(l10, l3, l9);
                                l50 = ((int32_t) (size_t) l3);
                                vader_array_t* _a112_slotarr = ((vader_array_t*) l14);
                                if (_a112_slotarr->buf != NULL && _a112_slotarr->buf->header.forward != NULL) { _a112_slotarr->buf = vader_array_buf_forward(_a112_slotarr->buf); }
                                if ((size_t) l4 >= _a112_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((int32_t*) _a112_slotarr->buf->slots)[_a112_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                l51 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l3 + l51);
                                l3 = (size_t) (int64_t) t0;
                                l52 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l4 + l52);
                                l4 = (size_t) (int64_t) t0;
                                goto loop_185;
                            }
                            vader_bytecode_push_or_assign(l10, l3, l9);
                            l50 = ((int32_t) (size_t) l3);
                            vader_array_t* _a113_slotarr = ((vader_array_t*) l14);
                            if (_a113_slotarr->buf != NULL && _a113_slotarr->buf->header.forward != NULL) { _a113_slotarr->buf = vader_array_buf_forward(_a113_slotarr->buf); }
                            if ((size_t) l4 >= _a113_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a113_slotarr->buf->slots)[_a113_slotarr->offset + (size_t) l4] = (int32_t) l50;
                            l51 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l3 + l51);
                            l3 = (size_t) (int64_t) t0;
                            l52 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l4 + l52);
                            l4 = (size_t) (int64_t) t0;
                            goto loop_185;
                        }
                        if (l9.tag == 520u) {
                            l40 = (size_t) (int64_t) INT64_C(0);
                            if ((l3 > l40)) {
                                l41 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l3 - l41);
                                l42 = (size_t) (int64_t) t0;
                                vader_array_t* _a114_slotarr = ((vader_array_t*) l10);
                                if (_a114_slotarr->buf != NULL && _a114_slotarr->buf->header.forward != NULL) { _a114_slotarr->buf = vader_array_buf_forward(_a114_slotarr->buf); }
                                if ((size_t) l42 >= _a114_slotarr->length) { vader_trap("array index out of bounds"); }
                                l43 = vader_array_ref_load_box(_a114_slotarr->buf, _a114_slotarr->offset + (size_t) l42);
                                if (l43.tag == 520u) {
                                    l44 = -(INT32_C(1));
                                    vader_array_t* _a115_slotarr = ((vader_array_t*) l14);
                                    if (_a115_slotarr->buf != NULL && _a115_slotarr->buf->header.forward != NULL) { _a115_slotarr->buf = vader_array_buf_forward(_a115_slotarr->buf); }
                                    if ((size_t) l4 >= _a115_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((int32_t*) _a115_slotarr->buf->slots)[_a115_slotarr->offset + (size_t) l4] = (int32_t) l44;
                                    l45 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l3 - l45);
                                    l3 = (size_t) (int64_t) t0;
                                    l46 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l4 + l46);
                                    l4 = (size_t) (int64_t) t0;
                                    goto loop_185;
                                }
                                if (l43.tag == 517u) {
                                    t2 = l43.payload.obj;
                                    t5 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                    vader_struct_vader_bytecode_BoolConst_t* _a116_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                    vader_obj_header_init(_a116_obj, 517u);
                                    _a116_obj->f_value = !(t5);
                                    l47 = (void*) _a116_obj;
                                    vader_array_t* _a117_slotarr = ((vader_array_t*) l10);
                                    if (_a117_slotarr->buf != NULL && _a117_slotarr->buf->header.forward != NULL) { _a117_slotarr->buf = vader_array_buf_forward(_a117_slotarr->buf); }
                                    if ((size_t) l42 >= _a117_slotarr->length) { vader_trap("array index out of bounds"); }
                                    vader_array_ref_store(_a117_slotarr->buf, _a117_slotarr->offset + (size_t) l42, l47);
                                    VADER_WRITE_BARRIER(_a117_slotarr->buf);
                                    l48 = ((int32_t) (size_t) l42);
                                    vader_array_t* _a118_slotarr = ((vader_array_t*) l14);
                                    if (_a118_slotarr->buf != NULL && _a118_slotarr->buf->header.forward != NULL) { _a118_slotarr->buf = vader_array_buf_forward(_a118_slotarr->buf); }
                                    if ((size_t) l4 >= _a118_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((int32_t*) _a118_slotarr->buf->slots)[_a118_slotarr->offset + (size_t) l4] = (int32_t) l48;
                                    l49 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l4 + l49);
                                    l4 = (size_t) (int64_t) t0;
                                    goto loop_185;
                                }
                                vader_bytecode_push_or_assign(l10, l3, l9);
                                l50 = ((int32_t) (size_t) l3);
                                vader_array_t* _a119_slotarr = ((vader_array_t*) l14);
                                if (_a119_slotarr->buf != NULL && _a119_slotarr->buf->header.forward != NULL) { _a119_slotarr->buf = vader_array_buf_forward(_a119_slotarr->buf); }
                                if ((size_t) l4 >= _a119_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((int32_t*) _a119_slotarr->buf->slots)[_a119_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                l51 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l3 + l51);
                                l3 = (size_t) (int64_t) t0;
                                l52 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l4 + l52);
                                l4 = (size_t) (int64_t) t0;
                                goto loop_185;
                            }
                            vader_bytecode_push_or_assign(l10, l3, l9);
                            l50 = ((int32_t) (size_t) l3);
                            vader_array_t* _a120_slotarr = ((vader_array_t*) l14);
                            if (_a120_slotarr->buf != NULL && _a120_slotarr->buf->header.forward != NULL) { _a120_slotarr->buf = vader_array_buf_forward(_a120_slotarr->buf); }
                            if ((size_t) l4 >= _a120_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a120_slotarr->buf->slots)[_a120_slotarr->offset + (size_t) l4] = (int32_t) l50;
                            l51 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l3 + l51);
                            l3 = (size_t) (int64_t) t0;
                            l52 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l4 + l52);
                            l4 = (size_t) (int64_t) t0;
                            goto loop_185;
                        }
                        vader_bytecode_push_or_assign(l10, l3, l9);
                        l50 = ((int32_t) (size_t) l3);
                        vader_array_t* _a121_slotarr = ((vader_array_t*) l14);
                        if (_a121_slotarr->buf != NULL && _a121_slotarr->buf->header.forward != NULL) { _a121_slotarr->buf = vader_array_buf_forward(_a121_slotarr->buf); }
                        if ((size_t) l4 >= _a121_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((int32_t*) _a121_slotarr->buf->slots)[_a121_slotarr->offset + (size_t) l4] = (int32_t) l50;
                        l51 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l3 + l51);
                        l3 = (size_t) (int64_t) t0;
                        l52 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l4 + l52);
                        l4 = (size_t) (int64_t) t0;
                        goto loop_185;
                    }
                    if (l9.tag == 520u) {
                        l40 = (size_t) (int64_t) INT64_C(0);
                        if ((l3 > l40)) {
                            l41 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l3 - l41);
                            l42 = (size_t) (int64_t) t0;
                            vader_array_t* _a122_slotarr = ((vader_array_t*) l10);
                            if (_a122_slotarr->buf != NULL && _a122_slotarr->buf->header.forward != NULL) { _a122_slotarr->buf = vader_array_buf_forward(_a122_slotarr->buf); }
                            if ((size_t) l42 >= _a122_slotarr->length) { vader_trap("array index out of bounds"); }
                            l43 = vader_array_ref_load_box(_a122_slotarr->buf, _a122_slotarr->offset + (size_t) l42);
                            if (l43.tag == 520u) {
                                l44 = -(INT32_C(1));
                                vader_array_t* _a123_slotarr = ((vader_array_t*) l14);
                                if (_a123_slotarr->buf != NULL && _a123_slotarr->buf->header.forward != NULL) { _a123_slotarr->buf = vader_array_buf_forward(_a123_slotarr->buf); }
                                if ((size_t) l4 >= _a123_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((int32_t*) _a123_slotarr->buf->slots)[_a123_slotarr->offset + (size_t) l4] = (int32_t) l44;
                                l45 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l3 - l45);
                                l3 = (size_t) (int64_t) t0;
                                l46 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l4 + l46);
                                l4 = (size_t) (int64_t) t0;
                                goto loop_185;
                            }
                            if (l43.tag == 517u) {
                                t2 = l43.payload.obj;
                                t5 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                vader_struct_vader_bytecode_BoolConst_t* _a124_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                vader_obj_header_init(_a124_obj, 517u);
                                _a124_obj->f_value = !(t5);
                                l47 = (void*) _a124_obj;
                                vader_array_t* _a125_slotarr = ((vader_array_t*) l10);
                                if (_a125_slotarr->buf != NULL && _a125_slotarr->buf->header.forward != NULL) { _a125_slotarr->buf = vader_array_buf_forward(_a125_slotarr->buf); }
                                if ((size_t) l42 >= _a125_slotarr->length) { vader_trap("array index out of bounds"); }
                                vader_array_ref_store(_a125_slotarr->buf, _a125_slotarr->offset + (size_t) l42, l47);
                                VADER_WRITE_BARRIER(_a125_slotarr->buf);
                                l48 = ((int32_t) (size_t) l42);
                                vader_array_t* _a126_slotarr = ((vader_array_t*) l14);
                                if (_a126_slotarr->buf != NULL && _a126_slotarr->buf->header.forward != NULL) { _a126_slotarr->buf = vader_array_buf_forward(_a126_slotarr->buf); }
                                if ((size_t) l4 >= _a126_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((int32_t*) _a126_slotarr->buf->slots)[_a126_slotarr->offset + (size_t) l4] = (int32_t) l48;
                                l49 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l4 + l49);
                                l4 = (size_t) (int64_t) t0;
                                goto loop_185;
                            }
                            vader_bytecode_push_or_assign(l10, l3, l9);
                            l50 = ((int32_t) (size_t) l3);
                            vader_array_t* _a127_slotarr = ((vader_array_t*) l14);
                            if (_a127_slotarr->buf != NULL && _a127_slotarr->buf->header.forward != NULL) { _a127_slotarr->buf = vader_array_buf_forward(_a127_slotarr->buf); }
                            if ((size_t) l4 >= _a127_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a127_slotarr->buf->slots)[_a127_slotarr->offset + (size_t) l4] = (int32_t) l50;
                            l51 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l3 + l51);
                            l3 = (size_t) (int64_t) t0;
                            l52 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l4 + l52);
                            l4 = (size_t) (int64_t) t0;
                            goto loop_185;
                        }
                        vader_bytecode_push_or_assign(l10, l3, l9);
                        l50 = ((int32_t) (size_t) l3);
                        vader_array_t* _a128_slotarr = ((vader_array_t*) l14);
                        if (_a128_slotarr->buf != NULL && _a128_slotarr->buf->header.forward != NULL) { _a128_slotarr->buf = vader_array_buf_forward(_a128_slotarr->buf); }
                        if ((size_t) l4 >= _a128_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((int32_t*) _a128_slotarr->buf->slots)[_a128_slotarr->offset + (size_t) l4] = (int32_t) l50;
                        l51 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l3 + l51);
                        l3 = (size_t) (int64_t) t0;
                        l52 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l4 + l52);
                        l4 = (size_t) (int64_t) t0;
                        goto loop_185;
                    }
                    vader_bytecode_push_or_assign(l10, l3, l9);
                    l50 = ((int32_t) (size_t) l3);
                    vader_array_t* _a129_slotarr = ((vader_array_t*) l14);
                    if (_a129_slotarr->buf != NULL && _a129_slotarr->buf->header.forward != NULL) { _a129_slotarr->buf = vader_array_buf_forward(_a129_slotarr->buf); }
                    if ((size_t) l4 >= _a129_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a129_slotarr->buf->slots)[_a129_slotarr->offset + (size_t) l4] = (int32_t) l50;
                    l51 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l51);
                    l3 = (size_t) (int64_t) t0;
                    l52 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l4 + l52);
                    l4 = (size_t) (int64_t) t0;
                    goto loop_185;
                }
                if (l9.tag == 618u) {
                    l20 = ((vader_array_t*) l10)->length;
                    l30 = (size_t) (int64_t) INT64_C(0);
                    if ((l20 > l30)) {
                        l31 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l20 - l31);
                        l32 = (size_t) (int64_t) t0;
                        vader_array_t* _a130_slotarr = ((vader_array_t*) l10);
                        if (_a130_slotarr->buf != NULL && _a130_slotarr->buf->header.forward != NULL) { _a130_slotarr->buf = vader_array_buf_forward(_a130_slotarr->buf); }
                        if ((size_t) l32 >= _a130_slotarr->length) { vader_trap("array index out of bounds"); }
                        t3 = vader_array_ref_load_box(_a130_slotarr->buf, _a130_slotarr->offset + (size_t) l32);
                        l33 = vader_bytecode_const_op_of(t3);
                        if (!(l33.tag == 0u)) {
                            l34 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l20 - l34);
                            l35 = (size_t) (int64_t) t0;
                            vader_struct_vader_bytecode_ReturnLit_t* _a131_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                            vader_obj_header_init(_a131_obj, 619u);
                            _a131_obj->f_value = l33;
                            l36 = (void*) _a131_obj;
                            vader_array_t* _a132_slotarr = ((vader_array_t*) l10);
                            if (_a132_slotarr->buf != NULL && _a132_slotarr->buf->header.forward != NULL) { _a132_slotarr->buf = vader_array_buf_forward(_a132_slotarr->buf); }
                            if ((size_t) l35 >= _a132_slotarr->length) { vader_trap("array index out of bounds"); }
                            vader_array_ref_store(_a132_slotarr->buf, _a132_slotarr->offset + (size_t) l35, l36);
                            VADER_WRITE_BARRIER(_a132_slotarr->buf);
                            l37 = (size_t) (int64_t) INT64_C(1);
                            l38 = ((int32_t) (int64_t) (l3 - l37));
                            vader_array_t* _a133_slotarr = ((vader_array_t*) l14);
                            if (_a133_slotarr->buf != NULL && _a133_slotarr->buf->header.forward != NULL) { _a133_slotarr->buf = vader_array_buf_forward(_a133_slotarr->buf); }
                            if ((size_t) l4 >= _a133_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a133_slotarr->buf->slots)[_a133_slotarr->offset + (size_t) l4] = (int32_t) l38;
                            l39 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l4 + l39);
                            l4 = (size_t) (int64_t) t0;
                            goto loop_185;
                        }
                        if (l9.tag == 520u) {
                            l40 = (size_t) (int64_t) INT64_C(0);
                            if ((l3 > l40)) {
                                l41 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l3 - l41);
                                l42 = (size_t) (int64_t) t0;
                                vader_array_t* _a134_slotarr = ((vader_array_t*) l10);
                                if (_a134_slotarr->buf != NULL && _a134_slotarr->buf->header.forward != NULL) { _a134_slotarr->buf = vader_array_buf_forward(_a134_slotarr->buf); }
                                if ((size_t) l42 >= _a134_slotarr->length) { vader_trap("array index out of bounds"); }
                                l43 = vader_array_ref_load_box(_a134_slotarr->buf, _a134_slotarr->offset + (size_t) l42);
                                if (l43.tag == 520u) {
                                    l44 = -(INT32_C(1));
                                    vader_array_t* _a135_slotarr = ((vader_array_t*) l14);
                                    if (_a135_slotarr->buf != NULL && _a135_slotarr->buf->header.forward != NULL) { _a135_slotarr->buf = vader_array_buf_forward(_a135_slotarr->buf); }
                                    if ((size_t) l4 >= _a135_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((int32_t*) _a135_slotarr->buf->slots)[_a135_slotarr->offset + (size_t) l4] = (int32_t) l44;
                                    l45 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l3 - l45);
                                    l3 = (size_t) (int64_t) t0;
                                    l46 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l4 + l46);
                                    l4 = (size_t) (int64_t) t0;
                                    goto loop_185;
                                }
                                if (l43.tag == 517u) {
                                    t2 = l43.payload.obj;
                                    t5 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                    vader_struct_vader_bytecode_BoolConst_t* _a136_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                    vader_obj_header_init(_a136_obj, 517u);
                                    _a136_obj->f_value = !(t5);
                                    l47 = (void*) _a136_obj;
                                    vader_array_t* _a137_slotarr = ((vader_array_t*) l10);
                                    if (_a137_slotarr->buf != NULL && _a137_slotarr->buf->header.forward != NULL) { _a137_slotarr->buf = vader_array_buf_forward(_a137_slotarr->buf); }
                                    if ((size_t) l42 >= _a137_slotarr->length) { vader_trap("array index out of bounds"); }
                                    vader_array_ref_store(_a137_slotarr->buf, _a137_slotarr->offset + (size_t) l42, l47);
                                    VADER_WRITE_BARRIER(_a137_slotarr->buf);
                                    l48 = ((int32_t) (size_t) l42);
                                    vader_array_t* _a138_slotarr = ((vader_array_t*) l14);
                                    if (_a138_slotarr->buf != NULL && _a138_slotarr->buf->header.forward != NULL) { _a138_slotarr->buf = vader_array_buf_forward(_a138_slotarr->buf); }
                                    if ((size_t) l4 >= _a138_slotarr->length) { vader_trap("array index out of bounds"); }
                                    ((int32_t*) _a138_slotarr->buf->slots)[_a138_slotarr->offset + (size_t) l4] = (int32_t) l48;
                                    l49 = (size_t) (int64_t) INT64_C(1);
                                    t0 = (l4 + l49);
                                    l4 = (size_t) (int64_t) t0;
                                    goto loop_185;
                                }
                                vader_bytecode_push_or_assign(l10, l3, l9);
                                l50 = ((int32_t) (size_t) l3);
                                vader_array_t* _a139_slotarr = ((vader_array_t*) l14);
                                if (_a139_slotarr->buf != NULL && _a139_slotarr->buf->header.forward != NULL) { _a139_slotarr->buf = vader_array_buf_forward(_a139_slotarr->buf); }
                                if ((size_t) l4 >= _a139_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((int32_t*) _a139_slotarr->buf->slots)[_a139_slotarr->offset + (size_t) l4] = (int32_t) l50;
                                l51 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l3 + l51);
                                l3 = (size_t) (int64_t) t0;
                                l52 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l4 + l52);
                                l4 = (size_t) (int64_t) t0;
                                goto loop_185;
                            }
                            vader_bytecode_push_or_assign(l10, l3, l9);
                            l50 = ((int32_t) (size_t) l3);
                            vader_array_t* _a140_slotarr = ((vader_array_t*) l14);
                            if (_a140_slotarr->buf != NULL && _a140_slotarr->buf->header.forward != NULL) { _a140_slotarr->buf = vader_array_buf_forward(_a140_slotarr->buf); }
                            if ((size_t) l4 >= _a140_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a140_slotarr->buf->slots)[_a140_slotarr->offset + (size_t) l4] = (int32_t) l50;
                            l51 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l3 + l51);
                            l3 = (size_t) (int64_t) t0;
                            l52 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l4 + l52);
                            l4 = (size_t) (int64_t) t0;
                            goto loop_185;
                        }
                        vader_bytecode_push_or_assign(l10, l3, l9);
                        l50 = ((int32_t) (size_t) l3);
                        vader_array_t* _a141_slotarr = ((vader_array_t*) l14);
                        if (_a141_slotarr->buf != NULL && _a141_slotarr->buf->header.forward != NULL) { _a141_slotarr->buf = vader_array_buf_forward(_a141_slotarr->buf); }
                        if ((size_t) l4 >= _a141_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((int32_t*) _a141_slotarr->buf->slots)[_a141_slotarr->offset + (size_t) l4] = (int32_t) l50;
                        l51 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l3 + l51);
                        l3 = (size_t) (int64_t) t0;
                        l52 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l4 + l52);
                        l4 = (size_t) (int64_t) t0;
                        goto loop_185;
                    }
                    if (l9.tag == 520u) {
                        l40 = (size_t) (int64_t) INT64_C(0);
                        if ((l3 > l40)) {
                            l41 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l3 - l41);
                            l42 = (size_t) (int64_t) t0;
                            vader_array_t* _a142_slotarr = ((vader_array_t*) l10);
                            if (_a142_slotarr->buf != NULL && _a142_slotarr->buf->header.forward != NULL) { _a142_slotarr->buf = vader_array_buf_forward(_a142_slotarr->buf); }
                            if ((size_t) l42 >= _a142_slotarr->length) { vader_trap("array index out of bounds"); }
                            l43 = vader_array_ref_load_box(_a142_slotarr->buf, _a142_slotarr->offset + (size_t) l42);
                            if (l43.tag == 520u) {
                                l44 = -(INT32_C(1));
                                vader_array_t* _a143_slotarr = ((vader_array_t*) l14);
                                if (_a143_slotarr->buf != NULL && _a143_slotarr->buf->header.forward != NULL) { _a143_slotarr->buf = vader_array_buf_forward(_a143_slotarr->buf); }
                                if ((size_t) l4 >= _a143_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((int32_t*) _a143_slotarr->buf->slots)[_a143_slotarr->offset + (size_t) l4] = (int32_t) l44;
                                l45 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l3 - l45);
                                l3 = (size_t) (int64_t) t0;
                                l46 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l4 + l46);
                                l4 = (size_t) (int64_t) t0;
                                goto loop_185;
                            }
                            if (l43.tag == 517u) {
                                t2 = l43.payload.obj;
                                t5 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                                vader_struct_vader_bytecode_BoolConst_t* _a144_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                                vader_obj_header_init(_a144_obj, 517u);
                                _a144_obj->f_value = !(t5);
                                l47 = (void*) _a144_obj;
                                vader_array_t* _a145_slotarr = ((vader_array_t*) l10);
                                if (_a145_slotarr->buf != NULL && _a145_slotarr->buf->header.forward != NULL) { _a145_slotarr->buf = vader_array_buf_forward(_a145_slotarr->buf); }
                                if ((size_t) l42 >= _a145_slotarr->length) { vader_trap("array index out of bounds"); }
                                vader_array_ref_store(_a145_slotarr->buf, _a145_slotarr->offset + (size_t) l42, l47);
                                VADER_WRITE_BARRIER(_a145_slotarr->buf);
                                l48 = ((int32_t) (size_t) l42);
                                vader_array_t* _a146_slotarr = ((vader_array_t*) l14);
                                if (_a146_slotarr->buf != NULL && _a146_slotarr->buf->header.forward != NULL) { _a146_slotarr->buf = vader_array_buf_forward(_a146_slotarr->buf); }
                                if ((size_t) l4 >= _a146_slotarr->length) { vader_trap("array index out of bounds"); }
                                ((int32_t*) _a146_slotarr->buf->slots)[_a146_slotarr->offset + (size_t) l4] = (int32_t) l48;
                                l49 = (size_t) (int64_t) INT64_C(1);
                                t0 = (l4 + l49);
                                l4 = (size_t) (int64_t) t0;
                                goto loop_185;
                            }
                            vader_bytecode_push_or_assign(l10, l3, l9);
                            l50 = ((int32_t) (size_t) l3);
                            vader_array_t* _a147_slotarr = ((vader_array_t*) l14);
                            if (_a147_slotarr->buf != NULL && _a147_slotarr->buf->header.forward != NULL) { _a147_slotarr->buf = vader_array_buf_forward(_a147_slotarr->buf); }
                            if ((size_t) l4 >= _a147_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a147_slotarr->buf->slots)[_a147_slotarr->offset + (size_t) l4] = (int32_t) l50;
                            l51 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l3 + l51);
                            l3 = (size_t) (int64_t) t0;
                            l52 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l4 + l52);
                            l4 = (size_t) (int64_t) t0;
                            goto loop_185;
                        }
                        vader_bytecode_push_or_assign(l10, l3, l9);
                        l50 = ((int32_t) (size_t) l3);
                        vader_array_t* _a148_slotarr = ((vader_array_t*) l14);
                        if (_a148_slotarr->buf != NULL && _a148_slotarr->buf->header.forward != NULL) { _a148_slotarr->buf = vader_array_buf_forward(_a148_slotarr->buf); }
                        if ((size_t) l4 >= _a148_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((int32_t*) _a148_slotarr->buf->slots)[_a148_slotarr->offset + (size_t) l4] = (int32_t) l50;
                        l51 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l3 + l51);
                        l3 = (size_t) (int64_t) t0;
                        l52 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l4 + l52);
                        l4 = (size_t) (int64_t) t0;
                        goto loop_185;
                    }
                    vader_bytecode_push_or_assign(l10, l3, l9);
                    l50 = ((int32_t) (size_t) l3);
                    vader_array_t* _a149_slotarr = ((vader_array_t*) l14);
                    if (_a149_slotarr->buf != NULL && _a149_slotarr->buf->header.forward != NULL) { _a149_slotarr->buf = vader_array_buf_forward(_a149_slotarr->buf); }
                    if ((size_t) l4 >= _a149_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a149_slotarr->buf->slots)[_a149_slotarr->offset + (size_t) l4] = (int32_t) l50;
                    l51 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l51);
                    l3 = (size_t) (int64_t) t0;
                    l52 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l4 + l52);
                    l4 = (size_t) (int64_t) t0;
                    goto loop_185;
                }
                if (l9.tag == 520u) {
                    l40 = (size_t) (int64_t) INT64_C(0);
                    if ((l3 > l40)) {
                        l41 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l3 - l41);
                        l42 = (size_t) (int64_t) t0;
                        vader_array_t* _a150_slotarr = ((vader_array_t*) l10);
                        if (_a150_slotarr->buf != NULL && _a150_slotarr->buf->header.forward != NULL) { _a150_slotarr->buf = vader_array_buf_forward(_a150_slotarr->buf); }
                        if ((size_t) l42 >= _a150_slotarr->length) { vader_trap("array index out of bounds"); }
                        l43 = vader_array_ref_load_box(_a150_slotarr->buf, _a150_slotarr->offset + (size_t) l42);
                        if (l43.tag == 520u) {
                            l44 = -(INT32_C(1));
                            vader_array_t* _a151_slotarr = ((vader_array_t*) l14);
                            if (_a151_slotarr->buf != NULL && _a151_slotarr->buf->header.forward != NULL) { _a151_slotarr->buf = vader_array_buf_forward(_a151_slotarr->buf); }
                            if ((size_t) l4 >= _a151_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a151_slotarr->buf->slots)[_a151_slotarr->offset + (size_t) l4] = (int32_t) l44;
                            l45 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l3 - l45);
                            l3 = (size_t) (int64_t) t0;
                            l46 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l4 + l46);
                            l4 = (size_t) (int64_t) t0;
                            goto loop_185;
                        }
                        if (l43.tag == 517u) {
                            t2 = l43.payload.obj;
                            t5 = ((vader_struct_vader_bytecode_BoolConst_t*) t2)->f_value;
                            vader_struct_vader_bytecode_BoolConst_t* _a152_obj = (vader_struct_vader_bytecode_BoolConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolConst_t));
                            vader_obj_header_init(_a152_obj, 517u);
                            _a152_obj->f_value = !(t5);
                            l47 = (void*) _a152_obj;
                            vader_array_t* _a153_slotarr = ((vader_array_t*) l10);
                            if (_a153_slotarr->buf != NULL && _a153_slotarr->buf->header.forward != NULL) { _a153_slotarr->buf = vader_array_buf_forward(_a153_slotarr->buf); }
                            if ((size_t) l42 >= _a153_slotarr->length) { vader_trap("array index out of bounds"); }
                            vader_array_ref_store(_a153_slotarr->buf, _a153_slotarr->offset + (size_t) l42, l47);
                            VADER_WRITE_BARRIER(_a153_slotarr->buf);
                            l48 = ((int32_t) (size_t) l42);
                            vader_array_t* _a154_slotarr = ((vader_array_t*) l14);
                            if (_a154_slotarr->buf != NULL && _a154_slotarr->buf->header.forward != NULL) { _a154_slotarr->buf = vader_array_buf_forward(_a154_slotarr->buf); }
                            if ((size_t) l4 >= _a154_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a154_slotarr->buf->slots)[_a154_slotarr->offset + (size_t) l4] = (int32_t) l48;
                            l49 = (size_t) (int64_t) INT64_C(1);
                            t0 = (l4 + l49);
                            l4 = (size_t) (int64_t) t0;
                            goto loop_185;
                        }
                        vader_bytecode_push_or_assign(l10, l3, l9);
                        l50 = ((int32_t) (size_t) l3);
                        vader_array_t* _a155_slotarr = ((vader_array_t*) l14);
                        if (_a155_slotarr->buf != NULL && _a155_slotarr->buf->header.forward != NULL) { _a155_slotarr->buf = vader_array_buf_forward(_a155_slotarr->buf); }
                        if ((size_t) l4 >= _a155_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((int32_t*) _a155_slotarr->buf->slots)[_a155_slotarr->offset + (size_t) l4] = (int32_t) l50;
                        l51 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l3 + l51);
                        l3 = (size_t) (int64_t) t0;
                        l52 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l4 + l52);
                        l4 = (size_t) (int64_t) t0;
                        goto loop_185;
                    }
                    vader_bytecode_push_or_assign(l10, l3, l9);
                    l50 = ((int32_t) (size_t) l3);
                    vader_array_t* _a156_slotarr = ((vader_array_t*) l14);
                    if (_a156_slotarr->buf != NULL && _a156_slotarr->buf->header.forward != NULL) { _a156_slotarr->buf = vader_array_buf_forward(_a156_slotarr->buf); }
                    if ((size_t) l4 >= _a156_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a156_slotarr->buf->slots)[_a156_slotarr->offset + (size_t) l4] = (int32_t) l50;
                    l51 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l3 + l51);
                    l3 = (size_t) (int64_t) t0;
                    l52 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l4 + l52);
                    l4 = (size_t) (int64_t) t0;
                    goto loop_185;
                }
                vader_bytecode_push_or_assign(l10, l3, l9);
                l50 = ((int32_t) (size_t) l3);
                vader_array_t* _a157_slotarr = ((vader_array_t*) l14);
                if (_a157_slotarr->buf != NULL && _a157_slotarr->buf->header.forward != NULL) { _a157_slotarr->buf = vader_array_buf_forward(_a157_slotarr->buf); }
                if ((size_t) l4 >= _a157_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a157_slotarr->buf->slots)[_a157_slotarr->offset + (size_t) l4] = (int32_t) l50;
                l51 = (size_t) (int64_t) INT64_C(1);
                t0 = (l3 + l51);
                l3 = (size_t) (int64_t) t0;
                l52 = (size_t) (int64_t) INT64_C(1);
                t0 = (l4 + l52);
                l4 = (size_t) (int64_t) t0;
                goto loop_185;
            } else {
            }
        }
    }
    vader_array_t* _a158_arr = vader_array_slice((vader_array_t*) l10, (size_t) INT64_C(0), (size_t) l3);
    l1 = (void*) _a158_arr;
    l5 = vader_bytecode_remap_jump_table(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l14, l3);
    l6 = vader_bytecode_remap_debug(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug, l14, l3);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a159_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a159_obj, 501u);
    _a159_obj->f_body = l1;
    _a159_obj->f_jump_table = l5;
    _a159_obj->f_debug = l6;
    t2 = (void*) _a159_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_bytecode_run_bc_return_lit_fold(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l13 = NULL;
    size_t l2, l4, l6, l9, l10, l12, l15, l16;
    int32_t l7, l14;
    vader_box_t l8 = vader_box_null(), l11 = vader_box_null();
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l8, &l11, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l5, &l13, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_body;
    l2 = ((vader_array_t*) l1)->length;
    vader_array_t* _a0_arr = vader_array_new(117u, 0u, 13u, 1070u);
    l3 = (void*) _a0_arr;
    l4 = (size_t) (int64_t) INT64_C(0);
    vader_array_t* _a1_arr = vader_array_new(9u, 0u, 7u, 166u);
    l5 = (void*) _a1_arr;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_13: {
            if ((l6 < l2)) {
                l7 = -(INT32_C(1));
                vader_array_push_i32((vader_array_t*) l5, l7);
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_13;
            } else {
            }
        }
    }
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_36: {
            if ((l6 < l2)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
                if (l8.tag == 618u) {
                    l9 = ((vader_array_t*) l3)->length;
                    if ((l9 > INT64_C(0))) {
                        t0 = (l9 - INT64_C(1));
                        l10 = (size_t) (int64_t) t0;
                        vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
                        if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                        if ((size_t) l10 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l10);
                        l11 = vader_bytecode_const_op_of(t1);
                        if (!(l11.tag == 0u)) {
                            t0 = (l9 - INT64_C(1));
                            l12 = (size_t) (int64_t) t0;
                            vader_struct_vader_bytecode_ReturnLit_t* _a4_obj = (vader_struct_vader_bytecode_ReturnLit_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_ReturnLit_t));
                            vader_obj_header_init(_a4_obj, 619u);
                            _a4_obj->f_value = l11;
                            l13 = (void*) _a4_obj;
                            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                            if ((size_t) l12 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                            vader_array_ref_store(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l12, l13);
                            VADER_WRITE_BARRIER(_a5_slotarr->buf);
                            l7 = ((int32_t) (int64_t) (l9 - INT64_C(1)));
                            vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
                            if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                            if ((size_t) l6 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                            ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l6] = (int32_t) l7;
                            t0 = (l6 + INT64_C(1));
                            l6 = (size_t) (int64_t) t0;
                            goto loop_36;
                        }
                        vader_bytecode_push_or_assign(l3, l4, l8);
                        l14 = ((int32_t) (size_t) l4);
                        vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
                        if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                        if ((size_t) l6 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l6] = (int32_t) l14;
                        l15 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l4 + l15);
                        l4 = (size_t) (int64_t) t0;
                        l16 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l6 + l16);
                        l6 = (size_t) (int64_t) t0;
                        goto loop_36;
                    }
                    vader_bytecode_push_or_assign(l3, l4, l8);
                    l14 = ((int32_t) (size_t) l4);
                    vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
                    if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                    if ((size_t) l6 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l6] = (int32_t) l14;
                    l15 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l4 + l15);
                    l4 = (size_t) (int64_t) t0;
                    l16 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l6 + l16);
                    l6 = (size_t) (int64_t) t0;
                    goto loop_36;
                }
                vader_bytecode_push_or_assign(l3, l4, l8);
                l14 = ((int32_t) (size_t) l4);
                vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
                if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                if ((size_t) l6 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l6] = (int32_t) l14;
                l15 = (size_t) (int64_t) INT64_C(1);
                t0 = (l4 + l15);
                l4 = (size_t) (int64_t) t0;
                l16 = (size_t) (int64_t) INT64_C(1);
                t0 = (l6 + l16);
                l6 = (size_t) (int64_t) t0;
                goto loop_36;
            } else {
            }
        }
    }
    vader_array_t* _a10_arr = vader_array_slice((vader_array_t*) l3, (size_t) INT64_C(0), (size_t) l4);
    l1 = (void*) _a10_arr;
    l3 = vader_bytecode_remap_jump_table(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table, l5, l4);
    l5 = vader_bytecode_remap_debug(((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug, l5, l4);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a11_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a11_obj, 501u);
    _a11_obj->f_body = l1;
    _a11_obj->f_jump_table = l3;
    _a11_obj->f_debug = l5;
    t2 = (void*) _a11_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
        vader_obj_header_init(_a0_obj, 594u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Shl_t* _a1_obj = (vader_struct_vader_bytecode_I32Shl_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Shl_t));
    vader_obj_header_init(_a1_obj, 574u);
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
            vader_obj_header_init(_a0_obj, 596u);
            t1 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_bytecode_I64Shr_t* _a1_obj = (vader_struct_vader_bytecode_I64Shr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Shr_t));
        vader_obj_header_init(_a1_obj, 595u);
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1) {
        vader_struct_vader_bytecode_I32ShrU_t* _a2_obj = (vader_struct_vader_bytecode_I32ShrU_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32ShrU_t));
        vader_obj_header_init(_a2_obj, 576u);
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_bytecode_I32Shr_t* _a3_obj = (vader_struct_vader_bytecode_I32Shr_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Shr_t));
    vader_obj_header_init(_a3_obj, 575u);
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

int32_t vader_bytecode_size_of_bc_type(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (l0.tag == 503u) {
        t0 = l0.payload.obj;
        t1 = vader_bytecode_size_of_val_type(((vader_struct_vader_bytecode_BcPrimitive_t*) t0)->f_val);
        return t1;
    }
    if (l0.tag == 507u) {
        return INT32_C(16);
    }
    if (l0.tag == 494u) {
        return INT32_C(16);
    }
    if (l0.tag == 508u) {
        return INT32_C(16);
    }
    if (l0.tag == 504u) {
        return INT32_C(16);
    }
    if (l0.tag == 497u) {
        return INT32_C(16);
    }
    vader_unreachable("unreachable return in vader_bytecode$size_of_bc_type");
}

int32_t vader_bytecode_size_of_val_type(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return INT32_C(1);
    }
    if (l0 == INT32_C(5)) {
        return INT32_C(1);
    }
    if (l0 == INT32_C(12)) {
        return INT32_C(1);
    }
    if (l0 == INT32_C(1)) {
        return INT32_C(2);
    }
    if (l0 == INT32_C(6)) {
        return INT32_C(2);
    }
    if (l0 == INT32_C(2)) {
        return INT32_C(4);
    }
    if (l0 == INT32_C(7)) {
        return INT32_C(4);
    }
    if (l0 == INT32_C(10)) {
        return INT32_C(4);
    }
    if (l0 == INT32_C(13)) {
        return INT32_C(4);
    }
    if (l0 == INT32_C(3)) {
        return INT32_C(8);
    }
    if (l0 == INT32_C(8)) {
        return INT32_C(8);
    }
    if (l0 == INT32_C(11)) {
        return INT32_C(8);
    }
    if (l0 == INT32_C(4)) {
        return INT32_C(8);
    }
    if (l0 == INT32_C(9)) {
        return INT32_C(8);
    }
    if (l0 == INT32_C(14)) {
        return INT32_C(16);
    }
    if (l0 == INT32_C(16)) {
        return INT32_C(0);
    }
    if (l0 == INT32_C(15)) {
        return INT32_C(0);
    }
    if (l0 == INT32_C(17)) {
        return INT32_C(8);
    }
    if (l0 == INT32_C(18)) {
        return INT32_C(16);
    }
    if (l0 == INT32_C(19)) {
        return INT32_C(16);
    }
    vader_unreachable("unreachable return in vader_bytecode$size_of_val_type");
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
        vader_obj_header_init(_a0_obj, 604u);
        _a0_obj->f_bounds_safe = l1;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(2)) {
        vader_struct_vader_bytecode_LoadSlotI64_t* _a1_obj = (vader_struct_vader_bytecode_LoadSlotI64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LoadSlotI64_t));
        vader_obj_header_init(_a1_obj, 605u);
        _a1_obj->f_bounds_safe = l1;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(3)) {
        vader_struct_vader_bytecode_LoadSlotF64_t* _a2_obj = (vader_struct_vader_bytecode_LoadSlotF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LoadSlotF64_t));
        vader_obj_header_init(_a2_obj, 603u);
        _a2_obj->f_bounds_safe = l1;
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l2 == INT32_C(4)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_unreachable("unreachable return in vader_bytecode$slot_load_op_for");
    vader_gc_top = gc_frame.prev;
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
        vader_obj_header_init(_a0_obj, 626u);
        _a0_obj->f_bounds_safe = l1;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(2)) {
        vader_struct_vader_bytecode_StoreSlotI64_t* _a1_obj = (vader_struct_vader_bytecode_StoreSlotI64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StoreSlotI64_t));
        vader_obj_header_init(_a1_obj, 627u);
        _a1_obj->f_bounds_safe = l1;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(3)) {
        vader_struct_vader_bytecode_StoreSlotF64_t* _a2_obj = (vader_struct_vader_bytecode_StoreSlotF64_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_StoreSlotF64_t));
        vader_obj_header_init(_a2_obj, 625u);
        _a2_obj->f_bounds_safe = l1;
        t1 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l2 == INT32_C(4)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_unreachable("unreachable return in vader_bytecode$slot_store_op_for");
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_bytecode_slot_touched(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (l0.tag == 608u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalGet_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 609u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalSet_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 610u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalTee_t*) t0)->f_slot;
        return t1;
    }
    if (l0.tag == 607u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_slot;
        return t1;
    }
    return -(INT32_C(1));
}

static vader_box_t vader_bytecode_slot_width_for(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return vader_box_i32(166u, INT32_C(0));
    }
    if (l0 == INT32_C(5)) {
        return vader_box_i32(166u, INT32_C(0));
    }
    if (l0 == INT32_C(12)) {
        return vader_box_i32(166u, INT32_C(0));
    }
    if (l0 == INT32_C(1)) {
        return vader_box_obj(0u, NULL);
    }
    if (l0 == INT32_C(6)) {
        return vader_box_obj(0u, NULL);
    }
    if (l0 == INT32_C(2)) {
        return vader_box_i32(166u, INT32_C(1));
    }
    if (l0 == INT32_C(7)) {
        return vader_box_i32(166u, INT32_C(1));
    }
    if (l0 == INT32_C(13)) {
        return vader_box_i32(166u, INT32_C(1));
    }
    if (l0 == INT32_C(10)) {
        return vader_box_obj(0u, NULL);
    }
    if (l0 == INT32_C(3)) {
        return vader_box_i32(166u, INT32_C(2));
    }
    if (l0 == INT32_C(8)) {
        return vader_box_i32(166u, INT32_C(2));
    }
    if (l0 == INT32_C(4)) {
        return vader_box_i32(166u, INT32_C(2));
    }
    if (l0 == INT32_C(9)) {
        return vader_box_i32(166u, INT32_C(2));
    }
    if (l0 == INT32_C(11)) {
        return vader_box_i32(166u, INT32_C(3));
    }
    if (l0 == INT32_C(14)) {
        return vader_box_i32(166u, INT32_C(4));
    }
    if (l0 == INT32_C(15)) {
        return vader_box_i32(166u, INT32_C(4));
    }
    if (l0 == INT32_C(16)) {
        return vader_box_i32(166u, INT32_C(4));
    }
    if (l0 == INT32_C(17)) {
        return vader_box_i32(166u, INT32_C(2));
    }
    if (l0 == INT32_C(18)) {
        return vader_box_i32(166u, INT32_C(4));
    }
    if (l0 == INT32_C(19)) {
        return vader_box_i32(166u, INT32_C(4));
    }
    vader_unreachable("unreachable return in vader_bytecode$slot_width_for");
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_string_starts_with(l0, 2028u);
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
    l4 = vader_host_std_core_byte_len(2028u);
    l5 = ((vader_array_t*) l3)->length;
    l6 = vader_host_std_core_byte_len(l1);
    t2 = (l5 - l6);
    l5 = (size_t) (int64_t) t2;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l3, (size_t) l4, (size_t) l5);
    t3 = (void*) _a0_arr;
    t4 = vader_host_std_core_bytes_to_string(t3);
    t1 = vader_box_string(163u, t4);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
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
    l5 = (size_t) (int64_t) INT64_C(0);
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
            } else {
            }
        }
    }
    if (!(l4)) {
        l6 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
        l7 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug;
        vader_struct_vader_bytecode_BcPeepholeOut_t* _a0_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
        vader_obj_header_init(_a0_obj, 501u);
        _a0_obj->f_body = l1;
        _a0_obj->f_jump_table = l6;
        _a0_obj->f_debug = l7;
        t2 = (void*) _a0_obj;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(117u, 0u, 13u, 1070u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 1u, 7u, 166u);
    ((int32_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (int32_t) -(INT32_C(1));
    t2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t2, (size_t) l2);
    l7 = (void*) _a3_arr;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_61: {
            if ((l5 < l2)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l5 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                t0 = vader_bytecode_foldable_self_copy(l1, l5, l2, l3);
                if (t0) {
                    t1 = (l5 + INT64_C(1));
                    l9 = (size_t) (int64_t) t1;
                    vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
                    if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                    if ((size_t) l9 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9);
                    if (t3.tag == 610u) {
                        t4 = ((vader_array_t*) l6)->length;
                        l10 = ((int32_t) (size_t) t4);
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l7);
                        if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                        if ((size_t) l5 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l5] = (int32_t) l10;
                        vader_array_push((vader_array_t*) l6, l8);
                    } else {
                        l11 = -(INT32_C(1));
                        vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
                        if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                        if ((size_t) l5 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                        ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l5] = (int32_t) l11;
                    }
                    t1 = (l5 + INT64_C(1));
                    l12 = (size_t) (int64_t) t1;
                    l13 = -(INT32_C(1));
                    vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
                    if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                    if ((size_t) l12 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                    ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l12] = (int32_t) l13;
                    t1 = (l5 + INT64_C(2));
                    l5 = (size_t) (int64_t) t1;
                    goto loop_61;
                }
                t4 = ((vader_array_t*) l6)->length;
                l14 = ((int32_t) (size_t) t4);
                vader_array_t* _a9_slotarr = ((vader_array_t*) l7);
                if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                if ((size_t) l5 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l5] = (int32_t) l14;
                vader_array_push((vader_array_t*) l6, l8);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_61;
            } else {
            }
        }
    }
    l1 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_jump_table;
    l2 = ((vader_array_t*) l6)->length;
    l1 = vader_bytecode_remap_jump_table(l1, l7, l2);
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) l0)->f_debug;
    l2 = ((vader_array_t*) l6)->length;
    l3 = vader_bytecode_remap_debug(l3, l7, l2);
    vader_struct_vader_bytecode_BcPeepholeOut_t* _a10_obj = (vader_struct_vader_bytecode_BcPeepholeOut_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcPeepholeOut_t));
    vader_obj_header_init(_a10_obj, 501u);
    _a10_obj->f_body = l6;
    _a10_obj->f_jump_table = l1;
    _a10_obj->f_debug = l3;
    t2 = (void*) _a10_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

int32_t vader_bytecode_struct_type_index(void* l0, vader_string_t l1) {
    size_t l2, l3, l5;
    vader_box_t l4;
    void* t0;
    vader_string_t t1;
    int64_t t2;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_6: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                if (l4.tag == 507u) {
                    t0 = l4.payload.obj;
                    t1 = ((vader_struct_vader_bytecode_BcStruct_t*) t0)->f_name;
                    if (t1 == l1) {
                        return ((int32_t) (size_t) l3);
                    }
                    l5 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l3 + l5);
                    l3 = (size_t) (int64_t) t2;
                    goto loop_6;
                }
                l5 = (size_t) (int64_t) INT64_C(1);
                t2 = (l3 + l5);
                l3 = (size_t) (int64_t) t2;
                goto loop_6;
            } else {
            }
        }
    }
    return -(INT32_C(1));
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_module_name;
    if (t0 == 0u) {
        l1 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(22));
        l2 = (size_t) (int64_t) INT64_C(0);
        l2 = std_core_write_string_at(l1, l2, 1668u);
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
        l3 = ((int64_t) (int32_t) t1);
        l2 = std_core_write_int(l1, l2, l3);
        t0 = std_core_finish_buffer(l1, l2);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_module_name;
    l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_name;
    t0 = concat_3(l4, 423u, l5);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_bytecode_try_fold_arith(vader_box_t l0, void* l1, size_t l2) {
    size_t l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* l6 = NULL;
    void* l7 = NULL;
    int32_t l8, l9;
    int64_t l10, l11, l12, l13, l14, l15;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l4, &l5, &t0 };
    void** gc_raw_roots[4] = { &l1, &l6, &l7, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l2 < INT64_C(2))) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = (l2 - INT64_C(1));
    l3 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    t1 = (l2 - INT64_C(2));
    l3 = (size_t) (int64_t) t1;
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l5.tag == 563u) {
        l6 = l5.payload.obj;
        if (l4.tag == 563u) {
            l7 = l4.payload.obj;
            if (l0.tag == 558u) {
                l8 = ((vader_struct_vader_bytecode_I32Const_t*) l6)->f_value;
                l9 = ((vader_struct_vader_bytecode_I32Const_t*) l7)->f_value;
                vader_struct_vader_bytecode_I32Const_t* _a1_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
                vader_obj_header_init(_a1_obj, 563u);
                _a1_obj->f_value = (l8 + l9);
                t2 = (void*) _a1_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 577u) {
                l8 = ((vader_struct_vader_bytecode_I32Const_t*) l6)->f_value;
                l9 = ((vader_struct_vader_bytecode_I32Const_t*) l7)->f_value;
                vader_struct_vader_bytecode_I32Const_t* _a2_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
                vader_obj_header_init(_a2_obj, 563u);
                _a2_obj->f_value = (l8 - l9);
                t2 = (void*) _a2_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 571u) {
                l8 = ((vader_struct_vader_bytecode_I32Const_t*) l6)->f_value;
                l9 = ((vader_struct_vader_bytecode_I32Const_t*) l7)->f_value;
                vader_struct_vader_bytecode_I32Const_t* _a3_obj = (vader_struct_vader_bytecode_I32Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I32Const_t));
                vader_obj_header_init(_a3_obj, 563u);
                _a3_obj->f_value = (l8 * l9);
                t2 = (void*) _a3_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l5.tag == 583u) {
                l6 = l5.payload.obj;
                if (l4.tag == 583u) {
                    l7 = l4.payload.obj;
                    if (l0.tag == 578u) {
                        l10 = ((vader_struct_vader_bytecode_I64Const_t*) l6)->f_value;
                        l11 = ((vader_struct_vader_bytecode_I64Const_t*) l7)->f_value;
                        vader_struct_vader_bytecode_I64Const_t* _a4_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                        vader_obj_header_init(_a4_obj, 583u);
                        _a4_obj->f_value = (l10 + l11);
                        t2 = (void*) _a4_obj;
                        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    if (l0.tag == 597u) {
                        l12 = ((vader_struct_vader_bytecode_I64Const_t*) l6)->f_value;
                        l13 = ((vader_struct_vader_bytecode_I64Const_t*) l7)->f_value;
                        vader_struct_vader_bytecode_I64Const_t* _a5_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                        vader_obj_header_init(_a5_obj, 583u);
                        _a5_obj->f_value = (l12 - l13);
                        t2 = (void*) _a5_obj;
                        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    if (l0.tag == 591u) {
                        l14 = ((vader_struct_vader_bytecode_I64Const_t*) l6)->f_value;
                        l15 = ((vader_struct_vader_bytecode_I64Const_t*) l7)->f_value;
                        vader_struct_vader_bytecode_I64Const_t* _a6_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                        vader_obj_header_init(_a6_obj, 583u);
                        _a6_obj->f_value = (l14 * l15);
                        t2 = (void*) _a6_obj;
                        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    t0 = vader_box_obj(0u, NULL);
                    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                t0 = vader_box_obj(0u, NULL);
                { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            t0 = vader_box_obj(0u, NULL);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l5.tag == 583u) {
            l6 = l5.payload.obj;
            if (l4.tag == 583u) {
                l7 = l4.payload.obj;
                if (l0.tag == 578u) {
                    l10 = ((vader_struct_vader_bytecode_I64Const_t*) l6)->f_value;
                    l11 = ((vader_struct_vader_bytecode_I64Const_t*) l7)->f_value;
                    vader_struct_vader_bytecode_I64Const_t* _a7_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                    vader_obj_header_init(_a7_obj, 583u);
                    _a7_obj->f_value = (l10 + l11);
                    t2 = (void*) _a7_obj;
                    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                }
                if (l0.tag == 597u) {
                    l12 = ((vader_struct_vader_bytecode_I64Const_t*) l6)->f_value;
                    l13 = ((vader_struct_vader_bytecode_I64Const_t*) l7)->f_value;
                    vader_struct_vader_bytecode_I64Const_t* _a8_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                    vader_obj_header_init(_a8_obj, 583u);
                    _a8_obj->f_value = (l12 - l13);
                    t2 = (void*) _a8_obj;
                    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                }
                if (l0.tag == 591u) {
                    l14 = ((vader_struct_vader_bytecode_I64Const_t*) l6)->f_value;
                    l15 = ((vader_struct_vader_bytecode_I64Const_t*) l7)->f_value;
                    vader_struct_vader_bytecode_I64Const_t* _a9_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                    vader_obj_header_init(_a9_obj, 583u);
                    _a9_obj->f_value = (l14 * l15);
                    t2 = (void*) _a9_obj;
                    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t0 = vader_box_obj(0u, NULL);
                { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            t0 = vader_box_obj(0u, NULL);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 583u) {
        l6 = l5.payload.obj;
        if (l4.tag == 583u) {
            l7 = l4.payload.obj;
            if (l0.tag == 578u) {
                l10 = ((vader_struct_vader_bytecode_I64Const_t*) l6)->f_value;
                l11 = ((vader_struct_vader_bytecode_I64Const_t*) l7)->f_value;
                vader_struct_vader_bytecode_I64Const_t* _a10_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                vader_obj_header_init(_a10_obj, 583u);
                _a10_obj->f_value = (l10 + l11);
                t2 = (void*) _a10_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 597u) {
                l12 = ((vader_struct_vader_bytecode_I64Const_t*) l6)->f_value;
                l13 = ((vader_struct_vader_bytecode_I64Const_t*) l7)->f_value;
                vader_struct_vader_bytecode_I64Const_t* _a11_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                vader_obj_header_init(_a11_obj, 583u);
                _a11_obj->f_value = (l12 - l13);
                t2 = (void*) _a11_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l0.tag == 591u) {
                l14 = ((vader_struct_vader_bytecode_I64Const_t*) l6)->f_value;
                l15 = ((vader_struct_vader_bytecode_I64Const_t*) l7)->f_value;
                vader_struct_vader_bytecode_I64Const_t* _a12_obj = (vader_struct_vader_bytecode_I64Const_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_I64Const_t));
                vader_obj_header_init(_a12_obj, 583u);
                _a12_obj->f_value = (l14 * l15);
                t2 = (void*) _a12_obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t0 = vader_box_obj(0u, NULL);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_bytecode_type_index_of(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (l0.tag == 634u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 633u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_StructGet_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 635u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_StructSet_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 486u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArrayNew_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 484u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArrayGet_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 491u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArraySet_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 487u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArrayPush_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 636u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_TypeCheck_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 637u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_TypeConst_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 531u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_CallIndirect_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 612u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_MakeClosure_t*) t0)->f_env_type_id;
        return t1;
    }
    if (l0.tag == 557u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_FnRef_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 607u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_LocalField_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 492u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_ArraySlice_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 615u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_RefCast_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 522u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_Box_t*) t0)->f_type_id;
        return t1;
    }
    if (l0.tag == 534u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_DataConst_t*) t0)->f_type_id;
        return t1;
    }
    return -(INT32_C(1));
}

vader_string_t vader_bytecode_type_intern_key(vader_box_t l0) {
    void* l1 = NULL;
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 917u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 919u) {
        l1 = l0.payload.obj;
        l2 = vader_bytecode_symbol_key(((vader_struct_vader_types_StructType_t*) l1)->f_symbol);
        l3 = vader_bytecode_type_key_join(((vader_struct_vader_types_StructType_t*) l1)->f_args, 2441u);
        t1 = concat_5(747u, l2, 511u, l3, 530u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 920u) {
        l1 = l0.payload.obj;
        l2 = vader_bytecode_symbol_key(((vader_struct_vader_types_TraitType_t*) l1)->f_symbol);
        l3 = vader_bytecode_type_key_join(((vader_struct_vader_types_TraitType_t*) l1)->f_args, 2441u);
        t1 = concat_5(822u, l2, 511u, l3, 530u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 910u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 909u) {
        t0 = l0.payload.obj;
        t1 = vader_bytecode_type_intern_key(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 908u) {
        l1 = l0.payload.obj;
        l2 = vader_bytecode_type_intern_key(((vader_struct_vader_types_ArrayType_t*) l1)->f_element);
        t1 = concat_3(550u, l2, 530u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 924u) {
        l1 = l0.payload.obj;
        l2 = vader_bytecode_type_key_join(((vader_struct_vader_types_UnionType_t*) l1)->f_variants, 2441u);
        t1 = concat_3(828u, l2, 530u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 921u) {
        l1 = l0.payload.obj;
        l2 = vader_bytecode_type_key_join(((vader_struct_vader_types_TupleType_t*) l1)->f_elements, 2441u);
        t1 = concat_3(824u, l2, 530u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 911u) {
        l1 = l0.payload.obj;
        l2 = vader_bytecode_type_key_join(((vader_struct_vader_types_FnType_t*) l1)->f_params, 381u);
        l3 = vader_bytecode_type_intern_key(((vader_struct_vader_types_FnType_t*) l1)->f_return_type);
        t1 = concat_4(612u, l2, 363u, l3);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 923u) {
        t0 = l0.payload.obj;
        t1 = vader_types_display_type(vader_ref_box(t0));
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 922u) {
        t0 = l0.payload.obj;
        t1 = vader_types_display_type(vader_ref_box(t0));
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        t1 = vader_types_display_type(vader_ref_box(t0));
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 925u) {
        t0 = l0.payload.obj;
        t1 = vader_types_display_type(vader_ref_box(t0));
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 914u) {
        t0 = l0.payload.obj;
        t1 = vader_types_display_type(vader_ref_box(t0));
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 912u) {
        t0 = l0.payload.obj;
        t1 = vader_types_display_type(vader_ref_box(t0));
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 913u) {
        t0 = l0.payload.obj;
        t1 = vader_types_display_type(vader_ref_box(t0));
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 915u) {
        t0 = l0.payload.obj;
        t1 = vader_types_display_type(vader_ref_box(t0));
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 907u) {
        { vader_gc_top = gc_frame.prev; return 548u; }
    }
    vader_unreachable("unreachable return in vader_bytecode$type_intern_key");
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = 0u;
    l3 = ((vader_array_t*) l0)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l4 < l3)) {
                if ((l4 > INT64_C(0))) {
                    l5 = l1;
                } else {
                    l5 = 0u;
                }
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                l6 = vader_bytecode_type_intern_key(t0);
                l2 = concat_3(l2, l5, l6);
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_8;
            } else {
            }
        }
    }
    { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_bytecode_unary_op_for(uint8_t l0, uint8_t l1) {
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        t0 = vader_bytecode_neg_op(l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        vader_struct_vader_bytecode_BoolNot_t* _a0_obj = (vader_struct_vader_bytecode_BoolNot_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BoolNot_t));
        vader_obj_header_init(_a0_obj, 520u);
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(2)) {
        t0 = vader_bytecode_bitnot_op(l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_bytecode$unary_op_for");
    vader_gc_top = gc_frame.prev;
}

vader_string_t vader_bytecode_val_type_name(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 1667u;
    }
    if (l0 == INT32_C(1)) {
        return 1622u;
    }
    if (l0 == INT32_C(2)) {
        return 1623u;
    }
    if (l0 == INT32_C(3)) {
        return 1645u;
    }
    if (l0 == INT32_C(4)) {
        return 1741u;
    }
    if (l0 == INT32_C(5)) {
        return 2261u;
    }
    if (l0 == INT32_C(6)) {
        return 2242u;
    }
    if (l0 == INT32_C(7)) {
        return 2243u;
    }
    if (l0 == INT32_C(8)) {
        return 2252u;
    }
    if (l0 == INT32_C(9)) {
        return 2305u;
    }
    if (l0 == INT32_C(10)) {
        return 1516u;
    }
    if (l0 == INT32_C(11)) {
        return 1519u;
    }
    if (l0 == INT32_C(12)) {
        return 1248u;
    }
    if (l0 == INT32_C(13)) {
        return 1339u;
    }
    if (l0 == INT32_C(14)) {
        return 2101u;
    }
    if (l0 == INT32_C(15)) {
        return 1883u;
    }
    if (l0 == INT32_C(16)) {
        return 2402u;
    }
    if (l0 == INT32_C(17)) {
        return 1914u;
    }
    if (l0 == INT32_C(18)) {
        return 1936u;
    }
    if (l0 == INT32_C(19)) {
        return 1172u;
    }
    vader_unreachable("unreachable return in vader_bytecode$val_type_name");
}

static uint8_t vader_bytecode_val_type_of_primitive_name(vader_string_t l0) {
    vader_box_t l1;
    uint8_t t0;
    if (l0 == 578u) {
        return (uint8_t) (int32_t) INT32_C(17);
    }
    l1 = vader_bytecode_parse_val_type(l0);
    if (l1.tag == 0u) {
        return (uint8_t) (int32_t) INT32_C(19);
    }
    t0 = ((uint8_t) l1.payload.i);
    return t0;
}

uint8_t vader_bytecode_val_type_of_type(vader_box_t l0) {
    void* t0;
    vader_string_t t1;
    uint8_t t2;
    if (l0.tag == 917u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        t2 = vader_bytecode_val_type_of_primitive_name(t1);
        return t2;
    }
    if (l0.tag == 919u) {
        return (uint8_t) (int32_t) INT32_C(18);
    }
    if (l0.tag == 910u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
        t2 = vader_bytecode_val_type_of_primitive_name(t1);
        return t2;
    }
    if (l0.tag == 909u) {
        t0 = l0.payload.obj;
        t2 = vader_bytecode_val_type_of_type(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
        return t2;
    }
    if (l0.tag == 908u) {
        return (uint8_t) (int32_t) INT32_C(18);
    }
    if (l0.tag == 911u) {
        return (uint8_t) (int32_t) INT32_C(18);
    }
    if (l0.tag == 921u) {
        return (uint8_t) (int32_t) INT32_C(18);
    }
    if (l0.tag == 920u) {
        return (uint8_t) (int32_t) INT32_C(19);
    }
    if (l0.tag == 924u) {
        return (uint8_t) (int32_t) INT32_C(19);
    }
    if (l0.tag == 923u) {
        return (uint8_t) (int32_t) INT32_C(19);
    }
    if (l0.tag == 922u) {
        return (uint8_t) (int32_t) INT32_C(19);
    }
    if (l0.tag == 918u) {
        return (uint8_t) (int32_t) INT32_C(19);
    }
    if (l0.tag == 907u) {
        return (uint8_t) (int32_t) INT32_C(19);
    }
    if (l0.tag == 925u) {
        return (uint8_t) (int32_t) INT32_C(19);
    }
    if (l0.tag == 914u) {
        return (uint8_t) (int32_t) INT32_C(2);
    }
    if (l0.tag == 912u) {
        return (uint8_t) (int32_t) INT32_C(13);
    }
    if (l0.tag == 913u) {
        return (uint8_t) (int32_t) INT32_C(11);
    }
    if (l0.tag == 915u) {
        return (uint8_t) (int32_t) INT32_C(16);
    }
    vader_unreachable("unreachable return in vader_bytecode$val_type_of_type");
}

static void vader_bytecode_visit_type(int32_t l0, void* l1, void* l2) {
    size_t l3, l4;
    void* l5 = NULL;
    void* l7 = NULL;
    vader_box_t l6 = vader_box_null();
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    int32_t t3;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[5] = { &l1, &l2, &l5, &l7, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l0 < INT32_C(0))) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) l2)->f_inner, l0);
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
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (l6.tag == 507u) {
        t2 = l6.payload.obj;
        l5 = ((vader_struct_vader_bytecode_BcStruct_t*) t2)->f_fields;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_48: {
                if ((l4 < l3)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                    t3 = ((vader_struct_vader_bytecode_BcField_t*) t2)->f_type_index;
                    vader_bytecode_visit_type(t3, l1, l2);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_48;
                } else {
                }
            }
        }
    } else {
    }
    if (l6.tag == 508u) {
        t2 = l6.payload.obj;
        l5 = ((vader_struct_vader_bytecode_BcUnion_t*) t2)->f_variants;
        l3 = ((vader_array_t*) l5)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_84: {
                if ((l4 < l3)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                    vader_bytecode_visit_type(t3, l1, l2);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_84;
                } else {
                }
            }
        }
    } else {
    }
    if (l6.tag == 494u) {
        t2 = l6.payload.obj;
        t3 = ((vader_struct_vader_bytecode_BcArray_t*) t2)->f_element;
        vader_bytecode_visit_type(t3, l1, l2);
    } else {
    }
    if (l6.tag == 497u) {
        l5 = l6.payload.obj;
        l7 = ((vader_struct_vader_bytecode_BcFn_t*) l5)->f_params;
        l3 = ((vader_array_t*) l7)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_131: {
                if ((l4 < l3)) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t3 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l4];
                    vader_bytecode_visit_type(t3, l1, l2);
                    t1 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t1;
                    goto loop_131;
                } else {
                }
            }
        }
        t3 = ((vader_struct_vader_bytecode_BcFn_t*) l5)->f_return_type;
        vader_bytecode_visit_type(t3, l1, l2);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_bytecode_with_remapped_slot(vader_box_t l0, int32_t l1) {
    void* l2 = NULL;
    int32_t l3, l4;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 608u) {
        vader_struct_vader_bytecode_LocalGet_t* _a0_obj = (vader_struct_vader_bytecode_LocalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalGet_t));
        vader_obj_header_init(_a0_obj, 608u);
        _a0_obj->f_slot = l1;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 609u) {
        vader_struct_vader_bytecode_LocalSet_t* _a1_obj = (vader_struct_vader_bytecode_LocalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalSet_t));
        vader_obj_header_init(_a1_obj, 609u);
        _a1_obj->f_slot = l1;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 610u) {
        vader_struct_vader_bytecode_LocalTee_t* _a2_obj = (vader_struct_vader_bytecode_LocalTee_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalTee_t));
        vader_obj_header_init(_a2_obj, 610u);
        _a2_obj->f_slot = l1;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 607u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_bytecode_LocalField_t*) l2)->f_type_id;
        l4 = ((vader_struct_vader_bytecode_LocalField_t*) l2)->f_field_index;
        vader_struct_vader_bytecode_LocalField_t* _a3_obj = (vader_struct_vader_bytecode_LocalField_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_LocalField_t));
        vader_obj_header_init(_a3_obj, 607u);
        _a3_obj->f_slot = l1;
        _a3_obj->f_type_id = l3;
        _a3_obj->f_field_index = l4;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

