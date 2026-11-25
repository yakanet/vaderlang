#include "bootstrap.split.h"

vader_string_t concat_10(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6, vader_string_t l7, vader_string_t l8, vader_string_t l9) {
	int64_t l10, l11, l12, l13, l14, l15, l16, l17, l18, l19;
	void* l20 = NULL;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l20 };
	vader_string_t* gc_atom_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 11u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l10 = vader_host_std_core$Intrinsic$byte_len(l0);
	l11 = vader_host_std_core$Intrinsic$byte_len(l1);
	l11 = (l10 + l11);
	l12 = vader_host_std_core$Intrinsic$byte_len(l2);
	l12 = (l11 + l12);
	l13 = vader_host_std_core$Intrinsic$byte_len(l3);
	l13 = (l12 + l13);
	l14 = vader_host_std_core$Intrinsic$byte_len(l4);
	l14 = (l13 + l14);
	l15 = vader_host_std_core$Intrinsic$byte_len(l5);
	l15 = (l14 + l15);
	l16 = vader_host_std_core$Intrinsic$byte_len(l6);
	l16 = (l15 + l16);
	l17 = vader_host_std_core$Intrinsic$byte_len(l7);
	l17 = (l16 + l17);
	l18 = vader_host_std_core$Intrinsic$byte_len(l8);
	l18 = (l17 + l18);
	l19 = vader_host_std_core$Intrinsic$byte_len(l9);
	l19 = (l18 + l19);
	l20 = (void*) vader_buffer_new((size_t) l19);
	vader_buffer_write_string((vader_buffer_t*) l20, (size_t) INT64_C(0), l0);
	vader_buffer_write_string((vader_buffer_t*) l20, (size_t) l10, l1);
	vader_buffer_write_string((vader_buffer_t*) l20, (size_t) l11, l2);
	vader_buffer_write_string((vader_buffer_t*) l20, (size_t) l12, l3);
	vader_buffer_write_string((vader_buffer_t*) l20, (size_t) l13, l4);
	vader_buffer_write_string((vader_buffer_t*) l20, (size_t) l14, l5);
	vader_buffer_write_string((vader_buffer_t*) l20, (size_t) l15, l6);
	vader_buffer_write_string((vader_buffer_t*) l20, (size_t) l16, l7);
	vader_buffer_write_string((vader_buffer_t*) l20, (size_t) l17, l8);
	vader_buffer_write_string((vader_buffer_t*) l20, (size_t) l18, l9);
	t0 = vader_buffer_intern_string((vader_buffer_t*) l20, (size_t) l19);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_11(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6, vader_string_t l7, vader_string_t l8, vader_string_t l9, vader_string_t l10) {
	int64_t l11, l12, l13, l14, l15, l16, l17, l18, l19, l20, l21;
	void* l22 = NULL;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l22 };
	vader_string_t* gc_atom_roots[12] = {
		&l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &t0,
	};
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 12u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l11 = vader_host_std_core$Intrinsic$byte_len(l0);
	l12 = vader_host_std_core$Intrinsic$byte_len(l1);
	l12 = (l11 + l12);
	l13 = vader_host_std_core$Intrinsic$byte_len(l2);
	l13 = (l12 + l13);
	l14 = vader_host_std_core$Intrinsic$byte_len(l3);
	l14 = (l13 + l14);
	l15 = vader_host_std_core$Intrinsic$byte_len(l4);
	l15 = (l14 + l15);
	l16 = vader_host_std_core$Intrinsic$byte_len(l5);
	l16 = (l15 + l16);
	l17 = vader_host_std_core$Intrinsic$byte_len(l6);
	l17 = (l16 + l17);
	l18 = vader_host_std_core$Intrinsic$byte_len(l7);
	l18 = (l17 + l18);
	l19 = vader_host_std_core$Intrinsic$byte_len(l8);
	l19 = (l18 + l19);
	l20 = vader_host_std_core$Intrinsic$byte_len(l9);
	l20 = (l19 + l20);
	l21 = vader_host_std_core$Intrinsic$byte_len(l10);
	l21 = (l20 + l21);
	l22 = (void*) vader_buffer_new((size_t) l21);
	vader_buffer_write_string((vader_buffer_t*) l22, (size_t) INT64_C(0), l0);
	vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l11, l1);
	vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l12, l2);
	vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l13, l3);
	vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l14, l4);
	vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l15, l5);
	vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l16, l6);
	vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l17, l7);
	vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l18, l8);
	vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l19, l9);
	vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l20, l10);
	t0 = vader_buffer_intern_string((vader_buffer_t*) l22, (size_t) l21);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_12(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6, vader_string_t l7, vader_string_t l8, vader_string_t l9, vader_string_t l10, vader_string_t l11) {
	int64_t l12, l13, l14, l15, l16, l17, l18, l19, l20, l21, l22, l23;
	void* l24 = NULL;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l24 };
	vader_string_t* gc_atom_roots[13] = {
		&l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l11, &t0,
	};
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 13u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l12 = vader_host_std_core$Intrinsic$byte_len(l0);
	l13 = vader_host_std_core$Intrinsic$byte_len(l1);
	l13 = (l12 + l13);
	l14 = vader_host_std_core$Intrinsic$byte_len(l2);
	l14 = (l13 + l14);
	l15 = vader_host_std_core$Intrinsic$byte_len(l3);
	l15 = (l14 + l15);
	l16 = vader_host_std_core$Intrinsic$byte_len(l4);
	l16 = (l15 + l16);
	l17 = vader_host_std_core$Intrinsic$byte_len(l5);
	l17 = (l16 + l17);
	l18 = vader_host_std_core$Intrinsic$byte_len(l6);
	l18 = (l17 + l18);
	l19 = vader_host_std_core$Intrinsic$byte_len(l7);
	l19 = (l18 + l19);
	l20 = vader_host_std_core$Intrinsic$byte_len(l8);
	l20 = (l19 + l20);
	l21 = vader_host_std_core$Intrinsic$byte_len(l9);
	l21 = (l20 + l21);
	l22 = vader_host_std_core$Intrinsic$byte_len(l10);
	l22 = (l21 + l22);
	l23 = vader_host_std_core$Intrinsic$byte_len(l11);
	l23 = (l22 + l23);
	l24 = (void*) vader_buffer_new((size_t) l23);
	vader_buffer_write_string((vader_buffer_t*) l24, (size_t) INT64_C(0), l0);
	vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l12, l1);
	vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l13, l2);
	vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l14, l3);
	vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l15, l4);
	vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l16, l5);
	vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l17, l6);
	vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l18, l7);
	vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l19, l8);
	vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l20, l9);
	vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l21, l10);
	vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l22, l11);
	t0 = vader_buffer_intern_string((vader_buffer_t*) l24, (size_t) l23);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_2(vader_string_t l0, vader_string_t l1) {
	int64_t l2, l3;
	void* l4 = NULL;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l4 };
	vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l2 = vader_host_std_core$Intrinsic$byte_len(l0);
	l3 = vader_host_std_core$Intrinsic$byte_len(l1);
	l3 = (l2 + l3);
	l4 = (void*) vader_buffer_new((size_t) l3);
	vader_buffer_write_string((vader_buffer_t*) l4, (size_t) INT64_C(0), l0);
	vader_buffer_write_string((vader_buffer_t*) l4, (size_t) l2, l1);
	t0 = vader_buffer_intern_string((vader_buffer_t*) l4, (size_t) l3);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_3(vader_string_t l0, vader_string_t l1, vader_string_t l2) {
	int64_t l3, l4, l5;
	void* l6 = NULL;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l6 };
	vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l3 = vader_host_std_core$Intrinsic$byte_len(l0);
	l4 = vader_host_std_core$Intrinsic$byte_len(l1);
	l4 = (l3 + l4);
	l5 = vader_host_std_core$Intrinsic$byte_len(l2);
	l5 = (l4 + l5);
	l6 = (void*) vader_buffer_new((size_t) l5);
	vader_buffer_write_string((vader_buffer_t*) l6, (size_t) INT64_C(0), l0);
	vader_buffer_write_string((vader_buffer_t*) l6, (size_t) l3, l1);
	vader_buffer_write_string((vader_buffer_t*) l6, (size_t) l4, l2);
	t0 = vader_buffer_intern_string((vader_buffer_t*) l6, (size_t) l5);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_4(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3) {
	int64_t l4, l5, l6, l7;
	void* l8 = NULL;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l8 };
	vader_string_t* gc_atom_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l4 = vader_host_std_core$Intrinsic$byte_len(l0);
	l5 = vader_host_std_core$Intrinsic$byte_len(l1);
	l5 = (l4 + l5);
	l6 = vader_host_std_core$Intrinsic$byte_len(l2);
	l6 = (l5 + l6);
	l7 = vader_host_std_core$Intrinsic$byte_len(l3);
	l7 = (l6 + l7);
	l8 = (void*) vader_buffer_new((size_t) l7);
	vader_buffer_write_string((vader_buffer_t*) l8, (size_t) INT64_C(0), l0);
	vader_buffer_write_string((vader_buffer_t*) l8, (size_t) l4, l1);
	vader_buffer_write_string((vader_buffer_t*) l8, (size_t) l5, l2);
	vader_buffer_write_string((vader_buffer_t*) l8, (size_t) l6, l3);
	t0 = vader_buffer_intern_string((vader_buffer_t*) l8, (size_t) l7);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_5(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4) {
	int64_t l5, l6, l7, l8, l9;
	void* l10 = NULL;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l10 };
	vader_string_t* gc_atom_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l5 = vader_host_std_core$Intrinsic$byte_len(l0);
	l6 = vader_host_std_core$Intrinsic$byte_len(l1);
	l6 = (l5 + l6);
	l7 = vader_host_std_core$Intrinsic$byte_len(l2);
	l7 = (l6 + l7);
	l8 = vader_host_std_core$Intrinsic$byte_len(l3);
	l8 = (l7 + l8);
	l9 = vader_host_std_core$Intrinsic$byte_len(l4);
	l9 = (l8 + l9);
	l10 = (void*) vader_buffer_new((size_t) l9);
	vader_buffer_write_string((vader_buffer_t*) l10, (size_t) INT64_C(0), l0);
	vader_buffer_write_string((vader_buffer_t*) l10, (size_t) l5, l1);
	vader_buffer_write_string((vader_buffer_t*) l10, (size_t) l6, l2);
	vader_buffer_write_string((vader_buffer_t*) l10, (size_t) l7, l3);
	vader_buffer_write_string((vader_buffer_t*) l10, (size_t) l8, l4);
	t0 = vader_buffer_intern_string((vader_buffer_t*) l10, (size_t) l9);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_6(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5) {
	int64_t l6, l7, l8, l9, l10, l11;
	void* l12 = NULL;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l12 };
	vader_string_t* gc_atom_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 7u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l6 = vader_host_std_core$Intrinsic$byte_len(l0);
	l7 = vader_host_std_core$Intrinsic$byte_len(l1);
	l7 = (l6 + l7);
	l8 = vader_host_std_core$Intrinsic$byte_len(l2);
	l8 = (l7 + l8);
	l9 = vader_host_std_core$Intrinsic$byte_len(l3);
	l9 = (l8 + l9);
	l10 = vader_host_std_core$Intrinsic$byte_len(l4);
	l10 = (l9 + l10);
	l11 = vader_host_std_core$Intrinsic$byte_len(l5);
	l11 = (l10 + l11);
	l12 = (void*) vader_buffer_new((size_t) l11);
	vader_buffer_write_string((vader_buffer_t*) l12, (size_t) INT64_C(0), l0);
	vader_buffer_write_string((vader_buffer_t*) l12, (size_t) l6, l1);
	vader_buffer_write_string((vader_buffer_t*) l12, (size_t) l7, l2);
	vader_buffer_write_string((vader_buffer_t*) l12, (size_t) l8, l3);
	vader_buffer_write_string((vader_buffer_t*) l12, (size_t) l9, l4);
	vader_buffer_write_string((vader_buffer_t*) l12, (size_t) l10, l5);
	t0 = vader_buffer_intern_string((vader_buffer_t*) l12, (size_t) l11);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_7(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6) {
	int64_t l7, l8, l9, l10, l11, l12, l13;
	void* l14 = NULL;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l14 };
	vader_string_t* gc_atom_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l7 = vader_host_std_core$Intrinsic$byte_len(l0);
	l8 = vader_host_std_core$Intrinsic$byte_len(l1);
	l8 = (l7 + l8);
	l9 = vader_host_std_core$Intrinsic$byte_len(l2);
	l9 = (l8 + l9);
	l10 = vader_host_std_core$Intrinsic$byte_len(l3);
	l10 = (l9 + l10);
	l11 = vader_host_std_core$Intrinsic$byte_len(l4);
	l11 = (l10 + l11);
	l12 = vader_host_std_core$Intrinsic$byte_len(l5);
	l12 = (l11 + l12);
	l13 = vader_host_std_core$Intrinsic$byte_len(l6);
	l13 = (l12 + l13);
	l14 = (void*) vader_buffer_new((size_t) l13);
	vader_buffer_write_string((vader_buffer_t*) l14, (size_t) INT64_C(0), l0);
	vader_buffer_write_string((vader_buffer_t*) l14, (size_t) l7, l1);
	vader_buffer_write_string((vader_buffer_t*) l14, (size_t) l8, l2);
	vader_buffer_write_string((vader_buffer_t*) l14, (size_t) l9, l3);
	vader_buffer_write_string((vader_buffer_t*) l14, (size_t) l10, l4);
	vader_buffer_write_string((vader_buffer_t*) l14, (size_t) l11, l5);
	vader_buffer_write_string((vader_buffer_t*) l14, (size_t) l12, l6);
	t0 = vader_buffer_intern_string((vader_buffer_t*) l14, (size_t) l13);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_8(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6, vader_string_t l7) {
	int64_t l8, l9, l10, l11, l12, l13, l14, l15;
	void* l16 = NULL;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l16 };
	vader_string_t* gc_atom_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 9u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l8 = vader_host_std_core$Intrinsic$byte_len(l0);
	l9 = vader_host_std_core$Intrinsic$byte_len(l1);
	l9 = (l8 + l9);
	l10 = vader_host_std_core$Intrinsic$byte_len(l2);
	l10 = (l9 + l10);
	l11 = vader_host_std_core$Intrinsic$byte_len(l3);
	l11 = (l10 + l11);
	l12 = vader_host_std_core$Intrinsic$byte_len(l4);
	l12 = (l11 + l12);
	l13 = vader_host_std_core$Intrinsic$byte_len(l5);
	l13 = (l12 + l13);
	l14 = vader_host_std_core$Intrinsic$byte_len(l6);
	l14 = (l13 + l14);
	l15 = vader_host_std_core$Intrinsic$byte_len(l7);
	l15 = (l14 + l15);
	l16 = (void*) vader_buffer_new((size_t) l15);
	vader_buffer_write_string((vader_buffer_t*) l16, (size_t) INT64_C(0), l0);
	vader_buffer_write_string((vader_buffer_t*) l16, (size_t) l8, l1);
	vader_buffer_write_string((vader_buffer_t*) l16, (size_t) l9, l2);
	vader_buffer_write_string((vader_buffer_t*) l16, (size_t) l10, l3);
	vader_buffer_write_string((vader_buffer_t*) l16, (size_t) l11, l4);
	vader_buffer_write_string((vader_buffer_t*) l16, (size_t) l12, l5);
	vader_buffer_write_string((vader_buffer_t*) l16, (size_t) l13, l6);
	vader_buffer_write_string((vader_buffer_t*) l16, (size_t) l14, l7);
	t0 = vader_buffer_intern_string((vader_buffer_t*) l16, (size_t) l15);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_9(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6, vader_string_t l7, vader_string_t l8) {
	int64_t l9, l10, l11, l12, l13, l14, l15, l16, l17;
	void* l18 = NULL;
	vader_string_t t0 = 0;
	void** gc_raw_roots[1] = { &l18 };
	vader_string_t* gc_atom_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &t0 };
	vader_gc_frame_t gc_frame = {
		vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 10u, gc_atom_roots,
	};
	vader_gc_top = &gc_frame;
	l9 = vader_host_std_core$Intrinsic$byte_len(l0);
	l10 = vader_host_std_core$Intrinsic$byte_len(l1);
	l10 = (l9 + l10);
	l11 = vader_host_std_core$Intrinsic$byte_len(l2);
	l11 = (l10 + l11);
	l12 = vader_host_std_core$Intrinsic$byte_len(l3);
	l12 = (l11 + l12);
	l13 = vader_host_std_core$Intrinsic$byte_len(l4);
	l13 = (l12 + l13);
	l14 = vader_host_std_core$Intrinsic$byte_len(l5);
	l14 = (l13 + l14);
	l15 = vader_host_std_core$Intrinsic$byte_len(l6);
	l15 = (l14 + l15);
	l16 = vader_host_std_core$Intrinsic$byte_len(l7);
	l16 = (l15 + l16);
	l17 = vader_host_std_core$Intrinsic$byte_len(l8);
	l17 = (l16 + l17);
	l18 = (void*) vader_buffer_new((size_t) l17);
	vader_buffer_write_string((vader_buffer_t*) l18, (size_t) INT64_C(0), l0);
	vader_buffer_write_string((vader_buffer_t*) l18, (size_t) l9, l1);
	vader_buffer_write_string((vader_buffer_t*) l18, (size_t) l10, l2);
	vader_buffer_write_string((vader_buffer_t*) l18, (size_t) l11, l3);
	vader_buffer_write_string((vader_buffer_t*) l18, (size_t) l12, l4);
	vader_buffer_write_string((vader_buffer_t*) l18, (size_t) l13, l5);
	vader_buffer_write_string((vader_buffer_t*) l18, (size_t) l14, l6);
	vader_buffer_write_string((vader_buffer_t*) l18, (size_t) l15, l7);
	vader_buffer_write_string((vader_buffer_t*) l18, (size_t) l16, l8);
	t0 = vader_buffer_intern_string((vader_buffer_t*) l18, (size_t) l17);
	{ vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
