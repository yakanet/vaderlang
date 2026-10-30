#include "bootstrap.split.h"

static void* vader_support_diagnostics$dedup_diagnostics(void* l0);
static vader_string_t vader_support_diagnostics$diag_key(void* l0);
static void vader_support_diagnostics$format_diagnostic(void* l0, void* l1, bool l2, vader_string_t l3);
static void* vader_support_diagnostics$new_diagnostic(uint8_t l0, void* l1, void* l2, vader_string_t l3);
static vader_string_t vader_support_diagnostics$relative_to(vader_string_t l0, vader_string_t l1);
static vader_string_t vader_support_diagnostics$render_diagnostics(void* l0, bool l1, bool l2);

bool vader_support_diagnostics$any_error_diag(void* l0) {
    void* l1;
    int64_t l2, l3;
    void* t0;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (((vader_struct_vader_support_diagnostics$Diagnostic_t*) t0)->f_severity == INT32_C(0)) {
            return true;
        }
        l3 = (l3 + INT64_C(1));
    }
    return false;
}

void* vader_support_diagnostics$comptime_error(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    int64_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = (void*) &vader_data_7;
    l4 = ((int64_t) (uint8_t) l0);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    t0 = vader_support_diagnostics$new_diagnostic((uint8_t) 0, l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_support_diagnostics$dedup_diagnostics(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 333u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 547u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__string_t* _a4_obj = (vader_struct_std_collections$MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__string_t));
    vader_obj_header_init(_a4_obj, 615u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(216u, 0u, 13u, 1410u);
    l2 = (void*) _a5_arr;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
        l7 = vader_support_diagnostics$diag_key(l6);
        t1 = std_collections$add__string(l1, l7);
        if (t1) {
            vader_array_push_ref((vader_array_t*) l2, l6);
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_support_diagnostics$diag_key(void* l0) {
    int32_t l1;
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_string_t l6 = 0;
    int64_t l4, l5, l7, l8;
    void* l9 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[2] = { &l0, &l9 };
    vader_string_t* gc_atom_roots[4] = { &l2, &l3, &l6, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((int32_t) (uint8_t) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l0)->f_severity);
    l2 = ((vader_struct_vader_support_diagnostics$CodeInfo_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l0)->f_code)->f_id;
    l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l0)->f_primary)->f_start)->f_file;
    l4 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l0)->f_primary)->f_start)->f_offset;
    l5 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l0)->f_primary)->f_end)->f_offset;
    l6 = ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l0)->f_detail;
    l7 = vader_host_std_core$byte_len(l2);
    l8 = vader_host_std_core$byte_len(l3);
    l7 = (l7 + l8);
    l8 = vader_host_std_core$byte_len(l6);
    l7 = (l7 + l8);
    l9 = (void*) vader_buffer_new((size_t) (INT64_C(65) + l7));
    l7 = INT64_C(0);
    l8 = ((int64_t) (int32_t) l1);
    l7 = std_core$write_int(l9, l7, l8);
    l7 = std_core$write_string_at(l9, l7, 3057u);
    l7 = std_core$write_string_at(l9, l7, l2);
    l7 = std_core$write_string_at(l9, l7, 3057u);
    l7 = std_core$write_string_at(l9, l7, l3);
    l7 = std_core$write_string_at(l9, l7, 3057u);
    l7 = std_core$write_int(l9, l7, l4);
    l7 = std_core$write_string_at(l9, l7, 3057u);
    l7 = std_core$write_int(l9, l7, l5);
    l7 = std_core$write_string_at(l9, l7, 3057u);
    l7 = std_core$write_string_at(l9, l7, l6);
    t0 = std_core$finish_buffer(l9, l7);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_support_diagnostics$diag_less(void* l0, void* l1) {
    int64_t l2, l3;
    vader_string_t l4, l5;
    bool t0;
    l2 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l0)->f_primary)->f_start)->f_offset;
    l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l1)->f_primary)->f_start)->f_offset;
    if ((l2 < l3)) {
        return true;
    }
    l2 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l0)->f_primary)->f_start)->f_offset;
    l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l1)->f_primary)->f_start)->f_offset;
    if (!((l2 > l3))) {
        l4 = ((vader_struct_vader_support_diagnostics$CodeInfo_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l0)->f_code)->f_id;
        l5 = ((vader_struct_vader_support_diagnostics$CodeInfo_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l1)->f_code)->f_id;
        t0 = std_string$compare_ascending(l4, l5);
        return t0;
    }
    return false;
}

bool vader_support_diagnostics$diag_less_with_file(void* l0, void* l1) {
    vader_string_t l2, l3;
    bool t0;
    l2 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l0)->f_primary)->f_start)->f_file;
    l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l1)->f_primary)->f_start)->f_file;
    if (!(l2 != l3)) {
        t0 = vader_support_diagnostics$diag_less(l0, l1);
        return t0;
    }
    t0 = std_string$compare_ascending(l2, l3);
    return t0;
}

vader_string_t vader_support_diagnostics$dump_diagnostics_with_file(void* l0) {
    vader_string_t t0;
    t0 = vader_support_diagnostics$render_diagnostics(l0, true, true);
    return t0;
}

static void vader_support_diagnostics$format_diagnostic(void* l0, void* l1, bool l2, vader_string_t l3) {
    vader_string_t l4 = 0;
    vader_string_t l6 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l14 = 0;
    uint8_t l5;
    bool l7;
    void* l8 = NULL;
    void* l12 = NULL;
    int64_t l11, l13;
    vader_string_t t0 = 0;
    bool t1;
    int32_t t2;
    void** gc_raw_roots[4] = { &l0, &l1, &l8, &l12 };
    vader_string_t* gc_atom_roots[7] = { &l3, &l4, &l6, &l9, &l10, &l14, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 7u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l1)->f_severity;
    if (l5 == INT32_C(0)) {
        l4 = 1902u;
    } else if (l5 == INT32_C(1)) {
        l4 = 3013u;
    } else if (l5 == INT32_C(2)) {
        l4 = 2158u;
    } else {
        if (!(l5 == INT32_C(3))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l4 = 2071u;
    }
    if (l2) {
        l5 = ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l1)->f_severity;
        if (l5 == INT32_C(0)) {
            l6 = std_tty$red(l4);
        } else if (l5 == INT32_C(1)) {
            l6 = std_tty$yellow(l4);
        } else {
            if (l5 == INT32_C(2)) {
                l7 = true;
            } else {
                l7 = l5 == INT32_C(3);
            }
            if (!(l7)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l6 = l4;
        }
    } else {
        l6 = l4;
    }
    l8 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l1)->f_primary)->f_start;
    l4 = 0u;
    t0 = ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l1)->f_detail;
    t1 = std_string$is_empty(t0);
    if (!(t1)) {
        l9 = ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l1)->f_detail;
        l4 = concat_2(462u, l9);
    }
    if (l2) {
        t0 = ((vader_struct_toolchain_span$Position_t*) l8)->f_file;
        l10 = vader_support_diagnostics$relative_to(t0, l3);
        l11 = vader_host_std_core$byte_len(l10);
        l12 = (void*) vader_buffer_new((size_t) (INT64_C(42) + l11));
        l11 = INT64_C(0);
        l11 = std_core$write_string_at(l12, l11, l10);
        l11 = std_core$write_string_at(l12, l11, 461u);
        t2 = ((vader_struct_toolchain_span$Position_t*) l8)->f_line;
        l13 = ((int64_t) (int32_t) t2);
        l11 = std_core$write_int(l12, l11, l13);
        l11 = std_core$write_string_at(l12, l11, 461u);
        t2 = ((vader_struct_toolchain_span$Position_t*) l8)->f_column;
        l13 = ((int64_t) (int32_t) t2);
        l11 = std_core$write_int(l12, l11, l13);
        l9 = std_core$finish_buffer(l12, l11);
    } else {
        l12 = (void*) vader_buffer_new((size_t) INT64_C(41));
        l11 = INT64_C(0);
        t2 = ((vader_struct_toolchain_span$Position_t*) l8)->f_line;
        l13 = ((int64_t) (int32_t) t2);
        l11 = std_core$write_int(l12, l11, l13);
        l11 = std_core$write_string_at(l12, l11, 461u);
        t2 = ((vader_struct_toolchain_span$Position_t*) l8)->f_column;
        l13 = ((int64_t) (int32_t) t2);
        l11 = std_core$write_int(l12, l11, l13);
        l9 = std_core$finish_buffer(l12, l11);
    }
    l10 = ((vader_struct_vader_support_diagnostics$CodeInfo_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l1)->f_code)->f_id;
    l14 = ((vader_struct_vader_support_diagnostics$CodeInfo_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l1)->f_code)->f_message;
    l4 = concat_9(964u, l9, 969u, l6, 964u, l10, 969u, l14, l4);
    std_string__builder$append(l0, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

void* vader_support_diagnostics$internal_error(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    int64_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = (void*) &vader_data_3;
    l4 = ((int64_t) (uint8_t) l0);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    t0 = vader_support_diagnostics$new_diagnostic((uint8_t) 0, l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_support_diagnostics$lexer_error(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    int64_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = (void*) &vader_data_9;
    l4 = ((int64_t) (uint8_t) l0);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    t0 = vader_support_diagnostics$new_diagnostic((uint8_t) 0, l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_support_diagnostics$lower_error(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    int64_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = (void*) &vader_data_8;
    l4 = ((int64_t) (uint8_t) l0);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    t0 = vader_support_diagnostics$new_diagnostic((uint8_t) 0, l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_support_diagnostics$new_diagnostic(uint8_t l0, void* l1, void* l2, vader_string_t l3) {
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_support_diagnostics$Diagnostic_t* _a0_obj = (vader_struct_vader_support_diagnostics$Diagnostic_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_diagnostics$Diagnostic_t));
    vader_obj_header_init(_a0_obj, 1410u);
    _a0_obj->f_severity = l0;
    _a0_obj->f_code = l1;
    _a0_obj->f_detail = l3;
    _a0_obj->f_primary = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_support_diagnostics$parser_error(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    int64_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = (void*) &vader_data_10;
    l4 = ((int64_t) (uint8_t) l0);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    t0 = vader_support_diagnostics$new_diagnostic((uint8_t) 0, l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_support_diagnostics$relative_to(vader_string_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    int64_t l3, l4;
    void* l5 = NULL;
    bool t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l5 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string$is_empty(l1);
    if (t0) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = std_string$ends_with(l1, 440u);
    if (t0) {
        l2 = l1;
    } else {
        l2 = concat_2(l1, 440u);
    }
    t0 = std_string$starts_with(l0, l2);
    if (!(t0)) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = std_core$len(l2);
    l4 = std_core$len(l0);
    vader_struct_std_core$Range__i64_t* _a0_obj = (vader_struct_std_core$Range__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_core$Range__i64_t));
    vader_obj_header_init(_a0_obj, 621u);
    _a0_obj->f_start = l3;
    _a0_obj->f_end = l4;
    _a0_obj->f_inclusive = false;
    _a0_obj->f_done = false;
    _a0_obj->f_cursor = l3;
    l5 = (void*) _a0_obj;
    t1 = std_core$string$Index$at$1(l0, l5);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_support_diagnostics$render_diagnostics(void* l0, bool l1, bool l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    int64_t l5, l8, l9;
    vader_string_t l6 = 0;
    int64_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    void** gc_raw_roots[6] = { &l0, &l3, &l4, &l7, &l10, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1) {
        l3 = (void*) &vader_fn_static_vader_support_diagnostics$diag_less_with_file;
        l3 = std_sort$sort__vader_support_diagnostics_Diagnostic(l0, l3);
    } else {
        l4 = (void*) &vader_fn_static_vader_support_diagnostics$diag_less;
        l3 = std_sort$sort__vader_support_diagnostics_Diagnostic(l0, l4);
    }
    l3 = vader_support_diagnostics$dedup_diagnostics(l3);
    if (l2) {
        t0 = ((vader_array_t*) l3)->length;
        l5 = std_math$min_3(t0, INT64_C(100));
    } else {
        l5 = ((vader_array_t*) l3)->length;
    }
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    t1 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 626u);
    _a1_obj->f_parts = t1;
    l4 = (void*) _a1_obj;
    std_string__builder$append(l4, 7u);
    if (l1) {
        l6 = std_io$current_working_directory();
    } else {
        l6 = 0u;
    }
    vader_array_t* _a2_arr = vader_array_slice((vader_array_t*) l3, (int64_t) INT64_C(0), (int64_t) l5);
    l7 = (void*) _a2_arr;
    l8 = ((vader_array_t*) l7)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l10 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
        std_string__builder$append_char(l4, 10u);
        vader_support_diagnostics$format_diagnostic(l4, l10, l1, l6);
        l9 = (l9 + INT64_C(1));
    }
    t0 = ((vader_array_t*) l3)->length;
    if ((t0 > l5)) {
        std_string__builder$append_char(l4, 10u);
        l7 = (void*) vader_buffer_new((size_t) INT64_C(47));
        l8 = INT64_C(0);
        l8 = std_core$write_string_at(l7, l8, 3066u);
        t0 = ((vader_array_t*) l3)->length;
        l5 = vader_chk_sub(i64, t0, l5);
        l8 = std_core$write_int(l7, l8, l5);
        l8 = std_core$write_string_at(l7, l8, 177u);
        l6 = std_core$finish_buffer(l7, l8);
        std_string__builder$append(l4, l6);
        t2 = std_string__builder$StringBuilder$std_core$Display$to_string(l4);
        { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = std_string__builder$StringBuilder$std_core$Display$to_string(l4);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_support_diagnostics$resolver_error(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    int64_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = (void*) &vader_data_4;
    l4 = ((int64_t) (uint8_t) l0);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    t0 = vader_support_diagnostics$new_diagnostic((uint8_t) 0, l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_support_diagnostics$typecheck_error(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    int64_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = (void*) &vader_data_5;
    l4 = ((int64_t) (uint8_t) l0);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    t0 = vader_support_diagnostics$new_diagnostic((uint8_t) 0, l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_support_diagnostics$warning(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    int64_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = (void*) &vader_data_6;
    l4 = ((int64_t) (uint8_t) l0);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    t0 = vader_support_diagnostics$new_diagnostic((uint8_t) 1, l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_support_diagnostics$wildcard_clash_detail(vader_string_t l0, void* l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_string$join(l1, 362u);
    l2 = concat_4(1035u, l0, 1151u, l2);
    l3 = concat_3(2478u, l0, 1269u);
    t0 = concat_6(l2, 71u, l3, 191u, l0, 91u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
