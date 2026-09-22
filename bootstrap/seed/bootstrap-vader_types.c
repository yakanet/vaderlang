#include "bootstrap.split.h"

static bool vader_types_contains_distinct(vader_box_t l0);
static bool vader_types_variants_grant_mutation(void* l0);
static void vader_types_write_named_mut(void* l0, vader_string_t l1, void* l2, bool l3);
static void vader_types_write_type(void* l0, vader_box_t l1);
static void vader_types_write_type_list_mut(void* l0, void* l1, vader_string_t l2, bool l3);
static void vader_types_write_type_mut(void* l0, vader_box_t l1, bool l2);

vader_box_t vader_types_array_backing(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        return vader_ref_box(t0);
    }
    if (l0.tag == 927u) {
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 176u);
    t1 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 396u);
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
                    std_string_builder_append(l1, 392u);
                }
                l2 = false;
                l7 = vader_types_canonical_key(l6);
                std_string_builder_append(l1, l7);
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_19;
            }
        }
    }
    t3 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t vader_types_canonical_key(vader_box_t l0) {
    vader_string_t l1 = 0;
    vader_string_t l5 = 0;
    size_t l2;
    void* l3 = NULL;
    int64_t l4;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int32_t t2;
    bool t3;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l3, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 935u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        t1 = concat_2(2009u, l1);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 937u) {
        t0 = l0.payload.obj;
        l1 = vader_types_canonical_args_key(((vader_struct_vader_types_StructType_t*) t0)->f_args);
        l2 = vader_host_std_core_byte_len(l1);
        l3 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(23) + l2));
        l2 = (size_t) (int64_t) INT64_C(0);
        l2 = std_core_write_string_at(l3, l2, 2074u);
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_id;
        l4 = ((int64_t) (int32_t) t2);
        l2 = std_core_write_int(l3, l2, l4);
        l2 = std_core_write_string_at(l3, l2, 518u);
        l2 = std_core_write_string_at(l3, l2, l1);
        l2 = std_core_write_string_at(l3, l2, 537u);
        t1 = std_core_finish_buffer(l3, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 938u) {
        t0 = l0.payload.obj;
        l1 = vader_types_canonical_args_key(((vader_struct_vader_types_TraitType_t*) t0)->f_args);
        l2 = vader_host_std_core_byte_len(l1);
        l3 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(23) + l2));
        l2 = (size_t) (int64_t) INT64_C(0);
        l2 = std_core_write_string_at(l3, l2, 2216u);
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol)->f_id;
        l4 = ((int64_t) (int32_t) t2);
        l2 = std_core_write_int(l3, l2, l4);
        l2 = std_core_write_string_at(l3, l2, 518u);
        l2 = std_core_write_string_at(l3, l2, l1);
        l2 = std_core_write_string_at(l3, l2, 537u);
        t1 = std_core_finish_buffer(l3, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        t3 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_immutable;
        if (t3) {
            t0 = l0.payload.obj;
            l1 = vader_types_canonical_key(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
            t1 = concat_3(1224u, l1, 343u);
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l0.payload.obj;
        l1 = vader_types_canonical_key(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        t1 = concat_3(1236u, l1, 343u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 939u) {
        t0 = l0.payload.obj;
        l1 = vader_types_canonical_args_key(((vader_struct_vader_types_TupleType_t*) t0)->f_elements);
        t1 = concat_3(834u, l1, 537u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 929u) {
        t0 = l0.payload.obj;
        l1 = vader_types_canonical_args_key(((vader_struct_vader_types_FnType_t*) t0)->f_params);
        t0 = l0.payload.obj;
        l5 = vader_types_canonical_key(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
        t1 = concat_4(608u, l1, 539u, l5);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 942u) {
        t0 = l0.payload.obj;
        l1 = vader_types_canonical_args_key(((vader_struct_vader_types_UnionType_t*) t0)->f_variants);
        t1 = concat_3(839u, l1, 537u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 941u) {
        l3 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
        l2 = (size_t) (int64_t) INT64_C(0);
        l2 = std_core_write_string_at(l3, l2, 674u);
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) t0)->f_symbol)->f_id;
        l4 = ((int64_t) (int32_t) t2);
        l2 = std_core_write_int(l3, l2, l4);
        t1 = std_core_finish_buffer(l3, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 928u) {
        l3 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
        l2 = (size_t) (int64_t) INT64_C(0);
        l2 = std_core_write_string_at(l3, l2, 1528u);
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_EnumType_t*) t0)->f_symbol)->f_id;
        l4 = ((int64_t) (int32_t) t2);
        l2 = std_core_write_int(l3, l2, l4);
        t1 = std_core_finish_buffer(l3, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 927u) {
        l3 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
        l2 = (size_t) (int64_t) INT64_C(0);
        l2 = std_core_write_string_at(l3, l2, 1490u);
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_DistinctType_t*) t0)->f_symbol)->f_id;
        l4 = ((int64_t) (int32_t) t2);
        l2 = std_core_write_int(l3, l2, l4);
        t1 = std_core_finish_buffer(l3, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 940u) {
        { vader_gc_top = gc_frame.prev; return 652u; }
    }
    if (l0.tag == 936u) {
        { vader_gc_top = gc_frame.prev; return 751u; }
    }
    if (l0.tag == 943u) {
        { vader_gc_top = gc_frame.prev; return 541u; }
    }
    if (l0.tag == 933u) {
        { vader_gc_top = gc_frame.prev; return 239u; }
    }
    if (l0.tag == 932u) {
        { vader_gc_top = gc_frame.prev; return 611u; }
    }
    if (l0.tag == 930u) {
        { vader_gc_top = gc_frame.prev; return 609u; }
    }
    if (l0.tag == 931u) {
        { vader_gc_top = gc_frame.prev; return 610u; }
    }
    if (l0.tag == 925u) {
        { vader_gc_top = gc_frame.prev; return 552u; }
    }
    vader_unreachable("unreachable return in vader_types$canonical_key");
    vader_gc_top = gc_frame.prev;
}

static bool vader_types_contains_distinct(vader_box_t l0) {
    void* l1;
    size_t l2, l3;
    void* t0;
    vader_box_t t1;
    bool t2;
    int64_t t3;
    if (l0.tag == 927u) {
        return true;
    }
    if (l0.tag == 937u) {
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
                }
            }
        }
    }
    if (l0.tag == 938u) {
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
                    t3 = (l3 + INT64_C(1));
                    l3 = (size_t) (int64_t) t3;
                    goto loop_50;
                }
            }
        }
    }
    if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        t2 = vader_types_contains_distinct(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        return t2;
    }
    if (l0.tag == 939u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
        l2 = ((vader_array_t*) l1)->length;
        l3 = (size_t) (int64_t) INT64_C(0);
        {
            loop_92: {
                if ((l3 < l2)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l3 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
                    t2 = vader_types_contains_distinct(t1);
                    if (t2) {
                        return true;
                    }
                    t3 = (l3 + INT64_C(1));
                    l3 = (size_t) (int64_t) t3;
                    goto loop_92;
                }
            }
        }
    }
    if (l0.tag == 929u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
        l2 = ((vader_array_t*) l1)->length;
        l3 = (size_t) (int64_t) INT64_C(0);
        {
            loop_125: {
                if ((l3 < l2)) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l3 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l3);
                    t2 = vader_types_contains_distinct(t1);
                    if (t2) {
                        return true;
                    }
                    t3 = (l3 + INT64_C(1));
                    l3 = (size_t) (int64_t) t3;
                    goto loop_125;
                }
            }
        }
        t0 = l0.payload.obj;
        t2 = vader_types_contains_distinct(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
        return t2;
    }
    if (l0.tag == 942u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        l2 = ((vader_array_t*) l1)->length;
        l3 = (size_t) (int64_t) INT64_C(0);
        {
            loop_163: {
                if ((l3 < l2)) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                    if ((size_t) l3 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l3);
                    t2 = vader_types_contains_distinct(t1);
                    if (t2) {
                        return true;
                    }
                    t3 = (l3 + INT64_C(1));
                    l3 = (size_t) (int64_t) t3;
                    goto loop_163;
                }
            }
        }
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
    if (l0.tag == 935u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 941u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 928u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_EnumType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 927u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_DistinctType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 943u) {
        { vader_gc_top = gc_frame.prev; return 541u; }
    }
    if (l0.tag == 933u) {
        { vader_gc_top = gc_frame.prev; return 1969u; }
    }
    if (l0.tag == 932u) {
        { vader_gc_top = gc_frame.prev; return 2517u; }
    }
    if (l0.tag == 931u) {
        { vader_gc_top = gc_frame.prev; return 2516u; }
    }
    if (l0.tag == 930u) {
        { vader_gc_top = gc_frame.prev; return 2515u; }
    }
    if (l0.tag == 936u) {
        { vader_gc_top = gc_frame.prev; return 753u; }
    }
    if (l0.tag == 940u) {
        { vader_gc_top = gc_frame.prev; return 2261u; }
    }
    if (l0.tag == 925u) {
        { vader_gc_top = gc_frame.prev; return 555u; }
    }
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 176u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 396u);
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
    size_t t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 935u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 927u || l0.tag == 928u || l0.tag == 941u)) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_DistinctType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 937u || l0.tag == 938u)) {
        t0 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_args)->length;
        if (t2 == INT64_C(0)) {
            t0 = l0.payload.obj;
            t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_name;
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else {
    }
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 176u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 396u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    vader_types_write_type_mut(l1, l0, false);
    t1 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void vader_types_for_each_type(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
    ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, l0);
    if (l0.tag == 937u) {
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
                }
            }
        }
    } else {
        if (l0.tag == 938u) {
            t0 = l0.payload.obj;
            l2 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
            l3 = ((vader_array_t*) l2)->length;
            l4 = (size_t) (int64_t) INT64_C(0);
            {
                loop_46: {
                    if ((l4 < l3)) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                        vader_types_for_each_type(t1, l1);
                        t2 = (l4 + INT64_C(1));
                        l4 = (size_t) (int64_t) t2;
                        goto loop_46;
                    }
                }
            }
        } else {
            if (l0.tag == 926u) {
                t0 = l0.payload.obj;
                vader_types_for_each_type(((vader_struct_vader_types_ArrayType_t*) t0)->f_element, l1);
            } else {
                if (l0.tag == 939u) {
                    t0 = l0.payload.obj;
                    l2 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
                    l3 = ((vader_array_t*) l2)->length;
                    l4 = (size_t) (int64_t) INT64_C(0);
                    {
                        loop_86: {
                            if ((l4 < l3)) {
                                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                                t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
                                vader_types_for_each_type(t1, l1);
                                t2 = (l4 + INT64_C(1));
                                l4 = (size_t) (int64_t) t2;
                                goto loop_86;
                            }
                        }
                    }
                } else {
                    if (l0.tag == 929u) {
                        t0 = l0.payload.obj;
                        l2 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
                        l3 = ((vader_array_t*) l2)->length;
                        l4 = (size_t) (int64_t) INT64_C(0);
                        {
                            loop_117: {
                                if ((l4 < l3)) {
                                    vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                                    if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                    if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                    t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
                                    vader_types_for_each_type(t1, l1);
                                    t2 = (l4 + INT64_C(1));
                                    l4 = (size_t) (int64_t) t2;
                                    goto loop_117;
                                }
                            }
                        }
                        t0 = l0.payload.obj;
                        vader_types_for_each_type(((vader_struct_vader_types_FnType_t*) t0)->f_return_type, l1);
                    } else {
                        if (l0.tag == 942u) {
                            t0 = l0.payload.obj;
                            l2 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
                            l3 = ((vader_array_t*) l2)->length;
                            l4 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_153: {
                                    if ((l4 < l3)) {
                                        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
                                        if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                                        if ((size_t) l4 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t1 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4);
                                        vader_types_for_each_type(t1, l1);
                                        t2 = (l4 + INT64_C(1));
                                        l4 = (size_t) (int64_t) t2;
                                        goto loop_153;
                                    }
                                }
                            }
                        } else {
                            if (l0.tag == 927u) {
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

bool vader_types_is_reference_name(vader_string_t l0) {
    vader_box_t l1;
    bool l2;
    void* t0;
    l1 = vader_types_primitive_meta(l0);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_types_PrimitiveMeta_t*) t0)->f_is_reference;
    } else {
        l2 = false;
    }
    return l2;
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
    vader_obj_header_init(_a0_obj, 926u);
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
    vader_obj_header_init(_a0_obj, 927u);
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
    vader_obj_header_init(_a0_obj, 928u);
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
    vader_array_t* _a0_arr = vader_array_new(6u, 0u, 12u, 174u);
    l2 = (void*) _a0_arr;
    vader_struct_vader_types_FnType_t* _a1_obj = (vader_struct_vader_types_FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_FnType_t));
    vader_obj_header_init(_a1_obj, 929u);
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
    vader_array_t* _a0_arr = vader_array_new(6u, 0u, 12u, 174u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_types_FnType_t*) l0)->f_params_mutable)->length;
    l5 = (size_t) (int64_t) INT64_C(1);
    {
        vader_array_t* _pc18_hdr = (vader_array_t*) l3;
        size_t _pc18_len = _pc18_hdr->length;
        size_t _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
        void* _pc18_slots = _pc18_hdr->buf->slots;
        loop_18: {
            if ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_types_FnType_t*) l0)->f_params_mutable);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_box_bool(174u, ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5]);
                l6 = t1.payload.b;
                if (VADER_LIKELY(_pc18_len < _pc18_cap)) {
                    ((uint8_t*) _pc18_slots)[_pc18_len] = (uint8_t) (l6);
                    _pc18_len += 1;
                } else {
                    _pc18_hdr->length = _pc18_len;
                    if (_pc18_hdr->buf->length < _pc18_len) { _pc18_hdr->buf->length = _pc18_len; }
                    vader_array_push_bool((vader_array_t*) l3, l6);
                    _pc18_hdr = (vader_array_t*) l3;
                    _pc18_len = _pc18_hdr->length;
                    _pc18_cap = (_pc18_hdr->offset == 0 && !vader_array_is_borrowed(_pc18_hdr) && _pc18_hdr->length >= _pc18_hdr->buf->length) ? _pc18_hdr->capacity : (size_t) 0;
                    _pc18_slots = _pc18_hdr->buf->slots;
                }
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_18;
            }
            _pc18_hdr->length = _pc18_len;
            if (_pc18_hdr->buf->length < _pc18_len) { _pc18_hdr->buf->length = _pc18_len; }
        }
    }
    vader_struct_vader_types_FnType_t* _a2_obj = (vader_struct_vader_types_FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_FnType_t));
    vader_obj_header_init(_a2_obj, 929u);
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
    vader_obj_header_init(_a0_obj, 929u);
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
    vader_obj_header_init(_a0_obj, 935u);
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
    vader_obj_header_init(_a0_obj, 937u);
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
    vader_obj_header_init(_a0_obj, 938u);
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
    vader_obj_header_init(_a0_obj, 939u);
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
    vader_obj_header_init(_a0_obj, 941u);
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
    vader_obj_header_init(_a0_obj, 942u);
    _a0_obj->f_variants = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_types_primitive_meta(vader_string_t l0) {
    void* l1;
    void* l4;
    size_t l2, l3;
    vader_string_t t0;
    int64_t t1;
    vader_box_t t2;
    l1 = (void*) &vader_data_9;
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
            }
        }
    }
    return l0;
}

int64_t vader_types_slot_byte_align(vader_box_t l0) {
    int64_t l1;
    l1 = vader_types_slot_byte_size(l0);
    if ((l1 > INT64_C(8))) {
        return INT64_C(8);
    }
    return l1;
}

int64_t vader_types_slot_byte_size(vader_box_t l0) {
    int64_t l1;
    void* t0;
    vader_string_t t1;
    if (l0.tag == 935u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        l1 = vader_types_primitive_size(t1);
    } else {
        if (l0.tag == 928u) {
            t0 = l0.payload.obj;
            t1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
            l1 = vader_types_primitive_size(t1);
        } else {
            if (l0.tag == 927u) {
                t0 = l0.payload.obj;
                l1 = vader_types_slot_byte_size(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
            } else {
                if ((l0.tag == 926u || l0.tag == 929u || l0.tag == 937u || l0.tag == 939u)) {
                    l1 = INT64_C(8);
                } else {
                    if ((l0.tag == 925u || l0.tag == 938u || l0.tag == 942u)) {
                        l1 = INT64_C(16);
                    } else {
                        if ((l0.tag == 930u || l0.tag == 931u || l0.tag == 932u || l0.tag == 933u || l0.tag == 936u || l0.tag == 940u || l0.tag == 941u || l0.tag == 943u)) {
                            l1 = INT64_C(0);
                        } else {
                            vader_unreachable("unreachable return in vader_types$slot_byte_size");
                        }
                    }
                }
            }
        }
    }
    return l1;
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
    if (l0.tag == 935u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_types_contains_distinct(l0);
    if (!(t1)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 927u) {
        t0 = l0.payload.obj;
        t2 = vader_types_strip_distinct(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 937u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_StructType_t*) t0)->f_symbol;
        t0 = l0.payload.obj;
        l2 = vader_types_strip_distinct_each(((vader_struct_vader_types_StructType_t*) t0)->f_args);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_types_StructType_t*) t0)->f_immutable;
        t2 = vader_types_mk_struct(l1, l2, l3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 938u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol;
        t0 = l0.payload.obj;
        l2 = vader_types_strip_distinct_each(((vader_struct_vader_types_TraitType_t*) t0)->f_args);
        t2 = vader_types_mk_trait(l1, l2);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        l4 = vader_types_strip_distinct(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_immutable;
        t2 = vader_types_mk_array(l4, l3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 939u) {
        t0 = l0.payload.obj;
        l1 = vader_types_strip_distinct_each(((vader_struct_vader_types_TupleType_t*) t0)->f_elements);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_types_TupleType_t*) t0)->f_immutable;
        t2 = vader_types_mk_tuple(l1, l3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 929u) {
        l1 = l0.payload.obj;
        t0 = l0.payload.obj;
        l2 = vader_types_strip_distinct_each(((vader_struct_vader_types_FnType_t*) t0)->f_params);
        t0 = l0.payload.obj;
        l4 = vader_types_strip_distinct(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
        t2 = vader_types_mk_fn_like(l1, l2, l4);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 942u) {
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
    vader_array_t* _a0_arr = vader_array_new(142u, 0u, 13u, 1245u);
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
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_types_struct_backing(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 937u) {
        t0 = l0.payload.obj;
        return vader_ref_box(t0);
    }
    if (l0.tag == 927u) {
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
    if (l0.tag == 939u) {
        t0 = l0.payload.obj;
        return vader_ref_box(t0);
    }
    if (l0.tag == 927u) {
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
    if (l0.tag == 937u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 938u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 928u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_EnumType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 927u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_DistinctType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 926u) {
        { vader_gc_top = gc_frame.prev; return 870u; }
    }
    t1 = vader_types_display_type_key(l0);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool vader_types_type_grants_mutation(vader_box_t l0) {
    bool l1;
    void* t0;
    bool t1;
    if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_immutable;
        l1 = !(t1);
    } else {
        if (l0.tag == 937u) {
            t0 = l0.payload.obj;
            t1 = ((vader_struct_vader_types_StructType_t*) t0)->f_immutable;
            l1 = !(t1);
        } else {
            if (l0.tag == 939u) {
                t0 = l0.payload.obj;
                t1 = ((vader_struct_vader_types_TupleType_t*) t0)->f_immutable;
                l1 = !(t1);
            } else {
                if (l0.tag == 942u) {
                    t0 = l0.payload.obj;
                    l1 = vader_types_variants_grant_mutation(((vader_struct_vader_types_UnionType_t*) t0)->f_variants);
                } else {
                    if ((l0.tag == 925u || l0.tag == 927u || l0.tag == 928u || l0.tag == 929u || l0.tag == 930u || l0.tag == 931u || l0.tag == 932u || l0.tag == 933u || l0.tag == 935u || l0.tag == 936u || l0.tag == 938u || l0.tag == 940u || l0.tag == 941u || l0.tag == 943u)) {
                        l1 = false;
                    } else {
                        vader_unreachable("unreachable return in vader_types$type_grants_mutation");
                    }
                }
            }
        }
    }
    return l1;
}

bool vader_types_type_is_immutable(vader_box_t l0) {
    bool l1;
    void* t0;
    if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_immutable;
    } else {
        if (l0.tag == 937u) {
            t0 = l0.payload.obj;
            l1 = ((vader_struct_vader_types_StructType_t*) t0)->f_immutable;
        } else {
            if (l0.tag == 939u) {
                t0 = l0.payload.obj;
                l1 = ((vader_struct_vader_types_TupleType_t*) t0)->f_immutable;
            } else {
                if ((l0.tag == 925u || l0.tag == 927u || l0.tag == 928u || l0.tag == 929u || l0.tag == 930u || l0.tag == 931u || l0.tag == 932u || l0.tag == 933u || l0.tag == 935u || l0.tag == 936u || l0.tag == 938u || l0.tag == 940u || l0.tag == 941u || l0.tag == 942u || l0.tag == 943u)) {
                    l1 = false;
                } else {
                    vader_unreachable("unreachable return in vader_types$type_is_immutable");
                }
            }
        }
    }
    return l1;
}

static bool vader_types_variants_grant_mutation(void* l0) {
    void* l1;
    size_t l2, l3;
    size_t t0;
    vader_box_t t1;
    bool t2;
    int64_t t3;
    t0 = ((vader_array_t*) l0)->length;
    if (t0 == INT64_C(0)) {
        return false;
    }
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_14: {
            if ((l3 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                t2 = vader_types_type_grants_mutation(t1);
                if (!(t2)) {
                    return false;
                }
                t3 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t3;
                goto loop_14;
            }
        }
    }
    return true;
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
    vader_types_write_type_list_mut(l0, l2, 393u, l3);
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
                }
                l4 = false;
                vader_types_write_type_mut(l0, l8, l3);
                t0 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t0;
                goto loop_9;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_types_write_type_mut(void* l0, vader_box_t l1, bool l2) {
    vader_string_t l3 = 0;
    void* l4 = NULL;
    bool l5;
    vader_box_t l6 = vader_box_null();
    size_t l7, l8;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l1, &l6 };
    void** gc_raw_roots[3] = { &l0, &l4, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 935u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        std_string_builder_append(l0, l3);
    } else {
        if (l1.tag == 937u) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_name;
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
            vader_types_write_named_mut(l0, l3, l4, l2);
            if (l2) {
                t0 = l1.payload.obj;
                t1 = ((vader_struct_vader_types_StructType_t*) t0)->f_immutable;
                l5 = !(t1);
            } else {
                l5 = false;
            }
            if (l5) {
                std_string_builder_append_char(l0, 33u);
            }
        } else {
            if (l1.tag == 928u) {
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_EnumType_t*) t0)->f_symbol)->f_name;
                std_string_builder_append(l0, l3);
            } else {
                if (l1.tag == 927u) {
                    t0 = l1.payload.obj;
                    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_DistinctType_t*) t0)->f_symbol)->f_name;
                    std_string_builder_append(l0, l3);
                } else {
                    if (l1.tag == 938u) {
                        t0 = l1.payload.obj;
                        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol)->f_name;
                        t0 = l1.payload.obj;
                        l4 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
                        vader_types_write_named_mut(l0, l3, l4, l2);
                    } else {
                        if (l1.tag == 941u) {
                            t0 = l1.payload.obj;
                            l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) t0)->f_symbol)->f_name;
                            std_string_builder_append(l0, l3);
                        } else {
                            if (l1.tag == 940u) {
                                std_string_builder_append(l0, 2261u);
                            } else {
                                if (l1.tag == 936u) {
                                    std_string_builder_append(l0, 753u);
                                } else {
                                    if (l1.tag == 943u) {
                                        std_string_builder_append(l0, 541u);
                                    } else {
                                        if (l1.tag == 933u) {
                                            std_string_builder_append(l0, 1969u);
                                        } else {
                                            if (l1.tag == 932u) {
                                                std_string_builder_append(l0, 2517u);
                                            } else {
                                                if (l1.tag == 931u) {
                                                    std_string_builder_append(l0, 2516u);
                                                } else {
                                                    if (l1.tag == 930u) {
                                                        std_string_builder_append(l0, 2515u);
                                                    } else {
                                                        if (l1.tag == 926u) {
                                                            t0 = l1.payload.obj;
                                                            if (((vader_struct_vader_types_ArrayType_t*) t0)->f_element.tag == 942u) {
                                                                l5 = true;
                                                            } else {
                                                                t0 = l1.payload.obj;
                                                                l5 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_element.tag == 929u;
                                                            }
                                                            if (l5) {
                                                                std_string_builder_append_char(l0, 40u);
                                                            }
                                                            t0 = l1.payload.obj;
                                                            l6 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_element;
                                                            vader_types_write_type_mut(l0, l6, l2);
                                                            if (l5) {
                                                                std_string_builder_append_char(l0, 41u);
                                                            }
                                                            std_string_builder_append(l0, 870u);
                                                            if (l2) {
                                                                t0 = l1.payload.obj;
                                                                t1 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_immutable;
                                                                l5 = !(t1);
                                                            } else {
                                                                l5 = false;
                                                            }
                                                            if (l5) {
                                                                std_string_builder_append_char(l0, 33u);
                                                            }
                                                        } else {
                                                            if (l1.tag == 939u) {
                                                                std_string_builder_append_char(l0, 91u);
                                                                t0 = l1.payload.obj;
                                                                l4 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
                                                                vader_types_write_type_list_mut(l0, l4, 393u, l2);
                                                                std_string_builder_append_char(l0, 93u);
                                                                if (l2) {
                                                                    t0 = l1.payload.obj;
                                                                    t1 = ((vader_struct_vader_types_TupleType_t*) t0)->f_immutable;
                                                                    l5 = !(t1);
                                                                } else {
                                                                    l5 = false;
                                                                }
                                                                if (l5) {
                                                                    std_string_builder_append_char(l0, 33u);
                                                                }
                                                            } else {
                                                                if (l1.tag == 929u) {
                                                                    std_string_builder_append(l0, 1662u);
                                                                    l5 = true;
                                                                    t0 = l1.payload.obj;
                                                                    l7 = ((vader_array_t*) ((vader_struct_vader_types_FnType_t*) t0)->f_params)->length;
                                                                    l8 = (size_t) (int64_t) INT64_C(0);
                                                                    {
                                                                        loop_268: {
                                                                            if ((l8 < l7)) {
                                                                                if (!(l5)) {
                                                                                    std_string_builder_append(l0, 393u);
                                                                                }
                                                                                l5 = false;
                                                                                t0 = l1.payload.obj;
                                                                                vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_types_FnType_t*) t0)->f_params);
                                                                                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                                                                                if ((size_t) l8 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
                                                                                vader_types_write_type_mut(l0, l6, l2);
                                                                                t2 = (l8 + INT64_C(1));
                                                                                l8 = (size_t) (int64_t) t2;
                                                                                goto loop_268;
                                                                            }
                                                                        }
                                                                    }
                                                                    std_string_builder_append(l0, 346u);
                                                                    t0 = l1.payload.obj;
                                                                    l6 = ((vader_struct_vader_types_FnType_t*) t0)->f_return_type;
                                                                    vader_types_write_type_mut(l0, l6, l2);
                                                                } else {
                                                                    if (l1.tag == 942u) {
                                                                        t0 = l1.payload.obj;
                                                                        l4 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
                                                                        vader_types_write_type_list_mut(l0, l4, 216u, l2);
                                                                    } else {
                                                                        if (l1.tag == 925u) {
                                                                            std_string_builder_append(l0, 555u);
                                                                        } else {
                                                                            { vader_gc_top = gc_frame.prev; return; }
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
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

