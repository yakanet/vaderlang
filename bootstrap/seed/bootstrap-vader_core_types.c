#include "bootstrap.split.h"

static bool vader_core_types$absorbed(vader_box_t l0, void* l1, void* l2);
static bool vader_core_types$any_contains_range(void* l0, bool l1);
static bool vader_core_types$any_holds_infer_var(void* l0, int32_t l1);
static bool vader_core_types$any_holds_refinement_union(void* l0);
static bool vader_core_types$any_type_each(void* l0, void* l1);
static void vader_core_types$bind_infer_var(void* l0, vader_box_t l1, void* l2, vader_box_t l3);
static vader_box_t vader_core_types$binding_of(void* l0, vader_box_t l1);
static bool vader_core_types$binds_any(void* l0, void* l1);
static bool vader_core_types$check_common(vader_box_t l0, vader_box_t l1);
static void vader_core_types$collect_variant(vader_box_t l0, void* l1);
static void* vader_core_types$erase_each(void* l0);
static vader_box_t vader_core_types$erase_params_in(vader_box_t l0);
static vader_box_t vader_core_types$erase_ranges(vader_box_t l0);
static void* vader_core_types$erase_ranges_each(void* l0);
static vader_box_t vader_core_types$erase_union(void* l0);
static int32_t vader_core_types$find_unused_equal(void* l0, void* l1, vader_box_t l2);
static bool vader_core_types$fits_tuple_field(vader_box_t l0, vader_box_t l1);
static bool vader_core_types$fn_param_compatible(vader_box_t l0, vader_box_t l1);
static bool vader_core_types$fn_signature_compatible(vader_box_t l0, vader_box_t l1);
static bool vader_core_types$held_by_another(void* l0, vader_box_t l1);
static bool vader_core_types$holds_infer_var(vader_box_t l0, int32_t l1);
static bool vader_core_types$holds_refinement_union(vader_box_t l0);
static vader_box_t vader_core_types$interval_hull(void* l0);
static bool vader_core_types$is_assignable_array(vader_box_t l0, void* l1, vader_box_t l2);
static bool vader_core_types$is_assignable_fn(vader_box_t l0, void* l1, vader_box_t l2);
static bool vader_core_types$is_assignable_free_literal(vader_box_t l0, vader_box_t l1);
static bool vader_core_types$is_assignable_struct(vader_box_t l0, void* l1, vader_box_t l2);
static bool vader_core_types$is_assignable_trait_from(vader_box_t l0, void* l1, vader_box_t l2);
static bool vader_core_types$is_assignable_tuple(vader_box_t l0, void* l1, vader_box_t l2);
static bool vader_core_types$is_assignable_union(vader_box_t l0, void* l1, vader_box_t l2);
static bool vader_core_types$is_reference_name(vader_string_t l0);
static void* vader_core_types$joined_ranges(vader_box_t l0, void* l1);
static void* vader_core_types$laid_out_unions_each(void* l0);
static bool vader_core_types$literal_takes(vader_box_t l0, vader_box_t l1);
static bool vader_core_types$nominal_eq(int32_t l0, void* l1, int32_t l2, void* l3);
static vader_string_t vader_core_types$nominal_name(void* l0, bool l1);
static vader_string_t vader_core_types$open_or(bool l0, int64_t l1);
static vader_box_t vader_core_types$primitive_meta(vader_string_t l0);
static vader_string_t vader_core_types$range_key(void* l0);
static bool vader_core_types$removed_covers(vader_box_t l0, vader_box_t l1);
static bool vader_core_types$same_variant(vader_box_t l0, vader_box_t l1);
static void* vader_core_types$sort_by_display_key(void* l0);
static void* vader_core_types$substitute_each_in(void* l0, vader_box_t l1, vader_box_t l2);
static void* vader_core_types$substitute_fn_in(void* l0, vader_box_t l1, vader_box_t l2);
static vader_box_t vader_core_types$substitute_in(vader_box_t l0, vader_box_t l1, vader_box_t l2);
static void* vader_core_types$unbound_quantifier(void* l0, vader_box_t l1);
static void vader_core_types$unify_args(void* l0, void* l1, void* l2);
static bool vader_core_types$variant_keeps_tag(vader_box_t l0, void* l1);
static void vader_core_types$write_named(void* l0, void* l1, void* l2);
static void vader_core_types$write_nominal(void* l0, void* l1);
static void vader_core_types$write_range(void* l0, void* l1, bool l2);
static void vader_core_types$write_type(void* l0, vader_box_t l1);
static void vader_core_types$write_type_list(void* l0, void* l1, vader_string_t l2);
static void* vader_core_types$zonk_each(void* l0, void* l1);
static vader_box_t vader_core_types$zonk_in(vader_box_t l0, void* l1);
static vader_box_t vader_core_types$zonk_var(void* l0, void* l1);

static bool vader_core_types$absorbed(vader_box_t l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l4, l5, l10, l11;
    vader_box_t l6 = vader_box_null(), l12 = vader_box_null();
    bool l9;
    vader_string_t t0 = 0;
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &l6, &l12 };
    void** gc_raw_roots[6] = { &l1, &l2, &l3, &l7, &l8, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$primitive_name(l0);
    if (t0 == 0u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t1 = vader_core_types$held_by_another(l1, l0);
    if (t1) {
        l3 = l2;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            if (l6.tag == 926u) {
                t2 = l6.payload.obj;
                l7 = ((vader_struct_vader_core_types$UnionType_t*) t2)->f_variants;
                vader_struct___lambda_env_vader_core_types_5_t* _a1_obj = (vader_struct___lambda_env_vader_core_types_5_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_core_types_5_t));
                vader_obj_header_init(_a1_obj, 360u);
                _a1_obj->f_cap_0 = l0;
                l8 = (void*) _a1_obj;
                l9 = false;
                l10 = ((vader_array_t*) l7)->length;
                l11 = INT64_C(0);
                {
                    while ((l11 < l10)) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
                        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                        l12 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
                        t1 = __lambda_vader_core_types_4(l8, l12);
                        if (t1) {
                            l9 = true;
                            goto end_42;
                        }
                        l11 = (l11 + INT64_C(1));
                    }
                    l9 = false;
                } end_42: ;
                if (l9) {
                    { vader_gc_top = gc_frame.prev; return false; }
                }
            }
            l5 = (l5 + INT64_C(1));
        }
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

bool vader_core_types$adopts_any_layout(vader_box_t l0) {
    bool l1;
    bool t0;
    if (l0.tag == 927u) {
        l1 = true;
    } else {
        l1 = l0.tag == 913u;
    }
    if (l1) {
        return true;
    }
    t0 = vader_core_types$is_free_numeric(l0);
    return t0;
}

static bool vader_core_types$any_contains_range(void* l0, bool l1) {
    void* l2;
    int64_t l3, l4;
    vader_box_t t0;
    bool t1;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = vader_core_types$contains_range(t0, l1);
        if (t1) {
            return true;
        }
        l4 = (l4 + INT64_C(1));
    }
    return false;
}

bool vader_core_types$any_contains_type_param(void* l0) {
    void* l1;
    int64_t l2, l3;
    vader_box_t t0;
    bool t1;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = vader_core_types$type_contains_type_param(t0);
        if (t1) {
            return true;
        }
        l3 = (l3 + INT64_C(1));
    }
    return false;
}

static bool vader_core_types$any_holds_infer_var(void* l0, int32_t l1) {
    void* l2;
    int64_t l3, l4;
    vader_box_t t0;
    bool t1;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = vader_core_types$holds_infer_var(t0, l1);
        if (t1) {
            return true;
        }
        l4 = (l4 + INT64_C(1));
    }
    return false;
}

static bool vader_core_types$any_holds_refinement_union(void* l0) {
    void* l1;
    int64_t l2, l3;
    vader_box_t t0;
    bool t1;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = vader_core_types$holds_refinement_union(t0);
        if (t1) {
            return true;
        }
        l3 = (l3 + INT64_C(1));
    }
    return false;
}

bool vader_core_types$any_type(vader_box_t l0, void* l1) {
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
    if (l0.tag == 918u) {
        t2 = l0.payload.obj;
        t1 = vader_core_types$any_type_each(((vader_struct_vader_core_types$StructType_t*) t2)->f_args, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 920u) {
        t2 = l0.payload.obj;
        t1 = vader_core_types$any_type_each(((vader_struct_vader_core_types$TraitType_t*) t2)->f_args, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 904u) {
        t2 = l0.payload.obj;
        t1 = vader_core_types$any_type(((vader_struct_vader_core_types$ArrayType_t*) t2)->f_element, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 921u) {
        t2 = l0.payload.obj;
        t1 = vader_core_types$any_type_each(((vader_struct_vader_core_types$TupleType_t*) t2)->f_elements, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 907u) {
        t2 = l0.payload.obj;
        t1 = vader_core_types$any_type_each(((vader_struct_vader_core_types$FnType_t*) t2)->f_params, l1);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        t2 = l0.payload.obj;
        t1 = vader_core_types$any_type(((vader_struct_vader_core_types$FnType_t*) t2)->f_return_type, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 926u) {
        t2 = l0.payload.obj;
        t1 = vader_core_types$any_type_each(((vader_struct_vader_core_types$UnionType_t*) t2)->f_variants, l1);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 905u)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t2 = l0.payload.obj;
    t1 = vader_core_types$any_type(((vader_struct_vader_core_types$DistinctType_t*) t2)->f_backing, l1);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_core_types$any_type_each(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = vader_core_types$any_type(t0, l1);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

vader_box_t vader_core_types$array_backing(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 904u) {
        t0 = l0.payload.obj;
        return vader_ref_box(t0);
    }
    if (!(l0.tag == 905u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    t1 = vader_core_types$array_backing(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
    return t1;
}

vader_box_t vader_core_types$async_inner_type(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_core_types$core_trait_arg(l0, 584u);
    if (l1.tag == 0u) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$async_result_arg(vader_box_t l0) {
    bool t0;
    void* t1;
    t0 = vader_core_types$is_void(l0);
    if (t0) {
        t1 = (void*) &vader_data_17;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t1);
    }
    return l0;
}

static void vader_core_types$bind_infer_var(void* l0, vader_box_t l1, void* l2, vader_box_t l3) {
    int32_t l4, l6;
    void* l5 = NULL;
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l3, &t1 };
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$type_contains_unresolved(l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = ((vader_struct_vader_core_types$InferVar_t*) l0)->f_id;
    t0 = vader_core_types$mentions_infer_var(l1, l4);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = ((vader_struct_vader_core_types$InferVar_t*) l0)->f_id;
    t1 = std_collections$get_or_put__i32__vader_core_types_AnyType___vader_core_types_ArrayType___vader_core_types_DistinctType___vader_core_types_EnumType___vader_core_types_FnType___vader_core_types_FreeCharType___vader_core_types_FreeFloatType___vader_core_types_FreeIntType___vader_core_types_InferVar___vader_core_types_NeverType___vader_core_types_PrimitiveType___vader_core_types_RangeType___vader_core_types_SelfType___vader_core_types_StructType___vader_core_types_TraitType___vader_core_types_TupleType___vader_core_types_TypeMetaType___vader_core_types_TypeParamType___vader_core_types_UnionType___vader_core_types_UnresolvedType(l2, l4, l1);
    t0 = vader_core_types$is_free_numeric(t1);
    if (t0) {
        t0 = vader_core_types$is_free_numeric(l1);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l3.tag == 0u) {
            l6 = ((vader_struct_vader_core_types$InferVar_t*) l0)->f_id;
            std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l2, l6, l1);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l5 = l3.payload.obj;
        l4 = ((vader_struct_vader_core_types$InferVar_t*) l0)->f_id;
        t0 = std_collections$MutableSet$std_core$Contains$contains__i32(l5, l4);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l6 = ((vader_struct_vader_core_types$InferVar_t*) l0)->f_id;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l2, l6, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_core_types$binding_of(void* l0, vader_box_t l1) {
    void* l2;
    int32_t l3;
    vader_box_t l4;
    if (l1.tag == 0u) {
        return vader_ref_box(l0);
    }
    l2 = l1.payload.obj;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) l0)->f_symbol)->f_id;
    l4 = std_collections$MutableMap$std_core$Index$at__i32__Any(l2, l3);
    if (l4.tag == 0u) {
        return vader_ref_box(l0);
    }
    return l4;
}

static bool vader_core_types$binds_any(void* l0, void* l1) {
    void* l2;
    int64_t l3, l4;
    int32_t l5;
    void* t0;
    bool t1;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) t0)->f_symbol)->f_id;
        t1 = std_collections$MutableMap$std_core$Contains$contains__i32__Any(l1, l5);
        if (t1) {
            return true;
        }
        l4 = (l4 + INT64_C(1));
    }
    return false;
}

vader_box_t vader_core_types$bound_range(void* l0, vader_box_t l1) {
    void* l2;
    int32_t l3;
    void* t0;
    vader_box_t t1, t2;
    if (!(l1.tag == 923u)) {
        return vader_box_obj(0u, NULL);
    }
    l2 = ((vader_struct_vader_core_types$Substitution_t*) l0)->f_type_params;
    t0 = l1.payload.obj;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) t0)->f_symbol)->f_id;
    t1 = std_collections$MutableMap$std_core$Index$at__i32__Any(l2, l3);
    t2 = vader_core_types$refinement_of(t1);
    return t2;
}

bool vader_core_types$boxes_as_representation(vader_box_t l0) {
    bool l1;
    bool t0;
    if (l0.tag == 906u) {
        l1 = true;
    } else {
        l1 = l0.tag == 905u;
    }
    if (l1) {
        return true;
    }
    t0 = vader_core_types$is_refinement(l0);
    return t0;
}

vader_string_t vader_core_types$canonical_args_key(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    bool l2;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    vader_string_t l7 = 0;
    int64_t t0;
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
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    t1 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 626u);
    _a1_obj->f_parts = t1;
    l1 = (void*) _a1_obj;
    l2 = true;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        if (!(l2)) {
            std_string__builder$append(l1, 360u);
        }
        l2 = false;
        l7 = vader_core_types$canonical_key(l6);
        std_string__builder$append(l1, l7);
        l5 = (l5 + INT64_C(1));
    }
    t2 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_types$canonical_key(vader_box_t l0) {
    vader_string_t l1 = 0;
    vader_string_t l6 = 0;
    int32_t l2;
    int64_t l3, l5;
    void* l4 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l4, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l6, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 915u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        t1 = concat_2(2442u, l1);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_id;
        t0 = l0.payload.obj;
        l1 = vader_core_types$canonical_args_key(((vader_struct_vader_core_types$StructType_t*) t0)->f_args);
        l3 = vader_host_std_core$byte_len(l1);
        l4 = (void*) vader_buffer_new((size_t) (INT64_C(23) + l3));
        l3 = INT64_C(0);
        l3 = std_core$write_string_at(l4, l3, 2530u);
        l5 = ((int64_t) (int32_t) l2);
        l3 = std_core$write_int(l4, l3, l5);
        l3 = std_core$write_string_at(l4, l3, 504u);
        l3 = std_core$write_string_at(l4, l3, l1);
        l3 = std_core$write_string_at(l4, l3, 525u);
        t1 = std_core$finish_buffer(l4, l3);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 920u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TraitType_t*) t0)->f_symbol)->f_id;
        t0 = l0.payload.obj;
        l1 = vader_core_types$canonical_args_key(((vader_struct_vader_core_types$TraitType_t*) t0)->f_args);
        l3 = vader_host_std_core$byte_len(l1);
        l4 = (void*) vader_buffer_new((size_t) (INT64_C(23) + l3));
        l3 = INT64_C(0);
        l3 = std_core$write_string_at(l4, l3, 2685u);
        l5 = ((int64_t) (int32_t) l2);
        l3 = std_core$write_int(l4, l3, l5);
        l3 = std_core$write_string_at(l4, l3, 504u);
        l3 = std_core$write_string_at(l4, l3, l1);
        l3 = std_core$write_string_at(l4, l3, 525u);
        t1 = std_core$finish_buffer(l4, l3);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 904u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$canonical_key(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element);
        t1 = concat_3(1499u, l1, 323u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 921u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$canonical_args_key(((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements);
        t1 = concat_3(906u, l1, 525u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 907u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$canonical_args_key(((vader_struct_vader_core_types$FnType_t*) t0)->f_params);
        t0 = l0.payload.obj;
        l6 = vader_core_types$canonical_key(((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type);
        t1 = concat_4(640u, l1, 527u, l6);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$canonical_args_key(((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants);
        t1 = concat_3(920u, l1, 525u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 923u) {
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l3 = INT64_C(0);
        l3 = std_core$write_string_at(l4, l3, 729u);
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) t0)->f_symbol)->f_id;
        l5 = ((int64_t) (int32_t) t2);
        l3 = std_core$write_int(l4, l3, l5);
        t1 = std_core$finish_buffer(l4, l3);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 906u) {
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l3 = INT64_C(0);
        l3 = std_core$write_string_at(l4, l3, 1849u);
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$EnumType_t*) t0)->f_symbol)->f_id;
        l5 = ((int64_t) (int32_t) t2);
        l3 = std_core$write_int(l4, l3, l5);
        t1 = std_core$finish_buffer(l4, l3);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 905u) {
        l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l3 = INT64_C(0);
        l3 = std_core$write_string_at(l4, l3, 1808u);
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$DistinctType_t*) t0)->f_symbol)->f_id;
        l5 = ((int64_t) (int32_t) t2);
        l3 = std_core$write_int(l4, l3, l5);
        t1 = std_core$finish_buffer(l4, l3);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$range_key(t0);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 922u) {
        { vader_gc_top = gc_frame.prev; return 705u; }
    }
    if (l0.tag == 917u) {
        { vader_gc_top = gc_frame.prev; return 794u; }
    }
    if (l0.tag == 927u) {
        { vader_gc_top = gc_frame.prev; return 529u; }
    }
    if (l0.tag == 913u) {
        { vader_gc_top = gc_frame.prev; return 245u; }
    }
    if (l0.tag == 910u) {
        { vader_gc_top = gc_frame.prev; return 643u; }
    }
    if (l0.tag == 908u) {
        { vader_gc_top = gc_frame.prev; return 641u; }
    }
    if (l0.tag == 909u) {
        { vader_gc_top = gc_frame.prev; return 642u; }
    }
    if (l0.tag == 903u) {
        { vader_gc_top = gc_frame.prev; return 574u; }
    }
    if (!(l0.tag == 911u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l4 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l4, l3, 660u);
    t0 = l0.payload.obj;
    t2 = ((vader_struct_vader_core_types$InferVar_t*) t0)->f_id;
    l5 = ((int64_t) (int32_t) t2);
    l3 = std_core$write_int(l4, l3, l5);
    t1 = std_core$finish_buffer(l4, l3);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_core_types$carries_own_tag(vader_box_t l0) {
    bool l1;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$is_untagged(vader_ref_box(t0));
        l1 = !(t1);
        { bool __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if ((l0.tag == 904u || l0.tag == 915u)) {
        l1 = true;
    } else if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$is_machine_range(t0);
    } else if ((l0.tag == 903u || l0.tag == 905u || l0.tag == 906u || l0.tag == 911u || l0.tag == 923u)) {
        l1 = false;
    } else if ((l0.tag == 907u || l0.tag == 917u || l0.tag == 920u || l0.tag == 921u || l0.tag == 922u || l0.tag == 926u)) {
        l1 = false;
    } else {
        if (!((l0.tag == 908u || l0.tag == 909u || l0.tag == 910u || l0.tag == 913u || l0.tag == 927u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    { bool __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_core_types$check_common(vader_box_t l0, vader_box_t l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[3] = { &l0, &l1, &l5 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 926u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            t1 = vader_core_types$is_assignable(l0, l5);
            if (t1) {
                { vader_gc_top = gc_frame.prev; return true; }
            }
            l4 = (l4 + INT64_C(1));
        }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void vader_core_types$collect_variant(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[4] = { &l0, &l5, &l6, &t1 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 913u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_core_types$collect_variant(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else {
        l2 = l1;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            l6 = l0;
            t2 = vader_core_types$equals_type(l5, l6);
            if (t2) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            l4 = (l4 + INT64_C(1));
        }
        l5 = l0;
        vader_array_push_ref((vader_array_t*) l1, l5.payload.obj);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

bool vader_core_types$comes_before(vader_box_t l0, vader_string_t l1, vader_box_t l2, vader_string_t l3) {
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    bool t0;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[6] = { &l1, &l3, &l4, &l5, &l6, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1 != l3) {
        t0 = std_string$compare_ascending_ci(l1, l3);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_core_types$qualified_display_type(l0);
    l5 = vader_core_types$qualified_display_type(l2);
    if (!(l4 != l5)) {
        l6 = vader_core_types$canonical_key(l0);
        l7 = vader_core_types$canonical_key(l2);
        { bool __vret = (vader_string_compare(l6, l7) < INT32_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { bool __vret = (vader_string_compare(l4, l5) < INT32_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_core_types$contains_distinct(vader_box_t l0) {
    void* l1;
    int64_t l2, l3;
    void* t0;
    vader_box_t t1;
    bool t2;
    if (l0.tag == 905u) {
        return true;
    }
    if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_args;
        l2 = ((vader_array_t*) l1)->length;
        l3 = INT64_C(0);
        while ((l3 < l2)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            t2 = vader_core_types$contains_distinct(t1);
            if (t2) {
                return true;
            }
            l3 = (l3 + INT64_C(1));
        }
    }
    if (l0.tag == 920u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_types$TraitType_t*) t0)->f_args;
        l2 = ((vader_array_t*) l1)->length;
        l3 = INT64_C(0);
        while ((l3 < l2)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
            t2 = vader_core_types$contains_distinct(t1);
            if (t2) {
                return true;
            }
            l3 = (l3 + INT64_C(1));
        }
    }
    if (l0.tag == 904u) {
        t0 = l0.payload.obj;
        t2 = vader_core_types$contains_distinct(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element);
        return t2;
    }
    if (l0.tag == 921u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements;
        l2 = ((vader_array_t*) l1)->length;
        l3 = INT64_C(0);
        while ((l3 < l2)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
            t2 = vader_core_types$contains_distinct(t1);
            if (t2) {
                return true;
            }
            l3 = (l3 + INT64_C(1));
        }
    }
    if (l0.tag == 907u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_params;
        l2 = ((vader_array_t*) l1)->length;
        l3 = INT64_C(0);
        while ((l3 < l2)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l3);
            t2 = vader_core_types$contains_distinct(t1);
            if (t2) {
                return true;
            }
            l3 = (l3 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        t2 = vader_core_types$contains_distinct(((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type);
        return t2;
    }
    if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
        l2 = ((vader_array_t*) l1)->length;
        l3 = INT64_C(0);
        while ((l3 < l2)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l3);
            t2 = vader_core_types$contains_distinct(t1);
            if (t2) {
                return true;
            }
            l3 = (l3 + INT64_C(1));
        }
    }
    return false;
}

bool vader_core_types$contains_range(vader_box_t l0, bool l1) {
    bool l2;
    void* t0;
    bool t1;
    if (l0.tag == 916u) {
        if (!(l1)) {
            l2 = true;
        } else {
            t0 = l0.payload.obj;
            t1 = vader_core_types$is_machine_range(t0);
            l2 = !(t1);
        }
        return l2;
    }
    if (l0.tag == 905u) {
        t0 = l0.payload.obj;
        l2 = vader_core_types$contains_range(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing, l1);
    } else if ((l0.tag == 918u || l0.tag == 920u)) {
        l2 = vader_core_types$any_contains_range(VADER_UNION_FIELD(void*, vader_struct_vader_core_types$StructType_t, f_args, l0.payload.obj), l1);
    } else if (l0.tag == 904u) {
        t0 = l0.payload.obj;
        l2 = vader_core_types$contains_range(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element, l1);
    } else if (l0.tag == 921u) {
        t0 = l0.payload.obj;
        l2 = vader_core_types$any_contains_range(((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements, l1);
    } else if (l0.tag == 907u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$any_contains_range(((vader_struct_vader_core_types$FnType_t*) t0)->f_params, l1);
        if (t1) {
            l2 = true;
        } else {
            t0 = l0.payload.obj;
            l2 = vader_core_types$contains_range(((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type, l1);
        }
    } else if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        l2 = vader_core_types$any_contains_range(((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants, l1);
    } else {
        if (!((l0.tag == 903u || l0.tag == 906u || l0.tag == 908u || l0.tag == 909u || l0.tag == 910u || l0.tag == 911u || l0.tag == 913u || l0.tag == 915u || l0.tag == 917u || l0.tag == 922u || l0.tag == 923u || l0.tag == 927u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = false;
    }
    return l2;
}

vader_box_t vader_core_types$core_trait_arg(vader_box_t l0, vader_string_t l1) {
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t3 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 920u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$is_core_trait(t0, l1);
        if (t1) {
            t0 = l0.payload.obj;
            t2 = ((vader_array_t*) ((vader_struct_vader_core_types$TraitType_t*) t0)->f_args)->length;
            if ((t2 > INT64_C(0))) {
                t0 = l0.payload.obj;
                vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_types$TraitType_t*) t0)->f_args);
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

vader_string_t vader_core_types$core_trait_key(vader_string_t l0) {
    vader_string_t t0;
    t0 = concat_2(2594u, l0);
    return t0;
}

vader_box_t vader_core_types$counterpart(vader_box_t l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    int64_t l4, l5;
    bool t0;
    vader_box_t* gc_roots[3] = { &l0, &l1, &l3 };
    void** gc_raw_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_core_types$union_variants(l0);
    if (l3.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(251u, 1u, 13u, 1789u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l0.payload.obj;
        l2 = (void*) _a0_arr;
    } else {
        l2 = l3.payload.obj;
    }
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t0 = vader_core_types$same_variant(l3, l1);
        if (t0) {
            { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

vader_string_t vader_core_types$declaration_key(void* l0) {
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
    l1 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 254u);
    t0 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
    l3 = ((int64_t) (int32_t) t0);
    l2 = std_core$write_int(l1, l2, l3);
    t1 = std_core$finish_buffer(l1, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$default_free_members(vader_box_t l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    vader_box_t l2 = vader_box_null();
    int64_t l4, l5;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l2, &t0 };
    void** gc_raw_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_core_types$union_variants(l0);
    if (l2.tag == 0u) {
        t0 = vader_core_types$default_if_free(l0);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l2.payload.obj;
    t0 = vader_core_types$free_member(l0);
    if (t0.tag == 0u) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(251u, 0u, 13u, 1789u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) l1)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    l4 = ((vader_array_t*) l1)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l2 = vader_core_types$default_if_free(t0);
        vader_array_push_ref((vader_array_t*) l3, l2.payload.obj);
        l5 = (l5 + INT64_C(1));
    }
    t0 = vader_core_types$union_of(l3);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$default_if_free(vader_box_t l0) {
    void* t0;
    if (l0.tag == 910u) {
        t0 = (void*) &vader_data_19;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    if (l0.tag == 909u) {
        t0 = (void*) &vader_data_29;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    if (!(l0.tag == 908u)) {
        return l0;
    }
    t0 = (void*) &vader_data_26;
    vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t0);
}

vader_string_t vader_core_types$display_bounds(void* l0) {
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
    l1 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo_open;
    l2 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
    l3 = vader_core_types$open_or(l1, l2);
    t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_open;
    if (!(t0)) {
        l4 = l3;
        l2 = vader_host_std_core$byte_len(l4);
        l5 = (void*) vader_buffer_new((size_t) (INT64_C(23) + l2));
        l2 = INT64_C(0);
        l2 = std_core$write_string_at(l5, l2, l4);
        l2 = std_core$write_string_at(l5, l2, 404u);
        l6 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi;
        l2 = std_core$write_int(l5, l2, l6);
        t1 = std_core$finish_buffer(l5, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_past;
    if (!(t2 == INT64_C(0))) {
        l4 = l3;
        l2 = vader_host_std_core$byte_len(l4);
        l5 = (void*) vader_buffer_new((size_t) (INT64_C(23) + l2));
        l2 = INT64_C(0);
        l2 = std_core$write_string_at(l5, l2, l4);
        l2 = std_core$write_string_at(l5, l2, 404u);
        l7 = vader_support_integer$upper_past_i64(l0);
        l2 = std_core$write_unsigned(l5, l2, l7);
        t1 = std_core$finish_buffer(l5, l2);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = concat_2(l3, 400u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_types$display_range(void* l0) {
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
    l1 = vader_support_integer$machine_integer_name(((vader_struct_vader_core_types$RangeType_t*) l0)->f_bounds);
    if (l1 != 0u) {
        t0 = ((vader_struct_vader_core_types$RangeType_t*) l0)->f_name;
        if (t0 == 0u) {
            l2 = true;
        } else {
            t0 = ((vader_struct_vader_core_types$RangeType_t*) l0)->f_name;
            l2 = t0 == l1;
        }
    } else {
        l2 = false;
    }
    if (l2) {
        t0 = concat_3(1035u, l1, 1035u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_core_types$RangeType_t*) l0)->f_name;
    if (!(t0 == 0u)) {
        l3 = ((vader_struct_vader_core_types$RangeType_t*) l0)->f_name;
        l4 = vader_core_types$display_bounds(((vader_struct_vader_core_types$RangeType_t*) l0)->f_bounds);
        t0 = concat_5(1035u, l3, 1037u, l4, 323u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = vader_core_types$display_bounds(((vader_struct_vader_core_types$RangeType_t*) l0)->f_bounds);
    t0 = concat_3(1035u, l1, 1035u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_types$display_type(vader_box_t l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 915u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_types$RangeType_t*) t0)->f_name;
        if (t1 != 0u) {
            t0 = l0.payload.obj;
            t1 = ((vader_struct_vader_core_types$RangeType_t*) t0)->f_name;
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else {
        if ((l0.tag == 905u || l0.tag == 906u || l0.tag == 923u)) {
            t1 = ((vader_struct_vader_core_symbol$Symbol_t*) VADER_UNION_FIELD(void*, vader_struct_vader_core_types$DistinctType_t, f_symbol, l0.payload.obj))->f_name;
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if ((l0.tag == 918u || l0.tag == 920u)) {
            t2 = ((vader_array_t*) VADER_UNION_FIELD(void*, vader_struct_vader_core_types$StructType_t, f_args, l0.payload.obj))->length;
            if (t2 == INT64_C(0)) {
                t1 = ((vader_struct_vader_core_symbol$Symbol_t*) VADER_UNION_FIELD(void*, vader_struct_vader_core_types$StructType_t, f_symbol, l0.payload.obj))->f_name;
                { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
            }
        } else {
            if (l0.tag == 927u) {
                { vader_gc_top = gc_frame.prev; return 529u; }
            }
            if (l0.tag == 913u) {
                { vader_gc_top = gc_frame.prev; return 2371u; }
            }
            if (l0.tag == 910u) {
                { vader_gc_top = gc_frame.prev; return 3056u; }
            }
            if (l0.tag == 909u) {
                { vader_gc_top = gc_frame.prev; return 3055u; }
            }
            if (l0.tag == 908u) {
                { vader_gc_top = gc_frame.prev; return 3054u; }
            }
            if (l0.tag == 917u) {
                { vader_gc_top = gc_frame.prev; return 797u; }
            }
            if (l0.tag == 922u) {
                { vader_gc_top = gc_frame.prev; return 2743u; }
            }
            if (l0.tag == 903u) {
                { vader_gc_top = gc_frame.prev; return 579u; }
            }
            if (l0.tag == 911u) {
                t0 = l0.payload.obj;
                t1 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$InferVar_t*) t0)->f_origin)->f_name;
                { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 626u);
    _a1_obj->f_parts = t0;
    t0 = (void*) _a1_obj;
    vader_struct_vader_core_types$TypeWriter_t* _a2_obj = (vader_struct_vader_core_types$TypeWriter_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$TypeWriter_t));
    vader_obj_header_init(_a2_obj, 924u);
    _a2_obj->f_sb = t0;
    _a2_obj->f_qualified = false;
    _a2_obj->f_names = vader_box_obj(0u, NULL);
    l1 = (void*) _a2_obj;
    vader_core_types$write_type(l1, l0);
    t1 = std_string__builder$StringBuilder$std_core$Display$to_string(((vader_struct_vader_core_types$TypeWriter_t*) l1)->f_sb);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$enum_data_of(vader_box_t l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[3] = { &l0, &l1, &l3 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 906u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_types$EnumType_t*) t0)->f_data;
        if (l3.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l2 = l3.payload.obj;
        t1 = vader_core_types$is_assignable(vader_ref_box(l2), l1);
        if (t1) {
            { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

void* vader_core_types$enum_value_runs(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5, l6, l7, l8;
    int64_t t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(217u, 0u, 13u, 1413u);
    l1 = (void*) _a0_arr;
    l2 = std_collections$values__string__i64(((vader_struct_vader_core_types$EnumType_t*) l0)->f_indices);
    l3 = (void*) &vader_fn_static___lambda_vader_core_types_2;
    l2 = std_sort$sort__i64(l2, l3);
    t0 = ((vader_array_t*) l2)->length;
    if (t0 == INT64_C(0)) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
    l4 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) INT32_C(0)];
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
    l5 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) INT32_C(0)];
    l6 = ((vader_array_t*) l2)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l8 = ((int64_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l7];
        if ((l8 > l5)) {
            t0 = vader_chk_sub(i64, l8, INT64_C(1));
            if ((t0 > l5)) {
                l3 = vader_support_integer$interval(l4, l5);
                vader_array_push_ref((vader_array_t*) l1, l3);
                l4 = l8;
            }
        }
        l5 = l8;
        l7 = (l7 + INT64_C(1));
    }
    l2 = vader_support_integer$interval(l4, l5);
    vader_array_push_ref((vader_array_t*) l1, l2);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_core_types$equals_type(vader_box_t l0, vader_box_t l1) {
    bool l2, l11;
    vader_string_t l3, l4;
    void* l5;
    void* l6;
    int32_t l7, l8;
    vader_box_t l9, l10;
    void* t0;
    if (l0.tag == 922u) {
        l2 = l1.tag == 922u;
        return l2;
    }
    if (l0.tag == 917u) {
        l2 = l1.tag == 917u;
    } else if (l0.tag == 927u) {
        l2 = l1.tag == 927u;
    } else if (l0.tag == 913u) {
        l2 = l1.tag == 913u;
    } else if (l0.tag == 910u) {
        l2 = l1.tag == 910u;
    } else if (l0.tag == 909u) {
        l2 = l1.tag == 909u;
    } else if (l0.tag == 908u) {
        l2 = l1.tag == 908u;
    } else if (l0.tag == 903u) {
        l2 = l1.tag == 903u;
    } else if (l0.tag == 915u) {
        if (l1.tag == 915u) {
            t0 = l0.payload.obj;
            l3 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
            l2 = l3 == l4;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 916u) {
        if (l1.tag == 916u) {
            t0 = l0.payload.obj;
            l5 = ((vader_struct_vader_core_types$RangeType_t*) t0)->f_bounds;
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_core_types$RangeType_t*) t0)->f_bounds;
            l2 = vader_support_integer$same_interval(l5, l6);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 923u) {
        if (l1.tag == 923u) {
            t0 = l0.payload.obj;
            l7 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) t0)->f_symbol)->f_id;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) t0)->f_symbol)->f_id;
            l2 = l7 == l8;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 911u) {
        if (l1.tag == 911u) {
            t0 = l0.payload.obj;
            l7 = ((vader_struct_vader_core_types$InferVar_t*) t0)->f_id;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_core_types$InferVar_t*) t0)->f_id;
            l2 = l7 == l8;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 906u) {
        if (l1.tag == 906u) {
            t0 = l0.payload.obj;
            l7 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$EnumType_t*) t0)->f_symbol)->f_id;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$EnumType_t*) t0)->f_symbol)->f_id;
            l2 = l7 == l8;
        } else if (l1.tag == 918u) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_id;
            t0 = l0.payload.obj;
            l8 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$EnumType_t*) t0)->f_symbol)->f_id;
            l2 = l7 == l8;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 918u) {
        if (l1.tag == 918u) {
            t0 = l0.payload.obj;
            l7 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_id;
            t0 = l0.payload.obj;
            l5 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_args;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_id;
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_args;
            l2 = vader_core_types$nominal_eq(l7, l5, l8, l6);
        } else if (l1.tag == 906u) {
            t0 = l0.payload.obj;
            l7 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_id;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$EnumType_t*) t0)->f_symbol)->f_id;
            l2 = l7 == l8;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 920u) {
        if (l1.tag == 920u) {
            t0 = l0.payload.obj;
            l7 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TraitType_t*) t0)->f_symbol)->f_id;
            t0 = l0.payload.obj;
            l5 = ((vader_struct_vader_core_types$TraitType_t*) t0)->f_args;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TraitType_t*) t0)->f_symbol)->f_id;
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_core_types$TraitType_t*) t0)->f_args;
            l2 = vader_core_types$nominal_eq(l7, l5, l8, l6);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 904u) {
        if (l1.tag == 904u) {
            t0 = l0.payload.obj;
            l9 = ((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element;
            t0 = l1.payload.obj;
            l10 = ((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element;
            l2 = vader_core_types$equals_type(l9, l10);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 921u) {
        if (l1.tag == 921u) {
            t0 = l0.payload.obj;
            l5 = ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements;
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements;
            l2 = vader_core_types$type_list_equals(l5, l6);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 907u) {
        if (l1.tag == 907u) {
            t0 = l0.payload.obj;
            l5 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_params;
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_params;
            l11 = vader_core_types$type_list_equals(l5, l6);
        } else {
            l11 = false;
        }
        if (l11) {
            t0 = l0.payload.obj;
            l9 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type;
            t0 = l1.payload.obj;
            l10 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type;
            l2 = vader_core_types$equals_type(l9, l10);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 926u) {
        if (l1.tag == 926u) {
            t0 = l0.payload.obj;
            l5 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
            l2 = vader_core_types$type_list_equals(l5, l6);
        } else {
            l2 = false;
        }
    } else {
        if (!(l0.tag == 905u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        if (l1.tag == 905u) {
            t0 = l0.payload.obj;
            l7 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$DistinctType_t*) t0)->f_symbol)->f_id;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$DistinctType_t*) t0)->f_symbol)->f_id;
            l2 = l7 == l8;
        } else {
            l2 = false;
        }
    }
    return l2;
}

static void* vader_core_types$erase_each(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    int64_t l2, l4;
    vader_box_t l5 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(251u, 0u, 13u, 1789u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l3 = l0;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = vader_core_types$erase_params_in(t0);
        vader_array_push_ref((vader_array_t*) l1, l5.payload.obj);
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_types$erase_params_in(vader_box_t l0) {
    vader_box_t l1 = vader_box_null(), l4 = vader_box_null();
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void* t2 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l1, &l4, &t1 };
    void** gc_raw_roots[4] = { &l2, &l3, &t0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 923u) {
        t0 = (void*) &vader_data_22;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        l1 = vader_ref_box(t0);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 911u) {
        t0 = (void*) &vader_data_22;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 904u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$erase_params_in(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element);
        l1 = vader_core_types$mk_array(t1);
    } else if (l0.tag == 921u) {
        t0 = l0.payload.obj;
        t2 = vader_core_types$erase_each(((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements);
        l1 = vader_core_types$mk_tuple(t2);
    } else if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol;
        t0 = l0.payload.obj;
        l3 = vader_core_types$erase_each(((vader_struct_vader_core_types$StructType_t*) t0)->f_args);
        l1 = vader_core_types$mk_struct(l2, l3);
    } else if (l0.tag == 920u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_types$TraitType_t*) t0)->f_symbol;
        t0 = l0.payload.obj;
        l3 = vader_core_types$erase_each(((vader_struct_vader_core_types$TraitType_t*) t0)->f_args);
        vader_struct_vader_core_types$TraitType_t* _a2_obj = (vader_struct_vader_core_types$TraitType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$TraitType_t));
        vader_obj_header_init(_a2_obj, 920u);
        _a2_obj->f_symbol = l2;
        _a2_obj->f_args = l3;
        t0 = (void*) _a2_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 907u) {
        t0 = l0.payload.obj;
        l2 = vader_core_types$erase_each(((vader_struct_vader_core_types$FnType_t*) t0)->f_params);
        t0 = l0.payload.obj;
        l4 = vader_core_types$erase_params_in(((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type);
        vader_array_t* _a3_arr = vader_array_new(85u, 0u, 13u, 923u);
        l3 = (void*) _a3_arr;
        t0 = vader_core_types$mk_fn(l2, l4, l3);
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        t2 = vader_core_types$erase_each(((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants);
        l1 = vader_core_types$mk_union(t2);
    } else {
        l1 = l0;
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_types$erase_ranges(vader_box_t l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null(), l4 = vader_box_null();
    void* l3 = NULL;
    void* l5 = NULL;
    bool t0;
    void* t1 = NULL;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l0, &l1, &l2, &l4, &t3 };
    void** gc_raw_roots[4] = { &l3, &l5, &t1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 915u) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_types$contains_range(l0, false);
    if (t0) {
        l1 = l0;
        if (l1.tag == 916u) {
            t1 = l0.payload.obj;
            t2 = vader_core_types$range_representation(t1);
            l2 = vader_ref_box(t2);
            { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        if (l1.tag == 905u) {
            t1 = l0.payload.obj;
            l3 = ((vader_struct_vader_core_types$DistinctType_t*) t1)->f_symbol;
            t1 = l0.payload.obj;
            l4 = vader_core_types$erase_ranges(((vader_struct_vader_core_types$DistinctType_t*) t1)->f_backing);
            l2 = vader_core_types$mk_distinct(l3, l4);
        } else if (l1.tag == 918u) {
            t1 = l0.payload.obj;
            l3 = ((vader_struct_vader_core_types$StructType_t*) t1)->f_symbol;
            t1 = l0.payload.obj;
            l5 = vader_core_types$erase_ranges_each(((vader_struct_vader_core_types$StructType_t*) t1)->f_args);
            l2 = vader_core_types$mk_struct(l3, l5);
        } else if (l1.tag == 920u) {
            t1 = l0.payload.obj;
            l3 = ((vader_struct_vader_core_types$TraitType_t*) t1)->f_symbol;
            t1 = l0.payload.obj;
            l5 = vader_core_types$erase_ranges_each(((vader_struct_vader_core_types$TraitType_t*) t1)->f_args);
            vader_struct_vader_core_types$TraitType_t* _a0_obj = (vader_struct_vader_core_types$TraitType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$TraitType_t));
            vader_obj_header_init(_a0_obj, 920u);
            _a0_obj->f_symbol = l3;
            _a0_obj->f_args = l5;
            t1 = (void*) _a0_obj;
            l2 = vader_ref_box(t1);
        } else if (l1.tag == 904u) {
            t1 = l0.payload.obj;
            t3 = vader_core_types$erase_ranges(((vader_struct_vader_core_types$ArrayType_t*) t1)->f_element);
            l2 = vader_core_types$mk_array(t3);
        } else if (l1.tag == 921u) {
            t1 = l0.payload.obj;
            t2 = vader_core_types$erase_ranges_each(((vader_struct_vader_core_types$TupleType_t*) t1)->f_elements);
            l2 = vader_core_types$mk_tuple(t2);
        } else if (l1.tag == 907u) {
            l3 = l0.payload.obj;
            t1 = l0.payload.obj;
            l5 = vader_core_types$erase_ranges_each(((vader_struct_vader_core_types$FnType_t*) t1)->f_params);
            t1 = l0.payload.obj;
            l4 = vader_core_types$erase_ranges(((vader_struct_vader_core_types$FnType_t*) t1)->f_return_type);
            l3 = ((vader_struct_vader_core_types$FnType_t*) l3)->f_type_params;
            vader_struct_vader_core_types$FnType_t* _a1_obj = (vader_struct_vader_core_types$FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$FnType_t));
            vader_obj_header_init(_a1_obj, 907u);
            _a1_obj->f_params = l5;
            _a1_obj->f_return_type = l4;
            _a1_obj->f_type_params = l3;
            t1 = (void*) _a1_obj;
            l2 = vader_ref_box(t1);
        } else if (l1.tag == 926u) {
            t1 = l0.payload.obj;
            l2 = vader_core_types$erase_union(t1);
        } else {
            if (!((l1.tag == 903u || l1.tag == 906u || l1.tag == 908u || l1.tag == 909u || l1.tag == 910u || l1.tag == 911u || l1.tag == 913u || l1.tag == 915u || l1.tag == 917u || l1.tag == 922u || l1.tag == 923u || l1.tag == 927u))) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l2 = l0;
        }
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_core_types$erase_ranges_each(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    int64_t l2, l4;
    vader_box_t l5 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(251u, 0u, 13u, 1789u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l3 = l0;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = vader_core_types$erase_ranges(t0);
        vader_array_push_ref((vader_array_t*) l1, l5.payload.obj);
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$erase_type_params(vader_box_t l0) {
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$type_contains_type_param(l0);
    if (t0) {
        t1 = vader_core_types$erase_params_in(l0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_types$erase_union(void* l0) {
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$contains_range(vader_ref_box(l0), true);
    if (!(t0)) {
        t1 = vader_core_types$erase_ranges_each(((vader_struct_vader_core_types$UnionType_t*) l0)->f_variants);
        vader_struct_vader_core_types$UnionType_t* _a0_obj = (vader_struct_vader_core_types$UnionType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$UnionType_t));
        vader_obj_header_init(_a0_obj, 926u);
        _a0_obj->f_variants = t1;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_core_types$erase_ranges_each(((vader_struct_vader_core_types$UnionType_t*) l0)->f_variants);
    t2 = vader_core_types$union_of(t1);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$erased_async_type(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &t0, &t1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$async_inner_type(l1);
    t1 = vader_core_types$async_result_arg(t0);
    vader_array_t* _a0_arr = vader_array_new(251u, 1u, 13u, 1789u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t1.payload.obj;
    l2 = (void*) _a0_arr;
    t0 = vader_core_types$mk_trait(l0, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_core_types$find_unused_equal(void* l0, void* l1, vader_box_t l2) {
    int64_t l3, l4;
    bool t0, t1;
    vader_box_t t2;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        t1 = t0;
        if (!(t1)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
            t0 = vader_core_types$equals_type(t2, l2);
            if (t0) {
                return ((int32_t) (int64_t) l3);
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    return INT32_C(-1);
}

static bool vader_core_types$fits_tuple_field(vader_box_t l0, vader_box_t l1) {
    bool l2;
    vader_box_t l3 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$adopts_any_layout(l0);
    if (t0) {
        t0 = vader_core_types$is_assignable(l0, l1);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_types$equals_type(l0, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = vader_core_types$is_assignable(l0, l1);
    if (t0) {
        l3 = l0;
        l2 = vader_core_types$is_assignable(l1, l3);
    } else {
        l2 = false;
    }
    { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_core_types$fn_param_compatible(vader_box_t l0, vader_box_t l1) {
    bool t0;
    t0 = vader_core_types$is_assignable(l0, l1);
    return t0;
}

static bool vader_core_types$fn_signature_compatible(vader_box_t l0, vader_box_t l1) {
    bool t0;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$is_assignable(l0, l1);
    if (t0) {
        t0 = vader_core_types$laid_out_alike(l0, l1);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

void vader_core_types$for_each_type(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
    ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, l0);
    if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_core_types$for_each_type(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 920u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_types$TraitType_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            vader_core_types$for_each_type(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 904u) {
        t0 = l0.payload.obj;
        vader_core_types$for_each_type(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element, l1);
    } else if (l0.tag == 921u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
            t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
            vader_core_types$for_each_type(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 907u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_params;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
            t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
            vader_core_types$for_each_type(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        vader_core_types$for_each_type(((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type, l1);
    } else if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l4)
            t1 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l4);
            vader_core_types$for_each_type(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 905u) {
        t0 = l0.payload.obj;
        vader_core_types$for_each_type(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

vader_box_t vader_core_types$free_member(vader_box_t l0) {
    vader_box_t l1;
    void* l2;
    int64_t l3, l4;
    bool t0;
    t0 = vader_core_types$is_free_numeric(l0);
    if (t0) {
        return l0;
    }
    l1 = vader_core_types$union_variants(l0);
    if (l1.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l2 = l1.payload.obj;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = vader_core_types$is_free_numeric(l1);
        if (t0) {
            return l1;
        }
        l4 = (l4 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

bool vader_core_types$has_builtin_impl(vader_box_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    bool l3;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 906u) {
        l2 = vader_core_types$core_trait_key(637u);
        if (l1 == l2) {
            l3 = true;
        } else {
            l2 = vader_core_types$core_trait_key(658u);
            l3 = l1 == l2;
        }
        { bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_core_types$held_by_another(void* l0, vader_box_t l1) {
    void* l2;
    int64_t l3, l4;
    vader_box_t t0;
    bool t1;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = vader_core_types$holds_integer(t0, l1);
        if (t1) {
            return true;
        }
        l4 = (l4 + INT64_C(1));
    }
    return false;
}

vader_box_t vader_core_types$held_integer(vader_box_t l0) {
    vader_box_t t0;
    void* t1;
    if (!(l0.tag == 905u)) {
        t0 = vader_core_types$integer_representation(l0);
        return t0;
    }
    t1 = l0.payload.obj;
    t0 = vader_core_types$held_integer(((vader_struct_vader_core_types$DistinctType_t*) t1)->f_backing);
    return t0;
}

vader_box_t vader_core_types$held_values(vader_box_t l0) {
    void* l1;
    vader_box_t l2;
    l2 = vader_core_types$held_integer(l0);
    if (l2.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l1 = l2.payload.obj;
    return vader_ref_box(((vader_struct_vader_support_integer$MachineInteger_t*) l1)->f_values);
}

static bool vader_core_types$holds_infer_var(vader_box_t l0, int32_t l1) {
    void* t0;
    int32_t t1;
    bool t2;
    if (l0.tag == 911u) {
        if (l1 == INT32_C(-1)) {
            return true;
        }
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_types$InferVar_t*) t0)->f_id;
        return t1 == l1;
    }
    if (l0.tag == 904u) {
        t0 = l0.payload.obj;
        t2 = vader_core_types$holds_infer_var(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element, l1);
        return t2;
    }
    if (l0.tag == 921u) {
        t0 = l0.payload.obj;
        t2 = vader_core_types$any_holds_infer_var(((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements, l1);
        return t2;
    }
    if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        t2 = vader_core_types$any_holds_infer_var(((vader_struct_vader_core_types$StructType_t*) t0)->f_args, l1);
        return t2;
    }
    if (l0.tag == 920u) {
        t0 = l0.payload.obj;
        t2 = vader_core_types$any_holds_infer_var(((vader_struct_vader_core_types$TraitType_t*) t0)->f_args, l1);
        return t2;
    }
    if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        t2 = vader_core_types$any_holds_infer_var(((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants, l1);
        return t2;
    }
    if (l0.tag == 905u) {
        t0 = l0.payload.obj;
        t2 = vader_core_types$holds_infer_var(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing, l1);
        return t2;
    }
    if (!(l0.tag == 907u)) {
        return false;
    }
    t0 = l0.payload.obj;
    t2 = vader_core_types$any_holds_infer_var(((vader_struct_vader_core_types$FnType_t*) t0)->f_params, l1);
    if (t2) {
        return true;
    }
    t0 = l0.payload.obj;
    t2 = vader_core_types$holds_infer_var(((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type, l1);
    return t2;
}

bool vader_core_types$holds_integer(vader_box_t l0, vader_box_t l1) {
    void* l2;
    void* l4;
    vader_box_t l3;
    bool t0;
    vader_string_t t1;
    l3 = vader_core_types$integer_values(l0);
    if (l3.tag == 0u) {
        return false;
    }
    l2 = l3.payload.obj;
    l3 = vader_core_types$integer_values(l1);
    if (l3.tag == 0u) {
        return false;
    }
    l4 = l3.payload.obj;
    t0 = vader_support_integer$interval_within(l4, l2);
    if (!(t0)) {
        return false;
    }
    t0 = vader_support_integer$same_interval(l4, l2);
    if (!(t0)) {
        return true;
    }
    t1 = vader_core_types$primitive_name(l1);
    if (t1 == 0u) {
        t1 = vader_core_types$primitive_name(l0);
        return t1 == 0u;
    }
    return false;
}

static bool vader_core_types$holds_refinement_union(vader_box_t l0) {
    bool l1;
    void* t0;
    bool t1;
    if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$contains_range(vader_ref_box(t0), true);
        return l1;
    }
    if (l0.tag == 905u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$holds_refinement_union(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
    } else if ((l0.tag == 918u || l0.tag == 920u)) {
        l1 = vader_core_types$any_holds_refinement_union(VADER_UNION_FIELD(void*, vader_struct_vader_core_types$StructType_t, f_args, l0.payload.obj));
    } else if (l0.tag == 904u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$holds_refinement_union(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element);
    } else if (l0.tag == 921u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$any_holds_refinement_union(((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements);
    } else if (l0.tag == 907u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$any_holds_refinement_union(((vader_struct_vader_core_types$FnType_t*) t0)->f_params);
        if (t1) {
            l1 = true;
        } else {
            t0 = l0.payload.obj;
            l1 = vader_core_types$holds_refinement_union(((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type);
        }
    } else {
        if (!((l0.tag == 903u || l0.tag == 906u || l0.tag == 908u || l0.tag == 909u || l0.tag == 910u || l0.tag == 911u || l0.tag == 913u || l0.tag == 915u || l0.tag == 916u || l0.tag == 917u || l0.tag == 922u || l0.tag == 923u || l0.tag == 927u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

vader_string_t vader_core_types$impl_base_key(vader_box_t l0) {
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
    if ((l0.tag == 905u || l0.tag == 906u || l0.tag == 918u || l0.tag == 920u)) {
        t0 = vader_core_types$declaration_key(VADER_UNION_FIELD(void*, vader_struct_vader_core_types$DistinctType_t, f_symbol, l0.payload.obj));
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 904u) {
        { vader_gc_top = gc_frame.prev; return 965u; }
    }
    if (l0.tag == 916u) {
        t1 = l0.payload.obj;
        t2 = vader_core_types$storage_integer(t1);
        t0 = ((vader_struct_vader_support_integer$MachineInteger_t*) t2)->f_name;
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!((l0.tag == 907u || l0.tag == 921u || l0.tag == 926u))) {
        t0 = vader_core_types$display_type(l0);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_types$canonical_key(l0);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t vader_core_types$integer_bound(void* l0, bool l1) {
    int64_t t0;
    bool t1;
    uint64_t t2;
    if (!(l1)) {
        t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_lo;
        return t0;
    }
    t1 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi_open;
    if (!(t1)) {
        t0 = ((vader_struct_vader_support_integer$Interval_t*) l0)->f_hi;
        return t0;
    }
    t2 = vader_support_integer$upper_past_i64(l0);
    return ((int64_t) (uint64_t) t2);
}

vader_box_t vader_core_types$integer_representation(vader_box_t l0) {
    void* t0;
    void* t1;
    if (!(l0.tag == 916u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    t1 = vader_core_types$storage_integer(t0);
    return vader_ref_box(t1);
}

vader_box_t vader_core_types$integer_set(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    bool t2;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!((l0.tag == 905u || l0.tag == 915u || l0.tag == 916u))) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l1 = vader_core_types$strip_distinct(l0);
    if (l1.tag == 915u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        if (t1 == 1745u) {
            t0 = __const_vader_core_types$CHAR_VALUES();
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l1 = vader_core_types$integer_values(l1);
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l1.payload.obj;
    t2 = ((vader_struct_vader_support_integer$Interval_t*) l2)->f_lo_open;
    if (t2) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t2 = ((vader_struct_vader_support_integer$Interval_t*) l2)->f_hi_open;
    if (!(t2)) {
        vader_array_t* _a0_arr = vader_array_new(217u, 1u, 13u, 1413u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l2;
        t0 = (void*) _a0_arr;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

vader_box_t vader_core_types$integer_values(vader_box_t l0) {
    void* t0;
    if (!(l0.tag == 916u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    return vader_ref_box(((vader_struct_vader_core_types$RangeType_t*) t0)->f_bounds);
}

static vader_box_t vader_core_types$interval_hull(void* l0) {
    int64_t l1, l2;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l0)->length;
    if (!(t0 == INT64_C(0))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        l1 = ((vader_struct_vader_support_integer$Interval_t*) t1)->f_lo;
        t0 = ((vader_array_t*) l0)->length;
        l2 = vader_chk_sub(i64, t0, INT64_C(1));
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        l2 = ((vader_struct_vader_support_integer$Interval_t*) t1)->f_hi;
        t1 = vader_support_integer$interval(l1, l2);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

bool vader_core_types$is_assignable(vader_box_t l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l7 = vader_box_null();
    bool l4;
    void* l5 = NULL;
    void* l6 = NULL;
    bool t0;
    vader_box_t* gc_roots[5] = { &l0, &l1, &l2, &l3, &l7 };
    void** gc_raw_roots[2] = { &l5, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 927u) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l1.tag == 927u) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l0.tag == 913u) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l2 = l0;
    l3 = l1;
    t0 = vader_core_types$equals_type(l2, l3);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if ((l1.tag == 911u || l1.tag == 923u)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = l0;
    if (l2.tag == 918u) {
        l5 = l0.payload.obj;
        l6 = l0.payload.obj;
        l3 = l1;
        l4 = vader_core_types$is_assignable_struct(vader_ref_box(l5), l6, l3);
        { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 920u) {
        l5 = l0.payload.obj;
        l6 = l0.payload.obj;
        l3 = l1;
        l4 = vader_core_types$is_assignable_trait_from(vader_ref_box(l5), l6, l3);
    } else if (l2.tag == 921u) {
        l5 = l0.payload.obj;
        l6 = l0.payload.obj;
        l3 = l1;
        l4 = vader_core_types$is_assignable_tuple(vader_ref_box(l5), l6, l3);
    } else if (l2.tag == 904u) {
        l5 = l0.payload.obj;
        l6 = l0.payload.obj;
        l3 = l1;
        l4 = vader_core_types$is_assignable_array(vader_ref_box(l5), l6, l3);
    } else if (l2.tag == 907u) {
        l5 = l0.payload.obj;
        l6 = l0.payload.obj;
        l3 = l1;
        l4 = vader_core_types$is_assignable_fn(vader_ref_box(l5), l6, l3);
    } else if (l2.tag == 926u) {
        l5 = l0.payload.obj;
        l6 = l0.payload.obj;
        l3 = l1;
        l4 = vader_core_types$is_assignable_union(vader_ref_box(l5), l6, l3);
    } else if ((l2.tag == 908u || l2.tag == 909u || l2.tag == 910u)) {
        l3 = l0;
        l7 = l1;
        l4 = vader_core_types$is_assignable_free_literal(l3, l7);
    } else if (l2.tag == 916u) {
        l2 = l1;
        l5 = l0.payload.obj;
        t0 = vader_core_types$holds_integer(l2, vader_ref_box(l5));
        if (t0) {
            l4 = true;
        } else {
            l5 = l0.payload.obj;
            l2 = l1;
            l4 = vader_core_types$check_common(vader_ref_box(l5), l2);
        }
    } else {
        l2 = l0;
        l3 = l1;
        l4 = vader_core_types$check_common(l2, l3);
    }
    { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_core_types$is_assignable_array(vader_box_t l0, void* l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l2, &l3, &l4 };
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l2.tag == 904u)) {
        l3 = l2;
        t0 = vader_core_types$check_common(l0, l3);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_core_types$ArrayType_t*) l1)->f_element;
    t1 = l2.payload.obj;
    l4 = ((vader_struct_vader_core_types$ArrayType_t*) t1)->f_element;
    t0 = vader_core_types$equals_type(l3, l4);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l3 = ((vader_struct_vader_core_types$ArrayType_t*) l1)->f_element;
    t1 = l2.payload.obj;
    l4 = ((vader_struct_vader_core_types$ArrayType_t*) t1)->f_element;
    t0 = vader_core_types$fn_param_compatible(l3, l4);
    if (t0) {
        t1 = l2.payload.obj;
        l3 = ((vader_struct_vader_core_types$ArrayType_t*) t1)->f_element;
        l4 = ((vader_struct_vader_core_types$ArrayType_t*) l1)->f_element;
        t0 = vader_core_types$fn_param_compatible(l3, l4);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_core_types$is_assignable_fn(vader_box_t l0, void* l1, vader_box_t l2) {
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l2, &l5, &l6 };
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l2.tag == 907u)) {
        t0 = vader_core_types$check_common(l0, l2);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_array_t*) ((vader_struct_vader_core_types$FnType_t*) l1)->f_params)->length;
    t1 = l2.payload.obj;
    l4 = ((vader_array_t*) ((vader_struct_vader_core_types$FnType_t*) t1)->f_params)->length;
    if (l3 != l4) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_core_types$FnType_t*) l1)->f_params)->length;
    while ((l3 < l4)) {
        t1 = l2.payload.obj;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_types$FnType_t*) t1)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_types$FnType_t*) l1)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        t0 = vader_core_types$fn_signature_compatible(l5, l6);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l3 = (l3 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_core_types$FnType_t*) l1)->f_return_type;
    t1 = l2.payload.obj;
    l6 = ((vader_struct_vader_core_types$FnType_t*) t1)->f_return_type;
    t0 = vader_core_types$fn_signature_compatible(l5, l6);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_core_types$is_assignable_free_literal(vader_box_t l0, vader_box_t l1) {
    bool t0;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$literal_takes(l0, l1);
    if (!(t0)) {
        t0 = vader_core_types$check_common(l0, l1);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return true; }
}

static bool vader_core_types$is_assignable_struct(vader_box_t l0, void* l1, vader_box_t l2) {
    int32_t l3, l4;
    void* l5 = NULL;
    void* l6 = NULL;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[4] = { &l1, &l5, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2.tag == 918u) {
        l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) l1)->f_symbol)->f_id;
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_id;
        if (l3 == l4) {
            l5 = ((vader_struct_vader_core_types$StructType_t*) l1)->f_args;
            t0 = l2.payload.obj;
            l6 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_args;
            t1 = vader_core_types$struct_args_compatible(l5, l6);
            if (t1) {
                { vader_gc_top = gc_frame.prev; return true; }
            }
        }
        t1 = vader_core_types$check_common(l0, l2);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_core_types$check_common(l0, l2);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_core_types$is_assignable_trait_from(vader_box_t l0, void* l1, vader_box_t l2) {
    int32_t l3, l4;
    void* l5 = NULL;
    void* l6 = NULL;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[4] = { &l1, &l5, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2.tag == 920u) {
        l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TraitType_t*) l1)->f_symbol)->f_id;
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TraitType_t*) t0)->f_symbol)->f_id;
        if (l3 == l4) {
            l5 = ((vader_struct_vader_core_types$TraitType_t*) l1)->f_args;
            t0 = l2.payload.obj;
            l6 = ((vader_struct_vader_core_types$TraitType_t*) t0)->f_args;
            t1 = vader_core_types$struct_args_compatible(l5, l6);
            if (t1) {
                { vader_gc_top = gc_frame.prev; return true; }
            }
        }
        t1 = vader_core_types$check_common(l0, l2);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_core_types$check_common(l0, l2);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_core_types$is_assignable_tuple(vader_box_t l0, void* l1, vader_box_t l2) {
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l2, &l5, &l6 };
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l2.tag == 921u)) {
        t0 = vader_core_types$check_common(l0, l2);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) l1)->f_elements)->length;
    t1 = l2.payload.obj;
    l4 = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t1)->f_elements)->length;
    if (l3 != l4) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) l1)->f_elements)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) l1)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = l2.payload.obj;
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t1)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        t0 = vader_core_types$fits_tuple_field(l5, l6);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return true; }
}

static bool vader_core_types$is_assignable_union(vader_box_t l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l7 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[3] = { &l0, &l2, &l6 };
    void** gc_raw_roots[3] = { &l1, &l3, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l2.tag == 926u)) {
        t0 = vader_core_types$check_common(l0, l2);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_core_types$UnionType_t*) l1)->f_variants;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l7 = l2.payload.obj;
        t0 = vader_core_types$variant_keeps_tag(l6, l7);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return true; }
}

bool vader_core_types$is_c_library(vader_box_t l0) {
    void* t0;
    vader_string_t t1;
    if (!(l0.tag == 918u)) {
        return false;
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_module_name;
    if (t1 == 2588u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_name;
        return t1 == 608u;
    }
    return false;
}

bool vader_core_types$is_char(vader_box_t l0) {
    void* t0;
    vader_string_t t1;
    if (l0.tag == 915u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        return t1 == 1745u;
    }
    return false;
}

bool vader_core_types$is_core_struct(void* l0, vader_string_t l1) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) l0)->f_symbol)->f_module_name;
    if (t0 == 2584u) {
        t0 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) l0)->f_symbol)->f_name;
        return t0 == l1;
    }
    return false;
}

bool vader_core_types$is_core_trait(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_core_types$trait_key_of(((vader_struct_vader_core_types$TraitType_t*) l0)->f_symbol);
    l3 = vader_core_types$core_trait_key(l1);
    { bool __vret = l2 == l3; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_core_types$is_counting_type(vader_box_t l0) {
    bool l1;
    if ((l0.tag == 908u || l0.tag == 910u || l0.tag == 916u)) {
        l1 = true;
        return l1;
    }
    if ((l0.tag == 905u || l0.tag == 906u || l0.tag == 909u || l0.tag == 915u || l0.tag == 918u)) {
        l1 = false;
    } else if ((l0.tag == 904u || l0.tag == 907u || l0.tag == 920u || l0.tag == 921u || l0.tag == 923u || l0.tag == 926u)) {
        l1 = false;
    } else if ((l0.tag == 903u || l0.tag == 911u || l0.tag == 917u)) {
        l1 = false;
    } else {
        if (!((l0.tag == 913u || l0.tag == 922u || l0.tag == 927u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

bool vader_core_types$is_empty_substitution(void* l0) {
    bool t0;
    t0 = std_collections$is_empty__i32__Any(((vader_struct_vader_core_types$Substitution_t*) l0)->f_type_params);
    if (!(t0)) {
        return false;
    }
    if (!(((vader_struct_vader_core_types$Substitution_t*) l0)->f_self_type.tag == 0u)) {
        return false;
    }
    return true;
}

bool vader_core_types$is_float_name(vader_string_t l0) {
    vader_box_t l1;
    void* t0;
    bool t1;
    l1 = vader_core_types$primitive_meta(l0);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_core_types$PrimitiveMeta_t*) t0)->f_is_float;
        return t1;
    }
    return false;
}

bool vader_core_types$is_free_numeric(vader_box_t l0) {
    if (l0.tag == 910u) {
        return true;
    }
    if (l0.tag == 908u) {
        return true;
    }
    if (!(l0.tag == 909u)) {
        return false;
    }
    return true;
}

bool vader_core_types$is_int_name(vader_string_t l0) {
    vader_box_t t0;
    t0 = vader_support_integer$machine_integer_named(l0);
    return !(t0.tag == 0u);
}

bool vader_core_types$is_machine_integer(vader_box_t l0) {
    void* t0;
    bool t1;
    if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$is_machine_range(t0);
        return t1;
    }
    return false;
}

bool vader_core_types$is_machine_range(void* l0) {
    vader_string_t t0;
    t0 = vader_support_integer$machine_integer_name(((vader_struct_vader_core_types$RangeType_t*) l0)->f_bounds);
    return t0 != 0u;
}

bool vader_core_types$is_null_type(vader_box_t l0) {
    void* t0;
    vader_string_t t1;
    if (l0.tag == 915u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        return t1 == 2408u;
    }
    return false;
}

bool vader_core_types$is_numeric_name(vader_string_t l0) {
    bool t0;
    t0 = vader_core_types$is_int_name(l0);
    if (t0) {
        return true;
    }
    t0 = vader_core_types$is_float_name(l0);
    return t0;
}

static bool vader_core_types$is_reference_name(vader_string_t l0) {
    vader_box_t l1;
    void* t0;
    bool t1;
    l1 = vader_core_types$primitive_meta(l0);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_core_types$PrimitiveMeta_t*) t0)->f_is_reference;
        return t1;
    }
    return false;
}

bool vader_core_types$is_refinement(vader_box_t l0) {
    vader_box_t t0;
    t0 = vader_core_types$refinement_of(l0);
    return !(t0.tag == 0u);
}

bool vader_core_types$is_scalar_type_name(vader_string_t l0) {
    vader_box_t t0;
    bool t1;
    t0 = vader_core_types$primitive_meta(l0);
    if (!(t0.tag == 0u)) {
        return true;
    }
    t1 = vader_core_types$is_int_name(l0);
    return t1;
}

bool vader_core_types$is_stored_as_integer(vader_box_t l0) {
    void* t0;
    bool t1;
    if (!(l0.tag == 905u)) {
        return l0.tag == 916u;
    }
    t0 = l0.payload.obj;
    t1 = vader_core_types$is_stored_as_integer(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
    return t1;
}

bool vader_core_types$is_structural(vader_box_t l0) {
    bool l1;
    if (l0.tag == 921u) {
        l1 = true;
    } else {
        l1 = l0.tag == 907u;
    }
    if (l1) {
        return true;
    }
    return l0.tag == 926u;
}

bool vader_core_types$is_unsigned_int_name(vader_string_t l0) {
    void* l1;
    vader_box_t l2;
    bool t0;
    l2 = vader_support_integer$machine_integer_named(l0);
    if (l2.tag == 0u) {
        return false;
    }
    l1 = l2.payload.obj;
    t0 = ((vader_struct_vader_support_integer$MachineInteger_t*) l1)->f_is_signed;
    return !(t0);
}

bool vader_core_types$is_untagged(vader_box_t l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l4, &t1 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 903u) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l0.tag == 923u) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_args;
        l2 = ((vader_array_t*) l1)->length;
        l3 = INT64_C(0);
        while ((l3 < l2)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            if (!(l4.tag == 927u)) {
                t1 = vader_core_types$kept_type_argument(l4);
                if (t1.tag == 0u) {
                    { vader_gc_top = gc_frame.prev; return true; }
                }
            }
            l3 = (l3 + INT64_C(1));
        }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

bool vader_core_types$is_void(vader_box_t l0) {
    void* t0;
    vader_string_t t1;
    if (!(l0.tag == 915u)) {
        return false;
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
    return t1 == 3005u;
}

static void* vader_core_types$joined_ranges(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 0u) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_core_types$RangeType_t*) t0)->f_bounds;
    l3 = ((vader_struct_vader_core_types$RangeType_t*) l1)->f_bounds;
    l2 = vader_support_integer$interval_join(l2, l3);
    t0 = l0.payload.obj;
    l3 = ((vader_struct_vader_core_types$RangeType_t*) t0)->f_bounds;
    t1 = vader_support_integer$same_interval(l2, l3);
    if (t1) {
        t0 = l0.payload.obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_core_types$RangeType_t*) l1)->f_bounds;
    t1 = vader_support_integer$same_interval(l2, l3);
    if (!(t1)) {
        vader_struct_vader_core_types$RangeType_t* _a0_obj = (vader_struct_vader_core_types$RangeType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$RangeType_t));
        vader_obj_header_init(_a0_obj, 916u);
        _a0_obj->f_bounds = l2;
        _a0_obj->f_name = 0u;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$kept_type_argument(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    void** gc_raw_roots[2] = { &t1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_core_types$strip_distinct(l0);
    if ((l1.tag == 906u || l1.tag == 915u)) {
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_types$is_machine_integer(l1);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = l1.payload.obj;
    t2 = vader_core_types$range_representation(t1);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_core_types$laid_out_alike(vader_box_t l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$integer_values(l0);
    if (t0.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = vader_core_types$integer_values(l1);
    if (!(t0.tag == 0u)) {
        l2 = vader_core_types$erase_ranges(l0);
        l3 = vader_core_types$erase_ranges(l1);
        t1 = vader_core_types$equals_type(l2, l3);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return true; }
}

vader_box_t vader_core_types$laid_out_unions(vader_box_t l0) {
    vader_box_t l1 = vader_box_null(), l3 = vader_box_null();
    void* l2 = NULL;
    void* l4 = NULL;
    bool t0;
    void* t1 = NULL;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l1, &l3, &t3 };
    void** gc_raw_roots[4] = { &l2, &l4, &t1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$holds_refinement_union(l0);
    if (!(t0)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 926u) {
        t1 = l0.payload.obj;
        t2 = vader_core_types$erase_ranges_each(((vader_struct_vader_core_types$UnionType_t*) t1)->f_variants);
        l1 = vader_core_types$union_of(t2);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 905u) {
        t1 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_types$DistinctType_t*) t1)->f_symbol;
        t1 = l0.payload.obj;
        l3 = vader_core_types$laid_out_unions(((vader_struct_vader_core_types$DistinctType_t*) t1)->f_backing);
        l1 = vader_core_types$mk_distinct(l2, l3);
    } else if (l0.tag == 918u) {
        t1 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_types$StructType_t*) t1)->f_symbol;
        t1 = l0.payload.obj;
        l4 = vader_core_types$laid_out_unions_each(((vader_struct_vader_core_types$StructType_t*) t1)->f_args);
        l1 = vader_core_types$mk_struct(l2, l4);
    } else if (l0.tag == 920u) {
        t1 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_types$TraitType_t*) t1)->f_symbol;
        t1 = l0.payload.obj;
        l4 = vader_core_types$laid_out_unions_each(((vader_struct_vader_core_types$TraitType_t*) t1)->f_args);
        vader_struct_vader_core_types$TraitType_t* _a0_obj = (vader_struct_vader_core_types$TraitType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$TraitType_t));
        vader_obj_header_init(_a0_obj, 920u);
        _a0_obj->f_symbol = l2;
        _a0_obj->f_args = l4;
        t1 = (void*) _a0_obj;
        l1 = vader_ref_box(t1);
    } else if (l0.tag == 904u) {
        t1 = l0.payload.obj;
        t3 = vader_core_types$laid_out_unions(((vader_struct_vader_core_types$ArrayType_t*) t1)->f_element);
        l1 = vader_core_types$mk_array(t3);
    } else if (l0.tag == 921u) {
        t1 = l0.payload.obj;
        t2 = vader_core_types$laid_out_unions_each(((vader_struct_vader_core_types$TupleType_t*) t1)->f_elements);
        l1 = vader_core_types$mk_tuple(t2);
    } else if (l0.tag == 907u) {
        l2 = l0.payload.obj;
        t1 = l0.payload.obj;
        l4 = vader_core_types$laid_out_unions_each(((vader_struct_vader_core_types$FnType_t*) t1)->f_params);
        t1 = l0.payload.obj;
        l3 = vader_core_types$laid_out_unions(((vader_struct_vader_core_types$FnType_t*) t1)->f_return_type);
        l2 = ((vader_struct_vader_core_types$FnType_t*) l2)->f_type_params;
        vader_struct_vader_core_types$FnType_t* _a1_obj = (vader_struct_vader_core_types$FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$FnType_t));
        vader_obj_header_init(_a1_obj, 907u);
        _a1_obj->f_params = l4;
        _a1_obj->f_return_type = l3;
        _a1_obj->f_type_params = l2;
        t1 = (void*) _a1_obj;
        l1 = vader_ref_box(t1);
    } else {
        if (!((l0.tag == 903u || l0.tag == 906u || l0.tag == 908u || l0.tag == 909u || l0.tag == 910u || l0.tag == 911u || l0.tag == 913u || l0.tag == 915u || l0.tag == 916u || l0.tag == 917u || l0.tag == 922u || l0.tag == 923u || l0.tag == 927u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = l0;
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_core_types$laid_out_unions_each(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    int64_t l2, l4;
    vader_box_t l5 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(251u, 0u, 13u, 1789u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l3 = l0;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = vader_core_types$laid_out_unions(t0);
        vader_array_push_ref((vader_array_t*) l1, l5.payload.obj);
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_core_types$leaked_infer_var(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$InferVar_t*) l0)->f_origin)->f_name;
    t0 = concat_3(1533u, l1, 1218u);
    vader_host_std_abort$panic(t0);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

bool vader_core_types$literal_family_holds(vader_box_t l0, vader_box_t l1) {
    bool l2;
    void* t0;
    vader_string_t t1;
    bool t2;
    if (l0.tag == 910u) {
        l2 = vader_core_types$is_machine_integer(l1);
        return l2;
    }
    if (l0.tag == 909u) {
        if (l1.tag == 915u) {
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
            l2 = vader_core_types$is_float_name(t1);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 908u) {
        t2 = vader_core_types$is_machine_integer(l1);
        if (t2) {
            l2 = true;
        } else {
            l2 = vader_core_types$is_char(l1);
        }
    } else {
        if (!((l0.tag == 903u || l0.tag == 904u || l0.tag == 905u || l0.tag == 906u || l0.tag == 907u || l0.tag == 911u || l0.tag == 913u || l0.tag == 915u || l0.tag == 916u || l0.tag == 917u || l0.tag == 918u || l0.tag == 920u || l0.tag == 921u || l0.tag == 922u || l0.tag == 923u || l0.tag == 926u || l0.tag == 927u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = false;
    }
    return l2;
}

static bool vader_core_types$literal_takes(vader_box_t l0, vader_box_t l1) {
    bool l2;
    bool t0;
    t0 = vader_core_types$literal_family_holds(l0, l1);
    if (t0) {
        return true;
    }
    if ((l0.tag == 908u || l0.tag == 910u)) {
        l2 = vader_core_types$is_refinement(l1);
    } else {
        l2 = false;
    }
    return l2;
}

void* vader_core_types$machine_integer_type(void* l0) {
    void* l1 = NULL;
    vader_string_t l2 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_support_integer$MachineInteger_t*) l0)->f_values;
    l2 = ((vader_struct_vader_support_integer$MachineInteger_t*) l0)->f_name;
    vader_struct_vader_core_types$RangeType_t* _a0_obj = (vader_struct_vader_core_types$RangeType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$RangeType_t));
    vader_obj_header_init(_a0_obj, 916u);
    _a0_obj->f_bounds = l1;
    _a0_obj->f_name = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_types$mangle_module_id(vader_string_t l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    uint8_t l4;
    bool t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(25u, 0u, 1u, 340u);
    l1 = (void*) _a0_arr;
    l2 = vader_host_std_core$byte_len(l0);
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l2 = INT64_C(0);
    l3 = vader_host_std_core$byte_len(l0);
    while ((l2 < l3)) {
        l4 = vader_host_std_core$byte_at(l0, l2);
        if (l4 == INT32_C(95)) {
            vader_array_push_u8((vader_array_t*) l1, INT32_C(95));
            vader_array_push_u8((vader_array_t*) l1, INT32_C(95));
        } else {
            t0 = vader_support_text$is_ident_byte(l4);
            if (t0) {
                vader_array_push_u8((vader_array_t*) l1, (int32_t) (uint8_t) l4);
            } else {
                vader_array_push_u8((vader_array_t*) l1, INT32_C(95));
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    t1 = vader_host_std_core$bytes_to_string(l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_core_types$mentions_infer_var(vader_box_t l0, int32_t l1) {
    bool t0;
    t0 = vader_core_types$holds_infer_var(l0, l1);
    return t0;
}

vader_box_t vader_core_types$mk_array(vader_box_t l0) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_types$ArrayType_t* _a0_obj = (vader_struct_vader_core_types$ArrayType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$ArrayType_t));
    vader_obj_header_init(_a0_obj, 904u);
    _a0_obj->f_element = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$mk_distinct(void* l0, vader_box_t l1) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_types$DistinctType_t* _a0_obj = (vader_struct_vader_core_types$DistinctType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$DistinctType_t));
    vader_obj_header_init(_a0_obj, 905u);
    _a0_obj->f_symbol = l0;
    _a0_obj->f_backing = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_core_types$mk_fn(void* l0, vader_box_t l1, void* l2) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_types$FnType_t* _a0_obj = (vader_struct_vader_core_types$FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$FnType_t));
    vader_obj_header_init(_a0_obj, 907u);
    _a0_obj->f_params = l0;
    _a0_obj->f_return_type = l1;
    _a0_obj->f_type_params = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_core_types$mk_fn_drop_self(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    int64_t l2;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_types$FnType_t*) l0)->f_params;
    l2 = ((vader_array_t*) ((vader_struct_vader_core_types$FnType_t*) l0)->f_params)->length;
    vader_array_t* _a0_arr = vader_array_slice((vader_array_t*) l1, (int64_t) INT64_C(1), (int64_t) l2);
    l1 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_core_types$FnType_t*) l0)->f_return_type;
    l4 = ((vader_struct_vader_core_types$FnType_t*) l0)->f_type_params;
    vader_struct_vader_core_types$FnType_t* _a1_obj = (vader_struct_vader_core_types$FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$FnType_t));
    vader_obj_header_init(_a1_obj, 907u);
    _a1_obj->f_params = l1;
    _a1_obj->f_return_type = l3;
    _a1_obj->f_type_params = l4;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$mk_primitive(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_support_integer$machine_integer_named(l0);
    if (l1.tag == 0u) {
        vader_struct_vader_core_types$PrimitiveType_t* _a0_obj = (vader_struct_vader_core_types$PrimitiveType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$PrimitiveType_t));
        vader_obj_header_init(_a0_obj, 915u);
        _a0_obj->f_name = l0;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    t1 = vader_core_types$machine_integer_type(t0);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$mk_struct(void* l0, void* l1) {
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_types$StructType_t* _a0_obj = (vader_struct_vader_core_types$StructType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$StructType_t));
    vader_obj_header_init(_a0_obj, 918u);
    _a0_obj->f_symbol = l0;
    _a0_obj->f_args = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$mk_trait(void* l0, void* l1) {
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_types$TraitType_t* _a0_obj = (vader_struct_vader_core_types$TraitType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$TraitType_t));
    vader_obj_header_init(_a0_obj, 920u);
    _a0_obj->f_symbol = l0;
    _a0_obj->f_args = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$mk_tuple(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_types$TupleType_t* _a0_obj = (vader_struct_vader_core_types$TupleType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$TupleType_t));
    vader_obj_header_init(_a0_obj, 921u);
    _a0_obj->f_elements = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$mk_type_param(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_types$TypeParamType_t* _a0_obj = (vader_struct_vader_core_types$TypeParamType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$TypeParamType_t));
    vader_obj_header_init(_a0_obj, 923u);
    _a0_obj->f_symbol = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$mk_union(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_types$UnionType_t* _a0_obj = (vader_struct_vader_core_types$UnionType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$UnionType_t));
    vader_obj_header_init(_a0_obj, 926u);
    _a0_obj->f_variants = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$narrow_for_expected(vader_box_t l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[3] = { &l0, &l1, &l3 };
    void** gc_raw_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 926u) {
        l2 = l1.payload.obj;
        l3 = vader_core_types$union_literal_member(l0, l2);
        if (l3.tag == 0u) {
            { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 0u) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l1;
    t0 = vader_core_types$literal_takes(l0, l3);
    if (t0) {
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_core_types$narrowest_integer(void* l0) {
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_support_integer$narrowest_machine_integer(l0);
    t1 = vader_core_types$machine_integer_type(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_core_types$new_substitution(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 0u, 346u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 467u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_vader_core_types$Substitution_t* _a4_obj = (vader_struct_vader_core_types$Substitution_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$Substitution_t));
    vader_obj_header_init(_a4_obj, 919u);
    _a4_obj->f_type_params = t0;
    _a4_obj->f_self_type = vader_box_obj(0u, NULL);
    _a4_obj->f_binds_refinement = false;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_core_types$nominal_eq(int32_t l0, void* l1, int32_t l2, void* l3) {
    bool t0;
    if (!(l0 != l2)) {
        t0 = vader_core_types$type_list_equals(l1, l3);
        return t0;
    }
    return false;
}

static vader_string_t vader_core_types$nominal_name(void* l0, bool l1) {
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l1)) {
        t0 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_types$qualified_symbol_name(l0);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_types$open_or(bool l0, int64_t l1) {
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
        l2 = (void*) vader_buffer_new((size_t) INT64_C(20));
        l3 = INT64_C(0);
        l3 = std_core$write_int(l2, l3, l1);
        t0 = std_core$finish_buffer(l2, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
}

void* vader_core_types$param_types_of(vader_box_t l0) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 907u)) {
        vader_array_t* _a0_arr = vader_array_new(251u, 0u, 13u, 1789u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    { void* __vret = ((vader_struct_vader_core_types$FnType_t*) t0)->f_params; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$primitive_from_name(vader_string_t l0) {
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0 == 2743u) {
        t0 = (void*) &vader_data_30;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == 797u) {
        t0 = (void*) &vader_data_31;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_core_types$primitive_meta(l0);
    if (!(t1.tag == 0u)) {
        t1 = vader_core_types$mk_primitive(l0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_core_types$primitive_meta(vader_string_t l0) {
    void* l1;
    void* l4;
    int64_t l2, l3;
    vader_string_t t0;
    l1 = (void*) &vader_data_24;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_vader_core_types$PrimitiveMeta_t*) l4)->f_name;
        if (t0 == l0) {
            return vader_ref_box(l4);
        }
        l3 = (l3 + INT64_C(1));
    }
    return vader_box_obj(0u, NULL);
}

vader_string_t vader_core_types$primitive_name(vader_box_t l0) {
    void* t0;
    vader_string_t t1;
    if (l0.tag == 915u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        return t1;
    }
    if (!(l0.tag == 916u)) {
        return 0u;
    }
    t0 = l0.payload.obj;
    t1 = vader_support_integer$machine_integer_name(((vader_struct_vader_core_types$RangeType_t*) t0)->f_bounds);
    return t1;
}

int64_t vader_core_types$primitive_size(vader_string_t l0) {
    vader_box_t l1;
    void* l2;
    void* t0;
    int64_t t1, t2;
    l1 = vader_support_integer$machine_integer_named(l0);
    if (!(l1.tag == 0u)) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_support_integer$MachineInteger_t*) t0)->f_bits;
        t2 = vader_div_i64(t1, INT64_C(8));
        return t2;
    }
    l1 = vader_core_types$primitive_meta(l0);
    if (l1.tag == 0u) {
        return INT64_C(0);
    }
    l2 = l1.payload.obj;
    t1 = ((vader_struct_vader_core_types$PrimitiveMeta_t*) l2)->f_size;
    return t1;
}

vader_string_t vader_core_types$qualified_display_type(vader_box_t l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 915u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 903u) {
        { vader_gc_top = gc_frame.prev; return 579u; }
    }
    if ((l0.tag == 905u || l0.tag == 906u)) {
        t1 = vader_core_types$qualified_symbol_name(VADER_UNION_FIELD(void*, vader_struct_vader_core_types$DistinctType_t, f_symbol, l0.payload.obj));
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        t2 = ((vader_array_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_args)->length;
        if (t2 == INT64_C(0)) {
            t0 = l0.payload.obj;
            t1 = vader_core_types$qualified_symbol_name(((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol);
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 626u);
    _a1_obj->f_parts = t0;
    t0 = (void*) _a1_obj;
    vader_struct_vader_core_types$TypeWriter_t* _a2_obj = (vader_struct_vader_core_types$TypeWriter_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$TypeWriter_t));
    vader_obj_header_init(_a2_obj, 924u);
    _a2_obj->f_sb = t0;
    _a2_obj->f_qualified = true;
    _a2_obj->f_names = vader_box_obj(0u, NULL);
    l1 = (void*) _a2_obj;
    vader_core_types$write_type(l1, l0);
    t1 = std_string__builder$StringBuilder$std_core$Display$to_string(((vader_struct_vader_core_types$TypeWriter_t*) l1)->f_sb);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_types$qualified_symbol_name(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_module_name;
    l1 = vader_core_types$mangle_module_id(t0);
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
    t0 = concat_3(l1, 259u, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_types$range_key(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_support_integer$machine_integer_name(((vader_struct_vader_core_types$RangeType_t*) l0)->f_bounds);
    if (!(l1 != 0u)) {
        l2 = vader_core_types$display_bounds(((vader_struct_vader_core_types$RangeType_t*) l0)->f_bounds);
        t0 = concat_2(2480u, l2);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = concat_2(2442u, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_core_types$range_representation(void* l0) {
    void* t0;
    t0 = vader_core_types$narrowest_integer(((vader_struct_vader_core_types$RangeType_t*) l0)->f_bounds);
    return t0;
}

vader_box_t vader_core_types$refinement_of(vader_box_t l0) {
    void* t0;
    bool t1;
    if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$is_machine_range(t0);
        if (!(t1)) {
            t0 = l0.payload.obj;
            return vader_ref_box(t0);
        }
        return vader_box_obj(0u, NULL);
    }
    return vader_box_obj(0u, NULL);
}

static bool vader_core_types$removed_covers(vader_box_t l0, vader_box_t l1) {
    void* l2;
    int64_t l3, l4;
    bool t0;
    void* t1;
    vader_box_t t2;
    if (!(l0.tag == 926u)) {
        t0 = vader_core_types$equals_type(l0, l1);
        return t0;
    }
    t1 = l0.payload.obj;
    l2 = ((vader_struct_vader_core_types$UnionType_t*) t1)->f_variants;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = vader_core_types$equals_type(t2, l1);
        if (t0) {
            return true;
        }
        l4 = (l4 + INT64_C(1));
    }
    return false;
}

vader_string_t vader_core_types$representation_name(vader_box_t l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 906u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_support_integer$MachineInteger_t*) ((vader_struct_vader_core_types$EnumType_t*) t0)->f_repr)->f_name;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_core_types$integer_representation(l0);
    if (l2.tag == 0u) {
        t1 = vader_core_types$display_type(l0);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l2.payload.obj;
    t1 = ((vader_struct_vader_support_integer$MachineInteger_t*) l1)->f_name;
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_core_types$same_variant(vader_box_t l0, vader_box_t l1) {
    bool l2, l3;
    bool t0;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$equals_type(l0, l1);
    if (t0) {
        l2 = true;
    } else {
        t0 = vader_core_types$is_free_numeric(l0);
        if (t0) {
            l3 = vader_core_types$is_assignable(l0, l1);
        } else {
            l3 = false;
        }
        l2 = l3;
    }
    if (l2) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = vader_core_types$is_free_numeric(l1);
    if (t0) {
        l2 = vader_core_types$is_assignable(l1, l0);
    } else {
        l2 = false;
    }
    { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$scalar_backing(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if ((l0.tag == 915u || l0.tag == 916u)) {
        return l0;
    }
    if (!(l0.tag == 905u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    t1 = vader_core_types$scalar_backing(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
    return t1;
}

int64_t vader_core_types$slot_byte_align(vader_box_t l0) {
    int64_t l1;
    l1 = vader_core_types$slot_byte_size(l0);
    if (!((l1 > INT64_C(8)))) {
        return l1;
    }
    return INT64_C(8);
}

int64_t vader_core_types$slot_byte_size(vader_box_t l0) {
    int64_t l1;
    void* t0;
    void* t3;
    vader_string_t t1;
    int64_t t2;
    if (l0.tag == 915u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        l1 = vader_core_types$primitive_size(t1);
        return l1;
    }
    if (l0.tag == 906u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_support_integer$MachineInteger_t*) ((vader_struct_vader_core_types$EnumType_t*) t0)->f_repr)->f_bits;
        l1 = vader_div_i64(t2, INT64_C(8));
    } else if (l0.tag == 905u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$slot_byte_size(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        t3 = vader_core_types$storage_integer(t0);
        t2 = ((vader_struct_vader_support_integer$MachineInteger_t*) t3)->f_bits;
        l1 = vader_div_i64(t2, INT64_C(8));
    } else if ((l0.tag == 904u || l0.tag == 907u || l0.tag == 918u || l0.tag == 921u)) {
        l1 = INT64_C(8);
    } else if ((l0.tag == 903u || l0.tag == 920u || l0.tag == 926u)) {
        l1 = INT64_C(16);
    } else {
        if (!((l0.tag == 908u || l0.tag == 909u || l0.tag == 910u || l0.tag == 911u || l0.tag == 913u || l0.tag == 917u || l0.tag == 922u || l0.tag == 923u || l0.tag == 927u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = INT64_C(0);
    }
    return l1;
}

static void* vader_core_types$sort_by_display_key(void* l0) {
    vader_box_t l1 = vader_box_null(), l3 = vader_box_null();
    vader_string_t l2 = 0;
    vader_string_t l4 = 0;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    int64_t l6, l8, l10;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    bool t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l3, &t1 };
    void** gc_raw_roots[5] = { &l0, &l5, &l7, &l9, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l0)->length;
    if (t0 == INT64_C(2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(1));
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(1));
        l2 = vader_core_types$display_type(t1);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
        t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
        l4 = vader_core_types$display_type(t1);
        t2 = vader_core_types$comes_before(l1, l2, l3, l4);
        if (!(t2)) {
            { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(1));
        l3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(0));
        vader_array_t* _a3_arr = vader_array_new(251u, 2u, 13u, 1789u);
        ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 1u] = l3.payload.obj;
        ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = l1.payload.obj;
        t3 = (void*) _a3_arr;
        { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 0u, 335u);
    l5 = (void*) _a4_arr;
    l6 = ((vader_array_t*) l0)->length;
    vader_array_t* _a5_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l6);
    l5 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(24u, 0u, 8u, 339u);
    l7 = (void*) _a6_arr;
    l6 = ((vader_array_t*) l0)->length;
    vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) l7, (int64_t) l6);
    l7 = (void*) _a7_arr;
    l6 = INT64_C(0);
    l8 = ((vader_array_t*) l0)->length;
    while ((l6 < l8)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        t1 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l6);
        l2 = vader_core_types$display_type(t1);
        vader_array_push_scalar((vader_array_t*) l5, vader_box_string(335u, l2));
        vader_array_push_i64((vader_array_t*) l7, l6);
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a9_arr = vader_array_new(251u, 0u, 13u, 1789u);
    l9 = (void*) _a9_arr;
    vader_struct___lambda_env_vader_core_types_1_t* _a10_obj = (vader_struct___lambda_env_vader_core_types_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_core_types_1_t));
    vader_obj_header_init(_a10_obj, 359u);
    _a10_obj->f_cap_0 = l0;
    _a10_obj->f_cap_1 = l5;
    t3 = (void*) _a10_obj;
    vader_fn_t* _a11_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a11_closure, 311u);
    _a11_closure->code = (void*) &vader_fn_lift___lambda_vader_core_types_0;
    _a11_closure->env = t3;
    l5 = (void*) _a11_closure;
    l5 = std_sort$sort__i64(l7, l5);
    l6 = ((vader_array_t*) l5)->length;
    l8 = INT64_C(0);
    while ((l8 < l6)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        l10 = ((int64_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l8];
        vader_array_t* _a13_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l10)
        l1 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l10);
        vader_array_push_ref((vader_array_t*) l9, l1.payload.obj);
        l8 = (l8 + INT64_C(1));
    }
    { void* __vret = l9; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_core_types$storage_integer(void* l0) {
    void* t0;
    t0 = vader_support_integer$narrowest_machine_integer(((vader_struct_vader_core_types$RangeType_t*) l0)->f_bounds);
    return t0;
}

vader_box_t vader_core_types$strip_distinct(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    void* t4 = NULL;
    vader_box_t t2 = vader_box_null(), t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l3, &t2, &t3 };
    void** gc_raw_roots[4] = { &l1, &l2, &t1, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if ((l0.tag == 915u || l0.tag == 916u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_types$contains_distinct(l0);
    if (!(t0)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 905u) {
        t1 = l0.payload.obj;
        t2 = vader_core_types$strip_distinct(((vader_struct_vader_core_types$DistinctType_t*) t1)->f_backing);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 918u) {
        t1 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_types$StructType_t*) t1)->f_symbol;
        t1 = l0.payload.obj;
        l2 = vader_core_types$strip_distinct_each(((vader_struct_vader_core_types$StructType_t*) t1)->f_args);
        t2 = vader_core_types$mk_struct(l1, l2);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 920u) {
        t1 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_types$TraitType_t*) t1)->f_symbol;
        t1 = l0.payload.obj;
        l2 = vader_core_types$strip_distinct_each(((vader_struct_vader_core_types$TraitType_t*) t1)->f_args);
        vader_struct_vader_core_types$TraitType_t* _a0_obj = (vader_struct_vader_core_types$TraitType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$TraitType_t));
        vader_obj_header_init(_a0_obj, 920u);
        _a0_obj->f_symbol = l1;
        _a0_obj->f_args = l2;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 904u) {
        t1 = l0.payload.obj;
        t2 = vader_core_types$strip_distinct(((vader_struct_vader_core_types$ArrayType_t*) t1)->f_element);
        t3 = vader_core_types$mk_array(t2);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 921u) {
        t1 = l0.payload.obj;
        t4 = vader_core_types$strip_distinct_each(((vader_struct_vader_core_types$TupleType_t*) t1)->f_elements);
        t2 = vader_core_types$mk_tuple(t4);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 907u) {
        t1 = l0.payload.obj;
        l1 = vader_core_types$strip_distinct_each(((vader_struct_vader_core_types$FnType_t*) t1)->f_params);
        t1 = l0.payload.obj;
        l3 = vader_core_types$strip_distinct(((vader_struct_vader_core_types$FnType_t*) t1)->f_return_type);
        vader_array_t* _a1_arr = vader_array_new(85u, 0u, 13u, 923u);
        l2 = (void*) _a1_arr;
        t1 = vader_core_types$mk_fn(l1, l3, l2);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 926u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l0.payload.obj;
    t4 = vader_core_types$strip_distinct_each(((vader_struct_vader_core_types$UnionType_t*) t1)->f_variants);
    t2 = vader_core_types$mk_union(t4);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_core_types$strip_distinct_each(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    int64_t l2, l4;
    vader_box_t l5 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(251u, 0u, 13u, 1789u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l3 = l0;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = vader_core_types$strip_distinct(t0);
        vader_array_push_ref((vader_array_t*) l1, l5.payload.obj);
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_core_types$struct_args_compatible(void* l0, void* l1) {
    int64_t l2, l3;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[6] = { &l4, &l5, &l6, &l7, &l8, &l9 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
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
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        t0 = vader_core_types$equals_type(l4, l5);
        if (t0) {
            l2 = (l2 + INT64_C(1));
            continue;
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l2)
        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l2);
        t0 = vader_core_types$fn_param_compatible(l6, l7);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l2)
        l8 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l2);
        vader_array_t* _a5_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l2)
        l9 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l2);
        t0 = vader_core_types$fn_param_compatible(l8, l9);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l2 = (l2 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return true; }
}

vader_box_t vader_core_types$struct_backing(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        return vader_ref_box(t0);
    }
    if (!(l0.tag == 905u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    t1 = vader_core_types$struct_backing(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
    return t1;
}

vader_box_t vader_core_types$substitute(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l3, &t1 };
    void** gc_raw_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$is_empty_substitution(l1);
    if (!(t0)) {
        l2 = ((vader_struct_vader_core_types$Substitution_t*) l1)->f_type_params;
        l3 = ((vader_struct_vader_core_types$Substitution_t*) l1)->f_self_type;
        t1 = vader_core_types$substitute_in(l0, vader_ref_box(l2), l3);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_core_types$substitute_each_in(void* l0, vader_box_t l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    int64_t l4, l6;
    vader_box_t l7 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l1, &l2, &l7, &t0 };
    void** gc_raw_roots[3] = { &l0, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(251u, 0u, 13u, 1789u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    l5 = l0;
    l4 = ((vader_array_t*) l5)->length;
    l6 = INT64_C(0);
    while ((l6 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        l7 = vader_core_types$substitute_in(t0, l1, l2);
        vader_array_push_ref((vader_array_t*) l3, l7.payload.obj);
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_core_types$substitute_each_map(void* l0, void* l1) {
    void* t0;
    t0 = vader_core_types$substitute_each_in(l0, vader_ref_box(l1), vader_box_obj(0u, NULL));
    return t0;
}

static void* vader_core_types$substitute_fn_in(void* l0, vader_box_t l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l2, &l4 };
    void** gc_raw_roots[4] = { &l0, &l3, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_core_types$substitute_each_in(((vader_struct_vader_core_types$FnType_t*) l0)->f_params, l1, l2);
    l4 = vader_core_types$substitute_in(((vader_struct_vader_core_types$FnType_t*) l0)->f_return_type, l1, l2);
    l5 = vader_core_types$unbound_quantifier(((vader_struct_vader_core_types$FnType_t*) l0)->f_type_params, l1);
    vader_struct_vader_core_types$FnType_t* _a0_obj = (vader_struct_vader_core_types$FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$FnType_t));
    vader_obj_header_init(_a0_obj, 907u);
    _a0_obj->f_params = l3;
    _a0_obj->f_return_type = l4;
    _a0_obj->f_type_params = l5;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_core_types$substitute_fn_map(void* l0, void* l1) {
    void* t0;
    t0 = vader_core_types$substitute_fn_in(l0, vader_ref_box(l1), vader_box_obj(0u, NULL));
    return t0;
}

static vader_box_t vader_core_types$substitute_in(vader_box_t l0, vader_box_t l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* l5 = NULL;
    void* l6 = NULL;
    void* t0 = NULL;
    void* t2 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t1 };
    void** gc_raw_roots[4] = { &l5, &l6, &t0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 6u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 923u) {
        t0 = l0.payload.obj;
        l3 = vader_core_types$binding_of(t0, l1);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 917u) {
        l4 = l2;
        if (l4.tag == 0u) {
            t0 = l0.payload.obj;
            l3 = vader_ref_box(t0);
        } else {
            l3 = l4;
        }
    } else if (l0.tag == 904u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$substitute_in(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element, l1, l2);
        l3 = vader_core_types$mk_array(t1);
    } else if (l0.tag == 921u) {
        t0 = l0.payload.obj;
        t2 = vader_core_types$substitute_each_in(((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements, l1, l2);
        l3 = vader_core_types$mk_tuple(t2);
    } else if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol;
        t0 = l0.payload.obj;
        l6 = vader_core_types$substitute_each_in(((vader_struct_vader_core_types$StructType_t*) t0)->f_args, l1, l2);
        l3 = vader_core_types$mk_struct(l5, l6);
    } else if (l0.tag == 920u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_core_types$TraitType_t*) t0)->f_symbol;
        t0 = l0.payload.obj;
        l6 = vader_core_types$substitute_each_in(((vader_struct_vader_core_types$TraitType_t*) t0)->f_args, l1, l2);
        vader_struct_vader_core_types$TraitType_t* _a0_obj = (vader_struct_vader_core_types$TraitType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$TraitType_t));
        vader_obj_header_init(_a0_obj, 920u);
        _a0_obj->f_symbol = l5;
        _a0_obj->f_args = l6;
        t0 = (void*) _a0_obj;
        l3 = vader_ref_box(t0);
    } else if (l0.tag == 907u) {
        t0 = l0.payload.obj;
        t2 = vader_core_types$substitute_fn_in(t0, l1, l2);
        l3 = vader_ref_box(t2);
    } else if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        t2 = vader_core_types$substitute_each_in(((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants, l1, l2);
        l3 = vader_core_types$union_of(t2);
    } else {
        l3 = l0;
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$substitute_map(vader_box_t l0, void* l1) {
    vader_box_t t0;
    t0 = vader_core_types$substitute_in(l0, vader_ref_box(l1), vader_box_obj(0u, NULL));
    return t0;
}

vader_box_t vader_core_types$substitute_self(vader_box_t l0, vader_box_t l1) {
    vader_box_t t0;
    t0 = vader_core_types$substitute_in(l0, vader_box_obj(0u, NULL), l1);
    return t0;
}

vader_box_t vader_core_types$subtract_type(vader_box_t l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l1, &l6, &t3 };
    void** gc_raw_roots[3] = { &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 926u) {
        vader_array_t* _a0_arr = vader_array_new(251u, 0u, 13u, 1789u);
        l2 = (void*) _a0_arr;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            t1 = vader_core_types$removed_covers(l1, l6);
            if (!(t1)) {
                vader_array_push_ref((vader_array_t*) l2, l6.payload.obj);
            }
            l5 = (l5 + INT64_C(1));
        }
        t2 = ((vader_array_t*) l2)->length;
        if (t2 == INT64_C(0)) {
            t0 = (void*) &vader_data_33;
            vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = ((vader_array_t*) l2)->length;
        if (!(t2 == INT64_C(1))) {
            t3 = vader_core_types$mk_union(l2);
            { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t3 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT32_C(0));
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l0;
    t1 = vader_core_types$removed_covers(l1, l6);
    if (!(t1)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = (void*) &vader_data_33;
    vader_array_t* _a4_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    t0 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) INT64_C(0));
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_types$trait_key_name(vader_string_t l0) {
    int64_t l1, l2;
    uint8_t t0;
    vader_string_t t1;
    l1 = vader_host_std_core$byte_len(l0);
    while ((l1 > INT64_C(0))) {
        l2 = vader_chk_sub(i64, l1, INT64_C(1));
        t0 = vader_host_std_core$byte_at(l0, l2);
        if (!(t0 != INT32_C(36))) {
            break;
        }
        l1 = vader_chk_sub(i64, l1, INT64_C(1));
    }
    l2 = vader_host_std_core$byte_len(l0);
    t1 = vader_host_std_core$byte_slice(l0, l1, l2);
    return t1;
}

vader_string_t vader_core_types$trait_key_of(void* l0) {
    vader_string_t t0;
    t0 = vader_core_types$qualified_symbol_name(l0);
    return t0;
}

vader_box_t vader_core_types$tuple_backing(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 921u) {
        t0 = l0.payload.obj;
        return vader_ref_box(t0);
    }
    if (!(l0.tag == 905u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    t1 = vader_core_types$tuple_backing(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
    return t1;
}

void* vader_core_types$type_arguments(vader_box_t l0) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        { void* __vret = ((vader_struct_vader_core_types$StructType_t*) t0)->f_args; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 904u)) {
        vader_array_t* _a0_arr = vader_array_new(251u, 0u, 13u, 1789u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    vader_array_t* _a1_arr = vader_array_new(251u, 1u, 13u, 1789u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = ((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element.payload.obj;
    t0 = (void*) _a1_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$type_bounds(vader_box_t l0) {
    bool t0;
    void* t1 = NULL;
    void* t3 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t2 };
    void** gc_raw_roots[2] = { &t1, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$is_char(l0);
    if (t0) {
        t1 = (void*) &vader_data_34;
        t2 = vader_core_types$interval_hull(t1);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 906u) {
        t1 = l0.payload.obj;
        if (((vader_struct_vader_core_types$EnumType_t*) t1)->f_data.tag == 0u) {
            t1 = l0.payload.obj;
            t3 = vader_core_types$enum_value_runs(t1);
            t2 = vader_core_types$interval_hull(t3);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = vader_core_types$integer_values(l0);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_core_types$integer_values(l0);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_core_types$type_contains_infer_var(vader_box_t l0) {
    bool t0;
    t0 = vader_core_types$holds_infer_var(l0, INT32_C(-1));
    return t0;
}

bool vader_core_types$type_contains_type_param(vader_box_t l0) {
    bool l1;
    void* t0;
    bool t1;
    if ((l0.tag == 911u || l0.tag == 923u)) {
        l1 = true;
        return l1;
    }
    if (l0.tag == 904u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$type_contains_type_param(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element);
    } else if (l0.tag == 921u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$any_contains_type_param(((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements);
    } else if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$any_contains_type_param(((vader_struct_vader_core_types$StructType_t*) t0)->f_args);
    } else if (l0.tag == 920u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$any_contains_type_param(((vader_struct_vader_core_types$TraitType_t*) t0)->f_args);
    } else if (l0.tag == 907u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$any_contains_type_param(((vader_struct_vader_core_types$FnType_t*) t0)->f_params);
        if (t1) {
            l1 = true;
        } else {
            t0 = l0.payload.obj;
            l1 = vader_core_types$type_contains_type_param(((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type);
        }
    } else if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$any_contains_type_param(((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants);
    } else {
        l1 = false;
    }
    return l1;
}

bool vader_core_types$type_contains_unresolved(vader_box_t l0) {
    void* l1;
    int64_t l2, l3;
    void* t0;
    bool t1;
    vader_box_t t2;
    if (l0.tag == 927u) {
        return true;
    }
    if (l0.tag == 904u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$type_contains_unresolved(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element);
        return t1;
    }
    if (l0.tag == 921u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements;
        l2 = ((vader_array_t*) l1)->length;
        l3 = INT64_C(0);
        while ((l3 < l2)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            t1 = vader_core_types$type_contains_unresolved(t2);
            if (t1) {
                return true;
            }
            l3 = (l3 + INT64_C(1));
        }
        return false;
    }
    if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_args;
        l2 = ((vader_array_t*) l1)->length;
        l3 = INT64_C(0);
        while ((l3 < l2)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
            t1 = vader_core_types$type_contains_unresolved(t2);
            if (t1) {
                return true;
            }
            l3 = (l3 + INT64_C(1));
        }
        return false;
    }
    if (l0.tag == 920u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_types$TraitType_t*) t0)->f_args;
        l2 = ((vader_array_t*) l1)->length;
        l3 = INT64_C(0);
        while ((l3 < l2)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3);
            t1 = vader_core_types$type_contains_unresolved(t2);
            if (t1) {
                return true;
            }
            l3 = (l3 + INT64_C(1));
        }
        return false;
    }
    if (l0.tag == 907u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_params;
        l2 = ((vader_array_t*) l1)->length;
        l3 = INT64_C(0);
        while ((l3 < l2)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t2 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l3);
            t1 = vader_core_types$type_contains_unresolved(t2);
            if (t1) {
                return true;
            }
            l3 = (l3 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        t1 = vader_core_types$type_contains_unresolved(((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type);
        return t1;
    }
    if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
        l2 = ((vader_array_t*) l1)->length;
        l3 = INT64_C(0);
        while ((l3 < l2)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t2 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l3);
            t1 = vader_core_types$type_contains_unresolved(t2);
            if (t1) {
                return true;
            }
            l3 = (l3 + INT64_C(1));
        }
        return false;
    }
    if (!(l0.tag == 905u)) {
        return false;
    }
    t0 = l0.payload.obj;
    t1 = vader_core_types$type_contains_unresolved(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
    return t1;
}

bool vader_core_types$type_list_equals(void* l0, void* l1) {
    int64_t l2, l3;
    vader_box_t l4, l5;
    bool t0;
    l2 = ((vader_array_t*) l0)->length;
    l3 = ((vader_array_t*) l1)->length;
    if (l2 != l3) {
        return false;
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
        t0 = vader_core_types$equals_type(l4, l5);
        if (!(t0)) {
            return false;
        }
        l2 = (l2 + INT64_C(1));
    }
    return true;
}

vader_box_t vader_core_types$type_to_target_symbol(vader_box_t l0) {
    void* t0;
    if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        return vader_ref_box(((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol);
    }
    if (l0.tag == 906u) {
        t0 = l0.payload.obj;
        return vader_ref_box(((vader_struct_vader_core_types$EnumType_t*) t0)->f_symbol);
    }
    if (!(l0.tag == 905u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    return vader_ref_box(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_symbol);
}

bool vader_core_types$types_overlap(vader_box_t l0, vader_box_t l1) {
    vader_box_t l2, l6;
    void* l3;
    int64_t l4, l5;
    bool t0;
    vader_box_t t1;
    l2 = vader_core_types$union_variants(l0);
    if (l2.tag == 0u) {
        l6 = vader_core_types$union_variants(l1);
        if (l6.tag == 0u) {
            t0 = vader_core_types$equals_type(l0, l1);
            return t0;
        }
        l3 = l6.payload.obj;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            t0 = vader_core_types$types_overlap(l0, l6);
            if (t0) {
                return true;
            }
            l5 = (l5 + INT64_C(1));
        }
        return false;
    }
    l3 = l2.payload.obj;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t0 = vader_core_types$types_overlap(t1, l1);
        if (t0) {
            return true;
        }
        l5 = (l5 + INT64_C(1));
    }
    return false;
}

static void* vader_core_types$unbound_quantifier(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t l4, l5;
    int32_t l8;
    bool t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l6, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 0u) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l1.payload.obj;
    t0 = vader_core_types$binds_any(l0, l2);
    if (t0) {
        vader_array_t* _a0_arr = vader_array_new(85u, 0u, 13u, 923u);
        l2 = (void*) _a0_arr;
        l3 = l0;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            l7 = l1.payload.obj;
            l8 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) l6)->f_symbol)->f_id;
            t0 = std_collections$MutableMap$std_core$Contains$contains__i32__Any(l7, l8);
            if (!(t0)) {
                vader_array_push_ref((vader_array_t*) l2, l6);
            }
            l5 = (l5 + INT64_C(1));
        }
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_core_types$unify_args(void* l0, void* l1, void* l2) {
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &l6 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) l0)->length;
    l4 = ((vader_array_t*) l1)->length;
    l3 = std_math$min_3(l3, l4);
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        vader_core_types$unify_type_param(l5, l6, l2);
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_core_types$unify_infer(vader_box_t l0, vader_box_t l1, void* l2, vader_box_t l3) {
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    int64_t l6, l7;
    int32_t l8, l9;
    void* l10 = NULL;
    void* l11 = NULL;
    bool l12;
    void* t0 = NULL;
    vader_box_t* gc_roots[5] = { &l0, &l1, &l3, &l4, &l5 };
    void** gc_raw_roots[4] = { &l2, &l10, &l11, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 911u) {
        t0 = l0.payload.obj;
        vader_core_types$bind_infer_var(t0, l1, l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 904u) {
        if (l1.tag == 904u) {
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element;
            vader_core_types$unify_infer(l4, l5, l2, l3);
        }
    } else if (l0.tag == 921u) {
        if (l1.tag == 921u) {
            t0 = l0.payload.obj;
            l6 = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements)->length;
            t0 = l1.payload.obj;
            l7 = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements)->length;
            if (l6 == l7) {
                l6 = INT64_C(0);
                t0 = l0.payload.obj;
                l7 = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements)->length;
                while ((l6 < l7)) {
                    t0 = l0.payload.obj;
                    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements);
                    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
                    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
                    t0 = l1.payload.obj;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements);
                    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
                    l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                    vader_core_types$unify_infer(l4, l5, l2, l3);
                    l6 = (l6 + INT64_C(1));
                }
            }
        }
    } else if (l0.tag == 918u) {
        if (l1.tag == 918u) {
            t0 = l0.payload.obj;
            l8 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_id;
            t0 = l1.payload.obj;
            l9 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_id;
            if (l8 == l9) {
                t0 = l0.payload.obj;
                l10 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_args;
                t0 = l1.payload.obj;
                l11 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_args;
                vader_core_types$unify_infer_each(l10, l11, l2, l3);
            }
        }
    } else if (l0.tag == 920u) {
        if (l1.tag == 920u) {
            t0 = l0.payload.obj;
            l8 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TraitType_t*) t0)->f_symbol)->f_id;
            t0 = l1.payload.obj;
            l9 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TraitType_t*) t0)->f_symbol)->f_id;
            l12 = l8 == l9;
        } else {
            l12 = false;
        }
        if (l12) {
            t0 = l0.payload.obj;
            l10 = ((vader_struct_vader_core_types$TraitType_t*) t0)->f_args;
            t0 = l1.payload.obj;
            l11 = ((vader_struct_vader_core_types$TraitType_t*) t0)->f_args;
            vader_core_types$unify_infer_each(l10, l11, l2, l3);
        } else if (l1.tag == 904u) {
            t0 = l0.payload.obj;
            l4 = vader_core_types$core_trait_arg(vader_ref_box(t0), 690u);
            if (!(l4.tag == 0u)) {
                t0 = l1.payload.obj;
                l5 = ((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element;
                vader_core_types$unify_infer(l4, l5, l2, l3);
            }
        }
    } else if (l0.tag == 907u) {
        if (l1.tag == 907u) {
            t0 = l0.payload.obj;
            l10 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_params;
            t0 = l1.payload.obj;
            l11 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_params;
            vader_core_types$unify_infer_each(l10, l11, l2, l3);
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type;
            vader_core_types$unify_infer(l4, l5, l2, l3);
        }
    } else if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        l10 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
        l4 = vader_core_types$union_variants(l1);
        if (l4.tag == 0u) {
            vader_array_t* _a2_arr = vader_array_new(251u, 1u, 13u, 1789u);
            ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = l1.payload.obj;
            l11 = (void*) _a2_arr;
        } else {
            l11 = l4.payload.obj;
        }
        l10 = vader_core_types$union_leftovers(l10, l11);
        l6 = ((vader_array_t*) l10)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
            l11 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
            l4 = ((vader_struct_vader_core_types$UnionLeftover_t*) l11)->f_pattern;
            l5 = ((vader_struct_vader_core_types$UnionLeftover_t*) l11)->f_actual;
            vader_core_types$unify_infer(l4, l5, l2, l3);
            l7 = (l7 + INT64_C(1));
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_core_types$unify_infer_each(void* l0, void* l1, void* l2, vader_box_t l3) {
    int64_t l4, l5, l6;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &l7, &l8 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) l0)->length;
    l6 = ((vader_array_t*) l1)->length;
    l5 = std_math$min_3(l5, l6);
    while ((l4 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l8 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        vader_core_types$unify_infer(l7, l8, l2, l3);
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_core_types$unify_type_param(vader_box_t l0, vader_box_t l1, void* l2) {
    int32_t l3, l8;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    int64_t l6, l7;
    void* l9 = NULL;
    void* l10 = NULL;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l0, &l1, &l4, &l5, &t2 };
    void** gc_raw_roots[4] = { &l2, &l9, &l10, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 923u) {
        t0 = vader_core_types$type_contains_unresolved(l1);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        t1 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) t1)->f_symbol)->f_id;
        t2 = std_collections$get_or_put__i32__vader_core_types_AnyType___vader_core_types_ArrayType___vader_core_types_DistinctType___vader_core_types_EnumType___vader_core_types_FnType___vader_core_types_FreeCharType___vader_core_types_FreeFloatType___vader_core_types_FreeIntType___vader_core_types_InferVar___vader_core_types_NeverType___vader_core_types_PrimitiveType___vader_core_types_RangeType___vader_core_types_SelfType___vader_core_types_StructType___vader_core_types_TraitType___vader_core_types_TupleType___vader_core_types_TypeMetaType___vader_core_types_TypeParamType___vader_core_types_UnionType___vader_core_types_UnresolvedType(l2, l3, l1);
        t0 = vader_core_types$is_free_numeric(t2);
        if (t0) {
            t0 = vader_core_types$is_free_numeric(l1);
            if (t0) {
                { vader_gc_top = gc_frame.prev; return; }
            }
            t1 = l0.payload.obj;
            l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) t1)->f_symbol)->f_id;
            std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l2, l3, l1);
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 904u) {
        if (l1.tag == 904u) {
            t1 = l0.payload.obj;
            l4 = ((vader_struct_vader_core_types$ArrayType_t*) t1)->f_element;
            t1 = l1.payload.obj;
            l5 = ((vader_struct_vader_core_types$ArrayType_t*) t1)->f_element;
            vader_core_types$unify_type_param(l4, l5, l2);
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 921u) {
        if (l1.tag == 921u) {
            t1 = l0.payload.obj;
            l6 = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t1)->f_elements)->length;
            t1 = l1.payload.obj;
            l7 = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t1)->f_elements)->length;
            if (l6 == l7) {
                l6 = INT64_C(0);
                t1 = l0.payload.obj;
                l7 = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t1)->f_elements)->length;
                while ((l6 < l7)) {
                    t1 = l0.payload.obj;
                    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t1)->f_elements);
                    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
                    l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
                    t1 = l1.payload.obj;
                    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t1)->f_elements);
                    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
                    l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                    vader_core_types$unify_type_param(l4, l5, l2);
                    l6 = (l6 + INT64_C(1));
                }
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 918u) {
        if (l1.tag == 918u) {
            t1 = l0.payload.obj;
            l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t1)->f_symbol)->f_id;
            t1 = l1.payload.obj;
            l8 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t1)->f_symbol)->f_id;
            if (l3 == l8) {
                t1 = l0.payload.obj;
                l9 = ((vader_struct_vader_core_types$StructType_t*) t1)->f_args;
                t1 = l1.payload.obj;
                l10 = ((vader_struct_vader_core_types$StructType_t*) t1)->f_args;
                vader_core_types$unify_args(l9, l10, l2);
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 920u) {
        if (l1.tag == 920u) {
            t1 = l0.payload.obj;
            l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TraitType_t*) t1)->f_symbol)->f_id;
            t1 = l1.payload.obj;
            l8 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TraitType_t*) t1)->f_symbol)->f_id;
            if (l3 == l8) {
                t1 = l0.payload.obj;
                l9 = ((vader_struct_vader_core_types$TraitType_t*) t1)->f_args;
                t1 = l1.payload.obj;
                l10 = ((vader_struct_vader_core_types$TraitType_t*) t1)->f_args;
                vader_core_types$unify_args(l9, l10, l2);
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l1.tag == 904u) {
            t1 = l0.payload.obj;
            l4 = vader_core_types$core_trait_arg(vader_ref_box(t1), 690u);
            if (!(l4.tag == 0u)) {
                t1 = l1.payload.obj;
                l5 = ((vader_struct_vader_core_types$ArrayType_t*) t1)->f_element;
                vader_core_types$unify_type_param(l4, l5, l2);
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 907u) {
        if (l1.tag == 907u) {
            t1 = l0.payload.obj;
            l6 = ((vader_array_t*) ((vader_struct_vader_core_types$FnType_t*) t1)->f_params)->length;
            t1 = l1.payload.obj;
            l7 = ((vader_array_t*) ((vader_struct_vader_core_types$FnType_t*) t1)->f_params)->length;
            l6 = std_math$min_3(l6, l7);
            l7 = INT64_C(0);
            while ((l7 < l6)) {
                t1 = l0.payload.obj;
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_types$FnType_t*) t1)->f_params);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
                l4 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
                t1 = l1.payload.obj;
                vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_core_types$FnType_t*) t1)->f_params);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
                l5 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
                vader_core_types$unify_type_param(l4, l5, l2);
                l7 = (l7 + INT64_C(1));
            }
            t1 = l0.payload.obj;
            l4 = ((vader_struct_vader_core_types$FnType_t*) t1)->f_return_type;
            t1 = l1.payload.obj;
            l5 = ((vader_struct_vader_core_types$FnType_t*) t1)->f_return_type;
            vader_core_types$unify_type_param(l4, l5, l2);
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l0.tag == 926u)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t1 = l0.payload.obj;
    l9 = ((vader_struct_vader_core_types$UnionType_t*) t1)->f_variants;
    l4 = vader_core_types$union_variants(l1);
    if (l4.tag == 0u) {
        vader_array_t* _a4_arr = vader_array_new(251u, 1u, 13u, 1789u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l1.payload.obj;
        l10 = (void*) _a4_arr;
    } else {
        l10 = l4.payload.obj;
    }
    l9 = vader_core_types$union_leftovers(l9, l10);
    l6 = ((vader_array_t*) l9)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
        l10 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
        l4 = ((vader_struct_vader_core_types$UnionLeftover_t*) l10)->f_pattern;
        l5 = ((vader_struct_vader_core_types$UnionLeftover_t*) l10)->f_actual;
        vader_core_types$unify_type_param(l4, l5, l2);
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void* vader_core_types$union_leftovers(void* l0, void* l1) {
    int64_t l2, l6, l11;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l12 = NULL;
    vader_box_t l7 = vader_box_null(), l10 = vader_box_null();
    int32_t l8;
    bool l9;
    bool t0, t3;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l7, &l10, &t4 };
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l4, &l5, &l12, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (void*) &vader_fn_static___lambda_vader_core_types_3;
    l3 = std_core$filled__bool(l2, l3);
    vader_array_t* _a0_arr = vader_array_new(251u, 0u, 13u, 1789u);
    l4 = (void*) _a0_arr;
    l5 = l0;
    l2 = ((vader_array_t*) l5)->length;
    l6 = INT64_C(0);
    while ((l6 < l2)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l8 = vader_core_types$find_unused_equal(l1, l3, l7);
        if ((l8 >= INT32_C(0))) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
            ((uint8_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l8] = (uint8_t) true;
        } else {
            t0 = vader_core_types$type_contains_type_param(l7);
            if (t0) {
                vader_array_push_ref((vader_array_t*) l4, l7.payload.obj);
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    t1 = ((vader_array_t*) l4)->length;
    if (t1 == INT64_C(0)) {
        vader_array_t* _a3_arr = vader_array_new(86u, 0u, 13u, 925u);
        t2 = (void*) _a3_arr;
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a4_arr = vader_array_new(251u, 0u, 13u, 1789u);
    l5 = (void*) _a4_arr;
    l2 = INT64_C(0);
    l6 = ((vader_array_t*) l1)->length;
    while ((l2 < l6)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l2)
        t0 = ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l2];
        t3 = t0;
        if (!(t3)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            l7 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l2);
            vader_array_push_ref((vader_array_t*) l5, l7.payload.obj);
        }
        l2 = (l2 + INT64_C(1));
    }
    t1 = ((vader_array_t*) l4)->length;
    if (t1 == INT64_C(1)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t4 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) INT32_C(0));
        l9 = (t4.tag == 911u || t4.tag == 923u);
    } else {
        l9 = false;
    }
    if (l9) {
        t1 = ((vader_array_t*) l5)->length;
        if ((t1 > INT64_C(1))) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, INT32_C(0))
            l7 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) INT32_C(0));
            l10 = vader_core_types$union_of(l5);
            vader_struct_vader_core_types$UnionLeftover_t* _a9_obj = (vader_struct_vader_core_types$UnionLeftover_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$UnionLeftover_t));
            vader_obj_header_init(_a9_obj, 925u);
            _a9_obj->f_pattern = l7;
            _a9_obj->f_actual = l10;
            t2 = (void*) _a9_obj;
            vader_array_t* _a10_arr = vader_array_new(86u, 1u, 13u, 925u);
            ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = t2;
            t2 = (void*) _a10_arr;
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    vader_array_t* _a11_arr = vader_array_new(86u, 0u, 13u, 925u);
    l3 = (void*) _a11_arr;
    l2 = INT64_C(0);
    l6 = ((vader_array_t*) l4)->length;
    l11 = ((vader_array_t*) l5)->length;
    l6 = std_math$min_3(l6, l11);
    while ((l2 < l6)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l2)
        l7 = vader_array_ref_load_box(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l2);
        vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l2)
        l10 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l2);
        vader_struct_vader_core_types$UnionLeftover_t* _a14_obj = (vader_struct_vader_core_types$UnionLeftover_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$UnionLeftover_t));
        vader_obj_header_init(_a14_obj, 925u);
        _a14_obj->f_pattern = l7;
        _a14_obj->f_actual = l10;
        l12 = (void*) _a14_obj;
        vader_array_push_ref((vader_array_t*) l3, l12);
        l2 = (l2 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_core_types$union_literal_candidates(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[2] = { &l0, &l6 };
    void** gc_raw_roots[3] = { &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(251u, 0u, 13u, 1789u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_core_types$UnionType_t*) l1)->f_variants;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t0 = vader_core_types$literal_takes(l0, l6);
        if (t0) {
            vader_array_push_ref((vader_array_t*) l2, l6.payload.obj);
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$union_literal_member(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null();
    int64_t l5, l6;
    bool t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l3, &l7, &t2 };
    void** gc_raw_roots[3] = { &l1, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$is_free_numeric(l0);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = vader_core_types$union_literal_candidates(l0, l1);
    l3 = vader_core_types$default_if_free(l0);
    l4 = l2;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        t0 = vader_core_types$equals_type(l7, l3);
        if (t0) {
            { vader_box_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = (l6 + INT64_C(1));
    }
    t1 = ((vader_array_t*) l2)->length;
    if (t1 == INT64_C(1)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

vader_box_t vader_core_types$union_of(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(251u, 0u, 13u, 1789u);
    l1 = (void*) _a0_arr;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        vader_core_types$collect_variant(t0, l1);
        l4 = (l4 + INT64_C(1));
    }
    t1 = ((vader_array_t*) l1)->length;
    if (t1 == INT64_C(0)) {
        t2 = (void*) &vader_data_33;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_array_t*) l1)->length;
    if (!(t1 == INT64_C(1))) {
        t2 = vader_core_types$sort_by_display_key(l1);
        t0 = vader_core_types$mk_union(t2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
    t0 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT32_C(0));
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$union_of_paths(void* l0) {
    vader_box_t l1 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    void* l2 = NULL;
    void* l3 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    int64_t l4, l5;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[4] = { &l1, &l6, &l7, &t1 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l8, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_box_obj(0u, NULL);
    vader_array_t* _a0_arr = vader_array_new(251u, 0u, 13u, 1789u);
    l2 = (void*) _a0_arr;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l7 = vader_core_types$refinement_of(l6);
        if (l7.tag == 0u) {
            vader_array_push_ref((vader_array_t*) l2, l6.payload.obj);
        } else {
            l8 = l7.payload.obj;
            t0 = vader_core_types$joined_ranges(l1, l8);
            l1 = vader_ref_box(t0);
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a2_arr = vader_array_new(251u, 0u, 13u, 1789u);
    l3 = (void*) _a2_arr;
    l8 = l2;
    l4 = ((vader_array_t*) l8)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
        vader_core_types$collect_variant(t1, l3);
        l5 = (l5 + INT64_C(1));
    }
    if (!(l1.tag == 0u)) {
        l8 = l1.payload.obj;
        t2 = vader_core_types$held_by_another(l3, vader_ref_box(l8));
        if (!(t2)) {
            l8 = l1.payload.obj;
            vader_array_push_ref((vader_array_t*) l3, l8);
        }
    }
    vader_array_t* _a4_arr = vader_array_new(251u, 0u, 13u, 1789u);
    l8 = (void*) _a4_arr;
    l9 = l3;
    l4 = ((vader_array_t*) l9)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l1 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
        t2 = vader_core_types$absorbed(l1, l3, l2);
        if (!(t2)) {
            vader_array_push_ref((vader_array_t*) l8, l1.payload.obj);
        }
        l5 = (l5 + INT64_C(1));
    }
    t1 = vader_core_types$union_of(l8);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_types$union_variants(vader_box_t l0) {
    void* t0;
    if (!(l0.tag == 926u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    return vader_ref_box(((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants);
}

int64_t vader_core_types$value_abi_leaf_size(vader_box_t l0) {
    int64_t l1;
    bool l2;
    void* t0;
    vader_string_t t1;
    bool t2;
    int64_t t3;
    if (l0.tag == 915u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        t2 = vader_core_types$is_reference_name(t1);
        if (t2) {
            l2 = true;
        } else {
            t0 = l0.payload.obj;
            t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
            t3 = vader_core_types$primitive_size(t1);
            l2 = t3 == INT64_C(0);
        }
        if (l2) {
            l1 = INT64_C(-1);
        } else {
            t0 = l0.payload.obj;
            t1 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
            l1 = vader_core_types$primitive_size(t1);
        }
        return l1;
    }
    if ((l0.tag == 906u || l0.tag == 916u)) {
        l1 = vader_core_types$slot_byte_size(l0);
    } else {
        l1 = INT64_C(-1);
    }
    return l1;
}

int64_t vader_core_types$value_abi_sum_leaves(void* l0) {
    int64_t l1, l3, l4, l5;
    void* l2;
    int64_t t0;
    vader_box_t t1;
    t0 = ((vader_array_t*) l0)->length;
    if (t0 == INT64_C(0)) {
        return INT64_C(-1);
    }
    l1 = INT64_C(0);
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l5 = vader_core_types$value_abi_leaf_size(t1);
        if ((l5 < INT64_C(0))) {
            return INT64_C(-1);
        }
        t0 = vader_chk_add(i64, l1, l5);
        if ((t0 > INT64_C(16))) {
            return INT64_C(-1);
        }
        l1 = vader_chk_add(i64, l1, l5);
        l4 = (l4 + INT64_C(1));
    }
    return l1;
}

vader_box_t vader_core_types$value_abi_tuple_elements(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    int64_t t2;
    if (l0.tag == 905u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$value_abi_tuple_elements(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
        return t1;
    }
    if (!(l0.tag == 921u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    t2 = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements)->length;
    if ((t2 < INT64_C(2))) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    t2 = vader_core_types$value_abi_sum_leaves(((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements);
    if (!((t2 < INT64_C(0)))) {
        t0 = l0.payload.obj;
        return vader_ref_box(((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements);
    }
    return vader_box_obj(0u, NULL);
}

int64_t vader_core_types$value_abi_type_size(vader_box_t l0) {
    void* t0;
    int64_t t1;
    if (l0.tag == 921u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$value_abi_sum_leaves(((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements);
        return t1;
    }
    if (!(l0.tag == 905u)) {
        return INT64_C(-1);
    }
    t0 = l0.payload.obj;
    t1 = vader_core_types$value_abi_type_size(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
    return t1;
}

static bool vader_core_types$variant_keeps_tag(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[3] = { &l0, &l5, &t0 };
    void** gc_raw_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$integer_values(l0);
    if (t0.tag == 0u) {
        t1 = vader_core_types$is_assignable(l0, vader_ref_box(l1));
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_core_types$UnionType_t*) l1)->f_variants;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = vader_core_types$is_assignable(l0, l5);
        if (t1) {
            t1 = vader_core_types$laid_out_alike(l0, l5);
            if (t1) {
                { vader_gc_top = gc_frame.prev; return true; }
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void vader_core_types$write_named(void* l0, void* l1, void* l2) {
    int64_t t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_core_types$write_nominal(l0, l1);
    t0 = ((vader_array_t*) l2)->length;
    if (!(t0 == INT64_C(0))) {
        std_string__builder$append_char(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb, 60u);
        vader_core_types$write_type_list(l0, l2, 362u);
        std_string__builder$append_char(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb, 62u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_core_types$write_nominal(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    bool l4;
    vader_string_t l5 = 0;
    int64_t l6, l8;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l7, &l9 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_names;
    if (!(l2.tag == 0u)) {
        l6 = std_string__builder$byte_len(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb);
        l3 = ((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb;
        l4 = ((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_qualified;
        l5 = vader_core_types$nominal_name(l1, l4);
        std_string__builder$append(l3, l5);
        l7 = l2.payload.obj;
        l8 = std_string__builder$byte_len(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb);
        vader_struct_vader_core_types$NamedRange_t* _a0_obj = (vader_struct_vader_core_types$NamedRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$NamedRange_t));
        vader_obj_header_init(_a0_obj, 912u);
        _a0_obj->f_start = l6;
        _a0_obj->f_end = l8;
        _a0_obj->f_symbol = l1;
        l9 = (void*) _a0_obj;
        vader_array_push_ref((vader_array_t*) l7, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb;
    l4 = ((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_qualified;
    l5 = vader_core_types$nominal_name(l1, l4);
    std_string__builder$append(l3, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_core_types$write_range(void* l0, void* l1, bool l2) {
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
    l3 = vader_support_integer$machine_integer_name(((vader_struct_vader_core_types$RangeType_t*) l1)->f_bounds);
    if (l3 != 0u) {
        if (l2) {
            l4 = true;
        } else {
            t0 = ((vader_struct_vader_core_types$RangeType_t*) l1)->f_name;
            l4 = t0 == 0u;
        }
    } else {
        l4 = false;
    }
    if (l4) {
        std_string__builder$append(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2) {
        l3 = vader_core_types$display_bounds(((vader_struct_vader_core_types$RangeType_t*) l1)->f_bounds);
        l3 = concat_2(686u, l3);
        std_string__builder$append(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = ((vader_struct_vader_core_types$RangeType_t*) l1)->f_name;
    if (!(t0 != 0u)) {
        l5 = vader_core_types$display_bounds(((vader_struct_vader_core_types$RangeType_t*) l1)->f_bounds);
        std_string__builder$append(l0, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct_vader_core_types$RangeType_t*) l1)->f_name;
    std_string__builder$append(l0, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_core_types$write_type(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_string_t l3 = 0;
    bool l5;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l6 };
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 915u) {
        l2 = ((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_types$PrimitiveType_t*) t0)->f_name;
        std_string__builder$append(l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if ((l1.tag == 918u || l1.tag == 920u)) {
        l2 = VADER_UNION_FIELD(void*, vader_struct_vader_core_types$StructType_t, f_symbol, l1.payload.obj);
        l4 = VADER_UNION_FIELD(void*, vader_struct_vader_core_types$StructType_t, f_args, l1.payload.obj);
        vader_core_types$write_named(l0, l2, l4);
    } else if ((l1.tag == 905u || l1.tag == 906u)) {
        l2 = VADER_UNION_FIELD(void*, vader_struct_vader_core_types$DistinctType_t, f_symbol, l1.payload.obj);
        vader_core_types$write_nominal(l0, l2);
    } else if (l1.tag == 916u) {
        l2 = ((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb;
        l4 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_qualified;
        vader_core_types$write_range(l2, l4, l5);
    } else if (l1.tag == 923u) {
        l2 = ((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) t0)->f_symbol)->f_name;
        std_string__builder$append(l2, l3);
    } else if (l1.tag == 922u) {
        std_string__builder$append(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb, 2743u);
    } else if (l1.tag == 917u) {
        std_string__builder$append(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb, 797u);
    } else if (l1.tag == 927u) {
        std_string__builder$append(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb, 529u);
    } else if (l1.tag == 913u) {
        std_string__builder$append(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb, 2371u);
    } else if (l1.tag == 910u) {
        std_string__builder$append(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb, 3056u);
    } else if (l1.tag == 909u) {
        std_string__builder$append(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb, 3055u);
    } else if (l1.tag == 908u) {
        std_string__builder$append(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb, 3054u);
    } else if (l1.tag == 904u) {
        t0 = l1.payload.obj;
        if (((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element.tag == 926u) {
            l5 = true;
        } else {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element.tag == 907u;
        }
        if (l5) {
            std_string__builder$append_char(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb, 40u);
        }
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element;
        vader_core_types$write_type(l0, l6);
        if (l5) {
            std_string__builder$append_char(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb, 41u);
        }
        std_string__builder$append(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb, 965u);
    } else if (l1.tag == 921u) {
        std_string__builder$append_char(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb, 91u);
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements;
        vader_core_types$write_type_list(l0, l2, 362u);
        std_string__builder$append_char(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb, 93u);
    } else if (l1.tag == 907u) {
        std_string__builder$append(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb, 2005u);
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_params;
        vader_core_types$write_type_list(l0, l2, 362u);
        std_string__builder$append(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb, 327u);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type;
        vader_core_types$write_type(l0, l6);
    } else if (l1.tag == 926u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
        vader_core_types$write_type_list(l0, l2, 238u);
    } else if (l1.tag == 903u) {
        std_string__builder$append(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb, 579u);
    } else {
        if (!(l1.tag == 911u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = ((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$InferVar_t*) t0)->f_origin)->f_name;
        std_string__builder$append(l2, l3);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_core_types$write_type_list(void* l0, void* l1, vader_string_t l2) {
    bool l3;
    void* l4 = NULL;
    int64_t l5, l6;
    vader_box_t l7 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = true;
    l4 = l1;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        if (!(l3)) {
            std_string__builder$append(((vader_struct_vader_core_types$TypeWriter_t*) l0)->f_sb, l2);
        }
        l3 = false;
        vader_core_types$write_type(l0, l7);
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

vader_box_t vader_core_types$zonk(vader_box_t l0, void* l1) {
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$type_contains_infer_var(l0);
    if (!(t0)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_core_types$zonk_in(l0, l1);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_core_types$zonk_each(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    int64_t l3, l5;
    vader_box_t l6 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l6, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(251u, 0u, 13u, 1789u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l4 = l0;
    l3 = ((vader_array_t*) l4)->length;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l6 = vader_core_types$zonk_in(t0, l1);
        vader_array_push_ref((vader_array_t*) l2, l6.payload.obj);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_types$zonk_in(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void* t2 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l2, &l5, &t1 };
    void** gc_raw_roots[5] = { &l1, &l3, &l4, &t0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 911u) {
        t0 = l0.payload.obj;
        l2 = vader_core_types$zonk_var(t0, l1);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 904u) {
        t0 = l0.payload.obj;
        t1 = vader_core_types$zonk_in(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element, l1);
        l2 = vader_core_types$mk_array(t1);
    } else if (l0.tag == 921u) {
        t0 = l0.payload.obj;
        t2 = vader_core_types$zonk_each(((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements, l1);
        l2 = vader_core_types$mk_tuple(t2);
    } else if (l0.tag == 918u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol;
        t0 = l0.payload.obj;
        l4 = vader_core_types$zonk_each(((vader_struct_vader_core_types$StructType_t*) t0)->f_args, l1);
        l2 = vader_core_types$mk_struct(l3, l4);
    } else if (l0.tag == 920u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_types$TraitType_t*) t0)->f_symbol;
        t0 = l0.payload.obj;
        l4 = vader_core_types$zonk_each(((vader_struct_vader_core_types$TraitType_t*) t0)->f_args, l1);
        vader_struct_vader_core_types$TraitType_t* _a0_obj = (vader_struct_vader_core_types$TraitType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$TraitType_t));
        vader_obj_header_init(_a0_obj, 920u);
        _a0_obj->f_symbol = l3;
        _a0_obj->f_args = l4;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 907u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = vader_core_types$zonk_each(((vader_struct_vader_core_types$FnType_t*) t0)->f_params, l1);
        t0 = l0.payload.obj;
        l5 = vader_core_types$zonk_in(((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type, l1);
        l3 = ((vader_struct_vader_core_types$FnType_t*) l3)->f_type_params;
        vader_struct_vader_core_types$FnType_t* _a1_obj = (vader_struct_vader_core_types$FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$FnType_t));
        vader_obj_header_init(_a1_obj, 907u);
        _a1_obj->f_params = l4;
        _a1_obj->f_return_type = l5;
        _a1_obj->f_type_params = l3;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        t2 = vader_core_types$zonk_each(((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants, l1);
        l2 = vader_core_types$union_of(t2);
    } else {
        l2 = l0;
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_types$zonk_var(void* l0, void* l1) {
    int32_t l2;
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_types$InferVar_t*) l0)->f_id;
    l3 = std_collections$MutableMap$std_core$Index$at__i32__Any(l1, l2);
    if (l3.tag == 0u) {
        { vader_box_t __vret = vader_ref_box(l0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_types$zonk_in(l3, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
