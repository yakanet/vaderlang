#include "bootstrap.split.h"

static vader_string_t vader_core_wit$NoForm$std_core$Error$message(void* l0);
static void vader_core_wit$advance(void* l0);
static void* vader_core_wit$alias_free_params(void* l0);
static vader_box_t vader_core_wit$argument(void* l0);
static bool vader_core_wit$at_end(void* l0);
static bool vader_core_wit$at_gate(void* l0);
static bool vader_core_wit$at_keyword(void* l0, vader_string_t l1);
static bool vader_core_wit$at_type_keyword(void* l0);
static bool vader_core_wit$at_version_byte(void* l0);
static void* vader_core_wit$bare_cases(void* l0);
static vader_box_t vader_core_wit$borrow_expr(void* l0, void* l1);
static void* vader_core_wit$case_alias_free(void* l0);
static vader_string_t vader_core_wit$case_struct_name(vader_string_t l0, void* l1);
static vader_string_t vader_core_wit$case_text(void* l0);
static vader_box_t vader_core_wit$declaration(void* l0, vader_box_t l1);
static vader_box_t vader_core_wit$declared_tag(vader_box_t l0);
static vader_box_t vader_core_wit$declared_type(void* l0, void* l1, void* l2);
static vader_box_t vader_core_wit$definition(void* l0, vader_string_t l1);
static vader_box_t vader_core_wit$dependency_named(void* l0, void* l1);
static vader_string_t vader_core_wit$enum_declaration(vader_string_t l0, void* l1);
static vader_string_t vader_core_wit$enum_error_impl(vader_string_t l0, void* l1);
static vader_string_t vader_core_wit$enum_name_text(void* l0);
static vader_string_t vader_core_wit$enum_text(void* l0, void* l1);
static vader_string_t vader_core_wit$error_impl(void* l0, vader_box_t l1);
static void* vader_core_wit$error_types(void* l0);
static vader_box_t vader_core_wit$expect(void* l0, uint8_t l1);
static void* vader_core_wit$fail_here(void* l0, vader_string_t l1);
static vader_string_t vader_core_wit$flags_declaration(vader_string_t l0, void* l1);
static vader_box_t vader_core_wit$function_decl(void* l0, vader_string_t l1, void* l2, void* l3);
static vader_string_t vader_core_wit$function_declaration(void* l0, void* l1);
static vader_string_t vader_core_wit$function_name(void* l0, vader_box_t l1);
static vader_box_t vader_core_wit$function_of(void* l0, void* l1, void* l2, vader_box_t l3);
static vader_string_t vader_core_wit$function_words(void* l0);
static vader_box_t vader_core_wit$future_expr(void* l0);
static vader_box_t vader_core_wit$future_value_text(void* l0, void* l1);
static vader_box_t vader_core_wit$gate(void* l0);
static vader_string_t vader_core_wit$grouped(vader_string_t l0);
static vader_string_t vader_core_wit$handle_keyword(void* l0);
static vader_box_t vader_core_wit$identifier(void* l0);
static vader_string_t vader_core_wit$interface_alias(void* l0);
static vader_box_t vader_core_wit$interface_body(void* l0, vader_string_t l1, void* l2, void* l3);
static vader_string_t vader_core_wit$interface_constant(void* l0);
static vader_box_t vader_core_wit$interface_of(void* l0, void* l1);
static bool vader_core_wit$is_resource(vader_box_t l0);
static bool vader_core_wit$is_word_byte(uint8_t l0);
static vader_string_t vader_core_wit$left_out(void* l0, void* l1);
static vader_box_t vader_core_wit$list_expr(void* l0);
static vader_box_t vader_core_wit$members(void* l0, vader_string_t l1);
static vader_string_t vader_core_wit$named_error_impl(vader_string_t l0, vader_string_t l1);
static vader_box_t vader_core_wit$named_expr(void* l0, void* l1);
static vader_string_t vader_core_wit$named_text(void* l0, void* l1, vader_string_t l2);
static vader_string_t vader_core_wit$named_text_1(void* l0, vader_string_t l1);
static vader_box_t vader_core_wit$named_type(void* l0, void* l1, vader_string_t l2, void* l3);
static vader_box_t vader_core_wit$namespaced_name(void* l0);
static void* vader_core_wit$no_form(vader_box_t l0, vader_string_t l1);
static vader_box_t vader_core_wit$open_scope(void* l0, void* l1);
static vader_box_t vader_core_wit$option_expr(void* l0);
static vader_box_t vader_core_wit$optional_alias_free(vader_box_t l0);
static vader_box_t vader_core_wit$optional_argument(void* l0);
static vader_string_t vader_core_wit$optional_tag_text(vader_box_t l0);
static vader_box_t vader_core_wit$optional_type_of(void* l0, void* l1, vader_box_t l2);
static vader_box_t vader_core_wit$own_expr(void* l0, void* l1);
static vader_box_t vader_core_wit$package_decl(void* l0);
static vader_box_t vader_core_wit$package_name(void* l0);
static vader_box_t vader_core_wit$package_of(void* l0, void* l1);
static vader_box_t vader_core_wit$parameter_text(void* l0, void* l1, vader_box_t l2);
static vader_box_t vader_core_wit$parameters_text(void* l0, void* l1);
static vader_box_t vader_core_wit$params(void* l0);
static void* vader_core_wit$payload_cases(void* l0);
static uint8_t vader_core_wit$peek(void* l0);
static uint8_t vader_core_wit$peek_at(void* l0, int64_t l1);
static uint8_t vader_core_wit$peek_word_end(void* l0);
static void vader_core_wit$push_declared_errors(vader_box_t l0, void* l1);
static void vader_core_wit$push_errors(vader_box_t l0, void* l1);
static void vader_core_wit$push_optional_errors(vader_box_t l0, void* l1);
static void vader_core_wit$push_tags(vader_box_t l0, void* l1);
static void vader_core_wit$push_variant_tags(void* l0, void* l1);
static vader_box_t vader_core_wit$read_wit_document(vader_string_t l0, vader_string_t l1);
static vader_box_t vader_core_wit$record_declaration(void* l0, vader_string_t l1, void* l2);
static vader_box_t vader_core_wit$resolve_name(void* l0, void* l1, vader_string_t l2, void* l3);
static vader_box_t vader_core_wit$resource_argument(void* l0, void* l1, vader_string_t l2);
static vader_box_t vader_core_wit$resource_body(void* l0);
static void* vader_core_wit$resource_methods(void* l0, vader_string_t l1);
static vader_box_t vader_core_wit$result_expr(void* l0);
static vader_box_t vader_core_wit$result_text(void* l0, void* l1);
static vader_box_t vader_core_wit$returned(void* l0, void* l1);
static vader_box_t vader_core_wit$returned_result(void* l0, void* l1, void* l2);
static vader_box_t vader_core_wit$returned_union(void* l0, void* l1, vader_box_t l2, vader_string_t l3, void* l4);
static vader_string_t vader_core_wit$scalar_text(uint8_t l0);
static bool vader_core_wit$shares_tag(vader_box_t l0, vader_box_t l1);
static bool vader_core_wit$skip(void* l0, uint8_t l1);
static bool vader_core_wit$skip_arrow(void* l0);
static vader_box_t vader_core_wit$skip_braces(void* l0);
static vader_box_t vader_core_wit$skip_past(void* l0, uint8_t l1);
static void vader_core_wit$skip_space(void* l0);
static void* vader_core_wit$span(void* l0);
static vader_box_t vader_core_wit$stream_expr(void* l0, void* l1);
static vader_string_t vader_core_wit$struct_tag(void* l0, vader_string_t l1);
static vader_string_t vader_core_wit$tag_text(vader_box_t l0);
static bool vader_core_wit$tags_meet(void* l0, void* l1);
static void* vader_core_wit$tags_of(vader_box_t l0);
static vader_string_t vader_core_wit$take_doc(void* l0);
static vader_box_t vader_core_wit$take_name(void* l0, vader_string_t l1, void* l2);
static vader_box_t vader_core_wit$tuple_expr(void* l0);
static vader_box_t vader_core_wit$type_decl(void* l0, vader_string_t l1, void* l2, void* l3);
static void* vader_core_wit$type_error(void* l0, void* l1);
static vader_box_t vader_core_wit$type_expr(void* l0);
static vader_box_t vader_core_wit$type_of(void* l0, void* l1, vader_box_t l2);
static vader_box_t vader_core_wit$type_text(void* l0, vader_box_t l1);
static vader_box_t vader_core_wit$use_decl(void* l0, void* l1, void* l2);
static vader_box_t vader_core_wit$use_path(void* l0);
static vader_box_t vader_core_wit$used_type(void* l0, void* l1);
static vader_string_t vader_core_wit$vader_function_name(void* l0);
static vader_box_t vader_core_wit$variant_declaration(void* l0, vader_string_t l1, void* l2);
static vader_string_t vader_core_wit$variant_error_impl(vader_string_t l0, void* l1);
static vader_box_t vader_core_wit$version(void* l0);
static void* vader_core_wit$wit_error(void* l0, vader_string_t l1);
static vader_string_t vader_core_wit$wit_scalar_name(uint8_t l0);
static vader_box_t vader_core_wit$wit_scalar_named(vader_string_t l0);
static vader_string_t vader_core_wit$word(void* l0);
static vader_string_t vader_core_wit$word_at(void* l0, int64_t l1);
static vader_string_t vader_core_wit$word_here(void* l0);
static void vader_core_wit$write_wit(void* l0, vader_box_t l1);
static void vader_core_wit$write_wit_or_none(void* l0, vader_box_t l1);

static vader_string_t vader_core_wit$NoForm$std_core$Error$message(void* l0) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &t0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_core_wit$NoForm_t*) l0)->f_what;
    t1 = concat_2(t0, 174u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_core_wit$advance(void* l0) {
    int32_t l1;
    int64_t l2;
    uint8_t t0;
    int32_t t1;
    int64_t t2;
    t0 = vader_core_wit$peek(l0);
    if (t0 == INT32_C(10)) {
        t1 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_line;
        l1 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_line = l1;
        ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_column = INT32_C(1);
    } else {
        t1 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_column;
        l1 = vader_chk_add(i32, t1, INT32_C(1));
        ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_column = l1;
    }
    t2 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_at;
    l2 = vader_chk_add(i64, t2, INT64_C(1));
    ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_at = l2;
    return;
}

vader_box_t vader_core_wit$alias_free(vader_box_t l0) {
    vader_box_t l1 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    void* l2 = NULL;
    void* l3 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    int64_t l4, l5;
    bool l8;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[5] = { &l0, &l1, &l6, &l7, &t1 };
    void** gc_raw_roots[5] = { &l2, &l3, &l10, &l11, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1478u) {
        t0 = l0.payload.obj;
        l1 = vader_core_wit$alias_free(((vader_struct_vader_core_wit$WitAlias_t*) t0)->f_target);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1496u) {
        t0 = l0.payload.obj;
        t1 = vader_core_wit$alias_free(((vader_struct_vader_core_wit$WitList_t*) t0)->f_element);
        vader_struct_vader_core_wit$WitList_t* _a0_obj = (vader_struct_vader_core_wit$WitList_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitList_t));
        vader_obj_header_init(_a0_obj, 1496u);
        _a0_obj->f_element = t1;
        t0 = (void*) _a0_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 1501u) {
        t0 = l0.payload.obj;
        t1 = vader_core_wit$alias_free(((vader_struct_vader_core_wit$WitOption_t*) t0)->f_value);
        vader_struct_vader_core_wit$WitOption_t* _a1_obj = (vader_struct_vader_core_wit$WitOption_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitOption_t));
        vader_obj_header_init(_a1_obj, 1501u);
        _a1_obj->f_value = t1;
        t0 = (void*) _a1_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 1519u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_wit$WitTuple_t*) t0)->f_elements;
        t2 = vader_array_length(((vader_array_t*) l2));
        vader_array_t* _a2_arr = vader_array_reserve(482u, (int64_t) t2, 0u, 2752u);
        l3 = (void*) _a2_arr;
        l4 = vader_array_length(((vader_array_t*) l2));
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t1 = vader_array_box_slots(_a3_slotarr->buf)[vader_array_offset(_a3_slotarr) + (size_t) l5];
            l6 = vader_core_wit$alias_free(t1);
            vader_array_push((vader_array_t*) l3, l6);
            l5 = (l5 + INT64_C(1));
        }
        vader_struct_vader_core_wit$WitTuple_t* _a4_obj = (vader_struct_vader_core_wit$WitTuple_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitTuple_t));
        vader_obj_header_init(_a4_obj, 1519u);
        _a4_obj->f_elements = l3;
        t0 = (void*) _a4_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 1513u) {
        t0 = l0.payload.obj;
        l6 = vader_core_wit$optional_alias_free(((vader_struct_vader_core_wit$WitResult_t*) t0)->f_ok);
        t0 = l0.payload.obj;
        l7 = vader_core_wit$optional_alias_free(((vader_struct_vader_core_wit$WitResult_t*) t0)->f_error);
        vader_struct_vader_core_wit$WitResult_t* _a5_obj = (vader_struct_vader_core_wit$WitResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitResult_t));
        vader_obj_header_init(_a5_obj, 1513u);
        _a5_obj->f_ok = l6;
        _a5_obj->f_error = l7;
        t0 = (void*) _a5_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 1517u) {
        t0 = l0.payload.obj;
        t1 = vader_core_wit$alias_free(((vader_struct_vader_core_wit$WitStream_t*) t0)->f_element);
        vader_struct_vader_core_wit$WitStream_t* _a6_obj = (vader_struct_vader_core_wit$WitStream_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitStream_t));
        vader_obj_header_init(_a6_obj, 1517u);
        _a6_obj->f_element = t1;
        t0 = (void*) _a6_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 1490u) {
        t0 = l0.payload.obj;
        t1 = vader_core_wit$optional_alias_free(((vader_struct_vader_core_wit$WitFuture_t*) t0)->f_value);
        vader_struct_vader_core_wit$WitFuture_t* _a7_obj = (vader_struct_vader_core_wit$WitFuture_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitFuture_t));
        vader_obj_header_init(_a7_obj, 1490u);
        _a7_obj->f_value = t1;
        t0 = (void*) _a7_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 1493u) {
        l2 = l0.payload.obj;
        t0 = l0.payload.obj;
        l6 = vader_core_wit$alias_free(((vader_struct_vader_core_wit$WitHandle_t*) t0)->f_resource);
        l8 = ((vader_struct_vader_core_wit$WitHandle_t*) l2)->f_is_borrow;
        vader_struct_vader_core_wit$WitHandle_t* _a8_obj = (vader_struct_vader_core_wit$WitHandle_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitHandle_t));
        vader_obj_header_init(_a8_obj, 1493u);
        _a8_obj->f_resource = l6;
        _a8_obj->f_is_borrow = l8;
        t0 = (void*) _a8_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 1509u) {
        l2 = l0.payload.obj;
        l9 = ((vader_struct_vader_core_wit$WitRecord_t*) l2)->f_name;
        l2 = ((vader_struct_vader_core_wit$WitRecord_t*) l2)->f_owner;
        t0 = l0.payload.obj;
        l3 = vader_core_wit$alias_free_params(((vader_struct_vader_core_wit$WitRecord_t*) t0)->f_fields);
        vader_struct_vader_core_wit$WitRecord_t* _a9_obj = (vader_struct_vader_core_wit$WitRecord_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitRecord_t));
        vader_obj_header_init(_a9_obj, 1509u);
        _a9_obj->f_name = l9;
        _a9_obj->f_owner = l2;
        _a9_obj->f_fields = l3;
        t0 = (void*) _a9_obj;
        l1 = vader_ref_box(t0);
    } else if (l0.tag == 1526u) {
        l2 = l0.payload.obj;
        l9 = ((vader_struct_vader_core_wit$WitVariant_t*) l2)->f_name;
        l2 = ((vader_struct_vader_core_wit$WitVariant_t*) l2)->f_owner;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_wit$WitVariant_t*) t0)->f_cases;
        t2 = vader_array_length(((vader_array_t*) l3));
        vader_array_t* _a10_arr = vader_array_reserve(237u, (int64_t) t2, 13u, 1481u);
        l10 = (void*) _a10_arr;
        l4 = vader_array_length(((vader_array_t*) l3));
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            t0 = vader_array_ref_load_obj(_a11_slotarr->buf, vader_array_offset(_a11_slotarr) + (size_t) l5);
            l11 = vader_core_wit$case_alias_free(t0);
            vader_array_push_ref((vader_array_t*) l10, l11);
            l5 = (l5 + INT64_C(1));
        }
        vader_struct_vader_core_wit$WitVariant_t* _a12_obj = (vader_struct_vader_core_wit$WitVariant_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitVariant_t));
        vader_obj_header_init(_a12_obj, 1526u);
        _a12_obj->f_name = l9;
        _a12_obj->f_owner = l2;
        _a12_obj->f_cases = l10;
        t0 = (void*) _a12_obj;
        l1 = vader_ref_box(t0);
    } else {
        if (!((l0.tag == 1483u || l0.tag == 1486u || l0.tag == 1511u || l0.tag == 628u || l0.tag == 1522u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = l0;
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_core_wit$alias_free_params(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = l0;
    t0 = vader_array_length(((vader_array_t*) l1));
    vader_array_t* _a0_arr = vader_array_reserve(245u, (int64_t) t0, 13u, 1506u);
    l2 = (void*) _a0_arr;
    l3 = vader_array_length(((vader_array_t*) l1));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
        l5 = __lambda_vader_core_wit_0(t1);
        vader_array_push_ref((vader_array_t*) l2, l5);
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$argument(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_core_wit$optional_argument(l0);
    l2 = l1;
    if (l1.tag == 0u) {
        t0 = vader_core_wit$fail_here(l0, 2437u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1485u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_core_wit$at_end(void* l0) {
    int64_t l1, l2;
    vader_string_t t0;
    l1 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_at;
    t0 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_text;
    l2 = vader_host_std_core$Intrinsic$byte_len(t0);
    return (l1 >= l2);
}

static bool vader_core_wit$at_gate(void* l0) {
    int64_t l1;
    vader_string_t l2;
    bool l3;
    int64_t t0;
    t0 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_at;
    l1 = vader_chk_add(i64, t0, INT64_C(1));
    l2 = vader_core_wit$word_at(l0, l1);
    if (l2 == 3179u) {
        l3 = true;
    } else {
        l3 = l2 == 3490u;
    }
    if (l3) {
        l3 = true;
    } else {
        l3 = l2 == 2336u;
    }
    if (l3) {
        return true;
    }
    return false;
}

static bool vader_core_wit$at_keyword(void* l0, vader_string_t l1) {
    vader_string_t t0;
    t0 = vader_core_wit$word_here(l0);
    return t0 == l1;
}

static bool vader_core_wit$at_type_keyword(void* l0) {
    vader_string_t l1;
    bool l2;
    l1 = vader_core_wit$word_here(l0);
    if (l1 == 3393u) {
        l2 = true;
    } else {
        l2 = l1 == 3102u;
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == 3681u;
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == 2401u;
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == 2539u;
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == 3125u;
    }
    if (l2) {
        return true;
    }
    return false;
}

static bool vader_core_wit$at_version_byte(void* l0) {
    uint8_t l1;
    uint8_t t0;
    bool t1;
    l1 = vader_core_wit$peek(l0);
    if (l1 == INT32_C(46)) {
        t0 = vader_core_wit$peek_at(l0, INT64_C(1));
        t1 = vader_core_wit$is_word_byte(t0);
        return t1;
    }
    t1 = vader_core_wit$is_word_byte(l1);
    if (t1) {
        return true;
    }
    return l1 == INT32_C(43);
}

static void* vader_core_wit$bare_cases(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4;
    vader_string_t l6 = 0;
    bool t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_wit$WitVariant_t*) l0)->f_cases;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l2 = (void*) _a0_arr;
    l3 = vader_array_length(((vader_array_t*) l1));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
        t0 = __lambda_vader_core_wit_10(l5);
        if (t0) {
            l6 = __lambda_vader_core_wit_11(l5);
            vader_array_push_scalar((vader_array_t*) l2, vader_box_string(623u, l6));
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$borrow_expr(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_core_wit$resource_argument(l0, l1, 2098u);
    l3 = l2;
    if (l2.tag == 1485u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    vader_struct_vader_core_wit$WitBorrowExpr_t* _a0_obj = (vader_struct_vader_core_wit$WitBorrowExpr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitBorrowExpr_t));
    vader_obj_header_init(_a0_obj, 1480u);
    _a0_obj->f_resource = t0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_core_wit$case_alias_free(void* l0) {
    vader_string_t l1 = 0;
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_wit$WitCase_t*) l0)->f_name;
    l2 = vader_core_wit$optional_alias_free(((vader_struct_vader_core_wit$WitCase_t*) l0)->f_type);
    vader_struct_vader_core_wit$WitCase_t* _a0_obj = (vader_struct_vader_core_wit$WitCase_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitCase_t));
    vader_obj_header_init(_a0_obj, 1481u);
    _a0_obj->f_name = l1;
    _a0_obj->f_type = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$case_struct_name(vader_string_t l0, void* l1) {
    vader_string_t l2 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_core_wit$WitCase_t*) l1)->f_name;
    l2 = vader_core_wit$pascal_name(t0);
    t0 = concat_2(l0, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$case_text(void* l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_wit$WitCase_t*) l0)->f_type;
    if (l1.tag == 0u) {
        t0 = ((vader_struct_vader_core_wit$WitCase_t*) l0)->f_name;
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_core_wit$WitCase_t*) l0)->f_name;
    l3 = vader_core_wit$wit_type_text(l1);
    t0 = concat_3(l2, 565u, l3);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$declaration(void* l0, vader_box_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l5 = 0;
    vader_box_t l3 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    void* l4 = NULL;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[4] = { &l1, &l3, &l6, &l7 };
    void** gc_raw_roots[3] = { &l0, &l4, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l5, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_core_wit$wit_type_name(l1);
    l2 = vader_core_wit$pascal_name(t0);
    if (l1.tag == 1509u) {
        l4 = l1.payload.obj;
        l3 = vader_core_wit$record_declaration(l0, l2, l4);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1526u) {
        l4 = l1.payload.obj;
        l3 = vader_core_wit$variant_declaration(l0, l2, l4);
    } else if (l1.tag == 1483u) {
        t1 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitEnum_t*) t1)->f_cases;
        t0 = vader_core_wit$enum_declaration(l2, l4);
        l3 = vader_box_string(623u, t0);
    } else if (l1.tag == 1486u) {
        l4 = l1.payload.obj;
        t0 = vader_core_wit$flags_declaration(l2, l4);
        l3 = vader_box_string(623u, t0);
    } else if (l1.tag == 1511u) {
        t0 = concat_3(2463u, l2, 101u);
        l3 = vader_box_string(623u, t0);
    } else {
        if (!(l1.tag == 1478u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t1 = l1.payload.obj;
        l6 = ((vader_struct_vader_core_wit$WitAlias_t*) t1)->f_target;
        l6 = vader_core_wit$type_text(l0, l6);
        l7 = l6;
        if (l6.tag == 1474u) {
            t1 = l7.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = l6.payload.s;
        t0 = concat_5(642u, l2, 90u, l5, 1u);
        l3 = vader_box_string(623u, t0);
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$declared_tag(vader_box_t l0) {
    vader_box_t l1 = vader_box_null(), l3 = vader_box_null();
    void* l2 = NULL;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[3] = { &l0, &l1, &l3 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l4, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1478u) {
        t0 = l0.payload.obj;
        l1 = vader_core_wit$declared_tag(((vader_struct_vader_core_wit$WitAlias_t*) t0)->f_target);
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1483u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_wit$WitEnum_t*) t0)->f_owner;
        if (l3.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l2 = l3.payload.obj;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitEnum_t*) t0)->f_name;
        t1 = vader_core_wit$struct_tag(l2, l4);
        l1 = vader_box_string(623u, t1);
    } else if (l0.tag == 1509u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_wit$WitRecord_t*) t0)->f_owner;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitRecord_t*) t0)->f_name;
        t1 = vader_core_wit$struct_tag(l2, l4);
        l1 = vader_box_string(623u, t1);
    } else if (l0.tag == 1526u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_wit$WitVariant_t*) t0)->f_owner;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitVariant_t*) t0)->f_name;
        t1 = vader_core_wit$struct_tag(l2, l4);
        l1 = vader_box_string(623u, t1);
    } else if (l0.tag == 1486u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_wit$WitFlags_t*) t0)->f_owner;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitFlags_t*) t0)->f_name;
        t1 = vader_core_wit$struct_tag(l2, l4);
        l1 = vader_box_string(623u, t1);
    } else if (l0.tag == 1511u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_wit$WitResource_t*) t0)->f_owner;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitResource_t*) t0)->f_name;
        t1 = vader_core_wit$struct_tag(l2, l4);
        l1 = vader_box_string(623u, t1);
    } else {
        if (!((l0.tag == 1490u || l0.tag == 1493u || l0.tag == 1496u || l0.tag == 1501u || l0.tag == 1513u || l0.tag == 628u || l0.tag == 1517u || l0.tag == 1519u || l0.tag == 1522u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_box_obj(0u, NULL);
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$declared_type(void* l0, void* l1, void* l2) {
    vader_string_t l3 = 0;
    vader_string_t l19 = 0;
    void* l4 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l15 = vader_box_null(), l16 = vader_box_null(), l17 = vader_box_null();
    int64_t l12, l13;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[8] = { &l5, &l6, &l7, &l8, &l9, &l15, &l16, &l17 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l4, &l10, &l11, &l14, &l18, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l19, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 8u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_core_wit$WitTypeDecl_t*) l2)->f_name;
    l4 = ((vader_struct_vader_core_wit$InterfaceScope_t*) l1)->f_owner;
    l5 = ((vader_struct_vader_core_wit$WitTypeDecl_t*) l2)->f_definition;
    l6 = l5;
    if (l5.tag == 1479u) {
        t0 = l6.payload.obj;
        l7 = ((vader_struct_vader_core_wit$WitAliasDef_t*) t0)->f_target;
        l8 = vader_core_wit$type_of(l0, l1, l7);
        l9 = l8;
        if (l8.tag == 1485u) {
            t0 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = l8;
        vader_struct_vader_core_wit$WitAlias_t* _a0_obj = (vader_struct_vader_core_wit$WitAlias_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitAlias_t));
        vader_obj_header_init(_a0_obj, 1478u);
        _a0_obj->f_name = l3;
        _a0_obj->f_owner = l4;
        _a0_obj->f_target = l7;
        t0 = (void*) _a0_obj;
        l7 = vader_ref_box(t0);
        { vader_box_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l5.tag == 1510u) {
        vader_array_t* _a1_arr = vader_array_new(245u, 0u, 13u, 1506u);
        l10 = (void*) _a1_arr;
        t0 = l6.payload.obj;
        l11 = ((vader_struct_vader_core_wit$WitRecordDef_t*) t0)->f_fields;
        l12 = vader_array_length(((vader_array_t*) l11));
        l13 = INT64_C(0);
        while ((l13 < l12)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l13)
            l14 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l13);
            l9 = ((vader_struct_vader_core_wit$WitMemberDecl_t*) l14)->f_type;
            if (l9.tag == 0u) {
                t0 = vader_core_wit$wit_error(((vader_struct_vader_core_wit$WitMemberDecl_t*) l14)->f_span, 1842u);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l8 = l9;
            l16 = vader_core_wit$type_of(l0, l1, l8);
            l17 = l16;
            if (l16.tag == 1485u) {
                t0 = l17.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l15 = l16;
            t1 = ((vader_struct_vader_core_wit$WitMemberDecl_t*) l14)->f_name;
            vader_struct_vader_core_wit$WitParam_t* _a3_obj = (vader_struct_vader_core_wit$WitParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitParam_t));
            vader_obj_header_init(_a3_obj, 1506u);
            _a3_obj->f_name = t1;
            _a3_obj->f_type = l15;
            l18 = (void*) _a3_obj;
            vader_array_push_ref((vader_array_t*) l10, l18);
            l13 = (l13 + INT64_C(1));
        }
        vader_struct_vader_core_wit$WitRecord_t* _a4_obj = (vader_struct_vader_core_wit$WitRecord_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitRecord_t));
        vader_obj_header_init(_a4_obj, 1509u);
        _a4_obj->f_name = l3;
        _a4_obj->f_owner = l4;
        _a4_obj->f_fields = l10;
        t0 = (void*) _a4_obj;
        l7 = vader_ref_box(t0);
    } else if (l5.tag == 1527u) {
        vader_array_t* _a5_arr = vader_array_new(237u, 0u, 13u, 1481u);
        l10 = (void*) _a5_arr;
        t0 = l6.payload.obj;
        l11 = ((vader_struct_vader_core_wit$WitVariantDef_t*) t0)->f_cases;
        l12 = vader_array_length(((vader_array_t*) l11));
        l13 = INT64_C(0);
        while ((l13 < l12)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l13)
            l14 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l13);
            l9 = ((vader_struct_vader_core_wit$WitMemberDecl_t*) l14)->f_type;
            l15 = vader_core_wit$optional_type_of(l0, l1, l9);
            l16 = l15;
            if (l15.tag == 1485u) {
                t0 = l16.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l8 = l15;
            t1 = ((vader_struct_vader_core_wit$WitMemberDecl_t*) l14)->f_name;
            vader_struct_vader_core_wit$WitCase_t* _a7_obj = (vader_struct_vader_core_wit$WitCase_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitCase_t));
            vader_obj_header_init(_a7_obj, 1481u);
            _a7_obj->f_name = t1;
            _a7_obj->f_type = l8;
            l18 = (void*) _a7_obj;
            vader_array_push_ref((vader_array_t*) l10, l18);
            l13 = (l13 + INT64_C(1));
        }
        vader_struct_vader_core_wit$WitVariant_t* _a8_obj = (vader_struct_vader_core_wit$WitVariant_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitVariant_t));
        vader_obj_header_init(_a8_obj, 1526u);
        _a8_obj->f_name = l3;
        _a8_obj->f_owner = l4;
        _a8_obj->f_cases = l10;
        t0 = (void*) _a8_obj;
        l7 = vader_ref_box(t0);
    } else if (l5.tag == 1484u) {
        t0 = l6.payload.obj;
        l10 = ((vader_struct_vader_core_wit$WitEnumDef_t*) t0)->f_cases;
        t2 = vader_array_length(((vader_array_t*) l10));
        vader_array_t* _a9_arr = vader_array_reserve(28u, (int64_t) t2, 0u, 623u);
        l11 = (void*) _a9_arr;
        l12 = vader_array_length(((vader_array_t*) l10));
        l13 = INT64_C(0);
        while ((l13 < l12)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            t0 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l13);
            l19 = __lambda_vader_core_wit_17(t0);
            vader_array_push_scalar((vader_array_t*) l11, vader_box_string(623u, l19));
            l13 = (l13 + INT64_C(1));
        }
        vader_struct_vader_core_wit$WitEnum_t* _a11_obj = (vader_struct_vader_core_wit$WitEnum_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitEnum_t));
        vader_obj_header_init(_a11_obj, 1483u);
        _a11_obj->f_name = l3;
        _a11_obj->f_cases = l11;
        _a11_obj->f_owner = vader_ref_box(l4);
        t0 = (void*) _a11_obj;
        l7 = vader_ref_box(t0);
    } else if (l5.tag == 1487u) {
        t0 = l6.payload.obj;
        l10 = ((vader_struct_vader_core_wit$WitFlagsDef_t*) t0)->f_flags;
        t2 = vader_array_length(((vader_array_t*) l10));
        vader_array_t* _a12_arr = vader_array_reserve(28u, (int64_t) t2, 0u, 623u);
        l11 = (void*) _a12_arr;
        l12 = vader_array_length(((vader_array_t*) l10));
        l13 = INT64_C(0);
        while ((l13 < l12)) {
            vader_array_t* _a13_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            t0 = vader_array_ref_load_obj(_a13_slotarr->buf, vader_array_offset(_a13_slotarr) + (size_t) l13);
            l19 = __lambda_vader_core_wit_16(t0);
            vader_array_push_scalar((vader_array_t*) l11, vader_box_string(623u, l19));
            l13 = (l13 + INT64_C(1));
        }
        vader_struct_vader_core_wit$WitFlags_t* _a14_obj = (vader_struct_vader_core_wit$WitFlags_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitFlags_t));
        vader_obj_header_init(_a14_obj, 1486u);
        _a14_obj->f_name = l3;
        _a14_obj->f_owner = l4;
        _a14_obj->f_flags = l11;
        t0 = (void*) _a14_obj;
        l7 = vader_ref_box(t0);
    } else {
        if (!(l5.tag == 1512u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_struct_vader_core_wit$WitResource_t* _a15_obj = (vader_struct_vader_core_wit$WitResource_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitResource_t));
        vader_obj_header_init(_a15_obj, 1511u);
        _a15_obj->f_name = l3;
        _a15_obj->f_owner = l4;
        t0 = (void*) _a15_obj;
        l7 = vader_ref_box(t0);
    }
    { vader_box_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$definition(void* l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    void* l5 = NULL;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l3, &l4, &t1 };
    void** gc_raw_roots[3] = { &l0, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1 == 3393u) {
        l2 = vader_core_wit$expect(l0, (uint8_t) 61);
        l3 = l2;
        if (l2.tag == 1485u) {
            t0 = l3.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l3 = vader_core_wit$type_expr(l0);
        l4 = l3;
        if (l3.tag == 1485u) {
            t0 = l4.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = l3;
        l3 = vader_core_wit$expect(l0, (uint8_t) 59);
        l4 = l3;
        if (!(l3.tag == 1485u)) {
            vader_struct_vader_core_wit$WitAliasDef_t* _a0_obj = (vader_struct_vader_core_wit$WitAliasDef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitAliasDef_t));
            vader_obj_header_init(_a0_obj, 1479u);
            _a0_obj->f_target = l2;
            t0 = (void*) _a0_obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 3125u) {
        t1 = vader_core_wit$resource_body(l0);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_core_wit$members(l0, l1);
    l3 = l2;
    if (l2.tag == 1485u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l2.payload.obj;
    if (l1 == 3102u) {
        vader_struct_vader_core_wit$WitRecordDef_t* _a1_obj = (vader_struct_vader_core_wit$WitRecordDef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitRecordDef_t));
        vader_obj_header_init(_a1_obj, 1510u);
        _a1_obj->f_fields = l5;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == 3681u) {
        vader_struct_vader_core_wit$WitVariantDef_t* _a2_obj = (vader_struct_vader_core_wit$WitVariantDef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitVariantDef_t));
        vader_obj_header_init(_a2_obj, 1527u);
        _a2_obj->f_cases = l5;
        t0 = (void*) _a2_obj;
        l2 = vader_ref_box(t0);
    } else if (l1 == 2401u) {
        vader_struct_vader_core_wit$WitEnumDef_t* _a3_obj = (vader_struct_vader_core_wit$WitEnumDef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitEnumDef_t));
        vader_obj_header_init(_a3_obj, 1484u);
        _a3_obj->f_cases = l5;
        t0 = (void*) _a3_obj;
        l2 = vader_ref_box(t0);
    } else {
        vader_struct_vader_core_wit$WitFlagsDef_t* _a4_obj = (vader_struct_vader_core_wit$WitFlagsDef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitFlagsDef_t));
        vader_obj_header_init(_a4_obj, 1487u);
        _a4_obj->f_flags = l5;
        t0 = (void*) _a4_obj;
        l2 = vader_ref_box(t0);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$dependency_named(void* l0, void* l1) {
    vader_string_t l2 = 0;
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null();
    void* l4 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_core_wit$wit_package_text(l1);
    l3 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_core_wit$Resolution_t*) l0)->f_dependencies, l2);
    if (!(l3.tag == 0u)) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_core_wit$Resolution_t*) l0)->f_dependency;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l4;
    l3 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_ref_box(l1));
    l5 = l3;
    if (l3.tag == 1485u) {
        t0 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l3.payload.obj;
    std_collections$Map$std_core$IndexSet$set_at__string__Any(((vader_struct_vader_core_wit$Resolution_t*) l0)->f_dependencies, l2, vader_ref_box(l4));
    { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t vader_core_wit$enum_case_bits(int64_t l0) {
    if ((l0 <= INT64_C(256))) {
        return INT64_C(8);
    }
    if (!((l0 <= INT64_C(65536)))) {
        return INT64_C(32);
    }
    return INT64_C(16);
}

static vader_string_t vader_core_wit$enum_declaration(vader_string_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5, l8;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l1, &l2, &l3 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l6, &l7, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l1;
    t0 = vader_array_length(((vader_array_t*) l2));
    vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t0, 0u, 623u);
    l3 = (void*) _a0_arr;
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l5];
        t2 = t1.payload.s;
        l6 = __lambda_vader_core_wit_7(t2);
        vader_array_push_scalar((vader_array_t*) l3, vader_box_string(623u, l6));
        l5 = (l5 + INT64_C(1));
    }
    l2 = l3;
    l6 = l0;
    t0 = vader_array_length(((vader_array_t*) l1));
    l4 = vader_core_wit$enum_case_bits(t0);
    l7 = std_string$join(l2, 0u);
    l5 = vader_host_std_core$Intrinsic$byte_len(l6);
    l8 = vader_host_std_core$Intrinsic$byte_len(l7);
    l5 = (l5 + l8);
    l2 = (void*) vader_buffer_new((size_t) (INT64_C(43) + l5));
    l5 = INT64_C(0);
    l5 = std_core$write_string_at(l2, l5, 2463u);
    l5 = std_core$write_string_at(l2, l5, l6);
    l5 = std_core$write_string_at(l2, l5, 95u);
    l5 = std_core$write_int(l2, l5, l4);
    l5 = std_core$write_string_at(l2, l5, 416u);
    l5 = std_core$write_string_at(l2, l5, l7);
    l5 = std_core$write_string_at(l2, l5, 3785u);
    t2 = std_core$finish_buffer(l2, l5);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$enum_error_impl(vader_string_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l1, &l2, &l3 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l6, &l7, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l1;
    t0 = vader_array_length(((vader_array_t*) l2));
    vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t0, 0u, 623u);
    l3 = (void*) _a0_arr;
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l5];
        t2 = t1.payload.s;
        l6 = __lambda_vader_core_wit_8(t2);
        vader_array_push_scalar((vader_array_t*) l3, vader_box_string(623u, l6));
        l5 = (l5 + INT64_C(1));
    }
    l2 = l3;
    l6 = concat_3(1u, l0, 183u);
    l7 = std_string$join(l2, 0u);
    l7 = concat_3(43u, l7, 48u);
    t2 = concat_2(l6, l7);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$enum_name_text(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_wit$WitEnum_t*) l0)->f_owner;
    if (l2.tag == 0u) {
        t0 = ((vader_struct_vader_core_wit$WitEnum_t*) l0)->f_name;
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l2.payload.obj;
    l3 = ((vader_struct_vader_core_wit$WitEnum_t*) l0)->f_name;
    t0 = vader_core_wit$named_text_1(l1, l3);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$enum_text(void* l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_string_t l4 = 0;
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[3] = { &l4, &t0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_core_wit$WitEnum_t*) l1)->f_owner;
    if (l3.tag == 0u) {
        t0 = ((vader_struct_vader_core_wit$WitEnum_t*) l1)->f_name;
        t1 = vader_core_wit$pascal_name(t0);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    l4 = ((vader_struct_vader_core_wit$WitEnum_t*) l1)->f_name;
    t0 = vader_core_wit$named_text(l0, l2, l4);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$error_impl(void* l0, vader_box_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    void* l4 = NULL;
    bool t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l4, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l3, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_core_wit$wit_type_name(l1);
    l3 = vader_core_wit$struct_tag(((vader_struct_vader_core_wit$Generation_t*) l0)->f_owner, l2);
    t0 = std_collections$Set$std_core$Contains$contains__string(((vader_struct_vader_core_wit$Generation_t*) l0)->f_errors, l3);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    l3 = vader_core_wit$pascal_name(l2);
    if (l1.tag == 1483u) {
        t1 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitEnum_t*) t1)->f_cases;
        t2 = vader_core_wit$enum_error_impl(l3, l4);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1.tag == 1526u)) {
        t2 = vader_core_wit$named_error_impl(l3, l2);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l1.payload.obj;
    t2 = vader_core_wit$variant_error_impl(l3, l4);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_core_wit$error_types(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    int64_t l4, l5, l7, l8, l10, l11, l14, l15;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l6, &l9, &l12, &l13, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(26u, 0u, 12u, 621u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 626u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__bool_t* _a3_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a3_obj, 976u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$Set__string_t* _a4_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
    vader_obj_header_init(_a4_obj, 1072u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    l2 = ((vader_struct_vader_core_wit$WitPackage_t*) l0)->f_interfaces;
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l3 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l5);
        l6 = ((vader_struct_vader_core_wit$WitInterface_t*) l3)->f_types;
        l7 = vader_array_length(((vader_array_t*) l6));
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            t1 = vader_array_ref_load_box(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l8);
            vader_core_wit$push_declared_errors(t1, l1);
            l8 = (l8 + INT64_C(1));
        }
        l9 = ((vader_struct_vader_core_wit$WitInterface_t*) l3)->f_functions;
        l10 = vader_array_length(((vader_array_t*) l9));
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            l12 = vader_array_ref_load_obj(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l11);
            l13 = ((vader_struct_vader_core_wit$WitFunction_t*) ((vader_struct_vader_core_wit$WitNamedFunction_t*) l12)->f_type)->f_params;
            l14 = vader_array_length(((vader_array_t*) l13));
            l15 = INT64_C(0);
            while ((l15 < l14)) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                t0 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l15);
                vader_core_wit$push_errors(((vader_struct_vader_core_wit$WitParam_t*) t0)->f_type, l1);
                l15 = (l15 + INT64_C(1));
            }
            vader_core_wit$push_optional_errors(((vader_struct_vader_core_wit$WitFunction_t*) ((vader_struct_vader_core_wit$WitNamedFunction_t*) l12)->f_type)->f_result, l1);
            l11 = (l11 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$expect(void* l0, uint8_t l1) {
    vader_string_t l2 = 0;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_core_wit$skip(l0, l1);
    if (!(t0)) {
        l2 = std_core$char$Display$to_string(((uint32_t) (uint8_t) l1));
        l2 = concat_3(2433u, l2, 1310u);
        t1 = vader_core_wit$fail_here(l0, l2);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_core_wit$fail_here(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    void* l4 = NULL;
    bool t0;
    uint8_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[3] = { &l0, &l4, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_core_wit$at_end(l0);
    if (t0) {
        l2 = 3321u;
    } else {
        t1 = vader_core_wit$peek(l0);
        l3 = std_core$char$Display$to_string(((uint32_t) (uint8_t) t1));
        l2 = concat_3(1310u, l3, 1310u);
    }
    l4 = vader_core_wit$span(l0);
    l2 = concat_3(l1, 459u, l2);
    t2 = vader_core_wit$wit_error(l4, l2);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$flags_declaration(vader_string_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l1, &l2, &l3 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l6, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_wit$WitFlags_t*) l1)->f_flags;
    t0 = vader_array_length(((vader_array_t*) l2));
    vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t0, 0u, 623u);
    l3 = (void*) _a0_arr;
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l5];
        t2 = t1.payload.s;
        l6 = __lambda_vader_core_wit_6(t2);
        vader_array_push_scalar((vader_array_t*) l3, vader_box_string(623u, l6));
        l5 = (l5 + INT64_C(1));
    }
    l6 = std_string$join(l3, 0u);
    t2 = concat_5(2463u, l0, 100u, l6, 3785u);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$function_decl(void* l0, vader_string_t l1, void* l2, void* l3) {
    vader_string_t l4 = 0;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null(), l10 = vader_box_null();
    uint8_t l7;
    bool l8;
    void* l9 = NULL;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[3] = { &l5, &l6, &l10 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l9, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_core_wit$identifier(l0);
    l6 = l5;
    if (l5.tag == 1485u) {
        t0 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l5.payload.s;
    l5 = vader_core_wit$expect(l0, (uint8_t) 58);
    l6 = l5;
    if (l5.tag == 1485u) {
        t0 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = (uint8_t) 0;
    t1 = vader_core_wit$at_keyword(l0, 3206u);
    if (t1) {
        vader_core_wit$word(l0);
        l7 = (uint8_t) 2;
    }
    l8 = vader_core_wit$at_keyword(l0, 2063u);
    if (l8) {
        vader_core_wit$word(l0);
    }
    t1 = vader_core_wit$at_keyword(l0, 2571u);
    if (!(t1)) {
        t0 = vader_core_wit$fail_here(l0, 2438u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_core_wit$word(l0);
    l5 = vader_core_wit$params(l0);
    l6 = l5;
    if (l5.tag == 1485u) {
        t0 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = l5.payload.obj;
    vader_struct_vader_core_wit$WitFunctionDecl_t* _a0_obj = (vader_struct_vader_core_wit$WitFunctionDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitFunctionDecl_t));
    vader_obj_header_init(_a0_obj, 1489u);
    _a0_obj->f_name = l4;
    _a0_obj->f_kind = l7;
    _a0_obj->f_is_async = l8;
    _a0_obj->f_params = l9;
    _a0_obj->f_result = vader_box_obj(0u, NULL);
    _a0_obj->f_doc = l1;
    _a0_obj->f_gate = l2;
    _a0_obj->f_span = l3;
    l9 = (void*) _a0_obj;
    t1 = vader_core_wit$skip_arrow(l0);
    if (t1) {
        l6 = vader_core_wit$type_expr(l0);
        l10 = l6;
        if (l6.tag == 1485u) {
            t0 = l10.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = l6;
        ((vader_struct_vader_core_wit$WitFunctionDecl_t*) l9)->f_result = l5;
        VADER_WRITE_BARRIER((vader_struct_vader_core_wit$WitFunctionDecl_t*) l9);
    }
    l5 = vader_core_wit$expect(l0, (uint8_t) 59);
    l6 = l5;
    if (!(l5.tag == 1485u)) {
        { vader_box_t __vret = vader_ref_box(l9); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l6.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$function_declaration(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    int64_t l10, l11;
    bool l12;
    vader_string_t t0 = 0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &l4, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_string_t* gc_atom_roots[5] = { &l6, &l7, &l8, &l9, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_core_wit$parameters_text(l0, l1);
    l4 = l3;
    if (l3.tag == 1474u) {
        l2 = l4.payload.obj;
        t0 = vader_core_wit$left_out(l1, l2);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    l3 = vader_core_wit$returned(l0, l1);
    l4 = l3;
    if (l3.tag == 1474u) {
        l5 = l4.payload.obj;
        t0 = vader_core_wit$left_out(l1, l5);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l3.payload.obj;
    l6 = ((vader_struct_vader_core_wit$Returned_t*) l5)->f_wrapper;
    l7 = ((vader_struct_vader_core_wit$WitNamedFunction_t*) l1)->f_name;
    l6 = concat_4(l6, 647u, l7, 324u);
    l7 = vader_core_wit$vader_function_name(l1);
    l7 = concat_3(2463u, l7, 97u);
    l8 = ((vader_struct_vader_core_wit$Returned_t*) l5)->f_text;
    l8 = concat_2(402u, l8);
    l9 = std_string$join(l2, 444u);
    l10 = vader_host_std_core$Intrinsic$byte_len(l7);
    l11 = vader_host_std_core$Intrinsic$byte_len(l9);
    l10 = vader_chk_add(i64, l10, l11);
    l11 = vader_host_std_core$Intrinsic$byte_len(l8);
    t1 = vader_chk_add(i64, l10, l11);
    if ((t1 <= INT64_C(100))) {
        l12 = true;
    } else {
        t1 = vader_array_length(((vader_array_t*) l2));
        l12 = t1 == INT64_C(0);
    }
    if (l12) {
        t0 = concat_5(l6, l7, l9, l8, 1u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_array_length(((vader_array_t*) l2));
    vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t1, 0u, 623u);
    l5 = (void*) _a0_arr;
    l10 = vader_array_length(((vader_array_t*) l2));
    l11 = INT64_C(0);
    while ((l11 < l10)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t2 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l11];
        t0 = t2.payload.s;
        l9 = __lambda_vader_core_wit_2(t0);
        vader_array_push_scalar((vader_array_t*) l5, vader_box_string(623u, l9));
        l11 = (l11 + INT64_C(1));
    }
    l9 = std_string$join(l5, 0u);
    t0 = concat_6(l6, l7, 1u, l9, l8, 1u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$function_name(void* l0, vader_box_t l1) {
    uint8_t l2;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 0u) {
        t0 = ((vader_struct_vader_core_wit$WitFunctionDecl_t*) l0)->f_name;
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_core_wit$WitFunctionDecl_t*) l0)->f_kind;
    if (l2 == INT32_C(1)) {
        t1 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_wit$WitResource_t*) t1)->f_name;
        l4 = ((vader_struct_vader_core_wit$WitFunctionDecl_t*) l0)->f_name;
        l3 = concat_4(1226u, l3, 492u, l4);
        { vader_string_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(2)) {
        t1 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitResource_t*) t1)->f_name;
        l5 = ((vader_struct_vader_core_wit$WitFunctionDecl_t*) l0)->f_name;
        l3 = concat_4(1227u, l4, 492u, l5);
    } else if (l2 == INT32_C(3)) {
        t1 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitResource_t*) t1)->f_name;
        l3 = concat_2(1225u, l4);
    } else {
        if (!(l2 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = ((vader_struct_vader_core_wit$WitFunctionDecl_t*) l0)->f_name;
    }
    { vader_string_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$function_of(void* l0, void* l1, void* l2, vader_box_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l13 = NULL;
    int64_t l6, l7;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null();
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    uint8_t l16;
    bool l17;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[5] = { &l3, &l9, &l10, &l11, &l12 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l4, &l5, &l8, &l13, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l14, &l15, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(245u, 0u, 13u, 1506u);
    l4 = (void*) _a0_arr;
    if (((vader_struct_vader_core_wit$WitFunctionDecl_t*) l2)->f_kind == INT32_C(1)) {
        if (!(l3.tag == 0u)) {
            t0 = l3.payload.obj;
            vader_struct_vader_core_wit$WitHandle_t* _a1_obj = (vader_struct_vader_core_wit$WitHandle_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitHandle_t));
            vader_obj_header_init(_a1_obj, 1493u);
            _a1_obj->f_resource = vader_ref_box(t0);
            _a1_obj->f_is_borrow = true;
            l5 = (void*) _a1_obj;
            vader_struct_vader_core_wit$WitParam_t* _a2_obj = (vader_struct_vader_core_wit$WitParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitParam_t));
            vader_obj_header_init(_a2_obj, 1506u);
            _a2_obj->f_name = 3164u;
            _a2_obj->f_type = vader_ref_box(l5);
            l5 = (void*) _a2_obj;
            vader_array_push_ref((vader_array_t*) l4, l5);
        }
    }
    l5 = ((vader_struct_vader_core_wit$WitFunctionDecl_t*) l2)->f_params;
    l6 = vader_array_length(((vader_array_t*) l5));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
        l8 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l7);
        l10 = ((vader_struct_vader_core_wit$WitParamDecl_t*) l8)->f_type;
        l11 = vader_core_wit$type_of(l0, l1, l10);
        l12 = l11;
        if (l11.tag == 1485u) {
            t0 = l12.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = l11;
        t1 = ((vader_struct_vader_core_wit$WitParamDecl_t*) l8)->f_name;
        vader_struct_vader_core_wit$WitParam_t* _a4_obj = (vader_struct_vader_core_wit$WitParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitParam_t));
        vader_obj_header_init(_a4_obj, 1506u);
        _a4_obj->f_name = t1;
        _a4_obj->f_type = l9;
        l13 = (void*) _a4_obj;
        vader_array_push_ref((vader_array_t*) l4, l13);
        l7 = (l7 + INT64_C(1));
    }
    l9 = vader_box_obj(0u, NULL);
    l10 = ((vader_struct_vader_core_wit$WitFunctionDecl_t*) l2)->f_result;
    if (l10.tag == 0u) {
        if (((vader_struct_vader_core_wit$WitFunctionDecl_t*) l2)->f_kind == INT32_C(3)) {
            if (!(l3.tag == 0u)) {
                t0 = l3.payload.obj;
                vader_struct_vader_core_wit$WitHandle_t* _a5_obj = (vader_struct_vader_core_wit$WitHandle_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitHandle_t));
                vader_obj_header_init(_a5_obj, 1493u);
                _a5_obj->f_resource = vader_ref_box(t0);
                _a5_obj->f_is_borrow = false;
                t0 = (void*) _a5_obj;
                l9 = vader_ref_box(t0);
            }
        }
    } else {
        l10 = vader_core_wit$type_of(l0, l1, l10);
        l11 = l10;
        if (l10.tag == 1485u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = l10;
    }
    l14 = vader_core_wit$function_name(l2, l3);
    l15 = ((vader_struct_vader_core_wit$WitFunctionDecl_t*) l2)->f_name;
    l16 = ((vader_struct_vader_core_wit$WitFunctionDecl_t*) l2)->f_kind;
    l17 = ((vader_struct_vader_core_wit$WitFunctionDecl_t*) l2)->f_is_async;
    vader_struct_vader_core_wit$WitFunction_t* _a6_obj = (vader_struct_vader_core_wit$WitFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitFunction_t));
    vader_obj_header_init(_a6_obj, 1488u);
    _a6_obj->f_params = l4;
    _a6_obj->f_result = l9;
    l4 = (void*) _a6_obj;
    vader_struct_vader_core_wit$WitNamedFunction_t* _a7_obj = (vader_struct_vader_core_wit$WitNamedFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitNamedFunction_t));
    vader_obj_header_init(_a7_obj, 1500u);
    _a7_obj->f_name = l14;
    _a7_obj->f_member = l15;
    _a7_obj->f_kind = l16;
    _a7_obj->f_is_async = l17;
    _a7_obj->f_resource = l3;
    _a7_obj->f_type = l4;
    t0 = (void*) _a7_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$function_words(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    uint8_t l3;
    vader_string_t l4 = 0;
    vader_string_t l6 = 0;
    bool l5;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[3] = { &l4, &l6, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_wit$WitNamedFunction_t*) l0)->f_resource;
    if (l2.tag == 0u) {
        t0 = ((vader_struct_vader_core_wit$WitNamedFunction_t*) l0)->f_name;
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l2.payload.obj;
    l3 = ((vader_struct_vader_core_wit$WitNamedFunction_t*) l0)->f_kind;
    if (l3 == INT32_C(1)) {
        l5 = true;
    } else {
        l5 = l3 == INT32_C(2);
    }
    if (l5) {
        l4 = ((vader_struct_vader_core_wit$WitResource_t*) l1)->f_name;
        l6 = ((vader_struct_vader_core_wit$WitNamedFunction_t*) l0)->f_member;
        l4 = concat_3(l4, 479u, l6);
        { vader_string_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(3)) {
        l6 = ((vader_struct_vader_core_wit$WitResource_t*) l1)->f_name;
        l4 = concat_2(2957u, l6);
    } else {
        if (!(l3 == INT32_C(0))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l4 = ((vader_struct_vader_core_wit$WitNamedFunction_t*) l0)->f_name;
    }
    { vader_string_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$future_expr(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_core_wit$optional_argument(l0);
    l2 = l1;
    if (l1.tag == 1485u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_wit$WitFutureExpr_t* _a0_obj = (vader_struct_vader_core_wit$WitFutureExpr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitFutureExpr_t));
    vader_obj_header_init(_a0_obj, 1491u);
    _a0_obj->f_value = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$future_value_text(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_wit$WitFuture_t*) l1)->f_value;
    if (l2.tag == 0u) {
        { vader_box_t __vret = vader_box_string(623u, 3699u); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_wit$type_text(l0, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$gate(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    vader_string_t l3 = 0;
    vader_string_t l6 = 0;
    vader_string_t l11 = 0;
    vader_string_t l16 = 0;
    vader_string_t l17 = 0;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null(), l14 = vader_box_null(), l15 = vader_box_null();
    uint8_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[10] = { &l4, &l5, &l7, &l8, &l9, &l10, &l12, &l13, &l14, &l15 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_string_t* gc_atom_roots[5] = { &l3, &l6, &l11, &l16, &l17 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 10u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_wit$WitGate_t* _a0_obj = (vader_struct_vader_core_wit$WitGate_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitGate_t));
    vader_obj_header_init(_a0_obj, 1492u);
    _a0_obj->f_since = 0u;
    _a0_obj->f_unstable = 0u;
    _a0_obj->f_deprecated = 0u;
    l1 = (void*) _a0_obj;
    for (;;) {
        t0 = vader_core_wit$peek(l0);
        if (t0 == INT32_C(64)) {
            l2 = vader_core_wit$span(l0);
            vader_core_wit$advance(l0);
            l3 = vader_core_wit$word(l0);
            l4 = vader_core_wit$expect(l0, (uint8_t) 40);
            l5 = l4;
            if (l4.tag == 1485u) {
                t1 = l5.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l7 = vader_core_wit$identifier(l0);
            l8 = l7;
            if (l7.tag == 1485u) {
                t1 = l8.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l6 = l7.payload.s;
            l9 = vader_core_wit$expect(l0, (uint8_t) 61);
            l10 = l9;
            if (l9.tag == 1485u) {
                t1 = l10.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l12 = vader_core_wit$version(l0);
            l13 = l12;
            if (l12.tag == 1485u) {
                t1 = l13.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l11 = l12.payload.s;
            l14 = vader_core_wit$expect(l0, (uint8_t) 41);
            l15 = l14;
            if (l14.tag == 1485u) {
                t1 = l15.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l6 != 3694u) {
                if (l6 != 2503u) {
                    l16 = concat_3(3474u, l6, 1310u);
                    t1 = vader_core_wit$wit_error(l2, l16);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            if (l3 == 3179u) {
                ((vader_struct_vader_core_wit$WitGate_t*) l1)->f_since = l11;
                continue;
            }
            if (l3 == 3490u) {
                ((vader_struct_vader_core_wit$WitGate_t*) l1)->f_unstable = l11;
            } else {
                if (!(l3 == 2336u)) {
                    l17 = concat_3(3473u, l3, 1310u);
                    t1 = vader_core_wit$wit_error(l2, l17);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                ((vader_struct_vader_core_wit$WitGate_t*) l1)->f_deprecated = l11;
            }
            continue;
        }
        break;
    }
    { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$grouped(vader_string_t l0) {
    bool t0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_string$string$std_core$Contains$contains(l0, 309u);
    if (t0) {
        t1 = concat_3(381u, l0, 398u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$handle_keyword(void* l0) {
    bool t0;
    t0 = ((vader_struct_vader_core_wit$WitHandle_t*) l0)->f_is_borrow;
    if (t0) {
        return 2098u;
    }
    return 3045u;
}

static vader_box_t vader_core_wit$identifier(void* l0) {
    vader_string_t l1 = 0;
    bool l2;
    int64_t l3;
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_core_wit$word_here(l0);
    if (l1 == 0u) {
        l2 = true;
    } else {
        l2 = l1 == 358u;
    }
    if (l2) {
        t0 = vader_core_wit$fail_here(l0, 2445u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_core_wit$word(l0);
    t1 = std_string$starts_with(l1, 358u);
    if (!(t1)) {
        { vader_box_t __vret = vader_box_string(623u, l1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_host_std_core$Intrinsic$byte_len(l1);
    t2 = vader_host_std_core$Intrinsic$byte_slice(l1, INT64_C(1), l3);
    { vader_box_t __vret = vader_box_string(623u, t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$interface_alias(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_core_wit$WitPackageName_t*) ((vader_struct_vader_core_wit$WitOwner_t*) l0)->f_package)->f_name;
    l1 = vader_core_wit$pascal_name(t0);
    t0 = ((vader_struct_vader_core_wit$WitOwner_t*) l0)->f_interface;
    l2 = vader_core_wit$pascal_name(t0);
    t0 = concat_2(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$interface_body(void* l0, vader_string_t l1, void* l2, void* l3) {
    vader_string_t l4 = 0;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null(), l14 = vader_box_null(), l15 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null();
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[8] = { &l5, &l6, &l11, &l12, &l14, &l15, &l17, &l18 };
    void** gc_raw_roots[10] = { &l0, &l2, &l3, &l7, &l8, &l9, &l10, &l13, &l16, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 8u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_core_wit$identifier(l0);
    l6 = l5;
    if (l5.tag == 1485u) {
        t0 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l5.payload.s;
    vader_array_t* _a0_arr = vader_array_new(249u, 0u, 13u, 1523u);
    l7 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(248u, 0u, 13u, 1521u);
    l8 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(239u, 0u, 13u, 1489u);
    l9 = (void*) _a2_arr;
    vader_struct_vader_core_wit$WitInterfaceDecl_t* _a3_obj = (vader_struct_vader_core_wit$WitInterfaceDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitInterfaceDecl_t));
    vader_obj_header_init(_a3_obj, 1495u);
    _a3_obj->f_name = l4;
    _a3_obj->f_doc = l1;
    _a3_obj->f_gate = l2;
    _a3_obj->f_span = l3;
    _a3_obj->f_uses = l7;
    _a3_obj->f_types = l8;
    _a3_obj->f_functions = l9;
    l7 = (void*) _a3_obj;
    l5 = vader_core_wit$expect(l0, (uint8_t) 123);
    l6 = l5;
    if (l5.tag == 1485u) {
        t0 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    for (;;) {
        t1 = vader_core_wit$skip(l0, (uint8_t) 125);
        if (!(t1)) {
            t1 = vader_core_wit$at_end(l0);
            if (t1) {
                t0 = vader_core_wit$fail_here(l0, 2443u);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l4 = vader_core_wit$take_doc(l0);
            l5 = vader_core_wit$gate(l0);
            l6 = l5;
            if (l5.tag == 1485u) {
                t0 = l6.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l8 = l5.payload.obj;
            l9 = vader_core_wit$span(l0);
            t1 = vader_core_wit$at_keyword(l0, 3502u);
            if (t1) {
                vader_core_wit$word(l0);
                l11 = vader_core_wit$use_decl(l0, l8, l9);
                l12 = l11;
                if (l11.tag == 1485u) {
                    t0 = l12.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l10 = l11.payload.obj;
                vader_array_push_ref((vader_array_t*) ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) l7)->f_uses, l10);
                continue;
            }
            t1 = vader_core_wit$at_type_keyword(l0);
            if (t1) {
                l14 = vader_core_wit$type_decl(l0, l4, l8, l9);
                l15 = l14;
                if (l14.tag == 1485u) {
                    t0 = l15.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l13 = l14.payload.obj;
                vader_array_push_ref((vader_array_t*) ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) l7)->f_types, l13);
            } else {
                l17 = vader_core_wit$function_decl(l0, l4, l8, l9);
                l18 = l17;
                if (l17.tag == 1485u) {
                    t0 = l18.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l16 = l17.payload.obj;
                vader_array_push_ref((vader_array_t*) ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) l7)->f_functions, l16);
            }
            continue;
        }
        break;
    }
    { vader_box_t __vret = vader_ref_box(l7); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$interface_constant(void* l0) {
    void* l1 = NULL;
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[5] = { &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_wit$WitOwner_t*) l0)->f_package;
    l2 = ((vader_struct_vader_core_wit$WitPackageName_t*) l1)->f_namespace;
    l3 = ((vader_struct_vader_core_wit$WitPackageName_t*) l1)->f_name;
    l4 = ((vader_struct_vader_core_wit$WitOwner_t*) l0)->f_interface;
    l5 = ((vader_struct_vader_core_wit$WitPackageName_t*) l1)->f_version;
    t0 = concat_9(1210u, l2, 565u, l3, 325u, l4, 326u, l5, 327u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$interface_of(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    int64_t l5, l6, l13, l14;
    vader_string_t l7 = 0;
    vader_box_t l8 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null(), l18 = vader_box_null(), l19 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[6] = { &l8, &l10, &l11, &l18, &l19, &t0 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l9, &l12, &l15, &l16, &l17, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_wit$InterfaceScope_t*) l1)->f_owner;
    vader_array_t* _a0_arr = vader_array_new(483u, 0u, 13u, 2755u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(243u, 0u, 13u, 1500u);
    l4 = (void*) _a1_arr;
    vader_struct_vader_core_wit$WitInterface_t* _a2_obj = (vader_struct_vader_core_wit$WitInterface_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitInterface_t));
    vader_obj_header_init(_a2_obj, 1494u);
    _a2_obj->f_owner = l2;
    _a2_obj->f_types = l3;
    _a2_obj->f_functions = l4;
    l2 = (void*) _a2_obj;
    vader_array_t* _a3_arr = vader_array_new(243u, 0u, 13u, 1500u);
    l3 = (void*) _a3_arr;
    l4 = ((vader_struct_vader_core_wit$InterfaceScope_t*) l1)->f_names;
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l6];
        l7 = t0.payload.s;
        l9 = ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) ((vader_struct_vader_core_wit$InterfaceScope_t*) l1)->f_decl)->f_span;
        l10 = vader_core_wit$resolve_name(l0, l1, l7, l9);
        l11 = l10;
        if (l10.tag == 1485u) {
            t1 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = l10;
        vader_array_push_ref((vader_array_t*) ((vader_struct_vader_core_wit$WitInterface_t*) l2)->f_types, l8.payload.obj);
        if (l8.tag == 1511u) {
            l12 = vader_core_wit$resource_methods(l1, l7);
            l13 = vader_array_length(((vader_array_t*) l12));
            l14 = INT64_C(0);
            while ((l14 < l13)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l14)
                l15 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l14);
                l17 = l8.payload.obj;
                l18 = vader_core_wit$function_of(l0, l1, l15, vader_ref_box(l17));
                l19 = l18;
                if (l18.tag == 1485u) {
                    t1 = l19.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l16 = l18.payload.obj;
                vader_array_push_ref((vader_array_t*) l3, l16);
                l14 = (l14 + INT64_C(1));
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) ((vader_struct_vader_core_wit$InterfaceScope_t*) l1)->f_decl)->f_functions;
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
        l9 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l6);
        t2 = __lambda_vader_core_wit_5(l9);
        if (t2) {
            l12 = l9;
            l8 = vader_core_wit$function_of(l0, l1, l12, vader_box_obj(0u, NULL));
            l10 = l8;
            if (l8.tag == 1485u) {
                t1 = l10.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l15 = l8.payload.obj;
            vader_array_push_ref((vader_array_t*) ((vader_struct_vader_core_wit$WitInterface_t*) l2)->f_functions, l15);
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_push_all((vader_array_t*) ((vader_struct_vader_core_wit$WitInterface_t*) l2)->f_functions, (vader_array_t*) l3);
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_core_wit$is_resource(vader_box_t l0) {
    vader_box_t l1;
    void* t0;
    l1 = l0;
    while (l1.tag == 1478u) {
        t0 = l1.payload.obj;
        l1 = ((vader_struct_vader_core_wit$WitAlias_t*) t0)->f_target;
    }
    return l1.tag == 1511u;
}

bool vader_core_wit$is_stable(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_core_wit$WitGate_t*) l0)->f_unstable;
    return t0 == 0u;
}

static bool vader_core_wit$is_word_byte(uint8_t l0) {
    bool l1, l2;
    if ((INT32_C(97) <= l0)) {
        l1 = (l0 <= INT32_C(122));
    } else {
        l1 = false;
    }
    if (l1) {
        l1 = true;
    } else {
        if ((INT32_C(65) <= l0)) {
            l2 = (l0 <= INT32_C(90));
        } else {
            l2 = false;
        }
        l1 = l2;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = std_ascii$is_digit_byte(l0);
    }
    if (l1) {
        return true;
    }
    return l0 == INT32_C(45);
}

static vader_string_t vader_core_wit$left_out(void* l0, void* l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_wit$WitNamedFunction_t*) l0)->f_name;
    l3 = vader_core_wit$NoForm$std_core$Error$message(l1);
    t0 = concat_5(543u, l2, 1475u, l3, 493u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$list_expr(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null(), l3 = vader_box_null();
    void* t0 = NULL;
    uint8_t t1;
    vader_box_t* gc_roots[3] = { &l1, &l2, &l3 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_core_wit$word(l0);
    l1 = vader_core_wit$expect(l0, (uint8_t) 60);
    l2 = l1;
    if (l1.tag == 1485u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_core_wit$type_expr(l0);
    l3 = l2;
    if (l2.tag == 1485u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l2;
    t1 = vader_core_wit$peek(l0);
    if (t1 == INT32_C(44)) {
        t0 = vader_core_wit$fail_here(l0, 1872u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_core_wit$expect(l0, (uint8_t) 62);
    l3 = l2;
    if (!(l2.tag == 1485u)) {
        vader_struct_vader_core_wit$WitListExpr_t* _a0_obj = (vader_struct_vader_core_wit$WitListExpr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitListExpr_t));
        vader_obj_header_init(_a0_obj, 1497u);
        _a0_obj->f_element = l1;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l3.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$members(void* l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null(), l14 = vader_box_null(), l15 = vader_box_null(), l16 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null(), l19 = vader_box_null();
    void* l4 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[14] = {
        &l2, &l3, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &l15, &l16, &l17, &l18, &l19,
    };
    void** gc_raw_roots[5] = { &l0, &l4, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l5, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 14u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_core_wit$expect(l0, (uint8_t) 123);
    l3 = l2;
    if (l2.tag == 1485u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(242u, 0u, 13u, 1498u);
    l4 = (void*) _a0_arr;
    for (;;) {
        t1 = vader_core_wit$skip(l0, (uint8_t) 125);
        if (!(t1)) {
            l5 = vader_core_wit$take_doc(l0);
            l6 = vader_core_wit$span(l0);
            l2 = vader_core_wit$identifier(l0);
            l3 = l2;
            if (l2.tag == 1485u) {
                t0 = l3.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = l2.payload.s;
            vader_struct_vader_core_wit$WitMemberDecl_t* _a1_obj = (vader_struct_vader_core_wit$WitMemberDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitMemberDecl_t));
            vader_obj_header_init(_a1_obj, 1498u);
            _a1_obj->f_name = t2;
            _a1_obj->f_type = vader_box_obj(0u, NULL);
            _a1_obj->f_doc = l5;
            _a1_obj->f_span = l6;
            l7 = (void*) _a1_obj;
            if (l1 == 3102u) {
                l8 = vader_core_wit$expect(l0, (uint8_t) 58);
                l9 = l8;
                if (l8.tag == 1485u) {
                    t0 = l9.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l11 = vader_core_wit$type_expr(l0);
                l12 = l11;
                if (l11.tag == 1485u) {
                    t0 = l12.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l10 = l11;
                ((vader_struct_vader_core_wit$WitMemberDecl_t*) l7)->f_type = l10;
                VADER_WRITE_BARRIER((vader_struct_vader_core_wit$WitMemberDecl_t*) l7);
            } else if (l1 == 3681u) {
                t1 = vader_core_wit$skip(l0, (uint8_t) 40);
                if (t1) {
                    l14 = vader_core_wit$type_expr(l0);
                    l15 = l14;
                    if (l14.tag == 1485u) {
                        t0 = l15.payload.obj;
                        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l13 = l14;
                    l16 = vader_core_wit$expect(l0, (uint8_t) 41);
                    l17 = l16;
                    if (l16.tag == 1485u) {
                        t0 = l17.payload.obj;
                        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    ((vader_struct_vader_core_wit$WitMemberDecl_t*) l7)->f_type = l13;
                    VADER_WRITE_BARRIER((vader_struct_vader_core_wit$WitMemberDecl_t*) l7);
                }
            }
            vader_array_push_ref((vader_array_t*) l4, l7);
            t1 = vader_core_wit$skip(l0, (uint8_t) 44);
            if (t1) {
                continue;
            }
            l18 = vader_core_wit$expect(l0, (uint8_t) 125);
            l19 = l18;
            if (!(l18.tag == 1485u)) {
                break;
            }
            t0 = l19.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        break;
    }
    { vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$named_error_impl(vader_string_t l0, vader_string_t l1) {
    vader_string_t t0;
    t0 = concat_5(1u, l0, 184u, l1, 321u);
    return t0;
}

static vader_box_t vader_core_wit$named_expr(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_core_wit$identifier(l0);
    l3 = l2;
    if (l2.tag == 1485u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l2.payload.s;
    vader_struct_vader_core_wit$WitNameExpr_t* _a0_obj = (vader_struct_vader_core_wit$WitNameExpr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitNameExpr_t));
    vader_obj_header_init(_a0_obj, 1499u);
    _a0_obj->f_name = t1;
    _a0_obj->f_span = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$named_text(void* l0, void* l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    void* l5 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_core_wit$wit_owner_text(l1);
    l4 = vader_core_wit$wit_owner_text(((vader_struct_vader_core_wit$Generation_t*) l0)->f_owner);
    if (!(l3 == l4)) {
        l3 = vader_core_wit$interface_alias(l1);
        l5 = ((vader_struct_vader_core_wit$Generation_t*) l0)->f_imports;
        l4 = vader_core_wit$wit_owner_text(l1);
        std_collections$Map$std_core$IndexSet$set_at__string__string(l5, l3, l4);
        l4 = vader_core_wit$pascal_name(l2);
        t0 = concat_3(l3, 492u, l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_wit$pascal_name(l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$named_text_1(void* l0, vader_string_t l1) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &t0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_core_wit$wit_owner_text(l0);
    t1 = concat_3(t0, 492u, l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$named_type(void* l0, void* l1, vader_string_t l2, void* l3) {
    vader_box_t l4 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null();
    void* l5 = NULL;
    vader_string_t l6 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[4] = { &l4, &l7, &l8, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_core_wit$InterfaceScope_t*) l1)->f_declared, l2);
    if (!(l4.tag == 0u)) {
        l5 = l4.payload.obj;
        t0 = vader_core_wit$declared_type(l0, l1, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_core_wit$InterfaceScope_t*) l1)->f_used, l2);
    if (l4.tag == 0u) {
        l6 = ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) ((vader_struct_vader_core_wit$InterfaceScope_t*) l1)->f_decl)->f_name;
        l6 = concat_5(2986u, l2, 1433u, l6, 1310u);
        t1 = vader_core_wit$wit_error(l3, l6);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l4.payload.obj;
    l7 = vader_core_wit$used_type(l0, l5);
    l8 = l7;
    if (l7.tag == 1485u) {
        t1 = l8.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l7;
    l5 = ((vader_struct_vader_core_wit$InterfaceScope_t*) l1)->f_owner;
    vader_struct_vader_core_wit$WitAlias_t* _a0_obj = (vader_struct_vader_core_wit$WitAlias_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitAlias_t));
    vader_obj_header_init(_a0_obj, 1478u);
    _a0_obj->f_name = l2;
    _a0_obj->f_owner = l5;
    _a0_obj->f_target = l4;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$namespaced_name(void* l0) {
    void* l1 = NULL;
    vader_string_t l2 = 0;
    vader_string_t l6 = 0;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    int64_t l5;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &l4, &t3 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l1 = (void*) _a0_arr;
    l3 = vader_core_wit$identifier(l0);
    l4 = l3;
    if (l3.tag == 1485u) {
        t0 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.s;
    vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l2));
    for (;;) {
        t1 = vader_core_wit$skip(l0, (uint8_t) 58);
        if (t1) {
            l3 = vader_core_wit$identifier(l0);
            l4 = l3;
            if (l3.tag == 1485u) {
                t0 = l4.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l2 = l3.payload.s;
            vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l2));
            continue;
        }
        break;
    }
    t2 = vader_array_length(((vader_array_t*) l1));
    if (!((t2 < INT64_C(2)))) {
        t2 = vader_array_length(((vader_array_t*) l1));
        l5 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a1_arr = vader_array_slice((vader_array_t*) l1, (int64_t) INT64_C(0), (int64_t) l5);
        t0 = (void*) _a1_arr;
        l2 = std_string$join(t0, 565u);
        t2 = vader_array_length(((vader_array_t*) l1));
        l5 = vader_chk_sub(i64, t2, INT64_C(1));
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t3 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l5];
        l6 = t3.payload.s;
        vader_struct_vader_core_wit$WitPackageName_t* _a3_obj = (vader_struct_vader_core_wit$WitPackageName_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitPackageName_t));
        vader_obj_header_init(_a3_obj, 1505u);
        _a3_obj->f_namespace = l2;
        _a3_obj->f_name = l6;
        _a3_obj->f_version = 0u;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_core_wit$fail_here(l0, 2440u);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_core_wit$no_form(vader_box_t l0, vader_string_t l1) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_wit$NoForm_t* _a0_obj = (vader_struct_vader_core_wit$NoForm_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$NoForm_t));
    vader_obj_header_init(_a0_obj, 1474u);
    _a0_obj->f_type = l0;
    _a0_obj->f_what = l1;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$open_scope(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l16 = NULL;
    void* l18 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    int64_t l9, l10, l11, l12;
    vader_string_t l13 = 0;
    vader_string_t l17 = 0;
    vader_string_t l19 = 0;
    vader_box_t l14 = vader_box_null(), l15 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l14, &l15 };
    void** gc_raw_roots[14] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l16, &l18, &l20, &l21, &t1,
    };
    vader_string_t* gc_atom_roots[3] = { &l13, &l17, &l19 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 634u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 626u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
    vader_obj_header_init(_a3_obj, 970u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(28u, 0u, 0u, 623u);
    l3 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(35u, 0u, 0u, 634u);
    l4 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(29u, 0u, 7u, 626u);
    l5 = (void*) _a6_arr;
    vader_struct_std_collections$Map__string__Any_t* _a7_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
    vader_obj_header_init(_a7_obj, 970u);
    _a7_obj->f_ekeys = l3;
    _a7_obj->f_evals = l4;
    _a7_obj->f_index = l5;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(28u, 0u, 0u, 623u);
    l4 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(28u, 0u, 0u, 623u);
    l5 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(35u, 0u, 0u, 634u);
    l6 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(29u, 0u, 7u, 626u);
    l7 = (void*) _a11_arr;
    vader_struct_std_collections$Map__string__Any_t* _a12_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
    vader_obj_header_init(_a12_obj, 970u);
    _a12_obj->f_ekeys = l5;
    _a12_obj->f_evals = l6;
    _a12_obj->f_index = l7;
    _a12_obj->f_mask = INT64_C(0);
    _a12_obj->f_grow_at = INT64_C(0);
    _a12_obj->f_size = INT64_C(0);
    _a12_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a12_obj;
    vader_array_t* _a13_arr = vader_array_new(28u, 0u, 0u, 623u);
    l6 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(26u, 0u, 12u, 621u);
    l7 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(29u, 0u, 7u, 626u);
    l8 = (void*) _a15_arr;
    vader_struct_std_collections$Map__string__bool_t* _a16_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a16_obj, 976u);
    _a16_obj->f_ekeys = l6;
    _a16_obj->f_evals = l7;
    _a16_obj->f_index = l8;
    _a16_obj->f_mask = INT64_C(0);
    _a16_obj->f_grow_at = INT64_C(0);
    _a16_obj->f_size = INT64_C(0);
    _a16_obj->f_tombs = INT64_C(0);
    l6 = (void*) _a16_obj;
    vader_struct_vader_core_wit$InterfaceScope_t* _a17_obj = (vader_struct_vader_core_wit$InterfaceScope_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$InterfaceScope_t));
    vader_obj_header_init(_a17_obj, 1473u);
    _a17_obj->f_decl = l0;
    _a17_obj->f_owner = l1;
    _a17_obj->f_declared = l2;
    _a17_obj->f_used = l3;
    _a17_obj->f_names = l4;
    _a17_obj->f_resolved = l5;
    _a17_obj->f_pending = l6;
    l2 = (void*) _a17_obj;
    l3 = ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) l0)->f_uses;
    l9 = vader_array_length(((vader_array_t*) l3));
    l10 = INT64_C(0);
    while ((l10 < l9)) {
        vader_array_t* _a18_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        l4 = vader_array_ref_load_obj(_a18_slotarr->buf, vader_array_offset(_a18_slotarr) + (size_t) l10);
        t0 = __lambda_vader_core_wit_3(l4);
        if (t0) {
            l5 = l4;
            l6 = ((vader_struct_vader_core_wit$WitUseDecl_t*) l5)->f_names;
            l11 = vader_array_length(((vader_array_t*) l6));
            l12 = INT64_C(0);
            while ((l12 < l11)) {
                vader_array_t* _a19_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
                l7 = vader_array_ref_load_obj(_a19_slotarr->buf, vader_array_offset(_a19_slotarr) + (size_t) l12);
                l13 = ((vader_struct_vader_core_wit$WitUseName_t*) l7)->f_local;
                l8 = ((vader_struct_vader_core_wit$WitUseName_t*) l7)->f_span;
                l14 = vader_core_wit$take_name(l2, l13, l8);
                l15 = l14;
                if (l14.tag == 1485u) {
                    t1 = l15.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l16 = ((vader_struct_vader_core_wit$InterfaceScope_t*) l2)->f_used;
                l17 = ((vader_struct_vader_core_wit$WitUseName_t*) l7)->f_local;
                l18 = ((vader_struct_vader_core_wit$WitUseDecl_t*) l5)->f_path;
                l19 = ((vader_struct_vader_core_wit$WitUseName_t*) l7)->f_name;
                l20 = ((vader_struct_vader_core_wit$WitUseName_t*) l7)->f_span;
                vader_struct_vader_core_wit$UsedName_t* _a20_obj = (vader_struct_vader_core_wit$UsedName_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$UsedName_t));
                vader_obj_header_init(_a20_obj, 1477u);
                _a20_obj->f_path = l18;
                _a20_obj->f_name = l19;
                _a20_obj->f_span = l20;
                l21 = (void*) _a20_obj;
                std_collections$Map$std_core$IndexSet$set_at__string__Any(l16, l17, vader_ref_box(l21));
                l12 = (l12 + INT64_C(1));
            }
        }
        l10 = (l10 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) l0)->f_types;
    l9 = vader_array_length(((vader_array_t*) l3));
    l10 = INT64_C(0);
    while ((l10 < l9)) {
        vader_array_t* _a21_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        l4 = vader_array_ref_load_obj(_a21_slotarr->buf, vader_array_offset(_a21_slotarr) + (size_t) l10);
        t0 = __lambda_vader_core_wit_4(l4);
        if (t0) {
            l5 = l4;
            l13 = ((vader_struct_vader_core_wit$WitTypeDecl_t*) l5)->f_name;
            l6 = ((vader_struct_vader_core_wit$WitTypeDecl_t*) l5)->f_span;
            l14 = vader_core_wit$take_name(l2, l13, l6);
            l15 = l14;
            if (l14.tag == 1485u) {
                t1 = l15.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l7 = ((vader_struct_vader_core_wit$InterfaceScope_t*) l2)->f_declared;
            l17 = ((vader_struct_vader_core_wit$WitTypeDecl_t*) l5)->f_name;
            std_collections$Map$std_core$IndexSet$set_at__string__Any(l7, l17, vader_ref_box(l5));
        }
        l10 = (l10 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$option_expr(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_core_wit$argument(l0);
    l2 = l1;
    if (l1.tag == 1485u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_wit$WitOptionExpr_t* _a0_obj = (vader_struct_vader_core_wit$WitOptionExpr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitOptionExpr_t));
    vader_obj_header_init(_a0_obj, 1502u);
    _a0_obj->f_value = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$optional_alias_free(vader_box_t l0) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 0u)) {
        t0 = vader_core_wit$alias_free(l0);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_core_wit$optional_argument(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null(), l3 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l2, &l3 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_core_wit$word(l0);
    t0 = vader_core_wit$skip(l0, (uint8_t) 60);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l1 = vader_core_wit$type_expr(l0);
    l2 = l1;
    if (l1.tag == 1485u) {
        t1 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_core_wit$expect(l0, (uint8_t) 62);
    l3 = l2;
    if (!(l2.tag == 1485u)) {
        { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l3.payload.obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$optional_tag_text(vader_box_t l0) {
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 0u)) {
        t0 = vader_core_wit$tag_text(l0);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 3699u; }
}

static vader_box_t vader_core_wit$optional_type_of(void* l0, void* l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l3, &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l2.tag == 0u)) {
        l3 = l2;
        t0 = vader_core_wit$type_of(l0, l1, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_core_wit$own_expr(void* l0, void* l1) {
    vader_box_t t0;
    t0 = vader_core_wit$resource_argument(l0, l1, 3045u);
    return t0;
}

static vader_box_t vader_core_wit$package_decl(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* t0 = NULL;
    uint8_t t1;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_core_wit$word(l0);
    l2 = vader_core_wit$package_name(l0);
    l3 = l2;
    if (l2.tag == 1485u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l2.payload.obj;
    t1 = vader_core_wit$peek(l0);
    if (t1 == INT32_C(123)) {
        t0 = vader_core_wit$fail_here(l0, 1885u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_core_wit$expect(l0, (uint8_t) 59);
    l3 = l2;
    if (!(l2.tag == 1485u)) {
        { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l3.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$package_name(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    vader_string_t l4 = 0;
    void* t0 = NULL;
    uint8_t t1;
    bool t2;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_core_wit$namespaced_name(l0);
    l3 = l2;
    if (l2.tag == 1485u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l2.payload.obj;
    t1 = vader_core_wit$peek(l0);
    if (t1 == INT32_C(64)) {
        t2 = vader_core_wit$at_gate(l0);
        if (t2) {
            { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_core_wit$advance(l0);
        l2 = vader_core_wit$version(l0);
        l3 = l2;
        if (l2.tag == 1485u) {
            t0 = l3.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = l2.payload.s;
        ((vader_struct_vader_core_wit$WitPackageName_t*) l1)->f_version = l4;
        { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$package_of(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l8 = vader_box_null();
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l11 = NULL;
    int64_t l4, l5;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_string_t l14 = 0;
    void* t0 = NULL;
    void* t3 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l2, &l8 };
    void** gc_raw_roots[8] = { &l0, &l1, &l3, &l6, &l7, &l11, &t0, &t3 };
    vader_string_t* gc_atom_roots[6] = { &l9, &l10, &l12, &l13, &l14, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_box_obj(0u, NULL);
    l3 = l0;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
        l8 = ((vader_struct_vader_core_wit$WitDocument_t*) l6)->f_package;
        if (l8.tag == 0u) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l7 = l8.payload.obj;
        if (!(l2.tag == 0u)) {
            t0 = l2.payload.obj;
            l9 = vader_core_wit$wit_package_text(t0);
            l10 = vader_core_wit$wit_package_text(l7);
            if (l9 != l10) {
                t1 = ((vader_struct_vader_core_wit$WitDocument_t*) l6)->f_file;
                vader_struct_vader_core_wit$WitSpan_t* _a1_obj = (vader_struct_vader_core_wit$WitSpan_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitSpan_t));
                vader_obj_header_init(_a1_obj, 1516u);
                _a1_obj->f_file = t1;
                _a1_obj->f_line = INT32_C(1);
                _a1_obj->f_column = INT32_C(1);
                l11 = (void*) _a1_obj;
                l12 = vader_core_wit$wit_package_text(l7);
                t0 = l2.payload.obj;
                l13 = vader_core_wit$wit_package_text(t0);
                l14 = concat_5(3049u, l12, 1435u, l13, 1310u);
                t0 = vader_core_wit$wit_error(l11, l14);
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        l2 = vader_ref_box(l7);
        l5 = (l5 + INT64_C(1));
    }
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_array_length(((vader_array_t*) l1));
    if ((t2 > INT64_C(0))) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) INT32_C(0));
        l9 = ((vader_struct_vader_core_wit$WitSource_t*) t0)->f_path;
    } else {
        l9 = 0u;
    }
    vader_struct_vader_core_wit$WitSpan_t* _a3_obj = (vader_struct_vader_core_wit$WitSpan_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitSpan_t));
    vader_obj_header_init(_a3_obj, 1516u);
    _a3_obj->f_file = l9;
    _a3_obj->f_line = INT32_C(1);
    _a3_obj->f_column = INT32_C(1);
    t0 = (void*) _a3_obj;
    t3 = vader_core_wit$wit_error(t0, 2967u);
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$parameter_text(void* l0, void* l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_string_t t4 = 0;
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[4] = { &l2, &l3, &l4, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &t0, &t1 };
    vader_string_t* gc_atom_roots[2] = { &t4, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2.tag == 1490u) {
        t0 = l2.payload.obj;
        t1 = vader_core_wit$no_form(vader_ref_box(t0), 1861u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2.tag == 1517u)) {
        l3 = l2;
        t2 = vader_core_wit$type_text(l0, l3);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = ((vader_struct_vader_core_wit$WitNamedFunction_t*) l1)->f_is_async;
    if (t3) {
        t0 = l2.payload.obj;
        t1 = vader_core_wit$no_form(vader_ref_box(t0), 1903u);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    l3 = ((vader_struct_vader_core_wit$WitStream_t*) t0)->f_element;
    l3 = vader_core_wit$type_text(l0, l3);
    l4 = l3;
    if (l3.tag == 1474u) {
        t0 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t4 = l3.payload.s;
    t5 = vader_core_wit$grouped(t4);
    t4 = concat_2(t5, 1224u);
    { vader_box_t __vret = vader_box_string(623u, t4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$parameters_text(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    vader_string_t l7 = 0;
    vader_string_t l11 = 0;
    vader_box_t l8 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[3] = { &l8, &l9, &l10 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l7, &l11, &t1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_core_wit$WitFunction_t*) ((vader_struct_vader_core_wit$WitNamedFunction_t*) l1)->f_type)->f_params;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
        l8 = ((vader_struct_vader_core_wit$WitParam_t*) l6)->f_type;
        l9 = vader_core_wit$parameter_text(l0, l1, l8);
        l10 = l9;
        if (l9.tag == 1474u) {
            t0 = l10.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = l9.payload.s;
        t1 = ((vader_struct_vader_core_wit$WitParam_t*) l6)->f_name;
        t2 = vader_core_wit$snake_name(t1);
        l11 = concat_3(t2, 566u, l7);
        vader_array_push_scalar((vader_array_t*) l2, vader_box_string(623u, l11));
        l5 = (l5 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$params(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null();
    void* l3 = NULL;
    void* l10 = NULL;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[9] = { &l1, &l2, &l5, &l6, &l7, &l8, &l9, &l11, &l12 };
    void** gc_raw_roots[4] = { &l0, &l3, &l10, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 9u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_core_wit$expect(l0, (uint8_t) 40);
    l2 = l1;
    if (l1.tag == 1485u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(246u, 0u, 13u, 1507u);
    l3 = (void*) _a0_arr;
    for (;;) {
        t1 = vader_core_wit$skip(l0, (uint8_t) 41);
        if (!(t1)) {
            l1 = vader_core_wit$identifier(l0);
            l2 = l1;
            if (l1.tag == 1485u) {
                t0 = l2.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l4 = l1.payload.s;
            l5 = vader_core_wit$expect(l0, (uint8_t) 58);
            l6 = l5;
            if (l5.tag == 1485u) {
                t0 = l6.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l8 = vader_core_wit$type_expr(l0);
            l9 = l8;
            if (l8.tag == 1485u) {
                t0 = l9.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l7 = l8;
            vader_struct_vader_core_wit$WitParamDecl_t* _a1_obj = (vader_struct_vader_core_wit$WitParamDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitParamDecl_t));
            vader_obj_header_init(_a1_obj, 1507u);
            _a1_obj->f_name = l4;
            _a1_obj->f_type = l7;
            l10 = (void*) _a1_obj;
            vader_array_push_ref((vader_array_t*) l3, l10);
            t1 = vader_core_wit$skip(l0, (uint8_t) 44);
            if (t1) {
                continue;
            }
            l11 = vader_core_wit$expect(l0, (uint8_t) 41);
            l12 = l11;
            if (!(l11.tag == 1485u)) {
                break;
            }
            t0 = l12.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        break;
    }
    { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_wit$pascal_name(vader_string_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    int64_t l3, l4, l7;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_string_t l8 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[5] = { &l0, &l5, &l6, &l8, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 1096u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = std_string$split(l0, 479u);
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l4];
        l5 = t1.payload.s;
        t2 = vader_host_std_core$Intrinsic$byte_len(l5);
        if (t2 == INT64_C(0)) {
            l4 = (l4 + INT64_C(1));
            continue;
        }
        t3 = vader_host_std_core$Intrinsic$byte_slice(l5, INT64_C(0), INT64_C(1));
        l6 = std_string$to_upper(t3);
        std_string__builder$append(l1, l6);
        l7 = vader_host_std_core$Intrinsic$byte_len(l5);
        t3 = vader_host_std_core$Intrinsic$byte_slice(l5, INT64_C(1), l7);
        l8 = std_string$to_lower(t3);
        std_string__builder$append(l1, l8);
        l4 = (l4 + INT64_C(1));
    }
    t3 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_core_wit$payload_cases(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    int64_t l3, l4;
    bool t0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_wit$WitVariant_t*) l0)->f_cases;
    vader_array_t* _a0_arr = vader_array_new(237u, 0u, 13u, 1481u);
    l2 = (void*) _a0_arr;
    l3 = vader_array_length(((vader_array_t*) l1));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
        t0 = __lambda_vader_core_wit_13(l5);
        if (t0) {
            l6 = l5;
            vader_array_push_ref((vader_array_t*) l2, l6);
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_core_wit$peek(void* l0) {
    uint8_t t0;
    t0 = vader_core_wit$peek_at(l0, INT64_C(0));
    return t0;
}

static uint8_t vader_core_wit$peek_at(void* l0, int64_t l1) {
    int64_t l2, l3;
    vader_string_t l4;
    int64_t t0;
    vader_string_t t1;
    uint8_t t2;
    t0 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_at;
    l2 = vader_chk_add(i64, t0, l1);
    t1 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_text;
    l3 = vader_host_std_core$Intrinsic$byte_len(t1);
    if (!((l2 >= l3))) {
        l4 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_text;
        t0 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_at;
        l2 = vader_chk_add(i64, t0, l1);
        t2 = vader_host_std_core$Intrinsic$byte_at(l4, l2);
        return t2;
    }
    return (uint8_t) 0;
}

static uint8_t vader_core_wit$peek_word_end(void* l0) {
    int64_t l1;
    vader_string_t t0;
    uint8_t t1;
    t0 = vader_core_wit$word_here(l0);
    l1 = vader_host_std_core$Intrinsic$byte_len(t0);
    t1 = vader_core_wit$peek_at(l0, l1);
    return t1;
}

static void vader_core_wit$push_declared_errors(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1509u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_wit$WitRecord_t*) t0)->f_fields;
        l3 = vader_array_length(((vader_array_t*) l2));
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
            vader_core_wit$push_errors(((vader_struct_vader_core_wit$WitParam_t*) t0)->f_type, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 1526u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_wit$WitVariant_t*) t0)->f_cases;
        l3 = vader_array_length(((vader_array_t*) l2));
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
            vader_core_wit$push_optional_errors(((vader_struct_vader_core_wit$WitCase_t*) t0)->f_type, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 1478u) {
        t0 = l0.payload.obj;
        vader_core_wit$push_errors(((vader_struct_vader_core_wit$WitAlias_t*) t0)->f_target, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_core_wit$push_errors(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    vader_string_t l7 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l5, &l6, &t1 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1496u) {
        t0 = l0.payload.obj;
        vader_core_wit$push_errors(((vader_struct_vader_core_wit$WitList_t*) t0)->f_element, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 1501u) {
        t0 = l0.payload.obj;
        vader_core_wit$push_errors(((vader_struct_vader_core_wit$WitOption_t*) t0)->f_value, l1);
    } else if (l0.tag == 1519u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_wit$WitTuple_t*) t0)->f_elements;
        l3 = vader_array_length(((vader_array_t*) l2));
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l4];
            vader_core_wit$push_errors(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 1513u) {
        t0 = l0.payload.obj;
        vader_core_wit$push_optional_errors(((vader_struct_vader_core_wit$WitResult_t*) t0)->f_ok, l1);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_core_wit$WitResult_t*) t0)->f_error;
        if (l5.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l6 = vader_core_wit$declared_tag(l5);
        if (!(l6.tag == 0u)) {
            l7 = l6.payload.s;
            std_collections$add__string(l1, l7);
        }
        vader_core_wit$push_errors(l5, l1);
    } else if (l0.tag == 1517u) {
        t0 = l0.payload.obj;
        vader_core_wit$push_errors(((vader_struct_vader_core_wit$WitStream_t*) t0)->f_element, l1);
    } else if (l0.tag == 1490u) {
        t0 = l0.payload.obj;
        vader_core_wit$push_optional_errors(((vader_struct_vader_core_wit$WitFuture_t*) t0)->f_value, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_core_wit$push_optional_errors(vader_box_t l0, void* l1) {
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_core_wit$push_errors(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_core_wit$push_tags(vader_box_t l0, void* l1) {
    vader_string_t l2 = 0;
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    vader_box_t l7 = vader_box_null();
    uint8_t t0;
    void* t1 = NULL;
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l7, &t4 };
    void** gc_raw_roots[4] = { &l1, &l3, &l6, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 628u) {
        t0 = ((uint8_t) l0.payload.i);
        l2 = vader_core_wit$scalar_text(t0);
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 1483u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 3423u);
        t1 = l0.payload.obj;
        t2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_wit$WitEnum_t*) t1)->f_cases));
        l5 = vader_core_wit$enum_case_bits(t2);
        l4 = std_core$write_int(l3, l4, l5);
        l2 = std_core$finish_buffer(l3, l4);
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l2));
    } else if (l0.tag == 1526u) {
        t1 = l0.payload.obj;
        vader_core_wit$push_variant_tags(t1, l1);
    } else if (l0.tag == 1509u) {
        t1 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_wit$WitRecord_t*) t1)->f_owner;
        t1 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_wit$WitRecord_t*) t1)->f_name;
        l2 = vader_core_wit$struct_tag(l3, l2);
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l2));
    } else if (l0.tag == 1486u) {
        t1 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_wit$WitFlags_t*) t1)->f_owner;
        t1 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_wit$WitFlags_t*) t1)->f_name;
        l2 = vader_core_wit$struct_tag(l3, l2);
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l2));
    } else if (l0.tag == 1511u) {
        t1 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_wit$WitResource_t*) t1)->f_owner;
        t1 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_wit$WitResource_t*) t1)->f_name;
        l2 = vader_core_wit$struct_tag(l3, l2);
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l2));
    } else if (l0.tag == 1478u) {
        t1 = l0.payload.obj;
        vader_core_wit$push_tags(((vader_struct_vader_core_wit$WitAlias_t*) t1)->f_target, l1);
    } else if (l0.tag == 1493u) {
        t1 = l0.payload.obj;
        vader_core_wit$push_tags(((vader_struct_vader_core_wit$WitHandle_t*) t1)->f_resource, l1);
    } else if (l0.tag == 1496u) {
        t1 = l0.payload.obj;
        t3 = vader_core_wit$tag_text(((vader_struct_vader_core_wit$WitList_t*) t1)->f_element);
        l2 = concat_2(t3, 1224u);
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l2));
    } else if (l0.tag == 1501u) {
        t1 = l0.payload.obj;
        vader_core_wit$push_tags(((vader_struct_vader_core_wit$WitOption_t*) t1)->f_value, l1);
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, 3004u));
    } else if (l0.tag == 1519u) {
        t1 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_wit$WitTuple_t*) t1)->f_elements;
        t2 = vader_array_length(((vader_array_t*) l3));
        vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t2, 0u, 623u);
        l6 = (void*) _a0_arr;
        l4 = vader_array_length(((vader_array_t*) l3));
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t4 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l5];
            l2 = vader_core_wit$tag_text(t4);
            vader_array_push_scalar((vader_array_t*) l6, vader_box_string(623u, l2));
            l5 = (l5 + INT64_C(1));
        }
        l2 = std_string$join(l6, 444u);
        l2 = concat_3(1221u, l2, 1237u);
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l2));
    } else if (l0.tag == 1513u) {
        t1 = l0.payload.obj;
        l7 = ((vader_struct_vader_core_wit$WitResult_t*) t1)->f_ok;
        if (l7.tag == 0u) {
            vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, 3699u));
        } else {
            vader_core_wit$push_tags(l7, l1);
        }
        t1 = l0.payload.obj;
        l7 = ((vader_struct_vader_core_wit$WitResult_t*) t1)->f_error;
        if (!(l7.tag == 0u)) {
            vader_core_wit$push_tags(l7, l1);
        }
    } else if (l0.tag == 1517u) {
        t1 = l0.payload.obj;
        l2 = vader_core_wit$tag_text(((vader_struct_vader_core_wit$WitStream_t*) t1)->f_element);
        l2 = concat_3(3235u, l2, 632u);
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l2));
    } else if (l0.tag == 1490u) {
        t1 = l0.payload.obj;
        l2 = vader_core_wit$optional_tag_text(((vader_struct_vader_core_wit$WitFuture_t*) t1)->f_value);
        l2 = concat_3(2587u, l2, 632u);
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l2));
    } else {
        if (!(l0.tag == 1522u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t1 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_wit$WitUnsupported_t*) t1)->f_reason;
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l2));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_core_wit$push_variant_tags(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    int64_t t0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l7 };
    vader_string_t* gc_atom_roots[4] = { &l6, &l8, &l9, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_core_wit$bare_cases(l0);
    t0 = vader_array_length(((vader_array_t*) l2));
    if ((t0 > INT64_C(0))) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 3423u);
        t0 = vader_array_length(((vader_array_t*) l2));
        l5 = vader_core_wit$enum_case_bits(t0);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l6));
    }
    l2 = vader_core_wit$payload_cases(l0);
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
        l7 = ((vader_struct_vader_core_wit$WitVariant_t*) l0)->f_owner;
        l6 = ((vader_struct_vader_core_wit$WitVariant_t*) l0)->f_name;
        l8 = ((vader_struct_vader_core_wit$WitCase_t*) l3)->f_name;
        l9 = concat_3(l6, 479u, l8);
        l10 = vader_core_wit$struct_tag(l7, l9);
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(623u, l10));
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_core_wit$read_wit_document(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null(), l14 = vader_box_null(), l15 = vader_box_null(), l16 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null();
    vader_string_t l7 = 0;
    vader_string_t l9 = 0;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[10] = { &l5, &l6, &l11, &l12, &l13, &l14, &l15, &l16, &l17, &l18 };
    void** gc_raw_roots[6] = { &l2, &l3, &l4, &l8, &l10, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l7, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 10u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l2 = (void*) _a0_arr;
    vader_struct_vader_core_wit$WitParser_t* _a1_obj = (vader_struct_vader_core_wit$WitParser_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitParser_t));
    vader_obj_header_init(_a1_obj, 1508u);
    _a1_obj->f_text = l0;
    _a1_obj->f_file = l1;
    _a1_obj->f_at = INT64_C(0);
    _a1_obj->f_line = INT32_C(1);
    _a1_obj->f_column = INT32_C(1);
    _a1_obj->f_doc = l2;
    l2 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(241u, 0u, 13u, 1495u);
    l3 = (void*) _a2_arr;
    vader_struct_vader_core_wit$WitDocument_t* _a3_obj = (vader_struct_vader_core_wit$WitDocument_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitDocument_t));
    vader_obj_header_init(_a3_obj, 1482u);
    _a3_obj->f_file = l1;
    _a3_obj->f_package = vader_box_obj(0u, NULL);
    _a3_obj->f_interfaces = l3;
    l3 = (void*) _a3_obj;
    vader_core_wit$skip_space(l2);
    t0 = vader_core_wit$at_keyword(l2, 3048u);
    if (t0) {
        l5 = vader_core_wit$package_decl(l2);
        l6 = l5;
        if (l5.tag == 1485u) {
            t1 = l6.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = l5.payload.obj;
        ((vader_struct_vader_core_wit$WitDocument_t*) l3)->f_package = vader_ref_box(l4);
        VADER_WRITE_BARRIER((vader_struct_vader_core_wit$WitDocument_t*) l3);
    }
    for (;;) {
        t0 = vader_core_wit$at_end(l2);
        if (!(t0)) {
            l7 = vader_core_wit$take_doc(l2);
            l5 = vader_core_wit$gate(l2);
            l6 = l5;
            if (l5.tag == 1485u) {
                t1 = l6.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l4 = l5.payload.obj;
            l8 = vader_core_wit$span(l2);
            l9 = vader_core_wit$word(l2);
            if (l9 == 2741u) {
                l11 = vader_core_wit$interface_body(l2, l7, l4, l8);
                l12 = l11;
                if (l11.tag == 1485u) {
                    t1 = l12.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l10 = l11.payload.obj;
                vader_array_push_ref((vader_array_t*) ((vader_struct_vader_core_wit$WitDocument_t*) l3)->f_interfaces, l10);
                continue;
            }
            if (l9 == 3738u) {
                l13 = vader_core_wit$identifier(l2);
                l14 = l13;
                if (l13.tag == 1485u) {
                    t1 = l14.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l15 = vader_core_wit$skip_braces(l2);
                l16 = l15;
                if (l15.tag == 1485u) {
                    t1 = l16.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
            } else {
                if (!(l9 == 3502u)) {
                    t1 = vader_core_wit$wit_error(l8, 2439u);
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l17 = vader_core_wit$skip_past(l2, (uint8_t) 59);
                l18 = l17;
                if (l17.tag == 1485u) {
                    t1 = l18.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            continue;
        }
        break;
    }
    { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_wit$read_wit_package(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    int64_t l4, l5, l15, l16;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t l18 = 0;
    vader_string_t l20 = 0;
    vader_string_t l23 = 0;
    vader_box_t l10 = vader_box_null(), l11 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l10, &l11, &t2 };
    void** gc_raw_roots[14] = {
        &l0, &l1, &l2, &l3, &l6, &l7, &l12, &l13, &l14, &l17, &l19, &l21, &l22, &t0,
    };
    vader_string_t* gc_atom_roots[5] = { &l8, &l9, &l18, &l20, &l23 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(238u, 0u, 13u, 1482u);
    l2 = (void*) _a0_arr;
    l3 = l0;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
        l8 = ((vader_struct_vader_core_wit$WitSource_t*) l6)->f_text;
        l9 = ((vader_struct_vader_core_wit$WitSource_t*) l6)->f_path;
        l10 = vader_core_wit$read_wit_document(l8, l9);
        l11 = l10;
        if (l10.tag == 1485u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = l10.payload.obj;
        vader_array_push_ref((vader_array_t*) l2, l7);
        l5 = (l5 + INT64_C(1));
    }
    l10 = vader_core_wit$package_of(l2, l0);
    l11 = l10;
    if (l10.tag == 1485u) {
        t0 = l11.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l10.payload.obj;
    l8 = vader_core_wit$wit_package_text(l3);
    vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 623u);
    l6 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(35u, 0u, 0u, 634u);
    l7 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 626u);
    l12 = (void*) _a4_arr;
    vader_struct_std_collections$Map__string__Any_t* _a5_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
    vader_obj_header_init(_a5_obj, 970u);
    _a5_obj->f_ekeys = l6;
    _a5_obj->f_evals = l7;
    _a5_obj->f_index = l12;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_grow_at = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    l6 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(236u, 0u, 13u, 1473u);
    l7 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(28u, 0u, 0u, 623u);
    l12 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(35u, 0u, 0u, 634u);
    l13 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(29u, 0u, 7u, 626u);
    l14 = (void*) _a9_arr;
    vader_struct_std_collections$Map__string__Any_t* _a10_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
    vader_obj_header_init(_a10_obj, 970u);
    _a10_obj->f_ekeys = l12;
    _a10_obj->f_evals = l13;
    _a10_obj->f_index = l14;
    _a10_obj->f_mask = INT64_C(0);
    _a10_obj->f_grow_at = INT64_C(0);
    _a10_obj->f_size = INT64_C(0);
    _a10_obj->f_tombs = INT64_C(0);
    l12 = (void*) _a10_obj;
    vader_struct_vader_core_wit$Resolution_t* _a11_obj = (vader_struct_vader_core_wit$Resolution_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$Resolution_t));
    vader_obj_header_init(_a11_obj, 1475u);
    _a11_obj->f_package = l3;
    _a11_obj->f_package_text = l8;
    _a11_obj->f_dependency = l1;
    _a11_obj->f_interfaces = l6;
    _a11_obj->f_order = l7;
    _a11_obj->f_dependencies = l12;
    l6 = (void*) _a11_obj;
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        t0 = vader_array_ref_load_obj(_a12_slotarr->buf, vader_array_offset(_a12_slotarr) + (size_t) l5);
        l7 = ((vader_struct_vader_core_wit$WitDocument_t*) t0)->f_interfaces;
        l15 = vader_array_length(((vader_array_t*) l7));
        l16 = INT64_C(0);
        while ((l16 < l15)) {
            vader_array_t* _a13_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            l12 = vader_array_ref_load_obj(_a13_slotarr->buf, vader_array_offset(_a13_slotarr) + (size_t) l16);
            t1 = __lambda_vader_core_wit_1(l12);
            if (t1) {
                l13 = l12;
                l14 = ((vader_struct_vader_core_wit$Resolution_t*) l6)->f_interfaces;
                l8 = ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) l13)->f_name;
                t2 = std_collections$Map$std_core$Index$at__string__Any(l14, l8);
                if (!(t2.tag == 0u)) {
                    l17 = ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) l13)->f_span;
                    l9 = ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) l13)->f_name;
                    l18 = concat_3(2742u, l9, 1463u);
                    t0 = vader_core_wit$wit_error(l17, l18);
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l20 = ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) l13)->f_name;
                vader_struct_vader_core_wit$WitOwner_t* _a14_obj = (vader_struct_vader_core_wit$WitOwner_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitOwner_t));
                vader_obj_header_init(_a14_obj, 1503u);
                _a14_obj->f_package = l3;
                _a14_obj->f_interface = l20;
                l21 = (void*) _a14_obj;
                l10 = vader_core_wit$open_scope(l13, l21);
                l11 = l10;
                if (l10.tag == 1485u) {
                    t0 = l11.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l19 = l10.payload.obj;
                l22 = ((vader_struct_vader_core_wit$Resolution_t*) l6)->f_interfaces;
                l23 = ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) l13)->f_name;
                std_collections$Map$std_core$IndexSet$set_at__string__Any(l22, l23, vader_ref_box(l19));
                vader_array_push_ref((vader_array_t*) ((vader_struct_vader_core_wit$Resolution_t*) l6)->f_order, l19);
            }
            l16 = (l16 + INT64_C(1));
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a15_arr = vader_array_new(240u, 0u, 13u, 1494u);
    l2 = (void*) _a15_arr;
    vader_struct_vader_core_wit$WitPackage_t* _a16_obj = (vader_struct_vader_core_wit$WitPackage_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitPackage_t));
    vader_obj_header_init(_a16_obj, 1504u);
    _a16_obj->f_name = l3;
    _a16_obj->f_interfaces = l2;
    l2 = (void*) _a16_obj;
    l3 = ((vader_struct_vader_core_wit$Resolution_t*) l6)->f_order;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a17_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l5)
        l7 = vader_array_ref_load_obj(_a17_slotarr->buf, vader_array_offset(_a17_slotarr) + (size_t) l5);
        l10 = vader_core_wit$interface_of(l6, l7);
        l11 = l10;
        if (l10.tag == 1485u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l12 = l10.payload.obj;
        vader_array_push_ref((vader_array_t*) ((vader_struct_vader_core_wit$WitPackage_t*) l2)->f_interfaces, l12);
        l5 = (l5 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$record_declaration(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    int64_t l5, l6;
    vader_string_t l8 = 0;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[3] = { &l9, &l10, &l11 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l4, &l7, &t0 };
    vader_string_t* gc_atom_roots[5] = { &l1, &l8, &l12, &l13, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_struct_vader_core_wit$WitRecord_t*) l2)->f_fields;
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l7 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
        l9 = ((vader_struct_vader_core_wit$WitParam_t*) l7)->f_type;
        l10 = vader_core_wit$type_text(l0, l9);
        l11 = l10;
        if (l10.tag == 1474u) {
            t0 = l11.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = l10.payload.s;
        t1 = ((vader_struct_vader_core_wit$WitParam_t*) l7)->f_name;
        l12 = vader_core_wit$snake_name(t1);
        l13 = concat_5(21u, l12, 566u, l8, 1u);
        vader_array_push_scalar((vader_array_t*) l3, vader_box_string(623u, l13));
        l6 = (l6 + INT64_C(1));
    }
    l8 = std_string$join(l3, 0u);
    t1 = concat_5(2463u, l1, 100u, l8, 3785u);
    { vader_box_t __vret = vader_box_string(623u, t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$resolve_name(void* l0, void* l1, vader_string_t l2, void* l3) {
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    vader_string_t l5 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[4] = { &l4, &l6, &l7, &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_core_wit$InterfaceScope_t*) l1)->f_resolved, l2);
    if (!(l4.tag == 0u)) {
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = std_collections$Map$std_core$Index$at__string__bool(((vader_struct_vader_core_wit$InterfaceScope_t*) l1)->f_pending, l2);
    if (vader_box_eq(t0, vader_box_bool(621u, true))) {
        l5 = concat_3(3394u, l2, 1576u);
        t1 = vader_core_wit$wit_error(l3, l5);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    std_collections$Map$std_core$IndexSet$set_at__string__bool(((vader_struct_vader_core_wit$InterfaceScope_t*) l1)->f_pending, l2, true);
    l6 = vader_core_wit$named_type(l0, l1, l2, l3);
    l7 = l6;
    if (l6.tag == 1485u) {
        t1 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l6;
    std_collections$Map$std_core$IndexSet$set_at__string__bool(((vader_struct_vader_core_wit$InterfaceScope_t*) l1)->f_pending, l2, false);
    std_collections$Map$std_core$IndexSet$set_at__string__Any(((vader_struct_vader_core_wit$InterfaceScope_t*) l1)->f_resolved, l2, l4);
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$resource_argument(void* l0, void* l1, vader_string_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l5 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_core_wit$argument(l0);
    l4 = l3;
    if (l3.tag == 1485u) {
        t0 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l3.tag == 1499u)) {
        l5 = concat_3(1310u, l2, 1595u);
        t0 = vader_core_wit$wit_error(l1, l5);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l3.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$resource_body(void* l0) {
    void* l1 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null(), l14 = vader_box_null(), l15 = vader_box_null();
    vader_string_t l4 = 0;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[8] = { &l2, &l3, &l8, &l9, &l10, &l11, &l14, &l15 };
    void** gc_raw_roots[8] = { &l0, &l1, &l5, &l6, &l7, &l12, &l13, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 8u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(239u, 0u, 13u, 1489u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_core_wit$WitResourceDef_t* _a1_obj = (vader_struct_vader_core_wit$WitResourceDef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitResourceDef_t));
    vader_obj_header_init(_a1_obj, 1512u);
    _a1_obj->f_methods = t0;
    l1 = (void*) _a1_obj;
    t1 = vader_core_wit$skip(l0, (uint8_t) 59);
    if (t1) {
        { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_core_wit$expect(l0, (uint8_t) 123);
    l3 = l2;
    if (l2.tag == 1485u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    for (;;) {
        t1 = vader_core_wit$skip(l0, (uint8_t) 125);
        if (!(t1)) {
            l4 = vader_core_wit$take_doc(l0);
            l2 = vader_core_wit$gate(l0);
            l3 = l2;
            if (l2.tag == 1485u) {
                t0 = l3.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l5 = l2.payload.obj;
            l6 = vader_core_wit$span(l0);
            t1 = vader_core_wit$at_keyword(l0, 2291u);
            if (t1) {
                vader_core_wit$word(l0);
                l8 = vader_core_wit$params(l0);
                l9 = l8;
                if (l8.tag == 1485u) {
                    t0 = l9.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l7 = l8.payload.obj;
                l10 = vader_core_wit$expect(l0, (uint8_t) 59);
                l11 = l10;
                if (l10.tag == 1485u) {
                    t0 = l11.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
                vader_struct_vader_core_wit$WitFunctionDecl_t* _a2_obj = (vader_struct_vader_core_wit$WitFunctionDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitFunctionDecl_t));
                vader_obj_header_init(_a2_obj, 1489u);
                _a2_obj->f_name = 2291u;
                _a2_obj->f_kind = (uint8_t) 3;
                _a2_obj->f_is_async = false;
                _a2_obj->f_params = l7;
                _a2_obj->f_result = vader_box_obj(0u, NULL);
                _a2_obj->f_doc = l4;
                _a2_obj->f_gate = l5;
                _a2_obj->f_span = l6;
                l12 = (void*) _a2_obj;
                vader_array_push_ref((vader_array_t*) ((vader_struct_vader_core_wit$WitResourceDef_t*) l1)->f_methods, l12);
                continue;
            }
            l14 = vader_core_wit$function_decl(l0, l4, l5, l6);
            l15 = l14;
            if (l14.tag == 1485u) {
                t0 = l15.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l13 = l14.payload.obj;
            if (((vader_struct_vader_core_wit$WitFunctionDecl_t*) l13)->f_kind == INT32_C(0)) {
                ((vader_struct_vader_core_wit$WitFunctionDecl_t*) l13)->f_kind = (uint8_t) 1;
            }
            vader_array_push_ref((vader_array_t*) ((vader_struct_vader_core_wit$WitResourceDef_t*) l1)->f_methods, l13);
            continue;
        }
        break;
    }
    { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_core_wit$resource_methods(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_box_t l3 = vader_box_null();
    int64_t l5, l6;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[6] = { &l0, &l2, &l4, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_core_wit$InterfaceScope_t*) l0)->f_declared, l1);
    if (l3.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(239u, 0u, 13u, 1489u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    l3 = ((vader_struct_vader_core_wit$WitTypeDecl_t*) l2)->f_definition;
    if (!(l3.tag == 1512u)) {
        vader_array_t* _a1_arr = vader_array_new(239u, 0u, 13u, 1489u);
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l3.payload.obj;
    l2 = ((vader_struct_vader_core_wit$WitResourceDef_t*) t0)->f_methods;
    vader_array_t* _a2_arr = vader_array_new(239u, 0u, 13u, 1489u);
    l4 = (void*) _a2_arr;
    l5 = vader_array_length(((vader_array_t*) l2));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l7 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l6);
        t1 = __lambda_vader_core_wit_9(l7);
        if (t1) {
            l8 = l7;
            vader_array_push_ref((vader_array_t*) l4, l8);
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$result_expr(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    bool t0;
    uint8_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l2, &l3, &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_core_wit$word(l0);
    vader_struct_vader_core_wit$WitResultExpr_t* _a0_obj = (vader_struct_vader_core_wit$WitResultExpr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitResultExpr_t));
    vader_obj_header_init(_a0_obj, 1514u);
    _a0_obj->f_ok = vader_box_obj(0u, NULL);
    _a0_obj->f_error = vader_box_obj(0u, NULL);
    l1 = (void*) _a0_obj;
    t0 = vader_core_wit$skip(l0, (uint8_t) 60);
    if (!(t0)) {
        { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_core_wit$peek(l0);
    if (t1 == INT32_C(95)) {
        vader_core_wit$advance(l0);
        vader_core_wit$skip_space(l0);
    } else {
        l2 = vader_core_wit$type_expr(l0);
        l3 = l2;
        if (l2.tag == 1485u) {
            t2 = l3.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        ((vader_struct_vader_core_wit$WitResultExpr_t*) l1)->f_ok = l2;
        VADER_WRITE_BARRIER((vader_struct_vader_core_wit$WitResultExpr_t*) l1);
    }
    t0 = vader_core_wit$skip(l0, (uint8_t) 44);
    if (t0) {
        l3 = vader_core_wit$type_expr(l0);
        l4 = l3;
        if (l3.tag == 1485u) {
            t2 = l4.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = l3;
        ((vader_struct_vader_core_wit$WitResultExpr_t*) l1)->f_error = l2;
        VADER_WRITE_BARRIER((vader_struct_vader_core_wit$WitResultExpr_t*) l1);
    }
    l2 = vader_core_wit$expect(l0, (uint8_t) 62);
    l3 = l2;
    if (!(l2.tag == 1485u)) {
        { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = l3.payload.obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$result_text(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null();
    vader_string_t l3 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_string_t t3 = 0;
    bool t2;
    vader_box_t* gc_roots[3] = { &l2, &l4, &l5 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l3, &t1, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_wit$WitResult_t*) l1)->f_error;
    if (l2.tag == 0u) {
        t0 = vader_core_wit$no_form(vader_ref_box(l1), 1807u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_core_wit$type_text(l0, l2);
    l5 = l4;
    if (l4.tag == 1474u) {
        t0 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l4.payload.s;
    l5 = ((vader_struct_vader_core_wit$WitResult_t*) l1)->f_ok;
    if (l5.tag == 0u) {
        t1 = concat_2(3700u, l3);
        { vader_box_t __vret = vader_box_string(623u, t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l5;
    t2 = vader_core_wit$shares_tag(l4, l2);
    if (t2) {
        t0 = vader_core_wit$no_form(vader_ref_box(l1), 1928u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_core_wit$type_text(l0, l4);
    l4 = l2;
    if (l2.tag == 1474u) {
        t0 = l4.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l2.payload.s;
    t3 = concat_3(t1, 309u, l3);
    { vader_box_t __vret = vader_box_string(623u, t3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$returned(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    vader_string_t l3 = 0;
    void* l4 = NULL;
    void* t0 = NULL;
    void* t2 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l5, &l6, &t3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &t0, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_wit$WitFunction_t*) ((vader_struct_vader_core_wit$WitNamedFunction_t*) l1)->f_type)->f_result;
    if (l2.tag == 0u) {
        vader_struct_vader_core_wit$Returned_t* _a0_obj = (vader_struct_vader_core_wit$Returned_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$Returned_t));
        vader_obj_header_init(_a0_obj, 1476u);
        _a0_obj->f_text = 3699u;
        _a0_obj->f_wrapper = 0u;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 1490u) {
        l4 = l2.payload.obj;
        l5 = vader_core_wit$future_value_text(l0, l4);
        l6 = l5;
        if (l5.tag == 1474u) {
            t0 = l6.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l3 = l5.payload.s;
        t1 = concat_3(1214u, l3, 632u);
        vader_struct_vader_core_wit$Returned_t* _a1_obj = (vader_struct_vader_core_wit$Returned_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$Returned_t));
        vader_obj_header_init(_a1_obj, 1476u);
        _a1_obj->f_text = t1;
        _a1_obj->f_wrapper = 0u;
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 1517u) {
        t0 = l2.payload.obj;
        t2 = vader_core_wit$no_form(vader_ref_box(t0), 1904u);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 1513u) {
        l4 = l2.payload.obj;
        t3 = vader_core_wit$returned_result(l0, l1, l4);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 1501u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_core_wit$WitOption_t*) t0)->f_value;
        vader_array_t* _a2_arr = vader_array_new(28u, 1u, 0u, 623u);
        vader_array_box_slots(_a2_arr->buf)[vader_array_offset(_a2_arr) + 0u] = vader_box_string(623u, 3004u);
        l4 = (void*) _a2_arr;
        t3 = vader_core_wit$returned_union(l0, l1, l5, 3004u, l4);
        { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_core_wit$type_text(l0, l2);
    l5 = l2;
    if (l2.tag == 1474u) {
        t0 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l2.payload.s;
    vader_struct_vader_core_wit$Returned_t* _a3_obj = (vader_struct_vader_core_wit$Returned_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$Returned_t));
    vader_obj_header_init(_a3_obj, 1476u);
    _a3_obj->f_text = t1;
    _a3_obj->f_wrapper = 0u;
    t0 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$returned_result(void* l0, void* l1, void* l2) {
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    vader_string_t l4 = 0;
    void* l7 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l3, &l5, &l6, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l7, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l4, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_core_wit$WitResult_t*) l2)->f_error;
    if (l3.tag == 0u) {
        t0 = vader_core_wit$no_form(vader_ref_box(l2), 1807u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = vader_core_wit$type_text(l0, l3);
    l6 = l5;
    if (l5.tag == 1474u) {
        t0 = l6.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l5.payload.s;
    l6 = ((vader_struct_vader_core_wit$WitResult_t*) l2)->f_ok;
    if (l6.tag == 0u) {
        t1 = concat_2(3700u, l4);
        vader_struct_vader_core_wit$Returned_t* _a0_obj = (vader_struct_vader_core_wit$Returned_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$Returned_t));
        vader_obj_header_init(_a0_obj, 1476u);
        _a0_obj->f_text = t1;
        _a0_obj->f_wrapper = 0u;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l6;
    l7 = vader_core_wit$tags_of(l3);
    t2 = vader_core_wit$returned_union(l0, l1, l5, l4, l7);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$returned_union(void* l0, void* l1, vader_box_t l2, vader_string_t l3, void* l4) {
    vader_string_t l5 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[3] = { &l2, &l6, &l7 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t0 };
    vader_string_t* gc_atom_roots[6] = { &l3, &l5, &l8, &l9, &t2, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = vader_core_wit$type_text(l0, l2);
    l7 = l6;
    if (l6.tag == 1474u) {
        t0 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l6.payload.s;
    t0 = vader_core_wit$tags_of(l2);
    t1 = vader_core_wit$tags_meet(t0, l4);
    if (!(t1)) {
        t2 = concat_3(l5, 309u, l3);
        vader_struct_vader_core_wit$Returned_t* _a0_obj = (vader_struct_vader_core_wit$Returned_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$Returned_t));
        vader_obj_header_init(_a0_obj, 1476u);
        _a0_obj->f_text = t2;
        _a0_obj->f_wrapper = 0u;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_core_wit$function_words(l1);
    t3 = vader_core_wit$pascal_name(t2);
    l8 = concat_2(t3, 903u);
    l9 = concat_3(l8, 309u, l3);
    l5 = concat_5(2463u, l8, 102u, l5, 17u);
    vader_struct_vader_core_wit$Returned_t* _a1_obj = (vader_struct_vader_core_wit$Returned_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$Returned_t));
    vader_obj_header_init(_a1_obj, 1476u);
    _a1_obj->f_text = l9;
    _a1_obj->f_wrapper = l5;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$scalar_text(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2091u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2679u;
    } else if (l0 == INT32_C(2)) {
        l1 = 3448u;
    } else if (l0 == INT32_C(3)) {
        l1 = 2634u;
    } else if (l0 == INT32_C(4)) {
        l1 = 3427u;
    } else if (l0 == INT32_C(5)) {
        l1 = 2635u;
    } else if (l0 == INT32_C(6)) {
        l1 = 3428u;
    } else if (l0 == INT32_C(7)) {
        l1 = 2657u;
    } else if (l0 == INT32_C(8)) {
        l1 = 3438u;
    } else if (l0 == INT32_C(9)) {
        l1 = 2483u;
    } else if (l0 == INT32_C(10)) {
        l1 = 2485u;
    } else if (l0 == INT32_C(11)) {
        l1 = 2232u;
    } else {
        if (!(l0 == INT32_C(12))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 3236u;
    }
    return l1;
}

static bool vader_core_wit$shares_tag(vader_box_t l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    bool t0;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    void** gc_raw_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_core_wit$tags_of(l0);
    l3 = vader_core_wit$tags_of(l1);
    t0 = vader_core_wit$tags_meet(l2, l3);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_core_wit$skip(void* l0, uint8_t l1) {
    uint8_t t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_wit$peek(l0);
    if (!(t0 != l1)) {
        vader_core_wit$advance(l0);
        vader_core_wit$skip_space(l0);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_core_wit$skip_arrow(void* l0) {
    uint8_t t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_wit$peek(l0);
    if (t0 != INT32_C(45)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t0 = vader_core_wit$peek_at(l0, INT64_C(1));
    if (!(t0 != INT32_C(62))) {
        vader_core_wit$advance(l0);
        vader_core_wit$advance(l0);
        vader_core_wit$skip_space(l0);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static vader_box_t vader_core_wit$skip_braces(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
    int32_t l3;
    uint8_t l4;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_core_wit$expect(l0, (uint8_t) 123);
    l2 = l1;
    if (l1.tag == 1485u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = INT32_C(1);
    while ((l3 > INT32_C(0))) {
        t1 = vader_core_wit$at_end(l0);
        if (t1) {
            t0 = vader_core_wit$fail_here(l0, 2443u);
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = vader_core_wit$peek(l0);
        if (l4 == INT32_C(123)) {
            l3 = vader_chk_add(i32, l3, INT32_C(1));
        } else if (l4 == INT32_C(125)) {
            l3 = vader_chk_sub(i32, l3, INT32_C(1));
        }
        vader_core_wit$advance(l0);
        vader_core_wit$skip_space(l0);
    }
    vader_array_clear((vader_array_t*) ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_doc);
    { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$skip_past(void* l0, uint8_t l1) {
    bool t0;
    uint8_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    for (;;) {
        t0 = vader_core_wit$at_end(l0);
        if (!(t0)) {
            t1 = vader_core_wit$peek(l0);
            if (!(t1 != l1)) {
                break;
            }
            vader_core_wit$advance(l0);
            vader_core_wit$skip_space(l0);
            continue;
        }
        break;
    }
    t2 = vader_core_wit$expect(l0, l1);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_core_wit$skip_space(void* l0) {
    uint8_t l1;
    bool l2, l10, l11, l12;
    int64_t l3, l5, l8;
    vader_string_t l4 = 0;
    vader_string_t l6 = 0;
    vader_string_t l9 = 0;
    void* l7 = NULL;
    bool t0;
    uint8_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l0, &l7 };
    vader_string_t* gc_atom_roots[4] = { &l4, &l6, &l9, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    for (;;) {
        t0 = vader_core_wit$at_end(l0);
        if (!(t0)) {
            l1 = vader_core_wit$peek(l0);
            t0 = std_ascii$is_white_byte(l1);
            if (t0) {
                vader_core_wit$advance(l0);
                continue;
            }
            if (l1 == INT32_C(47)) {
                t1 = vader_core_wit$peek_at(l0, INT64_C(1));
                l2 = t1 == INT32_C(47);
            } else {
                l2 = false;
            }
            if (l2) {
                l3 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_at;
                for (;;) {
                    t0 = vader_core_wit$at_end(l0);
                    if (!(t0)) {
                        t1 = vader_core_wit$peek(l0);
                        if (!(t1 != INT32_C(10))) {
                            break;
                        }
                        vader_core_wit$advance(l0);
                        continue;
                    }
                    break;
                }
                l4 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_text;
                l5 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_at;
                l6 = vader_host_std_core$Intrinsic$byte_slice(l4, l3, l5);
                t0 = std_string$starts_with(l6, 545u);
                if (t0) {
                    l7 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_doc;
                    l8 = vader_host_std_core$Intrinsic$byte_len(l6);
                    t2 = vader_host_std_core$Intrinsic$byte_slice(l6, INT64_C(3), l8);
                    l9 = std_string$trim(t2);
                    vader_array_push_scalar((vader_array_t*) l7, vader_box_string(623u, l9));
                }
            } else {
                if (l1 == INT32_C(47)) {
                    t1 = vader_core_wit$peek_at(l0, INT64_C(1));
                    l10 = t1 == INT32_C(42);
                } else {
                    l10 = false;
                }
                if (!(l10)) {
                    { vader_gc_top = gc_frame.prev; return; }
                }
                vader_core_wit$advance(l0);
                vader_core_wit$advance(l0);
                for (;;) {
                    t0 = vader_core_wit$at_end(l0);
                    if (!(t0)) {
                        t1 = vader_core_wit$peek(l0);
                        if (t1 == INT32_C(42)) {
                            t1 = vader_core_wit$peek_at(l0, INT64_C(1));
                            l12 = t1 == INT32_C(47);
                        } else {
                            l12 = false;
                        }
                        l11 = !(l12);
                    } else {
                        l11 = false;
                    }
                    if (l11) {
                        vader_core_wit$advance(l0);
                        continue;
                    }
                    vader_core_wit$advance(l0);
                    vader_core_wit$advance(l0);
                    break;
                }
            }
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

vader_string_t vader_core_wit$snake_name(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    bool t2;
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string$to_lower(l0);
    l1 = std_string$replace_all(t0, 479u, 1245u);
    t1 = (void*) &vader_data_61;
    t2 = std_core$$array$Contains$contains__string(t1, l1);
    if (!(t2)) {
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = concat_2(l1, 1245u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_core_wit$span(void* l0) {
    vader_string_t l1 = 0;
    int32_t l2, l3;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_file;
    l2 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_line;
    l3 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_column;
    vader_struct_vader_core_wit$WitSpan_t* _a0_obj = (vader_struct_vader_core_wit$WitSpan_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitSpan_t));
    vader_obj_header_init(_a0_obj, 1516u);
    _a0_obj->f_file = l1;
    _a0_obj->f_line = l2;
    _a0_obj->f_column = l3;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$stream_expr(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_core_wit$optional_argument(l0);
    l3 = l2;
    if (l2.tag == 1485u) {
        t0 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_wit$WitStreamExpr_t* _a0_obj = (vader_struct_vader_core_wit$WitStreamExpr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitStreamExpr_t));
    vader_obj_header_init(_a0_obj, 1518u);
    _a0_obj->f_element = l2;
    _a0_obj->f_span = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$struct_tag(void* l0, vader_string_t l1) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &t0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_core_wit$wit_owner_text(l0);
    t1 = concat_3(t0, 536u, l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$tag_text(vader_box_t l0) {
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_core_wit$tags_of(l0);
    t1 = std_string$join(t0, 309u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_core_wit$tags_meet(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l0;
    vader_struct___lambda_env_vader_core_wit_15_t* _a0_obj = (vader_struct___lambda_env_vader_core_wit_15_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_core_wit_15_t));
    vader_obj_header_init(_a0_obj, 678u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l5];
        l6 = t0.payload.s;
        t1 = __lambda_vader_core_wit_14(l3, l6);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void* vader_core_wit$tags_of(vader_box_t l0) {
    void* l1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l1 = (void*) _a0_arr;
    vader_core_wit$push_tags(l0, l1);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$take_doc(void* l0) {
    vader_string_t l1 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_string$join(((vader_struct_vader_core_wit$WitParser_t*) l0)->f_doc, 1u);
    vader_array_clear((vader_array_t*) ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_doc);
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$take_name(void* l0, vader_string_t l1, void* l2) {
    bool l3;
    vader_string_t l4 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l2, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_core_wit$InterfaceScope_t*) l0)->f_declared, l1);
    if (!(t0.tag == 0u)) {
        l3 = true;
    } else {
        t0 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_core_wit$InterfaceScope_t*) l0)->f_used, l1);
        l3 = !(t0.tag == 0u);
    }
    if (!(l3)) {
        vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_core_wit$InterfaceScope_t*) l0)->f_names, vader_box_string(623u, l1));
        { vader_box_t __vret = vader_box_obj(624u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) ((vader_struct_vader_core_wit$InterfaceScope_t*) l0)->f_decl)->f_name;
    l4 = concat_5(3394u, l1, 1464u, l4, 1310u);
    t1 = vader_core_wit$wit_error(l2, l4);
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$tuple_expr(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    void* l3 = NULL;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[5] = { &l1, &l2, &l4, &l5, &l6 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_core_wit$word(l0);
    l1 = vader_core_wit$expect(l0, (uint8_t) 60);
    l2 = l1;
    if (l1.tag == 1485u) {
        t0 = l2.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(484u, 0u, 0u, 2757u);
    l3 = (void*) _a0_arr;
    for (;;) {
        t1 = vader_core_wit$skip(l0, (uint8_t) 62);
        if (!(t1)) {
            l2 = vader_core_wit$type_expr(l0);
            l4 = l2;
            if (l2.tag == 1485u) {
                t0 = l4.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l1 = l2;
            vader_array_push((vader_array_t*) l3, l1);
            t1 = vader_core_wit$skip(l0, (uint8_t) 44);
            if (t1) {
                continue;
            }
            l5 = vader_core_wit$expect(l0, (uint8_t) 62);
            l6 = l5;
            if (!(l5.tag == 1485u)) {
                break;
            }
            t0 = l6.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        break;
    }
    vader_struct_vader_core_wit$WitTupleExpr_t* _a1_obj = (vader_struct_vader_core_wit$WitTupleExpr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitTupleExpr_t));
    vader_obj_header_init(_a1_obj, 1520u);
    _a1_obj->f_elements = l3;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$type_decl(void* l0, vader_string_t l1, void* l2, void* l3) {
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l6, &l7, &l8 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l4, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_core_wit$word(l0);
    l6 = vader_core_wit$identifier(l0);
    l7 = l6;
    if (l6.tag == 1485u) {
        t0 = l7.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l6.payload.s;
    l7 = vader_core_wit$definition(l0, l4);
    l8 = l7;
    if (l7.tag == 1485u) {
        t0 = l8.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l7;
    vader_struct_vader_core_wit$WitTypeDecl_t* _a0_obj = (vader_struct_vader_core_wit$WitTypeDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitTypeDecl_t));
    vader_obj_header_init(_a0_obj, 1521u);
    _a0_obj->f_name = l5;
    _a0_obj->f_doc = l1;
    _a0_obj->f_gate = l2;
    _a0_obj->f_span = l3;
    _a0_obj->f_definition = l6;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_core_wit$type_error(void* l0, void* l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    void* l4 = NULL;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_core_wit$wit_type_text(((vader_struct_vader_core_wit$NoForm_t*) l1)->f_type);
    l3 = vader_core_wit$wit_owner_text(((vader_struct_vader_core_wit$Generation_t*) l0)->f_owner);
    l2 = concat_5(1310u, l2, 1433u, l3, 1688u);
    l3 = vader_core_wit$NoForm$std_core$Error$message(l1);
    l2 = concat_2(l2, l3);
    t0 = vader_core_wit$wit_owner_text(((vader_struct_vader_core_wit$Generation_t*) l0)->f_owner);
    vader_struct_vader_core_wit$WitSpan_t* _a0_obj = (vader_struct_vader_core_wit$WitSpan_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitSpan_t));
    vader_obj_header_init(_a0_obj, 1516u);
    _a0_obj->f_file = t0;
    _a0_obj->f_line = INT32_C(1);
    _a0_obj->f_column = INT32_C(1);
    l4 = (void*) _a0_obj;
    vader_struct_vader_core_wit$WitError_t* _a1_obj = (vader_struct_vader_core_wit$WitError_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitError_t));
    vader_obj_header_init(_a1_obj, 1485u);
    _a1_obj->f_message = l2;
    _a1_obj->f_span = l4;
    t1 = (void*) _a1_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$type_expr(void* l0) {
    void* l1 = NULL;
    vader_string_t l2 = 0;
    vader_box_t l3 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    uint8_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_core_wit$span(l0);
    l2 = vader_core_wit$word_here(l0);
    t0 = std_string$starts_with(l2, 358u);
    if (t0) {
        t1 = vader_core_wit$named_expr(l0, l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_core_wit$wit_scalar_named(l2);
    if (!(l3.tag == 0u)) {
        vader_core_wit$word(l0);
        t2 = ((uint8_t) l3.payload.i);
        { vader_box_t __vret = vader_box_i32(628u, (int32_t)(uint32_t) t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == 2829u) {
        l3 = vader_core_wit$list_expr(l0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == 3036u) {
        l3 = vader_core_wit$option_expr(l0);
    } else if (l2 == 3131u) {
        l3 = vader_core_wit$result_expr(l0);
    } else if (l2 == 3383u) {
        l3 = vader_core_wit$tuple_expr(l0);
    } else if (l2 == 2586u) {
        l3 = vader_core_wit$future_expr(l0);
    } else if (l2 == 3234u) {
        l3 = vader_core_wit$stream_expr(l0, l1);
    } else if (l2 == 2098u) {
        l3 = vader_core_wit$borrow_expr(l0, l1);
    } else if (l2 == 3045u) {
        l3 = vader_core_wit$own_expr(l0, l1);
    } else if (l2 == 2879u) {
        t3 = vader_core_wit$wit_error(l1, 1764u);
        l3 = vader_ref_box(t3);
    } else {
        l3 = vader_core_wit$named_expr(l0, l1);
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$type_of(void* l0, void* l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l7 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
    vader_string_t l5 = 0;
    void* l6 = NULL;
    void* l8 = NULL;
    int64_t l11, l12;
    uint8_t t0;
    void* t1 = NULL;
    void* t3 = NULL;
    bool t2;
    vader_box_t* gc_roots[6] = { &l2, &l3, &l4, &l7, &l9, &l10 };
    void** gc_raw_roots[6] = { &l0, &l1, &l6, &l8, &t1, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2.tag == 628u) {
        t0 = ((uint8_t) l2.payload.i);
        l3 = vader_box_i32(628u, (int32_t)(uint32_t) t0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 1499u) {
        t1 = l2.payload.obj;
        l5 = ((vader_struct_vader_core_wit$WitNameExpr_t*) t1)->f_name;
        t1 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_wit$WitNameExpr_t*) t1)->f_span;
        l4 = vader_core_wit$resolve_name(l0, l1, l5, l6);
        l7 = l4;
        if (l4.tag == 1485u) {
            t1 = l7.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = vader_core_wit$is_resource(l4);
        if (t2) {
            vader_struct_vader_core_wit$WitHandle_t* _a0_obj = (vader_struct_vader_core_wit$WitHandle_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitHandle_t));
            vader_obj_header_init(_a0_obj, 1493u);
            _a0_obj->f_resource = l4;
            _a0_obj->f_is_borrow = false;
            t1 = (void*) _a0_obj;
            l3 = vader_ref_box(t1);
        } else {
            l3 = l4;
        }
    } else if (l2.tag == 1480u) {
        t1 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_wit$WitBorrowExpr_t*) t1)->f_resource;
        l5 = ((vader_struct_vader_core_wit$WitNameExpr_t*) l6)->f_name;
        l8 = ((vader_struct_vader_core_wit$WitNameExpr_t*) l6)->f_span;
        l7 = vader_core_wit$resolve_name(l0, l1, l5, l8);
        l9 = l7;
        if (l7.tag == 1485u) {
            t1 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = l7;
        t2 = vader_core_wit$is_resource(l4);
        if (!(t2)) {
            l8 = ((vader_struct_vader_core_wit$WitNameExpr_t*) l6)->f_span;
            l5 = ((vader_struct_vader_core_wit$WitNameExpr_t*) l6)->f_name;
            l5 = concat_3(1747u, l5, 1493u);
            t1 = vader_core_wit$wit_error(l8, l5);
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_core_wit$WitHandle_t* _a1_obj = (vader_struct_vader_core_wit$WitHandle_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitHandle_t));
        vader_obj_header_init(_a1_obj, 1493u);
        _a1_obj->f_resource = l4;
        _a1_obj->f_is_borrow = true;
        t1 = (void*) _a1_obj;
        l3 = vader_ref_box(t1);
    } else if (l2.tag == 1497u) {
        t1 = l2.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitListExpr_t*) t1)->f_element;
        l4 = vader_core_wit$type_of(l0, l1, l4);
        l7 = l4;
        if (l4.tag == 1485u) {
            t1 = l7.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_core_wit$WitList_t* _a2_obj = (vader_struct_vader_core_wit$WitList_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitList_t));
        vader_obj_header_init(_a2_obj, 1496u);
        _a2_obj->f_element = l4;
        t1 = (void*) _a2_obj;
        l3 = vader_ref_box(t1);
    } else if (l2.tag == 1502u) {
        t1 = l2.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitOptionExpr_t*) t1)->f_value;
        l4 = vader_core_wit$type_of(l0, l1, l4);
        l7 = l4;
        if (l4.tag == 1485u) {
            t1 = l7.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_core_wit$WitOption_t* _a3_obj = (vader_struct_vader_core_wit$WitOption_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitOption_t));
        vader_obj_header_init(_a3_obj, 1501u);
        _a3_obj->f_value = l4;
        t1 = (void*) _a3_obj;
        l3 = vader_ref_box(t1);
    } else if (l2.tag == 1514u) {
        t1 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_wit$WitResultExpr_t*) t1)->f_ok;
        l7 = vader_core_wit$optional_type_of(l0, l1, l7);
        l9 = l7;
        if (l7.tag == 1485u) {
            t1 = l9.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = l7;
        t1 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_wit$WitResultExpr_t*) t1)->f_error;
        l9 = vader_core_wit$optional_type_of(l0, l1, l9);
        l10 = l9;
        if (l9.tag == 1485u) {
            t1 = l10.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = l9;
        vader_struct_vader_core_wit$WitResult_t* _a4_obj = (vader_struct_vader_core_wit$WitResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitResult_t));
        vader_obj_header_init(_a4_obj, 1513u);
        _a4_obj->f_ok = l4;
        _a4_obj->f_error = l7;
        t1 = (void*) _a4_obj;
        l3 = vader_ref_box(t1);
    } else if (l2.tag == 1520u) {
        vader_array_t* _a5_arr = vader_array_new(482u, 0u, 0u, 2752u);
        l6 = (void*) _a5_arr;
        t1 = l2.payload.obj;
        l8 = ((vader_struct_vader_core_wit$WitTupleExpr_t*) t1)->f_elements;
        l11 = vader_array_length(((vader_array_t*) l8));
        l12 = INT64_C(0);
        while ((l12 < l11)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l12)
            l4 = vader_array_box_slots(_a6_slotarr->buf)[vader_array_offset(_a6_slotarr) + (size_t) l12];
            l9 = vader_core_wit$type_of(l0, l1, l4);
            l10 = l9;
            if (l9.tag == 1485u) {
                t1 = l10.payload.obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l7 = l9;
            vader_array_push((vader_array_t*) l6, l7);
            l12 = (l12 + INT64_C(1));
        }
        vader_struct_vader_core_wit$WitTuple_t* _a7_obj = (vader_struct_vader_core_wit$WitTuple_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitTuple_t));
        vader_obj_header_init(_a7_obj, 1519u);
        _a7_obj->f_elements = l6;
        t1 = (void*) _a7_obj;
        l3 = vader_ref_box(t1);
    } else if (l2.tag == 1491u) {
        t1 = l2.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitFutureExpr_t*) t1)->f_value;
        l4 = vader_core_wit$optional_type_of(l0, l1, l4);
        l7 = l4;
        if (l4.tag == 1485u) {
            t1 = l7.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_core_wit$WitFuture_t* _a8_obj = (vader_struct_vader_core_wit$WitFuture_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitFuture_t));
        vader_obj_header_init(_a8_obj, 1490u);
        _a8_obj->f_value = l4;
        t1 = (void*) _a8_obj;
        l3 = vader_ref_box(t1);
    } else {
        if (!(l2.tag == 1518u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t1 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_wit$WitStreamExpr_t*) t1)->f_element;
        if (l7.tag == 0u) {
            t1 = l2.payload.obj;
            t3 = vader_core_wit$wit_error(((vader_struct_vader_core_wit$WitStreamExpr_t*) t1)->f_span, 1808u);
            { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = l7;
        l4 = vader_core_wit$type_of(l0, l1, l4);
        l7 = l4;
        if (l4.tag == 1485u) {
            t1 = l7.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_core_wit$WitStream_t* _a9_obj = (vader_struct_vader_core_wit$WitStream_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitStream_t));
        vader_obj_header_init(_a9_obj, 1517u);
        _a9_obj->f_element = l4;
        t1 = (void*) _a9_obj;
        l3 = vader_ref_box(t1);
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$type_text(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null(), l10 = vader_box_null();
    void* l3 = NULL;
    void* l7 = NULL;
    vader_string_t l4 = 0;
    int64_t l8, l9;
    uint8_t t0;
    vader_string_t t1 = 0;
    vader_string_t t3 = 0;
    void* t2 = NULL;
    void* t4 = NULL;
    bool t5;
    vader_box_t* gc_roots[5] = { &l1, &l2, &l5, &l6, &l10 };
    void** gc_raw_roots[5] = { &l0, &l3, &l7, &t2, &t4 };
    vader_string_t* gc_atom_roots[3] = { &l4, &t1, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 628u) {
        t0 = ((uint8_t) l1.payload.i);
        t1 = vader_core_wit$scalar_text(t0);
        l2 = vader_box_string(623u, t1);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1509u) {
        t2 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_wit$WitRecord_t*) t2)->f_owner;
        t2 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitRecord_t*) t2)->f_name;
        t1 = vader_core_wit$named_text(l0, l3, l4);
        l2 = vader_box_string(623u, t1);
    } else if (l1.tag == 1526u) {
        t2 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_wit$WitVariant_t*) t2)->f_owner;
        t2 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitVariant_t*) t2)->f_name;
        t1 = vader_core_wit$named_text(l0, l3, l4);
        l2 = vader_box_string(623u, t1);
    } else if (l1.tag == 1483u) {
        l3 = l1.payload.obj;
        t1 = vader_core_wit$enum_text(l0, l3);
        l2 = vader_box_string(623u, t1);
    } else if (l1.tag == 1486u) {
        t2 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_wit$WitFlags_t*) t2)->f_owner;
        t2 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitFlags_t*) t2)->f_name;
        t1 = vader_core_wit$named_text(l0, l3, l4);
        l2 = vader_box_string(623u, t1);
    } else if (l1.tag == 1511u) {
        t2 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_wit$WitResource_t*) t2)->f_owner;
        t2 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitResource_t*) t2)->f_name;
        t1 = vader_core_wit$named_text(l0, l3, l4);
        l2 = vader_box_string(623u, t1);
    } else if (l1.tag == 1478u) {
        t2 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_wit$WitAlias_t*) t2)->f_owner;
        t2 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitAlias_t*) t2)->f_name;
        t1 = vader_core_wit$named_text(l0, l3, l4);
        l2 = vader_box_string(623u, t1);
    } else if (l1.tag == 1493u) {
        t2 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_wit$WitHandle_t*) t2)->f_resource;
        l2 = vader_core_wit$type_text(l0, l5);
    } else if (l1.tag == 1496u) {
        t2 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_wit$WitList_t*) t2)->f_element;
        l5 = vader_core_wit$type_text(l0, l5);
        l6 = l5;
        if (l5.tag == 1474u) {
            t2 = l6.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = l5.payload.s;
        t3 = vader_core_wit$grouped(t1);
        t1 = concat_2(t3, 1224u);
        l2 = vader_box_string(623u, t1);
    } else if (l1.tag == 1501u) {
        t2 = l1.payload.obj;
        t4 = vader_core_wit$tags_of(((vader_struct_vader_core_wit$WitOption_t*) t2)->f_value);
        t5 = std_core$$array$Contains$contains__string(t4, 3004u);
        if (t5) {
            t2 = l1.payload.obj;
            t4 = vader_core_wit$no_form(vader_ref_box(t2), 1928u);
            { vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_wit$WitOption_t*) t2)->f_value;
        l5 = vader_core_wit$type_text(l0, l5);
        l6 = l5;
        if (l5.tag == 1474u) {
            t2 = l6.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = l5.payload.s;
        t3 = concat_2(t1, 310u);
        l2 = vader_box_string(623u, t3);
    } else if (l1.tag == 1519u) {
        vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
        l3 = (void*) _a0_arr;
        t2 = l1.payload.obj;
        l7 = ((vader_struct_vader_core_wit$WitTuple_t*) t2)->f_elements;
        l8 = vader_array_length(((vader_array_t*) l7));
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l5 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l9];
            l6 = vader_core_wit$type_text(l0, l5);
            l10 = l6;
            if (l6.tag == 1474u) {
                t2 = l10.payload.obj;
                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l4 = l6.payload.s;
            vader_array_push_scalar((vader_array_t*) l3, vader_box_string(623u, l4));
            l9 = (l9 + INT64_C(1));
        }
        l4 = std_string$join(l3, 444u);
        t1 = concat_3(1221u, l4, 1237u);
        l2 = vader_box_string(623u, t1);
    } else if (l1.tag == 1513u) {
        l3 = l1.payload.obj;
        l2 = vader_core_wit$result_text(l0, l3);
    } else if ((l1.tag == 1490u || l1.tag == 1517u)) {
        t2 = vader_core_wit$no_form(l1, 1905u);
        l2 = vader_ref_box(t2);
    } else {
        if (!(l1.tag == 1522u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = l1.payload.obj;
        t2 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitUnsupported_t*) t2)->f_reason;
        t2 = vader_core_wit$no_form(vader_ref_box(l3), l4);
        l2 = vader_ref_box(t2);
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$use_decl(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l12 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null(), l13 = vader_box_null(), l14 = vader_box_null();
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[6] = { &l4, &l5, &l10, &l11, &l13, &l14 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l6, &l7, &l12, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_core_wit$use_path(l0);
    l5 = l4;
    if (l4.tag == 1485u) {
        t0 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l4.payload.obj;
    l4 = vader_core_wit$expect(l0, (uint8_t) 46);
    l5 = l4;
    if (l4.tag == 1485u) {
        t0 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_core_wit$expect(l0, (uint8_t) 123);
    l5 = l4;
    if (l4.tag == 1485u) {
        t0 = l5.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(250u, 0u, 13u, 1524u);
    l6 = (void*) _a0_arr;
    for (;;) {
        t1 = vader_core_wit$skip(l0, (uint8_t) 125);
        if (!(t1)) {
            l7 = vader_core_wit$span(l0);
            l4 = vader_core_wit$identifier(l0);
            l5 = l4;
            if (l4.tag == 1485u) {
                t0 = l5.payload.obj;
                { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
            }
            l8 = l4.payload.s;
            l9 = l8;
            t1 = vader_core_wit$at_keyword(l0, 2056u);
            if (t1) {
                vader_core_wit$word(l0);
                l10 = vader_core_wit$identifier(l0);
                l11 = l10;
                if (l10.tag == 1485u) {
                    t0 = l11.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l9 = l10.payload.s;
            }
            vader_struct_vader_core_wit$WitUseName_t* _a1_obj = (vader_struct_vader_core_wit$WitUseName_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitUseName_t));
            vader_obj_header_init(_a1_obj, 1524u);
            _a1_obj->f_name = l8;
            _a1_obj->f_local = l9;
            _a1_obj->f_span = l7;
            l12 = (void*) _a1_obj;
            vader_array_push_ref((vader_array_t*) l6, l12);
            t1 = vader_core_wit$skip(l0, (uint8_t) 44);
            if (t1) {
                continue;
            }
            l13 = vader_core_wit$expect(l0, (uint8_t) 125);
            l14 = l13;
            if (!(l13.tag == 1485u)) {
                break;
            }
            t0 = l14.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        break;
    }
    l4 = vader_core_wit$expect(l0, (uint8_t) 59);
    l5 = l4;
    if (!(l4.tag == 1485u)) {
        vader_struct_vader_core_wit$WitUseDecl_t* _a2_obj = (vader_struct_vader_core_wit$WitUseDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitUseDecl_t));
        vader_obj_header_init(_a2_obj, 1523u);
        _a2_obj->f_path = l3;
        _a2_obj->f_names = l6;
        _a2_obj->f_gate = l1;
        _a2_obj->f_span = l2;
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l5.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$use_path(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l5 = 0;
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    uint8_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[3] = { &l0, &l4, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_core_wit$peek_word_end(l0);
    if (t0 != INT32_C(58)) {
        l2 = vader_core_wit$identifier(l0);
        l3 = l2;
        if (l2.tag == 1485u) {
            t1 = l3.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l1 = l2.payload.s;
        vader_struct_vader_core_wit$WitUsePath_t* _a0_obj = (vader_struct_vader_core_wit$WitUsePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitUsePath_t));
        vader_obj_header_init(_a0_obj, 1525u);
        _a0_obj->f_package = vader_box_obj(0u, NULL);
        _a0_obj->f_interface = l1;
        t1 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_core_wit$namespaced_name(l0);
    l3 = l2;
    if (l2.tag == 1485u) {
        t1 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l2.payload.obj;
    l2 = vader_core_wit$expect(l0, (uint8_t) 47);
    l3 = l2;
    if (l2.tag == 1485u) {
        t1 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_core_wit$identifier(l0);
    l3 = l2;
    if (l2.tag == 1485u) {
        t1 = l3.payload.obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l2.payload.s;
    t2 = vader_core_wit$skip(l0, (uint8_t) 64);
    if (t2) {
        l2 = vader_core_wit$version(l0);
        l3 = l2;
        if (l2.tag == 1485u) {
            t1 = l3.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = l2.payload.s;
        ((vader_struct_vader_core_wit$WitPackageName_t*) l4)->f_version = l5;
        vader_struct_vader_core_wit$WitUsePath_t* _a1_obj = (vader_struct_vader_core_wit$WitUsePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitUsePath_t));
        vader_obj_header_init(_a1_obj, 1525u);
        _a1_obj->f_package = vader_ref_box(l4);
        _a1_obj->f_interface = l1;
        t1 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_core_wit$WitUsePath_t* _a2_obj = (vader_struct_vader_core_wit$WitUsePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitUsePath_t));
    vader_obj_header_init(_a2_obj, 1525u);
    _a2_obj->f_package = vader_ref_box(l4);
    _a2_obj->f_interface = l1;
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$used_type(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l7 = vader_box_null(), l9 = vader_box_null();
    bool l3;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    int64_t l11, l12;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[4] = { &l2, &l7, &l9, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l6, &l8, &l10, &l13, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l4, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_wit$WitUsePath_t*) ((vader_struct_vader_core_wit$UsedName_t*) l1)->f_path)->f_package;
    if (l2.tag == 0u) {
        l3 = true;
    } else {
        t0 = l2.payload.obj;
        l4 = vader_core_wit$wit_package_text(t0);
        l5 = ((vader_struct_vader_core_wit$Resolution_t*) l0)->f_package_text;
        l3 = l4 == l5;
    }
    if (l3) {
        l6 = ((vader_struct_vader_core_wit$Resolution_t*) l0)->f_interfaces;
        l4 = ((vader_struct_vader_core_wit$WitUsePath_t*) ((vader_struct_vader_core_wit$UsedName_t*) l1)->f_path)->f_interface;
        l7 = std_collections$Map$std_core$Index$at__string__Any(l6, l4);
        if (l7.tag == 0u) {
            l8 = ((vader_struct_vader_core_wit$UsedName_t*) l1)->f_span;
            l4 = ((vader_struct_vader_core_wit$WitUsePath_t*) ((vader_struct_vader_core_wit$UsedName_t*) l1)->f_path)->f_interface;
            l5 = ((vader_struct_vader_core_wit$Resolution_t*) l0)->f_package_text;
            l4 = concat_5(2980u, l4, 1433u, l5, 1310u);
            t0 = vader_core_wit$wit_error(l8, l4);
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = l7.payload.obj;
        l4 = ((vader_struct_vader_core_wit$UsedName_t*) l1)->f_name;
        l8 = ((vader_struct_vader_core_wit$UsedName_t*) l1)->f_span;
        t1 = vader_core_wit$resolve_name(l0, l6, l4, l8);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = l2.payload.obj;
    l7 = vader_core_wit$dependency_named(l0, l8);
    l9 = l7;
    if (l7.tag == 1485u) {
        t0 = l9.payload.obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l7.payload.obj;
    l8 = ((vader_struct_vader_core_wit$WitPackage_t*) l6)->f_interfaces;
    vader_struct___lambda_env_vader_core_wit_19_t* _a0_obj = (vader_struct___lambda_env_vader_core_wit_19_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_core_wit_19_t));
    vader_obj_header_init(_a0_obj, 679u);
    _a0_obj->f_cap_0 = l1;
    l10 = (void*) _a0_obj;
    l9 = vader_box_obj(0u, NULL);
    l11 = vader_array_length(((vader_array_t*) l8));
    l12 = INT64_C(0);
    {
        while ((l12 < l11)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l13 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l12);
            t2 = __lambda_vader_core_wit_18(l10, l13);
            if (t2) {
                l9 = vader_ref_box(l13);
                goto end_100;
            }
            l12 = (l12 + INT64_C(1));
        }
        l9 = vader_box_obj(0u, NULL);
    } end_100: ;
    l7 = l9;
    if (l7.tag == 0u) {
        l8 = ((vader_struct_vader_core_wit$UsedName_t*) l1)->f_span;
        l4 = ((vader_struct_vader_core_wit$WitUsePath_t*) ((vader_struct_vader_core_wit$UsedName_t*) l1)->f_path)->f_interface;
        t0 = l2.payload.obj;
        l5 = vader_core_wit$wit_package_text(t0);
        l4 = concat_5(2980u, l4, 1433u, l5, 1310u);
        t0 = vader_core_wit$wit_error(l8, l4);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l7.payload.obj;
    l8 = ((vader_struct_vader_core_wit$WitInterface_t*) l6)->f_types;
    vader_struct___lambda_env_vader_core_wit_21_t* _a2_obj = (vader_struct___lambda_env_vader_core_wit_21_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_core_wit_21_t));
    vader_obj_header_init(_a2_obj, 680u);
    _a2_obj->f_cap_0 = l1;
    l10 = (void*) _a2_obj;
    l7 = vader_box_obj(0u, NULL);
    l11 = vader_array_length(((vader_array_t*) l8));
    l12 = INT64_C(0);
    {
        while ((l12 < l11)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l9 = vader_array_ref_load_box(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l12);
            t2 = __lambda_vader_core_wit_20(l10, l9);
            if (t2) {
                l7 = l9;
                goto end_169;
            }
            l12 = (l12 + INT64_C(1));
        }
        l7 = vader_box_obj(0u, NULL);
    } end_169: ;
    l2 = l7;
    if (l2.tag == 0u) {
        l8 = ((vader_struct_vader_core_wit$UsedName_t*) l1)->f_span;
        l4 = ((vader_struct_vader_core_wit$UsedName_t*) l1)->f_name;
        l5 = vader_core_wit$wit_owner_text(((vader_struct_vader_core_wit$WitInterface_t*) l6)->f_owner);
        l4 = concat_5(2986u, l4, 1433u, l5, 1310u);
        t0 = vader_core_wit$wit_error(l8, l4);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$vader_function_name(void* l0) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &t0, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_vader_core_wit$WitNamedFunction_t*) l0)->f_kind == INT32_C(1))) {
        t0 = vader_core_wit$function_words(l0);
        t1 = vader_core_wit$snake_name(t0);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_core_wit$WitNamedFunction_t*) l0)->f_member;
    t1 = vader_core_wit$snake_name(t0);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$variant_declaration(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    int64_t l4, l5;
    vader_string_t l8 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    vader_box_t l10 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null();
    vader_string_t t0 = 0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[4] = { &l10, &l11, &l12, &l13 };
    void** gc_raw_roots[7] = { &l0, &l2, &l3, &l6, &l7, &l9, &t1 };
    vader_string_t* gc_atom_roots[5] = { &l1, &l8, &l14, &l15, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_core_wit$bare_cases(l2);
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_wit$WitVariant_t*) l2)->f_cases));
    if (l4 == l5) {
        t0 = vader_core_wit$enum_declaration(l1, l3);
        { vader_box_t __vret = vader_box_string(623u, t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l6 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 623u);
    t1 = (void*) _a1_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a2_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a2_obj, 1096u);
    _a2_obj->f_parts = t1;
    l7 = (void*) _a2_obj;
    t2 = vader_array_length(((vader_array_t*) l3));
    if ((t2 > INT64_C(0))) {
        l8 = concat_2(l1, 722u);
        vader_array_push_scalar((vader_array_t*) l6, vader_box_string(623u, l8));
        t0 = concat_2(l1, 722u);
        l8 = vader_core_wit$enum_declaration(t0, l3);
        l8 = concat_2(1u, l8);
        std_string__builder$append(l7, l8);
    }
    l3 = ((vader_struct_vader_core_wit$WitVariant_t*) l2)->f_cases;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l9 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l5);
        l11 = ((vader_struct_vader_core_wit$WitCase_t*) l9)->f_type;
        if (l11.tag == 0u) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l10 = l11;
        l12 = vader_core_wit$type_text(l0, l10);
        l13 = l12;
        if (l12.tag == 1474u) {
            t1 = l13.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = l12.payload.s;
        l14 = vader_core_wit$case_struct_name(l1, l9);
        vader_array_push_scalar((vader_array_t*) l6, vader_box_string(623u, l14));
        l15 = concat_5(14u, l14, 102u, l8, 16u);
        std_string__builder$append(l7, l15);
        l5 = (l5 + INT64_C(1));
    }
    l8 = std_string$join(l6, 309u);
    l14 = std_string__builder$StringBuilder$std_core$Display$to_string(l7);
    t0 = concat_6(2463u, l1, 90u, l8, 1u, l14);
    { vader_box_t __vret = vader_box_string(623u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$variant_error_impl(vader_string_t l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    int64_t l3, l4;
    vader_string_t l6 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    int64_t t2;
    void** gc_raw_roots[5] = { &l1, &l2, &l5, &l7, &t1 };
    vader_string_t* gc_atom_roots[5] = { &l0, &l6, &l8, &l9, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_core_wit$bare_cases(l1);
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_wit$WitVariant_t*) l1)->f_cases));
    if (l3 == l4) {
        t0 = vader_core_wit$enum_error_impl(l0, l2);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    t1 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 1096u);
    _a1_obj->f_parts = t1;
    l5 = (void*) _a1_obj;
    t2 = vader_array_length(((vader_array_t*) l2));
    if ((t2 > INT64_C(0))) {
        t0 = concat_2(l0, 722u);
        l6 = vader_core_wit$enum_error_impl(t0, l2);
        std_string__builder$append(l5, l6);
    }
    l2 = vader_core_wit$payload_cases(l1);
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l4);
        l6 = vader_core_wit$case_struct_name(l0, l7);
        l8 = ((vader_struct_vader_core_wit$WitCase_t*) l7)->f_name;
        l9 = vader_core_wit$named_error_impl(l6, l8);
        std_string__builder$append(l5, l9);
        l4 = (l4 + INT64_C(1));
    }
    t0 = std_string__builder$StringBuilder$std_core$Display$to_string(l5);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$version(void* l0) {
    int64_t l1, l3;
    vader_string_t l2 = 0;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[2] = { &l0, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_at;
    for (;;) {
        t0 = vader_core_wit$at_end(l0);
        if (!(t0)) {
            t0 = vader_core_wit$at_version_byte(l0);
            if (!(t0)) {
                break;
            }
            vader_core_wit$advance(l0);
            continue;
        }
        break;
    }
    t1 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_at;
    if (!(t1 == l1)) {
        l2 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_text;
        l3 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_at;
        l2 = vader_host_std_core$Intrinsic$byte_slice(l2, l1, l3);
        vader_core_wit$skip_space(l0);
        { vader_box_t __vret = vader_box_string(623u, l2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_core_wit$fail_here(l0, 2449u);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_core_wit$wit_error(void* l0, vader_string_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_core_wit$WitError_t* _a0_obj = (vader_struct_vader_core_wit$WitError_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitError_t));
    vader_obj_header_init(_a0_obj, 1485u);
    _a0_obj->f_message = l1;
    _a0_obj->f_span = l0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_core_wit$wit_module_source(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l14 = NULL;
    int64_t l6, l7;
    vader_box_t l8 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null();
    vader_string_t l9 = 0;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[4] = { &l8, &l10, &l11, &t2 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l14, &t0 };
    vader_string_t* gc_atom_roots[6] = { &l9, &l12, &l13, &l15, &l16, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_wit$WitInterface_t*) l1)->f_owner;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 623u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 626u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__string_t* _a3_obj = (vader_struct_std_collections$Map__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string_t));
    vader_obj_header_init(_a3_obj, 992u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a3_obj;
    l4 = vader_core_wit$error_types(l0);
    vader_struct_vader_core_wit$Generation_t* _a4_obj = (vader_struct_vader_core_wit$Generation_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$Generation_t));
    vader_obj_header_init(_a4_obj, 1472u);
    _a4_obj->f_owner = l2;
    _a4_obj->f_imports = l3;
    _a4_obj->f_errors = l4;
    l2 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a5_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a6_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a6_obj, 1096u);
    _a6_obj->f_parts = t0;
    l3 = (void*) _a6_obj;
    l4 = ((vader_struct_vader_core_wit$WitInterface_t*) l1)->f_types;
    l6 = vader_array_length(((vader_array_t*) l4));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        l8 = vader_array_ref_load_box(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l7);
        l10 = vader_core_wit$declaration(l2, l8);
        l11 = l10;
        if (l10.tag == 1474u) {
            l5 = l11.payload.obj;
            t0 = vader_core_wit$type_error(l2, l5);
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = l10.payload.s;
        l12 = vader_core_wit$error_impl(l2, l8);
        l13 = concat_3(1u, l9, l12);
        std_string__builder$append(l3, l13);
        l7 = (l7 + INT64_C(1));
    }
    t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_wit$WitInterface_t*) l1)->f_functions));
    if ((t1 > INT64_C(0))) {
        l9 = vader_core_wit$interface_constant(((vader_struct_vader_core_wit$WitInterface_t*) l1)->f_owner);
        l9 = concat_2(1u, l9);
        std_string__builder$append(l3, l9);
    }
    l4 = ((vader_struct_vader_core_wit$WitInterface_t*) l1)->f_functions;
    l6 = vader_array_length(((vader_array_t*) l4));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        l5 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l7);
        l9 = vader_core_wit$function_declaration(l2, l5);
        l12 = concat_2(1u, l9);
        std_string__builder$append(l3, l12);
        l7 = (l7 + INT64_C(1));
    }
    vader_array_t* _a9_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a9_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a10_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a10_obj, 1096u);
    _a10_obj->f_parts = t0;
    l4 = (void*) _a10_obj;
    l2 = ((vader_struct_vader_core_wit$Generation_t*) l2)->f_imports;
    l5 = ((vader_struct_std_collections$Map__string__string_t*) l2)->f_ekeys;
    l14 = ((vader_struct_std_collections$Map__string__string_t*) l2)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$Map__string__string_t*) l2)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l6)
        t2 = vader_array_box_slots(_a11_slotarr->buf)[vader_array_offset(_a11_slotarr) + (size_t) l6];
        l9 = t2.payload.s;
        vader_array_t* _a12_slotarr = ((vader_array_t*) l14);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l6)
        t2 = vader_array_box_slots(_a12_slotarr->buf)[vader_array_offset(_a12_slotarr) + (size_t) l6];
        l12 = t2.payload.s;
        l13 = l9;
        l15 = l12;
        l16 = concat_4(l13, 99u, l15, 320u);
        std_string__builder$append(l4, l16);
        l6 = (l6 + INT64_C(1));
    }
    l9 = std_string__builder$StringBuilder$std_core$Display$to_string(l3);
    std_string__builder$append(l4, l9);
    t3 = std_string__builder$StringBuilder$std_core$Display$to_string(l4);
    { vader_box_t __vret = vader_box_string(623u, t3); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_wit$wit_name(vader_string_t l0) {
    void* l1 = NULL;
    int64_t l2, l3, l7;
    uint8_t l4;
    bool l5;
    uint32_t l6;
    vader_string_t l8 = 0;
    void* t0 = NULL;
    uint8_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l8, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 1096u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = INT64_C(0);
    l3 = vader_host_std_core$Intrinsic$byte_len(l0);
    while ((l2 < l3)) {
        l4 = vader_host_std_core$Intrinsic$byte_at(l0, l2);
        if (l4 == INT32_C(95)) {
            std_string__builder$append(l1, 479u);
        } else {
            if ((l4 >= INT32_C(65))) {
                l5 = (l4 <= INT32_C(90));
            } else {
                l5 = false;
            }
            if (l5) {
                if ((l2 > INT64_C(0))) {
                    std_string__builder$append(l1, 479u);
                }
                t1 = std_ascii$to_lower_byte(l4);
                l6 = ((uint32_t) (uint8_t) t1);
                std_string__builder$append_char(l1, l6);
            } else {
                l7 = vader_chk_add(i64, l2, INT64_C(1));
                l8 = vader_host_std_core$Intrinsic$byte_slice(l0, l2, l7);
                std_string__builder$append(l1, l8);
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    t2 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_wit$wit_owner_text(void* l0) {
    void* l1 = NULL;
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_wit$WitOwner_t*) l0)->f_package;
    l2 = ((vader_struct_vader_core_wit$WitPackageName_t*) l1)->f_namespace;
    l3 = ((vader_struct_vader_core_wit$WitPackageName_t*) l1)->f_name;
    l4 = ((vader_struct_vader_core_wit$WitOwner_t*) l0)->f_interface;
    l2 = concat_5(l2, 565u, l3, 536u, l4);
    t0 = ((vader_struct_vader_core_wit$WitPackageName_t*) l1)->f_version;
    if (!(t0 == 0u)) {
        l3 = ((vader_struct_vader_core_wit$WitPackageName_t*) l1)->f_version;
        t0 = concat_3(l2, 641u, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_wit$wit_package_text(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_core_wit$WitPackageName_t*) l0)->f_version;
    if (!(t0 == 0u)) {
        l1 = ((vader_struct_vader_core_wit$WitPackageName_t*) l0)->f_namespace;
        l2 = ((vader_struct_vader_core_wit$WitPackageName_t*) l0)->f_name;
        l3 = ((vader_struct_vader_core_wit$WitPackageName_t*) l0)->f_version;
        t0 = concat_5(l1, 565u, l2, 641u, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((vader_struct_vader_core_wit$WitPackageName_t*) l0)->f_namespace;
    l2 = ((vader_struct_vader_core_wit$WitPackageName_t*) l0)->f_name;
    t0 = concat_3(l1, 565u, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$wit_scalar_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2091u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 3156u;
    } else if (l0 == INT32_C(2)) {
        l1 = 3448u;
    } else if (l0 == INT32_C(3)) {
        l1 = 3153u;
    } else if (l0 == INT32_C(4)) {
        l1 = 3427u;
    } else if (l0 == INT32_C(5)) {
        l1 = 3154u;
    } else if (l0 == INT32_C(6)) {
        l1 = 3428u;
    } else if (l0 == INT32_C(7)) {
        l1 = 3155u;
    } else if (l0 == INT32_C(8)) {
        l1 = 3438u;
    } else if (l0 == INT32_C(9)) {
        l1 = 2483u;
    } else if (l0 == INT32_C(10)) {
        l1 = 2485u;
    } else if (l0 == INT32_C(11)) {
        l1 = 2232u;
    } else {
        if (!(l0 == INT32_C(12))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 3236u;
    }
    return l1;
}

static vader_box_t vader_core_wit$wit_scalar_named(vader_string_t l0) {
    vader_box_t l1;
    if (l0 == 2091u) {
        l1 = vader_box_i32(628u, INT32_C(0));
        return l1;
    }
    if (l0 == 3156u) {
        l1 = vader_box_i32(628u, INT32_C(1));
    } else if (l0 == 3448u) {
        l1 = vader_box_i32(628u, INT32_C(2));
    } else if (l0 == 3153u) {
        l1 = vader_box_i32(628u, INT32_C(3));
    } else if (l0 == 3427u) {
        l1 = vader_box_i32(628u, INT32_C(4));
    } else if (l0 == 3154u) {
        l1 = vader_box_i32(628u, INT32_C(5));
    } else if (l0 == 3428u) {
        l1 = vader_box_i32(628u, INT32_C(6));
    } else if (l0 == 3155u) {
        l1 = vader_box_i32(628u, INT32_C(7));
    } else if (l0 == 3438u) {
        l1 = vader_box_i32(628u, INT32_C(8));
    } else if (l0 == 2483u) {
        l1 = vader_box_i32(628u, INT32_C(9));
    } else if (l0 == 2485u) {
        l1 = vader_box_i32(628u, INT32_C(10));
    } else if (l0 == 2232u) {
        l1 = vader_box_i32(628u, INT32_C(11));
    } else if (l0 == 3236u) {
        l1 = vader_box_i32(628u, INT32_C(12));
    } else {
        l1 = vader_box_obj(0u, NULL);
    }
    return l1;
}

vader_string_t vader_core_wit$wit_type_name(vader_box_t l0) {
    vader_string_t l1;
    void* t0;
    if (l0.tag == 1509u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_wit$WitRecord_t*) t0)->f_name;
        return l1;
    }
    if (l0.tag == 1526u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_wit$WitVariant_t*) t0)->f_name;
    } else if (l0.tag == 1483u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_wit$WitEnum_t*) t0)->f_name;
    } else if (l0.tag == 1486u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_wit$WitFlags_t*) t0)->f_name;
    } else if (l0.tag == 1511u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_wit$WitResource_t*) t0)->f_name;
    } else {
        if (!(l0.tag == 1478u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_core_wit$WitAlias_t*) t0)->f_name;
    }
    return l1;
}

vader_string_t vader_core_wit$wit_type_text(vader_box_t l0) {
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
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 623u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 1096u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    vader_core_wit$write_wit(l1, l0);
    t1 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_core_wit$without_aliases(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_core_wit$alias_free_params(((vader_struct_vader_core_wit$WitFunction_t*) l0)->f_params);
    l2 = vader_core_wit$optional_alias_free(((vader_struct_vader_core_wit$WitFunction_t*) l0)->f_result);
    vader_struct_vader_core_wit$WitFunction_t* _a0_obj = (vader_struct_vader_core_wit$WitFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitFunction_t));
    vader_obj_header_init(_a0_obj, 1488u);
    _a0_obj->f_params = l1;
    _a0_obj->f_result = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$word(void* l0) {
    vader_string_t l1 = 0;
    int64_t l2, l3;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_core_wit$word_here(l0);
    l2 = INT64_C(0);
    l3 = vader_host_std_core$Intrinsic$byte_len(l1);
    while ((l2 < l3)) {
        vader_core_wit$advance(l0);
        l2 = (l2 + INT64_C(1));
    }
    vader_core_wit$skip_space(l0);
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$word_at(void* l0, int64_t l1) {
    int64_t l2, l3;
    vader_string_t t0, t3;
    uint8_t t1;
    bool t2;
    l2 = l1;
    t0 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_text;
    l3 = vader_host_std_core$Intrinsic$byte_len(t0);
    if ((l2 < l3)) {
        t0 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_text;
        t1 = vader_host_std_core$Intrinsic$byte_at(t0, l2);
        if (t1 == INT32_C(37)) {
            l2 = vader_chk_add(i64, l2, INT64_C(1));
        }
    }
    for (;;) {
        t0 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_text;
        l3 = vader_host_std_core$Intrinsic$byte_len(t0);
        if ((l2 < l3)) {
            t0 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_text;
            t1 = vader_host_std_core$Intrinsic$byte_at(t0, l2);
            t2 = vader_core_wit$is_word_byte(t1);
            if (!(t2)) {
                break;
            }
            l2 = vader_chk_add(i64, l2, INT64_C(1));
            continue;
        }
        break;
    }
    t0 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_text;
    t3 = vader_host_std_core$Intrinsic$byte_slice(t0, l1, l2);
    return t3;
}

static vader_string_t vader_core_wit$word_here(void* l0) {
    int64_t l1;
    vader_string_t t0;
    l1 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_at;
    t0 = vader_core_wit$word_at(l0, l1);
    return t0;
}

static void vader_core_wit$write_wit(void* l0, vader_box_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null();
    void* l5 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    int64_t l7, l8;
    uint8_t t0;
    void* t1 = NULL;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l4, &t3 };
    void** gc_raw_roots[5] = { &l0, &l5, &l6, &l9, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 628u) {
        t0 = ((uint8_t) l1.payload.i);
        l2 = vader_core_wit$wit_scalar_name(t0);
        std_string__builder$append(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1483u) {
        t1 = l1.payload.obj;
        l2 = vader_core_wit$enum_name_text(t1);
        t1 = l1.payload.obj;
        l3 = std_string$join(((vader_struct_vader_core_wit$WitEnum_t*) t1)->f_cases, 442u);
        l2 = concat_5(2413u, l2, 3773u, l3, 3784u);
        std_string__builder$append(l0, l2);
    } else if (l1.tag == 1513u) {
        std_string__builder$append(l0, 3132u);
        t1 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitResult_t*) t1)->f_ok;
        vader_core_wit$write_wit_or_none(l0, l4);
        std_string__builder$append(l0, 442u);
        t1 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitResult_t*) t1)->f_error;
        vader_core_wit$write_wit_or_none(l0, l4);
        std_string__builder$append(l0, 632u);
    } else if (l1.tag == 1496u) {
        std_string__builder$append(l0, 2830u);
        t1 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitList_t*) t1)->f_element;
        vader_core_wit$write_wit(l0, l4);
        std_string__builder$append(l0, 632u);
    } else if (l1.tag == 1517u) {
        std_string__builder$append(l0, 3235u);
        t1 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitStream_t*) t1)->f_element;
        vader_core_wit$write_wit(l0, l4);
        std_string__builder$append(l0, 632u);
    } else if (l1.tag == 1490u) {
        std_string__builder$append(l0, 2587u);
        t1 = l1.payload.obj;
        l4 = ((vader_struct_vader_core_wit$WitFuture_t*) t1)->f_value;
        vader_core_wit$write_wit_or_none(l0, l4);
        std_string__builder$append(l0, 632u);
    } else if (l1.tag == 1509u) {
        t1 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_wit$WitRecord_t*) t1)->f_fields;
        t2 = vader_array_length(((vader_array_t*) l5));
        vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t2, 0u, 623u);
        l6 = (void*) _a0_arr;
        l7 = vader_array_length(((vader_array_t*) l5));
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l8);
            l2 = __lambda_vader_core_wit_12(t1);
            vader_array_push_scalar((vader_array_t*) l6, vader_box_string(623u, l2));
            l8 = (l8 + INT64_C(1));
        }
        l5 = l6;
        t1 = l1.payload.obj;
        l6 = ((vader_struct_vader_core_wit$WitRecord_t*) t1)->f_owner;
        t1 = l1.payload.obj;
        l2 = ((vader_struct_vader_core_wit$WitRecord_t*) t1)->f_name;
        l2 = vader_core_wit$named_text_1(l6, l2);
        l3 = std_string$join(l5, 442u);
        l2 = concat_5(3103u, l2, 3773u, l3, 3784u);
        std_string__builder$append(l0, l2);
    } else if (l1.tag == 1526u) {
        t1 = l1.payload.obj;
        l6 = ((vader_struct_vader_core_wit$WitVariant_t*) t1)->f_cases;
        t2 = vader_array_length(((vader_array_t*) l6));
        vader_array_t* _a2_arr = vader_array_reserve(28u, (int64_t) t2, 0u, 623u);
        l9 = (void*) _a2_arr;
        l7 = vader_array_length(((vader_array_t*) l6));
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t1 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l8);
            l2 = vader_core_wit$case_text(t1);
            vader_array_push_scalar((vader_array_t*) l9, vader_box_string(623u, l2));
            l8 = (l8 + INT64_C(1));
        }
        l5 = l9;
        t1 = l1.payload.obj;
        l6 = ((vader_struct_vader_core_wit$WitVariant_t*) t1)->f_owner;
        t1 = l1.payload.obj;
        l2 = ((vader_struct_vader_core_wit$WitVariant_t*) t1)->f_name;
        l2 = vader_core_wit$named_text_1(l6, l2);
        l3 = std_string$join(l5, 442u);
        l2 = concat_5(3690u, l2, 3773u, l3, 3784u);
        std_string__builder$append(l0, l2);
    } else if (l1.tag == 1486u) {
        t1 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_wit$WitFlags_t*) t1)->f_owner;
        t1 = l1.payload.obj;
        l2 = ((vader_struct_vader_core_wit$WitFlags_t*) t1)->f_name;
        l2 = vader_core_wit$named_text_1(l5, l2);
        t1 = l1.payload.obj;
        l3 = std_string$join(((vader_struct_vader_core_wit$WitFlags_t*) t1)->f_flags, 442u);
        l2 = concat_5(2540u, l2, 3773u, l3, 3784u);
        std_string__builder$append(l0, l2);
    } else if (l1.tag == 1501u) {
        t1 = l1.payload.obj;
        l2 = vader_core_wit$wit_type_text(((vader_struct_vader_core_wit$WitOption_t*) t1)->f_value);
        l2 = concat_3(3037u, l2, 632u);
        std_string__builder$append(l0, l2);
    } else if (l1.tag == 1519u) {
        t1 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_wit$WitTuple_t*) t1)->f_elements;
        t2 = vader_array_length(((vader_array_t*) l5));
        vader_array_t* _a4_arr = vader_array_reserve(28u, (int64_t) t2, 0u, 623u);
        l6 = (void*) _a4_arr;
        l7 = vader_array_length(((vader_array_t*) l5));
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            t3 = vader_array_box_slots(_a5_slotarr->buf)[vader_array_offset(_a5_slotarr) + (size_t) l8];
            l2 = vader_core_wit$wit_type_text(t3);
            vader_array_push_scalar((vader_array_t*) l6, vader_box_string(623u, l2));
            l8 = (l8 + INT64_C(1));
        }
        l2 = std_string$join(l6, 442u);
        l2 = concat_3(3384u, l2, 632u);
        std_string__builder$append(l0, l2);
    } else if (l1.tag == 1511u) {
        t1 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_wit$WitResource_t*) t1)->f_owner;
        t1 = l1.payload.obj;
        l2 = ((vader_struct_vader_core_wit$WitResource_t*) t1)->f_name;
        l2 = vader_core_wit$named_text_1(l5, l2);
        l2 = concat_2(3126u, l2);
        std_string__builder$append(l0, l2);
    } else if (l1.tag == 1493u) {
        t1 = l1.payload.obj;
        l2 = vader_core_wit$handle_keyword(t1);
        t1 = l1.payload.obj;
        l3 = vader_core_wit$wit_type_text(((vader_struct_vader_core_wit$WitHandle_t*) t1)->f_resource);
        l2 = concat_4(l2, 610u, l3, 632u);
        std_string__builder$append(l0, l2);
    } else if (l1.tag == 1478u) {
        t1 = l1.payload.obj;
        l5 = ((vader_struct_vader_core_wit$WitAlias_t*) t1)->f_owner;
        t1 = l1.payload.obj;
        l2 = ((vader_struct_vader_core_wit$WitAlias_t*) t1)->f_name;
        l2 = vader_core_wit$named_text_1(l5, l2);
        t1 = l1.payload.obj;
        l3 = vader_core_wit$wit_type_text(((vader_struct_vader_core_wit$WitAlias_t*) t1)->f_target);
        l2 = concat_4(3405u, l2, 627u, l3);
        std_string__builder$append(l0, l2);
    } else {
        if (!(l1.tag == 1522u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        std_string__builder$append(l0, 640u);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_core_wit$write_wit_or_none(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 0u)) {
        l2 = l1;
        vader_core_wit$write_wit(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_string__builder$append(l0, 1245u);
    { vader_gc_top = gc_frame.prev; return; }
}
