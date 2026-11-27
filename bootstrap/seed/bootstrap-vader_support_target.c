#include "bootstrap.split.h"

static bool vader_support_target$Target$std_core$Equals$equals(void* l0, void* l1);
static vader_string_t vader_support_target$arch_variant(uint8_t l0);
static vader_string_t vader_support_target$build_variant(uint8_t l0);
static vader_string_t vader_support_target$os_variant(uint8_t l0);

vader_string_t vader_support_target$Target$std_core$Display$to_string(void* l0) {
	vader_string_t l1 = 0;
	vader_string_t l2 = 0;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l0 };
	vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l1 = std_target$Os$std_core$Display$to_string(((vader_struct_vader_support_target$Target_t*) l0)->f_os);
	l2 = std_target$Arch$std_core$Display$to_string(((vader_struct_vader_support_target$Target_t*) l0)->f_arch);
	t0 = concat_3(l1, 478u, l2);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_support_target$Target$std_core$Equals$equals(void* l0, void* l1) {
	uint8_t l2, l3;
	l2 = ((vader_struct_vader_support_target$Target_t*) l0)->f_os;
	l3 = ((vader_struct_vader_support_target$Target_t*) l1)->f_os;
	if (l2 == l3) {
		l2 = ((vader_struct_vader_support_target$Target_t*) l0)->f_arch;
		l3 = ((vader_struct_vader_support_target$Target_t*) l1)->f_arch;
		return l2 == l3;
	}
	return false;
}

bool vader_support_target$Target$std_core$Equals$equals$guard(void* l0, vader_box_t l1) {
	void* l2;
	bool t0;
	if (l1.tag == 2152u) {
		l2 = l1.payload.obj;
		t0 = vader_support_target$Target$std_core$Equals$equals(l0, l2);
		return t0;
	}
	return false;
}

static vader_string_t vader_support_target$arch_variant(uint8_t l0) {
	vader_string_t l1;
	if (l0 == INT32_C(0)) {
		l1 = 1227u;
		return l1;
	}
	if (l0 == INT32_C(1)) {
		l1 = 678u;
	} else {
		if (!(l0 == INT32_C(2))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = 1220u;
	}
	return l1;
}

vader_string_t vader_support_target$baked_module_source(void* l0, uint8_t l1) {
	vader_string_t l2 = 0;
	vader_string_t l3 = 0;
	vader_string_t l4 = 0;
	void* t0 = NULL;
	vader_string_t t1 = 0;
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l4, &t1 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = vader_support_target$os_variant(((vader_struct_vader_support_target$Target_t*) l0)->f_os);
	l2 = concat_2(2483u, l2);
	l3 = vader_support_target$arch_variant(((vader_struct_vader_support_target$Target_t*) l0)->f_arch);
	l3 = concat_2(2481u, l3);
	l4 = vader_support_target$build_variant(l1);
	l4 = concat_2(2482u, l4);
	vader_array_t* _a0_arr = vader_array_new(28u, 17u, 0u, 642u);
	vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 16u] = vader_box_string(642u, 0u);
	vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 15u] = vader_box_string(642u, l4);
	vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 14u] = vader_box_string(642u, 546u);
	vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 13u] = vader_box_string(642u, 0u);
	vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 12u] = vader_box_string(642u, l3);
	vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 11u] = vader_box_string(642u, 547u);
	vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 10u] = vader_box_string(642u, 0u);
	vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 9u] = vader_box_string(642u, l2);
	vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 8u] = vader_box_string(642u, 548u);
	vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 7u] = vader_box_string(642u, 0u);
	vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 6u] = vader_box_string(642u, 2717u);
	vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 5u] = vader_box_string(642u, 0u);
	vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 4u] = vader_box_string(642u, 2944u);
	vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 3u] = vader_box_string(642u, 0u);
	vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 2u] = vader_box_string(642u, 544u);
	vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 1u] = vader_box_string(642u, 542u);
	vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(642u, 540u);
	t0 = (void*) _a0_arr;
	t1 = std_string$join(t0, 2u);
	{ vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

uint8_t vader_support_target$build_for(bool l0) {
	if (l0) {
		return (uint8_t) 1;
	}
	return (uint8_t) 0;
}

static vader_string_t vader_support_target$build_variant(uint8_t l0) {
	if (l0 == INT32_C(0)) {
		return 739u;
	}
	if (!(l0 == INT32_C(1))) {
		vader_unreachable("non-exhaustive match (T3013 should have caught this)");
	}
	return 992u;
}

void* vader_support_target$host_target(void) {
	uint8_t l0, l1;
	void* t0 = NULL;
	void** gc_raw_roots[1] = { &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	l0 = vader_host_std_core$Runtime$current_os();
	l1 = vader_host_std_core$Runtime$current_arch();
	vader_struct_vader_support_target$Target_t* _a0_obj = (vader_struct_vader_support_target$Target_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_target$Target_t));
	vader_obj_header_init(_a0_obj, 2152u);
	_a0_obj->f_os = l0;
	_a0_obj->f_arch = l1;
	t0 = (void*) _a0_obj;
	{ void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_support_target$os_variant(uint8_t l0) {
	vader_string_t l1;
	if (l0 == INT32_C(0)) {
		l1 = 1225u;
		return l1;
	}
	if (l0 == INT32_C(1)) {
		l1 = 877u;
	} else if (l0 == INT32_C(2)) {
		l1 = 738u;
	} else if (l0 == INT32_C(3)) {
		l1 = 1219u;
	} else {
		if (!(l0 == INT32_C(4))) {
			vader_unreachable("non-exhaustive match (T3013 should have caught this)");
		}
		l1 = 695u;
	}
	return l1;
}

vader_box_t vader_support_target$parse_os(vader_string_t l0) {
	vader_box_t l1;
	if (l0 == 3776u) {
		l1 = vader_box_i32(647u, INT32_C(0));
		return l1;
	}
	if (l0 == 2849u) {
		l1 = vader_box_i32(647u, INT32_C(1));
	} else if (l0 == 2329u) {
		l1 = vader_box_i32(647u, INT32_C(2));
	} else if (l0 == 3748u) {
		l1 = vader_box_i32(647u, INT32_C(3));
	} else if (l0 == 2126u) {
		l1 = vader_box_i32(647u, INT32_C(4));
	} else {
		l1 = vader_box_obj(0u, NULL);
	}
	return l1;
}
