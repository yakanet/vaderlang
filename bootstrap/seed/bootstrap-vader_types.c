#include "bootstrap.split.h"

static bool vader_types_contains_distinct(vader_box_t l0);
static void vader_types_write_named_mut(void* l0, vader_string_t l1, void* l2, bool l3);
static void vader_types_write_type(void* l0, vader_box_t l1);
static void vader_types_write_type_list_mut(void* l0, void* l1, vader_string_t l2, bool l3);
static void vader_types_write_type_mut(void* l0, vader_box_t l1, bool l2);

vader_box_t vader_types_array_backing(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        return vader_ref_box(t0);
    }
    if (l0.tag == 917u) {
        t0 = l0.payload.obj;
        t1 = vader_types_array_backing(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
        return t1;
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
}

vader_string_t vader_types_canonical_args_key(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    bool l2;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null();
    vader_string_t l7 = 0;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l0)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    t1 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 391u);
    _a1_obj->f_parts = t1;
    l1 = (void*) _a1_obj;
    l2 = true;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_19: {
            if ((l5 < l4)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
                if (!(l2)) {
                    std_string_builder_append(l1, 365u);
                } else {
                }
                l2 = false;
                l7 = vader_types_canonical_key(l6);
                std_string_builder_append(l1, l7);
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_19;
            } else {
            }
        }
    }
    t3 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t vader_types_canonical_key(vader_box_t l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    vader_string_t l2 = 0;
    vader_string_t l6 = 0;
    size_t l3;
    int64_t l5;
    vader_string_t t0 = 0;
    int32_t t1;
    bool t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &l4 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 925u) {
        l1 = l0.payload.obj;
        l2 = ((vader_struct_vader_types_PrimitiveType_t*) l1)->f_name;
        t0 = concat_2(1930u, l2);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 927u) {
        l1 = l0.payload.obj;
        l2 = vader_types_canonical_args_key(((vader_struct_vader_types_StructType_t*) l1)->f_args);
        l3 = vader_host_std_core_byte_len(l2);
        l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(23) + l3));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l4, l3, 1994u);
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) l1)->f_symbol)->f_id;
        l5 = ((int64_t) (int32_t) t1);
        l3 = std_core_write_int(l4, l3, l5);
        l3 = std_core_write_string_at(l4, l3, 499u);
        l3 = std_core_write_string_at(l4, l3, l2);
        l3 = std_core_write_string_at(l4, l3, 518u);
        t0 = std_core_finish_buffer(l4, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 928u) {
        l1 = l0.payload.obj;
        l2 = vader_types_canonical_args_key(((vader_struct_vader_types_TraitType_t*) l1)->f_args);
        l3 = vader_host_std_core_byte_len(l2);
        l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(23) + l3));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l4, l3, 2136u);
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TraitType_t*) l1)->f_symbol)->f_id;
        l5 = ((int64_t) (int32_t) t1);
        l3 = std_core_write_int(l4, l3, l5);
        l3 = std_core_write_string_at(l4, l3, 499u);
        l3 = std_core_write_string_at(l4, l3, l2);
        l3 = std_core_write_string_at(l4, l3, 518u);
        t0 = std_core_finish_buffer(l4, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 916u) {
        l1 = l0.payload.obj;
        t2 = ((vader_struct_vader_types_ArrayType_t*) l1)->f_immutable;
        if (t2) {
            l2 = vader_types_canonical_key(((vader_struct_vader_types_ArrayType_t*) l1)->f_element);
            t0 = concat_3(1165u, l2, 319u);
            { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = vader_types_canonical_key(((vader_struct_vader_types_ArrayType_t*) l1)->f_element);
        t0 = concat_3(1176u, l2, 319u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 929u) {
        l1 = l0.payload.obj;
        l2 = vader_types_canonical_args_key(((vader_struct_vader_types_TupleType_t*) l1)->f_elements);
        t0 = concat_3(813u, l2, 518u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 919u) {
        l1 = l0.payload.obj;
        l2 = vader_types_canonical_args_key(((vader_struct_vader_types_FnType_t*) l1)->f_params);
        l6 = vader_types_canonical_key(((vader_struct_vader_types_FnType_t*) l1)->f_return_type);
        t0 = concat_4(590u, l2, 520u, l6);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 932u) {
        l1 = l0.payload.obj;
        l2 = vader_types_canonical_args_key(((vader_struct_vader_types_UnionType_t*) l1)->f_variants);
        t0 = concat_3(818u, l2, 518u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 931u) {
        l1 = l0.payload.obj;
        l4 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l4, l3, 656u);
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) l1)->f_symbol)->f_id;
        l5 = ((int64_t) (int32_t) t1);
        l3 = std_core_write_int(l4, l3, l5);
        t0 = std_core_finish_buffer(l4, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 918u) {
        l1 = l0.payload.obj;
        l4 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l4, l3, 1461u);
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_EnumType_t*) l1)->f_symbol)->f_id;
        l5 = ((int64_t) (int32_t) t1);
        l3 = std_core_write_int(l4, l3, l5);
        t0 = std_core_finish_buffer(l4, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 917u) {
        l1 = l0.payload.obj;
        l4 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l4, l3, 1425u);
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_DistinctType_t*) l1)->f_symbol)->f_id;
        l5 = ((int64_t) (int32_t) t1);
        l3 = std_core_write_int(l4, l3, l5);
        t0 = std_core_finish_buffer(l4, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 930u) {
        { vader_gc_top = gc_frame.prev; return 634u; }
    }
    if (l0.tag == 926u) {
        { vader_gc_top = gc_frame.prev; return 732u; }
    }
    if (l0.tag == 933u) {
        { vader_gc_top = gc_frame.prev; return 522u; }
    }
    if (l0.tag == 923u) {
        { vader_gc_top = gc_frame.prev; return 219u; }
    }
    if (l0.tag == 922u) {
        { vader_gc_top = gc_frame.prev; return 593u; }
    }
    if (l0.tag == 920u) {
        { vader_gc_top = gc_frame.prev; return 591u; }
    }
    if (l0.tag == 921u) {
        { vader_gc_top = gc_frame.prev; return 592u; }
    }
    if (l0.tag == 915u) {
        { vader_gc_top = gc_frame.prev; return 533u; }
    }
    vader_unreachable("unreachable return in vader_types$canonical_key");
    vader_gc_top = gc_frame.prev;
}

static bool vader_types_contains_distinct(vader_box_t l0) {
    void* l1;
    void* l5;
    void* l9;
    void* l13;
    size_t l2, l3, l4, l6, l7, l8, l10, l11, l12, l14, l15, l16;
    void* t0;
    vader_box_t t1;
    bool t2;
    int64_t t3;
    if (l0.tag == 917u) {
        return true;
    }
    if (l0.tag == 927u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
        l2 = ((vader_array_t*) l1)->length;
        l3 = (size_t) (int64_t) INT64_C(0);
        {
            loop_17: {
                if ((l3 < l2)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                    t2 = vader_types_contains_distinct(t1);
                    if (t2) {
                        return true;
                    }
                    t3 = (l3 + INT64_C(1));
                    l3 = (size_t) (int64_t) t3;
                    goto loop_17;
                } else {
                }
            }
        }
        if (l0.tag == 928u) {
            t0 = l0.payload.obj;
            l1 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
            l2 = ((vader_array_t*) l1)->length;
            l3 = (size_t) (int64_t) INT64_C(0);
            {
                loop_50: {
                    if ((l3 < l2)) {
                        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
                        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                        if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
                        t2 = vader_types_contains_distinct(t1);
                        if (t2) {
                            return true;
                        }
                        l4 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l3 + l4);
                        l3 = (size_t) (int64_t) t3;
                        goto loop_50;
                    } else {
                    }
                }
            }
            if (l0.tag == 916u) {
                t0 = l0.payload.obj;
                t2 = vader_types_contains_distinct(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
                return t2;
            }
            if (l0.tag == 929u) {
                t0 = l0.payload.obj;
                l5 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
                l6 = ((vader_array_t*) l5)->length;
                l7 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_94: {
                        if ((l7 < l6)) {
                            vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
                            if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                            if ((size_t) l7 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                            t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
                            t2 = vader_types_contains_distinct(t1);
                            if (t2) {
                                return true;
                            }
                            l8 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l7 + l8);
                            l7 = (size_t) (int64_t) t3;
                            goto loop_94;
                        } else {
                        }
                    }
                }
                if (l0.tag == 919u) {
                    t0 = l0.payload.obj;
                    l9 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
                    l10 = ((vader_array_t*) l9)->length;
                    l11 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_129: {
                            if ((l11 < l10)) {
                                vader_array_t* _a3_slotarr = ((vader_array_t*) l9);
                                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                                if ((size_t) l11 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                                t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l11);
                                t2 = vader_types_contains_distinct(t1);
                                if (t2) {
                                    return true;
                                }
                                l12 = (size_t) (int64_t) INT64_C(1);
                                t3 = (l11 + l12);
                                l11 = (size_t) (int64_t) t3;
                                goto loop_129;
                            } else {
                            }
                        }
                    }
                    t0 = l0.payload.obj;
                    t2 = vader_types_contains_distinct(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
                    return t2;
                }
                if (l0.tag == 932u) {
                    t0 = l0.payload.obj;
                    l13 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
                    l14 = ((vader_array_t*) l13)->length;
                    l15 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_170: {
                            if ((l15 < l14)) {
                                vader_array_t* _a4_slotarr = ((vader_array_t*) l13);
                                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                if ((size_t) l15 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l15);
                                t2 = vader_types_contains_distinct(t1);
                                if (t2) {
                                    return true;
                                }
                                l16 = (size_t) (int64_t) INT64_C(1);
                                t3 = (l15 + l16);
                                l15 = (size_t) (int64_t) t3;
                                goto loop_170;
                            } else {
                            }
                        }
                    }
                    return false;
                }
                return false;
            }
            if (l0.tag == 919u) {
                t0 = l0.payload.obj;
                l9 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
                l10 = ((vader_array_t*) l9)->length;
                l11 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_209: {
                        if ((l11 < l10)) {
                            vader_array_t* _a5_slotarr = ((vader_array_t*) l9);
                            if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                            if ((size_t) l11 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                            t1 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l11);
                            t2 = vader_types_contains_distinct(t1);
                            if (t2) {
                                return true;
                            }
                            l12 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l11 + l12);
                            l11 = (size_t) (int64_t) t3;
                            goto loop_209;
                        } else {
                        }
                    }
                }
                t0 = l0.payload.obj;
                t2 = vader_types_contains_distinct(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
                return t2;
            }
            if (l0.tag == 932u) {
                t0 = l0.payload.obj;
                l13 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
                l14 = ((vader_array_t*) l13)->length;
                l15 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_250: {
                        if ((l15 < l14)) {
                            vader_array_t* _a6_slotarr = ((vader_array_t*) l13);
                            if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                            if ((size_t) l15 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                            t1 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l15);
                            t2 = vader_types_contains_distinct(t1);
                            if (t2) {
                                return true;
                            }
                            l16 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l15 + l16);
                            l15 = (size_t) (int64_t) t3;
                            goto loop_250;
                        } else {
                        }
                    }
                }
                return false;
            }
            return false;
        }
        if (l0.tag == 916u) {
            t0 = l0.payload.obj;
            t2 = vader_types_contains_distinct(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
            return t2;
        }
        if (l0.tag == 929u) {
            t0 = l0.payload.obj;
            l5 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
            l6 = ((vader_array_t*) l5)->length;
            l7 = (size_t) (int64_t) INT64_C(0);
            {
                loop_298: {
                    if ((l7 < l6)) {
                        vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
                        if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                        if ((size_t) l7 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l7);
                        t2 = vader_types_contains_distinct(t1);
                        if (t2) {
                            return true;
                        }
                        l8 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l7 + l8);
                        l7 = (size_t) (int64_t) t3;
                        goto loop_298;
                    } else {
                    }
                }
            }
            if (l0.tag == 919u) {
                t0 = l0.payload.obj;
                l9 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
                l10 = ((vader_array_t*) l9)->length;
                l11 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_333: {
                        if ((l11 < l10)) {
                            vader_array_t* _a8_slotarr = ((vader_array_t*) l9);
                            if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                            if ((size_t) l11 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                            t1 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l11);
                            t2 = vader_types_contains_distinct(t1);
                            if (t2) {
                                return true;
                            }
                            l12 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l11 + l12);
                            l11 = (size_t) (int64_t) t3;
                            goto loop_333;
                        } else {
                        }
                    }
                }
                t0 = l0.payload.obj;
                t2 = vader_types_contains_distinct(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
                return t2;
            }
            if (l0.tag == 932u) {
                t0 = l0.payload.obj;
                l13 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
                l14 = ((vader_array_t*) l13)->length;
                l15 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_374: {
                        if ((l15 < l14)) {
                            vader_array_t* _a9_slotarr = ((vader_array_t*) l13);
                            if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                            if ((size_t) l15 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                            t1 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l15);
                            t2 = vader_types_contains_distinct(t1);
                            if (t2) {
                                return true;
                            }
                            l16 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l15 + l16);
                            l15 = (size_t) (int64_t) t3;
                            goto loop_374;
                        } else {
                        }
                    }
                }
                return false;
            }
            return false;
        }
        if (l0.tag == 919u) {
            t0 = l0.payload.obj;
            l9 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
            l10 = ((vader_array_t*) l9)->length;
            l11 = (size_t) (int64_t) INT64_C(0);
            {
                loop_413: {
                    if ((l11 < l10)) {
                        vader_array_t* _a10_slotarr = ((vader_array_t*) l9);
                        if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                        if ((size_t) l11 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l11);
                        t2 = vader_types_contains_distinct(t1);
                        if (t2) {
                            return true;
                        }
                        l12 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l11 + l12);
                        l11 = (size_t) (int64_t) t3;
                        goto loop_413;
                    } else {
                    }
                }
            }
            t0 = l0.payload.obj;
            t2 = vader_types_contains_distinct(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
            return t2;
        }
        if (l0.tag == 932u) {
            t0 = l0.payload.obj;
            l13 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
            l14 = ((vader_array_t*) l13)->length;
            l15 = (size_t) (int64_t) INT64_C(0);
            {
                loop_454: {
                    if ((l15 < l14)) {
                        vader_array_t* _a11_slotarr = ((vader_array_t*) l13);
                        if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                        if ((size_t) l15 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l15);
                        t2 = vader_types_contains_distinct(t1);
                        if (t2) {
                            return true;
                        }
                        l16 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l15 + l16);
                        l15 = (size_t) (int64_t) t3;
                        goto loop_454;
                    } else {
                    }
                }
            }
            return false;
        }
        return false;
    }
    if (l0.tag == 928u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
        l2 = ((vader_array_t*) l1)->length;
        l3 = (size_t) (int64_t) INT64_C(0);
        {
            loop_493: {
                if ((l3 < l2)) {
                    vader_array_t* _a12_slotarr = ((vader_array_t*) l1);
                    if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                    if ((size_t) l3 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l3);
                    t2 = vader_types_contains_distinct(t1);
                    if (t2) {
                        return true;
                    }
                    l4 = (size_t) (int64_t) INT64_C(1);
                    t3 = (l3 + l4);
                    l3 = (size_t) (int64_t) t3;
                    goto loop_493;
                } else {
                }
            }
        }
        if (l0.tag == 916u) {
            t0 = l0.payload.obj;
            t2 = vader_types_contains_distinct(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
            return t2;
        }
        if (l0.tag == 929u) {
            t0 = l0.payload.obj;
            l5 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
            l6 = ((vader_array_t*) l5)->length;
            l7 = (size_t) (int64_t) INT64_C(0);
            {
                loop_537: {
                    if ((l7 < l6)) {
                        vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
                        if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                        if ((size_t) l7 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l7);
                        t2 = vader_types_contains_distinct(t1);
                        if (t2) {
                            return true;
                        }
                        l8 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l7 + l8);
                        l7 = (size_t) (int64_t) t3;
                        goto loop_537;
                    } else {
                    }
                }
            }
            if (l0.tag == 919u) {
                t0 = l0.payload.obj;
                l9 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
                l10 = ((vader_array_t*) l9)->length;
                l11 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_572: {
                        if ((l11 < l10)) {
                            vader_array_t* _a14_slotarr = ((vader_array_t*) l9);
                            if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                            if ((size_t) l11 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                            t1 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l11);
                            t2 = vader_types_contains_distinct(t1);
                            if (t2) {
                                return true;
                            }
                            l12 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l11 + l12);
                            l11 = (size_t) (int64_t) t3;
                            goto loop_572;
                        } else {
                        }
                    }
                }
                t0 = l0.payload.obj;
                t2 = vader_types_contains_distinct(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
                return t2;
            }
            if (l0.tag == 932u) {
                t0 = l0.payload.obj;
                l13 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
                l14 = ((vader_array_t*) l13)->length;
                l15 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_613: {
                        if ((l15 < l14)) {
                            vader_array_t* _a15_slotarr = ((vader_array_t*) l13);
                            if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                            if ((size_t) l15 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                            t1 = vader_array_ref_load_box(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l15);
                            t2 = vader_types_contains_distinct(t1);
                            if (t2) {
                                return true;
                            }
                            l16 = (size_t) (int64_t) INT64_C(1);
                            t3 = (l15 + l16);
                            l15 = (size_t) (int64_t) t3;
                            goto loop_613;
                        } else {
                        }
                    }
                }
                return false;
            }
            return false;
        }
        if (l0.tag == 919u) {
            t0 = l0.payload.obj;
            l9 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
            l10 = ((vader_array_t*) l9)->length;
            l11 = (size_t) (int64_t) INT64_C(0);
            {
                loop_652: {
                    if ((l11 < l10)) {
                        vader_array_t* _a16_slotarr = ((vader_array_t*) l9);
                        if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                        if ((size_t) l11 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_box(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l11);
                        t2 = vader_types_contains_distinct(t1);
                        if (t2) {
                            return true;
                        }
                        l12 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l11 + l12);
                        l11 = (size_t) (int64_t) t3;
                        goto loop_652;
                    } else {
                    }
                }
            }
            t0 = l0.payload.obj;
            t2 = vader_types_contains_distinct(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
            return t2;
        }
        if (l0.tag == 932u) {
            t0 = l0.payload.obj;
            l13 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
            l14 = ((vader_array_t*) l13)->length;
            l15 = (size_t) (int64_t) INT64_C(0);
            {
                loop_693: {
                    if ((l15 < l14)) {
                        vader_array_t* _a17_slotarr = ((vader_array_t*) l13);
                        if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                        if ((size_t) l15 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_box(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l15);
                        t2 = vader_types_contains_distinct(t1);
                        if (t2) {
                            return true;
                        }
                        l16 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l15 + l16);
                        l15 = (size_t) (int64_t) t3;
                        goto loop_693;
                    } else {
                    }
                }
            }
            return false;
        }
        return false;
    }
    if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        t2 = vader_types_contains_distinct(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        return t2;
    }
    if (l0.tag == 929u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) (int64_t) INT64_C(0);
        {
            loop_741: {
                if ((l7 < l6)) {
                    vader_array_t* _a18_slotarr = ((vader_array_t*) l5);
                    if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                    if ((size_t) l7 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l7);
                    t2 = vader_types_contains_distinct(t1);
                    if (t2) {
                        return true;
                    }
                    l8 = (size_t) (int64_t) INT64_C(1);
                    t3 = (l7 + l8);
                    l7 = (size_t) (int64_t) t3;
                    goto loop_741;
                } else {
                }
            }
        }
        if (l0.tag == 919u) {
            t0 = l0.payload.obj;
            l9 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
            l10 = ((vader_array_t*) l9)->length;
            l11 = (size_t) (int64_t) INT64_C(0);
            {
                loop_776: {
                    if ((l11 < l10)) {
                        vader_array_t* _a19_slotarr = ((vader_array_t*) l9);
                        if (_a19_slotarr->buf != NULL && _a19_slotarr->buf->header.forward != NULL) { _a19_slotarr->buf = vader_array_buf_forward(_a19_slotarr->buf); }
                        if ((size_t) l11 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_box(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l11);
                        t2 = vader_types_contains_distinct(t1);
                        if (t2) {
                            return true;
                        }
                        l12 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l11 + l12);
                        l11 = (size_t) (int64_t) t3;
                        goto loop_776;
                    } else {
                    }
                }
            }
            t0 = l0.payload.obj;
            t2 = vader_types_contains_distinct(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
            return t2;
        }
        if (l0.tag == 932u) {
            t0 = l0.payload.obj;
            l13 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
            l14 = ((vader_array_t*) l13)->length;
            l15 = (size_t) (int64_t) INT64_C(0);
            {
                loop_817: {
                    if ((l15 < l14)) {
                        vader_array_t* _a20_slotarr = ((vader_array_t*) l13);
                        if (_a20_slotarr->buf != NULL && _a20_slotarr->buf->header.forward != NULL) { _a20_slotarr->buf = vader_array_buf_forward(_a20_slotarr->buf); }
                        if ((size_t) l15 >= _a20_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_box(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l15);
                        t2 = vader_types_contains_distinct(t1);
                        if (t2) {
                            return true;
                        }
                        l16 = (size_t) (int64_t) INT64_C(1);
                        t3 = (l15 + l16);
                        l15 = (size_t) (int64_t) t3;
                        goto loop_817;
                    } else {
                    }
                }
            }
            return false;
        }
        return false;
    }
    if (l0.tag == 919u) {
        t0 = l0.payload.obj;
        l9 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
        l10 = ((vader_array_t*) l9)->length;
        l11 = (size_t) (int64_t) INT64_C(0);
        {
            loop_856: {
                if ((l11 < l10)) {
                    vader_array_t* _a21_slotarr = ((vader_array_t*) l9);
                    if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
                    if ((size_t) l11 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l11);
                    t2 = vader_types_contains_distinct(t1);
                    if (t2) {
                        return true;
                    }
                    l12 = (size_t) (int64_t) INT64_C(1);
                    t3 = (l11 + l12);
                    l11 = (size_t) (int64_t) t3;
                    goto loop_856;
                } else {
                }
            }
        }
        t0 = l0.payload.obj;
        t2 = vader_types_contains_distinct(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
        return t2;
    }
    if (l0.tag == 932u) {
        t0 = l0.payload.obj;
        l13 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        l14 = ((vader_array_t*) l13)->length;
        l15 = (size_t) (int64_t) INT64_C(0);
        {
            loop_897: {
                if ((l15 < l14)) {
                    vader_array_t* _a22_slotarr = ((vader_array_t*) l13);
                    if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                    if ((size_t) l15 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l15);
                    t2 = vader_types_contains_distinct(t1);
                    if (t2) {
                        return true;
                    }
                    l16 = (size_t) (int64_t) INT64_C(1);
                    t3 = (l15 + l16);
                    l15 = (size_t) (int64_t) t3;
                    goto loop_897;
                } else {
                }
            }
        }
        return false;
    }
    return false;
}

vader_string_t vader_types_display_type(vader_box_t l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 925u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 931u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_EnumType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 917u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_DistinctType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 933u) {
        { vader_gc_top = gc_frame.prev; return 522u; }
    }
    if (l0.tag == 923u) {
        { vader_gc_top = gc_frame.prev; return 1894u; }
    }
    if (l0.tag == 922u) {
        { vader_gc_top = gc_frame.prev; return 2425u; }
    }
    if (l0.tag == 921u) {
        { vader_gc_top = gc_frame.prev; return 2424u; }
    }
    if (l0.tag == 920u) {
        { vader_gc_top = gc_frame.prev; return 2423u; }
    }
    if (l0.tag == 926u) {
        { vader_gc_top = gc_frame.prev; return 734u; }
    }
    if (l0.tag == 930u) {
        { vader_gc_top = gc_frame.prev; return 2173u; }
    }
    if (l0.tag == 915u) {
        { vader_gc_top = gc_frame.prev; return 536u; }
    }
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 391u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    vader_types_write_type(l1, l0);
    t1 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t vader_types_display_type_key(vader_box_t l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 391u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    vader_types_write_type_mut(l1, l0, false);
    t1 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void vader_types_for_each_type(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    size_t l3, l4;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    void** gc_raw_roots[4] = { &l1, &l2, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
    ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, l0);
    if (l0.tag == 927u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) (int64_t) INT64_C(0);
        {
            loop_15: {
                if ((l4 < l3)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                    vader_types_for_each_type(t1, l1);
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    goto loop_15;
                } else {
                }
            }
        }
    } else {
        if (l0.tag == 928u) {
            t0 = l0.payload.obj;
            l2 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
            l3 = ((vader_array_t*) l2)->length;
            l4 = (size_t) (int64_t) INT64_C(0);
            {
                loop_47: {
                    if ((l4 < l3)) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                        vader_types_for_each_type(t1, l1);
                        t2 = (l4 + INT64_C(1));
                        l4 = (size_t) (int64_t) t2;
                        goto loop_47;
                    } else {
                    }
                }
            }
        } else {
            if (l0.tag == 916u) {
                t0 = l0.payload.obj;
                vader_types_for_each_type(((vader_struct_vader_types_ArrayType_t*) t0)->f_element, l1);
            } else {
                if (l0.tag == 929u) {
                    t0 = l0.payload.obj;
                    l2 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
                    l3 = ((vader_array_t*) l2)->length;
                    l4 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_88: {
                            if ((l4 < l3)) {
                                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                                t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
                                vader_types_for_each_type(t1, l1);
                                t2 = (l4 + INT64_C(1));
                                l4 = (size_t) (int64_t) t2;
                                goto loop_88;
                            } else {
                            }
                        }
                    }
                } else {
                    if (l0.tag == 919u) {
                        l2 = l0.payload.obj;
                        l5 = ((vader_struct_vader_types_FnType_t*) l2)->f_params;
                        l3 = ((vader_array_t*) l5)->length;
                        l4 = (size_t) (int64_t) INT64_C(0);
                        {
                            loop_121: {
                                if ((l4 < l3)) {
                                    vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
                                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
                                    vader_types_for_each_type(t1, l1);
                                    t2 = (l4 + INT64_C(1));
                                    l4 = (size_t) (int64_t) t2;
                                    goto loop_121;
                                } else {
                                }
                            }
                        }
                        vader_types_for_each_type(((vader_struct_vader_types_FnType_t*) l2)->f_return_type, l1);
                    } else {
                        if (l0.tag == 932u) {
                            t0 = l0.payload.obj;
                            l2 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
                            l3 = ((vader_array_t*) l2)->length;
                            l4 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_156: {
                                    if ((l4 < l3)) {
                                        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                                        if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                                        if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t1 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4);
                                        vader_types_for_each_type(t1, l1);
                                        t2 = (l4 + INT64_C(1));
                                        l4 = (size_t) (int64_t) t2;
                                        goto loop_156;
                                    } else {
                                    }
                                }
                            }
                        } else {
                            if (l0.tag == 917u) {
                                t0 = l0.payload.obj;
                                vader_types_for_each_type(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing, l1);
                            } else {
                            }
                        }
                    }
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

bool vader_types_is_float_name(vader_string_t l0) {
    vader_box_t l1;
    bool l2;
    void* t0;
    l1 = vader_types_primitive_meta(l0);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_types_PrimitiveMeta_t*) t0)->f_is_float;
    } else {
        l2 = false;
    }
    return l2;
}

bool vader_types_is_int_name(vader_string_t l0) {
    vader_box_t l1;
    bool l2;
    void* t0;
    l1 = vader_types_primitive_meta(l0);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_types_PrimitiveMeta_t*) t0)->f_is_int;
    } else {
        l2 = false;
    }
    return l2;
}

bool vader_types_is_numeric_name(vader_string_t l0) {
    vader_box_t l1;
    bool l2;
    void* t0;
    bool t1;
    l1 = vader_types_primitive_meta(l0);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveMeta_t*) t0)->f_is_int;
        if (t1) {
            l2 = true;
        } else {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_vader_types_PrimitiveMeta_t*) t0)->f_is_float;
        }
    } else {
        l2 = false;
    }
    return l2;
}

bool vader_types_is_primitive_name(vader_string_t l0) {
    vader_box_t t0;
    t0 = vader_types_primitive_meta(l0);
    return !(t0.tag == 0u);
}

bool vader_types_is_signed_int_name(vader_string_t l0) {
    vader_box_t l1;
    bool l2;
    void* t0;
    l1 = vader_types_primitive_meta(l0);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_types_PrimitiveMeta_t*) t0)->f_is_int;
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_types_PrimitiveMeta_t*) t0)->f_is_signed;
    } else {
        l2 = false;
    }
    return l2;
}

bool vader_types_is_unsigned_int_name(vader_string_t l0) {
    vader_box_t l1;
    bool l2;
    void* t0;
    bool t1;
    l1 = vader_types_primitive_meta(l0);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_types_PrimitiveMeta_t*) t0)->f_is_int;
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveMeta_t*) t0)->f_is_signed;
        l2 = !(t1);
    } else {
        l2 = false;
    }
    return l2;
}

vader_box_t vader_types_mk_array(vader_box_t l0, bool l1) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_ArrayType_t* _a0_obj = (vader_struct_vader_types_ArrayType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_ArrayType_t));
    vader_obj_header_init(_a0_obj, 916u);
    _a0_obj->f_element = l0;
    _a0_obj->f_immutable = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_types_mk_distinct(void* l0, vader_box_t l1) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_DistinctType_t* _a0_obj = (vader_struct_vader_types_DistinctType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_DistinctType_t));
    vader_obj_header_init(_a0_obj, 917u);
    _a0_obj->f_symbol = l0;
    _a0_obj->f_backing = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_types_mk_enum(void* l0, vader_string_t l1, void* l2) {
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_EnumType_t* _a0_obj = (vader_struct_vader_types_EnumType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_EnumType_t));
    vader_obj_header_init(_a0_obj, 918u);
    _a0_obj->f_symbol = l0;
    _a0_obj->f_repr = l1;
    _a0_obj->f_indices = l2;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_types_mk_fn(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(6u, 0u, 12u, 167u);
    l2 = (void*) _a0_arr;
    vader_struct_vader_types_FnType_t* _a1_obj = (vader_struct_vader_types_FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_FnType_t));
    vader_obj_header_init(_a1_obj, 919u);
    _a1_obj->f_params = l0;
    _a1_obj->f_params_mutable = l2;
    _a1_obj->f_return_type = l1;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_types_mk_fn_drop_self(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    size_t l4, l5;
    bool l6;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &t1 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_types_FnType_t*) l0)->f_params_mutable)->length;
    if (t0 == INT64_C(0)) {
        t1 = vader_types_mk_fn(l1, l2);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(6u, 0u, 12u, 167u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_types_FnType_t*) l0)->f_params_mutable)->length;
    l5 = (size_t) (int64_t) INT64_C(1);
    {
        loop_18: {
            if ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_types_FnType_t*) l0)->f_params_mutable);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_box_bool(167u, ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5]);
                l6 = t1.payload.b;
                vader_array_push_bool((vader_array_t*) l3, l6);
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_18;
            } else {
            }
        }
    }
    vader_struct_vader_types_FnType_t* _a2_obj = (vader_struct_vader_types_FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_FnType_t));
    vader_obj_header_init(_a2_obj, 919u);
    _a2_obj->f_params = l1;
    _a2_obj->f_params_mutable = l3;
    _a2_obj->f_return_type = l2;
    t3 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_types_mk_fn_like(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_types_FnType_t*) l0)->f_params_mutable;
    vader_struct_vader_types_FnType_t* _a0_obj = (vader_struct_vader_types_FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_FnType_t));
    vader_obj_header_init(_a0_obj, 919u);
    _a0_obj->f_params = l1;
    _a0_obj->f_params_mutable = l3;
    _a0_obj->f_return_type = l2;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_types_mk_primitive(vader_string_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_PrimitiveType_t* _a0_obj = (vader_struct_vader_types_PrimitiveType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_PrimitiveType_t));
    vader_obj_header_init(_a0_obj, 925u);
    _a0_obj->f_name = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_types_mk_struct(void* l0, void* l1, bool l2) {
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_StructType_t* _a0_obj = (vader_struct_vader_types_StructType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_StructType_t));
    vader_obj_header_init(_a0_obj, 927u);
    _a0_obj->f_symbol = l0;
    _a0_obj->f_args = l1;
    _a0_obj->f_immutable = l2;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_types_mk_trait(void* l0, void* l1) {
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_TraitType_t* _a0_obj = (vader_struct_vader_types_TraitType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_TraitType_t));
    vader_obj_header_init(_a0_obj, 928u);
    _a0_obj->f_symbol = l0;
    _a0_obj->f_args = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_types_mk_tuple(void* l0, bool l1) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_TupleType_t* _a0_obj = (vader_struct_vader_types_TupleType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_TupleType_t));
    vader_obj_header_init(_a0_obj, 929u);
    _a0_obj->f_elements = l0;
    _a0_obj->f_immutable = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_types_mk_type_param(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_TypeParamType_t* _a0_obj = (vader_struct_vader_types_TypeParamType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_TypeParamType_t));
    vader_obj_header_init(_a0_obj, 931u);
    _a0_obj->f_symbol = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_types_mk_union(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_UnionType_t* _a0_obj = (vader_struct_vader_types_UnionType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_UnionType_t));
    vader_obj_header_init(_a0_obj, 932u);
    _a0_obj->f_variants = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

int64_t vader_types_primitive_align(vader_string_t l0) {
    int64_t t0;
    t0 = vader_types_primitive_size(l0);
    return t0;
}

vader_box_t vader_types_primitive_meta(vader_string_t l0) {
    void* l1;
    void* l4;
    size_t l2, l3;
    vader_string_t t0;
    int64_t t1;
    vader_box_t t2;
    l1 = (void*) &vader_data_10;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                t0 = ((vader_struct_vader_types_PrimitiveMeta_t*) l4)->f_name;
                if (t0 == l0) {
                    return vader_ref_box(l4);
                }
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_7;
            } else {
            }
        }
    }
    t2 = vader_box_obj(0u, NULL);
    return t2;
}

int64_t vader_types_primitive_size(vader_string_t l0) {
    void* l1;
    vader_box_t l2;
    int64_t t0;
    l2 = vader_types_primitive_meta(l0);
    if (l2.tag == 0u) {
        return INT64_C(0);
    }
    l1 = l2.payload.obj;
    t0 = ((vader_struct_vader_types_PrimitiveMeta_t*) l1)->f_size;
    return t0;
}

vader_string_t vader_types_resolve_primitive_alias(vader_string_t l0) {
    void* l1;
    void* l4;
    size_t l2, l3;
    vader_box_t t0;
    vader_string_t t1;
    int64_t t2;
    l1 = (void*) &vader_data_11;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) INT32_C(0) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) INT32_C(0)];
                t1 = t0.payload.s;
                if (t1 == l0) {
                    if ((size_t) INT32_C(1) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) INT32_C(1)];
                    t1 = t0.payload.s;
                    return t1;
                }
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_7;
            } else {
            }
        }
    }
    return l0;
}

vader_box_t vader_types_strip_distinct(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    bool l3;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    void* t3 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l4, &t2 };
    void** gc_raw_roots[4] = { &l1, &l2, &t0, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 925u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_types_contains_distinct(l0);
    if (!(t1)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 917u) {
        t0 = l0.payload.obj;
        t2 = vader_types_strip_distinct(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 927u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_StructType_t*) t0)->f_symbol;
        t0 = l0.payload.obj;
        l2 = vader_types_strip_distinct_each(((vader_struct_vader_types_StructType_t*) t0)->f_args);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_types_StructType_t*) t0)->f_immutable;
        t2 = vader_types_mk_struct(l1, l2, l3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 928u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol;
        t0 = l0.payload.obj;
        l2 = vader_types_strip_distinct_each(((vader_struct_vader_types_TraitType_t*) t0)->f_args);
        t2 = vader_types_mk_trait(l1, l2);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        l4 = vader_types_strip_distinct(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_immutable;
        t2 = vader_types_mk_array(l4, l3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 929u) {
        t0 = l0.payload.obj;
        l1 = vader_types_strip_distinct_each(((vader_struct_vader_types_TupleType_t*) t0)->f_elements);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_types_TupleType_t*) t0)->f_immutable;
        t2 = vader_types_mk_tuple(l1, l3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 919u) {
        l1 = l0.payload.obj;
        t0 = l0.payload.obj;
        l2 = vader_types_strip_distinct_each(((vader_struct_vader_types_FnType_t*) t0)->f_params);
        t0 = l0.payload.obj;
        l4 = vader_types_strip_distinct(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
        t2 = vader_types_mk_fn_like(l1, l2, l4);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 932u) {
        t0 = l0.payload.obj;
        t3 = vader_types_strip_distinct_each(((vader_struct_vader_types_UnionType_t*) t0)->f_variants);
        t2 = vader_types_mk_union(t3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_types_strip_distinct_each(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(134u, 0u, 13u, 1192u);
    l1 = (void*) _a0_arr;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                l5 = vader_types_strip_distinct(t0);
                vader_array_push((vader_array_t*) l1, l5);
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_9;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_types_struct_backing(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 927u) {
        t0 = l0.payload.obj;
        return vader_ref_box(t0);
    }
    if (l0.tag == 917u) {
        t0 = l0.payload.obj;
        t1 = vader_types_struct_backing(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
        return t1;
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
}

vader_box_t vader_types_tuple_backing(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 929u) {
        t0 = l0.payload.obj;
        return vader_ref_box(t0);
    }
    if (l0.tag == 917u) {
        t0 = l0.payload.obj;
        t1 = vader_types_tuple_backing(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
        return t1;
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
}

vader_string_t vader_types_type_base_name(vader_box_t l0) {
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 927u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 928u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_EnumType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 917u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_DistinctType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 916u) {
        { vader_gc_top = gc_frame.prev; return 846u; }
    }
    t1 = vader_types_display_type_key(l0);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool vader_types_type_is_immutable(vader_box_t l0) {
    void* t0;
    bool t1;
    if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_immutable;
        return t1;
    }
    if (l0.tag == 927u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_StructType_t*) t0)->f_immutable;
        return t1;
    }
    if (l0.tag == 929u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_TupleType_t*) t0)->f_immutable;
        return t1;
    }
    if ((l0.tag == 915u || l0.tag == 917u || l0.tag == 918u || l0.tag == 919u || l0.tag == 920u || l0.tag == 921u || l0.tag == 922u || l0.tag == 923u || l0.tag == 925u || l0.tag == 926u || l0.tag == 928u || l0.tag == 930u || l0.tag == 931u || l0.tag == 932u || l0.tag == 933u)) {
        return false;
    }
    vader_unreachable("unreachable return in vader_types$type_is_immutable");
}

static void vader_types_write_named_mut(void* l0, vader_string_t l1, void* l2, bool l3) {
    size_t t0;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    std_string_builder_append(l0, l1);
    t0 = ((vader_array_t*) l2)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_string_builder_append_char(l0, 60u);
    vader_types_write_type_list_mut(l0, l2, 366u, l3);
    std_string_builder_append_char(l0, 62u);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_types_write_type(void* l0, vader_box_t l1) {
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_types_write_type_mut(l0, l1, true);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_types_write_type_list_mut(void* l0, void* l1, vader_string_t l2, bool l3) {
    bool l4;
    void* l5 = NULL;
    size_t l6, l7;
    vader_box_t l8 = vader_box_null();
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l4 = true;
    l5 = l1;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l7 < l6)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l7 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
                if (!(l4)) {
                    std_string_builder_append(l0, l2);
                } else {
                }
                l4 = false;
                vader_types_write_type_mut(l0, l8, l3);
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                goto loop_9;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_types_write_type_mut(void* l0, vader_box_t l1, bool l2) {
    vader_string_t l3 = 0;
    void* l4 = NULL;
    void* l5 = NULL;
    bool l6;
    vader_box_t l7 = vader_box_null();
    size_t l8, l9;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l1, &l7 };
    void** gc_raw_roots[4] = { &l0, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 925u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        std_string_builder_append(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 927u) {
        l4 = l1.payload.obj;
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) l4)->f_symbol)->f_name;
        l5 = ((vader_struct_vader_types_StructType_t*) l4)->f_args;
        vader_types_write_named_mut(l0, l3, l5, l2);
        if (l2) {
            t1 = ((vader_struct_vader_types_StructType_t*) l4)->f_immutable;
            l6 = !(t1);
        } else {
            l6 = false;
        }
        if (l6) {
            std_string_builder_append_char(l0, 33u);
        } else {
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 918u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_EnumType_t*) t0)->f_symbol)->f_name;
        std_string_builder_append(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 917u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_DistinctType_t*) t0)->f_symbol)->f_name;
        std_string_builder_append(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 928u) {
        l4 = l1.payload.obj;
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TraitType_t*) l4)->f_symbol)->f_name;
        l4 = ((vader_struct_vader_types_TraitType_t*) l4)->f_args;
        vader_types_write_named_mut(l0, l3, l4, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 931u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) t0)->f_symbol)->f_name;
        std_string_builder_append(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 930u) {
        std_string_builder_append(l0, 2173u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 926u) {
        std_string_builder_append(l0, 734u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 933u) {
        std_string_builder_append(l0, 522u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 923u) {
        std_string_builder_append(l0, 1894u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 922u) {
        std_string_builder_append(l0, 2425u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 921u) {
        std_string_builder_append(l0, 2424u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 920u) {
        std_string_builder_append(l0, 2423u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 916u) {
        l4 = l1.payload.obj;
        if (((vader_struct_vader_types_ArrayType_t*) l4)->f_element.tag == 932u) {
            l6 = true;
        } else {
            l6 = ((vader_struct_vader_types_ArrayType_t*) l4)->f_element.tag == 919u;
        }
        if (l6) {
            std_string_builder_append_char(l0, 40u);
        } else {
        }
        l7 = ((vader_struct_vader_types_ArrayType_t*) l4)->f_element;
        vader_types_write_type_mut(l0, l7, l2);
        if (l6) {
            std_string_builder_append_char(l0, 41u);
        } else {
        }
        std_string_builder_append(l0, 846u);
        if (l2) {
            t1 = ((vader_struct_vader_types_ArrayType_t*) l4)->f_immutable;
            l6 = !(t1);
        } else {
            l6 = false;
        }
        if (l6) {
            std_string_builder_append_char(l0, 33u);
        } else {
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 929u) {
        l4 = l1.payload.obj;
        std_string_builder_append_char(l0, 91u);
        l5 = ((vader_struct_vader_types_TupleType_t*) l4)->f_elements;
        vader_types_write_type_list_mut(l0, l5, 366u, l2);
        std_string_builder_append_char(l0, 93u);
        if (l2) {
            t1 = ((vader_struct_vader_types_TupleType_t*) l4)->f_immutable;
            l6 = !(t1);
        } else {
            l6 = false;
        }
        if (l6) {
            std_string_builder_append_char(l0, 33u);
        } else {
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 919u) {
        l4 = l1.payload.obj;
        std_string_builder_append(l0, 1595u);
        l6 = true;
        l8 = ((vader_array_t*) ((vader_struct_vader_types_FnType_t*) l4)->f_params)->length;
        l9 = (size_t) (int64_t) INT64_C(0);
        {
            loop_279: {
                if ((l9 < l8)) {
                    if (!(l6)) {
                        std_string_builder_append(l0, 366u);
                    } else {
                    }
                    l6 = false;
                    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_types_FnType_t*) l4)->f_params);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l9 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
                    vader_types_write_type_mut(l0, l7, l2);
                    t2 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t2;
                    goto loop_279;
                } else {
                }
            }
        }
        std_string_builder_append(l0, 322u);
        l7 = ((vader_struct_vader_types_FnType_t*) l4)->f_return_type;
        vader_types_write_type_mut(l0, l7, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 932u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        vader_types_write_type_list_mut(l0, l4, 199u, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 915u) {
        std_string_builder_append(l0, 536u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

