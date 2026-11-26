#include "bootstrap.split.h"

static vader_string_t vader_core_mangle$generated_word(uint8_t l0);
static vader_string_t vader_core_mangle$lifted_prefix(uint8_t l0, bool l1);
static vader_box_t vader_core_mangle$wit_name_escape(uint8_t l0);

vader_string_t vader_core_mangle$cell_struct_name(vader_string_t l0) {
	vader_string_t t0;
	t0 = concat_2(335u, l0);
	return t0;
}

vader_string_t vader_core_mangle$declaration_mangle(vader_string_t l0, vader_string_t l1, vader_string_t l2) {
	vader_string_t t0 = 0;
	vader_string_t t1 = 0;
	vader_string_t* gc_atom_roots[5] = { &l0, &l1, &l2, &t0, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 5u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	t0 = vader_core_mangle$mangle_module_id(l0);
	t1 = concat_4(t0, 331u, l1, l2);
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_mangle$derived_mangle(vader_string_t l0, uint8_t l1) {
	vader_string_t l2 = 0;
	vader_string_t* gc_atom_roots[2] = { &l0, &l2 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 2u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	if (l1 == INT32_C(0)) {
		l2 = concat_2(l0, 343u);
		{ vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
	}
	if (l1 == INT32_C(1)) {
		l2 = concat_2(l0, 348u);
	} else if (l1 == INT32_C(2)) {
		l2 = concat_2(l0, 345u);
	} else if (l1 == INT32_C(3)) {
		l2 = concat_2(l0, 351u);
	} else if (l1 == INT32_C(4)) {
		l2 = concat_2(l0, 340u);
	} else if (l1 == INT32_C(5)) {
		l2 = concat_2(l0, 337u);
	} else if (l1 == INT32_C(6)) {
		l2 = concat_2(l0, 352u);
	} else {
		if (!(l1 == INT32_C(7))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l2 = concat_2(l0, 333u);
	}
	{ vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_mangle$field_default_mangle(vader_string_t l0, vader_string_t l1) {
	vader_string_t t0;
	t0 = concat_3(l0, 338u, l1);
	return t0;
}

vader_string_t vader_core_mangle$fn_overload_suffix(int64_t l0) {
	void* l1 = NULL;
	int64_t l2;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l1 };
	vader_string_t* gc_atom_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l0 == INT64_C(0)) {
		{ vader_gc_top = gc_frame.prev; return 0u; }
	}
	l1 = (void*) vader_buffer_new((size_t) INT64_C(21));
	l2 = INT64_C(0);
	l2 = std_core$write_string_at(l1, l2, 1240u);
	l2 = std_core$write_int(l1, l2, l0);
	t0 = std_core$finish_buffer(l1, l2);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_mangle$generated_name(vader_string_t l0, uint8_t l1) {
	vader_string_t l2 = 0;
	bool t0;
	vader_string_t t1 = 0;
	vader_string_t* gc_atom_roots[3] = { &l0, &l2, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	t0 = std_string$string$std_core$Contains$contains(l0, 331u);
	if (!(t0)) {
		l2 = vader_core_mangle$generated_word(l1);
		t1 = concat_3(l0, 332u, l2);
		{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	t1 = concat_3(2598u, l0, 1488u);
	vader_host_std_core$Intrinsic$panic(t1);
	vader_unreachable("a no-return call returned");
	vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_core_mangle$generated_word(uint8_t l0) {
	vader_string_t l1;
	if (l0 == INT32_C(0)) {
		l1 = 2738u;
		return l1;
	}
	if (l0 == INT32_C(1)) {
		l1 = 2816u;
	} else if (l0 == INT32_C(2)) {
		l1 = 870u;
	} else if (l0 == INT32_C(3)) {
		l1 = 3077u;
	} else {
		if (!(l0 == INT32_C(4))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = 3145u;
	}
	return l1;
}

vader_string_t vader_core_mangle$generator_state_name(vader_string_t l0, vader_string_t l1) {
	vader_string_t t0;
	t0 = concat_3(342u, l0, l1);
	return t0;
}

vader_string_t vader_core_mangle$impl_member_mangle(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4) {
	vader_string_t t0 = 0;
	vader_string_t t1 = 0;
	vader_string_t* gc_atom_roots[7] = { &l0, &l1, &l2, &l3, &l4, &t0, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 7u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	t0 = vader_core_mangle$mangle_module_id(l0);
	t1 = concat_8(t0, 331u, l1, 331u, l2, 331u, l3, l4);
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_mangle$impl_overload_suffix(int64_t l0) {
	void* l1 = NULL;
	int64_t l2;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l1 };
	vader_string_t* gc_atom_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	if (l0 == INT64_C(0)) {
		{ vader_gc_top = gc_frame.prev; return 0u; }
	}
	l1 = (void*) vader_buffer_new((size_t) INT64_C(21));
	l2 = INT64_C(0);
	l2 = std_core$write_string_at(l1, l2, 331u);
	l2 = std_core$write_int(l1, l2, l0);
	t0 = std_core$finish_buffer(l1, l2);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_mangle$instance_suffix(void* l0) {
	void* l1 = NULL;
	void* l2 = NULL;
	int64_t l3, l4;
	vader_string_t l5 = 0;
	void* t0 = NULL;
	vader_box_t t1 = vader_box_null();
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[1] = { &t1 };
	void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_string_t* gc_atom_roots[2] = { &l5, &t2 };
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
	l2 = l0;
	l3 = vader_array_length(((vader_array_t*) l2));
	l4 = INT64_C(0);
	while ((l4 < l3)) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		t1 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l4];
		l5 = t1.payload.s;
		std_string__builder$append(l1, 1253u);
		std_string__builder$append(l1, l5);
		l4 = (l4 + INT64_C(1));
	}
	t2 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
	{ vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_core_mangle$is_tuple_struct_name(vader_string_t l0) {
	bool t0;
	t0 = std_string$string$std_core$Contains$contains(l0, 1254u);
	return t0;
}

vader_string_t vader_core_mangle$lifted_mangle(uint8_t l0, bool l1, vader_string_t l2, int64_t l3) {
	vader_string_t l4 = 0;
	vader_string_t l5 = 0;
	int64_t l6, l7;
	void* l8 = NULL;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l8 };
	vader_string_t* gc_atom_roots[4] = { &l2, &l4, &l5, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l4 = vader_core_mangle$lifted_prefix(l0, l1);
	l5 = vader_core_mangle$mangle_module_id(l2);
	l6 = vader_host_std_core$Intrinsic$byte_len(l4);
	l7 = vader_host_std_core$Intrinsic$byte_len(l5);
	l6 = (l6 + l7);
	l8 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l6));
	l6 = INT64_C(0);
	l6 = std_core$write_string_at(l8, l6, l4);
	l6 = std_core$write_string_at(l8, l6, l5);
	l6 = std_core$write_string_at(l8, l6, 1240u);
	l6 = std_core$write_int(l8, l6, l3);
	t0 = std_core$finish_buffer(l8, l6);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_mangle$lifted_module_part(vader_string_t l0) {
	void* l1;
	int64_t l2, l3, l7, l8, l10;
	uint8_t l4;
	vader_string_t l5, l6, l9;
	vader_box_t l11;
	bool t0;
	vader_box_t t1;
	vader_string_t t2;
	t0 = std_string$starts_with(l0, 1253u);
	if (!(t0)) {
		return 0u;
	}
	l1 = (void*) &vader_data_10;
	l2 = vader_array_length(((vader_array_t*) l1));
	l3 = INT64_C(0);
	while ((l3 < l2)) {
		vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
		VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
		t1 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) l3, 635u);
		l4 = ((uint8_t) t1.payload.i);
		l5 = vader_core_mangle$lifted_prefix(l4, true);
		t0 = std_string$starts_with(l0, l5);
		if (t0) {
			return 0u;
		}
		l6 = vader_core_mangle$lifted_prefix(l4, false);
		t0 = std_string$starts_with(l0, l6);
		if (t0) {
			l7 = vader_host_std_core$Intrinsic$byte_len(l6);
			l8 = vader_host_std_core$Intrinsic$byte_len(l0);
			l9 = vader_host_std_core$Intrinsic$byte_slice(l0, l7, l8);
			l11 = std_string$last_index_of(l9, 95u, INT64_C(0));
			if (l11.tag == 0u) {
				return 0u;
			}
			l10 = ((int64_t) l11.payload.i);
			t2 = vader_host_std_core$Intrinsic$byte_slice(l9, INT64_C(0), l10);
			return t2;
		}
		l3 = (l3 + INT64_C(1));
	}
	return 0u;
}

static vader_string_t vader_core_mangle$lifted_prefix(uint8_t l0, bool l1) {
	vader_string_t l2;
	if (l0 == INT32_C(0)) {
		if (l1) {
			l2 = 1269u;
		} else {
			l2 = 1268u;
		}
		return l2;
	}
	if (l0 == INT32_C(1)) {
		if (l1) {
			l2 = 1265u;
		} else {
			l2 = 1264u;
		}
	} else if (l0 == INT32_C(2)) {
		if (l1) {
			l2 = 1267u;
		} else {
			l2 = 1266u;
		}
	} else {
		if (!(l0 == INT32_C(3))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		if (l1) {
			l2 = 1271u;
		} else {
			l2 = 1270u;
		}
	}
	return l2;
}

vader_string_t vader_core_mangle$mangle_last_segment(vader_string_t l0) {
	int64_t l1, l3, l4;
	vader_box_t l2;
	uint8_t t0;
	vader_string_t t1;
	int64_t t2;
	l2 = std_string$last_index_of(l0, 36u, INT64_C(0));
	if (l2.tag == 0u) {
		return l0;
	}
	l1 = ((int64_t) l2.payload.i);
	if ((l1 >= INT64_C(2))) {
		l3 = vader_chk_sub(i64, l1, INT64_C(1));
		t0 = vader_host_std_core$Intrinsic$byte_at(l0, l3);
		if (t0 == INT32_C(36)) {
			l3 = vader_chk_sub(i64, l1, INT64_C(1));
			t1 = vader_host_std_core$Intrinsic$byte_slice(l0, INT64_C(0), l3);
			l2 = std_string$last_index_of(t1, 36u, INT64_C(0));
			if (!(l2.tag == 0u)) {
				t2 = ((int64_t) l2.payload.i);
				l3 = vader_chk_add(i64, t2, INT64_C(1));
				l4 = vader_chk_sub(i64, l1, INT64_C(1));
				if ((l3 < l4)) {
					t2 = ((int64_t) l2.payload.i);
					l3 = vader_chk_add(i64, t2, INT64_C(1));
					l4 = vader_host_std_core$Intrinsic$byte_len(l0);
					t1 = vader_host_std_core$Intrinsic$byte_slice(l0, l3, l4);
					return t1;
				}
			}
		}
	}
	l1 = vader_chk_add(i64, l1, INT64_C(1));
	l3 = vader_host_std_core$Intrinsic$byte_len(l0);
	t1 = vader_host_std_core$Intrinsic$byte_slice(l0, l1, l3);
	return t1;
}

vader_string_t vader_core_mangle$mangle_module_id(vader_string_t l0) {
	void* l1 = NULL;
	int64_t l2, l3;
	uint8_t l4, l6;
	vader_box_t l5 = vader_box_null();
	int64_t t0;
	bool t1;
	vader_string_t t2 = 0;
	vader_box_t* gc_roots[1] = { &l5 };
	void** gc_raw_roots[1] = { &l1 };
	vader_string_t* gc_atom_roots[2] = { &l0, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = vader_host_std_core$Intrinsic$byte_len(l0);
	vader_array_t* _a0_arr = vader_array_reserve(31u, (int64_t) t0, 1u, 635u);
	l1 = (void*) _a0_arr;
	l2 = INT64_C(0);
	l3 = vader_host_std_core$Intrinsic$byte_len(l0);
	while ((l2 < l3)) {
		l4 = vader_host_std_core$Intrinsic$byte_at(l0, l2);
		if (l4 == INT32_C(95)) {
			vader_array_push_u8((vader_array_t*) l1, INT32_C(95));
			vader_array_push_u8((vader_array_t*) l1, INT32_C(95));
		} else {
			t1 = vader_support_text$is_ident_byte(l4);
			if (t1) {
				vader_array_push_u8((vader_array_t*) l1, (int32_t) (uint8_t) l4);
			} else {
				vader_array_push_u8((vader_array_t*) l1, INT32_C(95));
				l5 = vader_core_mangle$wit_name_escape(l4);
				if (!(l5.tag == 0u)) {
					l6 = ((uint8_t) l5.payload.i);
					vader_array_push_u8((vader_array_t*) l1, (int32_t) (uint8_t) l6);
				}
			}
		}
		l2 = (l2 + INT64_C(1));
	}
	t2 = vader_host_std_core$Intrinsic$bytes_to_string(l1);
	{ vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_mangle$mangle_module_part(vader_string_t l0) {
	int64_t l1;
	vader_box_t l2;
	vader_string_t t0;
	l2 = std_string$index_of(l0, 36u, INT64_C(0));
	if (l2.tag == 0u) {
		return 0u;
	}
	l1 = ((int64_t) l2.payload.i);
	t0 = vader_host_std_core$Intrinsic$byte_slice(l0, INT64_C(0), l1);
	return t0;
}

vader_string_t vader_core_mangle$ranked_generated_name(vader_string_t l0, uint8_t l1, int64_t l2) {
	vader_string_t l3 = 0;
	vader_string_t l4 = 0;
	int64_t l5;
	void* l6 = NULL;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l6 };
	vader_string_t* gc_atom_roots[4] = { &l0, &l3, &l4, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = vader_core_mangle$generated_name(l0, l1);
	if (!(l2 == INT64_C(1))) {
		l4 = l3;
		l5 = vader_host_std_core$Intrinsic$byte_len(l4);
		l6 = (void*) vader_buffer_new((size_t) (INT64_C(20) + l5));
		l5 = INT64_C(0);
		l5 = std_core$write_string_at(l6, l5, l4);
		l5 = std_core$write_int(l6, l5, l2);
		t0 = std_core$finish_buffer(l6, l5);
		{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ vader_string_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_mangle$shape_segment_name(uint8_t l0) {
	vader_string_t l1;
	if (l0 == INT32_C(0)) {
		l1 = 336u;
		return l1;
	}
	if (l0 == INT32_C(1)) {
		l1 = 349u;
	} else if (l0 == INT32_C(2)) {
		l1 = 341u;
	} else {
		if (!(l0 == INT32_C(3))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = 350u;
	}
	return l1;
}

vader_string_t vader_core_mangle$trait_member_mangle(vader_string_t l0, vader_string_t l1, vader_string_t l2) {
	vader_string_t t0 = 0;
	vader_string_t t1 = 0;
	vader_string_t* gc_atom_roots[5] = { &l0, &l1, &l2, &t0, &t1 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 5u, gc_atom_roots };
	vader_gc_top = &gc_frame;
	t0 = vader_core_mangle$mangle_module_id(l0);
	t1 = concat_5(t0, 331u, l1, 331u, l2);
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_mangle$tuple_struct_name(vader_string_t l0) {
	vader_string_t t0;
	t0 = concat_2(1255u, l0);
	return t0;
}

vader_string_t vader_core_mangle$uniq(void* l0, vader_string_t l1) {
	int64_t l2, l4, l6;
	vader_string_t l3 = 0;
	vader_string_t l7 = 0;
	void* l5 = NULL;
	bool t0;
	vader_string_t t1 = 0;
	void** gc_raw_roots[2] = { &l0, &l5 };
	vader_string_t* gc_atom_roots[4] = { &l1, &l3, &l7, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = std_collections$add__string(l0, l1);
	if (t0) {
		{ vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
	}
	l2 = INT64_C(1);
	for (;;) {
		l3 = l1;
		l4 = vader_host_std_core$Intrinsic$byte_len(l3);
		l5 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l4));
		l6 = INT64_C(0);
		l6 = std_core$write_string_at(l5, l6, l3);
		l6 = std_core$write_string_at(l5, l6, 1240u);
		l6 = std_core$write_int(l5, l6, l2);
		l7 = std_core$finish_buffer(l5, l6);
		t0 = std_collections$add__string(l0, l7);
		if (!(t0)) {
			l2 = vader_chk_add(i64, l2, INT64_C(1));
			continue;
		}
		break;
	}
	l3 = l1;
	l4 = vader_host_std_core$Intrinsic$byte_len(l3);
	l5 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l4));
	l4 = INT64_C(0);
	l4 = std_core$write_string_at(l5, l4, l3);
	l4 = std_core$write_string_at(l5, l4, 1240u);
	l4 = std_core$write_int(l5, l4, l2);
	t1 = std_core$finish_buffer(l5, l4);
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_mangle$vtable_dispatcher_mangle(vader_string_t l0) {
	void* t0 = NULL;
	vader_string_t t1 = 0;
	vader_string_t t2 = 0;
	void** gc_raw_roots[1] = { &t0 };
	vader_string_t* gc_atom_roots[3] = { &l0, &t1, &t2 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	t0 = std_string$split(l0, 489u);
	t1 = std_string$join(t0, 331u);
	t2 = vader_core_mangle$derived_mangle(t1, (uint8_t) 7);
	{ vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_core_mangle$vtable_key(vader_string_t l0, vader_string_t l1) {
	vader_string_t t0;
	t0 = concat_3(l0, 489u, l1);
	return t0;
}

static vader_box_t vader_core_mangle$wit_name_escape(uint8_t l0) {
	vader_box_t l1;
	if (l0 == INT32_C(58)) {
		l1 = vader_box_i32(635u, INT32_C(48));
		return l1;
	}
	if (l0 == INT32_C(64)) {
		l1 = vader_box_i32(635u, INT32_C(49));
	} else if (l0 == INT32_C(46)) {
		l1 = vader_box_i32(635u, INT32_C(50));
	} else if (l0 == INT32_C(45)) {
		l1 = vader_box_i32(635u, INT32_C(51));
	} else {
		l1 = vader_box_obj(0u, NULL);
	}
	return l1;
}
