#include "bootstrap.split.h"

static void* __lambda_vader_core_wit_0(void* l0);
static vader_box_t __lambda_vader_core_wit_1(void* l0);
static vader_string_t __lambda_vader_core_wit_10(vader_string_t l0);
static bool __lambda_vader_core_wit_11(void* l0);
static bool __lambda_vader_core_wit_12(void* l0);
static bool __lambda_vader_core_wit_13(void* l0);
static vader_string_t __lambda_vader_core_wit_14(vader_string_t l0);
static vader_string_t __lambda_vader_core_wit_15(vader_string_t l0);
static vader_string_t __lambda_vader_core_wit_16(vader_string_t l0);
static bool __lambda_vader_core_wit_17(void* l0);
static vader_string_t __lambda_vader_core_wit_18(void* l0);
static vader_string_t __lambda_vader_core_wit_19(void* l0);
static vader_box_t __lambda_vader_core_wit_2(void* l0);
static vader_string_t __lambda_vader_core_wit_20(void* l0);
static bool __lambda_vader_core_wit_21(void* l0, void* l1);
static bool __lambda_vader_core_wit_23(void* l0, vader_box_t l1);
static bool __lambda_vader_core_wit_3(void* l0);
static bool __lambda_vader_core_wit_4(void* l0, vader_string_t l1);
static bool __lambda_vader_core_wit_6(void* l0);
static vader_string_t __lambda_vader_core_wit_7(void* l0);
static bool __lambda_vader_core_wit_8(void* l0);
static bool __lambda_vader_core_wit_9(void* l0);
static vader_string_t vader_core_wit$NoForm$std_core$Error$message(void* l0);
static void vader_core_wit$advance(void* l0);
static vader_box_t vader_core_wit$alias_free(vader_box_t l0);
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
static void* vader_core_wit$drop_of(void* l0);
static int64_t vader_core_wit$enum_case_bits(int64_t l0);
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
static bool vader_core_wit$is_stable(void* l0);
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
static vader_string_t vader_core_wit$pascal_name(vader_string_t l0);
static void* vader_core_wit$payload_cases(void* l0);
static uint8_t vader_core_wit$peek(void* l0);
static uint8_t vader_core_wit$peek_at(void* l0, int64_t l1);
static uint8_t vader_core_wit$peek_word_end(void* l0);
static void* vader_core_wit$present(void* l0);
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
static vader_string_t vader_core_wit$resource_drop_name(void* l0);
static void* vader_core_wit$resource_methods(void* l0, vader_string_t l1);
static vader_box_t vader_core_wit$result_expr(void* l0);
static vader_box_t vader_core_wit$result_text(void* l0, void* l1);
static vader_box_t vader_core_wit$returned(void* l0, void* l1);
static vader_box_t vader_core_wit$returned_result(void* l0, void* l1, void* l2);
static vader_box_t vader_core_wit$returned_text(void* l0, vader_box_t l1);
static vader_box_t vader_core_wit$returned_union(void* l0, void* l1, vader_box_t l2, vader_string_t l3, bool l4);
static vader_string_t vader_core_wit$scalar_text(uint8_t l0);
static bool vader_core_wit$shares_tag(vader_box_t l0, vader_box_t l1);
static bool vader_core_wit$skip(void* l0, uint8_t l1);
static bool vader_core_wit$skip_arrow(void* l0);
static vader_box_t vader_core_wit$skip_braces(void* l0);
static vader_box_t vader_core_wit$skip_past(void* l0, uint8_t l1);
static void vader_core_wit$skip_space(void* l0);
static vader_string_t vader_core_wit$snake_name(vader_string_t l0);
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
static vader_string_t vader_core_wit$wit_type_name(vader_box_t l0);
static vader_string_t vader_core_wit$wit_type_text(vader_box_t l0);
static vader_string_t vader_core_wit$word(void* l0);
static vader_string_t vader_core_wit$word_at(void* l0, int64_t l1);
static vader_string_t vader_core_wit$word_here(void* l0);
static void vader_core_wit$write_wit(void* l0, vader_box_t l1);
static void vader_core_wit$write_wit_or_none(void* l0, vader_box_t l1);

static void* __lambda_vader_core_wit_0(void* l0) {
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
	l1 = ((vader_struct_vader_core_wit$WitParam_t*) l0)->f_name;
	l2 = vader_core_wit$alias_free(((vader_struct_vader_core_wit$WitParam_t*) l0)->f_type);
	vader_struct_vader_core_wit$WitParam_t* _a0_obj = (vader_struct_vader_core_wit$WitParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitParam_t));
	vader_obj_header_init(_a0_obj, 1554u);
	_a0_obj->f_name = l1;
	_a0_obj->f_type = l2;
	t0 = (void*) _a0_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t __lambda_vader_core_wit_1(void* l0) {
	return ((vader_struct_vader_core_wit$WitCase_t*) l0)->f_type;
}

static vader_string_t __lambda_vader_core_wit_10(vader_string_t l0) {
	vader_string_t t0;
	t0 = concat_3(21u, l0, 442u);
	return t0;
}

static bool __lambda_vader_core_wit_11(void* l0) {
	bool t0;
	t0 = vader_core_wit$is_stable(((vader_struct_vader_core_wit$WitUseDecl_t*) l0)->f_gate);
	return t0;
}

static bool __lambda_vader_core_wit_12(void* l0) {
	bool t0;
	t0 = vader_core_wit$is_stable(((vader_struct_vader_core_wit$WitTypeDecl_t*) l0)->f_gate);
	return t0;
}

static bool __lambda_vader_core_wit_13(void* l0) {
	bool t0;
	t0 = vader_core_wit$is_stable(((vader_struct_vader_core_wit$WitFunctionDecl_t*) l0)->f_gate);
	return t0;
}

static vader_string_t __lambda_vader_core_wit_14(vader_string_t l0) {
	vader_string_t l1 = 0;
	vader_string_t t0 = 0;
	vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	l1 = vader_core_wit$snake_name(l0);
	t0 = concat_3(21u, l1, 578u);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t __lambda_vader_core_wit_15(vader_string_t l0) {
	vader_string_t l1 = 0;
	vader_string_t t0 = 0;
	vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	l1 = vader_core_wit$pascal_name(l0);
	t0 = concat_3(21u, l1, 442u);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t __lambda_vader_core_wit_16(vader_string_t l0) {
	vader_string_t l1 = 0;
	vader_string_t t0 = 0;
	vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	l1 = vader_core_wit$pascal_name(l0);
	t0 = concat_5(23u, l1, 81u, l0, 318u);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool __lambda_vader_core_wit_17(void* l0) {
	bool t0;
	t0 = vader_core_wit$is_stable(((vader_struct_vader_core_wit$WitFunctionDecl_t*) l0)->f_gate);
	return t0;
}

static vader_string_t __lambda_vader_core_wit_18(void* l0) {
	vader_string_t l1 = 0;
	vader_string_t l2 = 0;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l0 };
	vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l1 = ((vader_struct_vader_core_wit$WitParam_t*) l0)->f_name;
	l2 = vader_core_wit$wit_type_text(((vader_struct_vader_core_wit$WitParam_t*) l0)->f_type);
	t0 = concat_3(l1, 566u, l2);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t __lambda_vader_core_wit_19(void* l0) {
	vader_string_t t0;
	t0 = ((vader_struct_vader_core_wit$WitMemberDecl_t*) l0)->f_name;
	return t0;
}

static vader_box_t __lambda_vader_core_wit_2(void* l0) {
	return ((vader_struct_vader_core_wit$WitParam_t*) l0)->f_type;
}

static vader_string_t __lambda_vader_core_wit_20(void* l0) {
	vader_string_t t0;
	t0 = ((vader_struct_vader_core_wit$WitMemberDecl_t*) l0)->f_name;
	return t0;
}

static bool __lambda_vader_core_wit_21(void* l0, void* l1) {
	vader_string_t l2, l3;
	l2 = ((vader_struct_vader_core_wit$WitOwner_t*) ((vader_struct_vader_core_wit$WitInterface_t*) l1)->f_owner)->f_interface;
	l3 = ((vader_struct_vader_core_wit$WitUsePath_t*) ((vader_struct_vader_core_wit$UsedName_t*) ((vader_struct___lambda_env_vader_core_wit_22_t*) l0)->f_cap_0)->f_path)->f_interface;
	return l2 == l3;
}

static bool __lambda_vader_core_wit_23(void* l0, vader_box_t l1) {
	vader_string_t l2, l3;
	l2 = vader_core_wit$wit_type_name(l1);
	l3 = ((vader_struct_vader_core_wit$UsedName_t*) ((vader_struct___lambda_env_vader_core_wit_24_t*) l0)->f_cap_0)->f_name;
	return l2 == l3;
}

static bool __lambda_vader_core_wit_3(void* l0) {
	return ((vader_struct_vader_core_wit$WitCase_t*) l0)->f_type.tag == 0u;
}

static bool __lambda_vader_core_wit_4(void* l0, vader_string_t l1) {
	bool t0;
	t0 = std_core$$array$Contains$contains__string(((vader_struct___lambda_env_vader_core_wit_5_t*) l0)->f_cap_0, l1);
	return t0;
}

static bool __lambda_vader_core_wit_6(void* l0) {
	return ((vader_struct_vader_core_wit$WitCase_t*) l0)->f_type.tag == 0u;
}

static vader_string_t __lambda_vader_core_wit_7(void* l0) {
	vader_string_t t0;
	t0 = ((vader_struct_vader_core_wit$WitCase_t*) l0)->f_name;
	return t0;
}

static bool __lambda_vader_core_wit_8(void* l0) {
	return !(((vader_struct_vader_core_wit$WitCase_t*) l0)->f_type.tag == 0u);
}

static bool __lambda_vader_core_wit_9(void* l0) {
	bool t0;
	t0 = vader_core_wit$is_stable(((vader_struct_vader_core_wit$WitInterfaceDecl_t*) l0)->f_gate);
	return t0;
}

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
	t1 = concat_2(t0, 172u);
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

static vader_box_t vader_core_wit$alias_free(vader_box_t l0) {
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
	if (l0.tag == 1526u) {
		t0 = l0.payload.obj;
		l1 = vader_core_wit$alias_free(((vader_struct_vader_core_wit$WitAlias_t*) t0)->f_target);
		{ vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l0.tag == 1544u) {
		t0 = l0.payload.obj;
		t1 = vader_core_wit$alias_free(((vader_struct_vader_core_wit$WitList_t*) t0)->f_element);
		vader_struct_vader_core_wit$WitList_t* _a0_obj = (vader_struct_vader_core_wit$WitList_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitList_t));
		vader_obj_header_init(_a0_obj, 1544u);
		_a0_obj->f_element = t1;
		t0 = (void*) _a0_obj;
		l1 = vader_ref_box(t0);
	} else if (l0.tag == 1549u) {
		t0 = l0.payload.obj;
		t1 = vader_core_wit$alias_free(((vader_struct_vader_core_wit$WitOption_t*) t0)->f_value);
		vader_struct_vader_core_wit$WitOption_t* _a1_obj = (vader_struct_vader_core_wit$WitOption_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitOption_t));
		vader_obj_header_init(_a1_obj, 1549u);
		_a1_obj->f_value = t1;
		t0 = (void*) _a1_obj;
		l1 = vader_ref_box(t0);
	} else if (l0.tag == 1567u) {
		t0 = l0.payload.obj;
		l2 = ((vader_struct_vader_core_wit$WitTuple_t*) t0)->f_elements;
		t2 = vader_array_length(((vader_array_t*) l2));
		vader_array_t* _a2_arr = vader_array_reserve(498u, (int64_t) t2, 0u, 2825u);
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
		vader_obj_header_init(_a4_obj, 1567u);
		_a4_obj->f_elements = l3;
		t0 = (void*) _a4_obj;
		l1 = vader_ref_box(t0);
	} else if (l0.tag == 1561u) {
		t0 = l0.payload.obj;
		l6 = vader_core_wit$optional_alias_free(((vader_struct_vader_core_wit$WitResult_t*) t0)->f_ok);
		t0 = l0.payload.obj;
		l7 = vader_core_wit$optional_alias_free(((vader_struct_vader_core_wit$WitResult_t*) t0)->f_error);
		vader_struct_vader_core_wit$WitResult_t* _a5_obj = (vader_struct_vader_core_wit$WitResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitResult_t));
		vader_obj_header_init(_a5_obj, 1561u);
		_a5_obj->f_ok = l6;
		_a5_obj->f_error = l7;
		t0 = (void*) _a5_obj;
		l1 = vader_ref_box(t0);
	} else if (l0.tag == 1565u) {
		t0 = l0.payload.obj;
		t1 = vader_core_wit$alias_free(((vader_struct_vader_core_wit$WitStream_t*) t0)->f_element);
		vader_struct_vader_core_wit$WitStream_t* _a6_obj = (vader_struct_vader_core_wit$WitStream_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitStream_t));
		vader_obj_header_init(_a6_obj, 1565u);
		_a6_obj->f_element = t1;
		t0 = (void*) _a6_obj;
		l1 = vader_ref_box(t0);
	} else if (l0.tag == 1538u) {
		t0 = l0.payload.obj;
		t1 = vader_core_wit$optional_alias_free(((vader_struct_vader_core_wit$WitFuture_t*) t0)->f_value);
		vader_struct_vader_core_wit$WitFuture_t* _a7_obj = (vader_struct_vader_core_wit$WitFuture_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitFuture_t));
		vader_obj_header_init(_a7_obj, 1538u);
		_a7_obj->f_value = t1;
		t0 = (void*) _a7_obj;
		l1 = vader_ref_box(t0);
	} else if (l0.tag == 1541u) {
		l2 = l0.payload.obj;
		t0 = l0.payload.obj;
		l6 = vader_core_wit$alias_free(((vader_struct_vader_core_wit$WitHandle_t*) t0)->f_resource);
		l8 = ((vader_struct_vader_core_wit$WitHandle_t*) l2)->f_is_borrow;
		vader_struct_vader_core_wit$WitHandle_t* _a8_obj = (vader_struct_vader_core_wit$WitHandle_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitHandle_t));
		vader_obj_header_init(_a8_obj, 1541u);
		_a8_obj->f_resource = l6;
		_a8_obj->f_is_borrow = l8;
		t0 = (void*) _a8_obj;
		l1 = vader_ref_box(t0);
	} else if (l0.tag == 1557u) {
		l2 = l0.payload.obj;
		l9 = ((vader_struct_vader_core_wit$WitRecord_t*) l2)->f_name;
		l2 = ((vader_struct_vader_core_wit$WitRecord_t*) l2)->f_owner;
		t0 = l0.payload.obj;
		l3 = vader_core_wit$alias_free_params(((vader_struct_vader_core_wit$WitRecord_t*) t0)->f_fields);
		vader_struct_vader_core_wit$WitRecord_t* _a9_obj = (vader_struct_vader_core_wit$WitRecord_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitRecord_t));
		vader_obj_header_init(_a9_obj, 1557u);
		_a9_obj->f_name = l9;
		_a9_obj->f_owner = l2;
		_a9_obj->f_fields = l3;
		t0 = (void*) _a9_obj;
		l1 = vader_ref_box(t0);
	} else if (l0.tag == 1574u) {
		l2 = l0.payload.obj;
		l9 = ((vader_struct_vader_core_wit$WitVariant_t*) l2)->f_name;
		l2 = ((vader_struct_vader_core_wit$WitVariant_t*) l2)->f_owner;
		t0 = l0.payload.obj;
		l3 = ((vader_struct_vader_core_wit$WitVariant_t*) t0)->f_cases;
		t2 = vader_array_length(((vader_array_t*) l3));
		vader_array_t* _a10_arr = vader_array_reserve(244u, (int64_t) t2, 13u, 1529u);
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
		vader_obj_header_init(_a12_obj, 1574u);
		_a12_obj->f_name = l9;
		_a12_obj->f_owner = l2;
		_a12_obj->f_cases = l10;
		t0 = (void*) _a12_obj;
		l1 = vader_ref_box(t0);
	} else {
		if (!((l0.tag == 1531u || l0.tag == 1534u || l0.tag == 1559u || l0.tag == 647u || l0.tag == 1570u))) {
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
	vader_array_t* _a0_arr = vader_array_reserve(252u, (int64_t) t0, 13u, 1554u);
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
		t0 = vader_core_wit$fail_here(l0, 2454u);
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l1.tag == 1533u) {
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
	l2 = (int64_t) vader_string_byte_len(t0);
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
	if (l2 == 3201u) {
		l3 = true;
	} else {
		l3 = l2 == 3530u;
	}
	if (l3) {
		l3 = true;
	} else {
		l3 = l2 == 2353u;
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
	if (l1 == 3432u) {
		l2 = true;
	} else {
		l2 = l1 == 3124u;
	}
	if (l2) {
		l2 = true;
	} else {
		l2 = l1 == 3718u;
	}
	if (l2) {
		l2 = true;
	} else {
		l2 = l1 == 2418u;
	}
	if (l2) {
		l2 = true;
	} else {
		l2 = l1 == 2559u;
	}
	if (l2) {
		l2 = true;
	} else {
		l2 = l1 == 3147u;
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a0_arr;
	l3 = vader_array_length(((vader_array_t*) l1));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l5 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		t0 = __lambda_vader_core_wit_6(l5);
		if (t0) {
			l6 = __lambda_vader_core_wit_7(l5);
			vader_array_push_scalar((vader_array_t*) l2, vader_box_string(642u, l6));
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
	l2 = vader_core_wit$resource_argument(l0, l1, 2114u);
	l3 = l2;
	if (l2.tag == 1533u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l2.payload.obj;
	vader_struct_vader_core_wit$WitBorrowExpr_t* _a0_obj = (vader_struct_vader_core_wit$WitBorrowExpr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitBorrowExpr_t));
	vader_obj_header_init(_a0_obj, 1528u);
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
	vader_obj_header_init(_a0_obj, 1529u);
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
	t0 = concat_3(l2, 566u, l3);
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
	if (l1.tag == 1557u) {
		l4 = l1.payload.obj;
		l3 = vader_core_wit$record_declaration(l0, l2, l4);
		{ vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l1.tag == 1574u) {
		l4 = l1.payload.obj;
		l3 = vader_core_wit$variant_declaration(l0, l2, l4);
	} else if (l1.tag == 1531u) {
		t1 = l1.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitEnum_t*) t1)->f_cases;
		t0 = vader_core_wit$enum_declaration(l2, l4);
		l3 = vader_box_string(642u, t0);
	} else if (l1.tag == 1534u) {
		l4 = l1.payload.obj;
		t0 = vader_core_wit$flags_declaration(l2, l4);
		l3 = vader_box_string(642u, t0);
	} else if (l1.tag == 1559u) {
		t0 = concat_3(2480u, l2, 98u);
		l3 = vader_box_string(642u, t0);
	} else {
		if (!(l1.tag == 1526u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		t1 = l1.payload.obj;
		l6 = ((vader_struct_vader_core_wit$WitAlias_t*) t1)->f_target;
		l6 = vader_core_wit$type_text(l0, l6);
		l7 = l6;
		if (l6.tag == 1522u) {
			t1 = l7.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l5 = l6.payload.s;
		t0 = concat_5(644u, l2, 87u, l5, 2u);
		l3 = vader_box_string(642u, t0);
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
	if (l0.tag == 1526u) {
		t0 = l0.payload.obj;
		l1 = vader_core_wit$declared_tag(((vader_struct_vader_core_wit$WitAlias_t*) t0)->f_target);
		{ vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l0.tag == 1531u) {
		t0 = l0.payload.obj;
		l3 = ((vader_struct_vader_core_wit$WitEnum_t*) t0)->f_owner;
		if (l3.tag == 0u) {
			{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
		}
		l2 = l3.payload.obj;
		t0 = l0.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitEnum_t*) t0)->f_name;
		t1 = vader_core_wit$struct_tag(l2, l4);
		l1 = vader_box_string(642u, t1);
	} else if (l0.tag == 1557u) {
		t0 = l0.payload.obj;
		l2 = ((vader_struct_vader_core_wit$WitRecord_t*) t0)->f_owner;
		t0 = l0.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitRecord_t*) t0)->f_name;
		t1 = vader_core_wit$struct_tag(l2, l4);
		l1 = vader_box_string(642u, t1);
	} else if (l0.tag == 1574u) {
		t0 = l0.payload.obj;
		l2 = ((vader_struct_vader_core_wit$WitVariant_t*) t0)->f_owner;
		t0 = l0.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitVariant_t*) t0)->f_name;
		t1 = vader_core_wit$struct_tag(l2, l4);
		l1 = vader_box_string(642u, t1);
	} else if (l0.tag == 1534u) {
		t0 = l0.payload.obj;
		l2 = ((vader_struct_vader_core_wit$WitFlags_t*) t0)->f_owner;
		t0 = l0.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitFlags_t*) t0)->f_name;
		t1 = vader_core_wit$struct_tag(l2, l4);
		l1 = vader_box_string(642u, t1);
	} else if (l0.tag == 1559u) {
		t0 = l0.payload.obj;
		l2 = ((vader_struct_vader_core_wit$WitResource_t*) t0)->f_owner;
		t0 = l0.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitResource_t*) t0)->f_name;
		t1 = vader_core_wit$struct_tag(l2, l4);
		l1 = vader_box_string(642u, t1);
	} else {
		if (!((l0.tag == 1538u || l0.tag == 1541u || l0.tag == 1544u || l0.tag == 1549u || l0.tag == 1561u || l0.tag == 647u || l0.tag == 1565u || l0.tag == 1567u || l0.tag == 1570u))) {
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
	if (l5.tag == 1527u) {
		t0 = l6.payload.obj;
		l7 = ((vader_struct_vader_core_wit$WitAliasDef_t*) t0)->f_target;
		l8 = vader_core_wit$type_of(l0, l1, l7);
		l9 = l8;
		if (l8.tag == 1533u) {
			t0 = l9.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l7 = l8;
		vader_struct_vader_core_wit$WitAlias_t* _a0_obj = (vader_struct_vader_core_wit$WitAlias_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitAlias_t));
		vader_obj_header_init(_a0_obj, 1526u);
		_a0_obj->f_name = l3;
		_a0_obj->f_owner = l4;
		_a0_obj->f_target = l7;
		t0 = (void*) _a0_obj;
		l7 = vader_ref_box(t0);
		{ vader_box_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l5.tag == 1558u) {
		vader_array_t* _a1_arr = vader_array_new(252u, 0u, 13u, 1554u);
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
				t0 = vader_core_wit$wit_error(((vader_struct_vader_core_wit$WitMemberDecl_t*) l14)->f_span, 1858u);
				{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l8 = l9;
			l16 = vader_core_wit$type_of(l0, l1, l8);
			l17 = l16;
			if (l16.tag == 1533u) {
				t0 = l17.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l15 = l16;
			t1 = ((vader_struct_vader_core_wit$WitMemberDecl_t*) l14)->f_name;
			vader_struct_vader_core_wit$WitParam_t* _a3_obj = (vader_struct_vader_core_wit$WitParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitParam_t));
			vader_obj_header_init(_a3_obj, 1554u);
			_a3_obj->f_name = t1;
			_a3_obj->f_type = l15;
			l18 = (void*) _a3_obj;
			vader_array_push_ref((vader_array_t*) l10, l18);
			l13 = (l13 + INT64_C(1));
		}
		vader_struct_vader_core_wit$WitRecord_t* _a4_obj = (vader_struct_vader_core_wit$WitRecord_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitRecord_t));
		vader_obj_header_init(_a4_obj, 1557u);
		_a4_obj->f_name = l3;
		_a4_obj->f_owner = l4;
		_a4_obj->f_fields = l10;
		t0 = (void*) _a4_obj;
		l7 = vader_ref_box(t0);
	} else if (l5.tag == 1575u) {
		vader_array_t* _a5_arr = vader_array_new(244u, 0u, 13u, 1529u);
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
			if (l15.tag == 1533u) {
				t0 = l16.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l8 = l15;
			t1 = ((vader_struct_vader_core_wit$WitMemberDecl_t*) l14)->f_name;
			vader_struct_vader_core_wit$WitCase_t* _a7_obj = (vader_struct_vader_core_wit$WitCase_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitCase_t));
			vader_obj_header_init(_a7_obj, 1529u);
			_a7_obj->f_name = t1;
			_a7_obj->f_type = l8;
			l18 = (void*) _a7_obj;
			vader_array_push_ref((vader_array_t*) l10, l18);
			l13 = (l13 + INT64_C(1));
		}
		vader_struct_vader_core_wit$WitVariant_t* _a8_obj = (vader_struct_vader_core_wit$WitVariant_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitVariant_t));
		vader_obj_header_init(_a8_obj, 1574u);
		_a8_obj->f_name = l3;
		_a8_obj->f_owner = l4;
		_a8_obj->f_cases = l10;
		t0 = (void*) _a8_obj;
		l7 = vader_ref_box(t0);
	} else if (l5.tag == 1532u) {
		t0 = l6.payload.obj;
		l10 = ((vader_struct_vader_core_wit$WitEnumDef_t*) t0)->f_cases;
		t2 = vader_array_length(((vader_array_t*) l10));
		vader_array_t* _a9_arr = vader_array_reserve(28u, (int64_t) t2, 0u, 642u);
		l11 = (void*) _a9_arr;
		l12 = vader_array_length(((vader_array_t*) l10));
		l13 = INT64_C(0);
		while ((l13 < l12)) {
			vader_array_t* _a10_slotarr = ((vader_array_t*) l10);
			VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
			t0 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l13);
			l19 = __lambda_vader_core_wit_20(t0);
			vader_array_push_scalar((vader_array_t*) l11, vader_box_string(642u, l19));
			l13 = (l13 + INT64_C(1));
		}
		vader_struct_vader_core_wit$WitEnum_t* _a11_obj = (vader_struct_vader_core_wit$WitEnum_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitEnum_t));
		vader_obj_header_init(_a11_obj, 1531u);
		_a11_obj->f_name = l3;
		_a11_obj->f_cases = l11;
		_a11_obj->f_owner = vader_ref_box(l4);
		t0 = (void*) _a11_obj;
		l7 = vader_ref_box(t0);
	} else if (l5.tag == 1535u) {
		t0 = l6.payload.obj;
		l10 = ((vader_struct_vader_core_wit$WitFlagsDef_t*) t0)->f_flags;
		t2 = vader_array_length(((vader_array_t*) l10));
		vader_array_t* _a12_arr = vader_array_reserve(28u, (int64_t) t2, 0u, 642u);
		l11 = (void*) _a12_arr;
		l12 = vader_array_length(((vader_array_t*) l10));
		l13 = INT64_C(0);
		while ((l13 < l12)) {
			vader_array_t* _a13_slotarr = ((vader_array_t*) l10);
			VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
			t0 = vader_array_ref_load_obj(_a13_slotarr->buf, vader_array_offset(_a13_slotarr) + (size_t) l13);
			l19 = __lambda_vader_core_wit_19(t0);
			vader_array_push_scalar((vader_array_t*) l11, vader_box_string(642u, l19));
			l13 = (l13 + INT64_C(1));
		}
		vader_struct_vader_core_wit$WitFlags_t* _a14_obj = (vader_struct_vader_core_wit$WitFlags_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitFlags_t));
		vader_obj_header_init(_a14_obj, 1534u);
		_a14_obj->f_name = l3;
		_a14_obj->f_owner = l4;
		_a14_obj->f_flags = l11;
		t0 = (void*) _a14_obj;
		l7 = vader_ref_box(t0);
	} else {
		if (!(l5.tag == 1560u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		vader_struct_vader_core_wit$WitResource_t* _a15_obj = (vader_struct_vader_core_wit$WitResource_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitResource_t));
		vader_obj_header_init(_a15_obj, 1559u);
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
	if (l1 == 3432u) {
		l2 = vader_core_wit$expect(l0, (uint8_t) 61);
		l3 = l2;
		if (l2.tag == 1533u) {
			t0 = l3.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l3 = vader_core_wit$type_expr(l0);
		l4 = l3;
		if (l3.tag == 1533u) {
			t0 = l4.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l2 = l3;
		l3 = vader_core_wit$expect(l0, (uint8_t) 59);
		l4 = l3;
		if (!(l3.tag == 1533u)) {
			vader_struct_vader_core_wit$WitAliasDef_t* _a0_obj = (vader_struct_vader_core_wit$WitAliasDef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitAliasDef_t));
			vader_obj_header_init(_a0_obj, 1527u);
			_a0_obj->f_target = l2;
			t0 = (void*) _a0_obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		t0 = l4.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l1 == 3147u) {
		t1 = vader_core_wit$resource_body(l0);
		{ vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = vader_core_wit$members(l0, l1);
	l3 = l2;
	if (l2.tag == 1533u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = l2.payload.obj;
	if (l1 == 3124u) {
		vader_struct_vader_core_wit$WitRecordDef_t* _a1_obj = (vader_struct_vader_core_wit$WitRecordDef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitRecordDef_t));
		vader_obj_header_init(_a1_obj, 1558u);
		_a1_obj->f_fields = l5;
		t0 = (void*) _a1_obj;
		l2 = vader_ref_box(t0);
		{ vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l1 == 3718u) {
		vader_struct_vader_core_wit$WitVariantDef_t* _a2_obj = (vader_struct_vader_core_wit$WitVariantDef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitVariantDef_t));
		vader_obj_header_init(_a2_obj, 1575u);
		_a2_obj->f_cases = l5;
		t0 = (void*) _a2_obj;
		l2 = vader_ref_box(t0);
	} else if (l1 == 2418u) {
		vader_struct_vader_core_wit$WitEnumDef_t* _a3_obj = (vader_struct_vader_core_wit$WitEnumDef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitEnumDef_t));
		vader_obj_header_init(_a3_obj, 1532u);
		_a3_obj->f_cases = l5;
		t0 = (void*) _a3_obj;
		l2 = vader_ref_box(t0);
	} else {
		vader_struct_vader_core_wit$WitFlagsDef_t* _a4_obj = (vader_struct_vader_core_wit$WitFlagsDef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitFlagsDef_t));
		vader_obj_header_init(_a4_obj, 1535u);
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
	if (l3.tag == 1533u) {
		t0 = l5.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = l3.payload.obj;
	std_collections$Map$std_core$IndexSet$set_at__string__Any(((vader_struct_vader_core_wit$Resolution_t*) l0)->f_dependencies, l2, vader_ref_box(l4));
	{ vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_core_wit$drop_of(void* l0) {
	vader_string_t l1 = 0;
	void* l2 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[3] = { &l0, &l2, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l1 = vader_core_wit$resource_drop_name(l0);
	vader_struct_vader_core_wit$WitHandle_t* _a0_obj = (vader_struct_vader_core_wit$WitHandle_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitHandle_t));
	vader_obj_header_init(_a0_obj, 1541u);
	_a0_obj->f_resource = vader_ref_box(l0);
	_a0_obj->f_is_borrow = false;
	l2 = (void*) _a0_obj;
	vader_struct_vader_core_wit$WitParam_t* _a1_obj = (vader_struct_vader_core_wit$WitParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitParam_t));
	vader_obj_header_init(_a1_obj, 1554u);
	_a1_obj->f_name = 3186u;
	_a1_obj->f_type = vader_ref_box(l2);
	t0 = (void*) _a1_obj;
	vader_array_t* _a2_arr = vader_array_new(252u, 1u, 13u, 1554u);
	((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t0;
	t0 = (void*) _a2_arr;
	vader_struct_vader_core_wit$WitFunction_t* _a3_obj = (vader_struct_vader_core_wit$WitFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitFunction_t));
	vader_obj_header_init(_a3_obj, 1536u);
	_a3_obj->f_params = t0;
	_a3_obj->f_result = vader_box_obj(0u, NULL);
	_a3_obj->f_is_async = false;
	l2 = (void*) _a3_obj;
	vader_struct_vader_core_wit$WitNamedFunction_t* _a4_obj = (vader_struct_vader_core_wit$WitNamedFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitNamedFunction_t));
	vader_obj_header_init(_a4_obj, 1548u);
	_a4_obj->f_name = l1;
	_a4_obj->f_member = 2370u;
	_a4_obj->f_kind = (uint8_t) 4;
	_a4_obj->f_resource = vader_ref_box(l0);
	_a4_obj->f_type = l2;
	t0 = (void*) _a4_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_core_wit$enum_case_bits(int64_t l0) {
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
	vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t0, 0u, 642u);
	l3 = (void*) _a0_arr;
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t1 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l5];
		t2 = t1.payload.s;
		l6 = __lambda_vader_core_wit_15(t2);
		vader_array_push_scalar((vader_array_t*) l3, vader_box_string(642u, l6));
		l5 = (l5 + INT64_C(1));
	}
	l2 = l3;
	l6 = l0;
	t0 = vader_array_length(((vader_array_t*) l1));
	l4 = vader_core_wit$enum_case_bits(t0);
	l7 = std_string$join(l2, 0u);
	l5 = (int64_t) vader_string_byte_len(l6);
	l8 = (int64_t) vader_string_byte_len(l7);
	l5 = (l5 + l8);
	l2 = (void*) vader_buffer_new((size_t) (INT64_C(43) + l5));
	l5 = INT64_C(0);
	l5 = std_core$write_string_at(l2, l5, 2480u);
	l5 = std_core$write_string_at(l2, l5, l6);
	l5 = std_core$write_string_at(l2, l5, 92u);
	l5 = std_core$write_int(l2, l5, l4);
	l5 = std_core$write_string_at(l2, l5, 415u);
	l5 = std_core$write_string_at(l2, l5, l7);
	l5 = std_core$write_string_at(l2, l5, 3827u);
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
	vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t0, 0u, 642u);
	l3 = (void*) _a0_arr;
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t1 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l5];
		t2 = t1.payload.s;
		l6 = __lambda_vader_core_wit_16(t2);
		vader_array_push_scalar((vader_array_t*) l3, vader_box_string(642u, l6));
		l5 = (l5 + INT64_C(1));
	}
	l2 = l3;
	l6 = concat_3(2u, l0, 181u);
	l7 = std_string$join(l2, 0u);
	l7 = concat_3(39u, l7, 44u);
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
	if (l1.tag == 1531u) {
		t1 = l1.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitEnum_t*) t1)->f_cases;
		t2 = vader_core_wit$enum_error_impl(l3, l4);
		{ vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l1.tag == 1574u)) {
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l1 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(26u, 0u, 12u, 640u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l3 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__bool_t* _a3_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a3_obj, 1010u);
	_a3_obj->f_ekeys = l1;
	_a3_obj->f_evals = l2;
	_a3_obj->f_index = l3;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a3_obj;
	vader_struct_std_collections$Set__string_t* _a4_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
	vader_obj_header_init(_a4_obj, 1110u);
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
		l2 = concat_3(2450u, l2, 1318u);
		t1 = vader_core_wit$fail_here(l0, l2);
		{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ vader_box_t __vret = vader_box_obj(643u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
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
		l2 = 3363u;
	} else {
		t1 = vader_core_wit$peek(l0);
		l3 = std_core$char$Display$to_string(((uint32_t) (uint8_t) t1));
		l2 = concat_3(1318u, l3, 1318u);
	}
	l4 = vader_core_wit$span(l0);
	l2 = concat_3(l1, 458u, l2);
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
	vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t0, 0u, 642u);
	l3 = (void*) _a0_arr;
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t1 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l5];
		t2 = t1.payload.s;
		l6 = __lambda_vader_core_wit_14(t2);
		vader_array_push_scalar((vader_array_t*) l3, vader_box_string(642u, l6));
		l5 = (l5 + INT64_C(1));
	}
	l6 = std_string$join(l3, 0u);
	t2 = concat_5(2480u, l0, 97u, l6, 3827u);
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
	if (l5.tag == 1533u) {
		t0 = l6.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = l5.payload.s;
	l5 = vader_core_wit$expect(l0, (uint8_t) 58);
	l6 = l5;
	if (l5.tag == 1533u) {
		t0 = l6.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l7 = (uint8_t) 0;
	t1 = vader_core_wit$at_keyword(l0, 3228u);
	if (t1) {
		vader_core_wit$word(l0);
		l7 = (uint8_t) 2;
	}
	l8 = vader_core_wit$at_keyword(l0, 2077u);
	if (l8) {
		vader_core_wit$word(l0);
	}
	t1 = vader_core_wit$at_keyword(l0, 2591u);
	if (!(t1)) {
		t0 = vader_core_wit$fail_here(l0, 2455u);
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_core_wit$word(l0);
	l5 = vader_core_wit$params(l0);
	l6 = l5;
	if (l5.tag == 1533u) {
		t0 = l6.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l9 = l5.payload.obj;
	vader_struct_vader_core_wit$WitFunctionDecl_t* _a0_obj = (vader_struct_vader_core_wit$WitFunctionDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitFunctionDecl_t));
	vader_obj_header_init(_a0_obj, 1537u);
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
		if (l6.tag == 1533u) {
			t0 = l10.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l5 = l6;
		((vader_struct_vader_core_wit$WitFunctionDecl_t*) l9)->f_result = l5;
		VADER_WRITE_BARRIER((vader_struct_vader_core_wit$WitFunctionDecl_t*) l9);
	}
	l5 = vader_core_wit$expect(l0, (uint8_t) 59);
	l6 = l5;
	if (!(l5.tag == 1533u)) {
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
	if (l3.tag == 1522u) {
		l2 = l4.payload.obj;
		t0 = vader_core_wit$left_out(l1, l2);
		{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = l3.payload.obj;
	l3 = vader_core_wit$returned(l0, l1);
	l4 = l3;
	if (l3.tag == 1522u) {
		l5 = l4.payload.obj;
		t0 = vader_core_wit$left_out(l1, l5);
		{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = l3.payload.obj;
	l6 = ((vader_struct_vader_core_wit$Returned_t*) l5)->f_wrapper;
	l7 = ((vader_struct_vader_core_wit$WitNamedFunction_t*) l1)->f_name;
	l6 = concat_4(l6, 651u, l7, 322u);
	l7 = vader_core_wit$vader_function_name(l1);
	l7 = concat_3(2480u, l7, 94u);
	l8 = ((vader_struct_vader_core_wit$Returned_t*) l5)->f_text;
	l8 = concat_2(400u, l8);
	l9 = std_string$join(l2, 443u);
	l10 = (int64_t) vader_string_byte_len(l7);
	l11 = (int64_t) vader_string_byte_len(l9);
	l10 = vader_chk_add(i64, l10, l11);
	l11 = (int64_t) vader_string_byte_len(l8);
	t1 = vader_chk_add(i64, l10, l11);
	if ((t1 <= INT64_C(100))) {
		l12 = true;
	} else {
		t1 = vader_array_length(((vader_array_t*) l2));
		l12 = t1 == INT64_C(0);
	}
	if (l12) {
		t0 = concat_5(l6, l7, l9, l8, 2u);
		{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = vader_array_length(((vader_array_t*) l2));
	vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t1, 0u, 642u);
	l5 = (void*) _a0_arr;
	l10 = vader_array_length(((vader_array_t*) l2));
	l11 = INT64_C(0);
	while ((l11 < l10)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t2 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l11];
		t0 = t2.payload.s;
		l9 = __lambda_vader_core_wit_10(t0);
		vader_array_push_scalar((vader_array_t*) l5, vader_box_string(642u, l9));
		l11 = (l11 + INT64_C(1));
	}
	l9 = std_string$join(l5, 0u);
	t0 = concat_6(l6, l7, 2u, l9, l8, 2u);
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
		l3 = concat_4(1233u, l3, 491u, l4);
		{ vader_string_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l2 == INT32_C(2)) {
		t1 = l1.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitResource_t*) t1)->f_name;
		l5 = ((vader_struct_vader_core_wit$WitFunctionDecl_t*) l0)->f_name;
		l3 = concat_4(1235u, l4, 491u, l5);
	} else if (l2 == INT32_C(3)) {
		t1 = l1.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitResource_t*) t1)->f_name;
		l3 = concat_2(1232u, l4);
	} else if (l2 == INT32_C(4)) {
		t1 = l1.payload.obj;
		l3 = vader_core_wit$resource_drop_name(t1);
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
	vader_array_t* _a0_arr = vader_array_new(252u, 0u, 13u, 1554u);
	l4 = (void*) _a0_arr;
	if (((vader_struct_vader_core_wit$WitFunctionDecl_t*) l2)->f_kind == INT32_C(1)) {
		if (!(l3.tag == 0u)) {
			t0 = l3.payload.obj;
			vader_struct_vader_core_wit$WitHandle_t* _a1_obj = (vader_struct_vader_core_wit$WitHandle_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitHandle_t));
			vader_obj_header_init(_a1_obj, 1541u);
			_a1_obj->f_resource = vader_ref_box(t0);
			_a1_obj->f_is_borrow = true;
			l5 = (void*) _a1_obj;
			vader_struct_vader_core_wit$WitParam_t* _a2_obj = (vader_struct_vader_core_wit$WitParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitParam_t));
			vader_obj_header_init(_a2_obj, 1554u);
			_a2_obj->f_name = 3186u;
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
		if (l11.tag == 1533u) {
			t0 = l12.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l9 = l11;
		t1 = ((vader_struct_vader_core_wit$WitParamDecl_t*) l8)->f_name;
		vader_struct_vader_core_wit$WitParam_t* _a4_obj = (vader_struct_vader_core_wit$WitParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitParam_t));
		vader_obj_header_init(_a4_obj, 1554u);
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
				vader_obj_header_init(_a5_obj, 1541u);
				_a5_obj->f_resource = vader_ref_box(t0);
				_a5_obj->f_is_borrow = false;
				t0 = (void*) _a5_obj;
				l9 = vader_ref_box(t0);
			}
		}
	} else {
		l10 = vader_core_wit$type_of(l0, l1, l10);
		l11 = l10;
		if (l10.tag == 1533u) {
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
	vader_obj_header_init(_a6_obj, 1536u);
	_a6_obj->f_params = l4;
	_a6_obj->f_result = l9;
	_a6_obj->f_is_async = l17;
	l4 = (void*) _a6_obj;
	vader_struct_vader_core_wit$WitNamedFunction_t* _a7_obj = (vader_struct_vader_core_wit$WitNamedFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitNamedFunction_t));
	vader_obj_header_init(_a7_obj, 1548u);
	_a7_obj->f_name = l14;
	_a7_obj->f_member = l15;
	_a7_obj->f_kind = l16;
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
		l5 = true;
	} else {
		l5 = l3 == INT32_C(4);
	}
	if (l5) {
		l4 = ((vader_struct_vader_core_wit$WitResource_t*) l1)->f_name;
		l6 = ((vader_struct_vader_core_wit$WitNamedFunction_t*) l0)->f_member;
		l4 = concat_3(l4, 478u, l6);
		{ vader_string_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l3 == INT32_C(3)) {
		l6 = ((vader_struct_vader_core_wit$WitResource_t*) l1)->f_name;
		l4 = concat_2(2978u, l6);
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
	if (l1.tag == 1533u) {
		t0 = l2.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_struct_vader_core_wit$WitFutureExpr_t* _a0_obj = (vader_struct_vader_core_wit$WitFutureExpr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitFutureExpr_t));
	vader_obj_header_init(_a0_obj, 1539u);
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
		{ vader_box_t __vret = vader_box_string(642u, 3736u); vader_gc_top = gc_frame.prev; return __vret; }
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
	vader_obj_header_init(_a0_obj, 1540u);
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
			if (l4.tag == 1533u) {
				t1 = l5.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l7 = vader_core_wit$identifier(l0);
			l8 = l7;
			if (l7.tag == 1533u) {
				t1 = l8.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l6 = l7.payload.s;
			l9 = vader_core_wit$expect(l0, (uint8_t) 61);
			l10 = l9;
			if (l9.tag == 1533u) {
				t1 = l10.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l12 = vader_core_wit$version(l0);
			l13 = l12;
			if (l12.tag == 1533u) {
				t1 = l13.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l11 = l12.payload.s;
			l14 = vader_core_wit$expect(l0, (uint8_t) 41);
			l15 = l14;
			if (l14.tag == 1533u) {
				t1 = l15.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
			}
			if (l6 != 3731u) {
				if (l6 != 2521u) {
					l16 = concat_3(3514u, l6, 1318u);
					t1 = vader_core_wit$wit_error(l2, l16);
					{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
				}
			}
			if (l3 == 3201u) {
				((vader_struct_vader_core_wit$WitGate_t*) l1)->f_since = l11;
				continue;
			}
			if (l3 == 3530u) {
				((vader_struct_vader_core_wit$WitGate_t*) l1)->f_unstable = l11;
			} else {
				if (!(l3 == 2353u)) {
					l17 = concat_3(3513u, l3, 1318u);
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
	t0 = std_string$string$std_core$Contains$contains(l0, 307u);
	if (t0) {
		t1 = concat_3(379u, l0, 396u);
		{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$handle_keyword(void* l0) {
	bool t0;
	t0 = ((vader_struct_vader_core_wit$WitHandle_t*) l0)->f_is_borrow;
	if (t0) {
		return 2114u;
	}
	return 3067u;
}

bool vader_core_wit$has_bare_cases(void* l0) {
	void* l1;
	int64_t l2, l3;
	void* t0;
	bool t1;
	l1 = ((vader_struct_vader_core_wit$WitVariant_t*) l0)->f_cases;
	l2 = vader_array_length(((vader_array_t*) l1));
	l3 = INT64_C(0);
	while ((l3 < l2)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
		t1 = __lambda_vader_core_wit_3(t0);
		if (t1) {
			return true;
		}
		l3 = (l3 + INT64_C(1));
	}
	return false;
}

static vader_box_t vader_core_wit$identifier(void* l0) {
	vader_string_t l1 = 0;
	bool l2;
	int64_t l3;
	void* t0 = NULL;
	bool t1;
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l1 = vader_core_wit$word_here(l0);
	if (l1 == 0u) {
		l2 = true;
	} else {
		l2 = l1 == 356u;
	}
	if (l2) {
		t0 = vader_core_wit$fail_here(l0, 2462u);
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_core_wit$word(l0);
	t1 = std_string$starts_with(l1, 356u);
	if (!(t1)) {
		{ vader_box_t __vret = vader_box_string(642u, l1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = (int64_t) vader_string_byte_len(l1);
	{ vader_box_t __vret = vader_box_string(642u, vader_string_byte_slice(l1, INT64_C(1), l3)); vader_gc_top = gc_frame.prev; return __vret; }
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
	if (l5.tag == 1533u) {
		t0 = l6.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = l5.payload.s;
	vader_array_t* _a0_arr = vader_array_new(256u, 0u, 13u, 1571u);
	l7 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(255u, 0u, 13u, 1569u);
	l8 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(246u, 0u, 13u, 1537u);
	l9 = (void*) _a2_arr;
	vader_struct_vader_core_wit$WitInterfaceDecl_t* _a3_obj = (vader_struct_vader_core_wit$WitInterfaceDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitInterfaceDecl_t));
	vader_obj_header_init(_a3_obj, 1543u);
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
	if (l5.tag == 1533u) {
		t0 = l6.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	for (;;) {
		t1 = vader_core_wit$skip(l0, (uint8_t) 125);
		if (!(t1)) {
			t1 = vader_core_wit$at_end(l0);
			if (t1) {
				t0 = vader_core_wit$fail_here(l0, 2460u);
				{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l4 = vader_core_wit$take_doc(l0);
			l5 = vader_core_wit$gate(l0);
			l6 = l5;
			if (l5.tag == 1533u) {
				t0 = l6.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l8 = l5.payload.obj;
			l9 = vader_core_wit$span(l0);
			t1 = vader_core_wit$at_keyword(l0, 3542u);
			if (t1) {
				vader_core_wit$word(l0);
				l11 = vader_core_wit$use_decl(l0, l8, l9);
				l12 = l11;
				if (l11.tag == 1533u) {
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
				if (l14.tag == 1533u) {
					t0 = l15.payload.obj;
					{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
				}
				l13 = l14.payload.obj;
				vader_array_push_ref((vader_array_t*) ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) l7)->f_types, l13);
			} else {
				l17 = vader_core_wit$function_decl(l0, l4, l8, l9);
				l18 = l17;
				if (l17.tag == 1533u) {
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
	t0 = concat_9(1218u, l2, 566u, l3, 323u, l4, 324u, l5, 325u);
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
	void* l20 = NULL;
	int64_t l5, l6, l13, l14;
	vader_string_t l7 = 0;
	vader_box_t l8 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null(), l18 = vader_box_null(), l19 = vader_box_null();
	vader_box_t t0 = vader_box_null();
	void* t1 = NULL;
	bool t2;
	vader_box_t* gc_roots[6] = { &l8, &l10, &l11, &l18, &l19, &t0 };
	void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l9, &l12, &l15, &l16, &l17, &l20, &t1 };
	vader_string_t* gc_atom_roots[1] = { &l7 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 6u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_core_wit$InterfaceScope_t*) l1)->f_owner;
	vader_array_t* _a0_arr = vader_array_new(499u, 0u, 13u, 2829u);
	l3 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(250u, 0u, 13u, 1548u);
	l4 = (void*) _a1_arr;
	vader_struct_vader_core_wit$WitInterface_t* _a2_obj = (vader_struct_vader_core_wit$WitInterface_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitInterface_t));
	vader_obj_header_init(_a2_obj, 1542u);
	_a2_obj->f_owner = l2;
	_a2_obj->f_types = l3;
	_a2_obj->f_functions = l4;
	l2 = (void*) _a2_obj;
	vader_array_t* _a3_arr = vader_array_new(250u, 0u, 13u, 1548u);
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
		if (l10.tag == 1533u) {
			t1 = l11.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l8 = l10;
		vader_array_push_ref((vader_array_t*) ((vader_struct_vader_core_wit$WitInterface_t*) l2)->f_types, l8.payload.obj);
		if (l8.tag == 1559u) {
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
				if (l18.tag == 1533u) {
					t1 = l19.payload.obj;
					{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
				}
				l16 = l18.payload.obj;
				vader_array_push_ref((vader_array_t*) l3, l16);
				l14 = (l14 + INT64_C(1));
			}
			t1 = l8.payload.obj;
			l20 = vader_core_wit$drop_of(t1);
			vader_array_push_ref((vader_array_t*) l3, l20);
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
		t2 = __lambda_vader_core_wit_13(l9);
		if (t2) {
			l12 = l9;
			l8 = vader_core_wit$function_of(l0, l1, l12, vader_box_obj(0u, NULL));
			l10 = l8;
			if (l8.tag == 1533u) {
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
	while (l1.tag == 1526u) {
		t0 = l1.payload.obj;
		l1 = ((vader_struct_vader_core_wit$WitAlias_t*) t0)->f_target;
	}
	return l1.tag == 1559u;
}

static bool vader_core_wit$is_stable(void* l0) {
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
	t0 = concat_5(543u, l2, 1485u, l3, 492u);
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
	if (l1.tag == 1533u) {
		t0 = l2.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = vader_core_wit$type_expr(l0);
	l3 = l2;
	if (l2.tag == 1533u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = l2;
	t1 = vader_core_wit$peek(l0);
	if (t1 == INT32_C(44)) {
		t0 = vader_core_wit$fail_here(l0, 1887u);
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = vader_core_wit$expect(l0, (uint8_t) 62);
	l3 = l2;
	if (!(l2.tag == 1533u)) {
		vader_struct_vader_core_wit$WitListExpr_t* _a0_obj = (vader_struct_vader_core_wit$WitListExpr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitListExpr_t));
		vader_obj_header_init(_a0_obj, 1545u);
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
	if (l2.tag == 1533u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a0_arr = vader_array_new(249u, 0u, 13u, 1546u);
	l4 = (void*) _a0_arr;
	for (;;) {
		t1 = vader_core_wit$skip(l0, (uint8_t) 125);
		if (!(t1)) {
			l5 = vader_core_wit$take_doc(l0);
			l6 = vader_core_wit$span(l0);
			l2 = vader_core_wit$identifier(l0);
			l3 = l2;
			if (l2.tag == 1533u) {
				t0 = l3.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
			}
			t2 = l2.payload.s;
			vader_struct_vader_core_wit$WitMemberDecl_t* _a1_obj = (vader_struct_vader_core_wit$WitMemberDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitMemberDecl_t));
			vader_obj_header_init(_a1_obj, 1546u);
			_a1_obj->f_name = t2;
			_a1_obj->f_type = vader_box_obj(0u, NULL);
			_a1_obj->f_doc = l5;
			_a1_obj->f_span = l6;
			l7 = (void*) _a1_obj;
			if (l1 == 3124u) {
				l8 = vader_core_wit$expect(l0, (uint8_t) 58);
				l9 = l8;
				if (l8.tag == 1533u) {
					t0 = l9.payload.obj;
					{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
				}
				l11 = vader_core_wit$type_expr(l0);
				l12 = l11;
				if (l11.tag == 1533u) {
					t0 = l12.payload.obj;
					{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
				}
				l10 = l11;
				((vader_struct_vader_core_wit$WitMemberDecl_t*) l7)->f_type = l10;
				VADER_WRITE_BARRIER((vader_struct_vader_core_wit$WitMemberDecl_t*) l7);
			} else if (l1 == 3718u) {
				t1 = vader_core_wit$skip(l0, (uint8_t) 40);
				if (t1) {
					l14 = vader_core_wit$type_expr(l0);
					l15 = l14;
					if (l14.tag == 1533u) {
						t0 = l15.payload.obj;
						{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
					}
					l13 = l14;
					l16 = vader_core_wit$expect(l0, (uint8_t) 41);
					l17 = l16;
					if (l16.tag == 1533u) {
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
			if (!(l18.tag == 1533u)) {
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
	t0 = concat_5(2u, l0, 182u, l1, 319u);
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
	if (l2.tag == 1533u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = l2.payload.s;
	vader_struct_vader_core_wit$WitNameExpr_t* _a0_obj = (vader_struct_vader_core_wit$WitNameExpr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitNameExpr_t));
	vader_obj_header_init(_a0_obj, 1547u);
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
		t0 = concat_3(l3, 491u, l4);
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
	t1 = concat_3(t0, 491u, l1);
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
		l6 = concat_5(3006u, l2, 1442u, l6, 1318u);
		t1 = vader_core_wit$wit_error(l3, l6);
		{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = l4.payload.obj;
	l7 = vader_core_wit$used_type(l0, l5);
	l8 = l7;
	if (l7.tag == 1533u) {
		t1 = l8.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = l7;
	l5 = ((vader_struct_vader_core_wit$InterfaceScope_t*) l1)->f_owner;
	vader_struct_vader_core_wit$WitAlias_t* _a0_obj = (vader_struct_vader_core_wit$WitAlias_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitAlias_t));
	vader_obj_header_init(_a0_obj, 1526u);
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l1 = (void*) _a0_arr;
	l3 = vader_core_wit$identifier(l0);
	l4 = l3;
	if (l3.tag == 1533u) {
		t0 = l4.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = l3.payload.s;
	vader_array_push_scalar((vader_array_t*) l1, vader_box_string(642u, l2));
	for (;;) {
		t1 = vader_core_wit$skip(l0, (uint8_t) 58);
		if (t1) {
			l3 = vader_core_wit$identifier(l0);
			l4 = l3;
			if (l3.tag == 1533u) {
				t0 = l4.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l2 = l3.payload.s;
			vader_array_push_scalar((vader_array_t*) l1, vader_box_string(642u, l2));
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
		l2 = std_string$join(t0, 566u);
		t2 = vader_array_length(((vader_array_t*) l1));
		l5 = vader_chk_sub(i64, t2, INT64_C(1));
		vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		t3 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l5];
		l6 = t3.payload.s;
		vader_struct_vader_core_wit$WitPackageName_t* _a3_obj = (vader_struct_vader_core_wit$WitPackageName_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitPackageName_t));
		vader_obj_header_init(_a3_obj, 1553u);
		_a3_obj->f_namespace = l2;
		_a3_obj->f_name = l6;
		_a3_obj->f_version = 0u;
		t0 = (void*) _a3_obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = vader_core_wit$fail_here(l0, 2457u);
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
	vader_obj_header_init(_a0_obj, 1522u);
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 653u);
	l3 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l4 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 1004u);
	_a3_obj->f_ekeys = l2;
	_a3_obj->f_evals = l3;
	_a3_obj->f_index = l4;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l2 = (void*) _a3_obj;
	vader_array_t* _a4_arr = vader_array_new(28u, 0u, 0u, 642u);
	l3 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(35u, 0u, 0u, 653u);
	l4 = (void*) _a5_arr;
	vader_array_t* _a6_arr = vader_array_new(29u, 0u, 7u, 645u);
	l5 = (void*) _a6_arr;
	vader_struct_std_collections$Map__string__Any_t* _a7_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a7_obj, 1004u);
	_a7_obj->f_ekeys = l3;
	_a7_obj->f_evals = l4;
	_a7_obj->f_index = l5;
	_a7_obj->f_mask = INT64_C(0);
	_a7_obj->f_grow_at = INT64_C(0);
	_a7_obj->f_size = INT64_C(0);
	_a7_obj->f_tombs = INT64_C(0);
	l3 = (void*) _a7_obj;
	vader_array_t* _a8_arr = vader_array_new(28u, 0u, 0u, 642u);
	l4 = (void*) _a8_arr;
	vader_array_t* _a9_arr = vader_array_new(28u, 0u, 0u, 642u);
	l5 = (void*) _a9_arr;
	vader_array_t* _a10_arr = vader_array_new(35u, 0u, 0u, 653u);
	l6 = (void*) _a10_arr;
	vader_array_t* _a11_arr = vader_array_new(29u, 0u, 7u, 645u);
	l7 = (void*) _a11_arr;
	vader_struct_std_collections$Map__string__Any_t* _a12_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a12_obj, 1004u);
	_a12_obj->f_ekeys = l5;
	_a12_obj->f_evals = l6;
	_a12_obj->f_index = l7;
	_a12_obj->f_mask = INT64_C(0);
	_a12_obj->f_grow_at = INT64_C(0);
	_a12_obj->f_size = INT64_C(0);
	_a12_obj->f_tombs = INT64_C(0);
	l5 = (void*) _a12_obj;
	vader_array_t* _a13_arr = vader_array_new(28u, 0u, 0u, 642u);
	l6 = (void*) _a13_arr;
	vader_array_t* _a14_arr = vader_array_new(26u, 0u, 12u, 640u);
	l7 = (void*) _a14_arr;
	vader_array_t* _a15_arr = vader_array_new(29u, 0u, 7u, 645u);
	l8 = (void*) _a15_arr;
	vader_struct_std_collections$Map__string__bool_t* _a16_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
	vader_obj_header_init(_a16_obj, 1010u);
	_a16_obj->f_ekeys = l6;
	_a16_obj->f_evals = l7;
	_a16_obj->f_index = l8;
	_a16_obj->f_mask = INT64_C(0);
	_a16_obj->f_grow_at = INT64_C(0);
	_a16_obj->f_size = INT64_C(0);
	_a16_obj->f_tombs = INT64_C(0);
	l6 = (void*) _a16_obj;
	vader_struct_vader_core_wit$InterfaceScope_t* _a17_obj = (vader_struct_vader_core_wit$InterfaceScope_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$InterfaceScope_t));
	vader_obj_header_init(_a17_obj, 1521u);
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
		t0 = __lambda_vader_core_wit_11(l4);
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
				if (l14.tag == 1533u) {
					t1 = l15.payload.obj;
					{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
				}
				l16 = ((vader_struct_vader_core_wit$InterfaceScope_t*) l2)->f_used;
				l17 = ((vader_struct_vader_core_wit$WitUseName_t*) l7)->f_local;
				l18 = ((vader_struct_vader_core_wit$WitUseDecl_t*) l5)->f_path;
				l19 = ((vader_struct_vader_core_wit$WitUseName_t*) l7)->f_name;
				l20 = ((vader_struct_vader_core_wit$WitUseName_t*) l7)->f_span;
				vader_struct_vader_core_wit$UsedName_t* _a20_obj = (vader_struct_vader_core_wit$UsedName_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$UsedName_t));
				vader_obj_header_init(_a20_obj, 1525u);
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
		t0 = __lambda_vader_core_wit_12(l4);
		if (t0) {
			l5 = l4;
			l13 = ((vader_struct_vader_core_wit$WitTypeDecl_t*) l5)->f_name;
			l6 = ((vader_struct_vader_core_wit$WitTypeDecl_t*) l5)->f_span;
			l14 = vader_core_wit$take_name(l2, l13, l6);
			l15 = l14;
			if (l14.tag == 1533u) {
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
	if (l1.tag == 1533u) {
		t0 = l2.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_struct_vader_core_wit$WitOptionExpr_t* _a0_obj = (vader_struct_vader_core_wit$WitOptionExpr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitOptionExpr_t));
	vader_obj_header_init(_a0_obj, 1550u);
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
	if (l1.tag == 1533u) {
		t1 = l2.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = vader_core_wit$expect(l0, (uint8_t) 62);
	l3 = l2;
	if (!(l2.tag == 1533u)) {
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
	{ vader_gc_top = gc_frame.prev; return 3736u; }
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
	t0 = vader_core_wit$resource_argument(l0, l1, 3067u);
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
	if (l2.tag == 1533u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = l2.payload.obj;
	t1 = vader_core_wit$peek(l0);
	if (t1 == INT32_C(123)) {
		t0 = vader_core_wit$fail_here(l0, 1900u);
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = vader_core_wit$expect(l0, (uint8_t) 59);
	l3 = l2;
	if (!(l2.tag == 1533u)) {
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
	if (l2.tag == 1533u) {
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
		if (l2.tag == 1533u) {
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
				vader_obj_header_init(_a1_obj, 1564u);
				_a1_obj->f_file = t1;
				_a1_obj->f_line = INT32_C(1);
				_a1_obj->f_column = INT32_C(1);
				l11 = (void*) _a1_obj;
				l12 = vader_core_wit$wit_package_text(l7);
				t0 = l2.payload.obj;
				l13 = vader_core_wit$wit_package_text(t0);
				l14 = concat_5(3071u, l12, 1444u, l13, 1318u);
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
	vader_obj_header_init(_a3_obj, 1564u);
	_a3_obj->f_file = l9;
	_a3_obj->f_line = INT32_C(1);
	_a3_obj->f_column = INT32_C(1);
	t0 = (void*) _a3_obj;
	t3 = vader_core_wit$wit_error(t0, 2987u);
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
	if (l2.tag == 1538u) {
		t0 = l2.payload.obj;
		t1 = vader_core_wit$no_form(vader_ref_box(t0), 1876u);
		{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l2.tag == 1565u)) {
		l3 = l2;
		t2 = vader_core_wit$type_text(l0, l3);
		{ vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t3 = ((vader_struct_vader_core_wit$WitFunction_t*) ((vader_struct_vader_core_wit$WitNamedFunction_t*) l1)->f_type)->f_is_async;
	if (t3) {
		t0 = l2.payload.obj;
		t1 = vader_core_wit$no_form(vader_ref_box(t0), 1918u);
		{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l2.payload.obj;
	l3 = ((vader_struct_vader_core_wit$WitStream_t*) t0)->f_element;
	l3 = vader_core_wit$type_text(l0, l3);
	l4 = l3;
	if (l3.tag == 1522u) {
		t0 = l4.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t4 = l3.payload.s;
	t5 = vader_core_wit$grouped(t4);
	t4 = concat_2(t5, 1231u);
	{ vader_box_t __vret = vader_box_string(642u, t4); vader_gc_top = gc_frame.prev; return __vret; }
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
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
		if (l9.tag == 1522u) {
			t0 = l10.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l7 = l9.payload.s;
		t1 = ((vader_struct_vader_core_wit$WitParam_t*) l6)->f_name;
		t2 = vader_core_wit$snake_name(t1);
		l11 = concat_3(t2, 567u, l7);
		vader_array_push_scalar((vader_array_t*) l2, vader_box_string(642u, l11));
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
	if (l1.tag == 1533u) {
		t0 = l2.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a0_arr = vader_array_new(253u, 0u, 13u, 1555u);
	l3 = (void*) _a0_arr;
	for (;;) {
		t1 = vader_core_wit$skip(l0, (uint8_t) 41);
		if (!(t1)) {
			l1 = vader_core_wit$identifier(l0);
			l2 = l1;
			if (l1.tag == 1533u) {
				t0 = l2.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l4 = l1.payload.s;
			l5 = vader_core_wit$expect(l0, (uint8_t) 58);
			l6 = l5;
			if (l5.tag == 1533u) {
				t0 = l6.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l8 = vader_core_wit$type_expr(l0);
			l9 = l8;
			if (l8.tag == 1533u) {
				t0 = l9.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l7 = l8;
			vader_struct_vader_core_wit$WitParamDecl_t* _a1_obj = (vader_struct_vader_core_wit$WitParamDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitParamDecl_t));
			vader_obj_header_init(_a1_obj, 1555u);
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
			if (!(l11.tag == 1533u)) {
				break;
			}
			t0 = l12.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		break;
	}
	{ vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$pascal_name(vader_string_t l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	int64_t l3, l4, l7;
	vader_string_t l5 = 0;
	vader_string_t l6 = 0;
	vader_string_t l8 = 0;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[1] = { &t1 };
	void** gc_raw_roots[3] = { &l1, &l2, &t0 };
	vader_string_t* gc_atom_roots[5] = { &l0, &l5, &l6, &l8, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	t0 = (void*) _a0_arr;
	vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
	vader_obj_header_init(_a1_obj, 1139u);
	_a1_obj->f_parts = t0;
	l1 = (void*) _a1_obj;
	l2 = std_string$split(l0, 478u);
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		t1 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l4];
		l5 = t1.payload.s;
		if ((int64_t) vader_string_byte_len(l5) == INT64_C(0)) {
			l4 = (l4 + INT64_C(1));
			continue;
		}
		l6 = std_string$to_upper(vader_string_byte_slice(l5, INT64_C(0), INT64_C(1)));
		std_string__builder$append(l1, l6);
		l7 = (int64_t) vader_string_byte_len(l5);
		l8 = std_string$to_lower(vader_string_byte_slice(l5, INT64_C(1), l7));
		std_string__builder$append(l1, l8);
		l4 = (l4 + INT64_C(1));
	}
	t2 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
	{ vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
	vader_array_t* _a0_arr = vader_array_new(244u, 0u, 13u, 1529u);
	l2 = (void*) _a0_arr;
	l3 = vader_array_length(((vader_array_t*) l1));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l5 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		t0 = __lambda_vader_core_wit_8(l5);
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
	t0 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_at;
	l2 = vader_chk_add(i64, t0, l1);
	t1 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_text;
	l3 = (int64_t) vader_string_byte_len(t1);
	if (!((l2 >= l3))) {
		l4 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_text;
		t0 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_at;
		l2 = vader_chk_add(i64, t0, l1);
		return vader_string_byte_at(l4, (size_t) l2);
	}
	return (uint8_t) 0;
}

static uint8_t vader_core_wit$peek_word_end(void* l0) {
	int64_t l1;
	vader_string_t t0;
	uint8_t t1;
	t0 = vader_core_wit$word_here(l0);
	l1 = (int64_t) vader_string_byte_len(t0);
	t1 = vader_core_wit$peek_at(l0, l1);
	return t1;
}

static void* vader_core_wit$present(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	int64_t l3, l4;
	vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l5, &l6 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(498u, 0u, 0u, 2825u);
	l1 = (void*) _a0_arr;
	l2 = l0;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l5 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l4];
		if (!(l5.tag == 0u)) {
			l6 = l5;
			vader_array_push((vader_array_t*) l1, l6);
		}
		l4 = (l4 + INT64_C(1));
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_core_wit$push_declared_errors(vader_box_t l0, void* l1) {
	void* l2 = NULL;
	int64_t l3, l4;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l0 };
	void** gc_raw_roots[3] = { &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l0.tag == 1557u) {
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
	} else if (l0.tag == 1574u) {
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
	} else if (l0.tag == 1526u) {
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
	if (l0.tag == 1544u) {
		t0 = l0.payload.obj;
		vader_core_wit$push_errors(((vader_struct_vader_core_wit$WitList_t*) t0)->f_element, l1);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l0.tag == 1549u) {
		t0 = l0.payload.obj;
		vader_core_wit$push_errors(((vader_struct_vader_core_wit$WitOption_t*) t0)->f_value, l1);
	} else if (l0.tag == 1567u) {
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
	} else if (l0.tag == 1561u) {
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
	} else if (l0.tag == 1565u) {
		t0 = l0.payload.obj;
		vader_core_wit$push_errors(((vader_struct_vader_core_wit$WitStream_t*) t0)->f_element, l1);
	} else if (l0.tag == 1538u) {
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
	if (l0.tag == 647u) {
		t0 = ((uint8_t) l0.payload.i);
		l2 = vader_core_wit$scalar_text(t0);
		vader_array_push_scalar((vader_array_t*) l1, vader_box_string(642u, l2));
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l0.tag == 1531u) {
		l3 = (void*) vader_buffer_new((size_t) INT64_C(21));
		l4 = INT64_C(0);
		l4 = std_core$write_string_at(l3, l4, 3462u);
		t1 = l0.payload.obj;
		t2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_wit$WitEnum_t*) t1)->f_cases));
		l5 = vader_core_wit$enum_case_bits(t2);
		l4 = std_core$write_int(l3, l4, l5);
		l2 = std_core$finish_buffer(l3, l4);
		vader_array_push_scalar((vader_array_t*) l1, vader_box_string(642u, l2));
	} else if (l0.tag == 1574u) {
		t1 = l0.payload.obj;
		vader_core_wit$push_variant_tags(t1, l1);
	} else if (l0.tag == 1557u) {
		t1 = l0.payload.obj;
		l3 = ((vader_struct_vader_core_wit$WitRecord_t*) t1)->f_owner;
		t1 = l0.payload.obj;
		l2 = ((vader_struct_vader_core_wit$WitRecord_t*) t1)->f_name;
		l2 = vader_core_wit$struct_tag(l3, l2);
		vader_array_push_scalar((vader_array_t*) l1, vader_box_string(642u, l2));
	} else if (l0.tag == 1534u) {
		t1 = l0.payload.obj;
		l3 = ((vader_struct_vader_core_wit$WitFlags_t*) t1)->f_owner;
		t1 = l0.payload.obj;
		l2 = ((vader_struct_vader_core_wit$WitFlags_t*) t1)->f_name;
		l2 = vader_core_wit$struct_tag(l3, l2);
		vader_array_push_scalar((vader_array_t*) l1, vader_box_string(642u, l2));
	} else if (l0.tag == 1559u) {
		t1 = l0.payload.obj;
		l3 = ((vader_struct_vader_core_wit$WitResource_t*) t1)->f_owner;
		t1 = l0.payload.obj;
		l2 = ((vader_struct_vader_core_wit$WitResource_t*) t1)->f_name;
		l2 = vader_core_wit$struct_tag(l3, l2);
		vader_array_push_scalar((vader_array_t*) l1, vader_box_string(642u, l2));
	} else if (l0.tag == 1526u) {
		t1 = l0.payload.obj;
		vader_core_wit$push_tags(((vader_struct_vader_core_wit$WitAlias_t*) t1)->f_target, l1);
	} else if (l0.tag == 1541u) {
		t1 = l0.payload.obj;
		vader_core_wit$push_tags(((vader_struct_vader_core_wit$WitHandle_t*) t1)->f_resource, l1);
	} else if (l0.tag == 1544u) {
		t1 = l0.payload.obj;
		t3 = vader_core_wit$tag_text(((vader_struct_vader_core_wit$WitList_t*) t1)->f_element);
		l2 = concat_2(t3, 1231u);
		vader_array_push_scalar((vader_array_t*) l1, vader_box_string(642u, l2));
	} else if (l0.tag == 1549u) {
		t1 = l0.payload.obj;
		vader_core_wit$push_tags(((vader_struct_vader_core_wit$WitOption_t*) t1)->f_value, l1);
		vader_array_push_scalar((vader_array_t*) l1, vader_box_string(642u, 3025u));
	} else if (l0.tag == 1567u) {
		t1 = l0.payload.obj;
		l3 = ((vader_struct_vader_core_wit$WitTuple_t*) t1)->f_elements;
		t2 = vader_array_length(((vader_array_t*) l3));
		vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t2, 0u, 642u);
		l6 = (void*) _a0_arr;
		l4 = vader_array_length(((vader_array_t*) l3));
		l5 = INT64_C(0);
		while ((l5 < l4)) {
			vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
			VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
			t4 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l5];
			l2 = vader_core_wit$tag_text(t4);
			vader_array_push_scalar((vader_array_t*) l6, vader_box_string(642u, l2));
			l5 = (l5 + INT64_C(1));
		}
		l2 = std_string$join(l6, 443u);
		l2 = concat_3(1228u, l2, 1245u);
		vader_array_push_scalar((vader_array_t*) l1, vader_box_string(642u, l2));
	} else if (l0.tag == 1561u) {
		t1 = l0.payload.obj;
		l7 = ((vader_struct_vader_core_wit$WitResult_t*) t1)->f_ok;
		if (l7.tag == 0u) {
			vader_array_push_scalar((vader_array_t*) l1, vader_box_string(642u, 3736u));
		} else {
			vader_core_wit$push_tags(l7, l1);
		}
		t1 = l0.payload.obj;
		l7 = ((vader_struct_vader_core_wit$WitResult_t*) t1)->f_error;
		if (!(l7.tag == 0u)) {
			vader_core_wit$push_tags(l7, l1);
		}
	} else if (l0.tag == 1565u) {
		t1 = l0.payload.obj;
		l2 = vader_core_wit$tag_text(((vader_struct_vader_core_wit$WitStream_t*) t1)->f_element);
		l2 = concat_3(3272u, l2, 634u);
		vader_array_push_scalar((vader_array_t*) l1, vader_box_string(642u, l2));
	} else if (l0.tag == 1538u) {
		t1 = l0.payload.obj;
		l2 = vader_core_wit$optional_tag_text(((vader_struct_vader_core_wit$WitFuture_t*) t1)->f_value);
		l2 = concat_3(2607u, l2, 634u);
		vader_array_push_scalar((vader_array_t*) l1, vader_box_string(642u, l2));
	} else {
		if (!(l0.tag == 1570u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		t1 = l0.payload.obj;
		l2 = ((vader_struct_vader_core_wit$WitUnsupported_t*) t1)->f_reason;
		vader_array_push_scalar((vader_array_t*) l1, vader_box_string(642u, l2));
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
		l4 = std_core$write_string_at(l3, l4, 3462u);
		t0 = vader_array_length(((vader_array_t*) l2));
		l5 = vader_core_wit$enum_case_bits(t0);
		l4 = std_core$write_int(l3, l4, l5);
		l6 = std_core$finish_buffer(l3, l4);
		vader_array_push_scalar((vader_array_t*) l1, vader_box_string(642u, l6));
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
		l9 = concat_3(l6, 478u, l8);
		l10 = vader_core_wit$struct_tag(l7, l9);
		vader_array_push_scalar((vader_array_t*) l1, vader_box_string(642u, l10));
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l2 = (void*) _a0_arr;
	vader_struct_vader_core_wit$WitParser_t* _a1_obj = (vader_struct_vader_core_wit$WitParser_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitParser_t));
	vader_obj_header_init(_a1_obj, 1556u);
	_a1_obj->f_text = l0;
	_a1_obj->f_file = l1;
	_a1_obj->f_at = INT64_C(0);
	_a1_obj->f_line = INT32_C(1);
	_a1_obj->f_column = INT32_C(1);
	_a1_obj->f_doc = l2;
	l2 = (void*) _a1_obj;
	vader_array_t* _a2_arr = vader_array_new(248u, 0u, 13u, 1543u);
	l3 = (void*) _a2_arr;
	vader_struct_vader_core_wit$WitDocument_t* _a3_obj = (vader_struct_vader_core_wit$WitDocument_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitDocument_t));
	vader_obj_header_init(_a3_obj, 1530u);
	_a3_obj->f_file = l1;
	_a3_obj->f_package = vader_box_obj(0u, NULL);
	_a3_obj->f_interfaces = l3;
	l3 = (void*) _a3_obj;
	vader_core_wit$skip_space(l2);
	t0 = vader_core_wit$at_keyword(l2, 3070u);
	if (t0) {
		l5 = vader_core_wit$package_decl(l2);
		l6 = l5;
		if (l5.tag == 1533u) {
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
			if (l5.tag == 1533u) {
				t1 = l6.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l4 = l5.payload.obj;
			l8 = vader_core_wit$span(l2);
			l9 = vader_core_wit$word(l2);
			if (l9 == 2761u) {
				l11 = vader_core_wit$interface_body(l2, l7, l4, l8);
				l12 = l11;
				if (l11.tag == 1533u) {
					t1 = l12.payload.obj;
					{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
				}
				l10 = l11.payload.obj;
				vader_array_push_ref((vader_array_t*) ((vader_struct_vader_core_wit$WitDocument_t*) l3)->f_interfaces, l10);
				continue;
			}
			if (l9 == 3780u) {
				l13 = vader_core_wit$identifier(l2);
				l14 = l13;
				if (l13.tag == 1533u) {
					t1 = l14.payload.obj;
					{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
				}
				l15 = vader_core_wit$skip_braces(l2);
				l16 = l15;
				if (l15.tag == 1533u) {
					t1 = l16.payload.obj;
					{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
				}
			} else {
				if (!(l9 == 3542u)) {
					t1 = vader_core_wit$wit_error(l8, 2456u);
					{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
				}
				l17 = vader_core_wit$skip_past(l2, (uint8_t) 59);
				l18 = l17;
				if (l17.tag == 1533u) {
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
	vader_array_t* _a0_arr = vader_array_new(245u, 0u, 13u, 1530u);
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
		if (l10.tag == 1533u) {
			t0 = l11.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l7 = l10.payload.obj;
		vader_array_push_ref((vader_array_t*) l2, l7);
		l5 = (l5 + INT64_C(1));
	}
	l10 = vader_core_wit$package_of(l2, l0);
	l11 = l10;
	if (l10.tag == 1533u) {
		t0 = l11.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = l10.payload.obj;
	l8 = vader_core_wit$wit_package_text(l3);
	vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 642u);
	l6 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(35u, 0u, 0u, 653u);
	l7 = (void*) _a3_arr;
	vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 645u);
	l12 = (void*) _a4_arr;
	vader_struct_std_collections$Map__string__Any_t* _a5_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a5_obj, 1004u);
	_a5_obj->f_ekeys = l6;
	_a5_obj->f_evals = l7;
	_a5_obj->f_index = l12;
	_a5_obj->f_mask = INT64_C(0);
	_a5_obj->f_grow_at = INT64_C(0);
	_a5_obj->f_size = INT64_C(0);
	_a5_obj->f_tombs = INT64_C(0);
	l6 = (void*) _a5_obj;
	vader_array_t* _a6_arr = vader_array_new(243u, 0u, 13u, 1521u);
	l7 = (void*) _a6_arr;
	vader_array_t* _a7_arr = vader_array_new(28u, 0u, 0u, 642u);
	l12 = (void*) _a7_arr;
	vader_array_t* _a8_arr = vader_array_new(35u, 0u, 0u, 653u);
	l13 = (void*) _a8_arr;
	vader_array_t* _a9_arr = vader_array_new(29u, 0u, 7u, 645u);
	l14 = (void*) _a9_arr;
	vader_struct_std_collections$Map__string__Any_t* _a10_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a10_obj, 1004u);
	_a10_obj->f_ekeys = l12;
	_a10_obj->f_evals = l13;
	_a10_obj->f_index = l14;
	_a10_obj->f_mask = INT64_C(0);
	_a10_obj->f_grow_at = INT64_C(0);
	_a10_obj->f_size = INT64_C(0);
	_a10_obj->f_tombs = INT64_C(0);
	l12 = (void*) _a10_obj;
	vader_struct_vader_core_wit$Resolution_t* _a11_obj = (vader_struct_vader_core_wit$Resolution_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$Resolution_t));
	vader_obj_header_init(_a11_obj, 1523u);
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
			t1 = __lambda_vader_core_wit_9(l12);
			if (t1) {
				l13 = l12;
				l14 = ((vader_struct_vader_core_wit$Resolution_t*) l6)->f_interfaces;
				l8 = ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) l13)->f_name;
				t2 = std_collections$Map$std_core$Index$at__string__Any(l14, l8);
				if (!(t2.tag == 0u)) {
					l17 = ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) l13)->f_span;
					l9 = ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) l13)->f_name;
					l18 = concat_3(2762u, l9, 1473u);
					t0 = vader_core_wit$wit_error(l17, l18);
					{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
				}
				l20 = ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) l13)->f_name;
				vader_struct_vader_core_wit$WitOwner_t* _a14_obj = (vader_struct_vader_core_wit$WitOwner_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitOwner_t));
				vader_obj_header_init(_a14_obj, 1551u);
				_a14_obj->f_package = l3;
				_a14_obj->f_interface = l20;
				l21 = (void*) _a14_obj;
				l10 = vader_core_wit$open_scope(l13, l21);
				l11 = l10;
				if (l10.tag == 1533u) {
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
	vader_array_t* _a15_arr = vader_array_new(247u, 0u, 13u, 1542u);
	l2 = (void*) _a15_arr;
	vader_struct_vader_core_wit$WitPackage_t* _a16_obj = (vader_struct_vader_core_wit$WitPackage_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitPackage_t));
	vader_obj_header_init(_a16_obj, 1552u);
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
		if (l10.tag == 1533u) {
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
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
		if (l10.tag == 1522u) {
			t0 = l11.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l8 = l10.payload.s;
		t1 = ((vader_struct_vader_core_wit$WitParam_t*) l7)->f_name;
		l12 = vader_core_wit$snake_name(t1);
		l13 = concat_5(21u, l12, 567u, l8, 2u);
		vader_array_push_scalar((vader_array_t*) l3, vader_box_string(642u, l13));
		l6 = (l6 + INT64_C(1));
	}
	l8 = std_string$join(l3, 0u);
	t1 = concat_5(2480u, l1, 97u, l8, 3827u);
	{ vader_box_t __vret = vader_box_string(642u, t1); vader_gc_top = gc_frame.prev; return __vret; }
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
	if (vader_box_eq(t0, vader_box_bool(640u, true))) {
		l5 = concat_3(3433u, l2, 1589u);
		t1 = vader_core_wit$wit_error(l3, l5);
		{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	std_collections$Map$std_core$IndexSet$set_at__string__bool(((vader_struct_vader_core_wit$InterfaceScope_t*) l1)->f_pending, l2, true);
	l6 = vader_core_wit$named_type(l0, l1, l2, l3);
	l7 = l6;
	if (l6.tag == 1533u) {
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
	if (l3.tag == 1533u) {
		t0 = l4.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l3.tag == 1547u)) {
		l5 = concat_3(1318u, l2, 1608u);
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
	vader_array_t* _a0_arr = vader_array_new(246u, 0u, 13u, 1537u);
	t0 = (void*) _a0_arr;
	vader_struct_vader_core_wit$WitResourceDef_t* _a1_obj = (vader_struct_vader_core_wit$WitResourceDef_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitResourceDef_t));
	vader_obj_header_init(_a1_obj, 1560u);
	_a1_obj->f_methods = t0;
	l1 = (void*) _a1_obj;
	t1 = vader_core_wit$skip(l0, (uint8_t) 59);
	if (t1) {
		{ vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = vader_core_wit$expect(l0, (uint8_t) 123);
	l3 = l2;
	if (l2.tag == 1533u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	for (;;) {
		t1 = vader_core_wit$skip(l0, (uint8_t) 125);
		if (!(t1)) {
			l4 = vader_core_wit$take_doc(l0);
			l2 = vader_core_wit$gate(l0);
			l3 = l2;
			if (l2.tag == 1533u) {
				t0 = l3.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l5 = l2.payload.obj;
			l6 = vader_core_wit$span(l0);
			t1 = vader_core_wit$at_keyword(l0, 2308u);
			if (t1) {
				vader_core_wit$word(l0);
				l8 = vader_core_wit$params(l0);
				l9 = l8;
				if (l8.tag == 1533u) {
					t0 = l9.payload.obj;
					{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
				}
				l7 = l8.payload.obj;
				l10 = vader_core_wit$expect(l0, (uint8_t) 59);
				l11 = l10;
				if (l10.tag == 1533u) {
					t0 = l11.payload.obj;
					{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
				}
				vader_struct_vader_core_wit$WitFunctionDecl_t* _a2_obj = (vader_struct_vader_core_wit$WitFunctionDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitFunctionDecl_t));
				vader_obj_header_init(_a2_obj, 1537u);
				_a2_obj->f_name = 2308u;
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
			if (l14.tag == 1533u) {
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

static vader_string_t vader_core_wit$resource_drop_name(void* l0) {
	vader_string_t l1 = 0;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l0 };
	vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l1 = ((vader_struct_vader_core_wit$WitResource_t*) l0)->f_name;
	t0 = concat_2(1234u, l1);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
		vader_array_t* _a0_arr = vader_array_new(246u, 0u, 13u, 1537u);
		t0 = (void*) _a0_arr;
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = l3.payload.obj;
	l3 = ((vader_struct_vader_core_wit$WitTypeDecl_t*) l2)->f_definition;
	if (!(l3.tag == 1560u)) {
		vader_array_t* _a1_arr = vader_array_new(246u, 0u, 13u, 1537u);
		t0 = (void*) _a1_arr;
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l3.payload.obj;
	l2 = ((vader_struct_vader_core_wit$WitResourceDef_t*) t0)->f_methods;
	vader_array_t* _a2_arr = vader_array_new(246u, 0u, 13u, 1537u);
	l4 = (void*) _a2_arr;
	l5 = vader_array_length(((vader_array_t*) l2));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
		l7 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l6);
		t1 = __lambda_vader_core_wit_17(l7);
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
	vader_obj_header_init(_a0_obj, 1562u);
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
		if (l2.tag == 1533u) {
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
		if (l3.tag == 1533u) {
			t2 = l4.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l2 = l3;
		((vader_struct_vader_core_wit$WitResultExpr_t*) l1)->f_error = l2;
		VADER_WRITE_BARRIER((vader_struct_vader_core_wit$WitResultExpr_t*) l1);
	}
	l2 = vader_core_wit$expect(l0, (uint8_t) 62);
	l3 = l2;
	if (!(l2.tag == 1533u)) {
		{ vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t2 = l3.payload.obj;
	{ vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$result_text(void* l0, void* l1) {
	vader_box_t l2 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null();
	vader_string_t l3 = 0;
	vader_string_t l6 = 0;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	bool t2;
	vader_box_t* gc_roots[3] = { &l2, &l4, &l5 };
	void** gc_raw_roots[3] = { &l0, &l1, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l3, &l6, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_core_wit$WitResult_t*) l1)->f_error;
	if (l2.tag == 0u) {
		t0 = vader_core_wit$no_form(vader_ref_box(l1), 1822u);
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = vader_core_wit$type_text(l0, l2);
	l5 = l4;
	if (l4.tag == 1522u) {
		t0 = l5.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = l4.payload.s;
	l5 = ((vader_struct_vader_core_wit$WitResult_t*) l1)->f_ok;
	if (l5.tag == 0u) {
		l6 = vader_core_wit$grouped(l3);
		t1 = concat_2(3737u, l6);
		{ vader_box_t __vret = vader_box_string(642u, t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = l5;
	t2 = vader_core_wit$shares_tag(l4, l2);
	if (t2) {
		t0 = vader_core_wit$no_form(vader_ref_box(l1), 1943u);
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = vader_core_wit$type_text(l0, l4);
	l4 = l2;
	if (l2.tag == 1522u) {
		t0 = l4.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = l2.payload.s;
	l6 = vader_core_wit$grouped(t1);
	l3 = vader_core_wit$grouped(l3);
	t1 = concat_3(l6, 307u, l3);
	{ vader_box_t __vret = vader_box_string(642u, t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$returned(void* l0, void* l1) {
	vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
	void* l3 = NULL;
	bool l5;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[3] = { &l2, &l4, &t1 };
	void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
	vader_string_t* gc_atom_roots[1] = { &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_core_wit$WitFunction_t*) ((vader_struct_vader_core_wit$WitNamedFunction_t*) l1)->f_type)->f_result;
	if (l2.tag == 0u) {
		vader_struct_vader_core_wit$Returned_t* _a0_obj = (vader_struct_vader_core_wit$Returned_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$Returned_t));
		vader_obj_header_init(_a0_obj, 1524u);
		_a0_obj->f_text = 3736u;
		_a0_obj->f_wrapper = 0u;
		t0 = (void*) _a0_obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l2.tag == 1561u) {
		l3 = l2.payload.obj;
		t1 = vader_core_wit$returned_result(l0, l1, l3);
		{ vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l2.tag == 1549u) {
		t0 = l2.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitOption_t*) t0)->f_value;
		t0 = l2.payload.obj;
		l5 = vader_core_wit$wraps_returned_value(vader_ref_box(t0));
		t1 = vader_core_wit$returned_union(l0, l1, l4, 3025u, l5);
		{ vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = vader_core_wit$returned_text(l0, l2);
	l4 = l2;
	if (l2.tag == 1522u) {
		t0 = l4.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t2 = l2.payload.s;
	vader_struct_vader_core_wit$Returned_t* _a1_obj = (vader_struct_vader_core_wit$Returned_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$Returned_t));
	vader_obj_header_init(_a1_obj, 1524u);
	_a1_obj->f_text = t2;
	_a1_obj->f_wrapper = 0u;
	t0 = (void*) _a1_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$returned_result(void* l0, void* l1, void* l2) {
	vader_box_t l3 = vader_box_null(), l5 = vader_box_null();
	vader_string_t l4 = 0;
	vader_string_t l6 = 0;
	bool l7;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[3] = { &l3, &l5, &t2 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l4, &l6, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_vader_core_wit$WitResult_t*) l2)->f_error;
	if (l3.tag == 0u) {
		t0 = vader_core_wit$no_form(vader_ref_box(l2), 1822u);
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = vader_core_wit$type_text(l0, l3);
	l5 = l3;
	if (l3.tag == 1522u) {
		t0 = l5.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = l3.payload.s;
	l5 = ((vader_struct_vader_core_wit$WitResult_t*) l2)->f_ok;
	if (l5.tag == 0u) {
		l6 = vader_core_wit$grouped(l4);
		t1 = concat_2(3737u, l6);
		vader_struct_vader_core_wit$Returned_t* _a0_obj = (vader_struct_vader_core_wit$Returned_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$Returned_t));
		vader_obj_header_init(_a0_obj, 1524u);
		_a0_obj->f_text = t1;
		_a0_obj->f_wrapper = 0u;
		t0 = (void*) _a0_obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = l5;
	l4 = vader_core_wit$grouped(l4);
	l7 = vader_core_wit$wraps_returned_value(vader_ref_box(l2));
	t2 = vader_core_wit$returned_union(l0, l1, l3, l4, l7);
	{ vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$returned_text(void* l0, vader_box_t l1) {
	vader_string_t l2 = 0;
	vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l9 = vader_box_null();
	void* l5 = NULL;
	void* l6 = NULL;
	int64_t l7, l8;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[5] = { &l1, &l3, &l4, &l9, &t2 };
	void** gc_raw_roots[4] = { &l0, &l5, &l6, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l2, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 5u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l1.tag == 1565u) {
		t0 = l1.payload.obj;
		l3 = ((vader_struct_vader_core_wit$WitStream_t*) t0)->f_element;
		l3 = vader_core_wit$type_text(l0, l3);
		l4 = l3;
		if (l3.tag == 1522u) {
			t0 = l4.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l2 = l3.payload.s;
		t1 = concat_3(1223u, l2, 634u);
		{ vader_box_t __vret = vader_box_string(642u, t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l1.tag == 1538u) {
		l5 = l1.payload.obj;
		l3 = vader_core_wit$future_value_text(l0, l5);
		l4 = l3;
		if (l3.tag == 1522u) {
			t0 = l4.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l2 = l3.payload.s;
		t1 = concat_3(1221u, l2, 634u);
		{ vader_box_t __vret = vader_box_string(642u, t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l1.tag == 1567u)) {
		l9 = l1;
		t2 = vader_core_wit$type_text(l0, l9);
		{ vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l5 = (void*) _a0_arr;
	t0 = l1.payload.obj;
	l6 = ((vader_struct_vader_core_wit$WitTuple_t*) t0)->f_elements;
	l7 = vader_array_length(((vader_array_t*) l6));
	l8 = INT64_C(0);
	while ((l8 < l7)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l3 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l8];
		l4 = vader_core_wit$returned_text(l0, l3);
		l9 = l4;
		if (l4.tag == 1522u) {
			t0 = l9.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l2 = l4.payload.s;
		vader_array_push_scalar((vader_array_t*) l5, vader_box_string(642u, l2));
		l8 = (l8 + INT64_C(1));
	}
	l2 = std_string$join(l5, 443u);
	t1 = concat_3(1228u, l2, 1245u);
	{ vader_box_t __vret = vader_box_string(642u, t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_core_wit$returned_union(void* l0, void* l1, vader_box_t l2, vader_string_t l3, bool l4) {
	vader_string_t l5 = 0;
	vader_string_t l8 = 0;
	vader_string_t l9 = 0;
	vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[3] = { &l2, &l6, &l7 };
	void** gc_raw_roots[3] = { &l0, &l1, &t0 };
	vader_string_t* gc_atom_roots[6] = { &l3, &l5, &l8, &l9, &t1, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l6 = vader_core_wit$type_text(l0, l2);
	l7 = l6;
	if (l6.tag == 1522u) {
		t0 = l7.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = l6.payload.s;
	if (!(l4)) {
		t1 = vader_core_wit$grouped(l5);
		t2 = concat_3(t1, 307u, l3);
		vader_struct_vader_core_wit$Returned_t* _a0_obj = (vader_struct_vader_core_wit$Returned_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$Returned_t));
		vader_obj_header_init(_a0_obj, 1524u);
		_a0_obj->f_text = t2;
		_a0_obj->f_wrapper = 0u;
		t0 = (void*) _a0_obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = vader_core_wit$function_words(l1);
	t2 = vader_core_wit$pascal_name(t1);
	l8 = concat_2(t2, 903u);
	l9 = concat_3(l8, 307u, l3);
	l5 = concat_5(2480u, l8, 99u, l5, 17u);
	vader_struct_vader_core_wit$Returned_t* _a1_obj = (vader_struct_vader_core_wit$Returned_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$Returned_t));
	vader_obj_header_init(_a1_obj, 1524u);
	_a1_obj->f_text = l9;
	_a1_obj->f_wrapper = l5;
	t0 = (void*) _a1_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$scalar_text(uint8_t l0) {
	vader_string_t l1;
	if (l0 == INT32_C(0)) {
		l1 = 2107u;
		return l1;
	}
	if (l0 == INT32_C(1)) {
		l1 = 2699u;
	} else if (l0 == INT32_C(2)) {
		l1 = 3487u;
	} else if (l0 == INT32_C(3)) {
		l1 = 2654u;
	} else if (l0 == INT32_C(4)) {
		l1 = 3466u;
	} else if (l0 == INT32_C(5)) {
		l1 = 2655u;
	} else if (l0 == INT32_C(6)) {
		l1 = 3467u;
	} else if (l0 == INT32_C(7)) {
		l1 = 2677u;
	} else if (l0 == INT32_C(8)) {
		l1 = 3477u;
	} else if (l0 == INT32_C(9)) {
		l1 = 2501u;
	} else if (l0 == INT32_C(10)) {
		l1 = 2503u;
	} else if (l0 == INT32_C(11)) {
		l1 = 2247u;
	} else {
		if (!(l0 == INT32_C(12))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = 3273u;
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
	if (l1.tag == 1533u) {
		t0 = l2.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = INT32_C(1);
	while ((l3 > INT32_C(0))) {
		t1 = vader_core_wit$at_end(l0);
		if (t1) {
			t0 = vader_core_wit$fail_here(l0, 2460u);
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
	{ vader_box_t __vret = vader_box_obj(643u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
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
	void** gc_raw_roots[2] = { &l0, &l7 };
	vader_string_t* gc_atom_roots[3] = { &l4, &l6, &l9 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
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
				l6 = vader_string_byte_slice(l4, l3, l5);
				t0 = std_string$starts_with(l6, 545u);
				if (t0) {
					l7 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_doc;
					l8 = (int64_t) vader_string_byte_len(l6);
					l9 = std_string$trim(vader_string_byte_slice(l6, INT64_C(3), l8));
					vader_array_push_scalar((vader_array_t*) l7, vader_box_string(642u, l9));
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

static vader_string_t vader_core_wit$snake_name(vader_string_t l0) {
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
	l1 = std_string$replace_all(t0, 478u, 1253u);
	t1 = (void*) &vader_data_60;
	t2 = std_core$$array$Contains$contains__string(t1, l1);
	if (!(t2)) {
		{ vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = concat_2(l1, 1253u);
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
	vader_obj_header_init(_a0_obj, 1564u);
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
	if (l2.tag == 1533u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_struct_vader_core_wit$WitStreamExpr_t* _a0_obj = (vader_struct_vader_core_wit$WitStreamExpr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitStreamExpr_t));
	vader_obj_header_init(_a0_obj, 1566u);
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
	t1 = std_string$join(t0, 307u);
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
	vader_struct___lambda_env_vader_core_wit_5_t* _a0_obj = (vader_struct___lambda_env_vader_core_wit_5_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_core_wit_5_t));
	vader_obj_header_init(_a0_obj, 701u);
	_a0_obj->f_cap_0 = l1;
	l3 = (void*) _a0_obj;
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l5];
		l6 = t0.payload.s;
		t1 = __lambda_vader_core_wit_4(l3, l6);
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
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
	l1 = std_string$join(((vader_struct_vader_core_wit$WitParser_t*) l0)->f_doc, 2u);
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
		vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_core_wit$InterfaceScope_t*) l0)->f_names, vader_box_string(642u, l1));
		{ vader_box_t __vret = vader_box_obj(643u, NULL); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = ((vader_struct_vader_core_wit$WitInterfaceDecl_t*) ((vader_struct_vader_core_wit$InterfaceScope_t*) l0)->f_decl)->f_name;
	l4 = concat_5(3433u, l1, 1474u, l4, 1318u);
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
	if (l1.tag == 1533u) {
		t0 = l2.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a0_arr = vader_array_new(500u, 0u, 0u, 2831u);
	l3 = (void*) _a0_arr;
	for (;;) {
		t1 = vader_core_wit$skip(l0, (uint8_t) 62);
		if (!(t1)) {
			l2 = vader_core_wit$type_expr(l0);
			l4 = l2;
			if (l2.tag == 1533u) {
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
			if (!(l5.tag == 1533u)) {
				break;
			}
			t0 = l6.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		break;
	}
	vader_struct_vader_core_wit$WitTupleExpr_t* _a1_obj = (vader_struct_vader_core_wit$WitTupleExpr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitTupleExpr_t));
	vader_obj_header_init(_a1_obj, 1568u);
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
	if (l6.tag == 1533u) {
		t0 = l7.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = l6.payload.s;
	l7 = vader_core_wit$definition(l0, l4);
	l8 = l7;
	if (l7.tag == 1533u) {
		t0 = l8.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l6 = l7;
	vader_struct_vader_core_wit$WitTypeDecl_t* _a0_obj = (vader_struct_vader_core_wit$WitTypeDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitTypeDecl_t));
	vader_obj_header_init(_a0_obj, 1569u);
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
	l2 = concat_5(1318u, l2, 1442u, l3, 1703u);
	l3 = vader_core_wit$NoForm$std_core$Error$message(l1);
	l2 = concat_2(l2, l3);
	t0 = vader_core_wit$wit_owner_text(((vader_struct_vader_core_wit$Generation_t*) l0)->f_owner);
	vader_struct_vader_core_wit$WitSpan_t* _a0_obj = (vader_struct_vader_core_wit$WitSpan_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitSpan_t));
	vader_obj_header_init(_a0_obj, 1564u);
	_a0_obj->f_file = t0;
	_a0_obj->f_line = INT32_C(1);
	_a0_obj->f_column = INT32_C(1);
	l4 = (void*) _a0_obj;
	vader_struct_vader_core_wit$WitError_t* _a1_obj = (vader_struct_vader_core_wit$WitError_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitError_t));
	vader_obj_header_init(_a1_obj, 1533u);
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
	t0 = std_string$starts_with(l2, 356u);
	if (t0) {
		t1 = vader_core_wit$named_expr(l0, l1);
		{ vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = vader_core_wit$wit_scalar_named(l2);
	if (!(l3.tag == 0u)) {
		vader_core_wit$word(l0);
		t2 = ((uint8_t) l3.payload.i);
		{ vader_box_t __vret = vader_box_i32(647u, (int32_t)(uint32_t) t2); vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l2 == 2850u) {
		l3 = vader_core_wit$list_expr(l0);
		{ vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l2 == 3057u) {
		l3 = vader_core_wit$option_expr(l0);
	} else if (l2 == 3153u) {
		l3 = vader_core_wit$result_expr(l0);
	} else if (l2 == 3422u) {
		l3 = vader_core_wit$tuple_expr(l0);
	} else if (l2 == 2606u) {
		l3 = vader_core_wit$future_expr(l0);
	} else if (l2 == 3271u) {
		l3 = vader_core_wit$stream_expr(l0, l1);
	} else if (l2 == 2114u) {
		l3 = vader_core_wit$borrow_expr(l0, l1);
	} else if (l2 == 3067u) {
		l3 = vader_core_wit$own_expr(l0, l1);
	} else if (l2 == 2900u) {
		t3 = vader_core_wit$wit_error(l1, 1779u);
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
	if (l2.tag == 647u) {
		t0 = ((uint8_t) l2.payload.i);
		l3 = vader_box_i32(647u, (int32_t)(uint32_t) t0);
		{ vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l2.tag == 1547u) {
		t1 = l2.payload.obj;
		l5 = ((vader_struct_vader_core_wit$WitNameExpr_t*) t1)->f_name;
		t1 = l2.payload.obj;
		l6 = ((vader_struct_vader_core_wit$WitNameExpr_t*) t1)->f_span;
		l4 = vader_core_wit$resolve_name(l0, l1, l5, l6);
		l7 = l4;
		if (l4.tag == 1533u) {
			t1 = l7.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
		}
		t2 = vader_core_wit$is_resource(l4);
		if (t2) {
			vader_struct_vader_core_wit$WitHandle_t* _a0_obj = (vader_struct_vader_core_wit$WitHandle_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitHandle_t));
			vader_obj_header_init(_a0_obj, 1541u);
			_a0_obj->f_resource = l4;
			_a0_obj->f_is_borrow = false;
			t1 = (void*) _a0_obj;
			l3 = vader_ref_box(t1);
		} else {
			l3 = l4;
		}
	} else if (l2.tag == 1528u) {
		t1 = l2.payload.obj;
		l6 = ((vader_struct_vader_core_wit$WitBorrowExpr_t*) t1)->f_resource;
		l5 = ((vader_struct_vader_core_wit$WitNameExpr_t*) l6)->f_name;
		l8 = ((vader_struct_vader_core_wit$WitNameExpr_t*) l6)->f_span;
		l7 = vader_core_wit$resolve_name(l0, l1, l5, l8);
		l9 = l7;
		if (l7.tag == 1533u) {
			t1 = l9.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l4 = l7;
		t2 = vader_core_wit$is_resource(l4);
		if (!(t2)) {
			l8 = ((vader_struct_vader_core_wit$WitNameExpr_t*) l6)->f_span;
			l5 = ((vader_struct_vader_core_wit$WitNameExpr_t*) l6)->f_name;
			l5 = concat_3(1762u, l5, 1504u);
			t1 = vader_core_wit$wit_error(l8, l5);
			{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
		}
		vader_struct_vader_core_wit$WitHandle_t* _a1_obj = (vader_struct_vader_core_wit$WitHandle_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitHandle_t));
		vader_obj_header_init(_a1_obj, 1541u);
		_a1_obj->f_resource = l4;
		_a1_obj->f_is_borrow = true;
		t1 = (void*) _a1_obj;
		l3 = vader_ref_box(t1);
	} else if (l2.tag == 1545u) {
		t1 = l2.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitListExpr_t*) t1)->f_element;
		l4 = vader_core_wit$type_of(l0, l1, l4);
		l7 = l4;
		if (l4.tag == 1533u) {
			t1 = l7.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
		}
		vader_struct_vader_core_wit$WitList_t* _a2_obj = (vader_struct_vader_core_wit$WitList_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitList_t));
		vader_obj_header_init(_a2_obj, 1544u);
		_a2_obj->f_element = l4;
		t1 = (void*) _a2_obj;
		l3 = vader_ref_box(t1);
	} else if (l2.tag == 1550u) {
		t1 = l2.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitOptionExpr_t*) t1)->f_value;
		l4 = vader_core_wit$type_of(l0, l1, l4);
		l7 = l4;
		if (l4.tag == 1533u) {
			t1 = l7.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
		}
		vader_struct_vader_core_wit$WitOption_t* _a3_obj = (vader_struct_vader_core_wit$WitOption_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitOption_t));
		vader_obj_header_init(_a3_obj, 1549u);
		_a3_obj->f_value = l4;
		t1 = (void*) _a3_obj;
		l3 = vader_ref_box(t1);
	} else if (l2.tag == 1562u) {
		t1 = l2.payload.obj;
		l7 = ((vader_struct_vader_core_wit$WitResultExpr_t*) t1)->f_ok;
		l7 = vader_core_wit$optional_type_of(l0, l1, l7);
		l9 = l7;
		if (l7.tag == 1533u) {
			t1 = l9.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l4 = l7;
		t1 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_wit$WitResultExpr_t*) t1)->f_error;
		l9 = vader_core_wit$optional_type_of(l0, l1, l9);
		l10 = l9;
		if (l9.tag == 1533u) {
			t1 = l10.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l7 = l9;
		vader_struct_vader_core_wit$WitResult_t* _a4_obj = (vader_struct_vader_core_wit$WitResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitResult_t));
		vader_obj_header_init(_a4_obj, 1561u);
		_a4_obj->f_ok = l4;
		_a4_obj->f_error = l7;
		t1 = (void*) _a4_obj;
		l3 = vader_ref_box(t1);
	} else if (l2.tag == 1568u) {
		vader_array_t* _a5_arr = vader_array_new(498u, 0u, 0u, 2825u);
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
			if (l9.tag == 1533u) {
				t1 = l10.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l7 = l9;
			vader_array_push((vader_array_t*) l6, l7);
			l12 = (l12 + INT64_C(1));
		}
		vader_struct_vader_core_wit$WitTuple_t* _a7_obj = (vader_struct_vader_core_wit$WitTuple_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitTuple_t));
		vader_obj_header_init(_a7_obj, 1567u);
		_a7_obj->f_elements = l6;
		t1 = (void*) _a7_obj;
		l3 = vader_ref_box(t1);
	} else if (l2.tag == 1539u) {
		t1 = l2.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitFutureExpr_t*) t1)->f_value;
		l4 = vader_core_wit$optional_type_of(l0, l1, l4);
		l7 = l4;
		if (l4.tag == 1533u) {
			t1 = l7.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
		}
		vader_struct_vader_core_wit$WitFuture_t* _a8_obj = (vader_struct_vader_core_wit$WitFuture_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitFuture_t));
		vader_obj_header_init(_a8_obj, 1538u);
		_a8_obj->f_value = l4;
		t1 = (void*) _a8_obj;
		l3 = vader_ref_box(t1);
	} else {
		if (!(l2.tag == 1566u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		t1 = l2.payload.obj;
		l7 = ((vader_struct_vader_core_wit$WitStreamExpr_t*) t1)->f_element;
		if (l7.tag == 0u) {
			t1 = l2.payload.obj;
			t3 = vader_core_wit$wit_error(((vader_struct_vader_core_wit$WitStreamExpr_t*) t1)->f_span, 1823u);
			{ vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l4 = l7;
		l4 = vader_core_wit$type_of(l0, l1, l4);
		l7 = l4;
		if (l4.tag == 1533u) {
			t1 = l7.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
		}
		vader_struct_vader_core_wit$WitStream_t* _a9_obj = (vader_struct_vader_core_wit$WitStream_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitStream_t));
		vader_obj_header_init(_a9_obj, 1565u);
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
	if (l1.tag == 647u) {
		t0 = ((uint8_t) l1.payload.i);
		t1 = vader_core_wit$scalar_text(t0);
		l2 = vader_box_string(642u, t1);
		{ vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l1.tag == 1557u) {
		t2 = l1.payload.obj;
		l3 = ((vader_struct_vader_core_wit$WitRecord_t*) t2)->f_owner;
		t2 = l1.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitRecord_t*) t2)->f_name;
		t1 = vader_core_wit$named_text(l0, l3, l4);
		l2 = vader_box_string(642u, t1);
	} else if (l1.tag == 1574u) {
		t2 = l1.payload.obj;
		l3 = ((vader_struct_vader_core_wit$WitVariant_t*) t2)->f_owner;
		t2 = l1.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitVariant_t*) t2)->f_name;
		t1 = vader_core_wit$named_text(l0, l3, l4);
		l2 = vader_box_string(642u, t1);
	} else if (l1.tag == 1531u) {
		l3 = l1.payload.obj;
		t1 = vader_core_wit$enum_text(l0, l3);
		l2 = vader_box_string(642u, t1);
	} else if (l1.tag == 1534u) {
		t2 = l1.payload.obj;
		l3 = ((vader_struct_vader_core_wit$WitFlags_t*) t2)->f_owner;
		t2 = l1.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitFlags_t*) t2)->f_name;
		t1 = vader_core_wit$named_text(l0, l3, l4);
		l2 = vader_box_string(642u, t1);
	} else if (l1.tag == 1559u) {
		t2 = l1.payload.obj;
		l3 = ((vader_struct_vader_core_wit$WitResource_t*) t2)->f_owner;
		t2 = l1.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitResource_t*) t2)->f_name;
		t1 = vader_core_wit$named_text(l0, l3, l4);
		l2 = vader_box_string(642u, t1);
	} else if (l1.tag == 1526u) {
		t2 = l1.payload.obj;
		l3 = ((vader_struct_vader_core_wit$WitAlias_t*) t2)->f_owner;
		t2 = l1.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitAlias_t*) t2)->f_name;
		t1 = vader_core_wit$named_text(l0, l3, l4);
		l2 = vader_box_string(642u, t1);
	} else if (l1.tag == 1541u) {
		t2 = l1.payload.obj;
		l5 = ((vader_struct_vader_core_wit$WitHandle_t*) t2)->f_resource;
		l2 = vader_core_wit$type_text(l0, l5);
	} else if (l1.tag == 1544u) {
		t2 = l1.payload.obj;
		l5 = ((vader_struct_vader_core_wit$WitList_t*) t2)->f_element;
		l5 = vader_core_wit$type_text(l0, l5);
		l6 = l5;
		if (l5.tag == 1522u) {
			t2 = l6.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
		}
		t1 = l5.payload.s;
		t3 = vader_core_wit$grouped(t1);
		t1 = concat_2(t3, 1231u);
		l2 = vader_box_string(642u, t1);
	} else if (l1.tag == 1549u) {
		t2 = l1.payload.obj;
		t4 = vader_core_wit$tags_of(((vader_struct_vader_core_wit$WitOption_t*) t2)->f_value);
		t5 = std_core$$array$Contains$contains__string(t4, 3025u);
		if (t5) {
			t2 = l1.payload.obj;
			t4 = vader_core_wit$no_form(vader_ref_box(t2), 1943u);
			{ vader_box_t __vret = vader_ref_box(t4); vader_gc_top = gc_frame.prev; return __vret; }
		}
		t2 = l1.payload.obj;
		l5 = ((vader_struct_vader_core_wit$WitOption_t*) t2)->f_value;
		l5 = vader_core_wit$type_text(l0, l5);
		l6 = l5;
		if (l5.tag == 1522u) {
			t2 = l6.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
		}
		t1 = l5.payload.s;
		t3 = vader_core_wit$grouped(t1);
		t1 = concat_2(t3, 308u);
		l2 = vader_box_string(642u, t1);
	} else if (l1.tag == 1567u) {
		vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
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
			if (l6.tag == 1522u) {
				t2 = l10.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l4 = l6.payload.s;
			vader_array_push_scalar((vader_array_t*) l3, vader_box_string(642u, l4));
			l9 = (l9 + INT64_C(1));
		}
		l4 = std_string$join(l3, 443u);
		t1 = concat_3(1228u, l4, 1245u);
		l2 = vader_box_string(642u, t1);
	} else if (l1.tag == 1561u) {
		l3 = l1.payload.obj;
		l2 = vader_core_wit$result_text(l0, l3);
	} else if ((l1.tag == 1538u || l1.tag == 1565u)) {
		t2 = vader_core_wit$no_form(l1, 1919u);
		l2 = vader_ref_box(t2);
	} else {
		if (!(l1.tag == 1570u)) {
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
	if (l4.tag == 1533u) {
		t0 = l5.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = l4.payload.obj;
	l4 = vader_core_wit$expect(l0, (uint8_t) 46);
	l5 = l4;
	if (l4.tag == 1533u) {
		t0 = l5.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = vader_core_wit$expect(l0, (uint8_t) 123);
	l5 = l4;
	if (l4.tag == 1533u) {
		t0 = l5.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a0_arr = vader_array_new(257u, 0u, 13u, 1572u);
	l6 = (void*) _a0_arr;
	for (;;) {
		t1 = vader_core_wit$skip(l0, (uint8_t) 125);
		if (!(t1)) {
			l7 = vader_core_wit$span(l0);
			l4 = vader_core_wit$identifier(l0);
			l5 = l4;
			if (l4.tag == 1533u) {
				t0 = l5.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l8 = l4.payload.s;
			l9 = l8;
			t1 = vader_core_wit$at_keyword(l0, 2070u);
			if (t1) {
				vader_core_wit$word(l0);
				l10 = vader_core_wit$identifier(l0);
				l11 = l10;
				if (l10.tag == 1533u) {
					t0 = l11.payload.obj;
					{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
				}
				l9 = l10.payload.s;
			}
			vader_struct_vader_core_wit$WitUseName_t* _a1_obj = (vader_struct_vader_core_wit$WitUseName_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitUseName_t));
			vader_obj_header_init(_a1_obj, 1572u);
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
			if (!(l13.tag == 1533u)) {
				break;
			}
			t0 = l14.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		break;
	}
	l4 = vader_core_wit$expect(l0, (uint8_t) 59);
	l5 = l4;
	if (!(l4.tag == 1533u)) {
		vader_struct_vader_core_wit$WitUseDecl_t* _a2_obj = (vader_struct_vader_core_wit$WitUseDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitUseDecl_t));
		vader_obj_header_init(_a2_obj, 1571u);
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
		if (l2.tag == 1533u) {
			t1 = l3.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l1 = l2.payload.s;
		vader_struct_vader_core_wit$WitUsePath_t* _a0_obj = (vader_struct_vader_core_wit$WitUsePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitUsePath_t));
		vader_obj_header_init(_a0_obj, 1573u);
		_a0_obj->f_package = vader_box_obj(0u, NULL);
		_a0_obj->f_interface = l1;
		t1 = (void*) _a0_obj;
		{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = vader_core_wit$namespaced_name(l0);
	l3 = l2;
	if (l2.tag == 1533u) {
		t1 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = l2.payload.obj;
	l2 = vader_core_wit$expect(l0, (uint8_t) 47);
	l3 = l2;
	if (l2.tag == 1533u) {
		t1 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = vader_core_wit$identifier(l0);
	l3 = l2;
	if (l2.tag == 1533u) {
		t1 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = l2.payload.s;
	t2 = vader_core_wit$skip(l0, (uint8_t) 64);
	if (t2) {
		l2 = vader_core_wit$version(l0);
		l3 = l2;
		if (l2.tag == 1533u) {
			t1 = l3.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l5 = l2.payload.s;
		((vader_struct_vader_core_wit$WitPackageName_t*) l4)->f_version = l5;
		vader_struct_vader_core_wit$WitUsePath_t* _a1_obj = (vader_struct_vader_core_wit$WitUsePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitUsePath_t));
		vader_obj_header_init(_a1_obj, 1573u);
		_a1_obj->f_package = vader_ref_box(l4);
		_a1_obj->f_interface = l1;
		t1 = (void*) _a1_obj;
		{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_struct_vader_core_wit$WitUsePath_t* _a2_obj = (vader_struct_vader_core_wit$WitUsePath_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitUsePath_t));
	vader_obj_header_init(_a2_obj, 1573u);
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
			l4 = concat_5(3000u, l4, 1442u, l5, 1318u);
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
	if (l7.tag == 1533u) {
		t0 = l9.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l6 = l7.payload.obj;
	l8 = ((vader_struct_vader_core_wit$WitPackage_t*) l6)->f_interfaces;
	vader_struct___lambda_env_vader_core_wit_22_t* _a0_obj = (vader_struct___lambda_env_vader_core_wit_22_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_core_wit_22_t));
	vader_obj_header_init(_a0_obj, 699u);
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
			t2 = __lambda_vader_core_wit_21(l10, l13);
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
		l4 = concat_5(3000u, l4, 1442u, l5, 1318u);
		t0 = vader_core_wit$wit_error(l8, l4);
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l6 = l7.payload.obj;
	l8 = ((vader_struct_vader_core_wit$WitInterface_t*) l6)->f_types;
	vader_struct___lambda_env_vader_core_wit_24_t* _a2_obj = (vader_struct___lambda_env_vader_core_wit_24_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_core_wit_24_t));
	vader_obj_header_init(_a2_obj, 700u);
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
			t2 = __lambda_vader_core_wit_23(l10, l9);
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
		l4 = concat_5(3006u, l4, 1442u, l5, 1318u);
		t0 = vader_core_wit$wit_error(l8, l4);
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$vader_function_name(void* l0) {
	bool l1;
	vader_string_t t0 = 0;
	vader_string_t t1 = 0;
	void** gc_raw_roots[1] = { &l0 };
	vader_string_t* gc_atom_roots[2] = { &t0, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (((vader_struct_vader_core_wit$WitNamedFunction_t*) l0)->f_kind == INT32_C(1)) {
		l1 = true;
	} else {
		l1 = ((vader_struct_vader_core_wit$WitNamedFunction_t*) l0)->f_kind == INT32_C(4);
	}
	if (!(l1)) {
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
		{ vader_box_t __vret = vader_box_string(642u, t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l6 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
	t1 = (void*) _a1_arr;
	vader_struct_std_string__builder$StringBuilder_t* _a2_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
	vader_obj_header_init(_a2_obj, 1139u);
	_a2_obj->f_parts = t1;
	l7 = (void*) _a2_obj;
	t2 = vader_array_length(((vader_array_t*) l3));
	if ((t2 > INT64_C(0))) {
		l8 = concat_2(l1, 725u);
		vader_array_push_scalar((vader_array_t*) l6, vader_box_string(642u, l8));
		t0 = concat_2(l1, 725u);
		l8 = vader_core_wit$enum_declaration(t0, l3);
		l8 = concat_2(2u, l8);
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
		if (l12.tag == 1522u) {
			t1 = l13.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l8 = l12.payload.s;
		l14 = vader_core_wit$case_struct_name(l1, l9);
		vader_array_push_scalar((vader_array_t*) l6, vader_box_string(642u, l14));
		l15 = concat_5(14u, l14, 99u, l8, 16u);
		std_string__builder$append(l7, l15);
		l5 = (l5 + INT64_C(1));
	}
	l8 = std_string$join(l6, 307u);
	l14 = std_string__builder$StringBuilder$std_core$Display$to_string(l7);
	t0 = concat_6(2480u, l1, 87u, l8, 2u, l14);
	{ vader_box_t __vret = vader_box_string(642u, t0); vader_gc_top = gc_frame.prev; return __vret; }
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	t1 = (void*) _a0_arr;
	vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
	vader_obj_header_init(_a1_obj, 1139u);
	_a1_obj->f_parts = t1;
	l5 = (void*) _a1_obj;
	t2 = vader_array_length(((vader_array_t*) l2));
	if ((t2 > INT64_C(0))) {
		t0 = concat_2(l0, 725u);
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
		l2 = vader_string_byte_slice(l2, l1, l3);
		vader_core_wit$skip_space(l0);
		{ vader_box_t __vret = vader_box_string(642u, l2); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t2 = vader_core_wit$fail_here(l0, 2466u);
	{ vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_core_wit$wit_children(vader_box_t l0) {
	void* l1 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
	int64_t l6, l7;
	void* t0 = NULL;
	int64_t t1;
	vader_box_t* gc_roots[3] = { &l0, &l2, &l3 };
	void** gc_raw_roots[4] = { &l1, &l4, &l5, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l0.tag == 1561u) {
		t0 = l0.payload.obj;
		l2 = ((vader_struct_vader_core_wit$WitResult_t*) t0)->f_ok;
		t0 = l0.payload.obj;
		l3 = ((vader_struct_vader_core_wit$WitResult_t*) t0)->f_error;
		vader_array_t* _a0_arr = vader_array_new(474u, 2u, 0u, 2284u);
		vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 1u] = l3;
		vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = l2;
		t0 = (void*) _a0_arr;
		l1 = vader_core_wit$present(t0);
		{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l0.tag == 1549u) {
		t0 = l0.payload.obj;
		vader_array_t* _a1_arr = vader_array_new(498u, 1u, 0u, 2825u);
		vader_array_box_slots(_a1_arr->buf)[vader_array_offset(_a1_arr) + 0u] = ((vader_struct_vader_core_wit$WitOption_t*) t0)->f_value;
		l1 = (void*) _a1_arr;
	} else if (l0.tag == 1544u) {
		t0 = l0.payload.obj;
		vader_array_t* _a2_arr = vader_array_new(498u, 1u, 0u, 2825u);
		vader_array_box_slots(_a2_arr->buf)[vader_array_offset(_a2_arr) + 0u] = ((vader_struct_vader_core_wit$WitList_t*) t0)->f_element;
		l1 = (void*) _a2_arr;
	} else if (l0.tag == 1565u) {
		t0 = l0.payload.obj;
		vader_array_t* _a3_arr = vader_array_new(498u, 1u, 0u, 2825u);
		vader_array_box_slots(_a3_arr->buf)[vader_array_offset(_a3_arr) + 0u] = ((vader_struct_vader_core_wit$WitStream_t*) t0)->f_element;
		l1 = (void*) _a3_arr;
	} else if (l0.tag == 1538u) {
		t0 = l0.payload.obj;
		vader_array_t* _a4_arr = vader_array_new(474u, 1u, 0u, 2284u);
		vader_array_box_slots(_a4_arr->buf)[vader_array_offset(_a4_arr) + 0u] = ((vader_struct_vader_core_wit$WitFuture_t*) t0)->f_value;
		t0 = (void*) _a4_arr;
		l1 = vader_core_wit$present(t0);
	} else if (l0.tag == 1567u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_vader_core_wit$WitTuple_t*) t0)->f_elements;
	} else if (l0.tag == 1557u) {
		t0 = l0.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitRecord_t*) t0)->f_fields;
		t1 = vader_array_length(((vader_array_t*) l4));
		vader_array_t* _a5_arr = vader_array_reserve(498u, (int64_t) t1, 0u, 2825u);
		l5 = (void*) _a5_arr;
		l6 = vader_array_length(((vader_array_t*) l4));
		l7 = INT64_C(0);
		while ((l7 < l6)) {
			vader_array_t* _a6_slotarr = ((vader_array_t*) l4);
			VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
			t0 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l7);
			l2 = __lambda_vader_core_wit_2(t0);
			vader_array_push((vader_array_t*) l5, l2);
			l7 = (l7 + INT64_C(1));
		}
		l1 = l5;
	} else if (l0.tag == 1574u) {
		t0 = l0.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitVariant_t*) t0)->f_cases;
		t1 = vader_array_length(((vader_array_t*) l4));
		vader_array_t* _a7_arr = vader_array_reserve(474u, (int64_t) t1, 0u, 2284u);
		l5 = (void*) _a7_arr;
		l6 = vader_array_length(((vader_array_t*) l4));
		l7 = INT64_C(0);
		while ((l7 < l6)) {
			vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
			VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
			t0 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l7);
			l2 = __lambda_vader_core_wit_1(t0);
			vader_array_push((vader_array_t*) l5, l2);
			l7 = (l7 + INT64_C(1));
		}
		l1 = vader_core_wit$present(l5);
	} else if (l0.tag == 1526u) {
		t0 = l0.payload.obj;
		vader_array_t* _a9_arr = vader_array_new(498u, 1u, 0u, 2825u);
		vader_array_box_slots(_a9_arr->buf)[vader_array_offset(_a9_arr) + 0u] = ((vader_struct_vader_core_wit$WitAlias_t*) t0)->f_target;
		l1 = (void*) _a9_arr;
	} else {
		if (!((l0.tag == 1531u || l0.tag == 1534u || l0.tag == 1541u || l0.tag == 1559u || l0.tag == 647u || l0.tag == 1570u))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		vader_array_t* _a10_arr = vader_array_new(498u, 0u, 0u, 2825u);
		l1 = (void*) _a10_arr;
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
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
	vader_obj_header_init(_a0_obj, 1533u);
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l3 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 642u);
	l4 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 645u);
	l5 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__string_t* _a3_obj = (vader_struct_std_collections$Map__string__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__string_t));
	vader_obj_header_init(_a3_obj, 1028u);
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
	vader_obj_header_init(_a4_obj, 1520u);
	_a4_obj->f_owner = l2;
	_a4_obj->f_imports = l3;
	_a4_obj->f_errors = l4;
	l2 = (void*) _a4_obj;
	vader_array_t* _a5_arr = vader_array_new(28u, 0u, 0u, 642u);
	t0 = (void*) _a5_arr;
	vader_struct_std_string__builder$StringBuilder_t* _a6_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
	vader_obj_header_init(_a6_obj, 1139u);
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
		if (l10.tag == 1522u) {
			l5 = l11.payload.obj;
			t0 = vader_core_wit$type_error(l2, l5);
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l9 = l10.payload.s;
		l12 = vader_core_wit$error_impl(l2, l8);
		l13 = concat_3(2u, l9, l12);
		std_string__builder$append(l3, l13);
		l7 = (l7 + INT64_C(1));
	}
	t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_wit$WitInterface_t*) l1)->f_functions));
	if ((t1 > INT64_C(0))) {
		l9 = vader_core_wit$interface_constant(((vader_struct_vader_core_wit$WitInterface_t*) l1)->f_owner);
		l9 = concat_2(2u, l9);
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
		l12 = concat_2(2u, l9);
		std_string__builder$append(l3, l12);
		l7 = (l7 + INT64_C(1));
	}
	vader_array_t* _a9_arr = vader_array_new(28u, 0u, 0u, 642u);
	t0 = (void*) _a9_arr;
	vader_struct_std_string__builder$StringBuilder_t* _a10_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
	vader_obj_header_init(_a10_obj, 1139u);
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
		l16 = concat_4(l13, 96u, l15, 318u);
		std_string__builder$append(l4, l16);
		l6 = (l6 + INT64_C(1));
	}
	l9 = std_string__builder$StringBuilder$std_core$Display$to_string(l3);
	std_string__builder$append(l4, l9);
	t3 = std_string__builder$StringBuilder$std_core$Display$to_string(l4);
	{ vader_box_t __vret = vader_box_string(642u, t3); vader_gc_top = gc_frame.prev; return __vret; }
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
	l2 = concat_5(l2, 566u, l3, 536u, l4);
	t0 = ((vader_struct_vader_core_wit$WitPackageName_t*) l1)->f_version;
	if (!(t0 == 0u)) {
		l3 = ((vader_struct_vader_core_wit$WitPackageName_t*) l1)->f_version;
		t0 = concat_3(l2, 643u, l3);
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
		t0 = concat_5(l1, 566u, l2, 643u, l3);
		{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = ((vader_struct_vader_core_wit$WitPackageName_t*) l0)->f_namespace;
	l2 = ((vader_struct_vader_core_wit$WitPackageName_t*) l0)->f_name;
	t0 = concat_3(l1, 566u, l2);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$wit_scalar_name(uint8_t l0) {
	vader_string_t l1;
	if (l0 == INT32_C(0)) {
		l1 = 2107u;
		return l1;
	}
	if (l0 == INT32_C(1)) {
		l1 = 3178u;
	} else if (l0 == INT32_C(2)) {
		l1 = 3487u;
	} else if (l0 == INT32_C(3)) {
		l1 = 3175u;
	} else if (l0 == INT32_C(4)) {
		l1 = 3466u;
	} else if (l0 == INT32_C(5)) {
		l1 = 3176u;
	} else if (l0 == INT32_C(6)) {
		l1 = 3467u;
	} else if (l0 == INT32_C(7)) {
		l1 = 3177u;
	} else if (l0 == INT32_C(8)) {
		l1 = 3477u;
	} else if (l0 == INT32_C(9)) {
		l1 = 2501u;
	} else if (l0 == INT32_C(10)) {
		l1 = 2503u;
	} else if (l0 == INT32_C(11)) {
		l1 = 2247u;
	} else {
		if (!(l0 == INT32_C(12))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = 3273u;
	}
	return l1;
}

static vader_box_t vader_core_wit$wit_scalar_named(vader_string_t l0) {
	vader_box_t l1;
	if (l0 == 2107u) {
		l1 = vader_box_i32(647u, INT32_C(0));
		return l1;
	}
	if (l0 == 3178u) {
		l1 = vader_box_i32(647u, INT32_C(1));
	} else if (l0 == 3487u) {
		l1 = vader_box_i32(647u, INT32_C(2));
	} else if (l0 == 3175u) {
		l1 = vader_box_i32(647u, INT32_C(3));
	} else if (l0 == 3466u) {
		l1 = vader_box_i32(647u, INT32_C(4));
	} else if (l0 == 3176u) {
		l1 = vader_box_i32(647u, INT32_C(5));
	} else if (l0 == 3467u) {
		l1 = vader_box_i32(647u, INT32_C(6));
	} else if (l0 == 3177u) {
		l1 = vader_box_i32(647u, INT32_C(7));
	} else if (l0 == 3477u) {
		l1 = vader_box_i32(647u, INT32_C(8));
	} else if (l0 == 2501u) {
		l1 = vader_box_i32(647u, INT32_C(9));
	} else if (l0 == 2503u) {
		l1 = vader_box_i32(647u, INT32_C(10));
	} else if (l0 == 2247u) {
		l1 = vader_box_i32(647u, INT32_C(11));
	} else if (l0 == 3273u) {
		l1 = vader_box_i32(647u, INT32_C(12));
	} else {
		l1 = vader_box_obj(0u, NULL);
	}
	return l1;
}

static vader_string_t vader_core_wit$wit_type_name(vader_box_t l0) {
	vader_string_t l1;
	void* t0;
	if (l0.tag == 1557u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_vader_core_wit$WitRecord_t*) t0)->f_name;
		return l1;
	}
	if (l0.tag == 1574u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_vader_core_wit$WitVariant_t*) t0)->f_name;
	} else if (l0.tag == 1531u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_vader_core_wit$WitEnum_t*) t0)->f_name;
	} else if (l0.tag == 1534u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_vader_core_wit$WitFlags_t*) t0)->f_name;
	} else if (l0.tag == 1559u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_vader_core_wit$WitResource_t*) t0)->f_name;
	} else {
		if (!(l0.tag == 1526u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		t0 = l0.payload.obj;
		l1 = ((vader_struct_vader_core_wit$WitAlias_t*) t0)->f_name;
	}
	return l1;
}

static vader_string_t vader_core_wit$wit_type_text(vader_box_t l0) {
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
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	t0 = (void*) _a0_arr;
	vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
	vader_obj_header_init(_a1_obj, 1139u);
	_a1_obj->f_parts = t0;
	l1 = (void*) _a1_obj;
	vader_core_wit$write_wit(l1, l0);
	t1 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_core_wit$without_aliases(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	vader_box_t l3 = vader_box_null();
	bool l4;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l3 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l1 = l0;
	l2 = vader_core_wit$alias_free_params(((vader_struct_vader_core_wit$WitFunction_t*) l0)->f_params);
	l3 = vader_core_wit$optional_alias_free(((vader_struct_vader_core_wit$WitFunction_t*) l0)->f_result);
	l4 = ((vader_struct_vader_core_wit$WitFunction_t*) l1)->f_is_async;
	vader_struct_vader_core_wit$WitFunction_t* _a0_obj = (vader_struct_vader_core_wit$WitFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitFunction_t));
	vader_obj_header_init(_a0_obj, 1536u);
	_a0_obj->f_params = l2;
	_a0_obj->f_result = l3;
	_a0_obj->f_is_async = l4;
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
	l3 = (int64_t) vader_string_byte_len(l1);
	while ((l2 < l3)) {
		vader_core_wit$advance(l0);
		l2 = (l2 + INT64_C(1));
	}
	vader_core_wit$skip_space(l0);
	{ vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_core_wit$word_at(void* l0, int64_t l1) {
	int64_t l2, l3;
	vader_string_t t0;
	bool t1;
	l2 = l1;
	t0 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_text;
	l3 = (int64_t) vader_string_byte_len(t0);
	if ((l2 < l3)) {
		t0 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_text;
		if (vader_string_byte_at(t0, (size_t) l2) == INT32_C(37)) {
			l2 = vader_chk_add(i64, l2, INT64_C(1));
		}
	}
	for (;;) {
		t0 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_text;
		l3 = (int64_t) vader_string_byte_len(t0);
		if ((l2 < l3)) {
			t0 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_text;
			t1 = vader_core_wit$is_word_byte(vader_string_byte_at(t0, (size_t) l2));
			if (!(t1)) {
				break;
			}
			l2 = vader_chk_add(i64, l2, INT64_C(1));
			continue;
		}
		break;
	}
	t0 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_text;
	return vader_string_byte_slice(t0, l1, l2);
}

static vader_string_t vader_core_wit$word_here(void* l0) {
	int64_t l1;
	vader_string_t t0;
	l1 = ((vader_struct_vader_core_wit$WitParser_t*) l0)->f_at;
	t0 = vader_core_wit$word_at(l0, l1);
	return t0;
}

bool vader_core_wit$wraps_returned_value(vader_box_t l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
	void* t0 = NULL;
	bool t1;
	vader_box_t* gc_roots[3] = { &l0, &l3, &l4 };
	void** gc_raw_roots[3] = { &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l0.tag == 1549u) {
		t0 = l0.payload.obj;
		l1 = vader_core_wit$tags_of(((vader_struct_vader_core_wit$WitOption_t*) t0)->f_value);
		vader_array_t* _a0_arr = vader_array_new(28u, 1u, 0u, 642u);
		vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(642u, 3025u);
		l2 = (void*) _a0_arr;
		t1 = vader_core_wit$tags_meet(l1, l2);
		{ bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l0.tag == 1561u)) {
		{ vader_gc_top = gc_frame.prev; return false; }
	}
	t0 = l0.payload.obj;
	l3 = ((vader_struct_vader_core_wit$WitResult_t*) t0)->f_ok;
	if (l3.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return false; }
	}
	t0 = l0.payload.obj;
	l4 = ((vader_struct_vader_core_wit$WitResult_t*) t0)->f_error;
	if (l4.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return false; }
	}
	t1 = vader_core_wit$shares_tag(l3, l4);
	{ bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
	if (l1.tag == 647u) {
		t0 = ((uint8_t) l1.payload.i);
		l2 = vader_core_wit$wit_scalar_name(t0);
		std_string__builder$append(l0, l2);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l1.tag == 1531u) {
		t1 = l1.payload.obj;
		l2 = vader_core_wit$enum_name_text(t1);
		t1 = l1.payload.obj;
		l3 = std_string$join(((vader_struct_vader_core_wit$WitEnum_t*) t1)->f_cases, 441u);
		l2 = concat_5(2429u, l2, 3816u, l3, 3826u);
		std_string__builder$append(l0, l2);
	} else if (l1.tag == 1561u) {
		std_string__builder$append(l0, 3154u);
		t1 = l1.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitResult_t*) t1)->f_ok;
		vader_core_wit$write_wit_or_none(l0, l4);
		std_string__builder$append(l0, 441u);
		t1 = l1.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitResult_t*) t1)->f_error;
		vader_core_wit$write_wit_or_none(l0, l4);
		std_string__builder$append(l0, 634u);
	} else if (l1.tag == 1544u) {
		std_string__builder$append(l0, 2851u);
		t1 = l1.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitList_t*) t1)->f_element;
		vader_core_wit$write_wit(l0, l4);
		std_string__builder$append(l0, 634u);
	} else if (l1.tag == 1565u) {
		std_string__builder$append(l0, 3272u);
		t1 = l1.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitStream_t*) t1)->f_element;
		vader_core_wit$write_wit(l0, l4);
		std_string__builder$append(l0, 634u);
	} else if (l1.tag == 1538u) {
		std_string__builder$append(l0, 2607u);
		t1 = l1.payload.obj;
		l4 = ((vader_struct_vader_core_wit$WitFuture_t*) t1)->f_value;
		vader_core_wit$write_wit_or_none(l0, l4);
		std_string__builder$append(l0, 634u);
	} else if (l1.tag == 1557u) {
		t1 = l1.payload.obj;
		l5 = ((vader_struct_vader_core_wit$WitRecord_t*) t1)->f_fields;
		t2 = vader_array_length(((vader_array_t*) l5));
		vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t2, 0u, 642u);
		l6 = (void*) _a0_arr;
		l7 = vader_array_length(((vader_array_t*) l5));
		l8 = INT64_C(0);
		while ((l8 < l7)) {
			vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
			VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
			t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l8);
			l2 = __lambda_vader_core_wit_18(t1);
			vader_array_push_scalar((vader_array_t*) l6, vader_box_string(642u, l2));
			l8 = (l8 + INT64_C(1));
		}
		l5 = l6;
		t1 = l1.payload.obj;
		l6 = ((vader_struct_vader_core_wit$WitRecord_t*) t1)->f_owner;
		t1 = l1.payload.obj;
		l2 = ((vader_struct_vader_core_wit$WitRecord_t*) t1)->f_name;
		l2 = vader_core_wit$named_text_1(l6, l2);
		l3 = std_string$join(l5, 441u);
		l2 = concat_5(3125u, l2, 3816u, l3, 3826u);
		std_string__builder$append(l0, l2);
	} else if (l1.tag == 1574u) {
		t1 = l1.payload.obj;
		l6 = ((vader_struct_vader_core_wit$WitVariant_t*) t1)->f_cases;
		t2 = vader_array_length(((vader_array_t*) l6));
		vader_array_t* _a2_arr = vader_array_reserve(28u, (int64_t) t2, 0u, 642u);
		l9 = (void*) _a2_arr;
		l7 = vader_array_length(((vader_array_t*) l6));
		l8 = INT64_C(0);
		while ((l8 < l7)) {
			vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
			VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
			t1 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l8);
			l2 = vader_core_wit$case_text(t1);
			vader_array_push_scalar((vader_array_t*) l9, vader_box_string(642u, l2));
			l8 = (l8 + INT64_C(1));
		}
		l5 = l9;
		t1 = l1.payload.obj;
		l6 = ((vader_struct_vader_core_wit$WitVariant_t*) t1)->f_owner;
		t1 = l1.payload.obj;
		l2 = ((vader_struct_vader_core_wit$WitVariant_t*) t1)->f_name;
		l2 = vader_core_wit$named_text_1(l6, l2);
		l3 = std_string$join(l5, 441u);
		l2 = concat_5(3727u, l2, 3816u, l3, 3826u);
		std_string__builder$append(l0, l2);
	} else if (l1.tag == 1534u) {
		t1 = l1.payload.obj;
		l5 = ((vader_struct_vader_core_wit$WitFlags_t*) t1)->f_owner;
		t1 = l1.payload.obj;
		l2 = ((vader_struct_vader_core_wit$WitFlags_t*) t1)->f_name;
		l2 = vader_core_wit$named_text_1(l5, l2);
		t1 = l1.payload.obj;
		l3 = std_string$join(((vader_struct_vader_core_wit$WitFlags_t*) t1)->f_flags, 441u);
		l2 = concat_5(2560u, l2, 3816u, l3, 3826u);
		std_string__builder$append(l0, l2);
	} else if (l1.tag == 1549u) {
		t1 = l1.payload.obj;
		l2 = vader_core_wit$wit_type_text(((vader_struct_vader_core_wit$WitOption_t*) t1)->f_value);
		l2 = concat_3(3058u, l2, 634u);
		std_string__builder$append(l0, l2);
	} else if (l1.tag == 1567u) {
		t1 = l1.payload.obj;
		l5 = ((vader_struct_vader_core_wit$WitTuple_t*) t1)->f_elements;
		t2 = vader_array_length(((vader_array_t*) l5));
		vader_array_t* _a4_arr = vader_array_reserve(28u, (int64_t) t2, 0u, 642u);
		l6 = (void*) _a4_arr;
		l7 = vader_array_length(((vader_array_t*) l5));
		l8 = INT64_C(0);
		while ((l8 < l7)) {
			vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
			VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
			t3 = vader_array_box_slots(_a5_slotarr->buf)[vader_array_offset(_a5_slotarr) + (size_t) l8];
			l2 = vader_core_wit$wit_type_text(t3);
			vader_array_push_scalar((vader_array_t*) l6, vader_box_string(642u, l2));
			l8 = (l8 + INT64_C(1));
		}
		l2 = std_string$join(l6, 441u);
		l2 = concat_3(3423u, l2, 634u);
		std_string__builder$append(l0, l2);
	} else if (l1.tag == 1559u) {
		t1 = l1.payload.obj;
		l5 = ((vader_struct_vader_core_wit$WitResource_t*) t1)->f_owner;
		t1 = l1.payload.obj;
		l2 = ((vader_struct_vader_core_wit$WitResource_t*) t1)->f_name;
		l2 = vader_core_wit$named_text_1(l5, l2);
		l2 = concat_2(3148u, l2);
		std_string__builder$append(l0, l2);
	} else if (l1.tag == 1541u) {
		t1 = l1.payload.obj;
		l2 = vader_core_wit$handle_keyword(t1);
		t1 = l1.payload.obj;
		l3 = vader_core_wit$wit_type_text(((vader_struct_vader_core_wit$WitHandle_t*) t1)->f_resource);
		l2 = concat_4(l2, 612u, l3, 634u);
		std_string__builder$append(l0, l2);
	} else if (l1.tag == 1526u) {
		t1 = l1.payload.obj;
		l5 = ((vader_struct_vader_core_wit$WitAlias_t*) t1)->f_owner;
		t1 = l1.payload.obj;
		l2 = ((vader_struct_vader_core_wit$WitAlias_t*) t1)->f_name;
		l2 = vader_core_wit$named_text_1(l5, l2);
		t1 = l1.payload.obj;
		l3 = vader_core_wit$wit_type_text(((vader_struct_vader_core_wit$WitAlias_t*) t1)->f_target);
		l2 = concat_4(3444u, l2, 629u, l3);
		std_string__builder$append(l0, l2);
	} else {
		if (!(l1.tag == 1570u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		std_string__builder$append(l0, 642u);
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
	std_string__builder$append(l0, 1253u);
	{ vader_gc_top = gc_frame.prev; return; }
}
