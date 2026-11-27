#include "bootstrap.split.h"

static vader_string_t __lambda_toolchain_protocol_0(void* l0, vader_string_t l1);
static bool __lambda_toolchain_protocol_2(void* l0);
static void* toolchain_protocol$past_last_field(void* l0);
static vader_box_t toolchain_protocol$read_body(void* l0);
static vader_box_t toolchain_protocol$read_configure(void* l0);
static vader_box_t toolchain_protocol$read_count(void* l0);
static vader_box_t toolchain_protocol$read_doc_query(void* l0);
static vader_box_t toolchain_protocol$read_driver_frame(void* l0, vader_string_t l1);
static vader_box_t toolchain_protocol$read_emit_module(void* l0);
static vader_box_t toolchain_protocol$read_field(void* l0);
static vader_box_t toolchain_protocol$read_generated(void* l0);
static vader_box_t toolchain_protocol$read_givens(void* l0);
static vader_box_t toolchain_protocol$read_i32(void* l0);
static vader_box_t toolchain_protocol$read_integer(void* l0);
static vader_box_t toolchain_protocol$read_place(void* l0, vader_string_t l1);
static vader_box_t toolchain_protocol$read_position(void* l0);
static vader_box_t toolchain_protocol$read_report(void* l0);
static vader_box_t toolchain_protocol$read_reports(void* l0);
static vader_box_t toolchain_protocol$read_span_1(void* l0);
static vader_box_t toolchain_protocol$read_specs(void* l0);
static vader_box_t toolchain_protocol$read_strings(void* l0);
static void toolchain_protocol$write_alias(void* l0, void* l1);
static void toolchain_protocol$write_assert(void* l0, void* l1);
static void toolchain_protocol$write_block(void* l0, void* l1);
static void toolchain_protocol$write_block_body(void* l0, void* l1);
static void toolchain_protocol$write_const(void* l0, void* l1);
static void toolchain_protocol$write_declarations(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_decorators(void* l0, void* l1);
static void toolchain_protocol$write_defer_body(void* l0, vader_box_t l1);
static void toolchain_protocol$write_doc(void* l0, vader_box_t l1);
static void toolchain_protocol$write_enum(void* l0, void* l1);
static void toolchain_protocol$write_exprs(void* l0, void* l1);
static void toolchain_protocol$write_fallback_body(void* l0, void* l1);
static void toolchain_protocol$write_fallback_result(void* l0, vader_box_t l1);
static void toolchain_protocol$write_field(void* l0, vader_string_t l1);
static void toolchain_protocol$write_flag(void* l0, bool l1);
static void toolchain_protocol$write_fn(void* l0, void* l1);
static void toolchain_protocol$write_for_form(void* l0, vader_box_t l1);
static void toolchain_protocol$write_form(void* l0, vader_string_t l1, void* l2);
static void toolchain_protocol$write_head(void* l0, void* l1, vader_string_t l2, void* l3, uint8_t l4, void* l5);
static void toolchain_protocol$write_if_body(void* l0, void* l1);
static void toolchain_protocol$write_impl(void* l0, void* l1);
static void toolchain_protocol$write_import(void* l0, void* l1);
static void toolchain_protocol$write_integer(void* l0, int64_t l1);
static void toolchain_protocol$write_list__toolchain_ast_ArrayTypeExpr___toolchain_ast_BinaryExpr___toolchain_ast_BlockExpr___toolchain_ast_BoolLitExpr___toolchain_ast_CallExpr___toolchain_ast_CastExpr___toolchain_ast_CharLitExpr___toolchain_ast_DotVariantExpr___toolchain_ast_FallbackExpr___toolchain_ast_FieldExpr___toolchain_ast_FloatLitExpr___toolchain_ast_FnTypeExpr___toolchain_ast_GenericInstExpr___toolchain_ast_IdentExpr___toolchain_ast_IfExpr___toolchain_ast_IndexExpr___toolchain_ast_IntLitExpr___toolchain_ast_IntrinsicCallExpr___toolchain_ast_LambdaExpr___toolchain_ast_MatchExpr___toolchain_ast_NullLitExpr___toolchain_ast_RangeExpr___toolchain_ast_SeqLitExpr___toolchain_ast_StringLitExpr___toolchain_ast_StructLitExpr___toolchain_ast_UnaryExpr(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_AssertDecl___toolchain_ast_ConstDecl___toolchain_ast_EnumDecl___toolchain_ast_FnDecl___toolchain_ast_ImplDecl___toolchain_ast_ImportDecl___toolchain_ast_StructDecl___toolchain_ast_TraitDecl___toolchain_ast_TypeAliasDecl(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_AssignStmt___toolchain_ast_BreakStmt___toolchain_ast_ContinueStmt___toolchain_ast_DeferStmt___toolchain_ast_DestructureAssignStmt___toolchain_ast_ExprStmt___toolchain_ast_ForStmt___toolchain_ast_LetStmt___toolchain_ast_ReturnStmt___toolchain_ast_YieldStmt(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_CallArg(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_Decorator(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_EnumVariant(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_EnumVariantPattern___toolchain_ast_IsPattern___toolchain_ast_LiteralPattern___toolchain_ast_OrPattern___toolchain_ast_RangePattern___toolchain_ast_StructPattern___toolchain_ast_WildcardPattern(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_FallbackClause(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_FnDecl(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_FnParam(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_ImportName(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_MatchArm(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_PlaceTarget___toolchain_ast_RestTarget___toolchain_ast_WildcardTarget(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_RestBinding___toolchain_ast_SimpleBinding___toolchain_ast_TupleBinding___toolchain_ast_WildcardBinding(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_StringLitInterpolation___toolchain_ast_StringLitText(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_StructField(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_StructLitField___toolchain_ast_StructLitSpread(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_StructPatternField(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_StructSpread(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_list__toolchain_ast_TypeParam(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_loop_var(void* l0, vader_box_t l1);
static void toolchain_protocol$write_match_body(void* l0, void* l1);
static void toolchain_protocol$write_members(void* l0, void* l1);
static void toolchain_protocol$write_module(void* l0, void* l1, void* l2);
static void toolchain_protocol$write_optional___toolchain_ast_StructLitField___toolchain_ast_StructLitSpread___(void* l0, vader_box_t l1, void* l2);
static void toolchain_protocol$write_optional_binding(void* l0, vader_box_t l1);
static void toolchain_protocol$write_optional_expr(void* l0, vader_box_t l1);
static void toolchain_protocol$write_optional_field(void* l0, vader_box_t l1);
static void toolchain_protocol$write_optional_integer(void* l0, vader_box_t l1);
static void toolchain_protocol$write_optional_pattern(void* l0, vader_box_t l1);
static void toolchain_protocol$write_optional_span(void* l0, vader_box_t l1);
static void toolchain_protocol$write_params(void* l0, void* l1);
static void toolchain_protocol$write_pattern_field_value(void* l0, vader_box_t l1);
static void toolchain_protocol$write_place(void* l0, void* l1);
static void toolchain_protocol$write_position(void* l0, void* l1);
static void toolchain_protocol$write_span_1(void* l0, void* l1);
static void toolchain_protocol$write_string_parts(void* l0, void* l1);
static void toolchain_protocol$write_strings(void* l0, void* l1);
static void toolchain_protocol$write_struct(void* l0, void* l1);
static void toolchain_protocol$write_trait(void* l0, void* l1);
static void toolchain_protocol$write_type_params(void* l0, void* l1);

vader_box_t vader_fn_tramp_toolchain_protocol$write_binding(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_binding(a0.payload.obj, a1);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_binding = {
	VADER_STATIC_HEADER(605u), (void*) &vader_fn_tramp_toolchain_protocol$write_binding, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_call_arg(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_call_arg(a0.payload.obj, a1.payload.obj);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_call_arg = {
	VADER_STATIC_HEADER(585u), (void*) &vader_fn_tramp_toolchain_protocol$write_call_arg, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_call_args(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_call_args(a0.payload.obj, a1.payload.obj);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_call_args = {
	VADER_STATIC_HEADER(582u), (void*) &vader_fn_tramp_toolchain_protocol$write_call_args, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_decl(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_decl(a0.payload.obj, a1);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_decl = {
	VADER_STATIC_HEADER(601u), (void*) &vader_fn_tramp_toolchain_protocol$write_decl, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_decorator(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_decorator(a0.payload.obj, a1.payload.obj);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_decorator = {
	VADER_STATIC_HEADER(586u), (void*) &vader_fn_tramp_toolchain_protocol$write_decorator, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_expr(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_expr(a0.payload.obj, a1);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_expr = {
	VADER_STATIC_HEADER(600u), (void*) &vader_fn_tramp_toolchain_protocol$write_expr, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_fallback_clause(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_fallback_clause(a0.payload.obj, a1.payload.obj);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_fallback_clause = {
	VADER_STATIC_HEADER(588u), (void*) &vader_fn_tramp_toolchain_protocol$write_fallback_clause,
	NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_function(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_function(a0.payload.obj, a1.payload.obj);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_function = {
	VADER_STATIC_HEADER(589u), (void*) &vader_fn_tramp_toolchain_protocol$write_function, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_import_name(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_import_name(a0.payload.obj, a1.payload.obj);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_import_name = {
	VADER_STATIC_HEADER(592u), (void*) &vader_fn_tramp_toolchain_protocol$write_import_name, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_match_arm(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_match_arm(a0.payload.obj, a1.payload.obj);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_match_arm = {
	VADER_STATIC_HEADER(593u), (void*) &vader_fn_tramp_toolchain_protocol$write_match_arm, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_param(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_param(a0.payload.obj, a1.payload.obj);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_param = {
	VADER_STATIC_HEADER(590u), (void*) &vader_fn_tramp_toolchain_protocol$write_param, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_pattern(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_pattern(a0.payload.obj, a1);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_pattern = {
	VADER_STATIC_HEADER(603u), (void*) &vader_fn_tramp_toolchain_protocol$write_pattern, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_qualifier(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_qualifier(a0.payload.obj, a1.payload.obj);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_qualifier = {
	VADER_STATIC_HEADER(591u), (void*) &vader_fn_tramp_toolchain_protocol$write_qualifier, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_simple_binding(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_simple_binding(a0.payload.obj, a1.payload.obj);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_simple_binding = {
	VADER_STATIC_HEADER(594u), (void*) &vader_fn_tramp_toolchain_protocol$write_simple_binding,
	NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_span(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_span(a0.payload.obj, a1.payload.obj);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_span = {
	VADER_STATIC_HEADER(599u), (void*) &vader_fn_tramp_toolchain_protocol$write_span, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_spread(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_spread(a0.payload.obj, a1.payload.obj);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_spread = {
	VADER_STATIC_HEADER(597u), (void*) &vader_fn_tramp_toolchain_protocol$write_spread, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_stmt(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_stmt(a0.payload.obj, a1);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_stmt = {
	VADER_STATIC_HEADER(602u), (void*) &vader_fn_tramp_toolchain_protocol$write_stmt, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_string_part(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_string_part(a0.payload.obj, a1);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_string_part = {
	VADER_STATIC_HEADER(606u), (void*) &vader_fn_tramp_toolchain_protocol$write_string_part, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_struct_field(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_struct_field(a0.payload.obj, a1.payload.obj);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_struct_field = {
	VADER_STATIC_HEADER(595u), (void*) &vader_fn_tramp_toolchain_protocol$write_struct_field, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_struct_item(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_struct_item(a0.payload.obj, a1);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_struct_item = {
	VADER_STATIC_HEADER(607u), (void*) &vader_fn_tramp_toolchain_protocol$write_struct_item, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_struct_items(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_struct_items(a0.payload.obj, a1.payload.obj);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_struct_items = {
	VADER_STATIC_HEADER(583u), (void*) &vader_fn_tramp_toolchain_protocol$write_struct_items, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_struct_pattern_field(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_struct_pattern_field(a0.payload.obj, a1.payload.obj);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_struct_pattern_field = {
	VADER_STATIC_HEADER(596u),
	(void*) &vader_fn_tramp_toolchain_protocol$write_struct_pattern_field, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_target(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_target(a0.payload.obj, a1);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_target = {
	VADER_STATIC_HEADER(604u), (void*) &vader_fn_tramp_toolchain_protocol$write_target, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_type_param(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_type_param(a0.payload.obj, a1.payload.obj);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_type_param = {
	VADER_STATIC_HEADER(598u), (void*) &vader_fn_tramp_toolchain_protocol$write_type_param, NULL,
};

vader_box_t vader_fn_tramp_toolchain_protocol$write_variant(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	toolchain_protocol$write_variant(a0.payload.obj, a1.payload.obj);
	return vader_box_obj(643u, NULL);
}

vader_fn_t vader_fn_static_toolchain_protocol$write_variant = {
	VADER_STATIC_HEADER(587u), (void*) &vader_fn_tramp_toolchain_protocol$write_variant, NULL,
};

static vader_string_t __lambda_toolchain_protocol_0(void* l0, vader_string_t l1) {
	vader_box_t l2;
	vader_string_t t0;
	l2 = std_collections$Map$std_core$Index$at__string__string(((vader_struct___lambda_env_toolchain_protocol_1_t*) l0)->f_cap_0, l1);
	if (l2.tag == 0u) {
		return l1;
	}
	t0 = l2.payload.s;
	return t0;
}

static bool __lambda_toolchain_protocol_2(void* l0) {
	bool t0;
	t0 = toolchain_ast$is_compiler_made(l0);
	return !(t0);
}

bool toolchain_protocol$crosses(vader_box_t l0) {
	bool l1;
	bool t0;
	void* t1;
	t0 = toolchain_ast$is_comptime_made(l0);
	if (!(t0)) {
		if (!(l0.tag == 1181u)) {
			l1 = true;
		} else {
			t1 = l0.payload.obj;
			t0 = toolchain_ast$is_compiler_made(t1);
			l1 = !(t0);
		}
		return l1;
	}
	return false;
}

vader_box_t toolchain_protocol$decode_driver_frame(vader_string_t l0) {
	void* l1 = NULL;
	vader_string_t l2 = 0;
	vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l5 = vader_box_null();
	int64_t l6, l7;
	void* t0 = NULL;
	vader_box_t* gc_roots[3] = { &l3, &l4, &l5 };
	void** gc_raw_roots[2] = { &l1, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l0, &l2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_struct_toolchain_protocol$FieldReader_t* _a0_obj = (vader_struct_toolchain_protocol$FieldReader_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$FieldReader_t));
	vader_obj_header_init(_a0_obj, 1278u);
	_a0_obj->f_payload = l0;
	_a0_obj->f_at = INT64_C(0);
	l1 = (void*) _a0_obj;
	l3 = toolchain_protocol$read_field(l1);
	l4 = l3;
	if (l3.tag == 1282u) {
		t0 = l4.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = l3.payload.s;
	l4 = toolchain_protocol$read_driver_frame(l1, l2);
	l5 = l4;
	if (l4.tag == 1282u) {
		t0 = l5.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = l4;
	l6 = ((vader_struct_toolchain_protocol$FieldReader_t*) l1)->f_at;
	l7 = (int64_t) vader_string_byte_len(l0);
	if (!((l6 < l7))) {
		{ vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = toolchain_protocol$past_last_field(l1);
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t toolchain_protocol$decode_stage_plan(vader_string_t l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l5 = NULL;
	vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
	int64_t l6, l7;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l3, &l4 };
	void** gc_raw_roots[4] = { &l1, &l2, &l5, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_struct_toolchain_protocol$FieldReader_t* _a0_obj = (vader_struct_toolchain_protocol$FieldReader_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$FieldReader_t));
	vader_obj_header_init(_a0_obj, 1278u);
	_a0_obj->f_payload = l0;
	_a0_obj->f_at = INT64_C(0);
	l1 = (void*) _a0_obj;
	l3 = toolchain_protocol$read_specs(l1);
	l4 = l3;
	if (l3.tag == 1282u) {
		t0 = l4.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = l3.payload.obj;
	l3 = toolchain_protocol$read_strings(l1);
	l4 = l3;
	if (l3.tag == 1282u) {
		t0 = l4.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = l3.payload.obj;
	l6 = ((vader_struct_toolchain_protocol$FieldReader_t*) l1)->f_at;
	l7 = (int64_t) vader_string_byte_len(l0);
	if (!((l6 < l7))) {
		vader_struct_toolchain_protocol$StagePlan_t* _a1_obj = (vader_struct_toolchain_protocol$StagePlan_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$StagePlan_t));
		vader_obj_header_init(_a1_obj, 1285u);
		_a1_obj->f_sources = l2;
		_a1_obj->f_bodies = l5;
		t0 = (void*) _a1_obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = toolchain_protocol$past_last_field(l1);
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* toolchain_protocol$past_last_field(void* l0) {
	void* l1 = NULL;
	int64_t l2, l3;
	vader_string_t t0 = 0;
	void* t1 = NULL;
	void** gc_raw_roots[3] = { &l0, &l1, &t1 };
	vader_string_t* gc_atom_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l1 = (void*) vader_buffer_new((size_t) INT64_C(67));
	l2 = INT64_C(0);
	l2 = std_core$write_string_at(l1, l2, 3369u);
	l3 = ((vader_struct_toolchain_protocol$FieldReader_t*) l0)->f_at;
	l2 = std_core$write_int(l1, l2, l3);
	t0 = std_core$finish_buffer(l1, l2);
	vader_struct_toolchain_protocol$ProtocolError_t* _a0_obj = (vader_struct_toolchain_protocol$ProtocolError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$ProtocolError_t));
	vader_obj_header_init(_a0_obj, 1282u);
	_a0_obj->f_msg = t0;
	t1 = (void*) _a0_obj;
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_protocol$read_body(void* l0) {
	vader_string_t l1 = 0;
	vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
	void* l4 = NULL;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l2, &l3 };
	void** gc_raw_roots[3] = { &l0, &l4, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = toolchain_protocol$read_field(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = l2.payload.s;
	l2 = toolchain_protocol$read_reports(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = l2.payload.obj;
	vader_struct_toolchain_protocol$BodyFrame_t* _a0_obj = (vader_struct_toolchain_protocol$BodyFrame_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$BodyFrame_t));
	vader_obj_header_init(_a0_obj, 1270u);
	_a0_obj->f_text = l1;
	_a0_obj->f_reports = l4;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_protocol$read_configure(void* l0) {
	vader_string_t l1 = 0;
	vader_string_t l7 = 0;
	vader_string_t l8 = 0;
	vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
	int64_t l4, l6;
	void* l5 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	void* l14 = NULL;
	void* l15 = NULL;
	bool l13;
	uint8_t l16;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	int32_t t2;
	vader_box_t* gc_roots[4] = { &l2, &l3, &l9, &l10 };
	void** gc_raw_roots[7] = { &l0, &l5, &l11, &l12, &l14, &l15, &t0 };
	vader_string_t* gc_atom_roots[4] = { &l1, &l7, &l8, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = toolchain_protocol$read_field(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = l2.payload.s;
	l2 = toolchain_protocol$read_count(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = ((int64_t) l2.payload.i);
	vader_array_t* _a0_arr = vader_array_new(100u, 0u, 13u, 1269u);
	l5 = (void*) _a0_arr;
	l6 = INT64_C(0);
	while ((l6 < l4)) {
		l2 = toolchain_protocol$read_field(l0);
		l3 = l2;
		if (l2.tag == 1282u) {
			t0 = l3.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l7 = l2.payload.s;
		l9 = toolchain_protocol$read_field(l0);
		l10 = l9;
		if (l9.tag == 1282u) {
			t0 = l10.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l8 = l9.payload.s;
		vader_struct_toolchain_project$ManifestEntry_t* _a1_obj = (vader_struct_toolchain_project$ManifestEntry_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_project$ManifestEntry_t));
		vader_obj_header_init(_a1_obj, 1269u);
		_a1_obj->f_name = l7;
		_a1_obj->f_path = l8;
		l11 = (void*) _a1_obj;
		vader_array_push_ref((vader_array_t*) l5, l11);
		l6 = (l6 + INT64_C(1));
	}
	l2 = toolchain_protocol$read_strings(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l11 = l2.payload.obj;
	l2 = toolchain_protocol$read_strings(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l12 = l2.payload.obj;
	l2 = toolchain_protocol$read_integer(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = ((int64_t) l2.payload.i);
	if ((l4 < INT64_C(0))) {
		l13 = true;
	} else {
		l13 = (l4 > INT64_C(1));
	}
	if (l13) {
		l14 = (void*) vader_buffer_new((size_t) INT64_C(39));
		l6 = INT64_C(0);
		l6 = std_core$write_int(l14, l6, l4);
		l6 = std_core$write_string_at(l14, l6, 204u);
		t1 = std_core$finish_buffer(l14, l6);
		vader_struct_toolchain_protocol$ProtocolError_t* _a2_obj = (vader_struct_toolchain_protocol$ProtocolError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$ProtocolError_t));
		vader_obj_header_init(_a2_obj, 1282u);
		_a2_obj->f_msg = t1;
		t0 = (void*) _a2_obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = toolchain_protocol$read_field(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l7 = l2.payload.s;
	l2 = toolchain_protocol$read_field(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l8 = l2.payload.s;
	l2 = toolchain_protocol$read_specs(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l14 = l2.payload.obj;
	l2 = toolchain_protocol$read_strings(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l15 = l2.payload.obj;
	t2 = (((int32_t) (int64_t) l4) & INT32_C(255));
	l16 = (uint8_t) (int32_t) t2;
	vader_struct_toolchain_protocol$ConfigureFrame_t* _a3_obj = (vader_struct_toolchain_protocol$ConfigureFrame_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$ConfigureFrame_t));
	vader_obj_header_init(_a3_obj, 1273u);
	_a3_obj->f_fingerprint = l1;
	_a3_obj->f_entries = l5;
	_a3_obj->f_include_paths = l11;
	_a3_obj->f_assets = l12;
	_a3_obj->f_target = l16;
	_a3_obj->f_cc = l7;
	_a3_obj->f_ldflags = l8;
	_a3_obj->f_stages = l14;
	_a3_obj->f_bodies = l15;
	t0 = (void*) _a3_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_protocol$read_count(void* l0) {
	int64_t l1, l5;
	vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
	void* l4 = NULL;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t* gc_roots[2] = { &l2, &l3 };
	void** gc_raw_roots[3] = { &l0, &l4, &t0 };
	vader_string_t* gc_atom_roots[1] = { &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = toolchain_protocol$read_integer(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = ((int64_t) l2.payload.i);
	if (!((l1 < INT64_C(0)))) {
		{ vader_box_t __vret = vader_box_i64(646u, l1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = (void*) vader_buffer_new((size_t) INT64_C(39));
	l5 = INT64_C(0);
	l5 = std_core$write_string_at(l4, l5, 1886u);
	l5 = std_core$write_int(l4, l5, l1);
	l5 = std_core$write_string_at(l4, l5, 214u);
	t1 = std_core$finish_buffer(l4, l5);
	vader_struct_toolchain_protocol$ProtocolError_t* _a0_obj = (vader_struct_toolchain_protocol$ProtocolError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$ProtocolError_t));
	vader_obj_header_init(_a0_obj, 1282u);
	_a0_obj->f_msg = t1;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_protocol$read_doc_query(void* l0) {
	vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l1, &l2 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l1 = toolchain_protocol$read_span_1(l0);
	l2 = l1;
	if (l1.tag == 1282u) {
		t0 = l2.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l1.payload.obj;
	vader_struct_toolchain_protocol$DocQueryFrame_t* _a0_obj = (vader_struct_toolchain_protocol$DocQueryFrame_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$DocQueryFrame_t));
	vader_obj_header_init(_a0_obj, 1276u);
	_a0_obj->f_span = t0;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_protocol$read_driver_frame(void* l0, vader_string_t l1) {
	vader_box_t l2 = vader_box_null();
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t* gc_roots[1] = { &l2 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l1 == 2296u) {
		l2 = toolchain_protocol$read_configure(l0);
		{ vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l1 == 2402u) {
		l2 = toolchain_protocol$read_emit_module(l0);
	} else if (l1 == 3144u) {
		l2 = toolchain_protocol$read_report(l0);
	} else if (l1 == 2368u) {
		l2 = toolchain_protocol$read_doc_query(l0);
	} else if (l1 == 2981u) {
		t0 = (void*) &vader_data_119;
		vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
		l2 = vader_ref_box(t0);
	} else if (l1 == 3256u) {
		t0 = (void*) &vader_data_120;
		vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
		l2 = vader_ref_box(t0);
	} else if (l1 == 2618u) {
		l2 = toolchain_protocol$read_generated(l0);
	} else if (l1 == 2105u) {
		l2 = toolchain_protocol$read_body(l0);
	} else {
		t1 = concat_3(1318u, l1, 1495u);
		vader_struct_toolchain_protocol$ProtocolError_t* _a2_obj = (vader_struct_toolchain_protocol$ProtocolError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$ProtocolError_t));
		vader_obj_header_init(_a2_obj, 1282u);
		_a2_obj->f_msg = t1;
		t0 = (void*) _a2_obj;
		l2 = vader_ref_box(t0);
	}
	{ vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_protocol$read_emit_module(void* l0) {
	vader_string_t l1 = 0;
	vader_string_t l4 = 0;
	vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l2, &l3 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l1, &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = toolchain_protocol$read_field(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = l2.payload.s;
	l2 = toolchain_protocol$read_field(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = l2.payload.s;
	vader_struct_toolchain_protocol$EmitModuleFrame_t* _a0_obj = (vader_struct_toolchain_protocol$EmitModuleFrame_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$EmitModuleFrame_t));
	vader_obj_header_init(_a0_obj, 1277u);
	_a0_obj->f_name = l1;
	_a0_obj->f_source = l4;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_protocol$read_field(void* l0) {
	int64_t l1, l5, l6, l7;
	vader_string_t l2 = 0;
	vader_box_t l3 = vader_box_null();
	void* l4 = NULL;
	vader_string_t t0 = 0;
	void* t1 = NULL;
	vader_box_t* gc_roots[1] = { &l3 };
	void** gc_raw_roots[3] = { &l0, &l4, &t1 };
	vader_string_t* gc_atom_roots[2] = { &l2, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_protocol$FieldReader_t*) l0)->f_payload;
	l1 = ((vader_struct_toolchain_protocol$FieldReader_t*) l0)->f_at;
	l3 = std_string$index_of(l2, 58u, l1);
	if (l3.tag == 0u) {
		l4 = (void*) vader_buffer_new((size_t) INT64_C(50));
		l5 = INT64_C(0);
		l5 = std_core$write_string_at(l4, l5, 1855u);
		l6 = ((vader_struct_toolchain_protocol$FieldReader_t*) l0)->f_at;
		l5 = std_core$write_int(l4, l5, l6);
		l5 = std_core$write_string_at(l4, l5, 174u);
		t0 = std_core$finish_buffer(l4, l5);
		vader_struct_toolchain_protocol$ProtocolError_t* _a0_obj = (vader_struct_toolchain_protocol$ProtocolError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$ProtocolError_t));
		vader_obj_header_init(_a0_obj, 1282u);
		_a0_obj->f_msg = t0;
		t1 = (void*) _a0_obj;
		{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = ((int64_t) l3.payload.i);
	l2 = ((vader_struct_toolchain_protocol$FieldReader_t*) l0)->f_payload;
	l6 = ((vader_struct_toolchain_protocol$FieldReader_t*) l0)->f_at;
	l3 = std_numbers$parse_int_in_base(vader_string_byte_slice(l2, l6, l1), INT32_C(10));
	if (l3.tag == 1137u) {
		l4 = (void*) vader_buffer_new((size_t) INT64_C(50));
		l6 = INT64_C(0);
		l6 = std_core$write_string_at(l4, l6, 1855u);
		l7 = ((vader_struct_toolchain_protocol$FieldReader_t*) l0)->f_at;
		l6 = std_core$write_int(l4, l6, l7);
		l6 = std_core$write_string_at(l4, l6, 174u);
		t0 = std_core$finish_buffer(l4, l6);
		vader_struct_toolchain_protocol$ProtocolError_t* _a1_obj = (vader_struct_toolchain_protocol$ProtocolError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$ProtocolError_t));
		vader_obj_header_init(_a1_obj, 1282u);
		_a1_obj->f_msg = t0;
		t1 = (void*) _a1_obj;
		{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = ((int64_t) l3.payload.i);
	l1 = vader_chk_add(i64, l1, INT64_C(1));
	l5 = vader_chk_add(i64, l1, l5);
	t0 = ((vader_struct_toolchain_protocol$FieldReader_t*) l0)->f_payload;
	l6 = (int64_t) vader_string_byte_len(t0);
	if (!((l5 > l6))) {
		((vader_struct_toolchain_protocol$FieldReader_t*) l0)->f_at = l5;
		t0 = ((vader_struct_toolchain_protocol$FieldReader_t*) l0)->f_payload;
		{ vader_box_t __vret = vader_box_string(642u, vader_string_byte_slice(t0, l1, l5)); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = (void*) vader_buffer_new((size_t) INT64_C(67));
	l1 = INT64_C(0);
	l1 = std_core$write_string_at(l4, l1, 1855u);
	l5 = ((vader_struct_toolchain_protocol$FieldReader_t*) l0)->f_at;
	l1 = std_core$write_int(l4, l1, l5);
	l1 = std_core$write_string_at(l4, l1, 264u);
	t0 = std_core$finish_buffer(l4, l1);
	vader_struct_toolchain_protocol$ProtocolError_t* _a2_obj = (vader_struct_toolchain_protocol$ProtocolError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$ProtocolError_t));
	vader_obj_header_init(_a2_obj, 1282u);
	_a2_obj->f_msg = t0;
	t1 = (void*) _a2_obj;
	{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_protocol$read_generated(void* l0) {
	vader_string_t l1 = 0;
	vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
	int64_t l4, l6;
	void* l5 = NULL;
	void* l7 = NULL;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l2, &l3 };
	void** gc_raw_roots[4] = { &l0, &l5, &l7, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = toolchain_protocol$read_field(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = l2.payload.s;
	l2 = toolchain_protocol$read_count(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = ((int64_t) l2.payload.i);
	vader_array_t* _a0_arr = vader_array_new(104u, 0u, 13u, 1289u);
	l5 = (void*) _a0_arr;
	l6 = INT64_C(0);
	while ((l6 < l4)) {
		l2 = toolchain_protocol$read_span_1(l0);
		l3 = l2;
		if (l2.tag == 1282u) {
			t0 = l3.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l7 = l2.payload.obj;
		vader_array_push_ref((vader_array_t*) l5, l7);
		l6 = (l6 + INT64_C(1));
	}
	l2 = toolchain_protocol$read_reports(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l7 = l2.payload.obj;
	vader_struct_toolchain_protocol$GeneratedFrame_t* _a1_obj = (vader_struct_toolchain_protocol$GeneratedFrame_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$GeneratedFrame_t));
	vader_obj_header_init(_a1_obj, 1279u);
	_a1_obj->f_text = l1;
	_a1_obj->f_anchors = l5;
	_a1_obj->f_reports = l7;
	t0 = (void*) _a1_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_protocol$read_givens(void* l0) {
	int64_t l1, l5;
	vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l13 = vader_box_null(), l14 = vader_box_null(), l16 = vader_box_null(), l17 = vader_box_null();
	void* l4 = NULL;
	void* l11 = NULL;
	void* l18 = NULL;
	vader_string_t l6 = 0;
	vader_string_t l7 = 0;
	vader_string_t l12 = 0;
	vader_string_t l15 = 0;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	uint8_t t2;
	vader_box_t* gc_roots[9] = { &l2, &l3, &l8, &l9, &l10, &l13, &l14, &l16, &l17 };
	void** gc_raw_roots[5] = { &l0, &l4, &l11, &l18, &t0 };
	vader_string_t* gc_atom_roots[5] = { &l6, &l7, &l12, &l15, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 9u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = toolchain_protocol$read_count(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = ((int64_t) l2.payload.i);
	vader_array_t* _a0_arr = vader_array_new(490u, 0u, 13u, 2547u);
	l4 = (void*) _a0_arr;
	l5 = INT64_C(0);
	while ((l5 < l1)) {
		l2 = toolchain_protocol$read_field(l0);
		l3 = l2;
		if (l2.tag == 1282u) {
			t0 = l3.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l6 = l2.payload.s;
		if (l6 == 2276u) {
			l8 = toolchain_protocol$read_field(l0);
			l9 = l8;
			if (l8.tag == 1282u) {
				t0 = l9.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l7 = l8.payload.s;
			l10 = toolchain_ast$compiler_decorator_named(l7);
			if (l10.tag == 0u) {
				t1 = concat_3(1720u, l7, 1494u);
				vader_struct_toolchain_protocol$ProtocolError_t* _a1_obj = (vader_struct_toolchain_protocol$ProtocolError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$ProtocolError_t));
				vader_obj_header_init(_a1_obj, 1282u);
				_a1_obj->f_msg = t1;
				t0 = (void*) _a1_obj;
				{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
			}
			t2 = ((uint8_t) l10.payload.i);
			vader_struct_toolchain_stage$DecoratedWith_t* _a2_obj = (vader_struct_toolchain_stage$DecoratedWith_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$DecoratedWith_t));
			vader_obj_header_init(_a2_obj, 1293u);
			_a2_obj->f_marker = t2;
			l11 = (void*) _a2_obj;
			vader_array_push_ref((vader_array_t*) l4, l11);
		} else {
			if (!(l6 == 2337u)) {
				t1 = concat_3(1318u, l6, 1493u);
				vader_struct_toolchain_protocol$ProtocolError_t* _a3_obj = (vader_struct_toolchain_protocol$ProtocolError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$ProtocolError_t));
				vader_obj_header_init(_a3_obj, 1282u);
				_a3_obj->f_msg = t1;
				t0 = (void*) _a3_obj;
				{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l13 = toolchain_protocol$read_field(l0);
			l14 = l13;
			if (l13.tag == 1282u) {
				t0 = l14.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l12 = l13.payload.s;
			l16 = toolchain_protocol$read_field(l0);
			l17 = l16;
			if (l16.tag == 1282u) {
				t0 = l17.payload.obj;
				{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
			}
			l15 = l16.payload.s;
			vader_struct_toolchain_stage$DecoratorOrigin_t* _a4_obj = (vader_struct_toolchain_stage$DecoratorOrigin_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$DecoratorOrigin_t));
			vader_obj_header_init(_a4_obj, 1294u);
			_a4_obj->f_module = l12;
			_a4_obj->f_name = l15;
			l18 = (void*) _a4_obj;
			vader_array_push_ref((vader_array_t*) l4, l18);
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_protocol$read_i32(void* l0) {
	int64_t l1, l6;
	vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
	bool l4;
	void* l5 = NULL;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t* gc_roots[2] = { &l2, &l3 };
	void** gc_raw_roots[3] = { &l0, &l5, &t0 };
	vader_string_t* gc_atom_roots[1] = { &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = toolchain_protocol$read_integer(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = ((int64_t) l2.payload.i);
	if ((l1 < INT64_C(-2147483648))) {
		l4 = true;
	} else {
		l4 = (l1 > INT64_C(2147483647));
	}
	if (!(l4)) {
		{ vader_box_t __vret = vader_box_i32(645u, ((int32_t) (int64_t) l1)); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = (void*) vader_buffer_new((size_t) INT64_C(42));
	l6 = INT64_C(0);
	l6 = std_core$write_int(l5, l6, l1);
	l6 = std_core$write_string_at(l5, l6, 146u);
	t1 = std_core$finish_buffer(l5, l6);
	vader_struct_toolchain_protocol$ProtocolError_t* _a0_obj = (vader_struct_toolchain_protocol$ProtocolError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$ProtocolError_t));
	vader_obj_header_init(_a0_obj, 1282u);
	_a0_obj->f_msg = t1;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_protocol$read_integer(void* l0) {
	vader_string_t l1 = 0;
	vader_string_t l4 = 0;
	vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
	int64_t l5, l6, l7;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	int64_t t2;
	vader_box_t* gc_roots[2] = { &l2, &l3 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l1, &l4, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = toolchain_protocol$read_field(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = l2.payload.s;
	l4 = std_string$trim_prefix(l1, 478u);
	l2 = std_numbers$parse_int_in_base(l4, INT32_C(10));
	if (l2.tag == 1137u) {
		t1 = concat_3(1318u, l1, 1498u);
		vader_struct_toolchain_protocol$ProtocolError_t* _a0_obj = (vader_struct_toolchain_protocol$ProtocolError_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$ProtocolError_t));
		vader_obj_header_init(_a0_obj, 1282u);
		_a0_obj->f_msg = t1;
		t0 = (void*) _a0_obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = ((int64_t) l2.payload.i);
	l6 = (int64_t) vader_string_byte_len(l4);
	l7 = (int64_t) vader_string_byte_len(l1);
	if (!((l6 < l7))) {
		{ vader_box_t __vret = vader_box_i64(646u, l5); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t2 = vader_chk_neg(i64, l5);
	{ vader_box_t __vret = vader_box_i64(646u, t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_protocol$read_place(void* l0, vader_string_t l1) {
	int64_t l2;
	vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
	int32_t l5, l6;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l3, &l4 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = toolchain_protocol$read_integer(l0);
	l4 = l3;
	if (l3.tag == 1282u) {
		t0 = l4.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = ((int64_t) l3.payload.i);
	l3 = toolchain_protocol$read_i32(l0);
	l4 = l3;
	if (l3.tag == 1282u) {
		t0 = l4.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = ((int32_t) l3.payload.i);
	l3 = toolchain_protocol$read_i32(l0);
	l4 = l3;
	if (l3.tag == 1282u) {
		t0 = l4.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l6 = ((int32_t) l3.payload.i);
	vader_struct_toolchain_span$Position_t* _a0_obj = (vader_struct_toolchain_span$Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Position_t));
	vader_obj_header_init(_a0_obj, 1288u);
	_a0_obj->f_file = l1;
	_a0_obj->f_offset = l2;
	_a0_obj->f_line = l5;
	_a0_obj->f_column = l6;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_protocol$read_position(void* l0) {
	vader_string_t l1 = 0;
	vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_box_t* gc_roots[3] = { &l2, &l3, &t1 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = toolchain_protocol$read_field(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = l2.payload.s;
	t1 = toolchain_protocol$read_place(l0, l1);
	{ vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_protocol$read_report(void* l0) {
	vader_string_t l1 = 0;
	vader_string_t l5 = 0;
	vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
	void* l4 = NULL;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l2, &l3 };
	void** gc_raw_roots[3] = { &l0, &l4, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l1, &l5 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = toolchain_protocol$read_field(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = l2.payload.s;
	l2 = toolchain_protocol$read_span_1(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = l2.payload.obj;
	l2 = toolchain_protocol$read_field(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = l2.payload.s;
	vader_struct_toolchain_protocol$ReportFrame_t* _a0_obj = (vader_struct_toolchain_protocol$ReportFrame_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$ReportFrame_t));
	vader_obj_header_init(_a0_obj, 1283u);
	_a0_obj->f_code = l1;
	_a0_obj->f_span = l4;
	_a0_obj->f_detail = l5;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_protocol$read_reports(void* l0) {
	int64_t l1, l5;
	vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
	void* l4 = NULL;
	void* l6 = NULL;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l2, &l3 };
	void** gc_raw_roots[4] = { &l0, &l4, &l6, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = toolchain_protocol$read_count(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = ((int64_t) l2.payload.i);
	vader_array_t* _a0_arr = vader_array_new(102u, 0u, 13u, 1283u);
	l4 = (void*) _a0_arr;
	l5 = INT64_C(0);
	while ((l5 < l1)) {
		l2 = toolchain_protocol$read_report(l0);
		l3 = l2;
		if (l2.tag == 1282u) {
			t0 = l3.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l6 = l2.payload.obj;
		vader_array_push_ref((vader_array_t*) l4, l6);
		l5 = (l5 + INT64_C(1));
	}
	{ vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_protocol$read_span_1(void* l0) {
	void* l1 = NULL;
	void* l4 = NULL;
	vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l2, &l3 };
	void** gc_raw_roots[4] = { &l0, &l1, &l4, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = toolchain_protocol$read_position(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = l2.payload.obj;
	l2 = toolchain_protocol$read_position(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = l2.payload.obj;
	vader_struct_toolchain_span$Span_t* _a0_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
	vader_obj_header_init(_a0_obj, 1289u);
	_a0_obj->f_start = l1;
	_a0_obj->f_end = l4;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_protocol$read_specs(void* l0) {
	int64_t l1, l5;
	vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l11 = vader_box_null(), l12 = vader_box_null();
	void* l4 = NULL;
	void* l7 = NULL;
	void* l10 = NULL;
	void* l13 = NULL;
	vader_string_t l6 = 0;
	void* t0 = NULL;
	vader_box_t* gc_roots[6] = { &l2, &l3, &l8, &l9, &l11, &l12 };
	void** gc_raw_roots[6] = { &l0, &l4, &l7, &l10, &l13, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l6 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 6u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = toolchain_protocol$read_count(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = ((int64_t) l2.payload.i);
	vader_array_t* _a0_arr = vader_array_new(106u, 0u, 13u, 1301u);
	l4 = (void*) _a0_arr;
	l5 = INT64_C(0);
	while ((l5 < l1)) {
		l2 = toolchain_protocol$read_field(l0);
		l3 = l2;
		if (l2.tag == 1282u) {
			t0 = l3.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l6 = l2.payload.s;
		l8 = toolchain_protocol$read_givens(l0);
		l9 = l8;
		if (l8.tag == 1282u) {
			t0 = l9.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l7 = l8.payload.obj;
		l11 = toolchain_protocol$read_givens(l0);
		l12 = l11;
		if (l11.tag == 1282u) {
			t0 = l12.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l10 = l11.payload.obj;
		vader_struct_toolchain_stage$SourceSpec_t* _a1_obj = (vader_struct_toolchain_stage$SourceSpec_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_stage$SourceSpec_t));
		vader_obj_header_init(_a1_obj, 1301u);
		_a1_obj->f_name = l6;
		_a1_obj->f_given = l7;
		_a1_obj->f_generates = l10;
		l13 = (void*) _a1_obj;
		vader_array_push_ref((vader_array_t*) l4, l13);
		l5 = (l5 + INT64_C(1));
	}
	{ vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_protocol$read_strings(void* l0) {
	int64_t l1, l5;
	vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
	void* l4 = NULL;
	vader_string_t l6 = 0;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l2, &l3 };
	void** gc_raw_roots[3] = { &l0, &l4, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l6 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = toolchain_protocol$read_count(l0);
	l3 = l2;
	if (l2.tag == 1282u) {
		t0 = l3.payload.obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = ((int64_t) l2.payload.i);
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	l4 = (void*) _a0_arr;
	l5 = INT64_C(0);
	while ((l5 < l1)) {
		l2 = toolchain_protocol$read_field(l0);
		l3 = l2;
		if (l2.tag == 1282u) {
			t0 = l3.payload.obj;
			{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l6 = l2.payload.s;
		vader_array_push_scalar((vader_array_t*) l4, vader_box_string(642u, l6));
		l5 = (l5 + INT64_C(1));
	}
	{ vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
}

void* toolchain_protocol$renamed_span(void* l0, void* l1) {
	void* l2 = NULL;
	void* l8 = NULL;
	vader_string_t l3 = 0;
	vader_box_t l4 = vader_box_null();
	int64_t l5;
	int32_t l6, l7;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l4 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_span$Span_t*) l0)->f_start;
	l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_file;
	l4 = std_collections$Map$std_core$Index$at__string__string(l1, l3);
	if (l4.tag == 0u) {
		l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_start)->f_file;
	} else {
		l3 = l4.payload.s;
	}
	l5 = ((vader_struct_toolchain_span$Position_t*) l2)->f_offset;
	l6 = ((vader_struct_toolchain_span$Position_t*) l2)->f_line;
	l7 = ((vader_struct_toolchain_span$Position_t*) l2)->f_column;
	vader_struct_toolchain_span$Position_t* _a0_obj = (vader_struct_toolchain_span$Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Position_t));
	vader_obj_header_init(_a0_obj, 1288u);
	_a0_obj->f_file = l3;
	_a0_obj->f_offset = l5;
	_a0_obj->f_line = l6;
	_a0_obj->f_column = l7;
	l2 = (void*) _a0_obj;
	l8 = ((vader_struct_toolchain_span$Span_t*) l0)->f_end;
	l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_end)->f_file;
	l4 = std_collections$Map$std_core$Index$at__string__string(l1, l3);
	if (l4.tag == 0u) {
		l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l0)->f_end)->f_file;
	} else {
		l3 = l4.payload.s;
	}
	l5 = ((vader_struct_toolchain_span$Position_t*) l8)->f_offset;
	l6 = ((vader_struct_toolchain_span$Position_t*) l8)->f_line;
	l7 = ((vader_struct_toolchain_span$Position_t*) l8)->f_column;
	vader_struct_toolchain_span$Position_t* _a1_obj = (vader_struct_toolchain_span$Position_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Position_t));
	vader_obj_header_init(_a1_obj, 1288u);
	_a1_obj->f_file = l3;
	_a1_obj->f_offset = l5;
	_a1_obj->f_line = l6;
	_a1_obj->f_column = l7;
	l8 = (void*) _a1_obj;
	vader_struct_toolchain_span$Span_t* _a2_obj = (vader_struct_toolchain_span$Span_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_span$Span_t));
	vader_obj_header_init(_a2_obj, 1289u);
	_a2_obj->f_start = l2;
	_a2_obj->f_end = l8;
	t0 = (void*) _a2_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t toolchain_protocol$server_payload(vader_box_t l0) {
	void* l1 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	void* l8 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	vader_string_t l2 = 0;
	vader_string_t l9 = 0;
	int64_t l5, l7;
	vader_box_t l6 = vader_box_null();
	bool l12;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	int32_t t2;
	vader_box_t* gc_roots[2] = { &l0, &l6 };
	void** gc_raw_roots[7] = { &l1, &l3, &l4, &l8, &l10, &l11, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l2, &l9, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	t0 = (void*) _a0_arr;
	vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
	vader_obj_header_init(_a1_obj, 1139u);
	_a1_obj->f_parts = t0;
	l1 = (void*) _a1_obj;
	if (l0.tag == 1287u) {
		toolchain_protocol$write_field(l1, 3457u);
		t0 = l0.payload.obj;
		l2 = ((vader_struct_toolchain_protocol$TypecheckedFrame_t*) t0)->f_module_name;
		toolchain_protocol$write_field(l1, l2);
		t0 = l0.payload.obj;
		l3 = ((vader_struct_toolchain_protocol$TypecheckedFrame_t*) t0)->f_decorators;
		t0 = l0.payload.obj;
		l4 = ((vader_struct_toolchain_protocol$TypecheckedFrame_t*) t0)->f_declarations;
		toolchain_protocol$write_module(l1, l3, l4);
		t1 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
		{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l0.tag == 1281u) {
		toolchain_protocol$write_field(l1, 3091u);
		t0 = l0.payload.obj;
		l5 = ((int64_t) (uint8_t) ((vader_struct_toolchain_protocol$PhaseFrame_t*) t0)->f_phase);
		toolchain_protocol$write_integer(l1, l5);
	} else if (l0.tag == 1272u) {
		toolchain_protocol$write_field(l1, 2277u);
		t0 = l0.payload.obj;
		t2 = ((vader_struct_toolchain_protocol$CompleteFrame_t*) t0)->f_code;
		l5 = ((int64_t) (int32_t) t2);
		toolchain_protocol$write_integer(l1, l5);
		t0 = l0.payload.obj;
		l3 = ((vader_struct_toolchain_protocol$CompleteFrame_t*) t0)->f_generated;
		toolchain_protocol$write_strings(l1, l3);
	} else if (l0.tag == 1275u) {
		toolchain_protocol$write_field(l1, 2367u);
		t0 = l0.payload.obj;
		l6 = ((vader_struct_toolchain_protocol$DocAnswerFrame_t*) t0)->f_doc;
		toolchain_protocol$write_doc(l1, l6);
	} else if (l0.tag == 1284u) {
		toolchain_protocol$write_field(l1, 3217u);
		t0 = l0.payload.obj;
		l2 = ((vader_struct_toolchain_protocol$SourceStageFrame_t*) t0)->f_stage;
		toolchain_protocol$write_field(l1, l2);
		t0 = l0.payload.obj;
		l2 = ((vader_struct_toolchain_stage$Sources_t*) ((vader_struct_toolchain_protocol$SourceStageFrame_t*) t0)->f_sources)->f_module_name;
		toolchain_protocol$write_field(l1, l2);
		t0 = l0.payload.obj;
		l5 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_stage$Sources_t*) ((vader_struct_toolchain_protocol$SourceStageFrame_t*) t0)->f_sources)->f_files));
		toolchain_protocol$write_integer(l1, l5);
		t0 = l0.payload.obj;
		l3 = ((vader_struct_toolchain_protocol$SourceStageFrame_t*) t0)->f_names;
		t0 = l0.payload.obj;
		l4 = ((vader_struct_toolchain_stage$Sources_t*) ((vader_struct_toolchain_protocol$SourceStageFrame_t*) t0)->f_sources)->f_files;
		l5 = vader_array_length(((vader_array_t*) l4));
		l7 = INT64_C(0);
		while ((l7 < l5)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
			l8 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
			l2 = ((vader_struct_toolchain_ast$Program_t*) l8)->f_file;
			l6 = std_collections$Map$std_core$Index$at__string__string(l3, l2);
			if (l6.tag == 0u) {
				l9 = ((vader_struct_toolchain_ast$Program_t*) l8)->f_file;
			} else {
				l9 = l6.payload.s;
			}
			toolchain_protocol$write_field(l1, l9);
			l10 = toolchain_protocol$renamed_span(((vader_struct_toolchain_ast$Program_t*) l8)->f_span, l3);
			toolchain_protocol$write_span_1(l1, l10);
			l11 = ((vader_struct_toolchain_ast$Program_t*) l8)->f_decls;
			toolchain_protocol$write_declarations(l1, l11, l3);
			l7 = (l7 + INT64_C(1));
		}
	} else {
		if (!(l0.tag == 1271u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		toolchain_protocol$write_field(l1, 2106u);
		t0 = l0.payload.obj;
		l2 = ((vader_struct_toolchain_protocol$BodyStageFrame_t*) t0)->f_stage;
		toolchain_protocol$write_field(l1, l2);
		t0 = l0.payload.obj;
		l2 = ((vader_struct_toolchain_stage$BodyRequest_t*) ((vader_struct_toolchain_protocol$BodyStageFrame_t*) t0)->f_request)->f_module_name;
		toolchain_protocol$write_field(l1, l2);
		t0 = l0.payload.obj;
		l3 = ((vader_struct_toolchain_protocol$BodyStageFrame_t*) t0)->f_names;
		t0 = l0.payload.obj;
		vader_array_t* _a3_arr = vader_array_new(481u, 1u, 13u, 2451u);
		((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 0u] = ((vader_struct_toolchain_stage$BodyRequest_t*) ((vader_struct_toolchain_protocol$BodyStageFrame_t*) t0)->f_request)->f_decl;
		l4 = (void*) _a3_arr;
		toolchain_protocol$write_declarations(l1, l4, l3);
		t0 = l0.payload.obj;
		l6 = ((vader_struct_toolchain_stage$BodyRequest_t*) ((vader_struct_toolchain_protocol$BodyStageFrame_t*) t0)->f_request)->f_owner;
		l12 = !(l6.tag == 0u);
		toolchain_protocol$write_flag(l1, l12);
		if (!(l6.tag == 0u)) {
			t0 = l6.payload.obj;
			vader_array_t* _a4_arr = vader_array_new(481u, 1u, 13u, 2451u);
			((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = t0;
			l4 = (void*) _a4_arr;
			toolchain_protocol$write_declarations(l1, l4, l3);
		}
		t0 = l0.payload.obj;
		l4 = ((vader_struct_toolchain_stage$BodyRequest_t*) ((vader_struct_toolchain_protocol$BodyStageFrame_t*) t0)->f_request)->f_declarations;
		toolchain_protocol$write_declarations(l1, l4, l3);
	}
	t1 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void toolchain_protocol$write_alias(void* l0, void* l1) {
	void* l2 = NULL;
	void* l4 = NULL;
	void* l6 = NULL;
	vader_string_t l3 = 0;
	uint8_t l5;
	vader_box_t l7 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l7 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &l6 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 1968u);
	l2 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) l1)->f_span;
	l3 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) l1)->f_name;
	l4 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) l1)->f_name_span;
	l5 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) l1)->f_visibility;
	l6 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) l1)->f_decorators;
	toolchain_protocol$write_head(l0, l2, l3, l4, l5, l6);
	l2 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) l1)->f_type_params;
	toolchain_protocol$write_type_params(l0, l2);
	l7 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) l1)->f_aliased;
	toolchain_protocol$write_expr(l0, l7);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_assert(void* l0, void* l1) {
	void* l2 = NULL;
	vader_box_t l3 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l3 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 2071u);
	l2 = ((vader_struct_toolchain_ast$AssertDecl_t*) l1)->f_span;
	toolchain_protocol$write_span(l0, l2);
	l2 = ((vader_struct_toolchain_ast$AssertDecl_t*) l1)->f_decorators;
	toolchain_protocol$write_decorators(l0, l2);
	l3 = ((vader_struct_toolchain_ast$AssertDecl_t*) l1)->f_condition;
	toolchain_protocol$write_expr(l0, l3);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l3 = ((vader_struct_toolchain_ast$AssertDecl_t*) l1)->f_message;
	toolchain_protocol$write_optional_field(l2, l3);
	l3 = ((vader_struct_toolchain_ast$AssertDecl_t*) l1)->f_message_span;
	toolchain_protocol$write_optional_span(l0, l3);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_binding(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	vader_string_t l4 = 0;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l1.tag == 1220u) {
		toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 2960u);
		l2 = l1.payload.obj;
		toolchain_protocol$write_simple_binding(l0, l2);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l1.tag == 1233u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$TupleBinding_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3422u, l2);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$TupleBinding_t*) t0)->f_elements;
		l3 = (void*) &vader_fn_static_toolchain_protocol$write_binding;
		toolchain_protocol$write_list__toolchain_ast_RestBinding___toolchain_ast_SimpleBinding___toolchain_ast_TupleBinding___toolchain_ast_WildcardBinding(l0, l2, l3);
	} else if (l1.tag == 1238u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$WildcardBinding_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3774u, l2);
	} else {
		if (!(l1.tag == 1216u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$RestBinding_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3149u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$RestBinding_t*) t0)->f_name;
		toolchain_protocol$write_field(l2, l4);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$RestBinding_t*) t0)->f_name_span;
		toolchain_protocol$write_span(l0, l2);
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_block(void* l0, void* l1) {
	void* l2 = NULL;
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$BlockExpr_t*) l1)->f_span;
	toolchain_protocol$write_span(l0, l2);
	toolchain_protocol$write_block_body(l0, l1);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_block_body(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	vader_box_t l4 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l4 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$BlockExpr_t*) l1)->f_stmts;
	l3 = (void*) &vader_fn_static_toolchain_protocol$write_stmt;
	toolchain_protocol$write_list__toolchain_ast_AssignStmt___toolchain_ast_BreakStmt___toolchain_ast_ContinueStmt___toolchain_ast_DeferStmt___toolchain_ast_DestructureAssignStmt___toolchain_ast_ExprStmt___toolchain_ast_ForStmt___toolchain_ast_LetStmt___toolchain_ast_ReturnStmt___toolchain_ast_YieldStmt(l0, l2, l3);
	l4 = ((vader_struct_toolchain_ast$BlockExpr_t*) l1)->f_trailing;
	toolchain_protocol$write_optional_expr(l0, l4);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_call_arg(void* l0, void* l1) {
	void* l2 = NULL;
	vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
	bool l5;
	vader_box_t* gc_roots[2] = { &l3, &l4 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$CallArg_t*) l1)->f_span;
	toolchain_protocol$write_span(l0, l2);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l3 = ((vader_struct_toolchain_ast$CallArg_t*) l1)->f_name;
	toolchain_protocol$write_optional_field(l2, l3);
	l3 = ((vader_struct_toolchain_ast$CallArg_t*) l1)->f_comptime_body;
	if (l3.tag == 0u) {
		l4 = ((vader_struct_toolchain_ast$CallArg_t*) l1)->f_value;
	} else {
		l4 = l3;
	}
	toolchain_protocol$write_expr(l0, l4);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l5 = ((vader_struct_toolchain_ast$CallArg_t*) l1)->f_spread;
	toolchain_protocol$write_flag(l2, l5);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_call_args(void* l0, void* l1) {
	void* l2 = NULL;
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = (void*) &vader_fn_static_toolchain_protocol$write_call_arg;
	toolchain_protocol$write_list__toolchain_ast_CallArg(l0, l1, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_const(void* l0, void* l1) {
	void* l2 = NULL;
	void* l4 = NULL;
	void* l6 = NULL;
	vader_string_t l3 = 0;
	uint8_t l5;
	vader_box_t l7 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l7 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &l6 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 2300u);
	l2 = ((vader_struct_toolchain_ast$ConstDecl_t*) l1)->f_span;
	l3 = ((vader_struct_toolchain_ast$ConstDecl_t*) l1)->f_name;
	l4 = ((vader_struct_toolchain_ast$ConstDecl_t*) l1)->f_name_span;
	l5 = ((vader_struct_toolchain_ast$ConstDecl_t*) l1)->f_visibility;
	l6 = ((vader_struct_toolchain_ast$ConstDecl_t*) l1)->f_decorators;
	toolchain_protocol$write_head(l0, l2, l3, l4, l5, l6);
	l7 = ((vader_struct_toolchain_ast$ConstDecl_t*) l1)->f_ty;
	toolchain_protocol$write_optional_expr(l0, l7);
	l7 = toolchain_ast$written_value(l1);
	toolchain_protocol$write_expr(l0, l7);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_decl(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[2] = { &l0, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l1.tag == 1224u) {
		l2 = l1.payload.obj;
		toolchain_protocol$write_struct(l0, l2);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l1.tag == 1181u) {
		l2 = l1.payload.obj;
		toolchain_protocol$write_fn(l0, l2);
	} else if (l1.tag == 1172u) {
		l2 = l1.payload.obj;
		toolchain_protocol$write_enum(l0, l2);
	} else if (l1.tag == 1232u) {
		l2 = l1.payload.obj;
		toolchain_protocol$write_trait(l0, l2);
	} else if (l1.tag == 1190u) {
		l2 = l1.payload.obj;
		toolchain_protocol$write_impl(l0, l2);
	} else if (l1.tag == 1234u) {
		l2 = l1.payload.obj;
		toolchain_protocol$write_alias(l0, l2);
	} else if (l1.tag == 1157u) {
		l2 = l1.payload.obj;
		toolchain_protocol$write_const(l0, l2);
	} else if (l1.tag == 1147u) {
		l2 = l1.payload.obj;
		toolchain_protocol$write_assert(l0, l2);
	} else {
		if (!(l1.tag == 1191u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l2 = l1.payload.obj;
		toolchain_protocol$write_import(l0, l2);
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_declarations(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l8 = NULL;
	int64_t l7, l9;
	vader_string_t l10 = 0;
	vader_string_t l11 = 0;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_box_t* gc_roots[1] = { &t1 };
	void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l8, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l10, &l11 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	t0 = (void*) _a0_arr;
	vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
	vader_obj_header_init(_a1_obj, 1139u);
	_a1_obj->f_parts = t0;
	l3 = (void*) _a1_obj;
	vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 642u);
	l4 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(30u, 0u, 8u, 646u);
	l5 = (void*) _a3_arr;
	vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 645u);
	l6 = (void*) _a4_arr;
	vader_struct_std_collections$Map__string__i64_t* _a5_obj = (vader_struct_std_collections$Map__string__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i64_t));
	vader_obj_header_init(_a5_obj, 1013u);
	_a5_obj->f_ekeys = l4;
	_a5_obj->f_evals = l5;
	_a5_obj->f_index = l6;
	_a5_obj->f_mask = INT64_C(0);
	_a5_obj->f_grow_at = INT64_C(0);
	_a5_obj->f_size = INT64_C(0);
	_a5_obj->f_tombs = INT64_C(0);
	l4 = (void*) _a5_obj;
	vader_struct_toolchain_protocol$DeclWriter_t* _a6_obj = (vader_struct_toolchain_protocol$DeclWriter_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$DeclWriter_t));
	vader_obj_header_init(_a6_obj, 1274u);
	_a6_obj->f_out = l3;
	_a6_obj->f_files = l4;
	l3 = (void*) _a6_obj;
	l4 = (void*) &vader_fn_static_toolchain_protocol$write_decl;
	toolchain_protocol$write_list__toolchain_ast_AssertDecl___toolchain_ast_ConstDecl___toolchain_ast_EnumDecl___toolchain_ast_FnDecl___toolchain_ast_ImplDecl___toolchain_ast_ImportDecl___toolchain_ast_StructDecl___toolchain_ast_TraitDecl___toolchain_ast_TypeAliasDecl(l3, l1, l4);
	l4 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l3)->f_files;
	vader_struct___lambda_env_toolchain_protocol_1_t* _a7_obj = (vader_struct___lambda_env_toolchain_protocol_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_toolchain_protocol_1_t));
	vader_obj_header_init(_a7_obj, 693u);
	_a7_obj->f_cap_0 = l2;
	l5 = (void*) _a7_obj;
	l7 = ((vader_struct_std_collections$Map__string__i64_t*) l4)->f_size;
	if ((INT64_C(0) < l7)) {
		l7 = ((vader_struct_std_collections$Map__string__i64_t*) l4)->f_size;
	} else {
		l7 = INT64_C(0);
	}
	vader_array_t* _a8_arr = vader_array_reserve(28u, (int64_t) l7, 0u, 642u);
	l6 = (void*) _a8_arr;
	l8 = ((vader_struct_std_collections$Map__string__i64_t*) l4)->f_ekeys;
	l7 = INT64_C(0);
	l9 = ((vader_struct_std_collections$Map__string__i64_t*) l4)->f_size;
	while ((l7 < l9)) {
		vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
		VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l7)
		t1 = vader_array_box_slots(_a9_slotarr->buf)[vader_array_offset(_a9_slotarr) + (size_t) l7];
		l10 = t1.payload.s;
		l11 = __lambda_toolchain_protocol_0(l5, l10);
		vader_array_push_scalar((vader_array_t*) l6, vader_box_string(642u, l11));
		l7 = (l7 + INT64_C(1));
	}
	toolchain_protocol$write_strings(l0, l6);
	l10 = std_string__builder$StringBuilder$std_core$Display$to_string(((vader_struct_toolchain_protocol$DeclWriter_t*) l3)->f_out);
	std_string__builder$append(l0, l10);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_decorator(void* l0, void* l1) {
	void* l2 = NULL;
	vader_box_t l3 = vader_box_null();
	vader_string_t l4 = 0;
	vader_box_t* gc_roots[1] = { &l3 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_string_t* gc_atom_roots[1] = { &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_span;
	toolchain_protocol$write_span(l0, l2);
	l3 = ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_qualifier;
	l2 = (void*) &vader_fn_static_toolchain_protocol$write_qualifier;
	toolchain_protocol$write_optional___toolchain_ast_StructLitField___toolchain_ast_StructLitSpread___(l0, l3, l2);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_name;
	toolchain_protocol$write_field(l2, l4);
	l2 = ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_name_span;
	toolchain_protocol$write_span(l0, l2);
	l2 = ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_args;
	toolchain_protocol$write_call_args(l0, l2);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = ((vader_struct_toolchain_ast$Decorator_t*) l1)->f_module_name;
	toolchain_protocol$write_field(l2, l4);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_decorators(void* l0, void* l1) {
	void* l2 = NULL;
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = (void*) &vader_fn_static_toolchain_protocol$write_decorator;
	toolchain_protocol$write_list__toolchain_ast_Decorator(l0, l1, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_defer_body(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	vader_box_t l3 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l1, &l3 };
	void** gc_raw_roots[3] = { &l0, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l1.tag == 1162u) {
		toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 2101u);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$DeferBlockBody_t*) t0)->f_block;
		toolchain_protocol$write_block(l0, l2);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 3227u);
	t0 = l1.payload.obj;
	l3 = ((vader_struct_toolchain_ast$DeferStmtBody_t*) t0)->f_stmt;
	toolchain_protocol$write_stmt(l0, l3);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_doc(void* l0, vader_box_t l1) {
	bool l2;
	int64_t l3, l5;
	void* l4 = NULL;
	void* l6 = NULL;
	void* l8 = NULL;
	vader_string_t l7 = 0;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[5] = { &l0, &l4, &l6, &l8, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l7 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = !(l1.tag == 0u);
	toolchain_protocol$write_flag(l0, l2);
	if (l1.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	t0 = l1.payload.obj;
	l3 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$DocComment_t*) t0)->f_lines));
	toolchain_protocol$write_integer(l0, l3);
	t0 = l1.payload.obj;
	l4 = ((vader_struct_toolchain_ast$DocComment_t*) t0)->f_lines;
	l3 = vader_array_length(((vader_array_t*) l4));
	l5 = INT64_C(0);
	while ((l5 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		l7 = ((vader_struct_toolchain_ast$DocCommentLine_t*) l6)->f_text;
		toolchain_protocol$write_field(l0, l7);
		l8 = ((vader_struct_toolchain_ast$DocCommentLine_t*) l6)->f_span;
		toolchain_protocol$write_span_1(l0, l8);
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_enum(void* l0, void* l1) {
	void* l2 = NULL;
	void* l4 = NULL;
	void* l6 = NULL;
	vader_string_t l3 = 0;
	uint8_t l5;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &l6 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 2418u);
	l2 = ((vader_struct_toolchain_ast$EnumDecl_t*) l1)->f_span;
	l3 = ((vader_struct_toolchain_ast$EnumDecl_t*) l1)->f_name;
	l4 = ((vader_struct_toolchain_ast$EnumDecl_t*) l1)->f_name_span;
	l5 = ((vader_struct_toolchain_ast$EnumDecl_t*) l1)->f_visibility;
	l6 = ((vader_struct_toolchain_ast$EnumDecl_t*) l1)->f_decorators;
	toolchain_protocol$write_head(l0, l2, l3, l4, l5, l6);
	l2 = ((vader_struct_toolchain_ast$EnumDecl_t*) l1)->f_header;
	toolchain_protocol$write_exprs(l0, l2);
	l2 = ((vader_struct_toolchain_ast$EnumDecl_t*) l1)->f_variants;
	l4 = (void*) &vader_fn_static_toolchain_protocol$write_variant;
	toolchain_protocol$write_list__toolchain_ast_EnumVariant(l0, l2, l4);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_expr(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	int64_t l4;
	uint64_t l5;
	vader_string_t l6 = 0;
	bool l7;
	vader_box_t l8 = vader_box_null();
	void* t0 = NULL;
	double t1;
	int64_t t2;
	uint32_t t3;
	vader_box_t* gc_roots[2] = { &l1, &l8 };
	void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l6 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l1.tag == 1196u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$IntLitExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2748u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		l3 = (void*) vader_buffer_new((size_t) INT64_C(20));
		l4 = INT64_C(0);
		t0 = l1.payload.obj;
		l5 = ((vader_struct_toolchain_ast$IntLitExpr_t*) t0)->f_value;
		l4 = std_core$write_unsigned(l3, l4, l5);
		l6 = std_core$finish_buffer(l3, l4);
		toolchain_protocol$write_field(l2, l6);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l7 = ((vader_struct_toolchain_ast$IntLitExpr_t*) t0)->f_negative;
		toolchain_protocol$write_flag(l2, l7);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l1.tag == 1180u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$FloatLitExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2561u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		l3 = (void*) vader_buffer_new((size_t) INT64_C(20));
		l4 = INT64_C(0);
		t0 = l1.payload.obj;
		t1 = ((vader_struct_toolchain_ast$FloatLitExpr_t*) t0)->f_value;
		t2 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t1 }).__vu);
		l5 = (uint64_t) (int64_t) t2;
		l4 = std_core$write_unsigned(l3, l4, l5);
		l6 = std_core$finish_buffer(l3, l4);
		toolchain_protocol$write_field(l2, l6);
	} else if (l1.tag == 1151u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$BoolLitExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2107u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l7 = ((vader_struct_toolchain_ast$BoolLitExpr_t*) t0)->f_value;
		toolchain_protocol$write_flag(l2, l7);
	} else if (l1.tag == 1208u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$NullLitExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3025u, l2);
	} else if (l1.tag == 1156u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$CharLitExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2247u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		t3 = ((vader_struct_toolchain_ast$CharLitExpr_t*) t0)->f_value;
		l4 = ((int64_t) (uint32_t) t3);
		toolchain_protocol$write_integer(l2, l4);
	} else if (l1.tag == 1221u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$StringLitExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3273u, l2);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$StringLitExpr_t*) t0)->f_parts;
		toolchain_protocol$write_string_parts(l0, l2);
	} else if (l1.tag == 1186u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2701u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l6 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
		toolchain_protocol$write_field(l2, l6);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l7 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_implicit_dot;
		toolchain_protocol$write_flag(l2, l7);
	} else if (l1.tag == 1154u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2196u, l2);
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_callee;
		toolchain_protocol$write_expr(l0, l8);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_type_args;
		toolchain_protocol$write_exprs(l0, l2);
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_written_args;
		if (l8.tag == 0u) {
			t0 = l1.payload.obj;
			l2 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_args;
		} else {
			l2 = l8.payload.obj;
		}
		toolchain_protocol$write_call_args(l0, l2);
	} else if (l1.tag == 1179u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2532u, l2);
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_target;
		toolchain_protocol$write_expr(l0, l8);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l6 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_field;
		toolchain_protocol$write_field(l2, l6);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_field_span;
		toolchain_protocol$write_span(l0, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l7 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_is_numeric;
		toolchain_protocol$write_flag(l2, l7);
	} else if (l1.tag == 1194u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$IndexExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2735u, l2);
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$IndexExpr_t*) t0)->f_target;
		toolchain_protocol$write_expr(l0, l8);
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$IndexExpr_t*) t0)->f_index;
		toolchain_protocol$write_expr(l0, l8);
	} else if (l1.tag == 1236u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$UnaryExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3493u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l6 = toolchain_ast$unary_op_symbol(((vader_struct_toolchain_ast$UnaryExpr_t*) t0)->f_op);
		toolchain_protocol$write_field(l2, l6);
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$UnaryExpr_t*) t0)->f_operand;
		toolchain_protocol$write_expr(l0, l8);
	} else if (l1.tag == 1149u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2088u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l6 = toolchain_ast$binary_op_symbol(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_op);
		toolchain_protocol$write_field(l2, l6);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_op_span;
		toolchain_protocol$write_span(l0, l2);
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_left;
		toolchain_protocol$write_expr(l0, l8);
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_right;
		toolchain_protocol$write_expr(l0, l8);
	} else if (l1.tag == 1178u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$FallbackExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2519u, l2);
		l2 = l1.payload.obj;
		toolchain_protocol$write_fallback_body(l0, l2);
	} else if (l1.tag == 1189u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$IfExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2705u, l2);
		l2 = l1.payload.obj;
		toolchain_protocol$write_if_body(l0, l2);
	} else if (l1.tag == 1204u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$MatchExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2902u, l2);
		l2 = l1.payload.obj;
		toolchain_protocol$write_match_body(l0, l2);
	} else if (l1.tag == 1150u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$BlockExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2101u, l2);
		l2 = l1.payload.obj;
		toolchain_protocol$write_block_body(l0, l2);
	} else if (l1.tag == 1200u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2834u, l2);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_params;
		toolchain_protocol$write_params(l0, l2);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_params_span;
		toolchain_protocol$write_span(l0, l2);
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_return_type;
		toolchain_protocol$write_optional_expr(l0, l8);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_body;
		toolchain_protocol$write_block(l0, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l7 = ((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_is_expression_bodied;
		toolchain_protocol$write_flag(l2, l7);
	} else if (l1.tag == 1226u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$StructLitExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3290u, l2);
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$StructLitExpr_t*) t0)->f_type_name;
		toolchain_protocol$write_expr(l0, l8);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$StructLitExpr_t*) t0)->f_items;
		toolchain_protocol$write_struct_items(l0, l2);
	} else if (l1.tag == 1219u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$SeqLitExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3188u, l2);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$SeqLitExpr_t*) t0)->f_elements;
		toolchain_protocol$write_exprs(l0, l2);
	} else if (l1.tag == 1214u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$RangeExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3111u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l7 = ((vader_struct_toolchain_ast$RangeExpr_t*) t0)->f_inclusive;
		toolchain_protocol$write_flag(l2, l7);
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$RangeExpr_t*) t0)->f_lower;
		toolchain_protocol$write_expr(l0, l8);
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$RangeExpr_t*) t0)->f_upper;
		toolchain_protocol$write_expr(l0, l8);
	} else if (l1.tag == 1155u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$CastExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2238u, l2);
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$CastExpr_t*) t0)->f_target;
		toolchain_protocol$write_expr(l0, l8);
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$CastExpr_t*) t0)->f_value;
		toolchain_protocol$write_expr(l0, l8);
	} else if (l1.tag == 1185u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2627u, l2);
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee;
		toolchain_protocol$write_expr(l0, l8);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_type_args;
		toolchain_protocol$write_exprs(l0, l2);
	} else if (l1.tag == 1197u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2770u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l6 = toolchain_ast$intrinsic_name(((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) t0)->f_intrinsic);
		toolchain_protocol$write_field(l2, l6);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) t0)->f_name_span;
		toolchain_protocol$write_span(l0, l2);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) t0)->f_args;
		toolchain_protocol$write_exprs(l0, l2);
	} else if (l1.tag == 1171u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3718u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l6 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) t0)->f_variant;
		toolchain_protocol$write_field(l2, l6);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) t0)->f_variant_span;
		toolchain_protocol$write_span(l0, l2);
	} else if (l1.tag == 1183u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2592u, l2);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_params;
		toolchain_protocol$write_exprs(l0, l2);
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$FnTypeExpr_t*) t0)->f_return_type;
		toolchain_protocol$write_optional_expr(l0, l8);
	} else {
		if (!(l1.tag == 1146u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$ArrayTypeExpr_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2029u, l2);
		t0 = l1.payload.obj;
		l8 = ((vader_struct_toolchain_ast$ArrayTypeExpr_t*) t0)->f_element;
		toolchain_protocol$write_expr(l0, l8);
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_exprs(void* l0, void* l1) {
	void* l2 = NULL;
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = (void*) &vader_fn_static_toolchain_protocol$write_expr;
	toolchain_protocol$write_list__toolchain_ast_ArrayTypeExpr___toolchain_ast_BinaryExpr___toolchain_ast_BlockExpr___toolchain_ast_BoolLitExpr___toolchain_ast_CallExpr___toolchain_ast_CastExpr___toolchain_ast_CharLitExpr___toolchain_ast_DotVariantExpr___toolchain_ast_FallbackExpr___toolchain_ast_FieldExpr___toolchain_ast_FloatLitExpr___toolchain_ast_FnTypeExpr___toolchain_ast_GenericInstExpr___toolchain_ast_IdentExpr___toolchain_ast_IfExpr___toolchain_ast_IndexExpr___toolchain_ast_IntLitExpr___toolchain_ast_IntrinsicCallExpr___toolchain_ast_LambdaExpr___toolchain_ast_MatchExpr___toolchain_ast_NullLitExpr___toolchain_ast_RangeExpr___toolchain_ast_SeqLitExpr___toolchain_ast_StringLitExpr___toolchain_ast_StructLitExpr___toolchain_ast_UnaryExpr(l0, l1, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_fallback_body(void* l0, void* l1) {
	vader_box_t l2 = vader_box_null();
	void* l3 = NULL;
	void* l4 = NULL;
	vader_box_t* gc_roots[1] = { &l2 };
	void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$FallbackExpr_t*) l1)->f_left;
	toolchain_protocol$write_expr(l0, l2);
	l3 = ((vader_struct_toolchain_ast$FallbackExpr_t*) l1)->f_clauses;
	l4 = (void*) &vader_fn_static_toolchain_protocol$write_fallback_clause;
	toolchain_protocol$write_list__toolchain_ast_FallbackClause(l0, l3, l4);
	l2 = ((vader_struct_toolchain_ast$FallbackExpr_t*) l1)->f_binding;
	toolchain_protocol$write_optional_binding(l0, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_fallback_clause(void* l0, void* l1) {
	void* l2 = NULL;
	vader_box_t l3 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l3 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$FallbackClause_t*) l1)->f_span;
	toolchain_protocol$write_span(l0, l2);
	l2 = ((vader_struct_toolchain_ast$FallbackClause_t*) l1)->f_op_span;
	toolchain_protocol$write_span(l0, l2);
	l3 = ((vader_struct_toolchain_ast$FallbackClause_t*) l1)->f_test;
	toolchain_protocol$write_optional_expr(l0, l3);
	l3 = ((vader_struct_toolchain_ast$FallbackClause_t*) l1)->f_body;
	toolchain_protocol$write_fallback_result(l0, l3);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_fallback_result(void* l0, vader_box_t l1) {
	vader_box_t l2 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l1, &l2 };
	void** gc_raw_roots[1] = { &l0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if ((l1.tag == 1146u || l1.tag == 1149u || l1.tag == 1150u || l1.tag == 1151u || l1.tag == 1154u || l1.tag == 1155u || l1.tag == 1156u || l1.tag == 1171u || l1.tag == 1178u || l1.tag == 1179u || l1.tag == 1180u || l1.tag == 1183u || l1.tag == 1185u || l1.tag == 1186u || l1.tag == 1189u || l1.tag == 1194u || l1.tag == 1196u || l1.tag == 1197u || l1.tag == 1200u || l1.tag == 1204u || l1.tag == 1208u || l1.tag == 1214u || l1.tag == 1219u || l1.tag == 1221u || l1.tag == 1226u || l1.tag == 1236u)) {
		toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 3703u);
		l2 = l1;
		toolchain_protocol$write_expr(l0, l2);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l2 = l1;
	toolchain_protocol$write_stmt(l0, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_field(void* l0, vader_string_t l1) {
	void* l2 = NULL;
	int64_t l3, l4;
	vader_string_t l5 = 0;
	void** gc_raw_roots[2] = { &l0, &l2 };
	vader_string_t* gc_atom_roots[2] = { &l1, &l5 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = (void*) vader_buffer_new((size_t) INT64_C(21));
	l3 = INT64_C(0);
	l4 = (int64_t) vader_string_byte_len(l1);
	l3 = std_core$write_int(l2, l3, l4);
	l3 = std_core$write_string_at(l2, l3, 566u);
	l5 = std_core$finish_buffer(l2, l3);
	std_string__builder$append(l0, l5);
	std_string__builder$append(l0, l1);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_flag(void* l0, bool l1) {
	vader_string_t l2 = 0;
	void** gc_raw_roots[1] = { &l0 };
	vader_string_t* gc_atom_roots[1] = { &l2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l1) {
		l2 = 559u;
		toolchain_protocol$write_field(l0, l2);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l2 = 554u;
	toolchain_protocol$write_field(l0, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_fn(void* l0, void* l1) {
	void** gc_raw_roots[2] = { &l0, &l1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 2562u);
	toolchain_protocol$write_function(l0, l1);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_for_form(void* l0, vader_box_t l1) {
	vader_box_t l2 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l1, &l2 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l1.tag == 1195u) {
		toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 2586u);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l1.tag == 1237u) {
		toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 3768u);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$WhileFor_t*) t0)->f_cond;
		toolchain_protocol$write_expr(l0, l2);
	} else {
		if (!(l1.tag == 1193u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 2725u);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$InFor_t*) t0)->f_loop_var;
		toolchain_protocol$write_loop_var(l0, l2);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$InFor_t*) t0)->f_iter;
		toolchain_protocol$write_expr(l0, l2);
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_form(void* l0, vader_string_t l1, void* l2) {
	void** gc_raw_roots[2] = { &l0, &l2 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, l1);
	toolchain_protocol$write_span(l0, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_function(void* l0, void* l1) {
	void* l2 = NULL;
	void* l4 = NULL;
	void* l6 = NULL;
	vader_string_t l3 = 0;
	uint8_t l5;
	vader_box_t l7 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l7 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &l6 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_span;
	l3 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name;
	l4 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name_span;
	l5 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_visibility;
	l6 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_decorators;
	toolchain_protocol$write_head(l0, l2, l3, l4, l5, l6);
	l2 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_type_params;
	toolchain_protocol$write_type_params(l0, l2);
	l2 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_params_span;
	toolchain_protocol$write_span(l0, l2);
	l2 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_params;
	toolchain_protocol$write_params(l0, l2);
	l7 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_return_type;
	toolchain_protocol$write_optional_expr(l0, l7);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_head(void* l0, void* l1, vader_string_t l2, void* l3, uint8_t l4, void* l5) {
	void* l6 = NULL;
	bool l7;
	void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &l6 };
	vader_string_t* gc_atom_roots[1] = { &l2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	toolchain_protocol$write_span(l0, l1);
	toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, l2);
	toolchain_protocol$write_span(l0, l3);
	l6 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l7 = l4 == INT32_C(0);
	toolchain_protocol$write_flag(l6, l7);
	toolchain_protocol$write_decorators(l0, l5);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_if_body(void* l0, void* l1) {
	vader_box_t l2 = vader_box_null();
	void* l3 = NULL;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l2 };
	void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$IfExpr_t*) l1)->f_cond;
	toolchain_protocol$write_expr(l0, l2);
	l3 = ((vader_struct_toolchain_ast$IfExpr_t*) l1)->f_then_block;
	toolchain_protocol$write_block(l0, l3);
	l2 = ((vader_struct_toolchain_ast$IfExpr_t*) l1)->f_else_branch;
	if (l2.tag == 0u) {
		toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 3014u);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l2.tag == 1188u) {
		t0 = l2.payload.obj;
		l3 = ((vader_struct_toolchain_ast$IfExpr_t*) ((vader_struct_toolchain_ast$IfElseIf_t*) t0)->f_branch)->f_span;
		toolchain_protocol$write_form(l0, 2705u, l3);
		t0 = l2.payload.obj;
		l3 = ((vader_struct_toolchain_ast$IfElseIf_t*) t0)->f_branch;
		toolchain_protocol$write_if_body(l0, l3);
	} else {
		if (!(l2.tag == 1187u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 2387u);
		t0 = l2.payload.obj;
		l3 = ((vader_struct_toolchain_ast$IfElseBlock_t*) t0)->f_block;
		toolchain_protocol$write_block(l0, l3);
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_impl(void* l0, void* l1) {
	void* l2 = NULL;
	vader_box_t l3 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l3 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 2711u);
	l2 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_span;
	toolchain_protocol$write_span(l0, l2);
	l2 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_decorators;
	toolchain_protocol$write_decorators(l0, l2);
	l2 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_type_params;
	toolchain_protocol$write_type_params(l0, l2);
	l3 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_implemented;
	toolchain_protocol$write_expr(l0, l3);
	l3 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_for_type;
	toolchain_protocol$write_expr(l0, l3);
	l2 = ((vader_struct_toolchain_ast$ImplDecl_t*) l1)->f_members;
	toolchain_protocol$write_members(l0, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_import(void* l0, void* l1) {
	void* l2 = NULL;
	void* l5 = NULL;
	vader_string_t l3 = 0;
	vader_box_t l4 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l4 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 2716u);
	l2 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_span;
	toolchain_protocol$write_span(l0, l2);
	l2 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_decorators;
	toolchain_protocol$write_decorators(l0, l2);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l3 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_path;
	toolchain_protocol$write_field(l2, l3);
	l4 = ((vader_struct_toolchain_ast$ImportDecl_t*) l1)->f_binding;
	if (l4.tag == 1206u) {
		toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 2968u);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l4.payload.obj;
		l3 = ((vader_struct_toolchain_ast$NamedNamespaceImport_t*) t0)->f_name;
		toolchain_protocol$write_field(l2, l3);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l4.tag == 1166u) {
		toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 2358u);
		t0 = l4.payload.obj;
		l2 = ((vader_struct_toolchain_ast$DestructureImport_t*) t0)->f_names;
		l5 = (void*) &vader_fn_static_toolchain_protocol$write_import_name;
		toolchain_protocol$write_list__toolchain_ast_ImportName(l0, l2, l5);
	} else {
		if (!(l4.tag == 1239u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 3774u);
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_import_name(void* l0, void* l1) {
	void* l2 = NULL;
	vader_string_t l3 = 0;
	vader_box_t l4 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l4 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$ImportName_t*) l1)->f_span;
	toolchain_protocol$write_span(l0, l2);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l3 = ((vader_struct_toolchain_ast$ImportName_t*) l1)->f_name;
	toolchain_protocol$write_field(l2, l3);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = ((vader_struct_toolchain_ast$ImportName_t*) l1)->f_alias;
	toolchain_protocol$write_optional_field(l2, l4);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_integer(void* l0, int64_t l1) {
	void* l2 = NULL;
	int64_t l3;
	vader_string_t l4 = 0;
	void** gc_raw_roots[2] = { &l0, &l2 };
	vader_string_t* gc_atom_roots[1] = { &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = (void*) vader_buffer_new((size_t) INT64_C(20));
	l3 = INT64_C(0);
	l3 = std_core$write_int(l2, l3, l1);
	l4 = std_core$finish_buffer(l2, l3);
	toolchain_protocol$write_field(l0, l4);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_ArrayTypeExpr___toolchain_ast_BinaryExpr___toolchain_ast_BlockExpr___toolchain_ast_BoolLitExpr___toolchain_ast_CallExpr___toolchain_ast_CastExpr___toolchain_ast_CharLitExpr___toolchain_ast_DotVariantExpr___toolchain_ast_FallbackExpr___toolchain_ast_FieldExpr___toolchain_ast_FloatLitExpr___toolchain_ast_FnTypeExpr___toolchain_ast_GenericInstExpr___toolchain_ast_IdentExpr___toolchain_ast_IfExpr___toolchain_ast_IndexExpr___toolchain_ast_IntLitExpr___toolchain_ast_IntrinsicCallExpr___toolchain_ast_LambdaExpr___toolchain_ast_MatchExpr___toolchain_ast_NullLitExpr___toolchain_ast_RangeExpr___toolchain_ast_SeqLitExpr___toolchain_ast_StringLitExpr___toolchain_ast_StructLitExpr___toolchain_ast_UnaryExpr(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	int64_t l4, l5;
	vader_box_t l6 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), l6);
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_AssertDecl___toolchain_ast_ConstDecl___toolchain_ast_EnumDecl___toolchain_ast_FnDecl___toolchain_ast_ImplDecl___toolchain_ast_ImportDecl___toolchain_ast_StructDecl___toolchain_ast_TraitDecl___toolchain_ast_TypeAliasDecl(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	int64_t l4, l5;
	vader_box_t l6 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), l6);
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_AssignStmt___toolchain_ast_BreakStmt___toolchain_ast_ContinueStmt___toolchain_ast_DeferStmt___toolchain_ast_DestructureAssignStmt___toolchain_ast_ExprStmt___toolchain_ast_ForStmt___toolchain_ast_LetStmt___toolchain_ast_ReturnStmt___toolchain_ast_YieldStmt(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	int64_t l4, l5;
	vader_box_t l6 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), l6);
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_CallArg(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), vader_ref_box(l6));
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_Decorator(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), vader_ref_box(l6));
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_EnumVariant(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), vader_ref_box(l6));
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_EnumVariantPattern___toolchain_ast_IsPattern___toolchain_ast_LiteralPattern___toolchain_ast_OrPattern___toolchain_ast_RangePattern___toolchain_ast_StructPattern___toolchain_ast_WildcardPattern(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	int64_t l4, l5;
	vader_box_t l6 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), l6);
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_FallbackClause(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), vader_ref_box(l6));
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_FnDecl(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), vader_ref_box(l6));
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_FnParam(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), vader_ref_box(l6));
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_ImportName(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), vader_ref_box(l6));
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_MatchArm(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), vader_ref_box(l6));
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_PlaceTarget___toolchain_ast_RestTarget___toolchain_ast_WildcardTarget(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	int64_t l4, l5;
	vader_box_t l6 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), l6);
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_RestBinding___toolchain_ast_SimpleBinding___toolchain_ast_TupleBinding___toolchain_ast_WildcardBinding(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	int64_t l4, l5;
	vader_box_t l6 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), l6);
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_StringLitInterpolation___toolchain_ast_StringLitText(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	int64_t l4, l5;
	vader_box_t l6 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), l6);
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_StructField(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), vader_ref_box(l6));
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_StructLitField___toolchain_ast_StructLitSpread(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	int64_t l4, l5;
	vader_box_t l6 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), l6);
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_StructPatternField(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), vader_ref_box(l6));
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_StructSpread(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), vader_ref_box(l6));
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_list__toolchain_ast_TypeParam(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l3, l4);
	l3 = l1;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(l0), vader_ref_box(l6));
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_loop_var(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	vader_string_t l3 = 0;
	vader_box_t l4 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l1, &l4 };
	void** gc_raw_roots[3] = { &l0, &l2, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l1.tag == 1207u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$NamedVar_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2966u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$NamedVar_t*) t0)->f_name;
		toolchain_protocol$write_field(l2, l3);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l1.tag == 1167u) {
		toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 2358u);
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$DestructureVar_t*) t0)->f_pattern;
		toolchain_protocol$write_binding(l0, l4);
	} else {
		if (!(l1.tag == 1168u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 2361u);
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_match_arm(void* l0, void* l1) {
	void* l2 = NULL;
	vader_box_t l3 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l3 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$MatchArm_t*) l1)->f_span;
	toolchain_protocol$write_span(l0, l2);
	l3 = ((vader_struct_toolchain_ast$MatchArm_t*) l1)->f_pattern;
	toolchain_protocol$write_pattern(l0, l3);
	l3 = ((vader_struct_toolchain_ast$MatchArm_t*) l1)->f_guard;
	toolchain_protocol$write_optional_expr(l0, l3);
	l3 = ((vader_struct_toolchain_ast$MatchArm_t*) l1)->f_body;
	toolchain_protocol$write_expr(l0, l3);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_match_body(void* l0, void* l1) {
	vader_box_t l2 = vader_box_null();
	void* l3 = NULL;
	void* l4 = NULL;
	bool l5;
	vader_box_t* gc_roots[1] = { &l2 };
	void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$MatchExpr_t*) l1)->f_scrutinee;
	toolchain_protocol$write_expr(l0, l2);
	l3 = ((vader_struct_toolchain_ast$MatchExpr_t*) l1)->f_arms;
	l4 = (void*) &vader_fn_static_toolchain_protocol$write_match_arm;
	toolchain_protocol$write_list__toolchain_ast_MatchArm(l0, l3, l4);
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l5 = ((vader_struct_toolchain_ast$MatchExpr_t*) l1)->f_partial;
	toolchain_protocol$write_flag(l3, l5);
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l5 = ((vader_struct_toolchain_ast$MatchExpr_t*) l1)->f_unreachable;
	toolchain_protocol$write_flag(l3, l5);
	l2 = ((vader_struct_toolchain_ast$MatchExpr_t*) l1)->f_binding;
	toolchain_protocol$write_optional_binding(l0, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_members(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	int64_t l4, l5;
	bool t0;
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &l7 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = l1;
	vader_array_t* _a0_arr = vader_array_new(73u, 0u, 13u, 1181u);
	l3 = (void*) _a0_arr;
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
		t0 = __lambda_toolchain_protocol_2(l6);
		if (t0) {
			l7 = l6;
			vader_array_push_ref((vader_array_t*) l3, l7);
		}
		l5 = (l5 + INT64_C(1));
	}
	l2 = l3;
	l3 = (void*) &vader_fn_static_toolchain_protocol$write_function;
	toolchain_protocol$write_list__toolchain_ast_FnDecl(l0, l2, l3);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_module(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	int64_t l7, l8;
	vader_string_t l9 = 0;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_box_t* gc_roots[1] = { &t1 };
	void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l9 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	t0 = (void*) _a0_arr;
	vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
	vader_obj_header_init(_a1_obj, 1139u);
	_a1_obj->f_parts = t0;
	l3 = (void*) _a1_obj;
	vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 642u);
	l4 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(30u, 0u, 8u, 646u);
	l5 = (void*) _a3_arr;
	vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 645u);
	l6 = (void*) _a4_arr;
	vader_struct_std_collections$Map__string__i64_t* _a5_obj = (vader_struct_std_collections$Map__string__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i64_t));
	vader_obj_header_init(_a5_obj, 1013u);
	_a5_obj->f_ekeys = l4;
	_a5_obj->f_evals = l5;
	_a5_obj->f_index = l6;
	_a5_obj->f_mask = INT64_C(0);
	_a5_obj->f_grow_at = INT64_C(0);
	_a5_obj->f_size = INT64_C(0);
	_a5_obj->f_tombs = INT64_C(0);
	l4 = (void*) _a5_obj;
	vader_struct_toolchain_protocol$DeclWriter_t* _a6_obj = (vader_struct_toolchain_protocol$DeclWriter_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$DeclWriter_t));
	vader_obj_header_init(_a6_obj, 1274u);
	_a6_obj->f_out = l3;
	_a6_obj->f_files = l4;
	l3 = (void*) _a6_obj;
	toolchain_protocol$write_decorators(l3, l1);
	l4 = (void*) &vader_fn_static_toolchain_protocol$write_decl;
	toolchain_protocol$write_list__toolchain_ast_AssertDecl___toolchain_ast_ConstDecl___toolchain_ast_EnumDecl___toolchain_ast_FnDecl___toolchain_ast_ImplDecl___toolchain_ast_ImportDecl___toolchain_ast_StructDecl___toolchain_ast_TraitDecl___toolchain_ast_TypeAliasDecl(l3, l2, l4);
	l4 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l3)->f_files;
	l7 = ((vader_struct_std_collections$Map__string__i64_t*) l4)->f_size;
	if ((INT64_C(0) < l7)) {
		l7 = ((vader_struct_std_collections$Map__string__i64_t*) l4)->f_size;
	} else {
		l7 = INT64_C(0);
	}
	vader_array_t* _a7_arr = vader_array_reserve(28u, (int64_t) l7, 0u, 642u);
	l5 = (void*) _a7_arr;
	l6 = ((vader_struct_std_collections$Map__string__i64_t*) l4)->f_ekeys;
	l7 = INT64_C(0);
	l8 = ((vader_struct_std_collections$Map__string__i64_t*) l4)->f_size;
	while ((l7 < l8)) {
		vader_array_t* _a8_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l7)
		t1 = vader_array_box_slots(_a8_slotarr->buf)[vader_array_offset(_a8_slotarr) + (size_t) l7];
		l9 = t1.payload.s;
		vader_array_push_scalar((vader_array_t*) l5, vader_box_string(642u, l9));
		l7 = (l7 + INT64_C(1));
	}
	toolchain_protocol$write_strings(l0, l5);
	l9 = std_string__builder$StringBuilder$std_core$Display$to_string(((vader_struct_toolchain_protocol$DeclWriter_t*) l3)->f_out);
	std_string__builder$append(l0, l9);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_optional___toolchain_ast_StructLitField___toolchain_ast_StructLitSpread___(void* l0, vader_box_t l1, void* l2) {
	void* l3 = NULL;
	bool l4;
	vader_box_t l5 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l1, &l5 };
	void** gc_raw_roots[3] = { &l0, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = !(l1.tag == 0u);
	toolchain_protocol$write_flag(l3, l4);
	if (l1.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l5 = l1;
	vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
	((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, vader_ref_box(l0), l5);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_optional_binding(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[2] = { &l0, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = (void*) &vader_fn_static_toolchain_protocol$write_simple_binding;
	toolchain_protocol$write_optional___toolchain_ast_StructLitField___toolchain_ast_StructLitSpread___(l0, l1, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_optional_expr(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[2] = { &l0, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = (void*) &vader_fn_static_toolchain_protocol$write_expr;
	toolchain_protocol$write_optional___toolchain_ast_StructLitField___toolchain_ast_StructLitSpread___(l0, l1, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_optional_field(void* l0, vader_box_t l1) {
	bool l2;
	vader_string_t l3 = 0;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[1] = { &l0 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = !(l1.tag == 0u);
	toolchain_protocol$write_flag(l0, l2);
	if (l1.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l3 = l1.payload.s;
	toolchain_protocol$write_field(l0, l3);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_optional_integer(void* l0, vader_box_t l1) {
	bool l2;
	int64_t l3;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[1] = { &l0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = !(l1.tag == 0u);
	toolchain_protocol$write_flag(l0, l2);
	if (l1.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l3 = ((int64_t) l1.payload.i);
	toolchain_protocol$write_integer(l0, l3);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_optional_pattern(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[2] = { &l0, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = (void*) &vader_fn_static_toolchain_protocol$write_pattern;
	toolchain_protocol$write_optional___toolchain_ast_StructLitField___toolchain_ast_StructLitSpread___(l0, l1, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_optional_span(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[2] = { &l0, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = (void*) &vader_fn_static_toolchain_protocol$write_span;
	toolchain_protocol$write_optional___toolchain_ast_StructLitField___toolchain_ast_StructLitSpread___(l0, l1, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_param(void* l0, void* l1) {
	void* l2 = NULL;
	vader_string_t l3 = 0;
	vader_box_t l4 = vader_box_null();
	bool l5;
	vader_box_t* gc_roots[1] = { &l4 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$FnParam_t*) l1)->f_span;
	toolchain_protocol$write_span(l0, l2);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l3 = ((vader_struct_toolchain_ast$FnParam_t*) l1)->f_name;
	toolchain_protocol$write_field(l2, l3);
	l2 = ((vader_struct_toolchain_ast$FnParam_t*) l1)->f_name_span;
	toolchain_protocol$write_span(l0, l2);
	l4 = ((vader_struct_toolchain_ast$FnParam_t*) l1)->f_ty;
	toolchain_protocol$write_optional_expr(l0, l4);
	l4 = ((vader_struct_toolchain_ast$FnParam_t*) l1)->f_default_value;
	toolchain_protocol$write_optional_expr(l0, l4);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l5 = ((vader_struct_toolchain_ast$FnParam_t*) l1)->f_variadic;
	toolchain_protocol$write_flag(l2, l5);
	l2 = ((vader_struct_toolchain_ast$FnParam_t*) l1)->f_decorators;
	toolchain_protocol$write_decorators(l0, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_params(void* l0, void* l1) {
	void* l2 = NULL;
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = (void*) &vader_fn_static_toolchain_protocol$write_param;
	toolchain_protocol$write_list__toolchain_ast_FnParam(l0, l1, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_pattern(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	void* l4 = NULL;
	vader_box_t l3 = vader_box_null();
	vader_string_t l5 = 0;
	bool l6;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l1, &l3 };
	void** gc_raw_roots[4] = { &l0, &l2, &l4, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l5 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l1.tag == 1199u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2791u, l2);
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_ty;
		toolchain_protocol$write_expr(l0, l3);
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$IsPattern_t*) t0)->f_inner;
		toolchain_protocol$write_optional_pattern(l0, l3);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l1.tag == 1229u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$StructPattern_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3290u, l2);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$StructPattern_t*) t0)->f_fields;
		l4 = (void*) &vader_fn_static_toolchain_protocol$write_struct_pattern_field;
		toolchain_protocol$write_list__toolchain_ast_StructPatternField(l0, l2, l4);
	} else if (l1.tag == 1240u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$WildcardPattern_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3774u, l2);
	} else if (l1.tag == 1174u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$EnumVariantPattern_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3718u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l5 = ((vader_struct_toolchain_ast$EnumVariantPattern_t*) t0)->f_variant;
		toolchain_protocol$write_field(l2, l5);
	} else if (l1.tag == 1202u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$LiteralPattern_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2852u, l2);
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$LiteralPattern_t*) t0)->f_value;
		toolchain_protocol$write_expr(l0, l3);
	} else if (l1.tag == 1215u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$RangePattern_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3111u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l6 = ((vader_struct_toolchain_ast$RangePattern_t*) t0)->f_inclusive;
		toolchain_protocol$write_flag(l2, l6);
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$RangePattern_t*) t0)->f_lower;
		toolchain_protocol$write_expr(l0, l3);
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$RangePattern_t*) t0)->f_upper;
		toolchain_protocol$write_expr(l0, l3);
	} else {
		if (!(l1.tag == 1209u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$OrPattern_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3059u, l2);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$OrPattern_t*) t0)->f_patterns;
		l4 = (void*) &vader_fn_static_toolchain_protocol$write_pattern;
		toolchain_protocol$write_list__toolchain_ast_EnumVariantPattern___toolchain_ast_IsPattern___toolchain_ast_LiteralPattern___toolchain_ast_OrPattern___toolchain_ast_RangePattern___toolchain_ast_StructPattern___toolchain_ast_WildcardPattern(l0, l2, l4);
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_pattern_field_value(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	vader_string_t l3 = 0;
	vader_box_t l4 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l1, &l4 };
	void** gc_raw_roots[3] = { &l0, &l2, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l1.tag == 1210u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$PatternBinding_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2092u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$PatternBinding_t*) t0)->f_name;
		toolchain_protocol$write_field(l2, l3);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 2852u);
	t0 = l1.payload.obj;
	l4 = ((vader_struct_toolchain_ast$PatternLiteral_t*) t0)->f_value;
	toolchain_protocol$write_expr(l0, l4);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_place(void* l0, void* l1) {
	int64_t l2;
	int32_t t0;
	void** gc_raw_roots[2] = { &l0, &l1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_span$Position_t*) l1)->f_offset;
	toolchain_protocol$write_integer(l0, l2);
	t0 = ((vader_struct_toolchain_span$Position_t*) l1)->f_line;
	l2 = ((int64_t) (int32_t) t0);
	toolchain_protocol$write_integer(l0, l2);
	t0 = ((vader_struct_toolchain_span$Position_t*) l1)->f_column;
	l2 = ((int64_t) (int32_t) t0);
	toolchain_protocol$write_integer(l0, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_position(void* l0, void* l1) {
	vader_string_t l2 = 0;
	void** gc_raw_roots[2] = { &l0, &l1 };
	vader_string_t* gc_atom_roots[1] = { &l2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_span$Position_t*) l1)->f_file;
	toolchain_protocol$write_field(l0, l2);
	toolchain_protocol$write_place(l0, l1);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_qualifier(void* l0, void* l1) {
	void* l2 = NULL;
	vader_string_t l3 = 0;
	bool l4;
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_span;
	toolchain_protocol$write_span(l0, l2);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l3 = ((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_name;
	toolchain_protocol$write_field(l2, l3);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = ((vader_struct_toolchain_ast$IdentExpr_t*) l1)->f_implicit_dot;
	toolchain_protocol$write_flag(l2, l4);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_simple_binding(void* l0, void* l1) {
	void* l2 = NULL;
	vader_string_t l3 = 0;
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$SimpleBinding_t*) l1)->f_span;
	toolchain_protocol$write_span(l0, l2);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l3 = ((vader_struct_toolchain_ast$SimpleBinding_t*) l1)->f_name;
	toolchain_protocol$write_field(l2, l3);
	l2 = ((vader_struct_toolchain_ast$SimpleBinding_t*) l1)->f_name_span;
	toolchain_protocol$write_span(l0, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_span(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	vader_string_t l4 = 0;
	int64_t l5;
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
	vader_string_t* gc_atom_roots[1] = { &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l3 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_files;
	l4 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) l1)->f_start)->f_file;
	l5 = std_collections$len__string__i64(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_files);
	l5 = std_collections$get_or_put__string__i64(l3, l4, l5);
	toolchain_protocol$write_integer(l2, l5);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l3 = ((vader_struct_toolchain_span$Span_t*) l1)->f_start;
	toolchain_protocol$write_place(l2, l3);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l3 = ((vader_struct_toolchain_span$Span_t*) l1)->f_end;
	toolchain_protocol$write_place(l2, l3);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_span_1(void* l0, void* l1) {
	void* l2 = NULL;
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_span$Span_t*) l1)->f_start;
	toolchain_protocol$write_position(l0, l2);
	l2 = ((vader_struct_toolchain_span$Span_t*) l1)->f_end;
	toolchain_protocol$write_position(l0, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_spread(void* l0, void* l1) {
	void* l2 = NULL;
	vader_box_t l3 = vader_box_null();
	int64_t l4;
	vader_box_t* gc_roots[1] = { &l3 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$StructSpread_t*) l1)->f_span;
	toolchain_protocol$write_span(l0, l2);
	l3 = ((vader_struct_toolchain_ast$StructSpread_t*) l1)->f_base;
	toolchain_protocol$write_expr(l0, l3);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = ((vader_struct_toolchain_ast$StructSpread_t*) l1)->f_at;
	toolchain_protocol$write_integer(l2, l4);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_stmt(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	void* l5 = NULL;
	bool l3;
	vader_box_t l4 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l1, &l4 };
	void** gc_raw_roots[4] = { &l0, &l2, &l5, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l1.tag == 1201u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2840u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_mutable;
		toolchain_protocol$write_flag(l2, l3);
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_binding;
		toolchain_protocol$write_binding(l0, l4);
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_ty;
		toolchain_protocol$write_optional_expr(l0, l4);
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$LetStmt_t*) t0)->f_value;
		toolchain_protocol$write_expr(l0, l4);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l1.tag == 1148u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$AssignStmt_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2075u, l2);
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$AssignStmt_t*) t0)->f_target;
		toolchain_protocol$write_expr(l0, l4);
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$AssignStmt_t*) t0)->f_value;
		toolchain_protocol$write_expr(l0, l4);
	} else if (l1.tag == 1165u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$DestructureAssignStmt_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2358u, l2);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$DestructureAssignStmt_t*) t0)->f_targets;
		l5 = (void*) &vader_fn_static_toolchain_protocol$write_target;
		toolchain_protocol$write_list__toolchain_ast_PlaceTarget___toolchain_ast_RestTarget___toolchain_ast_WildcardTarget(l0, l2, l5);
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$DestructureAssignStmt_t*) t0)->f_value;
		toolchain_protocol$write_expr(l0, l4);
	} else if (l1.tag == 1175u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$ExprStmt_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2488u, l2);
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$ExprStmt_t*) t0)->f_expr;
		toolchain_protocol$write_expr(l0, l4);
	} else if (l1.tag == 1218u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3159u, l2);
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_value;
		toolchain_protocol$write_optional_expr(l0, l4);
	} else if (l1.tag == 1242u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$YieldStmt_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3811u, l2);
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$YieldStmt_t*) t0)->f_value;
		toolchain_protocol$write_expr(l0, l4);
	} else if (l1.tag == 1184u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$ForStmt_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2573u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$ForStmt_t*) t0)->f_label;
		toolchain_protocol$write_optional_field(l2, l4);
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$ForStmt_t*) t0)->f_form;
		toolchain_protocol$write_for_form(l0, l4);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$ForStmt_t*) t0)->f_body;
		toolchain_protocol$write_block(l0, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$ForStmt_t*) t0)->f_is_comptime;
		toolchain_protocol$write_flag(l2, l3);
	} else if (l1.tag == 1152u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$BreakStmt_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2122u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$BreakStmt_t*) t0)->f_label;
		toolchain_protocol$write_optional_field(l2, l4);
	} else if (l1.tag == 1158u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$ContinueStmt_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2312u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$ContinueStmt_t*) t0)->f_label;
		toolchain_protocol$write_optional_field(l2, l4);
	} else {
		if (!(l1.tag == 1163u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$DeferStmt_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2347u, l2);
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$DeferStmt_t*) t0)->f_body;
		toolchain_protocol$write_defer_body(l0, l4);
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_string_part(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	vader_string_t l3 = 0;
	vader_box_t l4 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l1, &l4 };
	void** gc_raw_roots[3] = { &l0, &l2, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l1.tag == 1223u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$StringLitText_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3345u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$StringLitText_t*) t0)->f_value;
		toolchain_protocol$write_field(l2, l3);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	t0 = l1.payload.obj;
	l2 = ((vader_struct_toolchain_ast$StringLitInterpolation_t*) t0)->f_span;
	toolchain_protocol$write_form(l0, 2765u, l2);
	t0 = l1.payload.obj;
	l4 = ((vader_struct_toolchain_ast$StringLitInterpolation_t*) t0)->f_expr;
	toolchain_protocol$write_expr(l0, l4);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_string_parts(void* l0, void* l1) {
	void* l2 = NULL;
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = (void*) &vader_fn_static_toolchain_protocol$write_string_part;
	toolchain_protocol$write_list__toolchain_ast_StringLitInterpolation___toolchain_ast_StringLitText(l0, l1, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_strings(void* l0, void* l1) {
	int64_t l2, l4;
	void* l3 = NULL;
	vader_string_t l5 = 0;
	vader_box_t t0 = vader_box_null();
	vader_box_t* gc_roots[1] = { &t0 };
	void** gc_raw_roots[3] = { &l0, &l1, &l3 };
	vader_string_t* gc_atom_roots[1] = { &l5 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = vader_array_length(((vader_array_t*) l1));
	toolchain_protocol$write_integer(l0, l2);
	l3 = l1;
	l2 = vader_array_length(((vader_array_t*) l3));
	l4 = INT64_C(0);
	while ((l4 < l2)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l4];
		l5 = t0.payload.s;
		toolchain_protocol$write_field(l0, l5);
		l4 = (l4 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_struct(void* l0, void* l1) {
	void* l2 = NULL;
	void* l4 = NULL;
	void* l6 = NULL;
	vader_string_t l3 = 0;
	uint8_t l5;
	vader_box_t l7 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l7 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &l6 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 3290u);
	l2 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_span;
	l3 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_name;
	l4 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_name_span;
	l5 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_visibility;
	l6 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_decorators;
	toolchain_protocol$write_head(l0, l2, l3, l4, l5, l6);
	l2 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_type_params;
	toolchain_protocol$write_type_params(l0, l2);
	l2 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_fields;
	l4 = (void*) &vader_fn_static_toolchain_protocol$write_struct_field;
	toolchain_protocol$write_list__toolchain_ast_StructField(l0, l2, l4);
	l2 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_spreads;
	l4 = (void*) &vader_fn_static_toolchain_protocol$write_spread;
	toolchain_protocol$write_list__toolchain_ast_StructSpread(l0, l2, l4);
	l7 = ((vader_struct_toolchain_ast$StructDecl_t*) l1)->f_decorator_args;
	l2 = (void*) &vader_fn_static_toolchain_protocol$write_call_args;
	toolchain_protocol$write_optional___toolchain_ast_StructLitField___toolchain_ast_StructLitSpread___(l0, l7, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_struct_field(void* l0, void* l1) {
	void* l2 = NULL;
	vader_string_t l3 = 0;
	bool l4;
	vader_box_t l5 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l5 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$StructField_t*) l1)->f_span;
	toolchain_protocol$write_span(l0, l2);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l3 = ((vader_struct_toolchain_ast$StructField_t*) l1)->f_name;
	toolchain_protocol$write_field(l2, l3);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = ((vader_struct_toolchain_ast$StructField_t*) l1)->f_visibility == INT32_C(0);
	toolchain_protocol$write_flag(l2, l4);
	l5 = ((vader_struct_toolchain_ast$StructField_t*) l1)->f_ty;
	toolchain_protocol$write_expr(l0, l5);
	l5 = ((vader_struct_toolchain_ast$StructField_t*) l1)->f_default;
	toolchain_protocol$write_optional_expr(l0, l5);
	l2 = ((vader_struct_toolchain_ast$StructField_t*) l1)->f_decorators;
	toolchain_protocol$write_decorators(l0, l2);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = ((vader_struct_toolchain_ast$StructField_t*) l1)->f_variadic;
	toolchain_protocol$write_flag(l2, l4);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_struct_item(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	vader_string_t l3 = 0;
	vader_box_t l4 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l1, &l4 };
	void** gc_raw_roots[3] = { &l0, &l2, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l1.tag == 1227u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$StructLitField_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 2532u, l2);
		l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$StructLitField_t*) t0)->f_name;
		toolchain_protocol$write_field(l2, l3);
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$StructLitField_t*) t0)->f_name_span;
		toolchain_protocol$write_span(l0, l2);
		t0 = l1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$StructLitField_t*) t0)->f_value;
		toolchain_protocol$write_expr(l0, l4);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	t0 = l1.payload.obj;
	l2 = ((vader_struct_toolchain_ast$StructLitSpread_t*) t0)->f_span;
	toolchain_protocol$write_form(l0, 3222u, l2);
	t0 = l1.payload.obj;
	l4 = ((vader_struct_toolchain_ast$StructLitSpread_t*) t0)->f_expr;
	toolchain_protocol$write_expr(l0, l4);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_struct_items(void* l0, void* l1) {
	void* l2 = NULL;
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = (void*) &vader_fn_static_toolchain_protocol$write_struct_item;
	toolchain_protocol$write_list__toolchain_ast_StructLitField___toolchain_ast_StructLitSpread(l0, l1, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_struct_pattern_field(void* l0, void* l1) {
	void* l2 = NULL;
	vader_string_t l3 = 0;
	vader_box_t l4 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l4 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$StructPatternField_t*) l1)->f_span;
	toolchain_protocol$write_span(l0, l2);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l3 = ((vader_struct_toolchain_ast$StructPatternField_t*) l1)->f_name;
	toolchain_protocol$write_field(l2, l3);
	l2 = ((vader_struct_toolchain_ast$StructPatternField_t*) l1)->f_name_span;
	toolchain_protocol$write_span(l0, l2);
	l4 = ((vader_struct_toolchain_ast$StructPatternField_t*) l1)->f_value;
	toolchain_protocol$write_pattern_field_value(l0, l4);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_target(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	vader_box_t l3 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l1, &l3 };
	void** gc_raw_roots[3] = { &l0, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l1.tag == 1212u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$PlaceTarget_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3092u, l2);
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$PlaceTarget_t*) t0)->f_place;
		toolchain_protocol$write_expr(l0, l3);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l1.tag == 1241u) {
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$WildcardTarget_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3774u, l2);
	} else {
		if (!(l1.tag == 1217u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		t0 = l1.payload.obj;
		l2 = ((vader_struct_toolchain_ast$RestTarget_t*) t0)->f_span;
		toolchain_protocol$write_form(l0, 3149u, l2);
		t0 = l1.payload.obj;
		l3 = ((vader_struct_toolchain_ast$RestTarget_t*) t0)->f_place;
		toolchain_protocol$write_expr(l0, l3);
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_trait(void* l0, void* l1) {
	void* l2 = NULL;
	void* l4 = NULL;
	void* l6 = NULL;
	vader_string_t l3 = 0;
	uint8_t l5;
	vader_box_t l7 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l7 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &l6 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	toolchain_protocol$write_field(((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out, 3412u);
	l2 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_span;
	l3 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_name;
	l4 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_name_span;
	l5 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_visibility;
	l6 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_decorators;
	toolchain_protocol$write_head(l0, l2, l3, l4, l5, l6);
	l2 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_type_params;
	toolchain_protocol$write_type_params(l0, l2);
	l7 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_requires;
	toolchain_protocol$write_optional_expr(l0, l7);
	l2 = ((vader_struct_toolchain_ast$TraitDecl_t*) l1)->f_members;
	toolchain_protocol$write_members(l0, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_type_param(void* l0, void* l1) {
	void* l2 = NULL;
	vader_string_t l3 = 0;
	vader_box_t l4 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l4 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$TypeParam_t*) l1)->f_span;
	toolchain_protocol$write_span(l0, l2);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l3 = ((vader_struct_toolchain_ast$TypeParam_t*) l1)->f_name;
	toolchain_protocol$write_field(l2, l3);
	l4 = ((vader_struct_toolchain_ast$TypeParam_t*) l1)->f_bound;
	toolchain_protocol$write_optional_expr(l0, l4);
	l4 = ((vader_struct_toolchain_ast$TypeParam_t*) l1)->f_default;
	toolchain_protocol$write_optional_expr(l0, l4);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void toolchain_protocol$write_type_params(void* l0, void* l1) {
	void* l2 = NULL;
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = (void*) &vader_fn_static_toolchain_protocol$write_type_param;
	toolchain_protocol$write_list__toolchain_ast_TypeParam(l0, l1, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

void toolchain_protocol$write_variant(void* l0, void* l1) {
	void* l2 = NULL;
	vader_string_t l3 = 0;
	vader_box_t l4 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l4 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$EnumVariant_t*) l1)->f_span;
	toolchain_protocol$write_span(l0, l2);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l3 = ((vader_struct_toolchain_ast$EnumVariant_t*) l1)->f_name;
	toolchain_protocol$write_field(l2, l3);
	l2 = ((vader_struct_toolchain_protocol$DeclWriter_t*) l0)->f_out;
	l4 = ((vader_struct_toolchain_ast$EnumVariant_t*) l1)->f_value;
	toolchain_protocol$write_optional_integer(l2, l4);
	l4 = ((vader_struct_toolchain_ast$EnumVariant_t*) l1)->f_value_span;
	toolchain_protocol$write_optional_span(l0, l4);
	l4 = ((vader_struct_toolchain_ast$EnumVariant_t*) l1)->f_data;
	l2 = (void*) &vader_fn_static_toolchain_protocol$write_struct_items;
	toolchain_protocol$write_optional___toolchain_ast_StructLitField___toolchain_ast_StructLitSpread___(l0, l4, l2);
	l2 = ((vader_struct_toolchain_ast$EnumVariant_t*) l1)->f_decorators;
	toolchain_protocol$write_decorators(l0, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}
