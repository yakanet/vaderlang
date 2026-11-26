#include "bootstrap.split.h"

int64_t std_runtime$allocated_bytes(void) {
	int64_t t0;
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_host_std_core$Runtime$collector_statistic(INT32_C(3));
	{ int64_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t std_runtime$allocations(void) {
	int64_t t0;
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_host_std_core$Runtime$collector_statistic(INT32_C(4));
	{ int64_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t std_runtime$bytes_copied(void) {
	int64_t t0;
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_host_std_core$Runtime$collector_statistic(INT32_C(2));
	{ int64_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t std_runtime$collections(void) {
	int64_t t0;
	vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
	vader_gc_top = &gc_frame;
	t0 = vader_host_std_core$Runtime$collector_statistic(INT32_C(0));
	{ int64_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t std_runtime$peak_resident_bytes(void) {
	return vader_box_obj(0u, NULL);
}
