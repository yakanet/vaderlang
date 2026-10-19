#include "bootstrap.split.h"

static bool vader_types_any_type_each(void* l0, void* l1);
static void* vader_types_integer_candidates(void* l0);
static vader_string_t vader_types_machine_integer_name(void* l0);
static vader_string_t vader_types_nominal_name(void* l0, bool l1);
static vader_string_t vader_types_open_or(bool l0, int64_t l1);
static vader_string_t vader_types_range_key(void* l0);
static void* vader_types_signed_interval(int64_t l0);
static vader_string_t vader_types_signed_machine_name(int64_t l0);
static void* vader_types_unsigned_interval(int64_t l0);
static vader_string_t vader_types_unsigned_machine_name(int64_t l0);
static void vader_types_write_named(void* l0, vader_string_t l1, void* l2, bool l3);
static void vader_types_write_range(void* l0, void* l1, bool l2);
static void vader_types_write_type(void* l0, vader_box_t l1, bool l2);
static void vader_types_write_type_list(void* l0, void* l1, vader_string_t l2, bool l3);

bool vader_types_any_type(vader_box_t l0, void* l1) {
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[2] = { &l1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
    t0 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, l0);
    t1 = t0.payload.b;
    if (t1) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l0.tag == 1256u) {
        t2 = l0.payload.obj;
        t1 = vader_types_any_type_each(((vader_struct_vader_types_StructType_t*) t2)->f_args, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1257u) {
        t2 = l0.payload.obj;
        t1 = vader_types_any_type_each(((vader_struct_vader_types_TraitType_t*) t2)->f_args, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1243u) {
        t2 = l0.payload.obj;
        t1 = vader_types_any_type(((vader_struct_vader_types_ArrayType_t*) t2)->f_element, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1258u) {
        t2 = l0.payload.obj;
        t1 = vader_types_any_type_each(((vader_struct_vader_types_TupleType_t*) t2)->f_elements, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1246u) {
        t2 = l0.payload.obj;
        t1 = vader_types_any_type_each(((vader_struct_vader_types_FnType_t*) t2)->f_params, l1);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t2 = l0.payload.obj;
        t1 = vader_types_any_type(((vader_struct_vader_types_FnType_t*) t2)->f_return_type, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1261u) {
        t2 = l0.payload.obj;
        t1 = vader_types_any_type_each(((vader_struct_vader_types_UnionType_t*) t2)->f_variants, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 1244u)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t2 = l0.payload.obj;
    t1 = vader_types_any_type(((vader_struct_vader_types_DistinctType_t*) t2)->f_backing, l1);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_types_any_type_each(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    size_t t0;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    t0 = ((vader_array_t*) l2)->length;
    l3 = (int64_t) (size_t) t0;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t2 = vader_types_any_type(t1, l1);
        if (t2) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

vader_box_t vader_types_array_backing(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 1243u) {
        t0 = l0.payload.obj;
        return vader_ref_box(t0);
    }
    if (!(l0.tag == 1244u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    t1 = vader_types_array_backing(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    return t1;
}

vader_box_t vader_types_at_own_width(vader_box_t l0) {
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
    if (l0.tag == 1254u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_RangeType_t*) t0)->f_origin;
        if (t1 != 0u) {
            t0 = l0.payload.obj;
            t2 = vader_types_without_origin(t0);
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_types_boxes_as_representation(vader_box_t l0) {
    bool l1;
    bool t0;
    if (l0.tag == 1245u) {
        l1 = true;
    } else {
        l1 = l0.tag == 1244u;
    }
    if (l1) {
        return true;
    }
    t0 = vader_types_is_refinement(l0);
    return t0;
}

vader_string_t vader_types_canonical_args_key(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    bool l2;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    vader_string_t l7 = 0;
    size_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l0)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 285u);
    t1 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 522u);
    _a1_obj->f_parts = t1;
    l1 = (void*) _a1_obj;
    l2 = true;
    l3 = l0;
    t0 = ((vader_array_t*) l3)->length;
    l4 = (int64_t) (size_t) t0;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        if (!(l2)) {
            std_string_builder_append(l1, 296u);
        }
        l2 = false;
        l7 = vader_types_canonical_key(l6);
        std_string_builder_append(l1, l7);
        l5 = (l5 + INT64_C(1));
    }
    t2 = std_string_builder_StringBuilder_std_core_Display_to_string(l1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_types_canonical_key(vader_box_t l0) {
    vader_string_t l1 = 0;
    vader_string_t l5 = 0;
    int64_t l2, l4;
    void* l3 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l3, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l5, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1253u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        t1 = concat_2(2212u, l1);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1256u) {
        t0 = l0.payload.obj;
        l1 = vader_types_canonical_args_key(((vader_struct_vader_types_StructType_t*) t0)->f_args);
        l2 = vader_host_std_core_byte_len(l1);
        l3 = std_core_new_byte_buffer((INT64_C(23) + l2));
        l2 = INT64_C(0);
        l2 = std_core_write_string_at(l3, l2, 2292u);
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_id;
        l4 = ((int64_t) (int32_t) t2);
        l2 = std_core_write_int(l3, l2, l4);
        l2 = std_core_write_string_at(l3, l2, 422u);
        l2 = std_core_write_string_at(l3, l2, l1);
        l2 = std_core_write_string_at(l3, l2, 445u);
        t1 = std_core_finish_buffer(l3, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1257u) {
        t0 = l0.payload.obj;
        l1 = vader_types_canonical_args_key(((vader_struct_vader_types_TraitType_t*) t0)->f_args);
        l2 = vader_host_std_core_byte_len(l1);
        l3 = std_core_new_byte_buffer((INT64_C(23) + l2));
        l2 = INT64_C(0);
        l2 = std_core_write_string_at(l3, l2, 2439u);
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol)->f_id;
        l4 = ((int64_t) (int32_t) t2);
        l2 = std_core_write_int(l3, l2, l4);
        l2 = std_core_write_string_at(l3, l2, 422u);
        l2 = std_core_write_string_at(l3, l2, l1);
        l2 = std_core_write_string_at(l3, l2, 445u);
        t1 = std_core_finish_buffer(l3, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1243u) {
        t0 = l0.payload.obj;
        l1 = vader_types_canonical_key(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        t1 = concat_3(1317u, l1, 263u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1258u) {
        t0 = l0.payload.obj;
        l1 = vader_types_canonical_args_key(((vader_struct_vader_types_TupleType_t*) t0)->f_elements);
        t1 = concat_3(784u, l1, 445u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1246u) {
        t0 = l0.payload.obj;
        l1 = vader_types_canonical_args_key(((vader_struct_vader_types_FnType_t*) t0)->f_params);
        t0 = l0.payload.obj;
        l5 = vader_types_canonical_key(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
        t1 = concat_4(522u, l1, 447u, l5);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1261u) {
        t0 = l0.payload.obj;
        l1 = vader_types_canonical_args_key(((vader_struct_vader_types_UnionType_t*) t0)->f_variants);
        t1 = concat_3(788u, l1, 445u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1260u) {
        l3 = std_core_new_byte_buffer(INT64_C(21));
        l2 = INT64_C(0);
        l2 = std_core_write_string_at(l3, l2, 600u);
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) t0)->f_symbol)->f_id;
        l4 = ((int64_t) (int32_t) t2);
        l2 = std_core_write_int(l3, l2, l4);
        t1 = std_core_finish_buffer(l3, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1245u) {
        l3 = std_core_new_byte_buffer(INT64_C(21));
        l2 = INT64_C(0);
        l2 = std_core_write_string_at(l3, l2, 1641u);
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_EnumType_t*) t0)->f_symbol)->f_id;
        l4 = ((int64_t) (int32_t) t2);
        l2 = std_core_write_int(l3, l2, l4);
        t1 = std_core_finish_buffer(l3, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1244u) {
        l3 = std_core_new_byte_buffer(INT64_C(21));
        l2 = INT64_C(0);
        l2 = std_core_write_string_at(l3, l2, 1597u);
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_DistinctType_t*) t0)->f_symbol)->f_id;
        l4 = ((int64_t) (int32_t) t2);
        l2 = std_core_write_int(l3, l2, l4);
        t1 = std_core_finish_buffer(l3, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1254u) {
        t0 = l0.payload.obj;
        t1 = vader_types_range_key(t0);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1259u) {
        { vader_gc_top = gc_frame.prev; return 583u; }
    }
    if (l0.tag == 1255u) {
        { vader_gc_top = gc_frame.prev; return 677u; }
    }
    if (l0.tag == 1262u) {
        { vader_gc_top = gc_frame.prev; return 449u; }
    }
    if (l0.tag == 1251u) {
        { vader_gc_top = gc_frame.prev; return 191u; }
    }
    if (l0.tag == 1249u) {
        { vader_gc_top = gc_frame.prev; return 525u; }
    }
    if (l0.tag == 1247u) {
        { vader_gc_top = gc_frame.prev; return 523u; }
    }
    if (l0.tag == 1248u) {
        { vader_gc_top = gc_frame.prev; return 524u; }
    }
    if (l0.tag == 1242u) {
        { vader_gc_top = gc_frame.prev; return 458u; }
    }
    if (!(l0.tag == 1250u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l3 = std_core_new_byte_buffer(INT64_C(21));
    l2 = INT64_C(0);
    l2 = std_core_write_string_at(l3, l2, 539u);
    t0 = l0.payload.obj;
    t2 = ((vader_struct_vader_types_InferVar_t*) t0)->f_id;
    l4 = ((int64_t) (int32_t) t2);
    l2 = std_core_write_int(l3, l2, l4);
    t1 = std_core_finish_buffer(l3, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_types_carries_own_tag(vader_box_t l0) {
    bool l1;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1256u) {
        t0 = l0.payload.obj;
        t1 = vader_types_is_untagged(vader_ref_box(t0));
        l1 = !(t1);
        { bool __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 1243u || l0.tag == 1253u)) {
        l1 = true;
    } else if (l0.tag == 1254u) {
        t0 = l0.payload.obj;
        l1 = vader_types_is_machine_range(t0);
    } else if ((l0.tag == 1242u || l0.tag == 1244u || l0.tag == 1245u || l0.tag == 1250u || l0.tag == 1260u)) {
        l1 = false;
    } else if ((l0.tag == 1246u || l0.tag == 1255u || l0.tag == 1257u || l0.tag == 1258u || l0.tag == 1259u || l0.tag == 1261u)) {
        l1 = false;
    } else {
        if (!((l0.tag == 1247u || l0.tag == 1248u || l0.tag == 1249u || l0.tag == 1251u || l0.tag == 1262u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    { bool __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_types_contains_distinct(vader_box_t l0) {
    void* l1;
    int64_t l2, l3;
    void* t0;
    size_t t1;
    vader_box_t t2;
    bool t3;
    if (l0.tag == 1244u) {
        return true;
    }
    if (l0.tag == 1256u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
        t1 = ((vader_array_t*) l1)->length;
        l2 = (int64_t) (size_t) t1;
        l3 = INT64_C(0);
        while ((l3 < l2)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            t3 = vader_types_contains_distinct(t2);
            if (t3) {
                return true;
            }
            l3 = (l3 + INT64_C(1));
        }
    }
    if (l0.tag == 1257u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
        t1 = ((vader_array_t*) l1)->length;
        l2 = (int64_t) (size_t) t1;
        l3 = INT64_C(0);
        while ((l3 < l2)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
            t3 = vader_types_contains_distinct(t2);
            if (t3) {
                return true;
            }
            l3 = (l3 + INT64_C(1));
        }
    }
    if (l0.tag == 1243u) {
        t0 = l0.payload.obj;
        t3 = vader_types_contains_distinct(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        return t3;
    }
    if (l0.tag == 1258u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
        t1 = ((vader_array_t*) l1)->length;
        l2 = (int64_t) (size_t) t1;
        l3 = INT64_C(0);
        while ((l3 < l2)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
            t3 = vader_types_contains_distinct(t2);
            if (t3) {
                return true;
            }
            l3 = (l3 + INT64_C(1));
        }
    }
    if (l0.tag == 1246u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
        t1 = ((vader_array_t*) l1)->length;
        l2 = (int64_t) (size_t) t1;
        l3 = INT64_C(0);
        while ((l3 < l2)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t2 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l3);
            t3 = vader_types_contains_distinct(t2);
            if (t3) {
                return true;
            }
            l3 = (l3 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        t3 = vader_types_contains_distinct(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
        return t3;
    }
    if (l0.tag == 1261u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        t1 = ((vader_array_t*) l1)->length;
        l2 = (int64_t) (size_t) t1;
        l3 = INT64_C(0);
        while ((l3 < l2)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l3);
            t3 = vader_types_contains_distinct(t2);
            if (t3) {
                return true;
            }
            l3 = (l3 + INT64_C(1));
        }
    }
    return false;
}

vader_box_t vader_types_core_trait_arg(vader_box_t l0, vader_string_t l1) {
    void* t0 = NULL;
    bool t1;
    size_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t3 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1257u) {
        t0 = l0.payload.obj;
        t1 = vader_types_is_core_trait(t0, l1);
        if (t1) {
            t0 = l0.payload.obj;
            t2 = ((vader_array_t*) ((vader_struct_vader_types_TraitType_t*) t0)->f_args)->length;
            if ((t2 > INT64_C(0))) {
                t0 = l0.payload.obj;
                vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_types_TraitType_t*) t0)->f_args);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
                t3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
                { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
            }
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

vader_string_t vader_types_core_trait_key(vader_string_t l0) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = concat_2(2353u, l0);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_types_declaration_key(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    int32_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_core_new_byte_buffer(INT64_C(21));
    l2 = INT64_C(0);
    l2 = std_core_write_string_at(l1, l2, 200u);
    t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core_write_int(l1, l2, l3);
    t1 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_types_display_bounds(void* l0) {
    bool l1;
    int64_t l2, l6;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    void* l5 = NULL;
    uint64_t l7;
    bool t0;
    vader_string_t t1 = 0;
    uint64_t t2;
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_integer_Interval_t*) l0)->f_lo_open;
    l2 = ((vader_struct_vader_integer_Interval_t*) l0)->f_lo;
    l3 = vader_types_open_or(l1, l2);
    t0 = ((vader_struct_vader_integer_Interval_t*) l0)->f_hi_open;
    if (!(t0)) {
        l4 = l3;
        l2 = vader_host_std_core_byte_len(l4);
        l5 = std_core_new_byte_buffer((INT64_C(23) + l2));
        l2 = INT64_C(0);
        l2 = std_core_write_string_at(l5, l2, l4);
        l2 = std_core_write_string_at(l5, l2, 333u);
        l6 = ((vader_struct_vader_integer_Interval_t*) l0)->f_hi;
        l2 = std_core_write_int(l5, l2, l6);
        t1 = std_core_finish_buffer(l5, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((vader_struct_vader_integer_Interval_t*) l0)->f_hi_past;
    if (!(t2 == INT64_C(0))) {
        l4 = l3;
        l2 = vader_host_std_core_byte_len(l4);
        l5 = std_core_new_byte_buffer((INT64_C(23) + l2));
        l2 = INT64_C(0);
        l2 = std_core_write_string_at(l5, l2, l4);
        l2 = std_core_write_string_at(l5, l2, 333u);
        l7 = vader_integer_upper_past_i64(l0);
        l2 = std_core_write_unsigned(l5, l2, l7);
        t1 = std_core_finish_buffer(l5, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = concat_2(l3, 329u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_types_display_range(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    bool l2;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_types_machine_integer_name(((vader_struct_vader_types_RangeType_t*) l0)->f_bounds);
    if (l1 != 0u) {
        t0 = ((vader_struct_vader_types_RangeType_t*) l0)->f_name;
        if (t0 == 0u) {
            l2 = true;
        } else {
            t0 = ((vader_struct_vader_types_RangeType_t*) l0)->f_name;
            l2 = t0 == l1;
        }
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = concat_3(896u, l1, 896u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_types_RangeType_t*) l0)->f_name;
    if (!(t0 == 0u)) {
        l3 = ((vader_struct_vader_types_RangeType_t*) l0)->f_name;
        l4 = vader_types_display_bounds(((vader_struct_vader_types_RangeType_t*) l0)->f_bounds);
        t0 = concat_5(896u, l3, 898u, l4, 263u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_types_display_bounds(((vader_struct_vader_types_RangeType_t*) l0)->f_bounds);
    t0 = concat_3(896u, l1, 896u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_types_display_type(vader_box_t l0) {
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
    if (l0.tag == 1253u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1254u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_RangeType_t*) t0)->f_name;
        if (t1 != 0u) {
            t0 = l0.payload.obj;
            t1 = ((vader_struct_vader_types_RangeType_t*) t0)->f_name;
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else {
        if ((l0.tag == 1244u || l0.tag == 1245u || l0.tag == 1260u)) {
            t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) VADER_UNION_FIELD(void*, vader_struct_vader_types_DistinctType_t, f_symbol, l0.payload.obj))->f_name;
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if ((l0.tag == 1256u || l0.tag == 1257u)) {
            t2 = ((vader_array_t*) VADER_UNION_FIELD(void*, vader_struct_vader_types_StructType_t, f_args, l0.payload.obj))->length;
            if (t2 == INT64_C(0)) {
                t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) VADER_UNION_FIELD(void*, vader_struct_vader_types_StructType_t, f_symbol, l0.payload.obj))->f_name;
                { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
            }
        } else {
            if (l0.tag == 1262u) {
                { vader_gc_top = gc_frame.prev; return 449u; }
            }
            if (l0.tag == 1251u) {
                { vader_gc_top = gc_frame.prev; return 2145u; }
            }
            if (l0.tag == 1249u) {
                { vader_gc_top = gc_frame.prev; return 2796u; }
            }
            if (l0.tag == 1248u) {
                { vader_gc_top = gc_frame.prev; return 2795u; }
            }
            if (l0.tag == 1247u) {
                { vader_gc_top = gc_frame.prev; return 2794u; }
            }
            if (l0.tag == 1255u) {
                { vader_gc_top = gc_frame.prev; return 678u; }
            }
            if (l0.tag == 1259u) {
                { vader_gc_top = gc_frame.prev; return 2493u; }
            }
            if (l0.tag == 1242u) {
                { vader_gc_top = gc_frame.prev; return 461u; }
            }
            if (l0.tag == 1250u) {
                t0 = l0.payload.obj;
                t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_InferVar_t*) t0)->f_origin)->f_name;
                { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 285u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 522u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    vader_types_write_type(l1, l0, false);
    t1 = std_string_builder_StringBuilder_std_core_Display_to_string(l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_types_for_each_type(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    void* t0 = NULL;
    size_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t2 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
    ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, l0);
    if (l0.tag == 1256u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
        t1 = ((vader_array_t*) l2)->length;
        l3 = (int64_t) (size_t) t1;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_types_for_each_type(t2, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 1257u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
        t1 = ((vader_array_t*) l2)->length;
        l3 = (int64_t) (size_t) t1;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            vader_types_for_each_type(t2, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 1243u) {
        t0 = l0.payload.obj;
        vader_types_for_each_type(((vader_struct_vader_types_ArrayType_t*) t0)->f_element, l1);
    } else if (l0.tag == 1258u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
        t1 = ((vader_array_t*) l2)->length;
        l3 = (int64_t) (size_t) t1;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
            t2 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
            vader_types_for_each_type(t2, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 1246u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
        t1 = ((vader_array_t*) l2)->length;
        l3 = (int64_t) (size_t) t1;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
            t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
            vader_types_for_each_type(t2, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        vader_types_for_each_type(((vader_struct_vader_types_FnType_t*) t0)->f_return_type, l1);
    } else if (l0.tag == 1261u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        t1 = ((vader_array_t*) l2)->length;
        l3 = (int64_t) (size_t) t1;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
            t2 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4);
            vader_types_for_each_type(t2, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 1244u) {
        t0 = l0.payload.obj;
        vader_types_for_each_type(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

bool vader_types_has_builtin_impl(vader_box_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    bool l3;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1245u) {
        l2 = vader_types_core_trait_key(520u);
        if (l1 == l2) {
            l3 = true;
        } else {
            l2 = vader_types_core_trait_key(537u);
            l3 = l1 == l2;
        }
        { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

vader_string_t vader_types_impl_base_key(vader_box_t l0) {
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &t1, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l0.tag == 1244u || l0.tag == 1245u || l0.tag == 1256u || l0.tag == 1257u)) {
        t0 = vader_types_declaration_key(VADER_UNION_FIELD(void*, vader_struct_vader_types_DistinctType_t, f_symbol, l0.payload.obj));
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1243u) {
        { vader_gc_top = gc_frame.prev; return 830u; }
    }
    if (l0.tag == 1254u) {
        t1 = l0.payload.obj;
        t2 = vader_types_range_representation(t1);
        t0 = ((vader_struct_vader_types_PrimitiveType_t*) t2)->f_name;
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!((l0.tag == 1246u || l0.tag == 1258u || l0.tag == 1261u))) {
        t0 = vader_types_display_type(l0);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_types_canonical_key(l0);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t vader_types_integer_bound(void* l0, bool l1) {
    int64_t t0;
    bool t1;
    uint64_t t2;
    if (!(l1)) {
        t0 = ((vader_struct_vader_integer_Interval_t*) l0)->f_lo;
        return t0;
    }
    t1 = ((vader_struct_vader_integer_Interval_t*) l0)->f_hi_open;
    if (!(t1)) {
        t0 = ((vader_struct_vader_integer_Interval_t*) l0)->f_hi;
        return t0;
    }
    t2 = vader_integer_upper_past_i64(l0);
    return ((int64_t) (uint64_t) t2);
}

static void* vader_types_integer_candidates(void* l0) {
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[2] = { &l0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_integer_Interval_t*) l0)->f_lo_open;
    if (!(t0)) {
        t1 = ((vader_struct_vader_integer_Interval_t*) l0)->f_lo;
        if ((t1 >= INT64_C(0))) {
            vader_array_t* _a0_arr = vader_array_new(14u, 4u, 0u, 285u);
            vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 3u] = vader_box_string(285u, 2538u);
            vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 2u] = vader_box_string(285u, 2528u);
            vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = vader_box_string(285u, 2527u);
            vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(285u, 2548u);
            t2 = (void*) _a0_arr;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    vader_array_t* _a1_arr = vader_array_new(14u, 4u, 0u, 285u);
    vader_array_box_slots(_a1_arr->buf)[_a1_arr->offset + 3u] = vader_box_string(285u, 1878u);
    vader_array_box_slots(_a1_arr->buf)[_a1_arr->offset + 2u] = vader_box_string(285u, 1856u);
    vader_array_box_slots(_a1_arr->buf)[_a1_arr->offset + 1u] = vader_box_string(285u, 1855u);
    vader_array_box_slots(_a1_arr->buf)[_a1_arr->offset + 0u] = vader_box_string(285u, 1900u);
    t2 = (void*) _a1_arr;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_types_is_char(vader_box_t l0) {
    void* t0;
    vader_string_t t1;
    if (l0.tag == 1253u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        return t1 == 1536u;
    }
    return false;
}

bool vader_types_is_core_struct(void* l0, vader_string_t l1) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) l0)->f_symbol)->f_module_name;
    if (t0 == 2344u) {
        t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) l0)->f_symbol)->f_name;
        return t0 == l1;
    }
    return false;
}

bool vader_types_is_core_trait(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_types_trait_key_of(((vader_struct_vader_types_TraitType_t*) l0)->f_symbol);
    l3 = vader_types_core_trait_key(l1);
    { bool __vret = l2 == l3; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_types_is_counting_type(vader_box_t l0) {
    bool l1;
    void* t0;
    vader_string_t t1;
    if (l0.tag == 1253u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        l1 = vader_types_is_int_name(t1);
        return l1;
    }
    if ((l0.tag == 1247u || l0.tag == 1249u || l0.tag == 1254u)) {
        l1 = true;
    } else if ((l0.tag == 1243u || l0.tag == 1244u || l0.tag == 1245u || l0.tag == 1248u || l0.tag == 1256u || l0.tag == 1258u)) {
        l1 = false;
    } else if ((l0.tag == 1242u || l0.tag == 1246u || l0.tag == 1250u || l0.tag == 1255u || l0.tag == 1257u || l0.tag == 1260u || l0.tag == 1261u)) {
        l1 = false;
    } else {
        if (!((l0.tag == 1251u || l0.tag == 1259u || l0.tag == 1262u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
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

bool vader_types_is_machine_range(void* l0) {
    vader_string_t t0;
    t0 = vader_types_machine_integer_name(((vader_struct_vader_types_RangeType_t*) l0)->f_bounds);
    return t0 != 0u;
}

bool vader_types_is_null_type(vader_box_t l0) {
    void* t0;
    vader_string_t t1;
    if (l0.tag == 1253u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        return t1 == 2179u;
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

bool vader_types_is_refinement(vader_box_t l0) {
    vader_box_t t0;
    t0 = vader_types_refinement_of(l0);
    return !(t0.tag == 0u);
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

bool vader_types_is_untagged(vader_box_t l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    size_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l4, &t2 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1242u) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l0.tag == 1260u) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l0.tag == 1256u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
        t1 = ((vader_array_t*) l1)->length;
        l2 = (int64_t) (size_t) t1;
        l3 = INT64_C(0);
        while ((l3 < l2)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            if (!(l4.tag == 1262u)) {
                t2 = vader_types_kept_type_argument(l4);
                if (t2.tag == 0u) {
                    { vader_gc_top = gc_frame.prev; return true; }
                }
            }
            l3 = (l3 + INT64_C(1));
        }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

vader_box_t vader_types_kept_type_argument(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    void* t2 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    void** gc_raw_roots[2] = { &t0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_types_strip_distinct(l0);
    if (l1.tag == 1253u) {
        t0 = l1.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1254u) {
        t0 = l1.payload.obj;
        t1 = vader_types_is_machine_range(t0);
        if (t1) {
            t0 = l1.payload.obj;
            t2 = vader_types_narrowest_integer(((vader_struct_vader_types_RangeType_t*) t0)->f_bounds);
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1.tag == 1245u) {
        t0 = l1.payload.obj;
        if (!(((vader_struct_vader_types_EnumType_t*) t0)->f_data.tag == 0u)) {
            t0 = l1.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

void vader_types_leaked_infer_var(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_InferVar_t*) l0)->f_origin)->f_name;
    t0 = concat_3(1346u, l1, 1054u);
    vader_host_std_abort_panic(t0);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_types_machine_integer_name(void* l0) {
    void* l1;
    bool l2;
    int64_t l3, l4;
    void* t0;
    bool t1;
    int64_t t2, t4;
    vader_string_t t3;
    t0 = (void*) &vader_data_51;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    t1 = vader_integer_same_interval(l0, l1);
    if (t1) {
        return 2538u;
    }
    t1 = ((vader_struct_vader_integer_Interval_t*) l0)->f_lo_open;
    if (t1) {
        l2 = true;
    } else {
        l2 = ((vader_struct_vader_integer_Interval_t*) l0)->f_hi_open;
    }
    if (l2) {
        return 0u;
    }
    t2 = ((vader_struct_vader_integer_Interval_t*) l0)->f_lo;
    if (t2 == INT64_C(0)) {
        t2 = ((vader_struct_vader_integer_Interval_t*) l0)->f_hi;
        t3 = vader_types_unsigned_machine_name(t2);
        return t3;
    }
    t2 = ((vader_struct_vader_integer_Interval_t*) l0)->f_hi;
    if ((t2 > INT64_C(0))) {
        l3 = ((vader_struct_vader_integer_Interval_t*) l0)->f_lo;
        t2 = ((vader_struct_vader_integer_Interval_t*) l0)->f_hi;
        t4 = vader_chk_neg(i64, t2);
        l4 = vader_chk_sub(i64, t4, INT64_C(1));
        if (l3 == l4) {
            t2 = ((vader_struct_vader_integer_Interval_t*) l0)->f_hi;
            t3 = vader_types_signed_machine_name(t2);
            return t3;
        }
        return 0u;
    }
    return 0u;
}

vader_string_t vader_types_mangle_module_id(vader_string_t l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    uint8_t l4;
    bool l5;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(17u, 0u, 1u, 291u);
    l1 = (void*) _a0_arr;
    l2 = vader_host_std_core_byte_len(l0);
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = vader_host_std_core_byte_len(l0);
    while ((l2 < l3)) {
        l4 = vader_host_std_core_byte_at(l0, l2);
        if (l4 == INT32_C(47)) {
            l5 = true;
        } else {
            l5 = l4 == INT32_C(46);
        }
        if (l5) {
            vader_array_push_u8((vader_array_t*) l1, INT32_C(95));
        } else {
            vader_array_push_u8((vader_array_t*) l1, (int32_t) (uint8_t) l4);
        }
        l2 = (l2 + INT64_C(1));
    }
    t0 = vader_host_std_core_bytes_to_string(l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_mk_array(vader_box_t l0) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_ArrayType_t* _a0_obj = (vader_struct_vader_types_ArrayType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_ArrayType_t));
    vader_obj_header_init(_a0_obj, 1243u);
    _a0_obj->f_element = l0;
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
    vader_obj_header_init(_a0_obj, 1244u);
    _a0_obj->f_symbol = l0;
    _a0_obj->f_backing = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_types_mk_fn(void* l0, vader_box_t l1, void* l2) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_FnType_t* _a0_obj = (vader_struct_vader_types_FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_FnType_t));
    vader_obj_header_init(_a0_obj, 1246u);
    _a0_obj->f_params = l0;
    _a0_obj->f_return_type = l1;
    _a0_obj->f_type_params = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_types_mk_fn_drop_self(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    int64_t l2;
    vader_box_t l3 = vader_box_null();
    size_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_types_FnType_t*) l0)->f_params;
    t0 = ((vader_array_t*) ((vader_struct_vader_types_FnType_t*) l0)->f_params)->length;
    l2 = (int64_t) (size_t) t0;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l1, (int64_t) INT64_C(1), (int64_t) l2);
    l1 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_types_FnType_t*) l0)->f_return_type;
    l4 = ((vader_struct_vader_types_FnType_t*) l0)->f_type_params;
    vader_struct_vader_types_FnType_t* _a1_obj = (vader_struct_vader_types_FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_FnType_t));
    vader_obj_header_init(_a1_obj, 1246u);
    _a1_obj->f_params = l1;
    _a1_obj->f_return_type = l3;
    _a1_obj->f_type_params = l4;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_mk_integer(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0 == 1900u) {
        t0 = (void*) &vader_data_38;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        l1 = vader_ref_box(t0);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 1855u) {
        t0 = (void*) &vader_data_37;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        l1 = vader_ref_box(t0);
    } else if (l0 == 1856u) {
        t0 = (void*) &vader_data_31;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        l1 = vader_ref_box(t0);
    } else if (l0 == 1878u) {
        t0 = (void*) &vader_data_36;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
        l1 = vader_ref_box(t0);
    } else if (l0 == 2548u) {
        t0 = (void*) &vader_data_35;
        vader_array_t* _a4_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT64_C(0));
        l1 = vader_ref_box(t0);
    } else if (l0 == 2527u) {
        t0 = (void*) &vader_data_34;
        vader_array_t* _a5_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) INT64_C(0));
        l1 = vader_ref_box(t0);
    } else if (l0 == 2528u) {
        t0 = (void*) &vader_data_33;
        vader_array_t* _a6_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        t0 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) INT64_C(0));
        l1 = vader_ref_box(t0);
    } else if (l0 == 2538u) {
        t0 = (void*) &vader_data_51;
        vader_array_t* _a7_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t0 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) INT64_C(0));
        vader_struct_vader_types_RangeType_t* _a8_obj = (vader_struct_vader_types_RangeType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_RangeType_t));
        vader_obj_header_init(_a8_obj, 1254u);
        _a8_obj->f_bounds = t0;
        _a8_obj->f_name = 2538u;
        _a8_obj->f_origin = 0u;
        t0 = (void*) _a8_obj;
        l1 = vader_ref_box(t0);
    } else {
        vader_struct_vader_types_PrimitiveType_t* _a9_obj = (vader_struct_vader_types_PrimitiveType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_PrimitiveType_t));
        vader_obj_header_init(_a9_obj, 1253u);
        _a9_obj->f_name = l0;
        t0 = (void*) _a9_obj;
        l1 = vader_ref_box(t0);
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_obj_header_init(_a0_obj, 1253u);
    _a0_obj->f_name = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_mk_struct(void* l0, void* l1) {
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_StructType_t* _a0_obj = (vader_struct_vader_types_StructType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_StructType_t));
    vader_obj_header_init(_a0_obj, 1256u);
    _a0_obj->f_symbol = l0;
    _a0_obj->f_args = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_mk_trait(void* l0, void* l1) {
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_TraitType_t* _a0_obj = (vader_struct_vader_types_TraitType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_TraitType_t));
    vader_obj_header_init(_a0_obj, 1257u);
    _a0_obj->f_symbol = l0;
    _a0_obj->f_args = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_mk_tuple(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_TupleType_t* _a0_obj = (vader_struct_vader_types_TupleType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_TupleType_t));
    vader_obj_header_init(_a0_obj, 1258u);
    _a0_obj->f_elements = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_mk_type_param(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_types_TypeParamType_t* _a0_obj = (vader_struct_vader_types_TypeParamType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_TypeParamType_t));
    vader_obj_header_init(_a0_obj, 1260u);
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
    vader_obj_header_init(_a0_obj, 1261u);
    _a0_obj->f_variants = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_narrowed_origin(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_string_t t0 = 0;
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_types_RangeType_t*) l0)->f_origin;
    if (t0 == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = ((vader_struct_vader_types_RangeType_t*) l0)->f_origin;
    l2 = vader_types_primitive_interval(t0);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l1 = l2.payload.obj;
    t1 = vader_integer_interval_within(((vader_struct_vader_types_RangeType_t*) l0)->f_bounds, l1);
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = ((vader_struct_vader_types_RangeType_t*) l0)->f_origin;
    vader_struct_vader_types_PrimitiveType_t* _a0_obj = (vader_struct_vader_types_PrimitiveType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_PrimitiveType_t));
    vader_obj_header_init(_a0_obj, 1253u);
    _a0_obj->f_name = t0;
    t2 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_types_narrowest_integer(void* l0) {
    vader_string_t l1 = 0;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    vader_box_t l7 = vader_box_null();
    void* t0 = NULL;
    size_t t1;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[2] = { &l7, &t2 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l6, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_types_machine_integer_name(l0);
    if (l1 != 0u) {
        vader_struct_vader_types_PrimitiveType_t* _a0_obj = (vader_struct_vader_types_PrimitiveType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_PrimitiveType_t));
        vader_obj_header_init(_a0_obj, 1253u);
        _a0_obj->f_name = l1;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_types_integer_candidates(l0);
    l3 = l2;
    t1 = ((vader_array_t*) l3)->length;
    l4 = (int64_t) (size_t) t1;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t2 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l5];
        l1 = t2.payload.s;
        l7 = vader_types_primitive_interval(l1);
        if (l7.tag == 0u) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l6 = l7.payload.obj;
        t3 = vader_integer_interval_within(l0, l6);
        if (t3) {
            vader_struct_vader_types_PrimitiveType_t* _a2_obj = (vader_struct_vader_types_PrimitiveType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_PrimitiveType_t));
            vader_obj_header_init(_a2_obj, 1253u);
            _a2_obj->f_name = l1;
            t0 = (void*) _a2_obj;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = (l5 + INT64_C(1));
    }
    t1 = ((vader_array_t*) l2)->length;
    l4 = vader_chk_sub(i64, t1, INT64_C(1));
    vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
    t2 = vader_array_box_slots(_a3_slotarr->buf)[_a3_slotarr->offset + (size_t) l4];
    t4 = t2.payload.s;
    vader_struct_vader_types_PrimitiveType_t* _a4_obj = (vader_struct_vader_types_PrimitiveType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_PrimitiveType_t));
    vader_obj_header_init(_a4_obj, 1253u);
    _a4_obj->f_name = t4;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_types_nominal_name(void* l0, bool l1) {
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l1)) {
        t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_name;
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_types_qualified_symbol_name(l0);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_types_open_or(bool l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0)) {
        l2 = std_core_new_byte_buffer(INT64_C(20));
        l3 = INT64_C(0);
        l3 = std_core_write_int(l2, l3, l1);
        t0 = std_core_finish_buffer(l2, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
}

vader_box_t vader_types_primitive_interval(vader_string_t l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    int64_t l3;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l1, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_types_primitive_meta(l0);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l1 = l2.payload.obj;
    t0 = ((vader_struct_vader_types_PrimitiveMeta_t*) l1)->f_is_int;
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = ((vader_struct_vader_types_PrimitiveMeta_t*) l1)->f_size;
    l3 = vader_chk_mul(i64, t1, INT64_C(8));
    t0 = ((vader_struct_vader_types_PrimitiveMeta_t*) l1)->f_is_signed;
    if (!(t0)) {
        t2 = vader_types_unsigned_interval(l3);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_types_signed_interval(l3);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_primitive_meta(vader_string_t l0) {
    void* l1;
    void* l4;
    int64_t l2, l3;
    size_t t0;
    vader_string_t t1;
    l1 = (void*) &vader_data_27;
    t0 = ((vader_array_t*) l1)->length;
    l2 = (int64_t) (size_t) t0;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = ((vader_struct_vader_types_PrimitiveMeta_t*) l4)->f_name;
        if (t1 == l0) {
            return vader_ref_box(l4);
        }
        l3 = (l3 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

vader_string_t vader_types_primitive_name(vader_box_t l0) {
    void* t0;
    vader_string_t t1;
    if (l0.tag == 1253u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        return t1;
    }
    if (!(l0.tag == 1254u)) {
        return 0u;
    }
    t0 = l0.payload.obj;
    t1 = vader_types_machine_integer_name(((vader_struct_vader_types_RangeType_t*) t0)->f_bounds);
    return t1;
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

vader_string_t vader_types_qualified_display_type(vader_box_t l0) {
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
    if (l0.tag == 1253u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1242u) {
        { vader_gc_top = gc_frame.prev; return 461u; }
    }
    if ((l0.tag == 1244u || l0.tag == 1245u)) {
        t1 = vader_types_qualified_symbol_name(VADER_UNION_FIELD(void*, vader_struct_vader_types_DistinctType_t, f_symbol, l0.payload.obj));
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1256u) {
        t0 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_args)->length;
        if (t2 == INT64_C(0)) {
            t0 = l0.payload.obj;
            t1 = vader_types_qualified_symbol_name(((vader_struct_vader_types_StructType_t*) t0)->f_symbol);
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 285u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 522u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    vader_types_write_type(l1, l0, true);
    t1 = std_string_builder_StringBuilder_std_core_Display_to_string(l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_types_qualified_symbol_name(void* l0) {
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
    t0 = concat_3(l1, 839u, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_types_range_key(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_types_machine_integer_name(((vader_struct_vader_types_RangeType_t*) l0)->f_bounds);
    if (!(l1 != 0u)) {
        l2 = vader_types_display_bounds(((vader_struct_vader_types_RangeType_t*) l0)->f_bounds);
        t0 = concat_2(2244u, l2);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = concat_2(2212u, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_types_range_representation(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_types_narrowed_origin(l0);
    if (l1.tag == 0u) {
        t0 = vader_types_narrowest_integer(((vader_struct_vader_types_RangeType_t*) l0)->f_bounds);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_refinement_of(vader_box_t l0) {
    void* t0;
    bool t1;
    if (l0.tag == 1254u) {
        t0 = l0.payload.obj;
        t1 = vader_types_is_machine_range(t0);
        if (!(t1)) {
            t0 = l0.payload.obj;
            return vader_ref_box(t0);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

vader_string_t vader_types_resolve_primitive_alias(vader_string_t l0) {
    void* l1;
    void* l4;
    int64_t l2, l3;
    size_t t0;
    vader_box_t t1;
    vader_string_t t2;
    l1 = (void*) &vader_data_28;
    t0 = ((vader_array_t*) l1)->length;
    l2 = (int64_t) (size_t) t0;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
        t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) INT32_C(0)];
        t2 = t1.payload.s;
        if (t2 == l0) {
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(1))
            t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) INT32_C(1)];
            t2 = t1.payload.s;
            return t2;
        }
        l3 = (l3 + INT64_C(1));
    }
    return l0;
}

vader_box_t vader_types_scalar_backing(vader_box_t l0) {
    void* t0 = NULL;
    void* t2 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    void** gc_raw_roots[2] = { &t0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1253u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1244u) {
        t0 = l0.payload.obj;
        t1 = vader_types_scalar_backing(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 1254u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l0.payload.obj;
    t2 = vader_types_range_representation(t0);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_types_signed_interval(int64_t l0) {
    int64_t l1, l2;
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0 == INT64_C(64))) {
        l1 = vader_chk_sub(i64, l0, INT64_C(1));
        l1 = (INT64_C(1) << l1);
        l2 = vader_chk_neg(i64, l1);
        l1 = vader_chk_sub(i64, l1, INT64_C(1));
        t0 = vader_integer_interval(l2, l1);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_integer_interval(INT64_MIN, INT64_C(9223372036854775807));
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_types_signed_machine_name(int64_t l0) {
    vader_string_t l1;
    if (l0 == INT64_C(127)) {
        l1 = 1900u;
        return l1;
    }
    if (l0 == INT64_C(32767)) {
        l1 = 1855u;
    } else if (l0 == INT64_C(2147483647)) {
        l1 = 1856u;
    } else if (l0 == INT64_C(9223372036854775807)) {
        l1 = 1878u;
    } else {
        l1 = 0u;
    }
    return l1;
}

int64_t vader_types_slot_byte_align(vader_box_t l0) {
    int64_t l1;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_types_slot_byte_size(l0);
    if (!((l1 > INT64_C(8)))) {
        { int64_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return INT64_C(8); }
}

int64_t vader_types_slot_byte_size(vader_box_t l0) {
    int64_t l1;
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
    if (l0.tag == 1253u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        l1 = vader_types_primitive_size(t1);
        { int64_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1245u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_EnumType_t*) t0)->f_repr;
        l1 = vader_types_primitive_size(t1);
    } else if (l0.tag == 1244u) {
        t0 = l0.payload.obj;
        l1 = vader_types_slot_byte_size(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 1254u) {
        t0 = l0.payload.obj;
        t2 = vader_types_range_representation(t0);
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t2)->f_name;
        l1 = vader_types_primitive_size(t1);
    } else if ((l0.tag == 1243u || l0.tag == 1246u || l0.tag == 1256u || l0.tag == 1258u)) {
        l1 = INT64_C(8);
    } else if ((l0.tag == 1242u || l0.tag == 1257u || l0.tag == 1261u)) {
        l1 = INT64_C(16);
    } else {
        if (!((l0.tag == 1247u || l0.tag == 1248u || l0.tag == 1249u || l0.tag == 1250u || l0.tag == 1251u || l0.tag == 1255u || l0.tag == 1259u || l0.tag == 1260u || l0.tag == 1262u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = INT64_C(0);
    }
    { int64_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_strip_distinct(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    void* t4 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null(), t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l3, &t2, &t3 };
    void** gc_raw_roots[4] = { &l1, &l2, &t0, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1253u) {
        t0 = l0.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_types_contains_distinct(l0);
    if (!(t1)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1244u) {
        t0 = l0.payload.obj;
        t2 = vader_types_strip_distinct(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1256u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_StructType_t*) t0)->f_symbol;
        t0 = l0.payload.obj;
        l2 = vader_types_strip_distinct_each(((vader_struct_vader_types_StructType_t*) t0)->f_args);
        t2 = vader_types_mk_struct(l1, l2);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1257u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol;
        t0 = l0.payload.obj;
        l2 = vader_types_strip_distinct_each(((vader_struct_vader_types_TraitType_t*) t0)->f_args);
        vader_struct_vader_types_TraitType_t* _a0_obj = (vader_struct_vader_types_TraitType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_TraitType_t));
        vader_obj_header_init(_a0_obj, 1257u);
        _a0_obj->f_symbol = l1;
        _a0_obj->f_args = l2;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1243u) {
        t0 = l0.payload.obj;
        t2 = vader_types_strip_distinct(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        t3 = vader_types_mk_array(t2);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1258u) {
        t0 = l0.payload.obj;
        t4 = vader_types_strip_distinct_each(((vader_struct_vader_types_TupleType_t*) t0)->f_elements);
        t2 = vader_types_mk_tuple(t4);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1246u) {
        t0 = l0.payload.obj;
        l1 = vader_types_strip_distinct_each(((vader_struct_vader_types_FnType_t*) t0)->f_params);
        t0 = l0.payload.obj;
        l3 = vader_types_strip_distinct(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
        vader_array_t* _a1_arr = vader_array_new(197u, 0u, 13u, 1260u);
        l2 = (void*) _a1_arr;
        t0 = vader_types_mk_fn(l1, l3, l2);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 1261u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    t4 = vader_types_strip_distinct_each(((vader_struct_vader_types_UnionType_t*) t0)->f_variants);
    t2 = vader_types_mk_union(t4);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_types_strip_distinct_each(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    int64_t l2, l4;
    vader_box_t l5 = vader_box_null();
    size_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(243u, 0u, 13u, 1787u);
    l1 = (void*) _a0_arr;
    t0 = ((vader_array_t*) l0)->length;
    l2 = (int64_t) (size_t) t0;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l3 = l0;
    t0 = ((vader_array_t*) l3)->length;
    l2 = (int64_t) (size_t) t0;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = vader_types_strip_distinct(t1);
        vader_array_push((vader_array_t*) l1, l5);
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_struct_backing(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 1256u) {
        t0 = l0.payload.obj;
        return vader_ref_box(t0);
    }
    if (!(l0.tag == 1244u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    t1 = vader_types_struct_backing(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    return t1;
}

vader_string_t vader_types_trait_key_name(vader_string_t l0) {
    int64_t l1, l2;
    uint8_t t0;
    vader_string_t t1;
    l1 = vader_host_std_core_byte_len(l0);
    while ((l1 > INT64_C(0))) {
        l2 = vader_chk_sub(i64, l1, INT64_C(1));
        t0 = vader_host_std_core_byte_at(l0, l2);
        if (!(t0 != INT32_C(36))) {
            break;
        }
        l1 = vader_chk_sub(i64, l1, INT64_C(1));
    }
    l2 = vader_host_std_core_byte_len(l0);
    t1 = vader_host_std_core_byte_slice(l0, l1, l2);
    return t1;
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
    t0 = concat_3(l1, 205u, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_types_tuple_backing(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 1258u) {
        t0 = l0.payload.obj;
        return vader_ref_box(t0);
    }
    if (!(l0.tag == 1244u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    t1 = vader_types_tuple_backing(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    return t1;
}

static void* vader_types_unsigned_interval(int64_t l0) {
    int64_t l1;
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0 == INT64_C(64))) {
        l1 = vader_chk_sub(i64, (INT64_C(1) << l0), INT64_C(1));
        t0 = vader_integer_interval(INT64_C(0), l1);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = (void*) &vader_data_51;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_types_unsigned_machine_name(int64_t l0) {
    vader_string_t l1;
    if (l0 == INT64_C(255)) {
        l1 = 2548u;
        return l1;
    }
    if (l0 == INT64_C(65535)) {
        l1 = 2527u;
    } else if (l0 == INT64_C(4294967295)) {
        l1 = 2528u;
    } else {
        l1 = 0u;
    }
    return l1;
}

void* vader_types_without_origin(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    vader_string_t l3 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = l0;
    l2 = ((vader_struct_vader_types_RangeType_t*) l1)->f_bounds;
    l3 = ((vader_struct_vader_types_RangeType_t*) l1)->f_name;
    vader_struct_vader_types_RangeType_t* _a0_obj = (vader_struct_vader_types_RangeType_t*) vader_gc_alloc(sizeof(vader_struct_vader_types_RangeType_t));
    vader_obj_header_init(_a0_obj, 1254u);
    _a0_obj->f_bounds = l2;
    _a0_obj->f_name = l3;
    _a0_obj->f_origin = 0u;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_types_write_named(void* l0, vader_string_t l1, void* l2, bool l3) {
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
        vader_types_write_type_list(l0, l2, 298u, l3);
        std_string_builder_append_char(l0, 62u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_types_write_range(void* l0, void* l1, bool l2) {
    vader_string_t l3 = 0;
    vader_string_t l5 = 0;
    bool l4;
    vader_string_t t0 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_types_machine_integer_name(((vader_struct_vader_types_RangeType_t*) l1)->f_bounds);
    if (l3 != 0u) {
        if (l2) {
            l4 = true;
        } else {
            t0 = ((vader_struct_vader_types_RangeType_t*) l1)->f_name;
            l4 = t0 == 0u;
        }
    } else {
        l4 = false;
    }
    if (l4) {
        std_string_builder_append(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2) {
        l3 = vader_types_display_bounds(((vader_struct_vader_types_RangeType_t*) l1)->f_bounds);
        l3 = concat_2(563u, l3);
        std_string_builder_append(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = ((vader_struct_vader_types_RangeType_t*) l1)->f_name;
    if (!(t0 != 0u)) {
        l5 = vader_types_display_bounds(((vader_struct_vader_types_RangeType_t*) l1)->f_bounds);
        std_string_builder_append(l0, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_types_RangeType_t*) l1)->f_name;
    std_string_builder_append(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_types_write_type(void* l0, vader_box_t l1, bool l2) {
    vader_string_t l3 = 0;
    void* l4 = NULL;
    bool l5;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l6 };
    void** gc_raw_roots[3] = { &l0, &l4, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1253u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        std_string_builder_append(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1256u) {
        t0 = l1.payload.obj;
        l3 = vader_types_nominal_name(((vader_struct_vader_types_StructType_t*) t0)->f_symbol, l2);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
        vader_types_write_named(l0, l3, l4, l2);
    } else if (l1.tag == 1245u) {
        t0 = l1.payload.obj;
        l3 = vader_types_nominal_name(((vader_struct_vader_types_EnumType_t*) t0)->f_symbol, l2);
        std_string_builder_append(l0, l3);
    } else if (l1.tag == 1244u) {
        t0 = l1.payload.obj;
        l3 = vader_types_nominal_name(((vader_struct_vader_types_DistinctType_t*) t0)->f_symbol, l2);
        std_string_builder_append(l0, l3);
    } else if (l1.tag == 1254u) {
        l4 = l1.payload.obj;
        vader_types_write_range(l0, l4, l2);
    } else if (l1.tag == 1257u) {
        t0 = l1.payload.obj;
        l3 = vader_types_nominal_name(((vader_struct_vader_types_TraitType_t*) t0)->f_symbol, l2);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
        vader_types_write_named(l0, l3, l4, l2);
    } else if (l1.tag == 1260u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) t0)->f_symbol)->f_name;
        std_string_builder_append(l0, l3);
    } else if (l1.tag == 1259u) {
        std_string_builder_append(l0, 2493u);
    } else if (l1.tag == 1255u) {
        std_string_builder_append(l0, 678u);
    } else if (l1.tag == 1262u) {
        std_string_builder_append(l0, 449u);
    } else if (l1.tag == 1251u) {
        std_string_builder_append(l0, 2145u);
    } else if (l1.tag == 1249u) {
        std_string_builder_append(l0, 2796u);
    } else if (l1.tag == 1248u) {
        std_string_builder_append(l0, 2795u);
    } else if (l1.tag == 1247u) {
        std_string_builder_append(l0, 2794u);
    } else if (l1.tag == 1243u) {
        t0 = l1.payload.obj;
        if (((vader_struct_vader_types_ArrayType_t*) t0)->f_element.tag == 1261u) {
            l5 = true;
        } else {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_element.tag == 1246u;
        }
        if (l5) {
            std_string_builder_append_char(l0, 40u);
        }
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_element;
        vader_types_write_type(l0, l6, l2);
        if (l5) {
            std_string_builder_append_char(l0, 41u);
        }
        std_string_builder_append(l0, 830u);
    } else if (l1.tag == 1258u) {
        std_string_builder_append_char(l0, 91u);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
        vader_types_write_type_list(l0, l4, 298u, l2);
        std_string_builder_append_char(l0, 93u);
    } else if (l1.tag == 1246u) {
        std_string_builder_append(l0, 1788u);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
        vader_types_write_type_list(l0, l4, 298u, l2);
        std_string_builder_append(l0, 266u);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_types_FnType_t*) t0)->f_return_type;
        vader_types_write_type(l0, l6, l2);
    } else if (l1.tag == 1261u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
        vader_types_write_type_list(l0, l4, 175u, l2);
    } else if (l1.tag == 1242u) {
        std_string_builder_append(l0, 461u);
    } else {
        if (!(l1.tag == 1250u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_InferVar_t*) t0)->f_origin)->f_name;
        std_string_builder_append(l0, l3);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_types_write_type_list(void* l0, void* l1, vader_string_t l2, bool l3) {
    bool l4;
    void* l5 = NULL;
    int64_t l6, l7;
    vader_box_t l8 = vader_box_null();
    size_t t0;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = true;
    l5 = l1;
    t0 = ((vader_array_t*) l5)->length;
    l6 = (int64_t) (size_t) t0;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l8 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        if (!(l4)) {
            std_string_builder_append(l0, l2);
        }
        l4 = false;
        vader_types_write_type(l0, l8, l3);
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}
