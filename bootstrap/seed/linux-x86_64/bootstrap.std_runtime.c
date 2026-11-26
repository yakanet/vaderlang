#include "bootstrap.split.h"

int64_t std_runtime$allocated_bytes(void) {
	int64_t t0;
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_host_std_core$Intrinsic$collector_statistic(INT32_C(3));
	{ int64_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t std_runtime$allocations(void) {
	int64_t t0;
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_host_std_core$Intrinsic$collector_statistic(INT32_C(4));
	{ int64_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t std_runtime$bytes_copied(void) {
	int64_t t0;
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_host_std_core$Intrinsic$collector_statistic(INT32_C(2));
	{ int64_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t std_runtime$collections(void) {
	int64_t t0;
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_host_std_core$Intrinsic$collector_statistic(INT32_C(0));
	{ int64_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t std_runtime$peak_resident_bytes(void) {
	void* l0 = NULL;
	void* t0 = NULL;
	int32_t t1;
	int64_t t2, t3;
	void** gc_raw_roots[2] = { &l0, &t0 };
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
	vader_gc_top = &gc_frame;
	vader_array_t* _a0_arr = vader_array_new(30u, 1u, 8u, 640u);
	((int64_t*) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = (int64_t) INT64_C(0);
	t0 = (void*) _a0_arr;
	vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) INT64_C(18));
	l0 = (void*) _a1_arr;
	t1 = vader_host_system_posix$sys_getrusage(INT32_C(0), l0);
	if (!(t1 != INT32_C(0))) {
		vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
		VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
		VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT64_C(4))
		t2 = ((int64_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) INT64_C(4)];
		t3 = vader_chk_mul(i64, t2, INT64_C(1024));
		{ vader_box_t __vret = vader_box_i64(640u, t3); vader_gc_top = gc_frame.prev; return __vret; }
	}
	{ vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}
