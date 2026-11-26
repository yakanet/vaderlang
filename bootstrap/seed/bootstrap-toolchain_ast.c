#include "bootstrap.split.h"

static bool __lambda_toolchain_ast_0(void* l0, void* l1);
static void toolchain_ast$append_bitor_variants(vader_box_t l0, void* l1);
static vader_string_t toolchain_ast$c_header_of(void* l0);
static bool toolchain_ast$inspect_alias(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_arms(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_assign(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_call(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_clauses(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_const(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_decorators(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_defer(vader_box_t l0, void* l1, void* l2);
static bool toolchain_ast$inspect_enum(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_exprs(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_fn(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_fns(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_form(vader_box_t l0, void* l1, void* l2);
static bool toolchain_ast$inspect_if(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_impl(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_items(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_lambda(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_maybe(vader_box_t l0, void* l1, void* l2);
static bool toolchain_ast$inspect_params(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_parts(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_pattern_fields(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_patterns(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_stmts(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_struct(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_targets(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_trait(void* l0, void* l1, void* l2);
static bool toolchain_ast$inspect_type_params(void* l0, void* l1, void* l2);
static bool toolchain_ast$is_arith_op(uint8_t l0);
static vader_box_t toolchain_ast$own_const_type(void* l0);
static vader_box_t toolchain_ast$struct_item_value(vader_box_t l0);
static uint8_t toolchain_ast$take_first(vader_box_t l0, void* l1, void* l2);

vader_box_t vader_fn_tramp_toolchain_ast$ignore_node(void* env, vader_box_t a0) {
	(void) env;
	toolchain_ast$ignore_node(a0);
	return vader_box_obj(631u, NULL);
}

vader_fn_t vader_fn_static_toolchain_ast$ignore_node = {
	VADER_STATIC_HEADER(614u), (void*) &vader_fn_tramp_toolchain_ast$ignore_node, NULL,
};

vader_box_t vader_fn_lift___lambda_toolchain_ast_2(void* env, vader_box_t a0) {
	return vader_box_i32(635u, (int32_t)(uint32_t) __lambda_toolchain_ast_2(env, a0));
}

static bool __lambda_toolchain_ast_0(void* l0, void* l1) {
	uint8_t l2;
	bool t0;
	l2 = ((vader_struct___lambda_env_toolchain_ast_1_t*) l0)->f_cap_0;
	t0 = toolchain_ast$is_compiler(l1, l2);
	return t0;
}

uint8_t __lambda_toolchain_ast_2(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	uint8_t t0;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[3] = { &l0, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct___lambda_env_toolchain_ast_3_t*) l0)->f_cap_0;
	l3 = ((vader_struct___lambda_env_toolchain_ast_3_t*) l0)->f_cap_1;
	t0 = toolchain_ast$take_first(l1, l2, l3);
	{ uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t toolchain_ast$$genstate_decorator_sites$Iterator$next(void* l0) {
	int64_t l1, l2, l3, l6, l9, l10, l11, l12, l15, l18, l19, l20, l21, l24, l27;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	void* l13 = NULL;
	void* l14 = NULL;
	void* l16 = NULL;
	void* l17 = NULL;
	void* l22 = NULL;
	void* l23 = NULL;
	void* l25 = NULL;
	void* l26 = NULL;
	void* l29 = NULL;
	vader_string_t l28 = 0;
	int32_t t0;
	int64_t t1;
	void* t2 = NULL;
	void** gc_raw_roots[15] = {
		&l0, &l4, &l5, &l7, &l8, &l13, &l14, &l16, &l17, &l22, &l23, &l25, &l26, &l29, &t2,
	};
	vader_string_t* gc_atom_roots[1] = { &l28 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 15u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	for (;;) {
		t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
		if (t0 == INT32_C(0)) {
			((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(-1);
			continue;
		}
		t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
		if (t0 == INT32_C(1)) {
			((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(0);
		} else {
			t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
			if (t0 == INT32_C(2)) {
				((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(1);
			} else {
				t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
				if (t0 == INT32_C(3)) {
					((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(2);
				} else {
					t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
					if (t0 == INT32_C(4)) {
						((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(3);
					} else {
						t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
						if (t0 == INT32_C(5)) {
							l1 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s4;
							l2 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s3;
							if ((l1 < l2)) {
								((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(8);
							} else {
								((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(4);
							}
						} else {
							t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
							if (t0 == INT32_C(6)) {
								t1 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s4;
								l3 = (t1 + INT64_C(1));
								((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s4 = l3;
								((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(5);
							} else {
								t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
								if (t0 == INT32_C(7)) {
									((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(6);
									l4 = ((vader_struct_toolchain_ast$StructField_t*) ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s5)->f_decorators;
									vader_struct_toolchain_ast$DecoratorSite_t* _a0_obj = (vader_struct_toolchain_ast$DecoratorSite_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DecoratorSite_t));
									vader_obj_header_init(_a0_obj, 1142u);
									_a0_obj->f_place = 755u;
									_a0_obj->f_decorators = l4;
									t2 = (void*) _a0_obj;
									{ vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
								}
								t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
								if (t0 == INT32_C(8)) {
									l5 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s2;
									l6 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s4;
									vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
									VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
									VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
									l7 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
									((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s5 = l7;
									VADER_WRITE_BARRIER((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0);
									((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(7);
								} else {
									t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
									if (t0 == INT32_C(9)) {
										t2 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s0.payload.obj;
										l8 = ((vader_struct_toolchain_ast$StructDecl_t*) t2)->f_fields;
										((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s2 = l8;
										VADER_WRITE_BARRIER((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0);
										l9 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s2));
										((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s3 = l9;
										((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s4 = INT64_C(0);
										((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(5);
									} else {
										t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
										if (t0 == INT32_C(10)) {
											((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(1);
										} else {
											t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
											if (t0 == INT32_C(11)) {
												((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(10);
											} else {
												t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
												if (t0 == INT32_C(12)) {
													((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(11);
												} else {
													t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
													if (t0 == INT32_C(13)) {
														((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(12);
													} else {
														t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
														if (t0 == INT32_C(14)) {
															l10 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s8;
															l11 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s7;
															if ((l10 < l11)) {
																((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(17);
															} else {
																((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(13);
															}
														} else {
															t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
															if (t0 == INT32_C(15)) {
																t1 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s8;
																l12 = (t1 + INT64_C(1));
																((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s8 = l12;
																((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(14);
															} else {
																t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
																if (t0 == INT32_C(16)) {
																	((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(15);
																	l13 = ((vader_struct_toolchain_ast$EnumVariant_t*) ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s9)->f_decorators;
																	vader_struct_toolchain_ast$DecoratorSite_t* _a2_obj = (vader_struct_toolchain_ast$DecoratorSite_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DecoratorSite_t));
																	vader_obj_header_init(_a2_obj, 1142u);
																	_a2_obj->f_place = 1184u;
																	_a2_obj->f_decorators = l13;
																	t2 = (void*) _a2_obj;
																	{ vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
																}
																t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
																if (t0 == INT32_C(17)) {
																	l14 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s6;
																	l15 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s8;
																	vader_array_t* _a3_slotarr = ((vader_array_t*) l14);
																	VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
																	VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l15)
																	l16 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l15);
																	((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s9 = l16;
																	VADER_WRITE_BARRIER((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0);
																	((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(16);
																} else {
																	t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
																	if (t0 == INT32_C(18)) {
																		t2 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s0.payload.obj;
																		l17 = ((vader_struct_toolchain_ast$EnumDecl_t*) t2)->f_variants;
																		((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s6 = l17;
																		VADER_WRITE_BARRIER((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0);
																		l18 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s6));
																		((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s7 = l18;
																		((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s8 = INT64_C(0);
																		((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(14);
																	} else {
																		t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
																		if (t0 == INT32_C(19)) {
																			((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(10);
																		} else {
																			t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
																			if (t0 == INT32_C(20)) {
																				((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(19);
																			} else {
																				t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
																				if (t0 == INT32_C(21)) {
																					((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(20);
																				} else {
																					t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
																					if (t0 == INT32_C(22)) {
																						((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(21);
																					} else {
																						t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
																						if (t0 == INT32_C(23)) {
																							l19 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s12;
																							l20 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s11;
																							if ((l19 < l20)) {
																								((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(26);
																							} else {
																								((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(22);
																							}
																						} else {
																							t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
																							if (t0 == INT32_C(24)) {
																								t1 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s12;
																								l21 = (t1 + INT64_C(1));
																								((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s12 = l21;
																								((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(23);
																							} else {
																								t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
																								if (t0 == INT32_C(25)) {
																									((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(24);
																									l22 = ((vader_struct_toolchain_ast$FnParam_t*) ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s13)->f_decorators;
																									vader_struct_toolchain_ast$DecoratorSite_t* _a4_obj = (vader_struct_toolchain_ast$DecoratorSite_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DecoratorSite_t));
																									vader_obj_header_init(_a4_obj, 1142u);
																									_a4_obj->f_place = 928u;
																									_a4_obj->f_decorators = l22;
																									t2 = (void*) _a4_obj;
																									{ vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
																								}
																								t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
																								if (t0 == INT32_C(26)) {
																									l23 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s10;
																									l24 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s12;
																									vader_array_t* _a5_slotarr = ((vader_array_t*) l23);
																									VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
																									VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l24)
																									l25 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l24);
																									((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s13 = l25;
																									VADER_WRITE_BARRIER((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0);
																									((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(25);
																								} else {
																									t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
																									if (t0 == INT32_C(27)) {
																										t2 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s0.payload.obj;
																										l26 = ((vader_struct_toolchain_ast$FnDecl_t*) t2)->f_params;
																										((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s10 = l26;
																										VADER_WRITE_BARRIER((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0);
																										l27 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s10));
																										((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s11 = l27;
																										((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s12 = INT64_C(0);
																										((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(23);
																									} else {
																										t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
																										if (t0 == INT32_C(28)) {
																											((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(19);
																										} else {
																											t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
																											if (t0 == INT32_C(29)) {
																												((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(28);
																											} else {
																												t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
																												if (t0 == INT32_C(30)) {
																													if (((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s0.tag == 1162u) {
																														((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(27);
																													} else {
																														((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(29);
																													}
																												} else {
																													t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
																													if (t0 == INT32_C(31)) {
																														if (((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s0.tag == 1153u) {
																															((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(18);
																														} else {
																															((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(30);
																														}
																													} else {
																														t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
																														if (t0 == INT32_C(32)) {
																															if (((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s0.tag == 1205u) {
																																((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(9);
																															} else {
																																((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(31);
																															}
																														} else {
																															t0 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state;
																															if (!(t0 == INT32_C(33))) {
																																t2 = (void*) &vader_data_72;
																																vader_array_t* _a6_slotarr = ((vader_array_t*) t2);
																																VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
																																t2 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) INT64_C(0));
																																{ vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
																															}
																															((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_state = INT32_C(32);
																															l28 = ((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s1;
																															l29 = toolchain_ast$decl_decorators(((vader_struct_toolchain_ast$$genstate_decorator_sites_t*) l0)->f_s0);
																															vader_struct_toolchain_ast$DecoratorSite_t* _a7_obj = (vader_struct_toolchain_ast$DecoratorSite_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$DecoratorSite_t));
																															vader_obj_header_init(_a7_obj, 1142u);
																															_a7_obj->f_place = l28;
																															_a7_obj->f_decorators = l29;
																															t2 = (void*) _a7_obj;
																															{ vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
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
		continue;
	}
	vader_gc_top = gc_frame.prev;
}

static void toolchain_ast$append_bitor_variants(vader_box_t l0, void* l1) {
	void* l2 = NULL;
	vader_box_t l3 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l0, &l3 };
	void** gc_raw_roots[3] = { &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l0.tag == 1130u) {
		t0 = l0.payload.obj;
		if (((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_op == INT32_C(8)) {
			t0 = l0.payload.obj;
			toolchain_ast$append_bitor_variants(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_left, l1);
			t0 = l0.payload.obj;
			toolchain_ast$append_bitor_variants(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_right, l1);
			{ vader_gc_top = gc_frame.prev; return; }
		}
		l2 = l0.payload.obj;
		vader_array_push_ref((vader_array_t*) l1, l2);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	l3 = l0;
	vader_array_push_ref((vader_array_t*) l1, l3.payload.obj);
	{ vader_gc_top = gc_frame.prev; return; }
}

uint8_t toolchain_ast$arg_kind(uint8_t l0, int64_t l1) {
	void* l2 = NULL;
	int64_t l3;
	vader_box_t t0 = vader_box_null();
	vader_box_t* gc_roots[1] = { &t0 };
	void** gc_raw_roots[1] = { &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = toolchain_ast$intrinsic_args(l0);
	l3 = vader_array_length(((vader_array_t*) l2));
	if (!((l1 < l3))) {
		{ vader_gc_top = gc_frame.prev; return (uint8_t) 1; }
	}
	vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
	VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
	t0 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l1, 635u);
	{ uint8_t __vret = ((uint8_t) t0.payload.i); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t toolchain_ast$argument_named(void* l0, vader_string_t l1, int64_t l2) {
	int64_t l3, l5, l6;
	void* l4;
	void* l7;
	l3 = INT64_C(0);
	l4 = ((vader_struct_toolchain_ast$Decorator_t*) l0)->f_args;
	l5 = vader_array_length(((vader_array_t*) l4));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l7 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
		if (vader_box_eq(((vader_struct_toolchain_ast$CallArg_t*) l7)->f_name, vader_box_string(630u, l1))) {
			return ((vader_struct_toolchain_ast$CallArg_t*) l7)->f_value;
		}
		if (((vader_struct_toolchain_ast$CallArg_t*) l7)->f_name.tag == 0u) {
			if (l3 == l2) {
				return ((vader_struct_toolchain_ast$CallArg_t*) l7)->f_value;
			}
			l3 = vader_chk_add(i64, l3, INT64_C(1));
		}
		l6 = (l6 + INT64_C(1));
	}
	return vader_box_obj(0u, NULL);
}

void* toolchain_ast$assign_places(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	int64_t l3, l4;
	vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l5, &l6 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(468u, 0u, 13u, 2386u);
	l1 = (void*) _a0_arr;
	l2 = ((vader_struct_toolchain_ast$DestructureAssignStmt_t*) l0)->f_targets;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l5 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
		if ((l5.tag == 1193u || l5.tag == 1198u)) {
			l6 = VADER_UNION_FIELD(vader_box_t, vader_struct_toolchain_ast$PlaceTarget_t, f_place, l5.payload.obj);
			vader_array_push_ref((vader_array_t*) l1, l6.payload.obj);
		} else if (!(l5.tag == 1222u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l4 = (l4 + INT64_C(1));
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t toolchain_ast$binary_op_symbol(uint8_t l0) {
	vader_string_t l1;
	if (l0 == INT32_C(0)) {
		l1 = 434u;
		return l1;
	}
	if (l0 == INT32_C(1)) {
		l1 = 476u;
	} else if (l0 == INT32_C(2)) {
		l1 = 429u;
	} else if (l0 == INT32_C(3)) {
		l1 = 533u;
	} else if (l0 == INT32_C(4)) {
		l1 = 354u;
	} else if (l0 == INT32_C(5)) {
		l1 = 609u;
	} else if (l0 == INT32_C(6)) {
		l1 = 635u;
	} else if (l0 == INT32_C(7)) {
		l1 = 356u;
	} else if (l0 == INT32_C(8)) {
		l1 = 3809u;
	} else if (l0 == INT32_C(9)) {
		l1 = 1239u;
	} else if (l0 == INT32_C(10)) {
		l1 = 357u;
	} else if (l0 == INT32_C(11)) {
		l1 = 3810u;
	} else if (l0 == INT32_C(12)) {
		l1 = 627u;
	} else if (l0 == INT32_C(13)) {
		l1 = 312u;
	} else if (l0 == INT32_C(14)) {
		l1 = 608u;
	} else if (l0 == INT32_C(15)) {
		l1 = 610u;
	} else if (l0 == INT32_C(16)) {
		l1 = 630u;
	} else if (l0 == INT32_C(17)) {
		l1 = 634u;
	} else if (l0 == INT32_C(18)) {
		l1 = 2770u;
	} else if (l0 == INT32_C(19)) {
		l1 = 2704u;
	} else if (l0 == INT32_C(20)) {
		l1 = 314u;
	} else if (l0 == INT32_C(21)) {
		l1 = 628u;
	} else if (l0 == INT32_C(22)) {
		l1 = 313u;
	} else if (l0 == INT32_C(23)) {
		l1 = 435u;
	} else if (l0 == INT32_C(24)) {
		l1 = 477u;
	} else {
		if (!(l0 == INT32_C(25))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = 430u;
	}
	return l1;
}

void* toolchain_ast$body_source(void* l0) {
	vader_box_t l1;
	void* t0;
	l1 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_inherits;
	if (l1.tag == 0u) {
		return l0;
	}
	t0 = l1.payload.obj;
	return t0;
}

static vader_string_t toolchain_ast$c_header_of(void* l0) {
	vader_box_t l1 = vader_box_null();
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[1] = { &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l1 = toolchain_ast$find_compiler_decorator(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_decorators, (uint8_t) 5);
	if (l1.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return 0u; }
	}
	t0 = l1.payload.obj;
	t1 = toolchain_ast$string_field(t0, 2628u, INT64_C(0));
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t toolchain_ast$c_struct_spelling(void* l0, vader_string_t l1) {
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
	l2 = toolchain_ast$find_compiler_decorator(l0, (uint8_t) 7);
	if (l2.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return 0u; }
	}
	t0 = l2.payload.obj;
	l2 = toolchain_ast$argument_named(t0, 2938u, INT64_C(0));
	if (l2.tag == 0u) {
		{ vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = toolchain_ast$string_literal_text(l2);
	if (l2.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return 0u; }
	}
	t1 = l2.payload.s;
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t toolchain_ast$c_type_of(void* l0) {
	vader_box_t l1 = vader_box_null();
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[1] = { &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l1 = toolchain_ast$find_compiler_decorator(l0, (uint8_t) 8);
	if (l1.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return 0u; }
	}
	t0 = l1.payload.obj;
	t1 = toolchain_ast$string_field(t0, 2938u, INT64_C(0));
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t toolchain_ast$c_variadic_start(void* l0) {
	int64_t l1, l2;
	void* t0 = NULL;
	bool t1;
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l1 = INT64_C(0);
	l2 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params));
	while ((l1 < l2)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
		t1 = toolchain_ast$has_compiler_decorator(((vader_struct_toolchain_ast$FnParam_t*) t0)->f_decorators, (uint8_t) 9);
		if (t1) {
			{ int64_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
		}
		l1 = (l1 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return INT64_C(-1); }
}

void* toolchain_ast$collect_bitor_variants(vader_box_t l0) {
	void* l1 = NULL;
	vader_box_t* gc_roots[1] = { &l0 };
	void** gc_raw_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(468u, 0u, 13u, 2386u);
	l1 = (void*) _a0_arr;
	toolchain_ast$append_bitor_variants(l0, l1);
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t toolchain_ast$compiler_decorator_named(vader_string_t l0) {
	vader_box_t l1;
	if (l0 == 1947u) {
		l1 = vader_box_i32(635u, INT32_C(0));
		return l1;
	}
	if (l0 == 1953u) {
		l1 = vader_box_i32(635u, INT32_C(1));
	} else if (l0 == 2052u) {
		l1 = vader_box_i32(635u, INT32_C(2));
	} else if (l0 == 2163u) {
		l1 = vader_box_i32(635u, INT32_C(3));
	} else if (l0 == 2165u) {
		l1 = vader_box_i32(635u, INT32_C(4));
	} else if (l0 == 2174u) {
		l1 = vader_box_i32(635u, INT32_C(5));
	} else if (l0 == 2175u) {
		l1 = vader_box_i32(635u, INT32_C(6));
	} else if (l0 == 2176u) {
		l1 = vader_box_i32(635u, INT32_C(7));
	} else if (l0 == 2177u) {
		l1 = vader_box_i32(635u, INT32_C(8));
	} else if (l0 == 2178u) {
		l1 = vader_box_i32(635u, INT32_C(9));
	} else if (l0 == 2261u) {
		l1 = vader_box_i32(635u, INT32_C(10));
	} else if (l0 == 2335u) {
		l1 = vader_box_i32(635u, INT32_C(11));
	} else if (l0 == 2346u) {
		l1 = vader_box_i32(635u, INT32_C(12));
	} else if (l0 == 2393u) {
		l1 = vader_box_i32(635u, INT32_C(13));
	} else if (l0 == 2475u) {
		l1 = vader_box_i32(635u, INT32_C(14));
	} else if (l0 == 2739u) {
		l1 = vader_box_i32(635u, INT32_C(15));
	} else if (l0 == 2743u) {
		l1 = vader_box_i32(635u, INT32_C(16));
	} else if (l0 == 2874u) {
		l1 = vader_box_i32(635u, INT32_C(17));
	} else if (l0 == 2988u) {
		l1 = vader_box_i32(635u, INT32_C(18));
	} else if (l0 == 3062u) {
		l1 = vader_box_i32(635u, INT32_C(19));
	} else if (l0 == 3144u) {
		l1 = vader_box_i32(635u, INT32_C(20));
	} else if (l0 == 3179u) {
		l1 = vader_box_i32(635u, INT32_C(21));
	} else if (l0 == 3299u) {
		l1 = vader_box_i32(635u, INT32_C(22));
	} else if (l0 == 3310u) {
		l1 = vader_box_i32(635u, INT32_C(23));
	} else if (l0 == 3495u) {
		l1 = vader_box_i32(635u, INT32_C(24));
	} else {
		l1 = vader_box_obj(0u, NULL);
	}
	return l1;
}

vader_box_t toolchain_ast$compiler_decorator_of(void* l0) {
	vader_string_t t0;
	vader_box_t t1;
	if (!(((vader_struct_toolchain_ast$Decorator_t*) l0)->f_qualifier.tag == 0u)) {
		return vader_box_obj(0u, NULL);
	}
	t0 = ((vader_struct_toolchain_ast$Decorator_t*) l0)->f_name;
	t1 = toolchain_ast$compiler_decorator_named(t0);
	return t1;
}

vader_box_t toolchain_ast$compound_assign_op(void* l0) {
	vader_box_t l1;
	void* l2;
	void* l3;
	void* t0;
	bool t1;
	l1 = ((vader_struct_toolchain_ast$AssignStmt_t*) l0)->f_value;
	if (l1.tag == 1130u) {
		t0 = l1.payload.obj;
		l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_left.payload.obj);
		l3 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, ((vader_struct_toolchain_ast$AssignStmt_t*) l0)->f_target.payload.obj);
		t1 = toolchain_span$Span$std_core$Equals$equals(l2, l3);
		if (t1) {
			t0 = l1.payload.obj;
			t1 = toolchain_ast$is_arith_op(((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_op);
			if (t1) {
				t0 = l1.payload.obj;
				return vader_box_i32(635u, (int32_t)(uint32_t) ((vader_struct_toolchain_ast$BinaryExpr_t*) t0)->f_op);
			}
		}
		return vader_box_obj(0u, NULL);
	}
	return vader_box_obj(0u, NULL);
}

void* toolchain_ast$decl_decorators(vader_box_t l0) {
	void* l1;
	void* t0;
	if (l0.tag == 1172u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_decorators;
		return l1;
	}
	if (l0.tag == 1162u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators;
	} else if (l0.tag == 1205u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_decorators;
	} else if (l0.tag == 1153u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_decorators;
	} else if (l0.tag == 1213u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_decorators;
	} else if (l0.tag == 1171u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$ImplDecl_t*) t0)->f_decorators;
	} else if (l0.tag == 1215u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_decorators;
	} else if (l0.tag == 1138u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_decorators;
	} else {
		if (!(l0.tag == 1128u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$AssertDecl_t*) t0)->f_decorators;
	}
	return l1;
}

bool toolchain_ast$decl_is_public(vader_box_t l0) {
	bool l1;
	void* t0;
	if (l0.tag == 1162u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_visibility == INT32_C(0);
		return l1;
	}
	if (l0.tag == 1205u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_visibility == INT32_C(0);
	} else if (l0.tag == 1153u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_visibility == INT32_C(0);
	} else if (l0.tag == 1213u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_visibility == INT32_C(0);
	} else if (l0.tag == 1215u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_visibility == INT32_C(0);
	} else if (l0.tag == 1138u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_visibility == INT32_C(0);
	} else {
		if (!((l0.tag == 1128u || l0.tag == 1171u || l0.tag == 1172u))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = false;
	}
	return l1;
}

vader_box_t toolchain_ast$decl_name_span(vader_box_t l0) {
	vader_box_t l1;
	void* t0;
	void* t1;
	if (l0.tag == 1162u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name_span;
		l1 = vader_ref_box(t1);
		return l1;
	}
	if (l0.tag == 1205u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_name_span;
		l1 = vader_ref_box(t1);
	} else if (l0.tag == 1153u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_name_span;
		l1 = vader_ref_box(t1);
	} else if (l0.tag == 1213u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_name_span;
		l1 = vader_ref_box(t1);
	} else if (l0.tag == 1215u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_name_span;
		l1 = vader_ref_box(t1);
	} else if (l0.tag == 1138u) {
		t0 = l0.payload.obj;
		t1 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_name_span;
		l1 = vader_ref_box(t1);
	} else {
		if (!((l0.tag == 1128u || l0.tag == 1171u || l0.tag == 1172u))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = vader_box_obj(0u, NULL);
	}
	return l1;
}

void* toolchain_ast$decl_span(vader_box_t l0) {
	void* l1;
	void* t0;
	if (l0.tag == 1162u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_span;
		return l1;
	}
	if (l0.tag == 1205u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_span;
	} else if (l0.tag == 1153u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$EnumDecl_t*) t0)->f_span;
	} else if (l0.tag == 1213u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_span;
	} else if (l0.tag == 1171u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$ImplDecl_t*) t0)->f_span;
	} else if (l0.tag == 1215u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$TypeAliasDecl_t*) t0)->f_span;
	} else if (l0.tag == 1138u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_span;
	} else if (l0.tag == 1128u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$AssertDecl_t*) t0)->f_span;
	} else {
		if (!(l0.tag == 1172u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$ImportDecl_t*) t0)->f_span;
	}
	return l1;
}

vader_box_t toolchain_ast$decorator_sites(vader_box_t l0, vader_string_t l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	void* l5 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l0 };
	void** gc_raw_roots[7] = { &l2, &l3, &l4, &l5, &l6, &l7, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = vader_box_obj(0u, NULL).payload.obj;
	l3 = vader_box_obj(0u, NULL).payload.obj;
	l4 = vader_box_obj(0u, NULL).payload.obj;
	l5 = vader_box_obj(0u, NULL).payload.obj;
	l6 = vader_box_obj(0u, NULL).payload.obj;
	l7 = vader_box_obj(0u, NULL).payload.obj;
	vader_struct_toolchain_ast$$genstate_decorator_sites_t* _a0_obj = (vader_struct_toolchain_ast$$genstate_decorator_sites_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$$genstate_decorator_sites_t));
	vader_obj_header_init(_a0_obj, 1126u);
	_a0_obj->f_s0 = l0;
	_a0_obj->f_s1 = l1;
	_a0_obj->f_s2 = l2;
	_a0_obj->f_s3 = INT64_C(0);
	_a0_obj->f_s4 = INT64_C(0);
	_a0_obj->f_s5 = l3;
	_a0_obj->f_s6 = l4;
	_a0_obj->f_s7 = INT64_C(0);
	_a0_obj->f_s8 = INT64_C(0);
	_a0_obj->f_s9 = l5;
	_a0_obj->f_s10 = l6;
	_a0_obj->f_s11 = INT64_C(0);
	_a0_obj->f_s12 = INT64_C(0);
	_a0_obj->f_s13 = l7;
	_a0_obj->f_state = INT32_C(33);
	t0 = (void*) _a0_obj;
	{ vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

void* toolchain_ast$extern_arguments(void* l0) {
	vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[2] = { &l1, &l2 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l1 = toolchain_ast$argument_named(l0, 2566u, INT64_C(0));
	l2 = toolchain_ast$argument_named(l0, 3288u, INT64_C(1));
	vader_struct_toolchain_ast$ExternArguments_t* _a0_obj = (vader_struct_toolchain_ast$ExternArguments_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$ExternArguments_t));
	vader_obj_header_init(_a0_obj, 1157u);
	_a0_obj->f_from = l1;
	_a0_obj->f_symbol = l2;
	t0 = (void*) _a0_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* toolchain_ast$extern_headers(void* l0, vader_box_t l1) {
	vader_string_t l2 = 0;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[1] = { &l2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = toolchain_ast$c_header_of(l0);
	if (l2 != 0u) {
		vader_array_t* _a0_arr = vader_array_new(28u, 1u, 0u, 630u);
		vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(630u, l2);
		t0 = (void*) _a0_arr;
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l1.tag == 0u)) {
		t0 = l1.payload.obj;
		{ void* __vret = ((vader_struct_std_core$CLibrary_t*) t0)->f_headers; vader_gc_top = gc_frame.prev; return __vret; }
	}
	vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 630u);
	t0 = (void*) _a1_arr;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t toolchain_ast$extern_symbol_of(void* l0) {
	vader_box_t l1 = vader_box_null();
	vader_string_t t0 = 0;
	void* t1 = NULL;
	void* t2 = NULL;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[3] = { &l0, &t1, &t2 };
	vader_string_t* gc_atom_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l1 = toolchain_ast$find_compiler_decorator(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_decorators, (uint8_t) 14);
	if (l1.tag == 0u) {
		t0 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
		{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = l1.payload.obj;
	t2 = toolchain_ast$extern_arguments(t1);
	l1 = ((vader_struct_toolchain_ast$ExternArguments_t*) t2)->f_symbol;
	if (l1.tag == 0u) {
		t0 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
		{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = toolchain_ast$string_literal_text(l1);
	if (l1.tag == 0u) {
		t0 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
		{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l1.payload.s;
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t toolchain_ast$fallback_body_expr(vader_box_t l0) {
	vader_box_t l1;
	void* t0;
	if (l0.tag == 1199u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_value;
		return l1;
	}
	if ((l0.tag == 1133u || l0.tag == 1139u)) {
		l1 = vader_box_obj(0u, NULL);
	} else {
		if (!((l0.tag == 1127u || l0.tag == 1130u || l0.tag == 1131u || l0.tag == 1132u || l0.tag == 1135u || l0.tag == 1136u || l0.tag == 1137u || l0.tag == 1152u || l0.tag == 1159u || l0.tag == 1160u || l0.tag == 1161u || l0.tag == 1164u || l0.tag == 1166u || l0.tag == 1167u || l0.tag == 1170u || l0.tag == 1175u || l0.tag == 1177u || l0.tag == 1178u || l0.tag == 1181u || l0.tag == 1185u || l0.tag == 1189u || l0.tag == 1195u || l0.tag == 1200u || l0.tag == 1202u || l0.tag == 1207u || l0.tag == 1217u))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = l0;
	}
	return l1;
}

vader_box_t toolchain_ast$find_compiler_decorator(void* l0, uint8_t l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	bool t0;
	void** gc_raw_roots[4] = { &l0, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = l0;
	vader_struct___lambda_env_toolchain_ast_1_t* _a0_obj = (vader_struct___lambda_env_toolchain_ast_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_toolchain_ast_1_t));
	vader_obj_header_init(_a0_obj, 677u);
	_a0_obj->f_cap_0 = l1;
	l3 = (void*) _a0_obj;
	l4 = vader_array_length(((vader_array_t*) l2));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
		t0 = __lambda_toolchain_ast_0(l3, l6);
		if (t0) {
			{ vader_box_t __vret = vader_ref_box(l6); vader_gc_top = gc_frame.prev; return __vret; }
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

vader_box_t toolchain_ast$find_expr(vader_box_t l0, void* l1) {
	void* l2 = NULL;
	void* l3 = NULL;
	void* l4 = NULL;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_box_t* gc_roots[2] = { &l0, &t1 };
	void** gc_raw_roots[5] = { &l1, &l2, &l3, &l4, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(468u, 0u, 13u, 2386u);
	l2 = (void*) _a0_arr;
	vader_struct___lambda_env_toolchain_ast_3_t* _a1_obj = (vader_struct___lambda_env_toolchain_ast_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_toolchain_ast_3_t));
	vader_obj_header_init(_a1_obj, 678u);
	_a1_obj->f_cap_0 = l1;
	_a1_obj->f_cap_1 = l2;
	t0 = (void*) _a1_obj;
	vader_fn_t* _a2_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
	vader_obj_header_init(_a2_closure, 615u);
	_a2_closure->code = (void*) &vader_fn_lift___lambda_toolchain_ast_2;
	_a2_closure->env = t0;
	l3 = (void*) _a2_closure;
	l4 = (void*) &vader_fn_static_toolchain_ast$ignore_node;
	toolchain_ast$inspect(l0, l3, l4);
	t1 = std_core$first__toolchain_ast_ArrayTypeExpr___toolchain_ast_BinaryExpr___toolchain_ast_BlockExpr___toolchain_ast_BoolLitExpr___toolchain_ast_CallExpr___toolchain_ast_CastExpr___toolchain_ast_CharLitExpr___toolchain_ast_DotVariantExpr___toolchain_ast_FallbackExpr___toolchain_ast_FieldExpr___toolchain_ast_FloatLitExpr___toolchain_ast_FnTypeExpr___toolchain_ast_GenericInstExpr___toolchain_ast_IdentExpr___toolchain_ast_IfExpr___toolchain_ast_IndexExpr___toolchain_ast_IntLitExpr___toolchain_ast_IntrinsicCallExpr___toolchain_ast_LambdaExpr___toolchain_ast_MatchExpr___toolchain_ast_NullLitExpr___toolchain_ast_RangeExpr___toolchain_ast_SeqLitExpr___toolchain_ast_StringLitExpr___toolchain_ast_StructLitExpr___toolchain_ast_UnaryExpr(l2);
	{ vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool toolchain_ast$has_compiler_decorator(void* l0, uint8_t l1) {
	vader_box_t t0 = vader_box_null();
	vader_box_t* gc_roots[1] = { &t0 };
	void** gc_raw_roots[1] = { &l0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = toolchain_ast$find_compiler_decorator(l0, l1);
	{ bool __vret = !(t0.tag == 0u); vader_gc_top = gc_frame.prev; return __vret; }
}

void toolchain_ast$ignore_node(vader_box_t l0) {
	return;
}

void* toolchain_ast$impl_trait_args(void* l0) {
	void* t0;
	t0 = toolchain_ast$instance_args(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_implemented);
	return t0;
}

vader_box_t toolchain_ast$impl_trait_head(void* l0) {
	vader_box_t t0;
	t0 = toolchain_ast$instance_head(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_implemented);
	return t0;
}

vader_string_t toolchain_ast$impl_trait_name(void* l0) {
	vader_box_t l1;
	void* t0;
	vader_string_t t1;
	l1 = toolchain_ast$impl_trait_head(l0);
	if (l1.tag == 1160u) {
		t0 = l1.payload.obj;
		t1 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_field;
		return t1;
	}
	if (l1.tag == 1167u) {
		t0 = l1.payload.obj;
		t1 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
		return t1;
	}
	return 0u;
}

void* toolchain_ast$impl_trait_name_span(void* l0) {
	vader_box_t l1;
	void* t0;
	l1 = toolchain_ast$impl_trait_head(l0);
	if (l1.tag == 1160u) {
		t0 = l1.payload.obj;
		return ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_field_span;
	}
	return VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj);
}

vader_string_t toolchain_ast$impl_trait_written_name(void* l0) {
	vader_box_t l1 = vader_box_null();
	vader_string_t l2 = 0;
	vader_string_t l3 = 0;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l2, &l3, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l1 = toolchain_ast$impl_trait_head(l0);
	if (l1.tag == 1160u) {
		t0 = l1.payload.obj;
		if (((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_target.tag == 1167u) {
			t0 = l1.payload.obj;
			l2 = ((vader_struct_toolchain_ast$IdentExpr_t*) ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_target.payload.obj)->f_name;
			t0 = l1.payload.obj;
			l3 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_field;
			t1 = concat_3(l2, 489u, l3);
			{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
		}
		t1 = toolchain_ast$impl_trait_name(l0);
		{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = toolchain_ast$impl_trait_name(l0);
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t toolchain_ast$impl_type_name(void* l0) {
	vader_box_t l1;
	void* t0;
	vader_string_t t1;
	l1 = toolchain_ast$instance_head(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_for_type);
	if (!(l1.tag == 1167u)) {
		return vader_box_obj(0u, NULL);
	}
	t0 = l1.payload.obj;
	t1 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
	return vader_box_string(630u, t1);
}

bool toolchain_ast$inspect(vader_box_t l0, void* l1, void* l2) {
	uint8_t l3;
	bool l4;
	vader_box_t t0 = vader_box_null();
	void* t1 = NULL;
	bool t2;
	vader_box_t* gc_roots[2] = { &l0, &t0 };
	void** gc_raw_roots[3] = { &l1, &l2, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
	t0 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, l0);
	l3 = ((uint8_t) t0.payload.i);
	if (l3 == INT32_C(2)) {
		{ vader_gc_top = gc_frame.prev; return true; }
	}
	if (l3 == INT32_C(0)) {
		if ((l0.tag == 1132u || l0.tag == 1137u || l0.tag == 1161u || l0.tag == 1177u || l0.tag == 1189u)) {
			l4 = false;
		} else if (l0.tag == 1202u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_parts(((vader_struct_toolchain_ast$StringLitExpr_t*) t1)->f_parts, l1, l2);
		} else if ((l0.tag == 1152u || l0.tag == 1167u)) {
			l4 = false;
		} else if (l0.tag == 1135u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_call(t1, l1, l2);
		} else if (l0.tag == 1160u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$FieldExpr_t*) t1)->f_target, l1, l2);
		} else if (l0.tag == 1175u) {
			t1 = l0.payload.obj;
			t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$IndexExpr_t*) t1)->f_target, l1, l2);
			if (t2) {
				l4 = true;
			} else {
				t1 = l0.payload.obj;
				l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$IndexExpr_t*) t1)->f_index, l1, l2);
			}
		} else if (l0.tag == 1217u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$UnaryExpr_t*) t1)->f_operand, l1, l2);
		} else if (l0.tag == 1130u) {
			t1 = l0.payload.obj;
			t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$BinaryExpr_t*) t1)->f_left, l1, l2);
			if (t2) {
				l4 = true;
			} else {
				t1 = l0.payload.obj;
				l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$BinaryExpr_t*) t1)->f_right, l1, l2);
			}
		} else if (l0.tag == 1159u) {
			t1 = l0.payload.obj;
			t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$FallbackExpr_t*) t1)->f_left, l1, l2);
			if (t2) {
				l4 = true;
			} else {
				t1 = l0.payload.obj;
				l4 = toolchain_ast$inspect_clauses(((vader_struct_toolchain_ast$FallbackExpr_t*) t1)->f_clauses, l1, l2);
			}
		} else if (l0.tag == 1170u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_if(t1, l1, l2);
		} else if (l0.tag == 1185u) {
			t1 = l0.payload.obj;
			t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$MatchExpr_t*) t1)->f_scrutinee, l1, l2);
			if (t2) {
				l4 = true;
			} else {
				t1 = l0.payload.obj;
				l4 = toolchain_ast$inspect_arms(((vader_struct_toolchain_ast$MatchExpr_t*) t1)->f_arms, l1, l2);
			}
		} else if (l0.tag == 1131u) {
			t1 = l0.payload.obj;
			t2 = toolchain_ast$inspect_stmts(((vader_struct_toolchain_ast$BlockExpr_t*) t1)->f_stmts, l1, l2);
			if (t2) {
				l4 = true;
			} else {
				t1 = l0.payload.obj;
				l4 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$BlockExpr_t*) t1)->f_trailing, l1, l2);
			}
		} else if (l0.tag == 1181u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_lambda(t1, l1, l2);
		} else if (l0.tag == 1207u) {
			t1 = l0.payload.obj;
			t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$StructLitExpr_t*) t1)->f_type_name, l1, l2);
			if (t2) {
				l4 = true;
			} else {
				t1 = l0.payload.obj;
				l4 = toolchain_ast$inspect_items(((vader_struct_toolchain_ast$StructLitExpr_t*) t1)->f_items, l1, l2);
			}
		} else if (l0.tag == 1200u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_exprs(((vader_struct_toolchain_ast$SeqLitExpr_t*) t1)->f_elements, l1, l2);
		} else if (l0.tag == 1195u) {
			t1 = l0.payload.obj;
			t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$RangeExpr_t*) t1)->f_lower, l1, l2);
			if (t2) {
				l4 = true;
			} else {
				t1 = l0.payload.obj;
				l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$RangeExpr_t*) t1)->f_upper, l1, l2);
			}
		} else if (l0.tag == 1136u) {
			t1 = l0.payload.obj;
			t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$CastExpr_t*) t1)->f_value, l1, l2);
			if (t2) {
				l4 = true;
			} else {
				t1 = l0.payload.obj;
				l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$CastExpr_t*) t1)->f_target, l1, l2);
			}
		} else if (l0.tag == 1166u) {
			t1 = l0.payload.obj;
			t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$GenericInstExpr_t*) t1)->f_callee, l1, l2);
			if (t2) {
				l4 = true;
			} else {
				t1 = l0.payload.obj;
				l4 = toolchain_ast$inspect_exprs(((vader_struct_toolchain_ast$GenericInstExpr_t*) t1)->f_type_args, l1, l2);
			}
		} else if (l0.tag == 1178u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_exprs(((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) t1)->f_args, l1, l2);
		} else if (l0.tag == 1164u) {
			t1 = l0.payload.obj;
			t2 = toolchain_ast$inspect_exprs(((vader_struct_toolchain_ast$FnTypeExpr_t*) t1)->f_params, l1, l2);
			if (t2) {
				l4 = true;
			} else {
				t1 = l0.payload.obj;
				l4 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$FnTypeExpr_t*) t1)->f_return_type, l1, l2);
			}
		} else if (l0.tag == 1127u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$ArrayTypeExpr_t*) t1)->f_element, l1, l2);
		} else if (l0.tag == 1182u) {
			t1 = l0.payload.obj;
			t2 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$LetStmt_t*) t1)->f_ty, l1, l2);
			if (t2) {
				l4 = true;
			} else {
				t1 = l0.payload.obj;
				l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$LetStmt_t*) t1)->f_value, l1, l2);
			}
		} else if (l0.tag == 1129u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_assign(t1, l1, l2);
		} else if (l0.tag == 1146u) {
			t1 = l0.payload.obj;
			t2 = toolchain_ast$inspect_targets(((vader_struct_toolchain_ast$DestructureAssignStmt_t*) t1)->f_targets, l1, l2);
			if (t2) {
				l4 = true;
			} else {
				t1 = l0.payload.obj;
				l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$DestructureAssignStmt_t*) t1)->f_value, l1, l2);
			}
		} else if (l0.tag == 1156u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$ExprStmt_t*) t1)->f_expr, l1, l2);
		} else if (l0.tag == 1199u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$ReturnStmt_t*) t1)->f_value, l1, l2);
		} else if (l0.tag == 1223u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$YieldStmt_t*) t1)->f_value, l1, l2);
		} else if (l0.tag == 1165u) {
			t1 = l0.payload.obj;
			t2 = toolchain_ast$inspect_form(((vader_struct_toolchain_ast$ForStmt_t*) t1)->f_form, l1, l2);
			if (t2) {
				l4 = true;
			} else {
				t1 = l0.payload.obj;
				l4 = toolchain_ast$inspect(vader_ref_box(((vader_struct_toolchain_ast$ForStmt_t*) t1)->f_body), l1, l2);
			}
		} else if ((l0.tag == 1133u || l0.tag == 1139u)) {
			l4 = false;
		} else if (l0.tag == 1144u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_defer(((vader_struct_toolchain_ast$DeferStmt_t*) t1)->f_body, l1, l2);
		} else if (l0.tag == 1180u) {
			t1 = l0.payload.obj;
			t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$IsPattern_t*) t1)->f_ty, l1, l2);
			if (t2) {
				l4 = true;
			} else {
				t1 = l0.payload.obj;
				l4 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$IsPattern_t*) t1)->f_inner, l1, l2);
			}
		} else if (l0.tag == 1210u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_pattern_fields(((vader_struct_toolchain_ast$StructPattern_t*) t1)->f_fields, l1, l2);
		} else if ((l0.tag == 1155u || l0.tag == 1221u)) {
			l4 = false;
		} else if (l0.tag == 1183u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$LiteralPattern_t*) t1)->f_value, l1, l2);
		} else if (l0.tag == 1196u) {
			t1 = l0.payload.obj;
			t2 = toolchain_ast$inspect(((vader_struct_toolchain_ast$RangePattern_t*) t1)->f_lower, l1, l2);
			if (t2) {
				l4 = true;
			} else {
				t1 = l0.payload.obj;
				l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$RangePattern_t*) t1)->f_upper, l1, l2);
			}
		} else if (l0.tag == 1190u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_patterns(((vader_struct_toolchain_ast$OrPattern_t*) t1)->f_patterns, l1, l2);
		} else if (l0.tag == 1172u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$ImportDecl_t*) t1)->f_decorators, l1, l2);
		} else if (l0.tag == 1162u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_fn(t1, l1, l2);
		} else if (l0.tag == 1205u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_struct(t1, l1, l2);
		} else if (l0.tag == 1153u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_enum(t1, l1, l2);
		} else if (l0.tag == 1213u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_trait(t1, l1, l2);
		} else if (l0.tag == 1171u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_impl(t1, l1, l2);
		} else if (l0.tag == 1215u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_alias(t1, l1, l2);
		} else if (l0.tag == 1138u) {
			t1 = l0.payload.obj;
			l4 = toolchain_ast$inspect_const(t1, l1, l2);
		} else {
			if (!(l0.tag == 1128u)) {
				vader_unreachable("non-exhaustive match (T3013 should have caught this)");
			}
			t1 = l0.payload.obj;
			t2 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$AssertDecl_t*) t1)->f_decorators, l1, l2);
			if (t2) {
				l4 = true;
			} else {
				t1 = l0.payload.obj;
				l4 = toolchain_ast$inspect(((vader_struct_toolchain_ast$AssertDecl_t*) t1)->f_condition, l1, l2);
			}
		}
		if (l4) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
		((vader_fn_erased_sig_1_t) _a1_fnobj->code)(_a1_fnobj->env, l0);
		{ vader_gc_top = gc_frame.prev; return false; }
	}
	vader_fn_t* _a2_fnobj = (vader_fn_t*) l2;
	((vader_fn_erased_sig_1_t) _a2_fnobj->code)(_a2_fnobj->env, l0);
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_alias(void* l0, void* l1, void* l2) {
	bool l3;
	bool t0;
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$TypeAliasDecl_t*) l0)->f_decorators, l1, l2);
	if (t0) {
		l3 = true;
	} else {
		l3 = toolchain_ast$inspect_type_params(((vader_struct_toolchain_ast$TypeAliasDecl_t*) l0)->f_type_params, l1, l2);
	}
	if (l3) {
		{ vader_gc_top = gc_frame.prev; return true; }
	}
	t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$TypeAliasDecl_t*) l0)->f_aliased, l1, l2);
	{ bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_arms(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	bool t0;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = l0;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_pattern, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		t0 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_guard, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_body, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_assign(void* l0, void* l1, void* l2) {
	vader_box_t t0 = vader_box_null();
	bool t1;
	vader_box_t* gc_roots[1] = { &t0 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = toolchain_ast$compound_assign_op(l0);
	if (!(t0.tag == 0u)) {
		t1 = toolchain_ast$inspect(((vader_struct_toolchain_ast$AssignStmt_t*) l0)->f_value, l1, l2);
		{ bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = toolchain_ast$inspect(((vader_struct_toolchain_ast$AssignStmt_t*) l0)->f_target, l1, l2);
	if (t1) {
		{ vader_gc_top = gc_frame.prev; return true; }
	}
	t1 = toolchain_ast$inspect(((vader_struct_toolchain_ast$AssignStmt_t*) l0)->f_value, l1, l2);
	{ bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_call(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	int64_t l4, l5;
	bool t0;
	void* t1 = NULL;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_callee, l1, l2);
	if (t0) {
		{ vader_gc_top = gc_frame.prev; return true; }
	}
	t0 = toolchain_ast$inspect_exprs(((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_type_args, l1, l2);
	if (t0) {
		{ vader_gc_top = gc_frame.prev; return true; }
	}
	l3 = ((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_args;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		t1 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$CallArg_t*) t1)->f_value, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_clauses(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	bool t0;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = l0;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		t0 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$FallbackClause_t*) l6)->f_test, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$FallbackClause_t*) l6)->f_body, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_const(void* l0, void* l1, void* l2) {
	bool l3;
	bool t0;
	vader_box_t t1 = vader_box_null();
	vader_box_t* gc_roots[1] = { &t1 };
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_decorators, l1, l2);
	if (t0) {
		l3 = true;
	} else {
		t1 = toolchain_ast$own_const_type(l0);
		l3 = toolchain_ast$inspect_maybe(t1, l1, l2);
	}
	if (l3) {
		{ vader_gc_top = gc_frame.prev; return true; }
	}
	t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_value, l1, l2);
	{ bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_decorators(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	void* l7 = NULL;
	int64_t l4, l5, l8, l9;
	bool t0;
	void* t1 = NULL;
	void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l6, &l7, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = l0;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		t0 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$Decorator_t*) l6)->f_qualifier, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l7 = ((vader_struct_toolchain_ast$Decorator_t*) l6)->f_args;
		l8 = vader_array_length(((vader_array_t*) l7));
		l9 = INT64_C(0);
		while ((l9 < l8)) {
			vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
			VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
			t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l9);
			t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$CallArg_t*) t1)->f_value, l1, l2);
			if (t0) {
				{ vader_gc_top = gc_frame.prev; return true; }
			}
			l9 = (l9 + INT64_C(1));
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_defer(vader_box_t l0, void* l1, void* l2) {
	void* t0 = NULL;
	bool t1;
	vader_box_t* gc_roots[1] = { &l0 };
	void** gc_raw_roots[3] = { &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l0.tag == 1145u) {
		t0 = l0.payload.obj;
		t1 = toolchain_ast$inspect(((vader_struct_toolchain_ast$DeferStmtBody_t*) t0)->f_stmt, l1, l2);
		{ bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (!(l0.tag == 1143u)) {
		vader_unreachable("non-exhaustive match (T3013 should have caught this)");
	}
	t0 = l0.payload.obj;
	t1 = toolchain_ast$inspect(vader_ref_box(((vader_struct_toolchain_ast$DeferBlockBody_t*) t0)->f_block), l1, l2);
	{ bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_enum(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	vader_box_t l7 = vader_box_null();
	bool t0;
	void* t1 = NULL;
	vader_box_t* gc_roots[1] = { &l7 };
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$EnumDecl_t*) l0)->f_decorators, l1, l2);
	if (t0) {
		{ vader_gc_top = gc_frame.prev; return true; }
	}
	t0 = toolchain_ast$inspect_exprs(((vader_struct_toolchain_ast$EnumDecl_t*) l0)->f_header, l1, l2);
	if (t0) {
		{ vader_gc_top = gc_frame.prev; return true; }
	}
	l3 = ((vader_struct_toolchain_ast$EnumDecl_t*) l0)->f_variants;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		t0 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$EnumVariant_t*) l6)->f_decorators, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l7 = ((vader_struct_toolchain_ast$EnumVariant_t*) l6)->f_data;
		if (l7.tag == 0u) {
			l5 = (l5 + INT64_C(1));
			continue;
		}
		t1 = l7.payload.obj;
		t0 = toolchain_ast$inspect_items(t1, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_exprs(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	int64_t l4, l5;
	vader_box_t t0 = vader_box_null();
	bool t1;
	vader_box_t* gc_roots[1] = { &t0 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = l0;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		t1 = toolchain_ast$inspect(t0, l1, l2);
		if (t1) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_fn(void* l0, void* l1, void* l2) {
	bool l3;
	bool t0;
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_decorators, l1, l2);
	if (t0) {
		l3 = true;
	} else {
		l3 = toolchain_ast$inspect_type_params(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_type_params, l1, l2);
	}
	if (l3) {
		l3 = true;
	} else {
		l3 = toolchain_ast$inspect_params(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params, l1, l2);
	}
	if (l3) {
		l3 = true;
	} else {
		l3 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_return_type, l1, l2);
	}
	if (l3) {
		{ vader_gc_top = gc_frame.prev; return true; }
	}
	t0 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_body, l1, l2);
	{ bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_fns(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	int64_t l4, l5;
	void* t0 = NULL;
	bool t1;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = l0;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		t1 = toolchain_ast$inspect(vader_ref_box(t0), l1, l2);
		if (t1) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_form(vader_box_t l0, void* l1, void* l2) {
	bool l3;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l0 };
	void** gc_raw_roots[3] = { &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l0.tag == 1174u) {
		t0 = l0.payload.obj;
		l3 = toolchain_ast$inspect(((vader_struct_toolchain_ast$InFor_t*) t0)->f_iter, l1, l2);
		{ bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l0.tag == 1218u) {
		t0 = l0.payload.obj;
		l3 = toolchain_ast$inspect(((vader_struct_toolchain_ast$WhileFor_t*) t0)->f_cond, l1, l2);
	} else {
		if (!(l0.tag == 1176u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l3 = false;
	}
	{ bool __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_if(void* l0, void* l1, void* l2) {
	vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
	bool l5;
	bool t0;
	void* t1 = NULL;
	vader_box_t* gc_roots[2] = { &l3, &l4 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$IfExpr_t*) l0)->f_cond, l1, l2);
	if (t0) {
		{ vader_gc_top = gc_frame.prev; return true; }
	}
	t0 = toolchain_ast$inspect(vader_ref_box(((vader_struct_toolchain_ast$IfExpr_t*) l0)->f_then_block), l1, l2);
	if (t0) {
		{ vader_gc_top = gc_frame.prev; return true; }
	}
	l3 = ((vader_struct_toolchain_ast$IfExpr_t*) l0)->f_else_branch;
	l4 = l3;
	if (l3.tag == 0u) {
		l5 = false;
		{ bool __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l3.tag == 1169u) {
		t1 = l4.payload.obj;
		l5 = toolchain_ast$inspect(vader_ref_box(((vader_struct_toolchain_ast$IfElseIf_t*) t1)->f_branch), l1, l2);
	} else {
		if (!(l3.tag == 1168u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		t1 = l4.payload.obj;
		l5 = toolchain_ast$inspect(vader_ref_box(((vader_struct_toolchain_ast$IfElseBlock_t*) t1)->f_block), l1, l2);
	}
	{ bool __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_impl(void* l0, void* l1, void* l2) {
	bool l3;
	bool t0;
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_decorators, l1, l2);
	if (t0) {
		l3 = true;
	} else {
		l3 = toolchain_ast$inspect_type_params(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_type_params, l1, l2);
	}
	if (l3) {
		l3 = true;
	} else {
		l3 = toolchain_ast$inspect(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_for_type, l1, l2);
	}
	if (l3) {
		l3 = true;
	} else {
		l3 = toolchain_ast$inspect(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_implemented, l1, l2);
	}
	if (l3) {
		{ vader_gc_top = gc_frame.prev; return true; }
	}
	t0 = toolchain_ast$inspect_fns(((vader_struct_toolchain_ast$ImplDecl_t*) l0)->f_members, l1, l2);
	{ bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_items(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	int64_t l4, l5;
	vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
	bool t2;
	vader_box_t* gc_roots[2] = { &t0, &t1 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = l0;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		t1 = toolchain_ast$struct_item_value(t0);
		t2 = toolchain_ast$inspect(t1, l1, l2);
		if (t2) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_lambda(void* l0, void* l1, void* l2) {
	bool l3;
	bool t0;
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = toolchain_ast$inspect_params(((vader_struct_toolchain_ast$LambdaExpr_t*) l0)->f_params, l1, l2);
	if (t0) {
		l3 = true;
	} else {
		l3 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$LambdaExpr_t*) l0)->f_return_type, l1, l2);
	}
	if (l3) {
		{ vader_gc_top = gc_frame.prev; return true; }
	}
	t0 = toolchain_ast$inspect(vader_ref_box(((vader_struct_toolchain_ast$LambdaExpr_t*) l0)->f_body), l1, l2);
	{ bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_maybe(vader_box_t l0, void* l1, void* l2) {
	vader_box_t l3 = vader_box_null();
	bool t0;
	vader_box_t* gc_roots[2] = { &l0, &l3 };
	void** gc_raw_roots[2] = { &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = l0;
	if (l3.tag == 0u) {
		{ vader_gc_top = gc_frame.prev; return false; }
	}
	t0 = toolchain_ast$inspect(l3, l1, l2);
	{ bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_params(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	bool t0;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = l0;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		t0 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$FnParam_t*) l6)->f_decorators, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		t0 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$FnParam_t*) l6)->f_ty, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		t0 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$FnParam_t*) l6)->f_default_value, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_parts(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	int64_t l4, l5;
	vader_box_t l6 = vader_box_null();
	void* t0 = NULL;
	bool t1;
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = l0;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		if (l6.tag == 1203u) {
			t0 = l6.payload.obj;
			t1 = toolchain_ast$inspect(((vader_struct_toolchain_ast$StringLitInterpolation_t*) t0)->f_expr, l1, l2);
			if (t1) {
				{ vader_gc_top = gc_frame.prev; return true; }
			}
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_pattern_fields(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	int64_t l4, l5;
	vader_box_t l6 = vader_box_null();
	void* t0 = NULL;
	bool t1;
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = l0;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		l6 = ((vader_struct_toolchain_ast$StructPatternField_t*) t0)->f_value;
		if (l6.tag == 1192u) {
			t0 = l6.payload.obj;
			t1 = toolchain_ast$inspect(((vader_struct_toolchain_ast$PatternLiteral_t*) t0)->f_value, l1, l2);
			if (t1) {
				{ vader_gc_top = gc_frame.prev; return true; }
			}
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_patterns(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	int64_t l4, l5;
	vader_box_t t0 = vader_box_null();
	bool t1;
	vader_box_t* gc_roots[1] = { &t0 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = l0;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		t1 = toolchain_ast$inspect(t0, l1, l2);
		if (t1) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_stmts(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	int64_t l4, l5;
	vader_box_t t0 = vader_box_null();
	bool t1;
	vader_box_t* gc_roots[1] = { &t0 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = l0;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		t1 = toolchain_ast$inspect(t0, l1, l2);
		if (t1) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_struct(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	vader_box_t l7 = vader_box_null();
	bool t0;
	void* t1 = NULL;
	vader_box_t* gc_roots[1] = { &l7 };
	void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$StructDecl_t*) l0)->f_decorators, l1, l2);
	if (t0) {
		{ vader_gc_top = gc_frame.prev; return true; }
	}
	t0 = toolchain_ast$inspect_type_params(((vader_struct_toolchain_ast$StructDecl_t*) l0)->f_type_params, l1, l2);
	if (t0) {
		{ vader_gc_top = gc_frame.prev; return true; }
	}
	l3 = ((vader_struct_toolchain_ast$StructDecl_t*) l0)->f_fields;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		t0 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$StructField_t*) l6)->f_decorators, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$StructField_t*) l6)->f_ty, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		t0 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$StructField_t*) l6)->f_default, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l5 = (l5 + INT64_C(1));
	}
	l3 = ((vader_struct_toolchain_ast$StructDecl_t*) l0)->f_spreads;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
		t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
		t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$StructSpread_t*) t1)->f_base, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l5 = (l5 + INT64_C(1));
	}
	l7 = ((vader_struct_toolchain_ast$StructDecl_t*) l0)->f_decorator_args;
	if (l7.tag == 0u) {
		vader_array_t* _a2_arr = vader_array_new(63u, 0u, 13u, 1134u);
		l3 = (void*) _a2_arr;
	} else {
		l3 = l7.payload.obj;
	}
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
		t1 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l5);
		t0 = toolchain_ast$inspect(((vader_struct_toolchain_ast$CallArg_t*) t1)->f_value, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_targets(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	int64_t l4, l5;
	vader_box_t l6 = vader_box_null();
	bool t0;
	vader_box_t* gc_roots[1] = { &l6 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = l0;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		if ((l6.tag == 1193u || l6.tag == 1198u)) {
			t0 = toolchain_ast$inspect(VADER_UNION_FIELD(vader_box_t, vader_struct_toolchain_ast$PlaceTarget_t, f_place, l6.payload.obj), l1, l2);
			if (t0) {
				{ vader_gc_top = gc_frame.prev; return true; }
			}
		} else if (!(l6.tag == 1222u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

static bool toolchain_ast$inspect_trait(void* l0, void* l1, void* l2) {
	bool l3;
	bool t0;
	void** gc_raw_roots[3] = { &l0, &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = toolchain_ast$inspect_decorators(((vader_struct_toolchain_ast$TraitDecl_t*) l0)->f_decorators, l1, l2);
	if (t0) {
		l3 = true;
	} else {
		l3 = toolchain_ast$inspect_type_params(((vader_struct_toolchain_ast$TraitDecl_t*) l0)->f_type_params, l1, l2);
	}
	if (l3) {
		l3 = true;
	} else {
		l3 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$TraitDecl_t*) l0)->f_requires, l1, l2);
	}
	if (l3) {
		{ vader_gc_top = gc_frame.prev; return true; }
	}
	t0 = toolchain_ast$inspect_fns(((vader_struct_toolchain_ast$TraitDecl_t*) l0)->f_members, l1, l2);
	{ bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool toolchain_ast$inspect_type_params(void* l0, void* l1, void* l2) {
	void* l3 = NULL;
	void* l6 = NULL;
	int64_t l4, l5;
	bool t0;
	void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l3 = l0;
	l4 = vader_array_length(((vader_array_t*) l3));
	l5 = INT64_C(0);
	while ((l5 < l4)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
		l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
		t0 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$TypeParam_t*) l6)->f_bound, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		t0 = toolchain_ast$inspect_maybe(((vader_struct_toolchain_ast$TypeParam_t*) l6)->f_default, l1, l2);
		if (t0) {
			{ vader_gc_top = gc_frame.prev; return true; }
		}
		l5 = (l5 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return false; }
}

void* toolchain_ast$instance_args(vader_box_t l0) {
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l0 };
	void** gc_raw_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (!(l0.tag == 1166u)) {
		vader_array_t* _a0_arr = vader_array_new(468u, 0u, 13u, 2386u);
		t0 = (void*) _a0_arr;
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t0 = l0.payload.obj;
	{ void* __vret = ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_type_args; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t toolchain_ast$instance_head(vader_box_t l0) {
	void* t0;
	if (!(l0.tag == 1166u)) {
		return l0;
	}
	t0 = l0.payload.obj;
	return ((vader_struct_toolchain_ast$GenericInstExpr_t*) t0)->f_callee;
}

vader_string_t toolchain_ast$int_literal_text(void* l0) {
	void* l1 = NULL;
	int64_t l2;
	uint64_t l3;
	bool t0;
	vader_string_t t1 = 0;
	void** gc_raw_roots[2] = { &l0, &l1 };
	vader_string_t* gc_atom_roots[1] = { &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = ((vader_struct_toolchain_ast$IntLitExpr_t*) l0)->f_negative;
	if (!(t0)) {
		l1 = (void*) vader_buffer_new((size_t) INT64_C(20));
		l2 = INT64_C(0);
		l3 = ((vader_struct_toolchain_ast$IntLitExpr_t*) l0)->f_value;
		l2 = std_core$write_unsigned(l1, l2, l3);
		t1 = std_core$finish_buffer(l1, l2);
		{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = (void*) vader_buffer_new((size_t) INT64_C(21));
	l2 = INT64_C(0);
	l2 = std_core$write_string_at(l1, l2, 476u);
	l3 = ((vader_struct_toolchain_ast$IntLitExpr_t*) l0)->f_value;
	l2 = std_core$write_unsigned(l1, l2, l3);
	t1 = std_core$finish_buffer(l1, l2);
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t toolchain_ast$int_literal_value(void* l0) {
	int64_t l1;
	bool t0;
	uint64_t t1;
	t0 = ((vader_struct_toolchain_ast$IntLitExpr_t*) l0)->f_negative;
	if (!(t0)) {
		t1 = ((vader_struct_toolchain_ast$IntLitExpr_t*) l0)->f_value;
		return ((int64_t) (uint64_t) t1);
	}
	t1 = ((vader_struct_toolchain_ast$IntLitExpr_t*) l0)->f_value;
	l1 = ((int64_t) (uint64_t) t1);
	return (INT64_C(0) - l1);
}

void* toolchain_ast$intrinsic_args(uint8_t l0) {
	void* l1 = NULL;
	void** gc_raw_roots[1] = { &l1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l0 == INT32_C(0)) {
		vader_array_t* _a0_arr = vader_array_new(31u, 1u, 1u, 635u);
		((uint8_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (uint8_t) INT32_C(2);
		l1 = (void*) _a0_arr;
		{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l0 == INT32_C(1)) {
		vader_array_t* _a1_arr = vader_array_new(31u, 1u, 1u, 635u);
		((uint8_t*) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = (uint8_t) INT32_C(0);
		l1 = (void*) _a1_arr;
	} else if (l0 == INT32_C(2)) {
		vader_array_t* _a2_arr = vader_array_new(31u, 1u, 1u, 635u);
		((uint8_t*) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = (uint8_t) INT32_C(0);
		l1 = (void*) _a2_arr;
	} else if (l0 == INT32_C(3)) {
		vader_array_t* _a3_arr = vader_array_new(31u, 1u, 1u, 635u);
		((uint8_t*) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 0u] = (uint8_t) INT32_C(0);
		l1 = (void*) _a3_arr;
	} else if (l0 == INT32_C(4)) {
		vader_array_t* _a4_arr = vader_array_new(31u, 1u, 1u, 635u);
		((uint8_t*) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = (uint8_t) INT32_C(0);
		l1 = (void*) _a4_arr;
	} else if (l0 == INT32_C(5)) {
		vader_array_t* _a5_arr = vader_array_new(31u, 1u, 1u, 635u);
		((uint8_t*) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = (uint8_t) INT32_C(0);
		l1 = (void*) _a5_arr;
	} else if (l0 == INT32_C(6)) {
		vader_array_t* _a6_arr = vader_array_new(31u, 2u, 1u, 635u);
		((uint8_t*) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 1u] = (uint8_t) INT32_C(1);
		((uint8_t*) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 0u] = (uint8_t) INT32_C(0);
		l1 = (void*) _a6_arr;
	} else if (l0 == INT32_C(7)) {
		vader_array_t* _a7_arr = vader_array_new(31u, 2u, 1u, 635u);
		((uint8_t*) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 1u] = (uint8_t) INT32_C(0);
		((uint8_t*) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = (uint8_t) INT32_C(0);
		l1 = (void*) _a7_arr;
	} else if (l0 == INT32_C(8)) {
		vader_array_t* _a8_arr = vader_array_new(31u, 1u, 1u, 635u);
		((uint8_t*) _a8_arr->buf->slots)[vader_array_offset(_a8_arr) + 0u] = (uint8_t) INT32_C(0);
		l1 = (void*) _a8_arr;
	} else if (l0 == INT32_C(9)) {
		vader_array_t* _a9_arr = vader_array_new(31u, 1u, 1u, 635u);
		((uint8_t*) _a9_arr->buf->slots)[vader_array_offset(_a9_arr) + 0u] = (uint8_t) INT32_C(0);
		l1 = (void*) _a9_arr;
	} else if (l0 == INT32_C(10)) {
		vader_array_t* _a10_arr = vader_array_new(31u, 1u, 1u, 635u);
		((uint8_t*) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 0u] = (uint8_t) INT32_C(3);
		l1 = (void*) _a10_arr;
	} else if (l0 == INT32_C(11)) {
		vader_array_t* _a11_arr = vader_array_new(31u, 1u, 1u, 635u);
		((uint8_t*) _a11_arr->buf->slots)[vader_array_offset(_a11_arr) + 0u] = (uint8_t) INT32_C(0);
		l1 = (void*) _a11_arr;
	} else if (l0 == INT32_C(12)) {
		vader_array_t* _a12_arr = vader_array_new(31u, 1u, 1u, 635u);
		((uint8_t*) _a12_arr->buf->slots)[vader_array_offset(_a12_arr) + 0u] = (uint8_t) INT32_C(0);
		l1 = (void*) _a12_arr;
	} else if (l0 == INT32_C(13)) {
		vader_array_t* _a13_arr = vader_array_new(31u, 2u, 1u, 635u);
		((uint8_t*) _a13_arr->buf->slots)[vader_array_offset(_a13_arr) + 1u] = (uint8_t) INT32_C(1);
		((uint8_t*) _a13_arr->buf->slots)[vader_array_offset(_a13_arr) + 0u] = (uint8_t) INT32_C(1);
		l1 = (void*) _a13_arr;
	} else {
		if (!(l0 == INT32_C(14))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		vader_array_t* _a14_arr = vader_array_new(31u, 2u, 1u, 635u);
		((uint8_t*) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 1u] = (uint8_t) INT32_C(0);
		((uint8_t*) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 0u] = (uint8_t) INT32_C(3);
		l1 = (void*) _a14_arr;
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* toolchain_ast$intrinsic_info(uint8_t l0) {
	void* l1;
	int64_t l2;
	void* t0;
	l1 = (void*) &vader_data_37;
	l2 = ((int64_t) (uint8_t) l0);
	vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
	VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
	t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
	return t0;
}

vader_string_t toolchain_ast$intrinsic_name(uint8_t l0) {
	void* l1;
	int64_t l2;
	void* t0;
	vader_string_t t1;
	l1 = (void*) &vader_data_37;
	l2 = ((int64_t) (uint8_t) l0);
	vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
	VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
	VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
	t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
	t1 = ((vader_struct_toolchain_ast$IntrinsicInfo_t*) t0)->f_name;
	return t1;
}

vader_box_t toolchain_ast$intrinsic_named(vader_string_t l0) {
	uint8_t l1, l2;
	vader_string_t t0;
	int32_t t1;
	l1 = (uint8_t) 0;
	while ((l1 <= INT32_C(14))) {
		l2 = l1;
		t0 = toolchain_ast$intrinsic_name(l2);
		if (t0 == l0) {
			return vader_box_i32(635u, (int32_t)(uint32_t) l2);
		}
		t1 = ((l1 + INT32_C(1)) & INT32_C(255));
		l1 = (uint8_t) (int32_t) t1;
	}
	return vader_box_obj(0u, NULL);
}

static bool toolchain_ast$is_arith_op(uint8_t l0) {
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
		l2 = l0 == INT32_C(10);
	}
	if (l2) {
		l2 = true;
	} else {
		l2 = l0 == INT32_C(11);
	}
	if (l2) {
		l1 = false;
	} else {
		if (l0 == INT32_C(12)) {
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
			l2 = true;
		} else {
			l2 = l0 == INT32_C(18);
		}
		if (l2) {
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
	return l1;
}

bool toolchain_ast$is_compiler(void* l0, uint8_t l1) {
	vader_box_t t0;
	t0 = toolchain_ast$compiler_decorator_of(l0);
	return vader_box_eq(t0, vader_box_i32(635u, (int32_t)(uint32_t) l1));
}

bool toolchain_ast$is_compiler_made(void* l0) {
	bool t0;
	t0 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_comptime_synthetic;
	if (t0) {
		return true;
	}
	t0 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_materialized;
	return t0;
}

bool toolchain_ast$is_comptime_const(void* l0) {
	return !(((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_comptime_body.tag == 0u);
}

bool toolchain_ast$is_comptime_made(vader_box_t l0) {
	bool l1;
	void* t0;
	if (l0.tag == 1162u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_comptime_synthetic;
	} else {
		l1 = false;
	}
	if (l1) {
		return true;
	}
	if (l0.tag == 1138u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_comptime_synthetic;
	} else {
		l1 = false;
	}
	return l1;
}

bool toolchain_ast$is_decorator(void* l0) {
	return !(((vader_struct_toolchain_ast$StructDecl_t*) l0)->f_decorator_args.tag == 0u);
}

bool toolchain_ast$is_evaluated(uint8_t l0) {
	bool l1;
	if (l0 == INT32_C(1)) {
		l1 = true;
	} else {
		l1 = l0 == INT32_C(2);
	}
	if (l1) {
		return true;
	}
	if (l0 == INT32_C(0)) {
		l1 = true;
	} else {
		l1 = l0 == INT32_C(3);
	}
	if (!(l1)) {
		vader_unreachable("non-exhaustive match (T3013 should have caught this)");
	}
	return false;
}

vader_string_t toolchain_ast$member_place(vader_box_t l0) {
	vader_string_t l1;
	if (l0.tag == 1213u) {
		l1 = 1151u;
		return l1;
	}
	if (l0.tag == 1171u) {
		l1 = 815u;
	} else {
		if (!((l0.tag == 1128u || l0.tag == 1138u || l0.tag == 1153u || l0.tag == 1162u || l0.tag == 1172u || l0.tag == 1205u || l0.tag == 1215u))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = 0u;
	}
	return l1;
}

void* toolchain_ast$members_of(vader_box_t l0) {
	void* l1 = NULL;
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l0 };
	void** gc_raw_roots[2] = { &l1, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if (l0.tag == 1213u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$TraitDecl_t*) t0)->f_members;
		{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l0.tag == 1171u) {
		t0 = l0.payload.obj;
		l1 = ((vader_struct_toolchain_ast$ImplDecl_t*) t0)->f_members;
	} else {
		if (!((l0.tag == 1128u || l0.tag == 1138u || l0.tag == 1153u || l0.tag == 1162u || l0.tag == 1172u || l0.tag == 1205u || l0.tag == 1215u))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		vader_array_t* _a0_arr = vader_array_new(72u, 0u, 13u, 1162u);
		l1 = (void*) _a0_arr;
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* toolchain_ast$module_decorators(void* l0) {
	void* l1 = NULL;
	vader_box_t l2 = vader_box_null();
	void* t0 = NULL;
	vader_box_t* gc_roots[1] = { &l2 };
	void** gc_raw_roots[3] = { &l0, &l1, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l2 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_module;
	if (l2.tag == 0u) {
		vader_array_t* _a0_arr = vader_array_new(66u, 0u, 13u, 1140u);
		t0 = (void*) _a0_arr;
		{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = l2.payload.obj;
	{ void* __vret = ((vader_struct_toolchain_ast$ModuleDecl_t*) l1)->f_decorators; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t toolchain_ast$own_const_type(void* l0) {
	if (!(((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_comptime_body.tag == 0u)) {
		return vader_box_obj(0u, NULL);
	}
	return ((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_ty;
}

vader_string_t toolchain_ast$place_of(vader_box_t l0) {
	vader_string_t l1;
	if (l0.tag == 1162u) {
		l1 = 763u;
		return l1;
	}
	if (l0.tag == 1205u) {
		l1 = 1007u;
	} else if (l0.tag == 1153u) {
		l1 = 741u;
	} else if (l0.tag == 1213u) {
		l1 = 1149u;
	} else if (l0.tag == 1171u) {
		l1 = 816u;
	} else if (l0.tag == 1138u) {
		l1 = 729u;
	} else if (l0.tag == 1215u) {
		l1 = 667u;
	} else if (l0.tag == 1172u) {
		l1 = 817u;
	} else {
		if (!(l0.tag == 1128u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = 0u;
	}
	return l1;
}

vader_string_t toolchain_ast$string_field(void* l0, vader_string_t l1, int64_t l2) {
	vader_box_t l3;
	vader_string_t t0;
	l3 = toolchain_ast$argument_named(l0, l1, l2);
	if (l3.tag == 0u) {
		return 0u;
	}
	l3 = toolchain_ast$string_literal_text(l3);
	if (l3.tag == 0u) {
		return 0u;
	}
	t0 = l3.payload.s;
	return t0;
}

vader_box_t toolchain_ast$string_literal_text(vader_box_t l0) {
	vader_box_t l1;
	void* t0;
	int64_t t1;
	bool t2;
	vader_string_t t3;
	if (l0.tag == 1202u) {
		t0 = l0.payload.obj;
		t1 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$StringLitExpr_t*) t0)->f_parts));
		if ((t1 > INT64_C(1))) {
			return vader_box_obj(0u, NULL);
		}
		t0 = l0.payload.obj;
		t2 = std_core$is_empty__toolchain_ast_StringLitInterpolation___toolchain_ast_StringLitText(((vader_struct_toolchain_ast$StringLitExpr_t*) t0)->f_parts);
		if (t2) {
			return vader_box_string(630u, 0u);
		}
		t0 = l0.payload.obj;
		vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$StringLitExpr_t*) t0)->f_parts);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
		l1 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
		if (!(l1.tag == 1204u)) {
			return vader_box_obj(0u, NULL);
		}
		t0 = l1.payload.obj;
		t3 = ((vader_struct_toolchain_ast$StringLitText_t*) t0)->f_value;
		return vader_box_string(630u, t3);
	}
	return vader_box_obj(0u, NULL);
}

static vader_box_t toolchain_ast$struct_item_value(vader_box_t l0) {
	void* t0;
	if (l0.tag == 1208u) {
		t0 = l0.payload.obj;
		return ((vader_struct_toolchain_ast$StructLitField_t*) t0)->f_value;
	}
	if (!(l0.tag == 1209u)) {
		vader_unreachable("non-exhaustive match (T3013 should have caught this)");
	}
	t0 = l0.payload.obj;
	return ((vader_struct_toolchain_ast$StructLitSpread_t*) t0)->f_expr;
}

void* toolchain_ast$struct_members(void* l0) {
	void* l1 = NULL;
	void* l7 = NULL;
	void* l9 = NULL;
	int64_t l2, l3, l4, l6, l8;
	bool l5;
	void* t0 = NULL;
	int64_t t1;
	void** gc_raw_roots[5] = { &l0, &l1, &l7, &l9, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(476u, 0u, 13u, 2486u);
	l1 = (void*) _a0_arr;
	l2 = INT64_C(0);
	l3 = INT64_C(0);
	l4 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$StructDecl_t*) l0)->f_fields));
	l5 = (l3 <= l4);
	while (l5) {
		for (;;) {
			l6 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$StructDecl_t*) l0)->f_spreads));
			if ((l2 < l6)) {
				vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$StructDecl_t*) l0)->f_spreads);
				VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
				VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
				t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l2);
				t1 = ((vader_struct_toolchain_ast$StructSpread_t*) t0)->f_at;
				if (!(t1 == l3)) {
					break;
				}
				vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$StructDecl_t*) l0)->f_spreads);
				VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
				VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
				l7 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l2);
				vader_array_push_ref((vader_array_t*) l1, l7);
				l2 = vader_chk_add(i64, l2, INT64_C(1));
				continue;
			}
			break;
		}
		l8 = vader_array_length(((vader_array_t*) ((vader_struct_toolchain_ast$StructDecl_t*) l0)->f_fields));
		if ((l3 < l8)) {
			vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$StructDecl_t*) l0)->f_fields);
			VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
			VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
			l9 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l3);
			vader_array_push_ref((vader_array_t*) l1, l9);
		}
		l5 = (l3 < l4);
		l3 = (l3 + INT64_C(1));
	}
	{ void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t toolchain_ast$take_first(vader_box_t l0, void* l1, void* l2) {
	vader_box_t l3 = vader_box_null();
	vader_box_t t0 = vader_box_null();
	bool t1;
	vader_box_t* gc_roots[3] = { &l0, &l3, &t0 };
	void** gc_raw_roots[2] = { &l1, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	if ((l0.tag == 1127u || l0.tag == 1130u || l0.tag == 1131u || l0.tag == 1132u || l0.tag == 1135u || l0.tag == 1136u || l0.tag == 1137u || l0.tag == 1152u || l0.tag == 1159u || l0.tag == 1160u || l0.tag == 1161u || l0.tag == 1164u || l0.tag == 1166u || l0.tag == 1167u || l0.tag == 1170u || l0.tag == 1175u || l0.tag == 1177u || l0.tag == 1178u || l0.tag == 1181u || l0.tag == 1185u || l0.tag == 1189u || l0.tag == 1195u || l0.tag == 1200u || l0.tag == 1202u || l0.tag == 1207u || l0.tag == 1217u)) {
		vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
		t0 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, l0);
		t1 = t0.payload.b;
		if (t1) {
			l3 = l0;
			vader_array_push_ref((vader_array_t*) l2, l3.payload.obj);
			{ vader_gc_top = gc_frame.prev; return (uint8_t) 2; }
		}
		{ vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
	}
	{ vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
}

vader_box_t toolchain_ast$trait_alias_target(void* l0) {
	vader_box_t l1;
	bool l2;
	bool t0;
	t0 = std_core$is_empty__toolchain_ast_FnDecl(((vader_struct_toolchain_ast$TraitDecl_t*) l0)->f_members);
	if (!(t0)) {
		return vader_box_obj(0u, NULL);
	}
	l1 = ((vader_struct_toolchain_ast$TraitDecl_t*) l0)->f_requires;
	if (l1.tag == 0u) {
		return vader_box_obj(0u, NULL);
	}
	if (l1.tag == 1167u) {
		l2 = true;
	} else {
		l2 = l1.tag == 1160u;
	}
	if (l2) {
		l2 = true;
	} else {
		l2 = l1.tag == 1166u;
	}
	if (!(l2)) {
		return vader_box_obj(0u, NULL);
	}
	return l1;
}

vader_string_t toolchain_ast$unary_op_symbol(uint8_t l0) {
	vader_string_t l1;
	if (l0 == INT32_C(0)) {
		l1 = 476u;
		return l1;
	}
	if (l0 == INT32_C(1)) {
		l1 = 311u;
	} else {
		if (!(l0 == INT32_C(2))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = 3817u;
	}
	return l1;
}

vader_box_t toolchain_ast$written_value(void* l0) {
	vader_box_t l1;
	l1 = ((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_comptime_body;
	if (l1.tag == 0u) {
		return ((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_value;
	}
	return l1;
}
