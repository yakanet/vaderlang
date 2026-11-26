#include "bootstrap.split.h"

static bool __lambda_vader_front_comptime_12(void* l0, void* l1);
static bool __lambda_vader_front_comptime_8(void* l0, void* l1);
static void vader_front_comptime$add_dependency(void* l0, void* l1, void* l2, void* l3, void* l4);
static void* vader_front_comptime$arg_error(void* l0, vader_string_t l1);
static vader_box_t vader_front_comptime$argument_value(vader_box_t l0, void* l1, void* l2);
static void* vader_front_comptime$arithmetic(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3);
static void* vader_front_comptime$arithmetic_int(void* l0, vader_box_t l1, vader_box_t l2, void* l3);
static void* vader_front_comptime$arithmetic_or_concat(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3);
static vader_box_t vader_front_comptime$array_literal(void* l0, void* l1);
static uint8_t vader_front_comptime$assert_verdict(vader_box_t l0);
static int64_t vader_front_comptime$bit_not_i64(int64_t l0);
static void* vader_front_comptime$bool_equality_only(void* l0, bool l1, uint8_t l2);
static void* vader_front_comptime$bool_op(void* l0, vader_box_t l1, vader_box_t l2, void* l3);
static vader_box_t vader_front_comptime$bool_value(bool l0);
static vader_box_t vader_front_comptime$build_vm_required(void* l0, void* l1, void* l2, vader_string_t l3);
static void vader_front_comptime$check_extern_symbols(void* l0, void* l1, void* l2, void* l3);
static void vader_front_comptime$check_one_binary_per_name(void* l0, void* l1, void* l2, void* l3);
static void* vader_front_comptime$checked_int(void* l0, void* l1, void* l2, vader_string_t l3);
static vader_box_t vader_front_comptime$checked_int_op(uint8_t l0, int64_t l1, bool l2, int64_t l3, int64_t l4);
static void* vader_front_comptime$checked_result(void* l0, vader_box_t l1, vader_string_t l2);
static void* vader_front_comptime$claimed_twice(vader_string_t l0, void* l1, void* l2, void* l3);
static vader_string_t vader_front_comptime$claimed_twice_fix(void* l0, void* l1);
static void* vader_front_comptime$collect_nodes(void* l0);
static void* vader_front_comptime$combine_binary(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3);
static void* vader_front_comptime$compare(void* l0, vader_box_t l1, vader_box_t l2, uint8_t l3);
static void* vader_front_comptime$complete_struct(void* l0, void* l1, void* l2, void* l3);
static vader_box_t vader_front_comptime$context_declaring(void* l0, void* l1);
static vader_box_t vader_front_comptime$converted_integer(vader_box_t l0, vader_string_t l1);
static void* vader_front_comptime$cycle_closed_by(void* l0, void* l1);
static vader_string_t vader_front_comptime$cycle_names(int64_t l0, void* l1, int64_t l2, void* l3);
static vader_box_t vader_front_comptime$declaring_context(vader_string_t l0, void* l1);
static void* vader_front_comptime$decorator_context(void* l0, void* l1);
static vader_box_t vader_front_comptime$decorator_value(void* l0, void* l1, void* l2);
static uint8_t vader_front_comptime$dependency_step(vader_box_t l0, void* l1, void* l2, void* l3, void* l4);
static void* vader_front_comptime$diag_sink(void);
static void* vader_front_comptime$differing_binary_fields(void* l0, void* l1);
static void* vader_front_comptime$display_enum(void* l0, vader_box_t l1, void* l2);
static vader_string_t vader_front_comptime$display_value(vader_box_t l0);
static void* vader_front_comptime$division_by_zero(void* l0, vader_string_t l1);
static void vader_front_comptime$emit_cycle(int64_t l0, void* l1, void* l2, void* l3, void* l4);
static void vader_front_comptime$evaluate_assert_decls(void* l0, void* l1, void* l2, void* l3);
static void* vader_front_comptime$evaluate_binary_expr(void* l0, void* l1);
static void* vader_front_comptime$evaluate_block_value(void* l0, void* l1, void* l2);
static void* vader_front_comptime$evaluate_bool_lit(void* l0);
static void* vader_front_comptime$evaluate_call_expr(void* l0, void* l1);
static void* vader_front_comptime$evaluate_char_lit(void* l0);
static vader_box_t vader_front_comptime$evaluate_constant_as__std_core_CLibrary(void* l0, void* l1, vader_string_t l2, void* l3, void* l4);
static void* vader_front_comptime$evaluate_declared(void* l0, vader_box_t l1, void* l2);
static void vader_front_comptime$evaluate_decorator_uses(void* l0, void* l1, void* l2);
static void* vader_front_comptime$evaluate_dot_variant(void* l0, void* l1);
static void* vader_front_comptime$evaluate_expr(vader_box_t l0, void* l1);
static void vader_front_comptime$evaluate_extern_interfaces(void* l0, void* l1, void* l2);
static void vader_front_comptime$evaluate_extern_libraries(void* l0, void* l1, void* l2);
static void* vader_front_comptime$evaluate_field(void* l0, void* l1);
static void* vader_front_comptime$evaluate_float_lit(void* l0);
static void* vader_front_comptime$evaluate_fn_body(void* l0, void* l1, void* l2);
static void* vader_front_comptime$evaluate_ident(void* l0, void* l1);
static void* vader_front_comptime$evaluate_if(void* l0, void* l1);
static void* vader_front_comptime$evaluate_int_lit(void* l0, void* l1);
static void* vader_front_comptime$evaluate_intrinsic_call(void* l0, void* l1);
static void* vader_front_comptime$evaluate_match(void* l0, void* l1);
static void vader_front_comptime$evaluate_module_decls(void* l0, void* l1, void* l2, vader_string_t l3, void* l4, void* l5);
static void vader_front_comptime$evaluate_named_constants__std_core_CLibrary(void* l0, void* l1, void* l2, void* l3);
static void* vader_front_comptime$evaluate_null_lit(void* l0);
static vader_box_t vader_front_comptime$evaluate_project_const(void* l0, void* l1, void* l2);
static void* vader_front_comptime$evaluate_seq_lit(void* l0, void* l1);
static void* vader_front_comptime$evaluate_string_lit(void* l0, void* l1);
static void* vader_front_comptime$evaluate_struct_lit(void* l0, void* l1);
static void* vader_front_comptime$evaluate_unary_expr(void* l0, void* l1);
static void* vader_front_comptime$evaluate_with_arguments(void* l0, void* l1, void* l2, void* l3, void* l4);
static void* vader_front_comptime$fail(void* l0);
static vader_box_t vader_front_comptime$fault_of(void* l0);
static double vader_front_comptime$float_arith(uint8_t l0, double l1, double l2);
static bool vader_front_comptime$float_compare(double l0, double l1, uint8_t l2);
static vader_box_t vader_front_comptime$float_val(double l0);
static void vader_front_comptime$fold_plain_constants(void* l0, void* l1, void* l2, void* l3);
static vader_string_t vader_front_comptime$folder_beside(vader_string_t l0, vader_string_t l1);
static bool vader_front_comptime$has_uncomputed_argument(void* l0, void* l1);
static bool vader_front_comptime$has_union_operand(void* l0, void* l1);
static bool vader_front_comptime$holds_struct(vader_box_t l0);
static int64_t vader_front_comptime$int_bits_of(vader_string_t l0);
static bool vader_front_comptime$int_compare(int64_t l0, int64_t l1, uint8_t l2);
static vader_string_t vader_front_comptime$int_digits(void* l0);
static void* vader_front_comptime$int_div_check(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3);
static vader_box_t vader_front_comptime$int_literal(void* l0, void* l1);
static void* vader_front_comptime$int_mod_check(void* l0, vader_box_t l1, vader_box_t l2);
static vader_box_t vader_front_comptime$int_val(int64_t l0);
static vader_string_t vader_front_comptime$interpolation_value(vader_box_t l0);
static void* vader_front_comptime$intrinsic_align_of(void* l0, void* l1);
static void* vader_front_comptime$intrinsic_field_count(void* l0, void* l1);
static void* vader_front_comptime$intrinsic_field_index(void* l0, void* l1);
static void* vader_front_comptime$intrinsic_integer_bound(void* l0, void* l1);
static void* vader_front_comptime$intrinsic_satisfies(void* l0, void* l1);
static void* vader_front_comptime$intrinsic_size_of(void* l0, void* l1);
static void* vader_front_comptime$intrinsic_type_kind(void* l0, void* l1);
static void* vader_front_comptime$intrinsic_type_name(void* l0, void* l1);
static void* vader_front_comptime$intrinsic_variant_count(void* l0, void* l1);
static bool vader_front_comptime$is_arithmetic(uint8_t l0);
static bool vader_front_comptime$is_computed(vader_box_t l0, void* l1);
static bool vader_front_comptime$is_resolved(vader_box_t l0);
static vader_box_t vader_front_comptime$literal_of(vader_box_t l0, void* l1);
static vader_box_t vader_front_comptime$lookup_module_decls(void* l0, vader_string_t l1);
static vader_box_t vader_front_comptime$mask_shift_amount(vader_box_t l0, vader_string_t l1);
static void* vader_front_comptime$module_context(void* l0, void* l1);
static void* vader_front_comptime$new_evaluated_program(void* l0);
static void* vader_front_comptime$new_evaluated_project(void* l0);
static void* vader_front_comptime$normalize_int_result(void* l0, vader_string_t l1);
static bool vader_front_comptime$numbers_of_two_types(vader_box_t l0, vader_box_t l1);
static void* vader_front_comptime$ok(vader_box_t l0);
static int64_t vader_front_comptime$op_div(int64_t l0, int64_t l1);
static bool vader_front_comptime$owns_prototype(void* l0, void* l1);
static vader_string_t vader_front_comptime$path_beside(vader_string_t l0, vader_string_t l1);
static vader_box_t vader_front_comptime$pattern_holds(vader_box_t l0, vader_box_t l1);
static void vader_front_comptime$populate_deps(void* l0, void* l1);
static void vader_front_comptime$record_decorator_value(void* l0, void* l1, void* l2, void* l3);
static vader_string_t vader_front_comptime$render_array(void* l0);
static vader_string_t vader_front_comptime$render_struct(void* l0);
static void vader_front_comptime$report_failure(void* l0, void* l1);
static vader_box_t vader_front_comptime$resolve_type_arg(vader_box_t l0, void* l1);
static vader_string_t vader_front_comptime$resolved_int_name(void* l0, int64_t l1);
static vader_box_t vader_front_comptime$resolved_library(vader_box_t l0, vader_string_t l1);
static vader_string_t vader_front_comptime$result_type_name(void* l0, vader_string_t l1);
static bool vader_front_comptime$runs_an_impl(void* l0, void* l1);
static bool vader_front_comptime$same_kind(vader_box_t l0, vader_box_t l1);
static bool vader_front_comptime$settles_alone(uint8_t l0, vader_box_t l1);
static int64_t vader_front_comptime$shift_amount_mask(vader_string_t l0);
static int64_t vader_front_comptime$sign_extend(int64_t l0, int64_t l1);
static void* vader_front_comptime$sort_comptime_decls(void* l0, void* l1);
static vader_box_t vader_front_comptime$string_field(void* l0, vader_string_t l1);
static vader_box_t vader_front_comptime$string_literal(vader_string_t l0, void* l1);
static vader_box_t vader_front_comptime$strings_field(void* l0, vader_string_t l1);
static void* vader_front_comptime$symbol_span(void* l0, void* l1);
static void* vader_front_comptime$topo_sort(void* l0);
static int64_t vader_front_comptime$type_field_count(vader_box_t l0, void* l1);
static vader_box_t vader_front_comptime$type_from_expr_safe(void* l0, void* l1);
static void* vader_front_comptime$type_mismatch(void* l0, vader_string_t l1);
static vader_box_t vader_front_comptime$type_val(vader_box_t l0);
static int64_t vader_front_comptime$type_variant_count(vader_box_t l0);
static void* vader_front_comptime$unary_bit_not(void* l0, vader_box_t l1);
static void* vader_front_comptime$unary_neg(void* l0, vader_box_t l1, vader_string_t l2);
static void* vader_front_comptime$unary_not(void* l0, vader_box_t l1);
static void* vader_front_comptime$unary_type_mismatch(void* l0, vader_string_t l1);
static void* vader_front_comptime$value_arguments(void* l0, void* l1, void* l2);
static void* vader_front_comptime$variant_equality(void* l0, bool l1, uint8_t l2);
static void* vader_front_comptime$variant_value(void* l0, vader_string_t l1, void* l2);
static void vader_front_comptime$visit(int64_t l0, void* l1, void* l2, void* l3, void* l4, void* l5, void* l6);
static void* vader_front_comptime$vm_required(void* l0, vader_string_t l1);
static void* vader_front_comptime$written_span(void* l0, vader_string_t l1, int64_t l2, bool l3);

vader_box_t vader_fn_tramp___lambda_vader_front_comptime_4(void* env, vader_box_t a0) {
	(void) env;
	return vader_ref_box(__lambda_vader_front_comptime_4(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_comptime_4 = {
	VADER_STATIC_HEADER(608u), (void*) &vader_fn_tramp___lambda_vader_front_comptime_4, NULL,
};

vader_box_t vader_fn_tramp___lambda_vader_front_comptime_7(void* env, vader_box_t a0) {
	(void) env;
	return vader_ref_box(__lambda_vader_front_comptime_7(a0.payload.obj));
}

vader_fn_t vader_fn_static___lambda_vader_front_comptime_7 = {
	VADER_STATIC_HEADER(608u), (void*) &vader_fn_tramp___lambda_vader_front_comptime_7, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_add(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	return vader_box_i64(634u, vader_front_comptime$op_add(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_add = {
	VADER_STATIC_HEADER(562u), (void*) &vader_fn_tramp_vader_front_comptime$op_add, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_and(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	return vader_box_bool(628u, vader_front_comptime$op_and(a0.payload.b, a1.payload.b));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_and = {
	VADER_STATIC_HEADER(547u), (void*) &vader_fn_tramp_vader_front_comptime$op_and, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_bit_and(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	return vader_box_i64(634u, vader_front_comptime$op_bit_and(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_bit_and = {
	VADER_STATIC_HEADER(562u), (void*) &vader_fn_tramp_vader_front_comptime$op_bit_and, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_bit_or(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	return vader_box_i64(634u, vader_front_comptime$op_bit_or(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_bit_or = {
	VADER_STATIC_HEADER(562u), (void*) &vader_fn_tramp_vader_front_comptime$op_bit_or, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_bit_xor(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	return vader_box_i64(634u, vader_front_comptime$op_bit_xor(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_bit_xor = {
	VADER_STATIC_HEADER(562u), (void*) &vader_fn_tramp_vader_front_comptime$op_bit_xor, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_mod(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	return vader_box_i64(634u, vader_front_comptime$op_mod(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_mod = {
	VADER_STATIC_HEADER(562u), (void*) &vader_fn_tramp_vader_front_comptime$op_mod, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_mul(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	return vader_box_i64(634u, vader_front_comptime$op_mul(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_mul = {
	VADER_STATIC_HEADER(562u), (void*) &vader_fn_tramp_vader_front_comptime$op_mul, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_or(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	return vader_box_bool(628u, vader_front_comptime$op_or(a0.payload.b, a1.payload.b));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_or = {
	VADER_STATIC_HEADER(547u), (void*) &vader_fn_tramp_vader_front_comptime$op_or, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_shl(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	return vader_box_i64(634u, vader_front_comptime$op_shl(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_shl = {
	VADER_STATIC_HEADER(562u), (void*) &vader_fn_tramp_vader_front_comptime$op_shl, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_shr(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	return vader_box_i64(634u, vader_front_comptime$op_shr(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_shr = {
	VADER_STATIC_HEADER(562u), (void*) &vader_fn_tramp_vader_front_comptime$op_shr, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$op_sub(void* env, vader_box_t a0, vader_box_t a1) {
	(void) env;
	return vader_box_i64(634u, vader_front_comptime$op_sub(((int64_t) a0.payload.i), ((int64_t) a1.payload.i)));
}

vader_fn_t vader_fn_static_vader_front_comptime$op_sub = {
	VADER_STATIC_HEADER(562u), (void*) &vader_fn_tramp_vader_front_comptime$op_sub, NULL,
};

vader_box_t vader_fn_tramp_vader_front_comptime$resolved_interface(void* env, vader_box_t a0) {
	(void) env;
	return vader_front_comptime$resolved_interface(a0);
}

vader_fn_t vader_fn_static_vader_front_comptime$resolved_interface = {
	VADER_STATIC_HEADER(621u), (void*) &vader_fn_tramp_vader_front_comptime$resolved_interface,
	NULL,
};

vader_box_t vader_fn_lift___lambda_vader_front_comptime_0(void* env, vader_box_t a0) {
	return __lambda_vader_front_comptime_0(env, a0.payload.obj);
}

vader_box_t vader_fn_lift___lambda_vader_front_comptime_10(void* env, vader_box_t a0) {
	return vader_box_i32(635u, (int32_t)(uint32_t) __lambda_vader_front_comptime_10(env, a0));
}

vader_box_t vader_fn_lift___lambda_vader_front_comptime_2(void* env, vader_box_t a0) {
	return __lambda_vader_front_comptime_2(env, a0);
}

vader_box_t vader_fn_lift___lambda_vader_front_comptime_5(void* env, vader_box_t a0) {
	return __lambda_vader_front_comptime_5(env, a0.payload.obj);
}

vader_box_t __lambda_vader_front_comptime_0(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	vader_box_t l5 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l5 };
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct___lambda_env_vader_front_comptime_1_t*) l0)->f_cap_0;
	vader_struct___lambda_env_vader_front_comptime_3_t* _a0_obj = (vader_struct___lambda_env_vader_front_comptime_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_comptime_3_t));
	vader_obj_header_init(_a0_obj, 713u);
	_a0_obj->f_cap_0 = l1;
	t0 = (void*) _a0_obj;
	vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
	vader_obj_header_init(_a1_closure, 623u);
	_a1_closure->code = (void*) &vader_fn_lift___lambda_vader_front_comptime_2;
	_a1_closure->env = t0;
	l3 = (void*) _a1_closure;
	l4 = ((vader_struct___lambda_env_vader_front_comptime_1_t*) l0)->f_cap_1;
	l5 = vader_front_comptime$evaluate_constant_as__std_core_CLibrary(l1, l2, 707u, l3, l4);
	if (l5.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l2 = l5.payload.obj;
	l3 = ((vader_struct___lambda_env_vader_front_comptime_1_t*) l0)->f_cap_2;
	l4 = ((vader_struct___lambda_env_vader_front_comptime_1_t*) l0)->f_cap_1;
	vader_front_comptime$check_one_binary_per_name(l1, l2, l3, l4);
	{ vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
}

uint8_t __lambda_vader_front_comptime_10(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	uint8_t t0;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &l5 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct___lambda_env_vader_front_comptime_11_t*) l0)->f_cap_0;
	l3 = ((vader_struct___lambda_env_vader_front_comptime_11_t*) l0)->f_cap_1;
	l4 = ((vader_struct___lambda_env_vader_front_comptime_11_t*) l0)->f_cap_2;
	l5 = ((vader_struct___lambda_env_vader_front_comptime_11_t*) l0)->f_cap_3;
	t0 = vader_front_comptime$dependency_step(l1, l2, l3, l4, l5);
	{ uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool __lambda_vader_front_comptime_12(void* l0, void* l1) {
	int64_t l2;
	bool t0;
	l2 = ((vader_struct___lambda_env_vader_front_comptime_13_t*) l0)->f_cap_0;
	t0 = vader_support_integer$holds_value(l1, l2);
	return t0;
}

vader_box_t __lambda_vader_front_comptime_2(void* l0, vader_box_t l1) {
	vader_string_t l2 = 0;
	vader_box_t t0 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l1, &t0 };
	void** gc_raw_roots[1] = { &l0 };
	vader_string_t* gc_atom_roots[1] = { &l2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct___lambda_env_vader_front_comptime_3_t*) l0)->f_cap_0)->f_module;
	t0 = vader_front_comptime$resolved_library(l1, l2);
	{ vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_comptime_4(void* l0) {
	return ((vader_struct_vader_front_typecheck$TypedProgram_t*) l0)->f_extern_libraries;
}

vader_box_t __lambda_vader_front_comptime_5(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	vader_box_t t0 = vader_box_null();
	vader_box_t* gc_roots[1] = { &t0 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct___lambda_env_vader_front_comptime_6_t*) l0)->f_cap_0;
	l3 = (void*) &vader_fn_static_vader_front_comptime$resolved_interface;
	l4 = ((vader_struct___lambda_env_vader_front_comptime_6_t*) l0)->f_cap_1;
	t0 = vader_front_comptime$evaluate_constant_as__std_core_CLibrary(l1, l2, 1209u, l3, l4);
	{ vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_comptime_7(void* l0) {
	return ((vader_struct_vader_front_typecheck$TypedProgram_t*) l0)->f_extern_interfaces;
}

static bool __lambda_vader_front_comptime_8(void* l0, void* l1) {
	vader_box_t l2;
	void* l3;
	bool t0;
	if (!(((vader_struct_toolchain_ast$CallArg_t*) l1)->f_comptime_body.tag == 0u)) {
		l2 = ((vader_struct_toolchain_ast$CallArg_t*) l1)->f_value;
		l3 = ((vader_struct___lambda_env_vader_front_comptime_9_t*) l0)->f_cap_0;
		t0 = vader_front_comptime$is_computed(l2, l3);
		return !(t0);
	}
	return false;
}

static void vader_front_comptime$add_dependency(void* l0, void* l1, void* l2, void* l3, void* l4) {
	void* l5 = NULL;
	void* l9 = NULL;
	uint64_t l6;
	vader_box_t l7 = vader_box_null();
	int64_t l8;
	int32_t l10;
	bool t0;
	vader_box_t* gc_roots[1] = { &l7 };
	void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &l9 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l5 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) ((vader_struct_vader_front_typecheck$TypedProgram_t*) l1)->f_resolved)->f_idents;
	l6 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$IdentExpr_t*) l0)->f_span);
	l7 = std_collections$Map$std_core$Index$at__u64__Any(l5, l6);
	if (l7.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l5 = l7.payload.obj;
	if (((vader_struct_vader_core_symbol$Symbol_t*) l5)->f_kind != INT32_C(6)) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l9 = ((vader_struct_vader_front_comptime$Nodes_t*) l2)->f_by_symbol;
	l10 = ((vader_struct_vader_core_symbol$Symbol_t*) l5)->f_id;
	l7 = std_collections$Map$std_core$Index$at__i32__i64(l9, l10);
	if (l7.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l8 = ((int64_t) l7.payload.i);
	t0 = std_collections$add__i64(l3, l8);
	if (t0) {
		vader_array_push_i64((vader_array_t*) ((vader_struct_vader_front_comptime$NodeRecord_t*) l4)->f_dependency_ids, l8);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_comptime$arg_error(void* l0, vader_string_t l1) {
	void* l2 = NULL;
	void* t0 = NULL;
	void* t1 = NULL;
	void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_span;
	t0 = toolchain_diagnostics$comptime_error((uint8_t) 5, l2, l1);
	t1 = vader_front_comptime$fail(t0);
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$argument_value(vader_box_t l0, void* l1, void* l2) {
	void* l3 = NULL;
	vader_box_t l4 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l0, &l4 };
	void** gc_raw_roots[3] = { &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = vader_front_comptime$evaluate_expr(l0, l1);
	l4 = ((vader_struct_vader_front_comptime$EvalResult_t*) l3)->f_value;
	if (l4.tag == 0u) {
		vader_front_comptime$report_failure(l3, l2);
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	{ vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$arithmetic(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3) {
	int64_t l4, l5;
	vader_string_t l6 = 0;
	void* l7 = NULL;
	void* l8 = NULL;
	uint8_t l9;
	double l10, l11;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_box_t* gc_roots[3] = { &l1, &l2, &t1 };
	void** gc_raw_roots[4] = { &l0, &l7, &l8, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l3, &l6 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l1.tag == 1660u) {
		if (l2.tag == 1660u) {
			if (!(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op == INT32_C(3))) {
				l7 = l1.payload.obj;
				l8 = l2.payload.obj;
				t0 = vader_front_comptime$checked_int(l0, l7, l8, l3);
				{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
			}
			t0 = l1.payload.obj;
			l4 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
			t0 = l2.payload.obj;
			l5 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
			l4 = vader_front_comptime$op_div(l4, l5);
			t0 = l1.payload.obj;
			l6 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_type_name;
			t1 = vader_front_comptime$int_val_typed(l4, l6);
			t0 = vader_front_comptime$ok(t1);
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
	}
	if (l1.tag == 1659u) {
		if (l2.tag == 1659u) {
			l9 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op;
			t0 = l1.payload.obj;
			l10 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_value;
			t0 = l2.payload.obj;
			l11 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_value;
			l10 = vader_front_comptime$float_arith(l9, l10, l11);
			t0 = l1.payload.obj;
			l6 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_type_name;
			t1 = vader_front_comptime$float_val_typed(l10, l6);
			t0 = vader_front_comptime$ok(t1);
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l6 = 3018u;
		t0 = vader_front_comptime$type_mismatch(l0, l6);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l6 = 3018u;
	t0 = vader_front_comptime$type_mismatch(l0, l6);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$arithmetic_int(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
	int64_t l4, l5;
	vader_string_t l6 = 0;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_box_t* gc_roots[3] = { &l1, &l2, &t1 };
	void** gc_raw_roots[3] = { &l0, &l3, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l6 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l1.tag == 1660u) {
		if (l2.tag == 1660u) {
			t0 = l1.payload.obj;
			l4 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
			t0 = l2.payload.obj;
			l5 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
			vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
			t1 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i64(634u, l4), vader_box_i64(634u, l5));
			l4 = ((int64_t) t1.payload.i);
			t0 = l1.payload.obj;
			l6 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_type_name;
			t1 = vader_front_comptime$int_val_typed(l4, l6);
			t0 = vader_front_comptime$ok(t1);
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l6 = 3019u;
		t0 = vader_front_comptime$type_mismatch(l0, l6);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l6 = 3019u;
	t0 = vader_front_comptime$type_mismatch(l0, l6);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$arithmetic_or_concat(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3) {
	vader_string_t l4 = 0;
	vader_string_t l5 = 0;
	vader_box_t l6 = vader_box_null();
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[4] = { &l1, &l2, &l6, &t2 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[4] = { &l3, &l4, &l5, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (!(l1.tag == 1666u)) {
		l6 = l1;
		t0 = vader_front_comptime$arithmetic(l0, l6, l2, l3);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l2.tag == 1666u)) {
		t0 = vader_front_comptime$type_mismatch(l0, 3246u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l1.payload.obj;
	l4 = ((vader_struct_vader_front_comptime$StringValue_t*) t0)->f_value;
	t0 = l2.payload.obj;
	l5 = ((vader_struct_vader_front_comptime$StringValue_t*) t0)->f_value;
	t1 = concat_2(l4, l5);
	t2 = vader_front_comptime$string_val(t1);
	t0 = vader_front_comptime$ok(t2);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$array_literal(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	int64_t l4, l5;
	vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
	vader_box_t t0 = vader_box_null();
	void* t1 = NULL;
	vader_box_t* gc_roots[3] = { &l6, &l7, &t0 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(468u, 0u, 13u, 2386u);
	l2 = (void*) _a0_arr;
	l3 = ((vader_struct_vader_front_comptime$ArrayValue_t*) l0)->f_elements;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t0 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
		l6 = vader_front_comptime$literal_of(t0, l1);
		if (l6.tag == 0u) {
			{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
		}
		l7 = l6;
		vader_array_push_ref((vader_array_t*) l2, l7.payload.obj);
		l5 = (l5 + INT64_C(1));
	}
	vader_struct_toolchain_ast$SeqLitExpr_t* _a2_obj = (vader_struct_toolchain_ast$SeqLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$SeqLitExpr_t));
	vader_obj_header_init(_a2_obj, 1200u);
	_a2_obj->f_span = l1;
	_a2_obj->f_id = INT64_C(0);
	_a2_obj->f_elements = l2;
	_a2_obj->f_trailing_comma = false;
	t1 = (void*) _a2_obj;
	{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_front_comptime$assert_verdict(vader_box_t l0) {
	void* t0;
	bool t1;
	if (!(l0.tag == 1649u)) {
		return (uint8_t) 2;
	}
	t0 = l0.payload.obj;
	t1 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
	if (!(t1)) {
		return (uint8_t) 1;
	}
	return (uint8_t) 0;
}

static int64_t vader_front_comptime$bit_not_i64(int64_t l0) {
	return (l0 ^ INT64_C(-1));
}

static void* vader_front_comptime$bool_equality_only(void* l0, bool l1, uint8_t l2) {
	vader_box_t t0 = vader_box_null();
	void* t1 = NULL;
	vader_box_t* gc_roots[1] = { &t0 };
	void** gc_raw_roots[2] = { &l0, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l2 == INT32_C(0)) {
		t0 = vader_front_comptime$bool_value(l1);
		t1 = vader_front_comptime$ok(t0);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l2 == INT32_C(1))) {
		t1 = vader_front_comptime$type_mismatch(l0, 1742u);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = vader_front_comptime$bool_value(!(l1));
	t1 = vader_front_comptime$ok(t0);
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$bool_op(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
	bool l4, l5;
	vader_string_t l6 = 0;
	void* t0 = NULL;
	void* t3 = NULL;
	vader_box_t t1 = vader_box_null();
	bool t2;
	vader_box_t* gc_roots[3] = { &l1, &l2, &t1 };
	void** gc_raw_roots[4] = { &l0, &l3, &t0, &t3 };
	vader_string_t* gc_atom_roots[1] = { &l6 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l1.tag == 1649u) {
		if (l2.tag == 1649u) {
			t0 = l1.payload.obj;
			l4 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
			t0 = l2.payload.obj;
			l5 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
			vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
			t1 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_bool(628u, l4), vader_box_bool(628u, l5));
			t2 = t1.payload.b;
			if (!(t2)) {
				t0 = (void*) &vader_data_35;
				vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
				VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
				t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
				t3 = vader_front_comptime$ok(vader_ref_box(t0));
				{ void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
			}
			t0 = (void*) &vader_data_34;
			vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) INT64_C(0));
			t3 = vader_front_comptime$ok(vader_ref_box(t0));
			{ void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l6 = 2845u;
		t0 = vader_front_comptime$type_mismatch(l0, l6);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l6 = 2845u;
	t0 = vader_front_comptime$type_mismatch(l0, l6);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$bool_value(bool l0) {
	void* t0;
	if (!(l0)) {
		t0 = (void*) &vader_data_35;
		vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
		return vader_ref_box(t0);
	}
	t0 = (void*) &vader_data_34;
	vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
	VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
	t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
	return vader_ref_box(t0);
}

static vader_box_t vader_front_comptime$build_vm_required(void* l0, void* l1, void* l2, vader_string_t l3) {
	vader_box_t l4 = vader_box_null(), l7 = vader_box_null();
	void* l5 = NULL;
	int32_t l6;
	int64_t l8;
	vader_string_t l9 = 0;
	bool l10;
	void* t0 = NULL;
	int64_t t1;
	vader_box_t* gc_roots[2] = { &l4, &l7 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l3, &l9 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l4 = ((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_value;
	if (l4.tag == 1135u) {
		t0 = l4.payload.obj;
		if (((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_callee.tag == 1167u) {
			t0 = l4.payload.obj;
			t1 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_args));
			if (t1 == INT64_C(0)) {
				l5 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) l2)->f_decl_types;
				l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
				l7 = std_collections$Map$std_core$Index$at__i32__Any(l5, l6);
				l5 = vader_front_typecheck$sites_of(((vader_struct_vader_front_typecheck$TypedProgram_t*) l2)->f_call_sites, (uint8_t) 0);
				t0 = l4.payload.obj;
				l8 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_id;
				l4 = std_collections$Map$std_core$Index$at__i64__Any(l5, l8);
				if (!(l7.tag == 0u)) {
					if (l4.tag == 1809u) {
						l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
						l9 = ((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_name;
						t0 = l4.payload.obj;
						l8 = ((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_vader_front_typecheck$DirectFn_t*) t0)->f_decl)->f_id;
						l4 = l7;
						l5 = ((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_span;
						l10 = ((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_comptime_synthetic;
						vader_struct_vader_front_comptime$VmRequiredDecl_t* _a0_obj = (vader_struct_vader_front_comptime$VmRequiredDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$VmRequiredDecl_t));
						vader_obj_header_init(_a0_obj, 1669u);
						_a0_obj->f_symbol_id = l6;
						_a0_obj->f_name = l9;
						_a0_obj->f_module_id = l3;
						_a0_obj->f_callee_decl_id = l8;
						_a0_obj->f_decl_type = l4;
						_a0_obj->f_span = l5;
						_a0_obj->f_read_at_compile_time = l10;
						t0 = (void*) _a0_obj;
						{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
					}
				}
			}
		}
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

int64_t vader_front_comptime$byte_align(vader_box_t l0) {
	int64_t t0;
	t0 = vader_core_types$slot_byte_align(l0);
	return t0;
}

int64_t vader_front_comptime$byte_size(vader_box_t l0) {
	int64_t t0;
	t0 = vader_core_types$slot_byte_size(l0);
	return t0;
}

static void vader_front_comptime$check_extern_symbols(void* l0, void* l1, void* l2, void* l3) {
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l10 = NULL;
	void* l14 = NULL;
	void* l20 = NULL;
	void* l21 = NULL;
	void* l22 = NULL;
	void* l24 = NULL;
	void* l25 = NULL;
	void* l27 = NULL;
	void* l30 = NULL;
	void* l31 = NULL;
	int64_t l8, l9, l11, l12, l16, l28, l29;
	vader_box_t l13 = vader_box_null(), l15 = vader_box_null();
	vader_string_t l17 = 0;
	vader_string_t l18 = 0;
	vader_string_t l19 = 0;
	vader_string_t l23 = 0;
	vader_string_t l26 = 0;
	vader_box_t t0 = vader_box_null();
	vader_string_t t1 = 0;
	void* t2 = NULL;
	bool t3;
	int64_t t4;
	vader_box_t* gc_roots[3] = { &l13, &l15, &t0 };
	void** gc_raw_roots[19] = {
		&l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l10, &l14, &l20, &l21, &l22, &l24, &l25, &l27,
		&l30, &l31, &t2,
	};
	vader_string_t* gc_atom_roots[6] = { &l17, &l18, &l19, &l23, &l26, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 19u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 630u);
	l4 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 641u);
	l5 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 633u);
	l6 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 987u);
	_a3_obj->f_ekeys = l4;
	_a3_obj->f_evals = l5;
	_a3_obj->f_index = l6;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l4 = (void*) _a3_obj;
	l5 = ((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules;
	l6 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l5)->f_ekeys;
	l7 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l5)->f_evals;
	l8 = INT64_C(0);
	l9 = ((vader_struct_std_collections$Map__string__vader_front_resolver_LoadedModule_t*) l5)->f_size;
	while ((l8 < l9)) {
		vader_array_t* _a4_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
		t0 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l8];
		t1 = t0.payload.s;
		vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
		l5 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l8);
		l10 = vader_front_resolver$concat_file_decls(((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l5)->f_module)->f_files);
		l11 = vader_array_length(((vader_array_t*) l10));
		l12 = INT64_C(0);
		while ((l12 < l11)) {
			vader_array_t* _a6_slotarr = ((vader_array_t*) l10);
			VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
			l13 = vader_array_ref_load_box(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l12);
			if (l13.tag == 1162u) {
				t2 = l13.payload.obj;
				if (((vader_struct_toolchain_ast$FnDecl_t*) t2)->f_body.tag == 0u) {
					t2 = l13.payload.obj;
					l15 = toolchain_ast$find_compiler_decorator(((vader_struct_toolchain_ast$FnDecl_t*) t2)->f_decorators, (uint8_t) 14);
					if (l15.tag == 0u) {
						l12 = (l12 + INT64_C(1));
						continue;
					}
					l14 = l15.payload.obj;
					t2 = l13.payload.obj;
					l16 = ((vader_struct_toolchain_ast$FnDecl_t*) t2)->f_id;
					t3 = std_collections$Map$std_core$Contains$contains__i64__Any(l2, l16);
					if (t3) {
						l12 = (l12 + INT64_C(1));
						continue;
					}
					t2 = l13.payload.obj;
					t4 = toolchain_ast$c_variadic_start(t2);
					if ((t4 >= INT64_C(0))) {
						t2 = l13.payload.obj;
						t3 = vader_front_comptime$owns_prototype(t2, l1);
						if (!(t3)) {
							t2 = l13.payload.obj;
							l17 = ((vader_struct_toolchain_ast$FnDecl_t*) t2)->f_name;
							t2 = l13.payload.obj;
							l18 = toolchain_ast$extern_symbol_of(t2);
							l19 = concat_5(1305u, l17, 1516u, l18, 1616u);
							l20 = ((vader_struct_toolchain_ast$Decorator_t*) l14)->f_span;
							l21 = toolchain_diagnostics$comptime_error((uint8_t) 12, l20, l19);
							vader_array_push_ref((vader_array_t*) l3, l21);
						}
					}
					l22 = l13.payload.obj;
					l23 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l5)->f_module)->f_module_name;
					t2 = l13.payload.obj;
					l24 = vader_front_comptime$symbol_span(t2, l14);
					vader_struct_vader_front_comptime$Claim_t* _a7_obj = (vader_struct_vader_front_comptime$Claim_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$Claim_t));
					vader_obj_header_init(_a7_obj, 1651u);
					_a7_obj->f_decl = l22;
					_a7_obj->f_module = l23;
					_a7_obj->f_span = l24;
					l25 = (void*) _a7_obj;
					t2 = l13.payload.obj;
					l26 = toolchain_ast$extern_symbol_of(t2);
					l27 = std_collections$get_or_put__string__vader_front_comptime_Claim(l4, l26, l25);
					l28 = ((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_vader_front_comptime$Claim_t*) l27)->f_decl)->f_id;
					t2 = l13.payload.obj;
					l29 = ((vader_struct_toolchain_ast$FnDecl_t*) t2)->f_id;
					if (l28 == l29) {
						l12 = (l12 + INT64_C(1));
						continue;
					}
					t2 = l13.payload.obj;
					t3 = vader_front_comptime$owns_prototype(t2, l1);
					if (t3) {
						t3 = vader_front_comptime$owns_prototype(((vader_struct_vader_front_comptime$Claim_t*) l27)->f_decl, l1);
						if (!(t3)) {
							std_collections$Map$std_core$IndexSet$set_at__string__Any(l4, l26, vader_ref_box(l25));
							l31 = vader_front_comptime$claimed_twice(l26, l27, l25, l1);
							vader_array_push_ref((vader_array_t*) l3, l31);
						}
					} else {
						l30 = vader_front_comptime$claimed_twice(l26, l25, l27, l1);
						vader_array_push_ref((vader_array_t*) l3, l30);
					}
					l12 = (l12 + INT64_C(1));
					continue;
				}
			}
			l12 = (l12 + INT64_C(1));
		}
		l8 = (l8 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_comptime$check_one_binary_per_name(void* l0, void* l1, void* l2, void* l3) {
	void* l4 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	vader_string_t l5 = 0;
	vader_string_t l9 = 0;
	vader_string_t l10 = 0;
	vader_box_t l6 = vader_box_null();
	vader_string_t t0 = 0;
	int64_t t1;
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8 };
	vader_string_t* gc_atom_roots[4] = { &l5, &l9, &l10, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = ((vader_struct_std_core$CLibrary_t*) l1)->f_name;
	if (t0 == 0u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l5 = ((vader_struct_std_core$CLibrary_t*) l1)->f_name;
	l6 = std_collections$Map$std_core$Index$at__string__Any(l2, l5);
	if (l6.tag == 0u) {
		l5 = ((vader_struct_std_core$CLibrary_t*) l1)->f_name;
		vader_struct_vader_front_comptime$NamedLibrary_t* _a0_obj = (vader_struct_vader_front_comptime$NamedLibrary_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$NamedLibrary_t));
		vader_obj_header_init(_a0_obj, 1661u);
		_a0_obj->f_symbol = l0;
		_a0_obj->f_library = l1;
		l4 = (void*) _a0_obj;
		std_collections$Map$std_core$IndexSet$set_at__string__Any(l2, l5, vader_ref_box(l4));
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l4 = l6.payload.obj;
	l7 = vader_front_comptime$differing_binary_fields(((vader_struct_vader_front_comptime$NamedLibrary_t*) l4)->f_library, l1);
	t1 = vader_array_length(((vader_array_t*) l7));
	if (t1 == INT64_C(0)) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_defined_at;
	if (l6.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l8 = l6.payload.obj;
	l5 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_front_comptime$NamedLibrary_t*) l4)->f_symbol)->f_name;
	l9 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_front_comptime$NamedLibrary_t*) l4)->f_symbol)->f_module_name;
	l5 = concat_5(1305u, l5, 1429u, l9, 1305u);
	l9 = std_string$join(l7, 441u);
	l10 = ((vader_struct_std_core$CLibrary_t*) l1)->f_name;
	l5 = concat_6(1305u, l10, 1451u, l5, 469u, l9);
	l4 = toolchain_diagnostics$comptime_error((uint8_t) 10, l8, l5);
	vader_array_push_ref((vader_array_t*) l3, l4);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_comptime$checked_int(void* l0, void* l1, void* l2, vader_string_t l3) {
	vader_string_t l4 = 0;
	int64_t l5, l8, l9;
	uint8_t l6;
	bool l7;
	vader_box_t l10 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l10 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l3, &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l4 = vader_front_comptime$result_type_name(l1, l3);
	l5 = vader_front_comptime$int_bits_of(l4);
	l6 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op;
	l7 = vader_core_types$is_unsigned_int_name(l4);
	l8 = ((vader_struct_vader_front_comptime$IntValue_t*) l1)->f_value;
	l9 = ((vader_struct_vader_front_comptime$IntValue_t*) l2)->f_value;
	l10 = vader_front_comptime$checked_int_op(l6, l5, l7, l8, l9);
	t0 = vader_front_comptime$checked_result(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, l10, l4);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$checked_int_op(uint8_t l0, int64_t l1, bool l2, int64_t l3, int64_t l4) {
	vader_box_t t0;
	if (l0 == INT32_C(0)) {
		t0 = vader_support_integer$checked_add(l1, l2, l3, l4);
		return t0;
	}
	if (!(l0 == INT32_C(1))) {
		t0 = vader_support_integer$checked_mul(l1, l2, l3, l4);
		return t0;
	}
	t0 = vader_support_integer$checked_sub(l1, l2, l3, l4);
	return t0;
}

static void* vader_front_comptime$checked_result(void* l0, vader_box_t l1, vader_string_t l2) {
	vader_string_t l3 = 0;
	int64_t t0;
	vader_box_t t1 = vader_box_null();
	void* t2 = NULL;
	void* t3 = NULL;
	vader_box_t* gc_roots[2] = { &l1, &t1 };
	void** gc_raw_roots[3] = { &l0, &t2, &t3 };
	vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (!(l1.tag == 0u)) {
		t0 = ((int64_t) l1.payload.i);
		t1 = vader_front_comptime$int_val_typed(t0, l2);
		t2 = vader_front_comptime$ok(t1);
		{ void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = concat_3(3341u, l2, 1305u);
	t2 = toolchain_diagnostics$comptime_error((uint8_t) 8, l0, l3);
	t3 = vader_front_comptime$fail(t2);
	{ void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$claimed_twice(vader_string_t l0, void* l1, void* l2, void* l3) {
	vader_string_t l4 = 0;
	vader_string_t l5 = 0;
	vader_string_t l6 = 0;
	void* l7 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[5] = { &l1, &l2, &l3, &l7, &t0 };
	vader_string_t* gc_atom_roots[4] = { &l0, &l4, &l5, &l6 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l4 = ((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_vader_front_comptime$Claim_t*) l2)->f_decl)->f_name;
	l5 = ((vader_struct_vader_front_comptime$Claim_t*) l2)->f_module;
	l6 = vader_front_comptime$claimed_twice_fix(l2, l3);
	l4 = concat_8(1305u, l0, 1453u, l4, 1429u, l5, 1684u, l6);
	l7 = ((vader_struct_vader_front_comptime$Claim_t*) l1)->f_span;
	t0 = toolchain_diagnostics$comptime_error((uint8_t) 11, l7, l4);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_comptime$claimed_twice_fix(void* l0, void* l1) {
	bool t0;
	void** gc_raw_roots[2] = { &l0, &l1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_front_comptime$owns_prototype(((vader_struct_vader_front_comptime$Claim_t*) l0)->f_decl, l1);
	if (!(t0)) {
		{ vader_gc_top = gc_frame.prev; return 2313u; }
	}
	{ vader_gc_top = gc_frame.prev; return 2936u; }
}

static void* vader_front_comptime$collect_nodes(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	int64_t l6, l7, l9, l12;
	vader_box_t l8 = vader_box_null();
	bool t0;
	vader_box_t* gc_roots[1] = { &l8 };
	void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l10, &l11 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(30u, 0u, 8u, 634u);
	l1 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 641u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 633u);
	l3 = (void*) _a2_arr;
	vader_struct_std_collections$Map__i64__Any_t* _a3_obj = (vader_struct_std_collections$Map__i64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i64__Any_t));
	vader_obj_header_init(_a3_obj, 950u);
	_a3_obj->f_ekeys = l1;
	_a3_obj->f_evals = l2;
	_a3_obj->f_index = l3;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l1 = (void*) _a3_obj;
	vader_array_t* _a4_arr = vader_array_new(30u, 0u, 8u, 634u);
	l2 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(29u, 0u, 7u, 633u);
	l3 = (void*) _a5_arr;
	vader_array_t* _a6_arr = vader_array_new(30u, 0u, 8u, 634u);
	l4 = (void*) _a6_arr;
	vader_array_t* _a7_arr = vader_array_new(29u, 0u, 7u, 633u);
	l5 = (void*) _a7_arr;
	vader_struct_std_collections$Map__i32__i64_t* _a8_obj = (vader_struct_std_collections$Map__i32__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__i64_t));
	vader_obj_header_init(_a8_obj, 907u);
	_a8_obj->f_ekeys = l3;
	_a8_obj->f_evals = l4;
	_a8_obj->f_index = l5;
	_a8_obj->f_mask = INT64_C(0);
	_a8_obj->f_grow_at = INT64_C(0);
	_a8_obj->f_size = INT64_C(0);
	_a8_obj->f_tombs = INT64_C(0);
	l3 = (void*) _a8_obj;
	vader_struct_vader_front_comptime$Nodes_t* _a9_obj = (vader_struct_vader_front_comptime$Nodes_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$Nodes_t));
	vader_obj_header_init(_a9_obj, 1663u);
	_a9_obj->f_by_id = l1;
	_a9_obj->f_order = l2;
	_a9_obj->f_by_symbol = l3;
	l1 = (void*) _a9_obj;
	l2 = l0;
	l6 = vader_array_length(((vader_array_t*) l2));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
		l8 = vader_array_ref_load_box(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l7);
		if (l8.tag == 1138u) {
			l3 = l8.payload.obj;
			t0 = toolchain_ast$is_comptime_const(l3);
			if (t0) {
				vader_array_t* _a11_arr = vader_array_new(30u, 0u, 8u, 634u);
				l4 = (void*) _a11_arr;
				l5 = ((vader_struct_vader_front_comptime$Nodes_t*) l1)->f_by_id;
				l9 = ((vader_struct_toolchain_ast$ConstDecl_t*) l3)->f_id;
				vader_struct_vader_front_comptime$NodeRecord_t* _a12_obj = (vader_struct_vader_front_comptime$NodeRecord_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$NodeRecord_t));
				vader_obj_header_init(_a12_obj, 1662u);
				_a12_obj->f_decl = l3;
				_a12_obj->f_dependency_ids = l4;
				l10 = (void*) _a12_obj;
				std_collections$Map$std_core$IndexSet$set_at__i64__Any(l5, l9, vader_ref_box(l10));
				l11 = ((vader_struct_vader_front_comptime$Nodes_t*) l1)->f_order;
				l12 = ((vader_struct_toolchain_ast$ConstDecl_t*) l3)->f_id;
				vader_array_push_i64((vader_array_t*) l11, l12);
			} else {
				l7 = (l7 + INT64_C(1));
				continue;
			}
		}
		l7 = (l7 + INT64_C(1));
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$combine_binary(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3) {
	uint8_t l4;
	void* l5 = NULL;
	void* l6 = NULL;
	vader_box_t* gc_roots[2] = { &l1, &l2 };
	void** gc_raw_roots[3] = { &l0, &l5, &l6 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l4 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op;
	if (l4 == INT32_C(0)) {
		l5 = vader_front_comptime$arithmetic_or_concat(l0, l1, l2, l3);
		{ void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l4 == INT32_C(1)) {
		l5 = vader_front_comptime$arithmetic(l0, l1, l2, l3);
	} else if (l4 == INT32_C(2)) {
		l5 = vader_front_comptime$arithmetic(l0, l1, l2, l3);
	} else if (l4 == INT32_C(3)) {
		l5 = vader_front_comptime$int_div_check(l0, l1, l2, l3);
	} else if (l4 == INT32_C(4)) {
		l5 = vader_front_comptime$int_mod_check(l0, l1, l2);
	} else if (l4 == INT32_C(5)) {
		l6 = (void*) &vader_fn_static_vader_front_comptime$op_shl;
		l5 = vader_front_comptime$arithmetic_int(l0, l1, l2, l6);
	} else if (l4 == INT32_C(6)) {
		l6 = (void*) &vader_fn_static_vader_front_comptime$op_shr;
		l5 = vader_front_comptime$arithmetic_int(l0, l1, l2, l6);
	} else if (l4 == INT32_C(7)) {
		l6 = (void*) &vader_fn_static_vader_front_comptime$op_bit_and;
		l5 = vader_front_comptime$arithmetic_int(l0, l1, l2, l6);
	} else if (l4 == INT32_C(8)) {
		l6 = (void*) &vader_fn_static_vader_front_comptime$op_bit_or;
		l5 = vader_front_comptime$arithmetic_int(l0, l1, l2, l6);
	} else if (l4 == INT32_C(9)) {
		l6 = (void*) &vader_fn_static_vader_front_comptime$op_bit_xor;
		l5 = vader_front_comptime$arithmetic_int(l0, l1, l2, l6);
	} else if (l4 == INT32_C(10)) {
		l6 = (void*) &vader_fn_static_vader_front_comptime$op_and;
		l5 = vader_front_comptime$bool_op(l0, l1, l2, l6);
	} else if (l4 == INT32_C(11)) {
		l6 = (void*) &vader_fn_static_vader_front_comptime$op_or;
		l5 = vader_front_comptime$bool_op(l0, l1, l2, l6);
	} else if (l4 == INT32_C(12)) {
		l5 = vader_front_comptime$compare(l0, l1, l2, (uint8_t) 0);
	} else if (l4 == INT32_C(13)) {
		l5 = vader_front_comptime$compare(l0, l1, l2, (uint8_t) 1);
	} else if (l4 == INT32_C(14)) {
		l5 = vader_front_comptime$compare(l0, l1, l2, (uint8_t) 2);
	} else if (l4 == INT32_C(15)) {
		l5 = vader_front_comptime$compare(l0, l1, l2, (uint8_t) 3);
	} else if (l4 == INT32_C(16)) {
		l5 = vader_front_comptime$compare(l0, l1, l2, (uint8_t) 4);
	} else if (l4 == INT32_C(17)) {
		l5 = vader_front_comptime$compare(l0, l1, l2, (uint8_t) 5);
	} else if (l4 == INT32_C(18)) {
		l5 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, 683u);
	} else if (l4 == INT32_C(19)) {
		l5 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, 682u);
	} else if (l4 == INT32_C(20)) {
		l5 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, 684u);
	} else if (l4 == INT32_C(21)) {
		l5 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, 686u);
	} else if (l4 == INT32_C(22)) {
		l5 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, 685u);
	} else if (l4 == INT32_C(23)) {
		l6 = (void*) &vader_fn_static_vader_front_comptime$op_add;
		l5 = vader_front_comptime$arithmetic_int(l0, l1, l2, l6);
	} else if (l4 == INT32_C(24)) {
		l6 = (void*) &vader_fn_static_vader_front_comptime$op_sub;
		l5 = vader_front_comptime$arithmetic_int(l0, l1, l2, l6);
	} else {
		if (!(l4 == INT32_C(25))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l6 = (void*) &vader_fn_static_vader_front_comptime$op_mul;
		l5 = vader_front_comptime$arithmetic_int(l0, l1, l2, l6);
	}
	{ void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$compare(void* l0, vader_box_t l1, vader_box_t l2, uint8_t l3) {
	int64_t l4, l5;
	double l6, l7;
	bool l8, l9;
	vader_string_t l10 = 0;
	vader_string_t l11 = 0;
	void* t0 = NULL;
	bool t1;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[3] = { &l1, &l2, &t2 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l10, &l11 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l1.tag == 1660u) {
		if (l2.tag == 1660u) {
			t0 = l1.payload.obj;
			l4 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
			t0 = l2.payload.obj;
			l5 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
			t1 = vader_front_comptime$int_compare(l4, l5, l3);
			t2 = vader_front_comptime$bool_value(t1);
			t0 = vader_front_comptime$ok(t2);
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
	} else if (l1.tag == 1659u) {
		if (l2.tag == 1659u) {
			t0 = l1.payload.obj;
			l6 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_value;
			t0 = l2.payload.obj;
			l7 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_value;
			t1 = vader_front_comptime$float_compare(l6, l7, l3);
			t2 = vader_front_comptime$bool_value(t1);
			t0 = vader_front_comptime$ok(t2);
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
	} else if (l1.tag == 1649u) {
		if (l2.tag == 1649u) {
			t0 = l1.payload.obj;
			l8 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
			t0 = l2.payload.obj;
			l9 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
			l8 = l8 == l9;
			t0 = vader_front_comptime$bool_equality_only(l0, l8, l3);
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
	} else if (l1.tag == 1666u) {
		if (l2.tag == 1666u) {
			t0 = l1.payload.obj;
			l10 = ((vader_struct_vader_front_comptime$StringValue_t*) t0)->f_value;
			t0 = l2.payload.obj;
			l11 = ((vader_struct_vader_front_comptime$StringValue_t*) t0)->f_value;
			t1 = vader_front_comptime$int_compare(((int64_t) (int32_t) vader_string_compare(l10, l11)), INT64_C(0), l3);
			t2 = vader_front_comptime$bool_value(t1);
			t0 = vader_front_comptime$ok(t2);
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
	} else if (l1.tag == 1655u) {
		if (l2.tag == 1655u) {
			t0 = l1.payload.obj;
			l4 = ((vader_struct_vader_front_comptime$EnumValue_t*) t0)->f_value;
			t0 = l2.payload.obj;
			l5 = ((vader_struct_vader_front_comptime$EnumValue_t*) t0)->f_value;
			l8 = l4 == l5;
			t0 = vader_front_comptime$variant_equality(l0, l8, l3);
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
	}
	if (!(l1.tag == 1647u)) {
		if (!(l1.tag == 1667u)) {
			l10 = 2250u;
			t0 = vader_front_comptime$type_mismatch(l0, l10);
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
	}
	t1 = vader_front_comptime$same_kind(l1, l2);
	if (t1) {
		t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, 2249u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l10 = 2250u;
	t0 = vader_front_comptime$type_mismatch(l0, l10);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$complete_struct(void* l0, void* l1, void* l2, void* l3) {
	void* l4 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	void* l13 = NULL;
	void* l14 = NULL;
	void* l16 = NULL;
	int32_t l5;
	vader_box_t l6 = vader_box_null(), l15 = vader_box_null(), l17 = vader_box_null(), l18 = vader_box_null();
	int64_t l9, l10;
	vader_string_t l11 = 0;
	vader_string_t l12 = 0;
	void* t0 = NULL;
	void* t4 = NULL;
	vader_box_t t1 = vader_box_null();
	bool t2;
	vader_string_t t3 = 0;
	vader_box_t* gc_roots[5] = { &l6, &l15, &l17, &l18, &t1 };
	void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8, &l13, &l14, &l16, &t0, &t4 };
	vader_string_t* gc_atom_roots[3] = { &l11, &l12, &t3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 5u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l4 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l3)->f_typed)->f_struct_fields;
	l5 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) l0)->f_symbol)->f_id;
	l6 = std_collections$Map$std_core$Index$at__i32__std_collections_Map_string__vader_front_typecheck_StructFieldInfo_(l4, l5);
	if (l6.tag == 0u) {
		t0 = vader_front_comptime$vm_required(l2, 3264u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = l6.payload.obj;
	l7 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_StructFieldInfo_t*) l4)->f_ekeys;
	l8 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_StructFieldInfo_t*) l4)->f_evals;
	l9 = INT64_C(0);
	l10 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_StructFieldInfo_t*) l4)->f_size;
	while ((l9 < l10)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
		t1 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l9];
		l11 = t1.payload.s;
		vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
		l4 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l9);
		l12 = l11;
		l13 = l4;
		l6 = ((vader_struct_toolchain_ast$StructField_t*) ((vader_struct_vader_front_typecheck$StructFieldInfo_t*) l13)->f_decl)->f_default;
		{
			t2 = std_collections$Map$std_core$Contains$contains__string__Any(l1, l12);
			if (!(t2)) {
				if (!(l6.tag == 0u)) {
					t3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) ((vader_struct_vader_front_typecheck$StructFieldInfo_t*) l13)->f_owner)->f_symbol)->f_module;
					l15 = vader_front_comptime$declaring_context(t3, l3);
					if (l15.tag == 0u) {
						t0 = vader_front_comptime$vm_required(l2, 3265u);
						{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
					}
					l14 = l15.payload.obj;
					l16 = vader_front_comptime$evaluate_expr(l6, l14);
					l18 = ((vader_struct_vader_front_comptime$EvalResult_t*) l16)->f_value;
					if (l18.tag == 0u) {
						{ void* __vret = l16; vader_gc_top = gc_frame.prev; return __vret; }
					}
					l17 = l18;
					std_collections$Map$std_core$IndexSet$set_at__string__Any(l1, l12, l17);
					goto end_51;
				}
			}
		} end_51: ;
		l9 = (l9 + INT64_C(1));
	}
	vader_struct_vader_front_comptime$StructValue_t* _a2_obj = (vader_struct_vader_front_comptime$StructValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$StructValue_t));
	vader_obj_header_init(_a2_obj, 1667u);
	_a2_obj->f_type = vader_ref_box(l0);
	_a2_obj->f_fields = l1;
	t0 = (void*) _a2_obj;
	t4 = vader_front_comptime$ok(vader_ref_box(t0));
	{ void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$context_declaring(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	int64_t l5, l6;
	vader_string_t l7 = 0;
	vader_string_t l8 = 0;
	vader_box_t t0 = vader_box_null();
	vader_box_t* gc_roots[1] = { &t0 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
	vader_string_t* gc_atom_roots[2] = { &l7, &l8 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_front_resolver$decl_symbol(((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_resolved, vader_ref_box(l0));
	if (!(t0.tag == 0u)) {
		{ vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = ((vader_struct_vader_front_typecheck$TypedProject_t*) ((vader_struct_vader_front_comptime$ProjectConstants_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_project)->f_typed)->f_modules;
	l3 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_TypedProgram_t*) l2)->f_ekeys;
	l4 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_TypedProgram_t*) l2)->f_evals;
	l5 = INT64_C(0);
	l6 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_TypedProgram_t*) l2)->f_size;
	while ((l5 < l6)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l5];
		l7 = t0.payload.s;
		vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
		l2 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
		l8 = l7;
		t0 = vader_front_resolver$decl_symbol(((vader_struct_vader_front_typecheck$TypedProgram_t*) l2)->f_resolved, vader_ref_box(l0));
		if (!(t0.tag == 0u)) {
			t0 = vader_front_comptime$declaring_context(l8, l1);
			{ vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_front_comptime$converted_integer(vader_box_t l0, vader_string_t l1) {
	int64_t l2, l6, l7;
	void* l3 = NULL;
	void* l4 = NULL;
	void* l8 = NULL;
	bool l5;
	void* t0 = NULL;
	int64_t t1;
	bool t2;
	vader_box_t* gc_roots[1] = { &l0 };
	void** gc_raw_roots[4] = { &l3, &l4, &l8, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (!(l0.tag == 1660u)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	t0 = l0.payload.obj;
	l2 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
	if (l1 != 2225u) {
		t1 = vader_front_comptime$wrap_to_width(l2, l1);
		vader_struct_vader_front_comptime$IntValue_t* _a0_obj = (vader_struct_vader_front_comptime$IntValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$IntValue_t));
		vader_obj_header_init(_a0_obj, 1660u);
		_a0_obj->f_value = t1;
		_a0_obj->f_type_name = l1;
		t0 = (void*) _a0_obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = (void*) &vader_data_54;
	vader_struct___lambda_env_vader_front_comptime_13_t* _a1_obj = (vader_struct___lambda_env_vader_front_comptime_13_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_comptime_13_t));
	vader_obj_header_init(_a1_obj, 712u);
	_a1_obj->f_cap_0 = l2;
	l4 = (void*) _a1_obj;
	l5 = false;
	l6 = vader_array_length(((vader_array_t*) l3));
	l7 = INT64_C(0);
	{
		while ((l7 < l6)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			l8 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
			t2 = __lambda_vader_front_comptime_12(l4, l8);
			if (t2) {
				l5 = true;
				goto end_34;
			}
			l7 = (l7 + INT64_C(1));
		}
		l5 = false;
	} end_34: ;
	if (!(l5)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	vader_struct_vader_front_comptime$CharValue_t* _a3_obj = (vader_struct_vader_front_comptime$CharValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$CharValue_t));
	vader_obj_header_init(_a3_obj, 1650u);
	_a3_obj->f_value = (uint32_t) (int32_t) ((int32_t) (int64_t) l2);
	t0 = (void*) _a3_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$cycle_closed_by(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	bool l7;
	int32_t l8, l9;
	int64_t t0;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(218u, 0u, 13u, 1467u);
	l2 = (void*) _a0_arr;
	l3 = l0;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
		t0 = vader_array_length(((vader_array_t*) l2));
		if ((t0 > INT64_C(0))) {
			l7 = true;
		} else {
			l8 = ((vader_struct_vader_core_symbol$Symbol_t*) l6)->f_id;
			l9 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
			l7 = l8 == l9;
		}
		if (l7) {
			vader_array_push_ref((vader_array_t*) l2, l6);
		}
		l5 = (l5 + INT64_C(1));
	}
	{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_comptime$cycle_names(int64_t l0, void* l1, int64_t l2, void* l3) {
	void* l4 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	int64_t l5, l6, l9;
	vader_box_t l10 = vader_box_null();
	vader_string_t l11 = 0;
	vader_string_t t0 = 0;
	void* t1 = NULL;
	vader_box_t* gc_roots[1] = { &l10 };
	void** gc_raw_roots[6] = { &l1, &l3, &l4, &l7, &l8, &t1 };
	vader_string_t* gc_atom_roots[2] = { &l11, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 630u);
	l4 = (void*) _a0_arr;
	l5 = l0;
	l6 = vader_array_length(((vader_array_t*) l1));
	while ((l5 < l6)) {
		l8 = ((vader_struct_vader_front_comptime$Nodes_t*) l3)->f_by_id;
		vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
		l9 = ((int64_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l5];
		l10 = std_collections$Map$std_core$Index$at__i64__Any(l8, l9);
		if (l10.tag == 0u) {
			l5 = (l5 + INT64_C(1));
			continue;
		}
		l7 = l10.payload.obj;
		l11 = ((vader_struct_toolchain_ast$ConstDecl_t*) ((vader_struct_vader_front_comptime$NodeRecord_t*) l7)->f_decl)->f_name;
		vader_array_push_scalar((vader_array_t*) l4, vader_box_string(630u, l11));
		l5 = (l5 + INT64_C(1));
	}
	l10 = std_collections$Map$std_core$Index$at__i64__Any(((vader_struct_vader_front_comptime$Nodes_t*) l3)->f_by_id, l2);
	if (l10.tag == 0u) {
		t0 = vader_front_comptime$display_cycle(l4);
		{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = l10.payload.obj;
	l11 = ((vader_struct_toolchain_ast$ConstDecl_t*) ((vader_struct_vader_front_comptime$NodeRecord_t*) t1)->f_decl)->f_name;
	vader_array_push_scalar((vader_array_t*) l4, vader_box_string(630u, l11));
	t0 = vader_front_comptime$display_cycle(l4);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$declaring_context(vader_string_t l0, void* l1) {
	void* l2 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	vader_box_t l3 = vader_box_null();
	int64_t l8;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l3 };
	void** gc_raw_roots[7] = { &l1, &l2, &l4, &l5, &l6, &l7, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_front_typecheck$TypedProject_t*) ((vader_struct_vader_front_comptime$ProjectConstants_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_project)->f_typed)->f_modules, l0);
	if (l3.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l2 = l3.payload.obj;
	l4 = l1;
	vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 633u);
	l5 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 641u);
	l6 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 633u);
	l7 = (void*) _a2_arr;
	vader_struct_std_collections$Map__i32__Any_t* _a3_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
	vader_obj_header_init(_a3_obj, 901u);
	_a3_obj->f_ekeys = l5;
	_a3_obj->f_evals = l6;
	_a3_obj->f_index = l7;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l5 = (void*) _a3_obj;
	l8 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l4)->f_depth;
	l4 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l4)->f_project;
	vader_struct_vader_front_comptime$ComptimeContext_t* _a4_obj = (vader_struct_vader_front_comptime$ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ComptimeContext_t));
	vader_obj_header_init(_a4_obj, 1652u);
	_a4_obj->f_typed = l2;
	_a4_obj->f_bindings = l5;
	_a4_obj->f_depth = l8;
	_a4_obj->f_project = l4;
	t0 = (void*) _a4_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$decorator_context(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l0)->f_typed;
	l3 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l0)->f_comptime_decls;
	vader_struct_vader_front_comptime$ComptimeContext_t* _a0_obj = (vader_struct_vader_front_comptime$ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ComptimeContext_t));
	vader_obj_header_init(_a0_obj, 1652u);
	_a0_obj->f_typed = l2;
	_a0_obj->f_bindings = l3;
	_a0_obj->f_depth = INT64_C(0);
	_a0_obj->f_project = l1;
	t0 = (void*) _a0_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$decorator_value(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l7 = NULL;
	bool l6;
	int64_t l8, l9;
	vader_string_t l10 = 0;
	vader_string_t l12 = 0;
	vader_box_t l11 = vader_box_null(), l13 = vader_box_null(), l14 = vader_box_null();
	vader_box_t t0 = vader_box_null();
	void* t1 = NULL;
	vader_box_t* gc_roots[4] = { &l11, &l13, &l14, &t0 };
	void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l7, &t1 };
	vader_string_t* gc_atom_roots[2] = { &l10, &l12 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 4u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 630u);
	l3 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 641u);
	l4 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 633u);
	l5 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 987u);
	_a3_obj->f_ekeys = l3;
	_a3_obj->f_evals = l4;
	_a3_obj->f_index = l5;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l3 = (void*) _a3_obj;
	l6 = false;
	l4 = ((vader_struct_vader_front_typecheck$DecoratorUse_t*) l0)->f_arguments;
	l5 = ((vader_struct_std_collections$Map__string__toolchain_ast_ArrayTypeExpr___toolchain_ast_BinaryExpr___toolchain_ast_BlockExpr___toolchain_ast_BoolLitExpr___toolchain_ast_CallExpr___toolchain_ast_CastExpr___toolchain_ast_CharLitExpr___toolchain_ast_DotVariantExpr___toolchain_ast_FallbackExpr___toolchain_ast_FieldExpr___toolchain_ast_FloatLitExpr___toolchain_ast_FnTypeExpr___toolchain_ast_GenericInstExpr___toolchain_ast_IdentExpr___toolchain_ast_IfExpr___toolchain_ast_IndexExpr___toolchain_ast_IntLitExpr___toolchain_ast_IntrinsicCallExpr___toolchain_ast_LambdaExpr___toolchain_ast_MatchExpr___toolchain_ast_NullLitExpr___toolchain_ast_RangeExpr___toolchain_ast_SeqLitExpr___toolchain_ast_StringLitExpr___toolchain_ast_StructLitExpr___toolchain_ast_UnaryExpr_t*) l4)->f_ekeys;
	l7 = ((vader_struct_std_collections$Map__string__toolchain_ast_ArrayTypeExpr___toolchain_ast_BinaryExpr___toolchain_ast_BlockExpr___toolchain_ast_BoolLitExpr___toolchain_ast_CallExpr___toolchain_ast_CastExpr___toolchain_ast_CharLitExpr___toolchain_ast_DotVariantExpr___toolchain_ast_FallbackExpr___toolchain_ast_FieldExpr___toolchain_ast_FloatLitExpr___toolchain_ast_FnTypeExpr___toolchain_ast_GenericInstExpr___toolchain_ast_IdentExpr___toolchain_ast_IfExpr___toolchain_ast_IndexExpr___toolchain_ast_IntLitExpr___toolchain_ast_IntrinsicCallExpr___toolchain_ast_LambdaExpr___toolchain_ast_MatchExpr___toolchain_ast_NullLitExpr___toolchain_ast_RangeExpr___toolchain_ast_SeqLitExpr___toolchain_ast_StringLitExpr___toolchain_ast_StructLitExpr___toolchain_ast_UnaryExpr_t*) l4)->f_evals;
	l8 = INT64_C(0);
	l9 = ((vader_struct_std_collections$Map__string__toolchain_ast_ArrayTypeExpr___toolchain_ast_BinaryExpr___toolchain_ast_BlockExpr___toolchain_ast_BoolLitExpr___toolchain_ast_CallExpr___toolchain_ast_CastExpr___toolchain_ast_CharLitExpr___toolchain_ast_DotVariantExpr___toolchain_ast_FallbackExpr___toolchain_ast_FieldExpr___toolchain_ast_FloatLitExpr___toolchain_ast_FnTypeExpr___toolchain_ast_GenericInstExpr___toolchain_ast_IdentExpr___toolchain_ast_IfExpr___toolchain_ast_IndexExpr___toolchain_ast_IntLitExpr___toolchain_ast_IntrinsicCallExpr___toolchain_ast_LambdaExpr___toolchain_ast_MatchExpr___toolchain_ast_NullLitExpr___toolchain_ast_RangeExpr___toolchain_ast_SeqLitExpr___toolchain_ast_StringLitExpr___toolchain_ast_StructLitExpr___toolchain_ast_UnaryExpr_t*) l4)->f_size;
	while ((l8 < l9)) {
		vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l8)
		t0 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l8];
		l10 = t0.payload.s;
		vader_array_t* _a5_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
		l11 = vader_array_ref_load_box(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l8);
		l12 = l10;
		l14 = vader_front_comptime$argument_value(l11, l1, l2);
		if (l14.tag == 0u) {
			l6 = true;
		} else {
			l13 = l14;
			std_collections$Map$std_core$IndexSet$set_at__string__Any(l3, l12, l13);
		}
		l8 = (l8 + INT64_C(1));
	}
	l11 = ((vader_struct_vader_front_typecheck$DecoratorUse_t*) l0)->f_variadic;
	if (!(l11.tag == 0u)) {
		vader_array_t* _a6_arr = vader_array_new(495u, 0u, 13u, 2834u);
		l4 = (void*) _a6_arr;
		t1 = l11.payload.obj;
		l5 = ((vader_struct_vader_front_typecheck$VariadicArguments_t*) t1)->f_elements;
		l8 = vader_array_length(((vader_array_t*) l5));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
			VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
			t0 = vader_array_ref_load_box(_a7_slotarr->buf, vader_array_offset(_a7_slotarr) + (size_t) l9);
			l14 = vader_front_comptime$argument_value(t0, l1, l2);
			if (l14.tag == 0u) {
				l6 = true;
				l9 = (l9 + INT64_C(1));
				continue;
			}
			l13 = l14;
			vader_array_push_ref((vader_array_t*) l4, l13.payload.obj);
			l9 = (l9 + INT64_C(1));
		}
		t1 = l11.payload.obj;
		l10 = ((vader_struct_vader_front_typecheck$VariadicArguments_t*) t1)->f_field;
		t1 = l11.payload.obj;
		l11 = ((vader_struct_vader_front_typecheck$VariadicArguments_t*) t1)->f_type;
		vader_struct_vader_front_comptime$ArrayValue_t* _a8_obj = (vader_struct_vader_front_comptime$ArrayValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ArrayValue_t));
		vader_obj_header_init(_a8_obj, 1647u);
		_a8_obj->f_elements = l4;
		_a8_obj->f_type = l11;
		l4 = (void*) _a8_obj;
		std_collections$Map$std_core$IndexSet$set_at__string__Any(l3, l10, vader_ref_box(l4));
	}
	if (l6) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l4 = ((vader_struct_vader_front_typecheck$DecoratorUse_t*) l0)->f_symbol;
	vader_array_t* _a9_arr = vader_array_new(485u, 0u, 13u, 2618u);
	l5 = (void*) _a9_arr;
	vader_struct_vader_core_types$StructType_t* _a10_obj = (vader_struct_vader_core_types$StructType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$StructType_t));
	vader_obj_header_init(_a10_obj, 1485u);
	_a10_obj->f_symbol = l4;
	_a10_obj->f_args = l5;
	l4 = (void*) _a10_obj;
	l5 = ((vader_struct_toolchain_ast$Decorator_t*) ((vader_struct_vader_front_typecheck$DecoratorUse_t*) l0)->f_written)->f_span;
	l3 = vader_front_comptime$complete_struct(l4, l3, l5, l1);
	l13 = ((vader_struct_vader_front_comptime$EvalResult_t*) l3)->f_value;
	if (l13.tag == 0u) {
		vader_front_comptime$report_failure(l3, l2);
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l11 = l13;
	if (!(l11.tag == 1667u)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	t1 = l11.payload.obj;
	{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_comptime$deliver_decorators(void* l0, vader_box_t l1, void* l2) {
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l10 = NULL;
	void* l12 = NULL;
	void* l13 = NULL;
	void* l16 = NULL;
	void* l17 = NULL;
	void* l20 = NULL;
	void* l21 = NULL;
	void* l22 = NULL;
	void* l23 = NULL;
	void* l24 = NULL;
	void* l25 = NULL;
	void* l26 = NULL;
	int64_t l7, l8, l14;
	vader_string_t l9 = 0;
	vader_string_t l11 = 0;
	vader_box_t l15 = vader_box_null(), l19 = vader_box_null();
	int32_t l18;
	int64_t t0;
	bool t1;
	void* t2 = NULL;
	vader_box_t* gc_roots[3] = { &l1, &l15, &l19 };
	void** gc_raw_roots[19] = {
		&l0, &l2, &l3, &l4, &l5, &l6, &l10, &l12, &l13, &l16, &l17, &l20, &l21, &l22, &l23, &l24,
		&l25, &l26, &t2,
	};
	vader_string_t* gc_atom_roots[2] = { &l9, &l11 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 19u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(285u, 0u, 13u, 1671u);
	l3 = (void*) _a0_arr;
	l4 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) l0)->f_decorator_uses;
	l5 = ((vader_struct_std_collections$Map__i64__vader_front_typecheck_DecoratorUse_t*) l4)->f_ekeys;
	l6 = ((vader_struct_std_collections$Map__i64__vader_front_typecheck_DecoratorUse_t*) l4)->f_evals;
	l7 = INT64_C(0);
	l8 = ((vader_struct_std_collections$Map__i64__vader_front_typecheck_DecoratorUse_t*) l4)->f_size;
	while ((l7 < l8)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
		t0 = ((int64_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l7];
		vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
		l4 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
		l9 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$Decorator_t*) ((vader_struct_vader_front_typecheck$DecoratorUse_t*) l4)->f_written)->f_span)->f_start)->f_file;
		t1 = std_core$$array$Contains$contains__string(l2, l9);
		if (t1) {
			l10 = ((vader_struct_vader_front_typecheck$DecoratorUse_t*) l4)->f_written;
			l11 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_front_typecheck$DecoratorUse_t*) l4)->f_symbol)->f_module_name;
			((vader_struct_toolchain_ast$Decorator_t*) l10)->f_module_name = l11;
			if (!(l1.tag == 0u)) {
				t2 = l1.payload.obj;
				l13 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) t2)->f_decorator_values;
				l14 = ((vader_struct_toolchain_ast$Decorator_t*) ((vader_struct_vader_front_typecheck$DecoratorUse_t*) l4)->f_written)->f_id;
				l15 = std_collections$Map$std_core$Index$at__i64__Any(l13, l14);
				if (!(l15.tag == 0u)) {
					l12 = l15.payload.obj;
					l17 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) l0)->f_struct_fields;
					l18 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_front_typecheck$DecoratorUse_t*) l4)->f_symbol)->f_id;
					l19 = std_collections$Map$std_core$Index$at__i32__std_collections_Map_string__vader_front_typecheck_StructFieldInfo_(l17, l18);
					if (!(l19.tag == 0u)) {
						l16 = l19.payload.obj;
						l20 = ((vader_struct_vader_front_typecheck$DecoratorUse_t*) l4)->f_written;
						l21 = ((vader_struct_toolchain_ast$Decorator_t*) ((vader_struct_vader_front_typecheck$DecoratorUse_t*) l4)->f_written)->f_args;
						vader_struct_vader_front_comptime$WrittenArguments_t* _a3_obj = (vader_struct_vader_front_comptime$WrittenArguments_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$WrittenArguments_t));
						vader_obj_header_init(_a3_obj, 1671u);
						_a3_obj->f_written = l20;
						_a3_obj->f_args = l21;
						l22 = (void*) _a3_obj;
						vader_array_push_ref((vader_array_t*) l3, l22);
						l23 = ((vader_struct_vader_front_typecheck$DecoratorUse_t*) l4)->f_written;
						l24 = ((vader_struct_vader_front_typecheck$DecoratorUse_t*) l4)->f_written;
						l25 = ((vader_struct_vader_front_comptime$DecoratorValue_t*) l12)->f_value;
						l26 = vader_front_comptime$value_arguments(l24, l25, l16);
						((vader_struct_toolchain_ast$Decorator_t*) l23)->f_args = l26;
						VADER_WRITE_BARRIER((vader_struct_toolchain_ast$Decorator_t*) l23);
					}
				}
			}
		}
		l7 = (l7 + INT64_C(1));
	}
	{ void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_front_comptime$dependency_step(vader_box_t l0, void* l1, void* l2, void* l3, void* l4) {
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l0 };
	void** gc_raw_roots[5] = { &l1, &l2, &l3, &l4, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l0.tag == 1167u) {
		t0 = l0.payload.obj;
		vader_front_comptime$add_dependency(t0, l1, l2, l3, l4);
		{ vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
	}
	{ vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
}

static void* vader_front_comptime$diag_sink(void) {
	void* t0 = NULL;
	void** gc_raw_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(92u, 0u, 13u, 1226u);
	t0 = (void*) _a0_arr;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$differing_binary_fields(void* l0, void* l1) {
	void* l2 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	vader_string_t l3 = 0;
	vader_string_t l4 = 0;
	bool t0;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &l6 };
	vader_string_t* gc_atom_roots[2] = { &l3, &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 630u);
	l2 = (void*) _a0_arr;
	l3 = ((vader_struct_std_core$CLibrary_t*) l0)->f_include;
	l4 = ((vader_struct_std_core$CLibrary_t*) l1)->f_include;
	if (l3 != l4) {
		vader_array_push_scalar((vader_array_t*) l2, vader_box_string(630u, 1759u));
	}
	l5 = ((vader_struct_std_core$CLibrary_t*) l0)->f_archives;
	l6 = ((vader_struct_std_core$CLibrary_t*) l1)->f_archives;
	t0 = std_core$content_equals__string(l5, l6);
	if (!(t0)) {
		vader_array_push_scalar((vader_array_t*) l2, vader_box_string(630u, 1741u));
	}
	l5 = ((vader_struct_std_core$CLibrary_t*) l0)->f_system;
	l6 = ((vader_struct_std_core$CLibrary_t*) l1)->f_system;
	t0 = std_core$content_equals__string(l5, l6);
	if (t0) {
		{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_push_scalar((vader_array_t*) l2, vader_box_string(630u, 1769u));
	{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_front_comptime$display_cycle(void* l0) {
	vader_string_t t0;
	t0 = std_string$join(l0, 78u);
	return t0;
}

static void* vader_front_comptime$display_enum(void* l0, vader_box_t l1, void* l2) {
	void* l3 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	void* l9 = NULL;
	void* l10 = NULL;
	int64_t l4;
	vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t* gc_roots[3] = { &l1, &l5, &l6 };
	void** gc_raw_roots[8] = { &l0, &l2, &l3, &l7, &l8, &l9, &l10, &t0 };
	vader_string_t* gc_atom_roots[1] = { &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = vader_front_typecheck$sites_of(((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l2)->f_typed)->f_call_sites, (uint8_t) 7);
	l4 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_id, l1.payload.obj);
	l5 = std_collections$Map$std_core$Index$at__i64__Any(l3, l4);
	if (!(l5.tag == 1809u)) {
		t0 = vader_front_comptime$vm_required(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj), 2403u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$EnumType_t*) ((vader_struct_vader_front_comptime$EnumValue_t*) l0)->f_enum_type)->f_symbol)->f_module;
	l6 = vader_front_comptime$declaring_context(t1, l2);
	if (l6.tag == 0u) {
		t0 = vader_front_comptime$vm_required(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj), 2399u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = l6.payload.obj;
	vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 633u);
	l7 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 641u);
	l8 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 633u);
	l9 = (void*) _a2_arr;
	vader_struct_std_collections$Map__i32__Any_t* _a3_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
	vader_obj_header_init(_a3_obj, 901u);
	_a3_obj->f_ekeys = l7;
	_a3_obj->f_evals = l8;
	_a3_obj->f_index = l9;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l7 = (void*) _a3_obj;
	t0 = l5.payload.obj;
	l8 = ((vader_struct_vader_front_typecheck$DirectFn_t*) t0)->f_decl;
	vader_array_t* _a4_arr = vader_array_new(495u, 1u, 13u, 2834u);
	((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = l0;
	l9 = (void*) _a4_arr;
	l10 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj);
	l3 = vader_front_comptime$evaluate_with_arguments(l8, l9, l7, l3, l10);
	l5 = ((vader_struct_vader_front_comptime$EvalResult_t*) l3)->f_value;
	if (l5.tag == 0u) {
		{ void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l5.tag == 1666u)) {
		t0 = vader_front_comptime$vm_required(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj), 2397u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_comptime$display_value(vader_box_t l0) {
	vader_string_t l1 = 0;
	vader_string_t l2 = 0;
	vader_string_t l3 = 0;
	void* l4 = NULL;
	int64_t l5;
	bool l6;
	void* t0 = NULL;
	double t1;
	uint32_t t2;
	vader_string_t t3 = 0;
	vader_box_t* gc_roots[1] = { &l0 };
	void** gc_raw_roots[2] = { &l4, &t0 };
	vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l3, &t3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l0.tag == 1660u) {
		t0 = l0.payload.obj;
		l1 = vader_front_comptime$int_digits(t0);
		t0 = l0.payload.obj;
		l2 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_type_name;
		l1 = concat_3(l1, 1240u, l2);
		{ vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l0.tag == 1659u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_value;
		l2 = std_core$f64$Display$to_string(t1);
		t0 = l0.payload.obj;
		l3 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_type_name;
		l1 = concat_3(l2, 1240u, l3);
	} else if (l0.tag == 1649u) {
		l4 = (void*) vader_buffer_new((size_t) INT64_C(5));
		l5 = INT64_C(0);
		t0 = l0.payload.obj;
		l6 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
		l5 = std_core$write_bool(l4, l5, l6);
		l1 = std_core$finish_buffer(l4, l5);
	} else if (l0.tag == 1650u) {
		t0 = l0.payload.obj;
		t2 = ((vader_struct_vader_front_comptime$CharValue_t*) t0)->f_value;
		t3 = std_numbers$to_hex((uint64_t) (int64_t) ((int64_t) (uint32_t) t2));
		l2 = std_string$pad_start(t3, INT64_C(4), 48u);
		l1 = concat_3(375u, l2, 358u);
	} else if (l0.tag == 1666u) {
		t0 = l0.payload.obj;
		l2 = ((vader_struct_vader_front_comptime$StringValue_t*) t0)->f_value;
		l1 = concat_3(315u, l2, 315u);
	} else if (l0.tag == 1664u) {
		l1 = 2997u;
	} else if (l0.tag == 1670u) {
		l1 = 3700u;
	} else if (l0.tag == 1647u) {
		t0 = l0.payload.obj;
		l1 = vader_front_comptime$render_array(t0);
	} else if (l0.tag == 1667u) {
		t0 = l0.payload.obj;
		l1 = vader_front_comptime$render_struct(t0);
	} else if (l0.tag == 1668u) {
		t0 = l0.payload.obj;
		l1 = vader_core_types$display_type(((vader_struct_vader_front_comptime$TypeValue_t*) t0)->f_value);
	} else {
		if (!(l0.tag == 1655u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		t0 = l0.payload.obj;
		l2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$EnumType_t*) ((vader_struct_vader_front_comptime$EnumValue_t*) t0)->f_enum_type)->f_symbol)->f_name;
		t0 = l0.payload.obj;
		l3 = ((vader_struct_vader_front_comptime$EnumValue_t*) t0)->f_variant;
		l1 = concat_3(l2, 489u, l3);
	}
	{ vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$division_by_zero(void* l0, vader_string_t l1) {
	void* l2 = NULL;
	void* t0 = NULL;
	void* t1 = NULL;
	void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span;
	t0 = toolchain_diagnostics$comptime_error((uint8_t) 2, l2, l1);
	t1 = vader_front_comptime$fail(t0);
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_comptime$emit_cycle(int64_t l0, void* l1, void* l2, void* l3, void* l4) {
	int64_t l5, l6, l7;
	vader_string_t l8 = 0;
	vader_box_t l9 = vader_box_null();
	void* l10 = NULL;
	int64_t t0;
	void* t1 = NULL;
	vader_box_t* gc_roots[1] = { &l9 };
	void** gc_raw_roots[6] = { &l1, &l2, &l3, &l4, &l10, &t1 };
	vader_string_t* gc_atom_roots[1] = { &l8 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l5 = vader_array_length(((vader_array_t*) l1));
	l6 = l5;
	l7 = INT64_C(0);
	while ((l7 < l5)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l7];
		if (t0 == l0) {
			l6 = l7;
			break;
		}
		l7 = (l7 + INT64_C(1));
	}
	l8 = vader_front_comptime$cycle_names(l6, l1, l0, l2);
	l9 = std_collections$Map$std_core$Index$at__i64__Any(((vader_struct_vader_front_comptime$Nodes_t*) l2)->f_by_id, l0);
	if (!(l9.tag == 0u)) {
		t1 = l9.payload.obj;
		l10 = ((vader_struct_toolchain_ast$ConstDecl_t*) ((vader_struct_vader_front_comptime$NodeRecord_t*) t1)->f_decl)->f_span;
		l10 = toolchain_diagnostics$comptime_error((uint8_t) 4, l10, l8);
		vader_array_push_ref((vader_array_t*) l4, l10);
	}
	while ((l6 < l5)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
		l7 = ((int64_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l6];
		std_collections$add__i64(l3, l7);
		l6 = (l6 + INT64_C(1));
	}
	std_collections$add__i64(l3, l0);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_comptime$evaluate_assert_decls(void* l0, void* l1, void* l2, void* l3) {
	void* l4 = NULL;
	void* l5 = NULL;
	void* l9 = NULL;
	void* l10 = NULL;
	void* l12 = NULL;
	void* l14 = NULL;
	void* l17 = NULL;
	void* l18 = NULL;
	void* l19 = NULL;
	int64_t l6, l7;
	vader_box_t l8 = vader_box_null(), l11 = vader_box_null(), l15 = vader_box_null();
	uint8_t l13;
	vader_string_t l16 = 0;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t* gc_roots[3] = { &l8, &l11, &l15 };
	void** gc_raw_roots[14] = {
		&l0, &l1, &l2, &l3, &l4, &l5, &l9, &l10, &l12, &l14, &l17, &l18, &l19, &t0,
	};
	vader_string_t* gc_atom_roots[2] = { &l16, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l4 = vader_front_comptime$module_context(l1, l2);
	l5 = l0;
	l6 = vader_array_length(((vader_array_t*) l5));
	l7 = INT64_C(0);
	while ((l7 < l6)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
		l8 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l7);
		if (l8.tag == 1128u) {
			l9 = l8.payload.obj;
			l10 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$AssertDecl_t*) l9)->f_condition, l4);
			l11 = ((vader_struct_vader_front_comptime$EvalResult_t*) l10)->f_diag;
			if (!(l11.tag == 0u)) {
				t0 = l11.payload.obj;
				t1 = ((vader_struct_toolchain_diagnostics$CodeInfo_t*) ((vader_struct_toolchain_diagnostics$Diagnostic_t*) t0)->f_code)->f_id;
				if (t1 != 693u) {
					l12 = l11.payload.obj;
					vader_array_push_ref((vader_array_t*) l3, l12);
				}
			}
			l13 = vader_front_comptime$assert_verdict(((vader_struct_vader_front_comptime$EvalResult_t*) l10)->f_value);
			if (l13 == INT32_C(1)) {
				l14 = ((vader_struct_toolchain_ast$AssertDecl_t*) l9)->f_span;
				l15 = ((vader_struct_toolchain_ast$AssertDecl_t*) l9)->f_message;
				if (l15.tag == 0u) {
					l16 = 0u;
				} else {
					l16 = l15.payload.s;
				}
				l17 = toolchain_diagnostics$comptime_error((uint8_t) 6, l14, l16);
				vader_array_push_ref((vader_array_t*) l3, l17);
			}
			l18 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l1)->f_asserts;
			vader_struct_vader_front_comptime$AssertCheck_t* _a1_obj = (vader_struct_vader_front_comptime$AssertCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$AssertCheck_t));
			vader_obj_header_init(_a1_obj, 1648u);
			_a1_obj->f_span = ((vader_struct_toolchain_ast$AssertDecl_t*) l9)->f_span;
			_a1_obj->f_verdict = l13;
			l19 = (void*) _a1_obj;
			vader_array_push_ref((vader_array_t*) l18, l19);
		}
		l7 = (l7 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

void vader_front_comptime$evaluate_awaiting_decorator_uses(void* l0, vader_box_t l1, void* l2) {
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	void* l9 = NULL;
	void* l17 = NULL;
	void* l18 = NULL;
	int64_t l10, l11, l14, l15, l16;
	vader_string_t l12 = 0;
	vader_string_t l13 = 0;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	bool t2;
	vader_box_t* gc_roots[2] = { &l1, &t1 };
	void** gc_raw_roots[12] = { &l0, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l17, &l18, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l12, &l13 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l0)->f_typed;
	vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 633u);
	l4 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 641u);
	l5 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 633u);
	l6 = (void*) _a2_arr;
	vader_struct_std_collections$Map__i32__Any_t* _a3_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
	vader_obj_header_init(_a3_obj, 901u);
	_a3_obj->f_ekeys = l4;
	_a3_obj->f_evals = l5;
	_a3_obj->f_index = l6;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l4 = (void*) _a3_obj;
	vader_array_t* _a4_arr = vader_array_new(218u, 0u, 13u, 1467u);
	l5 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(29u, 0u, 7u, 633u);
	l6 = (void*) _a5_arr;
	vader_array_t* _a6_arr = vader_array_new(26u, 0u, 12u, 628u);
	l7 = (void*) _a6_arr;
	vader_array_t* _a7_arr = vader_array_new(29u, 0u, 7u, 633u);
	l8 = (void*) _a7_arr;
	vader_struct_std_collections$Map__i32__bool_t* _a8_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
	vader_obj_header_init(_a8_obj, 904u);
	_a8_obj->f_ekeys = l6;
	_a8_obj->f_evals = l7;
	_a8_obj->f_index = l8;
	_a8_obj->f_mask = INT64_C(0);
	_a8_obj->f_grow_at = INT64_C(0);
	_a8_obj->f_size = INT64_C(0);
	_a8_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a8_obj;
	vader_struct_std_collections$Set__i32_t* _a9_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
	vader_obj_header_init(_a9_obj, 1089u);
	_a9_obj->f_inner = t0;
	l6 = (void*) _a9_obj;
	vader_array_t* _a10_arr = vader_array_new(29u, 0u, 7u, 633u);
	l7 = (void*) _a10_arr;
	vader_array_t* _a11_arr = vader_array_new(26u, 0u, 12u, 628u);
	l8 = (void*) _a11_arr;
	vader_array_t* _a12_arr = vader_array_new(29u, 0u, 7u, 633u);
	l9 = (void*) _a12_arr;
	vader_struct_std_collections$Map__i32__bool_t* _a13_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
	vader_obj_header_init(_a13_obj, 904u);
	_a13_obj->f_ekeys = l7;
	_a13_obj->f_evals = l8;
	_a13_obj->f_index = l9;
	_a13_obj->f_mask = INT64_C(0);
	_a13_obj->f_grow_at = INT64_C(0);
	_a13_obj->f_size = INT64_C(0);
	_a13_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a13_obj;
	vader_struct_std_collections$Set__i32_t* _a14_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
	vader_obj_header_init(_a14_obj, 1089u);
	_a14_obj->f_inner = t0;
	l7 = (void*) _a14_obj;
	vader_struct_vader_front_comptime$ProjectConstants_t* _a15_obj = (vader_struct_vader_front_comptime$ProjectConstants_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ProjectConstants_t));
	vader_obj_header_init(_a15_obj, 1665u);
	_a15_obj->f_typed = l3;
	_a15_obj->f_values = l4;
	_a15_obj->f_evaluating = l5;
	_a15_obj->f_faulted = l6;
	_a15_obj->f_cycles = l7;
	_a15_obj->f_steps = INT64_C(0);
	l3 = (void*) _a15_obj;
	l4 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l0)->f_modules;
	l5 = ((vader_struct_std_collections$Map__string__vader_front_comptime_EvaluatedProgram_t*) l4)->f_ekeys;
	l6 = ((vader_struct_std_collections$Map__string__vader_front_comptime_EvaluatedProgram_t*) l4)->f_evals;
	l10 = INT64_C(0);
	l11 = ((vader_struct_std_collections$Map__string__vader_front_comptime_EvaluatedProgram_t*) l4)->f_size;
	while ((l10 < l11)) {
		vader_array_t* _a16_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l10)
		t1 = vader_array_box_slots(_a16_slotarr->buf)[vader_array_offset(_a16_slotarr) + (size_t) l10];
		l12 = t1.payload.s;
		vader_array_t* _a17_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l10)
		l4 = vader_array_ref_load_obj(_a17_slotarr->buf, vader_array_offset(_a17_slotarr) + (size_t) l10);
		l13 = l12;
		l7 = l4;
		l14 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l7)->f_awaiting_decorators));
		{
			{
				if (!(l14 == INT64_C(0))) {
					if (!(l1.tag == 0u)) {
						t0 = l1.payload.obj;
						t2 = std_core$$array$Contains$contains__string(t0, l13);
						if (!(t2)) {
							goto end_92;
						}
					}
					l8 = vader_front_comptime$decorator_context(l7, l3);
					l9 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l7)->f_awaiting_decorators;
					l15 = vader_array_length(((vader_array_t*) l9));
					l16 = INT64_C(0);
					while ((l16 < l15)) {
						vader_array_t* _a18_slotarr = ((vader_array_t*) l9);
						VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
						VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l16)
						l17 = vader_array_ref_load_obj(_a18_slotarr->buf, vader_array_offset(_a18_slotarr) + (size_t) l16);
						t2 = vader_front_comptime$has_uncomputed_argument(l17, l7);
						if (!(t2)) {
							vader_front_comptime$record_decorator_value(l7, l17, l8, l2);
						}
						l16 = (l16 + INT64_C(1));
					}
					vader_array_t* _a19_arr = vader_array_new(350u, 0u, 13u, 1805u);
					l18 = (void*) _a19_arr;
					((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l7)->f_awaiting_decorators = l18;
					VADER_WRITE_BARRIER((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l7);
					goto end_91;
				}
			} end_92: ;
		} end_91: ;
		l10 = (l10 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_comptime$evaluate_binary_expr(void* l0, void* l1) {
	void* l2 = NULL;
	vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l7 = vader_box_null();
	int64_t l5;
	vader_string_t l6 = 0;
	bool l8, l9;
	bool t0;
	void* t1 = NULL;
	void* t2 = NULL;
	vader_box_t t3 = vader_box_null();
	vader_box_t* gc_roots[4] = { &l3, &l4, &l7, &t3 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &t1, &t2 };
	vader_string_t* gc_atom_roots[1] = { &l6 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_front_comptime$runs_an_impl(l0, l1);
	if (t0) {
		t1 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, 3026u);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_left, l1);
	l3 = ((vader_struct_vader_front_comptime$EvalResult_t*) l2)->f_value;
	if (l3.tag == 0u) {
		{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = vader_front_comptime$settles_alone(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op, l3);
	if (t0) {
		t1 = l3.payload.obj;
		t2 = vader_front_comptime$ok(vader_ref_box(t1));
		{ void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_right, l1);
	l4 = ((vader_struct_vader_front_comptime$EvalResult_t*) l2)->f_value;
	if (l4.tag == 0u) {
		{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_id;
	l6 = vader_front_comptime$resolved_int_name(l1, l5);
	if (((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op == INT32_C(5)) {
		l8 = true;
	} else {
		l8 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op == INT32_C(6);
	}
	if (l8) {
		l7 = vader_front_comptime$mask_shift_amount(l4, l6);
	} else {
		l7 = l4;
	}
	if (((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op == INT32_C(12)) {
		l8 = true;
	} else {
		l8 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op == INT32_C(13);
	}
	if (l8) {
		l8 = vader_front_comptime$has_union_operand(l1, l0);
		if (l8) {
			t0 = vader_front_comptime$numbers_of_two_types(l3, l7);
			if (t0) {
				t1 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, 2999u);
				{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
			}
		}
		t0 = vader_front_comptime$same_kind(l3, l7);
		l9 = !(t0);
		{
			if (!(l9)) {
				if (!(l3.tag == 1664u)) {
					goto end_103;
				}
			}
			if (l8) {
				l8 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op == INT32_C(13);
				t3 = vader_front_comptime$bool_value(l9 == l8);
				t1 = vader_front_comptime$ok(t3);
				{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
			}
		} end_103: ;
	}
	t1 = vader_front_comptime$combine_binary(l0, l3, l7, l6);
	t2 = vader_front_comptime$normalize_int_result(t1, l6);
	{ void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_block_value(void* l0, void* l1, void* l2) {
	vader_box_t l3 = vader_box_null();
	void* t0 = NULL;
	int64_t t1;
	vader_box_t* gc_roots[1] = { &l3 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_trailing;
	if (l3.tag == 0u) {
		t0 = vader_front_comptime$vm_required(l1, 2081u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l0)->f_stmts));
	if (!((t1 > INT64_C(0)))) {
		t0 = vader_front_comptime$evaluate_expr(l3, l2);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = vader_front_comptime$vm_required(l1, 2082u);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_bool_lit(void* l0) {
	bool t0;
	void* t1 = NULL;
	void* t2 = NULL;
	void** gc_raw_roots[3] = { &l0, &t1, &t2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = ((vader_struct_toolchain_ast$BoolLitExpr_t*) l0)->f_value;
	if (!(t0)) {
		t1 = (void*) &vader_data_35;
		vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t1 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
		t2 = vader_front_comptime$ok(vader_ref_box(t1));
		{ void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = (void*) &vader_data_34;
	vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
	VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
	t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
	t2 = vader_front_comptime$ok(vader_ref_box(t1));
	{ void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_call_expr(void* l0, void* l1) {
	void* l2 = NULL;
	void* l4 = NULL;
	void* l8 = NULL;
	void* l9 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	bool l3;
	vader_box_t l5 = vader_box_null(), l15 = vader_box_null();
	vader_string_t l6 = 0;
	int64_t l7, l10;
	int32_t l13, l14;
	void* t0 = NULL;
	void* t5 = NULL;
	vader_box_t t1 = vader_box_null();
	int64_t t2;
	vader_string_t t3 = 0;
	bool t4;
	vader_box_t* gc_roots[3] = { &l5, &l15, &t1 };
	void** gc_raw_roots[10] = { &l0, &l1, &l2, &l4, &l8, &l9, &l11, &l12, &t0, &t5 };
	vader_string_t* gc_atom_roots[2] = { &l6, &t3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (!(((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_callee.tag == 1167u)) {
		t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_span, 716u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = ((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_callee;
	l2 = t1.payload.obj;
	t2 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_args));
	if (t2 == INT64_C(1)) {
		t3 = ((vader_struct_toolchain_ast$IdentExpr_t*) l2)->f_name;
		t4 = vader_core_types$is_int_name(t3);
		if (t4) {
			l3 = true;
		} else {
			t3 = ((vader_struct_toolchain_ast$IdentExpr_t*) l2)->f_name;
			l3 = t3 == 2225u;
		}
	} else {
		l3 = false;
	}
	if (l3) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_args);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
		l4 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$CallArg_t*) t0)->f_value, l1);
		l5 = ((vader_struct_vader_front_comptime$EvalResult_t*) l4)->f_value;
		if (l5.tag == 0u) {
			{ void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l6 = ((vader_struct_toolchain_ast$IdentExpr_t*) l2)->f_name;
		l5 = vader_front_comptime$converted_integer(l5, l6);
		if (!(l5.tag == 0u)) {
			t0 = vader_front_comptime$ok(l5);
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
	}
	l4 = vader_front_typecheck$sites_of(((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_call_sites, (uint8_t) 0);
	l7 = ((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_id;
	l5 = std_collections$Map$std_core$Index$at__i64__Any(l4, l7);
	if (!(l5.tag == 1809u)) {
		t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_span, 713u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l5.payload.obj;
	if (!(((vader_struct_vader_front_typecheck$DirectFn_t*) t0)->f_bindings.tag == 0u)) {
		t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_span, 715u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l5.payload.obj;
	l4 = ((vader_struct_vader_front_typecheck$DirectFn_t*) t0)->f_decl;
	l5 = vader_front_comptime$context_declaring(l4, l1);
	if (l5.tag == 0u) {
		t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_span, 714u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l8 = l5.payload.obj;
	t4 = toolchain_ast$has_compiler_decorator(((vader_struct_toolchain_ast$FnDecl_t*) l4)->f_decorators, (uint8_t) 21);
	if (t4) {
		l9 = ((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_span;
		l6 = ((vader_struct_toolchain_ast$IdentExpr_t*) l2)->f_name;
		l6 = concat_3(1305u, l6, 1305u);
		t0 = toolchain_diagnostics$comptime_error((uint8_t) 9, l9, l6);
		t5 = vader_front_comptime$fail(t0);
		{ void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l7 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l4)->f_params));
	l10 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_args));
	if (l7 != l10) {
		t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_span, 710u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a1_arr = vader_array_new(29u, 0u, 7u, 633u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(35u, 0u, 0u, 641u);
	l9 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(29u, 0u, 7u, 633u);
	l11 = (void*) _a3_arr;
	vader_struct_std_collections$Map__i32__Any_t* _a4_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
	vader_obj_header_init(_a4_obj, 901u);
	_a4_obj->f_ekeys = l2;
	_a4_obj->f_evals = l9;
	_a4_obj->f_index = l11;
	_a4_obj->f_mask = INT64_C(0);
	_a4_obj->f_grow_at = INT64_C(0);
	_a4_obj->f_size = INT64_C(0);
	_a4_obj->f_tombs = INT64_C(0);
	l2 = (void*) _a4_obj;
	l9 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_bindings;
	l11 = ((vader_struct_std_collections$Map__i32__vader_front_comptime_ArrayValue___vader_front_comptime_BoolValue___vader_front_comptime_CharValue___vader_front_comptime_EnumValue___vader_front_comptime_FloatValue___vader_front_comptime_IntValue___vader_front_comptime_NullValue___vader_front_comptime_StringValue___vader_front_comptime_StructValue___vader_front_comptime_TypeValue___vader_front_comptime_VoidValue_t*) l9)->f_ekeys;
	l12 = ((vader_struct_std_collections$Map__i32__vader_front_comptime_ArrayValue___vader_front_comptime_BoolValue___vader_front_comptime_CharValue___vader_front_comptime_EnumValue___vader_front_comptime_FloatValue___vader_front_comptime_IntValue___vader_front_comptime_NullValue___vader_front_comptime_StringValue___vader_front_comptime_StructValue___vader_front_comptime_TypeValue___vader_front_comptime_VoidValue_t*) l9)->f_evals;
	l7 = INT64_C(0);
	l10 = ((vader_struct_std_collections$Map__i32__vader_front_comptime_ArrayValue___vader_front_comptime_BoolValue___vader_front_comptime_CharValue___vader_front_comptime_EnumValue___vader_front_comptime_FloatValue___vader_front_comptime_IntValue___vader_front_comptime_NullValue___vader_front_comptime_StringValue___vader_front_comptime_StructValue___vader_front_comptime_TypeValue___vader_front_comptime_VoidValue_t*) l9)->f_size;
	while ((l7 < l10)) {
		vader_array_t* _a5_slotarr = ((vader_array_t*) l11);
		VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
		l13 = ((int32_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l7];
		vader_array_t* _a6_slotarr = ((vader_array_t*) l12);
		VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
		l5 = vader_array_ref_load_box(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l7);
		l14 = l13;
		l15 = l5;
		std_collections$Map$std_core$IndexSet$set_at__i32__Any(l2, l14, l15);
		l7 = (l7 + INT64_C(1));
	}
	vader_array_t* _a7_arr = vader_array_new(495u, 0u, 13u, 2834u);
	l9 = (void*) _a7_arr;
	l11 = ((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_args;
	l7 = vader_array_length(((vader_array_t*) l11));
	l10 = INT64_C(0);
	while ((l10 < l7)) {
		vader_array_t* _a8_slotarr = ((vader_array_t*) l11);
		VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l10)
		t0 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l10);
		l12 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$CallArg_t*) t0)->f_value, l1);
		l15 = ((vader_struct_vader_front_comptime$EvalResult_t*) l12)->f_value;
		if (l15.tag == 0u) {
			{ void* __vret = l12; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l5 = l15;
		vader_array_push_ref((vader_array_t*) l9, l5.payload.obj);
		l10 = (l10 + INT64_C(1));
	}
	l11 = ((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_span;
	t0 = vader_front_comptime$evaluate_with_arguments(l4, l9, l2, l8, l11);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_char_lit(void* l0) {
	uint32_t t0;
	void* t1 = NULL;
	void* t2 = NULL;
	void** gc_raw_roots[3] = { &l0, &t1, &t2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = ((vader_struct_toolchain_ast$CharLitExpr_t*) l0)->f_value;
	vader_struct_vader_front_comptime$CharValue_t* _a0_obj = (vader_struct_vader_front_comptime$CharValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$CharValue_t));
	vader_obj_header_init(_a0_obj, 1650u);
	_a0_obj->f_value = t0;
	t1 = (void*) _a0_obj;
	t2 = vader_front_comptime$ok(vader_ref_box(t1));
	{ void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$evaluate_constant_as__std_core_CLibrary(void* l0, void* l1, vader_string_t l2, void* l3, void* l4) {
	void* l5 = NULL;
	void* l8 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	vader_string_t l6 = 0;
	vader_box_t l7 = vader_box_null();
	int32_t l9;
	vader_box_t t0 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l7, &t0 };
	void** gc_raw_roots[9] = { &l0, &l1, &l3, &l4, &l5, &l8, &l10, &l11, &l12 };
	vader_string_t* gc_atom_roots[2] = { &l2, &l6 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l5 = ((vader_struct_vader_front_typecheck$TypedProject_t*) ((vader_struct_vader_front_comptime$ProjectConstants_t*) l1)->f_typed)->f_modules;
	l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_module;
	l7 = std_collections$Map$std_core$Index$at__string__Any(l5, l6);
	if (l7.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l5 = l7.payload.obj;
	l8 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) l5)->f_const_decls;
	l9 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
	l7 = std_collections$Map$std_core$Index$at__i32__Any(l8, l9);
	if (l7.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l8 = l7.payload.obj;
	vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 633u);
	l10 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 641u);
	l11 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 633u);
	l12 = (void*) _a2_arr;
	vader_struct_std_collections$Map__i32__Any_t* _a3_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
	vader_obj_header_init(_a3_obj, 901u);
	_a3_obj->f_ekeys = l10;
	_a3_obj->f_evals = l11;
	_a3_obj->f_index = l12;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l10 = (void*) _a3_obj;
	vader_struct_vader_front_comptime$ComptimeContext_t* _a4_obj = (vader_struct_vader_front_comptime$ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ComptimeContext_t));
	vader_obj_header_init(_a4_obj, 1652u);
	_a4_obj->f_typed = l5;
	_a4_obj->f_bindings = l10;
	_a4_obj->f_depth = INT64_C(0);
	_a4_obj->f_project = l1;
	l5 = (void*) _a4_obj;
	l10 = ((vader_struct_toolchain_ast$ConstDecl_t*) l8)->f_span;
	l7 = vader_front_comptime$evaluate_project_const(l0, l5, l10);
	if (l7.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l5 = l7.payload.obj;
	l7 = ((vader_struct_vader_front_comptime$EvalResult_t*) l5)->f_value;
	if (l7.tag == 0u) {
		if (((vader_struct_vader_front_comptime$EvalResult_t*) l5)->f_diag.tag == 0u) {
			{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
		}
		t0 = ((vader_struct_vader_front_comptime$EvalResult_t*) l5)->f_diag;
		l5 = t0.payload.obj;
		vader_array_push_ref((vader_array_t*) l4, l5);
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	vader_fn_t* _a5_fnobj = (vader_fn_t*) l3;
	l7 = ((vader_fn_erased_sig_1_t) _a5_fnobj->code)(_a5_fnobj->env, l7);
	if (l7.tag == 0u) {
		l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
		l6 = concat_5(1305u, l6, 1424u, l2, 1305u);
		l5 = ((vader_struct_toolchain_ast$ConstDecl_t*) l8)->f_span;
		l5 = toolchain_diagnostics$comptime_error((uint8_t) 0, l5, l6);
		vader_array_push_ref((vader_array_t*) l4, l5);
		{ vader_box_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ vader_box_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_declared(void* l0, vader_box_t l1, void* l2) {
	void* l3 = NULL;
	void* l4 = NULL;
	vader_box_t l5 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l1, &l5 };
	void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l1.tag == 0u) {
		t0 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_value, l2);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = l1.payload.obj;
	l4 = ((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_span;
	l5 = vader_front_comptime$evaluate_project_const(l3, l2, l4);
	if (l5.tag == 0u) {
		t0 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_value, l2);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l5.payload.obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_comptime$evaluate_decorator_uses(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	int64_t l7, l8;
	int64_t t0;
	bool t1;
	void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = vader_front_comptime$decorator_context(l0, l1);
	l4 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l0)->f_typed)->f_decorator_uses;
	l5 = ((vader_struct_std_collections$Map__i64__vader_front_typecheck_DecoratorUse_t*) l4)->f_ekeys;
	l6 = ((vader_struct_std_collections$Map__i64__vader_front_typecheck_DecoratorUse_t*) l4)->f_evals;
	l7 = INT64_C(0);
	l8 = ((vader_struct_std_collections$Map__i64__vader_front_typecheck_DecoratorUse_t*) l4)->f_size;
	while ((l7 < l8)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
		t0 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l7];
		vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
		l4 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l7);
		t1 = vader_front_comptime$has_uncomputed_argument(l4, l0);
		if (t1) {
			vader_array_push_ref((vader_array_t*) ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l0)->f_awaiting_decorators, l4);
		} else {
			vader_front_comptime$record_decorator_value(l0, l4, l3, l2);
		}
		l7 = (l7 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_comptime$evaluate_dot_variant(void* l0, void* l1) {
	vader_box_t l2 = vader_box_null();
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4;
	vader_string_t l5 = 0;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l2 };
	void** gc_raw_roots[5] = { &l0, &l1, &l3, &l6, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l5 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_expr_types;
	l4 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) l0)->f_id;
	l2 = std_collections$Map$std_core$Index$at__i64__Any(l3, l4);
	if (l2.tag == 0u) {
		t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$DotVariantExpr_t*) l0)->f_span, 2401u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l2.tag == 1473u)) {
		t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$DotVariantExpr_t*) l0)->f_span, 3689u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = l2.payload.obj;
	l5 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) l0)->f_variant;
	l6 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) l0)->f_span;
	t0 = vader_front_comptime$variant_value(l3, l5, l6);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_expr(vader_box_t l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	int64_t l4;
	vader_string_t l5 = 0;
	int64_t t0;
	void* t1 = NULL;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l0, &t2 };
	void** gc_raw_roots[4] = { &l1, &l2, &l3, &t1 };
	vader_string_t* gc_atom_roots[1] = { &l5 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_depth;
	if ((t0 >= INT64_C(2000))) {
		l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l0.payload.obj);
		l3 = (void*) vader_buffer_new((size_t) INT64_C(93));
		l4 = INT64_C(0);
		l4 = std_core$write_string_at(l3, l4, 1824u);
		l4 = std_core$write_int(l3, l4, INT64_C(2000));
		l4 = std_core$write_string_at(l3, l4, 226u);
		l5 = std_core$finish_buffer(l3, l4);
		t1 = vader_front_comptime$vm_required(l2, l5);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_into_coercions;
	l4 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_id, l0.payload.obj);
	t2 = std_collections$Map$std_core$Index$at__i64__Any(l2, l4);
	if (!(t2.tag == 0u)) {
		t1 = vader_front_comptime$vm_required(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l0.payload.obj), 1925u);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_depth;
	l4 = vader_chk_add(i64, t0, INT64_C(1));
	((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_depth = l4;
	l2 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_project;
	t0 = ((vader_struct_vader_front_comptime$ProjectConstants_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_project)->f_steps;
	l4 = vader_chk_add(i64, t0, INT64_C(1));
	((vader_struct_vader_front_comptime$ProjectConstants_t*) l2)->f_steps = l4;
	if (l0.tag == 1177u) {
		t1 = l0.payload.obj;
		l2 = vader_front_comptime$evaluate_int_lit(t1, l1);
	} else if (l0.tag == 1161u) {
		t1 = l0.payload.obj;
		l2 = vader_front_comptime$evaluate_float_lit(t1);
	} else if (l0.tag == 1132u) {
		t1 = l0.payload.obj;
		l2 = vader_front_comptime$evaluate_bool_lit(t1);
	} else if (l0.tag == 1137u) {
		t1 = l0.payload.obj;
		l2 = vader_front_comptime$evaluate_char_lit(t1);
	} else if (l0.tag == 1189u) {
		t1 = l0.payload.obj;
		l2 = vader_front_comptime$evaluate_null_lit(t1);
	} else if (l0.tag == 1202u) {
		t1 = l0.payload.obj;
		l2 = vader_front_comptime$evaluate_string_lit(t1, l1);
	} else if (l0.tag == 1167u) {
		t1 = l0.payload.obj;
		l2 = vader_front_comptime$evaluate_ident(t1, l1);
	} else if (l0.tag == 1130u) {
		t1 = l0.payload.obj;
		l2 = vader_front_comptime$evaluate_binary_expr(t1, l1);
	} else if (l0.tag == 1217u) {
		t1 = l0.payload.obj;
		l2 = vader_front_comptime$evaluate_unary_expr(t1, l1);
	} else if (l0.tag == 1178u) {
		t1 = l0.payload.obj;
		l2 = vader_front_comptime$evaluate_intrinsic_call(t1, l1);
	} else if (l0.tag == 1135u) {
		t1 = l0.payload.obj;
		l2 = vader_front_comptime$evaluate_call_expr(t1, l1);
	} else if (l0.tag == 1200u) {
		t1 = l0.payload.obj;
		l2 = vader_front_comptime$evaluate_seq_lit(t1, l1);
	} else if (l0.tag == 1207u) {
		t1 = l0.payload.obj;
		l2 = vader_front_comptime$evaluate_struct_lit(t1, l1);
	} else if (l0.tag == 1152u) {
		t1 = l0.payload.obj;
		l2 = vader_front_comptime$evaluate_dot_variant(t1, l1);
	} else if (l0.tag == 1160u) {
		t1 = l0.payload.obj;
		l2 = vader_front_comptime$evaluate_field(t1, l1);
	} else if (l0.tag == 1185u) {
		t1 = l0.payload.obj;
		l2 = vader_front_comptime$evaluate_match(t1, l1);
	} else if (l0.tag == 1170u) {
		t1 = l0.payload.obj;
		l2 = vader_front_comptime$evaluate_if(t1, l1);
	} else {
		l3 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l0.payload.obj);
		l5 = vader_front_typecheck$expr_kind_name(l0);
		l2 = vader_front_comptime$vm_required(l3, l5);
	}
	t0 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_depth;
	l4 = vader_chk_sub(i64, t0, INT64_C(1));
	((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_depth = l4;
	{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_comptime$evaluate_extern_interfaces(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_struct___lambda_env_vader_front_comptime_6_t* _a0_obj = (vader_struct___lambda_env_vader_front_comptime_6_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_comptime_6_t));
	vader_obj_header_init(_a0_obj, 714u);
	_a0_obj->f_cap_0 = l0;
	_a0_obj->f_cap_1 = l2;
	t0 = (void*) _a0_obj;
	vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
	vader_obj_header_init(_a1_closure, 596u);
	_a1_closure->code = (void*) &vader_fn_lift___lambda_vader_front_comptime_5;
	_a1_closure->env = t0;
	l3 = (void*) _a1_closure;
	l4 = (void*) &vader_fn_static___lambda_vader_front_comptime_7;
	l5 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l1)->f_interfaces;
	vader_front_comptime$evaluate_named_constants__std_core_CLibrary(l0, l4, l3, l5);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_comptime$evaluate_extern_libraries(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 630u);
	l3 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 641u);
	l4 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 633u);
	l5 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 987u);
	_a3_obj->f_ekeys = l3;
	_a3_obj->f_evals = l4;
	_a3_obj->f_index = l5;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l3 = (void*) _a3_obj;
	vader_struct___lambda_env_vader_front_comptime_1_t* _a4_obj = (vader_struct___lambda_env_vader_front_comptime_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_comptime_1_t));
	vader_obj_header_init(_a4_obj, 710u);
	_a4_obj->f_cap_0 = l0;
	_a4_obj->f_cap_1 = l2;
	_a4_obj->f_cap_2 = l3;
	t0 = (void*) _a4_obj;
	vader_fn_t* _a5_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
	vader_obj_header_init(_a5_closure, 598u);
	_a5_closure->code = (void*) &vader_fn_lift___lambda_vader_front_comptime_0;
	_a5_closure->env = t0;
	l3 = (void*) _a5_closure;
	l4 = (void*) &vader_fn_static___lambda_vader_front_comptime_4;
	l5 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l1)->f_libraries;
	vader_front_comptime$evaluate_named_constants__std_core_CLibrary(l0, l4, l3, l5);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_comptime$evaluate_field(void* l0, void* l1) {
	void* l2 = NULL;
	void* l5 = NULL;
	vader_box_t l3 = vader_box_null();
	vader_string_t l4 = 0;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l3, &t1 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$FieldExpr_t*) l0)->f_target, l1);
	l3 = ((vader_struct_vader_front_comptime$EvalResult_t*) l2)->f_value;
	if (l3.tag == 0u) {
		{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l3.tag == 1668u) {
		t0 = l3.payload.obj;
		if (!(((vader_struct_vader_front_comptime$TypeValue_t*) t0)->f_value.tag == 1473u)) {
			t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$FieldExpr_t*) l0)->f_span, 2517u);
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
		t0 = l3.payload.obj;
		t1 = ((vader_struct_vader_front_comptime$TypeValue_t*) t0)->f_value;
		l2 = t1.payload.obj;
		l4 = ((vader_struct_toolchain_ast$FieldExpr_t*) l0)->f_field;
		l5 = ((vader_struct_toolchain_ast$FieldExpr_t*) l0)->f_span;
		t0 = vader_front_comptime$variant_value(l2, l4, l5);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l3.tag == 1667u)) {
		t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$FieldExpr_t*) l0)->f_span, 2518u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l3.payload.obj;
	l2 = ((vader_struct_vader_front_comptime$StructValue_t*) t0)->f_fields;
	l4 = ((vader_struct_toolchain_ast$FieldExpr_t*) l0)->f_field;
	l3 = std_collections$Map$std_core$Index$at__string__Any(l2, l4);
	if (l3.tag == 0u) {
		t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$FieldExpr_t*) l0)->f_span, 3477u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = vader_front_comptime$ok(l3);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_float_lit(void* l0) {
	double t0;
	vader_box_t t1 = vader_box_null();
	void* t2 = NULL;
	vader_box_t* gc_roots[1] = { &t1 };
	void** gc_raw_roots[2] = { &l0, &t2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = ((vader_struct_toolchain_ast$FloatLitExpr_t*) l0)->f_value;
	t1 = vader_front_comptime$float_val(t0);
	t2 = vader_front_comptime$ok(t1);
	{ void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_fn_body(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	int64_t l4;
	vader_string_t l5 = 0;
	vader_box_t l6 = vader_box_null();
	bool t0;
	void* t1 = NULL;
	void* t2 = NULL;
	int64_t t3;
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &t1, &t2 };
	vader_string_t* gc_atom_roots[1] = { &l5 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_resolved)->f_late_bodies;
	l4 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_id;
	t0 = std_collections$Set$std_core$Contains$contains__i64(l3, l4);
	if (t0) {
		l5 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
		l5 = concat_3(1305u, l5, 1305u);
		t1 = toolchain_diagnostics$comptime_error((uint8_t) 13, l2, l5);
		t2 = vader_front_comptime$fail(t1);
		{ void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l6 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_body;
	if (l6.tag == 0u) {
		t1 = vader_front_comptime$vm_required(l2, 712u);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = l6.payload.obj;
	if (!(((vader_struct_toolchain_ast$BlockExpr_t*) l3)->f_trailing.tag == 0u)) {
		t1 = vader_front_comptime$evaluate_block_value(l3, l2, l1);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t3 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l3)->f_stmts));
	if (t3 == INT64_C(1)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l3)->f_stmts);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
		l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
		if (l6.tag == 1199u) {
			t1 = l6.payload.obj;
			if (!(((vader_struct_toolchain_ast$ReturnStmt_t*) t1)->f_value.tag == 0u)) {
				t1 = l6.payload.obj;
				t2 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$ReturnStmt_t*) t1)->f_value, l1);
				{ void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
			}
		}
		l5 = 711u;
		t1 = vader_front_comptime$vm_required(l2, l5);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = 711u;
	t1 = vader_front_comptime$vm_required(l2, l5);
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_ident(void* l0, void* l1) {
	void* l2 = NULL;
	void* l5 = NULL;
	void* l7 = NULL;
	uint64_t l3;
	vader_box_t l4 = vader_box_null();
	int32_t l6;
	int64_t l8;
	vader_string_t l9 = 0;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l4, &t1 };
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l5, &l7, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l9 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_resolved)->f_idents;
	l3 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$IdentExpr_t*) l0)->f_span);
	l4 = std_collections$Map$std_core$Index$at__u64__Any(l2, l3);
	if (l4.tag == 0u) {
		t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$IdentExpr_t*) l0)->f_span, 813u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = l4.payload.obj;
	l5 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_bindings;
	l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_id;
	l4 = std_collections$Map$std_core$Index$at__i32__Any(l5, l6);
	if (!(l4.tag == 0u)) {
		t0 = vader_front_comptime$ok(l4);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = ((vader_struct_toolchain_ast$IdentExpr_t*) l0)->f_span;
	l4 = vader_front_comptime$evaluate_project_const(l2, l1, l5);
	if (!(l4.tag == 0u)) {
		t0 = l4.payload.obj;
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = vader_front_comptime$type_from_expr_safe(l0, l1);
	if (!(l4.tag == 0u)) {
		t1 = vader_front_comptime$type_val(l4);
		t0 = vader_front_comptime$ok(t1);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = ((vader_struct_toolchain_ast$IdentExpr_t*) l0)->f_span;
	l7 = (void*) &vader_data_11;
	l8 = ((int64_t) (uint8_t) ((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_kind);
	vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
	VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
	t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l8);
	l9 = ((vader_struct_vader_core_symbol$SymbolKindInfo_t*) t0)->f_label;
	l9 = concat_3(812u, l9, 394u);
	t0 = vader_front_comptime$vm_required(l5, l9);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_if(void* l0, void* l1) {
	void* l2 = NULL;
	void* l4 = NULL;
	vader_box_t l3 = vader_box_null(), l5 = vader_box_null();
	void* t0 = NULL;
	void* t2 = NULL;
	bool t1;
	vader_box_t* gc_roots[2] = { &l3, &l5 };
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l4, &t0, &t2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$IfExpr_t*) l0)->f_cond, l1);
	l3 = ((vader_struct_vader_front_comptime$EvalResult_t*) l2)->f_value;
	if (l3.tag == 0u) {
		{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l3.tag == 1649u)) {
		t0 = vader_front_comptime$vm_required(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, ((vader_struct_toolchain_ast$IfExpr_t*) l0)->f_cond.payload.obj), 2272u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l3.payload.obj;
	t1 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
	if (t1) {
		l2 = ((vader_struct_toolchain_ast$IfExpr_t*) l0)->f_then_block;
		l4 = ((vader_struct_toolchain_ast$BlockExpr_t*) ((vader_struct_toolchain_ast$IfExpr_t*) l0)->f_then_block)->f_span;
		t0 = vader_front_comptime$evaluate_block_value(l2, l4, l1);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = ((vader_struct_toolchain_ast$IfExpr_t*) l0)->f_else_branch;
	if (l5.tag == 0u) {
		t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$IfExpr_t*) l0)->f_span, 2683u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = l5;
	if (l3.tag == 1169u) {
		t0 = l3.payload.obj;
		t2 = vader_front_comptime$evaluate_if(((vader_struct_toolchain_ast$IfElseIf_t*) t0)->f_branch, l1);
		{ void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l3.tag == 1168u)) {
		vader_unreachable("non-exhaustive match (T3013 should have caught this)");
	}
	t0 = l3.payload.obj;
	l2 = ((vader_struct_toolchain_ast$IfElseBlock_t*) t0)->f_block;
	t0 = l3.payload.obj;
	l4 = ((vader_struct_toolchain_ast$BlockExpr_t*) ((vader_struct_toolchain_ast$IfElseBlock_t*) t0)->f_block)->f_span;
	t0 = vader_front_comptime$evaluate_block_value(l2, l4, l1);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_int_lit(void* l0, void* l1) {
	void* l2 = NULL;
	int64_t l3;
	vader_string_t l4 = 0;
	int64_t t0;
	vader_box_t t1 = vader_box_null();
	void* t2 = NULL;
	vader_box_t* gc_roots[1] = { &t1 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t2 };
	vader_string_t* gc_atom_roots[1] = { &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = toolchain_ast$int_literal_value(l0);
	t1 = vader_front_comptime$int_val(t0);
	l2 = vader_front_comptime$ok(t1);
	l3 = ((vader_struct_toolchain_ast$IntLitExpr_t*) l0)->f_id;
	l4 = vader_front_comptime$resolved_int_name(l1, l3);
	t2 = vader_front_comptime$normalize_int_result(l2, l4);
	{ void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_intrinsic_call(void* l0, void* l1) {
	uint8_t l2;
	void* l3 = NULL;
	void* l5 = NULL;
	bool l4;
	vader_string_t l6 = 0;
	void** gc_raw_roots[4] = { &l0, &l1, &l3, &l5 };
	vader_string_t* gc_atom_roots[1] = { &l6 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_intrinsic;
	if (l2 == INT32_C(0)) {
		l3 = vader_front_comptime$intrinsic_size_of(l0, l1);
		{ void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l2 == INT32_C(1)) {
		l3 = vader_front_comptime$intrinsic_align_of(l0, l1);
	} else if (l2 == INT32_C(2)) {
		l3 = vader_front_comptime$intrinsic_type_name(l0, l1);
	} else if (l2 == INT32_C(3)) {
		l3 = vader_front_comptime$intrinsic_type_kind(l0, l1);
	} else if (l2 == INT32_C(4)) {
		l3 = vader_front_comptime$intrinsic_field_count(l0, l1);
	} else if (l2 == INT32_C(5)) {
		l3 = vader_front_comptime$intrinsic_variant_count(l0, l1);
	} else if (l2 == INT32_C(6)) {
		l3 = vader_front_comptime$intrinsic_field_index(l0, l1);
	} else if (l2 == INT32_C(7)) {
		l3 = vader_front_comptime$intrinsic_satisfies(l0, l1);
	} else {
		if (l2 == INT32_C(8)) {
			l4 = true;
		} else {
			l4 = l2 == INT32_C(9);
		}
		if (l4) {
			l3 = vader_front_comptime$intrinsic_integer_bound(l0, l1);
		} else {
			if (l2 == INT32_C(10)) {
				l4 = true;
			} else {
				l4 = l2 == INT32_C(11);
			}
			if (l4) {
				l4 = true;
			} else {
				l4 = l2 == INT32_C(12);
			}
			if (l4) {
				l4 = true;
			} else {
				l4 = l2 == INT32_C(13);
			}
			if (l4) {
				l4 = true;
			} else {
				l4 = l2 == INT32_C(14);
			}
			if (!(l4)) {
				vader_unreachable("non-exhaustive match (T3013 should have caught this)");
			}
			l5 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_span;
			l6 = toolchain_ast$intrinsic_name(((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_intrinsic);
			l6 = concat_2(639u, l6);
			l3 = vader_front_comptime$vm_required(l5, l6);
		}
	}
	{ void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_match(void* l0, void* l1) {
	void* l2 = NULL;
	void* l6 = NULL;
	vader_box_t l3 = vader_box_null(), l7 = vader_box_null();
	int64_t l4, l5;
	void* t0 = NULL;
	bool t1;
	vader_box_t* gc_roots[2] = { &l3, &l7 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (!(((vader_struct_toolchain_ast$MatchExpr_t*) l0)->f_binding.tag == 0u)) {
		t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$MatchExpr_t*) l0)->f_span, 2878u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$MatchExpr_t*) l0)->f_scrutinee, l1);
	l3 = ((vader_struct_vader_front_comptime$EvalResult_t*) l2)->f_value;
	if (l3.tag == 0u) {
		{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = ((vader_struct_toolchain_ast$MatchExpr_t*) l0)->f_arms;
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		if (!(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_guard.tag == 0u)) {
			t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_span, 2877u);
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l7 = vader_front_comptime$pattern_holds(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_pattern, l3);
		if (l7.tag == 0u) {
			t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_span, 2880u);
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
		t1 = l7.payload.b;
		if (t1) {
			t0 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_body, l1);
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l5 = (l5 + INT64_C(1));
	}
	t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$MatchExpr_t*) l0)->f_span, 2881u);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_comptime$evaluate_module_decls(void* l0, void* l1, void* l2, vader_string_t l3, void* l4, void* l5) {
	void* l6 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	void* l13 = NULL;
	void* l15 = NULL;
	void* l17 = NULL;
	void* l18 = NULL;
	void* l20 = NULL;
	void* l21 = NULL;
	void* l22 = NULL;
	void* l24 = NULL;
	void* l25 = NULL;
	void* l26 = NULL;
	void* l28 = NULL;
	void* l31 = NULL;
	void* l33 = NULL;
	int64_t l9, l10;
	vader_box_t l14 = vader_box_null(), l23 = vader_box_null(), l27 = vader_box_null(), l30 = vader_box_null();
	int32_t l16, l19, l29, l32;
	void* t0 = NULL;
	bool t1;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[5] = { &l14, &l23, &l27, &l30, &t2 };
	void** gc_raw_roots[24] = {
		&l0, &l1, &l2, &l4, &l5, &l6, &l7, &l8, &l11, &l12, &l13, &l15, &l17, &l18, &l20, &l21,
		&l22, &l24, &l25, &l26, &l28, &l31, &l33, &t0,
	};
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 5u, 24u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l6 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l1)->f_typed;
	l7 = vader_front_comptime$sort_comptime_decls(l0, l6);
	l8 = ((vader_struct_vader_front_comptime$ComptimeOrder_t*) l7)->f_cycle_diags;
	l9 = vader_array_length(((vader_array_t*) l8));
	l10 = INT64_C(0);
	while ((l10 < l9)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l8);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l11 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l10);
		vader_array_push_ref((vader_array_t*) l5, l11);
		l10 = (l10 + INT64_C(1));
	}
	l8 = vader_front_comptime$module_context(l1, l4);
	l7 = ((vader_struct_vader_front_comptime$ComptimeOrder_t*) l7)->f_order;
	l9 = vader_array_length(((vader_array_t*) l7));
	l10 = INT64_C(0);
	while ((l10 < l9)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l10)
		l11 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l10);
		l12 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) l6)->f_resolved;
		l13 = ((vader_struct_toolchain_ast$ConstDecl_t*) l11)->f_name_span;
		l14 = vader_front_resolver$symbol_declared_at(l12, l13);
		if (!(l14.tag == 0u)) {
			l15 = ((vader_struct_vader_front_comptime$ProjectConstants_t*) l4)->f_cycles;
			t0 = l14.payload.obj;
			l16 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_id;
			t1 = std_collections$Set$std_core$Contains$contains__i32(l15, l16);
			if (t1) {
				l10 = (l10 + INT64_C(1));
				continue;
			}
		}
		l17 = vader_front_comptime$evaluate_declared(l11, l14, l8);
		t1 = ((vader_struct_vader_front_comptime$EvalResult_t*) l17)->f_vm_required;
		if (t1) {
			if (!(l14.tag == 0u)) {
				l18 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) l6)->f_decl_types;
				t0 = l14.payload.obj;
				l19 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_id;
				t2 = std_collections$Map$std_core$Index$at__i32__Any(l18, l19);
				if (t2.tag == 1490u) {
					l20 = ((vader_struct_toolchain_ast$ConstDecl_t*) l11)->f_span;
					l21 = toolchain_diagnostics$comptime_error((uint8_t) 0, l20, 1917u);
					vader_array_push_ref((vader_array_t*) l5, l21);
					l10 = (l10 + INT64_C(1));
					continue;
				}
				l22 = l14.payload.obj;
				l23 = vader_front_comptime$build_vm_required(l11, l22, l6, l3);
				if (l23.tag == 1669u) {
					l24 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l2)->f_vm_required;
					l25 = l23.payload.obj;
					vader_array_push_ref((vader_array_t*) l24, l25);
					l10 = (l10 + INT64_C(1));
					continue;
				}
			}
			if (!(((vader_struct_vader_front_comptime$EvalResult_t*) l17)->f_diag.tag == 0u)) {
				t2 = ((vader_struct_vader_front_comptime$EvalResult_t*) l17)->f_diag;
				l26 = t2.payload.obj;
				vader_array_push_ref((vader_array_t*) l5, l26);
			}
			l10 = (l10 + INT64_C(1));
			continue;
		}
		l27 = ((vader_struct_vader_front_comptime$EvalResult_t*) l17)->f_value;
		if (!(l27.tag == 0u)) {
			if (!(l14.tag == 0u)) {
				l28 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l1)->f_comptime_decls;
				t0 = l14.payload.obj;
				l29 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_id;
				l30 = l27;
				std_collections$Map$std_core$IndexSet$set_at__i32__Any(l28, l29, l30);
				l31 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l1)->f_routes;
				t0 = l14.payload.obj;
				l32 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_id;
				std_collections$Map$std_core$IndexSet$set_at__i32__vader_front_comptime_ComptimeRoute(l31, l32, (uint8_t) 0);
			}
		}
		if (!(((vader_struct_vader_front_comptime$EvalResult_t*) l17)->f_diag.tag == 0u)) {
			t2 = ((vader_struct_vader_front_comptime$EvalResult_t*) l17)->f_diag;
			l33 = t2.payload.obj;
			vader_array_push_ref((vader_array_t*) l5, l33);
		}
		l10 = (l10 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_comptime$evaluate_named_constants__std_core_CLibrary(void* l0, void* l1, void* l2, void* l3) {
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	void* l16 = NULL;
	void* l18 = NULL;
	int64_t l9, l10, l13, l14, l15, l17;
	int32_t l19, l22, l25, l26;
	vader_box_t l20 = vader_box_null(), l21 = vader_box_null(), l23 = vader_box_null(), l24 = vader_box_null();
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_string_t t2 = 0;
	bool t3;
	vader_box_t* gc_roots[5] = { &l20, &l21, &l23, &l24, &t1 };
	void** gc_raw_roots[14] = {
		&l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l11, &l12, &l16, &l18, &t0,
	};
	vader_string_t* gc_atom_roots[1] = { &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 5u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 633u);
	l4 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 641u);
	l5 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 633u);
	l6 = (void*) _a2_arr;
	vader_struct_std_collections$Map__i32__Any_t* _a3_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
	vader_obj_header_init(_a3_obj, 901u);
	_a3_obj->f_ekeys = l4;
	_a3_obj->f_evals = l5;
	_a3_obj->f_index = l6;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l4 = (void*) _a3_obj;
	vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 633u);
	l5 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(26u, 0u, 12u, 628u);
	l6 = (void*) _a5_arr;
	vader_array_t* _a6_arr = vader_array_new(29u, 0u, 7u, 633u);
	l7 = (void*) _a6_arr;
	vader_struct_std_collections$Map__i32__bool_t* _a7_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
	vader_obj_header_init(_a7_obj, 904u);
	_a7_obj->f_ekeys = l5;
	_a7_obj->f_evals = l6;
	_a7_obj->f_index = l7;
	_a7_obj->f_mask = INT64_C(0);
	_a7_obj->f_grow_at = INT64_C(0);
	_a7_obj->f_size = INT64_C(0);
	_a7_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a7_obj;
	vader_struct_std_collections$Set__i32_t* _a8_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
	vader_obj_header_init(_a8_obj, 1089u);
	_a8_obj->f_inner = t0;
	l5 = (void*) _a8_obj;
	l6 = ((vader_struct_vader_front_typecheck$TypedProject_t*) ((vader_struct_vader_front_comptime$ProjectConstants_t*) l0)->f_typed)->f_modules;
	l7 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_TypedProgram_t*) l6)->f_ekeys;
	l8 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_TypedProgram_t*) l6)->f_evals;
	l9 = INT64_C(0);
	l10 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_TypedProgram_t*) l6)->f_size;
	while ((l9 < l10)) {
		vader_array_t* _a9_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l9)
		t1 = vader_array_box_slots(_a9_slotarr->buf)[vader_array_offset(_a9_slotarr) + (size_t) l9];
		t2 = t1.payload.s;
		vader_array_t* _a10_slotarr = ((vader_array_t*) l8);
		VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l9)
		t0 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l9);
		vader_fn_t* _a11_fnobj = (vader_fn_t*) l1;
		t1 = ((vader_fn_erased_sig_1_t) _a11_fnobj->code)(_a11_fnobj->env, vader_ref_box(t0));
		l6 = t1.payload.obj;
		l11 = ((vader_struct_std_collections$Map__i64__vader_core_symbol_Symbol_t*) l6)->f_ekeys;
		l12 = ((vader_struct_std_collections$Map__i64__vader_core_symbol_Symbol_t*) l6)->f_evals;
		l13 = INT64_C(0);
		l14 = ((vader_struct_std_collections$Map__i64__vader_core_symbol_Symbol_t*) l6)->f_size;
		while ((l13 < l14)) {
			vader_array_t* _a12_slotarr = ((vader_array_t*) l11);
			VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l13)
			l15 = ((int64_t*) _a12_slotarr->buf->slots)[vader_array_offset(_a12_slotarr) + (size_t) l13];
			vader_array_t* _a13_slotarr = ((vader_array_t*) l12);
			VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l13)
			l16 = vader_array_ref_load_obj(_a13_slotarr->buf, vader_array_offset(_a13_slotarr) + (size_t) l13);
			l17 = l15;
			l18 = l16;
			l19 = ((vader_struct_vader_core_symbol$Symbol_t*) l18)->f_id;
			l20 = std_collections$Map$std_core$Index$at__i32__Any(l4, l19);
			if (l20.tag == 0u) {
				l22 = ((vader_struct_vader_core_symbol$Symbol_t*) l18)->f_id;
				t3 = std_collections$Set$std_core$Contains$contains__i32(l5, l22);
				if (!(t3)) {
					vader_fn_t* _a14_fnobj = (vader_fn_t*) l2;
					l24 = ((vader_fn_erased_sig_1_t) _a14_fnobj->code)(_a14_fnobj->env, vader_ref_box(l18));
					if (l24.tag == 0u) {
						l25 = ((vader_struct_vader_core_symbol$Symbol_t*) l18)->f_id;
						std_collections$add__i32(l5, l25);
					} else {
						l23 = l24;
						l26 = ((vader_struct_vader_core_symbol$Symbol_t*) l18)->f_id;
						std_collections$Map$std_core$IndexSet$set_at__i32__Any(l4, l26, l23);
						std_collections$Map$std_core$IndexSet$set_at__i64__Any(l3, l17, l23);
					}
				}
			} else {
				l21 = l20;
				std_collections$Map$std_core$IndexSet$set_at__i64__Any(l3, l17, l21);
			}
			l13 = (l13 + INT64_C(1));
		}
		l9 = (l9 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_comptime$evaluate_null_lit(void* l0) {
	void* t0 = NULL;
	void* t1 = NULL;
	void** gc_raw_roots[3] = { &l0, &t0, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = (void*) &vader_data_33;
	vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
	VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
	t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
	t1 = vader_front_comptime$ok(vader_ref_box(t0));
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_comptime$evaluate_project(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	void* l9 = NULL;
	void* l15 = NULL;
	int64_t l10, l11;
	vader_string_t l12 = 0;
	vader_string_t l13 = 0;
	vader_box_t l14 = vader_box_null();
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l14, &t1 };
	void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l15, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l12, &l13 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = vader_front_comptime$new_evaluated_project(l1);
	vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 633u);
	l4 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 641u);
	l5 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 633u);
	l6 = (void*) _a2_arr;
	vader_struct_std_collections$Map__i32__Any_t* _a3_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
	vader_obj_header_init(_a3_obj, 901u);
	_a3_obj->f_ekeys = l4;
	_a3_obj->f_evals = l5;
	_a3_obj->f_index = l6;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l4 = (void*) _a3_obj;
	vader_array_t* _a4_arr = vader_array_new(218u, 0u, 13u, 1467u);
	l5 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(29u, 0u, 7u, 633u);
	l6 = (void*) _a5_arr;
	vader_array_t* _a6_arr = vader_array_new(26u, 0u, 12u, 628u);
	l7 = (void*) _a6_arr;
	vader_array_t* _a7_arr = vader_array_new(29u, 0u, 7u, 633u);
	l8 = (void*) _a7_arr;
	vader_struct_std_collections$Map__i32__bool_t* _a8_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
	vader_obj_header_init(_a8_obj, 904u);
	_a8_obj->f_ekeys = l6;
	_a8_obj->f_evals = l7;
	_a8_obj->f_index = l8;
	_a8_obj->f_mask = INT64_C(0);
	_a8_obj->f_grow_at = INT64_C(0);
	_a8_obj->f_size = INT64_C(0);
	_a8_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a8_obj;
	vader_struct_std_collections$Set__i32_t* _a9_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
	vader_obj_header_init(_a9_obj, 1089u);
	_a9_obj->f_inner = t0;
	l6 = (void*) _a9_obj;
	vader_array_t* _a10_arr = vader_array_new(29u, 0u, 7u, 633u);
	l7 = (void*) _a10_arr;
	vader_array_t* _a11_arr = vader_array_new(26u, 0u, 12u, 628u);
	l8 = (void*) _a11_arr;
	vader_array_t* _a12_arr = vader_array_new(29u, 0u, 7u, 633u);
	l9 = (void*) _a12_arr;
	vader_struct_std_collections$Map__i32__bool_t* _a13_obj = (vader_struct_std_collections$Map__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__bool_t));
	vader_obj_header_init(_a13_obj, 904u);
	_a13_obj->f_ekeys = l7;
	_a13_obj->f_evals = l8;
	_a13_obj->f_index = l9;
	_a13_obj->f_mask = INT64_C(0);
	_a13_obj->f_grow_at = INT64_C(0);
	_a13_obj->f_size = INT64_C(0);
	_a13_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a13_obj;
	vader_struct_std_collections$Set__i32_t* _a14_obj = (vader_struct_std_collections$Set__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i32_t));
	vader_obj_header_init(_a14_obj, 1089u);
	_a14_obj->f_inner = t0;
	l7 = (void*) _a14_obj;
	vader_struct_vader_front_comptime$ProjectConstants_t* _a15_obj = (vader_struct_vader_front_comptime$ProjectConstants_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ProjectConstants_t));
	vader_obj_header_init(_a15_obj, 1665u);
	_a15_obj->f_typed = l1;
	_a15_obj->f_values = l4;
	_a15_obj->f_evaluating = l5;
	_a15_obj->f_faulted = l6;
	_a15_obj->f_cycles = l7;
	_a15_obj->f_steps = INT64_C(0);
	l4 = (void*) _a15_obj;
	vader_array_t* _a16_arr = vader_array_new(28u, 0u, 0u, 630u);
	l5 = (void*) _a16_arr;
	vader_array_t* _a17_arr = vader_array_new(35u, 0u, 0u, 641u);
	l6 = (void*) _a17_arr;
	vader_array_t* _a18_arr = vader_array_new(29u, 0u, 7u, 633u);
	l7 = (void*) _a18_arr;
	vader_struct_std_collections$Map__string__Any___t* _a19_obj = (vader_struct_std_collections$Map__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any___t));
	vader_obj_header_init(_a19_obj, 988u);
	_a19_obj->f_ekeys = l5;
	_a19_obj->f_evals = l6;
	_a19_obj->f_index = l7;
	_a19_obj->f_mask = INT64_C(0);
	_a19_obj->f_grow_at = INT64_C(0);
	_a19_obj->f_size = INT64_C(0);
	_a19_obj->f_tombs = INT64_C(0);
	l5 = (void*) _a19_obj;
	l6 = ((vader_struct_vader_front_typecheck$TypedProject_t*) l1)->f_modules;
	l7 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_TypedProgram_t*) l6)->f_ekeys;
	l8 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_TypedProgram_t*) l6)->f_evals;
	l10 = INT64_C(0);
	l11 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_TypedProgram_t*) l6)->f_size;
	while ((l10 < l11)) {
		vader_array_t* _a20_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l10)
		t1 = vader_array_box_slots(_a20_slotarr->buf)[vader_array_offset(_a20_slotarr) + (size_t) l10];
		l12 = t1.payload.s;
		vader_array_t* _a21_slotarr = ((vader_array_t*) l8);
		VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l10)
		l6 = vader_array_ref_load_obj(_a21_slotarr->buf, vader_array_offset(_a21_slotarr) + (size_t) l10);
		l13 = l12;
		l9 = vader_front_comptime$new_evaluated_program(l6);
		l14 = vader_front_comptime$lookup_module_decls(l0, l13);
		if (!(l14.tag == 0u)) {
			l15 = l14.payload.obj;
			std_collections$Map$std_core$IndexSet$set_at__string__Any(l5, l13, vader_ref_box(l15));
			t0 = l14.payload.obj;
			vader_front_comptime$evaluate_module_decls(t0, l9, l3, l13, l4, l2);
		}
		std_collections$Map$std_core$IndexSet$set_at__string__Any(((vader_struct_vader_front_comptime$EvaluatedProject_t*) l3)->f_modules, l13, vader_ref_box(l9));
		l10 = (l10 + INT64_C(1));
	}
	l6 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l3)->f_modules;
	l7 = ((vader_struct_std_collections$Map__string__vader_front_comptime_EvaluatedProgram_t*) l6)->f_ekeys;
	l8 = ((vader_struct_std_collections$Map__string__vader_front_comptime_EvaluatedProgram_t*) l6)->f_evals;
	l10 = INT64_C(0);
	l11 = ((vader_struct_std_collections$Map__string__vader_front_comptime_EvaluatedProgram_t*) l6)->f_size;
	while ((l10 < l11)) {
		vader_array_t* _a22_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l10)
		t1 = vader_array_box_slots(_a22_slotarr->buf)[vader_array_offset(_a22_slotarr) + (size_t) l10];
		l12 = t1.payload.s;
		vader_array_t* _a23_slotarr = ((vader_array_t*) l8);
		VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a23_slotarr, l10)
		l6 = vader_array_ref_load_obj(_a23_slotarr->buf, vader_array_offset(_a23_slotarr) + (size_t) l10);
		l13 = l12;
		l9 = l6;
		l14 = std_collections$Map$std_core$Index$at__string__Any(l5, l13);
		if (!(l14.tag == 0u)) {
			t0 = l14.payload.obj;
			vader_front_comptime$fold_plain_constants(t0, l9, l4, l2);
			t0 = l14.payload.obj;
			vader_front_comptime$evaluate_assert_decls(t0, l9, l4, l2);
		}
		vader_front_comptime$evaluate_decorator_uses(l9, l4, l2);
		l10 = (l10 + INT64_C(1));
	}
	vader_front_comptime$evaluate_extern_libraries(l4, l3, l2);
	vader_front_comptime$evaluate_extern_interfaces(l4, l3, l2);
	l4 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l3)->f_libraries;
	l5 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l3)->f_interfaces;
	vader_front_comptime$check_extern_symbols(l0, l4, l5, l2);
	{ void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$evaluate_project_const(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l4 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	void* l9 = NULL;
	void* l12 = NULL;
	void* l13 = NULL;
	int32_t l5, l15;
	vader_box_t l6 = vader_box_null();
	int64_t l10, l11;
	vader_string_t l14 = 0;
	void* t0 = NULL;
	void* t5 = NULL;
	bool t1;
	vader_string_t t2 = 0;
	vader_box_t t3 = vader_box_null();
	int64_t t4;
	vader_box_t* gc_roots[2] = { &l6, &t3 };
	void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8, &l9, &l12, &l13, &t0, &t5 };
	vader_string_t* gc_atom_roots[2] = { &l14, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_project;
	l4 = ((vader_struct_vader_front_comptime$ProjectConstants_t*) l3)->f_values;
	l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
	l6 = std_collections$Map$std_core$Index$at__i32__Any(l4, l5);
	if (!(l6.tag == 0u)) {
		t0 = vader_front_comptime$ok(l6);
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = ((vader_struct_vader_front_comptime$ProjectConstants_t*) l3)->f_faulted;
	l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
	t1 = std_collections$Set$std_core$Contains$contains__i32(l4, l5);
	if (t1) {
		vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
		vader_obj_header_init(_a0_obj, 1656u);
		_a0_obj->f_value = vader_box_obj(0u, NULL);
		_a0_obj->f_diag = vader_box_obj(0u, NULL);
		_a0_obj->f_vm_required = false;
		t0 = (void*) _a0_obj;
		{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
	}
	t2 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_module;
	l6 = vader_front_comptime$declaring_context(t2, l1);
	if (l6.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l4 = l6.payload.obj;
	l7 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l4)->f_typed)->f_const_decls;
	l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
	l6 = std_collections$Map$std_core$Index$at__i32__Any(l7, l5);
	if (l6.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l7 = l6.payload.obj;
	l8 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l4)->f_typed)->f_decl_types;
	l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
	t3 = std_collections$Map$std_core$Index$at__i32__Any(l8, l5);
	if (t3.tag == 1490u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l8 = vader_front_comptime$cycle_closed_by(((vader_struct_vader_front_comptime$ProjectConstants_t*) l3)->f_evaluating, l0);
	t4 = vader_array_length(((vader_array_t*) l8));
	if ((t4 > INT64_C(0))) {
		t4 = vader_array_length(((vader_array_t*) l8));
		vader_array_t* _a1_arr = vader_array_reserve(28u, (int64_t) t4, 0u, 630u);
		l9 = (void*) _a1_arr;
		l10 = vader_array_length(((vader_array_t*) l8));
		l11 = INT64_C(0);
		while ((l11 < l10)) {
			vader_array_t* _a2_slotarr = ((vader_array_t*) l8);
			VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
			l12 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l11);
			l13 = ((vader_struct_vader_front_comptime$ProjectConstants_t*) l3)->f_cycles;
			l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l12)->f_id;
			std_collections$add__i32(l13, l5);
			l14 = ((vader_struct_vader_core_symbol$Symbol_t*) l12)->f_name;
			vader_array_push_scalar((vader_array_t*) l9, vader_box_string(630u, l14));
			l11 = (l11 + INT64_C(1));
		}
		l14 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
		vader_array_push_scalar((vader_array_t*) l9, vader_box_string(630u, l14));
		l8 = ((vader_struct_toolchain_ast$ConstDecl_t*) l7)->f_span;
		l14 = vader_front_comptime$display_cycle(l9);
		t0 = toolchain_diagnostics$comptime_error((uint8_t) 4, l8, l14);
		t5 = vader_front_comptime$fail(t0);
		{ vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_push_ref((vader_array_t*) ((vader_struct_vader_front_comptime$ProjectConstants_t*) l3)->f_evaluating, l0);
	l4 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$ConstDecl_t*) l7)->f_value, l4);
	t3 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_front_comptime$ProjectConstants_t*) l3)->f_evaluating);
	if (((vader_struct_vader_front_comptime$EvalResult_t*) l4)->f_value.tag == 0u) {
		t3 = vader_front_comptime$fault_of(l4);
		if (!(t3.tag == 0u)) {
			l7 = ((vader_struct_vader_front_comptime$ProjectConstants_t*) l3)->f_faulted;
			l15 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
			std_collections$add__i32(l7, l15);
		}
		{ vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = ((vader_struct_vader_front_comptime$ProjectConstants_t*) l3)->f_values;
	l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
	l6 = ((vader_struct_vader_front_comptime$EvalResult_t*) l4)->f_value;
	std_collections$Map$std_core$IndexSet$set_at__i32__Any(l3, l5, l6);
	{ vader_box_t __vret = vader_ref_box(l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_seq_lit(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l6 = NULL;
	void* l9 = NULL;
	int64_t l4, l5, l10;
	vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
	vader_string_t l11 = 0;
	vader_box_t t0 = vader_box_null();
	void* t1 = NULL;
	void* t2 = NULL;
	vader_box_t* gc_roots[3] = { &l7, &l8, &t0 };
	void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l6, &l9, &t1, &t2 };
	vader_string_t* gc_atom_roots[1] = { &l11 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(495u, 0u, 13u, 2834u);
	l2 = (void*) _a0_arr;
	l3 = ((vader_struct_toolchain_ast$SeqLitExpr_t*) l0)->f_elements;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
		t0 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
		l6 = vader_front_comptime$evaluate_expr(t0, l1);
		l8 = ((vader_struct_vader_front_comptime$EvalResult_t*) l6)->f_value;
		if (l8.tag == 0u) {
			{ void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l7 = l8;
		vader_array_push_ref((vader_array_t*) l2, l7.payload.obj);
		l5 = (l5 + INT64_C(1));
	}
	l3 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_expr_types;
	l4 = ((vader_struct_toolchain_ast$SeqLitExpr_t*) l0)->f_id;
	l8 = std_collections$Map$std_core$Index$at__i64__Any(l3, l4);
	if (l8.tag == 0u) {
		t1 = (void*) &vader_data_44;
		vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		t1 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) INT64_C(0));
		l7 = vader_ref_box(t1);
	} else {
		l7 = l8;
	}
	t0 = vader_core_types$tuple_backing(l7);
	if (t0.tag == 0u) {
		vader_struct_vader_front_comptime$ArrayValue_t* _a3_obj = (vader_struct_vader_front_comptime$ArrayValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ArrayValue_t));
		vader_obj_header_init(_a3_obj, 1647u);
		_a3_obj->f_elements = l2;
		_a3_obj->f_type = l7;
		t1 = (void*) _a3_obj;
		t2 = vader_front_comptime$ok(vader_ref_box(t1));
		{ void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a4_arr = vader_array_new(28u, 0u, 0u, 630u);
	l3 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(35u, 0u, 0u, 641u);
	l6 = (void*) _a5_arr;
	vader_array_t* _a6_arr = vader_array_new(29u, 0u, 7u, 633u);
	l9 = (void*) _a6_arr;
	vader_struct_std_collections$Map__string__Any_t* _a7_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a7_obj, 987u);
	_a7_obj->f_ekeys = l3;
	_a7_obj->f_evals = l6;
	_a7_obj->f_index = l9;
	_a7_obj->f_mask = INT64_C(0);
	_a7_obj->f_grow_at = INT64_C(0);
	_a7_obj->f_size = INT64_C(0);
	_a7_obj->f_tombs = INT64_C(0);
	l3 = (void*) _a7_obj;
	l4 = INT64_C(0);
	l5 = vader_array_length(((vader_array_t*) l2));
	while ((l4 < l5)) {
		l6 = (void*) vader_buffer_new((size_t) INT64_C(21));
		l10 = INT64_C(0);
		l10 = std_core$write_string_at(l6, l10, 1240u);
		l10 = std_core$write_int(l6, l10, l4);
		l11 = std_core$finish_buffer(l6, l10);
		vader_array_t* _a8_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
		l8 = vader_array_ref_load_box(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l4);
		std_collections$Map$std_core$IndexSet$set_at__string__Any(l3, l11, l8);
		l4 = (l4 + INT64_C(1));
	}
	vader_struct_vader_front_comptime$StructValue_t* _a9_obj = (vader_struct_vader_front_comptime$StructValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$StructValue_t));
	vader_obj_header_init(_a9_obj, 1667u);
	_a9_obj->f_type = l7;
	_a9_obj->f_fields = l3;
	t1 = (void*) _a9_obj;
	t2 = vader_front_comptime$ok(vader_ref_box(t1));
	{ void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_string_lit(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l8 = NULL;
	void* l11 = NULL;
	void* l13 = NULL;
	int64_t l4, l5;
	vader_box_t l6 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l12 = vader_box_null(), l14 = vader_box_null();
	vader_string_t l7 = 0;
	vader_string_t l15 = 0;
	vader_string_t l16 = 0;
	void* t0 = NULL;
	void* t1 = NULL;
	vader_string_t t2 = 0;
	vader_box_t t3 = vader_box_null();
	vader_box_t* gc_roots[6] = { &l6, &l9, &l10, &l12, &l14, &t3 };
	void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l8, &l11, &l13, &t0, &t1 };
	vader_string_t* gc_atom_roots[4] = { &l7, &l15, &l16, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 6u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 630u);
	t0 = (void*) _a0_arr;
	vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
	vader_obj_header_init(_a1_obj, 1120u);
	_a1_obj->f_parts = t0;
	l2 = (void*) _a1_obj;
	l3 = ((vader_struct_toolchain_ast$StringLitExpr_t*) l0)->f_parts;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
		l6 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
		if (l6.tag == 1204u) {
			t0 = l6.payload.obj;
			l7 = ((vader_struct_toolchain_ast$StringLitText_t*) t0)->f_value;
			std_string__builder$append(l2, l7);
		} else {
			if (!(l6.tag == 1203u)) {
				vader_unreachable("non-exhaustive match (T3013 should have caught this)");
			}
			t0 = l6.payload.obj;
			l8 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$StringLitInterpolation_t*) t0)->f_expr, l1);
			l10 = ((vader_struct_vader_front_comptime$EvalResult_t*) l8)->f_value;
			if (l10.tag == 0u) {
				{ void* __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
			}
			l9 = l10;
			if (l9.tag == 1655u) {
				l11 = l9.payload.obj;
				t0 = l6.payload.obj;
				l12 = ((vader_struct_toolchain_ast$StringLitInterpolation_t*) t0)->f_expr;
				l13 = vader_front_comptime$display_enum(l11, l12, l1);
				l14 = ((vader_struct_vader_front_comptime$EvalResult_t*) l13)->f_value;
				if (l14.tag == 0u) {
					{ void* __vret = l13; vader_gc_top = gc_frame.prev; return __vret; }
				}
				l15 = vader_front_comptime$interpolation_value(l14);
				std_string__builder$append(l2, l15);
				l5 = (l5 + INT64_C(1));
				continue;
			}
			if ((l9.tag == 1647u || l9.tag == 1667u)) {
				t0 = l6.payload.obj;
				t1 = vader_front_comptime$vm_required(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, ((vader_struct_toolchain_ast$StringLitInterpolation_t*) t0)->f_expr.payload.obj), 2011u);
				{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
			}
			l16 = vader_front_comptime$interpolation_value(l9);
			std_string__builder$append(l2, l16);
		}
		l5 = (l5 + INT64_C(1));
	}
	t2 = std_string__builder$StringBuilder$std_core$Display$to_string(l2);
	t3 = vader_front_comptime$string_val(t2);
	t0 = vader_front_comptime$ok(t3);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_struct_lit(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	int64_t l5, l6;
	vader_box_t l7 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
	vader_string_t l10 = 0;
	void* t0 = NULL;
	void* t1 = NULL;
	vader_box_t* gc_roots[3] = { &l7, &l8, &l9 };
	void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &t0, &t1 };
	vader_string_t* gc_atom_roots[1] = { &l10 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 630u);
	l2 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 641u);
	l3 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 633u);
	l4 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 987u);
	_a3_obj->f_ekeys = l2;
	_a3_obj->f_evals = l3;
	_a3_obj->f_index = l4;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l2 = (void*) _a3_obj;
	l3 = ((vader_struct_toolchain_ast$StructLitExpr_t*) l0)->f_items;
	l5 = vader_array_length(((vader_array_t*) l3));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
		l7 = vader_array_ref_load_box(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l6);
		if (l7.tag == 1209u) {
			t0 = l7.payload.obj;
			t1 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$StructLitSpread_t*) t0)->f_span, 3263u);
			{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
		}
		t0 = l7.payload.obj;
		l4 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$StructLitField_t*) t0)->f_value, l1);
		l9 = ((vader_struct_vader_front_comptime$EvalResult_t*) l4)->f_value;
		if (l9.tag == 0u) {
			{ void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l8 = l9;
		t0 = l7.payload.obj;
		l10 = ((vader_struct_toolchain_ast$StructLitField_t*) t0)->f_name;
		std_collections$Map$std_core$IndexSet$set_at__string__Any(l2, l10, l8);
		l6 = (l6 + INT64_C(1));
	}
	l3 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_expr_types;
	l5 = ((vader_struct_toolchain_ast$StructLitExpr_t*) l0)->f_id;
	l8 = std_collections$Map$std_core$Index$at__i64__Any(l3, l5);
	if (l8.tag == 0u) {
		t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$StructLitExpr_t*) l0)->f_span, 3266u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l7 = l8;
	if (!(l7.tag == 1485u)) {
		t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$StructLitExpr_t*) l0)->f_span, 3262u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = l7.payload.obj;
	l4 = ((vader_struct_toolchain_ast$StructLitExpr_t*) l0)->f_span;
	t0 = vader_front_comptime$complete_struct(l3, l2, l4, l1);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_unary_expr(void* l0, void* l1) {
	void* l2 = NULL;
	vader_box_t l3 = vader_box_null();
	int64_t l4;
	vader_string_t l5 = 0;
	uint8_t l6;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l3 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l5 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$UnaryExpr_t*) l0)->f_operand, l1);
	l3 = ((vader_struct_vader_front_comptime$EvalResult_t*) l2)->f_value;
	if (l3.tag == 0u) {
		{ void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = ((vader_struct_toolchain_ast$UnaryExpr_t*) l0)->f_id;
	l5 = vader_front_comptime$resolved_int_name(l1, l4);
	l6 = ((vader_struct_toolchain_ast$UnaryExpr_t*) l0)->f_op;
	if (l6 == INT32_C(0)) {
		l2 = vader_front_comptime$unary_neg(l0, l3, l5);
		t0 = vader_front_comptime$normalize_int_result(l2, l5);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l6 == INT32_C(1)) {
		l2 = vader_front_comptime$unary_not(l0, l3);
	} else {
		if (!(l6 == INT32_C(2))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l2 = vader_front_comptime$unary_bit_not(l0, l3);
	}
	t0 = vader_front_comptime$normalize_int_result(l2, l5);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_with_arguments(void* l0, void* l1, void* l2, void* l3, void* l4) {
	int64_t l5, l6;
	void* l7 = NULL;
	void* l8 = NULL;
	void* l13 = NULL;
	uint64_t l9;
	vader_box_t l10 = vader_box_null(), l12 = vader_box_null();
	int32_t l11;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l10, &l12 };
	void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8, &l13, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l5 = INT64_C(0);
	l6 = vader_array_length(((vader_array_t*) l1));
	while ((l5 < l6)) {
		l8 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l3)->f_typed)->f_resolved)->f_idents;
		vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		l9 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$FnParam_t*) t0)->f_span);
		l10 = std_collections$Map$std_core$Index$at__u64__Any(l8, l9);
		if (l10.tag == 0u) {
			t0 = vader_front_comptime$vm_required(l4, 717u);
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l7 = l10.payload.obj;
		l11 = ((vader_struct_vader_core_symbol$Symbol_t*) l7)->f_id;
		vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l12 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
		std_collections$Map$std_core$IndexSet$set_at__i32__Any(l2, l11, l12);
		l5 = (l5 + INT64_C(1));
	}
	l8 = l3;
	l13 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l8)->f_typed;
	l5 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l8)->f_depth;
	l8 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l8)->f_project;
	vader_struct_vader_front_comptime$ComptimeContext_t* _a2_obj = (vader_struct_vader_front_comptime$ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ComptimeContext_t));
	vader_obj_header_init(_a2_obj, 1652u);
	_a2_obj->f_typed = l13;
	_a2_obj->f_bindings = l2;
	_a2_obj->f_depth = l5;
	_a2_obj->f_project = l8;
	l7 = (void*) _a2_obj;
	t0 = vader_front_comptime$evaluate_fn_body(l0, l7, l4);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$fail(void* l0) {
	void* t0 = NULL;
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
	vader_obj_header_init(_a0_obj, 1656u);
	_a0_obj->f_value = vader_box_obj(0u, NULL);
	_a0_obj->f_diag = vader_ref_box(l0);
	_a0_obj->f_vm_required = false;
	t0 = (void*) _a0_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$fault_of(void* l0) {
	void* l1;
	void* l4;
	vader_box_t l2;
	vader_string_t l3, l6;
	int64_t l5;
	bool t0;
	void* t1;
	l2 = ((vader_struct_vader_front_comptime$EvalResult_t*) l0)->f_diag;
	if (l2.tag == 0u) {
		return vader_box_obj(0u, NULL);
	}
	l1 = l2.payload.obj;
	t0 = ((vader_struct_vader_front_comptime$EvalResult_t*) l0)->f_vm_required;
	if (t0) {
		return vader_box_obj(0u, NULL);
	}
	l3 = ((vader_struct_toolchain_diagnostics$CodeInfo_t*) ((vader_struct_toolchain_diagnostics$Diagnostic_t*) l1)->f_code)->f_id;
	l4 = (void*) &vader_data_3;
	l5 = ((int64_t) (uint32_t) INT32_C(8));
	vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
	VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
	t1 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
	l6 = ((vader_struct_toolchain_diagnostics$CodeInfo_t*) t1)->f_id;
	if (l3 == l6) {
		return vader_ref_box(l1);
	}
	l3 = ((vader_struct_toolchain_diagnostics$CodeInfo_t*) ((vader_struct_toolchain_diagnostics$Diagnostic_t*) l1)->f_code)->f_id;
	l4 = (void*) &vader_data_3;
	l5 = ((int64_t) (uint32_t) INT32_C(2));
	vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
	VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
	t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
	l6 = ((vader_struct_toolchain_diagnostics$CodeInfo_t*) t1)->f_id;
	if (!(l3 == l6)) {
		return vader_box_obj(0u, NULL);
	}
	return vader_ref_box(l1);
}

static double vader_front_comptime$float_arith(uint8_t l0, double l1, double l2) {
	double l3;
	if (l0 == INT32_C(0)) {
		l3 = (l1 + l2);
		return l3;
	}
	if (l0 == INT32_C(1)) {
		l3 = (l1 - l2);
	} else if (l0 == INT32_C(2)) {
		l3 = (l1 * l2);
	} else if (l0 == INT32_C(3)) {
		l3 = l1 / l2;
	} else {
		l3 = 0.0;
	}
	return l3;
}

static bool vader_front_comptime$float_compare(double l0, double l1, uint8_t l2) {
	bool l3;
	if (l2 == INT32_C(0)) {
		l3 = l0 == l1;
		return l3;
	}
	if (l2 == INT32_C(1)) {
		l3 = l0 != l1;
	} else if (l2 == INT32_C(2)) {
		l3 = (l0 < l1);
	} else if (l2 == INT32_C(3)) {
		l3 = (l0 <= l1);
	} else if (l2 == INT32_C(4)) {
		l3 = (l0 > l1);
	} else {
		if (!(l2 == INT32_C(5))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l3 = (l0 >= l1);
	}
	return l3;
}

static vader_box_t vader_front_comptime$float_val(double l0) {
	void* t0 = NULL;
	void** gc_raw_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_struct_vader_front_comptime$FloatValue_t* _a0_obj = (vader_struct_vader_front_comptime$FloatValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$FloatValue_t));
	vader_obj_header_init(_a0_obj, 1659u);
	_a0_obj->f_value = l0;
	_a0_obj->f_type_name = 2479u;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_front_comptime$float_val_typed(double l0, vader_string_t l1) {
	void* t0 = NULL;
	void** gc_raw_roots[1] = { &t0 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_struct_vader_front_comptime$FloatValue_t* _a0_obj = (vader_struct_vader_front_comptime$FloatValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$FloatValue_t));
	vader_obj_header_init(_a0_obj, 1659u);
	_a0_obj->f_value = l0;
	_a0_obj->f_type_name = l1;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_comptime$fold_plain_constants(void* l0, void* l1, void* l2, void* l3) {
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l10 = NULL;
	void* l11 = NULL;
	void* l12 = NULL;
	void* l13 = NULL;
	void* l15 = NULL;
	void* l17 = NULL;
	void* l18 = NULL;
	void* l21 = NULL;
	void* l25 = NULL;
	void* l29 = NULL;
	void* l30 = NULL;
	void* l33 = NULL;
	int64_t l7, l8, l20, l22, l23;
	vader_box_t l9 = vader_box_null(), l14 = vader_box_null(), l26 = vader_box_null(), l27 = vader_box_null(), l28 = vader_box_null(), l32 = vader_box_null();
	int32_t l16, l31, l34;
	vader_string_t l19 = 0;
	vader_string_t l24 = 0;
	bool t0;
	int64_t t1;
	vader_box_t* gc_roots[6] = { &l9, &l14, &l26, &l27, &l28, &l32 };
	void** gc_raw_roots[19] = {
		&l0, &l1, &l2, &l3, &l4, &l5, &l6, &l10, &l11, &l12, &l13, &l15, &l17, &l18, &l21, &l25,
		&l29, &l30, &l33,
	};
	vader_string_t* gc_atom_roots[2] = { &l19, &l24 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 6u, 19u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l4 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l1)->f_typed;
	l5 = vader_front_comptime$module_context(l1, l2);
	l6 = l0;
	l7 = vader_array_length(((vader_array_t*) l6));
	l8 = INT64_C(0);
	while ((l8 < l7)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
		l9 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l8);
		if (l9.tag == 1138u) {
			l10 = l9.payload.obj;
			t0 = toolchain_ast$is_comptime_const(l10);
			if (t0) {
				l8 = (l8 + INT64_C(1));
				continue;
			}
			l12 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) l4)->f_resolved;
			l13 = ((vader_struct_toolchain_ast$ConstDecl_t*) l10)->f_name_span;
			l14 = vader_front_resolver$symbol_declared_at(l12, l13);
			if (l14.tag == 0u) {
				l8 = (l8 + INT64_C(1));
				continue;
			}
			l11 = l14.payload.obj;
			l15 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l1)->f_comptime_decls;
			l16 = ((vader_struct_vader_core_symbol$Symbol_t*) l11)->f_id;
			t0 = std_collections$Map$std_core$Contains$contains__i32__Any(l15, l16);
			if (t0) {
				l8 = (l8 + INT64_C(1));
				continue;
			}
			((vader_struct_vader_front_comptime$ProjectConstants_t*) l2)->f_steps = INT64_C(0);
			l17 = vader_front_comptime$evaluate_declared(l10, vader_ref_box(l11), l5);
			t1 = ((vader_struct_vader_front_comptime$ProjectConstants_t*) l2)->f_steps;
			if ((t1 > INT64_C(100000))) {
				l18 = ((vader_struct_toolchain_ast$ConstDecl_t*) l10)->f_name_span;
				l19 = ((vader_struct_toolchain_ast$ConstDecl_t*) l10)->f_name;
				l20 = vader_host_std_core$Intrinsic$byte_len(l19);
				l21 = (void*) vader_buffer_new((size_t) (INT64_C(112) + l20));
				l22 = INT64_C(0);
				l22 = std_core$write_string_at(l21, l22, 1305u);
				l22 = std_core$write_string_at(l21, l22, l19);
				l22 = std_core$write_string_at(l21, l22, 1588u);
				l23 = ((vader_struct_vader_front_comptime$ProjectConstants_t*) l2)->f_steps;
				l22 = std_core$write_int(l21, l22, l23);
				l22 = std_core$write_string_at(l21, l22, 151u);
				l24 = std_core$finish_buffer(l21, l22);
				l25 = toolchain_diagnostics$warning((uint8_t) 19, l18, l24);
				vader_array_push_ref((vader_array_t*) l3, l25);
			}
			l27 = ((vader_struct_vader_front_comptime$EvalResult_t*) l17)->f_value;
			if (l27.tag == 0u) {
				l28 = vader_front_comptime$fault_of(l17);
				if (!(l28.tag == 0u)) {
					l29 = l28.payload.obj;
					vader_array_push_ref((vader_array_t*) l3, l29);
				}
				l8 = (l8 + INT64_C(1));
				continue;
			}
			l26 = l27;
			t0 = vader_front_comptime$holds_struct(l26);
			if (t0) {
				l8 = (l8 + INT64_C(1));
				continue;
			}
			l30 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l1)->f_comptime_decls;
			l31 = ((vader_struct_vader_core_symbol$Symbol_t*) l11)->f_id;
			l32 = l26;
			std_collections$Map$std_core$IndexSet$set_at__i32__Any(l30, l31, l32);
			l33 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l1)->f_routes;
			l34 = ((vader_struct_vader_core_symbol$Symbol_t*) l11)->f_id;
			std_collections$Map$std_core$IndexSet$set_at__i32__vader_front_comptime_ComptimeRoute(l33, l34, (uint8_t) 2);
		}
		l8 = (l8 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_front_comptime$folder_beside(vader_string_t l0, vader_string_t l1) {
	vader_string_t t0 = 0;
	vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	if (!(l1 == 0u)) {
		t0 = vader_front_comptime$path_beside(l0, l1);
		{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ vader_gc_top = gc_frame.prev; return 0u; }
}

static bool vader_front_comptime$has_uncomputed_argument(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	bool t0;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$Decorator_t*) ((vader_struct_vader_front_typecheck$DecoratorUse_t*) l0)->f_written)->f_args;
	vader_struct___lambda_env_vader_front_comptime_9_t* _a0_obj = (vader_struct___lambda_env_vader_front_comptime_9_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_comptime_9_t));
	vader_obj_header_init(_a0_obj, 715u);
	_a0_obj->f_cap_0 = l1;
	l3 = (void*) _a0_obj;
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
		t0 = __lambda_vader_front_comptime_8(l3, l6);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool vader_front_comptime$has_union_operand(void* l0, void* l1) {
	void* l2;
	int64_t l3;
	vader_box_t t0;
	l2 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l0)->f_typed)->f_expr_types;
	l3 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_id, ((vader_struct_toolchain_ast$BinaryExpr_t*) l1)->f_left.payload.obj);
	t0 = std_collections$Map$std_core$Index$at__i64__Any(l2, l3);
	if (t0.tag == 1494u) {
		return true;
	}
	l2 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l0)->f_typed)->f_expr_types;
	l3 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_id, ((vader_struct_toolchain_ast$BinaryExpr_t*) l1)->f_right.payload.obj);
	t0 = std_collections$Map$std_core$Index$at__i64__Any(l2, l3);
	return t0.tag == 1494u;
}

static bool vader_front_comptime$holds_struct(vader_box_t l0) {
	bool l1;
	void* l2;
	int64_t l3, l4;
	void* t0;
	vader_box_t t1;
	bool t2;
	if (l0.tag == 1667u) {
		return true;
	}
	if (l0.tag == 1647u) {
		t0 = l0.payload.obj;
		l2 = ((vader_struct_vader_front_comptime$ArrayValue_t*) t0)->f_elements;
		l1 = false;
		l3 = vader_array_length(((vader_array_t*) l2));
		l4 = INT64_C(0);
		{
			while ((l4 < l3)) {
				vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
				VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
				t1 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
				t2 = vader_front_comptime$holds_struct(t1);
				if (t2) {
					l1 = true;
					goto end_19;
				}
				l4 = (l4 + INT64_C(1));
			}
			l1 = false;
		} end_19: ;
	} else {
		l1 = false;
	}
	return l1;
}

static int64_t vader_front_comptime$int_bits_of(vader_string_t l0) {
	void* l1;
	vader_box_t l2;
	int64_t t0;
	l2 = vader_support_integer$machine_integer_named(l0);
	if (l2.tag == 0u) {
		return INT64_C(64);
	}
	l1 = l2.payload.obj;
	t0 = ((vader_struct_vader_support_integer$MachineInteger_t*) l1)->f_bits;
	return t0;
}

static bool vader_front_comptime$int_compare(int64_t l0, int64_t l1, uint8_t l2) {
	bool l3;
	if (l2 == INT32_C(0)) {
		l3 = l0 == l1;
		return l3;
	}
	if (l2 == INT32_C(1)) {
		l3 = l0 != l1;
	} else if (l2 == INT32_C(2)) {
		l3 = (l0 < l1);
	} else if (l2 == INT32_C(3)) {
		l3 = (l0 <= l1);
	} else if (l2 == INT32_C(4)) {
		l3 = (l0 > l1);
	} else {
		if (!(l2 == INT32_C(5))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l3 = (l0 >= l1);
	}
	return l3;
}

static vader_string_t vader_front_comptime$int_digits(void* l0) {
	void* l1 = NULL;
	int64_t l2, l4;
	uint64_t l3;
	vader_string_t t0 = 0;
	bool t1;
	int64_t t2, t3;
	void** gc_raw_roots[2] = { &l0, &l1 };
	vader_string_t* gc_atom_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = ((vader_struct_vader_front_comptime$IntValue_t*) l0)->f_type_name;
	t1 = vader_core_types$is_unsigned_int_name(t0);
	if (!(t1)) {
		l1 = (void*) vader_buffer_new((size_t) INT64_C(20));
		l2 = INT64_C(0);
		l4 = ((vader_struct_vader_front_comptime$IntValue_t*) l0)->f_value;
		l2 = std_core$write_int(l1, l2, l4);
		t0 = std_core$finish_buffer(l1, l2);
		{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = (void*) vader_buffer_new((size_t) INT64_C(20));
	l2 = INT64_C(0);
	t2 = ((vader_struct_vader_front_comptime$IntValue_t*) l0)->f_value;
	t3 = t2;
	l3 = (uint64_t) (int64_t) t3;
	l2 = std_core$write_unsigned(l1, l2, l3);
	t0 = std_core$finish_buffer(l1, l2);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$int_div_check(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3) {
	void* t0 = NULL;
	int64_t t1;
	vader_box_t* gc_roots[2] = { &l1, &l2 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l2.tag == 1660u) {
		t0 = l2.payload.obj;
		t1 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
		if (t1 == INT64_C(0)) {
			t0 = vader_front_comptime$division_by_zero(l0, 533u);
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
		t0 = vader_front_comptime$arithmetic(l0, l1, l2, l3);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = vader_front_comptime$arithmetic(l0, l1, l2, l3);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$int_literal(void* l0, void* l1) {
	int64_t l2;
	uint64_t l3;
	int64_t t0, t4;
	vader_string_t t1 = 0;
	bool t2;
	void* t3 = NULL;
	void** gc_raw_roots[3] = { &l0, &l1, &t3 };
	vader_string_t* gc_atom_roots[1] = { &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = ((vader_struct_vader_front_comptime$IntValue_t*) l0)->f_value;
	if ((t0 < INT64_C(0))) {
		t1 = ((vader_struct_vader_front_comptime$IntValue_t*) l0)->f_type_name;
		t2 = std_string$starts_with(t1, 3428u);
		if (!(t2)) {
			l2 = ((vader_struct_vader_front_comptime$IntValue_t*) l0)->f_value;
			t0 = (INT64_C(0) - l2);
			l3 = (uint64_t) (int64_t) t0;
			vader_struct_toolchain_ast$IntLitExpr_t* _a0_obj = (vader_struct_toolchain_ast$IntLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IntLitExpr_t));
			vader_obj_header_init(_a0_obj, 1177u);
			_a0_obj->f_span = l1;
			_a0_obj->f_id = INT64_C(0);
			_a0_obj->f_value = l3;
			_a0_obj->f_negative = true;
			t3 = (void*) _a0_obj;
			{ vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
		}
	}
	t0 = ((vader_struct_vader_front_comptime$IntValue_t*) l0)->f_value;
	t4 = t0;
	l3 = (uint64_t) (int64_t) t4;
	vader_struct_toolchain_ast$IntLitExpr_t* _a1_obj = (vader_struct_toolchain_ast$IntLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$IntLitExpr_t));
	vader_obj_header_init(_a1_obj, 1177u);
	_a1_obj->f_span = l1;
	_a1_obj->f_id = INT64_C(0);
	_a1_obj->f_value = l3;
	_a1_obj->f_negative = false;
	t3 = (void*) _a1_obj;
	{ vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$int_mod_check(void* l0, vader_box_t l1, vader_box_t l2) {
	void* l3 = NULL;
	void* t0 = NULL;
	int64_t t1;
	vader_box_t* gc_roots[2] = { &l1, &l2 };
	void** gc_raw_roots[3] = { &l0, &l3, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l2.tag == 1660u) {
		t0 = l2.payload.obj;
		t1 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
		if (t1 == INT64_C(0)) {
			t0 = vader_front_comptime$division_by_zero(l0, 354u);
			{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l3 = (void*) &vader_fn_static_vader_front_comptime$op_mod;
		t0 = vader_front_comptime$arithmetic_int(l0, l1, l2, l3);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = (void*) &vader_fn_static_vader_front_comptime$op_mod;
	t0 = vader_front_comptime$arithmetic_int(l0, l1, l2, l3);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$int_val(int64_t l0) {
	void* t0 = NULL;
	void** gc_raw_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_struct_vader_front_comptime$IntValue_t* _a0_obj = (vader_struct_vader_front_comptime$IntValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$IntValue_t));
	vader_obj_header_init(_a0_obj, 1660u);
	_a0_obj->f_value = l0;
	_a0_obj->f_type_name = 2629u;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_front_comptime$int_val_typed(int64_t l0, vader_string_t l1) {
	void* t0 = NULL;
	void** gc_raw_roots[1] = { &t0 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_struct_vader_front_comptime$IntValue_t* _a0_obj = (vader_struct_vader_front_comptime$IntValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$IntValue_t));
	vader_obj_header_init(_a0_obj, 1660u);
	_a0_obj->f_value = l0;
	_a0_obj->f_type_name = l1;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_comptime$interpolation_value(vader_box_t l0) {
	vader_string_t l1 = 0;
	void* l2 = NULL;
	int64_t l3;
	bool l4;
	uint32_t l5;
	void* t0 = NULL;
	double t1;
	vader_box_t* gc_roots[1] = { &l0 };
	void** gc_raw_roots[2] = { &l2, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l0.tag == 1660u) {
		t0 = l0.payload.obj;
		l1 = vader_front_comptime$int_digits(t0);
		{ vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l0.tag == 1659u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_value;
		l1 = std_core$f64$Display$to_string(t1);
	} else if (l0.tag == 1649u) {
		l2 = (void*) vader_buffer_new((size_t) INT64_C(5));
		l3 = INT64_C(0);
		t0 = l0.payload.obj;
		l4 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
		l3 = std_core$write_bool(l2, l3, l4);
		l1 = std_core$finish_buffer(l2, l3);
	} else if (l0.tag == 1666u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_vader_front_comptime$StringValue_t*) t0)->f_value;
	} else if (l0.tag == 1650u) {
		t0 = l0.payload.obj;
		l5 = ((vader_struct_vader_front_comptime$CharValue_t*) t0)->f_value;
		if ((l5 > INT32_C(55295))) {
			if ((l5 < INT32_C(57344))) {
				l4 = true;
			} else {
				l4 = (l5 > INT32_C(1114111));
			}
			if (l4) {
				vader_unreachable("value out of range: no Unicode scalar value");
			}
		}
		l1 = std_core$char$Display$to_string(((uint32_t) (uint32_t) l5));
	} else if (l0.tag == 1664u) {
		l1 = 2997u;
	} else if (l0.tag == 1670u) {
		l1 = 0u;
	} else if (l0.tag == 1668u) {
		t0 = l0.payload.obj;
		l1 = vader_front_comptime$display_value(vader_ref_box(t0));
	} else {
		if (!((l0.tag == 1647u || l0.tag == 1655u || l0.tag == 1667u))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = vader_front_comptime$display_value(l0);
	}
	{ vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$intrinsic_align_of(void* l0, void* l1) {
	vader_box_t l2 = vader_box_null();
	int64_t t0;
	void* t1 = NULL;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l2, &t2 };
	void** gc_raw_roots[3] = { &l0, &l1, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args));
	if (t0 != INT64_C(1)) {
		vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
		vader_obj_header_init(_a0_obj, 1656u);
		_a0_obj->f_value = vader_box_obj(0u, NULL);
		_a0_obj->f_diag = vader_box_obj(0u, NULL);
		_a0_obj->f_vm_required = false;
		t1 = (void*) _a0_obj;
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
	VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
	t2 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0));
	l2 = vader_front_comptime$resolve_type_arg(t2, l1);
	if (l2.tag == 0u) {
		t1 = vader_front_comptime$arg_error(l0, 1950u);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = vader_front_comptime$byte_align(l2);
	t2 = vader_front_comptime$int_val_typed(t0, 2651u);
	t1 = vader_front_comptime$ok(t2);
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$intrinsic_field_count(void* l0, void* l1) {
	vader_box_t l2 = vader_box_null();
	int64_t t0;
	void* t1 = NULL;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l2, &t2 };
	void** gc_raw_roots[3] = { &l0, &l1, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args));
	if (t0 != INT64_C(1)) {
		vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
		vader_obj_header_init(_a0_obj, 1656u);
		_a0_obj->f_value = vader_box_obj(0u, NULL);
		_a0_obj->f_diag = vader_box_obj(0u, NULL);
		_a0_obj->f_vm_required = false;
		t1 = (void*) _a0_obj;
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
	VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
	t2 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0));
	l2 = vader_front_comptime$resolve_type_arg(t2, l1);
	if (l2.tag == 0u) {
		t1 = vader_front_comptime$arg_error(l0, 2521u);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = vader_front_comptime$type_field_count(l2, l1);
	t2 = vader_front_comptime$int_val_typed(t0, 2651u);
	t1 = vader_front_comptime$ok(t2);
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$intrinsic_field_index(void* l0, void* l1) {
	vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
	vader_string_t l3 = 0;
	vader_string_t l7 = 0;
	void* l5 = NULL;
	int32_t l6;
	int64_t l8;
	int64_t t0;
	void* t1 = NULL;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[3] = { &l2, &l4, &t2 };
	void** gc_raw_roots[4] = { &l0, &l1, &l5, &t1 };
	vader_string_t* gc_atom_roots[2] = { &l3, &l7 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args));
	if (t0 != INT64_C(2)) {
		vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
		vader_obj_header_init(_a0_obj, 1656u);
		_a0_obj->f_value = vader_box_obj(0u, NULL);
		_a0_obj->f_diag = vader_box_obj(0u, NULL);
		_a0_obj->f_vm_required = false;
		t1 = (void*) _a0_obj;
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
	VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
	t2 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0));
	l2 = vader_front_comptime$resolve_type_arg(t2, l1);
	if (l2.tag == 0u) {
		t1 = vader_front_comptime$arg_error(l0, 2524u);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
	VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(1))
	t2 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) INT32_C(1));
	l4 = toolchain_ast$string_literal_text(t2);
	if (l4.tag == 0u) {
		t1 = vader_front_comptime$arg_error(l0, 2523u);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = l4.payload.s;
	if (!(l2.tag == 1485u)) {
		vader_struct_vader_front_comptime$EvalResult_t* _a3_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
		vader_obj_header_init(_a3_obj, 1656u);
		_a3_obj->f_value = vader_box_obj(0u, NULL);
		_a3_obj->f_diag = vader_box_obj(0u, NULL);
		_a3_obj->f_vm_required = false;
		t1 = (void*) _a3_obj;
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_struct_fields;
	t1 = l2.payload.obj;
	l6 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t1)->f_symbol)->f_id;
	t2 = std_collections$Map$std_core$Index$at__i32__std_collections_Map_string__vader_front_typecheck_StructFieldInfo_(l5, l6);
	if (t2.tag == 0u) {
		t1 = l2.payload.obj;
		l7 = vader_core_types$display_type(vader_ref_box(t1));
		l7 = concat_3(2525u, l7, 1544u);
		t1 = vader_front_comptime$arg_error(l0, l7);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed;
	t1 = l2.payload.obj;
	l6 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t1)->f_symbol)->f_id;
	l8 = vader_front_typecheck$struct_field_index(l5, l6, l3);
	if (!((l8 < INT64_C(0)))) {
		t2 = vader_front_comptime$int_val_typed(l8, 2651u);
		t1 = vader_front_comptime$ok(t2);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_struct_vader_front_comptime$EvalResult_t* _a4_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
	vader_obj_header_init(_a4_obj, 1656u);
	_a4_obj->f_value = vader_box_obj(0u, NULL);
	_a4_obj->f_diag = vader_box_obj(0u, NULL);
	_a4_obj->f_vm_required = false;
	t1 = (void*) _a4_obj;
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$intrinsic_integer_bound(void* l0, void* l1) {
	vader_string_t l2 = 0;
	vader_string_t l4 = 0;
	vader_box_t l3 = vader_box_null(), l6 = vader_box_null();
	void* l5 = NULL;
	bool l7;
	int64_t l8;
	int64_t t0;
	void* t1 = NULL;
	void* t4 = NULL;
	vader_box_t t2 = vader_box_null();
	bool t3;
	vader_box_t* gc_roots[3] = { &l3, &l6, &t2 };
	void** gc_raw_roots[5] = { &l0, &l1, &l5, &t1, &t4 };
	vader_string_t* gc_atom_roots[2] = { &l2, &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args));
	if (t0 != INT64_C(1)) {
		vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
		vader_obj_header_init(_a0_obj, 1656u);
		_a0_obj->f_value = vader_box_obj(0u, NULL);
		_a0_obj->f_diag = vader_box_obj(0u, NULL);
		_a0_obj->f_vm_required = false;
		t1 = (void*) _a0_obj;
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = toolchain_ast$intrinsic_name(((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_intrinsic);
	vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
	VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
	t2 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0));
	l3 = vader_front_comptime$resolve_type_arg(t2, l1);
	if (l3.tag == 0u) {
		l4 = concat_2(l2, 571u);
		t1 = vader_front_comptime$arg_error(l0, l4);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l3.tag == 1473u) {
		l5 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_span;
		l4 = concat_3(639u, l2, 233u);
		t1 = vader_front_comptime$vm_required(l5, l4);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l6 = vader_core_types$type_bounds(l3);
	if (l6.tag == 0u) {
		l4 = vader_core_types$display_type(l3);
		l2 = concat_4(l2, 566u, l4, 1399u);
		t1 = vader_front_comptime$arg_error(l0, l2);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l5 = l6.payload.obj;
	l7 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_intrinsic == INT32_C(9);
	l8 = vader_core_types$integer_bound(l5, l7);
	t3 = vader_core_types$is_char(l3);
	if (!(t3)) {
		l2 = vader_core_types$representation_name(l3);
		t2 = vader_front_comptime$int_val_typed(l8, l2);
		t1 = vader_front_comptime$ok(t2);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_struct_vader_front_comptime$CharValue_t* _a2_obj = (vader_struct_vader_front_comptime$CharValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$CharValue_t));
	vader_obj_header_init(_a2_obj, 1650u);
	_a2_obj->f_value = (uint32_t) (int32_t) ((int32_t) (int64_t) l8);
	t1 = (void*) _a2_obj;
	t4 = vader_front_comptime$ok(vader_ref_box(t1));
	{ void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$intrinsic_satisfies(void* l0, void* l1) {
	vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
	void* l4 = NULL;
	int64_t t0;
	void* t1 = NULL;
	void* t3 = NULL;
	vader_box_t t2 = vader_box_null();
	bool t4;
	vader_box_t* gc_roots[3] = { &l2, &l3, &t2 };
	void** gc_raw_roots[5] = { &l0, &l1, &l4, &t1, &t3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args));
	if (t0 != INT64_C(2)) {
		vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
		vader_obj_header_init(_a0_obj, 1656u);
		_a0_obj->f_value = vader_box_obj(0u, NULL);
		_a0_obj->f_diag = vader_box_obj(0u, NULL);
		_a0_obj->f_vm_required = false;
		t1 = (void*) _a0_obj;
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
	VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
	t2 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0));
	l2 = vader_front_comptime$resolve_type_arg(t2, l1);
	if (l2.tag == 0u) {
		t1 = vader_front_comptime$arg_error(l0, 3153u);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
	VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(1))
	t2 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) INT32_C(1));
	l3 = vader_front_comptime$resolve_type_arg(t2, l1);
	if (l3.tag == 0u) {
		t1 = (void*) &vader_data_35;
		vader_array_t* _a3_slotarr = ((vader_array_t*) t1);
		VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
		t1 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) INT64_C(0));
		t3 = vader_front_comptime$ok(vader_ref_box(t1));
		{ void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed;
	t4 = vader_front_typecheck$satisfies_trait(l2, l3, l4);
	t2 = vader_front_comptime$bool_value(t4);
	t1 = vader_front_comptime$ok(t2);
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$intrinsic_size_of(void* l0, void* l1) {
	vader_box_t l2 = vader_box_null();
	int64_t t0;
	void* t1 = NULL;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l2, &t2 };
	void** gc_raw_roots[3] = { &l0, &l1, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args));
	if (t0 != INT64_C(1)) {
		vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
		vader_obj_header_init(_a0_obj, 1656u);
		_a0_obj->f_value = vader_box_obj(0u, NULL);
		_a0_obj->f_diag = vader_box_obj(0u, NULL);
		_a0_obj->f_vm_required = false;
		t1 = (void*) _a0_obj;
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
	VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
	t2 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0));
	l2 = vader_front_comptime$resolve_type_arg(t2, l1);
	if (l2.tag == 0u) {
		t1 = vader_front_comptime$arg_error(l0, 3178u);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = vader_front_comptime$byte_size(l2);
	t2 = vader_front_comptime$int_val_typed(t0, 2651u);
	t1 = vader_front_comptime$ok(t2);
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$intrinsic_type_kind(void* l0, void* l1) {
	vader_box_t l2 = vader_box_null();
	int64_t t0;
	void* t1 = NULL;
	vader_box_t t2 = vader_box_null();
	vader_string_t t3 = 0;
	vader_box_t* gc_roots[2] = { &l2, &t2 };
	void** gc_raw_roots[3] = { &l0, &l1, &t1 };
	vader_string_t* gc_atom_roots[1] = { &t3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args));
	if (t0 != INT64_C(1)) {
		vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
		vader_obj_header_init(_a0_obj, 1656u);
		_a0_obj->f_value = vader_box_obj(0u, NULL);
		_a0_obj->f_diag = vader_box_obj(0u, NULL);
		_a0_obj->f_vm_required = false;
		t1 = (void*) _a0_obj;
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
	VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
	t2 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0));
	l2 = vader_front_comptime$resolve_type_arg(t2, l1);
	if (l2.tag == 0u) {
		t1 = vader_front_comptime$arg_error(l0, 3417u);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t3 = vader_front_comptime$type_kind_label(l2);
	t2 = vader_front_comptime$string_val(t3);
	t1 = vader_front_comptime$ok(t2);
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$intrinsic_type_name(void* l0, void* l1) {
	vader_box_t l2 = vader_box_null();
	int64_t t0;
	void* t1 = NULL;
	vader_box_t t2 = vader_box_null();
	vader_string_t t3 = 0;
	vader_box_t* gc_roots[2] = { &l2, &t2 };
	void** gc_raw_roots[3] = { &l0, &l1, &t1 };
	vader_string_t* gc_atom_roots[1] = { &t3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args));
	if (t0 != INT64_C(1)) {
		vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
		vader_obj_header_init(_a0_obj, 1656u);
		_a0_obj->f_value = vader_box_obj(0u, NULL);
		_a0_obj->f_diag = vader_box_obj(0u, NULL);
		_a0_obj->f_vm_required = false;
		t1 = (void*) _a0_obj;
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
	VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
	t2 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0));
	l2 = vader_front_comptime$resolve_type_arg(t2, l1);
	if (l2.tag == 0u) {
		t1 = vader_front_comptime$arg_error(l0, 3419u);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t3 = vader_core_types$display_type(l2);
	t2 = vader_front_comptime$string_val(t3);
	t1 = vader_front_comptime$ok(t2);
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$intrinsic_variant_count(void* l0, void* l1) {
	vader_box_t l2 = vader_box_null();
	int64_t t0;
	void* t1 = NULL;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l2, &t2 };
	void** gc_raw_roots[3] = { &l0, &l1, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args));
	if (t0 != INT64_C(1)) {
		vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
		vader_obj_header_init(_a0_obj, 1656u);
		_a0_obj->f_value = vader_box_obj(0u, NULL);
		_a0_obj->f_diag = vader_box_obj(0u, NULL);
		_a0_obj->f_vm_required = false;
		t1 = (void*) _a0_obj;
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
	VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
	t2 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT32_C(0));
	l2 = vader_front_comptime$resolve_type_arg(t2, l1);
	if (l2.tag == 0u) {
		t1 = vader_front_comptime$arg_error(l0, 3693u);
		{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = vader_front_comptime$type_variant_count(l2);
	t2 = vader_front_comptime$int_val_typed(t0, 2651u);
	t1 = vader_front_comptime$ok(t2);
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_comptime$is_arithmetic(uint8_t l0) {
	bool l1, l2;
	if (l0 == INT32_C(0)) {
		l1 = true;
	} else {
		l1 = l0 == INT32_C(1);
	}
	if (l1) {
		l2 = true;
	} else {
		l2 = l0 == INT32_C(2);
	}
	if (l2) {
		l2 = true;
	} else {
		l2 = l0 == INT32_C(3);
	}
	if (l2) {
		l2 = true;
	} else {
		l2 = l0 == INT32_C(4);
	}
	if (l2) {
		l1 = true;
		return l1;
	}
	if (l0 == INT32_C(5)) {
		l2 = true;
	} else {
		l2 = l0 == INT32_C(6);
	}
	if (l2) {
		l2 = true;
	} else {
		l2 = l0 == INT32_C(7);
	}
	if (l2) {
		l2 = true;
	} else {
		l2 = l0 == INT32_C(8);
	}
	if (l2) {
		l2 = true;
	} else {
		l2 = l0 == INT32_C(9);
	}
	if (l2) {
		l2 = true;
	} else {
		l2 = l0 == INT32_C(23);
	}
	if (l2) {
		l2 = true;
	} else {
		l2 = l0 == INT32_C(24);
	}
	if (l2) {
		l2 = true;
	} else {
		l2 = l0 == INT32_C(25);
	}
	if (l2) {
		l1 = false;
	} else {
		if (l0 == INT32_C(10)) {
			l2 = true;
		} else {
			l2 = l0 == INT32_C(11);
		}
		if (l2) {
			l2 = true;
		} else {
			l2 = l0 == INT32_C(12);
		}
		if (l2) {
			l2 = true;
		} else {
			l2 = l0 == INT32_C(13);
		}
		if (l2) {
			l2 = true;
		} else {
			l2 = l0 == INT32_C(14);
		}
		if (l2) {
			l2 = true;
		} else {
			l2 = l0 == INT32_C(15);
		}
		if (l2) {
			l2 = true;
		} else {
			l2 = l0 == INT32_C(16);
		}
		if (l2) {
			l2 = true;
		} else {
			l2 = l0 == INT32_C(17);
		}
		if (l2) {
			l1 = false;
		} else {
			if (l0 == INT32_C(18)) {
				l2 = true;
			} else {
				l2 = l0 == INT32_C(19);
			}
			if (l2) {
				l2 = true;
			} else {
				l2 = l0 == INT32_C(20);
			}
			if (l2) {
				l2 = true;
			} else {
				l2 = l0 == INT32_C(21);
			}
			if (l2) {
				l2 = true;
			} else {
				l2 = l0 == INT32_C(22);
			}
			if (!(l2)) {
				vader_unreachable("non-exhaustive match (T3013 should have caught this)");
			}
			l1 = false;
		}
	}
	return l1;
}

static bool vader_front_comptime$is_computed(vader_box_t l0, void* l1) {
	void* l2;
	void* l5;
	uint64_t l3;
	vader_box_t l4;
	int32_t l6;
	vader_box_t t0;
	l2 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l1)->f_typed)->f_resolved)->f_idents;
	l3 = toolchain_span$Span$std_core$Hash$hash(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l0.payload.obj));
	l4 = std_collections$Map$std_core$Index$at__u64__Any(l2, l3);
	if (l4.tag == 0u) {
		return true;
	}
	l2 = l4.payload.obj;
	l5 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l1)->f_comptime_decls;
	l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_id;
	t0 = std_collections$Map$std_core$Index$at__i32__Any(l5, l6);
	return !(t0.tag == 0u);
}

static bool vader_front_comptime$is_resolved(vader_box_t l0) {
	if (!(l0.tag == 1495u)) {
		return true;
	}
	return false;
}

static vader_box_t vader_front_comptime$literal_of(vader_box_t l0, void* l1) {
	vader_box_t l2 = vader_box_null();
	double l3;
	bool l4;
	uint32_t l5;
	vader_string_t l6 = 0;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t* gc_roots[2] = { &l0, &l2 };
	void** gc_raw_roots[2] = { &l1, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l6, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l0.tag == 1660u) {
		t0 = l0.payload.obj;
		l2 = vader_front_comptime$int_literal(t0, l1);
		{ vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l0.tag == 1659u) {
		t0 = l0.payload.obj;
		l3 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_value;
		vader_struct_toolchain_ast$FloatLitExpr_t* _a0_obj = (vader_struct_toolchain_ast$FloatLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FloatLitExpr_t));
		vader_obj_header_init(_a0_obj, 1161u);
		_a0_obj->f_span = l1;
		_a0_obj->f_id = INT64_C(0);
		_a0_obj->f_value = l3;
		t0 = (void*) _a0_obj;
		l2 = vader_ref_box(t0);
	} else if (l0.tag == 1649u) {
		t0 = l0.payload.obj;
		l4 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
		vader_struct_toolchain_ast$BoolLitExpr_t* _a1_obj = (vader_struct_toolchain_ast$BoolLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$BoolLitExpr_t));
		vader_obj_header_init(_a1_obj, 1132u);
		_a1_obj->f_span = l1;
		_a1_obj->f_id = INT64_C(0);
		_a1_obj->f_value = l4;
		t0 = (void*) _a1_obj;
		l2 = vader_ref_box(t0);
	} else if (l0.tag == 1650u) {
		t0 = l0.payload.obj;
		l5 = ((vader_struct_vader_front_comptime$CharValue_t*) t0)->f_value;
		vader_struct_toolchain_ast$CharLitExpr_t* _a2_obj = (vader_struct_toolchain_ast$CharLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$CharLitExpr_t));
		vader_obj_header_init(_a2_obj, 1137u);
		_a2_obj->f_span = l1;
		_a2_obj->f_id = INT64_C(0);
		_a2_obj->f_value = l5;
		t0 = (void*) _a2_obj;
		l2 = vader_ref_box(t0);
	} else if (l0.tag == 1666u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_vader_front_comptime$StringValue_t*) t0)->f_value;
		l2 = vader_front_comptime$string_literal(t1, l1);
	} else if (l0.tag == 1664u) {
		vader_struct_toolchain_ast$NullLitExpr_t* _a3_obj = (vader_struct_toolchain_ast$NullLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$NullLitExpr_t));
		vader_obj_header_init(_a3_obj, 1189u);
		_a3_obj->f_span = l1;
		_a3_obj->f_id = INT64_C(0);
		t0 = (void*) _a3_obj;
		l2 = vader_ref_box(t0);
	} else if (l0.tag == 1655u) {
		t0 = l0.payload.obj;
		l6 = ((vader_struct_vader_front_comptime$EnumValue_t*) t0)->f_variant;
		vader_struct_toolchain_ast$DotVariantExpr_t* _a4_obj = (vader_struct_toolchain_ast$DotVariantExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DotVariantExpr_t));
		vader_obj_header_init(_a4_obj, 1152u);
		_a4_obj->f_span = l1;
		_a4_obj->f_id = INT64_C(0);
		_a4_obj->f_variant = l6;
		_a4_obj->f_variant_span = l1;
		t0 = (void*) _a4_obj;
		l2 = vader_ref_box(t0);
	} else if (l0.tag == 1647u) {
		t0 = l0.payload.obj;
		l2 = vader_front_comptime$array_literal(t0, l1);
	} else {
		if (!((l0.tag == 1667u || l0.tag == 1668u || l0.tag == 1670u))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l2 = vader_box_obj(0u, NULL);
	}
	{ vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$lookup_module_decls(void* l0, vader_string_t l1) {
	void* l2 = NULL;
	vader_box_t l3 = vader_box_null();
	int64_t t0;
	void* t1 = NULL;
	vader_box_t* gc_roots[1] = { &l3 };
	void** gc_raw_roots[3] = { &l0, &l2, &t1 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules, l1);
	if (l3.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l2 = l3.payload.obj;
	l2 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_module)->f_files;
	t0 = vader_array_length(((vader_array_t*) l2));
	if (!(t0 == INT64_C(0))) {
		t1 = vader_front_resolver$concat_file_decls(l2);
		{ vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_front_comptime$mask_shift_amount(vader_box_t l0, vader_string_t l1) {
	int64_t l2, l3;
	vader_string_t l4 = 0;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l0, &t1 };
	void** gc_raw_roots[1] = { &t0 };
	vader_string_t* gc_atom_roots[2] = { &l1, &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (!(l0.tag == 1660u)) {
		{ vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l0.payload.obj;
	l2 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
	l3 = vader_front_comptime$shift_amount_mask(l1);
	l2 = (l2 & l3);
	t0 = l0.payload.obj;
	l4 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_type_name;
	t1 = vader_front_comptime$int_val_typed(l2, l4);
	{ vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$module_context(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l0)->f_typed;
	l3 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l0)->f_comptime_decls;
	vader_struct_vader_front_comptime$ComptimeContext_t* _a0_obj = (vader_struct_vader_front_comptime$ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ComptimeContext_t));
	vader_obj_header_init(_a0_obj, 1652u);
	_a0_obj->f_typed = l2;
	_a0_obj->f_bindings = l3;
	_a0_obj->f_depth = INT64_C(0);
	_a0_obj->f_project = l1;
	t0 = (void*) _a0_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$new_evaluated_program(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 633u);
	l1 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 641u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 633u);
	l3 = (void*) _a2_arr;
	vader_struct_std_collections$Map__i32__Any_t* _a3_obj = (vader_struct_std_collections$Map__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__Any_t));
	vader_obj_header_init(_a3_obj, 901u);
	_a3_obj->f_ekeys = l1;
	_a3_obj->f_evals = l2;
	_a3_obj->f_index = l3;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l1 = (void*) _a3_obj;
	vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 633u);
	l2 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(31u, 0u, 1u, 635u);
	l3 = (void*) _a5_arr;
	vader_array_t* _a6_arr = vader_array_new(29u, 0u, 7u, 633u);
	l4 = (void*) _a6_arr;
	vader_struct_std_collections$Map__i32__vader_front_comptime_ComptimeRoute_t* _a7_obj = (vader_struct_std_collections$Map__i32__vader_front_comptime_ComptimeRoute_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i32__vader_front_comptime_ComptimeRoute_t));
	vader_obj_header_init(_a7_obj, 932u);
	_a7_obj->f_ekeys = l2;
	_a7_obj->f_evals = l3;
	_a7_obj->f_index = l4;
	_a7_obj->f_mask = INT64_C(0);
	_a7_obj->f_grow_at = INT64_C(0);
	_a7_obj->f_size = INT64_C(0);
	_a7_obj->f_tombs = INT64_C(0);
	l2 = (void*) _a7_obj;
	vader_array_t* _a8_arr = vader_array_new(279u, 0u, 13u, 1648u);
	l3 = (void*) _a8_arr;
	vader_array_t* _a9_arr = vader_array_new(30u, 0u, 8u, 634u);
	l4 = (void*) _a9_arr;
	vader_array_t* _a10_arr = vader_array_new(35u, 0u, 0u, 641u);
	l5 = (void*) _a10_arr;
	vader_array_t* _a11_arr = vader_array_new(29u, 0u, 7u, 633u);
	l6 = (void*) _a11_arr;
	vader_struct_std_collections$Map__i64__Any_t* _a12_obj = (vader_struct_std_collections$Map__i64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i64__Any_t));
	vader_obj_header_init(_a12_obj, 950u);
	_a12_obj->f_ekeys = l4;
	_a12_obj->f_evals = l5;
	_a12_obj->f_index = l6;
	_a12_obj->f_mask = INT64_C(0);
	_a12_obj->f_grow_at = INT64_C(0);
	_a12_obj->f_size = INT64_C(0);
	_a12_obj->f_tombs = INT64_C(0);
	l4 = (void*) _a12_obj;
	vader_array_t* _a13_arr = vader_array_new(350u, 0u, 13u, 1805u);
	l5 = (void*) _a13_arr;
	vader_struct_vader_front_comptime$EvaluatedProgram_t* _a14_obj = (vader_struct_vader_front_comptime$EvaluatedProgram_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvaluatedProgram_t));
	vader_obj_header_init(_a14_obj, 1657u);
	_a14_obj->f_typed = l0;
	_a14_obj->f_comptime_decls = l1;
	_a14_obj->f_routes = l2;
	_a14_obj->f_asserts = l3;
	_a14_obj->f_decorator_values = l4;
	_a14_obj->f_awaiting_decorators = l5;
	t0 = (void*) _a14_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$new_evaluated_project(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 630u);
	l1 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 641u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 633u);
	l3 = (void*) _a2_arr;
	vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
	vader_obj_header_init(_a3_obj, 987u);
	_a3_obj->f_ekeys = l1;
	_a3_obj->f_evals = l2;
	_a3_obj->f_index = l3;
	_a3_obj->f_mask = INT64_C(0);
	_a3_obj->f_grow_at = INT64_C(0);
	_a3_obj->f_size = INT64_C(0);
	_a3_obj->f_tombs = INT64_C(0);
	l1 = (void*) _a3_obj;
	vader_array_t* _a4_arr = vader_array_new(284u, 0u, 13u, 1669u);
	l2 = (void*) _a4_arr;
	vader_array_t* _a5_arr = vader_array_new(30u, 0u, 8u, 634u);
	l3 = (void*) _a5_arr;
	vader_array_t* _a6_arr = vader_array_new(35u, 0u, 0u, 641u);
	l4 = (void*) _a6_arr;
	vader_array_t* _a7_arr = vader_array_new(29u, 0u, 7u, 633u);
	l5 = (void*) _a7_arr;
	vader_struct_std_collections$Map__i64__Any_t* _a8_obj = (vader_struct_std_collections$Map__i64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i64__Any_t));
	vader_obj_header_init(_a8_obj, 950u);
	_a8_obj->f_ekeys = l3;
	_a8_obj->f_evals = l4;
	_a8_obj->f_index = l5;
	_a8_obj->f_mask = INT64_C(0);
	_a8_obj->f_grow_at = INT64_C(0);
	_a8_obj->f_size = INT64_C(0);
	_a8_obj->f_tombs = INT64_C(0);
	l3 = (void*) _a8_obj;
	vader_array_t* _a9_arr = vader_array_new(30u, 0u, 8u, 634u);
	l4 = (void*) _a9_arr;
	vader_array_t* _a10_arr = vader_array_new(35u, 0u, 0u, 641u);
	l5 = (void*) _a10_arr;
	vader_array_t* _a11_arr = vader_array_new(29u, 0u, 7u, 633u);
	l6 = (void*) _a11_arr;
	vader_struct_std_collections$Map__i64__Any_t* _a12_obj = (vader_struct_std_collections$Map__i64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i64__Any_t));
	vader_obj_header_init(_a12_obj, 950u);
	_a12_obj->f_ekeys = l4;
	_a12_obj->f_evals = l5;
	_a12_obj->f_index = l6;
	_a12_obj->f_mask = INT64_C(0);
	_a12_obj->f_grow_at = INT64_C(0);
	_a12_obj->f_size = INT64_C(0);
	_a12_obj->f_tombs = INT64_C(0);
	l4 = (void*) _a12_obj;
	vader_struct_vader_front_comptime$EvaluatedProject_t* _a13_obj = (vader_struct_vader_front_comptime$EvaluatedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvaluatedProject_t));
	vader_obj_header_init(_a13_obj, 1658u);
	_a13_obj->f_typed = l0;
	_a13_obj->f_modules = l1;
	_a13_obj->f_vm_required = l2;
	_a13_obj->f_libraries = l3;
	_a13_obj->f_interfaces = l4;
	t0 = (void*) _a13_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$normalize_int_result(void* l0, vader_string_t l1) {
	vader_box_t l2 = vader_box_null();
	int64_t l3;
	vader_string_t l4 = 0;
	void* t0 = NULL;
	int64_t t1;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l2, &t2 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l1, &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_front_comptime$EvalResult_t*) l0)->f_value;
	if (!(l2.tag == 1660u)) {
		{ void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l2.payload.obj;
	t1 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
	l3 = vader_front_comptime$wrap_to_width(t1, l1);
	t0 = l2.payload.obj;
	l4 = vader_front_comptime$result_type_name(t0, l1);
	t2 = vader_front_comptime$int_val_typed(l3, l4);
	t0 = vader_front_comptime$ok(t2);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_comptime$numbers_of_two_types(vader_box_t l0, vader_box_t l1) {
	vader_string_t l2, l3;
	void* t0;
	vader_string_t t1;
	if (l0.tag == 1660u) {
		if (l1.tag == 1660u) {
			t0 = l0.payload.obj;
			t1 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_type_name;
			if (t1 == 0u) {
				return true;
			}
			t0 = l0.payload.obj;
			l2 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_type_name;
			t0 = l1.payload.obj;
			l3 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_type_name;
			return l2 != l3;
		}
	}
	if (l0.tag == 1659u) {
		if (l1.tag == 1659u) {
			t0 = l0.payload.obj;
			t1 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_type_name;
			if (t1 == 0u) {
				return true;
			}
			t0 = l0.payload.obj;
			l2 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_type_name;
			t0 = l1.payload.obj;
			l3 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_type_name;
			return l2 != l3;
		}
		return false;
	}
	return false;
}

static void* vader_front_comptime$ok(vader_box_t l0) {
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l0 };
	void** gc_raw_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
	vader_obj_header_init(_a0_obj, 1656u);
	_a0_obj->f_value = l0;
	_a0_obj->f_diag = vader_box_obj(0u, NULL);
	_a0_obj->f_vm_required = false;
	t0 = (void*) _a0_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t vader_front_comptime$op_add(int64_t l0, int64_t l1) {
	return (l0 + l1);
}

bool vader_front_comptime$op_and(bool l0, bool l1) {
	if (l0) {
		return l1;
	}
	return false;
}

int64_t vader_front_comptime$op_bit_and(int64_t l0, int64_t l1) {
	return (l0 & l1);
}

int64_t vader_front_comptime$op_bit_or(int64_t l0, int64_t l1) {
	return (l0 | l1);
}

int64_t vader_front_comptime$op_bit_xor(int64_t l0, int64_t l1) {
	return (l0 ^ l1);
}

static int64_t vader_front_comptime$op_div(int64_t l0, int64_t l1) {
	int64_t t0;
	t0 = vader_div_i64(l0, l1);
	return t0;
}

int64_t vader_front_comptime$op_mod(int64_t l0, int64_t l1) {
	int64_t t0;
	t0 = vader_mod_i64(l0, l1);
	return t0;
}

int64_t vader_front_comptime$op_mul(int64_t l0, int64_t l1) {
	return (l0 * l1);
}

bool vader_front_comptime$op_or(bool l0, bool l1) {
	if (l0) {
		return true;
	}
	return l1;
}

int64_t vader_front_comptime$op_shl(int64_t l0, int64_t l1) {
	return (l0 << (l1 & 63));
}

int64_t vader_front_comptime$op_shr(int64_t l0, int64_t l1) {
	return (l0 >> (l1 & 63));
}

int64_t vader_front_comptime$op_sub(int64_t l0, int64_t l1) {
	return (l0 - l1);
}

static bool vader_front_comptime$owns_prototype(void* l0, void* l1) {
	int64_t l2;
	vader_box_t l3 = vader_box_null();
	void* t0 = NULL;
	int64_t t1;
	vader_box_t* gc_roots[1] = { &l3 };
	void** gc_raw_roots[3] = { &l0, &l1, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_id;
	l3 = std_collections$Map$std_core$Index$at__i64__Any(l1, l2);
	t0 = toolchain_ast$extern_headers(l0, l3);
	t1 = vader_array_length(((vader_array_t*) t0));
	{ bool __vret = (t1 > INT64_C(0)); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_comptime$path_beside(vader_string_t l0, vader_string_t l1) {
	vader_string_t t0 = 0;
	vader_string_t t1 = 0;
	vader_string_t* gc_atom_roots[4] = { &l0, &l1, &t0, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 4u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	t0 = vader_front_resolver$join_path(l0, l1);
	t1 = std_path$to_path(t0);
	t0 = std_path$normalize(t1);
	t1 = std_path$as_string(t0);
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$pattern_holds(vader_box_t l0, vader_box_t l1) {
	vader_string_t l2, l3;
	void* l4;
	int64_t l5, l6;
	vader_box_t l7;
	void* t0;
	vader_box_t t1;
	bool t2;
	if (l0.tag == 1221u) {
		return vader_box_bool(628u, true);
	}
	if (l0.tag == 1155u) {
		if (!(l1.tag == 1655u)) {
			return vader_box_obj(0u, NULL);
		}
		t0 = l1.payload.obj;
		l2 = ((vader_struct_vader_front_comptime$EnumValue_t*) t0)->f_variant;
		t0 = l0.payload.obj;
		l3 = ((vader_struct_toolchain_ast$EnumVariantPattern_t*) t0)->f_variant;
		return vader_box_bool(628u, l2 == l3);
	}
	if (!(l0.tag == 1190u)) {
		return vader_box_obj(0u, NULL);
	}
	t0 = l0.payload.obj;
	l4 = ((vader_struct_toolchain_ast$OrPattern_t*) t0)->f_patterns;
	l5 = vader_array_length(((vader_array_t*) l4));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t1 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
		l7 = vader_front_comptime$pattern_holds(t1, l1);
		if (l7.tag == 0u) {
			return vader_box_obj(0u, NULL);
		}
		t2 = l7.payload.b;
		if (t2) {
			return vader_box_bool(628u, true);
		}
		l6 = (l6 + INT64_C(1));
	}
	return vader_box_bool(628u, false);
}

static void vader_front_comptime$populate_deps(void* l0, void* l1) {
	void* l2 = NULL;
	void* l6 = NULL;
	void* l8 = NULL;
	void* l9 = NULL;
	void* l10 = NULL;
	void* l12 = NULL;
	void* l14 = NULL;
	void* l15 = NULL;
	int64_t l3, l4, l5;
	vader_box_t l7 = vader_box_null(), l11 = vader_box_null();
	int32_t l13;
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l7, &l11 };
	void** gc_raw_roots[11] = { &l0, &l1, &l2, &l6, &l8, &l9, &l10, &l12, &l14, &l15, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_front_comptime$Nodes_t*) l0)->f_order;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l5 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l4];
		l7 = std_collections$Map$std_core$Index$at__i64__Any(((vader_struct_vader_front_comptime$Nodes_t*) l0)->f_by_id, l5);
		if (l7.tag == 0u) {
			l4 = (l4 + INT64_C(1));
			continue;
		}
		l6 = l7.payload.obj;
		l9 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) l1)->f_resolved;
		l10 = ((vader_struct_toolchain_ast$ConstDecl_t*) ((vader_struct_vader_front_comptime$NodeRecord_t*) l6)->f_decl)->f_name_span;
		l11 = vader_front_resolver$symbol_declared_at(l9, l10);
		if (l11.tag == 0u) {
			l4 = (l4 + INT64_C(1));
			continue;
		}
		l8 = l11.payload.obj;
		l12 = ((vader_struct_vader_front_comptime$Nodes_t*) l0)->f_by_symbol;
		l13 = ((vader_struct_vader_core_symbol$Symbol_t*) l8)->f_id;
		std_collections$Map$std_core$IndexSet$set_at__i32__i64(l12, l13, l5);
		l4 = (l4 + INT64_C(1));
	}
	l2 = ((vader_struct_vader_front_comptime$Nodes_t*) l0)->f_order;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
		l5 = ((int64_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l4];
		l7 = std_collections$Map$std_core$Index$at__i64__Any(((vader_struct_vader_front_comptime$Nodes_t*) l0)->f_by_id, l5);
		if (l7.tag == 0u) {
			l4 = (l4 + INT64_C(1));
			continue;
		}
		l6 = l7.payload.obj;
		vader_array_t* _a2_arr = vader_array_new(30u, 0u, 8u, 634u);
		l8 = (void*) _a2_arr;
		vader_array_t* _a3_arr = vader_array_new(26u, 0u, 12u, 628u);
		l9 = (void*) _a3_arr;
		vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 633u);
		l10 = (void*) _a4_arr;
		vader_struct_std_collections$Map__i64__bool_t* _a5_obj = (vader_struct_std_collections$Map__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i64__bool_t));
		vader_obj_header_init(_a5_obj, 953u);
		_a5_obj->f_ekeys = l8;
		_a5_obj->f_evals = l9;
		_a5_obj->f_index = l10;
		_a5_obj->f_mask = INT64_C(0);
		_a5_obj->f_grow_at = INT64_C(0);
		_a5_obj->f_size = INT64_C(0);
		_a5_obj->f_tombs = INT64_C(0);
		t0 = (void*) _a5_obj;
		vader_struct_std_collections$Set__i64_t* _a6_obj = (vader_struct_std_collections$Set__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i64_t));
		vader_obj_header_init(_a6_obj, 1090u);
		_a6_obj->f_inner = t0;
		l12 = (void*) _a6_obj;
		l11 = toolchain_ast$written_value(((vader_struct_vader_front_comptime$NodeRecord_t*) l6)->f_decl);
		vader_struct___lambda_env_vader_front_comptime_11_t* _a7_obj = (vader_struct___lambda_env_vader_front_comptime_11_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_comptime_11_t));
		vader_obj_header_init(_a7_obj, 711u);
		_a7_obj->f_cap_0 = l1;
		_a7_obj->f_cap_1 = l0;
		_a7_obj->f_cap_2 = l12;
		_a7_obj->f_cap_3 = l6;
		t0 = (void*) _a7_obj;
		vader_fn_t* _a8_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
		vader_obj_header_init(_a8_closure, 615u);
		_a8_closure->code = (void*) &vader_fn_lift___lambda_vader_front_comptime_10;
		_a8_closure->env = t0;
		l14 = (void*) _a8_closure;
		l15 = (void*) &vader_fn_static_toolchain_ast$ignore_node;
		toolchain_ast$inspect(l11, l14, l15);
		std_collections$Map$std_core$IndexSet$set_at__i64__Any(((vader_struct_vader_front_comptime$Nodes_t*) l0)->f_by_id, l5, vader_ref_box(l6));
		l4 = (l4 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_front_comptime$record_decorator_value(void* l0, void* l1, void* l2, void* l3) {
	void* l4 = NULL;
	void* l6 = NULL;
	vader_box_t l5 = vader_box_null();
	int64_t l7;
	vader_box_t* gc_roots[1] = { &l5 };
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l5 = vader_front_comptime$decorator_value(l1, l2, l3);
	if (l5.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l4 = l5.payload.obj;
	l6 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l0)->f_decorator_values;
	l7 = ((vader_struct_toolchain_ast$Decorator_t*) ((vader_struct_vader_front_typecheck$DecoratorUse_t*) l1)->f_written)->f_id;
	vader_struct_vader_front_comptime$DecoratorValue_t* _a0_obj = (vader_struct_vader_front_comptime$DecoratorValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$DecoratorValue_t));
	vader_obj_header_init(_a0_obj, 1654u);
	_a0_obj->f_use = l1;
	_a0_obj->f_value = l4;
	l4 = (void*) _a0_obj;
	std_collections$Map$std_core$IndexSet$set_at__i64__Any(l6, l7, vader_ref_box(l4));
	{ vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_front_comptime$render_array(void* l0) {
	void* l1 = NULL;
	void* l7 = NULL;
	int64_t l2, l3, l5;
	bool l4;
	vader_string_t l6 = 0;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[1] = { &t1 };
	void** gc_raw_roots[4] = { &l0, &l1, &l7, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l6, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 630u);
	t0 = (void*) _a0_arr;
	vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
	vader_obj_header_init(_a1_obj, 1120u);
	_a1_obj->f_parts = t0;
	l1 = (void*) _a1_obj;
	std_string__builder$append_char(l1, 91u);
	l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_comptime$ArrayValue_t*) l0)->f_elements));
	l3 = ((int64_t) 16);
	l4 = (l2 > l3);
	if (l4) {
		l3 = ((int64_t) 8);
	} else {
		l3 = l2;
	}
	l5 = INT64_C(0);
	while ((l5 < l3)) {
		if ((l5 > INT64_C(0))) {
			std_string__builder$append(l1, 441u);
		}
		vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_front_comptime$ArrayValue_t*) l0)->f_elements);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
		t1 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
		l6 = vader_front_comptime$display_value(t1);
		std_string__builder$append(l1, l6);
		l5 = (l5 + INT64_C(1));
	}
	if (l4) {
		l7 = (void*) vader_buffer_new((size_t) INT64_C(35));
		l3 = INT64_C(0);
		l3 = std_core$write_string_at(l7, l3, 444u);
		l3 = std_core$write_int(l7, l3, l2);
		l3 = std_core$write_string_at(l7, l3, 146u);
		l6 = std_core$finish_buffer(l7, l3);
		std_string__builder$append(l1, l6);
	}
	std_string__builder$append_char(l1, 93u);
	t2 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
	{ vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_comptime$render_struct(void* l0) {
	void* l1 = NULL;
	void* l3 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	vader_string_t l2 = 0;
	vader_string_t l10 = 0;
	int64_t l4, l7;
	vader_box_t l8 = vader_box_null(), l9 = vader_box_null();
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[3] = { &l8, &l9, &t1 };
	void** gc_raw_roots[6] = { &l0, &l1, &l3, &l5, &l6, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l2, &l10, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 630u);
	t0 = (void*) _a0_arr;
	vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
	vader_obj_header_init(_a1_obj, 1120u);
	_a1_obj->f_parts = t0;
	l1 = (void*) _a1_obj;
	l2 = vader_core_types$display_type(((vader_struct_vader_front_comptime$StructValue_t*) l0)->f_type);
	std_string__builder$append(l1, l2);
	std_string__builder$append(l1, 301u);
	l3 = ((vader_struct_vader_front_comptime$StructValue_t*) l0)->f_fields;
	l4 = ((vader_struct_std_collections$Map__string__vader_front_comptime_ArrayValue___vader_front_comptime_BoolValue___vader_front_comptime_CharValue___vader_front_comptime_EnumValue___vader_front_comptime_FloatValue___vader_front_comptime_IntValue___vader_front_comptime_NullValue___vader_front_comptime_StringValue___vader_front_comptime_StructValue___vader_front_comptime_TypeValue___vader_front_comptime_VoidValue_t*) l3)->f_size;
	if ((INT64_C(0) < l4)) {
		l4 = ((vader_struct_std_collections$Map__string__vader_front_comptime_ArrayValue___vader_front_comptime_BoolValue___vader_front_comptime_CharValue___vader_front_comptime_EnumValue___vader_front_comptime_FloatValue___vader_front_comptime_IntValue___vader_front_comptime_NullValue___vader_front_comptime_StringValue___vader_front_comptime_StructValue___vader_front_comptime_TypeValue___vader_front_comptime_VoidValue_t*) l3)->f_size;
	} else {
		l4 = INT64_C(0);
	}
	vader_array_t* _a2_arr = vader_array_reserve(28u, (int64_t) l4, 0u, 630u);
	l5 = (void*) _a2_arr;
	l6 = ((vader_struct_std_collections$Map__string__vader_front_comptime_ArrayValue___vader_front_comptime_BoolValue___vader_front_comptime_CharValue___vader_front_comptime_EnumValue___vader_front_comptime_FloatValue___vader_front_comptime_IntValue___vader_front_comptime_NullValue___vader_front_comptime_StringValue___vader_front_comptime_StructValue___vader_front_comptime_TypeValue___vader_front_comptime_VoidValue_t*) l3)->f_ekeys;
	l4 = INT64_C(0);
	l7 = ((vader_struct_std_collections$Map__string__vader_front_comptime_ArrayValue___vader_front_comptime_BoolValue___vader_front_comptime_CharValue___vader_front_comptime_EnumValue___vader_front_comptime_FloatValue___vader_front_comptime_IntValue___vader_front_comptime_NullValue___vader_front_comptime_StringValue___vader_front_comptime_StructValue___vader_front_comptime_TypeValue___vader_front_comptime_VoidValue_t*) l3)->f_size;
	while ((l4 < l7)) {
		vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l4)
		t1 = vader_array_box_slots(_a3_slotarr->buf)[vader_array_offset(_a3_slotarr) + (size_t) l4];
		l2 = t1.payload.s;
		vader_array_push_scalar((vader_array_t*) l5, vader_box_string(630u, l2));
		l4 = (l4 + INT64_C(1));
	}
	l3 = (void*) &vader_fn_static_std_string$compare_ascending;
	l3 = std_sort$sort__string(l5, l3);
	l4 = INT64_C(0);
	l7 = vader_array_length(((vader_array_t*) l3));
	while ((l4 < l7)) {
		vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
		t1 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l4];
		l2 = t1.payload.s;
		l9 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_front_comptime$StructValue_t*) l0)->f_fields, l2);
		if (l9.tag == 0u) {
			l4 = (l4 + INT64_C(1));
			continue;
		}
		l8 = l9;
		if ((l4 > INT64_C(0))) {
			std_string__builder$append(l1, 441u);
		}
		std_string__builder$append_char(l1, 46u);
		std_string__builder$append(l1, l2);
		std_string__builder$append(l1, 107u);
		l10 = vader_front_comptime$display_value(l8);
		std_string__builder$append(l1, l10);
		l4 = (l4 + INT64_C(1));
	}
	std_string__builder$append(l1, 308u);
	t2 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
	{ vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_comptime$report_failure(void* l0, void* l1) {
	void* l2 = NULL;
	vader_box_t l3 = vader_box_null();
	vader_box_t* gc_roots[1] = { &l3 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = ((vader_struct_vader_front_comptime$EvalResult_t*) l0)->f_diag;
	if (l3.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l2 = l3.payload.obj;
	vader_array_push_ref((vader_array_t*) l1, l2);
	{ vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_front_comptime$resolve_type_arg(vader_box_t l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	vader_box_t l4 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l0, &l4 };
	void** gc_raw_roots[3] = { &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_resolved;
	l3 = vader_front_comptime$diag_sink();
	l4 = vader_front_typecheck$type_from_expr(l0, l2, l3);
	if (!(l4.tag == 1495u)) {
		{ vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_string_t vader_front_comptime$resolved_int_name(void* l0, int64_t l1) {
	vader_box_t l2;
	vader_string_t l3;
	l2 = std_collections$Map$std_core$Index$at__i64__Any(((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l0)->f_typed)->f_expr_types, l1);
	l3 = vader_core_types$primitive_name(l2);
	if (l3 != 0u) {
		return l3;
	}
	if (!(l2.tag == 1477u)) {
		return 0u;
	}
	return 2629u;
}

vader_box_t vader_front_comptime$resolved_interface(vader_box_t l0) {
	vader_string_t l1 = 0;
	vader_string_t l3 = 0;
	vader_string_t l4 = 0;
	vader_box_t l2 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l0, &l2 };
	void** gc_raw_roots[1] = { &t0 };
	vader_string_t* gc_atom_roots[3] = { &l1, &l3, &l4 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (!(l0.tag == 1667u)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	t0 = l0.payload.obj;
	l2 = vader_front_comptime$string_field(t0, 3042u);
	if (l2.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l1 = l2.payload.s;
	t0 = l0.payload.obj;
	l2 = vader_front_comptime$string_field(t0, 2933u);
	if (l2.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l3 = l2.payload.s;
	t0 = l0.payload.obj;
	l2 = vader_front_comptime$string_field(t0, 3695u);
	if (l2.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l4 = l2.payload.s;
	vader_struct_std_core$WasmInterface_t* _a0_obj = (vader_struct_std_core$WasmInterface_t*) vader_gc_alloc(sizeof(vader_struct_std_core$WasmInterface_t));
	vader_obj_header_init(_a0_obj, 1103u);
	_a0_obj->f_package = l1;
	_a0_obj->f_name = l3;
	_a0_obj->f_version = l4;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$resolved_library(vader_box_t l0, vader_string_t l1) {
	vader_string_t l2 = 0;
	vader_string_t l5 = 0;
	vader_string_t l11 = 0;
	vader_string_t l12 = 0;
	vader_box_t l3 = vader_box_null();
	void* l4 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	int64_t l9, l10;
	void* t0 = NULL;
	int64_t t1;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[3] = { &l0, &l3, &t2 };
	void** gc_raw_roots[5] = { &l4, &l6, &l7, &l8, &t0 };
	vader_string_t* gc_atom_roots[5] = { &l1, &l2, &l5, &l11, &l12 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (!(l0.tag == 1667u)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	t0 = l0.payload.obj;
	l3 = vader_front_comptime$string_field(t0, 2933u);
	if (l3.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l2 = l3.payload.s;
	t0 = l0.payload.obj;
	l3 = vader_front_comptime$strings_field(t0, 2624u);
	if (l3.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l4 = l3.payload.obj;
	t0 = l0.payload.obj;
	l3 = vader_front_comptime$string_field(t0, 2705u);
	if (l3.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l5 = l3.payload.s;
	t0 = l0.payload.obj;
	l3 = vader_front_comptime$strings_field(t0, 1995u);
	if (l3.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l6 = l3.payload.obj;
	t0 = l0.payload.obj;
	l3 = vader_front_comptime$strings_field(t0, 3286u);
	if (l3.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	l7 = l3.payload.obj;
	t1 = vader_array_length(((vader_array_t*) l6));
	vader_array_t* _a0_arr = vader_array_reserve(28u, (int64_t) t1, 0u, 630u);
	l8 = (void*) _a0_arr;
	l9 = vader_array_length(((vader_array_t*) l6));
	l10 = INT64_C(0);
	while ((l10 < l9)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l10)
		t2 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l10];
		l11 = t2.payload.s;
		l12 = vader_front_comptime$path_beside(l1, l11);
		vader_array_push_scalar((vader_array_t*) l8, vader_box_string(630u, l12));
		l10 = (l10 + INT64_C(1));
	}
	l5 = vader_front_comptime$folder_beside(l1, l5);
	vader_struct_std_core$CLibrary_t* _a2_obj = (vader_struct_std_core$CLibrary_t*) vader_gc_alloc(sizeof(vader_struct_std_core$CLibrary_t));
	vader_obj_header_init(_a2_obj, 1096u);
	_a2_obj->f_name = l2;
	_a2_obj->f_headers = l4;
	_a2_obj->f_include = l5;
	_a2_obj->f_archives = l8;
	_a2_obj->f_system = l7;
	t0 = (void*) _a2_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_front_comptime$restore_written_arguments(void* l0) {
	void* l1;
	void* l4;
	void* l5;
	void* l6;
	int64_t l2, l3;
	l1 = l0;
	l2 = vader_array_length(((vader_array_t*) l1));
	l3 = INT64_C(0);
	while ((l3 < l2)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l4 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
		l5 = ((vader_struct_vader_front_comptime$WrittenArguments_t*) l4)->f_written;
		l6 = ((vader_struct_vader_front_comptime$WrittenArguments_t*) l4)->f_args;
		((vader_struct_toolchain_ast$Decorator_t*) l5)->f_args = l6;
		VADER_WRITE_BARRIER((vader_struct_toolchain_ast$Decorator_t*) l5);
		l3 = (l3 + INT64_C(1));
	}
	return;
}

static vader_string_t vader_front_comptime$result_type_name(void* l0, vader_string_t l1) {
	vader_string_t t0;
	if (!(l1 != 0u)) {
		t0 = ((vader_struct_vader_front_comptime$IntValue_t*) l0)->f_type_name;
		return t0;
	}
	return l1;
}

static bool vader_front_comptime$runs_an_impl(void* l0, void* l1) {
	void* l2;
	int64_t l3;
	bool t0;
	vader_box_t t1;
	t0 = vader_front_comptime$is_arithmetic(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op);
	if (!(t0)) {
		return false;
	}
	l2 = vader_front_typecheck$sites_of(((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_call_sites, (uint8_t) 1);
	l3 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_id;
	t1 = std_collections$Map$std_core$Index$at__i64__Any(l2, l3);
	return (t1.tag == 1796u || t1.tag == 1809u || t1.tag == 1811u || t1.tag == 1854u);
}

static bool vader_front_comptime$same_kind(vader_box_t l0, vader_box_t l1) {
	bool l2;
	if (l0.tag == 1660u) {
		l2 = l1.tag == 1660u;
		return l2;
	}
	if (l0.tag == 1659u) {
		l2 = l1.tag == 1659u;
	} else if (l0.tag == 1649u) {
		l2 = l1.tag == 1649u;
	} else if (l0.tag == 1650u) {
		l2 = l1.tag == 1650u;
	} else if (l0.tag == 1666u) {
		l2 = l1.tag == 1666u;
	} else if (l0.tag == 1664u) {
		l2 = l1.tag == 1664u;
	} else if (l0.tag == 1670u) {
		l2 = l1.tag == 1670u;
	} else if (l0.tag == 1647u) {
		l2 = l1.tag == 1647u;
	} else if (l0.tag == 1667u) {
		l2 = l1.tag == 1667u;
	} else if (l0.tag == 1668u) {
		l2 = l1.tag == 1668u;
	} else {
		if (!(l0.tag == 1655u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l2 = l1.tag == 1655u;
	}
	return l2;
}

static bool vader_front_comptime$settles_alone(uint8_t l0, vader_box_t l1) {
	bool l2, l3;
	void* t0;
	bool t1;
	if (l1.tag == 1649u) {
		if (l0 == INT32_C(10)) {
			t0 = l1.payload.obj;
			t1 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
			l2 = !(t1);
		} else {
			l2 = false;
		}
		if (l2) {
			l2 = true;
		} else {
			if (l0 == INT32_C(11)) {
				t0 = l1.payload.obj;
				l3 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
			} else {
				l3 = false;
			}
			l2 = l3;
		}
		return l2;
	}
	return false;
}

static int64_t vader_front_comptime$shift_amount_mask(vader_string_t l0) {
	void* l1;
	vader_box_t l2;
	int64_t t0;
	l2 = vader_support_integer$machine_integer_named(l0);
	if (l2.tag == 0u) {
		return INT64_C(63);
	}
	l1 = l2.payload.obj;
	t0 = ((vader_struct_vader_support_integer$MachineInteger_t*) l1)->f_bits;
	if (!((t0 <= INT64_C(32)))) {
		return INT64_C(63);
	}
	return INT64_C(31);
}

static int64_t vader_front_comptime$sign_extend(int64_t l0, int64_t l1) {
	int64_t l2, l3, l4;
	int64_t t0;
	l2 = (INT64_C(1) << (l1 & 63));
	l3 = vader_chk_sub(i64, l2, INT64_C(1));
	l3 = (l0 & l3);
	l4 = (l2 >> INT64_C(1));
	if (!((l3 & l4) != INT64_C(0))) {
		return l3;
	}
	t0 = vader_chk_sub(i64, l3, l2);
	return t0;
}

static void* vader_front_comptime$sort_comptime_decls(void* l0, void* l1) {
	void* l2 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = vader_front_comptime$collect_nodes(l0);
	vader_front_comptime$populate_deps(l2, l1);
	t0 = vader_front_comptime$topo_sort(l2);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$string_field(void* l0, vader_string_t l1) {
	vader_box_t l2;
	void* t0;
	vader_string_t t1;
	l2 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_front_comptime$StructValue_t*) l0)->f_fields, l1);
	if (l2.tag == 0u) {
		return vader_box_obj(0u, NULL);
	}
	if (!(l2.tag == 1666u)) {
		return vader_box_obj(0u, NULL);
	}
	t0 = l2.payload.obj;
	t1 = ((vader_struct_vader_front_comptime$StringValue_t*) t0)->f_value;
	return vader_box_string(630u, t1);
}

static vader_box_t vader_front_comptime$string_literal(vader_string_t l0, void* l1) {
	void* l2 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[3] = { &l1, &l2, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_struct_toolchain_ast$StringLitText_t* _a0_obj = (vader_struct_toolchain_ast$StringLitText_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StringLitText_t));
	vader_obj_header_init(_a0_obj, 1204u);
	_a0_obj->f_value = l0;
	_a0_obj->f_span = l1;
	_a0_obj->f_id = INT64_C(0);
	t0 = (void*) _a0_obj;
	vader_array_t* _a1_arr = vader_array_new(475u, 1u, 13u, 2485u);
	((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0;
	l2 = (void*) _a1_arr;
	vader_struct_toolchain_ast$StringLitExpr_t* _a2_obj = (vader_struct_toolchain_ast$StringLitExpr_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StringLitExpr_t));
	vader_obj_header_init(_a2_obj, 1202u);
	_a2_obj->f_span = l1;
	_a2_obj->f_id = INT64_C(0);
	_a2_obj->f_parts = l2;
	t0 = (void*) _a2_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_front_comptime$string_val(vader_string_t l0) {
	void* t0 = NULL;
	void** gc_raw_roots[1] = { &t0 };
	vader_string_t* gc_atom_roots[1] = { &l0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_struct_vader_front_comptime$StringValue_t* _a0_obj = (vader_struct_vader_front_comptime$StringValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$StringValue_t));
	vader_obj_header_init(_a0_obj, 1666u);
	_a0_obj->f_value = l0;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$strings_field(void* l0, vader_string_t l1) {
	vader_box_t l2 = vader_box_null();
	void* l3 = NULL;
	void* l4 = NULL;
	int64_t l5, l6;
	vader_string_t l7 = 0;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l2 };
	void** gc_raw_roots[4] = { &l0, &l3, &l4, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l1, &l7 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_front_comptime$StructValue_t*) l0)->f_fields, l1);
	if (l2.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	if (!(l2.tag == 1647u)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 630u);
	l3 = (void*) _a0_arr;
	t0 = l2.payload.obj;
	l4 = ((vader_struct_vader_front_comptime$ArrayValue_t*) t0)->f_elements;
	l5 = vader_array_length(((vader_array_t*) l4));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l2 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
		if (!(l2.tag == 1666u)) {
			{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
		}
		t0 = l2.payload.obj;
		l7 = ((vader_struct_vader_front_comptime$StringValue_t*) t0)->f_value;
		vader_array_push_scalar((vader_array_t*) l3, vader_box_string(630u, l7));
		l6 = (l6 + INT64_C(1));
	}
	{ vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$symbol_span(void* l0, void* l1) {
	vader_box_t l2 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l2 };
	void** gc_raw_roots[3] = { &l0, &l1, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = toolchain_ast$extern_arguments(l1);
	l2 = ((vader_struct_toolchain_ast$ExternArguments_t*) t0)->f_symbol;
	if (l2.tag == 0u) {
		{ void* __vret = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name_span; vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ void* __vret = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l2.payload.obj); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$topo_sort(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	int64_t l7, l8, l9;
	void* t0 = NULL;
	int64_t t1;
	void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(65u, 0u, 13u, 1138u);
	l1 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_new(92u, 0u, 13u, 1226u);
	l2 = (void*) _a1_arr;
	vader_array_t* _a2_arr = vader_array_new(30u, 0u, 8u, 634u);
	l3 = (void*) _a2_arr;
	vader_array_t* _a3_arr = vader_array_new(29u, 0u, 7u, 633u);
	l4 = (void*) _a3_arr;
	vader_array_t* _a4_arr = vader_array_new(29u, 0u, 7u, 633u);
	l5 = (void*) _a4_arr;
	vader_struct_std_collections$Map__i64__i32_t* _a5_obj = (vader_struct_std_collections$Map__i64__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i64__i32_t));
	vader_obj_header_init(_a5_obj, 954u);
	_a5_obj->f_ekeys = l3;
	_a5_obj->f_evals = l4;
	_a5_obj->f_index = l5;
	_a5_obj->f_mask = INT64_C(0);
	_a5_obj->f_grow_at = INT64_C(0);
	_a5_obj->f_size = INT64_C(0);
	_a5_obj->f_tombs = INT64_C(0);
	l3 = (void*) _a5_obj;
	vader_array_t* _a6_arr = vader_array_new(30u, 0u, 8u, 634u);
	l4 = (void*) _a6_arr;
	vader_array_t* _a7_arr = vader_array_new(26u, 0u, 12u, 628u);
	l5 = (void*) _a7_arr;
	vader_array_t* _a8_arr = vader_array_new(29u, 0u, 7u, 633u);
	l6 = (void*) _a8_arr;
	vader_struct_std_collections$Map__i64__bool_t* _a9_obj = (vader_struct_std_collections$Map__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__i64__bool_t));
	vader_obj_header_init(_a9_obj, 953u);
	_a9_obj->f_ekeys = l4;
	_a9_obj->f_evals = l5;
	_a9_obj->f_index = l6;
	_a9_obj->f_mask = INT64_C(0);
	_a9_obj->f_grow_at = INT64_C(0);
	_a9_obj->f_size = INT64_C(0);
	_a9_obj->f_tombs = INT64_C(0);
	t0 = (void*) _a9_obj;
	vader_struct_std_collections$Set__i64_t* _a10_obj = (vader_struct_std_collections$Set__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__i64_t));
	vader_obj_header_init(_a10_obj, 1090u);
	_a10_obj->f_inner = t0;
	l4 = (void*) _a10_obj;
	l5 = ((vader_struct_vader_front_comptime$Nodes_t*) l0)->f_order;
	l7 = vader_array_length(((vader_array_t*) l5));
	l8 = INT64_C(0);
	while ((l8 < l7)) {
		vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
		VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
		l9 = ((int64_t*) _a11_slotarr->buf->slots)[vader_array_offset(_a11_slotarr) + (size_t) l8];
		std_collections$Map$std_core$IndexSet$set_at__i64__i32(l3, l9, INT32_C(0));
		l8 = (l8 + INT64_C(1));
	}
	vader_array_t* _a12_arr = vader_array_new(30u, 0u, 8u, 634u);
	l5 = (void*) _a12_arr;
	l6 = ((vader_struct_vader_front_comptime$Nodes_t*) l0)->f_order;
	l7 = vader_array_length(((vader_array_t*) l6));
	l8 = INT64_C(0);
	while ((l8 < l7)) {
		vader_array_t* _a13_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l8)
		t1 = ((int64_t*) _a13_slotarr->buf->slots)[vader_array_offset(_a13_slotarr) + (size_t) l8];
		vader_front_comptime$visit(t1, l0, l3, l4, l5, l1, l2);
		l8 = (l8 + INT64_C(1));
	}
	vader_struct_vader_front_comptime$ComptimeOrder_t* _a14_obj = (vader_struct_vader_front_comptime$ComptimeOrder_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ComptimeOrder_t));
	vader_obj_header_init(_a14_obj, 1653u);
	_a14_obj->f_order = l1;
	_a14_obj->f_cycle_diags = l2;
	t0 = (void*) _a14_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_front_comptime$type_field_count(vader_box_t l0, void* l1) {
	void* l2;
	int32_t l3;
	vader_box_t l4;
	void* t0;
	int64_t t1;
	if (l0.tag == 1485u) {
		l2 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_struct_fields;
		t0 = l0.payload.obj;
		l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_id;
		l4 = std_collections$Map$std_core$Index$at__i32__std_collections_Map_string__vader_front_typecheck_StructFieldInfo_(l2, l3);
		if (l4.tag == 0u) {
			return INT64_C(0);
		}
		t0 = l4.payload.obj;
		t1 = std_collections$len__string__Any(t0);
		return t1;
	}
	if (!(l0.tag == 1489u)) {
		return INT64_C(0);
	}
	t0 = l0.payload.obj;
	t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements));
	return t1;
}

static vader_box_t vader_front_comptime$type_from_expr_safe(void* l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	vader_box_t l4 = vader_box_null();
	bool t0;
	vader_box_t* gc_roots[1] = { &l4 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_resolved;
	l3 = vader_front_comptime$diag_sink();
	l4 = vader_front_typecheck$type_from_expr(vader_ref_box(l0), l2, l3);
	t0 = vader_front_comptime$is_resolved(l4);
	if (!(t0)) {
		{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
	}
	{ vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_front_comptime$type_kind_label(vader_box_t l0) {
	vader_string_t l1 = 0;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l0 };
	void** gc_raw_roots[1] = { &t0 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if ((l0.tag == 1482u || l0.tag == 1483u)) {
		l1 = 3070u;
		{ vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l0.tag == 1472u) {
		t0 = l0.payload.obj;
		l1 = vader_front_comptime$type_kind_label(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
	} else if (l0.tag == 1485u) {
		l1 = 3257u;
	} else if (l0.tag == 1473u) {
		l1 = 2395u;
	} else if (l0.tag == 1494u) {
		l1 = 3468u;
	} else if (l0.tag == 1471u) {
		l1 = 2008u;
	} else if (l0.tag == 1489u) {
		l1 = 3388u;
	} else if (l0.tag == 1474u) {
		l1 = 2536u;
	} else if (l0.tag == 1488u) {
		l1 = 3378u;
	} else if (l0.tag == 1490u) {
		l1 = 3398u;
	} else if (l0.tag == 1491u) {
		l1 = 3471u;
	} else if (l0.tag == 1478u) {
		t0 = l0.payload.obj;
		vader_core_types$leaked_infer_var(t0);
		vader_unreachable("a no-return call returned");
	} else if (l0.tag == 1484u) {
		l1 = 3471u;
	} else if (l0.tag == 1495u) {
		l1 = 3471u;
	} else if (l0.tag == 1477u) {
		l1 = 3471u;
	} else if (l0.tag == 1475u) {
		l1 = 3471u;
	} else if (l0.tag == 1476u) {
		l1 = 3471u;
	} else if (l0.tag == 1480u) {
		l1 = 3471u;
	} else {
		if (!(l0.tag == 1470u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = 1993u;
	}
	{ vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$type_mismatch(void* l0, vader_string_t l1) {
	void* l2 = NULL;
	void* t0 = NULL;
	void* t1 = NULL;
	void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span;
	t0 = toolchain_diagnostics$comptime_error((uint8_t) 3, l2, l1);
	t1 = vader_front_comptime$fail(t0);
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$type_val(vader_box_t l0) {
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l0 };
	void** gc_raw_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_struct_vader_front_comptime$TypeValue_t* _a0_obj = (vader_struct_vader_front_comptime$TypeValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$TypeValue_t));
	vader_obj_header_init(_a0_obj, 1668u);
	_a0_obj->f_value = l0;
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_front_comptime$type_variant_count(vader_box_t l0) {
	void* t0;
	int64_t t1;
	if (l0.tag == 1494u) {
		t0 = l0.payload.obj;
		t1 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants));
		return t1;
	}
	if (!(l0.tag == 1473u)) {
		return INT64_C(0);
	}
	t0 = l0.payload.obj;
	t1 = std_collections$len__string__i64(((vader_struct_vader_core_types$EnumType_t*) t0)->f_indices);
	return t1;
}

static void* vader_front_comptime$unary_bit_not(void* l0, vader_box_t l1) {
	int64_t l2;
	vader_string_t l3 = 0;
	void* t0 = NULL;
	int64_t t1;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l1, &t2 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (!(l1.tag == 1660u)) {
		t0 = vader_front_comptime$unary_type_mismatch(l0, 1788u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l1.payload.obj;
	t1 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
	l2 = vader_front_comptime$bit_not_i64(t1);
	t0 = l1.payload.obj;
	l3 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_type_name;
	t2 = vader_front_comptime$int_val_typed(l2, l3);
	t0 = vader_front_comptime$ok(t2);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$unary_neg(void* l0, vader_box_t l1, vader_string_t l2) {
	vader_string_t l3 = 0;
	int64_t l4, l6;
	bool l5;
	vader_box_t l7 = vader_box_null();
	double l8;
	void* t0 = NULL;
	double t1;
	vader_box_t t2 = vader_box_null();
	vader_box_t* gc_roots[3] = { &l1, &l7, &t2 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l1.tag == 1660u) {
		t0 = l1.payload.obj;
		l3 = vader_front_comptime$result_type_name(t0, l2);
		l4 = vader_front_comptime$int_bits_of(l3);
		l5 = vader_core_types$is_unsigned_int_name(l3);
		t0 = l1.payload.obj;
		l6 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
		l7 = vader_support_integer$checked_negation(l4, l5, l6);
		t0 = vader_front_comptime$checked_result(((vader_struct_toolchain_ast$UnaryExpr_t*) l0)->f_span, l7, l3);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l1.tag == 1659u)) {
		t0 = vader_front_comptime$unary_type_mismatch(l0, 1678u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l1.payload.obj;
	t1 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_value;
	l8 = -(t1);
	t0 = l1.payload.obj;
	l3 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_type_name;
	t2 = vader_front_comptime$float_val_typed(l8, l3);
	t0 = vader_front_comptime$ok(t2);
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$unary_not(void* l0, vader_box_t l1) {
	void* t0 = NULL;
	void* t2 = NULL;
	bool t1;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[3] = { &l0, &t0, &t2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (!(l1.tag == 1649u)) {
		t0 = vader_front_comptime$unary_type_mismatch(l0, 1625u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l1.payload.obj;
	t1 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
	if (!(t1)) {
		t0 = (void*) &vader_data_34;
		vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
		t2 = vader_front_comptime$ok(vader_ref_box(t0));
		{ void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = (void*) &vader_data_35;
	vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
	VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
	t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
	t2 = vader_front_comptime$ok(vader_ref_box(t0));
	{ void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$unary_type_mismatch(void* l0, vader_string_t l1) {
	void* l2 = NULL;
	void* t0 = NULL;
	void* t1 = NULL;
	void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$UnaryExpr_t*) l0)->f_span;
	t0 = toolchain_diagnostics$comptime_error((uint8_t) 3, l2, l1);
	t1 = vader_front_comptime$fail(t0);
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$value_arguments(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* l12 = NULL;
	void* l14 = NULL;
	void* l18 = NULL;
	int64_t l4, l8, l9;
	vader_string_t l10 = 0;
	vader_string_t l11 = 0;
	bool l13;
	vader_box_t l15 = vader_box_null(), l16 = vader_box_null(), l17 = vader_box_null();
	vader_box_t t0 = vader_box_null();
	bool t1;
	vader_box_t* gc_roots[4] = { &l15, &l16, &l17, &t0 };
	void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l5, &l6, &l7, &l12, &l14, &l18 };
	vader_string_t* gc_atom_roots[2] = { &l10, &l11 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 4u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(63u, 0u, 13u, 1134u);
	l3 = (void*) _a0_arr;
	l4 = INT64_C(0);
	l5 = l2;
	l6 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_StructFieldInfo_t*) l5)->f_ekeys;
	l7 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_StructFieldInfo_t*) l5)->f_evals;
	l8 = INT64_C(0);
	l9 = ((vader_struct_std_collections$Map__string__vader_front_typecheck_StructFieldInfo_t*) l5)->f_size;
	while ((l8 < l9)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
		t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l8];
		l10 = t0.payload.s;
		vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
		l5 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l8);
		l11 = l10;
		l12 = l5;
		l13 = ((vader_struct_toolchain_ast$StructField_t*) ((vader_struct_vader_front_typecheck$StructFieldInfo_t*) l12)->f_decl)->f_variadic;
		l14 = vader_front_comptime$written_span(l0, l11, l4, l13);
		t1 = ((vader_struct_toolchain_ast$StructField_t*) ((vader_struct_vader_front_typecheck$StructFieldInfo_t*) l12)->f_decl)->f_variadic;
		if (!(t1)) {
			l4 = vader_chk_add(i64, l4, INT64_C(1));
		}
		l15 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct_vader_front_comptime$StructValue_t*) l1)->f_fields, l11);
		if (!(l15.tag == 0u)) {
			l17 = vader_front_comptime$literal_of(l15, l14);
			if (!(l17.tag == 0u)) {
				l16 = l17;
				vader_struct_toolchain_ast$CallArg_t* _a3_obj = (vader_struct_toolchain_ast$CallArg_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$CallArg_t));
				vader_obj_header_init(_a3_obj, 1134u);
				_a3_obj->f_span = l14;
				_a3_obj->f_id = INT64_C(0);
				_a3_obj->f_name = vader_box_string(630u, l11);
				_a3_obj->f_value = l16;
				_a3_obj->f_spread = false;
				_a3_obj->f_comptime_body = vader_box_obj(0u, NULL);
				l18 = (void*) _a3_obj;
				vader_array_push_ref((vader_array_t*) l3, l18);
			}
		}
		l8 = (l8 + INT64_C(1));
	}
	{ void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$variant_equality(void* l0, bool l1, uint8_t l2) {
	void* l3 = NULL;
	bool l4;
	vader_box_t t0 = vader_box_null();
	vader_box_t* gc_roots[1] = { &t0 };
	void** gc_raw_roots[2] = { &l0, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l2 == INT32_C(0)) {
		t0 = vader_front_comptime$bool_value(l1);
		l3 = vader_front_comptime$ok(t0);
		{ void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l2 == INT32_C(1)) {
		t0 = vader_front_comptime$bool_value(!(l1));
		l3 = vader_front_comptime$ok(t0);
	} else {
		if (l2 == INT32_C(2)) {
			l4 = true;
		} else {
			l4 = l2 == INT32_C(3);
		}
		if (l4) {
			l4 = true;
		} else {
			l4 = l2 == INT32_C(4);
		}
		if (l4) {
			l4 = true;
		} else {
			l4 = l2 == INT32_C(5);
		}
		if (!(l4)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l3 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, 3034u);
	}
	{ void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$variant_value(void* l0, vader_string_t l1, void* l2) {
	int64_t l3;
	vader_box_t l4 = vader_box_null();
	void* t0 = NULL;
	void* t1 = NULL;
	vader_box_t* gc_roots[1] = { &l4 };
	void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (!(((vader_struct_vader_core_types$EnumType_t*) l0)->f_data.tag == 0u)) {
		t0 = vader_front_comptime$vm_required(l2, 3690u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l4 = std_collections$Map$std_core$Index$at__string__i64(((vader_struct_vader_core_types$EnumType_t*) l0)->f_indices, l1);
	if (l4.tag == 0u) {
		t0 = vader_front_comptime$vm_required(l2, 3474u);
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l3 = ((int64_t) l4.payload.i);
	vader_struct_vader_front_comptime$EnumValue_t* _a0_obj = (vader_struct_vader_front_comptime$EnumValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EnumValue_t));
	vader_obj_header_init(_a0_obj, 1655u);
	_a0_obj->f_enum_type = l0;
	_a0_obj->f_variant = l1;
	_a0_obj->f_value = l3;
	t0 = (void*) _a0_obj;
	t1 = vader_front_comptime$ok(vader_ref_box(t0));
	{ void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_comptime$visit(int64_t l0, void* l1, void* l2, void* l3, void* l4, void* l5, void* l6) {
	int32_t l7;
	vader_box_t l8 = vader_box_null();
	void* l9 = NULL;
	int64_t l10, l11;
	void* t0 = NULL;
	int64_t t1;
	vader_box_t t2 = vader_box_null();
	bool t3;
	vader_box_t* gc_roots[2] = { &l8, &t2 };
	void** gc_raw_roots[8] = { &l1, &l2, &l3, &l4, &l5, &l6, &l9, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l8 = std_collections$Map$std_core$Index$at__i64__i32(l2, l0);
	if (l8.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l7 = ((int32_t) l8.payload.i);
	if (l7 == INT32_C(2)) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l7 == INT32_C(1)) {
		vader_front_comptime$emit_cycle(l0, l4, l1, l3, l6);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	std_collections$Map$std_core$IndexSet$set_at__i64__i32(l2, l0, INT32_C(1));
	vader_array_push_i64((vader_array_t*) l4, l0);
	l8 = std_collections$Map$std_core$Index$at__i64__Any(((vader_struct_vader_front_comptime$Nodes_t*) l1)->f_by_id, l0);
	if (!(l8.tag == 0u)) {
		t0 = l8.payload.obj;
		l9 = ((vader_struct_vader_front_comptime$NodeRecord_t*) t0)->f_dependency_ids;
		l10 = vader_array_length(((vader_array_t*) l9));
		l11 = INT64_C(0);
		while ((l11 < l10)) {
			vader_array_t* _a0_slotarr = ((vader_array_t*) l9);
			VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l11)
			t1 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l11];
			vader_front_comptime$visit(t1, l1, l2, l3, l4, l5, l6);
			l11 = (l11 + INT64_C(1));
		}
	}
	t2 = vader_array_remove_last((vader_array_t*) l4);
	std_collections$Map$std_core$IndexSet$set_at__i64__i32(l2, l0, INT32_C(2));
	t3 = std_collections$Set$std_core$Contains$contains__i64(l3, l0);
	if (t3) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l8.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return; }
	}
	t0 = l8.payload.obj;
	l9 = ((vader_struct_vader_front_comptime$NodeRecord_t*) t0)->f_decl;
	vader_array_push_ref((vader_array_t*) l5, l9);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_comptime$vm_required(void* l0, vader_string_t l1) {
	void* l2 = NULL;
	void* t0 = NULL;
	void** gc_raw_roots[3] = { &l0, &l2, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = toolchain_diagnostics$comptime_error((uint8_t) 0, l0, l1);
	vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
	vader_obj_header_init(_a0_obj, 1656u);
	_a0_obj->f_value = vader_box_obj(0u, NULL);
	_a0_obj->f_diag = vader_ref_box(l2);
	_a0_obj->f_vm_required = true;
	t0 = (void*) _a0_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t vader_front_comptime$wrap_to_width(int64_t l0, vader_string_t l1) {
	void* l2;
	vader_box_t l3;
	int64_t l4, l5;
	int64_t t0;
	bool t1;
	l3 = vader_support_integer$machine_integer_named(l1);
	if (l3.tag == 0u) {
		return l0;
	}
	l2 = l3.payload.obj;
	t0 = ((vader_struct_vader_support_integer$MachineInteger_t*) l2)->f_bits;
	if (t0 == INT64_C(64)) {
		return l0;
	}
	t1 = ((vader_struct_vader_support_integer$MachineInteger_t*) l2)->f_is_signed;
	if (!(t1)) {
		l4 = ((vader_struct_vader_support_integer$MachineInteger_t*) l2)->f_bits;
		l5 = vader_chk_sub(i64, (INT64_C(1) << (l4 & 63)), INT64_C(1));
		return (l0 & l5);
	}
	l4 = ((vader_struct_vader_support_integer$MachineInteger_t*) l2)->f_bits;
	t0 = vader_front_comptime$sign_extend(l0, l4);
	return t0;
}

static void* vader_front_comptime$written_span(void* l0, vader_string_t l1, int64_t l2, bool l3) {
	vader_box_t l4;
	if (l3) {
		return ((vader_struct_toolchain_ast$Decorator_t*) l0)->f_span;
	}
	l4 = toolchain_ast$argument_named(l0, l1, l2);
	if (l4.tag == 0u) {
		return ((vader_struct_toolchain_ast$Decorator_t*) l0)->f_span;
	}
	return VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l4.payload.obj);
}
