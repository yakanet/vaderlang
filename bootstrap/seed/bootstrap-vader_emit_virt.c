#include "bootstrap.split.h"

static vader_string_t vader_emit_virt$bounds_safe_word(bool l0);
static vader_string_t vader_emit_virt$convert_target_name(uint8_t l0);
static vader_string_t vader_emit_virt$f64_const_operands(double l0);
static void vader_emit_virt$printed(void* l0, void* l1, vader_string_t l2, void* l3);
static vader_string_t vader_emit_virt$quote_string(vader_string_t l0);
static vader_string_t vader_emit_virt$reason_word(vader_string_t l0);
static void* vader_emit_virt$refer(uint8_t l0, int32_t l1);
static void* vader_emit_virt$refer_field(int32_t l0, int32_t l1);
static void vader_emit_virt$write_op_refs(void* l0, void* l1, vader_box_t l2);
static void vader_emit_virt$write_results(void* l0, void* l1);

static vader_string_t vader_emit_virt$bounds_safe_word(bool l0) {
	if (l0) {
		return 266u;
	}
	return 0u;
}

static vader_string_t vader_emit_virt$convert_target_name(uint8_t l0) {
	vader_string_t l1;
	if (l0 == INT32_C(0)) {
		l1 = 2655u;
		return l1;
	}
	if (l0 == INT32_C(1)) {
		l1 = 2677u;
	} else if (l0 == INT32_C(2)) {
		l1 = 2503u;
	} else {
		if (!(l0 == INT32_C(3))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = 2247u;
	}
	return l1;
}

static vader_string_t vader_emit_virt$f64_const_operands(double l0) {
	vader_string_t l1 = 0;
	int64_t l2;
	void* l3 = NULL;
	uint64_t l4;
	bool t0;
	vader_string_t t1 = 0;
	int64_t t2;
	void** gc_raw_roots[1] = { &l3 };
	vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = std_math$is_finite(l0);
	if (!(t0)) {
		t1 = std_core$f64$Display$to_string(l0);
		{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l1 = std_core$f64$Display$to_string(l0);
	l2 = (int64_t) vader_string_byte_len(l1);
	l3 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l2));
	l2 = INT64_C(0);
	l2 = std_core$write_string_at(l3, l2, l1);
	l2 = std_core$write_string_at(l3, l2, 19u);
	t2 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = l0 }).__vu);
	l4 = (uint64_t) (int64_t) t2;
	l2 = std_core$write_unsigned(l3, l2, l4);
	t1 = std_core$finish_buffer(l3, l2);
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_virt$printed(void* l0, void* l1, vader_string_t l2, void* l3) {
	void* l4 = NULL;
	void* l7 = NULL;
	void* l8 = NULL;
	int64_t l5, l6, l9, l10;
	vader_string_t l11 = 0;
	int32_t t0;
	void** gc_raw_roots[6] = { &l0, &l1, &l3, &l4, &l7, &l8 };
	vader_string_t* gc_atom_roots[2] = { &l2, &l11 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	std_string__builder$append(l0, l2);
	l4 = l3;
	l5 = vader_array_length(((vader_array_t*) l4));
	l6 = INT64_C(0);
	while ((l6 < l5)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		l7 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
		l8 = (void*) vader_buffer_new((size_t) INT64_C(21));
		l9 = INT64_C(0);
		l9 = std_core$write_string_at(l8, l9, 19u);
		t0 = ((vader_struct_vader_emit_virt$OperandRef_t*) l7)->f_index;
		l10 = ((int64_t) (int32_t) t0);
		l9 = std_core$write_int(l8, l9, l10);
		l11 = std_core$finish_buffer(l8, l9);
		std_string__builder$append(l0, l11);
		vader_array_push_ref((vader_array_t*) l1, l7);
		l6 = (l6 + INT64_C(1));
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_emit_virt$quote_string(vader_string_t l0) {
	void* l1 = NULL;
	int64_t l2, l3, l5;
	uint8_t l4;
	vader_string_t l6 = 0;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	void** gc_raw_roots[2] = { &l1, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l0, &l6, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 642u);
	t0 = (void*) _a0_arr;
	vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
	vader_obj_header_init(_a1_obj, 1139u);
	_a1_obj->f_parts = t0;
	l1 = (void*) _a1_obj;
	std_string__builder$append(l1, 317u);
	l2 = (int64_t) vader_string_byte_len(l0);
	l3 = INT64_C(0);
	while ((l3 < l2)) {
		l4 = vader_string_byte_at(l0, (size_t) l3);
		if (l4 == INT32_C(92)) {
			std_string__builder$append(l1, 1240u);
		} else if (l4 == INT32_C(34)) {
			std_string__builder$append(l1, 1237u);
		} else if (l4 == INT32_C(10)) {
			std_string__builder$append(l1, 1241u);
		} else if (l4 == INT32_C(13)) {
			std_string__builder$append(l1, 1242u);
		} else if (l4 == INT32_C(9)) {
			std_string__builder$append(l1, 1243u);
		} else if (l4 == INT32_C(0)) {
			std_string__builder$append(l1, 1239u);
		} else {
			l5 = vader_chk_add(i64, l3, INT64_C(1));
			l6 = vader_string_byte_slice(l0, l3, l5);
			std_string__builder$append(l1, l6);
		}
		l3 = (l3 + INT64_C(1));
	}
	std_string__builder$append(l1, 317u);
	t1 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_virt$reason_word(vader_string_t l0) {
	vader_string_t l1 = 0;
	vader_string_t t0 = 0;
	vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	if (l0 == 0u) {
		{ vader_gc_top = gc_frame.prev; return 0u; }
	}
	l1 = vader_emit_virt$quote_string(l0);
	t0 = concat_2(19u, l1);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_virt$refer(uint8_t l0, int32_t l1) {
	void* t0 = NULL;
	void** gc_raw_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_struct_vader_emit_virt$OperandRef_t* _a0_obj = (vader_struct_vader_emit_virt$OperandRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_virt$OperandRef_t));
	vader_obj_header_init(_a0_obj, 1670u);
	_a0_obj->f_kind = l0;
	_a0_obj->f_index = l1;
	_a0_obj->f_owner = INT32_C(-1);
	t0 = (void*) _a0_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_virt$refer_field(int32_t l0, int32_t l1) {
	void* t0 = NULL;
	void** gc_raw_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_struct_vader_emit_virt$OperandRef_t* _a0_obj = (vader_struct_vader_emit_virt$OperandRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_virt$OperandRef_t));
	vader_obj_header_init(_a0_obj, 1670u);
	_a0_obj->f_kind = (uint8_t) 2;
	_a0_obj->f_index = l1;
	_a0_obj->f_owner = l0;
	t0 = (void*) _a0_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_emit_virt$write_op(void* l0, vader_box_t l1) {
	void* l2 = NULL;
	vader_box_t* gc_roots[1] = { &l1 };
	void** gc_raw_roots[2] = { &l0, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(475u, 0u, 13u, 2298u);
	l2 = (void*) _a0_arr;
	vader_emit_virt$write_op_refs(l0, l2, l1);
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_virt$write_op_refs(void* l0, void* l1, vader_box_t l2) {
	void* l3 = NULL;
	void* l10 = NULL;
	void* l12 = NULL;
	int64_t l4, l5;
	vader_string_t l6 = 0;
	vader_string_t l14 = 0;
	bool l7;
	uint64_t l8;
	int32_t l9, l11;
	vader_box_t l13 = vader_box_null();
	void* t0 = NULL;
	int32_t t1;
	double t2;
	uint32_t t3;
	int64_t t4;
	vader_string_t t5 = 0;
	bool t6;
	vader_box_t* gc_roots[2] = { &l2, &l13 };
	void** gc_raw_roots[6] = { &l0, &l1, &l3, &l10, &l12, &t0 };
	vader_string_t* gc_atom_roots[3] = { &l6, &l14, &t5 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l2.tag == 1388u) {
		l3 = (void*) vader_buffer_new((size_t) INT64_C(30));
		l4 = INT64_C(0);
		l4 = std_core$write_string_at(l3, l4, 2661u);
		t0 = l2.payload.obj;
		t1 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
		l5 = ((int64_t) (int32_t) t1);
		l4 = std_core$write_int(l3, l4, l5);
		l6 = std_core$finish_buffer(l3, l4);
		std_string__builder$append(l0, l6);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	if (l2.tag == 1408u) {
		l3 = (void*) vader_buffer_new((size_t) INT64_C(30));
		l4 = INT64_C(0);
		l4 = std_core$write_string_at(l3, l4, 2683u);
		t0 = l2.payload.obj;
		l5 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
		l4 = std_core$write_int(l3, l4, l5);
		l6 = std_core$finish_buffer(l3, l4);
		std_string__builder$append(l0, l6);
	} else if (l2.tag == 1367u) {
		t0 = l2.payload.obj;
		t2 = ((vader_struct_vader_core_bytecode$F64Const_t*) t0)->f_value;
		l6 = vader_emit_virt$f64_const_operands(t2);
		l6 = concat_2(2505u, l6);
		std_string__builder$append(l0, l6);
	} else if (l2.tag == 1339u) {
		l3 = (void*) vader_buffer_new((size_t) INT64_C(16));
		l4 = INT64_C(0);
		l4 = std_core$write_string_at(l3, l4, 2109u);
		t0 = l2.payload.obj;
		l7 = ((vader_struct_vader_core_bytecode$BoolConst_t*) t0)->f_value;
		l4 = std_core$write_bool(l3, l4, l7);
		l6 = std_core$finish_buffer(l3, l4);
		std_string__builder$append(l0, l6);
	} else if (l2.tag == 1354u) {
		l3 = (void*) vader_buffer_new((size_t) INT64_C(31));
		l4 = INT64_C(0);
		l4 = std_core$write_string_at(l3, l4, 2249u);
		t0 = l2.payload.obj;
		t3 = ((vader_struct_vader_core_bytecode$CharConst_t*) t0)->f_value;
		t4 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3));
		l8 = (uint64_t) (int64_t) t4;
		l4 = std_core$write_unsigned(l3, l4, l8);
		l6 = std_core$finish_buffer(l3, l4);
		std_string__builder$append(l0, l6);
	} else if (l2.tag == 1439u) {
		std_string__builder$append(l0, 3026u);
	} else if (l2.tag == 1486u) {
		std_string__builder$append(l0, 3740u);
	} else if (l2.tag == 1460u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$StringConst_t*) t0)->f_index;
		t0 = vader_emit_virt$refer((uint8_t) 3, l9);
		vader_array_t* _a0_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0;
		l3 = (void*) _a0_arr;
		vader_emit_virt$printed(l0, l1, 3280u, l3);
	} else if (l2.tag == 1433u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
		t0 = vader_emit_virt$refer((uint8_t) 6, l9);
		vader_array_t* _a1_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0;
		l3 = (void*) _a1_arr;
		vader_emit_virt$printed(l0, l1, 2869u, l3);
	} else if (l2.tag == 1434u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
		t0 = vader_emit_virt$refer((uint8_t) 6, l9);
		vader_array_t* _a2_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t0;
		l3 = (void*) _a2_arr;
		vader_emit_virt$printed(l0, l1, 2870u, l3);
	} else if (l2.tag == 1435u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
		t0 = vader_emit_virt$refer((uint8_t) 6, l9);
		vader_array_t* _a3_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 0u] = t0;
		l3 = (void*) _a3_arr;
		vader_emit_virt$printed(l0, l1, 2871u, l3);
	} else if (l2.tag == 1432u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_slot;
		l3 = vader_emit_virt$refer((uint8_t) 6, l9);
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_type_id;
		l10 = vader_emit_virt$refer((uint8_t) 1, l9);
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_type_id;
		t0 = l2.payload.obj;
		l11 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_field_index;
		l12 = vader_emit_virt$refer_field(l9, l11);
		vader_array_t* _a4_arr = vader_array_new(284u, 3u, 13u, 1670u);
		((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 2u] = l12;
		((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 1u] = l10;
		((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = l3;
		l3 = (void*) _a4_arr;
		vader_emit_virt$printed(l0, l1, 2868u, l3);
	} else if (l2.tag == 1444u) {
		std_string__builder$append(l0, 3159u);
	} else if (l2.tag == 1445u) {
		std_string__builder$append(l0, 3163u);
		vader_array_push_ref((vader_array_t*) l1, vader_box_obj(0u, NULL).payload.obj);
		t0 = l2.payload.obj;
		l13 = ((vader_struct_vader_core_bytecode$ReturnLit_t*) t0)->f_value;
		vader_emit_virt$write_op_refs(l0, l1, l13);
	} else if (l2.tag == 1362u) {
		std_string__builder$append(l0, 2370u);
	} else if (l2.tag == 1351u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
		t0 = vader_emit_virt$refer((uint8_t) 0, l9);
		vader_array_t* _a5_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = t0;
		l3 = (void*) _a5_arr;
		vader_emit_virt$printed(l0, l1, 2196u, l3);
	} else if (l2.tag == 1352u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
		t0 = vader_emit_virt$refer((uint8_t) 4, l9);
		vader_array_t* _a6_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 0u] = t0;
		l3 = (void*) _a6_arr;
		vader_emit_virt$printed(l0, l1, 2199u, l3);
	} else if (l2.tag == 1353u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
		t0 = vader_emit_virt$refer((uint8_t) 1, l9);
		vader_array_t* _a7_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = t0;
		l3 = (void*) _a7_arr;
		vader_emit_virt$printed(l0, l1, 2200u, l3);
	} else if (l2.tag == 1485u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_parameter_count;
		t0 = l2.payload.obj;
		l6 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_vtable_key;
		l4 = (int64_t) vader_string_byte_len(l6);
		l3 = (void*) vader_buffer_new((size_t) (INT64_C(38) + l4));
		l4 = INT64_C(0);
		l4 = std_core$write_string_at(l3, l4, 3734u);
		l5 = ((int64_t) (int32_t) l9);
		l4 = std_core$write_int(l3, l4, l5);
		l4 = std_core$write_string_at(l3, l4, 19u);
		l4 = std_core$write_string_at(l3, l4, l6);
		l4 = std_core$write_string_at(l3, l4, 80u);
		l6 = std_core$finish_buffer(l3, l4);
		std_string__builder$append(l0, l6);
		t0 = l2.payload.obj;
		l3 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_results;
		vader_emit_virt$write_results(l0, l3);
	} else if (l2.tag == 1380u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
		l3 = vader_emit_virt$refer((uint8_t) 0, l9);
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_type_id;
		l10 = vader_emit_virt$refer((uint8_t) 1, l9);
		vader_array_t* _a8_arr = vader_array_new(284u, 2u, 13u, 1670u);
		((void**) _a8_arr->buf->slots)[vader_array_offset(_a8_arr) + 1u] = l10;
		((void**) _a8_arr->buf->slots)[vader_array_offset(_a8_arr) + 0u] = l3;
		l3 = (void*) _a8_arr;
		vader_emit_virt$printed(l0, l1, 2569u, l3);
	} else if (l2.tag == 1379u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$FnAddr_t*) t0)->f_function_index;
		t0 = vader_emit_virt$refer((uint8_t) 0, l9);
		vader_array_t* _a9_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a9_arr->buf->slots)[vader_array_offset(_a9_arr) + 0u] = t0;
		l3 = (void*) _a9_arr;
		vader_emit_virt$printed(l0, l1, 2567u, l3);
	} else if (l2.tag == 1355u) {
		t0 = l2.payload.obj;
		l6 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_kind);
		t0 = l2.payload.obj;
		l14 = vader_core_bytecode$checked_op_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_op);
		l6 = concat_3(l6, 504u, l14);
		std_string__builder$append(l0, l6);
	} else if (l2.tag == 1356u) {
		t0 = l2.payload.obj;
		t5 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$CheckedNeg_t*) t0)->f_kind);
		l6 = concat_2(t5, 505u);
		std_string__builder$append(l0, l6);
	} else if (l2.tag == 1437u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
		l3 = vader_emit_virt$refer((uint8_t) 0, l9);
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_env_type_id;
		l10 = vader_emit_virt$refer((uint8_t) 1, l9);
		vader_array_t* _a10_arr = vader_array_new(284u, 2u, 13u, 1670u);
		((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 1u] = l10;
		((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 0u] = l3;
		l3 = (void*) _a10_arr;
		vader_emit_virt$printed(l0, l1, 2897u, l3);
	} else if (l2.tag == 1423u) {
		std_string__builder$append(l0, 2705u);
	} else if (l2.tag == 1363u) {
		std_string__builder$append(l0, 2387u);
	} else if (l2.tag == 1364u) {
		std_string__builder$append(l0, 2406u);
	} else if (l2.tag == 1337u) {
		std_string__builder$append(l0, 2101u);
	} else if (l2.tag == 1436u) {
		std_string__builder$append(l0, 2874u);
	} else if (l2.tag == 1344u) {
		std_string__builder$append(l0, 2118u);
	} else if (l2.tag == 1345u) {
		std_string__builder$append(l0, 2120u);
	} else if (l2.tag == 1342u) {
		std_string__builder$append(l0, 2112u);
	} else if (l2.tag == 1466u) {
		t0 = l2.payload.obj;
		t6 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_stack;
		if (t6) {
			l6 = 3304u;
		} else {
			l6 = 3301u;
		}
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
		t0 = vader_emit_virt$refer((uint8_t) 1, l9);
		vader_array_t* _a11_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a11_arr->buf->slots)[vader_array_offset(_a11_arr) + 0u] = t0;
		l3 = (void*) _a11_arr;
		vader_emit_virt$printed(l0, l1, l6, l3);
	} else if (l2.tag == 1465u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
		l3 = vader_emit_virt$refer((uint8_t) 1, l9);
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
		t0 = l2.payload.obj;
		l11 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_field_index;
		l10 = vader_emit_virt$refer_field(l9, l11);
		vader_array_t* _a12_arr = vader_array_new(284u, 2u, 13u, 1670u);
		((void**) _a12_arr->buf->slots)[vader_array_offset(_a12_arr) + 1u] = l10;
		((void**) _a12_arr->buf->slots)[vader_array_offset(_a12_arr) + 0u] = l3;
		l3 = (void*) _a12_arr;
		vader_emit_virt$printed(l0, l1, 3300u, l3);
	} else if (l2.tag == 1467u) {
		t0 = l2.payload.obj;
		t6 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_stack;
		if (t6) {
			l6 = 3309u;
		} else {
			l6 = 3305u;
		}
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
		l3 = vader_emit_virt$refer((uint8_t) 1, l9);
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
		t0 = l2.payload.obj;
		l11 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_field_index;
		l10 = vader_emit_virt$refer_field(l9, l11);
		vader_array_t* _a13_arr = vader_array_new(284u, 2u, 13u, 1670u);
		((void**) _a13_arr->buf->slots)[vader_array_offset(_a13_arr) + 1u] = l10;
		((void**) _a13_arr->buf->slots)[vader_array_offset(_a13_arr) + 0u] = l3;
		l3 = (void*) _a13_arr;
		vader_emit_virt$printed(l0, l1, l6, l3);
	} else if (l2.tag == 1482u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
		l3 = vader_emit_virt$refer((uint8_t) 1, l9);
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
		t0 = l2.payload.obj;
		l11 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_field_index;
		l10 = vader_emit_virt$refer_field(l9, l11);
		vader_array_t* _a14_arr = vader_array_new(284u, 2u, 13u, 1670u);
		((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 1u] = l10;
		((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 0u] = l3;
		l3 = (void*) _a14_arr;
		vader_emit_virt$printed(l0, l1, 3504u, l3);
	} else if (l2.tag == 1483u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
		l3 = vader_emit_virt$refer((uint8_t) 1, l9);
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
		t0 = l2.payload.obj;
		l11 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_field_index;
		l10 = vader_emit_virt$refer_field(l9, l11);
		vader_array_t* _a15_arr = vader_array_new(284u, 2u, 13u, 1670u);
		((void**) _a15_arr->buf->slots)[vader_array_offset(_a15_arr) + 1u] = l10;
		((void**) _a15_arr->buf->slots)[vader_array_offset(_a15_arr) + 0u] = l3;
		l3 = (void*) _a15_arr;
		vader_emit_virt$printed(l0, l1, 3505u, l3);
	} else if (l2.tag == 1307u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_type_id;
		t0 = vader_emit_virt$refer((uint8_t) 1, l9);
		vader_array_t* _a16_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a16_arr->buf->slots)[vader_array_offset(_a16_arr) + 0u] = t0;
		l3 = (void*) _a16_arr;
		vader_emit_virt$printed(l0, l1, 2045u, l3);
		l3 = (void*) vader_buffer_new((size_t) INT64_C(21));
		l4 = INT64_C(0);
		l4 = std_core$write_string_at(l3, l4, 19u);
		t0 = l2.payload.obj;
		t1 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_length;
		l5 = ((int64_t) (int32_t) t1);
		l4 = std_core$write_int(l3, l4, l5);
		l6 = std_core$finish_buffer(l3, l4);
		std_string__builder$append(l0, l6);
	} else if (l2.tag == 1306u) {
		std_string__builder$append(l0, 2044u);
	} else if (l2.tag == 1308u) {
		t0 = l2.payload.obj;
		t1 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
		if ((t1 >= INT32_C(0))) {
			t0 = l2.payload.obj;
			l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
			l3 = vader_emit_virt$refer((uint8_t) 1, l9);
			t0 = l2.payload.obj;
			l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
			l10 = vader_emit_virt$refer((uint8_t) 6, l9);
			vader_array_t* _a17_arr = vader_array_new(284u, 2u, 13u, 1670u);
			((void**) _a17_arr->buf->slots)[vader_array_offset(_a17_arr) + 1u] = l10;
			((void**) _a17_arr->buf->slots)[vader_array_offset(_a17_arr) + 0u] = l3;
			l3 = (void*) _a17_arr;
			vader_emit_virt$printed(l0, l1, 2047u, l3);
		} else {
			t0 = l2.payload.obj;
			l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
			t0 = vader_emit_virt$refer((uint8_t) 1, l9);
			vader_array_t* _a18_arr = vader_array_new(284u, 1u, 13u, 1670u);
			((void**) _a18_arr->buf->slots)[vader_array_offset(_a18_arr) + 0u] = t0;
			l3 = (void*) _a18_arr;
			vader_emit_virt$printed(l0, l1, 2047u, l3);
		}
	} else if (l2.tag == 1305u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_type_id;
		t0 = vader_emit_virt$refer((uint8_t) 1, l9);
		vader_array_t* _a19_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a19_arr->buf->slots)[vader_array_offset(_a19_arr) + 0u] = t0;
		l3 = (void*) _a19_arr;
		vader_emit_virt$printed(l0, l1, 2043u, l3);
		t0 = l2.payload.obj;
		t6 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_bounds_safe;
		l6 = vader_emit_virt$bounds_safe_word(t6);
		std_string__builder$append(l0, l6);
	} else if (l2.tag == 1313u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$ArraySet_t*) t0)->f_type_id;
		t0 = vader_emit_virt$refer((uint8_t) 1, l9);
		vader_array_t* _a20_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a20_arr->buf->slots)[vader_array_offset(_a20_arr) + 0u] = t0;
		l3 = (void*) _a20_arr;
		vader_emit_virt$printed(l0, l1, 2058u, l3);
		t0 = l2.payload.obj;
		t6 = ((vader_struct_vader_core_bytecode$ArraySet_t*) t0)->f_bounds_safe;
		l6 = vader_emit_virt$bounds_safe_word(t6);
		std_string__builder$append(l0, l6);
	} else if (l2.tag == 1314u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$ArraySlice_t*) t0)->f_type_id;
		t0 = vader_emit_virt$refer((uint8_t) 1, l9);
		vader_array_t* _a21_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a21_arr->buf->slots)[vader_array_offset(_a21_arr) + 0u] = t0;
		l3 = (void*) _a21_arr;
		vader_emit_virt$printed(l0, l1, 2059u, l3);
	} else if (l2.tag == 1312u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$ArrayReserve_t*) t0)->f_type_id;
		t0 = vader_emit_virt$refer((uint8_t) 1, l9);
		vader_array_t* _a22_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a22_arr->buf->slots)[vader_array_offset(_a22_arr) + 0u] = t0;
		l3 = (void*) _a22_arr;
		vader_emit_virt$printed(l0, l1, 2056u, l3);
	} else if (l2.tag == 1311u) {
		std_string__builder$append(l0, 2053u);
	} else if (l2.tag == 1309u) {
		std_string__builder$append(l0, 2048u);
	} else if (l2.tag == 1304u) {
		std_string__builder$append(l0, 2035u);
	} else if (l2.tag == 1310u) {
		std_string__builder$append(l0, 2051u);
	} else if (l2.tag == 1303u) {
		std_string__builder$append(l0, 2033u);
	} else if (l2.tag == 1358u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
		l3 = vader_emit_virt$refer((uint8_t) 5, l9);
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_type_id;
		l10 = vader_emit_virt$refer((uint8_t) 1, l9);
		vader_array_t* _a23_arr = vader_array_new(284u, 2u, 13u, 1670u);
		((void**) _a23_arr->buf->slots)[vader_array_offset(_a23_arr) + 1u] = l10;
		((void**) _a23_arr->buf->slots)[vader_array_offset(_a23_arr) + 0u] = l3;
		l3 = (void*) _a23_arr;
		vader_emit_virt$printed(l0, l1, 2331u, l3);
	} else if (l2.tag == 1381u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
		t0 = vader_emit_virt$refer((uint8_t) 7, l9);
		vader_array_t* _a24_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a24_arr->buf->slots)[vader_array_offset(_a24_arr) + 0u] = t0;
		l3 = (void*) _a24_arr;
		vader_emit_virt$printed(l0, l1, 2631u, l3);
	} else if (l2.tag == 1382u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
		t0 = vader_emit_virt$refer((uint8_t) 7, l9);
		vader_array_t* _a25_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a25_arr->buf->slots)[vader_array_offset(_a25_arr) + 0u] = t0;
		l3 = (void*) _a25_arr;
		vader_emit_virt$printed(l0, l1, 2632u, l3);
	} else if (l2.tag == 1469u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
		t0 = vader_emit_virt$refer((uint8_t) 1, l9);
		vader_array_t* _a26_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a26_arr->buf->slots)[vader_array_offset(_a26_arr) + 0u] = t0;
		l3 = (void*) _a26_arr;
		vader_emit_virt$printed(l0, l1, 3443u, l3);
	} else if (l2.tag == 1468u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
		t0 = vader_emit_virt$refer((uint8_t) 1, l9);
		vader_array_t* _a27_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a27_arr->buf->slots)[vader_array_offset(_a27_arr) + 0u] = t0;
		l3 = (void*) _a27_arr;
		vader_emit_virt$printed(l0, l1, 3447u, l3);
	} else if (l2.tag == 1440u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$RefCast_t*) t0)->f_type_id;
		t0 = vader_emit_virt$refer((uint8_t) 1, l9);
		vader_array_t* _a28_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a28_arr->buf->slots)[vader_array_offset(_a28_arr) + 0u] = t0;
		l3 = (void*) _a28_arr;
		vader_emit_virt$printed(l0, l1, 3130u, l3);
	} else if (l2.tag == 1443u) {
		t0 = l2.payload.obj;
		l9 = ((vader_struct_vader_core_bytecode$Retag_t*) t0)->f_type_id;
		t0 = vader_emit_virt$refer((uint8_t) 1, l9);
		vader_array_t* _a29_arr = vader_array_new(284u, 1u, 13u, 1670u);
		((void**) _a29_arr->buf->slots)[vader_array_offset(_a29_arr) + 0u] = t0;
		l3 = (void*) _a29_arr;
		vader_emit_virt$printed(l0, l1, 3156u, l3);
	} else if (l2.tag == 1484u) {
		t0 = l2.payload.obj;
		t5 = ((vader_struct_vader_core_bytecode$Unreachable_t*) t0)->f_reason;
		l6 = vader_emit_virt$reason_word(t5);
		l6 = concat_2(3521u, l6);
		std_string__builder$append(l0, l6);
	} else if (l2.tag == 1357u) {
		t0 = l2.payload.obj;
		l6 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_from_name;
		t0 = l2.payload.obj;
		l14 = vader_emit_virt$convert_target_name(((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_target);
		l6 = concat_3(l6, 532u, l14);
		std_string__builder$append(l0, l6);
	} else if (l2.tag == 1447u) {
		std_string__builder$append(l0, 2772u);
	} else if (l2.tag == 1383u) {
		std_string__builder$append(l0, 2656u);
	} else if (l2.tag == 1402u) {
		std_string__builder$append(l0, 2676u);
	} else if (l2.tag == 1396u) {
		std_string__builder$append(l0, 2670u);
	} else if (l2.tag == 1389u) {
		std_string__builder$append(l0, 2662u);
	} else if (l2.tag == 1395u) {
		std_string__builder$append(l0, 2673u);
	} else if (l2.tag == 1398u) {
		std_string__builder$append(l0, 2672u);
	} else if (l2.tag == 1385u) {
		std_string__builder$append(l0, 2658u);
	} else if (l2.tag == 1384u) {
		std_string__builder$append(l0, 2657u);
	} else if (l2.tag == 1386u) {
		std_string__builder$append(l0, 2659u);
	} else if (l2.tag == 1387u) {
		std_string__builder$append(l0, 2660u);
	} else if (l2.tag == 1399u) {
		std_string__builder$append(l0, 2674u);
	} else if (l2.tag == 1400u) {
		std_string__builder$append(l0, 2675u);
	} else if (l2.tag == 1401u) {
		std_string__builder$append(l0, 3476u);
	} else if (l2.tag == 1390u) {
		std_string__builder$append(l0, 2664u);
	} else if (l2.tag == 1397u) {
		std_string__builder$append(l0, 2671u);
	} else if (l2.tag == 1394u) {
		std_string__builder$append(l0, 2668u);
	} else if (l2.tag == 1393u) {
		std_string__builder$append(l0, 2667u);
	} else if (l2.tag == 1392u) {
		std_string__builder$append(l0, 2666u);
	} else if (l2.tag == 1391u) {
		std_string__builder$append(l0, 2665u);
	} else if (l2.tag == 1403u) {
		std_string__builder$append(l0, 2678u);
	} else if (l2.tag == 1422u) {
		std_string__builder$append(l0, 2698u);
	} else if (l2.tag == 1416u) {
		std_string__builder$append(l0, 2691u);
	} else if (l2.tag == 1409u) {
		std_string__builder$append(l0, 2684u);
	} else if (l2.tag == 1415u) {
		std_string__builder$append(l0, 2694u);
	} else if (l2.tag == 1418u) {
		std_string__builder$append(l0, 2693u);
	} else if (l2.tag == 1404u) {
		std_string__builder$append(l0, 2679u);
	} else if (l2.tag == 1406u) {
		std_string__builder$append(l0, 2681u);
	} else if (l2.tag == 1407u) {
		std_string__builder$append(l0, 2682u);
	} else if (l2.tag == 1405u) {
		std_string__builder$append(l0, 2680u);
	} else if (l2.tag == 1419u) {
		std_string__builder$append(l0, 2696u);
	} else if (l2.tag == 1420u) {
		std_string__builder$append(l0, 2697u);
	} else if (l2.tag == 1421u) {
		std_string__builder$append(l0, 3486u);
	} else if (l2.tag == 1410u) {
		std_string__builder$append(l0, 2686u);
	} else if (l2.tag == 1417u) {
		std_string__builder$append(l0, 2692u);
	} else if (l2.tag == 1414u) {
		std_string__builder$append(l0, 2690u);
	} else if (l2.tag == 1413u) {
		std_string__builder$append(l0, 2689u);
	} else if (l2.tag == 1412u) {
		std_string__builder$append(l0, 2688u);
	} else if (l2.tag == 1411u) {
		std_string__builder$append(l0, 2687u);
	} else if (l2.tag == 1470u) {
		std_string__builder$append(l0, 3468u);
	} else if (l2.tag == 1475u) {
		std_string__builder$append(l0, 3474u);
	} else if (l2.tag == 1474u) {
		std_string__builder$append(l0, 3473u);
	} else if (l2.tag == 1473u) {
		std_string__builder$append(l0, 3472u);
	} else if (l2.tag == 1472u) {
		std_string__builder$append(l0, 3471u);
	} else if (l2.tag == 1471u) {
		std_string__builder$append(l0, 3470u);
	} else if (l2.tag == 1476u) {
		std_string__builder$append(l0, 3478u);
	} else if (l2.tag == 1481u) {
		std_string__builder$append(l0, 3484u);
	} else if (l2.tag == 1480u) {
		std_string__builder$append(l0, 3483u);
	} else if (l2.tag == 1479u) {
		std_string__builder$append(l0, 3482u);
	} else if (l2.tag == 1478u) {
		std_string__builder$append(l0, 3481u);
	} else if (l2.tag == 1477u) {
		std_string__builder$append(l0, 3480u);
	} else if (l2.tag == 1366u) {
		std_string__builder$append(l0, 2504u);
	} else if (l2.tag == 1377u) {
		std_string__builder$append(l0, 2515u);
	} else if (l2.tag == 1374u) {
		std_string__builder$append(l0, 2512u);
	} else if (l2.tag == 1368u) {
		std_string__builder$append(l0, 2506u);
	} else if (l2.tag == 1376u) {
		std_string__builder$append(l0, 2514u);
	} else if (l2.tag == 1369u) {
		std_string__builder$append(l0, 2507u);
	} else if (l2.tag == 1375u) {
		std_string__builder$append(l0, 2513u);
	} else if (l2.tag == 1373u) {
		std_string__builder$append(l0, 2511u);
	} else if (l2.tag == 1372u) {
		std_string__builder$append(l0, 2510u);
	} else if (l2.tag == 1371u) {
		std_string__builder$append(l0, 2509u);
	} else if (l2.tag == 1370u) {
		std_string__builder$append(l0, 2508u);
	} else if (l2.tag == 1340u) {
		std_string__builder$append(l0, 2110u);
	} else if (l2.tag == 1341u) {
		std_string__builder$append(l0, 2111u);
	} else if (l2.tag == 1338u) {
		std_string__builder$append(l0, 2108u);
	} else if (l2.tag == 1343u) {
		std_string__builder$append(l0, 2113u);
	} else if (l2.tag == 1461u) {
		std_string__builder$append(l0, 3281u);
	} else if (l2.tag == 1464u) {
		std_string__builder$append(l0, 3285u);
	} else if (l2.tag == 1459u) {
		std_string__builder$append(l0, 3279u);
	} else if (l2.tag == 1457u) {
		std_string__builder$append(l0, 3277u);
	} else if (l2.tag == 1456u) {
		std_string__builder$append(l0, 3276u);
	} else if (l2.tag == 1458u) {
		std_string__builder$append(l0, 3278u);
	} else if (l2.tag == 1463u) {
		std_string__builder$append(l0, 3284u);
	} else if (l2.tag == 1462u) {
		std_string__builder$append(l0, 3283u);
	} else if (l2.tag == 1441u) {
		std_string__builder$append(l0, 3131u);
	} else if (l2.tag == 1442u) {
		std_string__builder$append(l0, 3132u);
	} else if (l2.tag == 1361u) {
		std_string__builder$append(l0, 2352u);
	} else if (l2.tag == 1360u) {
		l3 = (void*) vader_buffer_new((size_t) INT64_C(35));
		l4 = INT64_C(0);
		l4 = std_core$write_string_at(l3, l4, 2350u);
		t0 = l2.payload.obj;
		t1 = ((vader_struct_vader_core_bytecode$DeferPopExec_t*) t0)->f_count;
		l5 = ((int64_t) (int32_t) t1);
		l4 = std_core$write_int(l3, l4, l5);
		l6 = std_core$finish_buffer(l3, l4);
		std_string__builder$append(l0, l6);
	} else if (l2.tag == 1346u) {
		std_string__builder$append(l0, 2130u);
	} else if (l2.tag == 1431u) {
		std_string__builder$append(l0, 2862u);
	} else if (l2.tag == 1426u) {
		std_string__builder$append(l0, 2856u);
	} else if (l2.tag == 1427u) {
		std_string__builder$append(l0, 2857u);
	} else if (l2.tag == 1425u) {
		std_string__builder$append(l0, 2855u);
	} else if (l2.tag == 1455u) {
		std_string__builder$append(l0, 3269u);
	} else if (l2.tag == 1450u) {
		std_string__builder$append(l0, 3262u);
	} else if (l2.tag == 1451u) {
		std_string__builder$append(l0, 3263u);
	} else if (l2.tag == 1449u) {
		std_string__builder$append(l0, 3260u);
	} else if (l2.tag == 1429u) {
		t0 = l2.payload.obj;
		t6 = ((vader_struct_vader_core_bytecode$LoadSlotI32_t*) t0)->f_bounds_safe;
		l6 = vader_emit_virt$bounds_safe_word(t6);
		l6 = concat_2(2860u, l6);
		std_string__builder$append(l0, l6);
	} else if (l2.tag == 1430u) {
		t0 = l2.payload.obj;
		t6 = ((vader_struct_vader_core_bytecode$LoadSlotI64_t*) t0)->f_bounds_safe;
		l6 = vader_emit_virt$bounds_safe_word(t6);
		l6 = concat_2(2861u, l6);
		std_string__builder$append(l0, l6);
	} else if (l2.tag == 1428u) {
		t0 = l2.payload.obj;
		t6 = ((vader_struct_vader_core_bytecode$LoadSlotF64_t*) t0)->f_bounds_safe;
		l6 = vader_emit_virt$bounds_safe_word(t6);
		l6 = concat_2(2859u, l6);
		std_string__builder$append(l0, l6);
	} else if (l2.tag == 1453u) {
		t0 = l2.payload.obj;
		t6 = ((vader_struct_vader_core_bytecode$StoreSlotI32_t*) t0)->f_bounds_safe;
		l6 = vader_emit_virt$bounds_safe_word(t6);
		l6 = concat_2(3267u, l6);
		std_string__builder$append(l0, l6);
	} else if (l2.tag == 1454u) {
		t0 = l2.payload.obj;
		t6 = ((vader_struct_vader_core_bytecode$StoreSlotI64_t*) t0)->f_bounds_safe;
		l6 = vader_emit_virt$bounds_safe_word(t6);
		l6 = concat_2(3268u, l6);
		std_string__builder$append(l0, l6);
	} else if (l2.tag == 1452u) {
		t0 = l2.payload.obj;
		t6 = ((vader_struct_vader_core_bytecode$StoreSlotF64_t*) t0)->f_bounds_safe;
		l6 = vader_emit_virt$bounds_safe_word(t6);
		l6 = concat_2(3266u, l6);
		std_string__builder$append(l0, l6);
	} else if (l2.tag == 1438u) {
		std_string__builder$append(l0, 2920u);
	} else if (l2.tag == 1347u) {
		std_string__builder$append(l0, 2137u);
	} else if (l2.tag == 1348u) {
		std_string__builder$append(l0, 2140u);
	} else if (l2.tag == 1378u) {
		std_string__builder$append(l0, 2516u);
	} else if (l2.tag == 1336u) {
		std_string__builder$append(l0, 2099u);
	} else if (l2.tag == 1365u) {
		std_string__builder$append(l0, 2502u);
	} else {
		if (!(l2.tag == 1335u)) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		std_string__builder$append(l0, 2098u);
	}
	{ vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_virt$write_results(void* l0, void* l1) {
	vader_string_t l2 = 0;
	int64_t l3, l4;
	int64_t t0;
	vader_box_t t1 = vader_box_null();
	vader_box_t* gc_roots[1] = { &t1 };
	void** gc_raw_roots[2] = { &l0, &l1 };
	vader_string_t* gc_atom_roots[1] = { &l2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_array_length(((vader_array_t*) l1));
	if (t0 == INT64_C(1)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t1 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0), 647u);
		l2 = vader_core_bytecode$val_type_name(((uint8_t) t1.payload.i));
		std_string__builder$append(l0, l2);
		{ vader_gc_top = gc_frame.prev; return; }
	}
	std_string__builder$append_char(l0, 40u);
	l3 = INT64_C(0);
	l4 = vader_array_length(((vader_array_t*) l1));
	while ((l3 < l4)) {
		if ((l3 > INT64_C(0))) {
			std_string__builder$append(l0, 441u);
		}
		vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
		t1 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l3, 647u);
		l2 = vader_core_bytecode$val_type_name(((uint8_t) t1.payload.i));
		std_string__builder$append(l0, l2);
		l3 = (l3 + INT64_C(1));
	}
	std_string__builder$append_char(l0, 41u);
	{ vader_gc_top = gc_frame.prev; return; }
}
