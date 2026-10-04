#include "bootstrap.split.h"

static bool vader_types_any_variant_may_grant_mutation(void* l0);
static bool vader_types_variants_grant_mutation(void* l0);
static void vader_types_write_named_mut(void* l0, vader_string_t l1, void* l2, bool l3);
static void vader_types_write_type(void* l0, vader_box_t l1);
static void vader_types_write_type_list_mut(void* l0, void* l1, vader_string_t l2, bool l3);
static void vader_types_write_type_mut(void* l0, vader_box_t l1, bool l2);

static bool vader_types_any_variant_may_grant_mutation(void* l0) {
    void* l1;
    size_t l2, l3;
    vader_box_t t0;
    bool t1;
    int64_t t2;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = vader_types_type_may_grant_mutation(t0);
        if (t1) {
            return true;
        }
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    return false;
}

vader_box_t vader_types_array_backing(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 1008u) {
        t0 = l0.payload.obj;
        return vader_ref_box(t0);
    }
    if (!(l0.tag == 1009u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    t1 = vader_types_array_backing(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    return t1;
}

bool vader_types_boxes_as_representation(vader_box_t l0) {
    if (l0.tag == 1010u) {
        return true;
    }
    return l0.tag == 1009u;
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l0)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 223u);
    t1 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 393u);
    _a1_obj->f_parts = t1;
    l1 = (void*) _a1_obj;
    l2 = true;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        if (!(l2)) {
            std_string_builder_append(l1, 251u);
        }
        l2 = false;
        l7 = vader_types_canonical_key(l6);
        std_string_builder_append(l1, l7);
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    t3 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1017u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        t1 = concat_2(1935u, l1);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1019u) {
        t0 = l0.payload.obj;
        l1 = vader_types_canonical_args_key(((vader_struct_vader_types_StructType_t*) t0)->f_args);
        l2 = vader_host_std_core_byte_len(l1);
        l3 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(23) + l2));
        l2 = (size_t) 0;
        l2 = std_core_write_string_at(l3, l2, 2011u);
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_id;
        l4 = ((int64_t) (int32_t) t2);
        l2 = std_core_write_int(l3, l2, l4);
        l2 = std_core_write_string_at(l3, l2, 349u);
        l2 = std_core_write_string_at(l3, l2, l1);
        l2 = std_core_write_string_at(l3, l2, 370u);
        t1 = std_core_finish_buffer(l3, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1020u) {
        t0 = l0.payload.obj;
        l1 = vader_types_canonical_args_key(((vader_struct_vader_types_TraitType_t*) t0)->f_args);
        l2 = vader_host_std_core_byte_len(l1);
        l3 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(23) + l2));
        l2 = (size_t) 0;
        l2 = std_core_write_string_at(l3, l2, 2152u);
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol)->f_id;
        l4 = ((int64_t) (int32_t) t2);
        l2 = std_core_write_int(l3, l2, l4);
        l2 = std_core_write_string_at(l3, l2, 349u);
        l2 = std_core_write_string_at(l3, l2, l1);
        l2 = std_core_write_string_at(l3, l2, 370u);
        t1 = std_core_finish_buffer(l3, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1008u) {
        t0 = l0.payload.obj;
        t3 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_immutable;
        if (!(t3)) {
            t0 = l0.payload.obj;
            l5 = vader_types_canonical_key(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
            t1 = concat_3(1134u, l5, 223u);
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l0.payload.obj;
        l1 = vader_types_canonical_key(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        t1 = concat_3(1124u, l1, 223u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1021u) {
        t0 = l0.payload.obj;
        l1 = vader_types_canonical_args_key(((vader_struct_vader_types_TupleType_t*) t0)->f_elements);
        t1 = concat_3(702u, l1, 370u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1011u) {
        t0 = l0.payload.obj;
        l1 = vader_types_canonical_args_key(((vader_struct_vader_types_FnType_t*) t0)->f_params);
        t0 = l0.payload.obj;
        l5 = vader_types_canonical_key(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
        t1 = concat_4(445u, l1, 372u, l5);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1024u) {
        t0 = l0.payload.obj;
        l1 = vader_types_canonical_args_key(((vader_struct_vader_types_UnionType_t*) t0)->f_variants);
        t1 = concat_3(707u, l1, 370u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1023u) {
        l3 = std_core_new_byte_buffer((size_t) 21);
        l2 = (size_t) 0;
        l2 = std_core_write_string_at(l3, l2, 527u);
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) t0)->f_symbol)->f_id;
        l4 = ((int64_t) (int32_t) t2);
        l2 = std_core_write_int(l3, l2, l4);
        t1 = std_core_finish_buffer(l3, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1010u) {
        l3 = std_core_new_byte_buffer((size_t) 21);
        l2 = (size_t) 0;
        l2 = std_core_write_string_at(l3, l2, 1430u);
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_EnumType_t*) t0)->f_symbol)->f_id;
        l4 = ((int64_t) (int32_t) t2);
        l2 = std_core_write_int(l3, l2, l4);
        t1 = std_core_finish_buffer(l3, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1009u) {
        l3 = std_core_new_byte_buffer((size_t) 21);
        l2 = (size_t) 0;
        l2 = std_core_write_string_at(l3, l2, 1386u);
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_DistinctType_t*) t0)->f_symbol)->f_id;
        l4 = ((int64_t) (int32_t) t2);
        l2 = std_core_write_int(l3, l2, l4);
        t1 = std_core_finish_buffer(l3, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1022u) {
        { vader_gc_top = gc_frame.prev; return 504u; }
    }
    if (l0.tag == 1018u) {
        { vader_gc_top = gc_frame.prev; return 607u; }
    }
    if (l0.tag == 1025u) {
        { vader_gc_top = gc_frame.prev; return 374u; }
    }
    if (l0.tag == 1015u) {
        { vader_gc_top = gc_frame.prev; return 154u; }
    }
    if (l0.tag == 1014u) {
        { vader_gc_top = gc_frame.prev; return 448u; }
    }
    if (l0.tag == 1012u) {
        { vader_gc_top = gc_frame.prev; return 446u; }
    }
    if (l0.tag == 1013u) {
        { vader_gc_top = gc_frame.prev; return 447u; }
    }
    if (!(l0.tag == 1007u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    { vader_gc_top = gc_frame.prev; return 385u; }
}

bool vader_types_contains_distinct(vader_box_t l0) {
    void* l1;
    size_t l2, l3;
    void* t0;
    vader_box_t t1;
    bool t2;
    int64_t t3;
    if (l0.tag == 1009u) {
        return true;
    }
    if (l0.tag == 1019u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
        l2 = ((vader_array_t*) l1)->length;
        l3 = (size_t) 0;
        while ((l3 < l2)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            t2 = vader_types_contains_distinct(t1);
            if (t2) {
                return true;
            }
            t3 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t3;
        }
    }
    if (l0.tag == 1020u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
        l2 = ((vader_array_t*) l1)->length;
        l3 = (size_t) 0;
        while ((l3 < l2)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
            t2 = vader_types_contains_distinct(t1);
            if (t2) {
                return true;
            }
            t3 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t3;
        }
    }
    if (l0.tag == 1008u) {
        t0 = l0.payload.obj;
        t2 = vader_types_contains_distinct(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        return t2;
    }
    if (l0.tag == 1021u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
        l2 = ((vader_array_t*) l1)->length;
        l3 = (size_t) 0;
        while ((l3 < l2)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
            t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
            t2 = vader_types_contains_distinct(t1);
            if (t2) {
                return true;
            }
            t3 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t3;
        }
    }
    if (l0.tag == 1011u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
        l2 = ((vader_array_t*) l1)->length;
        l3 = (size_t) 0;
        while ((l3 < l2)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
            t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l3);
            t2 = vader_types_contains_distinct(t1);
            if (t2) {
                return true;
            }
            t3 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t3;
        }
        t0 = l0.payload.obj;
        t2 = vader_types_contains_distinct(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
        return t2;
    }
    if (l0.tag == 1024u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        l2 = ((vader_array_t*) l1)->length;
        l3 = (size_t) 0;
        while ((l3 < l2)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l3)
            t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l3);
            t2 = vader_types_contains_distinct(t1);
            if (t2) {
                return true;
            }
            t3 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t3;
        }
    }
    return false;
}

vader_string_t vader_types_core_trait_key(vader_string_t l0) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = concat_2(2063u, l0);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_types_declaration_key(void* l0) {
    void* l1 = NULL;
    size_t l2;
    int64_t l3;
    int32_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_core_new_byte_buffer((size_t) 21);
    l2 = (size_t) 0;
    l2 = std_core_write_string_at(l1, l2, 163u);
    t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core_write_int(l1, l2, l3);
    t1 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_types_display_type(vader_box_t l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1017u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1023u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1010u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_EnumType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1009u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_DistinctType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1025u) {
        { vader_gc_top = gc_frame.prev; return 374u; }
    }
    if (l0.tag == 1015u) {
        { vader_gc_top = gc_frame.prev; return 1885u; }
    }
    if (l0.tag == 1014u) {
        { vader_gc_top = gc_frame.prev; return 2486u; }
    }
    if (l0.tag == 1013u) {
        { vader_gc_top = gc_frame.prev; return 2485u; }
    }
    if (l0.tag == 1012u) {
        { vader_gc_top = gc_frame.prev; return 2484u; }
    }
    if (l0.tag == 1018u) {
        { vader_gc_top = gc_frame.prev; return 609u; }
    }
    if (l0.tag == 1022u) {
        { vader_gc_top = gc_frame.prev; return 2207u; }
    }
    if (!(l0.tag == 1007u)) {
        vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 223u);
        t0 = (void*) _a0_arr;
        vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
        vader_obj_header_init(_a1_obj, 393u);
        _a1_obj->f_parts = t0;
        l1 = (void*) _a1_obj;
        vader_types_write_type(l1, l0);
        t1 = std_string_builder_StringBuilder_Display_to_string(l1);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 389u; }
}

vader_string_t vader_types_display_type_key(vader_box_t l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    size_t t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1017u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 1009u || l0.tag == 1010u || l0.tag == 1023u)) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_DistinctType_t*) t0)->f_symbol)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 1019u || l0.tag == 1020u)) {
        t0 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_args)->length;
        if (t2 == INT64_C(0)) {
            t0 = l0.payload.obj;
            t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_name;
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 223u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 393u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    vader_types_write_type_mut(l1, l0, false);
    t1 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    if (l0.tag == 1019u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_types_for_each_type(t1, l1);
            t2 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t2;
        }
    } else if (l0.tag == 1020u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            vader_types_for_each_type(t1, l1);
            t2 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t2;
        }
    } else if (l0.tag == 1008u) {
        t0 = l0.payload.obj;
        vader_types_for_each_type(((vader_struct_vader_types_ArrayType_t*) t0)->f_element, l1);
    } else if (l0.tag == 1021u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
            t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
            vader_types_for_each_type(t1, l1);
            t2 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t2;
        }
    } else if (l0.tag == 1011u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
            t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
            vader_types_for_each_type(t1, l1);
            t2 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t2;
        }
        t0 = l0.payload.obj;
        vader_types_for_each_type(((vader_struct_vader_types_FnType_t*) t0)->f_return_type, l1);
    } else if (l0.tag == 1024u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
            t1 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4);
            vader_types_for_each_type(t1, l1);
            t2 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t2;
        }
    } else if (l0.tag == 1009u) {
        t0 = l0.payload.obj;
        vader_types_for_each_type(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

vader_string_t vader_types_impl_base_key(vader_box_t l0) {
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l0.tag == 1009u || l0.tag == 1010u || l0.tag == 1019u || l0.tag == 1020u)) {
        t0 = l0.payload.obj;
        t1 = vader_types_declaration_key(((vader_struct_vader_types_DistinctType_t*) t0)->f_symbol);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 1008u)) {
        t1 = vader_types_display_type_key(l0);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 748u; }
}

bool vader_types_is_float_name(vader_string_t l0) {
    vader_box_t l1;
    void* t0;
    bool t1;
    l1 = vader_types_primitive_meta(l0);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveMeta_t*) t0)->f_is_float;
        return t1;
    }
    return false;
}

bool vader_types_is_int_name(vader_string_t l0) {
    vader_box_t l1;
    void* t0;
    bool t1;
    l1 = vader_types_primitive_meta(l0);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveMeta_t*) t0)->f_is_int;
        return t1;
    }
    return false;
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
        return l2;
    }
    return false;
}

bool vader_types_is_primitive_name(vader_string_t l0) {
    vader_box_t t0;
    t0 = vader_types_primitive_meta(l0);
    return !(t0.tag == 0u);
}

bool vader_types_is_reference_name(vader_string_t l0) {
    vader_box_t l1;
    void* t0;
    bool t1;
    l1 = vader_types_primitive_meta(l0);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveMeta_t*) t0)->f_is_reference;
        return t1;
    }
    return false;
}

bool vader_types_is_signed_int_name(vader_string_t l0) {
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
        return t1;
    }
    return false;
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
        return !(t1);
    }
    return false;
}

vader_box_t vader_types_kept_type_argument(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_types_strip_distinct(l0);
    if (l1.tag == 1017u) {
        t0 = l1.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1010u) {
        t0 = l1.payload.obj;
        if (!(((vader_struct_vader_types_EnumType_t*) t0)->f_data.tag == 0u)) {
            t0 = l1.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

vader_string_t vader_types_mangle_module_id(vader_string_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    size_t l3, l4;
    uint8_t l5;
    bool l6;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l1, &l2 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core_bytes(l0);
    vader_array_t* _a0_arr = vader_array_new(11u, 0u, 1u, 229u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l1)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (size_t) l3);
    l2 = (void*) _a1_arr;
    l3 = ((vader_array_t*) l1)->length;
    l4 = (size_t) 0;
    vader_array_t* _pc17_hdr = (vader_array_t*) l2;
    size_t _pc17_len = _pc17_hdr->length;
    size_t _pc17_cap = (_pc17_hdr->offset == 0 && !vader_array_is_borrowed(_pc17_hdr) && _pc17_hdr->length >= _pc17_hdr->buf->length) ? _pc17_hdr->capacity : (size_t) 0;
    void* _pc17_slots = _pc17_hdr->buf->slots;
    for (;;) {
        if ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l4, 229u);
            l5 = ((uint8_t) t0.payload.i);
            if (l5 == INT32_C(47)) {
                l6 = true;
            } else {
                l6 = l5 == INT32_C(46);
            }
            if (l6) {
                if (VADER_LIKELY(_pc17_len < _pc17_cap)) {
                    ((uint8_t*) _pc17_slots)[_pc17_len] = (uint8_t) (INT32_C(95));
                    _pc17_len += 1;
                } else {
                    _pc17_hdr->length = _pc17_len;
                    if (_pc17_hdr->buf->length < _pc17_len) {
                        _pc17_hdr->buf->length = _pc17_len;
                    }
                    vader_array_push_u8((vader_array_t*) l2, INT32_C(95));
                    _pc17_hdr = (vader_array_t*) l2;
                    _pc17_len = _pc17_hdr->length;
                    _pc17_cap = (_pc17_hdr->offset == 0 && !vader_array_is_borrowed(_pc17_hdr) && _pc17_hdr->length >= _pc17_hdr->buf->length) ? _pc17_hdr->capacity : (size_t) 0;
                    _pc17_slots = _pc17_hdr->buf->slots;
                }
            } else if (VADER_LIKELY(_pc17_len < _pc17_cap)) {
                ((uint8_t*) _pc17_slots)[_pc17_len] = (uint8_t) ((int32_t) (uint8_t) l5);
                _pc17_len += 1;
            } else {
                _pc17_hdr->length = _pc17_len;
                if (_pc17_hdr->buf->length < _pc17_len) {
                    _pc17_hdr->buf->length = _pc17_len;
                }
                vader_array_push_u8((vader_array_t*) l2, (int32_t) (uint8_t) l5);
                _pc17_hdr = (vader_array_t*) l2;
                _pc17_len = _pc17_hdr->length;
                _pc17_cap = (_pc17_hdr->offset == 0 && !vader_array_is_borrowed(_pc17_hdr) && _pc17_hdr->length >= _pc17_hdr->buf->length) ? _pc17_hdr->capacity : (size_t) 0;
                _pc17_slots = _pc17_hdr->buf->slots;
            }
            t1 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t1;
            continue;
        }
        _pc17_hdr->length = _pc17_len;
        if (_pc17_hdr->buf->length < _pc17_len) {
            _pc17_hdr->buf->length = _pc17_len;
        }
        break;
    }
    t2 = vader_host_std_core_bytes_to_string(l2);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_mk_array(vader_box_t l0, bool l1) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_ArrayType_t* _a0_obj = (vader_struct_vader_types_ArrayType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_ArrayType_t));
    vader_obj_header_init(_a0_obj, 1008u);
    _a0_obj->f_element = l0;
    _a0_obj->f_immutable = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_mk_distinct(void* l0, vader_box_t l1) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_DistinctType_t* _a0_obj = (vader_struct_vader_types_DistinctType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_DistinctType_t));
    vader_obj_header_init(_a0_obj, 1009u);
    _a0_obj->f_symbol = l0;
    _a0_obj->f_backing = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_mk_fn(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(6u, 0u, 12u, 221u);
    l2 = (void*) _a0_arr;
    vader_struct_vader_types_FnType_t* _a1_obj = (vader_struct_vader_types_FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_FnType_t));
    vader_obj_header_init(_a1_obj, 1011u);
    _a1_obj->f_params = l0;
    _a1_obj->f_params_mutable = l2;
    _a1_obj->f_return_type = l1;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(6u, 0u, 12u, 221u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_types_FnType_t*) l0)->f_params_mutable)->length;
    if ((INT64_C(1) < l4)) {
        t0 = ((vader_array_t*) ((vader_struct_vader_types_FnType_t*) l0)->f_params_mutable)->length;
        t2 = (t0 - INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    } else {
        l4 = (size_t) 0;
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (size_t) l4);
    l3 = (void*) _a1_arr;
    l4 = (size_t) 1;
    l5 = ((vader_array_t*) ((vader_struct_vader_types_FnType_t*) l0)->f_params_mutable)->length;
    vader_array_t* _pc37_hdr = (vader_array_t*) l3;
    size_t _pc37_len = _pc37_hdr->length;
    size_t _pc37_cap = (_pc37_hdr->offset == 0 && !vader_array_is_borrowed(_pc37_hdr) && _pc37_hdr->length >= _pc37_hdr->buf->length) ? _pc37_hdr->capacity : (size_t) 0;
    void* _pc37_slots = _pc37_hdr->buf->slots;
    for (;;) {
        if ((l4 < l5)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_types_FnType_t*) l0)->f_params_mutable);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            t1 = vader_box_bool(221u, ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4]);
            l6 = t1.payload.b;
            if (VADER_LIKELY(_pc37_len < _pc37_cap)) {
                ((uint8_t*) _pc37_slots)[_pc37_len] = (uint8_t) (l6);
                _pc37_len += 1;
            } else {
                _pc37_hdr->length = _pc37_len;
                if (_pc37_hdr->buf->length < _pc37_len) {
                    _pc37_hdr->buf->length = _pc37_len;
                }
                vader_array_push_bool((vader_array_t*) l3, l6);
                _pc37_hdr = (vader_array_t*) l3;
                _pc37_len = _pc37_hdr->length;
                _pc37_cap = (_pc37_hdr->offset == 0 && !vader_array_is_borrowed(_pc37_hdr) && _pc37_hdr->length >= _pc37_hdr->buf->length) ? _pc37_hdr->capacity : (size_t) 0;
                _pc37_slots = _pc37_hdr->buf->slots;
            }
            t2 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t2;
            continue;
        }
        _pc37_hdr->length = _pc37_len;
        if (_pc37_hdr->buf->length < _pc37_len) {
            _pc37_hdr->buf->length = _pc37_len;
        }
        break;
    }
    vader_struct_vader_types_FnType_t* _a3_obj = (vader_struct_vader_types_FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_FnType_t));
    vader_obj_header_init(_a3_obj, 1011u);
    _a3_obj->f_params = l1;
    _a3_obj->f_params_mutable = l3;
    _a3_obj->f_return_type = l2;
    t3 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_obj_header_init(_a0_obj, 1011u);
    _a0_obj->f_params = l1;
    _a0_obj->f_params_mutable = l3;
    _a0_obj->f_return_type = l2;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_mk_primitive(vader_string_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_PrimitiveType_t* _a0_obj = (vader_struct_vader_types_PrimitiveType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_PrimitiveType_t));
    vader_obj_header_init(_a0_obj, 1017u);
    _a0_obj->f_name = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_mk_struct(void* l0, void* l1, bool l2) {
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_StructType_t* _a0_obj = (vader_struct_vader_types_StructType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_StructType_t));
    vader_obj_header_init(_a0_obj, 1019u);
    _a0_obj->f_symbol = l0;
    _a0_obj->f_args = l1;
    _a0_obj->f_immutable = l2;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_mk_trait(void* l0, void* l1) {
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_TraitType_t* _a0_obj = (vader_struct_vader_types_TraitType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_TraitType_t));
    vader_obj_header_init(_a0_obj, 1020u);
    _a0_obj->f_symbol = l0;
    _a0_obj->f_args = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_mk_tuple(void* l0, bool l1) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_TupleType_t* _a0_obj = (vader_struct_vader_types_TupleType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_TupleType_t));
    vader_obj_header_init(_a0_obj, 1021u);
    _a0_obj->f_elements = l0;
    _a0_obj->f_immutable = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_mk_type_param(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_TypeParamType_t* _a0_obj = (vader_struct_vader_types_TypeParamType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_TypeParamType_t));
    vader_obj_header_init(_a0_obj, 1023u);
    _a0_obj->f_symbol = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_mk_union(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_UnionType_t* _a0_obj = (vader_struct_vader_types_UnionType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_UnionType_t));
    vader_obj_header_init(_a0_obj, 1024u);
    _a0_obj->f_variants = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_primitive_meta(vader_string_t l0) {
    void* l1;
    void* l4;
    size_t l2, l3;
    vader_string_t t0;
    int64_t t1;
    l1 = (void*) &vader_data_19;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_vader_types_PrimitiveMeta_t*) l4)->f_name;
        if (t0 == l0) {
            return vader_ref_box(l4);
        }
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    return vader_box_obj(0u, NULL);
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
    l1 = (void*) &vader_data_20;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) INT32_C(0)];
        t1 = t0.payload.s;
        if (t1 == l0) {
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(1))
            t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) INT32_C(1)];
            t1 = t0.payload.s;
            return t1;
        }
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    return l0;
}

vader_box_t vader_types_scalar_backing(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 1017u) {
        t0 = l0.payload.obj;
        return vader_ref_box(t0);
    }
    if (!(l0.tag == 1009u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    t1 = vader_types_scalar_backing(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    return t1;
}

int64_t vader_types_slot_byte_align(vader_box_t l0) {
    int64_t l1;
    l1 = vader_types_slot_byte_size(l0);
    if (!((l1 > INT64_C(8)))) {
        return l1;
    }
    return INT64_C(8);
}

int64_t vader_types_slot_byte_size(vader_box_t l0) {
    int64_t l1;
    void* t0;
    vader_string_t t1;
    if (l0.tag == 1017u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        l1 = vader_types_primitive_size(t1);
        return l1;
    }
    if (l0.tag == 1010u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
        l1 = vader_types_primitive_size(t1);
    } else if (l0.tag == 1009u) {
        t0 = l0.payload.obj;
        l1 = vader_types_slot_byte_size(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else if ((l0.tag == 1008u || l0.tag == 1011u || l0.tag == 1019u || l0.tag == 1021u)) {
        l1 = INT64_C(8);
    } else if ((l0.tag == 1007u || l0.tag == 1020u || l0.tag == 1024u)) {
        l1 = INT64_C(16);
    } else {
        if (!((l0.tag == 1012u || l0.tag == 1013u || l0.tag == 1014u || l0.tag == 1015u || l0.tag == 1018u || l0.tag == 1022u || l0.tag == 1023u || l0.tag == 1025u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = INT64_C(0);
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
    if (l0.tag == 1017u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_types_contains_distinct(l0);
    if (!(t1)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1009u) {
        t0 = l0.payload.obj;
        t2 = vader_types_strip_distinct(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1019u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_StructType_t*) t0)->f_symbol;
        t0 = l0.payload.obj;
        l2 = vader_types_strip_distinct_each(((vader_struct_vader_types_StructType_t*) t0)->f_args);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_types_StructType_t*) t0)->f_immutable;
        t2 = vader_types_mk_struct(l1, l2, l3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1020u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol;
        t0 = l0.payload.obj;
        l2 = vader_types_strip_distinct_each(((vader_struct_vader_types_TraitType_t*) t0)->f_args);
        t2 = vader_types_mk_trait(l1, l2);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1008u) {
        t0 = l0.payload.obj;
        l4 = vader_types_strip_distinct(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_immutable;
        t2 = vader_types_mk_array(l4, l3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1021u) {
        t0 = l0.payload.obj;
        l1 = vader_types_strip_distinct_each(((vader_struct_vader_types_TupleType_t*) t0)->f_elements);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_types_TupleType_t*) t0)->f_immutable;
        t2 = vader_types_mk_tuple(l1, l3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1011u) {
        l1 = l0.payload.obj;
        t0 = l0.payload.obj;
        l2 = vader_types_strip_distinct_each(((vader_struct_vader_types_FnType_t*) t0)->f_params);
        t0 = l0.payload.obj;
        l4 = vader_types_strip_distinct(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
        t2 = vader_types_mk_fn_like(l1, l2, l4);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 1024u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    t3 = vader_types_strip_distinct_each(((vader_struct_vader_types_UnionType_t*) t0)->f_variants);
    t2 = vader_types_mk_union(t3);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_types_strip_distinct_each(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    size_t l2, l4;
    vader_box_t l5 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(185u, 0u, 13u, 1440u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (size_t) l2);
    l1 = (void*) _a1_arr;
    l3 = l0;
    l2 = ((vader_array_t*) l3)->length;
    l4 = (size_t) 0;
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = vader_types_strip_distinct(t0);
        vader_array_push((vader_array_t*) l1, l5);
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_struct_backing(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 1019u) {
        t0 = l0.payload.obj;
        return vader_ref_box(t0);
    }
    if (!(l0.tag == 1009u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    t1 = vader_types_struct_backing(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    return t1;
}

vader_string_t vader_types_trait_key_name(vader_string_t l0) {
    void* l1 = NULL;
    size_t l2, l3;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    uint8_t t2;
    void* t3 = NULL;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l1, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_host_std_core_bytes(l0);
    l2 = ((vader_array_t*) l1)->length;
    while ((l2 > INT64_C(0))) {
        t0 = (l2 - INT64_C(1));
        l3 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l3, 229u);
        t2 = ((uint8_t) t1.payload.i);
        if (!(t2 != INT32_C(36))) {
            break;
        }
        t0 = (l2 - INT64_C(1));
        l2 = (size_t) (int64_t) t0;
    }
    l3 = ((vader_array_t*) l1)->length;
    vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l1, (size_t) l2, (size_t) l3);
    t3 = (void*) _a1_arr;
    t4 = vader_host_std_core_bytes_to_string(t3);
    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_types_trait_key_of(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_module_name;
    l1 = vader_types_mangle_module_id(t0);
    l2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_name;
    t0 = concat_3(l1, 167u, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_tuple_backing(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 1021u) {
        t0 = l0.payload.obj;
        return vader_ref_box(t0);
    }
    if (!(l0.tag == 1009u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    t1 = vader_types_tuple_backing(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    return t1;
}

bool vader_types_type_grants_mutation(vader_box_t l0) {
    bool l1;
    void* t0;
    bool t1;
    if (l0.tag == 1008u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_immutable;
        l1 = !(t1);
        return l1;
    }
    if (l0.tag == 1019u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_StructType_t*) t0)->f_immutable;
        l1 = !(t1);
    } else if (l0.tag == 1021u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_TupleType_t*) t0)->f_immutable;
        l1 = !(t1);
    } else if (l0.tag == 1024u) {
        t0 = l0.payload.obj;
        l1 = vader_types_variants_grant_mutation(((vader_struct_vader_types_UnionType_t*) t0)->f_variants);
    } else {
        if (!((l0.tag == 1007u || l0.tag == 1009u || l0.tag == 1010u || l0.tag == 1011u || l0.tag == 1012u || l0.tag == 1013u || l0.tag == 1014u || l0.tag == 1015u || l0.tag == 1017u || l0.tag == 1018u || l0.tag == 1020u || l0.tag == 1022u || l0.tag == 1023u || l0.tag == 1025u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

bool vader_types_type_is_immutable(vader_box_t l0) {
    bool l1;
    void* t0;
    if (l0.tag == 1008u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_immutable;
        return l1;
    }
    if (l0.tag == 1019u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_StructType_t*) t0)->f_immutable;
    } else if (l0.tag == 1021u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_TupleType_t*) t0)->f_immutable;
    } else {
        if (!((l0.tag == 1007u || l0.tag == 1009u || l0.tag == 1010u || l0.tag == 1011u || l0.tag == 1012u || l0.tag == 1013u || l0.tag == 1014u || l0.tag == 1015u || l0.tag == 1017u || l0.tag == 1018u || l0.tag == 1020u || l0.tag == 1022u || l0.tag == 1023u || l0.tag == 1024u || l0.tag == 1025u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

bool vader_types_type_may_grant_mutation(vader_box_t l0) {
    bool l1;
    bool t0;
    void* t1;
    if ((l0.tag == 1008u || l0.tag == 1019u || l0.tag == 1021u)) {
        t0 = vader_types_type_is_immutable(l0);
        l1 = !(t0);
        return l1;
    }
    if (l0.tag == 1024u) {
        t1 = l0.payload.obj;
        l1 = vader_types_any_variant_may_grant_mutation(((vader_struct_vader_types_UnionType_t*) t1)->f_variants);
    } else if (l0.tag == 1009u) {
        t1 = l0.payload.obj;
        l1 = vader_types_type_may_grant_mutation(((vader_struct_vader_types_DistinctType_t*) t1)->f_backing);
    } else if ((l0.tag == 1007u || l0.tag == 1018u || l0.tag == 1020u || l0.tag == 1025u)) {
        l1 = true;
    } else {
        if (!((l0.tag == 1010u || l0.tag == 1011u || l0.tag == 1012u || l0.tag == 1013u || l0.tag == 1014u || l0.tag == 1015u || l0.tag == 1017u || l0.tag == 1022u || l0.tag == 1023u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
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
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t2 = vader_types_type_grants_mutation(t1);
        if (!(t2)) {
            return false;
        }
        t3 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t3;
    }
    return true;
}

static void vader_types_write_named_mut(void* l0, vader_string_t l1, void* l2, bool l3) {
    size_t t0;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_string_builder_append(l0, l1);
    t0 = ((vader_array_t*) l2)->length;
    if (!(t0 == INT64_C(0))) {
        std_string_builder_append_char(l0, 60u);
        vader_types_write_type_list_mut(l0, l2, 253u, l3);
        std_string_builder_append_char(l0, 62u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_types_write_type(void* l0, vader_box_t l1) {
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_types_write_type_mut(l0, l1, true);
    { vader_gc_top = gc_frame.prev; return; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = true;
    l5 = l1;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        l8 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        if (!(l4)) {
            std_string_builder_append(l0, l2);
        }
        l4 = false;
        vader_types_write_type_mut(l0, l8, l3);
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1017u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        std_string_builder_append(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1019u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_name;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
        vader_types_write_named_mut(l0, l3, l4, l2);
        if (l2) {
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_types_StructType_t*) t0)->f_immutable;
            if (!(t1)) {
                std_string_builder_append_char(l0, 33u);
            }
        }
    } else if (l1.tag == 1010u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_EnumType_t*) t0)->f_symbol)->f_name;
        std_string_builder_append(l0, l3);
    } else if (l1.tag == 1009u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_DistinctType_t*) t0)->f_symbol)->f_name;
        std_string_builder_append(l0, l3);
    } else if (l1.tag == 1020u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol)->f_name;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
        vader_types_write_named_mut(l0, l3, l4, l2);
    } else if (l1.tag == 1023u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) t0)->f_symbol)->f_name;
        std_string_builder_append(l0, l3);
    } else if (l1.tag == 1022u) {
        std_string_builder_append(l0, 2207u);
    } else if (l1.tag == 1018u) {
        std_string_builder_append(l0, 609u);
    } else if (l1.tag == 1025u) {
        std_string_builder_append(l0, 374u);
    } else if (l1.tag == 1015u) {
        std_string_builder_append(l0, 1885u);
    } else if (l1.tag == 1014u) {
        std_string_builder_append(l0, 2486u);
    } else if (l1.tag == 1013u) {
        std_string_builder_append(l0, 2485u);
    } else if (l1.tag == 1012u) {
        std_string_builder_append(l0, 2484u);
    } else if (l1.tag == 1008u) {
        t0 = l1.payload.obj;
        if (((vader_struct_vader_types_ArrayType_t*) t0)->f_element.tag == 1024u) {
            l5 = true;
        } else {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_element.tag == 1011u;
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
        std_string_builder_append(l0, 748u);
        if (l2) {
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_immutable;
            if (!(t1)) {
                std_string_builder_append_char(l0, 33u);
            }
        }
    } else if (l1.tag == 1021u) {
        std_string_builder_append_char(l0, 91u);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
        vader_types_write_type_list_mut(l0, l4, 253u, l2);
        std_string_builder_append_char(l0, 93u);
        if (l2) {
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_types_TupleType_t*) t0)->f_immutable;
            if (!(t1)) {
                std_string_builder_append_char(l0, 33u);
            }
        }
    } else if (l1.tag == 1011u) {
        std_string_builder_append(l0, 1562u);
        l5 = true;
        l7 = (size_t) 0;
        t0 = l1.payload.obj;
        l8 = ((vader_array_t*) ((vader_struct_vader_types_FnType_t*) t0)->f_params)->length;
        while ((l7 < l8)) {
            if (!(l5)) {
                std_string_builder_append(l0, 253u);
            }
            l5 = false;
            t0 = l1.payload.obj;
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_types_FnType_t*) t0)->f_params);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
            l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
            vader_types_write_type_mut(l0, l6, l2);
            t2 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t2;
        }
        std_string_builder_append(l0, 225u);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_types_FnType_t*) t0)->f_return_type;
        vader_types_write_type_mut(l0, l6, l2);
    } else if (l1.tag == 1024u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        vader_types_write_type_list_mut(l0, l4, 136u, l2);
    } else {
        if (!(l1.tag == 1007u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        std_string_builder_append(l0, 389u);
    }
    { vader_gc_top = gc_frame.prev; return; }
}
