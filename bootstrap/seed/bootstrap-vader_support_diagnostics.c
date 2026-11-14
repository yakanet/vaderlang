#include "bootstrap.split.h"

static void* vader_support_diagnostics$dedup_diagnostics(void* l0);
static vader_string_t vader_support_diagnostics$diag_key(void* l0);
static void vader_support_diagnostics$format_diagnostic(void* l0, void* l1, void* l2);
static void* vader_support_diagnostics$new_diagnostic(uint8_t l0, void* l1, void* l2, vader_string_t l3);
static vader_string_t vader_support_diagnostics$relative_to(vader_string_t l0, vader_string_t l1);
static vader_string_t vader_support_diagnostics$render_diagnostics(void* l0, void* l1);
static vader_string_t vader_support_diagnostics$shown_file(vader_string_t l0, void* l1);

bool vader_support_diagnostics$any_error_diag(void* l0) {
    void* l1;
    int64_t l2, l3;
    void* t0;
    l1 = l0;
    l2 = vader_array_length(((vader_array_t*) l1));
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
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
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
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
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 503u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 12u, 501u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 506u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__bool_t* _a3_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a3_obj, 785u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$Set__string_t* _a4_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
    vader_obj_header_init(_a4_obj, 867u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(364u, 0u, 13u, 1705u);
    l2 = (void*) _a5_arr;
    l3 = l0;
    l4 = vader_array_length(((vader_array_t*) l3));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l6 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l5);
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
    l7 = std_core$write_string_at(l9, l7, 3340u);
    l7 = std_core$write_string_at(l9, l7, l2);
    l7 = std_core$write_string_at(l9, l7, 3340u);
    l7 = std_core$write_string_at(l9, l7, l3);
    l7 = std_core$write_string_at(l9, l7, 3340u);
    l7 = std_core$write_int(l9, l7, l4);
    l7 = std_core$write_string_at(l9, l7, 3340u);
    l7 = std_core$write_int(l9, l7, l5);
    l7 = std_core$write_string_at(l9, l7, 3340u);
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
    vader_string_t l1 = 0;
    void* l2 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_env$current_working_directory();
    vader_struct_vader_support_diagnostics$Channel_t* _a0_obj = (vader_struct_vader_support_diagnostics$Channel_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_diagnostics$Channel_t));
    vader_obj_header_init(_a0_obj, 1703u);
    _a0_obj->f_files = true;
    _a0_obj->f_base = l1;
    _a0_obj->f_user = true;
    l2 = (void*) _a0_obj;
    t0 = vader_support_diagnostics$render_diagnostics(l0, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_support_diagnostics$format_diagnostic(void* l0, void* l1, void* l2) {
    vader_string_t l3 = 0;
    vader_string_t l5 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t l13 = 0;
    uint8_t l4;
    bool l6;
    void* l7 = NULL;
    void* l11 = NULL;
    int64_t l10, l12;
    bool t0;
    vader_string_t t1 = 0;
    int32_t t2;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l7, &l11 };
    vader_string_t* gc_atom_roots[6] = { &l3, &l5, &l8, &l9, &l13, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l1)->f_severity;
    if (l4 == INT32_C(0)) {
        l3 = 2053u;
    } else if (l4 == INT32_C(1)) {
        l3 = 3284u;
    } else if (l4 == INT32_C(2)) {
        l3 = 2320u;
    } else {
        if (!(l4 == INT32_C(3))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = 2231u;
    }
    t0 = ((vader_struct_vader_support_diagnostics$Channel_t*) l2)->f_user;
    if (t0) {
        l4 = ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l1)->f_severity;
        if (l4 == INT32_C(0)) {
            l5 = std_tty$red(l3);
        } else if (l4 == INT32_C(1)) {
            l5 = std_tty$yellow(l3);
        } else {
            if (l4 == INT32_C(2)) {
                l6 = true;
            } else {
                l6 = l4 == INT32_C(3);
            }
            if (!(l6)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l5 = l3;
        }
    } else {
        l5 = l3;
    }
    l7 = ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l1)->f_primary)->f_start;
    l3 = 0u;
    t1 = ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l1)->f_detail;
    t0 = std_core$is_empty_1(t1);
    if (!(t0)) {
        l8 = ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l1)->f_detail;
        l3 = concat_2(506u, l8);
    }
    t0 = ((vader_struct_vader_support_diagnostics$Channel_t*) l2)->f_files;
    if (t0) {
        t1 = ((vader_struct_toolchain_span$Position_t*) l7)->f_file;
        l9 = vader_support_diagnostics$shown_file(t1, l2);
        l10 = vader_host_std_core$byte_len(l9);
        l11 = (void*) vader_buffer_new((size_t) (INT64_C(42) + l10));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l11, l10, l9);
        l10 = std_core$write_string_at(l11, l10, 505u);
        t2 = ((vader_struct_toolchain_span$Position_t*) l7)->f_line;
        l12 = ((int64_t) (int32_t) t2);
        l10 = std_core$write_int(l11, l10, l12);
        l10 = std_core$write_string_at(l11, l10, 505u);
        t2 = ((vader_struct_toolchain_span$Position_t*) l7)->f_column;
        l12 = ((int64_t) (int32_t) t2);
        l10 = std_core$write_int(l11, l10, l12);
        l8 = std_core$finish_buffer(l11, l10);
    } else {
        l11 = (void*) vader_buffer_new((size_t) INT64_C(41));
        l10 = INT64_C(0);
        t2 = ((vader_struct_toolchain_span$Position_t*) l7)->f_line;
        l12 = ((int64_t) (int32_t) t2);
        l10 = std_core$write_int(l11, l10, l12);
        l10 = std_core$write_string_at(l11, l10, 505u);
        t2 = ((vader_struct_toolchain_span$Position_t*) l7)->f_column;
        l12 = ((int64_t) (int32_t) t2);
        l10 = std_core$write_int(l11, l10, l12);
        l8 = std_core$finish_buffer(l11, l10);
    }
    l9 = ((vader_struct_vader_support_diagnostics$CodeInfo_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l1)->f_code)->f_id;
    l13 = ((vader_struct_vader_support_diagnostics$CodeInfo_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) l1)->f_code)->f_message;
    l3 = concat_9(1039u, l8, 1046u, l5, 1039u, l9, 1046u, l13, l3);
    std_string__builder$append(l0, l3);
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
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
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
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
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
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
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
    vader_obj_header_init(_a0_obj, 1705u);
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
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
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
    t0 = std_core$is_empty_1(l1);
    if (t0) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = std_string$ends_with(l1, 483u);
    if (t0) {
        l2 = l1;
    } else {
        l2 = concat_2(l1, 483u);
    }
    t0 = std_string$starts_with(l0, l2);
    if (!(t0)) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = std_core$len(l2);
    l4 = std_core$len(l0);
    vader_struct_std_core$Range__i64_t* _a0_obj = (vader_struct_std_core$Range__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_core$Range__i64_t));
    vader_obj_header_init(_a0_obj, 873u);
    _a0_obj->f_start = l3;
    _a0_obj->f_end = l4;
    _a0_obj->f_inclusive = false;
    _a0_obj->f_done = false;
    _a0_obj->f_cursor = l3;
    l5 = (void*) _a0_obj;
    t1 = std_core$string$Index$at$1(l0, l5);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_support_diagnostics$render_diagnostics(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    int64_t l4, l6, l7;
    vader_string_t l9 = 0;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    vader_string_t t3 = 0;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l5, &l8, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l9, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_support_diagnostics$Channel_t*) l1)->f_files;
    if (t0) {
        l2 = (void*) &vader_fn_static_vader_support_diagnostics$diag_less_with_file;
        l2 = std_sort$sort__vader_support_diagnostics_Diagnostic(l0, l2);
    } else {
        l3 = (void*) &vader_fn_static_vader_support_diagnostics$diag_less;
        l2 = std_sort$sort__vader_support_diagnostics_Diagnostic(l0, l3);
    }
    l2 = vader_support_diagnostics$dedup_diagnostics(l2);
    t0 = ((vader_struct_vader_support_diagnostics$Channel_t*) l1)->f_user;
    if (t0) {
        t1 = vader_array_length(((vader_array_t*) l2));
        l4 = std_math$min__i64(t1, INT64_C(100));
    } else {
        l4 = vader_array_length(((vader_array_t*) l2));
    }
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 503u);
    t2 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 882u);
    _a1_obj->f_parts = t2;
    l3 = (void*) _a1_obj;
    std_string__builder$append(l3, 7u);
    vader_array_t* _a2_arr = vader_array_slice((vader_array_t*) l2, (int64_t) INT64_C(0), (int64_t) l4);
    l5 = (void*) _a2_arr;
    l6 = vader_array_length(((vader_array_t*) l5));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l7)
        l8 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l7);
        std_string__builder$append_char(l3, 10u);
        vader_support_diagnostics$format_diagnostic(l3, l8, l1);
        l7 = (l7 + INT64_C(1));
    }
    t1 = vader_array_length(((vader_array_t*) l2));
    if ((t1 > l4)) {
        std_string__builder$append_char(l3, 10u);
        l5 = (void*) vader_buffer_new((size_t) INT64_C(47));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l5, l6, 435u);
        t1 = vader_array_length(((vader_array_t*) l2));
        l4 = vader_chk_sub(i64, t1, l4);
        l6 = std_core$write_int(l5, l6, l4);
        l6 = std_core$write_string_at(l5, l6, 187u);
        l9 = std_core$finish_buffer(l5, l6);
        std_string__builder$append(l3, l9);
        t3 = std_string__builder$StringBuilder$std_core$Display$to_string(l3);
        { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = std_string__builder$StringBuilder$std_core$Display$to_string(l3);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
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
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
    t0 = vader_support_diagnostics$new_diagnostic((uint8_t) 0, l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_support_diagnostics$shown_file(vader_string_t l0, void* l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    bool t0;
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[5] = { &l0, &l2, &l3, &t1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_support_diagnostics$Channel_t*) l1)->f_user;
    if (!(t0)) {
        l2 = std_path$to_posix(l0);
        t1 = ((vader_struct_vader_support_diagnostics$Channel_t*) l1)->f_base;
        l3 = std_path$to_posix(t1);
        t1 = vader_support_diagnostics$relative_to(l2, l3);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_support_diagnostics$Channel_t*) l1)->f_base;
    t1 = vader_support_diagnostics$relative_to(l0, l2);
    t2 = std_path$to_native(t1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
    l3 = (void*) &vader_data_6;
    l4 = ((int64_t) (uint8_t) l0);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
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
    l3 = (void*) &vader_data_5;
    l4 = ((int64_t) (uint8_t) l0);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
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
    l2 = std_string$join(l1, 386u);
    l2 = concat_4(1109u, l0, 1240u, l2);
    l3 = concat_3(2663u, l0, 1368u);
    t0 = concat_6(l2, 73u, l3, 202u, l0, 95u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
